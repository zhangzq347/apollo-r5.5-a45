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

#include "modules/canbus/vehicle/a45/protocol/ems3_278.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

Ems3278::Ems3278() {}
const int32_t Ems3278::ID = 0x278;

void Ems3278::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_a45()->mutable_ems3_278()->set_ems_enginerunningstatus(ems_enginerunningstatus(bytes, length));
  chassis->mutable_a45()->mutable_ems3_278()->set_ems_brakepedlestatus(ems_brakepedlestatus(bytes, length));
  chassis->mutable_a45()->mutable_ems3_278()->set_ems_erroracclerationpedal(ems_erroracclerationpedal(bytes, length));
  chassis->mutable_a45()->mutable_ems3_278()->set_ems_errorenginespeedsignal(ems_errorenginespeedsignal(bytes, length));
  chassis->mutable_a45()->mutable_ems3_278()->set_ems_accelerationpedalposition(ems_accelerationpedalposition(bytes, length));
  chassis->mutable_a45()->mutable_ems3_278()->set_ems_enginespeedrpm(ems_enginespeedrpm(bytes, length));
  chassis->mutable_a45()->mutable_ems3_278()->set_ems_enginerunstatusforcvt(ems_enginerunstatusforcvt(bytes, length));
}

// config detail: {'name': 'ems_enginerunningstatus', 'enum': {0: 'EMS_ENGINERUNNINGSTATUS_OFF', 1: 'EMS_ENGINERUNNINGSTATUS_ON'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 43, 'type': 'enum', 'order': 'intel', 'physical_unit': ''}
Ems3_278::Ems_enginerunningstatusType Ems3278::ems_enginerunningstatus(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(3, 1);

  Ems3_278::Ems_enginerunningstatusType ret =  static_cast<Ems3_278::Ems_enginerunningstatusType>(x);
  return ret;
}

// config detail: {'name': 'ems_brakepedlestatus', 'enum': {0: 'EMS_BRAKEPEDLESTATUS_NOT_PRESSED', 1: 'EMS_BRAKEPEDLESTATUS_PRESSED', 2: 'EMS_BRAKEPEDLESTATUS_RESERVED', 3: 'EMS_BRAKEPEDLESTATUS_ERROR'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 38, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Ems3_278::Ems_brakepedlestatusType Ems3278::ems_brakepedlestatus(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 2);

  Ems3_278::Ems_brakepedlestatusType ret =  static_cast<Ems3_278::Ems_brakepedlestatusType>(x);
  return ret;
}

// config detail: {'name': 'ems_erroracclerationpedal', 'enum': {0: 'EMS_ERRORACCLERATIONPEDAL_NO_ERROR', 1: 'EMS_ERRORACCLERATIONPEDAL_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 36, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Ems3_278::Ems_erroracclerationpedalType Ems3278::ems_erroracclerationpedal(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 1);

  Ems3_278::Ems_erroracclerationpedalType ret =  static_cast<Ems3_278::Ems_erroracclerationpedalType>(x);
  return ret;
}

// config detail: {'name': 'ems_errorenginespeedsignal', 'enum': {0: 'EMS_ERRORENGINESPEEDSIGNAL_NO_ERROR', 1: 'EMS_ERRORENGINESPEEDSIGNAL_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 32, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Ems3_278::Ems_errorenginespeedsignalType Ems3278::ems_errorenginespeedsignal(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 1);

  Ems3_278::Ems_errorenginespeedsignalType ret =  static_cast<Ems3_278::Ems_errorenginespeedsignalType>(x);
  return ret;
}

// config detail: {'name': 'ems_accelerationpedalposition', 'offset': 0.0, 'precision': 0.392, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|99.6]', 'bit': 31, 'type': 'double', 'order': 'motorola', 'physical_unit': '%'}
double Ems3278::ems_accelerationpedalposition(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 0.392000;
  return ret;
}

// config detail: {'name': 'ems_enginespeedrpm', 'offset': 0.0, 'precision': 0.25, 'len': 16, 'is_signed_var': False, 'physical_range': '[0|16383.5]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'rmp'}
double Ems3278::ems_enginespeedrpm(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.250000;
  return ret;
}

// config detail: {'name': 'ems_enginerunstatusforcvt', 'enum': {0: 'EMS_ENGINERUNSTATUSFORCVT_OFF', 1: 'EMS_ENGINERUNSTATUSFORCVT_RUNNING', 2: 'EMS_ENGINERUNSTATUSFORCVT_CRANKING', 3: 'EMS_ENGINERUNSTATUSFORCVT_SUSPENDING_OFF', 4: 'EMS_ENGINERUNSTATUSFORCVT_RESERVED', 5: 'EMS_ENGINERUNSTATUSFORCVT_RESERVED', 6: 'EMS_ENGINERUNSTATUSFORCVT_RESERVED', 7: 'EMS_ENGINERUNSTATUSFORCVT_FAULT'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 46, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
Ems3_278::Ems_enginerunstatusforcvtType Ems3278::ems_enginerunstatusforcvt(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(4, 3);

  Ems3_278::Ems_enginerunstatusforcvtType ret =  static_cast<Ems3_278::Ems_enginerunstatusforcvtType>(x);
  return ret;
}
}  // namespace a45
}  // namespace canbus
}  // namespace apollo
