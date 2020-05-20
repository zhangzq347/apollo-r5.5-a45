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

#include "modules/canbus/vehicle/a45/protocol/esp4_213.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

Esp4213::Esp4213() {}
const int32_t Esp4213::ID = 0x213;

void Esp4213::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_a45()->mutable_esp4_213()->set_esp_lateralacc(esp_lateralacc(bytes, length));
  chassis->mutable_a45()->mutable_esp4_213()->set_esp_longitudeacc(esp_longitudeacc(bytes, length));
  chassis->mutable_a45()->mutable_esp4_213()->set_esp_vedynyawrate(esp_vedynyawrate(bytes, length));
  chassis->mutable_a45()->mutable_esp4_213()->set_esp_longitudeaccvalid(esp_longitudeaccvalid(bytes, length));
  chassis->mutable_a45()->mutable_esp4_213()->set_esp_lateralaccvalid(esp_lateralaccvalid(bytes, length));
}

// config detail: {'name': 'esp_lateralacc', 'offset': 0.0, 'precision': 0.00012207, 'len': 16, 'is_signed_var': True, 'physical_range': '[-4|4]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'g'}
double Esp4213::esp_lateralacc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x <<= 16;
  x >>= 16;

  double ret = x * 0.000122;
  return ret;
}

// config detail: {'name': 'esp_longitudeacc', 'offset': 0.0, 'precision': 0.00012207, 'len': 16, 'is_signed_var': True, 'physical_range': '[-4|4]', 'bit': 23, 'type': 'double', 'order': 'motorola', 'physical_unit': 'g'}
double Esp4213::esp_longitudeacc(const std::uint8_t* bytes, int32_t length) const {

  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 7);
  int32_t f = t0.get_byte(7, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.00012207 ;

  if (f == 1)
  {
    ret = ret - 4;
    return ret;
  } else {
    return ret;
  }
}

// config detail: {'name': 'esp_vedynyawrate', 'offset': -128.0, 'precision': 0.00390625, 'len': 16, 'is_signed_var': False, 'physical_range': '[-128|128]', 'bit': 39, 'type': 'double', 'order': 'motorola', 'physical_unit': 'deg/s'}
double Esp4213::esp_vedynyawrate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.003906 + -128.000000;
  return ret;
}

// config detail: {'name': 'esp_longitudeaccvalid', 'enum': {0: 'ESP_LONGITUDEACCVALID_VALID', 1: 'ESP_LONGITUDEACCVALID_NOT_VALID'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 54, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Esp4_213::Esp_longitudeaccvalidType Esp4213::esp_longitudeaccvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(6, 1);

  Esp4_213::Esp_longitudeaccvalidType ret =  static_cast<Esp4_213::Esp_longitudeaccvalidType>(x);
  return ret;
}

// config detail: {'name': 'esp_lateralaccvalid', 'enum': {0: 'ESP_LATERALACCVALID_VALID', 1: 'ESP_LATERALACCVALID_NOT_VALID'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 55, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Esp4_213::Esp_lateralaccvalidType Esp4213::esp_lateralaccvalid(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(7, 1);

  Esp4_213::Esp_lateralaccvalidType ret =  static_cast<Esp4_213::Esp_lateralaccvalidType>(x);
  return ret;
}
}  // namespace a45
}  // namespace canbus
}  // namespace apollo
