//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
//
// This file applies to the SIM3L1XX_PBGP_A module
//
// Script: 0.61
// Version: 1

#ifndef __SI32_PBGP_A_REGISTERS_H__
#define __SI32_PBGP_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_PBGP_A_PB_Struct
{
   union
   {
      struct
      {
         // Output Latch
         volatile uint16_t PB_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBGP_A_PB_PB_MASK  0x0000FFFF
#define SI32_PBGP_A_PB_PB_SHIFT  0



struct SI32_PBGP_A_PBPIN_Struct
{
   union
   {
      struct
      {
         // Pin Value
         volatile uint16_t PBPIN_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBGP_A_PBPIN_PBPIN_MASK  0x0000FFFF
#define SI32_PBGP_A_PBPIN_PBPIN_SHIFT  0



struct SI32_PBGP_A_PBMDSEL_Struct
{
   union
   {
      struct
      {
         // Mode Select
         volatile uint16_t PBMDSEL_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBGP_A_PBMDSEL_PBMDSEL_MASK  0x0000FFFF
#define SI32_PBGP_A_PBMDSEL_PBMDSEL_SHIFT  0



struct SI32_PBGP_A_PBOUTMD_Struct
{
   union
   {
      struct
      {
         // Output Mode
         volatile uint16_t PBOUTMD_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBGP_A_PBOUTMD_PBOUTMD_MASK  0x0000FFFF
#define SI32_PBGP_A_PBOUTMD_PBOUTMD_SHIFT  0



struct SI32_PBGP_A_PBDRV_Struct
{
   union
   {
      struct
      {
         // Drive Strength
         volatile uint16_t PBDRV_BITS;
         // Port Bank Weak Pull-up Enable
         volatile uint32_t PBPUEN: 1;
                  uint32_t reserved0: 15;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBGP_A_PBDRV_PBDRV_MASK  0x0000FFFF
#define SI32_PBGP_A_PBDRV_PBDRV_SHIFT  0

#define SI32_PBGP_A_PBDRV_PBPUEN_MASK  0x00010000
#define SI32_PBGP_A_PBDRV_PBPUEN_SHIFT  16
// Disable weak pull-ups for this port.
#define SI32_PBGP_A_PBDRV_PBPUEN_DISABLED_VALUE  0
#define SI32_PBGP_A_PBDRV_PBPUEN_DISABLED_U32 \
   (SI32_PBGP_A_PBDRV_PBPUEN_DISABLED_VALUE << SI32_PBGP_A_PBDRV_PBPUEN_SHIFT)
// Enable weak pull-ups for this port.
#define SI32_PBGP_A_PBDRV_PBPUEN_ENABLED_VALUE  1
#define SI32_PBGP_A_PBDRV_PBPUEN_ENABLED_U32 \
   (SI32_PBGP_A_PBDRV_PBPUEN_ENABLED_VALUE << SI32_PBGP_A_PBDRV_PBPUEN_SHIFT)



struct SI32_PBGP_A_PM_Struct
{
   union
   {
      struct
      {
         // Port Match Value
         volatile uint16_t PM_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBGP_A_PM_PM_MASK  0x0000FFFF
#define SI32_PBGP_A_PM_PM_SHIFT  0



struct SI32_PBGP_A_PMEN_Struct
{
   union
   {
      struct
      {
         // Port Match Enable
         volatile uint16_t PMEN_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_PBGP_A_PMEN_PMEN_MASK  0x0000FFFF
#define SI32_PBGP_A_PMEN_PMEN_SHIFT  0



typedef struct SI32_PBGP_A_Struct
{
   struct SI32_PBGP_A_PB_Struct                    PB             ; // Base Address + 0x0
   volatile uint32_t                               PB_SET;
   volatile uint32_t                               PB_CLR;
   volatile uint32_t                               PB_MSK;
   struct SI32_PBGP_A_PBPIN_Struct                 PBPIN          ; // Base Address + 0x10
   uint32_t                                        reserved0;
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   struct SI32_PBGP_A_PBMDSEL_Struct               PBMDSEL        ; // Base Address + 0x20
   volatile uint32_t                               PBMDSEL_SET;
   volatile uint32_t                               PBMDSEL_CLR;
   uint32_t                                        reserved3;
   struct SI32_PBGP_A_PBOUTMD_Struct               PBOUTMD        ; // Base Address + 0x30
   volatile uint32_t                               PBOUTMD_SET;
   volatile uint32_t                               PBOUTMD_CLR;
   uint32_t                                        reserved4;
   struct SI32_PBGP_A_PBDRV_Struct                 PBDRV          ; // Base Address + 0x40
   volatile uint32_t                               PBDRV_SET;
   volatile uint32_t                               PBDRV_CLR;
   uint32_t                                        reserved5;
   struct SI32_PBGP_A_PM_Struct                    PM             ; // Base Address + 0x50
   volatile uint32_t                               PM_SET;
   volatile uint32_t                               PM_CLR;
   uint32_t                                        reserved6;
   struct SI32_PBGP_A_PMEN_Struct                  PMEN           ; // Base Address + 0x60
   volatile uint32_t                               PMEN_SET;
   volatile uint32_t                               PMEN_CLR;
   uint32_t                                        reserved7;
} SI32_PBGP_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_PBGP_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

