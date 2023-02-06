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

#ifndef __SI32_UART_A_REGISTERS_H__
#define __SI32_UART_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_UART_A_CONFIG_Struct
{
   union
   {
      struct
      {
         // Receiver Start Enable
         volatile uint32_t RSTRTEN: 1;
         // Receiver Parity Enable
         volatile uint32_t RPAREN: 1;
         // Receiver Stop Enable
         volatile uint32_t RSTPEN: 1;
         // Receiver Stop Mode
         volatile uint32_t RSTPMD: 2;
         // Receiver Parity Mode
         volatile uint32_t RPARMD: 2;
                  uint32_t reserved0: 1;
         // Receiver Data Length
         volatile uint32_t RDATLN: 3;
                  uint32_t reserved1: 1;
         // Receiver Smartcard Parity Response Enable
         volatile uint32_t RSCEN: 1;
         // Receiver IrDA Enable
         volatile uint32_t RIRDAEN: 1;
         // Receiver Invert Enable
         volatile uint32_t RINVEN: 1;
                  uint32_t reserved2: 1;
         // Transmitter Start Enable
         volatile uint32_t TSTRTEN: 1;
         // Transmitter Parity Enable
         volatile uint32_t TPAREN: 1;
         // Transmitter Stop Enable
         volatile uint32_t TSTPEN: 1;
         // Transmitter Stop Mode
         volatile uint32_t TSTPMD: 2;
         // Transmitter Parity Mode
         volatile uint32_t TPARMD: 2;
                  uint32_t reserved3: 1;
         // Transmitter Data Length
         volatile uint32_t TDATLN: 3;
                  uint32_t reserved4: 1;
         // Transmitter Smartcard Parity Response Enable
         volatile uint32_t TSCEN: 1;
         // Transmitter IrDA Enable
         volatile uint32_t TIRDAEN: 1;
         // Transmitter Invert Enable
         volatile uint32_t TINVEN: 1;
                  uint32_t reserved5: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_UART_A_CONFIG_RSTRTEN_MASK  0x00000001
#define SI32_UART_A_CONFIG_RSTRTEN_SHIFT  0
// Do not expect a start bit during receptions.
#define SI32_UART_A_CONFIG_RSTRTEN_DISABLED_VALUE  0
#define SI32_UART_A_CONFIG_RSTRTEN_DISABLED_U32 \
   (SI32_UART_A_CONFIG_RSTRTEN_DISABLED_VALUE << SI32_UART_A_CONFIG_RSTRTEN_SHIFT)
// Expect a start bit during receptions.
#define SI32_UART_A_CONFIG_RSTRTEN_ENABLED_VALUE  1
#define SI32_UART_A_CONFIG_RSTRTEN_ENABLED_U32 \
   (SI32_UART_A_CONFIG_RSTRTEN_ENABLED_VALUE << SI32_UART_A_CONFIG_RSTRTEN_SHIFT)

#define SI32_UART_A_CONFIG_RPAREN_MASK  0x00000002
#define SI32_UART_A_CONFIG_RPAREN_SHIFT  1
// Do not expect a parity bit during receptions.
#define SI32_UART_A_CONFIG_RPAREN_DISABLED_VALUE  0
#define SI32_UART_A_CONFIG_RPAREN_DISABLED_U32 \
   (SI32_UART_A_CONFIG_RPAREN_DISABLED_VALUE << SI32_UART_A_CONFIG_RPAREN_SHIFT)
// Expect a parity bit during receptions.
#define SI32_UART_A_CONFIG_RPAREN_ENABLED_VALUE  1
#define SI32_UART_A_CONFIG_RPAREN_ENABLED_U32 \
   (SI32_UART_A_CONFIG_RPAREN_ENABLED_VALUE << SI32_UART_A_CONFIG_RPAREN_SHIFT)

#define SI32_UART_A_CONFIG_RSTPEN_MASK  0x00000004
#define SI32_UART_A_CONFIG_RSTPEN_SHIFT  2
// Do not expect stop bits during receptions.
#define SI32_UART_A_CONFIG_RSTPEN_DISABLED_VALUE  0
#define SI32_UART_A_CONFIG_RSTPEN_DISABLED_U32 \
   (SI32_UART_A_CONFIG_RSTPEN_DISABLED_VALUE << SI32_UART_A_CONFIG_RSTPEN_SHIFT)
// Expect stop bits during receptions.
#define SI32_UART_A_CONFIG_RSTPEN_ENABLED_VALUE  1
#define SI32_UART_A_CONFIG_RSTPEN_ENABLED_U32 \
   (SI32_UART_A_CONFIG_RSTPEN_ENABLED_VALUE << SI32_UART_A_CONFIG_RSTPEN_SHIFT)

#define SI32_UART_A_CONFIG_RSTPMD_MASK  0x00000018
#define SI32_UART_A_CONFIG_RSTPMD_SHIFT  3
// 0.5 stop bit.
#define SI32_UART_A_CONFIG_RSTPMD_0P5_STOP_VALUE  0
#define SI32_UART_A_CONFIG_RSTPMD_0P5_STOP_U32 \
   (SI32_UART_A_CONFIG_RSTPMD_0P5_STOP_VALUE << SI32_UART_A_CONFIG_RSTPMD_SHIFT)
// 1 stop bit.
#define SI32_UART_A_CONFIG_RSTPMD_1_STOP_VALUE  1
#define SI32_UART_A_CONFIG_RSTPMD_1_STOP_U32 \
   (SI32_UART_A_CONFIG_RSTPMD_1_STOP_VALUE << SI32_UART_A_CONFIG_RSTPMD_SHIFT)
// 1.5 stop bits.
#define SI32_UART_A_CONFIG_RSTPMD_1P5_STOP_VALUE  2
#define SI32_UART_A_CONFIG_RSTPMD_1P5_STOP_U32 \
   (SI32_UART_A_CONFIG_RSTPMD_1P5_STOP_VALUE << SI32_UART_A_CONFIG_RSTPMD_SHIFT)
// 2 stop bits.
#define SI32_UART_A_CONFIG_RSTPMD_2_STOP_VALUE  3
#define SI32_UART_A_CONFIG_RSTPMD_2_STOP_U32 \
   (SI32_UART_A_CONFIG_RSTPMD_2_STOP_VALUE << SI32_UART_A_CONFIG_RSTPMD_SHIFT)

#define SI32_UART_A_CONFIG_RPARMD_MASK  0x00000060
#define SI32_UART_A_CONFIG_RPARMD_SHIFT  5
// Odd Parity.
#define SI32_UART_A_CONFIG_RPARMD_ODD_VALUE  0
#define SI32_UART_A_CONFIG_RPARMD_ODD_U32 \
   (SI32_UART_A_CONFIG_RPARMD_ODD_VALUE << SI32_UART_A_CONFIG_RPARMD_SHIFT)
// Even Parity.
#define SI32_UART_A_CONFIG_RPARMD_EVEN_VALUE  1
#define SI32_UART_A_CONFIG_RPARMD_EVEN_U32 \
   (SI32_UART_A_CONFIG_RPARMD_EVEN_VALUE << SI32_UART_A_CONFIG_RPARMD_SHIFT)
// Set (Parity = 1).
#define SI32_UART_A_CONFIG_RPARMD_MARK_VALUE  2
#define SI32_UART_A_CONFIG_RPARMD_MARK_U32 \
   (SI32_UART_A_CONFIG_RPARMD_MARK_VALUE << SI32_UART_A_CONFIG_RPARMD_SHIFT)
// Clear (Parity = 0).
#define SI32_UART_A_CONFIG_RPARMD_SPACE_VALUE  3
#define SI32_UART_A_CONFIG_RPARMD_SPACE_U32 \
   (SI32_UART_A_CONFIG_RPARMD_SPACE_VALUE << SI32_UART_A_CONFIG_RPARMD_SHIFT)

#define SI32_UART_A_CONFIG_RDATLN_MASK  0x00000700
#define SI32_UART_A_CONFIG_RDATLN_SHIFT  8
// 5 bits.
#define SI32_UART_A_CONFIG_RDATLN_5_BITS_VALUE  0
#define SI32_UART_A_CONFIG_RDATLN_5_BITS_U32 \
   (SI32_UART_A_CONFIG_RDATLN_5_BITS_VALUE << SI32_UART_A_CONFIG_RDATLN_SHIFT)
// 6 bits.
#define SI32_UART_A_CONFIG_RDATLN_6_BITS_VALUE  1
#define SI32_UART_A_CONFIG_RDATLN_6_BITS_U32 \
   (SI32_UART_A_CONFIG_RDATLN_6_BITS_VALUE << SI32_UART_A_CONFIG_RDATLN_SHIFT)
// 7 bits.
#define SI32_UART_A_CONFIG_RDATLN_7_BITS_VALUE  2
#define SI32_UART_A_CONFIG_RDATLN_7_BITS_U32 \
   (SI32_UART_A_CONFIG_RDATLN_7_BITS_VALUE << SI32_UART_A_CONFIG_RDATLN_SHIFT)
// 8 bits.
#define SI32_UART_A_CONFIG_RDATLN_8_BITS_VALUE  3
#define SI32_UART_A_CONFIG_RDATLN_8_BITS_U32 \
   (SI32_UART_A_CONFIG_RDATLN_8_BITS_VALUE << SI32_UART_A_CONFIG_RDATLN_SHIFT)
// 9 bits. The 9th bit is stored in the FIFO (normal mode).
#define SI32_UART_A_CONFIG_RDATLN_9_BITS_STORED_VALUE  4
#define SI32_UART_A_CONFIG_RDATLN_9_BITS_STORED_U32 \
   (SI32_UART_A_CONFIG_RDATLN_9_BITS_STORED_VALUE << SI32_UART_A_CONFIG_RDATLN_SHIFT)
// 9 bits. The 9th bit is not stored in the FIFO (fixed mode). This mode is used
// when the 9th bit is only used for match operations (see MATMD).
#define SI32_UART_A_CONFIG_RDATLN_9_BITS_MATCH_VALUE  5
#define SI32_UART_A_CONFIG_RDATLN_9_BITS_MATCH_U32 \
   (SI32_UART_A_CONFIG_RDATLN_9_BITS_MATCH_VALUE << SI32_UART_A_CONFIG_RDATLN_SHIFT)

#define SI32_UART_A_CONFIG_RSCEN_MASK  0x00001000
#define SI32_UART_A_CONFIG_RSCEN_SHIFT  12
// The receiver does not send a Smartcard parity error response.
#define SI32_UART_A_CONFIG_RSCEN_DISABLED_VALUE  0
#define SI32_UART_A_CONFIG_RSCEN_DISABLED_U32 \
   (SI32_UART_A_CONFIG_RSCEN_DISABLED_VALUE << SI32_UART_A_CONFIG_RSCEN_SHIFT)
// The receiver sends a Smartcard Parity response.
#define SI32_UART_A_CONFIG_RSCEN_ENABLED_VALUE  1
#define SI32_UART_A_CONFIG_RSCEN_ENABLED_U32 \
   (SI32_UART_A_CONFIG_RSCEN_ENABLED_VALUE << SI32_UART_A_CONFIG_RSCEN_SHIFT)

#define SI32_UART_A_CONFIG_RIRDAEN_MASK  0x00002000
#define SI32_UART_A_CONFIG_RIRDAEN_SHIFT  13
// The receiver does not operate in IrDA mode.
#define SI32_UART_A_CONFIG_RIRDAEN_DISABLED_VALUE  0
#define SI32_UART_A_CONFIG_RIRDAEN_DISABLED_U32 \
   (SI32_UART_A_CONFIG_RIRDAEN_DISABLED_VALUE << SI32_UART_A_CONFIG_RIRDAEN_SHIFT)
// The receiver operates in IrDA mode.
#define SI32_UART_A_CONFIG_RIRDAEN_ENABLED_VALUE  1
#define SI32_UART_A_CONFIG_RIRDAEN_ENABLED_U32 \
   (SI32_UART_A_CONFIG_RIRDAEN_ENABLED_VALUE << SI32_UART_A_CONFIG_RIRDAEN_SHIFT)

#define SI32_UART_A_CONFIG_RINVEN_MASK  0x00004000
#define SI32_UART_A_CONFIG_RINVEN_SHIFT  14
// Do not invert the RX pin signals (the RX idle state is high).
#define SI32_UART_A_CONFIG_RINVEN_DISABLED_VALUE  0
#define SI32_UART_A_CONFIG_RINVEN_DISABLED_U32 \
   (SI32_UART_A_CONFIG_RINVEN_DISABLED_VALUE << SI32_UART_A_CONFIG_RINVEN_SHIFT)
// Invert the RX pin signals (the RX idle state is low).
#define SI32_UART_A_CONFIG_RINVEN_ENABLED_VALUE  1
#define SI32_UART_A_CONFIG_RINVEN_ENABLED_U32 \
   (SI32_UART_A_CONFIG_RINVEN_ENABLED_VALUE << SI32_UART_A_CONFIG_RINVEN_SHIFT)

#define SI32_UART_A_CONFIG_TSTRTEN_MASK  0x00010000
#define SI32_UART_A_CONFIG_TSTRTEN_SHIFT  16
// Do not generate a start bit during transmissions.
#define SI32_UART_A_CONFIG_TSTRTEN_DISABLED_VALUE  0
#define SI32_UART_A_CONFIG_TSTRTEN_DISABLED_U32 \
   (SI32_UART_A_CONFIG_TSTRTEN_DISABLED_VALUE << SI32_UART_A_CONFIG_TSTRTEN_SHIFT)
// Generate a start bit during transmissions.
#define SI32_UART_A_CONFIG_TSTRTEN_ENABLED_VALUE  1
#define SI32_UART_A_CONFIG_TSTRTEN_ENABLED_U32 \
   (SI32_UART_A_CONFIG_TSTRTEN_ENABLED_VALUE << SI32_UART_A_CONFIG_TSTRTEN_SHIFT)

#define SI32_UART_A_CONFIG_TPAREN_MASK  0x00020000
#define SI32_UART_A_CONFIG_TPAREN_SHIFT  17
// Do not send a parity bit during transmissions.
#define SI32_UART_A_CONFIG_TPAREN_DISABLED_VALUE  0
#define SI32_UART_A_CONFIG_TPAREN_DISABLED_U32 \
   (SI32_UART_A_CONFIG_TPAREN_DISABLED_VALUE << SI32_UART_A_CONFIG_TPAREN_SHIFT)
// Send a parity bit during transmissions.
#define SI32_UART_A_CONFIG_TPAREN_ENABLED_VALUE  1
#define SI32_UART_A_CONFIG_TPAREN_ENABLED_U32 \
   (SI32_UART_A_CONFIG_TPAREN_ENABLED_VALUE << SI32_UART_A_CONFIG_TPAREN_SHIFT)

#define SI32_UART_A_CONFIG_TSTPEN_MASK  0x00040000
#define SI32_UART_A_CONFIG_TSTPEN_SHIFT  18
// Do not send stop bits during transmissions.
#define SI32_UART_A_CONFIG_TSTPEN_DISABLED_VALUE  0
#define SI32_UART_A_CONFIG_TSTPEN_DISABLED_U32 \
   (SI32_UART_A_CONFIG_TSTPEN_DISABLED_VALUE << SI32_UART_A_CONFIG_TSTPEN_SHIFT)
// Send stop bits during transmissions.
#define SI32_UART_A_CONFIG_TSTPEN_ENABLED_VALUE  1
#define SI32_UART_A_CONFIG_TSTPEN_ENABLED_U32 \
   (SI32_UART_A_CONFIG_TSTPEN_ENABLED_VALUE << SI32_UART_A_CONFIG_TSTPEN_SHIFT)

#define SI32_UART_A_CONFIG_TSTPMD_MASK  0x00180000
#define SI32_UART_A_CONFIG_TSTPMD_SHIFT  19
// 0.5 stop bit.
#define SI32_UART_A_CONFIG_TSTPMD_0P5_STOP_VALUE  0
#define SI32_UART_A_CONFIG_TSTPMD_0P5_STOP_U32 \
   (SI32_UART_A_CONFIG_TSTPMD_0P5_STOP_VALUE << SI32_UART_A_CONFIG_TSTPMD_SHIFT)
// 1 stop bit.
#define SI32_UART_A_CONFIG_TSTPMD_1_STOP_VALUE  1
#define SI32_UART_A_CONFIG_TSTPMD_1_STOP_U32 \
   (SI32_UART_A_CONFIG_TSTPMD_1_STOP_VALUE << SI32_UART_A_CONFIG_TSTPMD_SHIFT)
// 1.5 stop bits.
#define SI32_UART_A_CONFIG_TSTPMD_1P5_STOP_VALUE  2
#define SI32_UART_A_CONFIG_TSTPMD_1P5_STOP_U32 \
   (SI32_UART_A_CONFIG_TSTPMD_1P5_STOP_VALUE << SI32_UART_A_CONFIG_TSTPMD_SHIFT)
// 2 stop bits.
#define SI32_UART_A_CONFIG_TSTPMD_2_STOP_VALUE  3
#define SI32_UART_A_CONFIG_TSTPMD_2_STOP_U32 \
   (SI32_UART_A_CONFIG_TSTPMD_2_STOP_VALUE << SI32_UART_A_CONFIG_TSTPMD_SHIFT)

#define SI32_UART_A_CONFIG_TPARMD_MASK  0x00600000
#define SI32_UART_A_CONFIG_TPARMD_SHIFT  21
// Odd Parity.
#define SI32_UART_A_CONFIG_TPARMD_ODD_VALUE  0
#define SI32_UART_A_CONFIG_TPARMD_ODD_U32 \
   (SI32_UART_A_CONFIG_TPARMD_ODD_VALUE << SI32_UART_A_CONFIG_TPARMD_SHIFT)
// Even Parity.
#define SI32_UART_A_CONFIG_TPARMD_EVEN_VALUE  1
#define SI32_UART_A_CONFIG_TPARMD_EVEN_U32 \
   (SI32_UART_A_CONFIG_TPARMD_EVEN_VALUE << SI32_UART_A_CONFIG_TPARMD_SHIFT)
// Set (Parity = 1).
#define SI32_UART_A_CONFIG_TPARMD_MARK_VALUE  2
#define SI32_UART_A_CONFIG_TPARMD_MARK_U32 \
   (SI32_UART_A_CONFIG_TPARMD_MARK_VALUE << SI32_UART_A_CONFIG_TPARMD_SHIFT)
// Clear (Parity = 0).
#define SI32_UART_A_CONFIG_TPARMD_SPACE_VALUE  3
#define SI32_UART_A_CONFIG_TPARMD_SPACE_U32 \
   (SI32_UART_A_CONFIG_TPARMD_SPACE_VALUE << SI32_UART_A_CONFIG_TPARMD_SHIFT)

#define SI32_UART_A_CONFIG_TDATLN_MASK  0x07000000
#define SI32_UART_A_CONFIG_TDATLN_SHIFT  24
// 5 bits.
#define SI32_UART_A_CONFIG_TDATLN_5_BITS_VALUE  0
#define SI32_UART_A_CONFIG_TDATLN_5_BITS_U32 \
   (SI32_UART_A_CONFIG_TDATLN_5_BITS_VALUE << SI32_UART_A_CONFIG_TDATLN_SHIFT)
// 6 bits.
#define SI32_UART_A_CONFIG_TDATLN_6_BITS_VALUE  1
#define SI32_UART_A_CONFIG_TDATLN_6_BITS_U32 \
   (SI32_UART_A_CONFIG_TDATLN_6_BITS_VALUE << SI32_UART_A_CONFIG_TDATLN_SHIFT)
// 7 bits.
#define SI32_UART_A_CONFIG_TDATLN_7_BITS_VALUE  2
#define SI32_UART_A_CONFIG_TDATLN_7_BITS_U32 \
   (SI32_UART_A_CONFIG_TDATLN_7_BITS_VALUE << SI32_UART_A_CONFIG_TDATLN_SHIFT)
// 8 bits.
#define SI32_UART_A_CONFIG_TDATLN_8_BITS_VALUE  3
#define SI32_UART_A_CONFIG_TDATLN_8_BITS_U32 \
   (SI32_UART_A_CONFIG_TDATLN_8_BITS_VALUE << SI32_UART_A_CONFIG_TDATLN_SHIFT)
// 9 bits. The 9th bit is taken from the FIFO data (normal mode).
#define SI32_UART_A_CONFIG_TDATLN_9_BITS_FIFO_VALUE  4
#define SI32_UART_A_CONFIG_TDATLN_9_BITS_FIFO_U32 \
   (SI32_UART_A_CONFIG_TDATLN_9_BITS_FIFO_VALUE << SI32_UART_A_CONFIG_TDATLN_SHIFT)
// 9 bits. The 9th bit is set by the value of TBIT (fixed mode).
#define SI32_UART_A_CONFIG_TDATLN_9_BITS_TBIT_VALUE  5
#define SI32_UART_A_CONFIG_TDATLN_9_BITS_TBIT_U32 \
   (SI32_UART_A_CONFIG_TDATLN_9_BITS_TBIT_VALUE << SI32_UART_A_CONFIG_TDATLN_SHIFT)

#define SI32_UART_A_CONFIG_TSCEN_MASK  0x10000000
#define SI32_UART_A_CONFIG_TSCEN_SHIFT  28
// The transmitter does not check for a Smartcard parity error response.
#define SI32_UART_A_CONFIG_TSCEN_DISABLED_VALUE  0
#define SI32_UART_A_CONFIG_TSCEN_DISABLED_U32 \
   (SI32_UART_A_CONFIG_TSCEN_DISABLED_VALUE << SI32_UART_A_CONFIG_TSCEN_SHIFT)
// The transmitter checks for a Smartcard parity error response.
#define SI32_UART_A_CONFIG_TSCEN_ENABLED_VALUE  1
#define SI32_UART_A_CONFIG_TSCEN_ENABLED_U32 \
   (SI32_UART_A_CONFIG_TSCEN_ENABLED_VALUE << SI32_UART_A_CONFIG_TSCEN_SHIFT)

#define SI32_UART_A_CONFIG_TIRDAEN_MASK  0x20000000
#define SI32_UART_A_CONFIG_TIRDAEN_SHIFT  29
// Disable IrDA transmit mode.
#define SI32_UART_A_CONFIG_TIRDAEN_DISABLED_VALUE  0
#define SI32_UART_A_CONFIG_TIRDAEN_DISABLED_U32 \
   (SI32_UART_A_CONFIG_TIRDAEN_DISABLED_VALUE << SI32_UART_A_CONFIG_TIRDAEN_SHIFT)
// Enable IrDA transmit mode.
#define SI32_UART_A_CONFIG_TIRDAEN_ENABLED_VALUE  1
#define SI32_UART_A_CONFIG_TIRDAEN_ENABLED_U32 \
   (SI32_UART_A_CONFIG_TIRDAEN_ENABLED_VALUE << SI32_UART_A_CONFIG_TIRDAEN_SHIFT)

#define SI32_UART_A_CONFIG_TINVEN_MASK  0x40000000
#define SI32_UART_A_CONFIG_TINVEN_SHIFT  30
// Do not invert the TX pin signals (the TX idle state is high).
#define SI32_UART_A_CONFIG_TINVEN_DISABLED_VALUE  0
#define SI32_UART_A_CONFIG_TINVEN_DISABLED_U32 \
   (SI32_UART_A_CONFIG_TINVEN_DISABLED_VALUE << SI32_UART_A_CONFIG_TINVEN_SHIFT)
// Invert the TX pin signals (the TX idle state is low).
#define SI32_UART_A_CONFIG_TINVEN_ENABLED_VALUE  1
#define SI32_UART_A_CONFIG_TINVEN_ENABLED_U32 \
   (SI32_UART_A_CONFIG_TINVEN_ENABLED_VALUE << SI32_UART_A_CONFIG_TINVEN_SHIFT)



struct SI32_UART_A_MODE_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 16;
         // UART Debug Mode
         volatile uint32_t DBGMD: 1;
                  uint32_t reserved1: 1;
         // Loop Back Mode
         volatile uint32_t LBMD: 2;
                  uint32_t reserved2: 7;
         // Duplex Mode
         volatile uint32_t DUPLEXMD: 1;
                  uint32_t reserved3: 2;
         // Idle TX Tristate Enable
         volatile uint32_t ITSEN: 1;
                  uint32_t reserved4: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_UART_A_MODE_DBGMD_MASK  0x00010000
#define SI32_UART_A_MODE_DBGMD_SHIFT  16
// The UART module will continue to operate while the core is halted in debug mode.
#define SI32_UART_A_MODE_DBGMD_RUN_VALUE  0
#define SI32_UART_A_MODE_DBGMD_RUN_U32 \
   (SI32_UART_A_MODE_DBGMD_RUN_VALUE << SI32_UART_A_MODE_DBGMD_SHIFT)
// A debug breakpoint will cause the UART module to halt. Any active transmissions
// and receptions will complete first.
#define SI32_UART_A_MODE_DBGMD_HALT_VALUE  1
#define SI32_UART_A_MODE_DBGMD_HALT_U32 \
   (SI32_UART_A_MODE_DBGMD_HALT_VALUE << SI32_UART_A_MODE_DBGMD_SHIFT)

#define SI32_UART_A_MODE_LBMD_MASK  0x000C0000
#define SI32_UART_A_MODE_LBMD_SHIFT  18
// Loop back is disabled and the TX and RX signals are connected to the
// corresponding external pins.
#define SI32_UART_A_MODE_LBMD_DISABLED_VALUE  0
#define SI32_UART_A_MODE_LBMD_DISABLED_U32 \
   (SI32_UART_A_MODE_LBMD_DISABLED_VALUE << SI32_UART_A_MODE_LBMD_SHIFT)
// Receive loop back. The receiver input path is disconnected from the RX pin and
// internally connected to the transmitter. Data transmitted will be sent out on TX
// and also received by the device.
#define SI32_UART_A_MODE_LBMD_RX_ONLY_VALUE  1
#define SI32_UART_A_MODE_LBMD_RX_ONLY_U32 \
   (SI32_UART_A_MODE_LBMD_RX_ONLY_VALUE << SI32_UART_A_MODE_LBMD_SHIFT)
// Transmit loop back. The transmitter output path is disconnected from the TX pin
// and the RX input pin is internally looped back out to the TX pin. Data received
// at RX will be received by the device and also sent directly back out on TX.
#define SI32_UART_A_MODE_LBMD_TX_ONLY_VALUE  2
#define SI32_UART_A_MODE_LBMD_TX_ONLY_U32 \
   (SI32_UART_A_MODE_LBMD_TX_ONLY_VALUE << SI32_UART_A_MODE_LBMD_SHIFT)
// Full loop back. Internally, the transmitter output is routed back to the
// receiver input. Neither the transmitter nor receiver are connected to external
// device pins. The device pin RX is looped back to TX in a similar fashion. Data
// transmitted on TX will be sent directly back in on RX.
#define SI32_UART_A_MODE_LBMD_BOTH_VALUE  3
#define SI32_UART_A_MODE_LBMD_BOTH_U32 \
   (SI32_UART_A_MODE_LBMD_BOTH_VALUE << SI32_UART_A_MODE_LBMD_SHIFT)

#define SI32_UART_A_MODE_DUPLEXMD_MASK  0x08000000
#define SI32_UART_A_MODE_DUPLEXMD_SHIFT  27
// Full-duplex mode. The transmitter and receiver can operate simultaneously.
#define SI32_UART_A_MODE_DUPLEXMD_FULL_DUPLEX_VALUE  0
#define SI32_UART_A_MODE_DUPLEXMD_FULL_DUPLEX_U32 \
   (SI32_UART_A_MODE_DUPLEXMD_FULL_DUPLEX_VALUE << SI32_UART_A_MODE_DUPLEXMD_SHIFT)
// Half-duplex mode. The transmitter automatically inhibits when the receiver is
// active and the receiver automatically inhibits when the transmitter is active.
#define SI32_UART_A_MODE_DUPLEXMD_HALF_DUPLEX_VALUE  1
#define SI32_UART_A_MODE_DUPLEXMD_HALF_DUPLEX_U32 \
   (SI32_UART_A_MODE_DUPLEXMD_HALF_DUPLEX_VALUE << SI32_UART_A_MODE_DUPLEXMD_SHIFT)

#define SI32_UART_A_MODE_ITSEN_MASK  0x40000000
#define SI32_UART_A_MODE_ITSEN_SHIFT  30
// The TX and UCLK (if in synchronous master mode) pins are always an output in
// this mode, even when idle.
#define SI32_UART_A_MODE_ITSEN_DISABLED_VALUE  0
#define SI32_UART_A_MODE_ITSEN_DISABLED_U32 \
   (SI32_UART_A_MODE_ITSEN_DISABLED_VALUE << SI32_UART_A_MODE_ITSEN_SHIFT)
// The TX pin is tristated when idle. If ISTCLK is cleared to 0 and the transmitter
// is configured in synchronous master mode, the UCLK pin will also be tristated
// when idle.
#define SI32_UART_A_MODE_ITSEN_ENABLED_VALUE  1
#define SI32_UART_A_MODE_ITSEN_ENABLED_U32 \
   (SI32_UART_A_MODE_ITSEN_ENABLED_VALUE << SI32_UART_A_MODE_ITSEN_SHIFT)



struct SI32_UART_A_FLOWCN_Struct
{
   union
   {
      struct
      {
         // RTS State
         volatile uint32_t RTS: 1;
         // RX Pin Status
         volatile uint32_t RX: 1;
                  uint32_t reserved0: 3;
         // RTS Invert Enable
         volatile uint32_t RTSINVEN: 1;
         // RTS Threshold Control
         volatile uint32_t RTSTH: 1;
         // RTS Enable
         volatile uint32_t RTSEN: 1;
                  uint32_t reserved1: 8;
         // CTS State
         volatile uint32_t CTS: 1;
         // TX State
         volatile uint32_t TX: 1;
                  uint32_t reserved2: 3;
         // CTS Invert Enable
         volatile uint32_t CTSINVEN: 1;
                  uint32_t reserved3: 1;
         // CTS Enable
         volatile uint32_t CTSEN: 1;
                  uint32_t reserved4: 4;
         // Transmit IrDA Pulse Width
         volatile uint32_t TIRDAPW: 2;
                  uint32_t reserved5: 2;
      };
      volatile uint32_t U32;
   };
};

#define SI32_UART_A_FLOWCN_RTS_MASK  0x00000001
#define SI32_UART_A_FLOWCN_RTS_SHIFT  0
// RTS pin (before optional inversion) is driven low.
#define SI32_UART_A_FLOWCN_RTS_LOW_VALUE  0
#define SI32_UART_A_FLOWCN_RTS_LOW_U32 \
   (SI32_UART_A_FLOWCN_RTS_LOW_VALUE << SI32_UART_A_FLOWCN_RTS_SHIFT)
// RTS pin (before optional inversion) is driven high.
#define SI32_UART_A_FLOWCN_RTS_HIGH_VALUE  1
#define SI32_UART_A_FLOWCN_RTS_HIGH_U32 \
   (SI32_UART_A_FLOWCN_RTS_HIGH_VALUE << SI32_UART_A_FLOWCN_RTS_SHIFT)

#define SI32_UART_A_FLOWCN_RX_MASK  0x00000002
#define SI32_UART_A_FLOWCN_RX_SHIFT  1
// RX pin (after optional inversion) is low.
#define SI32_UART_A_FLOWCN_RX_LOW_VALUE  0
#define SI32_UART_A_FLOWCN_RX_LOW_U32 \
   (SI32_UART_A_FLOWCN_RX_LOW_VALUE << SI32_UART_A_FLOWCN_RX_SHIFT)
// RX pin (after optional inversion) is high.
#define SI32_UART_A_FLOWCN_RX_HIGH_VALUE  1
#define SI32_UART_A_FLOWCN_RX_HIGH_U32 \
   (SI32_UART_A_FLOWCN_RX_HIGH_VALUE << SI32_UART_A_FLOWCN_RX_SHIFT)

#define SI32_UART_A_FLOWCN_RTSINVEN_MASK  0x00000020
#define SI32_UART_A_FLOWCN_RTSINVEN_SHIFT  5
// The UART does not invert the RTS signal before driving the pin.
#define SI32_UART_A_FLOWCN_RTSINVEN_DISABLED_VALUE  0
#define SI32_UART_A_FLOWCN_RTSINVEN_DISABLED_U32 \
   (SI32_UART_A_FLOWCN_RTSINVEN_DISABLED_VALUE << SI32_UART_A_FLOWCN_RTSINVEN_SHIFT)
// The UART inverts the RTS signal driving the pin.
#define SI32_UART_A_FLOWCN_RTSINVEN_ENABLED_VALUE  1
#define SI32_UART_A_FLOWCN_RTSINVEN_ENABLED_U32 \
   (SI32_UART_A_FLOWCN_RTSINVEN_ENABLED_VALUE << SI32_UART_A_FLOWCN_RTSINVEN_SHIFT)

#define SI32_UART_A_FLOWCN_RTSTH_MASK  0x00000040
#define SI32_UART_A_FLOWCN_RTSTH_SHIFT  6
// RTS is de-asserted when the receive FIFO and shift register are full and no more
// incoming data can be stored.
#define SI32_UART_A_FLOWCN_RTSTH_FULL_VALUE  0
#define SI32_UART_A_FLOWCN_RTSTH_FULL_U32 \
   (SI32_UART_A_FLOWCN_RTSTH_FULL_VALUE << SI32_UART_A_FLOWCN_RTSTH_SHIFT)
// RTS is de-asserted when the receive FIFO and shift register are nearly full and
// only one more data can be received.
#define SI32_UART_A_FLOWCN_RTSTH_ONE_BYTE_FREE_VALUE  1
#define SI32_UART_A_FLOWCN_RTSTH_ONE_BYTE_FREE_U32 \
   (SI32_UART_A_FLOWCN_RTSTH_ONE_BYTE_FREE_VALUE << SI32_UART_A_FLOWCN_RTSTH_SHIFT)

#define SI32_UART_A_FLOWCN_RTSEN_MASK  0x00000080
#define SI32_UART_A_FLOWCN_RTSEN_SHIFT  7
// The RTS state is not changed by hardware. The RTS bit can be written only when
// hardware RTS is disabled (RTSEN = 0).
#define SI32_UART_A_FLOWCN_RTSEN_DISABLED_VALUE  0
#define SI32_UART_A_FLOWCN_RTSEN_DISABLED_U32 \
   (SI32_UART_A_FLOWCN_RTSEN_DISABLED_VALUE << SI32_UART_A_FLOWCN_RTSEN_SHIFT)
// Hardware sets RTS when the receive FIFO is at or above the threshold set by
// RTSTH and clears RTS otherwise.
#define SI32_UART_A_FLOWCN_RTSEN_ENABLED_VALUE  1
#define SI32_UART_A_FLOWCN_RTSEN_ENABLED_U32 \
   (SI32_UART_A_FLOWCN_RTSEN_ENABLED_VALUE << SI32_UART_A_FLOWCN_RTSEN_SHIFT)

#define SI32_UART_A_FLOWCN_CTS_MASK  0x00010000
#define SI32_UART_A_FLOWCN_CTS_SHIFT  16
// Indicates the CTS pin state (after optional inversion) is low.
#define SI32_UART_A_FLOWCN_CTS_LOW_VALUE  0
#define SI32_UART_A_FLOWCN_CTS_LOW_U32 \
   (SI32_UART_A_FLOWCN_CTS_LOW_VALUE << SI32_UART_A_FLOWCN_CTS_SHIFT)
// Indicates the CTS pin state (after optional inversion) is high.
#define SI32_UART_A_FLOWCN_CTS_HIGH_VALUE  1
#define SI32_UART_A_FLOWCN_CTS_HIGH_U32 \
   (SI32_UART_A_FLOWCN_CTS_HIGH_VALUE << SI32_UART_A_FLOWCN_CTS_SHIFT)

#define SI32_UART_A_FLOWCN_TX_MASK  0x00020000
#define SI32_UART_A_FLOWCN_TX_SHIFT  17
// The TX pin (before optional inversion) is low.
#define SI32_UART_A_FLOWCN_TX_LOW_VALUE  0
#define SI32_UART_A_FLOWCN_TX_LOW_U32 \
   (SI32_UART_A_FLOWCN_TX_LOW_VALUE << SI32_UART_A_FLOWCN_TX_SHIFT)
// The TX pin (before optional inversion) is high.
#define SI32_UART_A_FLOWCN_TX_HIGH_VALUE  1
#define SI32_UART_A_FLOWCN_TX_HIGH_U32 \
   (SI32_UART_A_FLOWCN_TX_HIGH_VALUE << SI32_UART_A_FLOWCN_TX_SHIFT)

#define SI32_UART_A_FLOWCN_CTSINVEN_MASK  0x00200000
#define SI32_UART_A_FLOWCN_CTSINVEN_SHIFT  21
// The UART does not invert CTS.
#define SI32_UART_A_FLOWCN_CTSINVEN_DISABLED_VALUE  0
#define SI32_UART_A_FLOWCN_CTSINVEN_DISABLED_U32 \
   (SI32_UART_A_FLOWCN_CTSINVEN_DISABLED_VALUE << SI32_UART_A_FLOWCN_CTSINVEN_SHIFT)
// The UART inverts CTS.
#define SI32_UART_A_FLOWCN_CTSINVEN_ENABLED_VALUE  1
#define SI32_UART_A_FLOWCN_CTSINVEN_ENABLED_U32 \
   (SI32_UART_A_FLOWCN_CTSINVEN_ENABLED_VALUE << SI32_UART_A_FLOWCN_CTSINVEN_SHIFT)

#define SI32_UART_A_FLOWCN_CTSEN_MASK  0x00800000
#define SI32_UART_A_FLOWCN_CTSEN_SHIFT  23
// The CTS pin state does not affect transmissions.
#define SI32_UART_A_FLOWCN_CTSEN_DISABLED_VALUE  0
#define SI32_UART_A_FLOWCN_CTSEN_DISABLED_U32 \
   (SI32_UART_A_FLOWCN_CTSEN_DISABLED_VALUE << SI32_UART_A_FLOWCN_CTSEN_SHIFT)
// Transmissions will begin only if the CTS pin (after optional inversion) is low.
#define SI32_UART_A_FLOWCN_CTSEN_ENABLED_VALUE  1
#define SI32_UART_A_FLOWCN_CTSEN_ENABLED_U32 \
   (SI32_UART_A_FLOWCN_CTSEN_ENABLED_VALUE << SI32_UART_A_FLOWCN_CTSEN_SHIFT)

#define SI32_UART_A_FLOWCN_TIRDAPW_MASK  0x30000000
#define SI32_UART_A_FLOWCN_TIRDAPW_SHIFT  28
// The IrDA pulse width is 1/16th of a bit period.
#define SI32_UART_A_FLOWCN_TIRDAPW_1_16TH_VALUE  0
#define SI32_UART_A_FLOWCN_TIRDAPW_1_16TH_U32 \
   (SI32_UART_A_FLOWCN_TIRDAPW_1_16TH_VALUE << SI32_UART_A_FLOWCN_TIRDAPW_SHIFT)
// The IrDA pulse width is 1/8th of a bit period.
#define SI32_UART_A_FLOWCN_TIRDAPW_1_8TH_VALUE  1
#define SI32_UART_A_FLOWCN_TIRDAPW_1_8TH_U32 \
   (SI32_UART_A_FLOWCN_TIRDAPW_1_8TH_VALUE << SI32_UART_A_FLOWCN_TIRDAPW_SHIFT)
// The IrDA pulse width is 3/16th of a bit period.
#define SI32_UART_A_FLOWCN_TIRDAPW_3_16TH_VALUE  2
#define SI32_UART_A_FLOWCN_TIRDAPW_3_16TH_U32 \
   (SI32_UART_A_FLOWCN_TIRDAPW_3_16TH_VALUE << SI32_UART_A_FLOWCN_TIRDAPW_SHIFT)
// The IrDA pulse width is 1/4th of a bit period.
#define SI32_UART_A_FLOWCN_TIRDAPW_1_4TH_VALUE  3
#define SI32_UART_A_FLOWCN_TIRDAPW_1_4TH_U32 \
   (SI32_UART_A_FLOWCN_TIRDAPW_1_4TH_VALUE << SI32_UART_A_FLOWCN_TIRDAPW_SHIFT)



struct SI32_UART_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Receive Frame Error Interrupt Flag
         volatile uint32_t RFRMERI: 1;
         // Receive Parity Error Interrupt Flag
         volatile uint32_t RPARERI: 1;
         // Receive Overrun Error Interrupt Flag
         volatile uint32_t ROREI: 1;
         // Receive Data Request Interrupt Flag
         volatile uint32_t RDREQI: 1;
                  uint32_t reserved0: 1;
         // Receive Error Interrupt Enable
         volatile uint32_t RERIEN: 1;
         // Receive Data Request Interrupt Enable
         volatile uint32_t RDREQIEN: 1;
                  uint32_t reserved1: 1;
         // Match Mode
         volatile uint32_t MATMD: 2;
         // Receiver Auto-Baud Enable
         volatile uint32_t RABDEN: 1;
         // Receiver Busy Flag
         volatile uint32_t RBUSYF: 1;
         // Last Receive Bit
         volatile uint32_t RBIT: 1;
         // Receiver One-Shot Enable
         volatile uint32_t ROSEN: 1;
         // Receiver Inhibit
         volatile uint32_t RINH: 1;
         // Receiver Enable
         volatile uint32_t REN: 1;
         // Smartcard Parity Error Interrupt Flag
         volatile uint32_t TSCERI: 1;
                  uint32_t reserved2: 1;
         // Transmit Data Request Interrupt Flag
         volatile uint32_t TDREQI: 1;
         // Transmit Complete Interrupt Flag
         volatile uint32_t TCPTI: 1;
         // Transmit Complete Threshold
         volatile uint32_t TCPTTH: 1;
         // Transmit Error Interrupt Enable
         volatile uint32_t TERIEN: 1;
         // Transmit Data Request Interrupt Enable
         volatile uint32_t TDREQIEN: 1;
         // Transmit Complete Interrupt Enable
         volatile uint32_t TCPTIEN: 1;
                  uint32_t reserved3: 3;
         // Transmitter Busy Flag
         volatile uint32_t TBUSYF: 1;
         // Last Transmit Bit
         volatile uint32_t TBIT: 1;
                  uint32_t reserved4: 1;
         // Transmit Inhibit
         volatile uint32_t TINH: 1;
         // Transmitter Enable
         volatile uint32_t TEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_UART_A_CONTROL_RFRMERI_MASK  0x00000001
#define SI32_UART_A_CONTROL_RFRMERI_SHIFT  0
// Read: A frame error has not occurred since RFRMERI was last cleared. Write:
// Clear the interrupt.
#define SI32_UART_A_CONTROL_RFRMERI_NOT_SET_VALUE  0
#define SI32_UART_A_CONTROL_RFRMERI_NOT_SET_U32 \
   (SI32_UART_A_CONTROL_RFRMERI_NOT_SET_VALUE << SI32_UART_A_CONTROL_RFRMERI_SHIFT)
// Read: A frame error occurred. Write: Force a frame error interrupt.
#define SI32_UART_A_CONTROL_RFRMERI_SET_VALUE  1
#define SI32_UART_A_CONTROL_RFRMERI_SET_U32 \
   (SI32_UART_A_CONTROL_RFRMERI_SET_VALUE << SI32_UART_A_CONTROL_RFRMERI_SHIFT)

#define SI32_UART_A_CONTROL_RPARERI_MASK  0x00000002
#define SI32_UART_A_CONTROL_RPARERI_SHIFT  1
// Read: An invalid parity bit has not been received since RPARERI was last
// cleared. Write: Clear the interrupt.
#define SI32_UART_A_CONTROL_RPARERI_NOT_SET_VALUE  0
#define SI32_UART_A_CONTROL_RPARERI_NOT_SET_U32 \
   (SI32_UART_A_CONTROL_RPARERI_NOT_SET_VALUE << SI32_UART_A_CONTROL_RPARERI_SHIFT)
// Read: An invalid parity bit has been received since RPARERI was last cleared.
// Write: Force a parity error interrupt.
#define SI32_UART_A_CONTROL_RPARERI_SET_VALUE  1
#define SI32_UART_A_CONTROL_RPARERI_SET_U32 \
   (SI32_UART_A_CONTROL_RPARERI_SET_VALUE << SI32_UART_A_CONTROL_RPARERI_SHIFT)

#define SI32_UART_A_CONTROL_ROREI_MASK  0x00000004
#define SI32_UART_A_CONTROL_ROREI_SHIFT  2
// Read: A receiver overrun has not occurred since ROREI was last cleared. Write:
// Clear the interrupt.
#define SI32_UART_A_CONTROL_ROREI_NOT_SET_VALUE  0
#define SI32_UART_A_CONTROL_ROREI_NOT_SET_U32 \
   (SI32_UART_A_CONTROL_ROREI_NOT_SET_VALUE << SI32_UART_A_CONTROL_ROREI_SHIFT)
// Read: A receiver overrun occurred. Write: Force a receiver overrun interrupt.
#define SI32_UART_A_CONTROL_ROREI_SET_VALUE  1
#define SI32_UART_A_CONTROL_ROREI_SET_U32 \
   (SI32_UART_A_CONTROL_ROREI_SET_VALUE << SI32_UART_A_CONTROL_ROREI_SHIFT)

#define SI32_UART_A_CONTROL_RDREQI_MASK  0x00000008
#define SI32_UART_A_CONTROL_RDREQI_SHIFT  3
// Fewer than RFTH FIFO slots are filled with data.
#define SI32_UART_A_CONTROL_RDREQI_NOT_SET_VALUE  0
#define SI32_UART_A_CONTROL_RDREQI_NOT_SET_U32 \
   (SI32_UART_A_CONTROL_RDREQI_NOT_SET_VALUE << SI32_UART_A_CONTROL_RDREQI_SHIFT)
// At least RFTH FIFO slots are filled with data.
#define SI32_UART_A_CONTROL_RDREQI_SET_VALUE  1
#define SI32_UART_A_CONTROL_RDREQI_SET_U32 \
   (SI32_UART_A_CONTROL_RDREQI_SET_VALUE << SI32_UART_A_CONTROL_RDREQI_SHIFT)

#define SI32_UART_A_CONTROL_RERIEN_MASK  0x00000020
#define SI32_UART_A_CONTROL_RERIEN_SHIFT  5
// Disable the receive error interrupt.
#define SI32_UART_A_CONTROL_RERIEN_DISABLED_VALUE  0
#define SI32_UART_A_CONTROL_RERIEN_DISABLED_U32 \
   (SI32_UART_A_CONTROL_RERIEN_DISABLED_VALUE << SI32_UART_A_CONTROL_RERIEN_SHIFT)
// Enable the receive error interrupt. A receive error interrupt is asserted when
// ROREI, RFRMERI, or RPARERI is set to 1.
#define SI32_UART_A_CONTROL_RERIEN_ENABLED_VALUE  1
#define SI32_UART_A_CONTROL_RERIEN_ENABLED_U32 \
   (SI32_UART_A_CONTROL_RERIEN_ENABLED_VALUE << SI32_UART_A_CONTROL_RERIEN_SHIFT)

#define SI32_UART_A_CONTROL_RDREQIEN_MASK  0x00000040
#define SI32_UART_A_CONTROL_RDREQIEN_SHIFT  6
// Disable the read data request interrupt.
#define SI32_UART_A_CONTROL_RDREQIEN_DISABLED_VALUE  0
#define SI32_UART_A_CONTROL_RDREQIEN_DISABLED_U32 \
   (SI32_UART_A_CONTROL_RDREQIEN_DISABLED_VALUE << SI32_UART_A_CONTROL_RDREQIEN_SHIFT)
// Enable the read data request interrupt. A receive interrupt is generated when
// RDREQI is set to 1.
#define SI32_UART_A_CONTROL_RDREQIEN_ENABLED_VALUE  1
#define SI32_UART_A_CONTROL_RDREQIEN_ENABLED_U32 \
   (SI32_UART_A_CONTROL_RDREQIEN_ENABLED_VALUE << SI32_UART_A_CONTROL_RDREQIEN_SHIFT)

#define SI32_UART_A_CONTROL_MATMD_MASK  0x00000300
#define SI32_UART_A_CONTROL_MATMD_SHIFT  8
// Disable the match function.
#define SI32_UART_A_CONTROL_MATMD_OFF_VALUE  0
#define SI32_UART_A_CONTROL_MATMD_OFF_U32 \
   (SI32_UART_A_CONTROL_MATMD_OFF_VALUE << SI32_UART_A_CONTROL_MATMD_SHIFT)
// (MCE) Data whose last data bit equals RBIT is accepted and stored.
#define SI32_UART_A_CONTROL_MATMD_MCE_VALUE  1
#define SI32_UART_A_CONTROL_MATMD_MCE_U32 \
   (SI32_UART_A_CONTROL_MATMD_MCE_VALUE << SI32_UART_A_CONTROL_MATMD_SHIFT)
// (Frame) A framing error is asserted if the last received bit matches RBIT.
#define SI32_UART_A_CONTROL_MATMD_FRAME_VALUE  2
#define SI32_UART_A_CONTROL_MATMD_FRAME_U32 \
   (SI32_UART_A_CONTROL_MATMD_FRAME_VALUE << SI32_UART_A_CONTROL_MATMD_SHIFT)
// (Store) Store the last incoming data bit in RBIT. This mode can be used
// inconjunction with the RDATLN setting.
#define SI32_UART_A_CONTROL_MATMD_STORE_VALUE  3
#define SI32_UART_A_CONTROL_MATMD_STORE_U32 \
   (SI32_UART_A_CONTROL_MATMD_STORE_VALUE << SI32_UART_A_CONTROL_MATMD_SHIFT)

#define SI32_UART_A_CONTROL_RABDEN_MASK  0x00000400
#define SI32_UART_A_CONTROL_RABDEN_SHIFT  10
// Disable receiver auto-baud.
#define SI32_UART_A_CONTROL_RABDEN_DISABLED_VALUE  0
#define SI32_UART_A_CONTROL_RABDEN_DISABLED_U32 \
   (SI32_UART_A_CONTROL_RABDEN_DISABLED_VALUE << SI32_UART_A_CONTROL_RABDEN_SHIFT)
// Enable receiver auto-baud.
#define SI32_UART_A_CONTROL_RABDEN_ENABLED_VALUE  1
#define SI32_UART_A_CONTROL_RABDEN_ENABLED_U32 \
   (SI32_UART_A_CONTROL_RABDEN_ENABLED_VALUE << SI32_UART_A_CONTROL_RABDEN_SHIFT)

#define SI32_UART_A_CONTROL_RBUSYF_MASK  0x00000800
#define SI32_UART_A_CONTROL_RBUSYF_SHIFT  11
// The UART receiver is idle.
#define SI32_UART_A_CONTROL_RBUSYF_NOT_SET_VALUE  0
#define SI32_UART_A_CONTROL_RBUSYF_NOT_SET_U32 \
   (SI32_UART_A_CONTROL_RBUSYF_NOT_SET_VALUE << SI32_UART_A_CONTROL_RBUSYF_SHIFT)
// The UART receiver is receiving data.
#define SI32_UART_A_CONTROL_RBUSYF_SET_VALUE  1
#define SI32_UART_A_CONTROL_RBUSYF_SET_U32 \
   (SI32_UART_A_CONTROL_RBUSYF_SET_VALUE << SI32_UART_A_CONTROL_RBUSYF_SHIFT)

#define SI32_UART_A_CONTROL_RBIT_MASK  0x00001000
#define SI32_UART_A_CONTROL_RBIT_SHIFT  12
#define SI32_UART_A_CONTROL_RBIT_NOT_SET_VALUE  0
#define SI32_UART_A_CONTROL_RBIT_NOT_SET_U32 \
   (SI32_UART_A_CONTROL_RBIT_NOT_SET_VALUE << SI32_UART_A_CONTROL_RBIT_SHIFT)
#define SI32_UART_A_CONTROL_RBIT_SET_VALUE  1
#define SI32_UART_A_CONTROL_RBIT_SET_U32 \
   (SI32_UART_A_CONTROL_RBIT_SET_VALUE << SI32_UART_A_CONTROL_RBIT_SHIFT)

#define SI32_UART_A_CONTROL_ROSEN_MASK  0x00002000
#define SI32_UART_A_CONTROL_ROSEN_SHIFT  13
// Disable one-shot receive mode.
#define SI32_UART_A_CONTROL_ROSEN_DISABLED_VALUE  0
#define SI32_UART_A_CONTROL_ROSEN_DISABLED_U32 \
   (SI32_UART_A_CONTROL_ROSEN_DISABLED_VALUE << SI32_UART_A_CONTROL_ROSEN_SHIFT)
// Enable one-shot receive mode.
#define SI32_UART_A_CONTROL_ROSEN_ENABLED_VALUE  1
#define SI32_UART_A_CONTROL_ROSEN_ENABLED_U32 \
   (SI32_UART_A_CONTROL_ROSEN_ENABLED_VALUE << SI32_UART_A_CONTROL_ROSEN_SHIFT)

#define SI32_UART_A_CONTROL_RINH_MASK  0x00004000
#define SI32_UART_A_CONTROL_RINH_SHIFT  14
// The receiver operates normally.
#define SI32_UART_A_CONTROL_RINH_INACTIVE_VALUE  0
#define SI32_UART_A_CONTROL_RINH_INACTIVE_U32 \
   (SI32_UART_A_CONTROL_RINH_INACTIVE_VALUE << SI32_UART_A_CONTROL_RINH_SHIFT)
// RTS is immediately asserted when RINH is set. The receiver will complete any
// ongoing reception, but ignore all traffic after that.
#define SI32_UART_A_CONTROL_RINH_ACTIVE_VALUE  1
#define SI32_UART_A_CONTROL_RINH_ACTIVE_U32 \
   (SI32_UART_A_CONTROL_RINH_ACTIVE_VALUE << SI32_UART_A_CONTROL_RINH_SHIFT)

#define SI32_UART_A_CONTROL_REN_MASK  0x00008000
#define SI32_UART_A_CONTROL_REN_SHIFT  15
// Disable the receiver. The receiver can receive one data transaction only if
// ROSEN is set.
#define SI32_UART_A_CONTROL_REN_DISABLED_VALUE  0
#define SI32_UART_A_CONTROL_REN_DISABLED_U32 \
   (SI32_UART_A_CONTROL_REN_DISABLED_VALUE << SI32_UART_A_CONTROL_REN_SHIFT)
// Enable the receiver.
#define SI32_UART_A_CONTROL_REN_ENABLED_VALUE  1
#define SI32_UART_A_CONTROL_REN_ENABLED_U32 \
   (SI32_UART_A_CONTROL_REN_ENABLED_VALUE << SI32_UART_A_CONTROL_REN_SHIFT)

#define SI32_UART_A_CONTROL_TSCERI_MASK  0x00010000
#define SI32_UART_A_CONTROL_TSCERI_SHIFT  16
// Read: A Smartcard parity error has not occurred since TSCERI was last cleared.
// Write: Clear the interrupt.
#define SI32_UART_A_CONTROL_TSCERI_NOT_SET_VALUE  0
#define SI32_UART_A_CONTROL_TSCERI_NOT_SET_U32 \
   (SI32_UART_A_CONTROL_TSCERI_NOT_SET_VALUE << SI32_UART_A_CONTROL_TSCERI_SHIFT)
// Read: A Smartcard parity error occurred. Write: Force a Smartcard parity error
// interrupt.
#define SI32_UART_A_CONTROL_TSCERI_SET_VALUE  1
#define SI32_UART_A_CONTROL_TSCERI_SET_U32 \
   (SI32_UART_A_CONTROL_TSCERI_SET_VALUE << SI32_UART_A_CONTROL_TSCERI_SHIFT)

#define SI32_UART_A_CONTROL_TDREQI_MASK  0x00040000
#define SI32_UART_A_CONTROL_TDREQI_SHIFT  18
// The transmitter is not requesting more FIFO data.
#define SI32_UART_A_CONTROL_TDREQI_NOT_SET_VALUE  0
#define SI32_UART_A_CONTROL_TDREQI_NOT_SET_U32 \
   (SI32_UART_A_CONTROL_TDREQI_NOT_SET_VALUE << SI32_UART_A_CONTROL_TDREQI_SHIFT)
// The transmitter is requesting more FIFO data.
#define SI32_UART_A_CONTROL_TDREQI_SET_VALUE  1
#define SI32_UART_A_CONTROL_TDREQI_SET_U32 \
   (SI32_UART_A_CONTROL_TDREQI_SET_VALUE << SI32_UART_A_CONTROL_TDREQI_SHIFT)

#define SI32_UART_A_CONTROL_TCPTI_MASK  0x00080000
#define SI32_UART_A_CONTROL_TCPTI_SHIFT  19
// Read: A transmit has not completed since TCPTI was last cleared. Write: Clear
// the interrupt.
#define SI32_UART_A_CONTROL_TCPTI_NOT_SET_VALUE  0
#define SI32_UART_A_CONTROL_TCPTI_NOT_SET_U32 \
   (SI32_UART_A_CONTROL_TCPTI_NOT_SET_VALUE << SI32_UART_A_CONTROL_TCPTI_SHIFT)
// Read: A byte was transmitted (TCCPTH = 0) or the last available byte was
// transmitted (TCPTTH = 1). Write: Force a transmit complete interrupt.
#define SI32_UART_A_CONTROL_TCPTI_SET_VALUE  1
#define SI32_UART_A_CONTROL_TCPTI_SET_U32 \
   (SI32_UART_A_CONTROL_TCPTI_SET_VALUE << SI32_UART_A_CONTROL_TCPTI_SHIFT)

#define SI32_UART_A_CONTROL_TCPTTH_MASK  0x00100000
#define SI32_UART_A_CONTROL_TCPTTH_SHIFT  20
// A transmit is completed (TCPTI = 1) at the end of each transmission.
#define SI32_UART_A_CONTROL_TCPTTH_SET_ON_TX_VALUE  0
#define SI32_UART_A_CONTROL_TCPTTH_SET_ON_TX_U32 \
   (SI32_UART_A_CONTROL_TCPTTH_SET_ON_TX_VALUE << SI32_UART_A_CONTROL_TCPTTH_SHIFT)
// A transmit is completed (TCPTI = 1) only at the end of a transmission when no
// more data is available to transmit.
#define SI32_UART_A_CONTROL_TCPTTH_SET_ON_EMPTY_VALUE  1
#define SI32_UART_A_CONTROL_TCPTTH_SET_ON_EMPTY_U32 \
   (SI32_UART_A_CONTROL_TCPTTH_SET_ON_EMPTY_VALUE << SI32_UART_A_CONTROL_TCPTTH_SHIFT)

#define SI32_UART_A_CONTROL_TERIEN_MASK  0x00200000
#define SI32_UART_A_CONTROL_TERIEN_SHIFT  21
// Disable the transmit error interrupt.
#define SI32_UART_A_CONTROL_TERIEN_DISABLED_VALUE  0
#define SI32_UART_A_CONTROL_TERIEN_DISABLED_U32 \
   (SI32_UART_A_CONTROL_TERIEN_DISABLED_VALUE << SI32_UART_A_CONTROL_TERIEN_SHIFT)
// Enable the transmit error interrupt. A transmit interrupt is generated when
// TSCERI is set to 1.
#define SI32_UART_A_CONTROL_TERIEN_ENABLED_VALUE  1
#define SI32_UART_A_CONTROL_TERIEN_ENABLED_U32 \
   (SI32_UART_A_CONTROL_TERIEN_ENABLED_VALUE << SI32_UART_A_CONTROL_TERIEN_SHIFT)

#define SI32_UART_A_CONTROL_TDREQIEN_MASK  0x00400000
#define SI32_UART_A_CONTROL_TDREQIEN_SHIFT  22
// Disable the transmit data request interrupt.
#define SI32_UART_A_CONTROL_TDREQIEN_DISABLED_VALUE  0
#define SI32_UART_A_CONTROL_TDREQIEN_DISABLED_U32 \
   (SI32_UART_A_CONTROL_TDREQIEN_DISABLED_VALUE << SI32_UART_A_CONTROL_TDREQIEN_SHIFT)
// Enable the transmit data request interrupt. A transmit interrupt is asserted
// when TDREQI is set to 1.
#define SI32_UART_A_CONTROL_TDREQIEN_ENABLED_VALUE  1
#define SI32_UART_A_CONTROL_TDREQIEN_ENABLED_U32 \
   (SI32_UART_A_CONTROL_TDREQIEN_ENABLED_VALUE << SI32_UART_A_CONTROL_TDREQIEN_SHIFT)

#define SI32_UART_A_CONTROL_TCPTIEN_MASK  0x00800000
#define SI32_UART_A_CONTROL_TCPTIEN_SHIFT  23
// Disable the transmit complete interrupt.
#define SI32_UART_A_CONTROL_TCPTIEN_DISABLED_VALUE  0
#define SI32_UART_A_CONTROL_TCPTIEN_DISABLED_U32 \
   (SI32_UART_A_CONTROL_TCPTIEN_DISABLED_VALUE << SI32_UART_A_CONTROL_TCPTIEN_SHIFT)
// Enable the transmit complete interrupt. A transmit interrupt is generated when
// TCPTI is set to 1.
#define SI32_UART_A_CONTROL_TCPTIEN_ENABLED_VALUE  1
#define SI32_UART_A_CONTROL_TCPTIEN_ENABLED_U32 \
   (SI32_UART_A_CONTROL_TCPTIEN_ENABLED_VALUE << SI32_UART_A_CONTROL_TCPTIEN_SHIFT)

#define SI32_UART_A_CONTROL_TBUSYF_MASK  0x08000000
#define SI32_UART_A_CONTROL_TBUSYF_SHIFT  27
// The UART transmitter is idle.
#define SI32_UART_A_CONTROL_TBUSYF_NOT_SET_VALUE  0
#define SI32_UART_A_CONTROL_TBUSYF_NOT_SET_U32 \
   (SI32_UART_A_CONTROL_TBUSYF_NOT_SET_VALUE << SI32_UART_A_CONTROL_TBUSYF_SHIFT)
// The UART transmitter is active and transmitting.
#define SI32_UART_A_CONTROL_TBUSYF_SET_VALUE  1
#define SI32_UART_A_CONTROL_TBUSYF_SET_U32 \
   (SI32_UART_A_CONTROL_TBUSYF_SET_VALUE << SI32_UART_A_CONTROL_TBUSYF_SHIFT)

#define SI32_UART_A_CONTROL_TBIT_MASK  0x10000000
#define SI32_UART_A_CONTROL_TBIT_SHIFT  28
#define SI32_UART_A_CONTROL_TBIT_NOT_SET_VALUE  0
#define SI32_UART_A_CONTROL_TBIT_NOT_SET_U32 \
   (SI32_UART_A_CONTROL_TBIT_NOT_SET_VALUE << SI32_UART_A_CONTROL_TBIT_SHIFT)
#define SI32_UART_A_CONTROL_TBIT_SET_VALUE  1
#define SI32_UART_A_CONTROL_TBIT_SET_U32 \
   (SI32_UART_A_CONTROL_TBIT_SET_VALUE << SI32_UART_A_CONTROL_TBIT_SHIFT)

#define SI32_UART_A_CONTROL_TINH_MASK  0x40000000
#define SI32_UART_A_CONTROL_TINH_SHIFT  30
// The transmitter operates normally.
#define SI32_UART_A_CONTROL_TINH_INACTIVE_VALUE  0
#define SI32_UART_A_CONTROL_TINH_INACTIVE_U32 \
   (SI32_UART_A_CONTROL_TINH_INACTIVE_VALUE << SI32_UART_A_CONTROL_TINH_SHIFT)
// Transmissions are inhibited. The transmitter will stall after any current
// transmission is complete.
#define SI32_UART_A_CONTROL_TINH_ACTIVE_VALUE  1
#define SI32_UART_A_CONTROL_TINH_ACTIVE_U32 \
   (SI32_UART_A_CONTROL_TINH_ACTIVE_VALUE << SI32_UART_A_CONTROL_TINH_SHIFT)

#define SI32_UART_A_CONTROL_TEN_MASK  0x80000000
#define SI32_UART_A_CONTROL_TEN_SHIFT  31
// Disable the transmitter. When cleared, the transmitter immediately aborts any
// active transmission. Clearing this bit does not automatically flush the transmit
// FIFO.
#define SI32_UART_A_CONTROL_TEN_DISABLED_VALUE  0U
#define SI32_UART_A_CONTROL_TEN_DISABLED_U32 \
   (SI32_UART_A_CONTROL_TEN_DISABLED_VALUE << SI32_UART_A_CONTROL_TEN_SHIFT)
// Enable the transmitter. The transmitter will initiate a transmission when data
// becomes available in the transmit FIFO.
#define SI32_UART_A_CONTROL_TEN_ENABLED_VALUE  1U
#define SI32_UART_A_CONTROL_TEN_ENABLED_U32 \
   (SI32_UART_A_CONTROL_TEN_ENABLED_VALUE << SI32_UART_A_CONTROL_TEN_SHIFT)



struct SI32_UART_A_IPDELAY_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 16;
         // Inter-Packet Delay
         volatile uint8_t IPDELAY_BITS;
                  uint32_t reserved1: 8;
      };
      volatile uint32_t U32;
   };
};

#define SI32_UART_A_IPDELAY_IPDELAY_MASK  0x00FF0000
#define SI32_UART_A_IPDELAY_IPDELAY_SHIFT  16



struct SI32_UART_A_BAUDRATE_Struct
{
   union
   {
      struct
      {
         // Receiver Baud Rate Control
         volatile uint16_t RBAUD;
         // Transmitter Baud Rate Control
         volatile uint16_t TBAUD;
      };
      volatile uint32_t U32;
   };
};

#define SI32_UART_A_BAUDRATE_RBAUD_MASK  0x0000FFFF
#define SI32_UART_A_BAUDRATE_RBAUD_SHIFT  0

#define SI32_UART_A_BAUDRATE_TBAUD_MASK  0xFFFF0000
#define SI32_UART_A_BAUDRATE_TBAUD_SHIFT  16



struct SI32_UART_A_FIFOCN_Struct
{
   union
   {
      struct
      {
         // Receive FIFO Count
         volatile uint32_t RCNT: 3;
                  uint32_t reserved0: 1;
         // Receive FIFO Threshold
         volatile uint32_t RFTH: 2;
                  uint32_t reserved1: 2;
         // Receive FIFO Flush
         volatile uint32_t RFIFOFL: 1;
         // Receive FIFO Error Interrupt Flag
         volatile uint32_t RFERI: 1;
         // Receive Shift Register Full
         volatile uint32_t RSRFULLF: 1;
                  uint32_t reserved2: 5;
         // Transmit FIFO Count
         volatile uint32_t TCNT: 3;
                  uint32_t reserved3: 1;
         // Transmit FIFO Threshold
         volatile uint32_t TFTH: 2;
                  uint32_t reserved4: 2;
         // Transmit FIFO Flush
         volatile uint32_t TFIFOFL: 1;
         // Transmit FIFO Error Interrupt Flag
         volatile uint32_t TFERI: 1;
         // Transmit Shift Register Full Flag
         volatile uint32_t TSRFULLF: 1;
                  uint32_t reserved5: 5;
      };
      volatile uint32_t U32;
   };
};

#define SI32_UART_A_FIFOCN_RCNT_MASK  0x00000007
#define SI32_UART_A_FIFOCN_RCNT_SHIFT  0

#define SI32_UART_A_FIFOCN_RFTH_MASK  0x00000030
#define SI32_UART_A_FIFOCN_RFTH_SHIFT  4
// A read data request interrupt (RDREQI) is asserted when >= 1 FIFO slot is full.
#define SI32_UART_A_FIFOCN_RFTH_ONE_VALUE  0
#define SI32_UART_A_FIFOCN_RFTH_ONE_U32 \
   (SI32_UART_A_FIFOCN_RFTH_ONE_VALUE << SI32_UART_A_FIFOCN_RFTH_SHIFT)
// A read data request interrupt (RDREQI) is asserted when >= 2 FIFO slots are
// full.
#define SI32_UART_A_FIFOCN_RFTH_TWO_VALUE  1
#define SI32_UART_A_FIFOCN_RFTH_TWO_U32 \
   (SI32_UART_A_FIFOCN_RFTH_TWO_VALUE << SI32_UART_A_FIFOCN_RFTH_SHIFT)
// A read data request interrupt (RDREQI) is asserted when >= 4 FIFO slots are
// full.
#define SI32_UART_A_FIFOCN_RFTH_FOUR_VALUE  2
#define SI32_UART_A_FIFOCN_RFTH_FOUR_U32 \
   (SI32_UART_A_FIFOCN_RFTH_FOUR_VALUE << SI32_UART_A_FIFOCN_RFTH_SHIFT)

#define SI32_UART_A_FIFOCN_RFIFOFL_MASK  0x00000100
#define SI32_UART_A_FIFOCN_RFIFOFL_SHIFT  8
// Flush the contents of the receive FIFO and any data in the receive shift
// register.
#define SI32_UART_A_FIFOCN_RFIFOFL_SET_VALUE  1
#define SI32_UART_A_FIFOCN_RFIFOFL_SET_U32 \
   (SI32_UART_A_FIFOCN_RFIFOFL_SET_VALUE << SI32_UART_A_FIFOCN_RFIFOFL_SHIFT)

#define SI32_UART_A_FIFOCN_RFERI_MASK  0x00000200
#define SI32_UART_A_FIFOCN_RFERI_SHIFT  9
// A receive FIFO error has not occurred since RFERI was last cleared.
#define SI32_UART_A_FIFOCN_RFERI_NOT_SET_VALUE  0
#define SI32_UART_A_FIFOCN_RFERI_NOT_SET_U32 \
   (SI32_UART_A_FIFOCN_RFERI_NOT_SET_VALUE << SI32_UART_A_FIFOCN_RFERI_SHIFT)
// A receive FIFO error occurred.
#define SI32_UART_A_FIFOCN_RFERI_SET_VALUE  1
#define SI32_UART_A_FIFOCN_RFERI_SET_U32 \
   (SI32_UART_A_FIFOCN_RFERI_SET_VALUE << SI32_UART_A_FIFOCN_RFERI_SHIFT)

#define SI32_UART_A_FIFOCN_RSRFULLF_MASK  0x00000400
#define SI32_UART_A_FIFOCN_RSRFULLF_SHIFT  10
// The receive data shift register is not full.
#define SI32_UART_A_FIFOCN_RSRFULLF_NOT_SET_VALUE  0
#define SI32_UART_A_FIFOCN_RSRFULLF_NOT_SET_U32 \
   (SI32_UART_A_FIFOCN_RSRFULLF_NOT_SET_VALUE << SI32_UART_A_FIFOCN_RSRFULLF_SHIFT)
// The receive data shift register is full.
#define SI32_UART_A_FIFOCN_RSRFULLF_SET_VALUE  1
#define SI32_UART_A_FIFOCN_RSRFULLF_SET_U32 \
   (SI32_UART_A_FIFOCN_RSRFULLF_SET_VALUE << SI32_UART_A_FIFOCN_RSRFULLF_SHIFT)

#define SI32_UART_A_FIFOCN_TCNT_MASK  0x00070000
#define SI32_UART_A_FIFOCN_TCNT_SHIFT  16

#define SI32_UART_A_FIFOCN_TFTH_MASK  0x00300000
#define SI32_UART_A_FIFOCN_TFTH_SHIFT  20
// A transmit data request interrupt (TDREQI) is asserted when >= 1 FIFO slot is
// empty.
#define SI32_UART_A_FIFOCN_TFTH_ONE_VALUE  0
#define SI32_UART_A_FIFOCN_TFTH_ONE_U32 \
   (SI32_UART_A_FIFOCN_TFTH_ONE_VALUE << SI32_UART_A_FIFOCN_TFTH_SHIFT)
// A transmit data request interrupt (TDREQI) is asserted when >= 2 FIFO slots are
// empty.
#define SI32_UART_A_FIFOCN_TFTH_TWO_VALUE  1
#define SI32_UART_A_FIFOCN_TFTH_TWO_U32 \
   (SI32_UART_A_FIFOCN_TFTH_TWO_VALUE << SI32_UART_A_FIFOCN_TFTH_SHIFT)
// A transmit data request interrupt (TDREQI) is asserted when >= 4 FIFO slots are
// empty.
#define SI32_UART_A_FIFOCN_TFTH_FOUR_VALUE  2
#define SI32_UART_A_FIFOCN_TFTH_FOUR_U32 \
   (SI32_UART_A_FIFOCN_TFTH_FOUR_VALUE << SI32_UART_A_FIFOCN_TFTH_SHIFT)

#define SI32_UART_A_FIFOCN_TFIFOFL_MASK  0x01000000
#define SI32_UART_A_FIFOCN_TFIFOFL_SHIFT  24
// Flush the contents of the transmit FIFO. If data is pending in the transmit
// shift register but a transmit has not begun, the shift register is also flushed.
#define SI32_UART_A_FIFOCN_TFIFOFL_SET_VALUE  1
#define SI32_UART_A_FIFOCN_TFIFOFL_SET_U32 \
   (SI32_UART_A_FIFOCN_TFIFOFL_SET_VALUE << SI32_UART_A_FIFOCN_TFIFOFL_SHIFT)

#define SI32_UART_A_FIFOCN_TFERI_MASK  0x02000000
#define SI32_UART_A_FIFOCN_TFERI_SHIFT  25
// A transmit FIFO error has not occurred since TFERI was last cleared.
#define SI32_UART_A_FIFOCN_TFERI_NOT_SET_VALUE  0
#define SI32_UART_A_FIFOCN_TFERI_NOT_SET_U32 \
   (SI32_UART_A_FIFOCN_TFERI_NOT_SET_VALUE << SI32_UART_A_FIFOCN_TFERI_SHIFT)
// A transmit FIFO error occurred.
#define SI32_UART_A_FIFOCN_TFERI_SET_VALUE  1
#define SI32_UART_A_FIFOCN_TFERI_SET_U32 \
   (SI32_UART_A_FIFOCN_TFERI_SET_VALUE << SI32_UART_A_FIFOCN_TFERI_SHIFT)

#define SI32_UART_A_FIFOCN_TSRFULLF_MASK  0x04000000
#define SI32_UART_A_FIFOCN_TSRFULLF_SHIFT  26
// The transmit shift register is not full.
#define SI32_UART_A_FIFOCN_TSRFULLF_NOT_SET_VALUE  0
#define SI32_UART_A_FIFOCN_TSRFULLF_NOT_SET_U32 \
   (SI32_UART_A_FIFOCN_TSRFULLF_NOT_SET_VALUE << SI32_UART_A_FIFOCN_TSRFULLF_SHIFT)
// The transmit shift register is full.
#define SI32_UART_A_FIFOCN_TSRFULLF_SET_VALUE  1
#define SI32_UART_A_FIFOCN_TSRFULLF_SET_U32 \
   (SI32_UART_A_FIFOCN_TSRFULLF_SET_VALUE << SI32_UART_A_FIFOCN_TSRFULLF_SHIFT)



struct SI32_UART_A_DATA_Struct
{
   union
   {
      // This is a FIFO register
      volatile uint8_t  U8;
      volatile uint16_t U16;
      volatile uint32_t U32;
   };
};

#define SI32_UART_A_DATA_DATA_MASK  0xFFFFFFFF
#define SI32_UART_A_DATA_DATA_SHIFT  0



typedef struct SI32_UART_A_Struct
{
   struct SI32_UART_A_CONFIG_Struct                CONFIG         ; // Base Address + 0x0
   volatile uint32_t                               CONFIG_SET;
   volatile uint32_t                               CONFIG_CLR;
   uint32_t                                        reserved0;
   struct SI32_UART_A_MODE_Struct                  MODE           ; // Base Address + 0x10
   volatile uint32_t                               MODE_SET;
   volatile uint32_t                               MODE_CLR;
   uint32_t                                        reserved1;
   struct SI32_UART_A_FLOWCN_Struct                FLOWCN         ; // Base Address + 0x20
   volatile uint32_t                               FLOWCN_SET;
   volatile uint32_t                               FLOWCN_CLR;
   uint32_t                                        reserved2;
   struct SI32_UART_A_CONTROL_Struct               CONTROL        ; // Base Address + 0x30
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved3;
   struct SI32_UART_A_IPDELAY_Struct               IPDELAY        ; // Base Address + 0x40
   uint32_t                                        reserved4;
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   struct SI32_UART_A_BAUDRATE_Struct              BAUDRATE       ; // Base Address + 0x50
   uint32_t                                        reserved7;
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   struct SI32_UART_A_FIFOCN_Struct                FIFOCN         ; // Base Address + 0x60
   volatile uint32_t                               FIFOCN_SET;
   volatile uint32_t                               FIFOCN_CLR;
   uint32_t                                        reserved10;
   struct SI32_UART_A_DATA_Struct                  DATA           ; // Base Address + 0x70
   uint32_t                                        reserved11;
   uint32_t                                        reserved12;
   uint32_t                                        reserved13;
} SI32_UART_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_UART_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

