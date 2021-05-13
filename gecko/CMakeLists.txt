# Makefile - Gecko SDK
#
# Copyright (c) 2017, Christian Taedcke
# Copyright (c) 2021, Safran Passenger Innovations Germany GmbH
#
# SPDX-License-Identifier: Apache-2.0
#

# Translate the SoC name and part number into the gecko device and cpu name
# respectively.
string(TOUPPER ${CONFIG_SOC_SERIES} SILABS_GECKO_DEVICE)

# Remove any prefix from the board, e.g. efr32_radio_
string(FIND ${CONFIG_BOARD} "brd" SILABS_GECKO_BRD_INDEX)

if (${SILABS_GECKO_BRD_INDEX} LESS 0)
  set(SILABS_GECKO_BOARD ${CONFIG_BOARD})
else()
  string(SUBSTRING ${CONFIG_BOARD} ${SILABS_GECKO_BRD_INDEX} -1 SILABS_GECKO_BOARD)
endif()

set(SILABS_GECKO_PART_NUMBER ${CONFIG_SOC_PART_NUMBER})

if (${CONFIG_BOARD} STREQUAL "efr32bg_sltb010a")
  set(SILABS_GECKO_BOARD "brd4184b")
endif()

zephyr_include_directories(
  Device/SiliconLabs/${SILABS_GECKO_DEVICE}/Include
  emlib/inc
  service/sleeptimer/src
  service/sleeptimer/inc
  service/sleeptimer/config
  service/power_manager/src
  service/power_manager/inc
  service/power_manager/config
  service/hfxo_manager/src
  service/hfxo_manager/inc
  service/hfxo_manager/config
  common/inc
  service/device_init/inc
  service/device_init/config/s2
  service/device_init/config/s2/sdid205
  board/inc
  board/config/${SILABS_GECKO_BOARD}
  )

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
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/device_init/src/sl_device_init_lfrco.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/device_init/src/sl_device_init_lfxo_s2.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/device_init/src/${SILABS_GECKO_BOARD}/sl_device_init_clocks.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     service/device_init/src/sl_device_init_nvic.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     board/src/sl_board_init.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     board/src/${SILABS_GECKO_BOARD}/sl_board_default_init.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     board/src/sl_board_control_gpio.c)
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