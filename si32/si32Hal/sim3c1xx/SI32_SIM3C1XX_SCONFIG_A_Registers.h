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
// This file applies to the SIM3C1XX_SCONFIG_A module
//
// Script: 0.57
// Version: 1

#ifndef __SI32_SCONFIG_A_REGISTERS_H__
#define __SI32_SCONFIG_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_SCONFIG_A_CONFIG_Struct
{
   union
   {
      struct
      {
         // Faster DMA Mode Enable
         volatile uint32_t FDMAEN: 1;
                  uint32_t reserved0: 31;
      };
      volatile uint32_t U32;
   };
};

#define SI32_SCONFIG_A_CONFIG_FDMAEN_MASK  0x00000001
#define SI32_SCONFIG_A_CONFIG_FDMAEN_SHIFT  0
// Disable the faster DMA mode.  The DMA module and channels will behave like a
// standard uDMA.
#define SI32_SCONFIG_A_CONFIG_FDMAEN_DISABLED_VALUE  0
#define SI32_SCONFIG_A_CONFIG_FDMAEN_DISABLED_U32 \
   (SI32_SCONFIG_A_CONFIG_FDMAEN_DISABLED_VALUE << SI32_SCONFIG_A_CONFIG_FDMAEN_SHIFT)
// Enable the faster DMA mode.
#define SI32_SCONFIG_A_CONFIG_FDMAEN_ENABLED_VALUE  1
#define SI32_SCONFIG_A_CONFIG_FDMAEN_ENABLED_U32 \
   (SI32_SCONFIG_A_CONFIG_FDMAEN_ENABLED_VALUE << SI32_SCONFIG_A_CONFIG_FDMAEN_SHIFT)



typedef struct SI32_SCONFIG_A_Struct
{
   struct SI32_SCONFIG_A_CONFIG_Struct             CONFIG         ; // Base Address + 0x0
   volatile uint32_t                               CONFIG_SET;
   volatile uint32_t                               CONFIG_CLR;
   uint32_t                                        reserved0;
} SI32_SCONFIG_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_SCONFIG_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

