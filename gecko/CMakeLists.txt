# Makefile - Gecko SDK
#
# Copyright (c) 2017, Christian Taedcke
# Copyright (c) 2021, Safran Passenger Innovations Germany GmbH
# Copyright (c) 2022, Antmicro <www.antmicro.com>
#
# SPDX-License-Identifier: Apache-2.0
#

# Translate the SoC name and part number into the gecko device and cpu name
# respectively.
string(TOUPPER ${CONFIG_SOC_SERIES} SILABS_GECKO_DEVICE)

# Get SoC series number, i.e. translate e.g. efr32bg22 -> 22
string(SUBSTRING ${CONFIG_SOC_SERIES} 7 2 GECKO_SERIES_NUMBER)

set(SILABS_GECKO_PART_NUMBER ${CONFIG_SOC_PART_NUMBER})

function(add_prebuilt_library lib_name prebuilt_path)
  add_library(${lib_name} STATIC IMPORTED GLOBAL)
  set_target_properties(${lib_name} PROPERTIES
	  IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../zephyr/blobs/${prebuilt_path}
  )
  zephyr_link_libraries(${lib_name})
endfunction()

if(${CONFIG_SOC_GECKO_HAS_RADIO})
  if(${CONFIG_SOC_FAMILY_SILABS_S1})
    zephyr_include_directories(
      platform/radio/rail_lib/plugin/pa-conversions/efr32xg1x/config
      platform/radio/rail_lib/chip/efr32/efr32xg1x
    )
  endif()

  zephyr_include_directories(
    platform/radio/rail_lib/common
    platform/radio/rail_lib/plugin/pa-conversions
    protocol/bluetooth/bgstack/ll/inc
    )

  if(CONFIG_SOC_GECKO_USE_RAIL)
    # rail
    zephyr_sources(platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.c)
    zephyr_sources(platform/radio/rail_lib/plugin/pa-conversions/pa_curves_efr32.c)

    # prebuilt libs
    add_prebuilt_library(librail      gecko/platform/radio/rail_lib/autogen/librail_release/librail_efr32xg${GECKO_SERIES_NUMBER}_gcc_release.a)

    if(CONFIG_SOC_GECKO_CUSTOM_RADIO_PHY)
      zephyr_include_directories(
        platform/radio/rail_lib/plugin/rail_util_init/config/proprietary
        platform/radio/rail_lib/plugin/rail_util_callbacks
        platform/radio/rail_lib/plugin/rail_util_callbacks/config
        platform/radio/rail_lib/plugin/rail_util_protocol
        platform/radio/rail_lib/plugin/rail_util_protocol/config/efr32xg${GECKO_SERIES_NUMBER}/
        platform/radio/rail_lib/protocol/ble
        platform/radio/rail_lib/protocol/ieee802154
        platform/radio/rail_lib/protocol/zwave
      )
      zephyr_sources(platform/radio/rail_lib/plugin/rail_util_protocol/sl_rail_util_protocol.c)
    endif()

  endif()
endif()

zephyr_include_directories(
  Device/SiliconLabs/${SILABS_GECKO_DEVICE}/Include
  common/inc
  emlib/inc
  ${BOARD_DIR}
  )

# The gecko SDK uses the cpu name to include the matching device header.
# See Device/SiliconLabs/$(SILABS_GECKO_DEVICE)/Include/em_device.h for an example.
zephyr_compile_definitions(
  ${SILABS_GECKO_PART_NUMBER}
  )

zephyr_sources(                                    emlib/src/em_system.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_ADC          emlib/src/em_adc.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_BURTC        emlib/src/em_burtc.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_CMU          emlib/src/em_cmu.c)

zephyr_sources_ifdef(CONFIG_SOC_GECKO_CORE         emlib/src/em_core.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_CRYOTIMER    emlib/src/em_cryotimer.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_EMU          emlib/src/em_emu.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_GPIO         emlib/src/em_gpio.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_I2C          emlib/src/em_i2c.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_LETIMER      emlib/src/em_letimer.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_LEUART       emlib/src/em_leuart.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_MSC          emlib/src/em_msc.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_PRS          emlib/src/em_prs.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_RMU          emlib/src/em_rmu.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_RTC          emlib/src/em_rtc.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_RTCC         emlib/src/em_rtcc.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_TIMER        emlib/src/em_timer.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_USART        emlib/src/em_usart.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_WDOG         emlib/src/em_wdog.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFM32WG     Device/SiliconLabs/EFM32WG/Source/system_efm32wg.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFR32BG13P  Device/SiliconLabs/EFR32BG13P/Source/system_efr32bg13p.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFR32FG1P   Device/SiliconLabs/EFR32FG1P/Source/system_efr32fg1p.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFR32FG13P  Device/SiliconLabs/EFR32FG13P/Source/system_efr32fg13p.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFM32HG     Device/SiliconLabs/EFM32HG/Source/system_efm32hg.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFR32MG12P  Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFM32PG12B  Device/SiliconLabs/EFM32PG12B/Source/system_efm32pg12b.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFM32GG11B  Device/SiliconLabs/EFM32GG11B/Source/system_efm32gg11b.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFM32GG12B  Device/SiliconLabs/EFM32GG12B/Source/system_efm32gg12b.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFM32JG12B  Device/SiliconLabs/EFM32JG12B/Source/system_efm32jg12b.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFM32PG1B   Device/SiliconLabs/EFM32PG1B/Source/system_efm32pg1b.c)
