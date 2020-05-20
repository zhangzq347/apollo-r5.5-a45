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

class Epsstatus1230 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Epsstatus1230();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'name': 'EPS_Tx_EPS_WorkStatus', 'offset': 0.0, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'physical_range': '[0|3]', 'bit': 47, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  int eps_tx_eps_workstatus(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_EPS_DriverStrDtd_Valid', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 45, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool eps_tx_eps_driverstrdtd_valid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_EPS_DriverStrDtd', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 44, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool eps_tx_eps_driverstrdtd(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_SAS_SteeringAngleSpeed', 'offset': 0.0, 'precision': 4.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|1020]', 'bit': 23, 'type': 'double', 'order': 'motorola', 'physical_unit': 'deg/s'}
  double eps_tx_sas_steeringanglespeed(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_SAS_SteeringAngle', 'offset': -2048.0, 'precision': 0.0625, 'len': 16, 'is_signed_var': False, 'physical_range': '[-2048|2047.9375]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'deg'}
  double eps_tx_sas_steeringangle(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_SAS_Failure', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 31, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool eps_tx_sas_failure(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_SAS_Calibrated', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 26, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool eps_tx_sas_calibrated(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_EPS_WorkingCurrent', 'offset': 0.0, 'precision': 0.5, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 39, 'type': 'double', 'order': 'motorola', 'physical_unit': 'A'}
  double eps_tx_eps_workingcurrent(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_FailureSts', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 52, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool eps_tx_failurests(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace a45
}  // namespace canbus
}  // namespace apollo


