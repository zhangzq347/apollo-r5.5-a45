/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/canbus/vehicle/a45/a45_controller.h"

#include "modules/common/proto/vehicle_signal.pb.h"

#include "modules/canbus/vehicle/a45/a45_message_manager.h"
#include "modules/canbus/vehicle/vehicle_controller.h"
#include "cyber/common/log.h"
#include "modules/common/time/time.h"
#include "modules/drivers/canbus/can_comm/can_sender.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::ProtocolData;
using ::apollo::common::ErrorCode;
using ::apollo::control::ControlCommand;

namespace {

const int32_t kMaxFailAttempt = 10;
const int32_t CHECK_RESPONSE_STEER_UNIT_FLAG = 1;
const int32_t CHECK_RESPONSE_SPEED_UNIT_FLAG = 2;
double angle_init = 0;
}

ErrorCode A45Controller::Init(
	const VehicleParameter& params,
	CanSender<::apollo::canbus::ChassisDetail> *const can_sender,
    MessageManager<::apollo::canbus::ChassisDetail> *const message_manager) {
  if (is_initialized_) {
    AINFO << "A45Controller has already been initiated.";
    return ErrorCode::CANBUS_ERROR;
  }

  params_.CopyFrom(params);
  if (!params_.has_driving_mode()) {
    AERROR << "Vehicle conf pb not set driving_mode.";
    return ErrorCode::CANBUS_ERROR;
  }

  if (can_sender == nullptr) {
    return ErrorCode::CANBUS_ERROR;
  }
  can_sender_ = can_sender;

  if (message_manager == nullptr) {
    AERROR << "protocol manager is null.";
    return ErrorCode::CANBUS_ERROR;
  }
  message_manager_ = message_manager;

  // sender part
  acc1_225_ = dynamic_cast<Acc1225*>
          (message_manager_->GetMutableProtocolDataById(Acc1225::ID));
  if (acc1_225_ == nullptr) {
     AERROR << "Acc1225 does not exist in the A45MessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }

  acc2_250_ = dynamic_cast<Acc2250*>
          (message_manager_->GetMutableProtocolDataById(Acc2250::ID));
  if (acc2_250_ == nullptr) {
     AERROR << "Acc2250 does not exist in the A45MessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }

  acc3_251_ = dynamic_cast<Acc3251*>
          (message_manager_->GetMutableProtocolDataById(Acc3251::ID));
  if (acc3_251_ == nullptr) {
     AERROR << "Acc3251 does not exist in the A45MessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }

  eps_control_300_ = dynamic_cast<Epscontrol300*>
          (message_manager_->GetMutableProtocolDataById(Epscontrol300::ID));
  if (eps_control_300_ == nullptr) {
     AERROR << "Epscontrol300 does not exist in the A45MessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }

  can_sender_->AddMessage(Acc1225::ID, acc1_225_, false);
  can_sender_->AddMessage(Acc2250::ID, acc2_250_, false);
  can_sender_->AddMessage(Acc3251::ID, acc3_251_, false);
  can_sender_->AddMessage(Epscontrol300::ID, eps_control_300_, false);

  // need sleep to ensure all messages received
  AINFO << "A45Controller is initialized.";

  is_initialized_ = true;
  return ErrorCode::OK;
}

A45Controller::~A45Controller() {}

bool A45Controller::Start() {
  if (!is_initialized_) {
    AERROR << "A45Controller has NOT been initiated.";
    return false;
  }
  const auto& update_func = [this] { SecurityDogThreadFunc(); };
  thread_.reset(new std::thread(update_func));

  return true;
}

void A45Controller::Stop() {
  if (!is_initialized_) {
    AERROR << "A45Controller stops or starts improperly!";
    return;
  }

  if (thread_ != nullptr && thread_->joinable()) {
    thread_->join();
    thread_.reset();
    AINFO << "A45Controller stopped.";
  }
}

Chassis A45Controller::chassis() {
  chassis_.Clear();

  ChassisDetail chassis_detail;
  message_manager_->GetSensorData(&chassis_detail);

  // 21, 22, previously 1, 2
  if (driving_mode() == Chassis::EMERGENCY_MODE) {
    set_chassis_error_code(Chassis::NO_ERROR);
  }

  chassis_.set_driving_mode(driving_mode());
  chassis_.set_error_code(chassis_error_code());

  // 3
  chassis_.set_engine_started(true);

  if (!chassis_detail.has_a45()) {
    AERROR << "NO A45 chassis information!";
    return chassis_;
  }
  A45 a45 = chassis_detail.a45();

  if (a45.has_ems3_278() && a45.ems3_278().has_ems_enginespeedrpm()) {
    chassis_.set_engine_rpm(static_cast<float>(a45.ems3_278().ems_enginespeedrpm()));
  } else {
    chassis_.set_engine_rpm(0);
  }

  if (a45.has_abs1_esp1_311() &&
      a45.abs1_esp1_311().has_abs_esp_vehiclespeedvsosig()) {
    chassis_.set_speed_mps(
        static_cast<float>((a45.abs1_esp1_311().abs_esp_vehiclespeedvsosig()) / 3.6));
    chassis_.set_speed_kph(
        static_cast<float>(a45.abs1_esp1_311().abs_esp_vehiclespeedvsosig())) ;
  } else {
    chassis_.set_speed_mps(0);
    chassis_.set_speed_kph(0);
  }

  if (a45.has_ems3_278() && a45.ems3_278().has_ems_accelerationpedalposition()) {
    chassis_.set_throttle_percentage(
        static_cast<float>(a45.ems3_278().ems_accelerationpedalposition()));
  } else {
    chassis_.set_throttle_percentage(0);
  }

  if (a45.has_eps_status1_230() && a45.eps_status1_230().has_eps_tx_sas_steeringangle()) {
    chassis_.set_steering_percentage(static_cast<float>(
        a45.eps_status1_230().eps_tx_sas_steeringangle() * 100.0 / 470));
    chassis_.set_steering_angle(static_cast<float>(
        a45.eps_status1_230().eps_tx_sas_steeringangle()));
    angle_init = a45.eps_status1_230().eps_tx_sas_steeringangle();
  } else {
    chassis_.set_steering_percentage(0);
    chassis_.set_steering_angle(0);
  }

  if (a45.has_tcu1_1a0() && a45.tcu1_1a0().has_tcu_st_gearleverposition()) {
    Chassis::GearPosition gear_pos = Chassis::GEAR_INVALID;
	if (a45.tcu1_1a0().tcu_st_gearleverposition() == Tcu1_1a0::GEAR_STS_NEUTRAL) {
      gear_pos = Chassis::GEAR_NEUTRAL;
    }
    else if (a45.tcu1_1a0().tcu_st_gearleverposition() == Tcu1_1a0::GEAR_STS_REVERSE) {
      gear_pos = Chassis::GEAR_REVERSE;
    }
    else if (a45.tcu1_1a0().tcu_st_gearleverposition() == Tcu1_1a0::GEAR_STS_DRIVE) {
      gear_pos = Chassis::GEAR_DRIVE;
    }
    else if (a45.tcu1_1a0().tcu_st_gearleverposition() == Tcu1_1a0::GEAR_STS_PARK) {
      gear_pos = Chassis::GEAR_PARKING;
    }
    else{
      gear_pos = Chassis::GEAR_NONE;
    }
    chassis_.set_gear_location(gear_pos);
  } else {
    chassis_.set_gear_location(Chassis::GEAR_NONE);
  }

  if (a45.has_esp4_213() && a45.esp4_213().has_esp_longitudeacc()) {
	  chassis_.set_acc_speed_mps2(
		  static_cast<float>((a45.esp4_213().esp_longitudeacc()) * 9.8));
  }
  else {
	  chassis_.set_acc_speed_mps2(0);
  }

  if (chassis_error_mask_) {
    chassis_.set_chassis_error_mask(chassis_error_mask_);
  }

  if (chassis_detail.has_surround()) {
    chassis_.mutable_surround()->CopyFrom(chassis_detail.surround());
  }

  if (!chassis_error_mask_ && !chassis_.parking_brake() &&
      (chassis_.throttle_percentage() == 0.0)) {
    chassis_.mutable_engage_advice()->set_advice(
        apollo::common::EngageAdvice::READY_TO_ENGAGE);
  } else {
    chassis_.mutable_engage_advice()->set_advice(
        apollo::common::EngageAdvice::DISALLOW_ENGAGE);
    chassis_.mutable_engage_advice()->set_reason(
        "CANBUS not ready, firmware error or emergency button pressed!");
  }

  /*
  if (a45.has_ems3_278() && a45.ems3_278().ems_brakepedlestatus() == 1) {
    Emergency();
  }
  */

  return chassis_;
}

void A45Controller::Emergency() {
  set_driving_mode(Chassis::EMERGENCY_MODE);
  ResetProtocol();
}

ErrorCode A45Controller::EnableAutoMode() {
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE) {
    AINFO << "already in COMPLETE_AUTO_DRIVE mode";
    return ErrorCode::OK;
  }

  eps_control_300_->set_eps_control_request(Eps_control_300::EPS_CONTROL_REQUEST);
  eps_control_300_->set_eps_control_targetangle(angle_init);
  acc2_250_->set_frs_acc_cc_mode(Acc2_250::FRS_ACC_CC_MODE_ACTIVE_CONTROL_MODE);
  acc1_225_->set_acc_accmode_hmi(Acc1_225::ACC_ACCMODE_HMI_ACTIVE_CONTROL_MODE);

  can_sender_->Update();
  const int32_t flag =
      CHECK_RESPONSE_STEER_UNIT_FLAG | CHECK_RESPONSE_SPEED_UNIT_FLAG;
  if (!CheckResponse(flag, true)) {
    AERROR << "Failed to switch to COMPLETE_AUTO_DRIVE mode.";
    Emergency();
    set_chassis_error_code(Chassis::CHASSIS_ERROR);
    return ErrorCode::CANBUS_ERROR;
  }
  set_driving_mode(Chassis::COMPLETE_AUTO_DRIVE);
  AINFO << "Switch to COMPLETE_AUTO_DRIVE mode ok.";
  return ErrorCode::OK;

}

ErrorCode A45Controller::DisableAutoMode() {
  ResetProtocol();
  can_sender_->Update();
  set_driving_mode(Chassis::COMPLETE_MANUAL);
  set_chassis_error_code(Chassis::NO_ERROR);
  AINFO << "Switch to COMPLETE_MANUAL ok.";
  return ErrorCode::OK;
}

ErrorCode A45Controller::EnableSteeringOnlyMode() {
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE ||
      driving_mode() == Chassis::AUTO_STEER_ONLY) {
    set_driving_mode(Chassis::AUTO_STEER_ONLY);
    AINFO << "Already in AUTO_STEER_ONLY mode.";
    return ErrorCode::OK;
  }

  eps_control_300_->set_eps_control_request(Eps_control_300::EPS_CONTROL_REQUEST);
  eps_control_300_->set_eps_control_targetangle(angle_init);
  acc2_250_->set_frs_acc_cc_mode(Acc2_250::FRS_ACC_CC_MODE_PASSIVE_MODE);
  acc1_225_->set_acc_accmode_hmi(Acc1_225::ACC_ACCMODE_HMI_PASSIVE_MODE);

  can_sender_->Update();
  if (!CheckResponse(CHECK_RESPONSE_STEER_UNIT_FLAG, true)) {
    AERROR << "Failed to switch to AUTO_STEER_ONLY mode.";
    Emergency();
    set_chassis_error_code(Chassis::CHASSIS_ERROR);
    return ErrorCode::CANBUS_ERROR;
  }
  set_driving_mode(Chassis::AUTO_STEER_ONLY);
  AINFO << "Switch to AUTO_STEER_ONLY mode ok.";
  return ErrorCode::OK;

}

ErrorCode A45Controller::EnableSpeedOnlyMode() {
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE ||
      driving_mode() == Chassis::AUTO_SPEED_ONLY) {
    set_driving_mode(Chassis::AUTO_SPEED_ONLY);
    AINFO << "Already in AUTO_SPEED_ONLY mode";
    return ErrorCode::OK;
  }

  eps_control_300_->set_eps_control_request(Eps_control_300::EPS_CONTROL_NO_REQUEST);
  acc2_250_->set_frs_acc_cc_mode(Acc2_250::FRS_ACC_CC_MODE_ACTIVE_CONTROL_MODE);
  acc1_225_->set_acc_accmode_hmi(Acc1_225::ACC_ACCMODE_HMI_ACTIVE_CONTROL_MODE);

  can_sender_->Update();
  if (!CheckResponse(CHECK_RESPONSE_SPEED_UNIT_FLAG, true)) {
    AERROR << "Failed to switch to AUTO_STEER_ONLY mode.";
    Emergency();
    set_chassis_error_code(Chassis::CHASSIS_ERROR);
    return ErrorCode::CANBUS_ERROR;
  }
  set_driving_mode(Chassis::AUTO_SPEED_ONLY);
  AINFO << "Switch to AUTO_SPEED_ONLY mode ok.";
  return ErrorCode::OK;

}

// NEUTRAL, REVERSE, DRIVE
void A45Controller::Gear(Chassis::GearPosition gear_position) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "This drive mode no need to set gear.";
    return;
  }
  //None
}

// brake with new acceleration
// acceleration:0.00~99.99, unit:
// acceleration:0.0 ~ 7.0, unit:m/s^2
// acceleration_spd:60 ~ 100, suggest: 90
// -> pedal
void A45Controller::Brake(double pedal) {
  // double real_value = params_.max_acc() * acceleration / 100;
  // TODO(All) :  Update brake value based on mode
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "The current drive mode does not need to set brake pedal.";
    return;
  }
  //None
}

// drive with old acceleration
// gas:0.00~99.99 unit:
void A45Controller::Throttle(double pedal) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "The current drive mode does not need to set throttle pedal.";
    return;
  }
  //None
}

// confirm the car is driven by acceleration command or throttle/brake pedal
// drive with acceleration/deceleration
// acc:-7.0 ~ 5.0, unit:m/s^2
void A45Controller::Acceleration(double acc) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE ||
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "The current drive mode does not need to set acceleration.";
    return;
  }

  acc2_250_->set_frs_acc_axvcvaim(acc);

  if (chassis_.speed_mps() < 1) {
    if (acc >= 0) {
      acc2_250_->set_frs_acc_driveoffreq(Acc2_250::FRS_ACC_DRIVEOFFREQ_REQUESTED);
      acc2_250_->set_frs_acc_dectostopreq(Acc2_250::FRS_ACC_DECTOSTOPREQ_NO_REQUEST);
    } else {
      acc2_250_->set_frs_acc_driveoffreq(Acc2_250::FRS_ACC_DRIVEOFFREQ_NO_REQUEST);
      acc2_250_->set_frs_acc_dectostopreq(Acc2_250::FRS_ACC_DECTOSTOPREQ_REQUEST);
    }
  } else {
    acc2_250_->set_frs_acc_driveoffreq(Acc2_250::FRS_ACC_DRIVEOFFREQ_NO_REQUEST);
    acc2_250_->set_frs_acc_dectostopreq(Acc2_250::FRS_ACC_DECTOSTOPREQ_NO_REQUEST);
  }
}

// a45 default, -470 ~ 470, left:+, right:-
// need to be compatible with control module, so reverse
// steering with old angle speed
// angle:-99.99~0.00~99.99, unit:, left:-, right:+
void A45Controller::Steer(double angle) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_STEER_ONLY) {
    AINFO << "The current driving mode does not need to set steer.";
    return;
  }
  // const double real_angle = params_.max_steer_angle() * angle / 100.0;
  // reverse sign
  const double real_angle = 470 * angle / 100.0;
  eps_control_300_->set_eps_control_targetangle(real_angle);
}

// steering with new angle speed
// angle:-99.99~0.00~99.99, unit:, left:-, right:+
// angle_spd:0.00~99.99, unit:deg/s
void A45Controller::Steer(double angle, double angle_spd) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_STEER_ONLY) {
    AINFO << "The current driving mode does not need to set steer.";
    return;
  }

  const double real_angle = 470 * angle / 100.0;
  eps_control_300_->set_eps_control_targetangle(real_angle);
}

void A45Controller::SetEpbBreak(const ControlCommand& command) {
  if (command.parking_brake()) {
    // None
  } else {
    // None
  }
}

void A45Controller::SetBeam(const ControlCommand& command) {
  if (command.signal().high_beam()) {
    // None
  } else if (command.signal().low_beam()) {
    // None
  } else {
    // None
  }
}

void A45Controller::SetHorn(const ControlCommand& command) {
  if (command.signal().horn()) {
    // None
  } else {
    // None
  }
}

void A45Controller::SetTurningSignal(const ControlCommand& command) {
  // Set Turn Signal
  // None
}

void A45Controller::ResetProtocol() {
  message_manager_->ResetSendMessages();
}

bool A45Controller::CheckChassisError() {
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  */
  return false; //未检测底盘错误状态，后续需加上。（20200515-张智清）
}

void A45Controller::SecurityDogThreadFunc() {
  int32_t vertical_ctrl_fail = 0;
  int32_t horizontal_ctrl_fail = 0;

  if (can_sender_ == nullptr) {
    AERROR << "Failed to run SecurityDogThreadFunc() because can_sender_ is "
              "nullptr.";
    return;
  }
  while (!can_sender_->IsRunning()) {
    std::this_thread::yield();
  }

  std::chrono::duration<double, std::micro> default_period{50000};
  int64_t start = 0;
  int64_t end = 0;
  while (can_sender_->IsRunning()) {

    /***  此段为Apollo工具自动生成，由于版本较早，已不适用
    start = ::apollo::common::time::AsInt64<::apollo::common::time::micros>(
        ::apollo::common::time::Clock::Now());
    替换为下段代码  ***/
    start = absl::ToUnixMicros(::apollo::common::time::Clock::Now());

    const Chassis::DrivingMode mode = driving_mode();
    bool emergency_mode = false;

    // 1. horizontal control check
    if ((mode == Chassis::COMPLETE_AUTO_DRIVE ||
         mode == Chassis::AUTO_STEER_ONLY) &&
        CheckResponse(CHECK_RESPONSE_STEER_UNIT_FLAG, false) == false) {
      ++horizontal_ctrl_fail;
      if (horizontal_ctrl_fail >= kMaxFailAttempt) {
        emergency_mode = true;
        set_chassis_error_code(Chassis::MANUAL_INTERVENTION);
      }
    } else {
      horizontal_ctrl_fail = 0;
    }

    // 2. vertical control check
    if ((mode == Chassis::COMPLETE_AUTO_DRIVE ||
         mode == Chassis::AUTO_SPEED_ONLY) &&
        !CheckResponse(CHECK_RESPONSE_SPEED_UNIT_FLAG, false)) {
      ++vertical_ctrl_fail;
      if (vertical_ctrl_fail >= kMaxFailAttempt) {
        emergency_mode = true;
        set_chassis_error_code(Chassis::MANUAL_INTERVENTION);
      }
    } else {
      vertical_ctrl_fail = 0;
    }

    if (CheckChassisError()) {
      set_chassis_error_code(Chassis::CHASSIS_ERROR);
      emergency_mode = true;
    }

    if (emergency_mode && mode != Chassis::EMERGENCY_MODE) {
      set_driving_mode(Chassis::EMERGENCY_MODE);
      message_manager_->ResetSendMessages();
    }

    /***  此段为Apollo工具自动生成，由于版本较早，已不适用
    end = ::apollo::common::time::AsInt64<::apollo::common::time::micros>(
        ::apollo::common::time::Clock::Now());
    替换为下段代码  ***/
    end = absl::ToUnixMicros(::apollo::common::time::Clock::Now());

    std::chrono::duration<double, std::micro> elapsed{end - start};
    if (elapsed < default_period) {
      std::this_thread::sleep_for(default_period - elapsed);
    } else {
      AERROR
          << "Too much time consumption in A45Controller looping process:"
          << elapsed.count();
    }
  }
}

bool A45Controller::CheckResponse(const int32_t flags, bool need_wait) {
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  */
  return true; //未检测横纵向控制状态，后续需加上。（20200515-张智清）
}

void A45Controller::set_chassis_error_mask(const int32_t mask) {
  std::lock_guard<std::mutex> lock(chassis_mask_mutex_);
  chassis_error_mask_ = mask;
}

int32_t A45Controller::chassis_error_mask() {
  std::lock_guard<std::mutex> lock(chassis_mask_mutex_);
  return chassis_error_mask_;
}

Chassis::ErrorCode A45Controller::chassis_error_code() {
  std::lock_guard<std::mutex> lock(chassis_error_code_mutex_);
  return chassis_error_code_;
}

void A45Controller::set_chassis_error_code(
    const Chassis::ErrorCode& error_code) {
  std::lock_guard<std::mutex> lock(chassis_error_code_mutex_);
  chassis_error_code_ = error_code;
}

}  // namespace a45
}  // namespace canbus
}  // namespace apollo
