#!/usr/bin/env python3

"""
Copyright (c) 2024 Silicon Laboratories Inc.

SPDX-License-Identifier: Apache-2.0
"""

import argparse
import hashlib
import re
import shutil
import subprocess
from pathlib import Path
from ruamel.yaml import YAML


def copy_files(src: Path, dst: Path, paths: list[str|dict]) -> None:
  for path in paths:
    if isinstance(path, dict):
      inner_src = src / path["package"]
      inner_dst = dst / path.get("prefix", "")
      copy_files(inner_src, inner_dst, path["paths"])
    else:
      for f in src.glob(path):
        destfile = dst / f.relative_to(src)
        destfile.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy(f, destfile)


def update_blobs_from_lfs(mod: Path, sdk: Path, version: str|None, paths: list[str|dict]) -> None:
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
    src_path = sdk / path

    if not src_path.exists():
      for remap in paths:
        if isinstance(remap, str):
          continue

        if "prefix" in remap:
          try:
            path = path.relative_to(remap["prefix"])
          except ValueError:
            continue

        src_path = sdk / remap["package"] / path
        if src_path.exists():
          path = Path(remap["package"]) / path
          break
      else:
        raise ValueError(f"Blob {path} doesn't exist")

    lfs = subprocess.check_output(["git", "show", f"HEAD:{str(path)}"], cwd=sdk).decode()
    sha = re.search(r"sha256:([0-9a-f]{64})\s", lfs).group(1)

    blob["sha256"] = sha
    blob["url"] = f"https://artifacts.silabs.net/artifactory/gsdk/objects/{sha[0:2]}/{sha[2:4]}/{sha}"
    if version:
      blob["version"] = version
    else:
      blob["version"] = slcs["sdk_version"]

  y.dump(data, mod)


def update_blobs_from_url(mod: Path, sdk: Path, url: str, version: str|None, paths: list[str|dict]) -> None:
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
    src_path = sdk / path

    if not src_path.exists():
      for remap in paths:
        if isinstance(remap, str):
          continue

        if "prefix" in remap:
          try:
            path = path.relative_to(remap["prefix"])
          except ValueError:
            continue

        src_path = sdk / remap["package"] / path
        if src_path.exists():
          path = Path(remap["package"]) / path
          break
      else:
        raise ValueError(f"Blob {path} doesn't exist")

    sha = hashlib.sha256((src_path).read_bytes()).hexdigest()
    blob["sha256"] = sha
    blob["url"] = f"{url}{path}"
    if version:
      blob["version"] = version
    else:
      blob["version"] = slcs["sdk_version"] + "-dev"

  y.dump(data, mod)


def import_sisdk(src: Path, dst: Path, blobs: bool, blob_url: str|None, version: str|None, file_list: Path) -> None:
  print(f"Import SDK from {src}")
  for dir in dst.iterdir():
    if dir.is_dir():
      shutil.rmtree(dir, ignore_errors=True)

  y = YAML(typ='rt')
  paths = y.load(file_list)["paths"]
  copy_files(src, dst, paths)

  if blobs:
    print(f"Update module.yml with blobs from {src}")
    mod = Path(__file__).parent.parent / "zephyr" / "module.yml"
    if blob_url:
      update_blobs_from_url(mod, src, blob_url, version, paths)
    else:
      update_blobs_from_lfs(mod, src, version, paths)


if __name__ == "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument("--sdk", "-s", type=Path)
  parser.add_argument("--dst", "-d", type=Path, default=(Path(__file__).parent.parent / "simplicity_sdk").resolve())
  parser.add_argument("--file-list", "-f", type=Path, default=Path(__file__).parent / "simplicity_sdk_files.yaml")
  parser.add_argument("--blobs", "-b", action='store_true')
  parser.add_argument("--blob-url", "-u")
  parser.add_argument("--version", "-v")
  args = parser.parse_args()

  if args.sdk is not None:
    src = args.sdk.resolve(strict=True)
    import_sisdk(src, args.dst, args.blobs, args.blob_url, args.version, args.file_list)
    print("Done")
  else:
    print("No SDK to import from")
