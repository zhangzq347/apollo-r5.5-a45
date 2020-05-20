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

#include "modules/canbus/vehicle/a45/protocol/tcu1_1a0.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

Tcu11a0::Tcu11a0() {}
const int32_t Tcu11a0::ID = 0x1A0;

void Tcu11a0::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_a45()->mutable_tcu1_1a0()->set_tcu_st_gearleverposition(tcu_st_gearleverposition(bytes, length));
}

// config detail: {'name': 'tcu_st_gearleverposition', 'enum': {0: 'TCU_ST_GEARLEVERPOSITION_P', 1: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0X1', 2: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0X2', 3: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0X3', 4: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0X4', 5: 'TCU_ST_GEARLEVERPOSITION_D', 6: 'TCU_ST_GEARLEVERPOSITION_N', 7: 'TCU_ST_GEARLEVERPOSITION_R', 8: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0X8', 9: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0X9', 10: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0XA', 11: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0XB', 12: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0XC', 13: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0XD', 14: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0XE', 15: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0XF'}, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|15]', 'bit': 11, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Tcu1_1a0::Tcu_st_gearleverpositionType Tcu11a0::tcu_st_gearleverposition(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 4);

  Tcu1_1a0::Tcu_st_gearleverpositionType ret =  static_cast<Tcu1_1a0::Tcu_st_gearleverpositionType>(x);
  return ret;
}
}  // namespace a45
}  // namespace canbus
}  // namespace apollo
