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

#include "modules/canbus/vehicle/a45/protocol/ems13_279.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

Ems13279::Ems13279() {}
const int32_t Ems13279::ID = 0x279;

void Ems13279::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_a45()->mutable_ems13_279()->set_ems_accpedalposact(ems_accpedalposact(bytes, length));
  chassis->mutable_a45()->mutable_ems13_279()->set_ems_erroraccpedalposact(ems_erroraccpedalposact(bytes, length));
}

// config detail: {'name': 'ems_accpedalposact', 'offset': 0.0, 'precision': 0.392, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|99.6]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': '%'}
double Ems13279::ems_accpedalposact(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 0.392000;
  return ret;
}

// config detail: {'name': 'ems_erroraccpedalposact', 'enum': {0: 'EMS_ERRORACCPEDALPOSACT_NO_ERROR', 1: 'EMS_ERRORACCPEDALPOSACT_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 8, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Ems13_279::Ems_erroraccpedalposactType Ems13279::ems_erroraccpedalposact(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 1);

  Ems13_279::Ems_erroraccpedalposactType ret =  static_cast<Ems13_279::Ems_erroraccpedalposactType>(x);
  return ret;
}
}  // namespace a45
}  // namespace canbus
}  // namespace apollo
