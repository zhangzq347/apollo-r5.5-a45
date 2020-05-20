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

class Tcu11a0 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Tcu11a0();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'name': 'TCU_St_GearLeverPosition', 'enum': {0: 'TCU_ST_GEARLEVERPOSITION_P', 1: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0X1', 2: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0X2', 3: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0X3', 4: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0X4', 5: 'TCU_ST_GEARLEVERPOSITION_D', 6: 'TCU_ST_GEARLEVERPOSITION_N', 7: 'TCU_ST_GEARLEVERPOSITION_R', 8: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0X8', 9: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0X9', 10: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0XA', 11: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0XB', 12: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0XC', 13: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0XD', 14: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0XE', 15: 'TCU_ST_GEARLEVERPOSITION_DESCRIPTION_FOR_THE_VALUE_0XF'}, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|15]', 'bit': 11, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Tcu1_1a0::Tcu_st_gearleverpositionType tcu_st_gearleverposition(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace a45
}  // namespace canbus
}  // namespace apollo


