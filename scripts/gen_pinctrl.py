#!/usr/bin/env python

"""
Copyright (c) 2024 Silicon Laboratories Inc.

SPDX-License-Identifier: Apache-2.0
"""

import argparse
import cmsis_svd
import datetime
import lxml
import re
import shutil
import tempfile
import urllib.request
import zipfile

from pathlib import Path

import cmsis_svd.parser

PIN_TOOL_URL = "https://github.com/SiliconLabs/simplicity_sdk/releases/download/v2024.6.2/pintool.zip"
CMSIS_PACK_URL = "https://www.silabs.com/documents/public/cmsis-packs/SiliconLabs.GeckoPlatform_FAMILY_DFP.2024.6.0.pack"

# Families to parse to produce generic pinout header
FAMILIES = {
  "xg21": ["efr32mg21", "efr32bg21", "mgm21", "bgm21"],
  "xg22": ["efr32mg22", "efr32bg22", "efr32fg22", "mgm22", "bgm22", "efm32pg22"],
  "xg23": ["efr32fg23", "efr32sg23", "efr32zg23", "zgm23", "efm32pg23"], # "fgm23", 
  "xg24": ["efr32mg24", "efr32bg24", "mgm24", "bgm24"],
  "xg25": ["efr32fg25"],
  "xg26": ["efr32mg26", "efr32bg26"],
  "xg27": ["efr32mg27", "efr32bg27"],
  "xg28": ["efr32fg28", "efr32sg28", "efr32zg28", "efm32pg28"],
  "xg29": ["efr32bg29"],
}
ABUSES = {
  "xg21": "platform/Device/SiliconLabs/EFR32MG21/Include/efr32mg21_gpio.h",
  "xg22": "platform/Device/SiliconLabs/EFR32BG22/Include/efr32bg22_gpio.h",
  "xg23": "platform/Device/SiliconLabs/EFR32FG23/Include/efr32fg23_gpio.h",
  "xg24": "platform/Device/SiliconLabs/EFR32MG24/Include/efr32mg24_gpio.h",
  "xg25": "platform/Device/SiliconLabs/EFR32FG25/Include/efr32fg25_gpio.h",
  "xg26": "platform/Device/SiliconLabs/EFR32MG26/Include/efr32mg26_gpio.h",
  "xg27": "platform/Device/SiliconLabs/EFR32BG27/Include/efr32bg27_gpio.h",
  "xg28": "platform/Device/SiliconLabs/EFR32FG28/Include/efr32fg28_gpio.h",
  "xg29": "platform/Device/SiliconLabs/EFR32BG29/Include/efr32bg29_gpio.h",
}

# Certain peripherals have different names in SVD and Pin Tool data; rename the SVD peripheral
PERIPHERAL_ALIAS = {
  "FRC": "PTI",
  "LETIMER": "LETIMER0",
  "SYXO0": "HFXO0",
}

# Certain signals have different names in SVD and Pin Tool data; rename the SVD signal
SIGNAL_ALIAS = {
  "CCC0": "CDTI0",
  "CCC1": "CDTI1",
  "CCC2": "CDTI2",
  "CCC3": "CDTI3",
  "USART1::SCLK": "CLK",
}

# Certain signals have different names in SVD and Pin Tool data; rename the Pin Tool signal
PT_SIGNAL_ALIAS = {
  "ACMPOUT": "DIGOUT",
  "COLOUT0": "COL_OUT_0",
  "COLOUT1": "COL_OUT_1",
  "COLOUT2": "COL_OUT_2",
  "COLOUT3": "COL_OUT_3",
  "COLOUT4": "COL_OUT_4",
  "COLOUT5": "COL_OUT_5",
  "COLOUT6": "COL_OUT_6",
  "COLOUT7": "COL_OUT_7",
  "ROWSENSE0": "ROW_SENSE_0",
  "ROWSENSE1": "ROW_SENSE_1",
  "ROWSENSE2": "ROW_SENSE_2",
  "ROWSENSE3": "ROW_SENSE_3",
  "ROWSENSE4": "ROW_SENSE_4",
  "ROWSENSE5": "ROW_SENSE_5",
  "ANTROLLOVER": "ANT_ROLL_OVER",
  "ANTRR0": "ANT_RR0",
  "ANTRR1": "ANT_RR1",
  "ANTRR2": "ANT_RR2",
  "ANTRR3": "ANT_RR3",
  "ANTRR4": "ANT_RR4",
  "ANTRR5": "ANT_RR5",
  "ANTSWEN": "ANT_SW_EN",
  "ANTSWUS": "ANT_SW_US",
  "ANTTRIG": "ANT_TRIG",
  "ANTTRIGSTOP": "ANT_TRIG_STOP",
  "BUFOUTREQINASYNC": "BUFOUT_REQ_IN_ASYNC",
  "USBVBUSSENSE": "USB_VBUS_SENSE",
  "SWCLKTCK": "SWCLK",
  "SWDIOTMS": "SWDIO",
}

# Expected offset of DBGROUTEPEN register across all of Series 2.
# Used as base address of pinctrl device tree node.
PINCTRL_GPIO_OFFSET = 1088


class Peripheral:
  def __init__(self, name, offset):
    self.name = name
    self.offset = offset
    self.signals = []

  def max_signal_len(self):
    return max(len(s.name) for s in self.signals)
  
  def set_signal_enable(self, name, bit, offset=0):
    for signal in self.signals:
      if signal.name == name:
        break
    else:
      signal = Signal(name, self, offset)
      self.signals.append(signal)

    signal.have_enable = True
    signal.enable = bit

  def set_signal_route(self, name, offset):
    for signal in self.signals:
      if signal.name == name:
        break
    else:
      signal = Signal(name, self)
      self.signals.append(signal)

    signal.route = offset - self.offset


class Signal:
  def __init__(self, name, peripheral, offset=0):
    self.peripheral = peripheral
    self.offset = offset
    self.name = name
    self.route = None
    self.have_enable = False
    self.enable = 0
    self.pinout = {}
  
  def display_name(self):
    return f"{self.peripheral.name}_{self.name}"


def download_pin_tool_data(path: Path) -> None:
  """
  Download Pin Tool zip file from SiSDK release artifact
  """
  dst = path / "pin_tool"
  if dst.exists():
    print("Skipping download of Pin Tool data, already exists")
    return
  print("Downloading Pin Tool data")
  with urllib.request.urlopen(PIN_TOOL_URL) as response:
    with tempfile.NamedTemporaryFile() as tmp_file:
      shutil.copyfileobj(response, tmp_file)

      with zipfile.ZipFile(tmp_file, 'r') as zip:
        zip.extractall(dst)


def download_cmsis_pack(path: Path, family: str) -> None:
  """
  Download CMSIS Pack containing SVD files for a given family
  """
  dst = path / "pack" / family
  if dst.exists():
    print(f"Skipping download of CMSIS Pack for {family}, already exists")
    return
  print(f"Downloading CMSIS Pack for {family}")
  with urllib.request.urlopen(CMSIS_PACK_URL.replace("FAMILY", family.upper())) as response:
    with tempfile.NamedTemporaryFile() as tmp_file:
      shutil.copyfileobj(response, tmp_file)

      with zipfile.ZipFile(tmp_file, 'r') as zip:
        zip.extractall(dst)


def parse_svd(peripherals, path: Path, family: str) -> None:
  for svd_path in (path / "pack" / family / "SVD" / family.upper()).glob("*.svd"):
    print(f"Parsing SVD for {svd_path.stem}")
    parser = cmsis_svd.parser.SVDParser.for_xml_file(svd_path)
    gpio: cmsis_svd.parser.SVDPeripheral = next(filter(lambda p: p.name == "GPIO_NS", parser.get_device().peripherals))
    for reg in gpio.registers:
      if reg.name == "DBGROUTEPEN":
        assert PINCTRL_GPIO_OFFSET == reg.address_offset

      reg_offset_word = (reg.address_offset - PINCTRL_GPIO_OFFSET) // 4

      if reg.name.endswith("ROUTEPEN"):
        peripheral = "GPIO"
        if peripheral not in peripherals:
          peripherals[peripheral] = Peripheral(peripheral, reg_offset_word)
        
        for field in reg.fields:
          if field.name.endswith("PEN"):
            signal = field.name[:-3]
            signal = SIGNAL_ALIAS.get(signal, signal)
            signal = SIGNAL_ALIAS.get(f"{peripheral}::{signal}", signal)
            peripherals[peripheral].set_signal_enable(signal, field.bit_offset, reg_offset_word)

      if reg.name.endswith("_ROUTEEN"):
        peripheral = reg.name[:-8]
        peripheral = PERIPHERAL_ALIAS.get(peripheral, peripheral)
        if peripheral not in peripherals:
          peripherals[peripheral] = Peripheral(peripheral, reg_offset_word)
        
        for field in reg.fields:
          if field.name.endswith("PEN"):
            signal = field.name[:-3]
            signal = SIGNAL_ALIAS.get(signal, signal)
            signal = SIGNAL_ALIAS.get(f"{peripheral}::{signal}", signal)
            peripherals[peripheral].set_signal_enable(signal, field.bit_offset)

      if reg.name.endswith("ROUTE"):
        peripheral, signal = reg.name.split("_", 1)
        peripheral = PERIPHERAL_ALIAS.get(peripheral, peripheral)
        signal = signal[:-5]
        signal = SIGNAL_ALIAS.get(signal, signal)
        signal = SIGNAL_ALIAS.get(f"{peripheral}::{signal}", signal)

        if peripheral not in peripherals:
          peripherals[peripheral] = Peripheral(peripheral, reg_offset_word)
        
        peripherals[peripheral].set_signal_route(signal, reg_offset_word)


def parse_pin_tool(peripherals, path: Path, family: str):
  for pin_tool in (path / "pin_tool" / "platform" / "hwconf_data" / "pin_tool" / family).glob("*/PORTIO.portio"):
    print(f"Parsing Pin Tool for {pin_tool.parent.stem}")
    with open(pin_tool, 'r') as f:
      tree = lxml.etree.parse(f)

    for peripheral in peripherals.values():
      for signal in peripheral.signals:
        pt_signal = PT_SIGNAL_ALIAS.get(signal.name, signal.name)

        if peripheral.name == "PRS0":
          pt_peripheral = f"PRS.{signal.name}"
          pt_signal_prefix = "PRS"
        else:
          pt_peripheral = peripheral.name
          pt_signal_prefix = peripheral.name

        for node in tree.getroot().xpath(f'portIo/pinRoutes/module[@name="{pt_peripheral}"]/selector[@name="{pt_signal_prefix}_{pt_signal}"]'):
          for loc in node.xpath(f'route[@name="{pt_signal}"]/location'):
            port = int(loc.attrib["portBankIndex"])
            pin = int(loc.attrib["pinIndex"])
            if port not in signal.pinout:
              signal.pinout[port] = set()
            signal.pinout[port].add(pin)

          break
        else:
          print(f"WARN: No Pin Tool match for {signal.display_name()} for {pin_tool.parent.stem}")


def write_header(path: Path, family, peripherals: dict, abuses: list) -> None:
  """
  Write DT binding header containing DBUS routing data for pinctrl use
  """
  lines = [
    "/*",
    f" * Copyright (c) {datetime.date.today().year} Silicon Laboratories Inc.",
    " * SPDX-License-Identifier: Apache-2.0",
    " *",
    f" * Pin Control for Silicon Labs {family.upper()} devices",
    " *",
    f" * This file was generated by the script {Path(__file__).name} in the hal_silabs module.",
    " * Do not manually edit.",
    " */",
    "",
    f"#ifndef ZEPHYR_DT_BINDINGS_PINCTRL_SILABS_{family.upper()}_PINCTRL_H_",
    f"#define ZEPHYR_DT_BINDINGS_PINCTRL_SILABS_{family.upper()}_PINCTRL_H_",
    "",
    "#include <zephyr/dt-bindings/pinctrl/silabs-pinctrl-dbus.h>",
    "",
  ]

  # Emit generic peripheral macros
  for peripheral in peripherals.values():
    have_content = False
    for signal in peripheral.signals:
      if signal.route is not None:
        pad = peripheral.max_signal_len() - len(signal.name) + 1
        lines.append(f"#define SILABS_DBUS_{signal.display_name()}(port, pin){' ' * pad}"
                     f"SILABS_DBUS(port, pin, {peripheral.offset}, {int(signal.have_enable)}, "
                     f"{signal.enable}, {signal.route})")
        have_content = True
      else:
        print(f"WARN: No route register for {signal.display_name()}")
    if have_content:
      lines.append("")

  # Emit pin-specific macros using peripheral macros
  for peripheral in peripherals.values():
    have_content = False
    for signal in peripheral.signals:
      for port, pins in signal.pinout.items():
        for pin in sorted(pins):
          pad = peripheral.max_signal_len() - len(signal.name) + 3 - len(str(pin))
          if signal.route is not None:
            lines.append(f"#define {signal.display_name()}_P{chr(65 + port)}{pin}{' ' * pad}"
                         f"SILABS_DBUS_{signal.display_name()}(0x{port:x}, 0x{pin:x})")
          else:
            lines.append(f"#define {signal.display_name()}_P{chr(65 + port)}{pin}{' ' * pad}"
                         f"SILABS_FIXED_ROUTE(0x{port:x}, 0x{pin:x}, {signal.offset}, {signal.enable})")
          have_content = True
    if have_content:
      lines.append("")

  # Emit analog buses
  max_len = 0
  for abus in abuses:
    curr_len = len(abus["bus_name"]) + len(abus["peripheral"])
    if curr_len > max_len:
      max_len = curr_len
  for abus in abuses:
    curr_len = len(abus["bus_name"]) + len(abus["peripheral"])
    lines.append(f"#define ABUS_{abus['bus_name']}_{abus['peripheral']}{' ' * (max_len - curr_len + 1)}"
                 f"SILABS_ABUS(0x{abus['base_offset']:x}, 0x{abus['parity']:x}, 0x{abus['value']:x})")
  lines.append("")

  lines.append(f"#endif /* ZEPHYR_DT_BINDINGS_PINCTRL_SILABS_{family.upper()}_PINCTRL_H_ */")
  lines.append("")
  path.mkdir(parents=True, exist_ok=True)
  (path / f"{family}-pinctrl.h").write_text("\n".join(lines))

def parse_abus(file: Path) -> list:
  offset_map = {
    "EVEN0": 0,
    "EVEN1": 1,
    "ODD0": 2,
    "ODD1": 3,
  }
  peripheral_map = {
    "ADC0": "IADC0",
  }
  abuses = []
  with file.open() as f:
    for line in f:
      if m := re.match(r"#define _GPIO_([A-Z])[A-Z]?BUSALLOC_([A-Z]+(EVEN\d|ODD\d))_([^\s]+)\s+0x(.+)UL", line):
        if m.group(4) not in ["DEFAULT", "TRISTATE", "MASK"]:
          abuses.append({
            "base_offset": ord(m.group(1)) - 65,
            "bus_name": m.group(2),
            "parity": offset_map[m.group(3)],
            "peripheral": peripheral_map.get(m.group(4), m.group(4)),
            "value": int(m.group(5), base=16),
          })

  return abuses

if __name__ == "__main__":
  parser = argparse.ArgumentParser(description="Generate headers for Pinctrl for Series 2 devices. "
                                   "The headers are used from DeviceTree, and represent every "
                                   "allowed pin selection for every digital bus signal as a DT "
                                   "compatible macro.")
  parser.add_argument("--workdir", "-w", default=Path(__file__).parent.absolute() / "cache",
                      type=Path, help="Working directory to store downloaded Pin Tool and "
                      "CMSIS-Pack artifacts.")
  parser.add_argument("--sdk", "-s", default=Path(__file__).parent.parent.absolute() / "simplicity_sdk",
                      type=Path, help="SDK directory.")
  parser.add_argument("--out", "-o", default=(Path(__file__).parent.absolute() / "out"), type=Path,
                      help="Output directory for generated bindings. Defaults to the directory "
                      "./out relative to the script. Set to $ZEPHYR_BASE/include/zephyr/"
                      "dt-bindings/pinctrl/silabs/ to directly generate output into the expected "
                      "location within the Zephyr main tree.")
  parser.add_argument("--family", "-f", default="xg24", choices=FAMILIES.keys(),
                      help="Device family to generate pinctrl bindings for. Defaults to xg24 if "
                      "not set.")
  args = parser.parse_args()

  download_pin_tool_data(args.workdir)

  peripherals = {}

  for family in FAMILIES[args.family]:
    download_cmsis_pack(args.workdir, family)
    # Find DBUS register offsets for all peripheral signals from SVD
    parse_svd(peripherals, args.workdir, family)
    # Add available pins for all peripheral signals from Pin Tool data
    parse_pin_tool(peripherals, args.workdir, family)

  abuses = parse_abus(args.sdk / ABUSES[args.family])

  write_header(args.out, args.family, peripherals, abuses)
