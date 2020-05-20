load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "a45_vehicle_factory",
    srcs = [
        "a45_vehicle_factory.cc",
    ],
    hdrs = [
        "a45_vehicle_factory.h",
    ],
    deps = [
        ":a45_controller",
        ":a45_message_manager",
        "//modules/canbus/vehicle:abstract_vehicle_factory",
    ],
)

cc_library(
    name = "a45_message_manager",
    srcs = [
        "a45_message_manager.cc",
    ],
    hdrs = [
        "a45_message_manager.h",
    ],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle/a45/protocol:canbus_a45_protocol",
    ],
)

cc_library(
    name = "a45_controller",
    srcs = [
        "a45_controller.cc",
    ],
    hdrs = [
        "a45_controller.h",
    ],
    deps = [
        ":a45_message_manager",
        "//modules/drivers/canbus/can_comm:can_sender",
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle:vehicle_controller_base",
        "//modules/canbus/vehicle/a45/protocol:canbus_a45_protocol",
    ],
)

cpplint()
