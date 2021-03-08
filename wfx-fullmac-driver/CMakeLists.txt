# Makefile - SiLabs wfx fullMAC driver
#
# Copyright (c) 2023, grandcentrix GmbH
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_HAS_SILABS_WFX_FMAC)

zephyr_library()

if(CONFIG_WIFI_WFX200_VERBOSE_DEBUG)
    zephyr_compile_definitions(
      SL_WFX_DEBUG_MASK=0xff
      )
endif()

zephyr_include_directories(
  ./wfx_fmac_driver
  ./wfx_fmac_driver/firmware
  ./wfx_fmac_driver/bus
  $ENV{ZEPHYR_BASE}/include/drivers
  )

zephyr_library_sources(
  wfx_fmac_driver/secure_link/sl_wfx_secure_link.c
  wfx_fmac_driver/bus/sl_wfx_bus.c
  wfx_fmac_driver/sl_wfx.c
  wfx_fmac_driver/bus/sl_wfx_bus_spi.c
  )

endif()
