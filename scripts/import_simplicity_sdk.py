#!/usr/bin/env python

"""
Copyright (c) 2024 Silicon Laboratories Inc.

SPDX-License-Identifier: Apache-2.0
"""

import argparse
import re
import shutil
import subprocess
from pathlib import Path
from ruamel.yaml import YAML

paths = [
  "License.txt",
  "platform/common/config/sl_core_config.h",
  "platform/common/inc/*.h",
  "platform/common/src/sl_assert.c",
  "platform/common/src/sl_core_cortexm.c",
  "platform/common/src/sl_slist.c",
  "platform/Device/SiliconLabs/EFR32BG2[279]/Include/*.h",
  "platform/Device/SiliconLabs/EFR32BG2[279]/Source/system_*.c",
  "platform/Device/SiliconLabs/EFR32FG2[3]/Include/*.h",
  "platform/Device/SiliconLabs/EFR32FG2[3]/Source/system_*.c",
  "platform/Device/SiliconLabs/EFR32MG2[149]/Include/*.h",
  "platform/Device/SiliconLabs/EFR32MG2[149]/Source/system_*.c",
  "platform/Device/SiliconLabs/EFR32ZG2[3]/Include/*.h",
  "platform/Device/SiliconLabs/EFR32ZG2[3]/Source/system_*.c",
  "platform/driver/gpio/inc/*.h",
  "platform/driver/gpio/src/*.c",
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
  "platform/security/sl_component/sli_psec_osal/**/*.[ch]",
  "platform/security/sl_component/sl_protocol_crypto/**/*.[ch]",
  "platform/security/sl_component/sli_crypto/**/*.[ch]",
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
  "platform/service/interrupt_manager/inc/*.h",
  "platform/service/memory_manager/config/*.h", # TODO
  "platform/service/memory_manager/inc/*.h",
  "platform/service/memory_manager/src/*.[ch]",
  "platform/service/memory_manager/profiler/config/*.h", # TODO
  "platform/service/memory_manager/profiler/inc/*.h",
  "platform/service/memory_manager/profiler/src/*.c",
  "platform/service/power_manager/config/**/*.h", # TODO
  "platform/service/power_manager/inc/*.h",
  "platform/service/power_manager/src/*/*.[ch]",
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


def update_blobs(mod: Path, sdk: Path) -> None:
  y = YAML(typ='rt')
  y.default_flow_style = False
  y.indent(mapping=2, sequence=4, offset=2)
  y.preserve_quotes = True
  y.width = 1024
  y.boolean_representation = ['False', 'True']

  slcs = y.load(sdk / "simplicity_sdk.slcs")

  data = y.load(mod)
  for blob in data.get('blobs'):
    path = Path(blob["path"])
    if not path.is_relative_to(Path("simplicity_sdk")):
      continue

    path = path.relative_to(Path("simplicity_sdk"))
    lfs = subprocess.check_output(["git", "show", f"HEAD:{str(path)}"], cwd=sdk).decode()
    sha = re.search(r"sha256:([0-9a-f]{64})\s", lfs).group(1)

    blob["sha256"] = sha
    blob["url"] = f"https://artifacts.silabs.net/artifactory/gsdk/objects/{sha[0:2]}/{sha[2:4]}/{sha}"
    blob["version"] = slcs["sdk_version"]

  y.dump(data, mod)


if __name__ == "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument("--sdk", "-s", type=Path)
  parser.add_argument("--blobs", "-b", action='store_true')
  args = parser.parse_args()

  dst = (Path(__file__).parent.parent / "simplicity_sdk").resolve()

  if args.sdk is not None:
    src = args.sdk.resolve(strict=True)

    print(f"Import SDK from {src}")
    for dir in dst.iterdir():
      if dir.is_dir():
        shutil.rmtree(dir, ignore_errors=True)

    copy_files(src, dst, paths)

    print(f"Update module.yml with blobs from {src}")
    mod = Path(__file__).parent.parent / "zephyr" / "module.yml"
    update_blobs(mod, src)

    print("Done")
  else:
    print("No SDK to import from")
