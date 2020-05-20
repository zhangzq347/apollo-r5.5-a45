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

#pragma once

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/canbus/proto/chassis_detail.pb.h"

namespace apollo {
namespace canbus {
namespace a45 {

class Acc2250 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Acc2250();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'name': 'FRS_ACC_CheckSum', 'offset': 0.0, 'precision': 1.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|155]', 'bit': 63, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  Acc2250* set_frs_acc_checksum(Acc2_250::Frs_acc_driveoffreqType frs_acc_driveoffreq, double frs_acc_adtlowerlimitaxvcv,
    Acc2_250::Frs_acc_brakepreferredType frs_acc_brakepreferred, Acc2_250::Frs_acc_minimumbrakingType frs_acc_minimumbraking,
    Acc2_250::Frs_acc_shutdownmodeType frs_acc_shutdownmode, int frs_acc_alivecounter, Acc2_250::Frs_acc_cc_modeType frs_acc_cc_mode,
    double frs_acc_accecomflowervalue, double frs_acc_accecomfuppervalue, Acc2_250::Frs_acc_dectostopreqType frs_acc_dectostopreq,
    double frs_acc_adtupperlimitaxvcv, double frs_acc_axvcvaim);

  // config detail: {'name': 'FRS_ACC_DriveoffReq', 'enum': {0: 'FRS_ACC_DRIVEOFFREQ_NO_REQUEST', 1: 'FRS_ACC_DRIVEOFFREQ_REQUESTED'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 55, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc2250* set_frs_acc_driveoffreq(Acc2_250::Frs_acc_driveoffreqType frs_acc_driveoffreq);

  // config detail: {'name': 'FRS_ACC_aDtLowerLimitAxvCv', 'offset': -25.4, 'precision': 0.2, 'len': 7, 'is_signed_var': False, 'physical_range': '[-25.4|0]', 'bit': 54, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
  Acc2250* set_frs_acc_adtlowerlimitaxvcv(double frs_acc_adtlowerlimitaxvcv);

  // config detail: {'name': 'FRS_ACC_BrakePreferred', 'enum': {0: 'FRS_ACC_BRAKEPREFERRED_NO_DEMAND', 1: 'FRS_ACC_BRAKEPREFERRED_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 47, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc2250* set_frs_acc_brakepreferred(Acc2_250::Frs_acc_brakepreferredType frs_acc_brakepreferred);

  // config detail: {'name': 'FRS_ACC_MinimumBraking', 'enum': {0: 'FRS_ACC_MINIMUMBRAKING_NO_DEMAND', 1: 'FRS_ACC_MINIMUMBRAKING_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 46, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc2250* set_frs_acc_minimumbraking(Acc2_250::Frs_acc_minimumbrakingType frs_acc_minimumbraking);

  // config detail: {'name': 'FRS_ACC_ShutdownMode', 'enum': {0: 'FRS_ACC_SHUTDOWNMODE_SOFT_OFF', 1: 'FRS_ACC_SHUTDOWNMODE_FAST_OFF', 2: 'FRS_ACC_SHUTDOWNMODE_IMMEDIATE_OFF', 3: 'FRS_ACC_SHUTDOWNMODE_NO_REQUEST'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 45, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc2250* set_frs_acc_shutdownmode(Acc2_250::Frs_acc_shutdownmodeType frs_acc_shutdownmode);

  // config detail: {'name': 'FRS_ACC_AliveCounter', 'offset': 0.0, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'physical_range': '[0|15]', 'bit': 43, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  Acc2250* set_frs_acc_alivecounter();

  // config detail: {'name': 'FRS_ACC_CC_Mode', 'enum': {0: 'FRS_ACC_CC_MODE_OFF_MODE', 1: 'FRS_ACC_CC_MODE_PASSIVE_MODE', 2: 'FRS_ACC_CC_MODE_STAND_BY_MODE', 3: 'FRS_ACC_CC_MODE_ACTIVE_CONTROL_MODE', 4: 'FRS_ACC_CC_MODE_BRAKE_ONLY_MODE', 5: 'FRS_ACC_CC_MODE_OVERRIDE', 6: 'FRS_ACC_CC_MODE_STAND_ACTIVE', 7: 'FRS_ACC_CC_MODE_STAND_WAIT', 8: 'FRS_ACC_CC_MODE_TEMPORARY_FAILURE', 9: 'FRS_ACC_CC_MODE_PERMANENT_FAILURE'}, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|15]', 'bit': 39, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc2250* set_frs_acc_cc_mode(Acc2_250::Frs_acc_cc_modeType frs_acc_cc_mode);

  // config detail: {'name': 'FRS_ACC_AcceComfLowerValue', 'offset': -7.0, 'precision': 0.05, 'len': 8, 'is_signed_var': False, 'physical_range': '[-7|5.75]', 'bit': 31, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
  Acc2250* set_frs_acc_accecomflowervalue(double frs_acc_accecomflowervalue);

  // config detail: {'name': 'FRS_ACC_AcceComfUpperValue', 'offset': -7.0, 'precision': 0.05, 'len': 8, 'is_signed_var': False, 'physical_range': '[-7|5.75]', 'bit': 23, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
  Acc2250* set_frs_acc_accecomfuppervalue(double frs_acc_accecomfuppervalue);

  // config detail: {'name': 'FRS_ACC_DecToStopReq', 'enum': {0: 'FRS_ACC_DECTOSTOPREQ_NO_REQUEST', 1: 'FRS_ACC_DECTOSTOPREQ_REQUEST'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 15, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc2250* set_frs_acc_dectostopreq(Acc2_250::Frs_acc_dectostopreqType frs_acc_dectostopreq);

  // config detail: {'name': 'FRS_ACC_aDtUpperLimitAxvCv', 'offset': 0.0, 'precision': 0.2, 'len': 7, 'is_signed_var': False, 'physical_range': '[0|25.4]', 'bit': 14, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
  Acc2250* set_frs_acc_adtupperlimitaxvcv(double frs_acc_adtupperlimitaxvcv);

  // config detail: {'name': 'FRS_ACC_axvCvAim', 'offset': -7.0, 'precision': 0.05, 'len': 8, 'is_signed_var': False, 'physical_range': '[-7|5.75]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'm/s2'}
  Acc2250* set_frs_acc_axvcvaim(double frs_acc_axvcvaim);

 private:

  // config detail: {'name': 'FRS_ACC_CheckSum', 'offset': 0.0, 'precision': 1.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|155]', 'bit': 63, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_acc_checksum(uint8_t* data, int frs_acc_checksum);

  // config detail: {'name': 'FRS_ACC_DriveoffReq', 'enum': {0: 'FRS_ACC_DRIVEOFFREQ_NO_REQUEST', 1: 'FRS_ACC_DRIVEOFFREQ_REQUESTED'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 55, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_acc_driveoffreq(uint8_t* data, Acc2_250::Frs_acc_driveoffreqType frs_acc_driveoffreq);

  // config detail: {'name': 'FRS_ACC_aDtLowerLimitAxvCv', 'offset': -25.4, 'precision': 0.2, 'len': 7, 'is_signed_var': False, 'physical_range': '[-25.4|0]', 'bit': 54, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_acc_adtlowerlimitaxvcv(uint8_t* data, double frs_acc_adtlowerlimitaxvcv);

  // config detail: {'name': 'FRS_ACC_BrakePreferred', 'enum': {0: 'FRS_ACC_BRAKEPREFERRED_NO_DEMAND', 1: 'FRS_ACC_BRAKEPREFERRED_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 47, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_acc_brakepreferred(uint8_t* data, Acc2_250::Frs_acc_brakepreferredType frs_acc_brakepreferred);

  // config detail: {'name': 'FRS_ACC_MinimumBraking', 'enum': {0: 'FRS_ACC_MINIMUMBRAKING_NO_DEMAND', 1: 'FRS_ACC_MINIMUMBRAKING_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 46, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_acc_minimumbraking(uint8_t* data, Acc2_250::Frs_acc_minimumbrakingType frs_acc_minimumbraking);

  // config detail: {'name': 'FRS_ACC_ShutdownMode', 'enum': {0: 'FRS_ACC_SHUTDOWNMODE_SOFT_OFF', 1: 'FRS_ACC_SHUTDOWNMODE_FAST_OFF', 2: 'FRS_ACC_SHUTDOWNMODE_IMMEDIATE_OFF', 3: 'FRS_ACC_SHUTDOWNMODE_NO_REQUEST'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 45, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_acc_shutdownmode(uint8_t* data, Acc2_250::Frs_acc_shutdownmodeType frs_acc_shutdownmode);

  // config detail: {'name': 'FRS_ACC_AliveCounter', 'offset': 0.0, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'physical_range': '[0|15]', 'bit': 43, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_acc_alivecounter(uint8_t* data, int frs_acc_alivecounter);

  // config detail: {'name': 'FRS_ACC_CC_Mode', 'enum': {0: 'FRS_ACC_CC_MODE_OFF_MODE', 1: 'FRS_ACC_CC_MODE_PASSIVE_MODE', 2: 'FRS_ACC_CC_MODE_STAND_BY_MODE', 3: 'FRS_ACC_CC_MODE_ACTIVE_CONTROL_MODE', 4: 'FRS_ACC_CC_MODE_BRAKE_ONLY_MODE', 5: 'FRS_ACC_CC_MODE_OVERRIDE', 6: 'FRS_ACC_CC_MODE_STAND_ACTIVE', 7: 'FRS_ACC_CC_MODE_STAND_WAIT', 8: 'FRS_ACC_CC_MODE_TEMPORARY_FAILURE', 9: 'FRS_ACC_CC_MODE_PERMANENT_FAILURE'}, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|15]', 'bit': 39, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_acc_cc_mode(uint8_t* data, Acc2_250::Frs_acc_cc_modeType frs_acc_cc_mode);

  // config detail: {'name': 'FRS_ACC_AcceComfLowerValue', 'offset': -7.0, 'precision': 0.05, 'len': 8, 'is_signed_var': False, 'physical_range': '[-7|5.75]', 'bit': 31, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_acc_accecomflowervalue(uint8_t* data, double frs_acc_accecomflowervalue);

  // config detail: {'name': 'FRS_ACC_AcceComfUpperValue', 'offset': -7.0, 'precision': 0.05, 'len': 8, 'is_signed_var': False, 'physical_range': '[-7|5.75]', 'bit': 23, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_acc_accecomfuppervalue(uint8_t* data, double frs_acc_accecomfuppervalue);

  // config detail: {'name': 'FRS_ACC_DecToStopReq', 'enum': {0: 'FRS_ACC_DECTOSTOPREQ_NO_REQUEST', 1: 'FRS_ACC_DECTOSTOPREQ_REQUEST'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 15, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_acc_dectostopreq(uint8_t* data, Acc2_250::Frs_acc_dectostopreqType frs_acc_dectostopreq);

  // config detail: {'name': 'FRS_ACC_aDtUpperLimitAxvCv', 'offset': 0.0, 'precision': 0.2, 'len': 7, 'is_signed_var': False, 'physical_range': '[0|25.4]', 'bit': 14, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_acc_adtupperlimitaxvcv(uint8_t* data, double frs_acc_adtupperlimitaxvcv);

  // config detail: {'name': 'FRS_ACC_axvCvAim', 'offset': -7.0, 'precision': 0.05, 'len': 8, 'is_signed_var': False, 'physical_range': '[-7|5.75]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'm/s2'}
  void set_p_frs_acc_axvcvaim(uint8_t* data, double frs_acc_axvcvaim);

 private:
  int frs_acc_checksum_;
  Acc2_250::Frs_acc_driveoffreqType frs_acc_driveoffreq_;
  double frs_acc_adtlowerlimitaxvcv_;
  Acc2_250::Frs_acc_brakepreferredType frs_acc_brakepreferred_;
  Acc2_250::Frs_acc_minimumbrakingType frs_acc_minimumbraking_;
  Acc2_250::Frs_acc_shutdownmodeType frs_acc_shutdownmode_;
  int frs_acc_alivecounter_;
  Acc2_250::Frs_acc_cc_modeType frs_acc_cc_mode_;
  double frs_acc_accecomflowervalue_;
  double frs_acc_accecomfuppervalue_;
  Acc2_250::Frs_acc_dectostopreqType frs_acc_dectostopreq_;
  double frs_acc_adtupperlimitaxvcv_;
  double frs_acc_axvcvaim_;
};

}  // namespace a45
}  // namespace canbus
}  // namespace apollo


