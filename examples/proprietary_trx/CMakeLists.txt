# Copyright (c) 2023 Silicon Laboratories Inc.
# SPDX-License-Identifier: Zlib

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(propriatery_trx)

target_include_directories(app PRIVATE
    src/
    src/autogen/
    src/config/
    src/config/rail
    src/config/rail/${CONFIG_BOARD}
)

target_sources(app PRIVATE src/main.c)
target_sources(app PRIVATE src/app_gpio.c)
target_sources(app PRIVATE src/app_cli.c)
target_sources(app PRIVATE src/app_rail.c)
target_sources(app PRIVATE src/autogen/sl_rail_util_callbacks.c)
target_sources(app PRIVATE src/autogen/sl_rail_util_init.c)
target_sources(app PRIVATE src/config/rail/${CONFIG_BOARD}/rail_config.c)
