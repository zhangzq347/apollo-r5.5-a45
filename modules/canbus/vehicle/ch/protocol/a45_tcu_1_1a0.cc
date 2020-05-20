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
 *
 * 此模块用于A45的TCU1报文解析，并对类的定义及函数定义（20200508-张智清）
 * TCU1报文主要解析车辆档位状态
 *****************************************************************************/

#include "modules/canbus/vehicle/ch/protocol/a45_tcu_1_1a0.h"
#include "glog/logging.h"
#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

A45TCU11A0::A45TCU11A0() {}
const int32_t A45TCU11A0::ID = 0x1A0;

void A45TCU11A0::Parse(const std::uint8_t* bytes, int32_t length,
                          ChassisDetail* chassis) const {
  chassis->mutable_ch()->mutable_a45_tcu_1_1a0()->set_a45_gear_sts(
      a45_gear_sts(bytes, length));
}

A45_TCU_1A0::A45_Gear_stsType A45TCU11A0::a45_gear_sts(const std::uint8_t* bytes,
                                                      int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 5);

  A45_TCU_1A0::A45_Gear_stsType ret =
	  static_cast<A45_TCU_1A0::A45_Gear_stsType>(x);
  return ret;
}  //根据DBC解析档位信号的实际值

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
