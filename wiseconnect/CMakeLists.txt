# Copyright (c) 2024 Silicon Laboratories Inc.
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(
    ../gecko/common/inc
    components/device/silabs/si91x/mcu/core/config
    components/device/silabs/si91x/mcu/core/chip/inc
    components/device/silabs/si91x/mcu/drivers/rom_driver/inc
    components/device/silabs/si91x/mcu/drivers/peripheral_drivers/inc
    components/device/silabs/si91x/mcu/drivers/service/clock_manager/inc
    components/device/silabs/si91x/mcu/drivers/systemlevel/inc
    components/device/silabs/si91x/mcu/drivers/unified_api/inc
    components/device/silabs/si91x/mcu/drivers/unified_peripheral_drivers/inc
    components/device/silabs/si91x/mcu/drivers/cmsis_driver/config
    components/device/silabs/si91x/mcu/drivers/cmsis_driver
    components/device/silabs/si91x/mcu/drivers/cmsis_driver/CMSIS/Driver/Include
)

# Keep these values sync with
# components/device/silabs/si91x/mcu/core/chip/component/siwg917*.slcc
zephyr_compile_definitions(
    SLI_SI91X_MCU_CONFIG_RADIO_BOARD_VER2
    SLI_SI91X_MCU_CONFIG_RADIO_BOARD_BASE_VER
    SLI_SI91X_MCU_ENABLE_FLASH_BASED_EXECUTION
    SLI_SI91X_MCU_ENABLE_IPMU_APIS
    SLI_SI91X_MCU_INTERFACE
    SLI_SI917
    SLI_SI917B0
    CLOCK_ROMDRIVER_PRESENT
)

zephyr_compile_definitions_ifdef(CONFIG_SIWX917_FLASH_MODE_COMMON
    SLI_SI91X_MCU_COMMON_FLASH_MODE=1
)

zephyr_sources(
    components/device/silabs/si91x/mcu/core/chip/src/rsi_deepsleep_soc.c
    components/device/silabs/si91x/mcu/core/chip/src/system_si91x.c
    components/device/silabs/si91x/mcu/drivers/systemlevel/src/rsi_ipmu.c
    components/device/silabs/si91x/mcu/drivers/systemlevel/src/rsi_pll.c
    components/device/silabs/si91x/mcu/drivers/systemlevel/src/rsi_ulpss_clk.c
    components/device/silabs/si91x/mcu/drivers/service/clock_manager/src/sl_si91x_clock_manager.c
    components/device/silabs/si91x/mcu/drivers/unified_api/src/sl_si91x_driver_gpio.c
    components/device/silabs/si91x/mcu/drivers/unified_peripheral_drivers/src/sl_si91x_peripheral_gpio.c
    components/device/silabs/si91x/mcu/core/chip/src/iPMU_prog/iPMU_dotc/ipmu_apis.c
    components/device/silabs/si91x/mcu/core/chip/src/iPMU_prog/iPMU_dotc/rsi_system_config_917.c
)

if(CONFIG_WIFI_SIWX917)

zephyr_include_directories(
    # FIXME: find why this directory is not included when CMSIS_RTOS_V2=y
    ${ZEPHYR_BASE}/include/zephyr/portability
    ${ZEPHYR_BASE}/include/zephyr/posix
    components/common/inc
    components/device/silabs/si91x/wireless/inc
    components/device/silabs/si91x/wireless/sl_net/inc
    components/device/silabs/si91x/wireless/socket/inc
    components/device/silabs/si91x/wireless/asynchronous_socket/inc
    components/device/silabs/si91x/wireless/ahb_interface/inc
    components/device/silabs/si91x/mcu/core/chip/config
    components/protocol/wifi/inc
    components/service/network_manager/inc
    resources/defaults
)

zephyr_compile_definitions(
    SLI_SI91X_OFFLOAD_NETWORK_STACK
    SLI_SI91X_SOCKETS
    SL_SI91X_SI917_RAM_MEM_CONFIG=1
    SL_WIFI_COMPONENT_INCLUDED
)
zephyr_compile_definitions_ifdef(CONFIG_NET_IPV6
    SLI_SI91X_ENABLE_IPV6
)

zephyr_sources(
    components/common/src/sl_utility.c
    components/device/silabs/si91x/wireless/ahb_interface/src/rsi_hal_mcu_m4_ram.c
    components/device/silabs/si91x/wireless/ahb_interface/src/rsi_hal_mcu_m4_rom.c
    components/device/silabs/si91x/wireless/ahb_interface/src/sli_siwx917_soc.c
    components/device/silabs/si91x/wireless/ahb_interface/src/sl_platform.c
    components/device/silabs/si91x/wireless/ahb_interface/src/sl_platform_wireless.c
    components/device/silabs/si91x/wireless/ahb_interface/src/sl_si91x_bus.c
    components/device/silabs/si91x/wireless/asynchronous_socket/src/sl_si91x_socket.c
    components/device/silabs/si91x/wireless/host_mcu/si91x/siwx917_soc_ncp_host.c
    components/device/silabs/si91x/wireless/memory/malloc_buffers.c
    components/device/silabs/si91x/wireless/sl_net/src/sl_si91x_net_credentials.c
    components/device/silabs/si91x/wireless/sl_net/src/sl_si91x_net_internal_stack.c
    components/device/silabs/si91x/wireless/sl_net/src/sl_net_si91x_integration_handler.c
    components/device/silabs/si91x/wireless/sl_net/src/sl_net_rsi_utility.c
    components/device/silabs/si91x/wireless/socket/src/sl_si91x_socket_utility.c
    components/device/silabs/si91x/wireless/src/sl_rsi_utility.c
    components/device/silabs/si91x/wireless/src/sl_si91x_callback_framework.c
    components/device/silabs/si91x/wireless/src/sl_si91x_driver.c
    components/device/silabs/si91x/wireless/threading/sli_si91x_multithreaded.c
    components/protocol/wifi/si91x/sl_wifi.c
    components/protocol/wifi/src/sl_wifi_callback_framework.c
    components/service/network_manager/si91x/sl_net_si91x.c
    components/service/network_manager/src/sl_net_basic_credentials.c
    components/service/network_manager/src/sl_net_basic_profiles.c
    components/service/network_manager/src/sl_net.c
)
endif() # CONFIG_WIFI_SIWX917
