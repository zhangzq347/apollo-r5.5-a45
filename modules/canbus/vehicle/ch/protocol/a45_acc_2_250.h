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
 * 此模块用于A45的ACC2报文解析，对A45ACC2250类的声明及函数声明（20200508-张智清）
 * ACC2报文主要解析ACC模式、DecToStop请求、Driveoff请求、目标加速度
 *****************************************************************************/

#pragma once

#include "modules/canbus/proto/chassis_detail.pb.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

namespace apollo {
namespace canbus {
namespace ch {

class A45ACC2250 : public ::apollo::drivers::canbus::ProtocolData<
                            ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  A45ACC2250();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  A45ACC2250* set_acc_cc_mode(A45_ACC_2_250::ACC_cc_modeType acc_cc_mode);

  A45ACC2250* set_acc_dectostopreq(
      A45_ACC_2_250::ACC_DecToStopReqType acc_dectostopreq);

  A45ACC2250* set_acc_driveoffreq(
      A45_ACC_2_250::ACC_DriveoffReqType acc_driveoffreq);

  A45ACC2250* set_acc_axvcvaim(double acc_axvcvaim);

  A45ACC2250* set_acc_adtupperlimitaxvcv(double acc_adtupperlimitaxvcv);

  A45ACC2250* set_acc_adtlowerlimitaxvcv(double acc_adtlowerlimitaxvcv);

  A45ACC2250* set_acc_accecomfuppervalue(double acc_accecomfuppervalue);

  A45ACC2250* set_acc_accecomflowervalue(double acc_accecomflowervalue);

  A45ACC2250* set_acc_alivecounter();

  A45ACC2250* set_acc_checksum(A45_ACC_2_250::ACC_cc_modeType acc_cc_mode,
        A45_ACC_2_250::ACC_DecToStopReqType acc_dectostopreq,
        A45_ACC_2_250::ACC_DriveoffReqType acc_driveoffreq,
        double acc_axvcvaim, int32_t acc_alivecounter,
		double acc_adtupperlimitaxvcv, double acc_adtlowerlimitaxvcv,
		double acc_accecomfuppervalue, double acc_accecomflowervalue);

 private:

  void set_p_acc_cc_mode(
      uint8_t* data,
      A45_ACC_2_250::A45_ACC_2_250::ACC_cc_modeType acc_cc_mode);

  void set_p_acc_dectostopreq(
      uint8_t* data,
      A45_ACC_2_250::A45_ACC_2_250::ACC_DecToStopReqType acc_dectostopreq);

  void set_p_acc_driveoffreq(
      uint8_t* data,
      A45_ACC_2_250::A45_ACC_2_250::ACC_DriveoffReqType acc_driveoffreq);

  void set_p_acc_axvcvaim(uint8_t* data, double acc_axvcvaim);

  void set_p_acc_adtupperlimitaxvcv(uint8_t* data, double acc_adtupperlimitaxvcv);

  void set_p_acc_adtlowerlimitaxvcv(uint8_t* data, double acc_adtlowerlimitaxvcv);

  void set_p_acc_accecomfuppervalue(uint8_t* data, double acc_accecomfuppervalue);

  void set_p_acc_accecomflowervalue(uint8_t* data, double acc_accecomflowervalue);

  void set_p_acc_alivecounter(uint8_t* data, int32_t acc_alivecounter);

  void set_p_acc_checksum(uint8_t* data, int32_t acc_checksum);

 private:
  A45_ACC_2_250::ACC_cc_modeType acc_cc_mode_;
  A45_ACC_2_250::ACC_DecToStopReqType acc_dectostopreq_;
  A45_ACC_2_250::ACC_DriveoffReqType acc_driveoffreq_;
  double acc_axvcvaim_;
  double acc_adtupperlimitaxvcv_;
  double acc_adtlowerlimitaxvcv_;
  double acc_accecomfuppervalue_;
  double acc_accecomflowervalue_;
  int32_t acc_alivecounter_ ;
  int32_t acc_checksum_;
};

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
