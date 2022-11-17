# Copyright (c) 2022 Antmicro <www.antmicro.com>
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_BT_SILABS_HCI)
  zephyr_include_directories(include)
  zephyr_sources(src/sl_bt_ll_zephyr.c)
endif()
