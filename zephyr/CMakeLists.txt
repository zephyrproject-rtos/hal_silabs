# Copyright (c) 2022 Antmicro <www.antmicro.com>
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_SOC_FAMILY_SILABS_S2)
  zephyr_sources(src/sl_memory_manager_shim_zephyr.c)
endif()
