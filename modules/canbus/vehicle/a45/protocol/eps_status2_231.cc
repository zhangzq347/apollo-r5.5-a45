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

#include "modules/canbus/vehicle/a45/protocol/eps_status2_231.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

Epsstatus2231::Epsstatus2231() {}
const int32_t Epsstatus2231::ID = 0x231;

void Epsstatus2231::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_a45()->mutable_eps_status2_231()->set_eps_tx_eps2_torsionbartrqvalid(eps_tx_eps2_torsionbartrqvalid(bytes, length));
  chassis->mutable_a45()->mutable_eps_status2_231()->set_eps_tx_eps2_torsionbartrqdir(eps_tx_eps2_torsionbartrqdir(bytes, length));
  chassis->mutable_a45()->mutable_eps_status2_231()->set_eps_tx_eps2_torsionbartrq(eps_tx_eps2_torsionbartrq(bytes, length));
  chassis->mutable_a45()->mutable_eps_status2_231()->set_eps_tx_eps2_systemfault(eps_tx_eps2_systemfault(bytes, length));
  chassis->mutable_a45()->mutable_eps_status2_231()->set_eps_tx_eps2_pasrequestfeedback(eps_tx_eps2_pasrequestfeedback(bytes, length));
  chassis->mutable_a45()->mutable_eps_status2_231()->set_eps_tx_eps2_pasepasfailed(eps_tx_eps2_pasepasfailed(bytes, length));
  chassis->mutable_a45()->mutable_eps_status2_231()->set_eps_tx_eps2_pasabortfeedback(eps_tx_eps2_pasabortfeedback(bytes, length));
  chassis->mutable_a45()->mutable_eps_status2_231()->set_eps_tx_eps2_lkscontrolsts(eps_tx_eps2_lkscontrolsts(bytes, length));
}

// config detail: {'name': 'eps_tx_eps2_torsionbartrqvalid', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 17, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
bool Epsstatus2231::eps_tx_eps2_torsionbartrqvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'name': 'eps_tx_eps2_torsionbartrqdir', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 16, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
bool Epsstatus2231::eps_tx_eps2_torsionbartrqdir(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'name': 'eps_tx_eps2_torsionbartrq', 'offset': 0.0, 'precision': 0.01, 'len': 10, 'is_signed_var': False, 'physical_range': '[0|10.23]', 'bit': 1, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
double Epsstatus2231::eps_tx_eps2_torsionbartrq(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.010000;
  return ret;
}

// config detail: {'name': 'eps_tx_eps2_systemfault', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 52, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
bool Epsstatus2231::eps_tx_eps2_systemfault(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'name': 'eps_tx_eps2_pasrequestfeedback', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 3, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
bool Epsstatus2231::eps_tx_eps2_pasrequestfeedback(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'name': 'eps_tx_eps2_pasepasfailed', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 4, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
bool Epsstatus2231::eps_tx_eps2_pasepasfailed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'name': 'eps_tx_eps2_pasabortfeedback', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 2, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
bool Epsstatus2231::eps_tx_eps2_pasabortfeedback(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'name': 'eps_tx_eps2_lkscontrolsts', 'offset': 0.0, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 20, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
int Epsstatus2231::eps_tx_eps2_lkscontrolsts(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(2, 3);

  int ret = x;
  return ret;
}
}  // namespace a45
}  // namespace canbus
}  // namespace apollo
