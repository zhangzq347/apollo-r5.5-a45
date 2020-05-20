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

#include "modules/canbus/vehicle/a45/protocol/eps_status1_230.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

Epsstatus1230::Epsstatus1230() {}
const int32_t Epsstatus1230::ID = 0x230;

void Epsstatus1230::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_a45()->mutable_eps_status1_230()->set_eps_tx_eps_workstatus(eps_tx_eps_workstatus(bytes, length));
  chassis->mutable_a45()->mutable_eps_status1_230()->set_eps_tx_eps_driverstrdtd_valid(eps_tx_eps_driverstrdtd_valid(bytes, length));
  chassis->mutable_a45()->mutable_eps_status1_230()->set_eps_tx_eps_driverstrdtd(eps_tx_eps_driverstrdtd(bytes, length));
  chassis->mutable_a45()->mutable_eps_status1_230()->set_eps_tx_sas_steeringanglespeed(eps_tx_sas_steeringanglespeed(bytes, length));
  chassis->mutable_a45()->mutable_eps_status1_230()->set_eps_tx_sas_steeringangle(eps_tx_sas_steeringangle(bytes, length));
  chassis->mutable_a45()->mutable_eps_status1_230()->set_eps_tx_sas_failure(eps_tx_sas_failure(bytes, length));
  chassis->mutable_a45()->mutable_eps_status1_230()->set_eps_tx_sas_calibrated(eps_tx_sas_calibrated(bytes, length));
  chassis->mutable_a45()->mutable_eps_status1_230()->set_eps_tx_eps_workingcurrent(eps_tx_eps_workingcurrent(bytes, length));
  chassis->mutable_a45()->mutable_eps_status1_230()->set_eps_tx_failurests(eps_tx_failurests(bytes, length));
}

// config detail: {'name': 'eps_tx_eps_workstatus', 'offset': 0.0, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'physical_range': '[0|3]', 'bit': 47, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
int Epsstatus1230::eps_tx_eps_workstatus(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 2);

  int ret = x;
  return ret;
}

// config detail: {'name': 'eps_tx_eps_driverstrdtd_valid', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 45, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
bool Epsstatus1230::eps_tx_eps_driverstrdtd_valid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'name': 'eps_tx_eps_driverstrdtd', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 44, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
bool Epsstatus1230::eps_tx_eps_driverstrdtd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'name': 'eps_tx_sas_steeringanglespeed', 'offset': 0.0, 'precision': 4.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|1020]', 'bit': 23, 'type': 'double', 'order': 'motorola', 'physical_unit': 'deg/s'}
double Epsstatus1230::eps_tx_sas_steeringanglespeed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 4.000000;
  return ret;
}

// config detail: {'name': 'eps_tx_sas_steeringangle', 'offset': -2048.0, 'precision': 0.0625, 'len': 16, 'is_signed_var': False, 'physical_range': '[-2048|2047.9375]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'deg'}
double Epsstatus1230::eps_tx_sas_steeringangle(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.062500 + -2048.000000;
  return ret;
}

// config detail: {'name': 'eps_tx_sas_failure', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 31, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
bool Epsstatus1230::eps_tx_sas_failure(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'name': 'eps_tx_sas_calibrated', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 26, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
bool Epsstatus1230::eps_tx_sas_calibrated(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'name': 'eps_tx_eps_workingcurrent', 'offset': 0.0, 'precision': 0.5, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 39, 'type': 'double', 'order': 'motorola', 'physical_unit': 'A'}
double Epsstatus1230::eps_tx_eps_workingcurrent(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 0.500000;
  return ret;
}

// config detail: {'name': 'eps_tx_failurests', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 52, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
bool Epsstatus1230::eps_tx_failurests(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}
}  // namespace a45
}  // namespace canbus
}  // namespace apollo
