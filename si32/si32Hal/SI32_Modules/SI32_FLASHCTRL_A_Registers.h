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

#ifndef __SI32_FLASHCTRL_A_REGISTERS_H__
#define __SI32_FLASHCTRL_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_FLASHCTRL_A_CONFIG_Struct
{
   union
   {
      struct
      {
         // Flash Speed Mode
         volatile uint32_t SPMD: 2;
                  uint32_t reserved0: 2;
         // Read Store Mode Enable
         volatile uint32_t RDSEN: 1;
                  uint32_t reserved1: 1;
         // Data Prefetch Enable
         volatile uint32_t DPFEN: 1;
         // Prefetch Inhibit
         volatile uint32_t PFINH: 1;
                  uint32_t reserved2: 8;
         // Flash Write Sequence Enable
         volatile uint32_t SQWEN: 1;
                  uint32_t reserved3: 1;
         // Flash Page Erase Enable
         volatile uint32_t ERASEEN: 1;
         // Flash Buffer Status
         volatile uint32_t BUFSTS: 1;
         // Flash Operation Busy Flag
         volatile uint32_t BUSYF: 1;
                  uint32_t reserved4: 11;
      };
      volatile uint32_t U32;
   };
};

#define SI32_FLASHCTRL_A_CONFIG_SPMD_MASK  0x00000003
#define SI32_FLASHCTRL_A_CONFIG_SPMD_SHIFT  0
// Read and write the flash at speed mode 0.
#define SI32_FLASHCTRL_A_CONFIG_SPMD_MODE0_VALUE  0
#define SI32_FLASHCTRL_A_CONFIG_SPMD_MODE0_U32 \
   (SI32_FLASHCTRL_A_CONFIG_SPMD_MODE0_VALUE << SI32_FLASHCTRL_A_CONFIG_SPMD_SHIFT)
// Read and write the flash at speed mode 1.
#define SI32_FLASHCTRL_A_CONFIG_SPMD_MODE1_VALUE  1
#define SI32_FLASHCTRL_A_CONFIG_SPMD_MODE1_U32 \
   (SI32_FLASHCTRL_A_CONFIG_SPMD_MODE1_VALUE << SI32_FLASHCTRL_A_CONFIG_SPMD_SHIFT)
// Read and write the flash at speed mode 2.
#define SI32_FLASHCTRL_A_CONFIG_SPMD_MODE2_VALUE  2
#define SI32_FLASHCTRL_A_CONFIG_SPMD_MODE2_U32 \
   (SI32_FLASHCTRL_A_CONFIG_SPMD_MODE2_VALUE << SI32_FLASHCTRL_A_CONFIG_SPMD_SHIFT)
// Read and write the flash at speed mode 3.
#define SI32_FLASHCTRL_A_CONFIG_SPMD_MODE3_VALUE  3
#define SI32_FLASHCTRL_A_CONFIG_SPMD_MODE3_U32 \
   (SI32_FLASHCTRL_A_CONFIG_SPMD_MODE3_VALUE << SI32_FLASHCTRL_A_CONFIG_SPMD_SHIFT)

#define SI32_FLASHCTRL_A_CONFIG_RDSEN_MASK  0x00000010
#define SI32_FLASHCTRL_A_CONFIG_RDSEN_SHIFT  4
// Disable read store mode.
#define SI32_FLASHCTRL_A_CONFIG_RDSEN_DISABLED_VALUE  0
#define SI32_FLASHCTRL_A_CONFIG_RDSEN_DISABLED_U32 \
   (SI32_FLASHCTRL_A_CONFIG_RDSEN_DISABLED_VALUE << SI32_FLASHCTRL_A_CONFIG_RDSEN_SHIFT)
// Enable read store mode.
#define SI32_FLASHCTRL_A_CONFIG_RDSEN_ENABLED_VALUE  1
#define SI32_FLASHCTRL_A_CONFIG_RDSEN_ENABLED_U32 \
   (SI32_FLASHCTRL_A_CONFIG_RDSEN_ENABLED_VALUE << SI32_FLASHCTRL_A_CONFIG_RDSEN_SHIFT)

#define SI32_FLASHCTRL_A_CONFIG_DPFEN_MASK  0x00000040
#define SI32_FLASHCTRL_A_CONFIG_DPFEN_SHIFT  6
// Data accesses are excluded from the prefetch buffer.
#define SI32_FLASHCTRL_A_CONFIG_DPFEN_DISABLED_VALUE  0
#define SI32_FLASHCTRL_A_CONFIG_DPFEN_DISABLED_U32 \
   (SI32_FLASHCTRL_A_CONFIG_DPFEN_DISABLED_VALUE << SI32_FLASHCTRL_A_CONFIG_DPFEN_SHIFT)
// Data accesses are included in the prefetch buffer.
#define SI32_FLASHCTRL_A_CONFIG_DPFEN_ENABLED_VALUE  1
#define SI32_FLASHCTRL_A_CONFIG_DPFEN_ENABLED_U32 \
   (SI32_FLASHCTRL_A_CONFIG_DPFEN_ENABLED_VALUE << SI32_FLASHCTRL_A_CONFIG_DPFEN_SHIFT)

#define SI32_FLASHCTRL_A_CONFIG_PFINH_MASK  0x00000080
#define SI32_FLASHCTRL_A_CONFIG_PFINH_SHIFT  7
// Any reads from flash are prefetched until the prefetch buffer is full.
#define SI32_FLASHCTRL_A_CONFIG_PFINH_INACTIVE_VALUE  0
#define SI32_FLASHCTRL_A_CONFIG_PFINH_INACTIVE_U32 \
   (SI32_FLASHCTRL_A_CONFIG_PFINH_INACTIVE_VALUE << SI32_FLASHCTRL_A_CONFIG_PFINH_SHIFT)
// Inhibit the prefetch engine.
#define SI32_FLASHCTRL_A_CONFIG_PFINH_ACTIVE_VALUE  1
#define SI32_FLASHCTRL_A_CONFIG_PFINH_ACTIVE_U32 \
   (SI32_FLASHCTRL_A_CONFIG_PFINH_ACTIVE_VALUE << SI32_FLASHCTRL_A_CONFIG_PFINH_SHIFT)

#define SI32_FLASHCTRL_A_CONFIG_SQWEN_MASK  0x00010000
#define SI32_FLASHCTRL_A_CONFIG_SQWEN_SHIFT  16
// Disable sequential write mode.
#define SI32_FLASHCTRL_A_CONFIG_SQWEN_DISABLED_VALUE  0
#define SI32_FLASHCTRL_A_CONFIG_SQWEN_DISABLED_U32 \
   (SI32_FLASHCTRL_A_CONFIG_SQWEN_DISABLED_VALUE << SI32_FLASHCTRL_A_CONFIG_SQWEN_SHIFT)
// Enable sequential write mode.
#define SI32_FLASHCTRL_A_CONFIG_SQWEN_ENABLED_VALUE  1
#define SI32_FLASHCTRL_A_CONFIG_SQWEN_ENABLED_U32 \
   (SI32_FLASHCTRL_A_CONFIG_SQWEN_ENABLED_VALUE << SI32_FLASHCTRL_A_CONFIG_SQWEN_SHIFT)

#define SI32_FLASHCTRL_A_CONFIG_ERASEEN_MASK  0x00040000
#define SI32_FLASHCTRL_A_CONFIG_ERASEEN_SHIFT  18
// Writes to the WRDATA field will initiate a write to flash at the address in the
// WRADDR field.
#define SI32_FLASHCTRL_A_CONFIG_ERASEEN_DISABLED_VALUE  0
#define SI32_FLASHCTRL_A_CONFIG_ERASEEN_DISABLED_U32 \
   (SI32_FLASHCTRL_A_CONFIG_ERASEEN_DISABLED_VALUE << SI32_FLASHCTRL_A_CONFIG_ERASEEN_SHIFT)
// Writes to the WRDATA field will initiate an erase of the flash page containing
// the address in the WRADDR field.
#define SI32_FLASHCTRL_A_CONFIG_ERASEEN_ENABLED_VALUE  1
#define SI32_FLASHCTRL_A_CONFIG_ERASEEN_ENABLED_U32 \
   (SI32_FLASHCTRL_A_CONFIG_ERASEEN_ENABLED_VALUE << SI32_FLASHCTRL_A_CONFIG_ERASEEN_SHIFT)

#define SI32_FLASHCTRL_A_CONFIG_BUFSTS_MASK  0x00080000
#define SI32_FLASHCTRL_A_CONFIG_BUFSTS_SHIFT  19
// The flash controller write data buffer is empty.
#define SI32_FLASHCTRL_A_CONFIG_BUFSTS_EMPTY_VALUE  0
#define SI32_FLASHCTRL_A_CONFIG_BUFSTS_EMPTY_U32 \
   (SI32_FLASHCTRL_A_CONFIG_BUFSTS_EMPTY_VALUE << SI32_FLASHCTRL_A_CONFIG_BUFSTS_SHIFT)
// The flash controller write data buffer is full.
#define SI32_FLASHCTRL_A_CONFIG_BUFSTS_FULL_VALUE  1
#define SI32_FLASHCTRL_A_CONFIG_BUFSTS_FULL_U32 \
   (SI32_FLASHCTRL_A_CONFIG_BUFSTS_FULL_VALUE << SI32_FLASHCTRL_A_CONFIG_BUFSTS_SHIFT)

#define SI32_FLASHCTRL_A_CONFIG_BUSYF_MASK  0x00100000
#define SI32_FLASHCTRL_A_CONFIG_BUSYF_SHIFT  20
// The flash interface is not busy.
#define SI32_FLASHCTRL_A_CONFIG_BUSYF_NOT_SET_VALUE  0
#define SI32_FLASHCTRL_A_CONFIG_BUSYF_NOT_SET_U32 \
   (SI32_FLASHCTRL_A_CONFIG_BUSYF_NOT_SET_VALUE << SI32_FLASHCTRL_A_CONFIG_BUSYF_SHIFT)
// The flash interface is busy with an operation.
#define SI32_FLASHCTRL_A_CONFIG_BUSYF_SET_VALUE  1
#define SI32_FLASHCTRL_A_CONFIG_BUSYF_SET_U32 \
   (SI32_FLASHCTRL_A_CONFIG_BUSYF_SET_VALUE << SI32_FLASHCTRL_A_CONFIG_BUSYF_SHIFT)



struct SI32_FLASHCTRL_A_WRADDR_Struct
{
   union
   {
      struct
      {
         // Flash Write Address
         volatile uint32_t WRADDR_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_FLASHCTRL_A_WRADDR_WRADDR_MASK  0xFFFFFFFF
#define SI32_FLASHCTRL_A_WRADDR_WRADDR_SHIFT  0



struct SI32_FLASHCTRL_A_WRDATA_Struct
{
   union
   {
      struct
      {
         // Flash Write Data
         volatile uint32_t WRDATA_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_FLASHCTRL_A_WRDATA_WRDATA_MASK  0xFFFFFFFF
#define SI32_FLASHCTRL_A_WRDATA_WRDATA_SHIFT  0



struct SI32_FLASHCTRL_A_KEY_Struct
{
   union
   {
      struct
      {
         // Flash Key
         volatile uint8_t KEY_BITS;
                  uint32_t reserved0: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_FLASHCTRL_A_KEY_KEY_MASK  0x000000FF
#define SI32_FLASHCTRL_A_KEY_KEY_SHIFT  0
#define SI32_FLASHCTRL_A_KEY_KEY_MULTI_LOCK_VALUE  90
#define SI32_FLASHCTRL_A_KEY_KEY_MULTI_LOCK_U32 \
   (SI32_FLASHCTRL_A_KEY_KEY_MULTI_LOCK_VALUE << SI32_FLASHCTRL_A_KEY_KEY_SHIFT)
#define SI32_FLASHCTRL_A_KEY_KEY_INITIAL_UNLOCK_VALUE  165
#define SI32_FLASHCTRL_A_KEY_KEY_INITIAL_UNLOCK_U32 \
   (SI32_FLASHCTRL_A_KEY_KEY_INITIAL_UNLOCK_VALUE << SI32_FLASHCTRL_A_KEY_KEY_SHIFT)
#define SI32_FLASHCTRL_A_KEY_KEY_SINGLE_UNLOCK_VALUE  241
#define SI32_FLASHCTRL_A_KEY_KEY_SINGLE_UNLOCK_U32 \
   (SI32_FLASHCTRL_A_KEY_KEY_SINGLE_UNLOCK_VALUE << SI32_FLASHCTRL_A_KEY_KEY_SHIFT)
#define SI32_FLASHCTRL_A_KEY_KEY_MULTI_UNLOCK_VALUE  242
#define SI32_FLASHCTRL_A_KEY_KEY_MULTI_UNLOCK_U32 \
   (SI32_FLASHCTRL_A_KEY_KEY_MULTI_UNLOCK_VALUE << SI32_FLASHCTRL_A_KEY_KEY_SHIFT)



struct SI32_FLASHCTRL_A_TCONTROL_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 6;
         // Flash Read Timing Mode
         volatile uint32_t FLRTMD: 1;
                  uint32_t reserved1: 25;
      };
      volatile uint32_t U32;
   };
};

#define SI32_FLASHCTRL_A_TCONTROL_FLRTMD_MASK  0x00000040
#define SI32_FLASHCTRL_A_TCONTROL_FLRTMD_SHIFT  6
// Configure the flash read controller for AHB clocks below 12 MHz.
#define SI32_FLASHCTRL_A_TCONTROL_FLRTMD_SLOW_VALUE  0
#define SI32_FLASHCTRL_A_TCONTROL_FLRTMD_SLOW_U32 \
   (SI32_FLASHCTRL_A_TCONTROL_FLRTMD_SLOW_VALUE << SI32_FLASHCTRL_A_TCONTROL_FLRTMD_SHIFT)
// Configure the flash read controller for AHB clocks above 12 MHz.
#define SI32_FLASHCTRL_A_TCONTROL_FLRTMD_FAST_VALUE  1
#define SI32_FLASHCTRL_A_TCONTROL_FLRTMD_FAST_U32 \
   (SI32_FLASHCTRL_A_TCONTROL_FLRTMD_FAST_VALUE << SI32_FLASHCTRL_A_TCONTROL_FLRTMD_SHIFT)



typedef struct SI32_FLASHCTRL_A_Struct
{
   struct SI32_FLASHCTRL_A_CONFIG_Struct           CONFIG         ; // Base Address + 0x0
   volatile uint32_t                               CONFIG_SET;
   volatile uint32_t                               CONFIG_CLR;
   uint32_t                                        reserved0;
   uint32_t                                        reserved1[4];
   uint32_t                                        reserved2[4];
   uint32_t                                        reserved3[4];
   uint32_t                                        reserved4[4];
   uint32_t                                        reserved5[4];
   uint32_t                                        reserved6[4];
   uint32_t                                        reserved7[4];
   uint32_t                                        reserved8[4];
   uint32_t                                        reserved9[4];
   struct SI32_FLASHCTRL_A_WRADDR_Struct           WRADDR         ; // Base Address + 0xa0
   uint32_t                                        reserved10;
   uint32_t                                        reserved11;
   uint32_t                                        reserved12;
   struct SI32_FLASHCTRL_A_WRDATA_Struct           WRDATA         ; // Base Address + 0xb0
   uint32_t                                        reserved13;
   uint32_t                                        reserved14;
   uint32_t                                        reserved15;
   struct SI32_FLASHCTRL_A_KEY_Struct              KEY            ; // Base Address + 0xc0
   uint32_t                                        reserved16;
   uint32_t                                        reserved17;
   uint32_t                                        reserved18;
   struct SI32_FLASHCTRL_A_TCONTROL_Struct         TCONTROL       ; // Base Address + 0xd0
   uint32_t                                        reserved19;
   uint32_t                                        reserved20;
   uint32_t                                        reserved21;
   uint32_t                                        reserved22[4];
   uint32_t                                        reserved23[4];
   uint32_t                                        reserved24[4];
   uint32_t                                        reserved25[4];
   uint32_t                                        reserved26[4];
   uint32_t                                        reserved27[4];
   uint32_t                                        reserved28[4];
   uint32_t                                        reserved29[4];
} SI32_FLASHCTRL_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_FLASHCTRL_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

