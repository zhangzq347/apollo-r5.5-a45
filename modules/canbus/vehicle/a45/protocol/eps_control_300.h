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

class Epscontrol300 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Epscontrol300();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'name': 'EPS_Rx_APA_TargetAngle', 'offset': 0.0, 'precision': 0.1, 'len': 16, 'is_signed_var': True, 'physical_range': '[-720|720]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'deg'}
  Epscontrol300* set_eps_control_targetangle(double eps_control_targetangle);

  // config detail: {'name': 'EPS_Rx_APA_ControlRequest', 'offset': 0.0, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 39, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  Epscontrol300* set_eps_control_request(Eps_control_300::Eps_control_requestType  eps_control_request);

 private:

  // config detail: {'name': 'EPS_Rx_APA_TargetAngle', 'offset': 0.0, 'precision': 0.1, 'len': 16, 'is_signed_var': True, 'physical_range': '[-720|720]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'deg'}
  void set_p_eps_control_targetangle(uint8_t* data, double eps_control_targetangle);

  // config detail: {'name': 'EPS_Rx_APA_ControlRequest', 'offset': 0.0, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 39, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  void set_p_eps_control_request(uint8_t* data,
      Eps_control_300::Eps_control_requestType  eps_control_request);

 private:
  double eps_control_targetangle_;
  Eps_control_300::Eps_control_requestType  eps_control_request_;
};

}  // namespace a45
}  // namespace canbus
}  // namespace apollo


