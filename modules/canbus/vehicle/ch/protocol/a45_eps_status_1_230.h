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
 * 此模块用于A45的EPS_Status1报文解析，并对类的声明及函数声明（20200508-张智清）
 * EPS_Status1报文主要解析EPS工作状态、方向盘旋转角度、EPS故障及传感器故障状态
 *****************************************************************************/

#pragma once

#include "modules/canbus/proto/chassis_detail.pb.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

namespace apollo {
namespace canbus {
namespace ch {

class A45EPSstatus1230 : public ::apollo::drivers::canbus::ProtocolData<
                           ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  A45EPSstatus1230();
  void Parse(const std::uint8_t* bytes, int32_t length,
             ChassisDetail* chassis) const override;

 private:

  A45_EPS_status_1_230::A45_EPS_WorkStatusType a45_eps_workstatus(
      const std::uint8_t* bytes, const int32_t length) const;

  double a45_steer_angle(const std::uint8_t* bytes, const int32_t length) const;

  A45_EPS_status_1_230::Steer_errType steer_err(const std::uint8_t* bytes,
                                             const int32_t length) const;

  A45_EPS_status_1_230::Sensor_errType sensor_err(const std::uint8_t* bytes,
                                               const int32_t length) const;
};

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
