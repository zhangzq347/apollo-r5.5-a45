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
 * 此模块用于A45的ESP4报文解析，并对类的定义及函数定义（20200508-张智清）
 * ESP4报文主要解析车辆纵向加速度
 *****************************************************************************/

#include "modules/canbus/vehicle/ch/protocol/a45_esp_4_213.h"
#include "glog/logging.h"
#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

A45ESP4213::A45ESP4213() {}
const int32_t A45ESP4213::ID = 0x213;

void A45ESP4213::Parse(const std::uint8_t* bytes, int32_t length,
                          ChassisDetail* chassis) const {
  chassis->mutable_ch()->mutable_a45_esp_4_213()->set_a45_acc_speed(
      a45_acc_speed(bytes, length));

}

double A45ESP4213::a45_acc_speed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 7);
  int32_t f = t0.get_byte(7, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.00012207 * 10 ;

  if (f == 1)
  {
    ret = ret - 40;
    return ret;
  } else {
    return ret;
  }
}  //根据DBC解析车辆纵向加速度信号的实际值

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
