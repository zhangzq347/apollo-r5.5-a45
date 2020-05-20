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
 * 此模块用于A45的ACC2报文解析，对A45ACC2250类的定义及函数定义（20200508-张智清）
 * ACC2报文主要解析ACC模式、DecToStop请求、Driveoff请求、目标加速度
 *****************************************************************************/

#include "modules/canbus/vehicle/ch/protocol/a45_acc_2_250.h"
#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

const int32_t A45ACC2250::ID = 0x250;


// public
A45ACC2250::A45ACC2250() { Reset(); }

uint32_t A45ACC2250::GetPeriod() const {
  // modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void A45ACC2250::UpdateData(uint8_t* data) {
  set_acc_alivecounter();
  set_acc_checksum(acc_cc_mode_, acc_dectostopreq_,
         acc_driveoffreq_, acc_axvcvaim_, acc_alivecounter_,
         acc_adtupperlimitaxvcv_, acc_adtlowerlimitaxvcv_,
         acc_accecomfuppervalue_, acc_accecomflowervalue_);
  //AINFO << acc_alivecounter_;
  set_p_acc_cc_mode(data, acc_cc_mode_);
  set_p_acc_dectostopreq(data, acc_dectostopreq_);
  set_p_acc_driveoffreq(data, acc_driveoffreq_);
  set_p_acc_axvcvaim(data, acc_axvcvaim_);
  set_p_acc_adtupperlimitaxvcv(data, acc_adtupperlimitaxvcv_);
  set_p_acc_adtlowerlimitaxvcv(data, acc_adtlowerlimitaxvcv_);
  set_p_acc_accecomfuppervalue(data, acc_accecomfuppervalue_);
  set_p_acc_accecomflowervalue(data, acc_accecomflowervalue_);
  set_p_acc_alivecounter(data, acc_alivecounter_);
  set_p_acc_checksum(data, acc_checksum_);

}

void A45ACC2250::Reset() {
  // you should check this manually
  acc_cc_mode_ = A45_ACC_2_250::ACC_2_Stand_By;
  acc_dectostopreq_ = A45_ACC_2_250::ACC_DecToStopReq_No_Request;
  acc_driveoffreq_ = A45_ACC_2_250::ACC_DriveoffReq_No_Request;
  acc_axvcvaim_ = 0;
  acc_adtupperlimitaxvcv_ = 2;
  acc_adtlowerlimitaxvcv_ = -4;
  acc_accecomfuppervalue_ = 0.1;
  acc_accecomflowervalue_ = 0.1;
  acc_alivecounter_ = 0;
  acc_checksum_ = 0;
}


A45ACC2250* A45ACC2250::set_acc_cc_mode(
    A45_ACC_2_250::ACC_cc_modeType acc_cc_mode) {
    acc_cc_mode_ = acc_cc_mode;
    return this;
}

void A45ACC2250::set_p_acc_cc_mode(
    uint8_t* data,
    A45_ACC_2_250::A45_ACC_2_250::ACC_cc_modeType acc_cc_mode) {
  int x = acc_cc_mode;

  Byte to_set(data + 4);
  to_set.set_value(static_cast<uint8_t>(x), 4, 8);
}  //根据DBC解析ACC2报文中的ACC模式

A45ACC2250* A45ACC2250::set_acc_dectostopreq(
    A45_ACC_2_250::ACC_DecToStopReqType acc_dectostopreq) {
    acc_dectostopreq_ = acc_dectostopreq;
    return this;
}

void A45ACC2250::set_p_acc_dectostopreq(
    uint8_t* data,
    A45_ACC_2_250::A45_ACC_2_250::ACC_DecToStopReqType acc_dectostopreq) {
  int x = acc_dectostopreq;

  Byte to_set(data + 1);
  to_set.set_value(static_cast<uint8_t>(x), 7, 8);
}  //根据DBC解析ACC2报文中的DecToStop请求状态

A45ACC2250* A45ACC2250::set_acc_driveoffreq(
    A45_ACC_2_250::ACC_DriveoffReqType acc_driveoffreq) {
    acc_driveoffreq_ = acc_driveoffreq;
    return this;
}

void A45ACC2250::set_p_acc_driveoffreq(
    uint8_t* data,
    A45_ACC_2_250::A45_ACC_2_250::ACC_DriveoffReqType acc_driveoffreq) {
  int x = acc_driveoffreq;

  Byte to_set(data + 6);
  to_set.set_value(static_cast<uint8_t>(x), 7, 8);
}  //根据DBC解析ACC2报文中的Driveoff请求状态

A45ACC2250* A45ACC2250::set_acc_axvcvaim(double acc_axvcvaim) {
  acc_axvcvaim_ = acc_axvcvaim;
  return this;
}

void A45ACC2250::set_p_acc_axvcvaim(uint8_t* data, double acc_axvcvaim) {

  int x = static_cast<int>((acc_axvcvaim + 7) * 20);

  Byte to_set(data + 0);
  to_set.set_value(static_cast<uint8_t>(x), 0, 8);
}  //根据DBC解析ACC2报文中的目标加速度值

A45ACC2250* A45ACC2250::set_acc_adtupperlimitaxvcv(double acc_adtupperlimitaxvcv) {
	acc_adtupperlimitaxvcv_ = acc_adtupperlimitaxvcv;
	return this;
}

void A45ACC2250::set_p_acc_adtupperlimitaxvcv(uint8_t* data, double acc_adtupperlimitaxvcv) {

	int x = static_cast<int>(acc_adtupperlimitaxvcv * 5);

	Byte to_set(data + 1);
	to_set.set_value(static_cast<uint8_t>(x), 0, 7);
}  //根据DBC解析ACC2报文中的FRS_ACC_aDtUpperLimitAxvCv值

A45ACC2250* A45ACC2250::set_acc_adtlowerlimitaxvcv(double acc_adtlowerlimitaxvcv) {
	acc_adtlowerlimitaxvcv_ = acc_adtlowerlimitaxvcv;
	return this;
}

void A45ACC2250::set_p_acc_adtlowerlimitaxvcv(uint8_t* data, double acc_adtlowerlimitaxvcv) {

	int x = static_cast<int>((acc_adtlowerlimitaxvcv + 25.4) * 5);

	Byte to_set(data + 6);
	to_set.set_value(static_cast<uint8_t>(x), 0, 7);
}  //根据DBC解析ACC2报文中的FRS_ACC_aDtLowerLimitAxvCv值

A45ACC2250* A45ACC2250::set_acc_accecomfuppervalue(double acc_accecomfuppervalue) {
	acc_accecomfuppervalue_ = acc_accecomfuppervalue;
	return this;
}

void A45ACC2250::set_p_acc_accecomfuppervalue(uint8_t* data, double acc_accecomfuppervalue) {

	int x = static_cast<int>((acc_accecomfuppervalue + 7) * 20);

	Byte to_set(data + 2);
	to_set.set_value(static_cast<uint8_t>(x), 0, 8);
}  //根据DBC解析ACC2报文中的FRS_ACC_AcceComfUpperValue值

A45ACC2250* A45ACC2250::set_acc_accecomflowervalue(double acc_accecomflowervalue) {
	acc_accecomflowervalue_ = acc_accecomflowervalue;
	return this;
}

void A45ACC2250::set_p_acc_accecomflowervalue(uint8_t* data, double acc_accecomflowervalue) {

	int x = static_cast<int>((acc_accecomflowervalue + 7) * 20);

	Byte to_set(data + 3);
	to_set.set_value(static_cast<uint8_t>(x), 0, 8);
}  //根据DBC解析ACC2报文中的FRS_ACC_AcceComfLowerValue值

int ACC2_counter = 15;
A45ACC2250* A45ACC2250::set_acc_alivecounter() {
    if (ACC2_counter > 14) {
  ACC2_counter = 0;
  } else {
  ACC2_counter++;
  }
  acc_alivecounter_ = ACC2_counter;
  return this;
}

void A45ACC2250::set_p_acc_alivecounter(uint8_t* data, int32_t acc_alivecounter) {

  int x = acc_alivecounter;
  Byte to_set(data + 5);
  to_set.set_value(static_cast<uint8_t>(x), 0, 4);
}  //根据DBC解析ACC2报文中的alivecounter值

A45ACC2250* A45ACC2250::set_acc_checksum(A45_ACC_2_250::ACC_cc_modeType acc_cc_mode,
        A45_ACC_2_250::ACC_DecToStopReqType acc_dectostopreq,
        A45_ACC_2_250::ACC_DriveoffReqType acc_driveoffreq,
        double acc_axvcvaim, int32_t acc_alivecounter,
		double acc_adtupperlimitaxvcv, double acc_adtlowerlimitaxvcv,
		double acc_accecomfuppervalue, double acc_accecomflowervalue) {
  int32_t Byte_0 = (acc_axvcvaim + 7) * 20;
  int32_t Byte_1 = (acc_dectostopreq << 7) + acc_adtupperlimitaxvcv * 5;
  int32_t Byte_2 = (acc_accecomfuppervalue + 7) * 20;
  int32_t Byte_3 = (acc_accecomflowervalue + 7) * 20;
  int32_t Byte_4 = (acc_cc_mode << 4);
  int32_t Byte_5 = acc_alivecounter;
  int32_t Byte_6 = (acc_driveoffreq << 7) + (acc_adtlowerlimitaxvcv + 25.4) * 5;
  acc_checksum_= ((Byte_0 + Byte_1 + Byte_2 + Byte_3 + Byte_4 + Byte_5 + Byte_6) & 0xff) ^ 0xff;
  return this;
}

void A45ACC2250::set_p_acc_checksum(uint8_t* data, int32_t acc_checksum) {

  int x = acc_checksum;

  Byte to_set(data + 7);
  to_set.set_value(static_cast<uint8_t>(x), 0, 8);
}  //根据DBC解析ACC2报文中的checksum值

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
