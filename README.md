# Zephyr HAL for Silicon Labs

This module provides the HAL content needed to build Zephyr applications for Silicon Labs devices.

The following SDKs are imported:

* `gecko` - Gecko SDK for EFM32 and EFR32 Series 0 and 1 devices
* `si32` - Precision32 HAL for SiM3U devices
* `simplicity_sdk` - Simplicity SDK for EFM32 and EFR32 Series 2 devices
* `wiseconnect` - WiSeConnect SDK for SiWx91x devices

## Simplicity SDK

### Updating Simplicity SDK

Updates to Simplicity SDK are performed using the scripts available in the `scripts` directory.
To import a new version of Simplicity SDK, run
`./scripts/update_simplicity_sdk.py --src <path/to/simplicity_sdk> --signoff`,
where `path/to/simplicity_sdk` points to a checked out copy of the Simplicity SDK git repo.

This will revert any Zephyr-specific patches, import the new version of Simplicity SDK, and
reapply any patches that still apply. Patches that don't apply cleanly are called out by the
script and skipped, and should be investigated to see if the patch is no longer needed, or if
it needs to be adapted to changes in the HAL. Patches are discovered by searching the git history
backwards until the first commit message starting with `simplicity_sdk: Import [...]` is
encountered.

Zephyr-specific patches to Simplicity SDK must have a commit message that starts with
`simplicity_sdk: Patch [...]` in order to be automatically identified by the update script.

The script `import_simplicity_sdk.py` does the job of importing the content and updating blobs in
module.yml, and contains the file list used to filter Simplicity SDK content needed in Zephyr.
This script is called internally by `update_simplicity_sdk.py`, but can also be run standalone.

If new content is imported from Simplicity SDK, update the file list in one commit, and use the
prefix `simplicity_sdk: Add [...]` in the commit message of a separate commit that adds the
additional content. Strive to use the same revision of Simplicity SDK as pre-existing content to
keep the HAL consistent. If the scripts listed above are used to assist in adding the new content,
ensure that patches aren't accidentally undone -- the commit should only contain new files, no
modified files. If patches are needed, add these in separate commits with the
`simplicity_sdk: Patch [...]` prefix.

### Generating Devicetree Bindings

Python scripts named `scripts/gen_*.py` are used to generate Devicetree bindings for devices
supported by Simplicity SDK. See the help text of each script for usage details.
