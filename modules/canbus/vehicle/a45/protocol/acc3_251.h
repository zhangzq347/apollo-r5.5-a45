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

class Acc3251 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Acc3251();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'name': 'FRS_AEB_CheckSum', 'offset': 0.0, 'precision': 1.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|255]', 'bit': 63, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  Acc3251* set_frs_aeb_checksum(Acc3_251::Frs_aeb_vehicleholdType frs_aeb_vehiclehold, int frs_aeb_alivecounter,
    Acc3_251::Frs_aeb_abprequestType frs_aeb_abprequest, Acc3_251::Frs_aeb_awblevelType frs_aeb_awblevel,
    Acc3_251::Frs_aeb_awbrequestType frs_aeb_awbrequest, Acc3_251::Frs_aeb_abarequestType frs_aeb_abarequest,
    Acc3_251::Frs_aeb_abalevelType frs_aeb_abalevel, double frs_aeb_axtar);

  // config detail: {'name': 'FRS_AEB_VehicleHold', 'enum': {0: 'FRS_AEB_VEHICLEHOLD_NOT_HOLD', 1: 'FRS_AEB_VEHICLEHOLD_HOLD'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 29, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc3251* set_frs_aeb_vehiclehold(Acc3_251::Frs_aeb_vehicleholdType frs_aeb_vehiclehold);

  // config detail: {'name': 'FRS_AEB_AliveCounter', 'offset': 0.0, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'physical_range': '[0|15]', 'bit': 39, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  Acc3251* set_frs_aeb_alivecounter();

  // config detail: {'name': 'FRS_AEB_ABPRequest', 'enum': {0: 'FRS_AEB_ABPREQUEST_NO_DEMAND', 1: 'FRS_AEB_ABPREQUEST_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 28, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc3251* set_frs_aeb_abprequest(Acc3_251::Frs_aeb_abprequestType frs_aeb_abprequest);

  // config detail: {'name': 'FRS_AEB_AWBLevel', 'enum': {0: 'FRS_AEB_AWBLEVEL_NO_LEVEL', 1: 'FRS_AEB_AWBLEVEL_LEVEL_1', 2: 'FRS_AEB_AWBLEVEL_LEVEL_2', 3: 'FRS_AEB_AWBLEVEL_LEVEL_3', 4: 'FRS_AEB_AWBLEVEL_LEVEL_4'}, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|15]', 'bit': 27, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc3251* set_frs_aeb_awblevel(Acc3_251::Frs_aeb_awblevelType frs_aeb_awblevel);

  // config detail: {'name': 'FRS_AEB_AWBRequest', 'enum': {0: 'FRS_AEB_AWBREQUEST_NO_DEMAND', 1: 'FRS_AEB_AWBREQUEST_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 23, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc3251* set_frs_aeb_awbrequest(Acc3_251::Frs_aeb_awbrequestType frs_aeb_awbrequest);

  // config detail: {'name': 'FRS_AEB_ABARequest', 'enum': {0: 'FRS_AEB_ABAREQUEST_NO_DEMAND', 1: 'FRS_AEB_ABAREQUEST_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 22, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc3251* set_frs_aeb_abarequest(Acc3_251::Frs_aeb_abarequestType frs_aeb_abarequest);

  // config detail: {'name': 'FRS_AEB_ABALevel', 'enum': {0: 'FRS_AEB_ABALEVEL_LEVEL_0', 1: 'FRS_AEB_ABALEVEL_LEVEL_1', 2: 'FRS_AEB_ABALEVEL_LEVEL_2', 3: 'FRS_AEB_ABALEVEL_LEVEL_3'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 21, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  Acc3251* set_frs_aeb_abalevel(Acc3_251::Frs_aeb_abalevelType frs_aeb_abalevel);

  // config detail: {'name': 'FRS_AEB_axTar', 'offset': -16.0, 'precision': 0.0004882, 'len': 16, 'is_signed_var': False, 'physical_range': '[-16|16]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
  Acc3251* set_frs_aeb_axtar(double frs_aeb_axtar);

 private:

  // config detail: {'name': 'FRS_AEB_CheckSum', 'offset': 0.0, 'precision': 1.0, 'len': 8, 'is_signed_var': False, 'physical_range': '[0|255]', 'bit': 63, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_aeb_checksum(uint8_t* data, int frs_aeb_checksum);

  // config detail: {'name': 'FRS_AEB_VehicleHold', 'enum': {0: 'FRS_AEB_VEHICLEHOLD_NOT_HOLD', 1: 'FRS_AEB_VEHICLEHOLD_HOLD'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 29, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_aeb_vehiclehold(uint8_t* data, Acc3_251::Frs_aeb_vehicleholdType frs_aeb_vehiclehold);

  // config detail: {'name': 'FRS_AEB_AliveCounter', 'offset': 0.0, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'physical_range': '[0|15]', 'bit': 39, 'type': 'int', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_aeb_alivecounter(uint8_t* data, int frs_aeb_alivecounter);

  // config detail: {'name': 'FRS_AEB_ABPRequest', 'enum': {0: 'FRS_AEB_ABPREQUEST_NO_DEMAND', 1: 'FRS_AEB_ABPREQUEST_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 28, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_aeb_abprequest(uint8_t* data, Acc3_251::Frs_aeb_abprequestType frs_aeb_abprequest);

  // config detail: {'name': 'FRS_AEB_AWBLevel', 'enum': {0: 'FRS_AEB_AWBLEVEL_NO_LEVEL', 1: 'FRS_AEB_AWBLEVEL_LEVEL_1', 2: 'FRS_AEB_AWBLEVEL_LEVEL_2', 3: 'FRS_AEB_AWBLEVEL_LEVEL_3', 4: 'FRS_AEB_AWBLEVEL_LEVEL_4'}, 'precision': 1.0, 'len': 4, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|15]', 'bit': 27, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_aeb_awblevel(uint8_t* data, Acc3_251::Frs_aeb_awblevelType frs_aeb_awblevel);

  // config detail: {'name': 'FRS_AEB_AWBRequest', 'enum': {0: 'FRS_AEB_AWBREQUEST_NO_DEMAND', 1: 'FRS_AEB_AWBREQUEST_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 23, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_aeb_awbrequest(uint8_t* data, Acc3_251::Frs_aeb_awbrequestType frs_aeb_awbrequest);

  // config detail: {'name': 'FRS_AEB_ABARequest', 'enum': {0: 'FRS_AEB_ABAREQUEST_NO_DEMAND', 1: 'FRS_AEB_ABAREQUEST_DEMAND'}, 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|1]', 'bit': 22, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_aeb_abarequest(uint8_t* data, Acc3_251::Frs_aeb_abarequestType frs_aeb_abarequest);

  // config detail: {'name': 'FRS_AEB_ABALevel', 'enum': {0: 'FRS_AEB_ABALEVEL_LEVEL_0', 1: 'FRS_AEB_ABALEVEL_LEVEL_1', 2: 'FRS_AEB_ABALEVEL_LEVEL_2', 3: 'FRS_AEB_ABALEVEL_LEVEL_3'}, 'precision': 1.0, 'len': 2, 'is_signed_var': False, 'offset': 0.0, 'physical_range': '[0|3]', 'bit': 21, 'type': 'enum', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_aeb_abalevel(uint8_t* data, Acc3_251::Frs_aeb_abalevelType frs_aeb_abalevel);

  // config detail: {'name': 'FRS_AEB_axTar', 'offset': -16.0, 'precision': 0.0004882, 'len': 16, 'is_signed_var': False, 'physical_range': '[-16|16]', 'bit': 7, 'type': 'double', 'order': 'motorola', 'physical_unit': ''}
  void set_p_frs_aeb_axtar(uint8_t* data, double frs_aeb_axtar);

 private:
  int frs_aeb_checksum_;
  Acc3_251::Frs_aeb_vehicleholdType frs_aeb_vehiclehold_;
  int frs_aeb_alivecounter_;
  Acc3_251::Frs_aeb_abprequestType frs_aeb_abprequest_;
  Acc3_251::Frs_aeb_awblevelType frs_aeb_awblevel_;
  Acc3_251::Frs_aeb_awbrequestType frs_aeb_awbrequest_;
  Acc3_251::Frs_aeb_abarequestType frs_aeb_abarequest_;
  Acc3_251::Frs_aeb_abalevelType frs_aeb_abalevel_;
  double frs_aeb_axtar_;
};

}  // namespace a45
}  // namespace canbus
}  // namespace apollo


