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

#ifndef __SI32_IVC_A_REGISTERS_H__
#define __SI32_IVC_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_IVC_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Input 0 Range
         volatile uint32_t IN0RANGE: 3;
                  uint32_t reserved0: 1;
         // Input 1 Range
         volatile uint32_t IN1RANGE: 3;
                  uint32_t reserved1: 23;
         // Converter 0 Enable
         volatile uint32_t C0EN: 1;
         // Converter 1 Enable
         volatile uint32_t C1EN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_IVC_A_CONTROL_IN0RANGE_MASK  0x00000007
#define SI32_IVC_A_CONTROL_IN0RANGE_SHIFT  0
// Input range is 0-6 mA.
#define SI32_IVC_A_CONTROL_IN0RANGE_6_MA_VALUE  0
#define SI32_IVC_A_CONTROL_IN0RANGE_6_MA_U32 \
   (SI32_IVC_A_CONTROL_IN0RANGE_6_MA_VALUE << SI32_IVC_A_CONTROL_IN0RANGE_SHIFT)
// Input range is 0-5 mA.
#define SI32_IVC_A_CONTROL_IN0RANGE_5_MA_VALUE  1
#define SI32_IVC_A_CONTROL_IN0RANGE_5_MA_U32 \
   (SI32_IVC_A_CONTROL_IN0RANGE_5_MA_VALUE << SI32_IVC_A_CONTROL_IN0RANGE_SHIFT)
// Input range is 0-4 mA.
#define SI32_IVC_A_CONTROL_IN0RANGE_4_MA_VALUE  2
#define SI32_IVC_A_CONTROL_IN0RANGE_4_MA_U32 \
   (SI32_IVC_A_CONTROL_IN0RANGE_4_MA_VALUE << SI32_IVC_A_CONTROL_IN0RANGE_SHIFT)
// Input range is 0-3 mA.
#define SI32_IVC_A_CONTROL_IN0RANGE_3_MA_VALUE  3
#define SI32_IVC_A_CONTROL_IN0RANGE_3_MA_U32 \
   (SI32_IVC_A_CONTROL_IN0RANGE_3_MA_VALUE << SI32_IVC_A_CONTROL_IN0RANGE_SHIFT)
// Input range is 0-2 mA.
#define SI32_IVC_A_CONTROL_IN0RANGE_2_MA_VALUE  4
#define SI32_IVC_A_CONTROL_IN0RANGE_2_MA_U32 \
   (SI32_IVC_A_CONTROL_IN0RANGE_2_MA_VALUE << SI32_IVC_A_CONTROL_IN0RANGE_SHIFT)
// Input range is 0-1 mA.
#define SI32_IVC_A_CONTROL_IN0RANGE_1_MA_VALUE  5
#define SI32_IVC_A_CONTROL_IN0RANGE_1_MA_U32 \
   (SI32_IVC_A_CONTROL_IN0RANGE_1_MA_VALUE << SI32_IVC_A_CONTROL_IN0RANGE_SHIFT)

#define SI32_IVC_A_CONTROL_IN1RANGE_MASK  0x00000070
#define SI32_IVC_A_CONTROL_IN1RANGE_SHIFT  4
// Input range is 0-6 mA.
#define SI32_IVC_A_CONTROL_IN1RANGE_6_MA_VALUE  0
#define SI32_IVC_A_CONTROL_IN1RANGE_6_MA_U32 \
   (SI32_IVC_A_CONTROL_IN1RANGE_6_MA_VALUE << SI32_IVC_A_CONTROL_IN1RANGE_SHIFT)
// Input range is 0-5 mA.
#define SI32_IVC_A_CONTROL_IN1RANGE_5_MA_VALUE  1
#define SI32_IVC_A_CONTROL_IN1RANGE_5_MA_U32 \
   (SI32_IVC_A_CONTROL_IN1RANGE_5_MA_VALUE << SI32_IVC_A_CONTROL_IN1RANGE_SHIFT)
// Input range is 0-4 mA.
#define SI32_IVC_A_CONTROL_IN1RANGE_4_MA_VALUE  2
#define SI32_IVC_A_CONTROL_IN1RANGE_4_MA_U32 \
   (SI32_IVC_A_CONTROL_IN1RANGE_4_MA_VALUE << SI32_IVC_A_CONTROL_IN1RANGE_SHIFT)
// Input range is 0-3 mA.
#define SI32_IVC_A_CONTROL_IN1RANGE_3_MA_VALUE  3
#define SI32_IVC_A_CONTROL_IN1RANGE_3_MA_U32 \
   (SI32_IVC_A_CONTROL_IN1RANGE_3_MA_VALUE << SI32_IVC_A_CONTROL_IN1RANGE_SHIFT)
// Input range is 0-2 mA.
#define SI32_IVC_A_CONTROL_IN1RANGE_2_MA_VALUE  4
#define SI32_IVC_A_CONTROL_IN1RANGE_2_MA_U32 \
   (SI32_IVC_A_CONTROL_IN1RANGE_2_MA_VALUE << SI32_IVC_A_CONTROL_IN1RANGE_SHIFT)
// Input range is 0-1 mA.
#define SI32_IVC_A_CONTROL_IN1RANGE_1_MA_VALUE  5
#define SI32_IVC_A_CONTROL_IN1RANGE_1_MA_U32 \
   (SI32_IVC_A_CONTROL_IN1RANGE_1_MA_VALUE << SI32_IVC_A_CONTROL_IN1RANGE_SHIFT)

#define SI32_IVC_A_CONTROL_C0EN_MASK  0x40000000
#define SI32_IVC_A_CONTROL_C0EN_SHIFT  30
// Disable IVC channel 0.
#define SI32_IVC_A_CONTROL_C0EN_DISABLED_VALUE  0
#define SI32_IVC_A_CONTROL_C0EN_DISABLED_U32 \
   (SI32_IVC_A_CONTROL_C0EN_DISABLED_VALUE << SI32_IVC_A_CONTROL_C0EN_SHIFT)
// Enable IVC channel 0.
#define SI32_IVC_A_CONTROL_C0EN_ENABLED_VALUE  1
#define SI32_IVC_A_CONTROL_C0EN_ENABLED_U32 \
   (SI32_IVC_A_CONTROL_C0EN_ENABLED_VALUE << SI32_IVC_A_CONTROL_C0EN_SHIFT)

#define SI32_IVC_A_CONTROL_C1EN_MASK  0x80000000
#define SI32_IVC_A_CONTROL_C1EN_SHIFT  31
// Disable IVC channel 1.
#define SI32_IVC_A_CONTROL_C1EN_DISABLED_VALUE  0U
#define SI32_IVC_A_CONTROL_C1EN_DISABLED_U32 \
   (SI32_IVC_A_CONTROL_C1EN_DISABLED_VALUE << SI32_IVC_A_CONTROL_C1EN_SHIFT)
// Enable IVC channel 1.
#define SI32_IVC_A_CONTROL_C1EN_ENABLED_VALUE  1U
#define SI32_IVC_A_CONTROL_C1EN_ENABLED_U32 \
   (SI32_IVC_A_CONTROL_C1EN_ENABLED_VALUE << SI32_IVC_A_CONTROL_C1EN_SHIFT)



typedef struct SI32_IVC_A_Struct
{
   struct SI32_IVC_A_CONTROL_Struct                CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   uint32_t                                        reserved1[4];
} SI32_IVC_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_IVC_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

