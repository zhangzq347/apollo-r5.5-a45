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

class Epsstatus2231 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Epsstatus2231();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'name': 'EPS_Tx_EPS2_TorsionBarTrqValid', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 17, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool eps_tx_eps2_torsionbartrqvalid(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_EPS2_TorsionBarTrqDir', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 16, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool eps_tx_eps2_torsionbartrqdir(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_EPS2_TorsionBarTrq', 'offset': 0.0, 'precision': 0.01, 'len': 10, 'is_signed_var': False, 'physical_range': '[0|10.23]', 'bit': 1, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
  double eps_tx_eps2_torsionbartrq(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_EPS2_SystemFault', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 52, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool eps_tx_eps2_systemfault(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_EPS2_PASRequestfeedback', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 3, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool eps_tx_eps2_pasrequestfeedback(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_EPS2_PASEpasFailed', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 4, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool eps_tx_eps2_pasepasfailed(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_EPS2_PASAbortfeedback', 'offset': 0.0, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 2, 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool eps_tx_eps2_pasabortfeedback(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EPS_Tx_EPS2_LKSControlSts', 'offset': 0.0, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'physical_range': '[0|0]', 'bit': 20, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  int eps_tx_eps2_lkscontrolsts(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace a45
}  // namespace canbus
}  // namespace apollo


