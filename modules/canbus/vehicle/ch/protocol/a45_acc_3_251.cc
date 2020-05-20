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
 * 此模块用于A45的ACC3报文解析，对A45ACC2251类的定义及函数定义（20200508-张智清）
 * ACC3报文主要暂未使用相关控制信号，只需解析alivecounter及checksum
 *****************************************************************************/

#include "modules/canbus/vehicle/ch/protocol/a45_acc_3_251.h"
#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

const int32_t A45ACC3251::ID = 0x251;


// public
A45ACC3251::A45ACC3251() { Reset(); }

uint32_t A45ACC3251::GetPeriod() const {
  // modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void A45ACC3251::UpdateData(uint8_t* data) {
  set_acc_alivecounter();
  set_acc_checksum(acc_alivecounter_);

  set_p_acc_alivecounter(data, acc_alivecounter_);
  set_p_acc_checksum(data, acc_checksum_);
}

void A45ACC3251::Reset() {
  // you should check this manually
  acc_alivecounter_ = 0;
  acc_checksum_ = 0;
}

int ACC3_counter = 30;
A45ACC3251* A45ACC3251::set_acc_alivecounter() {
    if (ACC3_counter > 30) {
  ACC3_counter = 0;
  } else {
  ACC3_counter++;
  }
  acc_alivecounter_ = floor(ACC3_counter / 2);
  return this;
}
void A45ACC3251::set_p_acc_alivecounter(uint8_t* data, int32_t acc_alivecounter) {

  int x = acc_alivecounter;
  Byte to_set(data + 4);
  to_set.set_value(static_cast<uint8_t>(x), 4, 8);
}  //根据DBC解析ACC3报文中的alivecounter值

A45ACC3251* A45ACC3251::set_acc_checksum(int32_t acc_alivecounter) {

  int32_t Byte_0 = 0;
  int32_t Byte_1 = 0;
  int32_t Byte_2 = 0;
  int32_t Byte_3 = 0;
  int32_t Byte_4 = (acc_alivecounter << 4);
  int32_t Byte_5 = 0;
  int32_t Byte_6 = 0;
  acc_checksum_= ((Byte_0 + Byte_1 + Byte_2 + Byte_3 + Byte_4 + Byte_5 + Byte_6) & 0xff) ^ 0xff;
  return this;
}
void A45ACC3251::set_p_acc_checksum(uint8_t* data, int32_t acc_checksum) {

  int x = acc_checksum;

  Byte to_set(data + 7);
  to_set.set_value(static_cast<uint8_t>(x), 0, 8);
}  //根据DBC解析ACC3报文中的checksum值

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
