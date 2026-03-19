#!/usr/bin/env python3

"""
Copyright (c) 2026 Silicon Laboratories Inc.

SPDX-License-Identifier: Apache-2.0
"""

import logging
import shutil
import tempfile
import urllib.request
import zipfile

from pathlib import Path

logger = logging.getLogger(__name__)

PIN_TOOL_URL = "https://github.com/SiliconLabs/simplicity_sdk/releases/download/v2025.6.0/pintool.zip"
CMSIS_PACK_URL = "https://www.silabs.com/documents/public/cmsis-packs/SiliconLabs.GeckoPlatform_{}_DFP.2025.6.0.pack"


def cmsis_pack(path: Path, family: str) -> Path:
    """
    Download CMSIS Pack containing SVD files for a given family
    """
    dst = path / "pack" / family
    if dst.exists():
        logger.info("Skipping download of CMSIS Pack for %s, already exists", family)
        return dst
    logger.info("Downloading CMSIS Pack for %s", family)
    with urllib.request.urlopen(
        CMSIS_PACK_URL.format(family.upper())
    ) as response:
        with tempfile.NamedTemporaryFile() as tmp_file:
            shutil.copyfileobj(response, tmp_file)
            tmp_file.flush()
            tmp_file.seek(0)

            with zipfile.ZipFile(tmp_file, "r") as z:
                z.extractall(dst)

    return dst


def pin_tool_data(path: Path) -> Path:
    """
    Download Pin Tool zip file from SiSDK release artifact
    """
    dst = path / "pin_tool"
    if dst.exists():
        logger.info("Skipping download of Pin Tool data, already exists")
        return dst
    logger.info("Downloading Pin Tool data")
    with urllib.request.urlopen(PIN_TOOL_URL) as response:
        with tempfile.NamedTemporaryFile() as tmp_file:
            shutil.copyfileobj(response, tmp_file)
            tmp_file.flush()
            tmp_file.seek(0)

            with zipfile.ZipFile(tmp_file, "r") as z:
                z.extractall(dst)

    return dst
