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
 * 此模块用于A45的ECU_APA1报文解析，为便于理解改为EPS_Control,并对类的定义及函数定义（20200508-张智清）
 * EPS_Control报文主要解析方向盘控制请求、方向盘目标转角
 *****************************************************************************/

#include "modules/canbus/vehicle/ch/protocol/a45_eps_control_300.h"
#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

const int32_t A45EPScontrol300::ID = 0x300;

// public
A45EPScontrol300::A45EPScontrol300() { Reset(); }

uint32_t A45EPScontrol300::GetPeriod() const {
  // modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void A45EPScontrol300::UpdateData(uint8_t* data) {
  set_p_steer_angle_ctrl_req(data, steer_angle_ctrl_req_);
  set_p_steer_angle_target(data, steer_angle_target_);
}

void A45EPScontrol300::Reset() {
  // you should check this manually
  steer_angle_ctrl_req_ = A45_EPS_control_300::STEER_ANGLE_EN_CTRL_DISABLE;
  steer_angle_target_ = 0;
}

A45EPScontrol300* A45EPScontrol300::set_steer_angle_ctrl_req(
    A45_EPS_control_300::Steer_angle_ctrl_reqType steer_angle_ctrl_req) {
  steer_angle_ctrl_req_ = steer_angle_ctrl_req;
  return this;
}

void A45EPScontrol300::set_p_steer_angle_ctrl_req(
    uint8_t* data,
    A45_EPS_control_300::Steer_angle_ctrl_reqType steer_angle_ctrl_req) {
  int x = steer_angle_ctrl_req;

  Byte to_set(data + 4);
  to_set.set_value(static_cast<uint8_t>(x), 6, 8);
}  //根据DBC解析EPS转角控制请求的状态

A45EPScontrol300* A45EPScontrol300::set_steer_angle_target(double steer_angle_target) {
  steer_angle_target_ = steer_angle_target;
  return this;
}

void A45EPScontrol300::set_p_steer_angle_target(uint8_t* data,
                                            double steer_angle_target) {
  int x = static_cast<int>(steer_angle_target / 0.1000);
  uint8_t t = 0;

  if (x<0) {
  t = static_cast<uint8_t>(x & 0xFF);
  Byte to_set0(data + 1);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = static_cast<uint8_t>((x & 0xFF) | 0x80);
  Byte to_set1(data + 0);
  to_set1.set_value(t, 0, 8);
  }

  else {
  t = static_cast<uint8_t>(x & 0xFF);
  Byte to_set0(data + 1);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = static_cast<uint8_t>(x & 0xFF);
  Byte to_set1(data + 0);
  to_set1.set_value(t, 0, 8);
  }

}  //根据DBC解析EPS转角控制的目标方向盘转角

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
