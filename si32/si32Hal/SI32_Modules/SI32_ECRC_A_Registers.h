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
// Script: 0.61
// Version: 1

#ifndef __SI32_ECRC_A_REGISTERS_H__
#define __SI32_ECRC_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_ECRC_A_CONTROL_Struct
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
         volatile uint32_t POLYSEL: 1;
                  uint32_t reserved1: 3;
         // Byte Mode Enable
         volatile uint32_t BMDEN: 1;
         // Byte-Level Bit Reversal Enable
         volatile uint32_t BBREN: 1;
         // Input Processing Order
         volatile uint32_t ORDER: 2;
                  uint32_t reserved2: 1;
         // Automatic Seed Enable
         volatile uint32_t ASEEDEN: 1;
         // Automatic Seed Byte Select
         volatile uint32_t ASEEDSEL: 1;
                  uint32_t reserved3: 17;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ECRC_A_CONTROL_SINITEN_MASK  0x00000001
#define SI32_ECRC_A_CONTROL_SINITEN_SHIFT  0
// Do not initialize the CRC module to the value set by the SEED bit.
#define SI32_ECRC_A_CONTROL_SINITEN_DISABLED_VALUE  0
#define SI32_ECRC_A_CONTROL_SINITEN_DISABLED_U32 \
   (SI32_ECRC_A_CONTROL_SINITEN_DISABLED_VALUE << SI32_ECRC_A_CONTROL_SINITEN_SHIFT)
// Initialize the CRC module to the value set by the SEED bit.
#define SI32_ECRC_A_CONTROL_SINITEN_ENABLED_VALUE  1
#define SI32_ECRC_A_CONTROL_SINITEN_ENABLED_U32 \
   (SI32_ECRC_A_CONTROL_SINITEN_ENABLED_VALUE << SI32_ECRC_A_CONTROL_SINITEN_SHIFT)

#define SI32_ECRC_A_CONTROL_SEED_MASK  0x00000002
#define SI32_ECRC_A_CONTROL_SEED_SHIFT  1
// CRC seed value is all 0's (0x00000000)
#define SI32_ECRC_A_CONTROL_SEED_ALL_ZEROES_VALUE  0
#define SI32_ECRC_A_CONTROL_SEED_ALL_ZEROES_U32 \
   (SI32_ECRC_A_CONTROL_SEED_ALL_ZEROES_VALUE << SI32_ECRC_A_CONTROL_SEED_SHIFT)
// CRC seed value is all 1's (0xFFFFFFFF).
#define SI32_ECRC_A_CONTROL_SEED_ALL_ONES_VALUE  1
#define SI32_ECRC_A_CONTROL_SEED_ALL_ONES_U32 \
   (SI32_ECRC_A_CONTROL_SEED_ALL_ONES_VALUE << SI32_ECRC_A_CONTROL_SEED_SHIFT)

#define SI32_ECRC_A_CONTROL_CRCEN_MASK  0x00000004
#define SI32_ECRC_A_CONTROL_CRCEN_SHIFT  2
// Disable CRC operations.
#define SI32_ECRC_A_CONTROL_CRCEN_DISABLED_VALUE  0
#define SI32_ECRC_A_CONTROL_CRCEN_DISABLED_U32 \
   (SI32_ECRC_A_CONTROL_CRCEN_DISABLED_VALUE << SI32_ECRC_A_CONTROL_CRCEN_SHIFT)
// Enable CRC operations.
#define SI32_ECRC_A_CONTROL_CRCEN_ENABLED_VALUE  1
#define SI32_ECRC_A_CONTROL_CRCEN_ENABLED_U32 \
   (SI32_ECRC_A_CONTROL_CRCEN_ENABLED_VALUE << SI32_ECRC_A_CONTROL_CRCEN_SHIFT)

#define SI32_ECRC_A_CONTROL_POLYSEL_MASK  0x00000010
#define SI32_ECRC_A_CONTROL_POLYSEL_SHIFT  4
// Select the fixed 32-bit polynomial: 0x04C11DB7.
#define SI32_ECRC_A_CONTROL_POLYSEL_CRC32_FIXED_VALUE  0
#define SI32_ECRC_A_CONTROL_POLYSEL_CRC32_FIXED_U32 \
   (SI32_ECRC_A_CONTROL_POLYSEL_CRC32_FIXED_VALUE << SI32_ECRC_A_CONTROL_POLYSEL_SHIFT)
// Select the programmable 16-bit polynomial. The POLY register sets the polynomial
// coefficients.
#define SI32_ECRC_A_CONTROL_POLYSEL_CRC16_PROG_VALUE  1
#define SI32_ECRC_A_CONTROL_POLYSEL_CRC16_PROG_U32 \
   (SI32_ECRC_A_CONTROL_POLYSEL_CRC16_PROG_VALUE << SI32_ECRC_A_CONTROL_POLYSEL_SHIFT)

#define SI32_ECRC_A_CONTROL_BMDEN_MASK  0x00000100
#define SI32_ECRC_A_CONTROL_BMDEN_SHIFT  8
// Disable byte mode (word/byte width is determined automatically by the hardware).
#define SI32_ECRC_A_CONTROL_BMDEN_DISABLED_VALUE  0
#define SI32_ECRC_A_CONTROL_BMDEN_DISABLED_U32 \
   (SI32_ECRC_A_CONTROL_BMDEN_DISABLED_VALUE << SI32_ECRC_A_CONTROL_BMDEN_SHIFT)
// Enable byte mode (all writes are considered as bytes).
#define SI32_ECRC_A_CONTROL_BMDEN_ENABLED_VALUE  1
#define SI32_ECRC_A_CONTROL_BMDEN_ENABLED_U32 \
   (SI32_ECRC_A_CONTROL_BMDEN_ENABLED_VALUE << SI32_ECRC_A_CONTROL_BMDEN_SHIFT)

#define SI32_ECRC_A_CONTROL_BBREN_MASK  0x00000200
#define SI32_ECRC_A_CONTROL_BBREN_SHIFT  9
// No byte-level bit reversal (input is same order as written).
#define SI32_ECRC_A_CONTROL_BBREN_DISABLED_VALUE  0
#define SI32_ECRC_A_CONTROL_BBREN_DISABLED_U32 \
   (SI32_ECRC_A_CONTROL_BBREN_DISABLED_VALUE << SI32_ECRC_A_CONTROL_BBREN_SHIFT)
// Byte-level bit reversal enabled (the bits in each byte are reversed).
#define SI32_ECRC_A_CONTROL_BBREN_ENABLED_VALUE  1
#define SI32_ECRC_A_CONTROL_BBREN_ENABLED_U32 \
   (SI32_ECRC_A_CONTROL_BBREN_ENABLED_VALUE << SI32_ECRC_A_CONTROL_BBREN_SHIFT)

#define SI32_ECRC_A_CONTROL_ORDER_MASK  0x00000C00
#define SI32_ECRC_A_CONTROL_ORDER_SHIFT  10
// No byte reorientation (output is same order as input).
#define SI32_ECRC_A_CONTROL_ORDER_NO_REORDER_VALUE  0
#define SI32_ECRC_A_CONTROL_ORDER_NO_REORDER_U32 \
   (SI32_ECRC_A_CONTROL_ORDER_NO_REORDER_VALUE << SI32_ECRC_A_CONTROL_ORDER_SHIFT)
// Swap for 16-bit big endian order (input: B3 B2 B1 B0, output: B2 B3 B0 B1).
#define SI32_ECRC_A_CONTROL_ORDER_BIG_ENDIAN_16_VALUE  1
#define SI32_ECRC_A_CONTROL_ORDER_BIG_ENDIAN_16_U32 \
   (SI32_ECRC_A_CONTROL_ORDER_BIG_ENDIAN_16_VALUE << SI32_ECRC_A_CONTROL_ORDER_SHIFT)
// Swap for 32-bit big endian order (input: B3 B2 B1 B0, output: B0 B1 B2 B3).
#define SI32_ECRC_A_CONTROL_ORDER_BIG_ENDIAN_32_VALUE  2
#define SI32_ECRC_A_CONTROL_ORDER_BIG_ENDIAN_32_U32 \
   (SI32_ECRC_A_CONTROL_ORDER_BIG_ENDIAN_32_VALUE << SI32_ECRC_A_CONTROL_ORDER_SHIFT)

#define SI32_ECRC_A_CONTROL_ASEEDEN_MASK  0x00002000
#define SI32_ECRC_A_CONTROL_ASEEDEN_SHIFT  13
// Disable automatic seeding.
#define SI32_ECRC_A_CONTROL_ASEEDEN_DISABLED_VALUE  0
#define SI32_ECRC_A_CONTROL_ASEEDEN_DISABLED_U32 \
   (SI32_ECRC_A_CONTROL_ASEEDEN_DISABLED_VALUE << SI32_ECRC_A_CONTROL_ASEEDEN_SHIFT)
// Enable automatic seeding. Reading the byte of the DATA register selected by
// ASEEDSEL re-seeds the CRC result with the setting selected by SEED.
#define SI32_ECRC_A_CONTROL_ASEEDEN_ENABLED_VALUE  1
#define SI32_ECRC_A_CONTROL_ASEEDEN_ENABLED_U32 \
   (SI32_ECRC_A_CONTROL_ASEEDEN_ENABLED_VALUE << SI32_ECRC_A_CONTROL_ASEEDEN_SHIFT)

#define SI32_ECRC_A_CONTROL_ASEEDSEL_MASK  0x00004000
#define SI32_ECRC_A_CONTROL_ASEEDSEL_SHIFT  14
// Select a read of the least-significant byte ([7:0]) of DATA, RDATA or BRDATA for
// automatic re-seeding.
#define SI32_ECRC_A_CONTROL_ASEEDSEL_LSB_READ_VALUE  0
#define SI32_ECRC_A_CONTROL_ASEEDSEL_LSB_READ_U32 \
   (SI32_ECRC_A_CONTROL_ASEEDSEL_LSB_READ_VALUE << SI32_ECRC_A_CONTROL_ASEEDSEL_SHIFT)
// Select a read of the most-significant byte [31:24] for 32-bit operations, and
// [15:8] for 16-bit operations) of DATA, RDATA or BRDATA for automatic re-seeding.
#define SI32_ECRC_A_CONTROL_ASEEDSEL_MSB_READ_VALUE  1
#define SI32_ECRC_A_CONTROL_ASEEDSEL_MSB_READ_U32 \
   (SI32_ECRC_A_CONTROL_ASEEDSEL_MSB_READ_VALUE << SI32_ECRC_A_CONTROL_ASEEDSEL_SHIFT)



struct SI32_ECRC_A_POLY_Struct
{
   union
   {
      struct
      {
         // 16-bit Programmable Polynomial
         volatile uint16_t POLY_BITS;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ECRC_A_POLY_POLY_MASK  0x0000FFFF
#define SI32_ECRC_A_POLY_POLY_SHIFT  0



struct SI32_ECRC_A_DATA_Struct
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

#define SI32_ECRC_A_DATA_DATA_MASK  0xFFFFFFFF
#define SI32_ECRC_A_DATA_DATA_SHIFT  0



struct SI32_ECRC_A_RDATA_Struct
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

#define SI32_ECRC_A_RDATA_RDATA_MASK  0xFFFFFFFF
#define SI32_ECRC_A_RDATA_RDATA_SHIFT  0



struct SI32_ECRC_A_BRDATA_Struct
{
   union
   {
      struct
      {
         // Byte-Reversed Output Data
         volatile uint32_t BRDATA_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ECRC_A_BRDATA_BRDATA_MASK  0xFFFFFFFF
#define SI32_ECRC_A_BRDATA_BRDATA_SHIFT  0



struct SI32_ECRC_A_SCONTROL_Struct
{
   union
   {
      struct
      {
         // Snooping Enable
         volatile uint32_t SEN: 1;
         // Snooping Direction Select
         volatile uint32_t SDIRSEL: 1;
                  uint32_t reserved0: 2;
         // Snooping Peripheral Select
         volatile uint32_t SPERISEL: 4;
                  uint32_t reserved1: 10;
         // Snooping Address
         volatile uint32_t SADDR: 10;
                  uint32_t reserved2: 4;
      };
      volatile uint32_t U32;
   };
};

#define SI32_ECRC_A_SCONTROL_SEN_MASK  0x00000001
#define SI32_ECRC_A_SCONTROL_SEN_SHIFT  0
// Disable automatic bus snooping.
#define SI32_ECRC_A_SCONTROL_SEN_DISABLED_VALUE  0
#define SI32_ECRC_A_SCONTROL_SEN_DISABLED_U32 \
   (SI32_ECRC_A_SCONTROL_SEN_DISABLED_VALUE << SI32_ECRC_A_SCONTROL_SEN_SHIFT)
// Enable automatic bus snooping.
#define SI32_ECRC_A_SCONTROL_SEN_ENABLED_VALUE  1
#define SI32_ECRC_A_SCONTROL_SEN_ENABLED_U32 \
   (SI32_ECRC_A_SCONTROL_SEN_ENABLED_VALUE << SI32_ECRC_A_SCONTROL_SEN_SHIFT)

#define SI32_ECRC_A_SCONTROL_SDIRSEL_MASK  0x00000002
#define SI32_ECRC_A_SCONTROL_SDIRSEL_SHIFT  1
// ECRC will snoop writes to the selected peripheral.
#define SI32_ECRC_A_SCONTROL_SDIRSEL_WRITES_VALUE  0
#define SI32_ECRC_A_SCONTROL_SDIRSEL_WRITES_U32 \
   (SI32_ECRC_A_SCONTROL_SDIRSEL_WRITES_VALUE << SI32_ECRC_A_SCONTROL_SDIRSEL_SHIFT)
// ECRC will snoop reads from the selected peripheral.
#define SI32_ECRC_A_SCONTROL_SDIRSEL_READS_VALUE  1
#define SI32_ECRC_A_SCONTROL_SDIRSEL_READS_U32 \
   (SI32_ECRC_A_SCONTROL_SDIRSEL_READS_VALUE << SI32_ECRC_A_SCONTROL_SDIRSEL_SHIFT)

#define SI32_ECRC_A_SCONTROL_SPERISEL_MASK  0x000000F0
#define SI32_ECRC_A_SCONTROL_SPERISEL_SHIFT  4

#define SI32_ECRC_A_SCONTROL_SADDR_MASK  0x0FFC0000
#define SI32_ECRC_A_SCONTROL_SADDR_SHIFT  18



typedef struct SI32_ECRC_A_Struct
{
   struct SI32_ECRC_A_CONTROL_Struct               CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_ECRC_A_POLY_Struct                  POLY           ; // Base Address + 0x10
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   struct SI32_ECRC_A_DATA_Struct                  DATA           ; // Base Address + 0x20
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   struct SI32_ECRC_A_RDATA_Struct                 RDATA          ; // Base Address + 0x30
   uint32_t                                        reserved7;
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   struct SI32_ECRC_A_BRDATA_Struct                BRDATA         ; // Base Address + 0x40
   uint32_t                                        reserved10;
   uint32_t                                        reserved11;
   uint32_t                                        reserved12;
   struct SI32_ECRC_A_SCONTROL_Struct              SCONTROL       ; // Base Address + 0x50
   volatile uint32_t                               SCONTROL_SET;
   volatile uint32_t                               SCONTROL_CLR;
   uint32_t                                        reserved13;
} SI32_ECRC_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_ECRC_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

