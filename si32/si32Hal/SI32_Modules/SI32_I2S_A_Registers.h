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

#ifndef __SI32_I2S_A_REGISTERS_H__
#define __SI32_I2S_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_I2S_A_TXCONTROL_Struct
{
   union
   {
      struct
      {
         // DFS Generator Enable
         volatile uint32_t FSGEN: 1;
         // DFS Synchronize Enable
         volatile uint32_t FSSEN: 1;
                  uint32_t reserved0: 3;
         // Transmit Delay Disable
         volatile uint32_t DDIS: 1;
         // Transmit Initial Phase Delay
         volatile uint32_t FSDEL: 8;
         // Transmit Frame Sync Source Select
         volatile uint32_t FSSRCSEL: 1;
         // Transmit Data Fill Select
         volatile uint32_t FILLSEL: 2;
         // Transmit Data Justification Select
         volatile uint32_t JSEL: 1;
                  uint32_t reserved1: 2;
         // Transmit WS Inversion Enable
         volatile uint32_t FSINVEN: 1;
         // Transmit SCK Inversion Enable
         volatile uint32_t SCLKINVEN: 1;
         // Transmit Order
         volatile uint32_t ORDER: 1;
                  uint32_t reserved2: 1;
         // Transmit Mono Bit-Width Select
         volatile uint32_t MBSEL: 3;
                  uint32_t reserved3: 2;
         // Transmitter Enable
         volatile uint32_t TXEN: 1;
                  uint32_t reserved4: 2;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_TXCONTROL_FSGEN_MASK  0x00000001
#define SI32_I2S_A_TXCONTROL_FSGEN_SHIFT  0
// Disable the internal DFS generator.
#define SI32_I2S_A_TXCONTROL_FSGEN_DISABLED_VALUE  0
#define SI32_I2S_A_TXCONTROL_FSGEN_DISABLED_U32 \
   (SI32_I2S_A_TXCONTROL_FSGEN_DISABLED_VALUE << SI32_I2S_A_TXCONTROL_FSGEN_SHIFT)
// Enable the internal DFS generator.
#define SI32_I2S_A_TXCONTROL_FSGEN_ENABLED_VALUE  1
#define SI32_I2S_A_TXCONTROL_FSGEN_ENABLED_U32 \
   (SI32_I2S_A_TXCONTROL_FSGEN_ENABLED_VALUE << SI32_I2S_A_TXCONTROL_FSGEN_SHIFT)

#define SI32_I2S_A_TXCONTROL_FSSEN_MASK  0x00000002
#define SI32_I2S_A_TXCONTROL_FSSEN_SHIFT  1
// The internal DFS generator starts immediately when FSGEN is set to 1.
#define SI32_I2S_A_TXCONTROL_FSSEN_DISABLED_VALUE  0
#define SI32_I2S_A_TXCONTROL_FSSEN_DISABLED_U32 \
   (SI32_I2S_A_TXCONTROL_FSSEN_DISABLED_VALUE << SI32_I2S_A_TXCONTROL_FSSEN_SHIFT)
// Synchronize the rising edge of the internally generated WS signal from the DFS
// generator to the rising edge of the external WS input signal.
#define SI32_I2S_A_TXCONTROL_FSSEN_ENABLED_VALUE  1
#define SI32_I2S_A_TXCONTROL_FSSEN_ENABLED_U32 \
   (SI32_I2S_A_TXCONTROL_FSSEN_ENABLED_VALUE << SI32_I2S_A_TXCONTROL_FSSEN_SHIFT)

#define SI32_I2S_A_TXCONTROL_DDIS_MASK  0x00000020
#define SI32_I2S_A_TXCONTROL_DDIS_SHIFT  5
// The first data bit is sent on the second or later rising edge of SCK after WS
// changes.
#define SI32_I2S_A_TXCONTROL_DDIS_INACTIVE_VALUE  0
#define SI32_I2S_A_TXCONTROL_DDIS_INACTIVE_U32 \
   (SI32_I2S_A_TXCONTROL_DDIS_INACTIVE_VALUE << SI32_I2S_A_TXCONTROL_DDIS_SHIFT)
// The first data bit is sent on the first rising edge of SCK after WS changes.
#define SI32_I2S_A_TXCONTROL_DDIS_ACTIVE_VALUE  1
#define SI32_I2S_A_TXCONTROL_DDIS_ACTIVE_U32 \
   (SI32_I2S_A_TXCONTROL_DDIS_ACTIVE_VALUE << SI32_I2S_A_TXCONTROL_DDIS_SHIFT)

#define SI32_I2S_A_TXCONTROL_FSDEL_MASK  0x00003FC0
#define SI32_I2S_A_TXCONTROL_FSDEL_SHIFT  6

#define SI32_I2S_A_TXCONTROL_FSSRCSEL_MASK  0x00004000
#define SI32_I2S_A_TXCONTROL_FSSRCSEL_SHIFT  14
// The word select or frame sync is input from the WS pin.
#define SI32_I2S_A_TXCONTROL_FSSRCSEL_FSIN_EXT_VALUE  0
#define SI32_I2S_A_TXCONTROL_FSSRCSEL_FSIN_EXT_U32 \
   (SI32_I2S_A_TXCONTROL_FSSRCSEL_FSIN_EXT_VALUE << SI32_I2S_A_TXCONTROL_FSSRCSEL_SHIFT)
// The word select or frame sync is input from the internal DFS generator.
#define SI32_I2S_A_TXCONTROL_FSSRCSEL_FSIN_INT_VALUE  1
#define SI32_I2S_A_TXCONTROL_FSSRCSEL_FSIN_INT_U32 \
   (SI32_I2S_A_TXCONTROL_FSSRCSEL_FSIN_INT_VALUE << SI32_I2S_A_TXCONTROL_FSSRCSEL_SHIFT)

#define SI32_I2S_A_TXCONTROL_FILLSEL_MASK  0x00018000
#define SI32_I2S_A_TXCONTROL_FILLSEL_SHIFT  15
// Send zeros during unused bit cycles.
#define SI32_I2S_A_TXCONTROL_FILLSEL_ZEROS_VALUE  0
#define SI32_I2S_A_TXCONTROL_FILLSEL_ZEROS_U32 \
   (SI32_I2S_A_TXCONTROL_FILLSEL_ZEROS_VALUE << SI32_I2S_A_TXCONTROL_FILLSEL_SHIFT)
// Send ones during unused bit cycles.
#define SI32_I2S_A_TXCONTROL_FILLSEL_ONES_VALUE  1
#define SI32_I2S_A_TXCONTROL_FILLSEL_ONES_U32 \
   (SI32_I2S_A_TXCONTROL_FILLSEL_ONES_VALUE << SI32_I2S_A_TXCONTROL_FILLSEL_SHIFT)
// Send the sign bit of the current sample (MSB-first format) or last sample (LSB-
// first format) during unused bit cycles.
#define SI32_I2S_A_TXCONTROL_FILLSEL_SIGN_VALUE  2
#define SI32_I2S_A_TXCONTROL_FILLSEL_SIGN_U32 \
   (SI32_I2S_A_TXCONTROL_FILLSEL_SIGN_VALUE << SI32_I2S_A_TXCONTROL_FILLSEL_SHIFT)
// Send pseudo-random data generated by an 8-bit LFSR during unused bit cycles.
#define SI32_I2S_A_TXCONTROL_FILLSEL_RANDOM_VALUE  3
#define SI32_I2S_A_TXCONTROL_FILLSEL_RANDOM_U32 \
   (SI32_I2S_A_TXCONTROL_FILLSEL_RANDOM_VALUE << SI32_I2S_A_TXCONTROL_FILLSEL_SHIFT)

#define SI32_I2S_A_TXCONTROL_JSEL_MASK  0x00020000
#define SI32_I2S_A_TXCONTROL_JSEL_SHIFT  17
// Use left-justified or I2S-style formats.
#define SI32_I2S_A_TXCONTROL_JSEL_LEFT_VALUE  0
#define SI32_I2S_A_TXCONTROL_JSEL_LEFT_U32 \
   (SI32_I2S_A_TXCONTROL_JSEL_LEFT_VALUE << SI32_I2S_A_TXCONTROL_JSEL_SHIFT)
// Use right-justified format.
#define SI32_I2S_A_TXCONTROL_JSEL_RIGHT_VALUE  1
#define SI32_I2S_A_TXCONTROL_JSEL_RIGHT_U32 \
   (SI32_I2S_A_TXCONTROL_JSEL_RIGHT_VALUE << SI32_I2S_A_TXCONTROL_JSEL_SHIFT)

#define SI32_I2S_A_TXCONTROL_FSINVEN_MASK  0x00100000
#define SI32_I2S_A_TXCONTROL_FSINVEN_SHIFT  20
// Don't invert the WS signal. Use this setting for I2S format.
#define SI32_I2S_A_TXCONTROL_FSINVEN_DISABLED_VALUE  0
#define SI32_I2S_A_TXCONTROL_FSINVEN_DISABLED_U32 \
   (SI32_I2S_A_TXCONTROL_FSINVEN_DISABLED_VALUE << SI32_I2S_A_TXCONTROL_FSINVEN_SHIFT)
// Invert the WS signal.
#define SI32_I2S_A_TXCONTROL_FSINVEN_ENABLED_VALUE  1
#define SI32_I2S_A_TXCONTROL_FSINVEN_ENABLED_U32 \
   (SI32_I2S_A_TXCONTROL_FSINVEN_ENABLED_VALUE << SI32_I2S_A_TXCONTROL_FSINVEN_SHIFT)

#define SI32_I2S_A_TXCONTROL_SCLKINVEN_MASK  0x00200000
#define SI32_I2S_A_TXCONTROL_SCLKINVEN_SHIFT  21
// Do not invert the transmitter bit clock.
#define SI32_I2S_A_TXCONTROL_SCLKINVEN_DISABLED_VALUE  0
#define SI32_I2S_A_TXCONTROL_SCLKINVEN_DISABLED_U32 \
   (SI32_I2S_A_TXCONTROL_SCLKINVEN_DISABLED_VALUE << SI32_I2S_A_TXCONTROL_SCLKINVEN_SHIFT)
// Invert the transmitter bit clock.
#define SI32_I2S_A_TXCONTROL_SCLKINVEN_ENABLED_VALUE  1
#define SI32_I2S_A_TXCONTROL_SCLKINVEN_ENABLED_U32 \
   (SI32_I2S_A_TXCONTROL_SCLKINVEN_ENABLED_VALUE << SI32_I2S_A_TXCONTROL_SCLKINVEN_SHIFT)

#define SI32_I2S_A_TXCONTROL_ORDER_MASK  0x00400000
#define SI32_I2S_A_TXCONTROL_ORDER_SHIFT  22
// Left sample transmitted first, right sample transmitted second. Use this setting
// for I2S format.
#define SI32_I2S_A_TXCONTROL_ORDER_LEFT_RIGHT_VALUE  0
#define SI32_I2S_A_TXCONTROL_ORDER_LEFT_RIGHT_U32 \
   (SI32_I2S_A_TXCONTROL_ORDER_LEFT_RIGHT_VALUE << SI32_I2S_A_TXCONTROL_ORDER_SHIFT)
// Right sample transmitted first, left sample transmitted second.
#define SI32_I2S_A_TXCONTROL_ORDER_RIGHT_LEFT_VALUE  1
#define SI32_I2S_A_TXCONTROL_ORDER_RIGHT_LEFT_U32 \
   (SI32_I2S_A_TXCONTROL_ORDER_RIGHT_LEFT_VALUE << SI32_I2S_A_TXCONTROL_ORDER_SHIFT)

#define SI32_I2S_A_TXCONTROL_MBSEL_MASK  0x07000000
#define SI32_I2S_A_TXCONTROL_MBSEL_SHIFT  24
// 8 bits are sent per mono sample.
#define SI32_I2S_A_TXCONTROL_MBSEL_8BITS_VALUE  0
#define SI32_I2S_A_TXCONTROL_MBSEL_8BITS_U32 \
   (SI32_I2S_A_TXCONTROL_MBSEL_8BITS_VALUE << SI32_I2S_A_TXCONTROL_MBSEL_SHIFT)
// 9 bits are sent per mono sample.
#define SI32_I2S_A_TXCONTROL_MBSEL_9BITS_VALUE  1
#define SI32_I2S_A_TXCONTROL_MBSEL_9BITS_U32 \
   (SI32_I2S_A_TXCONTROL_MBSEL_9BITS_VALUE << SI32_I2S_A_TXCONTROL_MBSEL_SHIFT)
// 16 bits are sent per mono sample.
#define SI32_I2S_A_TXCONTROL_MBSEL_16BITS_VALUE  2
#define SI32_I2S_A_TXCONTROL_MBSEL_16BITS_U32 \
   (SI32_I2S_A_TXCONTROL_MBSEL_16BITS_VALUE << SI32_I2S_A_TXCONTROL_MBSEL_SHIFT)
// 24 bits are sent per mono sample.
#define SI32_I2S_A_TXCONTROL_MBSEL_24BITS_VALUE  3
#define SI32_I2S_A_TXCONTROL_MBSEL_24BITS_U32 \
   (SI32_I2S_A_TXCONTROL_MBSEL_24BITS_VALUE << SI32_I2S_A_TXCONTROL_MBSEL_SHIFT)
// 32 bits are sent per mono sample.
#define SI32_I2S_A_TXCONTROL_MBSEL_32BITS_VALUE  4
#define SI32_I2S_A_TXCONTROL_MBSEL_32BITS_U32 \
   (SI32_I2S_A_TXCONTROL_MBSEL_32BITS_VALUE << SI32_I2S_A_TXCONTROL_MBSEL_SHIFT)

#define SI32_I2S_A_TXCONTROL_TXEN_MASK  0x20000000
#define SI32_I2S_A_TXCONTROL_TXEN_SHIFT  29
// Disable the I2S transmitter.
#define SI32_I2S_A_TXCONTROL_TXEN_DISABLED_VALUE  0
#define SI32_I2S_A_TXCONTROL_TXEN_DISABLED_U32 \
   (SI32_I2S_A_TXCONTROL_TXEN_DISABLED_VALUE << SI32_I2S_A_TXCONTROL_TXEN_SHIFT)
// Enable the I2S transmitter.
#define SI32_I2S_A_TXCONTROL_TXEN_ENABLED_VALUE  1
#define SI32_I2S_A_TXCONTROL_TXEN_ENABLED_U32 \
   (SI32_I2S_A_TXCONTROL_TXEN_ENABLED_VALUE << SI32_I2S_A_TXCONTROL_TXEN_SHIFT)



struct SI32_I2S_A_TXMODE_Struct
{
   union
   {
      struct
      {
         // Transmit Clock Cycle Select
         volatile uint32_t CYCLE: 12;
         // Transmit Start Control
         volatile uint32_t START: 8;
         // Transmit Drive Select
         volatile uint32_t SLOTS: 5;
         // Transmit Drive Early Disable
         volatile uint32_t DEDIS: 1;
         // Transmit Drive Inactive Mode
         volatile uint32_t DIMD: 1;
         // Transmit Time Division Multiplexing Enable
         volatile uint32_t TDMEN: 1;
                  uint32_t reserved0: 4;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_TXMODE_CYCLE_MASK  0x00000FFF
#define SI32_I2S_A_TXMODE_CYCLE_SHIFT  0

#define SI32_I2S_A_TXMODE_START_MASK  0x000FF000
#define SI32_I2S_A_TXMODE_START_SHIFT  12

#define SI32_I2S_A_TXMODE_SLOTS_MASK  0x01F00000
#define SI32_I2S_A_TXMODE_SLOTS_SHIFT  20

#define SI32_I2S_A_TXMODE_DEDIS_MASK  0x02000000
#define SI32_I2S_A_TXMODE_DEDIS_SHIFT  25
// Drive the output during every cycle of the transmitter's assigned slot(s),
// including the last clock cycle.
#define SI32_I2S_A_TXMODE_DEDIS_INACTIVE_VALUE  0
#define SI32_I2S_A_TXMODE_DEDIS_INACTIVE_U32 \
   (SI32_I2S_A_TXMODE_DEDIS_INACTIVE_VALUE << SI32_I2S_A_TXMODE_DEDIS_SHIFT)
// Drive the output for every cycle of the transmitter's assigned slot(s), except
// for the last clock cycle of the last slot.
#define SI32_I2S_A_TXMODE_DEDIS_ACTIVE_VALUE  1
#define SI32_I2S_A_TXMODE_DEDIS_ACTIVE_U32 \
   (SI32_I2S_A_TXMODE_DEDIS_ACTIVE_VALUE << SI32_I2S_A_TXMODE_DEDIS_SHIFT)

#define SI32_I2S_A_TXMODE_DIMD_MASK  0x04000000
#define SI32_I2S_A_TXMODE_DIMD_SHIFT  26
// Drive zero on the data output pin during non-active slots.
#define SI32_I2S_A_TXMODE_DIMD_ZERO_VALUE  0
#define SI32_I2S_A_TXMODE_DIMD_ZERO_U32 \
   (SI32_I2S_A_TXMODE_DIMD_ZERO_VALUE << SI32_I2S_A_TXMODE_DIMD_SHIFT)
// Don't drive the data output pin. The data output pin is tristated.
#define SI32_I2S_A_TXMODE_DIMD_HIGH_Z_VALUE  1
#define SI32_I2S_A_TXMODE_DIMD_HIGH_Z_U32 \
   (SI32_I2S_A_TXMODE_DIMD_HIGH_Z_VALUE << SI32_I2S_A_TXMODE_DIMD_SHIFT)

#define SI32_I2S_A_TXMODE_TDMEN_MASK  0x08000000
#define SI32_I2S_A_TXMODE_TDMEN_SHIFT  27
// Disable the time division multiplexing (TDM) feature.
#define SI32_I2S_A_TXMODE_TDMEN_DISABLED_VALUE  0
#define SI32_I2S_A_TXMODE_TDMEN_DISABLED_U32 \
   (SI32_I2S_A_TXMODE_TDMEN_DISABLED_VALUE << SI32_I2S_A_TXMODE_TDMEN_SHIFT)
// Enable the time division multiplexing (TDM) feature.
#define SI32_I2S_A_TXMODE_TDMEN_ENABLED_VALUE  1
#define SI32_I2S_A_TXMODE_TDMEN_ENABLED_U32 \
   (SI32_I2S_A_TXMODE_TDMEN_ENABLED_VALUE << SI32_I2S_A_TXMODE_TDMEN_SHIFT)



struct SI32_I2S_A_FSDUTY_Struct
{
   union
   {
      struct
      {
         // Frame Sync Low Time
         volatile uint16_t FSLOW;
         // Frame Sync High Time
         volatile uint16_t FSHIGH;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_FSDUTY_FSLOW_MASK  0x0000FFFF
#define SI32_I2S_A_FSDUTY_FSLOW_SHIFT  0

#define SI32_I2S_A_FSDUTY_FSHIGH_MASK  0xFFFF0000
#define SI32_I2S_A_FSDUTY_FSHIGH_SHIFT  16



struct SI32_I2S_A_RXCONTROL_Struct
{
   union
   {
      struct
      {
         // Receive Initial Phase Delay
         volatile uint8_t FSDEL;
         // Receive Data Justification
         volatile uint32_t JSEL: 1;
         // Receive Delay Disable
         volatile uint32_t DDIS: 1;
                  uint32_t reserved0: 1;
         // Receive WS Inversion Enable
         volatile uint32_t FSINVEN: 1;
         // Receive SCK Inversion Enable
         volatile uint32_t SCLKINVEN: 1;
         // Receive Order
         volatile uint32_t ORDER: 1;
                  uint32_t reserved1: 1;
         // Receive Mono Bit-Width Select
         volatile uint32_t MBSEL: 3;
                  uint32_t reserved2: 2;
         // Receive Frame Sync Source Select
         volatile uint32_t FSSRCSEL: 1;
         // Receive Enable
         volatile uint32_t RXEN: 1;
                  uint32_t reserved3: 10;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_RXCONTROL_FSDEL_MASK  0x000000FF
#define SI32_I2S_A_RXCONTROL_FSDEL_SHIFT  0

#define SI32_I2S_A_RXCONTROL_JSEL_MASK  0x00000100
#define SI32_I2S_A_RXCONTROL_JSEL_SHIFT  8
// Use left-justified or I2S-style formats.
#define SI32_I2S_A_RXCONTROL_JSEL_LEFT_VALUE  0
#define SI32_I2S_A_RXCONTROL_JSEL_LEFT_U32 \
   (SI32_I2S_A_RXCONTROL_JSEL_LEFT_VALUE << SI32_I2S_A_RXCONTROL_JSEL_SHIFT)
// Use right-justified format.
#define SI32_I2S_A_RXCONTROL_JSEL_RIGHT_VALUE  1
#define SI32_I2S_A_RXCONTROL_JSEL_RIGHT_U32 \
   (SI32_I2S_A_RXCONTROL_JSEL_RIGHT_VALUE << SI32_I2S_A_RXCONTROL_JSEL_SHIFT)

#define SI32_I2S_A_RXCONTROL_DDIS_MASK  0x00000200
#define SI32_I2S_A_RXCONTROL_DDIS_SHIFT  9
// The first data bit is captured on the second or later rising edge of SCK after
// WS changes.
#define SI32_I2S_A_RXCONTROL_DDIS_INACTIVE_VALUE  0
#define SI32_I2S_A_RXCONTROL_DDIS_INACTIVE_U32 \
   (SI32_I2S_A_RXCONTROL_DDIS_INACTIVE_VALUE << SI32_I2S_A_RXCONTROL_DDIS_SHIFT)
// The first data bit is captured by the receiver on the first rising edge of SCK
// after WS changes.
#define SI32_I2S_A_RXCONTROL_DDIS_ACTIVE_VALUE  1
#define SI32_I2S_A_RXCONTROL_DDIS_ACTIVE_U32 \
   (SI32_I2S_A_RXCONTROL_DDIS_ACTIVE_VALUE << SI32_I2S_A_RXCONTROL_DDIS_SHIFT)

#define SI32_I2S_A_RXCONTROL_FSINVEN_MASK  0x00000800
#define SI32_I2S_A_RXCONTROL_FSINVEN_SHIFT  11
// Don't invert the WS signal. Use this setting for I2S format.
#define SI32_I2S_A_RXCONTROL_FSINVEN_DISABLED_VALUE  0
#define SI32_I2S_A_RXCONTROL_FSINVEN_DISABLED_U32 \
   (SI32_I2S_A_RXCONTROL_FSINVEN_DISABLED_VALUE << SI32_I2S_A_RXCONTROL_FSINVEN_SHIFT)
// Invert the WS signal.
#define SI32_I2S_A_RXCONTROL_FSINVEN_ENABLED_VALUE  1
#define SI32_I2S_A_RXCONTROL_FSINVEN_ENABLED_U32 \
   (SI32_I2S_A_RXCONTROL_FSINVEN_ENABLED_VALUE << SI32_I2S_A_RXCONTROL_FSINVEN_SHIFT)

#define SI32_I2S_A_RXCONTROL_SCLKINVEN_MASK  0x00001000
#define SI32_I2S_A_RXCONTROL_SCLKINVEN_SHIFT  12
// Do not invert the receiver bit clock.
#define SI32_I2S_A_RXCONTROL_SCLKINVEN_DISABLED_VALUE  0
#define SI32_I2S_A_RXCONTROL_SCLKINVEN_DISABLED_U32 \
   (SI32_I2S_A_RXCONTROL_SCLKINVEN_DISABLED_VALUE << SI32_I2S_A_RXCONTROL_SCLKINVEN_SHIFT)
// Invert the receiver bit clock.
#define SI32_I2S_A_RXCONTROL_SCLKINVEN_ENABLED_VALUE  1
#define SI32_I2S_A_RXCONTROL_SCLKINVEN_ENABLED_U32 \
   (SI32_I2S_A_RXCONTROL_SCLKINVEN_ENABLED_VALUE << SI32_I2S_A_RXCONTROL_SCLKINVEN_SHIFT)

#define SI32_I2S_A_RXCONTROL_ORDER_MASK  0x00002000
#define SI32_I2S_A_RXCONTROL_ORDER_SHIFT  13
// Left sample received first, right sample received second. Use this setting for
// I2S format.
#define SI32_I2S_A_RXCONTROL_ORDER_LEFT_RIGHT_VALUE  0
#define SI32_I2S_A_RXCONTROL_ORDER_LEFT_RIGHT_U32 \
   (SI32_I2S_A_RXCONTROL_ORDER_LEFT_RIGHT_VALUE << SI32_I2S_A_RXCONTROL_ORDER_SHIFT)
// Right sample received first, left sample received second.
#define SI32_I2S_A_RXCONTROL_ORDER_RIGHT_LEFT_VALUE  1
#define SI32_I2S_A_RXCONTROL_ORDER_RIGHT_LEFT_U32 \
   (SI32_I2S_A_RXCONTROL_ORDER_RIGHT_LEFT_VALUE << SI32_I2S_A_RXCONTROL_ORDER_SHIFT)

#define SI32_I2S_A_RXCONTROL_MBSEL_MASK  0x00038000
#define SI32_I2S_A_RXCONTROL_MBSEL_SHIFT  15
// 8 bits are received per mono sample.
#define SI32_I2S_A_RXCONTROL_MBSEL_8BITS_VALUE  0
#define SI32_I2S_A_RXCONTROL_MBSEL_8BITS_U32 \
   (SI32_I2S_A_RXCONTROL_MBSEL_8BITS_VALUE << SI32_I2S_A_RXCONTROL_MBSEL_SHIFT)
// 9 bits are received per mono sample.
#define SI32_I2S_A_RXCONTROL_MBSEL_9BITS_VALUE  1
#define SI32_I2S_A_RXCONTROL_MBSEL_9BITS_U32 \
   (SI32_I2S_A_RXCONTROL_MBSEL_9BITS_VALUE << SI32_I2S_A_RXCONTROL_MBSEL_SHIFT)
// 16 bits are received per mono sample.
#define SI32_I2S_A_RXCONTROL_MBSEL_16BITS_VALUE  2
#define SI32_I2S_A_RXCONTROL_MBSEL_16BITS_U32 \
   (SI32_I2S_A_RXCONTROL_MBSEL_16BITS_VALUE << SI32_I2S_A_RXCONTROL_MBSEL_SHIFT)
// 24 bits are received per mono sample.
#define SI32_I2S_A_RXCONTROL_MBSEL_24BITS_VALUE  3
#define SI32_I2S_A_RXCONTROL_MBSEL_24BITS_U32 \
   (SI32_I2S_A_RXCONTROL_MBSEL_24BITS_VALUE << SI32_I2S_A_RXCONTROL_MBSEL_SHIFT)
// 32 bits are received per mono sample.
#define SI32_I2S_A_RXCONTROL_MBSEL_32BITS_VALUE  4
#define SI32_I2S_A_RXCONTROL_MBSEL_32BITS_U32 \
   (SI32_I2S_A_RXCONTROL_MBSEL_32BITS_VALUE << SI32_I2S_A_RXCONTROL_MBSEL_SHIFT)

#define SI32_I2S_A_RXCONTROL_FSSRCSEL_MASK  0x00100000
#define SI32_I2S_A_RXCONTROL_FSSRCSEL_SHIFT  20
// The word select or frame sync is input from the WS pin.
#define SI32_I2S_A_RXCONTROL_FSSRCSEL_FSIN_EXT_VALUE  0
#define SI32_I2S_A_RXCONTROL_FSSRCSEL_FSIN_EXT_U32 \
   (SI32_I2S_A_RXCONTROL_FSSRCSEL_FSIN_EXT_VALUE << SI32_I2S_A_RXCONTROL_FSSRCSEL_SHIFT)
// The word select or frame sync is input from the internal DFS generator.
#define SI32_I2S_A_RXCONTROL_FSSRCSEL_FSIN_INT_VALUE  1
#define SI32_I2S_A_RXCONTROL_FSSRCSEL_FSIN_INT_U32 \
   (SI32_I2S_A_RXCONTROL_FSSRCSEL_FSIN_INT_VALUE << SI32_I2S_A_RXCONTROL_FSSRCSEL_SHIFT)

#define SI32_I2S_A_RXCONTROL_RXEN_MASK  0x00200000
#define SI32_I2S_A_RXCONTROL_RXEN_SHIFT  21
// Disable the I2S receiver.
#define SI32_I2S_A_RXCONTROL_RXEN_DISABLED_VALUE  0
#define SI32_I2S_A_RXCONTROL_RXEN_DISABLED_U32 \
   (SI32_I2S_A_RXCONTROL_RXEN_DISABLED_VALUE << SI32_I2S_A_RXCONTROL_RXEN_SHIFT)
// Enable the I2S receiver.
#define SI32_I2S_A_RXCONTROL_RXEN_ENABLED_VALUE  1
#define SI32_I2S_A_RXCONTROL_RXEN_ENABLED_U32 \
   (SI32_I2S_A_RXCONTROL_RXEN_ENABLED_VALUE << SI32_I2S_A_RXCONTROL_RXEN_SHIFT)



struct SI32_I2S_A_RXMODE_Struct
{
   union
   {
      struct
      {
         // Receive Clock Cycle Select
         volatile uint32_t CYCLE: 12;
         // Receive Start Control
         volatile uint32_t START: 8;
         // Receive Drive Select
         volatile uint32_t SLOTS: 6;
                  uint32_t reserved0: 1;
         // Receive Time Division Multiplexing Enable
         volatile uint32_t TDMEN: 1;
                  uint32_t reserved1: 4;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_RXMODE_CYCLE_MASK  0x00000FFF
#define SI32_I2S_A_RXMODE_CYCLE_SHIFT  0

#define SI32_I2S_A_RXMODE_START_MASK  0x000FF000
#define SI32_I2S_A_RXMODE_START_SHIFT  12

#define SI32_I2S_A_RXMODE_SLOTS_MASK  0x03F00000
#define SI32_I2S_A_RXMODE_SLOTS_SHIFT  20

#define SI32_I2S_A_RXMODE_TDMEN_MASK  0x08000000
#define SI32_I2S_A_RXMODE_TDMEN_SHIFT  27
// Disable the time division multiplexing (TDM) feature.
#define SI32_I2S_A_RXMODE_TDMEN_DISABLED_VALUE  0
#define SI32_I2S_A_RXMODE_TDMEN_DISABLED_U32 \
   (SI32_I2S_A_RXMODE_TDMEN_DISABLED_VALUE << SI32_I2S_A_RXMODE_TDMEN_SHIFT)
// Enable the time division multiplexing (TDM) feature.
#define SI32_I2S_A_RXMODE_TDMEN_ENABLED_VALUE  1
#define SI32_I2S_A_RXMODE_TDMEN_ENABLED_U32 \
   (SI32_I2S_A_RXMODE_TDMEN_ENABLED_VALUE << SI32_I2S_A_RXMODE_TDMEN_SHIFT)



struct SI32_I2S_A_CLKCONTROL_Struct
{
   union
   {
      struct
      {
         // Clock Divider Integer Value
         volatile uint32_t INTDIV: 10;
         // Clock Divider Fractional Value
         volatile uint32_t FRACDIV: 8;
         // Duty Cycle Adjustment Mode
         volatile uint32_t DUTYMD: 1;
         // Clock Divider Update
         volatile uint32_t CLKUPD: 1;
         // Clock Divider Enable
         volatile uint32_t DIVEN: 1;
         // Transmit Clock Select
         volatile uint32_t TXCLKSEL: 1;
         // Receive Clock Select
         volatile uint32_t RXCLKSEL: 1;
         // I2S Module Reset
         volatile uint32_t RESET: 1;
         // Receive Clock Enable
         volatile uint32_t RXCLKEN: 1;
         // Transmit Clock Enable
         volatile uint32_t TXCLKEN: 1;
         // Receive SCK Mode
         volatile uint32_t RXSCLKMD: 1;
         // Transmit SCK Mode
         volatile uint32_t TXSCLKMD: 1;
                  uint32_t reserved0: 4;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_CLKCONTROL_INTDIV_MASK  0x000003FF
#define SI32_I2S_A_CLKCONTROL_INTDIV_SHIFT  0

#define SI32_I2S_A_CLKCONTROL_FRACDIV_MASK  0x0003FC00
#define SI32_I2S_A_CLKCONTROL_FRACDIV_SHIFT  10

#define SI32_I2S_A_CLKCONTROL_DUTYMD_MASK  0x00040000
#define SI32_I2S_A_CLKCONTROL_DUTYMD_SHIFT  18
// When the division is fractional, the clock high time will be greater than 50%
// (by half of the source clock period).
#define SI32_I2S_A_CLKCONTROL_DUTYMD_MORE_VALUE  0
#define SI32_I2S_A_CLKCONTROL_DUTYMD_MORE_U32 \
   (SI32_I2S_A_CLKCONTROL_DUTYMD_MORE_VALUE << SI32_I2S_A_CLKCONTROL_DUTYMD_SHIFT)
// When the division is fractional, the clock low time will be greater than 50% (by
// half of the source clock period).
#define SI32_I2S_A_CLKCONTROL_DUTYMD_LESS_VALUE  1
#define SI32_I2S_A_CLKCONTROL_DUTYMD_LESS_U32 \
   (SI32_I2S_A_CLKCONTROL_DUTYMD_LESS_VALUE << SI32_I2S_A_CLKCONTROL_DUTYMD_SHIFT)

#define SI32_I2S_A_CLKCONTROL_CLKUPD_MASK  0x00080000
#define SI32_I2S_A_CLKCONTROL_CLKUPD_SHIFT  19
// Update the clock divider with new values of INTDIV, FRACDIV, and DIVEN.
#define SI32_I2S_A_CLKCONTROL_CLKUPD_UPDATE_VALUE  1
#define SI32_I2S_A_CLKCONTROL_CLKUPD_UPDATE_U32 \
   (SI32_I2S_A_CLKCONTROL_CLKUPD_UPDATE_VALUE << SI32_I2S_A_CLKCONTROL_CLKUPD_SHIFT)

#define SI32_I2S_A_CLKCONTROL_DIVEN_MASK  0x00100000
#define SI32_I2S_A_CLKCONTROL_DIVEN_SHIFT  20
// Disable the clock divider.
#define SI32_I2S_A_CLKCONTROL_DIVEN_DISABLED_VALUE  0
#define SI32_I2S_A_CLKCONTROL_DIVEN_DISABLED_U32 \
   (SI32_I2S_A_CLKCONTROL_DIVEN_DISABLED_VALUE << SI32_I2S_A_CLKCONTROL_DIVEN_SHIFT)
// Enable the clock divider.
#define SI32_I2S_A_CLKCONTROL_DIVEN_ENABLED_VALUE  1
#define SI32_I2S_A_CLKCONTROL_DIVEN_ENABLED_U32 \
   (SI32_I2S_A_CLKCONTROL_DIVEN_ENABLED_VALUE << SI32_I2S_A_CLKCONTROL_DIVEN_SHIFT)

#define SI32_I2S_A_CLKCONTROL_TXCLKSEL_MASK  0x00200000
#define SI32_I2S_A_CLKCONTROL_TXCLKSEL_SHIFT  21
// The I2S transmitter is clocked from the internal clock divider.
#define SI32_I2S_A_CLKCONTROL_TXCLKSEL_INTERNAL_VALUE  0
#define SI32_I2S_A_CLKCONTROL_TXCLKSEL_INTERNAL_U32 \
   (SI32_I2S_A_CLKCONTROL_TXCLKSEL_INTERNAL_VALUE << SI32_I2S_A_CLKCONTROL_TXCLKSEL_SHIFT)
// The I2S transmitter is clocked from the SCK pin.
#define SI32_I2S_A_CLKCONTROL_TXCLKSEL_EXTERNAL_VALUE  1
#define SI32_I2S_A_CLKCONTROL_TXCLKSEL_EXTERNAL_U32 \
   (SI32_I2S_A_CLKCONTROL_TXCLKSEL_EXTERNAL_VALUE << SI32_I2S_A_CLKCONTROL_TXCLKSEL_SHIFT)

#define SI32_I2S_A_CLKCONTROL_RXCLKSEL_MASK  0x00400000
#define SI32_I2S_A_CLKCONTROL_RXCLKSEL_SHIFT  22
// The I2S receiver is clocked from the internal clock divider.
#define SI32_I2S_A_CLKCONTROL_RXCLKSEL_INTERNAL_VALUE  0
#define SI32_I2S_A_CLKCONTROL_RXCLKSEL_INTERNAL_U32 \
   (SI32_I2S_A_CLKCONTROL_RXCLKSEL_INTERNAL_VALUE << SI32_I2S_A_CLKCONTROL_RXCLKSEL_SHIFT)
// The I2S receiver is clocked from the SCK pin.
#define SI32_I2S_A_CLKCONTROL_RXCLKSEL_EXTERNAL_VALUE  1
#define SI32_I2S_A_CLKCONTROL_RXCLKSEL_EXTERNAL_U32 \
   (SI32_I2S_A_CLKCONTROL_RXCLKSEL_EXTERNAL_VALUE << SI32_I2S_A_CLKCONTROL_RXCLKSEL_SHIFT)

#define SI32_I2S_A_CLKCONTROL_RESET_MASK  0x00800000
#define SI32_I2S_A_CLKCONTROL_RESET_SHIFT  23
// Reset the I2S module.
#define SI32_I2S_A_CLKCONTROL_RESET_ACTIVE_VALUE  1
#define SI32_I2S_A_CLKCONTROL_RESET_ACTIVE_U32 \
   (SI32_I2S_A_CLKCONTROL_RESET_ACTIVE_VALUE << SI32_I2S_A_CLKCONTROL_RESET_SHIFT)

#define SI32_I2S_A_CLKCONTROL_RXCLKEN_MASK  0x01000000
#define SI32_I2S_A_CLKCONTROL_RXCLKEN_SHIFT  24
// Disable the I2S receiver clock.
#define SI32_I2S_A_CLKCONTROL_RXCLKEN_DISABLED_VALUE  0
#define SI32_I2S_A_CLKCONTROL_RXCLKEN_DISABLED_U32 \
   (SI32_I2S_A_CLKCONTROL_RXCLKEN_DISABLED_VALUE << SI32_I2S_A_CLKCONTROL_RXCLKEN_SHIFT)
// Enable the I2S receiver clock.
#define SI32_I2S_A_CLKCONTROL_RXCLKEN_ENABLED_VALUE  1
#define SI32_I2S_A_CLKCONTROL_RXCLKEN_ENABLED_U32 \
   (SI32_I2S_A_CLKCONTROL_RXCLKEN_ENABLED_VALUE << SI32_I2S_A_CLKCONTROL_RXCLKEN_SHIFT)

#define SI32_I2S_A_CLKCONTROL_TXCLKEN_MASK  0x02000000
#define SI32_I2S_A_CLKCONTROL_TXCLKEN_SHIFT  25
// Disable the I2S transmitter clock.
#define SI32_I2S_A_CLKCONTROL_TXCLKEN_DISABLED_VALUE  0
#define SI32_I2S_A_CLKCONTROL_TXCLKEN_DISABLED_U32 \
   (SI32_I2S_A_CLKCONTROL_TXCLKEN_DISABLED_VALUE << SI32_I2S_A_CLKCONTROL_TXCLKEN_SHIFT)
// Enable the I2S transmitter clock.
#define SI32_I2S_A_CLKCONTROL_TXCLKEN_ENABLED_VALUE  1
#define SI32_I2S_A_CLKCONTROL_TXCLKEN_ENABLED_U32 \
   (SI32_I2S_A_CLKCONTROL_TXCLKEN_ENABLED_VALUE << SI32_I2S_A_CLKCONTROL_TXCLKEN_SHIFT)

#define SI32_I2S_A_CLKCONTROL_RXSCLKMD_MASK  0x04000000
#define SI32_I2S_A_CLKCONTROL_RXSCLKMD_SHIFT  26
// The I2S receiver SCK signal is an output.
#define SI32_I2S_A_CLKCONTROL_RXSCLKMD_SCK_OUTPUT_VALUE  0
#define SI32_I2S_A_CLKCONTROL_RXSCLKMD_SCK_OUTPUT_U32 \
   (SI32_I2S_A_CLKCONTROL_RXSCLKMD_SCK_OUTPUT_VALUE << SI32_I2S_A_CLKCONTROL_RXSCLKMD_SHIFT)
// The I2S receiver SCK signal is an input.
#define SI32_I2S_A_CLKCONTROL_RXSCLKMD_SCK_INPUT_VALUE  1
#define SI32_I2S_A_CLKCONTROL_RXSCLKMD_SCK_INPUT_U32 \
   (SI32_I2S_A_CLKCONTROL_RXSCLKMD_SCK_INPUT_VALUE << SI32_I2S_A_CLKCONTROL_RXSCLKMD_SHIFT)

#define SI32_I2S_A_CLKCONTROL_TXSCLKMD_MASK  0x08000000
#define SI32_I2S_A_CLKCONTROL_TXSCLKMD_SHIFT  27
// The I2S transmitter SCK signal is an output.
#define SI32_I2S_A_CLKCONTROL_TXSCLKMD_SCK_OUTPUT_VALUE  0
#define SI32_I2S_A_CLKCONTROL_TXSCLKMD_SCK_OUTPUT_U32 \
   (SI32_I2S_A_CLKCONTROL_TXSCLKMD_SCK_OUTPUT_VALUE << SI32_I2S_A_CLKCONTROL_TXSCLKMD_SHIFT)
// The I2S transmitter SCK signal is an input.
#define SI32_I2S_A_CLKCONTROL_TXSCLKMD_SCK_INPUT_VALUE  1
#define SI32_I2S_A_CLKCONTROL_TXSCLKMD_SCK_INPUT_U32 \
   (SI32_I2S_A_CLKCONTROL_TXSCLKMD_SCK_INPUT_VALUE << SI32_I2S_A_CLKCONTROL_TXSCLKMD_SHIFT)



struct SI32_I2S_A_TXFIFO_Struct
{
   union
   {
      // This is a FIFO register
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_TXFIFO_TXFIFO_MASK  0xFFFFFFFF
#define SI32_I2S_A_TXFIFO_TXFIFO_SHIFT  0



struct SI32_I2S_A_RXFIFO_Struct
{
   union
   {
      // This is a FIFO register
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_RXFIFO_RXFIFO_MASK  0xFFFFFFFF
#define SI32_I2S_A_RXFIFO_RXFIFO_SHIFT  0



struct SI32_I2S_A_FIFOSTATUS_Struct
{
   union
   {
      struct
      {
         // Transmit FIFO Status
         volatile uint32_t TXFIFONUM: 4;
                  uint32_t reserved0: 12;
         // Receive FIFO Status
         volatile uint32_t RXFIFONUM: 4;
                  uint32_t reserved1: 12;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_FIFOSTATUS_TXFIFONUM_MASK  0x0000000F
#define SI32_I2S_A_FIFOSTATUS_TXFIFONUM_SHIFT  0

#define SI32_I2S_A_FIFOSTATUS_RXFIFONUM_MASK  0x000F0000
#define SI32_I2S_A_FIFOSTATUS_RXFIFONUM_SHIFT  16



struct SI32_I2S_A_FIFOCONTROL_Struct
{
   union
   {
      struct
      {
         // Transmit FIFO Low Watermark
         volatile uint32_t TXFIFOWM: 4;
                  uint32_t reserved0: 12;
         // Receive FIFO High Watermark
         volatile uint32_t RXFIFOWM: 4;
                  uint32_t reserved1: 1;
         // Transmit FIFO Flush
         volatile uint32_t TXFIFOFL: 1;
         // Receive FIFO Flush
         volatile uint32_t RXFIFOFL: 1;
                  uint32_t reserved2: 9;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_FIFOCONTROL_TXFIFOWM_MASK  0x0000000F
#define SI32_I2S_A_FIFOCONTROL_TXFIFOWM_SHIFT  0

#define SI32_I2S_A_FIFOCONTROL_RXFIFOWM_MASK  0x000F0000
#define SI32_I2S_A_FIFOCONTROL_RXFIFOWM_SHIFT  16

#define SI32_I2S_A_FIFOCONTROL_TXFIFOFL_MASK  0x00200000
#define SI32_I2S_A_FIFOCONTROL_TXFIFOFL_SHIFT  21
// Flush the I2S transmitter FIFO.
#define SI32_I2S_A_FIFOCONTROL_TXFIFOFL_SET_VALUE  1
#define SI32_I2S_A_FIFOCONTROL_TXFIFOFL_SET_U32 \
   (SI32_I2S_A_FIFOCONTROL_TXFIFOFL_SET_VALUE << SI32_I2S_A_FIFOCONTROL_TXFIFOFL_SHIFT)

#define SI32_I2S_A_FIFOCONTROL_RXFIFOFL_MASK  0x00400000
#define SI32_I2S_A_FIFOCONTROL_RXFIFOFL_SHIFT  22
// Flush the I2S receiver FIFO.
#define SI32_I2S_A_FIFOCONTROL_RXFIFOFL_SET_VALUE  1
#define SI32_I2S_A_FIFOCONTROL_RXFIFOFL_SET_U32 \
   (SI32_I2S_A_FIFOCONTROL_RXFIFOFL_SET_VALUE << SI32_I2S_A_FIFOCONTROL_RXFIFOFL_SHIFT)



struct SI32_I2S_A_INTCONTROL_Struct
{
   union
   {
      struct
      {
         // Transmit Underflow Interrupt Enable
         volatile uint32_t TXUFIEN: 1;
         // Receive Overflow Interrupt Enable
         volatile uint32_t RXOFIEN: 1;
         // Transmit FIFO Low Watermark Interrupt Enable
         volatile uint32_t TXLWMIEN: 1;
         // Receive FIFO High Watermark Interrupt Enable
         volatile uint32_t RXHWMIEN: 1;
                  uint32_t reserved0: 28;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_INTCONTROL_TXUFIEN_MASK  0x00000001
#define SI32_I2S_A_INTCONTROL_TXUFIEN_SHIFT  0
// Disable the transmit underflow interrupt.
#define SI32_I2S_A_INTCONTROL_TXUFIEN_DISABLED_VALUE  0
#define SI32_I2S_A_INTCONTROL_TXUFIEN_DISABLED_U32 \
   (SI32_I2S_A_INTCONTROL_TXUFIEN_DISABLED_VALUE << SI32_I2S_A_INTCONTROL_TXUFIEN_SHIFT)
// Enable the transmit underflow interrupt.
#define SI32_I2S_A_INTCONTROL_TXUFIEN_ENABLED_VALUE  1
#define SI32_I2S_A_INTCONTROL_TXUFIEN_ENABLED_U32 \
   (SI32_I2S_A_INTCONTROL_TXUFIEN_ENABLED_VALUE << SI32_I2S_A_INTCONTROL_TXUFIEN_SHIFT)

#define SI32_I2S_A_INTCONTROL_RXOFIEN_MASK  0x00000002
#define SI32_I2S_A_INTCONTROL_RXOFIEN_SHIFT  1
// Disable the receive overflow interrupt.
#define SI32_I2S_A_INTCONTROL_RXOFIEN_DISABLED_VALUE  0
#define SI32_I2S_A_INTCONTROL_RXOFIEN_DISABLED_U32 \
   (SI32_I2S_A_INTCONTROL_RXOFIEN_DISABLED_VALUE << SI32_I2S_A_INTCONTROL_RXOFIEN_SHIFT)
// Enable the receive overflow interrupt.
#define SI32_I2S_A_INTCONTROL_RXOFIEN_ENABLED_VALUE  1
#define SI32_I2S_A_INTCONTROL_RXOFIEN_ENABLED_U32 \
   (SI32_I2S_A_INTCONTROL_RXOFIEN_ENABLED_VALUE << SI32_I2S_A_INTCONTROL_RXOFIEN_SHIFT)

#define SI32_I2S_A_INTCONTROL_TXLWMIEN_MASK  0x00000004
#define SI32_I2S_A_INTCONTROL_TXLWMIEN_SHIFT  2
// Disable the transmit FIFO low watermark interrupt.
#define SI32_I2S_A_INTCONTROL_TXLWMIEN_DISABLED_VALUE  0
#define SI32_I2S_A_INTCONTROL_TXLWMIEN_DISABLED_U32 \
   (SI32_I2S_A_INTCONTROL_TXLWMIEN_DISABLED_VALUE << SI32_I2S_A_INTCONTROL_TXLWMIEN_SHIFT)
// Enable the transmit FIFO low watermark interrupt.
#define SI32_I2S_A_INTCONTROL_TXLWMIEN_ENABLED_VALUE  1
#define SI32_I2S_A_INTCONTROL_TXLWMIEN_ENABLED_U32 \
   (SI32_I2S_A_INTCONTROL_TXLWMIEN_ENABLED_VALUE << SI32_I2S_A_INTCONTROL_TXLWMIEN_SHIFT)

#define SI32_I2S_A_INTCONTROL_RXHWMIEN_MASK  0x00000008
#define SI32_I2S_A_INTCONTROL_RXHWMIEN_SHIFT  3
// Disable the receive FIFO high watermark interrupt.
#define SI32_I2S_A_INTCONTROL_RXHWMIEN_DISABLED_VALUE  0
#define SI32_I2S_A_INTCONTROL_RXHWMIEN_DISABLED_U32 \
   (SI32_I2S_A_INTCONTROL_RXHWMIEN_DISABLED_VALUE << SI32_I2S_A_INTCONTROL_RXHWMIEN_SHIFT)
// Enable the receive FIFO high watermark interrupt.
#define SI32_I2S_A_INTCONTROL_RXHWMIEN_ENABLED_VALUE  1
#define SI32_I2S_A_INTCONTROL_RXHWMIEN_ENABLED_U32 \
   (SI32_I2S_A_INTCONTROL_RXHWMIEN_ENABLED_VALUE << SI32_I2S_A_INTCONTROL_RXHWMIEN_SHIFT)



struct SI32_I2S_A_STATUS_Struct
{
   union
   {
      struct
      {
         // Transmit Underflow Interrupt Flag
         volatile uint32_t TXUFI: 1;
         // Receive Overflow Interrupt Flag
         volatile uint32_t RXOFI: 1;
         // Transmit FIFO Low Watermark Interrupt Flag
         volatile uint32_t TXLWMI: 1;
         // Receive FIFO High Watermark Interrupt Flag
         volatile uint32_t RXHWMI: 1;
         // Clock Divider Busy Flag
         volatile uint32_t CDBUSYF: 1;
         // Clock Divider Counter Status
         volatile uint32_t CDSTS: 1;
         // Transmit Clock Select Ready Flag
         volatile uint32_t TXCLKSELRF: 1;
         // Receive Clock Select Ready Flag
         volatile uint32_t RXCLKSELRF: 1;
         // Transmit Clock Enable Ready Flag
         volatile uint32_t TXCLKENRF: 1;
         // Receive Clock Enable Ready Flag
         volatile uint32_t RXCLKENRF: 1;
                  uint32_t reserved0: 22;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_STATUS_TXUFI_MASK  0x00000001
#define SI32_I2S_A_STATUS_TXUFI_SHIFT  0
// A transmit underflow has not occurred.
#define SI32_I2S_A_STATUS_TXUFI_NOT_SET_VALUE  0
#define SI32_I2S_A_STATUS_TXUFI_NOT_SET_U32 \
   (SI32_I2S_A_STATUS_TXUFI_NOT_SET_VALUE << SI32_I2S_A_STATUS_TXUFI_SHIFT)
// A transmit underflow occurred.
#define SI32_I2S_A_STATUS_TXUFI_SET_VALUE  1
#define SI32_I2S_A_STATUS_TXUFI_SET_U32 \
   (SI32_I2S_A_STATUS_TXUFI_SET_VALUE << SI32_I2S_A_STATUS_TXUFI_SHIFT)

#define SI32_I2S_A_STATUS_RXOFI_MASK  0x00000002
#define SI32_I2S_A_STATUS_RXOFI_SHIFT  1
// A receive overflow has not occurred.
#define SI32_I2S_A_STATUS_RXOFI_NOT_SET_VALUE  0
#define SI32_I2S_A_STATUS_RXOFI_NOT_SET_U32 \
   (SI32_I2S_A_STATUS_RXOFI_NOT_SET_VALUE << SI32_I2S_A_STATUS_RXOFI_SHIFT)
// A receive overflow occurred.
#define SI32_I2S_A_STATUS_RXOFI_SET_VALUE  1
#define SI32_I2S_A_STATUS_RXOFI_SET_U32 \
   (SI32_I2S_A_STATUS_RXOFI_SET_VALUE << SI32_I2S_A_STATUS_RXOFI_SHIFT)

#define SI32_I2S_A_STATUS_TXLWMI_MASK  0x00000004
#define SI32_I2S_A_STATUS_TXLWMI_SHIFT  2
// Transmit FIFO level is above the low watermark.
#define SI32_I2S_A_STATUS_TXLWMI_NOT_SET_VALUE  0
#define SI32_I2S_A_STATUS_TXLWMI_NOT_SET_U32 \
   (SI32_I2S_A_STATUS_TXLWMI_NOT_SET_VALUE << SI32_I2S_A_STATUS_TXLWMI_SHIFT)
// Transmit FIFO level is at or below the low watermark.
#define SI32_I2S_A_STATUS_TXLWMI_SET_VALUE  1
#define SI32_I2S_A_STATUS_TXLWMI_SET_U32 \
   (SI32_I2S_A_STATUS_TXLWMI_SET_VALUE << SI32_I2S_A_STATUS_TXLWMI_SHIFT)

#define SI32_I2S_A_STATUS_RXHWMI_MASK  0x00000008
#define SI32_I2S_A_STATUS_RXHWMI_SHIFT  3
// Receive FIFO level is below the high watermark.
#define SI32_I2S_A_STATUS_RXHWMI_NOT_SET_VALUE  0
#define SI32_I2S_A_STATUS_RXHWMI_NOT_SET_U32 \
   (SI32_I2S_A_STATUS_RXHWMI_NOT_SET_VALUE << SI32_I2S_A_STATUS_RXHWMI_SHIFT)
// Receive FIFO level is at or above the high watermark.
#define SI32_I2S_A_STATUS_RXHWMI_SET_VALUE  1
#define SI32_I2S_A_STATUS_RXHWMI_SET_U32 \
   (SI32_I2S_A_STATUS_RXHWMI_SET_VALUE << SI32_I2S_A_STATUS_RXHWMI_SHIFT)

#define SI32_I2S_A_STATUS_CDBUSYF_MASK  0x00000010
#define SI32_I2S_A_STATUS_CDBUSYF_SHIFT  4
// The divider is not busy and an update is not pending.
#define SI32_I2S_A_STATUS_CDBUSYF_NOT_BUSY_VALUE  0
#define SI32_I2S_A_STATUS_CDBUSYF_NOT_BUSY_U32 \
   (SI32_I2S_A_STATUS_CDBUSYF_NOT_BUSY_VALUE << SI32_I2S_A_STATUS_CDBUSYF_SHIFT)
// The divider is busy and an update is pending.
#define SI32_I2S_A_STATUS_CDBUSYF_BUSY_VALUE  1
#define SI32_I2S_A_STATUS_CDBUSYF_BUSY_U32 \
   (SI32_I2S_A_STATUS_CDBUSYF_BUSY_VALUE << SI32_I2S_A_STATUS_CDBUSYF_SHIFT)

#define SI32_I2S_A_STATUS_CDSTS_MASK  0x00000020
#define SI32_I2S_A_STATUS_CDSTS_SHIFT  5
// Divided clock output is running.
#define SI32_I2S_A_STATUS_CDSTS_RUNNING_VALUE  0
#define SI32_I2S_A_STATUS_CDSTS_RUNNING_U32 \
   (SI32_I2S_A_STATUS_CDSTS_RUNNING_VALUE << SI32_I2S_A_STATUS_CDSTS_SHIFT)
// Divided clock output is halted.
#define SI32_I2S_A_STATUS_CDSTS_HALTED_VALUE  1
#define SI32_I2S_A_STATUS_CDSTS_HALTED_U32 \
   (SI32_I2S_A_STATUS_CDSTS_HALTED_VALUE << SI32_I2S_A_STATUS_CDSTS_SHIFT)

#define SI32_I2S_A_STATUS_TXCLKSELRF_MASK  0x00000040
#define SI32_I2S_A_STATUS_TXCLKSELRF_SHIFT  6
// The transmit clock is not synchronized.
#define SI32_I2S_A_STATUS_TXCLKSELRF_NOT_SET_VALUE  0
#define SI32_I2S_A_STATUS_TXCLKSELRF_NOT_SET_U32 \
   (SI32_I2S_A_STATUS_TXCLKSELRF_NOT_SET_VALUE << SI32_I2S_A_STATUS_TXCLKSELRF_SHIFT)
// The transmit clock is synchronized and the transmitter is ready to send data.
#define SI32_I2S_A_STATUS_TXCLKSELRF_SET_VALUE  1
#define SI32_I2S_A_STATUS_TXCLKSELRF_SET_U32 \
   (SI32_I2S_A_STATUS_TXCLKSELRF_SET_VALUE << SI32_I2S_A_STATUS_TXCLKSELRF_SHIFT)

#define SI32_I2S_A_STATUS_RXCLKSELRF_MASK  0x00000080
#define SI32_I2S_A_STATUS_RXCLKSELRF_SHIFT  7
// The receive clock is not synchronized.
#define SI32_I2S_A_STATUS_RXCLKSELRF_NOT_SET_VALUE  0
#define SI32_I2S_A_STATUS_RXCLKSELRF_NOT_SET_U32 \
   (SI32_I2S_A_STATUS_RXCLKSELRF_NOT_SET_VALUE << SI32_I2S_A_STATUS_RXCLKSELRF_SHIFT)
// The receive clock is synchronized and the receiver is ready to accept data.
#define SI32_I2S_A_STATUS_RXCLKSELRF_SET_VALUE  1
#define SI32_I2S_A_STATUS_RXCLKSELRF_SET_U32 \
   (SI32_I2S_A_STATUS_RXCLKSELRF_SET_VALUE << SI32_I2S_A_STATUS_RXCLKSELRF_SHIFT)

#define SI32_I2S_A_STATUS_TXCLKENRF_MASK  0x00000100
#define SI32_I2S_A_STATUS_TXCLKENRF_SHIFT  8
// The transmit clock is not synchronized.
#define SI32_I2S_A_STATUS_TXCLKENRF_NOT_SET_VALUE  0
#define SI32_I2S_A_STATUS_TXCLKENRF_NOT_SET_U32 \
   (SI32_I2S_A_STATUS_TXCLKENRF_NOT_SET_VALUE << SI32_I2S_A_STATUS_TXCLKENRF_SHIFT)
// The transmit clock is synchronized and the transmitter is ready to send data.
#define SI32_I2S_A_STATUS_TXCLKENRF_SET_VALUE  1
#define SI32_I2S_A_STATUS_TXCLKENRF_SET_U32 \
   (SI32_I2S_A_STATUS_TXCLKENRF_SET_VALUE << SI32_I2S_A_STATUS_TXCLKENRF_SHIFT)

#define SI32_I2S_A_STATUS_RXCLKENRF_MASK  0x00000200
#define SI32_I2S_A_STATUS_RXCLKENRF_SHIFT  9
// The receive clock is not synchronized.
#define SI32_I2S_A_STATUS_RXCLKENRF_NOT_SET_VALUE  0
#define SI32_I2S_A_STATUS_RXCLKENRF_NOT_SET_U32 \
   (SI32_I2S_A_STATUS_RXCLKENRF_NOT_SET_VALUE << SI32_I2S_A_STATUS_RXCLKENRF_SHIFT)
// The receive clock is synchronized and the receiver is ready to accept data.
#define SI32_I2S_A_STATUS_RXCLKENRF_SET_VALUE  1
#define SI32_I2S_A_STATUS_RXCLKENRF_SET_U32 \
   (SI32_I2S_A_STATUS_RXCLKENRF_SET_VALUE << SI32_I2S_A_STATUS_RXCLKENRF_SHIFT)



struct SI32_I2S_A_DMACONTROL_Struct
{
   union
   {
      struct
      {
         // Transmit DMA Enable
         volatile uint32_t TXDMAEN: 1;
         // Receive DMA Enable
         volatile uint32_t RXDMAEN: 1;
         // Transmit DMA Burst Mode
         volatile uint32_t TXDMABMD: 1;
         // Receive DMA Burst Mode
         volatile uint32_t RXDMABMD: 1;
                  uint32_t reserved0: 28;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_DMACONTROL_TXDMAEN_MASK  0x00000001
#define SI32_I2S_A_DMACONTROL_TXDMAEN_SHIFT  0
// Disable transmitter DMA data requests.
#define SI32_I2S_A_DMACONTROL_TXDMAEN_DISABLED_VALUE  0
#define SI32_I2S_A_DMACONTROL_TXDMAEN_DISABLED_U32 \
   (SI32_I2S_A_DMACONTROL_TXDMAEN_DISABLED_VALUE << SI32_I2S_A_DMACONTROL_TXDMAEN_SHIFT)
// Enable transmitter DMA data requests.
#define SI32_I2S_A_DMACONTROL_TXDMAEN_ENABLED_VALUE  1
#define SI32_I2S_A_DMACONTROL_TXDMAEN_ENABLED_U32 \
   (SI32_I2S_A_DMACONTROL_TXDMAEN_ENABLED_VALUE << SI32_I2S_A_DMACONTROL_TXDMAEN_SHIFT)

#define SI32_I2S_A_DMACONTROL_RXDMAEN_MASK  0x00000002
#define SI32_I2S_A_DMACONTROL_RXDMAEN_SHIFT  1
// Disable receiver DMA data transfer requests.
#define SI32_I2S_A_DMACONTROL_RXDMAEN_DISABLED_VALUE  0
#define SI32_I2S_A_DMACONTROL_RXDMAEN_DISABLED_U32 \
   (SI32_I2S_A_DMACONTROL_RXDMAEN_DISABLED_VALUE << SI32_I2S_A_DMACONTROL_RXDMAEN_SHIFT)
// Enable receiver DMA data transfer requests.
#define SI32_I2S_A_DMACONTROL_RXDMAEN_ENABLED_VALUE  1
#define SI32_I2S_A_DMACONTROL_RXDMAEN_ENABLED_U32 \
   (SI32_I2S_A_DMACONTROL_RXDMAEN_ENABLED_VALUE << SI32_I2S_A_DMACONTROL_RXDMAEN_SHIFT)

#define SI32_I2S_A_DMACONTROL_TXDMABMD_MASK  0x00000004
#define SI32_I2S_A_DMACONTROL_TXDMABMD_SHIFT  2
// The transmitter transmits one word at a time. Whenever there is any room in the
// transmit FIFO, a single word burst DMA data request is generated.
#define SI32_I2S_A_DMACONTROL_TXDMABMD_ONE_WORD_VALUE  0
#define SI32_I2S_A_DMACONTROL_TXDMABMD_ONE_WORD_U32 \
   (SI32_I2S_A_DMACONTROL_TXDMABMD_ONE_WORD_VALUE << SI32_I2S_A_DMACONTROL_TXDMABMD_SHIFT)
// The transmitter transmits four words at a time. Whenever the FIFO depth drops
// below five, a DMA burst request is generated for four words.
#define SI32_I2S_A_DMACONTROL_TXDMABMD_FOUR_WORDS_VALUE  1
#define SI32_I2S_A_DMACONTROL_TXDMABMD_FOUR_WORDS_U32 \
   (SI32_I2S_A_DMACONTROL_TXDMABMD_FOUR_WORDS_VALUE << SI32_I2S_A_DMACONTROL_TXDMABMD_SHIFT)

#define SI32_I2S_A_DMACONTROL_RXDMABMD_MASK  0x00000008
#define SI32_I2S_A_DMACONTROL_RXDMABMD_SHIFT  3
// The receiver receives one word at a time. Whenever there is at least one word in
// the receive FIFO, a single word burst DMA request is generated.
#define SI32_I2S_A_DMACONTROL_RXDMABMD_ONE_WORD_VALUE  0
#define SI32_I2S_A_DMACONTROL_RXDMABMD_ONE_WORD_U32 \
   (SI32_I2S_A_DMACONTROL_RXDMABMD_ONE_WORD_VALUE << SI32_I2S_A_DMACONTROL_RXDMABMD_SHIFT)
// The receiver receives four words at a time. Whenever the FIFO depth rises above
// three, a DMA burst request is generated for four words.
#define SI32_I2S_A_DMACONTROL_RXDMABMD_FOUR_WORDS_VALUE  1
#define SI32_I2S_A_DMACONTROL_RXDMABMD_FOUR_WORDS_U32 \
   (SI32_I2S_A_DMACONTROL_RXDMABMD_FOUR_WORDS_VALUE << SI32_I2S_A_DMACONTROL_RXDMABMD_SHIFT)



struct SI32_I2S_A_DBGCONTROL_Struct
{
   union
   {
      struct
      {
         // I2S Transmit DMA Debug Halt Enable
         volatile uint32_t TXDBGHEN: 1;
         // I2S Receive DMA Debug Halt Enable
         volatile uint32_t RXDBGHEN: 1;
         // I2S Transmit Debug Mode
         volatile uint32_t TXDBGMD: 1;
         // I2S Receive Debug Mode
         volatile uint32_t RXDBGMD: 1;
                  uint32_t reserved0: 28;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2S_A_DBGCONTROL_TXDBGHEN_MASK  0x00000001
#define SI32_I2S_A_DBGCONTROL_TXDBGHEN_SHIFT  0
// Transmit DMA requests continue while the core is debug mode.
#define SI32_I2S_A_DBGCONTROL_TXDBGHEN_DISABLED_VALUE  0
#define SI32_I2S_A_DBGCONTROL_TXDBGHEN_DISABLED_U32 \
   (SI32_I2S_A_DBGCONTROL_TXDBGHEN_DISABLED_VALUE << SI32_I2S_A_DBGCONTROL_TXDBGHEN_SHIFT)
// Transmit DMA requests stop while the core is debug mode.
#define SI32_I2S_A_DBGCONTROL_TXDBGHEN_ENABLED_VALUE  1
#define SI32_I2S_A_DBGCONTROL_TXDBGHEN_ENABLED_U32 \
   (SI32_I2S_A_DBGCONTROL_TXDBGHEN_ENABLED_VALUE << SI32_I2S_A_DBGCONTROL_TXDBGHEN_SHIFT)

#define SI32_I2S_A_DBGCONTROL_RXDBGHEN_MASK  0x00000002
#define SI32_I2S_A_DBGCONTROL_RXDBGHEN_SHIFT  1
// Receive DMA requests continue while the core is debug mode.
#define SI32_I2S_A_DBGCONTROL_RXDBGHEN_DISABLED_VALUE  0
#define SI32_I2S_A_DBGCONTROL_RXDBGHEN_DISABLED_U32 \
   (SI32_I2S_A_DBGCONTROL_RXDBGHEN_DISABLED_VALUE << SI32_I2S_A_DBGCONTROL_RXDBGHEN_SHIFT)
// Receive DMA requests stop while the core is debug mode.
#define SI32_I2S_A_DBGCONTROL_RXDBGHEN_ENABLED_VALUE  1
#define SI32_I2S_A_DBGCONTROL_RXDBGHEN_ENABLED_U32 \
   (SI32_I2S_A_DBGCONTROL_RXDBGHEN_ENABLED_VALUE << SI32_I2S_A_DBGCONTROL_RXDBGHEN_SHIFT)

#define SI32_I2S_A_DBGCONTROL_TXDBGMD_MASK  0x00000004
#define SI32_I2S_A_DBGCONTROL_TXDBGMD_SHIFT  2
// The clock to the I2S transmitter is active in debug mode.
#define SI32_I2S_A_DBGCONTROL_TXDBGMD_RUN_VALUE  0
#define SI32_I2S_A_DBGCONTROL_TXDBGMD_RUN_U32 \
   (SI32_I2S_A_DBGCONTROL_TXDBGMD_RUN_VALUE << SI32_I2S_A_DBGCONTROL_TXDBGMD_SHIFT)
// The clock to the I2S transmitter is not active in debug mode. The clock divider
// keeps running and the clock will be disabled when two samples are ready to be
// sent by the transmitter.
#define SI32_I2S_A_DBGCONTROL_TXDBGMD_HALT_VALUE  1
#define SI32_I2S_A_DBGCONTROL_TXDBGMD_HALT_U32 \
   (SI32_I2S_A_DBGCONTROL_TXDBGMD_HALT_VALUE << SI32_I2S_A_DBGCONTROL_TXDBGMD_SHIFT)

#define SI32_I2S_A_DBGCONTROL_RXDBGMD_MASK  0x00000008
#define SI32_I2S_A_DBGCONTROL_RXDBGMD_SHIFT  3
// The clock to the I2S receiver is active in debug mode.
#define SI32_I2S_A_DBGCONTROL_RXDBGMD_RUN_VALUE  0
#define SI32_I2S_A_DBGCONTROL_RXDBGMD_RUN_U32 \
   (SI32_I2S_A_DBGCONTROL_RXDBGMD_RUN_VALUE << SI32_I2S_A_DBGCONTROL_RXDBGMD_SHIFT)
// The clock to the I2S receiver is not active in debug mode. The clock divider
// keeps running and the clock will be disabled when two samples are captured in
// the receiver.
#define SI32_I2S_A_DBGCONTROL_RXDBGMD_HALT_VALUE  1
#define SI32_I2S_A_DBGCONTROL_RXDBGMD_HALT_U32 \
   (SI32_I2S_A_DBGCONTROL_RXDBGMD_HALT_VALUE << SI32_I2S_A_DBGCONTROL_RXDBGMD_SHIFT)



typedef struct SI32_I2S_A_Struct
{
   struct SI32_I2S_A_TXCONTROL_Struct              TXCONTROL      ; // Base Address + 0x0
   volatile uint32_t                               TXCONTROL_SET;
   volatile uint32_t                               TXCONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_I2S_A_TXMODE_Struct                 TXMODE         ; // Base Address + 0x10
   volatile uint32_t                               TXMODE_SET;
   volatile uint32_t                               TXMODE_CLR;
   uint32_t                                        reserved1;
   struct SI32_I2S_A_FSDUTY_Struct                 FSDUTY         ; // Base Address + 0x20
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   uint32_t                                        reserved4;
   struct SI32_I2S_A_RXCONTROL_Struct              RXCONTROL      ; // Base Address + 0x30
   volatile uint32_t                               RXCONTROL_SET;
   volatile uint32_t                               RXCONTROL_CLR;
   uint32_t                                        reserved5;
   struct SI32_I2S_A_RXMODE_Struct                 RXMODE         ; // Base Address + 0x40
   volatile uint32_t                               RXMODE_SET;
   volatile uint32_t                               RXMODE_CLR;
   uint32_t                                        reserved6;
   struct SI32_I2S_A_CLKCONTROL_Struct             CLKCONTROL     ; // Base Address + 0x50
   volatile uint32_t                               CLKCONTROL_SET;
   volatile uint32_t                               CLKCONTROL_CLR;
   uint32_t                                        reserved7;
   struct SI32_I2S_A_TXFIFO_Struct                 TXFIFO         ; // Base Address + 0x60
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   uint32_t                                        reserved10;
   struct SI32_I2S_A_RXFIFO_Struct                 RXFIFO         ; // Base Address + 0x70
   uint32_t                                        reserved11;
   uint32_t                                        reserved12;
   uint32_t                                        reserved13;
   struct SI32_I2S_A_FIFOSTATUS_Struct             FIFOSTATUS     ; // Base Address + 0x80
   uint32_t                                        reserved14;
   uint32_t                                        reserved15;
   uint32_t                                        reserved16;
   struct SI32_I2S_A_FIFOCONTROL_Struct            FIFOCONTROL    ; // Base Address + 0x90
   volatile uint32_t                               FIFOCONTROL_SET;
   volatile uint32_t                               FIFOCONTROL_CLR;
   uint32_t                                        reserved17;
   struct SI32_I2S_A_INTCONTROL_Struct             INTCONTROL     ; // Base Address + 0xa0
   volatile uint32_t                               INTCONTROL_SET;
   volatile uint32_t                               INTCONTROL_CLR;
   uint32_t                                        reserved18;
   struct SI32_I2S_A_STATUS_Struct                 STATUS         ; // Base Address + 0xb0
   volatile uint32_t                               STATUS_SET;
   volatile uint32_t                               STATUS_CLR;
   uint32_t                                        reserved19;
   struct SI32_I2S_A_DMACONTROL_Struct             DMACONTROL     ; // Base Address + 0xc0
   volatile uint32_t                               DMACONTROL_SET;
   volatile uint32_t                               DMACONTROL_CLR;
   uint32_t                                        reserved20;
   struct SI32_I2S_A_DBGCONTROL_Struct             DBGCONTROL     ; // Base Address + 0xd0
   volatile uint32_t                               DBGCONTROL_SET;
   volatile uint32_t                               DBGCONTROL_CLR;
   uint32_t                                        reserved21;
} SI32_I2S_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_I2S_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

