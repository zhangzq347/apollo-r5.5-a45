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

#include "modules/canbus/vehicle/a45/protocol/eps_control_300.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

const int32_t Epscontrol300::ID = 0x300;

// public
Epscontrol300::Epscontrol300() { Reset(); }

uint32_t Epscontrol300::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Epscontrol300::UpdateData(uint8_t* data) {
  set_p_eps_control_targetangle(data, eps_control_targetangle_);
  set_p_eps_control_request(data, eps_control_request_);
}

void Epscontrol300::Reset() {
  // TODO(All) :  you should check this manually
  eps_control_targetangle_ = 0.0;
  eps_control_request_ = Eps_control_300::EPS_CONTROL_NO_REQUEST;
}

Epscontrol300* Epscontrol300::set_eps_control_targetangle(
    double eps_control_targetangle) {
  eps_control_targetangle_ = eps_control_targetangle;
  return this;
 }

// config detail: {'name': 'EPS_Rx_APA_TargetAngle', 'offset': 0.0, 'precision': 0.1, 'len': 16, 'is_signed_var': True, 'physical_range': '[-720|720]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'deg'}
void Epscontrol300::set_p_eps_control_targetangle(uint8_t* data,
    double eps_control_targetangle) {
  eps_control_targetangle = ProtocolData::BoundedValue(-720.0, 720.0, eps_control_targetangle);
  int x = eps_control_targetangle * 10;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 1);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 0);
  to_set1.set_value(t, 0, 8);
}


Epscontrol300* Epscontrol300::set_eps_control_request(
    Eps_control_300::Eps_control_requestType eps_control_request) {
  eps_control_request_ = eps_control_request;
  return this;
 }

// config detail: {'name': 'EPS_Rx_APA_ControlRequest', 'offset': 0.0, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 39, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
void Epscontrol300::set_p_eps_control_request(uint8_t* data,
    Eps_control_300::Eps_control_requestType eps_control_request) {
  int x = eps_control_request;

  Byte to_set(data + 4);
  to_set.set_value(x, 6, 2);
}

}  // namespace a45
}  // namespace canbus
}  // namespace apollo
