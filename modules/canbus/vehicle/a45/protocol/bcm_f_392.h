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

class Bcmf392 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Bcmf392();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'name': 'BCM_F_TurnRightSwitch', 'enum': {0: 'BCM_F_TURNRIGHTSWITCH_NOT_ACTIVE', 1: 'BCM_F_TURNRIGHTSWITCH_AVTIVE'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 49, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Bcm_f_392::Bcm_f_turnrightswitchType bcm_f_turnrightswitch(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'BCM_F_TurnLeftSwitch', 'enum': {0: 'BCM_F_TURNLEFTSWITCH_NOT_ACTIVE', 1: 'BCM_F_TURNLEFTSWITCH_AVTIVE'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 50, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Bcm_f_392::Bcm_f_turnleftswitchType bcm_f_turnleftswitch(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'BCM_F_FrontWiperSwitchStatus', 'enum': {0: 'BCM_F_FRONTWIPERSWITCHSTATUS_OFF', 1: 'BCM_F_FRONTWIPERSWITCHSTATUS_LOW', 2: 'BCM_F_FRONTWIPERSWITCHSTATUS_HIGH', 3: 'BCM_F_FRONTWIPERSWITCHSTATUS_INTER', 4: 'BCM_F_FRONTWIPERSWITCHSTATUS_AUTO', 5: 'BCM_F_FRONTWIPERSWITCHSTATUS_RESERVED', 6: 'BCM_F_FRONTWIPERSWITCHSTATUS_RESERVED', 7: 'BCM_F_FRONTWIPERSWITCHSTATUS_RESERVED'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 39, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Bcm_f_392::Bcm_f_frontwiperswitchstatusType bcm_f_frontwiperswitchstatus(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'BCM_F_HazardStatus', 'enum': {0: 'BCM_F_HAZARDSTATUS_OFF', 1: 'BCM_F_HAZARDSTATUS_ACTIVE'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 6, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Bcm_f_392::Bcm_f_hazardstatusType bcm_f_hazardstatus(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace a45
}  // namespace canbus
}  // namespace apollo


