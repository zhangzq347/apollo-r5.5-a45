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

class Ems3278 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Ems3278();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'name': 'EMS_EngineRunningStatus', 'enum': {0: 'EMS_ENGINERUNNINGSTATUS_OFF', 1: 'EMS_ENGINERUNNINGSTATUS_ON'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 43, 'type': 'enum', 'order': 'intel', 'physical_unit': ''}
  Ems3_278::Ems_enginerunningstatusType ems_enginerunningstatus(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EMS_BrakePedleStatus', 'enum': {0: 'EMS_BRAKEPEDLESTATUS_NOT_PRESSED', 1: 'EMS_BRAKEPEDLESTATUS_PRESSED', 2: 'EMS_BRAKEPEDLESTATUS_RESERVED', 3: 'EMS_BRAKEPEDLESTATUS_ERROR'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 38, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Ems3_278::Ems_brakepedlestatusType ems_brakepedlestatus(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EMS_ErrorAcclerationPedal', 'enum': {0: 'EMS_ERRORACCLERATIONPEDAL_NO_ERROR', 1: 'EMS_ERRORACCLERATIONPEDAL_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 36, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Ems3_278::Ems_erroracclerationpedalType ems_erroracclerationpedal(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EMS_ErrorEngineSpeedSignal', 'enum': {0: 'EMS_ERRORENGINESPEEDSIGNAL_NO_ERROR', 1: 'EMS_ERRORENGINESPEEDSIGNAL_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 32, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Ems3_278::Ems_errorenginespeedsignalType ems_errorenginespeedsignal(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EMS_AccelerationPedalPosition', 'offset': 0.0, 'precision': 0.392, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|99.6]', 'bit': 31, 'type': 'double', 'order': 'motorola', 'physical_unit': '%'}
  double ems_accelerationpedalposition(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EMS_EngineSpeedRPM', 'offset': 0.0, 'precision': 0.25, 'len': 16, 'is_signed_var': False, 'physical_range': '[0|16383.5]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'rmp'}
  double ems_enginespeedrpm(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'EMS_EngineRunStatusForCvt', 'enum': {0: 'EMS_ENGINERUNSTATUSFORCVT_OFF', 1: 'EMS_ENGINERUNSTATUSFORCVT_RUNNING', 2: 'EMS_ENGINERUNSTATUSFORCVT_CRANKING', 3: 'EMS_ENGINERUNSTATUSFORCVT_SUSPENDING_OFF', 4: 'EMS_ENGINERUNSTATUSFORCVT_RESERVED', 5: 'EMS_ENGINERUNSTATUSFORCVT_RESERVED', 6: 'EMS_ENGINERUNSTATUSFORCVT_RESERVED', 7: 'EMS_ENGINERUNSTATUSFORCVT_FAULT'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 46, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Ems3_278::Ems_enginerunstatusforcvtType ems_enginerunstatusforcvt(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace a45
}  // namespace canbus
}  // namespace apollo


