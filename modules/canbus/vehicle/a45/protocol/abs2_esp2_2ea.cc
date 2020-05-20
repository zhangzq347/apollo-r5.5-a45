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

#include "modules/canbus/vehicle/a45/protocol/abs2_esp2_2ea.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

Abs2esp22ea::Abs2esp22ea() {}
const int32_t Abs2esp22ea::ID = 0x2EA;

void Abs2esp22ea::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_a45()->mutable_abs2_esp2_2ea()->set_abs_esp_rrwheelspeed(abs_esp_rrwheelspeed(bytes, length));
  chassis->mutable_a45()->mutable_abs2_esp2_2ea()->set_abs_esp_rlwheelspeed(abs_esp_rlwheelspeed(bytes, length));
  chassis->mutable_a45()->mutable_abs2_esp2_2ea()->set_abs_esp_rrwhspeedvaliddata(abs_esp_rrwhspeedvaliddata(bytes, length));
  chassis->mutable_a45()->mutable_abs2_esp2_2ea()->set_abs_esp_rlwhspeedvaliddata(abs_esp_rlwhspeedvaliddata(bytes, length));
}

// config detail: {'name': 'abs_esp_rrwheelspeed', 'offset': 0.0, 'precision': 0.05625, 'len': 13, 'is_signed_var': False, 'physical_range': '[0|360]', 'bit': 23, 'type': 'double', 'order': 'motorola', 'physical_unit': 'km/h'}
double Abs2esp22ea::abs_esp_rrwheelspeed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

  double ret = x * 0.056250;
  return ret;
}

// config detail: {'description': "Current speed information of rear left wheel.For ABS the valid range high is 260km/h,but for ESP it's 360.", 'offset': 0.0, 'precision': 0.05625, 'len': 13, 'name': 'abs_esp_rlwheelspeed', 'is_signed_var': False, 'physical_range': '[0|360]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'km/h'}
double Abs2esp22ea::abs_esp_rlwheelspeed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

  double ret = x * 0.056250;
  return ret;
}

// config detail: {'name': 'abs_esp_rrwhspeedvaliddata', 'enum': {0: 'ABS_ESP_RRWHSPEEDVALIDDATA_NOT_VALID', 1: 'ABS_ESP_RRWHSPEEDVALIDDATA_VALID'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 9, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Abs2_esp2_2ea::Abs_esp_rrwhspeedvaliddataType Abs2esp22ea::abs_esp_rrwhspeedvaliddata(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 1);

  Abs2_esp2_2ea::Abs_esp_rrwhspeedvaliddataType ret =  static_cast<Abs2_esp2_2ea::Abs_esp_rrwhspeedvaliddataType>(x);
  return ret;
}

// config detail: {'name': 'abs_esp_rlwhspeedvaliddata', 'enum': {0: 'ABS_ESP_RLWHSPEEDVALIDDATA_NOT_VALID', 1: 'ABS_ESP_RLWHSPEEDVALIDDATA_VALID'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 10, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Abs2_esp2_2ea::Abs_esp_rlwhspeedvaliddataType Abs2esp22ea::abs_esp_rlwhspeedvaliddata(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 1);

  Abs2_esp2_2ea::Abs_esp_rlwhspeedvaliddataType ret =  static_cast<Abs2_esp2_2ea::Abs_esp_rlwhspeedvaliddataType>(x);
  return ret;
}
}  // namespace a45
}  // namespace canbus
}  // namespace apollo
