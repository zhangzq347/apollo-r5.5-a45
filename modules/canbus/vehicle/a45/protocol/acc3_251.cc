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
 *****************************************************************************/

#include "modules/canbus/vehicle/a45/protocol/acc3_251.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

const int32_t Acc3251::ID = 0x251;

// public
Acc3251::Acc3251() { Reset(); }

uint32_t Acc3251::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Acc3251::UpdateData(uint8_t* data) {
  set_frs_aeb_alivecounter();
  set_frs_aeb_checksum(frs_aeb_vehiclehold_, frs_aeb_alivecounter_,frs_aeb_abprequest_, frs_aeb_awblevel_,
    frs_aeb_awbrequest_, frs_aeb_abarequest_, frs_aeb_abalevel_, frs_aeb_axtar_);

  set_p_frs_aeb_checksum(data, frs_aeb_checksum_);
  set_p_frs_aeb_vehiclehold(data, frs_aeb_vehiclehold_);
  set_p_frs_aeb_alivecounter(data, frs_aeb_alivecounter_);
  set_p_frs_aeb_abprequest(data, frs_aeb_abprequest_);
  set_p_frs_aeb_awblevel(data, frs_aeb_awblevel_);
  set_p_frs_aeb_awbrequest(data, frs_aeb_awbrequest_);
  set_p_frs_aeb_abarequest(data, frs_aeb_abarequest_);
  set_p_frs_aeb_abalevel(data, frs_aeb_abalevel_);
  set_p_frs_aeb_axtar(data, frs_aeb_axtar_);
}

void Acc3251::Reset() {
  // TODO(All) :  you should check this manually
  frs_aeb_checksum_ = 0;
  frs_aeb_vehiclehold_ = Acc3_251::FRS_AEB_VEHICLEHOLD_NOT_HOLD;
  frs_aeb_alivecounter_ = 0;
  frs_aeb_abprequest_ = Acc3_251::FRS_AEB_ABPREQUEST_NO_DEMAND;
  frs_aeb_awblevel_ = Acc3_251::FRS_AEB_AWBLEVEL_NO_LEVEL;
  frs_aeb_awbrequest_ = Acc3_251::FRS_AEB_AWBREQUEST_NO_DEMAND;
  frs_aeb_abarequest_ = Acc3_251::FRS_AEB_ABAREQUEST_NO_DEMAND;
  frs_aeb_abalevel_ = Acc3_251::FRS_AEB_ABALEVEL_LEVEL_0;
  frs_aeb_axtar_ = 0.0;
}

Acc3251* Acc3251::set_frs_aeb_checksum(Acc3_251::Frs_aeb_vehicleholdType frs_aeb_vehiclehold, int frs_aeb_alivecounter,
    Acc3_251::Frs_aeb_abprequestType frs_aeb_abprequest, Acc3_251::Frs_aeb_awblevelType frs_aeb_awblevel,
    Acc3_251::Frs_aeb_awbrequestType frs_aeb_awbrequest, Acc3_251::Frs_aeb_abarequestType frs_aeb_abarequest,
    Acc3_251::Frs_aeb_abalevelType frs_aeb_abalevel, double frs_aeb_axtar) {

  int32_t frs_aeb_axtar1 = (frs_aeb_axtar - -16.000000) * 2048;
  int32_t Byte_0 = (frs_aeb_axtar1 >> 8);;
  int32_t Byte_1 = (frs_aeb_axtar1 & 0xff);;
  int32_t Byte_2 = (frs_aeb_abalevel << 4) + (frs_aeb_abarequest << 6) + (frs_aeb_awbrequest << 7);
  int32_t Byte_3 = frs_aeb_awblevel + (frs_aeb_abprequest << 4) + (frs_aeb_vehiclehold << 5);
  int32_t Byte_4 = (frs_aeb_alivecounter << 4);
  int32_t Byte_5 = 0;
  int32_t Byte_6 = 0;
  frs_aeb_checksum_= ((Byte_0 + Byte_1 + Byte_2 + Byte_3 + Byte_4 + Byte_5 + Byte_6) & 0xff) ^ 0xff;
  return this;
 }

// config detail: {'name': 'FRS_AEB_CheckSum', 'offset': 0.0, 'precision': 1.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|255]', 'bit': 63, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
void Acc3251::set_p_frs_aeb_checksum(uint8_t* data,
    int frs_aeb_checksum) {
  frs_aeb_checksum = ProtocolData::BoundedValue(0, 255, frs_aeb_checksum);
  int x = frs_aeb_checksum;

  Byte to_set(data + 7);
  to_set.set_value(x, 0, 8);
}


Acc3251* Acc3251::set_frs_aeb_vehiclehold(
    Acc3_251::Frs_aeb_vehicleholdType frs_aeb_vehiclehold) {
  frs_aeb_vehiclehold_ = frs_aeb_vehiclehold;
  return this;
 }

// config detail: {'name': 'FRS_AEB_VehicleHold', 'enum': {0: 'FRS_AEB_VEHICLEHOLD_NOT_HOLD', 1: 'FRS_AEB_VEHICLEHOLD_HOLD'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 29, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc3251::set_p_frs_aeb_vehiclehold(uint8_t* data,
    Acc3_251::Frs_aeb_vehicleholdType frs_aeb_vehiclehold) {
  int x = frs_aeb_vehiclehold;

  Byte to_set(data + 3);
  to_set.set_value(x, 5, 1);
}

int ACC3_counter = 30;
Acc3251* Acc3251::set_frs_aeb_alivecounter() {
  if (ACC3_counter > 30) {
  ACC3_counter = 0;
  } else {
  ACC3_counter++;
  }

  frs_aeb_alivecounter_ = floor(ACC3_counter / 2);
  return this;
 }

// config detail: {'name': 'FRS_AEB_AliveCounter', 'offset': 0.0, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'physical_range': '[0|15]', 'bit': 39, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
void Acc3251::set_p_frs_aeb_alivecounter(uint8_t* data,
    int frs_aeb_alivecounter) {
  frs_aeb_alivecounter = ProtocolData::BoundedValue(0, 15, frs_aeb_alivecounter);
  int x = frs_aeb_alivecounter;

  Byte to_set(data + 4);
  to_set.set_value(x, 4, 4);
}


Acc3251* Acc3251::set_frs_aeb_abprequest(
    Acc3_251::Frs_aeb_abprequestType frs_aeb_abprequest) {
  frs_aeb_abprequest_ = frs_aeb_abprequest;
  return this;
 }

// config detail: {'name': 'FRS_AEB_ABPRequest', 'enum': {0: 'FRS_AEB_ABPREQUEST_NO_DEMAND', 1: 'FRS_AEB_ABPREQUEST_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 28, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc3251::set_p_frs_aeb_abprequest(uint8_t* data,
    Acc3_251::Frs_aeb_abprequestType frs_aeb_abprequest) {
  int x = frs_aeb_abprequest;

  Byte to_set(data + 3);
  to_set.set_value(x, 4, 1);
}


Acc3251* Acc3251::set_frs_aeb_awblevel(
    Acc3_251::Frs_aeb_awblevelType frs_aeb_awblevel) {
  frs_aeb_awblevel_ = frs_aeb_awblevel;
  return this;
 }

// config detail: {'name': 'FRS_AEB_AWBLevel', 'enum': {0: 'FRS_AEB_AWBLEVEL_NO_LEVEL', 1: 'FRS_AEB_AWBLEVEL_LEVEL_1', 2: 'FRS_AEB_AWBLEVEL_LEVEL_2', 3: 'FRS_AEB_AWBLEVEL_LEVEL_3', 4: 'FRS_AEB_AWBLEVEL_LEVEL_4'}, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|15]', 'bit': 27, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc3251::set_p_frs_aeb_awblevel(uint8_t* data,
    Acc3_251::Frs_aeb_awblevelType frs_aeb_awblevel) {
  int x = frs_aeb_awblevel;

  Byte to_set(data + 3);
  to_set.set_value(x, 0, 4);
}


Acc3251* Acc3251::set_frs_aeb_awbrequest(
    Acc3_251::Frs_aeb_awbrequestType frs_aeb_awbrequest) {
  frs_aeb_awbrequest_ = frs_aeb_awbrequest;
  return this;
 }

// config detail: {'name': 'FRS_AEB_AWBRequest', 'enum': {0: 'FRS_AEB_AWBREQUEST_NO_DEMAND', 1: 'FRS_AEB_AWBREQUEST_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 23, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc3251::set_p_frs_aeb_awbrequest(uint8_t* data,
    Acc3_251::Frs_aeb_awbrequestType frs_aeb_awbrequest) {
  int x = frs_aeb_awbrequest;

  Byte to_set(data + 2);
  to_set.set_value(x, 7, 1);
}


Acc3251* Acc3251::set_frs_aeb_abarequest(
    Acc3_251::Frs_aeb_abarequestType frs_aeb_abarequest) {
  frs_aeb_abarequest_ = frs_aeb_abarequest;
  return this;
 }

// config detail: {'name': 'FRS_AEB_ABARequest', 'enum': {0: 'FRS_AEB_ABAREQUEST_NO_DEMAND', 1: 'FRS_AEB_ABAREQUEST_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 22, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc3251::set_p_frs_aeb_abarequest(uint8_t* data,
    Acc3_251::Frs_aeb_abarequestType frs_aeb_abarequest) {
  int x = frs_aeb_abarequest;

  Byte to_set(data + 2);
  to_set.set_value(x, 6, 1);
}


Acc3251* Acc3251::set_frs_aeb_abalevel(
    Acc3_251::Frs_aeb_abalevelType frs_aeb_abalevel) {
  frs_aeb_abalevel_ = frs_aeb_abalevel;
  return this;
 }

// config detail: {'name': 'FRS_AEB_ABALevel', 'enum': {0: 'FRS_AEB_ABALEVEL_LEVEL_0', 1: 'FRS_AEB_ABALEVEL_LEVEL_1', 2: 'FRS_AEB_ABALEVEL_LEVEL_2', 3: 'FRS_AEB_ABALEVEL_LEVEL_3'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 21, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc3251::set_p_frs_aeb_abalevel(uint8_t* data,
    Acc3_251::Frs_aeb_abalevelType frs_aeb_abalevel) {
  int x = frs_aeb_abalevel;

  Byte to_set(data + 2);
  to_set.set_value(x, 4, 2);
}


Acc3251* Acc3251::set_frs_aeb_axtar(
    double frs_aeb_axtar) {
  frs_aeb_axtar_ = frs_aeb_axtar;
  return this;
 }

// config detail: {'name': 'FRS_AEB_axTar', 'offset': -16.0, 'precision': 0.0004882, 'len': 16, 'is_signed_var': False, 'physical_range': '[-16|16]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
void Acc3251::set_p_frs_aeb_axtar(uint8_t* data,
    double frs_aeb_axtar) {
  frs_aeb_axtar = ProtocolData::BoundedValue(-16.0, 16.0, frs_aeb_axtar);
  int x = (frs_aeb_axtar - -16.000000) * 2048;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 1);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 0);
  to_set1.set_value(t, 0, 8);
}

}  // namespace a45
}  // namespace canbus
}  // namespace apollo
