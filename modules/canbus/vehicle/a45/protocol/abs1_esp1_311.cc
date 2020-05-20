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

#include "modules/canbus/vehicle/a45/protocol/abs1_esp1_311.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

Abs1esp1311::Abs1esp1311() {}
const int32_t Abs1esp1311::ID = 0x311;

void Abs1esp1311::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_a45()->mutable_abs1_esp1_311()->set_abs_esp_abs_active(abs_esp_abs_active(bytes, length));
  chassis->mutable_a45()->mutable_abs1_esp1_311()->set_abs_esp_vehsosigvaliddata(abs_esp_vehsosigvaliddata(bytes, length));
  chassis->mutable_a45()->mutable_abs1_esp1_311()->set_abs_esp_vehiclespeedvsosig(abs_esp_vehiclespeedvsosig(bytes, length));
  chassis->mutable_a45()->mutable_abs1_esp1_311()->set_abs_esp_frwheelspeed(abs_esp_frwheelspeed(bytes, length));
  chassis->mutable_a45()->mutable_abs1_esp1_311()->set_abs_esp_frwhspeedvaliddata(abs_esp_frwhspeedvaliddata(bytes, length));
  chassis->mutable_a45()->mutable_abs1_esp1_311()->set_abs_esp_flwheelspeed(abs_esp_flwheelspeed(bytes, length));
  chassis->mutable_a45()->mutable_abs1_esp1_311()->set_abs_esp_flwhspeedvaliddata(abs_esp_flwhspeedvaliddata(bytes, length));
}

// config detail: {'name': 'abs_esp_abs_active', 'enum': {0: 'ABS_ESP_ABS_ACTIVE_NOT_ACTIVE', 1: 'ABS_ESP_ABS_ACTIVE_ACTIVE'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 26, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Abs1_esp1_311::Abs_esp_abs_activeType Abs1esp1311::abs_esp_abs_active(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(2, 1);

  Abs1_esp1_311::Abs_esp_abs_activeType ret =  static_cast<Abs1_esp1_311::Abs_esp_abs_activeType>(x);
  return ret;
}

// config detail: {'description': 'Quality/fault information to current vehicle speed information.', 'enum': {0: 'ABS_ESP_VEHSOSIGVALIDDATA_NOT_VALID', 1: 'ABS_ESP_VEHSOSIGVALIDDATA_VALID'}, 'precision': 1.0, 'len': 1, 'name': 'abs_esp_vehsosigvaliddata', 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 8, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Abs1_esp1_311::Abs_esp_vehsosigvaliddataType Abs1esp1311::abs_esp_vehsosigvaliddata(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 1);

  Abs1_esp1_311::Abs_esp_vehsosigvaliddataType ret =  static_cast<Abs1_esp1_311::Abs_esp_vehsosigvaliddataType>(x);
  return ret;
}

// config detail: {'description': 'It will be ox1FFF when the value is more that 260km/h', 'offset': 0.0, 'precision': 0.05625, 'len': 13, 'name': 'abs_esp_vehiclespeedvsosig', 'is_signed_var': False, 'physical_range': '[0|260]', 'bit': 39, 'type': 'double', 'order': 'motorola', 'physical_unit': 'km/h'}
double Abs1esp1311::abs_esp_vehiclespeedvsosig(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

  double ret = x * 0.056250;
  return ret;
}

// config detail: {'description': "Current wheel speed information of the front rignt wheel.For ABS the valid range high of the speed is 260km,but for ESP it's 360km.", 'offset': 0.0, 'precision': 0.05625, 'len': 13, 'name': 'abs_esp_frwheelspeed', 'is_signed_var': False, 'physical_range': '[0|360]', 'bit': 23, 'type': 'double', 'order': 'motorola', 'physical_unit': 'km/h'}
double Abs1esp1311::abs_esp_frwheelspeed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

  double ret = x * 0.056250;
  return ret;
}

// config detail: {'description': 'Quality/fault information to current wheel speed information of front left wheel.', 'enum': {0: 'ABS_ESP_FRWHSPEEDVALIDDATA_NOT_VALID', 1: 'ABS_ESP_FRWHSPEEDVALIDDATA_VALID'}, 'precision': 1.0, 'len': 1, 'name': 'abs_esp_frwhspeedvaliddata', 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 9, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Abs1_esp1_311::Abs_esp_frwhspeedvaliddataType Abs1esp1311::abs_esp_frwhspeedvaliddata(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 1);

  Abs1_esp1_311::Abs_esp_frwhspeedvaliddataType ret =  static_cast<Abs1_esp1_311::Abs_esp_frwhspeedvaliddataType>(x);
  return ret;
}

// config detail: {'description': 'Current wheel speed information of front left wheel. For ABS the valid range high is 260km,but for ESP the valid range high is 360km.', 'offset': 0.0, 'precision': 0.05625, 'len': 13, 'name': 'abs_esp_flwheelspeed', 'is_signed_var': False, 'physical_range': '[0|360]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'km/h'}
double Abs1esp1311::abs_esp_flwheelspeed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(3, 5);
  x <<= 5;
  x |= t;

  double ret = x * 0.056250;
  return ret;
}

// config detail: {'description': 'Quality/fault information to current wheel speed information of front left wheel.', 'enum': {0: 'ABS_ESP_FLWHSPEEDVALIDDATA_NOT_VALID', 1: 'ABS_ESP_FLWHSPEEDVALIDDATA_VALID'}, 'precision': 1.0, 'len': 1, 'name': 'abs_esp_flwhspeedvaliddata', 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 10, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Abs1_esp1_311::Abs_esp_flwhspeedvaliddataType Abs1esp1311::abs_esp_flwhspeedvaliddata(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 1);

  Abs1_esp1_311::Abs_esp_flwhspeedvaliddataType ret =  static_cast<Abs1_esp1_311::Abs_esp_flwhspeedvaliddataType>(x);
  return ret;
}
}  // namespace a45
}  // namespace canbus
}  // namespace apollo
