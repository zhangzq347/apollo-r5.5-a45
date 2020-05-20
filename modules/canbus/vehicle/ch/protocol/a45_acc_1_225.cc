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
 * 此模块用于A45的ACC1报文解析，对A45ACC1225类的定义及函数定义（20200508-张智清）
 * ACC1报文主要解析ACC模式、设定的车间时距、设定的巡航速度
 *****************************************************************************/

#include "modules/canbus/vehicle/ch/protocol/a45_acc_1_225.h"
#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

const int32_t A45ACC1225::ID = 0x225;

// public
A45ACC1225::A45ACC1225() { Reset(); }

uint32_t A45ACC1225::GetPeriod() const {
  // modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void A45ACC1225::UpdateData(uint8_t* data) {
  set_acc_mode_hmi();
  set_acc_alivecounter();
  set_acc_checksum(acc_mode_hmi_, acc_taugapset_,
         acc_vsetdis_, acc_alivecounter_);

  set_p_acc_mode_hmi(data, acc_mode_hmi_);
  set_p_acc_taugapset(data, acc_taugapset_);
  set_p_acc_vsetdis(data, acc_vsetdis_);
  set_p_acc_alivecounter(data, acc_alivecounter_);
  set_p_acc_checksum(data, acc_checksum_);

}

void A45ACC1225::Reset() {
  // you should check this manually
  acc_mode_hmi_ = A45_ACC_1_225::ACC_1_Stand_By;
  acc_taugapset_ = A45_ACC_1_225::ACC_1_tauGap_3;

  acc_vsetdis_ = 30;
  acc_alivecounter_ = 0;
  acc_checksum_ = 0;
}

int ACC1_mode_delay = 0;
A45ACC1225* A45ACC1225::set_acc_mode_hmi() {

    if (ACC1_mode_delay > 300) {
    acc_mode_hmi_ = A45_ACC_1_225::ACC_1_Active_Control;
    } else {
    acc_mode_hmi_ = A45_ACC_1_225::ACC_1_Stand_By;
    ACC1_mode_delay++;
    }
    return this;
}

void A45ACC1225::set_p_acc_mode_hmi(
    uint8_t* data,
    A45_ACC_1_225::A45_ACC_1_225::ACC_mode_hmiType acc_mode_hmi) {
  int x = acc_mode_hmi;

  Byte to_set(data + 2);
  to_set.set_value(static_cast<uint8_t>(x), 3, 6);
}//根据DBC解析ACC1报文中的ACC模式

A45ACC1225* A45ACC1225::set_acc_taugapset(
    A45_ACC_1_225::ACC_TauGapSetType acc_taugapset) {
    acc_taugapset_ = acc_taugapset;
    return this;
}

void A45ACC1225::set_p_acc_taugapset(
    uint8_t* data,
    A45_ACC_1_225::A45_ACC_1_225::ACC_TauGapSetType acc_taugapset) {
  int x = acc_taugapset;

  Byte to_set(data + 1);
  to_set.set_value(static_cast<uint8_t>(x), 3, 6);
}//根据DBC解析ACC1报文中的设定车间时距值

A45ACC1225* A45ACC1225::set_acc_vsetdis(double acc_vsetdis) {
  acc_vsetdis_ = acc_vsetdis;
  return this;
}

void A45ACC1225::set_p_acc_vsetdis(uint8_t* data, double acc_vsetdis) {

  int x = static_cast<int>(acc_vsetdis);

  Byte to_set(data + 0);
  to_set.set_value(static_cast<uint8_t>(x), 0, 8);
}//根据DBC解析ACC1报文中的设定巡航速度值

int ACC1_counter = 30;
A45ACC1225* A45ACC1225::set_acc_alivecounter() {
    if (ACC1_counter > 30) {
  ACC1_counter = 0;
  } else {
  ACC1_counter++;
  }
  acc_alivecounter_ = floor(ACC1_counter / 2);
  return this;
}

void A45ACC1225::set_p_acc_alivecounter(uint8_t* data, int32_t acc_alivecounter) {

  int x = acc_alivecounter;
  Byte to_set(data + 6);
  to_set.set_value(static_cast<uint8_t>(x), 0, 4);
}  //根据DBC解析ACC3报文中的alivecounter值

A45ACC1225* A45ACC1225::set_acc_checksum(A45_ACC_1_225::ACC_mode_hmiType acc_mode_hmi,
        A45_ACC_1_225::ACC_TauGapSetType acc_taugapset,
        double acc_vsetdis, int32_t acc_alivecounter) {
  int32_t Byte_0 = acc_vsetdis;
  int32_t Byte_1 = (acc_taugapset << 3);
  int32_t Byte_2 = (acc_mode_hmi << 3);
  int32_t Byte_3 = 0;
  int32_t Byte_4 = 0;
  int32_t Byte_5 = 0;
  int32_t Byte_6 = acc_alivecounter;
  acc_checksum_= ((Byte_0 + Byte_1 + Byte_2 + Byte_3 + Byte_4 + Byte_5 + Byte_6) & 0xff) ^ 0xff;
  return this;
}

void A45ACC1225::set_p_acc_checksum(uint8_t* data, int32_t acc_checksum) {

  int x = acc_checksum;

  Byte to_set(data + 7);
  to_set.set_value(static_cast<uint8_t>(x), 0, 8);
}  //根据DBC解析ACC1报文中的checksum值

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
