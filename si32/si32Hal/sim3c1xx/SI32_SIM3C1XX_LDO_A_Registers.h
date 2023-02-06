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
// This file applies to the SIM3C1XX_LDO_A module
//
// Script: 0.57
// Version: 1

#ifndef __SI32_LDO_A_REGISTERS_H__
#define __SI32_LDO_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_LDO_A_CONTROL_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 1;
         // LDO Bias Current Selection
         volatile uint32_t LDOIBIAS: 1;
                  uint32_t reserved1: 29;
         // LDO Analog Enable
         volatile uint32_t LDOAEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LDO_A_CONTROL_LDOIBIAS_MASK  0x00000002
#define SI32_LDO_A_CONTROL_LDOIBIAS_SHIFT  1
// Select high bias.
#define SI32_LDO_A_CONTROL_LDOIBIAS_HIGHBIAS_VALUE  0
#define SI32_LDO_A_CONTROL_LDOIBIAS_HIGHBIAS_U32 \
   (SI32_LDO_A_CONTROL_LDOIBIAS_HIGHBIAS_VALUE << SI32_LDO_A_CONTROL_LDOIBIAS_SHIFT)
// Select low bias (AHB frequency <= 2.5 MHz).
#define SI32_LDO_A_CONTROL_LDOIBIAS_LOWBIAS_VALUE  1
#define SI32_LDO_A_CONTROL_LDOIBIAS_LOWBIAS_U32 \
   (SI32_LDO_A_CONTROL_LDOIBIAS_LOWBIAS_VALUE << SI32_LDO_A_CONTROL_LDOIBIAS_SHIFT)

#define SI32_LDO_A_CONTROL_LDOAEN_MASK  0x80000000
#define SI32_LDO_A_CONTROL_LDOAEN_SHIFT  31
// LDO0 analog output disabled.
#define SI32_LDO_A_CONTROL_LDOAEN_DISABLE_VALUE  0U
#define SI32_LDO_A_CONTROL_LDOAEN_DISABLE_U32 \
   (SI32_LDO_A_CONTROL_LDOAEN_DISABLE_VALUE << SI32_LDO_A_CONTROL_LDOAEN_SHIFT)
// LDO0 analog output enabled.
#define SI32_LDO_A_CONTROL_LDOAEN_ENABLE_VALUE  1U
#define SI32_LDO_A_CONTROL_LDOAEN_ENABLE_U32 \
   (SI32_LDO_A_CONTROL_LDOAEN_ENABLE_VALUE << SI32_LDO_A_CONTROL_LDOAEN_SHIFT)



typedef struct SI32_LDO_A_Struct
{
   struct SI32_LDO_A_CONTROL_Struct                CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
} SI32_LDO_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_LDO_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

