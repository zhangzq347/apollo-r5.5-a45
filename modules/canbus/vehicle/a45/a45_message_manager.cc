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

#include "modules/canbus/vehicle/a45/a45_message_manager.h"

#include "modules/canbus/vehicle/a45/protocol/acc1_225.h"
#include "modules/canbus/vehicle/a45/protocol/acc2_250.h"
#include "modules/canbus/vehicle/a45/protocol/acc3_251.h"
#include "modules/canbus/vehicle/a45/protocol/eps_control_300.h"

#include "modules/canbus/vehicle/a45/protocol/abs1_esp1_311.h"
#include "modules/canbus/vehicle/a45/protocol/abs2_esp2_2ea.h"
#include "modules/canbus/vehicle/a45/protocol/bcm_f_392.h"
#include "modules/canbus/vehicle/a45/protocol/ems11_28a.h"
#include "modules/canbus/vehicle/a45/protocol/ems13_279.h"
#include "modules/canbus/vehicle/a45/protocol/ems3_278.h"
#include "modules/canbus/vehicle/a45/protocol/epb_320.h"
#include "modules/canbus/vehicle/a45/protocol/eps_status1_230.h"
#include "modules/canbus/vehicle/a45/protocol/eps_status2_231.h"
#include "modules/canbus/vehicle/a45/protocol/esp4_213.h"
#include "modules/canbus/vehicle/a45/protocol/tcu1_1a0.h"

namespace apollo {
namespace canbus {
namespace a45 {

A45MessageManager::A45MessageManager() {
  // Control Messages
  AddSendProtocolData<Acc1225, true>();
  AddSendProtocolData<Acc2250, true>();
  AddSendProtocolData<Acc3251, true>();
  AddSendProtocolData<Epscontrol300, true>();

  // Report Messages
  AddRecvProtocolData<Abs1esp1311, true>();
  AddRecvProtocolData<Abs2esp22ea, true>();
  AddRecvProtocolData<Bcmf392, true>();
  AddRecvProtocolData<Ems1128a, true>();
  AddRecvProtocolData<Ems13279, true>();
  AddRecvProtocolData<Ems3278, true>();
  AddRecvProtocolData<Epb320, true>();
  AddRecvProtocolData<Epsstatus1230, true>();
  AddRecvProtocolData<Epsstatus2231, true>();
  AddRecvProtocolData<Esp4213, true>();
  AddRecvProtocolData<Tcu11a0, true>();
}

A45MessageManager::~A45MessageManager() {}

}  // namespace a45
}  // namespace canbus
}  // namespace apollo
