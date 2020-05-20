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
 * 此模块用于A45的ECU_APA1报文解析，为便于理解改为EPS_Control,并对类的声明及函数声明（20200508-张智清）
 * EPS_Control报文主要解析方向盘控制请求、方向盘目标转角
 *****************************************************************************/

#pragma once

#include "modules/canbus/proto/chassis_detail.pb.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

namespace apollo {
namespace canbus {
namespace ch {

class A45EPScontrol300 : public ::apollo::drivers::canbus::ProtocolData<
                            ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  A45EPScontrol300();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;


  A45EPScontrol300* set_steer_angle_ctrl_req(
      A45_EPS_control_300::Steer_angle_ctrl_reqType steer_angle_ctrl_req);

  A45EPScontrol300* set_steer_angle_target(double steer_angle_target);

 private:

  void set_p_steer_angle_ctrl_req(
      uint8_t* data,
      A45_EPS_control_300::Steer_angle_ctrl_reqType steer_angle_ctrl_req);

  void set_p_steer_angle_target(uint8_t* data, double steer_angle_target);

 private:
  A45_EPS_control_300::Steer_angle_ctrl_reqType steer_angle_ctrl_req_;
  double steer_angle_target_;
};

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
