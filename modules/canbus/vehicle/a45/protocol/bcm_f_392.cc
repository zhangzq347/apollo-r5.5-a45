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

#include "modules/canbus/vehicle/a45/protocol/bcm_f_392.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

Bcmf392::Bcmf392() {}
const int32_t Bcmf392::ID = 0x392;

void Bcmf392::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_a45()->mutable_bcm_f_392()->set_bcm_f_turnrightswitch(bcm_f_turnrightswitch(bytes, length));
  chassis->mutable_a45()->mutable_bcm_f_392()->set_bcm_f_turnleftswitch(bcm_f_turnleftswitch(bytes, length));
  chassis->mutable_a45()->mutable_bcm_f_392()->set_bcm_f_frontwiperswitchstatus(bcm_f_frontwiperswitchstatus(bytes, length));
  chassis->mutable_a45()->mutable_bcm_f_392()->set_bcm_f_hazardstatus(bcm_f_hazardstatus(bytes, length));
}

// config detail: {'name': 'bcm_f_turnrightswitch', 'enum': {0: 'BCM_F_TURNRIGHTSWITCH_NOT_ACTIVE', 1: 'BCM_F_TURNRIGHTSWITCH_AVTIVE'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 49, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Bcm_f_392::Bcm_f_turnrightswitchType Bcmf392::bcm_f_turnrightswitch(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(1, 1);

  Bcm_f_392::Bcm_f_turnrightswitchType ret =  static_cast<Bcm_f_392::Bcm_f_turnrightswitchType>(x);
  return ret;
}

// config detail: {'name': 'bcm_f_turnleftswitch', 'enum': {0: 'BCM_F_TURNLEFTSWITCH_NOT_ACTIVE', 1: 'BCM_F_TURNLEFTSWITCH_AVTIVE'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 50, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Bcm_f_392::Bcm_f_turnleftswitchType Bcmf392::bcm_f_turnleftswitch(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(2, 1);

  Bcm_f_392::Bcm_f_turnleftswitchType ret =  static_cast<Bcm_f_392::Bcm_f_turnleftswitchType>(x);
  return ret;
}

// config detail: {'name': 'bcm_f_frontwiperswitchstatus', 'enum': {0: 'BCM_F_FRONTWIPERSWITCHSTATUS_OFF', 1: 'BCM_F_FRONTWIPERSWITCHSTATUS_LOW', 2: 'BCM_F_FRONTWIPERSWITCHSTATUS_HIGH', 3: 'BCM_F_FRONTWIPERSWITCHSTATUS_INTER', 4: 'BCM_F_FRONTWIPERSWITCHSTATUS_AUTO', 5: 'BCM_F_FRONTWIPERSWITCHSTATUS_RESERVED', 6: 'BCM_F_FRONTWIPERSWITCHSTATUS_RESERVED', 7: 'BCM_F_FRONTWIPERSWITCHSTATUS_RESERVED'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 39, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Bcm_f_392::Bcm_f_frontwiperswitchstatusType Bcmf392::bcm_f_frontwiperswitchstatus(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 3);

  Bcm_f_392::Bcm_f_frontwiperswitchstatusType ret =  static_cast<Bcm_f_392::Bcm_f_frontwiperswitchstatusType>(x);
  return ret;
}

// config detail: {'name': 'bcm_f_hazardstatus', 'enum': {0: 'BCM_F_HAZARDSTATUS_OFF', 1: 'BCM_F_HAZARDSTATUS_ACTIVE'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 6, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Bcm_f_392::Bcm_f_hazardstatusType Bcmf392::bcm_f_hazardstatus(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 1);

  Bcm_f_392::Bcm_f_hazardstatusType ret =  static_cast<Bcm_f_392::Bcm_f_hazardstatusType>(x);
  return ret;
}
}  // namespace a45
}  // namespace canbus
}  // namespace apollo
