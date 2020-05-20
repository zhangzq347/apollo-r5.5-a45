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

#include "modules/canbus/vehicle/a45/protocol/ems11_28a.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

Ems1128a::Ems1128a() {}
const int32_t Ems1128a::ID = 0x28A;

void Ems1128a::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_a45()->mutable_ems11_28a()->set_ems_acc_ecgpovrd(ems_acc_ecgpovrd(bytes, length));
}

// config detail: {'name': 'ems_acc_ecgpovrd', 'enum': {0: 'EMS_ACC_ECGPOVRD_NO_OVERRIDE', 1: 'EMS_ACC_ECGPOVRD_DRIVER_OVERRIDE'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 18, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Ems11_28a::Ems_acc_ecgpovrdType Ems1128a::ems_acc_ecgpovrd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(2, 1);

  Ems11_28a::Ems_acc_ecgpovrdType ret =  static_cast<Ems11_28a::Ems_acc_ecgpovrdType>(x);
  return ret;
}
}  // namespace a45
}  // namespace canbus
}  // namespace apollo
