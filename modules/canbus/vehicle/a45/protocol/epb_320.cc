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

#include "modules/canbus/vehicle/a45/protocol/epb_320.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

Epb320::Epb320() {}
const int32_t Epb320::ID = 0x320;

void Epb320::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_a45()->mutable_epb_320()->set_epb_actuatorstate(epb_actuatorstate(bytes, length));
  chassis->mutable_a45()->mutable_epb_320()->set_epb_faultlamp(epb_faultlamp(bytes, length));
}

// config detail: {'name': 'epb_actuatorstate', 'enum': {0: 'EPB_ACTUATORSTATE_UNKNOWN', 1: 'EPB_ACTUATORSTATE_PARKAPPLIED', 2: 'EPB_ACTUATORSTATE_RELEASED', 3: 'EPB_ACTUATORSTATE_COMPLETELYRELEASED', 4: 'EPB_ACTUATORSTATE_APPLYING', 5: 'EPB_ACTUATORSTATE_RELEASING', 6: 'EPB_ACTUATORSTATE_DYNAMICBRAKING', 7: 'EPB_ACTUATORSTATE_OTHER_RESERVED'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 15, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Epb_320::Epb_actuatorstateType Epb320::epb_actuatorstate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(5, 3);

  Epb_320::Epb_actuatorstateType ret =  static_cast<Epb_320::Epb_actuatorstateType>(x);
  return ret;
}

// config detail: {'name': 'epb_faultlamp', 'enum': {0: 'EPB_FAULTLAMP_LAMP_OFF', 1: 'EPB_FAULTLAMP_LAMP_ON', 2: 'EPB_FAULTLAMP_LAMP_FLASH', 3: 'EPB_FAULTLAMP_RESERVED'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 7, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Epb_320::Epb_faultlampType Epb320::epb_faultlamp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 2);

  Epb_320::Epb_faultlampType ret =  static_cast<Epb_320::Epb_faultlampType>(x);
  return ret;
}
}  // namespace a45
}  // namespace canbus
}  // namespace apollo
