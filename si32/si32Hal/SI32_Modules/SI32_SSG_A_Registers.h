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

#ifndef __SI32_SSG_A_REGISTERS_H__
#define __SI32_SSG_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_SSG_A_CONFIG_Struct
{
   union
   {
      struct
      {
         // Pulse Generator Counter
         volatile uint32_t COUNT: 12;
         // Speed Select
         volatile uint32_t SSEL: 1;
         // Phase Generator Free-Run Enable
         volatile uint32_t PHGFREN: 1;
         // Pulse Generator Free-Run Enable
         volatile uint32_t PUGFREN: 1;
                  uint32_t reserved0: 17;
      };
      volatile uint32_t U32;
   };
};

#define SI32_SSG_A_CONFIG_COUNT_MASK  0x00000FFF
#define SI32_SSG_A_CONFIG_COUNT_SHIFT  0

#define SI32_SSG_A_CONFIG_SSEL_MASK  0x00001000
#define SI32_SSG_A_CONFIG_SSEL_SHIFT  12
// The SSG module runs at normal speed, where each pulse and phase cycle consists
// of 16 ADC clocks.
#define SI32_SSG_A_CONFIG_SSEL_NORMAL_VALUE  0
#define SI32_SSG_A_CONFIG_SSEL_NORMAL_U32 \
   (SI32_SSG_A_CONFIG_SSEL_NORMAL_VALUE << SI32_SSG_A_CONFIG_SSEL_SHIFT)
// The SSG module runs at double speed, where each pulse and phase cycle consists
// of 8 ADC clocks.
#define SI32_SSG_A_CONFIG_SSEL_DOUBLE_VALUE  1
#define SI32_SSG_A_CONFIG_SSEL_DOUBLE_U32 \
   (SI32_SSG_A_CONFIG_SSEL_DOUBLE_VALUE << SI32_SSG_A_CONFIG_SSEL_SHIFT)

#define SI32_SSG_A_CONFIG_PHGFREN_MASK  0x00002000
#define SI32_SSG_A_CONFIG_PHGFREN_SHIFT  13
// The Phase Generator runs only when pulse generation occurs.
#define SI32_SSG_A_CONFIG_PHGFREN_DISABLED_VALUE  0
#define SI32_SSG_A_CONFIG_PHGFREN_DISABLED_U32 \
   (SI32_SSG_A_CONFIG_PHGFREN_DISABLED_VALUE << SI32_SSG_A_CONFIG_PHGFREN_SHIFT)
// The Phase Generator runs when an ADC is enabled, regardless of the Pulse
// Generator settings.
#define SI32_SSG_A_CONFIG_PHGFREN_ENABLED_VALUE  1
#define SI32_SSG_A_CONFIG_PHGFREN_ENABLED_U32 \
   (SI32_SSG_A_CONFIG_PHGFREN_ENABLED_VALUE << SI32_SSG_A_CONFIG_PHGFREN_SHIFT)

#define SI32_SSG_A_CONFIG_PUGFREN_MASK  0x00004000
#define SI32_SSG_A_CONFIG_PUGFREN_SHIFT  14
// The COUNT field determines the number of pulses generated by the Pulse
// Generator.
#define SI32_SSG_A_CONFIG_PUGFREN_DISABLED_VALUE  0
#define SI32_SSG_A_CONFIG_PUGFREN_DISABLED_U32 \
   (SI32_SSG_A_CONFIG_PUGFREN_DISABLED_VALUE << SI32_SSG_A_CONFIG_PUGFREN_SHIFT)
// The Pulse Generator always generates pulses regardless of COUNT unless all
// outputs are disabled (EX0EN, EX1EN, EX2EN, and EX3EN are all 0).
#define SI32_SSG_A_CONFIG_PUGFREN_ENABLED_VALUE  1
#define SI32_SSG_A_CONFIG_PUGFREN_ENABLED_U32 \
   (SI32_SSG_A_CONFIG_PUGFREN_ENABLED_VALUE << SI32_SSG_A_CONFIG_PUGFREN_SHIFT)



struct SI32_SSG_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Output 0 Invert Enable
         volatile uint32_t EX0INVEN: 1;
         // Output 1 Invert Enable
         volatile uint32_t EX1INVEN: 1;
         // Output 2 Invert Enable
         volatile uint32_t EX2INVEN: 1;
         // Output 3 Invert Enable
         volatile uint32_t EX3INVEN: 1;
         // Output 0 Enable
         volatile uint32_t EX0EN: 1;
         // Output 1 Enable
         volatile uint32_t EX1EN: 1;
         // Output 2 Enable
         volatile uint32_t EX2EN: 1;
         // Output 3 Enable
         volatile uint32_t EX3EN: 1;
         // SSG Module Status
         volatile uint32_t STATUS: 1;
                  uint32_t reserved0: 23;
      };
      volatile uint32_t U32;
   };
};

#define SI32_SSG_A_CONTROL_EX0INVEN_MASK  0x00000001
#define SI32_SSG_A_CONTROL_EX0INVEN_SHIFT  0
// Do not invert the Pulse Generator output on EX0.
#define SI32_SSG_A_CONTROL_EX0INVEN_NORMAL_VALUE  0
#define SI32_SSG_A_CONTROL_EX0INVEN_NORMAL_U32 \
   (SI32_SSG_A_CONTROL_EX0INVEN_NORMAL_VALUE << SI32_SSG_A_CONTROL_EX0INVEN_SHIFT)
// Invert the Pulse Generator output on EX0.
#define SI32_SSG_A_CONTROL_EX0INVEN_INVERT_VALUE  1
#define SI32_SSG_A_CONTROL_EX0INVEN_INVERT_U32 \
   (SI32_SSG_A_CONTROL_EX0INVEN_INVERT_VALUE << SI32_SSG_A_CONTROL_EX0INVEN_SHIFT)

#define SI32_SSG_A_CONTROL_EX1INVEN_MASK  0x00000002
#define SI32_SSG_A_CONTROL_EX1INVEN_SHIFT  1
// Do not invert the Pulse Generator output on EX1.
#define SI32_SSG_A_CONTROL_EX1INVEN_NORMAL_VALUE  0
#define SI32_SSG_A_CONTROL_EX1INVEN_NORMAL_U32 \
   (SI32_SSG_A_CONTROL_EX1INVEN_NORMAL_VALUE << SI32_SSG_A_CONTROL_EX1INVEN_SHIFT)
// Invert the Pulse Generator output on EX1.
#define SI32_SSG_A_CONTROL_EX1INVEN_INVERT_VALUE  1
#define SI32_SSG_A_CONTROL_EX1INVEN_INVERT_U32 \
   (SI32_SSG_A_CONTROL_EX1INVEN_INVERT_VALUE << SI32_SSG_A_CONTROL_EX1INVEN_SHIFT)

#define SI32_SSG_A_CONTROL_EX2INVEN_MASK  0x00000004
#define SI32_SSG_A_CONTROL_EX2INVEN_SHIFT  2
// Do not invert the Pulse Generator output on EX2.
#define SI32_SSG_A_CONTROL_EX2INVEN_NORMAL_VALUE  0
#define SI32_SSG_A_CONTROL_EX2INVEN_NORMAL_U32 \
   (SI32_SSG_A_CONTROL_EX2INVEN_NORMAL_VALUE << SI32_SSG_A_CONTROL_EX2INVEN_SHIFT)
// Invert the Pulse Generator output on EX2.
#define SI32_SSG_A_CONTROL_EX2INVEN_INVERT_VALUE  1
#define SI32_SSG_A_CONTROL_EX2INVEN_INVERT_U32 \
   (SI32_SSG_A_CONTROL_EX2INVEN_INVERT_VALUE << SI32_SSG_A_CONTROL_EX2INVEN_SHIFT)

#define SI32_SSG_A_CONTROL_EX3INVEN_MASK  0x00000008
#define SI32_SSG_A_CONTROL_EX3INVEN_SHIFT  3
// Do not invert the Pulse Generator output on EX3.
#define SI32_SSG_A_CONTROL_EX3INVEN_NORMAL_VALUE  0
#define SI32_SSG_A_CONTROL_EX3INVEN_NORMAL_U32 \
   (SI32_SSG_A_CONTROL_EX3INVEN_NORMAL_VALUE << SI32_SSG_A_CONTROL_EX3INVEN_SHIFT)
// Invert the Pulse Generator output on EX3.
#define SI32_SSG_A_CONTROL_EX3INVEN_INVERT_VALUE  1
#define SI32_SSG_A_CONTROL_EX3INVEN_INVERT_U32 \
   (SI32_SSG_A_CONTROL_EX3INVEN_INVERT_VALUE << SI32_SSG_A_CONTROL_EX3INVEN_SHIFT)

#define SI32_SSG_A_CONTROL_EX0EN_MASK  0x00000010
#define SI32_SSG_A_CONTROL_EX0EN_SHIFT  4
// Disable the EX0 Pulse Generator output.
#define SI32_SSG_A_CONTROL_EX0EN_DISABLED_VALUE  0
#define SI32_SSG_A_CONTROL_EX0EN_DISABLED_U32 \
   (SI32_SSG_A_CONTROL_EX0EN_DISABLED_VALUE << SI32_SSG_A_CONTROL_EX0EN_SHIFT)
// Enable the EX0 Pulse Generator output.
#define SI32_SSG_A_CONTROL_EX0EN_ENABLED_VALUE  1
#define SI32_SSG_A_CONTROL_EX0EN_ENABLED_U32 \
   (SI32_SSG_A_CONTROL_EX0EN_ENABLED_VALUE << SI32_SSG_A_CONTROL_EX0EN_SHIFT)

#define SI32_SSG_A_CONTROL_EX1EN_MASK  0x00000020
#define SI32_SSG_A_CONTROL_EX1EN_SHIFT  5
// Disable the EX1 Pulse Generator output.
#define SI32_SSG_A_CONTROL_EX1EN_DISABLED_VALUE  0
#define SI32_SSG_A_CONTROL_EX1EN_DISABLED_U32 \
   (SI32_SSG_A_CONTROL_EX1EN_DISABLED_VALUE << SI32_SSG_A_CONTROL_EX1EN_SHIFT)
// Enable the EX1 Pulse Generator output.
#define SI32_SSG_A_CONTROL_EX1EN_ENABLED_VALUE  1
#define SI32_SSG_A_CONTROL_EX1EN_ENABLED_U32 \
   (SI32_SSG_A_CONTROL_EX1EN_ENABLED_VALUE << SI32_SSG_A_CONTROL_EX1EN_SHIFT)

#define SI32_SSG_A_CONTROL_EX2EN_MASK  0x00000040
#define SI32_SSG_A_CONTROL_EX2EN_SHIFT  6
// Disable the EX2 Pulse Generator output.
#define SI32_SSG_A_CONTROL_EX2EN_DISABLED_VALUE  0
#define SI32_SSG_A_CONTROL_EX2EN_DISABLED_U32 \
   (SI32_SSG_A_CONTROL_EX2EN_DISABLED_VALUE << SI32_SSG_A_CONTROL_EX2EN_SHIFT)
// Enable the EX2 Pulse Generator output.
#define SI32_SSG_A_CONTROL_EX2EN_ENABLED_VALUE  1
#define SI32_SSG_A_CONTROL_EX2EN_ENABLED_U32 \
   (SI32_SSG_A_CONTROL_EX2EN_ENABLED_VALUE << SI32_SSG_A_CONTROL_EX2EN_SHIFT)

#define SI32_SSG_A_CONTROL_EX3EN_MASK  0x00000080
#define SI32_SSG_A_CONTROL_EX3EN_SHIFT  7
// Disable the EX3 Pulse Generator output.
#define SI32_SSG_A_CONTROL_EX3EN_DISABLED_VALUE  0
#define SI32_SSG_A_CONTROL_EX3EN_DISABLED_U32 \
   (SI32_SSG_A_CONTROL_EX3EN_DISABLED_VALUE << SI32_SSG_A_CONTROL_EX3EN_SHIFT)
// Enable the EX3 Pulse Generator output.
#define SI32_SSG_A_CONTROL_EX3EN_ENABLED_VALUE  1
#define SI32_SSG_A_CONTROL_EX3EN_ENABLED_U32 \
   (SI32_SSG_A_CONTROL_EX3EN_ENABLED_VALUE << SI32_SSG_A_CONTROL_EX3EN_SHIFT)

#define SI32_SSG_A_CONTROL_STATUS_MASK  0x00000100
#define SI32_SSG_A_CONTROL_STATUS_SHIFT  8
// The SSG module is idle and the Pulse Generator is not operating.
#define SI32_SSG_A_CONTROL_STATUS_IDLE_VALUE  0
#define SI32_SSG_A_CONTROL_STATUS_IDLE_U32 \
   (SI32_SSG_A_CONTROL_STATUS_IDLE_VALUE << SI32_SSG_A_CONTROL_STATUS_SHIFT)
// The SSG module is active and the Pulse Generator is counting.
#define SI32_SSG_A_CONTROL_STATUS_ACTIVE_VALUE  1
#define SI32_SSG_A_CONTROL_STATUS_ACTIVE_U32 \
   (SI32_SSG_A_CONTROL_STATUS_ACTIVE_VALUE << SI32_SSG_A_CONTROL_STATUS_SHIFT)



typedef struct SI32_SSG_A_Struct
{
   struct SI32_SSG_A_CONFIG_Struct                 CONFIG         ; // Base Address + 0x0
   uint32_t                                        reserved0;
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   struct SI32_SSG_A_CONTROL_Struct                CONTROL        ; // Base Address + 0x10
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved3;
} SI32_SSG_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_SSG_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

