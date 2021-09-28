# Makefile - Gecko SE Mananger
#
# Copyright (c) 2021, Safran Passenger Innovations Germany GmbH
#
# SPDX-License-Identifier: Apache-2.0
#

zephyr_include_directories(
  src
  inc
  )

zephyr_sources(                                src/sl_se_manager.c)
zephyr_sources(                                src/sl_se_manager_util.c)
zephyr_sources_ifdef(CONFIG_ENTROPY_GECKO_SE   src/sl_se_manager_entropy.c)
