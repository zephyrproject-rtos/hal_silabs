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
