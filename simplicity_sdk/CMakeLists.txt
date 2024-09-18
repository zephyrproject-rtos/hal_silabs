# CMake integration for Simplicity SDK
#
# Copyright (c) 2017, Christian Taedcke
# Copyright (c) 2021, Safran Passenger Innovations Germany GmbH
# Copyright (c) 2022, Antmicro <www.antmicro.com>
# Copyright (c) 2024, Silicon Laboratories Inc.
#
# SPDX-License-Identifier: Apache-2.0
#

# Translate the SoC name and part number into the gecko device and cpu name
# respectively.
string(TOUPPER ${CONFIG_SOC_SERIES} SILABS_DEVICE_FAMILY)

# Get SoC series number, i.e. translate e.g. efr32bg22 -> 22
string(SUBSTRING ${CONFIG_SOC_SERIES} 7 2 SILABS_DEVICE_FAMILY_NUMBER)

set(SILABS_DEVICE_PART_NUMBER ${CONFIG_SOC_PART_NUMBER})

function(add_prebuilt_library lib_name prebuilt_path)
  add_library(${lib_name} STATIC IMPORTED GLOBAL)
  set_target_properties(${lib_name} PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../zephyr/blobs/simplicity_sdk/${prebuilt_path}
  )
  zephyr_link_libraries(${lib_name})
endfunction()

if(CONFIG_SOC_GECKO_HAS_RADIO)
  zephyr_include_directories_ifdef(CONFIG_SOC_FAMILY_SILABS_S2
    platform/radio/rail_lib/plugin/pa-conversions/efr32xg${SILABS_DEVICE_FAMILY_NUMBER}/config
    platform/radio/rail_lib/chip/efr32/efr32xg2x
  )

  zephyr_include_directories(
    platform/radio/rail_lib/common
    platform/radio/rail_lib/plugin/pa-conversions
    protocol/bluetooth/bgstack/ll/inc
  )

  # sl_protocol_crypto
  zephyr_sources_ifdef(CONFIG_BT_SILABS_HCI
    platform/security/sl_component/sl_protocol_crypto/src/sli_radioaes_management.c
    platform/security/sl_component/sl_protocol_crypto/src/sli_protocol_crypto_radioaes.c
  )

  if(CONFIG_BT_SILABS_HCI)
    # prebuilt libs
    add_prebuilt_library(liblinklayer protocol/bluetooth/bgstack/ll/lib/libbluetooth_controller_efr32xg${SILABS_DEVICE_FAMILY_NUMBER}_gcc_release.a)
    add_prebuilt_library(libbgcommon  protocol/bluetooth/bgcommon/lib/build/gcc/cortex-m33/bgcommon/release/libbgcommon.a)

    # link mbedTLS
    if(CONFIG_MBEDTLS)
      zephyr_link_libraries(mbedTLS)
    endif()
  endif()

  if(CONFIG_SOC_GECKO_USE_RAIL)
    # rail
    zephyr_sources(platform/radio/rail_lib/plugin/pa-conversions/pa_conversions_efr32.c)
    zephyr_sources(platform/radio/rail_lib/plugin/pa-conversions/pa_curves_efr32.c)

    # prebuilt libs
    add_prebuilt_library(librail platform/radio/rail_lib/autogen/librail_release/librail_efr32xg${SILABS_DEVICE_FAMILY_NUMBER}_gcc_release.a)

    zephyr_include_directories_ifdef(CONFIG_SOC_GECKO_CUSTOM_RADIO_PHY
      platform/radio/rail_lib/protocol/ble
      platform/radio/rail_lib/protocol/ieee802154
      platform/radio/rail_lib/protocol/zwave
      platform/radio/rail_lib/protocol/sidewalk
      platform/radio/rail_lib/plugin/rail_util_protocol
      platform/radio/rail_lib/plugin/rail_util_protocol/config/efr32xg${SILABS_DEVICE_FAMILY_NUMBER}
    )
    zephyr_sources_ifdef(CONFIG_SOC_GECKO_CUSTOM_RADIO_PHY
      platform/radio/rail_lib/plugin/rail_util_protocol/sl_rail_util_protocol.c
    )
  endif()
 endif()

zephyr_include_directories(
  platform/Device/SiliconLabs/${SILABS_DEVICE_FAMILY}/Include
  platform/common/config
  platform/common/inc
  platform/emlib/inc
  platform/peripheral/inc
  platform/service/clock_manager/inc
  platform/service/device_init/config/s2
  platform/service/device_init/config/s2/sdid${CONFIG_SOC_GECKO_SDID}
  platform/service/device_init/inc
  platform/service/device_manager/inc
  platform/service/hfxo_manager/config
  platform/service/hfxo_manager/inc
  platform/service/hfxo_manager/src
  platform/service/memory_manager/inc
  platform/service/memory_manager/profiler/inc
  platform/service/power_manager/config
  platform/service/power_manager/inc
  platform/service/power_manager/src
  platform/service/sleeptimer/config
  platform/service/sleeptimer/inc
  platform/service/sleeptimer/src
  platform/security/sl_component/sl_protocol_crypto/src
  ${BOARD_DIR}
)

zephyr_compile_definitions(
  ${SILABS_DEVICE_PART_NUMBER}
)

zephyr_compile_definitions_ifdef(CONFIG_SOC_GECKO_DEV_INIT
  SL_CATALOG_POWER_MANAGER_PRESENT
  SL_CATALOG_HFXO_MANAGER_PRESENT
)

zephyr_compile_options(
  -mcmse # Cortex-M Security Extensions are needed for startup code
)

zephyr_sources(
  platform/Device/SiliconLabs/${SILABS_DEVICE_FAMILY}/Source/system_${CONFIG_SOC_SERIES}.c
  platform/emlib/src/em_system.c
  platform/service/clock_manager/src/sl_clock_manager.c
  platform/service/clock_manager/src/sl_clock_manager_hal_s2.c
  platform/service/device_manager/devices/sl_device_peripheral_hal_efr32xg${SILABS_DEVICE_FAMILY_NUMBER}.c
  platform/service/device_manager/gpios/sl_device_gpio_common.c
  platform/service/device_manager/src/sl_device_clock.c
  platform/service/device_manager/src/sl_device_gpio.c
  platform/service/device_manager/src/sl_device_peripheral.c
)

if(NOT SILABS_DEVICE_FAMILY_NUMBER EQUAL "21")
  zephyr_sources(
    platform/service/device_manager/clocks/sl_device_clock_efr32xg${SILABS_DEVICE_FAMILY_NUMBER}.c
  )
endif()

zephyr_sources_ifdef(CONFIG_SOC_GECKO_IADC         platform/emlib/src/em_iadc.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_BURTC        platform/emlib/src/em_burtc.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_CMU          platform/emlib/src/em_cmu.c)

zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT
  platform/service/device_init/src/sl_device_init_dcdc_s2.c
  platform/service/device_init/src/sl_device_init_dpll_s2.c
  platform/service/device_init/src/sl_device_init_hfrco.c
  platform/service/device_init/src/sl_device_init_hfxo_s2.c
  platform/service/device_init/src/sl_device_init_nvic.c
  platform/service/power_manager/src/sl_power_manager.c
  platform/service/power_manager/src/sl_power_manager_hal_s2.c
  platform/service/hfxo_manager/src/sl_hfxo_manager.c
  platform/service/hfxo_manager/src/sl_hfxo_manager_hal_s2.c
  platform/service/memory_manager/profiler/src/sli_memory_profiler_stubs.c
)

zephyr_sources_ifdef(CONFIG_SOC_GECKO_DEV_INIT     platform/common/src/sl_slist.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_CORE
  platform/emlib/src/em_core.c
  platform/common/src/sl_core_cortexm.c
)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_CRYOTIMER    platform/emlib/src/em_cryotimer.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_EMU          platform/emlib/src/em_emu.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_GPIO         platform/emlib/src/em_gpio.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_I2C          platform/emlib/src/em_i2c.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_LETIMER      platform/emlib/src/em_letimer.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_LEUART       platform/emlib/src/em_leuart.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_MSC          platform/emlib/src/em_msc.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_PRS          platform/emlib/src/em_prs.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_RMU          platform/emlib/src/em_rmu.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_RTC          platform/emlib/src/em_rtc.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_RTCC         platform/emlib/src/em_rtcc.c)
zephyr_sources_ifdef(CONFIG_COUNTER_GECKO_STIMER
  platform/peripheral/src/sl_hal_sysrtc.c
  platform/service/sleeptimer/src/sl_sleeptimer_hal_rtcc.c
  platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.c
  platform/service/sleeptimer/src/sl_sleeptimer.c
)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_EUSART       platform/emlib/src/em_eusart.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_TIMER        platform/emlib/src/em_timer.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_USART        platform/emlib/src/em_usart.c)
zephyr_sources_ifdef(CONFIG_SOC_GECKO_WDOG         platform/emlib/src/em_wdog.c)

zephyr_include_directories_ifdef(CONFIG_SOC_GECKO_SE
  platform/security/sl_component/se_manager/src
  platform/security/sl_component/se_manager/inc
)

zephyr_sources_ifdef(CONFIG_SOC_GECKO_SE
  platform/emlib/src/em_se.c
  platform/security/sl_component/se_manager/src/sl_se_manager.c
  platform/security/sl_component/se_manager/src/sl_se_manager_util.c
  platform/security/sl_component/se_manager/src/sli_se_manager_mailbox.c
)

zephyr_sources_ifdef(CONFIG_ENTROPY_GECKO_SE
  platform/security/sl_component/se_manager/src/sl_se_manager_entropy.c
)
