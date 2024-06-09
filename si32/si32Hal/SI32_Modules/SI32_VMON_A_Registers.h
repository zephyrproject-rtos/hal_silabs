//------------------------------------------------------------------------------
// Copyright 2012 (c) Silicon Laboratories Inc.
//
// SPDX-License-Identifier: Zlib
//
// This siHAL software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//------------------------------------------------------------------------------
//
// Script: 0.57
// Version: 1

#ifndef __SI32_VMON_A_REGISTERS_H__
#define __SI32_VMON_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_VMON_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // VREGIN Supply Monitor Enable
         volatile uint32_t VREGINSEN: 1;
         // VREGIN Low Interrupt Flag
         volatile uint32_t VREGINLI: 1;
         // VDD Reset Threshold Status Flag
         volatile uint32_t VDDRSTF: 1;
         // VDD Low Interrupt Flag
         volatile uint32_t VDDLI: 1;
         // VDD High Threshold Enable
         volatile uint32_t VDDHITHEN: 1;
                  uint32_t reserved0: 1;
         // VDD Low Interrupt Enable
         volatile uint32_t VDDLIEN: 1;
         // VREGIN Low Interrupt Enable
         volatile uint32_t VREGINLIEN: 1;
                  uint32_t reserved1: 23;
         // VDD Supply Monitor Enable
         volatile uint32_t VMONEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_VMON_A_CONTROL_VREGINSEN_MASK  0x00000001
#define SI32_VMON_A_CONTROL_VREGINSEN_SHIFT  0
// Disable the VREGIN supply monitor.
#define SI32_VMON_A_CONTROL_VREGINSEN_DISABLED_VALUE  0
#define SI32_VMON_A_CONTROL_VREGINSEN_DISABLED_U32 \
   (SI32_VMON_A_CONTROL_VREGINSEN_DISABLED_VALUE << SI32_VMON_A_CONTROL_VREGINSEN_SHIFT)
// Enable the VREGIN supply monitor.
#define SI32_VMON_A_CONTROL_VREGINSEN_ENABLED_VALUE  1
#define SI32_VMON_A_CONTROL_VREGINSEN_ENABLED_U32 \
   (SI32_VMON_A_CONTROL_VREGINSEN_ENABLED_VALUE << SI32_VMON_A_CONTROL_VREGINSEN_SHIFT)

#define SI32_VMON_A_CONTROL_VREGINLI_MASK  0x00000002
#define SI32_VMON_A_CONTROL_VREGINLI_SHIFT  1
// VREGIN is not above the interrupt threshold.
#define SI32_VMON_A_CONTROL_VREGINLI_VREGIN_IS_LOW_VALUE  0
#define SI32_VMON_A_CONTROL_VREGINLI_VREGIN_IS_LOW_U32 \
   (SI32_VMON_A_CONTROL_VREGINLI_VREGIN_IS_LOW_VALUE << SI32_VMON_A_CONTROL_VREGINLI_SHIFT)
// VREGIN is above the interrupt threshold.
#define SI32_VMON_A_CONTROL_VREGINLI_VREGIN_IS_OK_VALUE  1
#define SI32_VMON_A_CONTROL_VREGINLI_VREGIN_IS_OK_U32 \
   (SI32_VMON_A_CONTROL_VREGINLI_VREGIN_IS_OK_VALUE << SI32_VMON_A_CONTROL_VREGINLI_SHIFT)

#define SI32_VMON_A_CONTROL_VDDRSTF_MASK  0x00000004
#define SI32_VMON_A_CONTROL_VDDRSTF_SHIFT  2
// The VDD voltage is below the VDD reset threshold.
#define SI32_VMON_A_CONTROL_VDDRSTF_VDD_IS_BELOW_RESET_VALUE  0
#define SI32_VMON_A_CONTROL_VDDRSTF_VDD_IS_BELOW_RESET_U32 \
   (SI32_VMON_A_CONTROL_VDDRSTF_VDD_IS_BELOW_RESET_VALUE << SI32_VMON_A_CONTROL_VDDRSTF_SHIFT)
// The VDD voltage is above the VDD reset threshold.
#define SI32_VMON_A_CONTROL_VDDRSTF_VDD_IS_ABOVE_RESET_VALUE  1
#define SI32_VMON_A_CONTROL_VDDRSTF_VDD_IS_ABOVE_RESET_U32 \
   (SI32_VMON_A_CONTROL_VDDRSTF_VDD_IS_ABOVE_RESET_VALUE << SI32_VMON_A_CONTROL_VDDRSTF_SHIFT)

#define SI32_VMON_A_CONTROL_VDDLI_MASK  0x00000008
#define SI32_VMON_A_CONTROL_VDDLI_SHIFT  3
// The VDD voltage is below the early warning threshold.
#define SI32_VMON_A_CONTROL_VDDLI_VDD_IS_LOW_VALUE  0
#define SI32_VMON_A_CONTROL_VDDLI_VDD_IS_LOW_U32 \
   (SI32_VMON_A_CONTROL_VDDLI_VDD_IS_LOW_VALUE << SI32_VMON_A_CONTROL_VDDLI_SHIFT)
// The VDD voltage is above the early warning threshold.
#define SI32_VMON_A_CONTROL_VDDLI_VDD_IS_OK_VALUE  1
#define SI32_VMON_A_CONTROL_VDDLI_VDD_IS_OK_U32 \
   (SI32_VMON_A_CONTROL_VDDLI_VDD_IS_OK_VALUE << SI32_VMON_A_CONTROL_VDDLI_SHIFT)

#define SI32_VMON_A_CONTROL_VDDHITHEN_MASK  0x00000010
#define SI32_VMON_A_CONTROL_VDDHITHEN_SHIFT  4
// Use the standard VDD thresholds.
#define SI32_VMON_A_CONTROL_VDDHITHEN_DISABLED_VALUE  0
#define SI32_VMON_A_CONTROL_VDDHITHEN_DISABLED_U32 \
   (SI32_VMON_A_CONTROL_VDDHITHEN_DISABLED_VALUE << SI32_VMON_A_CONTROL_VDDHITHEN_SHIFT)
// Use the high VDD thresholds.
#define SI32_VMON_A_CONTROL_VDDHITHEN_ENABLED_VALUE  1
#define SI32_VMON_A_CONTROL_VDDHITHEN_ENABLED_U32 \
   (SI32_VMON_A_CONTROL_VDDHITHEN_ENABLED_VALUE << SI32_VMON_A_CONTROL_VDDHITHEN_SHIFT)

#define SI32_VMON_A_CONTROL_VDDLIEN_MASK  0x00000040
#define SI32_VMON_A_CONTROL_VDDLIEN_SHIFT  6
// Disable the VDD low interrupt.
#define SI32_VMON_A_CONTROL_VDDLIEN_DISABLED_VALUE  0
#define SI32_VMON_A_CONTROL_VDDLIEN_DISABLED_U32 \
   (SI32_VMON_A_CONTROL_VDDLIEN_DISABLED_VALUE << SI32_VMON_A_CONTROL_VDDLIEN_SHIFT)
// Enable the VDD low interrupt.
#define SI32_VMON_A_CONTROL_VDDLIEN_ENABLED_VALUE  1
#define SI32_VMON_A_CONTROL_VDDLIEN_ENABLED_U32 \
   (SI32_VMON_A_CONTROL_VDDLIEN_ENABLED_VALUE << SI32_VMON_A_CONTROL_VDDLIEN_SHIFT)

#define SI32_VMON_A_CONTROL_VREGINLIEN_MASK  0x00000080
#define SI32_VMON_A_CONTROL_VREGINLIEN_SHIFT  7
// Disable the VREGIN low interrupt.
#define SI32_VMON_A_CONTROL_VREGINLIEN_DISABLED_VALUE  0
#define SI32_VMON_A_CONTROL_VREGINLIEN_DISABLED_U32 \
   (SI32_VMON_A_CONTROL_VREGINLIEN_DISABLED_VALUE << SI32_VMON_A_CONTROL_VREGINLIEN_SHIFT)
// Enable the VREGIN low interrupt.
#define SI32_VMON_A_CONTROL_VREGINLIEN_ENABLED_VALUE  1
#define SI32_VMON_A_CONTROL_VREGINLIEN_ENABLED_U32 \
   (SI32_VMON_A_CONTROL_VREGINLIEN_ENABLED_VALUE << SI32_VMON_A_CONTROL_VREGINLIEN_SHIFT)

#define SI32_VMON_A_CONTROL_VMONEN_MASK  0x80000000
#define SI32_VMON_A_CONTROL_VMONEN_SHIFT  31
// Disable the VDD supply monitor.
#define SI32_VMON_A_CONTROL_VMONEN_DISABLED_VALUE  0U
#define SI32_VMON_A_CONTROL_VMONEN_DISABLED_U32 \
   (SI32_VMON_A_CONTROL_VMONEN_DISABLED_VALUE << SI32_VMON_A_CONTROL_VMONEN_SHIFT)
// Enable the VDD supply monitor.
#define SI32_VMON_A_CONTROL_VMONEN_ENABLED_VALUE  1U
#define SI32_VMON_A_CONTROL_VMONEN_ENABLED_U32 \
   (SI32_VMON_A_CONTROL_VMONEN_ENABLED_VALUE << SI32_VMON_A_CONTROL_VMONEN_SHIFT)



typedef struct SI32_VMON_A_Struct
{
   struct SI32_VMON_A_CONTROL_Struct               CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   uint32_t                                        reserved1[4];
} SI32_VMON_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_VMON_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

