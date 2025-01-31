#!/bin/sh
# Copyright (c) 2025 Silicon Laboratories Inc.
# SPDX-License-Identifier: Apache-2.0

# Add missing SecureFault interrupt number to device headers
sed -i '' "s/\(UsageFault_IRQn.*\)/\1\n#if defined(CONFIG_ARM_SECURE_FIRMWARE)\n  SecureFault_IRQn       = -9,\n#endif/" simplicity_sdk/platform/Device/SiliconLabs/*/Include/*.h

# Rename CONCAT macros conflicting with Zephyr macros
sed -i '' "s/ _CONCAT_/ _SL_CONCAT_/" simplicity_sdk/platform/common/inc/sl_common.h
sed -i '' "s/   first/first/" simplicity_sdk/platform/common/inc/sl_common.h

# Replace legacy Kconfig option name
sed -i '' "s/CONFIG_SOC_FAMILY_EXX32/__ZEPHYR__/" simplicity_sdk/platform/emlib/inc/em_ramfunc.h

# Rename MAX macro conflicting with Zephyr macro
sed -i '' "s/MAX(/_SL_MAX(/" simplicity_sdk/platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.c
