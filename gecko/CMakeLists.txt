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

# Remove any prefix from the board, e.g. efr32_radio_
string(FIND ${CONFIG_BOARD} "brd" SILABS_GECKO_BRD_INDEX)

set(SILABS_GECKO_PART_NUMBER ${CONFIG_SOC_PART_NUMBER})

if (${CONFIG_BOARD} STREQUAL "efr32xg24_dk2601b")
  set(SILABS_GECKO_BOARD "brd2601b")
  set(PRODUCT_NO "sdid215")
endif()

if (${CONFIG_BOARD} STREQUAL "efr32bg_sltb010a")
  set(SILABS_GECKO_BOARD "brd4184b")
  set(PRODUCT_NO "sdid205")
endif()

zephyr_include_directories(
  Device/SiliconLabs/${SILABS_GECKO_DEVICE}/Include
  board/config/${SILABS_GECKO_BOARD}
  board/inc
  common/inc
  emlib/inc
  platform/radio/rail_lib/chip/efr32/efr32xg2x
  platform/radio/rail_lib/common
  platform/radio/rail_lib/plugin/pa-conversions
  platform/radio/rail_lib/plugin/pa-conversions/efr32xg22/config
  protocol/bluetooth//bgstack/ll/inc
  service/device_init/config/s2
  service/device_init/config/s2/${PRODUCT_NO}
  service/device_init/inc
  service/hfxo_manager/config
  service/hfxo_manager/inc
  service/hfxo_manager/src
  service/power_manager/config
  service/power_manager/inc
  service/power_manager/src
  service/sleeptimer/config
  service/sleeptimer/inc
  service/sleeptimer/src
  util/third_party/crypto/sl_component/sl_protocol_crypto/src
  )

foreach(root ${BOARD_ROOT})
  message("ROOT: " ${root})
  if(IS_DIRECTORY "${root}/boards/arm/${CONFIG_BOARD}")
    zephyr_include_directories(${root}/boards/arm/${CONFIG_BOARD})
  endif()
endforeach()

# The gecko SDK uses the cpu name to include the matching device header.
# See Device/SiliconLabs/$(SILABS_GECKO_DEVICE)/Include/em_device.h for an example.
zephyr_compile_definitions(
  ${SILABS_GECKO_PART_NUMBER}
  )

add_subdirectory_ifdef(CONFIG_SOC_GECKO_SE se_manager)

zephyr_sources(                                    emlib/src/em_system.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_ADC          emlib/src/em_adc.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_CMU          emlib/src/em_cmu.c)

zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/device_init/src/sl_device_init_dcdc_s2.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/device_init/src/sl_device_init_dpll_s2.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/device_init/src/sl_device_init_emu_s2.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/device_init/src/sl_device_init_hfrco.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/device_init/src/sl_device_init_hfxo_s2.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/device_init/src/sl_device_init_nvic.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/power_manager/src/sl_power_manager.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/power_manager/src/sl_power_manager_hal_s2.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/hfxo_manager/src/sl_hfxo_manager.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/hfxo_manager/src/sl_hfxo_manager_hal_s2.c)

zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     common/src/sl_slist.c)
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
zephyr_sources_ifdef(CONFIG_COUNTER_GECKO_STIMER   service/sleeptimer/src/peripheral_sysrtc.c)
zephyr_sources_ifdef(CONFIG_COUNTER_GECKO_STIMER   service/sleeptimer/src/sl_sleeptimer_hal_rtcc.c)
zephyr_sources_ifdef(CONFIG_COUNTER_GECKO_STIMER   service/sleeptimer/src/sl_sleeptimer.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_SE           emlib/src/em_se.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_TIMER        emlib/src/em_timer.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_USART        emlib/src/em_usart.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_WDOG         emlib/src/em_wdog.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFM32WG     Device/SiliconLabs/EFM32WG/Source/system_efm32wg.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFR32BG13P  Device/SiliconLabs/EFR32BG13P/Source/system_efr32bg13p.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFR32BG22   Device/SiliconLabs/EFR32BG22/Source/system_efr32bg22.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFR32FG1P   Device/SiliconLabs/EFR32FG1P/Source/system_efr32fg1p.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFR32FG13P  Device/SiliconLabs/EFR32FG13P/Source/system_efr32fg13p.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFM32HG     Device/SiliconLabs/EFM32HG/Source/system_efm32hg.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFR32MG12P  Device/SiliconLabs/EFR32MG12P/Source/system_efr32mg12p.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFM32PG12B  Device/SiliconLabs/EFM32PG12B/Source/system_efm32pg12b.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFM32GG11B  Device/SiliconLabs/EFM32GG11B/Source/system_efm32gg11b.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFM32JG12B  Device/SiliconLabs/EFM32JG12B/Source/system_efm32jg12b.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFR32MG21   Device/SiliconLabs/EFR32MG21/Source/system_efr32mg21.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFM32PG1B   Device/SiliconLabs/EFM32PG1B/Source/system_efm32pg1b.c)
zephyr_sources_ifdef(CONFIG_SOC_SERIES_EFR32MG24   Device/SiliconLabs/EFR32MG24/Source/system_efr32mg24.c)

function(add_prebuilt_library lib_name prebuilt_path)
  add_library(${lib_name} STATIC IMPORTED GLOBAL)
  set_target_properties(${lib_name} PROPERTIES
	  IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../zephyr/blobs/${prebuilt_path}
  )
  zephyr_link_libraries(${lib_name})
endfunction()

if(CONFIG_BT_SILABS_HCI)
  # rail
  zephyr_sources(platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.c)

  # sl_protocol_crypto
  zephyr_sources(util/third_party/crypto/sl_component/sl_protocol_crypto/src/sli_protocol_crypto_crypto.c)
  zephyr_sources(util/third_party/crypto/sl_component/sl_protocol_crypto/src/sli_radioaes_management.c)
  zephyr_sources(util/third_party/crypto/sl_component/sl_protocol_crypto/src/sli_protocol_crypto_radioaes.c)

  # prebuilt libs
  add_prebuilt_library(liblinklayer gecko/protocol/bluetooth/bgstack/ll/lib/libbluetooth_controller_${CONFIG_SOC_SERIES}_gcc_release.a)
  add_prebuilt_library(libbgcommon  gecko/protocol/bluetooth/bgcommon/lib/libbgcommon_${CONFIG_SOC_SERIES}_gcc_release.a)
  add_prebuilt_library(librail      gecko/platform/radio/rail_lib//autogen/librail_release/librail_${CONFIG_SOC_SERIES}_gcc_release.a)

  # link mbedTLS
  if(CONFIG_MBEDTLS)
    zephyr_link_libraries(mbedTLS)
  endif()
endif()
