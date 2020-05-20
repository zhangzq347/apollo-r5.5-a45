load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "canbus_a45_protocol",
    deps = [
        ":abs1_esp1_311",
        ":abs2_esp2_2ea",
        ":acc1_225",
        ":acc2_250",
        ":acc3_251",
        ":bcm_f_392",
        ":ems3_278",
        ":ems11_28a",
        ":ems13_279",
        ":epb_320",
        ":eps_control_300",
        ":eps_status1_230",
        ":eps_status2_231",
        ":esp4_213",
        ":tcu1_1a0",
    ],
)

cc_library(
    name = "abs1_esp1_311",
    srcs = glob(["abs1_esp1_311.cc",]),
    hdrs = glob(["abs1_esp1_311.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "abs2_esp2_2ea",
    srcs = glob(["abs2_esp2_2ea.cc",]),
    hdrs = glob(["abs2_esp2_2ea.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "acc1_225",
    srcs = glob(["acc1_225.cc",]),
    hdrs = glob(["acc1_225.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "acc2_250",
    srcs = glob(["acc2_250.cc",]),
    hdrs = glob(["acc2_250.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "acc3_251",
    srcs = glob(["acc3_251.cc",]),
    hdrs = glob(["acc3_251.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "bcm_f_392",
    srcs = glob(["bcm_f_392.cc",]),
    hdrs = glob(["bcm_f_392.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "ems3_278",
    srcs = glob(["ems3_278.cc",]),
    hdrs = glob(["ems3_278.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "ems11_28a",
    srcs = glob(["ems11_28a.cc",]),
    hdrs = glob(["ems11_28a.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "ems13_279",
    srcs = glob(["ems13_279.cc",]),
    hdrs = glob(["ems13_279.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "epb_320",
    srcs = glob(["epb_320.cc",]),
    hdrs = glob(["epb_320.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "eps_control_300",
    srcs = glob(["eps_control_300.cc",]),
    hdrs = glob(["eps_control_300.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "eps_status1_230",
    srcs = glob(["eps_status1_230.cc",]),
    hdrs = glob(["eps_status1_230.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "eps_status2_231",
    srcs = glob(["eps_status2_231.cc",]),
    hdrs = glob(["eps_status2_231.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "esp4_213",
    srcs = glob(["esp4_213.cc",]),
    hdrs = glob(["esp4_213.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)

cc_library(
    name = "tcu1_1a0",
    srcs = glob(["tcu1_1a0.cc",]),
    hdrs = glob(["tcu1_1a0.h",]),
    copts = ["-DMODULE_NAME=\\\"canbus\\\""],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:canbus_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
    ],
)


cpplint()
