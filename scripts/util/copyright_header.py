# Copyright (c) 2025 Silicon Laboratories Inc.
# SPDX-License-Identifier: Apache-2.0

import datetime
import re
from pathlib import Path

COPYRIGHT_HEADER = """/*
 * {}
 *
 * SPDX-License-Identifier: Apache-2.0{}
 */

"""
COPYRIGHT_DEFAULT = "Silicon Laboratories Inc."
COPYRIGHT_LINE = f"Copyright (c) {datetime.date.today().year} {COPYRIGHT_DEFAULT}"


def default() -> str:
    return COPYRIGHT_HEADER.format(COPYRIGHT_LINE, "")


def from_path(path: Path, description: list[str]=None) -> str:
    if description:
        extra = "\n *"
        for line in description:
            if line.strip():
                extra += "\n * " + line
            else:
                extra += "\n *"
    else:
        extra = ""
    if not path.exists():
        return COPYRIGHT_HEADER.format(COPYRIGHT_LINE, extra)

    items = []
    content = path.read_text(encoding="utf-8")
    for line in content.splitlines():
        if m := re.match(r".*(Copyright.*)", line):
            items.append(m.group(1).strip())
    if not any(COPYRIGHT_DEFAULT in line for line in items):
        items.append(COPYRIGHT_LINE)

    return COPYRIGHT_HEADER.format("\n * ".join(items), extra)
