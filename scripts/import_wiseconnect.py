#!/usr/bin/env python3

"""
Copyright (c) 2024 Silicon Laboratories Inc.

SPDX-License-Identifier: Apache-2.0
"""

import argparse
import os
import shutil
import tempfile
import subprocess
from pathlib import Path


paths = [
    "components/common/inc/sl_additional_status.h",
    "components/common/inc/sl_constants.h",
    "components/common/inc/sl_ieee802_types.h",
    "components/common/inc/sl_ip_types.h",
    "components/common/inc/sl_utility.h",
    "components/common/src/sl_utility.c",
    "components/device/silabs/si91x/mcu/core/chip/config/sl_board_configuration.h",
    "components/device/silabs/si91x/mcu/core/chip/inc/base_types.h",
    "components/device/silabs/si91x/mcu/core/chip/inc/data_types.h",
    "components/device/silabs/si91x/mcu/core/chip/inc/em_device.h",
    "components/device/silabs/si91x/mcu/core/chip/inc/rsi_ccp_common.h",
    "components/device/silabs/si91x/mcu/core/chip/inc/rsi_error.h",
    "components/device/silabs/si91x/mcu/core/chip/inc/rsi_ps_ram_func.h",
    "components/device/silabs/si91x/mcu/core/chip/inc/rsi_system_config.h",
    "components/device/silabs/si91x/mcu/core/chip/inc/si91x_device.h",
    "components/device/silabs/si91x/mcu/core/chip/inc/si91x_mvp.h",
    "components/device/silabs/si91x/mcu/core/chip/inc/system_si91x.h",
    "components/device/silabs/si91x/mcu/core/chip/src/iPMU_prog/iPMU_dotc/ipmu_apis.c",
    "components/device/silabs/si91x/mcu/core/chip/src/iPMU_prog/iPMU_dotc/rsi_system_config_917.c",
    "components/device/silabs/si91x/mcu/core/chip/src/rsi_deepsleep_soc.c",
    "components/device/silabs/si91x/mcu/core/chip/src/system_si91x.c",
    "components/device/silabs/si91x/mcu/core/config/rsi_ccp_user_config.h",
    "components/device/silabs/si91x/mcu/drivers/cmsis_driver/CMSIS/Driver/Include/Driver_Common.h",
    "components/device/silabs/si91x/mcu/drivers/cmsis_driver/CMSIS/Driver/Include/Driver_I2C.h",
    "components/device/silabs/si91x/mcu/drivers/cmsis_driver/CMSIS/Driver/Include/Driver_SAI.h",
    "components/device/silabs/si91x/mcu/drivers/cmsis_driver/CMSIS/Driver/Include/Driver_SPI.h",
    "components/device/silabs/si91x/mcu/drivers/cmsis_driver/CMSIS/Driver/Include/Driver_USART.h",
    "components/device/silabs/si91x/mcu/drivers/cmsis_driver/config/RTE_Device_917.h",
    "components/device/silabs/si91x/mcu/drivers/cmsis_driver/GSPI.h",
    "components/device/silabs/si91x/mcu/drivers/cmsis_driver/I2C.h",
    "components/device/silabs/si91x/mcu/drivers/cmsis_driver/SAI.h",
    "components/device/silabs/si91x/mcu/drivers/cmsis_driver/SPI.h",
    "components/device/silabs/si91x/mcu/drivers/cmsis_driver/UDMA.h",
    "components/device/silabs/si91x/mcu/drivers/cmsis_driver/USART.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/inc/rsi_crc.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/inc/rsi_ct.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/inc/rsi_efuse.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/inc/rsi_egpio.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/inc/rsi_gpdma.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/inc/rsi_pwm.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/inc/rsi_qspi.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/inc/rsi_qspi_proto.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/inc/rsi_rng.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/inc/rsi_timers.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/inc/rsi_udma.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/inc/rsi_udma_wrapper.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/src/clock_update.c",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/src/clock_update.h",
    "components/device/silabs/si91x/mcu/drivers/peripheral_drivers/src/rsi_rng.c",
    "components/device/silabs/si91x/mcu/drivers/rom_driver/inc/rsi_packing.h",
    "components/device/silabs/si91x/mcu/drivers/rom_driver/inc/rsi_rom_clks.h",
    "components/device/silabs/si91x/mcu/drivers/rom_driver/inc/rsi_rom_egpio.h",
    "components/device/silabs/si91x/mcu/drivers/rom_driver/inc/rsi_rom_power_save.h",
    "components/device/silabs/si91x/mcu/drivers/rom_driver/inc/rsi_rom_rng.h",
    "components/device/silabs/si91x/mcu/drivers/rom_driver/inc/rsi_rom_table_si91x.h",
    "components/device/silabs/si91x/mcu/drivers/rom_driver/inc/rsi_rom_udma.h",
    "components/device/silabs/si91x/mcu/drivers/rom_driver/inc/rsi_rom_udma_wrapper.h",
    "components/device/silabs/si91x/mcu/drivers/rom_driver/inc/rsi_rom_ulpss_clk.h",
    "components/device/silabs/si91x/mcu/drivers/rom_driver/src/rsi_rom_table_si91x.c",
    "components/device/silabs/si91x/mcu/drivers/service/clock_manager/inc/sl_si91x_clock_manager.h",
    "components/device/silabs/si91x/mcu/drivers/service/clock_manager/src/sl_si91x_clock_manager.c",
    "components/device/silabs/si91x/mcu/drivers/systemlevel/inc/rsi_ipmu.h",
    "components/device/silabs/si91x/mcu/drivers/systemlevel/inc/rsi_pll.h",
    "components/device/silabs/si91x/mcu/drivers/systemlevel/inc/rsi_power_save.h",
    "components/device/silabs/si91x/mcu/drivers/systemlevel/inc/rsi_processor_sensor.h",
    "components/device/silabs/si91x/mcu/drivers/systemlevel/inc/rsi_reg_spi.h",
    "components/device/silabs/si91x/mcu/drivers/systemlevel/inc/rsi_retention.h",
    "components/device/silabs/si91x/mcu/drivers/systemlevel/inc/rsi_temp_sensor.h",
    "components/device/silabs/si91x/mcu/drivers/systemlevel/inc/rsi_time_period.h",
    "components/device/silabs/si91x/mcu/drivers/systemlevel/inc/rsi_ulpss_clk.h",
    "components/device/silabs/si91x/mcu/drivers/systemlevel/inc/rsi_wwdt.h",
    "components/device/silabs/si91x/mcu/drivers/systemlevel/src/rsi_ipmu.c",
    "components/device/silabs/si91x/mcu/drivers/systemlevel/src/rsi_pll.c",
    "components/device/silabs/si91x/mcu/drivers/systemlevel/src/rsi_ulpss_clk.c",
    "components/device/silabs/si91x/mcu/drivers/unified_api/inc/sl_driver_gpio.h",
    "components/device/silabs/si91x/mcu/drivers/unified_api/inc/sl_si91x_driver_gpio.h",
    "components/device/silabs/si91x/mcu/drivers/unified_api/src/sl_si91x_driver_gpio.c",
    "components/device/silabs/si91x/mcu/drivers/unified_peripheral_drivers/inc/sl_si91x_gpio_common.h",
    "components/device/silabs/si91x/mcu/drivers/unified_peripheral_drivers/inc/sl_si91x_gpio.h",
    "components/device/silabs/si91x/mcu/drivers/unified_peripheral_drivers/inc/sl_si91x_peripheral_gpio.h",
    "components/device/silabs/si91x/mcu/drivers/unified_peripheral_drivers/src/sl_si91x_peripheral_gpio.c",
    "components/device/silabs/si91x/wireless/ahb_interface/inc/rsi_m4.h",
    "components/device/silabs/si91x/wireless/ahb_interface/inc/rsi_os.h",
    "components/device/silabs/si91x/wireless/ahb_interface/inc/rsi_pkt_mgmt.h",
    "components/device/silabs/si91x/wireless/ahb_interface/inc/rsi_wisemcu_hardware_setup.h",
    "components/device/silabs/si91x/wireless/ahb_interface/inc/sl_device.h",
    "components/device/silabs/si91x/wireless/ahb_interface/inc/sli_siwx917_soc.h",
    "components/device/silabs/si91x/wireless/ahb_interface/inc/sli_siwx917_timer.h",
    "components/device/silabs/si91x/wireless/ahb_interface/src/rsi_hal_mcu_m4_ram.c",
    "components/device/silabs/si91x/wireless/ahb_interface/src/rsi_hal_mcu_m4_rom.c",
    "components/device/silabs/si91x/wireless/ahb_interface/src/sli_siwx917_soc.c",
    "components/device/silabs/si91x/wireless/ahb_interface/src/sl_platform.c",
    "components/device/silabs/si91x/wireless/ahb_interface/src/sl_platform_wireless.c",
    "components/device/silabs/si91x/wireless/ahb_interface/src/sl_si91x_bus.c",
    "components/device/silabs/si91x/wireless/asynchronous_socket/inc/sl_si91x_socket.h",
    "components/device/silabs/si91x/wireless/asynchronous_socket/src/sl_si91x_socket.c",
    "components/device/silabs/si91x/wireless/ble/inc/rsi_ble_apis.h",
    "components/device/silabs/si91x/wireless/ble/inc/rsi_ble_common_config.h",
    "components/device/silabs/si91x/wireless/ble/inc/rsi_ble.h",
    "components/device/silabs/si91x/wireless/ble/inc/rsi_bt_common_apis.h",
    "components/device/silabs/si91x/wireless/ble/inc/rsi_bt_common_config.h",
    "components/device/silabs/si91x/wireless/ble/inc/rsi_bt_common.h",
    "components/device/silabs/si91x/wireless/ble/inc/rsi_common_apis.h",
    "components/device/silabs/si91x/wireless/ble/inc/rsi_common.h",
    "components/device/silabs/si91x/wireless/ble/inc/rsi_user.h",
    "components/device/silabs/si91x/wireless/ble/inc/rsi_utils.h",
    "components/device/silabs/si91x/wireless/ble/inc/sl_si91x_ble.h",
    "components/device/silabs/si91x/wireless/ble/src/rsi_bt_ble.c",
    "components/device/silabs/si91x/wireless/ble/src/rsi_common_apis.c",
    "components/device/silabs/si91x/wireless/ble/src/rsi_utils.c",
    "components/device/silabs/si91x/wireless/host_mcu/si91x/siwx917_soc_ncp_host.c",
    "components/device/silabs/si91x/wireless/inc/sl_rsi_utility.h",
    "components/device/silabs/si91x/wireless/inc/sl_si91x_constants.h",
    "components/device/silabs/si91x/wireless/inc/sl_si91x_core_utilities.h",
    "components/device/silabs/si91x/wireless/inc/sl_si91x_driver.h",
    "components/device/silabs/si91x/wireless/inc/sl_si91x_host_interface.h",
    "components/device/silabs/si91x/wireless/inc/sl_si91x_protocol_types.h",
    "components/device/silabs/si91x/wireless/inc/sl_si91x_status.h",
    "components/device/silabs/si91x/wireless/inc/sl_si91x_types.h",
    "components/device/silabs/si91x/wireless/inc/sl_wifi_device.h",
    "components/device/silabs/si91x/wireless/memory/malloc_buffers.c",
    "components/device/silabs/si91x/wireless/sl_net/inc/sl_net_rsi_utility.h",
    "components/device/silabs/si91x/wireless/sl_net/inc/sl_net_si91x.h",
    "components/device/silabs/si91x/wireless/sl_net/inc/sl_net_si91x_integration_handler.h",
    "components/device/silabs/si91x/wireless/sl_net/src/sl_net_rsi_utility.c",
    "components/device/silabs/si91x/wireless/sl_net/src/sl_net_si91x_callback_framework.c",
    "components/device/silabs/si91x/wireless/sl_net/src/sl_net_si91x_integration_handler.c",
    "components/device/silabs/si91x/wireless/sl_net/src/sl_si91x_net_credentials.c",
    "components/device/silabs/si91x/wireless/sl_net/src/sl_si91x_net_internal_stack.c",
    "components/device/silabs/si91x/wireless/socket/inc/sl_bsd_utility.h",
    "components/device/silabs/si91x/wireless/socket/inc/sl_si91x_socket_callback_framework.h",
    "components/device/silabs/si91x/wireless/socket/inc/sl_si91x_socket_constants.h",
    "components/device/silabs/si91x/wireless/socket/inc/sl_si91x_socket_types.h",
    "components/device/silabs/si91x/wireless/socket/inc/sl_si91x_socket_utility.h",
    "components/device/silabs/si91x/wireless/socket/src/sl_si91x_socket_utility.c",
    "components/device/silabs/si91x/wireless/src/sl_rsi_utility.c",
    "components/device/silabs/si91x/wireless/src/sl_si91x_callback_framework.c",
    "components/device/silabs/si91x/wireless/src/sl_si91x_driver.c",
    "components/device/silabs/si91x/wireless/threading/sli_si91x_multithreaded.c",
    "components/protocol/wifi/inc/sl_wifi_callback_framework.h",
    "components/protocol/wifi/inc/sl_wifi_constants.h",
    "components/protocol/wifi/inc/sl_wifi_credentials.h",
    "components/protocol/wifi/inc/sl_wifi.h",
    "components/protocol/wifi/inc/sl_wifi_host_interface.h",
    "components/protocol/wifi/inc/sl_wifi_types.h",
    "components/protocol/wifi/si91x/sl_wifi.c",
    "components/protocol/wifi/src/sl_wifi_basic_credentials.c",
    "components/protocol/wifi/src/sl_wifi_callback_framework.c",
    "components/service/bsd_socket/si91x_socket/sl_si91x_socket_support.h",
    "components/service/network_manager/inc/sl_net_constants.h",
    "components/service/network_manager/inc/sl_net_dns.h",
    "components/service/network_manager/inc/sl_net.h",
    "components/service/network_manager/inc/sl_net_ip_types.h",
    "components/service/network_manager/inc/sl_net_types.h",
    "components/service/network_manager/inc/sl_net_wifi_types.h",
    "components/service/network_manager/si91x/sl_net_si91x.c",
    "components/service/network_manager/src/sl_net_basic_credentials.c",
    "components/service/network_manager/src/sl_net_basic_profiles.c",
    "components/service/network_manager/src/sl_net.c",
    "components/service/network_manager/src/sl_net_credentials.c",
    "resources/defaults/sl_net_default_values.h",
    "resources/defaults/sl_wifi_region_db_config.h",
]

def copy_files(src: Path, dst: Path, paths: list[str]) -> None:
    for path in paths:
        for f in src.glob(path):
            if not os.path.exists(f):
                print(f"Invalid path: {f}")
                continue
            destfile = dst / f.relative_to(src)
            if os.path.exists(destfile):
                continue
            print(f"Import {f.relative_to(src)}")
            destfile.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy(f, destfile)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("sdk", type=Path,
                        help="Source WiseConnect directory")
    parser.add_argument("--dest", "-d", type=Path,
                        help="store the result somewhere else than \"wiseconnect/\" directory")
    parser.add_argument("--overwrite", "-f", action="store_true",
                        help="Remove DEST before to continue")
    args = parser.parse_args()

    if args.dest:
        dst = args.dest
    else:
        dst = (Path(__file__).parent.parent / "wiseconnect").resolve()

    if args.overwrite:
        shutil.rmtree(dst)
    copy_files(args.sdk, dst, paths)

