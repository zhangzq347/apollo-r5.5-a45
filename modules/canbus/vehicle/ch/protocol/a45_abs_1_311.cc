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
 * 此模块用于A45的ABS1报文解析，对A45ABS1311类的定义及函数定义（20200508-张智清）
 * ABS1报文主要解析车辆实际速度信号
 *****************************************************************************/

#include "modules/canbus/vehicle/ch/protocol/a45_abs_1_311.h"
#include "glog/logging.h"
#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

A45ABS1311::A45ABS1311() {}
const int32_t A45ABS1311::ID = 0x311;

void A45ABS1311::Parse(const std::uint8_t* bytes, int32_t length,
                          ChassisDetail* chassis) const {
  chassis->mutable_ch()->mutable_a45_abs_1_311()->set_speed(
      speed(bytes, length));
  chassis->mutable_ch()->mutable_a45_abs_1_311()->set_chassis_sts(
      chassis_sts(bytes, length));
  chassis->mutable_ch()->mutable_a45_abs_1_311()->set_chassis_err(
      chassis_err(bytes, length));
}

double A45ABS1311::speed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x >>= 3;

  double ret = x * 0.05625 / 3.6 ;
  return ret;
}  //根据DBC解析ABS1报文中车辆实际速度值

// A45中没有对应的底盘状态信号，因此设为常数0
int A45ABS1311::chassis_sts(const std::uint8_t* bytes,
                               int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 1);

  int ret = x;
  return ret;
}

// A45中没有对应的底盘错误信号，因此设为常数0
int A45ABS1311::chassis_err(const std::uint8_t* bytes,
                               int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(1, 2);

  int ret = x;
  return ret;
}
}  // namespace ch
}  // namespace canbus
}  // namespace apollo
