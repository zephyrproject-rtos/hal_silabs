//-----------------------------------------------------------------------------
// Copyright 2013 (c) Silicon Laboratories Inc.
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
// Script: 0.62
// Version: 1

#ifndef __SI32_EMIFIF_A_REGISTERS_H__
#define __SI32_EMIFIF_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_EMIFIF_A_CONFIG_Struct
{
   union
   {
      struct
      {
         // Interface Bus Data Width
         volatile uint32_t BUSWIDTH: 1;
                  uint32_t reserved0: 1;
         // Interface Mux Mode
         volatile uint32_t MUXMD: 1;
         // Interface Automatic Address Shift Enable
         volatile uint32_t ASEN: 1;
         // Interface Read Only Enable
         volatile uint32_t ROEN: 1;
                  uint32_t reserved1: 3;
         // Write Data Hold State Inhibit
         volatile uint32_t WDHINH: 1;
                  uint32_t reserved2: 3;
         // Output Enable Delay
         volatile uint32_t DELAYOE: 1;
                  uint32_t reserved3: 3;
         // Keep Last Read Enable
         volatile uint32_t KLREN: 1;
                  uint32_t reserved4: 15;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EMIFIF_A_CONFIG_BUSWIDTH_MASK  0x00000001
#define SI32_EMIFIF_A_CONFIG_BUSWIDTH_SHIFT  0
// The data bus is 8-bits wide.
#define SI32_EMIFIF_A_CONFIG_BUSWIDTH_8BIT_VALUE  0
#define SI32_EMIFIF_A_CONFIG_BUSWIDTH_8BIT_U32 \
   (SI32_EMIFIF_A_CONFIG_BUSWIDTH_8BIT_VALUE << SI32_EMIFIF_A_CONFIG_BUSWIDTH_SHIFT)
// The data bus is 16-bits wide. This option should only be used in multiplexed
// mode (MUXMD = 1).
#define SI32_EMIFIF_A_CONFIG_BUSWIDTH_16BIT_VALUE  1
#define SI32_EMIFIF_A_CONFIG_BUSWIDTH_16BIT_U32 \
   (SI32_EMIFIF_A_CONFIG_BUSWIDTH_16BIT_VALUE << SI32_EMIFIF_A_CONFIG_BUSWIDTH_SHIFT)

#define SI32_EMIFIF_A_CONFIG_MUXMD_MASK  0x00000004
#define SI32_EMIFIF_A_CONFIG_MUXMD_SHIFT  2
// The interface operates in non-multiplexed mode.
#define SI32_EMIFIF_A_CONFIG_MUXMD_NONMUXED_VALUE  0
#define SI32_EMIFIF_A_CONFIG_MUXMD_NONMUXED_U32 \
   (SI32_EMIFIF_A_CONFIG_MUXMD_NONMUXED_VALUE << SI32_EMIFIF_A_CONFIG_MUXMD_SHIFT)
// The interface operates in multiplexed mode.
#define SI32_EMIFIF_A_CONFIG_MUXMD_MUXED_VALUE  1
#define SI32_EMIFIF_A_CONFIG_MUXMD_MUXED_U32 \
   (SI32_EMIFIF_A_CONFIG_MUXMD_MUXED_VALUE << SI32_EMIFIF_A_CONFIG_MUXMD_SHIFT)

#define SI32_EMIFIF_A_CONFIG_ASEN_MASK  0x00000008
#define SI32_EMIFIF_A_CONFIG_ASEN_SHIFT  3
// The address is not automatically shifted.
#define SI32_EMIFIF_A_CONFIG_ASEN_DISABLED_VALUE  0
#define SI32_EMIFIF_A_CONFIG_ASEN_DISABLED_U32 \
   (SI32_EMIFIF_A_CONFIG_ASEN_DISABLED_VALUE << SI32_EMIFIF_A_CONFIG_ASEN_SHIFT)
// The address is automatically shifted.
#define SI32_EMIFIF_A_CONFIG_ASEN_ENABLED_VALUE  1
#define SI32_EMIFIF_A_CONFIG_ASEN_ENABLED_U32 \
   (SI32_EMIFIF_A_CONFIG_ASEN_ENABLED_VALUE << SI32_EMIFIF_A_CONFIG_ASEN_SHIFT)

#define SI32_EMIFIF_A_CONFIG_ROEN_MASK  0x00000010
#define SI32_EMIFIF_A_CONFIG_ROEN_SHIFT  4
// The interface supports reads and writes.
#define SI32_EMIFIF_A_CONFIG_ROEN_DISABLED_VALUE  0
#define SI32_EMIFIF_A_CONFIG_ROEN_DISABLED_U32 \
   (SI32_EMIFIF_A_CONFIG_ROEN_DISABLED_VALUE << SI32_EMIFIF_A_CONFIG_ROEN_SHIFT)
// The interface supports only reads.
#define SI32_EMIFIF_A_CONFIG_ROEN_ENABLED_VALUE  1
#define SI32_EMIFIF_A_CONFIG_ROEN_ENABLED_U32 \
   (SI32_EMIFIF_A_CONFIG_ROEN_ENABLED_VALUE << SI32_EMIFIF_A_CONFIG_ROEN_SHIFT)

#define SI32_EMIFIF_A_CONFIG_WDHINH_MASK  0x00000100
#define SI32_EMIFIF_A_CONFIG_WDHINH_SHIFT  8
// Enable the write data hold state.
#define SI32_EMIFIF_A_CONFIG_WDHINH_INACTIVE_VALUE  0
#define SI32_EMIFIF_A_CONFIG_WDHINH_INACTIVE_U32 \
   (SI32_EMIFIF_A_CONFIG_WDHINH_INACTIVE_VALUE << SI32_EMIFIF_A_CONFIG_WDHINH_SHIFT)
// Inhibit the write data hold state.
#define SI32_EMIFIF_A_CONFIG_WDHINH_ACTIVE_VALUE  1
#define SI32_EMIFIF_A_CONFIG_WDHINH_ACTIVE_U32 \
   (SI32_EMIFIF_A_CONFIG_WDHINH_ACTIVE_VALUE << SI32_EMIFIF_A_CONFIG_WDHINH_SHIFT)

#define SI32_EMIFIF_A_CONFIG_DELAYOE_MASK  0x00001000
#define SI32_EMIFIF_A_CONFIG_DELAYOE_SHIFT  12
// The output enable signal (/OE) is not delayed.
#define SI32_EMIFIF_A_CONFIG_DELAYOE_DISABLED_VALUE  0
#define SI32_EMIFIF_A_CONFIG_DELAYOE_DISABLED_U32 \
   (SI32_EMIFIF_A_CONFIG_DELAYOE_DISABLED_VALUE << SI32_EMIFIF_A_CONFIG_DELAYOE_SHIFT)
// The output enable signal (/OE) is delayed.
#define SI32_EMIFIF_A_CONFIG_DELAYOE_ENABLED_VALUE  1
#define SI32_EMIFIF_A_CONFIG_DELAYOE_ENABLED_U32 \
   (SI32_EMIFIF_A_CONFIG_DELAYOE_ENABLED_VALUE << SI32_EMIFIF_A_CONFIG_DELAYOE_SHIFT)

#define SI32_EMIFIF_A_CONFIG_KLREN_MASK  0x00010000
#define SI32_EMIFIF_A_CONFIG_KLREN_SHIFT  16
// The bus is driven to the idle state between active requests.
#define SI32_EMIFIF_A_CONFIG_KLREN_DISABLED_VALUE  0
#define SI32_EMIFIF_A_CONFIG_KLREN_DISABLED_U32 \
   (SI32_EMIFIF_A_CONFIG_KLREN_DISABLED_VALUE << SI32_EMIFIF_A_CONFIG_KLREN_SHIFT)
// The bus drives the last value read on the interface between active requests.
#define SI32_EMIFIF_A_CONFIG_KLREN_ENABLED_VALUE  1
#define SI32_EMIFIF_A_CONFIG_KLREN_ENABLED_U32 \
   (SI32_EMIFIF_A_CONFIG_KLREN_ENABLED_VALUE << SI32_EMIFIF_A_CONFIG_KLREN_SHIFT)



struct SI32_EMIFIF_A_IFRT_Struct
{
   union
   {
      struct
      {
         // Interface Read Address Setup Delay
         volatile uint32_t RASET: 4;
         // Interface Read Address Hold Delay
         volatile uint32_t RAHOLD: 4;
         // Interface Read Data Hold Delay
         volatile uint32_t RDHOLD: 4;
                  uint32_t reserved0: 4;
         // Interface Read Data Wait Delay
         volatile uint32_t RDWAIT: 6;
                  uint32_t reserved1: 10;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EMIFIF_A_IFRT_RASET_MASK  0x0000000F
#define SI32_EMIFIF_A_IFRT_RASET_SHIFT  0

#define SI32_EMIFIF_A_IFRT_RAHOLD_MASK  0x000000F0
#define SI32_EMIFIF_A_IFRT_RAHOLD_SHIFT  4

#define SI32_EMIFIF_A_IFRT_RDHOLD_MASK  0x00000F00
#define SI32_EMIFIF_A_IFRT_RDHOLD_SHIFT  8

#define SI32_EMIFIF_A_IFRT_RDWAIT_MASK  0x003F0000
#define SI32_EMIFIF_A_IFRT_RDWAIT_SHIFT  16



struct SI32_EMIFIF_A_IFWT_Struct
{
   union
   {
      struct
      {
         // Interface Write Address Setup Delay
         volatile uint32_t WASET: 4;
         // Interface Write Address Hold Delay
         volatile uint32_t WAHOLD: 4;
         // Interface Write Data Hold Delay
         volatile uint32_t WDHOLD: 4;
                  uint32_t reserved0: 4;
         // Interface Write Data Wait Delay
         volatile uint32_t WDWAIT: 6;
                  uint32_t reserved1: 10;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EMIFIF_A_IFWT_WASET_MASK  0x0000000F
#define SI32_EMIFIF_A_IFWT_WASET_SHIFT  0

#define SI32_EMIFIF_A_IFWT_WAHOLD_MASK  0x000000F0
#define SI32_EMIFIF_A_IFWT_WAHOLD_SHIFT  4

#define SI32_EMIFIF_A_IFWT_WDHOLD_MASK  0x00000F00
#define SI32_EMIFIF_A_IFWT_WDHOLD_SHIFT  8

#define SI32_EMIFIF_A_IFWT_WDWAIT_MASK  0x003F0000
#define SI32_EMIFIF_A_IFWT_WDWAIT_SHIFT  16



struct SI32_EMIFIF_A_IFRCST_Struct
{
   union
   {
      struct
      {
         // Chip Select Read Address Setup State
         volatile uint32_t CSRAS: 1;
         // Chip Select Read Address Hold State
         volatile uint32_t CSRAH: 1;
         // Chip Select Read Data Wait State
         volatile uint32_t CSRDW: 1;
         // Chip Select Read Data Hold State
         volatile uint32_t CSRDH: 1;
         // Output Enable Read Address Setup State
         volatile uint32_t OERAS: 1;
         // Output Enable Read Address Hold State
         volatile uint32_t OERAH: 1;
         // Output Enable Read Data Wait State
         volatile uint32_t OERDW: 1;
         // Output Enable Read Data Hold State
         volatile uint32_t OERDH: 1;
         // Write Signal Read Address Setup State
         volatile uint32_t WRRAS: 1;
         // Write Signal Read Address Hold State
         volatile uint32_t WRRAH: 1;
         // Write Signal Read Data Wait State
         volatile uint32_t WRRDW: 1;
         // Write Signal Read Data Hold State
         volatile uint32_t WRRDH: 1;
         // Address Latch Enable Read Address Setup State
         volatile uint32_t ALERAS: 1;
         // Address Latch Enable Read Address Hold State
         volatile uint32_t ALERAH: 1;
         // Address Latch Enable Read Data Wait State
         volatile uint32_t ALERDW: 1;
         // Address Latch Enable Read Data Hold State
         volatile uint32_t ALERDH: 1;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EMIFIF_A_IFRCST_CSRAS_MASK  0x00000001
#define SI32_EMIFIF_A_IFRCST_CSRAS_SHIFT  0
// Set chip select (CSx) to low during the read address setup state.
#define SI32_EMIFIF_A_IFRCST_CSRAS_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_CSRAS_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_CSRAS_LOW_VALUE << SI32_EMIFIF_A_IFRCST_CSRAS_SHIFT)
// Set chip select (CSx) to high during the read address setup state.
#define SI32_EMIFIF_A_IFRCST_CSRAS_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_CSRAS_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_CSRAS_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_CSRAS_SHIFT)

#define SI32_EMIFIF_A_IFRCST_CSRAH_MASK  0x00000002
#define SI32_EMIFIF_A_IFRCST_CSRAH_SHIFT  1
// Set chip select (CSx) to low during the read address hold state.
#define SI32_EMIFIF_A_IFRCST_CSRAH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_CSRAH_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_CSRAH_LOW_VALUE << SI32_EMIFIF_A_IFRCST_CSRAH_SHIFT)
// Set chip select (CSx) to high during the read address hold state.
#define SI32_EMIFIF_A_IFRCST_CSRAH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_CSRAH_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_CSRAH_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_CSRAH_SHIFT)

#define SI32_EMIFIF_A_IFRCST_CSRDW_MASK  0x00000004
#define SI32_EMIFIF_A_IFRCST_CSRDW_SHIFT  2
// Set chip select (CSx) to low during the read data wait state.
#define SI32_EMIFIF_A_IFRCST_CSRDW_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_CSRDW_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_CSRDW_LOW_VALUE << SI32_EMIFIF_A_IFRCST_CSRDW_SHIFT)
// Set chip select (CSx) to high during the read data wait state.
#define SI32_EMIFIF_A_IFRCST_CSRDW_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_CSRDW_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_CSRDW_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_CSRDW_SHIFT)

#define SI32_EMIFIF_A_IFRCST_CSRDH_MASK  0x00000008
#define SI32_EMIFIF_A_IFRCST_CSRDH_SHIFT  3
// Set chip select (CSx) to low during the read data hold state.
#define SI32_EMIFIF_A_IFRCST_CSRDH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_CSRDH_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_CSRDH_LOW_VALUE << SI32_EMIFIF_A_IFRCST_CSRDH_SHIFT)
// Set chip select (CSx) to high during the read data hold state.
#define SI32_EMIFIF_A_IFRCST_CSRDH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_CSRDH_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_CSRDH_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_CSRDH_SHIFT)

#define SI32_EMIFIF_A_IFRCST_OERAS_MASK  0x00000010
#define SI32_EMIFIF_A_IFRCST_OERAS_SHIFT  4
// Set output enable (/OE) to low during the read address setup state.
#define SI32_EMIFIF_A_IFRCST_OERAS_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_OERAS_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_OERAS_LOW_VALUE << SI32_EMIFIF_A_IFRCST_OERAS_SHIFT)
// Set output enable (/OE) to high during the read address setup state.
#define SI32_EMIFIF_A_IFRCST_OERAS_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_OERAS_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_OERAS_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_OERAS_SHIFT)

#define SI32_EMIFIF_A_IFRCST_OERAH_MASK  0x00000020
#define SI32_EMIFIF_A_IFRCST_OERAH_SHIFT  5
// Set output enable (/OE) to low during the read address hold state.
#define SI32_EMIFIF_A_IFRCST_OERAH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_OERAH_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_OERAH_LOW_VALUE << SI32_EMIFIF_A_IFRCST_OERAH_SHIFT)
// Set output enable (/OE) to high during the read address hold state.
#define SI32_EMIFIF_A_IFRCST_OERAH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_OERAH_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_OERAH_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_OERAH_SHIFT)

#define SI32_EMIFIF_A_IFRCST_OERDW_MASK  0x00000040
#define SI32_EMIFIF_A_IFRCST_OERDW_SHIFT  6
// Set output enable (/OE) to low during the read data wait state.
#define SI32_EMIFIF_A_IFRCST_OERDW_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_OERDW_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_OERDW_LOW_VALUE << SI32_EMIFIF_A_IFRCST_OERDW_SHIFT)
// Set output enable (/OE) to high during the read data wait state.
#define SI32_EMIFIF_A_IFRCST_OERDW_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_OERDW_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_OERDW_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_OERDW_SHIFT)

#define SI32_EMIFIF_A_IFRCST_OERDH_MASK  0x00000080
#define SI32_EMIFIF_A_IFRCST_OERDH_SHIFT  7
// Set output enable (/OE) to low during the read data hold state.
#define SI32_EMIFIF_A_IFRCST_OERDH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_OERDH_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_OERDH_LOW_VALUE << SI32_EMIFIF_A_IFRCST_OERDH_SHIFT)
// Set output enable (/OE) to high during the read data hold state.
#define SI32_EMIFIF_A_IFRCST_OERDH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_OERDH_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_OERDH_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_OERDH_SHIFT)

#define SI32_EMIFIF_A_IFRCST_WRRAS_MASK  0x00000100
#define SI32_EMIFIF_A_IFRCST_WRRAS_SHIFT  8
// Set write signal (/WR) to low during the read address setup state.
#define SI32_EMIFIF_A_IFRCST_WRRAS_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_WRRAS_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_WRRAS_LOW_VALUE << SI32_EMIFIF_A_IFRCST_WRRAS_SHIFT)
// Set write signal (/WR) to high during the read address setup state.
#define SI32_EMIFIF_A_IFRCST_WRRAS_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_WRRAS_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_WRRAS_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_WRRAS_SHIFT)

#define SI32_EMIFIF_A_IFRCST_WRRAH_MASK  0x00000200
#define SI32_EMIFIF_A_IFRCST_WRRAH_SHIFT  9
// Set write signal (/WR) to low during the read address hold state.
#define SI32_EMIFIF_A_IFRCST_WRRAH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_WRRAH_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_WRRAH_LOW_VALUE << SI32_EMIFIF_A_IFRCST_WRRAH_SHIFT)
// Set write signal (/WR) to high during the read address hold state.
#define SI32_EMIFIF_A_IFRCST_WRRAH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_WRRAH_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_WRRAH_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_WRRAH_SHIFT)

#define SI32_EMIFIF_A_IFRCST_WRRDW_MASK  0x00000400
#define SI32_EMIFIF_A_IFRCST_WRRDW_SHIFT  10
// Set write signal (/WR) to low during the read data wait state.
#define SI32_EMIFIF_A_IFRCST_WRRDW_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_WRRDW_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_WRRDW_LOW_VALUE << SI32_EMIFIF_A_IFRCST_WRRDW_SHIFT)
// Set write signal (/WR) to high during the read data wait state.
#define SI32_EMIFIF_A_IFRCST_WRRDW_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_WRRDW_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_WRRDW_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_WRRDW_SHIFT)

#define SI32_EMIFIF_A_IFRCST_WRRDH_MASK  0x00000800
#define SI32_EMIFIF_A_IFRCST_WRRDH_SHIFT  11
// Set write signal (/WR) to low during the read data hold state.
#define SI32_EMIFIF_A_IFRCST_WRRDH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_WRRDH_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_WRRDH_LOW_VALUE << SI32_EMIFIF_A_IFRCST_WRRDH_SHIFT)
// Set write signal (/WR) to high during the read data hold state.
#define SI32_EMIFIF_A_IFRCST_WRRDH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_WRRDH_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_WRRDH_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_WRRDH_SHIFT)

#define SI32_EMIFIF_A_IFRCST_ALERAS_MASK  0x00001000
#define SI32_EMIFIF_A_IFRCST_ALERAS_SHIFT  12
// Set address latch enable (ALEm) to low during the read address setup state.
#define SI32_EMIFIF_A_IFRCST_ALERAS_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_ALERAS_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_ALERAS_LOW_VALUE << SI32_EMIFIF_A_IFRCST_ALERAS_SHIFT)
// Set address latch enable (ALEm) to high during the read address setup state.
#define SI32_EMIFIF_A_IFRCST_ALERAS_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_ALERAS_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_ALERAS_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_ALERAS_SHIFT)

#define SI32_EMIFIF_A_IFRCST_ALERAH_MASK  0x00002000
#define SI32_EMIFIF_A_IFRCST_ALERAH_SHIFT  13
// Set address latch enable (ALEm) to low during the read address hold state.
#define SI32_EMIFIF_A_IFRCST_ALERAH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_ALERAH_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_ALERAH_LOW_VALUE << SI32_EMIFIF_A_IFRCST_ALERAH_SHIFT)
// Set address latch enable (ALEm) to high during the read address hold state.
#define SI32_EMIFIF_A_IFRCST_ALERAH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_ALERAH_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_ALERAH_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_ALERAH_SHIFT)

#define SI32_EMIFIF_A_IFRCST_ALERDW_MASK  0x00004000
#define SI32_EMIFIF_A_IFRCST_ALERDW_SHIFT  14
// Set address latch enable (ALEm) to low during the read data wait state.
#define SI32_EMIFIF_A_IFRCST_ALERDW_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_ALERDW_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_ALERDW_LOW_VALUE << SI32_EMIFIF_A_IFRCST_ALERDW_SHIFT)
// Set address latch enable (ALEm) to high during the read data wait state.
#define SI32_EMIFIF_A_IFRCST_ALERDW_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_ALERDW_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_ALERDW_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_ALERDW_SHIFT)

#define SI32_EMIFIF_A_IFRCST_ALERDH_MASK  0x00008000
#define SI32_EMIFIF_A_IFRCST_ALERDH_SHIFT  15
// Set address latch enable (ALEm) to low during the read data hold state.
#define SI32_EMIFIF_A_IFRCST_ALERDH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFRCST_ALERDH_LOW_U32 \
   (SI32_EMIFIF_A_IFRCST_ALERDH_LOW_VALUE << SI32_EMIFIF_A_IFRCST_ALERDH_SHIFT)
// Set address latch enable (ALEm) to high during the read data hold state.
#define SI32_EMIFIF_A_IFRCST_ALERDH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFRCST_ALERDH_HIGH_U32 \
   (SI32_EMIFIF_A_IFRCST_ALERDH_HIGH_VALUE << SI32_EMIFIF_A_IFRCST_ALERDH_SHIFT)



struct SI32_EMIFIF_A_IFWCST_Struct
{
   union
   {
      struct
      {
         // Chip Select Write Address Setup State
         volatile uint32_t CSWAS: 1;
         // Chip Select Write Address Hold State
         volatile uint32_t CSWAH: 1;
         // Chip Select Write Data Wait State
         volatile uint32_t CSWDW: 1;
         // Chip Select Write Data Hold State
         volatile uint32_t CSWDH: 1;
         // Output Enable Write Address Setup State
         volatile uint32_t OEWAS: 1;
         // Output Enable Write Address Hold State
         volatile uint32_t OEWAH: 1;
         // Output Enable Write Data Wait State
         volatile uint32_t OEWDW: 1;
         // Output Enable Write Data Hold State
         volatile uint32_t OEWDH: 1;
         // Write Signal Write Address Setup State
         volatile uint32_t WRWAS: 1;
         // Write Signal Write Address Hold State
         volatile uint32_t WRWAH: 1;
         // Write Signal Write Data Wait State
         volatile uint32_t WRWDW: 1;
         // Write Signal Write Data Hold State
         volatile uint32_t WRWDH: 1;
         // Address Latch Enable Write Address Setup State
         volatile uint32_t ALEWAS: 1;
         // Address Latch Enable Write Address Hold State
         volatile uint32_t ALEWAH: 1;
         // Address Latch Enable Write Data Wait State
         volatile uint32_t ALEWDW: 1;
         // Address Latch Enable Write Data Hold State
         volatile uint32_t ALEWDH: 1;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_EMIFIF_A_IFWCST_CSWAS_MASK  0x00000001
#define SI32_EMIFIF_A_IFWCST_CSWAS_SHIFT  0
// Set chip select (CSx) to low during the write address setup state.
#define SI32_EMIFIF_A_IFWCST_CSWAS_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_CSWAS_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_CSWAS_LOW_VALUE << SI32_EMIFIF_A_IFWCST_CSWAS_SHIFT)
// Set chip select (CSx) to high during the write address setup state.
#define SI32_EMIFIF_A_IFWCST_CSWAS_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_CSWAS_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_CSWAS_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_CSWAS_SHIFT)

#define SI32_EMIFIF_A_IFWCST_CSWAH_MASK  0x00000002
#define SI32_EMIFIF_A_IFWCST_CSWAH_SHIFT  1
// Set chip select (CSx) to low during the write address hold state.
#define SI32_EMIFIF_A_IFWCST_CSWAH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_CSWAH_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_CSWAH_LOW_VALUE << SI32_EMIFIF_A_IFWCST_CSWAH_SHIFT)
// Set chip select (CSx) to high during the write address hold state.
#define SI32_EMIFIF_A_IFWCST_CSWAH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_CSWAH_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_CSWAH_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_CSWAH_SHIFT)

#define SI32_EMIFIF_A_IFWCST_CSWDW_MASK  0x00000004
#define SI32_EMIFIF_A_IFWCST_CSWDW_SHIFT  2
// Set chip select (CSx) to low during the write data wait state.
#define SI32_EMIFIF_A_IFWCST_CSWDW_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_CSWDW_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_CSWDW_LOW_VALUE << SI32_EMIFIF_A_IFWCST_CSWDW_SHIFT)
// Set chip select (CSx) to high during the write data wait state.
#define SI32_EMIFIF_A_IFWCST_CSWDW_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_CSWDW_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_CSWDW_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_CSWDW_SHIFT)

#define SI32_EMIFIF_A_IFWCST_CSWDH_MASK  0x00000008
#define SI32_EMIFIF_A_IFWCST_CSWDH_SHIFT  3
// Set chip select (CSx) to low during the write data hold state.
#define SI32_EMIFIF_A_IFWCST_CSWDH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_CSWDH_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_CSWDH_LOW_VALUE << SI32_EMIFIF_A_IFWCST_CSWDH_SHIFT)
// Set chip select (CSx) to high during the write data hold state.
#define SI32_EMIFIF_A_IFWCST_CSWDH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_CSWDH_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_CSWDH_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_CSWDH_SHIFT)

#define SI32_EMIFIF_A_IFWCST_OEWAS_MASK  0x00000010
#define SI32_EMIFIF_A_IFWCST_OEWAS_SHIFT  4
// Set output enable (/OE) to low during the write address setup state.
#define SI32_EMIFIF_A_IFWCST_OEWAS_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_OEWAS_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_OEWAS_LOW_VALUE << SI32_EMIFIF_A_IFWCST_OEWAS_SHIFT)
// Set output enable (/OE) to high during the write address setup state.
#define SI32_EMIFIF_A_IFWCST_OEWAS_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_OEWAS_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_OEWAS_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_OEWAS_SHIFT)

#define SI32_EMIFIF_A_IFWCST_OEWAH_MASK  0x00000020
#define SI32_EMIFIF_A_IFWCST_OEWAH_SHIFT  5
// Set output enable (/OE) to low during the write address hold state.
#define SI32_EMIFIF_A_IFWCST_OEWAH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_OEWAH_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_OEWAH_LOW_VALUE << SI32_EMIFIF_A_IFWCST_OEWAH_SHIFT)
// Set output enable (/OE) to high during the write address hold state.
#define SI32_EMIFIF_A_IFWCST_OEWAH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_OEWAH_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_OEWAH_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_OEWAH_SHIFT)

#define SI32_EMIFIF_A_IFWCST_OEWDW_MASK  0x00000040
#define SI32_EMIFIF_A_IFWCST_OEWDW_SHIFT  6
// Set output enable (/OE) to low during the write data wait state.
#define SI32_EMIFIF_A_IFWCST_OEWDW_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_OEWDW_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_OEWDW_LOW_VALUE << SI32_EMIFIF_A_IFWCST_OEWDW_SHIFT)
// Set output enable (/OE) to high during the write data wait state.
#define SI32_EMIFIF_A_IFWCST_OEWDW_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_OEWDW_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_OEWDW_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_OEWDW_SHIFT)

#define SI32_EMIFIF_A_IFWCST_OEWDH_MASK  0x00000080
#define SI32_EMIFIF_A_IFWCST_OEWDH_SHIFT  7
// Set output enable (/OE) to low during the write data hold state.
#define SI32_EMIFIF_A_IFWCST_OEWDH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_OEWDH_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_OEWDH_LOW_VALUE << SI32_EMIFIF_A_IFWCST_OEWDH_SHIFT)
// Set output enable (/OE) to high during the write data hold state.
#define SI32_EMIFIF_A_IFWCST_OEWDH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_OEWDH_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_OEWDH_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_OEWDH_SHIFT)

#define SI32_EMIFIF_A_IFWCST_WRWAS_MASK  0x00000100
#define SI32_EMIFIF_A_IFWCST_WRWAS_SHIFT  8
// Set write signal (/WR) to low during the write address setup state.
#define SI32_EMIFIF_A_IFWCST_WRWAS_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_WRWAS_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_WRWAS_LOW_VALUE << SI32_EMIFIF_A_IFWCST_WRWAS_SHIFT)
// Set write signal (/WR) to high during the write address setup state.
#define SI32_EMIFIF_A_IFWCST_WRWAS_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_WRWAS_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_WRWAS_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_WRWAS_SHIFT)

#define SI32_EMIFIF_A_IFWCST_WRWAH_MASK  0x00000200
#define SI32_EMIFIF_A_IFWCST_WRWAH_SHIFT  9
// Set write signal (/WR) to low during the write address hold state.
#define SI32_EMIFIF_A_IFWCST_WRWAH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_WRWAH_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_WRWAH_LOW_VALUE << SI32_EMIFIF_A_IFWCST_WRWAH_SHIFT)
// Set write signal (/WR) to high during the write address hold state.
#define SI32_EMIFIF_A_IFWCST_WRWAH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_WRWAH_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_WRWAH_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_WRWAH_SHIFT)

#define SI32_EMIFIF_A_IFWCST_WRWDW_MASK  0x00000400
#define SI32_EMIFIF_A_IFWCST_WRWDW_SHIFT  10
// Set write signal (/WR) to low during the write data wait state.
#define SI32_EMIFIF_A_IFWCST_WRWDW_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_WRWDW_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_WRWDW_LOW_VALUE << SI32_EMIFIF_A_IFWCST_WRWDW_SHIFT)
// Set write signal (/WR) to high during the write data wait state.
#define SI32_EMIFIF_A_IFWCST_WRWDW_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_WRWDW_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_WRWDW_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_WRWDW_SHIFT)

#define SI32_EMIFIF_A_IFWCST_WRWDH_MASK  0x00000800
#define SI32_EMIFIF_A_IFWCST_WRWDH_SHIFT  11
// Set write signal (/WR) to low during the write data hold state.
#define SI32_EMIFIF_A_IFWCST_WRWDH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_WRWDH_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_WRWDH_LOW_VALUE << SI32_EMIFIF_A_IFWCST_WRWDH_SHIFT)
// Set write signal (/WR) to high during the write data hold state.
#define SI32_EMIFIF_A_IFWCST_WRWDH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_WRWDH_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_WRWDH_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_WRWDH_SHIFT)

#define SI32_EMIFIF_A_IFWCST_ALEWAS_MASK  0x00001000
#define SI32_EMIFIF_A_IFWCST_ALEWAS_SHIFT  12
// Set address latch enable (ALEm) to low during the write address setup state.
#define SI32_EMIFIF_A_IFWCST_ALEWAS_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_ALEWAS_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_ALEWAS_LOW_VALUE << SI32_EMIFIF_A_IFWCST_ALEWAS_SHIFT)
// Set address latch enable (ALEm) to high during the write address setup state.
#define SI32_EMIFIF_A_IFWCST_ALEWAS_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_ALEWAS_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_ALEWAS_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_ALEWAS_SHIFT)

#define SI32_EMIFIF_A_IFWCST_ALEWAH_MASK  0x00002000
#define SI32_EMIFIF_A_IFWCST_ALEWAH_SHIFT  13
// Set address latch enable (ALEm) to low during the write address hold state.
#define SI32_EMIFIF_A_IFWCST_ALEWAH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_ALEWAH_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_ALEWAH_LOW_VALUE << SI32_EMIFIF_A_IFWCST_ALEWAH_SHIFT)
// Set address latch enable (ALEm) to high during the write address hold state.
#define SI32_EMIFIF_A_IFWCST_ALEWAH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_ALEWAH_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_ALEWAH_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_ALEWAH_SHIFT)

#define SI32_EMIFIF_A_IFWCST_ALEWDW_MASK  0x00004000
#define SI32_EMIFIF_A_IFWCST_ALEWDW_SHIFT  14
// Set address latch enable (ALEm) to low during the write data wait state.
#define SI32_EMIFIF_A_IFWCST_ALEWDW_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_ALEWDW_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_ALEWDW_LOW_VALUE << SI32_EMIFIF_A_IFWCST_ALEWDW_SHIFT)
// Set address latch enable (ALEm) to high during the write data wait state.
#define SI32_EMIFIF_A_IFWCST_ALEWDW_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_ALEWDW_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_ALEWDW_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_ALEWDW_SHIFT)

#define SI32_EMIFIF_A_IFWCST_ALEWDH_MASK  0x00008000
#define SI32_EMIFIF_A_IFWCST_ALEWDH_SHIFT  15
// Set address latch enable (ALEm) to low during the write data hold state.
#define SI32_EMIFIF_A_IFWCST_ALEWDH_LOW_VALUE  0
#define SI32_EMIFIF_A_IFWCST_ALEWDH_LOW_U32 \
   (SI32_EMIFIF_A_IFWCST_ALEWDH_LOW_VALUE << SI32_EMIFIF_A_IFWCST_ALEWDH_SHIFT)
// Set address latch enable (ALEm) to high during the write data hold state.
#define SI32_EMIFIF_A_IFWCST_ALEWDH_HIGH_VALUE  1
#define SI32_EMIFIF_A_IFWCST_ALEWDH_HIGH_U32 \
   (SI32_EMIFIF_A_IFWCST_ALEWDH_HIGH_VALUE << SI32_EMIFIF_A_IFWCST_ALEWDH_SHIFT)



typedef struct SI32_EMIFIF_A_Struct
{
   struct SI32_EMIFIF_A_CONFIG_Struct              CONFIG         ; // Base Address + 0x0
   volatile uint32_t                               CONFIG_SET;
   volatile uint32_t                               CONFIG_CLR;
   uint32_t                                        reserved0;
   struct SI32_EMIFIF_A_IFRT_Struct                IFRT           ; // Base Address + 0x10
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   struct SI32_EMIFIF_A_IFWT_Struct                IFWT           ; // Base Address + 0x20
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   struct SI32_EMIFIF_A_IFRCST_Struct              IFRCST         ; // Base Address + 0x30
   uint32_t                                        reserved7;
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   struct SI32_EMIFIF_A_IFWCST_Struct              IFWCST         ; // Base Address + 0x40
   uint32_t                                        reserved10;
   uint32_t                                        reserved11;
   uint32_t                                        reserved12;
} SI32_EMIFIF_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_EMIFIF_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

