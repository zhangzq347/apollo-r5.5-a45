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
 * 此模块用于管理车辆接收和发送的消息，需在此代码中添加消息定义文件及消息名称（20200508-张智清）
 *****************************************************************************/


#include "modules/canbus/vehicle/ch/ch_message_manager.h"
#include "modules/canbus/vehicle/ch/protocol/brake_command_111.h"
#include "modules/canbus/vehicle/ch/protocol/brake_status__511.h"
#include "modules/canbus/vehicle/ch/protocol/control_command_115.h"
#include "modules/canbus/vehicle/ch/protocol/ecu_status_2_516.h"
#include "modules/canbus/vehicle/ch/protocol/ecu_status_3_517.h"
#include "modules/canbus/vehicle/ch/protocol/gear_command_114.h"
#include "modules/canbus/vehicle/ch/protocol/steer_command_112.h"
#include "modules/canbus/vehicle/ch/protocol/throttle_command_110.h"
#include "modules/canbus/vehicle/ch/protocol/throttle_status__510.h"
#include "modules/canbus/vehicle/ch/protocol/turnsignal_command_113.h"
#include "modules/canbus/vehicle/ch/protocol/turnsignal_status__513.h"

#include "modules/canbus/vehicle/ch/protocol/a45_tcu_1_1a0.h"  //新增A45的TCU1报文定义（20200508-张智清）
#include "modules/canbus/vehicle/ch/protocol/a45_esp_4_213.h"  //新增A45的ESP4报文定义（20200508-张智清）
#include "modules/canbus/vehicle/ch/protocol/a45_eps_status_1_230.h"  //新增A45的EPS_Status1报文定义（20200508-张智清）
#include "modules/canbus/vehicle/ch/protocol/a45_abs_1_311.h"  //新增A45的ABS1报文定义（20200508-张智清）
#include "modules/canbus/vehicle/ch/protocol/a45_eps_control_300.h"  //新增A45的EPS_Control报文定义（20200508-张智清）
#include "modules/canbus/vehicle/ch/protocol/a45_acc_1_225.h"  //新增A45的ACC1报文定义（20200508-张智清）
#include "modules/canbus/vehicle/ch/protocol/a45_acc_2_250.h"  //新增A45的ACC2报文定义（20200508-张智清）
#include "modules/canbus/vehicle/ch/protocol/a45_acc_3_251.h"  //新增A45的ACC3报文定义（20200508-张智清）

namespace apollo {
namespace canbus {
namespace ch {

ChMessageManager::ChMessageManager() {
  // Control Messages
  AddSendProtocolData<Brakecommand111, true>();
  AddSendProtocolData<Controlcommand115, true>();
  AddSendProtocolData<Gearcommand114, true>();
  AddSendProtocolData<Steercommand112, true>();
  AddSendProtocolData<Throttlecommand110, true>();
  AddSendProtocolData<Turnsignalcommand113, true>();

  AddSendProtocolData<A45EPScontrol300, true>();  //新增A45的EPS_Control报文（20200508-张智清）
  AddSendProtocolData<A45ACC1225, true>();  //新增A45的ACC1报文（20200508-张智清）
  AddSendProtocolData<A45ACC2250, true>();  //新增A45的ACC2报文（20200508-张智清）
  AddSendProtocolData<A45ACC3251, true>();  //新增A45的ACC3报文（20200508-张智清）

  // Report Messages
  AddRecvProtocolData<Brakestatus511, true>();
  AddRecvProtocolData<Ecustatus2516, true>();
  AddRecvProtocolData<Ecustatus3517, true>();
  AddRecvProtocolData<Throttlestatus510, true>();
  AddRecvProtocolData<Turnsignalstatus513, true>();

  AddRecvProtocolData<A45TCU11A0, true>();  //新增A45的TCU1报文（20200508-张智清）
  AddRecvProtocolData<A45ESP4213, true>();  //新增A45的ESP4报文（20200508-张智清）
  AddRecvProtocolData<A45EPSstatus1230, true>();  //新增A45的EPS_Status1报文（20200508-张智清）
  AddRecvProtocolData<A45ABS1311, true>();  //新增A45的ABS1报文（20200508-张智清）
}

ChMessageManager::~ChMessageManager() {}

}  // namespace ch
}  // namespace canbus
}  // namespace apollo
