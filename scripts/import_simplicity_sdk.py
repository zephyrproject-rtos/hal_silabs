#!/usr/bin/env python

"""
Copyright (c) 2024 Silicon Laboratories Inc.

SPDX-License-Identifier: Apache-2.0
"""

import argparse
import shutil
from pathlib import Path

paths = [
  "License.txt",
  "platform/common/config/sl_core_config.h",
  "platform/common/inc/*.h",
  "platform/common/src/sl_assert.c",
  "platform/common/src/sl_core_cortexm.c",
  "platform/common/src/sl_slist.c",
  "platform/Device/SiliconLabs/EFR32BG2[27]/Include/*.h",
  "platform/Device/SiliconLabs/EFR32BG2[27]/Source/system_*.c",
  "platform/Device/SiliconLabs/EFR32FG2[3]/Include/*.h",
  "platform/Device/SiliconLabs/EFR32FG2[3]/Source/system_*.c",
  "platform/Device/SiliconLabs/EFR32MG2[14]/Include/*.h",
  "platform/Device/SiliconLabs/EFR32MG2[14]/Source/system_*.c",
  "platform/emlib/inc/*.h",
  "platform/emlib/src/*.c",
  "platform/peripheral/inc/*.h",
  "platform/peripheral/src/*.c",
  "platform/radio/rail_lib/chip/**/*.[ch]",
  "platform/radio/rail_lib/common/*.[ch]",
  "platform/radio/rail_lib/plugin/pa-conversions/**/*.[ch]",
  "platform/radio/rail_lib/plugin/rail_util_protocol/**/*.[ch]",
  "platform/radio/rail_lib/protocol/**/*.[ch]",
  "platform/security/sl_component/se_manager/**/*.[ch]",
  "platform/security/sl_component/sl_protocol_crypto/**/*.[ch]",
  "platform/service/clock_manager/config/**/*.h", # TODO
  "platform/service/clock_manager/inc/*.h",
  "platform/service/clock_manager/src/*.[ch]",
  "platform/service/device_init/config/**/*.h", # TODO
  "platform/service/device_init/inc/*.h",
  "platform/service/device_init/src/*.[ch]",
  "platform/service/device_manager/**/*.[ch]",
  "platform/service/hfxo_manager/config/**/*.h", # TODO
  "platform/service/hfxo_manager/inc/*.h",
  "platform/service/hfxo_manager/src/*.[ch]",
  "platform/service/memory_manager/config/*.h", # TODO
  "platform/service/memory_manager/inc/*.h",
  "platform/service/memory_manager/src/*.[ch]",
  "platform/service/memory_manager/profiler/config/*.h", # TODO
  "platform/service/memory_manager/profiler/inc/*.h",
  "platform/service/memory_manager/profiler/src/*.c",
  "platform/service/power_manager/config/**/*.h", # TODO
  "platform/service/power_manager/inc/*.h",
  "platform/service/power_manager/src/*.[ch]",
  "platform/service/sleeptimer/config/**/*.h", # TODO
  "platform/service/sleeptimer/inc/*.h",
  "platform/service/sleeptimer/src/*.[ch]",
  "protocol/bluetooth/bgstack/ll/inc/*.h",
]

configs = [
  "platform/common/config/sl_core_config.h"
]

def copy_files(src: Path, dst: Path, paths: list[str]) -> None:
  for path in paths:
    for f in src.glob(path):
      destfile = dst / f.relative_to(src)
      destfile.parent.mkdir(parents=True, exist_ok=True)
      shutil.copy(f, destfile)


if __name__ == "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument("--sdk", "-s", type=Path)
  args = parser.parse_args()

  dst = (Path(__file__).parent.parent / "simplicity_sdk").resolve()

  if args.sdk is not None:
    src = args.sdk.resolve(strict=True)
    print(f"Import SDK from {src}")
    for dir in dst.iterdir():
      if dir.is_dir():
        shutil.rmtree(dir, ignore_errors=True)

    copy_files(src, dst, paths)
