#!/usr/bin/env python

"""
Copyright (c) 2025 Silicon Laboratories Inc.

SPDX-License-Identifier: Apache-2.0
"""

import argparse
import json
from pathlib import Path

import git
from ruamel.yaml import YAML

import import_simplicity_sdk

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Update SiSDK")
    parser.add_argument("--src", help="Source directory", type=Path, default=Path(__file__).parent / "cache" / "simplicity_sdk")
    parser.add_argument("--dst", help="Destination directory", type=Path, default=Path(__file__).parent.parent / "simplicity_sdk")
    parser.add_argument("--src-props", type=Path)
    parser.add_argument("--signoff", "-s", action="store_true")
    args = parser.parse_args()

    if args.src_props:
        print("Using source information from properties file")
        props = json.loads(args.src_props.read_text())
        props["blobs"] = True
        props["blob_url"] = props["url"] + "!/"
    else:
        print("No source properties JSON file given, treating source directory as Git repo")
        repo = git.Repo(args.src)

        props = {
            "url": "https://github.com/SiliconLabs/simplicity_sdk",
            "commit": repo.head.commit.hexsha,
            "version": None,
            "blobs": True,
            "blob_url": None,
        }

    # Get SDK version from .slcs
    y = YAML(typ='rt')
    slcs = y.load(args.src / "simplicity_sdk.slcs")
    if props["version"] is None:
        props["version"] = slcs["sdk_version"]
    else:
        props["version"] = f"{slcs["sdk_version"]}-{props["version"]}"

    print("Find patch commits and revert them")
    repo = git.Repo(Path.cwd())
    patches = []
    for c in repo.iter_commits(max_count=200):
        if c.message.startswith("simplicity_sdk: Patch"):
            patches.append(c)
        elif c.message.startswith("simplicity_sdk: Import"):
            break
        else:
            print(f"  keep {c}")
    else:
        raise Exception("Failed to find import base")

    for p in patches:
        print(f"  revert {p}")
        repo.git.revert(p.hexsha, no_edit=True, signoff=args.signoff)

    print("Run import script")
    import_simplicity_sdk.import_sisdk(args.src, args.dst, props["blobs"], props["blob_url"], props["version"])
    repo.git.add(all=True)

    message = f"""simplicity_sdk: Import HAL version {props["version"]}

Origin: Simplicity SDK
License: Zlib
URL: {props["url"]}
Commit: {props["commit"]}
Version: {props["version"]}
Purpose: HAL for Silicon Labs Series 2 devices

"""

    if args.signoff:
        repo.git.commit("--signoff", "-m", message)
    else:
        repo.index.commit(message)

    print("Apply patches")
    for p in reversed(patches):
        print(f"  replay {p}")
        try:
            repo.git.cherry_pick(p.hexsha)
        except git.exc.GitCommandError:
            print(f"    WARNING: Failed to apply {p}")
            repo.git.cherry_pick(abort=True)

