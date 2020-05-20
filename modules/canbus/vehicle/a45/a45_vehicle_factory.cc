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

#include "modules/canbus/vehicle/a45/a45_vehicle_factory.h"

#include "modules/canbus/vehicle/a45/a45_controller.h"
#include "modules/canbus/vehicle/a45/a45_message_manager.h"
#include "cyber/common/log.h"
#include "modules/common/util/util.h"

namespace apollo {
namespace canbus {

std::unique_ptr<VehicleController>
A45VehicleFactory::CreateVehicleController() {
  return std::unique_ptr<VehicleController>(new a45::A45Controller());
}

std::unique_ptr<MessageManager<::apollo::canbus::ChassisDetail>>
A45VehicleFactory::CreateMessageManager() {
  return std::unique_ptr<MessageManager<::apollo::canbus::ChassisDetail>>(
	new a45::A45MessageManager());
}

}  // namespace canbus
}  // namespace apollo
