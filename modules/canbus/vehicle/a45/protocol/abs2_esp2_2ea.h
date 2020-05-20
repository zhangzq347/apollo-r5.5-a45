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

class Abs2esp22ea : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Abs2esp22ea();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'name': 'ABS_ESP_RRWheelSpeed', 'offset': 0.0, 'precision': 0.05625, 'len': 13, 'is_signed_var': False, 'physical_range': '[0|360]', 'bit': 23, 'type': 'double', 'order': 'motorola', 'physical_unit': 'km/h'}
  double abs_esp_rrwheelspeed(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'description': "Current speed information of rear left wheel.For ABS the valid range high is 260km/h,but for ESP it's 360.", 'offset': 0.0, 'precision': 0.05625, 'len': 13, 'name': 'ABS_ESP_RLWheelSpeed', 'is_signed_var': False, 'physical_range': '[0|360]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'km/h'}
  double abs_esp_rlwheelspeed(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'ABS_ESP_RRWhSpeedValidData', 'enum': {0: 'ABS_ESP_RRWHSPEEDVALIDDATA_NOT_VALID', 1: 'ABS_ESP_RRWHSPEEDVALIDDATA_VALID'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 9, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Abs2_esp2_2ea::Abs_esp_rrwhspeedvaliddataType abs_esp_rrwhspeedvaliddata(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'ABS_ESP_RLWhSpeedValidData', 'enum': {0: 'ABS_ESP_RLWHSPEEDVALIDDATA_NOT_VALID', 1: 'ABS_ESP_RLWHSPEEDVALIDDATA_VALID'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 10, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Abs2_esp2_2ea::Abs_esp_rlwhspeedvaliddataType abs_esp_rlwhspeedvaliddata(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace a45
}  // namespace canbus
}  // namespace apollo


