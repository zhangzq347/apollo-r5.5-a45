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
 * 此模块用于A45的ACC1报文解析，对A45ACC1225类的声明及函数声明（20200508-张智清）
 * ACC1报文主要解析ACC模式、设定的车间时距、设定的巡航速度
 *****************************************************************************/

#pragma once

#include "modules/canbus/proto/chassis_detail.pb.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

namespace apollo {
namespace canbus {
namespace ch {

class A45ACC1225 : public ::apollo::drivers::canbus::ProtocolData<
                            ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  A45ACC1225();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  A45ACC1225* set_acc_mode_hmi();

  A45ACC1225* set_acc_taugapset(
      A45_ACC_1_225::ACC_TauGapSetType acc_taugapset);

  A45ACC1225* set_acc_vsetdis(double acc_vsetdis);

  A45ACC1225* set_acc_alivecounter();

  A45ACC1225* set_acc_checksum(A45_ACC_1_225::ACC_mode_hmiType acc_mode_hmi,
        A45_ACC_1_225::ACC_TauGapSetType acc_taugapset,
        double acc_vsetdis, int32_t acc_alivecounter);

 private:

  void set_p_acc_mode_hmi(
      uint8_t* data,
      A45_ACC_1_225::A45_ACC_1_225::ACC_mode_hmiType acc_mode_hmi);

  void set_p_acc_taugapset(
      uint8_t* data,
      A45_ACC_1_225::A45_ACC_1_225::ACC_TauGapSetType acc_taugapset);

  void set_p_acc_vsetdis(uint8_t* data, double acc_vsetdis);

  void set_p_acc_alivecounter(uint8_t* data, int32_t acc_alivecounter);

  void set_p_acc_checksum(uint8_t* data, int32_t acc_checksum);

 private:
  A45_ACC_1_225::ACC_mode_hmiType acc_mode_hmi_;
  A45_ACC_1_225::ACC_TauGapSetType acc_taugapset_;
  double acc_vsetdis_;
  int32_t acc_alivecounter_ ;
  int32_t acc_checksum_;
};

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
