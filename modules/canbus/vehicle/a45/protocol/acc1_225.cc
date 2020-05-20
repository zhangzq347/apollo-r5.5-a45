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

#include "modules/canbus/vehicle/a45/protocol/acc1_225.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace a45 {

using ::apollo::drivers::canbus::Byte;

const int32_t Acc1225::ID = 0x225;

// public
Acc1225::Acc1225() { Reset(); }

uint32_t Acc1225::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Acc1225::UpdateData(uint8_t* data) {
  set_acc_messagecounteracc1();
  set_acc_checksumacc1(acc_target_type_, acc_pcwonoff_, acc_aeb_axtarfortcu_,
    acc_pcw_prewarning_, acc_pcw_latentwarning_, acc_aeb_request_, acc_textinfo_,
    acc_accfailinfo_, acc_accmode_hmi_, acc_taugapset_, acc_takeoverreq_,
    acc_objvalid_, acc_pcwstate_, acc_aeb_onoff_, acc_aebstate_, acc_dxtarobj_,
    acc_vsetdis_, acc_messagecounteracc1_);

  set_p_acc_messagecounteracc1(data, acc_messagecounteracc1_);
  set_p_acc_checksumacc1(data, acc_checksumacc1_);
  set_p_acc_target_type(data, acc_target_type_);
  set_p_acc_pcwonoff(data, acc_pcwonoff_);
  set_p_acc_aeb_axtarfortcu(data, acc_aeb_axtarfortcu_);
  set_p_acc_pcw_prewarning(data, acc_pcw_prewarning_);
  set_p_acc_pcw_latentwarning(data, acc_pcw_latentwarning_);
  set_p_acc_aeb_request(data, acc_aeb_request_);
  set_p_acc_textinfo(data, acc_textinfo_);
  set_p_acc_accfailinfo(data, acc_accfailinfo_);
  set_p_acc_accmode_hmi(data, acc_accmode_hmi_);
  set_p_acc_taugapset(data, acc_taugapset_);
  set_p_acc_takeoverreq(data, acc_takeoverreq_);
  set_p_acc_objvalid(data, acc_objvalid_);
  set_p_acc_pcwstate(data, acc_pcwstate_);
  set_p_acc_aeb_onoff(data, acc_aeb_onoff_);
  set_p_acc_aebstate(data, acc_aebstate_);
  set_p_acc_dxtarobj(data, acc_dxtarobj_);
  set_p_acc_vsetdis(data, acc_vsetdis_);
}

void Acc1225::Reset() {
  // TODO(All) :  you should check this manually
  acc_messagecounteracc1_ = 0;
  acc_checksumacc1_ = 0;
  acc_target_type_ = Acc1_225::ACC_TARGET_TYPE_CAR;
  acc_pcwonoff_ = Acc1_225::ACC_PCWONOFF_OFF;
  acc_aeb_axtarfortcu_ = 0.0;
  acc_pcw_prewarning_ = Acc1_225::ACC_PCW_PREWARNING_NO_WARNING;
  acc_pcw_latentwarning_ = Acc1_225::ACC_PCW_LATENTWARNING_NO_WARNING;
  acc_aeb_request_ = Acc1_225::ACC_AEB_REQUEST_NOT_REQUEST;
  acc_textinfo_ = Acc1_225::ACC_TEXTINFO_NO_DISPLAY;
  acc_accfailinfo_ = Acc1_225::ACC_ACCFAILINFO_NO_ERROR;
  acc_accmode_hmi_ = Acc1_225::ACC_ACCMODE_HMI_OFF_MODE;
  acc_taugapset_ = Acc1_225::ACC_TAUGAPSET_TAUGAP_0;
  acc_takeoverreq_ = Acc1_225::ACC_TAKEOVERREQ_NO_TAKEOVER_REQUEST;
  acc_objvalid_ = Acc1_225::ACC_OBJVALID_NO_OBJECT;
  acc_pcwstate_ = Acc1_225::ACC_PCWSTATE_NO_ERROR;
  acc_aeb_onoff_ = Acc1_225::ACC_AEB_ONOFF_OFF;
  acc_aebstate_ = Acc1_225::ACC_AEBSTATE_NO_ERROR;
  acc_dxtarobj_ = Acc1_225::ACC_DXTAROBJ_DISTANCE_0;
  acc_vsetdis_ = 30;
}

int ACC1_counter = 30;
Acc1225* Acc1225::set_acc_messagecounteracc1() {
  if (ACC1_counter > 30) {
  ACC1_counter = 0;
  } else {
  ACC1_counter++;
  }
  acc_messagecounteracc1_ = floor(ACC1_counter / 2);
  return this;
 }

// config detail: {'name': 'ACC_MessageCounterACC1', 'offset': 0.0, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'physical_range': '[0|15]', 'bit': 51, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_messagecounteracc1(uint8_t* data,
    int acc_messagecounteracc1) {
  acc_messagecounteracc1 = ProtocolData::BoundedValue(0, 15, acc_messagecounteracc1);
  int x = acc_messagecounteracc1;

  Byte to_set(data + 6);
  to_set.set_value(x, 0, 4);
}

Acc1225* Acc1225::set_acc_checksumacc1(Acc1_225::Acc_target_typeType acc_target_type,
    Acc1_225::Acc_pcwonoffType acc_pcwonoff, double acc_aeb_axtarfortcu,
    Acc1_225::Acc_pcw_prewarningType acc_pcw_prewarning,
    Acc1_225::Acc_pcw_latentwarningType acc_pcw_latentwarning,
    Acc1_225::Acc_aeb_requestType acc_aeb_request, Acc1_225::Acc_textinfoType acc_textinfo,
    Acc1_225::Acc_accfailinfoType acc_accfailinfo, Acc1_225::Acc_accmode_hmiType acc_accmode_hmi,
    Acc1_225::Acc_taugapsetType acc_taugapset, Acc1_225::Acc_takeoverreqType acc_takeoverreq,
    Acc1_225::Acc_objvalidType acc_objvalid, Acc1_225::Acc_pcwstateType acc_pcwstate,
    Acc1_225::Acc_aeb_onoffType acc_aeb_onoff, Acc1_225::Acc_aebstateType acc_aebstate,
    Acc1_225::Acc_dxtarobjType acc_dxtarobj, int32_t acc_vsetdis, int32_t acc_messagecounteracc1) {

  int32_t Byte_0 = acc_vsetdis;
  int32_t Byte_1 = acc_dxtarobj + (acc_taugapset << 3) + (acc_objvalid << 6) + (acc_takeoverreq << 7);
  int32_t Byte_2 = acc_aebstate + (acc_aeb_onoff << 1) + (acc_pcwstate << 2) + (acc_accmode_hmi << 3) +(acc_accfailinfo << 6);
  int32_t Byte_3 = acc_textinfo + (acc_aeb_request << 5) + (acc_pcw_latentwarning << 6) + (acc_pcw_prewarning << 7);
  int32_t acc_aeb_axtarfortcu1 = (acc_aeb_axtarfortcu - -16.000000) * 2048;
  int32_t Byte_4 = (acc_aeb_axtarfortcu1 >> 8);
  int32_t Byte_5 = (acc_aeb_axtarfortcu1 & 0xff);
  int32_t Byte_6 = acc_messagecounteracc1 + (acc_target_type << 4) + (acc_pcwonoff << 6);
  acc_checksumacc1_ = ((Byte_0 + Byte_1 + Byte_2 + Byte_3 + Byte_4 + Byte_5 + Byte_6) & 0xff) ^ 0xff;
  return this;
 }

// config detail: {'name': 'ACC_CheckSumACC1', 'offset': 0.0, 'precision': 1.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|255]', 'bit': 63, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_checksumacc1(uint8_t* data,
    int32_t acc_checksumacc1) {
  acc_checksumacc1 = ProtocolData::BoundedValue(0, 255, acc_checksumacc1);
  int x = acc_checksumacc1;

  Byte to_set(data + 7);
  to_set.set_value(x, 0, 8);
}


Acc1225* Acc1225::set_acc_target_type(
    Acc1_225::Acc_target_typeType acc_target_type) {
  acc_target_type_ = acc_target_type;
  return this;
 }

// config detail: {'name': 'ACC_Target_Type', 'enum': {0: 'ACC_TARGET_TYPE_CAR', 1: 'ACC_TARGET_TYPE_PEDESTRIAN', 2: 'ACC_TARGET_TYPE_TARGET_TYPE_UNKNOWN'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 53, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_target_type(uint8_t* data,
    Acc1_225::Acc_target_typeType acc_target_type) {
  int x = acc_target_type;

  Byte to_set(data + 6);
  to_set.set_value(x, 4, 2);
}


Acc1225* Acc1225::set_acc_pcwonoff(
    Acc1_225::Acc_pcwonoffType acc_pcwonoff) {
  acc_pcwonoff_ = acc_pcwonoff;
  return this;
 }

// config detail: {'name': 'ACC_PCWONOFF', 'enum': {0: 'ACC_PCWONOFF_OFF', 1: 'ACC_PCWONOFF_PCW_LOW_SENSITIVE', 2: 'ACC_PCWONOFF_PCW_STANDARD', 3: 'ACC_PCWONOFF_PCW_HIGH_SENSITIVE'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 55, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_pcwonoff(uint8_t* data,
    Acc1_225::Acc_pcwonoffType acc_pcwonoff) {
  int x = acc_pcwonoff;

  Byte to_set(data + 6);
  to_set.set_value(x, 6, 2);
}


Acc1225* Acc1225::set_acc_aeb_axtarfortcu(
    double acc_aeb_axtarfortcu) {
  acc_aeb_axtarfortcu_ = acc_aeb_axtarfortcu;
  return this;
 }

// config detail: {'name': 'ACC_AEB_axTarforTCU', 'offset': -16.0, 'precision': 0.0004882, 'len': 16, 'is_signed_var': False, 'physical_range': '[-16|16]', 'bit': 39, 'type': 'double', 'order': 'motorola', 'physical_unit': 'm/s2'}
void Acc1225::set_p_acc_aeb_axtarfortcu(uint8_t* data,
    double acc_aeb_axtarfortcu) {
  acc_aeb_axtarfortcu = ProtocolData::BoundedValue(-16.0, 16.0, acc_aeb_axtarfortcu);
  int x = (acc_aeb_axtarfortcu - -16.000000) * 2048;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 5);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 4);
  to_set1.set_value(t, 0, 8);
}


Acc1225* Acc1225::set_acc_pcw_prewarning(
    Acc1_225::Acc_pcw_prewarningType acc_pcw_prewarning) {
  acc_pcw_prewarning_ = acc_pcw_prewarning;
  return this;
 }

// config detail: {'name': 'ACC_PCW_preWarning', 'enum': {0: 'ACC_PCW_PREWARNING_NO_WARNING', 1: 'ACC_PCW_PREWARNING_WARNING'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 31, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_pcw_prewarning(uint8_t* data,
    Acc1_225::Acc_pcw_prewarningType acc_pcw_prewarning) {
  int x = acc_pcw_prewarning;

  Byte to_set(data + 3);
  to_set.set_value(x, 7, 1);
}


Acc1225* Acc1225::set_acc_pcw_latentwarning(
    Acc1_225::Acc_pcw_latentwarningType acc_pcw_latentwarning) {
  acc_pcw_latentwarning_ = acc_pcw_latentwarning;
  return this;
 }

// config detail: {'name': 'ACC_PCW_latentWarning', 'enum': {0: 'ACC_PCW_LATENTWARNING_NO_WARNING', 1: 'ACC_PCW_LATENTWARNING_WARNING'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 30, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_pcw_latentwarning(uint8_t* data,
    Acc1_225::Acc_pcw_latentwarningType acc_pcw_latentwarning) {
  int x = acc_pcw_latentwarning;

  Byte to_set(data + 3);
  to_set.set_value(x, 6, 1);
}


Acc1225* Acc1225::set_acc_aeb_request(
    Acc1_225::Acc_aeb_requestType acc_aeb_request) {
  acc_aeb_request_ = acc_aeb_request;
  return this;
 }

// config detail: {'name': 'ACC_AEB_Request', 'enum': {0: 'ACC_AEB_REQUEST_NOT_REQUEST', 1: 'ACC_AEB_REQUEST_REQUEST'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 29, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_aeb_request(uint8_t* data,
    Acc1_225::Acc_aeb_requestType acc_aeb_request) {
  int x = acc_aeb_request;

  Byte to_set(data + 3);
  to_set.set_value(x, 5, 1);
}


Acc1225* Acc1225::set_acc_textinfo(
    Acc1_225::Acc_textinfoType acc_textinfo) {
  acc_textinfo_ = acc_textinfo;
  return this;
 }

// config detail: {'name': 'ACC_Textinfo', 'enum': {0: 'ACC_TEXTINFO_NO_DISPLAY', 1: 'ACC_TEXTINFO_UNABLE_TO_ACTIVE_ACC', 2: 'ACC_TEXTINFO_ACC_ACTIVE_CONTROL_IS_CANCELLED', 3: 'ACC_TEXTINFO_ACTIVE', 4: 'ACC_TEXTINFO_ACC_PEPS_TEMPORARY_UNAVAILABLE', 5: 'ACC_TEXTINFO_MRR_BLINDNESS', 6: 'ACC_TEXTINFO_ACC_AND_PEBS_ERROR', 7: 'ACC_TEXTINFO_ACC_SWITCHED_ON', 8: 'ACC_TEXTINFO_ACC_SWITCHED_OFF', 9: 'ACC_TEXTINFO_EPB_ACTIVATE', 10: 'ACC_TEXTINFO_NO_FORWARD_GEAR', 11: 'ACC_TEXTINFO_SEATBELT_UNBUCKLED', 12: 'ACC_TEXTINFO_EMS_DON_T_RESPOND_RESERVED', 13: 'ACC_TEXTINFO_ACC_DEACTIVATE', 14: 'ACC_TEXTINFO_SYSTEM_ENTER_STAND_WAIT', 15: 'ACC_TEXTINFO_ACC_UNINTENDED_EXIT_WARNING', 16: 'ACC_TEXTINFO_ESP_OFF_RESERVED', 17: 'ACC_TEXTINFO_SPEED_OVER_150KPH_RESERVED', 18: 'ACC_TEXTINFO_BONNET_OPEN_RESERVED', 19: 'ACC_TEXTINFO_PEBS_ERROR_RESERVED', 20: 'ACC_TEXTINFO_ACC_ERROR_RESERVED', 21: 'ACC_TEXTINFO_OVERRIDE_RESERVED'}, 'precision': 1.0, 'len': 5, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|31]', 'bit': 28, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_textinfo(uint8_t* data,
    Acc1_225::Acc_textinfoType acc_textinfo) {
  int x = acc_textinfo;

  Byte to_set(data + 3);
  to_set.set_value(x, 0, 5);
}


Acc1225* Acc1225::set_acc_accfailinfo(
    Acc1_225::Acc_accfailinfoType acc_accfailinfo) {
  acc_accfailinfo_ = acc_accfailinfo;
  return this;
 }

// config detail: {'name': 'ACC_ACCFailInfo', 'enum': {0: 'ACC_ACCFAILINFO_NO_ERROR', 1: 'ACC_ACCFAILINFO_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 22, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_accfailinfo(uint8_t* data,
    Acc1_225::Acc_accfailinfoType acc_accfailinfo) {
  int x = acc_accfailinfo;

  Byte to_set(data + 2);
  to_set.set_value(x, 6, 1);
}


Acc1225* Acc1225::set_acc_accmode_hmi(
    Acc1_225::Acc_accmode_hmiType acc_accmode_hmi) {
  acc_accmode_hmi_ = acc_accmode_hmi;
  return this;
 }

// config detail: {'name': 'ACC_ACCMode_HMI', 'enum': {0: 'ACC_ACCMODE_HMI_OFF_MODE', 1: 'ACC_ACCMODE_HMI_PASSIVE_MODE', 2: 'ACC_ACCMODE_HMI_STAND_BY_MODE', 3: 'ACC_ACCMODE_HMI_ACTIVE_CONTROL_MODE', 4: 'ACC_ACCMODE_HMI_BRAKE_ONLY_MODE', 5: 'ACC_ACCMODE_HMI_OVERRIDE', 6: 'ACC_ACCMODE_HMI_STANDSTILL', 7: 'ACC_ACCMODE_HMI_FAILURE_MODE'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 21, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_accmode_hmi(uint8_t* data,
    Acc1_225::Acc_accmode_hmiType acc_accmode_hmi) {
  int x = acc_accmode_hmi;

  Byte to_set(data + 2);
  to_set.set_value(x, 3, 3);
}


Acc1225* Acc1225::set_acc_taugapset(
    Acc1_225::Acc_taugapsetType acc_taugapset) {
  acc_taugapset_ = acc_taugapset;
  return this;
 }

// config detail: {'name': 'ACC_TauGapSet', 'enum': {0: 'ACC_TAUGAPSET_TAUGAP_0', 1: 'ACC_TAUGAPSET_TAUGAP_1', 2: 'ACC_TAUGAPSET_TAUGAP_2', 3: 'ACC_TAUGAPSET_TAUGAP_3', 4: 'ACC_TAUGAPSET_TAUGAP_4', 5: 'ACC_TAUGAPSET_TAUGAP_5', 6: 'ACC_TAUGAPSET_TAUGAP_6', 7: 'ACC_TAUGAPSET_TAUGAP_7'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 13, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_taugapset(uint8_t* data,
    Acc1_225::Acc_taugapsetType acc_taugapset) {
  int x = acc_taugapset;

  Byte to_set(data + 1);
  to_set.set_value(x, 3, 3);
}


Acc1225* Acc1225::set_acc_takeoverreq(
    Acc1_225::Acc_takeoverreqType acc_takeoverreq) {
  acc_takeoverreq_ = acc_takeoverreq;
  return this;
 }

// config detail: {'name': 'ACC_TakeOverReq', 'enum': {0: 'ACC_TAKEOVERREQ_NO_TAKEOVER_REQUEST', 1: 'ACC_TAKEOVERREQ_VALID_TAKEOVER_REQUEST'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 15, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_takeoverreq(uint8_t* data,
    Acc1_225::Acc_takeoverreqType acc_takeoverreq) {
  int x = acc_takeoverreq;

  Byte to_set(data + 1);
  to_set.set_value(x, 7, 1);
}


Acc1225* Acc1225::set_acc_objvalid(
    Acc1_225::Acc_objvalidType acc_objvalid) {
  acc_objvalid_ = acc_objvalid;
  return this;
 }

// config detail: {'name': 'ACC_ObjValid', 'enum': {0: 'ACC_OBJVALID_NO_OBJECT', 1: 'ACC_OBJVALID_TARGET_OBJECT_DETECTED'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 14, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_objvalid(uint8_t* data,
    Acc1_225::Acc_objvalidType acc_objvalid) {
  int x = acc_objvalid;

  Byte to_set(data + 1);
  to_set.set_value(x, 6, 1);
}


Acc1225* Acc1225::set_acc_pcwstate(
    Acc1_225::Acc_pcwstateType acc_pcwstate) {
  acc_pcwstate_ = acc_pcwstate;
  return this;
 }

// config detail: {'name': 'ACC_PCWState', 'enum': {0: 'ACC_PCWSTATE_NO_ERROR', 1: 'ACC_PCWSTATE_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 18, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_pcwstate(uint8_t* data,
    Acc1_225::Acc_pcwstateType acc_pcwstate) {
  int x = acc_pcwstate;

  Byte to_set(data + 2);
  to_set.set_value(x, 2, 1);
}


Acc1225* Acc1225::set_acc_aeb_onoff(
    Acc1_225::Acc_aeb_onoffType acc_aeb_onoff) {
  acc_aeb_onoff_ = acc_aeb_onoff;
  return this;
 }

// config detail: {'name': 'ACC_AEB_ONOFF', 'enum': {0: 'ACC_AEB_ONOFF_OFF', 1: 'ACC_AEB_ONOFF_ON'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 17, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_aeb_onoff(uint8_t* data,
    Acc1_225::Acc_aeb_onoffType acc_aeb_onoff) {
  int x = acc_aeb_onoff;

  Byte to_set(data + 2);
  to_set.set_value(x, 1, 1);
}


Acc1225* Acc1225::set_acc_aebstate(
    Acc1_225::Acc_aebstateType acc_aebstate) {
  acc_aebstate_ = acc_aebstate;
  return this;
 }

// config detail: {'name': 'ACC_AEBState', 'enum': {0: 'ACC_AEBSTATE_NO_ERROR', 1: 'ACC_AEBSTATE_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 16, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_aebstate(uint8_t* data,
    Acc1_225::Acc_aebstateType acc_aebstate) {
  int x = acc_aebstate;

  Byte to_set(data + 2);
  to_set.set_value(x, 0, 1);
}


Acc1225* Acc1225::set_acc_dxtarobj(
    Acc1_225::Acc_dxtarobjType acc_dxtarobj) {
  acc_dxtarobj_ = acc_dxtarobj;
  return this;
 }

// config detail: {'name': 'ACC_dxTarObj', 'enum': {0: 'ACC_DXTAROBJ_DISTANCE_0', 1: 'ACC_DXTAROBJ_DISTANCE_1', 2: 'ACC_DXTAROBJ_DISTANCE_2', 3: 'ACC_DXTAROBJ_DISTANCE_3', 4: 'ACC_DXTAROBJ_DISTANCE_4', 5: 'ACC_DXTAROBJ_DISTANCE_5', 6: 'ACC_DXTAROBJ_DISTANCE_6', 7: 'ACC_DXTAROBJ_DISTANCE_7'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 10, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
void Acc1225::set_p_acc_dxtarobj(uint8_t* data,
    Acc1_225::Acc_dxtarobjType acc_dxtarobj) {
  int x = acc_dxtarobj;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 3);
}


Acc1225* Acc1225::set_acc_vsetdis(
    int32_t acc_vsetdis) {
  acc_vsetdis_ = acc_vsetdis;
  return this;
 }

// config detail: {'name': 'ACC_vSetDis', 'offset': 0.0, 'precision': 1.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|254]', 'bit': 7, 'type': 'int', 'order': 'motorola', 'physical_unit': 'km/h'}
void Acc1225::set_p_acc_vsetdis(uint8_t* data,
    int32_t acc_vsetdis) {
  acc_vsetdis = ProtocolData::BoundedValue(0, 254, acc_vsetdis);
  int x = acc_vsetdis;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}

}  // namespace a45
}  // namespace canbus
}  // namespace apollo
