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

#include "modules/canbus/vehicle/a45/protocol/acc2_250.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

const int32_t Acc2250::ID = 0x250;

// public
Acc2250::Acc2250() { Reset(); }

uint32_t Acc2250::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Acc2250::UpdateData(uint8_t* data) {
  set_frs_acc_alivecounter();
  set_frs_acc_checksum(frs_acc_driveoffreq_, frs_acc_adtlowerlimitaxvcv_, frs_acc_brakepreferred_, frs_acc_minimumbraking_,
    frs_acc_shutdownmode_, frs_acc_alivecounter_, frs_acc_cc_mode_, frs_acc_accecomflowervalue_, frs_acc_accecomfuppervalue_,
    frs_acc_dectostopreq_, frs_acc_adtupperlimitaxvcv_, frs_acc_axvcvaim_);

  set_p_frs_acc_checksum(data, frs_acc_checksum_);
  set_p_frs_acc_driveoffreq(data, frs_acc_driveoffreq_);
  set_p_frs_acc_adtlowerlimitaxvcv(data, frs_acc_adtlowerlimitaxvcv_);
  set_p_frs_acc_brakepreferred(data, frs_acc_brakepreferred_);
  set_p_frs_acc_minimumbraking(data, frs_acc_minimumbraking_);
  set_p_frs_acc_shutdownmode(data, frs_acc_shutdownmode_);
  set_p_frs_acc_alivecounter(data, frs_acc_alivecounter_);
  set_p_frs_acc_cc_mode(data, frs_acc_cc_mode_);
  set_p_frs_acc_accecomflowervalue(data, frs_acc_accecomflowervalue_);
  set_p_frs_acc_accecomfuppervalue(data, frs_acc_accecomfuppervalue_);
  set_p_frs_acc_dectostopreq(data, frs_acc_dectostopreq_);
  set_p_frs_acc_adtupperlimitaxvcv(data, frs_acc_adtupperlimitaxvcv_);
  set_p_frs_acc_axvcvaim(data, frs_acc_axvcvaim_);
}

void Acc2250::Reset() {
  // TODO(All) :  you should check this manually
  frs_acc_checksum_ = 0;
  frs_acc_driveoffreq_ = Acc2_250::FRS_ACC_DRIVEOFFREQ_NO_REQUEST;
  frs_acc_adtlowerlimitaxvcv_ = -4;
  frs_acc_brakepreferred_ = Acc2_250::FRS_ACC_BRAKEPREFERRED_NO_DEMAND;
  frs_acc_minimumbraking_ = Acc2_250::FRS_ACC_MINIMUMBRAKING_NO_DEMAND;
  frs_acc_shutdownmode_ = Acc2_250::FRS_ACC_SHUTDOWNMODE_SOFT_OFF;
  frs_acc_alivecounter_ = 0;
  frs_acc_cc_mode_ = Acc2_250::FRS_ACC_CC_MODE_OFF_MODE;
  frs_acc_accecomflowervalue_ = 0.1;
  frs_acc_accecomfuppervalue_ = 0.1;
  frs_acc_dectostopreq_ = Acc2_250::FRS_ACC_DECTOSTOPREQ_NO_REQUEST;
  frs_acc_adtupperlimitaxvcv_ = 2;
  frs_acc_axvcvaim_ = 0.0;
}

Acc2250* Acc2250::set_frs_acc_checksum(Acc2_250::Frs_acc_driveoffreqType frs_acc_driveoffreq, double frs_acc_adtlowerlimitaxvcv,
    Acc2_250::Frs_acc_brakepreferredType frs_acc_brakepreferred, Acc2_250::Frs_acc_minimumbrakingType frs_acc_minimumbraking,
    Acc2_250::Frs_acc_shutdownmodeType frs_acc_shutdownmode, int frs_acc_alivecounter, Acc2_250::Frs_acc_cc_modeType frs_acc_cc_mode,
    double frs_acc_accecomflowervalue, double frs_acc_accecomfuppervalue, Acc2_250::Frs_acc_dectostopreqType frs_acc_dectostopreq,
    double frs_acc_adtupperlimitaxvcv, double frs_acc_axvcvaim) {

  int32_t Byte_0 = (frs_acc_axvcvaim + 7) * 20;
  int32_t Byte_1 = (frs_acc_dectostopreq << 7) + frs_acc_adtupperlimitaxvcv * 5;
  int32_t Byte_2 = (frs_acc_accecomfuppervalue + 7) * 20;
  int32_t Byte_3 = (frs_acc_accecomflowervalue + 7) * 20;
  int32_t Byte_4 = (frs_acc_cc_mode << 4);
  int32_t Byte_5 = frs_acc_alivecounter + (frs_acc_shutdownmode << 4) + (frs_acc_minimumbraking << 6) + (frs_acc_brakepreferred << 7);
  int32_t Byte_6 = (frs_acc_driveoffreq << 7) + (frs_acc_adtlowerlimitaxvcv + 25.4) * 5;
  frs_acc_checksum_= ((Byte_0 + Byte_1 + Byte_2 + Byte_3 + Byte_4 + Byte_5 + Byte_6) & 0xff) ^ 0xff;
  return this;
 }

// config detail: {'name': 'FRS_ACC_CheckSum', 'offset': 0.0, 'precision': 1.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|155]', 'bit': 63, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
void Acc2250::set_p_frs_acc_checksum(uint8_t* data,
    int frs_acc_checksum) {
  frs_acc_checksum = ProtocolData::BoundedValue(0, 255, frs_acc_checksum);
  int x = frs_acc_checksum;

  Byte to_set(data + 7);
  to_set.set_value(x, 0, 8);
}


Acc2250* Acc2250::set_frs_acc_driveoffreq(
    Acc2_250::Frs_acc_driveoffreqType frs_acc_driveoffreq) {
  frs_acc_driveoffreq_ = frs_acc_driveoffreq;
  return this;
 }

// config detail: {'name': 'FRS_ACC_DriveoffReq', 'enum': {0: 'FRS_ACC_DRIVEOFFREQ_NO_REQUEST', 1: 'FRS_ACC_DRIVEOFFREQ_REQUESTED'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 55, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc2250::set_p_frs_acc_driveoffreq(uint8_t* data,
    Acc2_250::Frs_acc_driveoffreqType frs_acc_driveoffreq) {
  int x = frs_acc_driveoffreq;

  Byte to_set(data + 6);
  to_set.set_value(x, 7, 1);
}


Acc2250* Acc2250::set_frs_acc_adtlowerlimitaxvcv(
    double frs_acc_adtlowerlimitaxvcv) {
  frs_acc_adtlowerlimitaxvcv_ = frs_acc_adtlowerlimitaxvcv;
  return this;
 }

// config detail: {'name': 'FRS_ACC_aDtLowerLimitAxvCv', 'offset': -25.4, 'precision': 0.2, 'len': 7, 'is_signed_var': False, 'physical_range': '[-25.4|0]', 'bit': 54, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
void Acc2250::set_p_frs_acc_adtlowerlimitaxvcv(uint8_t* data,
    double frs_acc_adtlowerlimitaxvcv) {
  frs_acc_adtlowerlimitaxvcv = ProtocolData::BoundedValue(-25.4, 0.0, frs_acc_adtlowerlimitaxvcv);
  int x = (frs_acc_adtlowerlimitaxvcv - -25.400000) * 5;

  Byte to_set(data + 6);
  to_set.set_value(x, 0, 7);
}


Acc2250* Acc2250::set_frs_acc_brakepreferred(
    Acc2_250::Frs_acc_brakepreferredType frs_acc_brakepreferred) {
  frs_acc_brakepreferred_ = frs_acc_brakepreferred;
  return this;
 }

// config detail: {'name': 'FRS_ACC_BrakePreferred', 'enum': {0: 'FRS_ACC_BRAKEPREFERRED_NO_DEMAND', 1: 'FRS_ACC_BRAKEPREFERRED_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 47, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc2250::set_p_frs_acc_brakepreferred(uint8_t* data,
    Acc2_250::Frs_acc_brakepreferredType frs_acc_brakepreferred) {
  int x = frs_acc_brakepreferred;

  Byte to_set(data + 5);
  to_set.set_value(x, 7, 1);
}


Acc2250* Acc2250::set_frs_acc_minimumbraking(
    Acc2_250::Frs_acc_minimumbrakingType frs_acc_minimumbraking) {
  frs_acc_minimumbraking_ = frs_acc_minimumbraking;
  return this;
 }

// config detail: {'name': 'FRS_ACC_MinimumBraking', 'enum': {0: 'FRS_ACC_MINIMUMBRAKING_NO_DEMAND', 1: 'FRS_ACC_MINIMUMBRAKING_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 46, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc2250::set_p_frs_acc_minimumbraking(uint8_t* data,
    Acc2_250::Frs_acc_minimumbrakingType frs_acc_minimumbraking) {
  int x = frs_acc_minimumbraking;

  Byte to_set(data + 5);
  to_set.set_value(x, 6, 1);
}


Acc2250* Acc2250::set_frs_acc_shutdownmode(
    Acc2_250::Frs_acc_shutdownmodeType frs_acc_shutdownmode) {
  frs_acc_shutdownmode_ = frs_acc_shutdownmode;
  return this;
 }

// config detail: {'name': 'FRS_ACC_ShutdownMode', 'enum': {0: 'FRS_ACC_SHUTDOWNMODE_SOFT_OFF', 1: 'FRS_ACC_SHUTDOWNMODE_FAST_OFF', 2: 'FRS_ACC_SHUTDOWNMODE_IMMEDIATE_OFF', 3: 'FRS_ACC_SHUTDOWNMODE_NO_REQUEST'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 45, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc2250::set_p_frs_acc_shutdownmode(uint8_t* data,
    Acc2_250::Frs_acc_shutdownmodeType frs_acc_shutdownmode) {
  int x = frs_acc_shutdownmode;

  Byte to_set(data + 5);
  to_set.set_value(x, 4, 2);
}

int ACC2_counter = 30;
Acc2250* Acc2250::set_frs_acc_alivecounter() {
  if (ACC2_counter > 30) {
  ACC2_counter = 0;
  } else {
  ACC2_counter++;
  }

  frs_acc_alivecounter_ = floor(ACC2_counter / 2);
  return this;
 }

// config detail: {'name': 'FRS_ACC_AliveCounter', 'offset': 0.0, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'physical_range': '[0|15]', 'bit': 43, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
void Acc2250::set_p_frs_acc_alivecounter(uint8_t* data,
    int frs_acc_alivecounter) {
  frs_acc_alivecounter = ProtocolData::BoundedValue(0, 15, frs_acc_alivecounter);
  int x = frs_acc_alivecounter;

  Byte to_set(data + 5);
  to_set.set_value(x, 0, 4);
}


Acc2250* Acc2250::set_frs_acc_cc_mode(
    Acc2_250::Frs_acc_cc_modeType frs_acc_cc_mode) {
  frs_acc_cc_mode_ = frs_acc_cc_mode;
  return this;
 }

// config detail: {'name': 'FRS_ACC_CC_Mode', 'enum': {0: 'FRS_ACC_CC_MODE_OFF_MODE', 1: 'FRS_ACC_CC_MODE_PASSIVE_MODE', 2: 'FRS_ACC_CC_MODE_STAND_BY_MODE', 3: 'FRS_ACC_CC_MODE_ACTIVE_CONTROL_MODE', 4: 'FRS_ACC_CC_MODE_BRAKE_ONLY_MODE', 5: 'FRS_ACC_CC_MODE_OVERRIDE', 6: 'FRS_ACC_CC_MODE_STAND_ACTIVE', 7: 'FRS_ACC_CC_MODE_STAND_WAIT', 8: 'FRS_ACC_CC_MODE_TEMPORARY_FAILURE', 9: 'FRS_ACC_CC_MODE_PERMANENT_FAILURE'}, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|15]', 'bit': 39, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc2250::set_p_frs_acc_cc_mode(uint8_t* data,
    Acc2_250::Frs_acc_cc_modeType frs_acc_cc_mode) {
  int x = frs_acc_cc_mode;

  Byte to_set(data + 4);
  to_set.set_value(x, 4, 4);
}


Acc2250* Acc2250::set_frs_acc_accecomflowervalue(
    double frs_acc_accecomflowervalue) {
  frs_acc_accecomflowervalue_ = frs_acc_accecomflowervalue;
  return this;
 }

// config detail: {'name': 'FRS_ACC_AcceComfLowerValue', 'offset': -7.0, 'precision': 0.05, 'len': 8, 'is_signed_var': False, 'physical_range': '[-7|5.75]', 'bit': 31, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
void Acc2250::set_p_frs_acc_accecomflowervalue(uint8_t* data,
    double frs_acc_accecomflowervalue) {
  frs_acc_accecomflowervalue = ProtocolData::BoundedValue(-7.0, 5.75, frs_acc_accecomflowervalue);
  int x = (frs_acc_accecomflowervalue - -7.000000) * 20;

  Byte to_set(data + 3);
  to_set.set_value(x, 0, 8);
}


Acc2250* Acc2250::set_frs_acc_accecomfuppervalue(
    double frs_acc_accecomfuppervalue) {
  frs_acc_accecomfuppervalue_ = frs_acc_accecomfuppervalue;
  return this;
 }

// config detail: {'name': 'FRS_ACC_AcceComfUpperValue', 'offset': -7.0, 'precision': 0.05, 'len': 8, 'is_signed_var': False, 'physical_range': '[-7|5.75]', 'bit': 23, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
void Acc2250::set_p_frs_acc_accecomfuppervalue(uint8_t* data,
    double frs_acc_accecomfuppervalue) {
  frs_acc_accecomfuppervalue = ProtocolData::BoundedValue(-7.0, 5.75, frs_acc_accecomfuppervalue);
  int x = (frs_acc_accecomfuppervalue - -7.000000) * 20;

  Byte to_set(data + 2);
  to_set.set_value(x, 0, 8);
}


Acc2250* Acc2250::set_frs_acc_dectostopreq(
    Acc2_250::Frs_acc_dectostopreqType frs_acc_dectostopreq) {
  frs_acc_dectostopreq_ = frs_acc_dectostopreq;
  return this;
 }

// config detail: {'name': 'FRS_ACC_DecToStopReq', 'enum': {0: 'FRS_ACC_DECTOSTOPREQ_NO_REQUEST', 1: 'FRS_ACC_DECTOSTOPREQ_REQUEST'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 15, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc2250::set_p_frs_acc_dectostopreq(uint8_t* data,
    Acc2_250::Frs_acc_dectostopreqType frs_acc_dectostopreq) {
  int x = frs_acc_dectostopreq;

  Byte to_set(data + 1);
  to_set.set_value(x, 7, 1);
}


Acc2250* Acc2250::set_frs_acc_adtupperlimitaxvcv(
    double frs_acc_adtupperlimitaxvcv) {
  frs_acc_adtupperlimitaxvcv_ = frs_acc_adtupperlimitaxvcv;
  return this;
 }

// config detail: {'name': 'FRS_ACC_aDtUpperLimitAxvCv', 'offset': 0.0, 'precision': 0.2, 'len': 7, 'is_signed_var': False, 'physical_range': '[0|25.4]', 'bit': 14, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
void Acc2250::set_p_frs_acc_adtupperlimitaxvcv(uint8_t* data,
    double frs_acc_adtupperlimitaxvcv) {
  frs_acc_adtupperlimitaxvcv = ProtocolData::BoundedValue(0.0, 25.4, frs_acc_adtupperlimitaxvcv);
  int x = frs_acc_adtupperlimitaxvcv * 5;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 7);
}


Acc2250* Acc2250::set_frs_acc_axvcvaim(
    double frs_acc_axvcvaim) {
  frs_acc_axvcvaim_ = frs_acc_axvcvaim;
  return this;
 }

// config detail: {'name': 'FRS_ACC_axvCvAim', 'offset': -7.0, 'precision': 0.05, 'len': 8, 'is_signed_var': False, 'physical_range': '[-7|5.75]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': 'm/s2'}
void Acc2250::set_p_frs_acc_axvcvaim(uint8_t* data,
    double frs_acc_axvcvaim) {
  frs_acc_axvcvaim = ProtocolData::BoundedValue(-7.0, 5.75, frs_acc_axvcvaim);
  int x = (frs_acc_axvcvaim - -7.000000) * 20;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}

}  // namespace a45
}  // namespace canbus
}  // namespace apollo
