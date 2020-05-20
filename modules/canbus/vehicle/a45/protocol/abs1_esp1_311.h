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

class Abs1esp1311 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Abs1esp1311();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'name': 'ABS_ESP_ABS_Active', 'enum': {0: 'ABS_ESP_ABS_ACTIVE_NOT_ACTIVE', 1: 'ABS_ESP_ABS_ACTIVE_ACTIVE'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 26, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Abs1_esp1_311::Abs_esp_abs_activeType abs_esp_abs_active(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'description': 'Quality/fault information to current vehicle speed information.', 'enum': {0: 'ABS_ESP_VEHSOSIGVALIDDATA_NOT_VALID', 1: 'ABS_ESP_VEHSOSIGVALIDDATA_VALID'}, 'precision': 1.0, 'len': 1, 'name': 'ABS_ESP_VehSOSigValidData', 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 8, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Abs1_esp1_311::Abs_esp_vehsosigvaliddataType abs_esp_vehsosigvaliddata(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'description': 'It will be ox1FFF when the value is more that 260km/h', 'offset': 0.0, 'precision': 0.05625, 'len': 13, 'name': 'ABS_ESP_VehicleSpeedVSOSig', 'is_signed_var': False, 'physical_range': '[0|260]', 'bit': 39, 'type': 'double', 'order': 'motorola', 'physical_unit': 'km/h'}
  double abs_esp_vehiclespeedvsosig(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'description': "Current wheel speed information of the front rignt wheel.For ABS the valid range high of the speed is 260km,but for ESP it's 360km.", 'offset': 0.0, 'precision': 0.05625, 'len': 13, 'name': 'ABS_ESP_FRWheelSpeed', 'is_signed_var': False, 'physical_range': '[0|360]', 'bit': 23, 'type': 'double', 'order': 'motorola', 'physical_unit': 'km/h'}
  double abs_esp_frwheelspeed(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'description': 'Quality/fault information to current wheel speed information of front left wheel.', 'enum': {0: 'ABS_ESP_FRWHSPEEDVALIDDATA_NOT_VALID', 1: 'ABS_ESP_FRWHSPEEDVALIDDATA_VALID'}, 'precision': 1.0, 'len': 1, 'name': 'ABS_ESP_FRWhSpeedValidData', 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 9, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Abs1_esp1_311::Abs_esp_frwhspeedvaliddataType abs_esp_frwhspeedvaliddata(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'description': 'Current wheel speed information of front left wheel. For ABS the valid range high is 260km,but for ESP the valid range high is 360km.', 'offset': 0.0, 'precision': 0.05625, 'len': 13, 'name': 'ABS_ESP_FLWheelSpeed', 'is_signed_var': False, 'physical_range': '[0|360]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'km/h'}
  double abs_esp_flwheelspeed(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'description': 'Quality/fault information to current wheel speed information of front left wheel.', 'enum': {0: 'ABS_ESP_FLWHSPEEDVALIDDATA_NOT_VALID', 1: 'ABS_ESP_FLWHSPEEDVALIDDATA_VALID'}, 'precision': 1.0, 'len': 1, 'name': 'ABS_ESP_FLWhSpeedValidData', 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 10, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Abs1_esp1_311::Abs_esp_flwhspeedvaliddataType abs_esp_flwhspeedvaliddata(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace a45
}  // namespace canbus
}  // namespace apollo


