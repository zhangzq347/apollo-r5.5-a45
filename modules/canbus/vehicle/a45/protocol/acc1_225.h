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

#pragma once

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/canbus/proto/chassis_detail.pb.h"

namespace apollo {
namespace canbus {
namespace a45 {

class Acc1225 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Acc1225();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'name': 'ACC_MessageCounterACC1', 'offset': 0.0, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'physical_range': '[0|15]', 'bit': 51, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_messagecounteracc1();

  // config detail: {'name': 'ACC_CheckSumACC1', 'offset': 0.0, 'precision': 1.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|255]', 'bit': 63, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_checksumacc1(Acc1_225::Acc_target_typeType acc_target_type,
    Acc1_225::Acc_pcwonoffType acc_pcwonoff, double acc_aeb_axtarfortcu,
    Acc1_225::Acc_pcw_prewarningType acc_pcw_prewarning,
    Acc1_225::Acc_pcw_latentwarningType acc_pcw_latentwarning,
    Acc1_225::Acc_aeb_requestType acc_aeb_request, Acc1_225::Acc_textinfoType acc_textinfo,
    Acc1_225::Acc_accfailinfoType acc_accfailinfo, Acc1_225::Acc_accmode_hmiType acc_accmode_hmi,
    Acc1_225::Acc_taugapsetType acc_taugapset, Acc1_225::Acc_takeoverreqType acc_takeoverreq,
    Acc1_225::Acc_objvalidType acc_objvalid, Acc1_225::Acc_pcwstateType acc_pcwstate,
    Acc1_225::Acc_aeb_onoffType acc_aeb_onoff, Acc1_225::Acc_aebstateType acc_aebstate,
    Acc1_225::Acc_dxtarobjType acc_dxtarobj, int32_t acc_vsetdis, int32_t acc_messagecounteracc1);

  // config detail: {'name': 'ACC_Target_Type', 'enum': {0: 'ACC_TARGET_TYPE_CAR', 1: 'ACC_TARGET_TYPE_PEDESTRIAN', 2: 'ACC_TARGET_TYPE_TARGET_TYPE_UNKNOWN'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 53, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_target_type(Acc1_225::Acc_target_typeType acc_target_type);

  // config detail: {'name': 'ACC_PCWONOFF', 'enum': {0: 'ACC_PCWONOFF_OFF', 1: 'ACC_PCWONOFF_PCW_LOW_SENSITIVE', 2: 'ACC_PCWONOFF_PCW_STANDARD', 3: 'ACC_PCWONOFF_PCW_HIGH_SENSITIVE'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 55, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_pcwonoff(Acc1_225::Acc_pcwonoffType acc_pcwonoff);

  // config detail: {'name': 'ACC_AEB_axTarforTCU', 'offset': -16.0, 'precision': 0.0004882, 'len': 16, 'is_signed_var': False, 'physical_range': '[-16|16]', 'bit': 39, 'type': 'double', 'order': 'motorola', 'physical_unit': 'm/s2'}
  Acc1225* set_acc_aeb_axtarfortcu(double acc_aeb_axtarfortcu);

  // config detail: {'name': 'ACC_PCW_preWarning', 'enum': {0: 'ACC_PCW_PREWARNING_NO_WARNING', 1: 'ACC_PCW_PREWARNING_WARNING'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 31, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_pcw_prewarning(Acc1_225::Acc_pcw_prewarningType acc_pcw_prewarning);

  // config detail: {'name': 'ACC_PCW_latentWarning', 'enum': {0: 'ACC_PCW_LATENTWARNING_NO_WARNING', 1: 'ACC_PCW_LATENTWARNING_WARNING'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 30, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_pcw_latentwarning(Acc1_225::Acc_pcw_latentwarningType acc_pcw_latentwarning);

  // config detail: {'name': 'ACC_AEB_Request', 'enum': {0: 'ACC_AEB_REQUEST_NOT_REQUEST', 1: 'ACC_AEB_REQUEST_REQUEST'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 29, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_aeb_request(Acc1_225::Acc_aeb_requestType acc_aeb_request);

  // config detail: {'name': 'ACC_Textinfo', 'enum': {0: 'ACC_TEXTINFO_NO_DISPLAY', 1: 'ACC_TEXTINFO_UNABLE_TO_ACTIVE_ACC', 2: 'ACC_TEXTINFO_ACC_ACTIVE_CONTROL_IS_CANCELLED', 3: 'ACC_TEXTINFO_ACTIVE', 4: 'ACC_TEXTINFO_ACC_PEPS_TEMPORARY_UNAVAILABLE', 5: 'ACC_TEXTINFO_MRR_BLINDNESS', 6: 'ACC_TEXTINFO_ACC_AND_PEBS_ERROR', 7: 'ACC_TEXTINFO_ACC_SWITCHED_ON', 8: 'ACC_TEXTINFO_ACC_SWITCHED_OFF', 9: 'ACC_TEXTINFO_EPB_ACTIVATE', 10: 'ACC_TEXTINFO_NO_FORWARD_GEAR', 11: 'ACC_TEXTINFO_SEATBELT_UNBUCKLED', 12: 'ACC_TEXTINFO_EMS_DON_T_RESPOND_RESERVED', 13: 'ACC_TEXTINFO_ACC_DEACTIVATE', 14: 'ACC_TEXTINFO_SYSTEM_ENTER_STAND_WAIT', 15: 'ACC_TEXTINFO_ACC_UNINTENDED_EXIT_WARNING', 16: 'ACC_TEXTINFO_ESP_OFF_RESERVED', 17: 'ACC_TEXTINFO_SPEED_OVER_150KPH_RESERVED', 18: 'ACC_TEXTINFO_BONNET_OPEN_RESERVED', 19: 'ACC_TEXTINFO_PEBS_ERROR_RESERVED', 20: 'ACC_TEXTINFO_ACC_ERROR_RESERVED', 21: 'ACC_TEXTINFO_OVERRIDE_RESERVED'}, 'precision': 1.0, 'len': 5, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|31]', 'bit': 28, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_textinfo(Acc1_225::Acc_textinfoType acc_textinfo);

  // config detail: {'name': 'ACC_ACCFailInfo', 'enum': {0: 'ACC_ACCFAILINFO_NO_ERROR', 1: 'ACC_ACCFAILINFO_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 22, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_accfailinfo(Acc1_225::Acc_accfailinfoType acc_accfailinfo);

  // config detail: {'name': 'ACC_ACCMode_HMI', 'enum': {0: 'ACC_ACCMODE_HMI_OFF_MODE', 1: 'ACC_ACCMODE_HMI_PASSIVE_MODE', 2: 'ACC_ACCMODE_HMI_STAND_BY_MODE', 3: 'ACC_ACCMODE_HMI_ACTIVE_CONTROL_MODE', 4: 'ACC_ACCMODE_HMI_BRAKE_ONLY_MODE', 5: 'ACC_ACCMODE_HMI_OVERRIDE', 6: 'ACC_ACCMODE_HMI_STANDSTILL', 7: 'ACC_ACCMODE_HMI_FAILURE_MODE'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 21, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_accmode_hmi(Acc1_225::Acc_accmode_hmiType acc_accmode_hmi);

  // config detail: {'name': 'ACC_TauGapSet', 'enum': {0: 'ACC_TAUGAPSET_TAUGAP_0', 1: 'ACC_TAUGAPSET_TAUGAP_1', 2: 'ACC_TAUGAPSET_TAUGAP_2', 3: 'ACC_TAUGAPSET_TAUGAP_3', 4: 'ACC_TAUGAPSET_TAUGAP_4', 5: 'ACC_TAUGAPSET_TAUGAP_5', 6: 'ACC_TAUGAPSET_TAUGAP_6', 7: 'ACC_TAUGAPSET_TAUGAP_7'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 13, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_taugapset(Acc1_225::Acc_taugapsetType acc_taugapset);

  // config detail: {'name': 'ACC_TakeOverReq', 'enum': {0: 'ACC_TAKEOVERREQ_NO_TAKEOVER_REQUEST', 1: 'ACC_TAKEOVERREQ_VALID_TAKEOVER_REQUEST'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 15, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_takeoverreq(Acc1_225::Acc_takeoverreqType acc_takeoverreq);

  // config detail: {'name': 'ACC_ObjValid', 'enum': {0: 'ACC_OBJVALID_NO_OBJECT', 1: 'ACC_OBJVALID_TARGET_OBJECT_DETECTED'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 14, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_objvalid(Acc1_225::Acc_objvalidType acc_objvalid);

  // config detail: {'name': 'ACC_PCWState', 'enum': {0: 'ACC_PCWSTATE_NO_ERROR', 1: 'ACC_PCWSTATE_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 18, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_pcwstate(Acc1_225::Acc_pcwstateType acc_pcwstate);

  // config detail: {'name': 'ACC_AEB_ONOFF', 'enum': {0: 'ACC_AEB_ONOFF_OFF', 1: 'ACC_AEB_ONOFF_ON'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 17, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_aeb_onoff(Acc1_225::Acc_aeb_onoffType acc_aeb_onoff);

  // config detail: {'name': 'ACC_AEBState', 'enum': {0: 'ACC_AEBSTATE_NO_ERROR', 1: 'ACC_AEBSTATE_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 16, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_aebstate(Acc1_225::Acc_aebstateType acc_aebstate);

  // config detail: {'name': 'ACC_dxTarObj', 'enum': {0: 'ACC_DXTAROBJ_DISTANCE_0', 1: 'ACC_DXTAROBJ_DISTANCE_1', 2: 'ACC_DXTAROBJ_DISTANCE_2', 3: 'ACC_DXTAROBJ_DISTANCE_3', 4: 'ACC_DXTAROBJ_DISTANCE_4', 5: 'ACC_DXTAROBJ_DISTANCE_5', 6: 'ACC_DXTAROBJ_DISTANCE_6', 7: 'ACC_DXTAROBJ_DISTANCE_7'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 10, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc1225* set_acc_dxtarobj(Acc1_225::Acc_dxtarobjType acc_dxtarobj);

  // config detail: {'name': 'ACC_vSetDis', 'offset': 0.0, 'precision': 1.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|254]', 'bit': 7, 'type': 'int', 'order': 'motorola', 'physical_unit': 'km/h'}
  Acc1225* set_acc_vsetdis(int32_t acc_vsetdis);

 private:

  // config detail: {'name': 'ACC_MessageCounterACC1', 'offset': 0.0, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'physical_range': '[0|15]', 'bit': 51, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_messagecounteracc1(uint8_t* data, int32_t acc_messagecounteracc1);

  // config detail: {'name': 'ACC_CheckSumACC1', 'offset': 0.0, 'precision': 1.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|255]', 'bit': 63, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_checksumacc1(uint8_t* data, int32_t acc_checksumacc1);

  // config detail: {'name': 'ACC_Target_Type', 'enum': {0: 'ACC_TARGET_TYPE_CAR', 1: 'ACC_TARGET_TYPE_PEDESTRIAN', 2: 'ACC_TARGET_TYPE_TARGET_TYPE_UNKNOWN'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 53, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_target_type(uint8_t* data, Acc1_225::Acc_target_typeType acc_target_type);

  // config detail: {'name': 'ACC_PCWONOFF', 'enum': {0: 'ACC_PCWONOFF_OFF', 1: 'ACC_PCWONOFF_PCW_LOW_SENSITIVE', 2: 'ACC_PCWONOFF_PCW_STANDARD', 3: 'ACC_PCWONOFF_PCW_HIGH_SENSITIVE'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 55, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_pcwonoff(uint8_t* data, Acc1_225::Acc_pcwonoffType acc_pcwonoff);

  // config detail: {'name': 'ACC_AEB_axTarforTCU', 'offset': -16.0, 'precision': 0.0004882, 'len': 16, 'is_signed_var': False, 'physical_range': '[-16|16]', 'bit': 39, 'type': 'double', 'order': 'motorola', 'physical_unit': 'm/s2'}
  void set_p_acc_aeb_axtarfortcu(uint8_t* data, double acc_aeb_axtarfortcu);

  // config detail: {'name': 'ACC_PCW_preWarning', 'enum': {0: 'ACC_PCW_PREWARNING_NO_WARNING', 1: 'ACC_PCW_PREWARNING_WARNING'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 31, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_pcw_prewarning(uint8_t* data, Acc1_225::Acc_pcw_prewarningType acc_pcw_prewarning);

  // config detail: {'name': 'ACC_PCW_latentWarning', 'enum': {0: 'ACC_PCW_LATENTWARNING_NO_WARNING', 1: 'ACC_PCW_LATENTWARNING_WARNING'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 30, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_pcw_latentwarning(uint8_t* data, Acc1_225::Acc_pcw_latentwarningType acc_pcw_latentwarning);

  // config detail: {'name': 'ACC_AEB_Request', 'enum': {0: 'ACC_AEB_REQUEST_NOT_REQUEST', 1: 'ACC_AEB_REQUEST_REQUEST'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 29, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_aeb_request(uint8_t* data, Acc1_225::Acc_aeb_requestType acc_aeb_request);

  // config detail: {'name': 'ACC_Textinfo', 'enum': {0: 'ACC_TEXTINFO_NO_DISPLAY', 1: 'ACC_TEXTINFO_UNABLE_TO_ACTIVE_ACC', 2: 'ACC_TEXTINFO_ACC_ACTIVE_CONTROL_IS_CANCELLED', 3: 'ACC_TEXTINFO_ACTIVE', 4: 'ACC_TEXTINFO_ACC_PEPS_TEMPORARY_UNAVAILABLE', 5: 'ACC_TEXTINFO_MRR_BLINDNESS', 6: 'ACC_TEXTINFO_ACC_AND_PEBS_ERROR', 7: 'ACC_TEXTINFO_ACC_SWITCHED_ON', 8: 'ACC_TEXTINFO_ACC_SWITCHED_OFF', 9: 'ACC_TEXTINFO_EPB_ACTIVATE', 10: 'ACC_TEXTINFO_NO_FORWARD_GEAR', 11: 'ACC_TEXTINFO_SEATBELT_UNBUCKLED', 12: 'ACC_TEXTINFO_EMS_DON_T_RESPOND_RESERVED', 13: 'ACC_TEXTINFO_ACC_DEACTIVATE', 14: 'ACC_TEXTINFO_SYSTEM_ENTER_STAND_WAIT', 15: 'ACC_TEXTINFO_ACC_UNINTENDED_EXIT_WARNING', 16: 'ACC_TEXTINFO_ESP_OFF_RESERVED', 17: 'ACC_TEXTINFO_SPEED_OVER_150KPH_RESERVED', 18: 'ACC_TEXTINFO_BONNET_OPEN_RESERVED', 19: 'ACC_TEXTINFO_PEBS_ERROR_RESERVED', 20: 'ACC_TEXTINFO_ACC_ERROR_RESERVED', 21: 'ACC_TEXTINFO_OVERRIDE_RESERVED'}, 'precision': 1.0, 'len': 5, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|31]', 'bit': 28, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_textinfo(uint8_t* data, Acc1_225::Acc_textinfoType acc_textinfo);

  // config detail: {'name': 'ACC_ACCFailInfo', 'enum': {0: 'ACC_ACCFAILINFO_NO_ERROR', 1: 'ACC_ACCFAILINFO_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 22, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_accfailinfo(uint8_t* data, Acc1_225::Acc_accfailinfoType acc_accfailinfo);

  // config detail: {'name': 'ACC_ACCMode_HMI', 'enum': {0: 'ACC_ACCMODE_HMI_OFF_MODE', 1: 'ACC_ACCMODE_HMI_PASSIVE_MODE', 2: 'ACC_ACCMODE_HMI_STAND_BY_MODE', 3: 'ACC_ACCMODE_HMI_ACTIVE_CONTROL_MODE', 4: 'ACC_ACCMODE_HMI_BRAKE_ONLY_MODE', 5: 'ACC_ACCMODE_HMI_OVERRIDE', 6: 'ACC_ACCMODE_HMI_STANDSTILL', 7: 'ACC_ACCMODE_HMI_FAILURE_MODE'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 21, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_accmode_hmi(uint8_t* data, Acc1_225::Acc_accmode_hmiType acc_accmode_hmi);

  // config detail: {'name': 'ACC_TauGapSet', 'enum': {0: 'ACC_TAUGAPSET_TAUGAP_0', 1: 'ACC_TAUGAPSET_TAUGAP_1', 2: 'ACC_TAUGAPSET_TAUGAP_2', 3: 'ACC_TAUGAPSET_TAUGAP_3', 4: 'ACC_TAUGAPSET_TAUGAP_4', 5: 'ACC_TAUGAPSET_TAUGAP_5', 6: 'ACC_TAUGAPSET_TAUGAP_6', 7: 'ACC_TAUGAPSET_TAUGAP_7'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 13, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_taugapset(uint8_t* data, Acc1_225::Acc_taugapsetType acc_taugapset);

  // config detail: {'name': 'ACC_TakeOverReq', 'enum': {0: 'ACC_TAKEOVERREQ_NO_TAKEOVER_REQUEST', 1: 'ACC_TAKEOVERREQ_VALID_TAKEOVER_REQUEST'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 15, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_takeoverreq(uint8_t* data, Acc1_225::Acc_takeoverreqType acc_takeoverreq);

  // config detail: {'name': 'ACC_ObjValid', 'enum': {0: 'ACC_OBJVALID_NO_OBJECT', 1: 'ACC_OBJVALID_TARGET_OBJECT_DETECTED'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 14, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_objvalid(uint8_t* data, Acc1_225::Acc_objvalidType acc_objvalid);

  // config detail: {'name': 'ACC_PCWState', 'enum': {0: 'ACC_PCWSTATE_NO_ERROR', 1: 'ACC_PCWSTATE_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 18, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_pcwstate(uint8_t* data, Acc1_225::Acc_pcwstateType acc_pcwstate);

  // config detail: {'name': 'ACC_AEB_ONOFF', 'enum': {0: 'ACC_AEB_ONOFF_OFF', 1: 'ACC_AEB_ONOFF_ON'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 17, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_aeb_onoff(uint8_t* data, Acc1_225::Acc_aeb_onoffType acc_aeb_onoff);

  // config detail: {'name': 'ACC_AEBState', 'enum': {0: 'ACC_AEBSTATE_NO_ERROR', 1: 'ACC_AEBSTATE_ERROR'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 16, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_aebstate(uint8_t* data, Acc1_225::Acc_aebstateType acc_aebstate);

  // config detail: {'name': 'ACC_dxTarObj', 'enum': {0: 'ACC_DXTAROBJ_DISTANCE_0', 1: 'ACC_DXTAROBJ_DISTANCE_1', 2: 'ACC_DXTAROBJ_DISTANCE_2', 3: 'ACC_DXTAROBJ_DISTANCE_3', 4: 'ACC_DXTAROBJ_DISTANCE_4', 5: 'ACC_DXTAROBJ_DISTANCE_5', 6: 'ACC_DXTAROBJ_DISTANCE_6', 7: 'ACC_DXTAROBJ_DISTANCE_7'}, 'precision': 1.0, 'len': 3, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|7]', 'bit': 10, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_acc_dxtarobj(uint8_t* data, Acc1_225::Acc_dxtarobjType acc_dxtarobj);

  // config detail: {'name': 'ACC_vSetDis', 'offset': 0.0, 'precision': 1.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|254]', 'bit': 7, 'type': 'int', 'order': 'motorola', 'physical_unit': 'km/h'}
  void set_p_acc_vsetdis(uint8_t* data, int32_t acc_vsetdis);

 private:
  int32_t acc_messagecounteracc1_;
  int32_t acc_checksumacc1_;
  Acc1_225::Acc_target_typeType acc_target_type_;
  Acc1_225::Acc_pcwonoffType acc_pcwonoff_;
  double acc_aeb_axtarfortcu_;
  Acc1_225::Acc_pcw_prewarningType acc_pcw_prewarning_;
  Acc1_225::Acc_pcw_latentwarningType acc_pcw_latentwarning_;
  Acc1_225::Acc_aeb_requestType acc_aeb_request_;
  Acc1_225::Acc_textinfoType acc_textinfo_;
  Acc1_225::Acc_accfailinfoType acc_accfailinfo_;
  Acc1_225::Acc_accmode_hmiType acc_accmode_hmi_;
  Acc1_225::Acc_taugapsetType acc_taugapset_;
  Acc1_225::Acc_takeoverreqType acc_takeoverreq_;
  Acc1_225::Acc_objvalidType acc_objvalid_;
  Acc1_225::Acc_pcwstateType acc_pcwstate_;
  Acc1_225::Acc_aeb_onoffType acc_aeb_onoff_;
  Acc1_225::Acc_aebstateType acc_aebstate_;
  Acc1_225::Acc_dxtarobjType acc_dxtarobj_;
  int32_t acc_vsetdis_;
};

}  // namespace a45
}  // namespace canbus
}  // namespace apollo


