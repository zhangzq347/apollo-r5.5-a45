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

class Esp4213 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Esp4213();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'name': 'ESP_LateralACC', 'offset': 0.0, 'precision': 0.00012207, 'len': 16, 'is_signed_var': True, 'physical_range': '[-4|4]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'g'}
  double esp_lateralacc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'ESP_LongitudeACC', 'offset': 0.0, 'precision': 0.00012207, 'len': 16, 'is_signed_var': True, 'physical_range': '[-4|4]', 'bit': 23, 'type': 'double', 'order': 'motorola', 'physical_unit': 'g'}
  double esp_longitudeacc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'ESP_VeDynYawRate', 'offset': -128.0, 'precision': 0.00390625, 'len': 16, 'is_signed_var': False, 'physical_range': '[-128|128]', 'bit': 39, 'type': 'double', 'order': 'motorola', 'physical_unit': 'deg/s'}
  double esp_vedynyawrate(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'ESP_LongitudeACCValid', 'enum': {0: 'ESP_LONGITUDEACCVALID_VALID', 1: 'ESP_LONGITUDEACCVALID_NOT_VALID'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 54, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Esp4_213::Esp_longitudeaccvalidType esp_longitudeaccvalid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'ESP_LateralACCValid', 'enum': {0: 'ESP_LATERALACCVALID_VALID', 1: 'ESP_LATERALACCVALID_NOT_VALID'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 55, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Esp4_213::Esp_lateralaccvalidType esp_lateralaccvalid(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace a45
}  // namespace canbus
}  // namespace apollo


