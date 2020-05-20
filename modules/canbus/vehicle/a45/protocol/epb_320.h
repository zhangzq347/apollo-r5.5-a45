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

class Epb320 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Epb320();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'name': 'EPB_ActuatorState', 'enum': {0: 'EPB_ACTUATORSTATE_UNKNOWN', 1: 'EPB_ACTUATORSTATE_PARKAPPLIED', 2: 'EPB_ACTUATORSTATE_RELEASED', 3: 'EPB_ACTUATORSTATE_COMPLETELYRELEASED', 4: 'EPB_ACTUATORSTATE_APPLYING', 5: 'EPB_ACTUATORSTATE_RELEASING', 6: 'EPB_ACTUATORSTATE_DYNAMICBRAKING', 7: 'EPB_ACTUATORSTATE_OTHER_RESERVED'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 15, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Epb_320::Epb_actuatorstateType epb_actuatorstate(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPB_FaultLamp', 'enum': {0: 'EPB_FAULTLAMP_LAMP_OFF', 1: 'EPB_FAULTLAMP_LAMP_ON', 2: 'EPB_FAULTLAMP_LAMP_FLASH', 3: 'EPB_FAULTLAMP_RESERVED'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 7, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Epb_320::Epb_faultlampType epb_faultlamp(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace a45
}  // namespace canbus
}  // namespace apollo


