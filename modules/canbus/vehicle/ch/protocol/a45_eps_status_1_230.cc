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
 * 此模块用于A45的EPS_Status1报文解析，并对类的定义及函数定义（20200508-张智清）
 * EPS_Status1报文主要解析EPS工作状态、方向盘旋转角度、EPS故障及传感器故障状态
 *****************************************************************************/

#include "modules/canbus/vehicle/ch/protocol/a45_eps_status_1_230.h"
#include "glog/logging.h"
#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

A45EPSstatus1230::A45EPSstatus1230() {}
const int32_t A45EPSstatus1230::ID = 0x230;

void A45EPSstatus1230::Parse(const std::uint8_t* bytes, int32_t length,
                           ChassisDetail* chassis) const {
  chassis->mutable_ch()->mutable_a45_eps_status_1_230()->set_a45_eps_workstatus(
      a45_eps_workstatus(bytes, length));
  chassis->mutable_ch()->mutable_a45_eps_status_1_230()->set_a45_steer_angle(
      a45_steer_angle(bytes, length));
  chassis->mutable_ch()->mutable_a45_eps_status_1_230()->set_steer_err(
      steer_err(bytes, length));
  chassis->mutable_ch()->mutable_a45_eps_status_1_230()->set_sensor_err(
      sensor_err(bytes, length));
  chassis->mutable_check_response()->set_is_eps_online(
      a45_eps_workstatus(bytes, length) == 1);
}

// 0: 'STEER_ANGLE_EN_STS_DISABLE', 1: 'STEER_ANGLE_EN_STS_ENABLE',
A45_EPS_status_1_230::A45_EPS_WorkStatusType A45EPSstatus1230::a45_eps_workstatus(
    const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 8);
  if (x == 2) {
    x = 1;
  } else {
    x = 0;
  }
  A45_EPS_status_1_230::A45_EPS_WorkStatusType ret =
      static_cast<A45_EPS_status_1_230::A45_EPS_WorkStatusType>(x);
  return ret;
}  //根据DBC解析EPS工作状态

double A45EPSstatus1230::a45_steer_angle(const std::uint8_t* bytes,
                                       int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.0625 - 2048;
  return ret;
}  //根据DBC解析车辆方向盘实际转角

A45_EPS_status_1_230::Steer_errType A45EPSstatus1230::steer_err(
    const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(1, 2);

  A45_EPS_status_1_230::Steer_errType ret =
      static_cast<A45_EPS_status_1_230::Steer_errType>(x);
  return ret;
}  //根据DBC解析EPS故障状态

A45_EPS_status_1_230::Sensor_errType A45EPSstatus1230::sensor_err(
    const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(2, 3);

  A45_EPS_status_1_230::Sensor_errType ret =
      static_cast<A45_EPS_status_1_230::Sensor_errType>(x);
  return ret;
}  //根据DBC解析EPS传感器故障状态

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
