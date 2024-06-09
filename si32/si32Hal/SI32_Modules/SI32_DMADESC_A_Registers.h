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
// Script: 0.56
// Version: 1

#ifndef __SI32_DMADESC_A_REGISTERS_H__
#define __SI32_DMADESC_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_DMADESC_A_SRCEND_Struct
{
   union
   {
      struct
      {
         // Source End Pointer
         volatile uint32_t SRCEND_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_DMADESC_A_SRCEND_SRCEND_MASK  0xFFFFFFFF
#define SI32_DMADESC_A_SRCEND_SRCEND_SHIFT  0



struct SI32_DMADESC_A_DSTEND_Struct
{
   union
   {
      struct
      {
         // Destination End Pointer
         volatile uint32_t DSTEND_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_DMADESC_A_DSTEND_DSTEND_MASK  0xFFFFFFFF
#define SI32_DMADESC_A_DSTEND_DSTEND_SHIFT  0



struct SI32_DMADESC_A_CONFIG_Struct
{
   union
   {
      struct
      {
         // Transfer Mode
         volatile uint32_t TMD: 3;
                  uint32_t reserved0: 1;
         // Transfer Total
         volatile uint32_t NCOUNT: 10;
         // Transfer Size Select
         volatile uint32_t RPOWER: 4;
                  uint32_t reserved1: 6;
         // Source Data Size Select
         volatile uint32_t SRCSIZE: 2;
         // Source Address Increment Mode
         volatile uint32_t SRCAIMD: 2;
         // Destination Data Size Select
         volatile uint32_t DSTSIZE: 2;
         // Destination Address Increment Mode
         volatile uint32_t DSTAIMD: 2;
      };
      volatile uint32_t U32;
   };
};

#define SI32_DMADESC_A_CONFIG_TMD_MASK  0x00000007
#define SI32_DMADESC_A_CONFIG_TMD_SHIFT  0
// Stop the DMA channel.
#define SI32_DMADESC_A_CONFIG_TMD_STOP_VALUE  0
#define SI32_DMADESC_A_CONFIG_TMD_STOP_U32 \
   (SI32_DMADESC_A_CONFIG_TMD_STOP_VALUE << SI32_DMADESC_A_CONFIG_TMD_SHIFT)
// Use the Basic transfer type (single structure only).
#define SI32_DMADESC_A_CONFIG_TMD_BASIC_VALUE  1
#define SI32_DMADESC_A_CONFIG_TMD_BASIC_U32 \
   (SI32_DMADESC_A_CONFIG_TMD_BASIC_VALUE << SI32_DMADESC_A_CONFIG_TMD_SHIFT)
// Use the Auto-Request transfer type (single structure only).
#define SI32_DMADESC_A_CONFIG_TMD_AUTO_REQUEST_VALUE  2
#define SI32_DMADESC_A_CONFIG_TMD_AUTO_REQUEST_U32 \
   (SI32_DMADESC_A_CONFIG_TMD_AUTO_REQUEST_VALUE << SI32_DMADESC_A_CONFIG_TMD_SHIFT)
// Use the Ping-Pong transfer type (primary and alternate structures).
#define SI32_DMADESC_A_CONFIG_TMD_PING_PONG_VALUE  3
#define SI32_DMADESC_A_CONFIG_TMD_PING_PONG_U32 \
   (SI32_DMADESC_A_CONFIG_TMD_PING_PONG_VALUE << SI32_DMADESC_A_CONFIG_TMD_SHIFT)
// Use the Memory Scatter-Gather Primary transfer type (primary, alternate, and
// scattered structures).
#define SI32_DMADESC_A_CONFIG_TMD_MEMORY_SCATTER_GATHER_P_VALUE  4
#define SI32_DMADESC_A_CONFIG_TMD_MEMORY_SCATTER_GATHER_P_U32 \
   (SI32_DMADESC_A_CONFIG_TMD_MEMORY_SCATTER_GATHER_P_VALUE << SI32_DMADESC_A_CONFIG_TMD_SHIFT)
// Use the Memory Scatter-Gather Alternate transfer type (primary, alternate, and
// scattered structures).
#define SI32_DMADESC_A_CONFIG_TMD_MEMORY_SCATTER_GATHER_A_VALUE  5
#define SI32_DMADESC_A_CONFIG_TMD_MEMORY_SCATTER_GATHER_A_U32 \
   (SI32_DMADESC_A_CONFIG_TMD_MEMORY_SCATTER_GATHER_A_VALUE << SI32_DMADESC_A_CONFIG_TMD_SHIFT)
// Use the Peripheral Scatter-Gather Primary transfer type (primary, alternate, and
// scattered structures).
#define SI32_DMADESC_A_CONFIG_TMD_PERIPHERAL_SCATTER_GATHER_P_VALUE  6
#define SI32_DMADESC_A_CONFIG_TMD_PERIPHERAL_SCATTER_GATHER_P_U32 \
   (SI32_DMADESC_A_CONFIG_TMD_PERIPHERAL_SCATTER_GATHER_P_VALUE << SI32_DMADESC_A_CONFIG_TMD_SHIFT)
// Use the Peripheral Scatter-Gather Alternate transfer type (primary, alternate,
// and scattered structures).
#define SI32_DMADESC_A_CONFIG_TMD_PERIPHERAL_SCATTER_GATHER_A_VALUE  7
#define SI32_DMADESC_A_CONFIG_TMD_PERIPHERAL_SCATTER_GATHER_A_U32 \
   (SI32_DMADESC_A_CONFIG_TMD_PERIPHERAL_SCATTER_GATHER_A_VALUE << SI32_DMADESC_A_CONFIG_TMD_SHIFT)

#define SI32_DMADESC_A_CONFIG_NCOUNT_MASK  0x00003FF0
#define SI32_DMADESC_A_CONFIG_NCOUNT_SHIFT  4

#define SI32_DMADESC_A_CONFIG_RPOWER_MASK  0x0003C000
#define SI32_DMADESC_A_CONFIG_RPOWER_SHIFT  14

#define SI32_DMADESC_A_CONFIG_SRCSIZE_MASK  0x03000000
#define SI32_DMADESC_A_CONFIG_SRCSIZE_SHIFT  24
// Each DMA source data transfer reads a byte.
#define SI32_DMADESC_A_CONFIG_SRCSIZE_BYTE_VALUE  0
#define SI32_DMADESC_A_CONFIG_SRCSIZE_BYTE_U32 \
   (SI32_DMADESC_A_CONFIG_SRCSIZE_BYTE_VALUE << SI32_DMADESC_A_CONFIG_SRCSIZE_SHIFT)
// Each DMA source data transfer reads a half-word.
#define SI32_DMADESC_A_CONFIG_SRCSIZE_HALF_WORD_VALUE  1
#define SI32_DMADESC_A_CONFIG_SRCSIZE_HALF_WORD_U32 \
   (SI32_DMADESC_A_CONFIG_SRCSIZE_HALF_WORD_VALUE << SI32_DMADESC_A_CONFIG_SRCSIZE_SHIFT)
// Each DMA source data transfer reads a word.
#define SI32_DMADESC_A_CONFIG_SRCSIZE_WORD_VALUE  2
#define SI32_DMADESC_A_CONFIG_SRCSIZE_WORD_U32 \
   (SI32_DMADESC_A_CONFIG_SRCSIZE_WORD_VALUE << SI32_DMADESC_A_CONFIG_SRCSIZE_SHIFT)

#define SI32_DMADESC_A_CONFIG_SRCAIMD_MASK  0x0C000000
#define SI32_DMADESC_A_CONFIG_SRCAIMD_SHIFT  26
// The source address increments by one byte after each data transfer.
#define SI32_DMADESC_A_CONFIG_SRCAIMD_BYTE_VALUE  0
#define SI32_DMADESC_A_CONFIG_SRCAIMD_BYTE_U32 \
   (SI32_DMADESC_A_CONFIG_SRCAIMD_BYTE_VALUE << SI32_DMADESC_A_CONFIG_SRCAIMD_SHIFT)
// The source address increments by one half-word after each data transfer.
#define SI32_DMADESC_A_CONFIG_SRCAIMD_HALF_WORD_VALUE  1
#define SI32_DMADESC_A_CONFIG_SRCAIMD_HALF_WORD_U32 \
   (SI32_DMADESC_A_CONFIG_SRCAIMD_HALF_WORD_VALUE << SI32_DMADESC_A_CONFIG_SRCAIMD_SHIFT)
// The source address increments by one word after each data transfer.
#define SI32_DMADESC_A_CONFIG_SRCAIMD_WORD_VALUE  2
#define SI32_DMADESC_A_CONFIG_SRCAIMD_WORD_U32 \
   (SI32_DMADESC_A_CONFIG_SRCAIMD_WORD_VALUE << SI32_DMADESC_A_CONFIG_SRCAIMD_SHIFT)
// The source address does not increment.
#define SI32_DMADESC_A_CONFIG_SRCAIMD_NO_INCREMENT_VALUE  3
#define SI32_DMADESC_A_CONFIG_SRCAIMD_NO_INCREMENT_U32 \
   (SI32_DMADESC_A_CONFIG_SRCAIMD_NO_INCREMENT_VALUE << SI32_DMADESC_A_CONFIG_SRCAIMD_SHIFT)

#define SI32_DMADESC_A_CONFIG_DSTSIZE_MASK  0x30000000
#define SI32_DMADESC_A_CONFIG_DSTSIZE_SHIFT  28
// Each DMA destination data transfer writes a byte.
#define SI32_DMADESC_A_CONFIG_DSTSIZE_BYTE_VALUE  0
#define SI32_DMADESC_A_CONFIG_DSTSIZE_BYTE_U32 \
   (SI32_DMADESC_A_CONFIG_DSTSIZE_BYTE_VALUE << SI32_DMADESC_A_CONFIG_DSTSIZE_SHIFT)
// Each DMA destination data transfer writes a half-word.
#define SI32_DMADESC_A_CONFIG_DSTSIZE_HALF_WORD_VALUE  1
#define SI32_DMADESC_A_CONFIG_DSTSIZE_HALF_WORD_U32 \
   (SI32_DMADESC_A_CONFIG_DSTSIZE_HALF_WORD_VALUE << SI32_DMADESC_A_CONFIG_DSTSIZE_SHIFT)
// Each DMA destination data transfer writes a word.
#define SI32_DMADESC_A_CONFIG_DSTSIZE_WORD_VALUE  2
#define SI32_DMADESC_A_CONFIG_DSTSIZE_WORD_U32 \
   (SI32_DMADESC_A_CONFIG_DSTSIZE_WORD_VALUE << SI32_DMADESC_A_CONFIG_DSTSIZE_SHIFT)

#define SI32_DMADESC_A_CONFIG_DSTAIMD_MASK  0xC0000000
#define SI32_DMADESC_A_CONFIG_DSTAIMD_SHIFT  30
// The destination address increments by one byte after each data transfer.
#define SI32_DMADESC_A_CONFIG_DSTAIMD_BYTE_VALUE  0U
#define SI32_DMADESC_A_CONFIG_DSTAIMD_BYTE_U32 \
   (SI32_DMADESC_A_CONFIG_DSTAIMD_BYTE_VALUE << SI32_DMADESC_A_CONFIG_DSTAIMD_SHIFT)
// The destination address increments by one half-word after each data transfer.
#define SI32_DMADESC_A_CONFIG_DSTAIMD_HALF_WORD_VALUE  1U
#define SI32_DMADESC_A_CONFIG_DSTAIMD_HALF_WORD_U32 \
   (SI32_DMADESC_A_CONFIG_DSTAIMD_HALF_WORD_VALUE << SI32_DMADESC_A_CONFIG_DSTAIMD_SHIFT)
// The destination address increments by one word after each data transfer.
#define SI32_DMADESC_A_CONFIG_DSTAIMD_WORD_VALUE  2U
#define SI32_DMADESC_A_CONFIG_DSTAIMD_WORD_U32 \
   (SI32_DMADESC_A_CONFIG_DSTAIMD_WORD_VALUE << SI32_DMADESC_A_CONFIG_DSTAIMD_SHIFT)
// The destination address does not increment.
#define SI32_DMADESC_A_CONFIG_DSTAIMD_NO_INCREMENT_VALUE  3U
#define SI32_DMADESC_A_CONFIG_DSTAIMD_NO_INCREMENT_U32 \
   (SI32_DMADESC_A_CONFIG_DSTAIMD_NO_INCREMENT_VALUE << SI32_DMADESC_A_CONFIG_DSTAIMD_SHIFT)



typedef struct SI32_DMADESC_A_Struct
{
   struct SI32_DMADESC_A_SRCEND_Struct             SRCEND         ; // Base Address + 0x0
   struct SI32_DMADESC_A_DSTEND_Struct             DSTEND         ; // Base Address + 0x4
   struct SI32_DMADESC_A_CONFIG_Struct             CONFIG         ; // Base Address + 0x8
   uint32_t                                        reserved0;
} SI32_DMADESC_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_DMADESC_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

