#!/bin/sh

# Add missing SecureFault interrupt number to device headers
sed -i '' "s/\(UsageFault_IRQn.*\)/\1\n#if defined(CONFIG_ARM_SECURE_FIRMWARE)\n  SecureFault_IRQn       = -9,\n#endif/" simplicity_sdk/platform/Device/SiliconLabs/*/Include/*.h
