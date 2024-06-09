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

#ifndef __SI32_CRC_A_REGISTERS_H__
#define __SI32_CRC_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_CRC_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Seed Initialization Enable
         volatile uint32_t SINITEN: 1;
         // Seed Setting
         volatile uint32_t SEED: 1;
         // CRC Enable
         volatile uint32_t CRCEN: 1;
                  uint32_t reserved0: 1;
         // Polynomial Selection
         volatile uint32_t POLYSEL: 2;
                  uint32_t reserved1: 2;
         // Byte Mode Enable
         volatile uint32_t BMDEN: 1;
         // Byte-Level Bit Reversal Enable
         volatile uint32_t BBREN: 1;
         // Input Processing Order
         volatile uint32_t ORDER: 2;
                  uint32_t reserved2: 20;
      };
      volatile uint32_t U32;
   };
};

#define SI32_CRC_A_CONTROL_SINITEN_MASK  0x00000001
#define SI32_CRC_A_CONTROL_SINITEN_SHIFT  0
// Do not initialize the CRC module to the value set by the SEED bit.
#define SI32_CRC_A_CONTROL_SINITEN_DISABLED_VALUE  0
#define SI32_CRC_A_CONTROL_SINITEN_DISABLED_U32 \
   (SI32_CRC_A_CONTROL_SINITEN_DISABLED_VALUE << SI32_CRC_A_CONTROL_SINITEN_SHIFT)
// Initialize the CRC module to the value set by the SEED bit.
#define SI32_CRC_A_CONTROL_SINITEN_ENABLED_VALUE  1
#define SI32_CRC_A_CONTROL_SINITEN_ENABLED_U32 \
   (SI32_CRC_A_CONTROL_SINITEN_ENABLED_VALUE << SI32_CRC_A_CONTROL_SINITEN_SHIFT)

#define SI32_CRC_A_CONTROL_SEED_MASK  0x00000002
#define SI32_CRC_A_CONTROL_SEED_SHIFT  1
// CRC seed value is all 0's (0x00000000)
#define SI32_CRC_A_CONTROL_SEED_ALL_ZEROES_VALUE  0
#define SI32_CRC_A_CONTROL_SEED_ALL_ZEROES_U32 \
   (SI32_CRC_A_CONTROL_SEED_ALL_ZEROES_VALUE << SI32_CRC_A_CONTROL_SEED_SHIFT)
// CRC seed value is all 1's (0xFFFFFFFF).
#define SI32_CRC_A_CONTROL_SEED_ALL_ONES_VALUE  1
#define SI32_CRC_A_CONTROL_SEED_ALL_ONES_U32 \
   (SI32_CRC_A_CONTROL_SEED_ALL_ONES_VALUE << SI32_CRC_A_CONTROL_SEED_SHIFT)

#define SI32_CRC_A_CONTROL_CRCEN_MASK  0x00000004
#define SI32_CRC_A_CONTROL_CRCEN_SHIFT  2
// Disable CRC operations.
#define SI32_CRC_A_CONTROL_CRCEN_DISABLED_VALUE  0
#define SI32_CRC_A_CONTROL_CRCEN_DISABLED_U32 \
   (SI32_CRC_A_CONTROL_CRCEN_DISABLED_VALUE << SI32_CRC_A_CONTROL_CRCEN_SHIFT)
// Enable CRC operations.
#define SI32_CRC_A_CONTROL_CRCEN_ENABLED_VALUE  1
#define SI32_CRC_A_CONTROL_CRCEN_ENABLED_U32 \
   (SI32_CRC_A_CONTROL_CRCEN_ENABLED_VALUE << SI32_CRC_A_CONTROL_CRCEN_SHIFT)

#define SI32_CRC_A_CONTROL_POLYSEL_MASK  0x00000030
#define SI32_CRC_A_CONTROL_POLYSEL_SHIFT  4
// Select 32-bit polynomial: 0x04C11DB7.
#define SI32_CRC_A_CONTROL_POLYSEL_CRC_32_04C11DB7_VALUE  0
#define SI32_CRC_A_CONTROL_POLYSEL_CRC_32_04C11DB7_U32 \
   (SI32_CRC_A_CONTROL_POLYSEL_CRC_32_04C11DB7_VALUE << SI32_CRC_A_CONTROL_POLYSEL_SHIFT)
// Select 16-bit polynomial: 0x1021.
#define SI32_CRC_A_CONTROL_POLYSEL_CRC_16_1021_VALUE  1
#define SI32_CRC_A_CONTROL_POLYSEL_CRC_16_1021_U32 \
   (SI32_CRC_A_CONTROL_POLYSEL_CRC_16_1021_VALUE << SI32_CRC_A_CONTROL_POLYSEL_SHIFT)
// Select 16-bit polynomial: 0x3D65.
#define SI32_CRC_A_CONTROL_POLYSEL_CRC_16_3D65_VALUE  2
#define SI32_CRC_A_CONTROL_POLYSEL_CRC_16_3D65_U32 \
   (SI32_CRC_A_CONTROL_POLYSEL_CRC_16_3D65_VALUE << SI32_CRC_A_CONTROL_POLYSEL_SHIFT)
// Select 16-bit polynomial: 0x8005.
#define SI32_CRC_A_CONTROL_POLYSEL_CRC_16_8005_VALUE  3
#define SI32_CRC_A_CONTROL_POLYSEL_CRC_16_8005_U32 \
   (SI32_CRC_A_CONTROL_POLYSEL_CRC_16_8005_VALUE << SI32_CRC_A_CONTROL_POLYSEL_SHIFT)

#define SI32_CRC_A_CONTROL_BMDEN_MASK  0x00000100
#define SI32_CRC_A_CONTROL_BMDEN_SHIFT  8
// Disable byte mode (word/byte width is determined automatically by the hardware).
#define SI32_CRC_A_CONTROL_BMDEN_DISABLED_VALUE  0
#define SI32_CRC_A_CONTROL_BMDEN_DISABLED_U32 \
   (SI32_CRC_A_CONTROL_BMDEN_DISABLED_VALUE << SI32_CRC_A_CONTROL_BMDEN_SHIFT)
// Enable byte mode (all writes are considered as bytes).
#define SI32_CRC_A_CONTROL_BMDEN_ENABLED_VALUE  1
#define SI32_CRC_A_CONTROL_BMDEN_ENABLED_U32 \
   (SI32_CRC_A_CONTROL_BMDEN_ENABLED_VALUE << SI32_CRC_A_CONTROL_BMDEN_SHIFT)

#define SI32_CRC_A_CONTROL_BBREN_MASK  0x00000200
#define SI32_CRC_A_CONTROL_BBREN_SHIFT  9
// No byte-level bit reversal (input is same order as written).
#define SI32_CRC_A_CONTROL_BBREN_DISABLED_VALUE  0
#define SI32_CRC_A_CONTROL_BBREN_DISABLED_U32 \
   (SI32_CRC_A_CONTROL_BBREN_DISABLED_VALUE << SI32_CRC_A_CONTROL_BBREN_SHIFT)
// Byte-level bit reversal enabled (the bits in each byte are reversed).
#define SI32_CRC_A_CONTROL_BBREN_ENABLED_VALUE  1
#define SI32_CRC_A_CONTROL_BBREN_ENABLED_U32 \
   (SI32_CRC_A_CONTROL_BBREN_ENABLED_VALUE << SI32_CRC_A_CONTROL_BBREN_SHIFT)

#define SI32_CRC_A_CONTROL_ORDER_MASK  0x00000C00
#define SI32_CRC_A_CONTROL_ORDER_SHIFT  10
// No byte reorientation (output is same order as input).
#define SI32_CRC_A_CONTROL_ORDER_NO_REORDER_VALUE  0
#define SI32_CRC_A_CONTROL_ORDER_NO_REORDER_U32 \
   (SI32_CRC_A_CONTROL_ORDER_NO_REORDER_VALUE << SI32_CRC_A_CONTROL_ORDER_SHIFT)
// Swap for 16-bit big endian order (input: B3 B2 B1 B0, output: B2 B3 B0 B1).
#define SI32_CRC_A_CONTROL_ORDER_BIG_ENDIAN_16_VALUE  1
#define SI32_CRC_A_CONTROL_ORDER_BIG_ENDIAN_16_U32 \
   (SI32_CRC_A_CONTROL_ORDER_BIG_ENDIAN_16_VALUE << SI32_CRC_A_CONTROL_ORDER_SHIFT)
// Swap for 32-bit big endian order (input: B3 B2 B1 B0, output: B0 B1 B2 B3).
#define SI32_CRC_A_CONTROL_ORDER_BIG_ENDIAN_32_VALUE  2
#define SI32_CRC_A_CONTROL_ORDER_BIG_ENDIAN_32_U32 \
   (SI32_CRC_A_CONTROL_ORDER_BIG_ENDIAN_32_VALUE << SI32_CRC_A_CONTROL_ORDER_SHIFT)



struct SI32_CRC_A_DATA_Struct
{
   union
   {
      struct
      {
         // Input/Result Data
         volatile uint32_t DATA_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_CRC_A_DATA_DATA_MASK  0xFFFFFFFF
#define SI32_CRC_A_DATA_DATA_SHIFT  0



struct SI32_CRC_A_RDATA_Struct
{
   union
   {
      struct
      {
         // Bit-Reversed Output Data
         volatile uint32_t RDATA_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_CRC_A_RDATA_RDATA_MASK  0xFFFFFFFF
#define SI32_CRC_A_RDATA_RDATA_SHIFT  0



typedef struct SI32_CRC_A_Struct
{
   struct SI32_CRC_A_CONTROL_Struct                CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_CRC_A_DATA_Struct                   DATA           ; // Base Address + 0x10
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   struct SI32_CRC_A_RDATA_Struct                  RDATA          ; // Base Address + 0x20
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
} SI32_CRC_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_CRC_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

