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

#ifndef __SI32_SPI_A_REGISTERS_H__
#define __SI32_SPI_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_SPI_A_DATA_Struct
{
   union
   {
      // This is a FIFO register
      volatile uint8_t  U8;
      volatile uint16_t U16;
      volatile uint32_t U32;
   };
};

#define SI32_SPI_A_DATA_DATA_MASK  0xFFFFFFFF
#define SI32_SPI_A_DATA_DATA_SHIFT  0



struct SI32_SPI_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Receive FIFO Read Request Interrupt Flag
         volatile uint32_t RFRQI: 1;
         // Receive FIFO Overrun Interrupt Flag
         volatile uint32_t RFORI: 1;
         // Transmit FIFO Write Request Interrupt Flag
         volatile uint32_t TFRQI: 1;
         // Transmit FIFO Overrun Interrupt Flag
         volatile uint32_t TFORI: 1;
         // Slave Selected Interrupt Flag
         volatile uint32_t SLVSELI: 1;
         // Mode Fault Interrupt Flag
         volatile uint32_t MDFI: 1;
         // Underrun Interrupt Flag
         volatile uint32_t URI: 1;
         // Shift Register Empty Interrupt Flag
         volatile uint32_t SREI: 1;
         // Illegal Receive FIFO Access Interrupt Flag
         volatile uint32_t RFILI: 1;
         // Illegal Transmit FIFO Access Interrupt Flag
         volatile uint32_t TFILI: 1;
                  uint32_t reserved0: 4;
         // NSS Instantaneous Pin Status
         volatile uint32_t NSSSTS: 1;
         // SPI Busy
         volatile uint32_t BUSYF: 1;
         // Receive FIFO Counter
         volatile uint32_t RFCNT: 4;
         // Transmit FIFO Counter
         volatile uint32_t TFCNT: 4;
         // SPI Debug Mode
         volatile uint32_t DBGMD: 1;
                  uint32_t reserved1: 7;
      };
      volatile uint32_t U32;
   };
};

#define SI32_SPI_A_CONTROL_RFRQI_MASK  0x00000001
#define SI32_SPI_A_CONTROL_RFRQI_SHIFT  0
// The RX FIFO has fewer bytes than the level defined by RFTH.
#define SI32_SPI_A_CONTROL_RFRQI_NOT_SET_VALUE  0
#define SI32_SPI_A_CONTROL_RFRQI_NOT_SET_U32 \
   (SI32_SPI_A_CONTROL_RFRQI_NOT_SET_VALUE << SI32_SPI_A_CONTROL_RFRQI_SHIFT)
// The RX FIFO has equal or more bytes than the level defined by RFTH.
#define SI32_SPI_A_CONTROL_RFRQI_SET_VALUE  1
#define SI32_SPI_A_CONTROL_RFRQI_SET_U32 \
   (SI32_SPI_A_CONTROL_RFRQI_SET_VALUE << SI32_SPI_A_CONTROL_RFRQI_SHIFT)

#define SI32_SPI_A_CONTROL_RFORI_MASK  0x00000002
#define SI32_SPI_A_CONTROL_RFORI_SHIFT  1
// Read: A receive FIFO overrun has not occurred. Write: Clear the flag.
#define SI32_SPI_A_CONTROL_RFORI_NOT_SET_VALUE  0
#define SI32_SPI_A_CONTROL_RFORI_NOT_SET_U32 \
   (SI32_SPI_A_CONTROL_RFORI_NOT_SET_VALUE << SI32_SPI_A_CONTROL_RFORI_SHIFT)
// Read: A receive FIFO overrun  occurred. Write: Force a receive overrun
// interrupt.
#define SI32_SPI_A_CONTROL_RFORI_SET_VALUE  1
#define SI32_SPI_A_CONTROL_RFORI_SET_U32 \
   (SI32_SPI_A_CONTROL_RFORI_SET_VALUE << SI32_SPI_A_CONTROL_RFORI_SHIFT)

#define SI32_SPI_A_CONTROL_TFRQI_MASK  0x00000004
#define SI32_SPI_A_CONTROL_TFRQI_SHIFT  2
// The TX FIFO has fewer bytes than the level defined by TFTH.
#define SI32_SPI_A_CONTROL_TFRQI_NOT_SET_VALUE  0
#define SI32_SPI_A_CONTROL_TFRQI_NOT_SET_U32 \
   (SI32_SPI_A_CONTROL_TFRQI_NOT_SET_VALUE << SI32_SPI_A_CONTROL_TFRQI_SHIFT)
// The TX FIFO has equal or more bytes than the level defined by TFTH.
#define SI32_SPI_A_CONTROL_TFRQI_SET_VALUE  1
#define SI32_SPI_A_CONTROL_TFRQI_SET_U32 \
   (SI32_SPI_A_CONTROL_TFRQI_SET_VALUE << SI32_SPI_A_CONTROL_TFRQI_SHIFT)

#define SI32_SPI_A_CONTROL_TFORI_MASK  0x00000008
#define SI32_SPI_A_CONTROL_TFORI_SHIFT  3
// Read: A transmit FIFO overrun has not occurred. Write: Clear the flag.
#define SI32_SPI_A_CONTROL_TFORI_NOT_SET_VALUE  0
#define SI32_SPI_A_CONTROL_TFORI_NOT_SET_U32 \
   (SI32_SPI_A_CONTROL_TFORI_NOT_SET_VALUE << SI32_SPI_A_CONTROL_TFORI_SHIFT)
// Read: A transmit FIFO overrun  occurred. Write: Force a transmit overrun
// interrupt.
#define SI32_SPI_A_CONTROL_TFORI_SET_VALUE  1
#define SI32_SPI_A_CONTROL_TFORI_SET_U32 \
   (SI32_SPI_A_CONTROL_TFORI_SET_VALUE << SI32_SPI_A_CONTROL_TFORI_SHIFT)

#define SI32_SPI_A_CONTROL_SLVSELI_MASK  0x00000010
#define SI32_SPI_A_CONTROL_SLVSELI_SHIFT  4
// The slave select signal (NSS) is not active.
#define SI32_SPI_A_CONTROL_SLVSELI_NOT_SET_VALUE  0
#define SI32_SPI_A_CONTROL_SLVSELI_NOT_SET_U32 \
   (SI32_SPI_A_CONTROL_SLVSELI_NOT_SET_VALUE << SI32_SPI_A_CONTROL_SLVSELI_SHIFT)
// The slave select signal (NSS) is active.
#define SI32_SPI_A_CONTROL_SLVSELI_SET_VALUE  1
#define SI32_SPI_A_CONTROL_SLVSELI_SET_U32 \
   (SI32_SPI_A_CONTROL_SLVSELI_SET_VALUE << SI32_SPI_A_CONTROL_SLVSELI_SHIFT)

#define SI32_SPI_A_CONTROL_MDFI_MASK  0x00000020
#define SI32_SPI_A_CONTROL_MDFI_SHIFT  5
// Read: A master mode collision is not detected. Write: Clear the flag.
#define SI32_SPI_A_CONTROL_MDFI_NOT_SET_VALUE  0
#define SI32_SPI_A_CONTROL_MDFI_NOT_SET_U32 \
   (SI32_SPI_A_CONTROL_MDFI_NOT_SET_VALUE << SI32_SPI_A_CONTROL_MDFI_SHIFT)
// Read: A master mode collision occurred. Write: Force a mode fault interrupt.
#define SI32_SPI_A_CONTROL_MDFI_SET_VALUE  1
#define SI32_SPI_A_CONTROL_MDFI_SET_U32 \
   (SI32_SPI_A_CONTROL_MDFI_SET_VALUE << SI32_SPI_A_CONTROL_MDFI_SHIFT)

#define SI32_SPI_A_CONTROL_URI_MASK  0x00000040
#define SI32_SPI_A_CONTROL_URI_SHIFT  6
// Read: A data transfer is still in progress. Write: Clear the flag.
#define SI32_SPI_A_CONTROL_URI_NOT_SET_VALUE  0
#define SI32_SPI_A_CONTROL_URI_NOT_SET_U32 \
   (SI32_SPI_A_CONTROL_URI_NOT_SET_VALUE << SI32_SPI_A_CONTROL_URI_SHIFT)
// Read: The transmit FIFO and shift register are empty and the data transfer has
// ended. Write: Force an underrun interrupt.
#define SI32_SPI_A_CONTROL_URI_SET_VALUE  1
#define SI32_SPI_A_CONTROL_URI_SET_U32 \
   (SI32_SPI_A_CONTROL_URI_SET_VALUE << SI32_SPI_A_CONTROL_URI_SHIFT)

#define SI32_SPI_A_CONTROL_SREI_MASK  0x00000080
#define SI32_SPI_A_CONTROL_SREI_SHIFT  7
// There is data still present in the transmit FIFO.
#define SI32_SPI_A_CONTROL_SREI_NOT_SET_VALUE  0
#define SI32_SPI_A_CONTROL_SREI_NOT_SET_U32 \
   (SI32_SPI_A_CONTROL_SREI_NOT_SET_VALUE << SI32_SPI_A_CONTROL_SREI_SHIFT)
// All data has been transferred out of the shift register and there is no data
// waiting in the transmit FIFO.
#define SI32_SPI_A_CONTROL_SREI_SET_VALUE  1
#define SI32_SPI_A_CONTROL_SREI_SET_U32 \
   (SI32_SPI_A_CONTROL_SREI_SET_VALUE << SI32_SPI_A_CONTROL_SREI_SHIFT)

#define SI32_SPI_A_CONTROL_RFILI_MASK  0x00000100
#define SI32_SPI_A_CONTROL_RFILI_SHIFT  8
// Read: An illegal write or read of the receive FIFO has not occurred. Write:
// Clear the flag.
#define SI32_SPI_A_CONTROL_RFILI_NOT_SET_VALUE  0
#define SI32_SPI_A_CONTROL_RFILI_NOT_SET_U32 \
   (SI32_SPI_A_CONTROL_RFILI_NOT_SET_VALUE << SI32_SPI_A_CONTROL_RFILI_SHIFT)
// Read: An illegal write or read of the receive FIFO occurred. Write: Force an
// illegal receive access interrupt.
#define SI32_SPI_A_CONTROL_RFILI_SET_VALUE  1
#define SI32_SPI_A_CONTROL_RFILI_SET_U32 \
   (SI32_SPI_A_CONTROL_RFILI_SET_VALUE << SI32_SPI_A_CONTROL_RFILI_SHIFT)

#define SI32_SPI_A_CONTROL_TFILI_MASK  0x00000200
#define SI32_SPI_A_CONTROL_TFILI_SHIFT  9
// Read: An illegal write or read of the transmit FIFO has not occurred. Write:
// Clear the flag.
#define SI32_SPI_A_CONTROL_TFILI_NOT_SET_VALUE  0
#define SI32_SPI_A_CONTROL_TFILI_NOT_SET_U32 \
   (SI32_SPI_A_CONTROL_TFILI_NOT_SET_VALUE << SI32_SPI_A_CONTROL_TFILI_SHIFT)
// Read: An illegal write or read of the transmit FIFO occurred. Write: Force an
// illegal transmit access interrupt.
#define SI32_SPI_A_CONTROL_TFILI_SET_VALUE  1
#define SI32_SPI_A_CONTROL_TFILI_SET_U32 \
   (SI32_SPI_A_CONTROL_TFILI_SET_VALUE << SI32_SPI_A_CONTROL_TFILI_SHIFT)

#define SI32_SPI_A_CONTROL_NSSSTS_MASK  0x00004000
#define SI32_SPI_A_CONTROL_NSSSTS_SHIFT  14
// NSS is currently a logic low.
#define SI32_SPI_A_CONTROL_NSSSTS_LOW_VALUE  0
#define SI32_SPI_A_CONTROL_NSSSTS_LOW_U32 \
   (SI32_SPI_A_CONTROL_NSSSTS_LOW_VALUE << SI32_SPI_A_CONTROL_NSSSTS_SHIFT)
// NSS is currently a logic high.
#define SI32_SPI_A_CONTROL_NSSSTS_HIGH_VALUE  1
#define SI32_SPI_A_CONTROL_NSSSTS_HIGH_U32 \
   (SI32_SPI_A_CONTROL_NSSSTS_HIGH_VALUE << SI32_SPI_A_CONTROL_NSSSTS_SHIFT)

#define SI32_SPI_A_CONTROL_BUSYF_MASK  0x00008000
#define SI32_SPI_A_CONTROL_BUSYF_SHIFT  15
// The SPI is not busy and a transfer is not in progress.
#define SI32_SPI_A_CONTROL_BUSYF_NOT_SET_VALUE  0
#define SI32_SPI_A_CONTROL_BUSYF_NOT_SET_U32 \
   (SI32_SPI_A_CONTROL_BUSYF_NOT_SET_VALUE << SI32_SPI_A_CONTROL_BUSYF_SHIFT)
// The SPI is currently busy and a transfer is in progress.
#define SI32_SPI_A_CONTROL_BUSYF_SET_VALUE  1
#define SI32_SPI_A_CONTROL_BUSYF_SET_U32 \
   (SI32_SPI_A_CONTROL_BUSYF_SET_VALUE << SI32_SPI_A_CONTROL_BUSYF_SHIFT)

#define SI32_SPI_A_CONTROL_RFCNT_MASK  0x000F0000
#define SI32_SPI_A_CONTROL_RFCNT_SHIFT  16

#define SI32_SPI_A_CONTROL_TFCNT_MASK  0x00F00000
#define SI32_SPI_A_CONTROL_TFCNT_SHIFT  20

#define SI32_SPI_A_CONTROL_DBGMD_MASK  0x01000000
#define SI32_SPI_A_CONTROL_DBGMD_SHIFT  24
// The SPI module will continue to operate while the core is halted in debug mode.
#define SI32_SPI_A_CONTROL_DBGMD_RUN_VALUE  0
#define SI32_SPI_A_CONTROL_DBGMD_RUN_U32 \
   (SI32_SPI_A_CONTROL_DBGMD_RUN_VALUE << SI32_SPI_A_CONTROL_DBGMD_SHIFT)
// A debug breakpoint will cause the SPI module to halt.
#define SI32_SPI_A_CONTROL_DBGMD_HALT_VALUE  1
#define SI32_SPI_A_CONTROL_DBGMD_HALT_U32 \
   (SI32_SPI_A_CONTROL_DBGMD_HALT_VALUE << SI32_SPI_A_CONTROL_DBGMD_SHIFT)



struct SI32_SPI_A_CONFIG_Struct
{
   union
   {
      struct
      {
         // Receive FIFO Read Request Interrupt Enable
         volatile uint32_t RFRQIEN: 1;
         // Receive FIFO Overrun Interrupt Enable
         volatile uint32_t RFORIEN: 1;
         // Transmit FIFO Write Request Interrupt Enable
         volatile uint32_t TFRQIEN: 1;
         // Transmit FIFO Overrun Interrupt Enable
         volatile uint32_t TFORIEN: 1;
         // Slave Selected Interrupt Enable
         volatile uint32_t SLVSELIEN: 1;
         // Mode Fault Interrupt Enable
         volatile uint32_t MDFIEN: 1;
         // Underrun Interrupt Enable
         volatile uint32_t URIEN: 1;
         // Shift Register Empty Interrupt Enable
         volatile uint32_t SREIEN: 1;
         // SPI Enable
         volatile uint32_t SPIEN: 1;
         // Master Mode Enable
         volatile uint32_t MSTEN: 1;
         // SPI Clock Polarity
         volatile uint32_t CLKPOL: 1;
         // SPI Clock Phase
         volatile uint32_t CLKPHA: 1;
         // Slave Select Polarity Select
         volatile uint32_t NSSPOL: 1;
         // Data Direction Select
         volatile uint32_t DDIRSEL: 1;
         // Slave Select Mode
         volatile uint32_t NSSMD: 2;
         // Receive FIFO Threshold
         volatile uint32_t RFTH: 2;
         // Transmit FIFO Threshold
         volatile uint32_t TFTH: 2;
         // Data Size
         volatile uint32_t DSIZE: 4;
         // DMA Enable
         volatile uint32_t DMAEN: 1;
                  uint32_t reserved0: 4;
         // Receive FIFO Flush
         volatile uint32_t RFIFOFL: 1;
         // Transmit FIFO Flush
         volatile uint32_t TFIFOFL: 1;
         // Module Soft Reset
         volatile uint32_t RESET: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_SPI_A_CONFIG_RFRQIEN_MASK  0x00000001
#define SI32_SPI_A_CONFIG_RFRQIEN_SHIFT  0
// Disable the receive FIFO request interrupt.
#define SI32_SPI_A_CONFIG_RFRQIEN_DISABLED_VALUE  0
#define SI32_SPI_A_CONFIG_RFRQIEN_DISABLED_U32 \
   (SI32_SPI_A_CONFIG_RFRQIEN_DISABLED_VALUE << SI32_SPI_A_CONFIG_RFRQIEN_SHIFT)
// Enable the receive FIFO request interrupt.
#define SI32_SPI_A_CONFIG_RFRQIEN_ENABLED_VALUE  1
#define SI32_SPI_A_CONFIG_RFRQIEN_ENABLED_U32 \
   (SI32_SPI_A_CONFIG_RFRQIEN_ENABLED_VALUE << SI32_SPI_A_CONFIG_RFRQIEN_SHIFT)

#define SI32_SPI_A_CONFIG_RFORIEN_MASK  0x00000002
#define SI32_SPI_A_CONFIG_RFORIEN_SHIFT  1
// Disable the receive FIFO overrun interrupt.
#define SI32_SPI_A_CONFIG_RFORIEN_DISABLED_VALUE  0
#define SI32_SPI_A_CONFIG_RFORIEN_DISABLED_U32 \
   (SI32_SPI_A_CONFIG_RFORIEN_DISABLED_VALUE << SI32_SPI_A_CONFIG_RFORIEN_SHIFT)
// Enable the receive FIFO overrun interrupt.
#define SI32_SPI_A_CONFIG_RFORIEN_ENABLED_VALUE  1
#define SI32_SPI_A_CONFIG_RFORIEN_ENABLED_U32 \
   (SI32_SPI_A_CONFIG_RFORIEN_ENABLED_VALUE << SI32_SPI_A_CONFIG_RFORIEN_SHIFT)

#define SI32_SPI_A_CONFIG_TFRQIEN_MASK  0x00000004
#define SI32_SPI_A_CONFIG_TFRQIEN_SHIFT  2
// Disable the transmit FIFO data request interrupt.
#define SI32_SPI_A_CONFIG_TFRQIEN_DISABLED_VALUE  0
#define SI32_SPI_A_CONFIG_TFRQIEN_DISABLED_U32 \
   (SI32_SPI_A_CONFIG_TFRQIEN_DISABLED_VALUE << SI32_SPI_A_CONFIG_TFRQIEN_SHIFT)
// Enable the transmit FIFO data request interrupt.
#define SI32_SPI_A_CONFIG_TFRQIEN_ENABLED_VALUE  1
#define SI32_SPI_A_CONFIG_TFRQIEN_ENABLED_U32 \
   (SI32_SPI_A_CONFIG_TFRQIEN_ENABLED_VALUE << SI32_SPI_A_CONFIG_TFRQIEN_SHIFT)

#define SI32_SPI_A_CONFIG_TFORIEN_MASK  0x00000008
#define SI32_SPI_A_CONFIG_TFORIEN_SHIFT  3
// Disable the transmit FIFO overrun interrupt.
#define SI32_SPI_A_CONFIG_TFORIEN_DISABLED_VALUE  0
#define SI32_SPI_A_CONFIG_TFORIEN_DISABLED_U32 \
   (SI32_SPI_A_CONFIG_TFORIEN_DISABLED_VALUE << SI32_SPI_A_CONFIG_TFORIEN_SHIFT)
// Enable the transmit FIFO overrun interrupt.
#define SI32_SPI_A_CONFIG_TFORIEN_ENABLED_VALUE  1
#define SI32_SPI_A_CONFIG_TFORIEN_ENABLED_U32 \
   (SI32_SPI_A_CONFIG_TFORIEN_ENABLED_VALUE << SI32_SPI_A_CONFIG_TFORIEN_SHIFT)

#define SI32_SPI_A_CONFIG_SLVSELIEN_MASK  0x00000010
#define SI32_SPI_A_CONFIG_SLVSELIEN_SHIFT  4
// Disable the slave select interrupt.
#define SI32_SPI_A_CONFIG_SLVSELIEN_DISABLED_VALUE  0
#define SI32_SPI_A_CONFIG_SLVSELIEN_DISABLED_U32 \
   (SI32_SPI_A_CONFIG_SLVSELIEN_DISABLED_VALUE << SI32_SPI_A_CONFIG_SLVSELIEN_SHIFT)
// Enable the slave select interrupt.
#define SI32_SPI_A_CONFIG_SLVSELIEN_ENABLED_VALUE  1
#define SI32_SPI_A_CONFIG_SLVSELIEN_ENABLED_U32 \
   (SI32_SPI_A_CONFIG_SLVSELIEN_ENABLED_VALUE << SI32_SPI_A_CONFIG_SLVSELIEN_SHIFT)

#define SI32_SPI_A_CONFIG_MDFIEN_MASK  0x00000020
#define SI32_SPI_A_CONFIG_MDFIEN_SHIFT  5
// Disable the mode fault interrupt.
#define SI32_SPI_A_CONFIG_MDFIEN_DISABLED_VALUE  0
#define SI32_SPI_A_CONFIG_MDFIEN_DISABLED_U32 \
   (SI32_SPI_A_CONFIG_MDFIEN_DISABLED_VALUE << SI32_SPI_A_CONFIG_MDFIEN_SHIFT)
// Enable the mode fault interrupt.
#define SI32_SPI_A_CONFIG_MDFIEN_ENABLED_VALUE  1
#define SI32_SPI_A_CONFIG_MDFIEN_ENABLED_U32 \
   (SI32_SPI_A_CONFIG_MDFIEN_ENABLED_VALUE << SI32_SPI_A_CONFIG_MDFIEN_SHIFT)

#define SI32_SPI_A_CONFIG_URIEN_MASK  0x00000040
#define SI32_SPI_A_CONFIG_URIEN_SHIFT  6
// Disable the underrun interrupt.
#define SI32_SPI_A_CONFIG_URIEN_DISABLED_VALUE  0
#define SI32_SPI_A_CONFIG_URIEN_DISABLED_U32 \
   (SI32_SPI_A_CONFIG_URIEN_DISABLED_VALUE << SI32_SPI_A_CONFIG_URIEN_SHIFT)
// Enable the underrun interrupt.
#define SI32_SPI_A_CONFIG_URIEN_ENABLED_VALUE  1
#define SI32_SPI_A_CONFIG_URIEN_ENABLED_U32 \
   (SI32_SPI_A_CONFIG_URIEN_ENABLED_VALUE << SI32_SPI_A_CONFIG_URIEN_SHIFT)

#define SI32_SPI_A_CONFIG_SREIEN_MASK  0x00000080
#define SI32_SPI_A_CONFIG_SREIEN_SHIFT  7
// Disable the shift register empty interrupt.
#define SI32_SPI_A_CONFIG_SREIEN_DISABLED_VALUE  0
#define SI32_SPI_A_CONFIG_SREIEN_DISABLED_U32 \
   (SI32_SPI_A_CONFIG_SREIEN_DISABLED_VALUE << SI32_SPI_A_CONFIG_SREIEN_SHIFT)
// Enable the shift register empty interrupt.
#define SI32_SPI_A_CONFIG_SREIEN_ENABLED_VALUE  1
#define SI32_SPI_A_CONFIG_SREIEN_ENABLED_U32 \
   (SI32_SPI_A_CONFIG_SREIEN_ENABLED_VALUE << SI32_SPI_A_CONFIG_SREIEN_SHIFT)

#define SI32_SPI_A_CONFIG_SPIEN_MASK  0x00000100
#define SI32_SPI_A_CONFIG_SPIEN_SHIFT  8
// Disable the SPI.
#define SI32_SPI_A_CONFIG_SPIEN_DISABLED_VALUE  0
#define SI32_SPI_A_CONFIG_SPIEN_DISABLED_U32 \
   (SI32_SPI_A_CONFIG_SPIEN_DISABLED_VALUE << SI32_SPI_A_CONFIG_SPIEN_SHIFT)
// Enable the SPI.
#define SI32_SPI_A_CONFIG_SPIEN_ENABLED_VALUE  1
#define SI32_SPI_A_CONFIG_SPIEN_ENABLED_U32 \
   (SI32_SPI_A_CONFIG_SPIEN_ENABLED_VALUE << SI32_SPI_A_CONFIG_SPIEN_SHIFT)

#define SI32_SPI_A_CONFIG_MSTEN_MASK  0x00000200
#define SI32_SPI_A_CONFIG_MSTEN_SHIFT  9
// Operate in slave mode.
#define SI32_SPI_A_CONFIG_MSTEN_DISABLED_VALUE  0
#define SI32_SPI_A_CONFIG_MSTEN_DISABLED_U32 \
   (SI32_SPI_A_CONFIG_MSTEN_DISABLED_VALUE << SI32_SPI_A_CONFIG_MSTEN_SHIFT)
// Operate in master mode.
#define SI32_SPI_A_CONFIG_MSTEN_ENABLED_VALUE  1
#define SI32_SPI_A_CONFIG_MSTEN_ENABLED_U32 \
   (SI32_SPI_A_CONFIG_MSTEN_ENABLED_VALUE << SI32_SPI_A_CONFIG_MSTEN_SHIFT)

#define SI32_SPI_A_CONFIG_CLKPOL_MASK  0x00000400
#define SI32_SPI_A_CONFIG_CLKPOL_SHIFT  10
// The SCK line is low in the idle state.
#define SI32_SPI_A_CONFIG_CLKPOL_LOW_VALUE  0
#define SI32_SPI_A_CONFIG_CLKPOL_LOW_U32 \
   (SI32_SPI_A_CONFIG_CLKPOL_LOW_VALUE << SI32_SPI_A_CONFIG_CLKPOL_SHIFT)
// The SCK line is high in the idle state.
#define SI32_SPI_A_CONFIG_CLKPOL_HIGH_VALUE  1
#define SI32_SPI_A_CONFIG_CLKPOL_HIGH_U32 \
   (SI32_SPI_A_CONFIG_CLKPOL_HIGH_VALUE << SI32_SPI_A_CONFIG_CLKPOL_SHIFT)

#define SI32_SPI_A_CONFIG_CLKPHA_MASK  0x00000800
#define SI32_SPI_A_CONFIG_CLKPHA_SHIFT  11
// The first edge of SCK is the sample edge (center of data bit).
#define SI32_SPI_A_CONFIG_CLKPHA_CENTER_VALUE  0
#define SI32_SPI_A_CONFIG_CLKPHA_CENTER_U32 \
   (SI32_SPI_A_CONFIG_CLKPHA_CENTER_VALUE << SI32_SPI_A_CONFIG_CLKPHA_SHIFT)
// The first edge of SCK is the shift edge (edge of data bit).
#define SI32_SPI_A_CONFIG_CLKPHA_EDGE_VALUE  1
#define SI32_SPI_A_CONFIG_CLKPHA_EDGE_U32 \
   (SI32_SPI_A_CONFIG_CLKPHA_EDGE_VALUE << SI32_SPI_A_CONFIG_CLKPHA_SHIFT)

#define SI32_SPI_A_CONFIG_NSSPOL_MASK  0x00001000
#define SI32_SPI_A_CONFIG_NSSPOL_SHIFT  12
// NSS is active low.
#define SI32_SPI_A_CONFIG_NSSPOL_LOW_VALUE  0
#define SI32_SPI_A_CONFIG_NSSPOL_LOW_U32 \
   (SI32_SPI_A_CONFIG_NSSPOL_LOW_VALUE << SI32_SPI_A_CONFIG_NSSPOL_SHIFT)
// NSS is active high.
#define SI32_SPI_A_CONFIG_NSSPOL_HIGH_VALUE  1
#define SI32_SPI_A_CONFIG_NSSPOL_HIGH_U32 \
   (SI32_SPI_A_CONFIG_NSSPOL_HIGH_VALUE << SI32_SPI_A_CONFIG_NSSPOL_SHIFT)

#define SI32_SPI_A_CONFIG_DDIRSEL_MASK  0x00002000
#define SI32_SPI_A_CONFIG_DDIRSEL_SHIFT  13
// Data will be shifted MSB first.
#define SI32_SPI_A_CONFIG_DDIRSEL_MSB_FIRST_VALUE  0
#define SI32_SPI_A_CONFIG_DDIRSEL_MSB_FIRST_U32 \
   (SI32_SPI_A_CONFIG_DDIRSEL_MSB_FIRST_VALUE << SI32_SPI_A_CONFIG_DDIRSEL_SHIFT)
// Data will be shifted LSB first.
#define SI32_SPI_A_CONFIG_DDIRSEL_LSB_FIRST_VALUE  1
#define SI32_SPI_A_CONFIG_DDIRSEL_LSB_FIRST_U32 \
   (SI32_SPI_A_CONFIG_DDIRSEL_LSB_FIRST_VALUE << SI32_SPI_A_CONFIG_DDIRSEL_SHIFT)

#define SI32_SPI_A_CONFIG_NSSMD_MASK  0x0000C000
#define SI32_SPI_A_CONFIG_NSSMD_SHIFT  14
// 3-wire Slave or 3-wire Master.
#define SI32_SPI_A_CONFIG_NSSMD_3_WIRE_MASTER_SLAVE_VALUE  0
#define SI32_SPI_A_CONFIG_NSSMD_3_WIRE_MASTER_SLAVE_U32 \
   (SI32_SPI_A_CONFIG_NSSMD_3_WIRE_MASTER_SLAVE_VALUE << SI32_SPI_A_CONFIG_NSSMD_SHIFT)
// 4-wire slave (NSS input).  This setting can also be used for multi-master
// configurations.
#define SI32_SPI_A_CONFIG_NSSMD_4_WIRE_SLAVE_VALUE  1
#define SI32_SPI_A_CONFIG_NSSMD_4_WIRE_SLAVE_U32 \
   (SI32_SPI_A_CONFIG_NSSMD_4_WIRE_SLAVE_VALUE << SI32_SPI_A_CONFIG_NSSMD_SHIFT)
// 4-wire master with NSS low (NSS output).
#define SI32_SPI_A_CONFIG_NSSMD_4_WIRE_MASTER_NSS_LOW_VALUE  2
#define SI32_SPI_A_CONFIG_NSSMD_4_WIRE_MASTER_NSS_LOW_U32 \
   (SI32_SPI_A_CONFIG_NSSMD_4_WIRE_MASTER_NSS_LOW_VALUE << SI32_SPI_A_CONFIG_NSSMD_SHIFT)
// 4-wire master with NSS high (NSS output).
#define SI32_SPI_A_CONFIG_NSSMD_4_WIRE_MASTER_NSS_HIGH_VALUE  3
#define SI32_SPI_A_CONFIG_NSSMD_4_WIRE_MASTER_NSS_HIGH_U32 \
   (SI32_SPI_A_CONFIG_NSSMD_4_WIRE_MASTER_NSS_HIGH_VALUE << SI32_SPI_A_CONFIG_NSSMD_SHIFT)

#define SI32_SPI_A_CONFIG_RFTH_MASK  0x00030000
#define SI32_SPI_A_CONFIG_RFTH_SHIFT  16
// A DMA / RFRQ request asserts when >= 1 FIFO slot is filled.
#define SI32_SPI_A_CONFIG_RFTH_ONE_VALUE  0
#define SI32_SPI_A_CONFIG_RFTH_ONE_U32 \
   (SI32_SPI_A_CONFIG_RFTH_ONE_VALUE << SI32_SPI_A_CONFIG_RFTH_SHIFT)
// A DMA / RFRQ request asserts when >= 2 FIFO slots are filled.
#define SI32_SPI_A_CONFIG_RFTH_TWO_VALUE  1
#define SI32_SPI_A_CONFIG_RFTH_TWO_U32 \
   (SI32_SPI_A_CONFIG_RFTH_TWO_VALUE << SI32_SPI_A_CONFIG_RFTH_SHIFT)
// A DMA / RFRQ request asserts when >= 4 FIFO slots are filled.
#define SI32_SPI_A_CONFIG_RFTH_FOUR_VALUE  2
#define SI32_SPI_A_CONFIG_RFTH_FOUR_U32 \
   (SI32_SPI_A_CONFIG_RFTH_FOUR_VALUE << SI32_SPI_A_CONFIG_RFTH_SHIFT)
// A DMA / RFRQ request asserts when all FIFO slots are filled.
#define SI32_SPI_A_CONFIG_RFTH_FULL_VALUE  3
#define SI32_SPI_A_CONFIG_RFTH_FULL_U32 \
   (SI32_SPI_A_CONFIG_RFTH_FULL_VALUE << SI32_SPI_A_CONFIG_RFTH_SHIFT)

#define SI32_SPI_A_CONFIG_TFTH_MASK  0x000C0000
#define SI32_SPI_A_CONFIG_TFTH_SHIFT  18
// A DMA / TFRQ request asserts when >= 1 FIFO slot is empty.
#define SI32_SPI_A_CONFIG_TFTH_ONE_VALUE  0
#define SI32_SPI_A_CONFIG_TFTH_ONE_U32 \
   (SI32_SPI_A_CONFIG_TFTH_ONE_VALUE << SI32_SPI_A_CONFIG_TFTH_SHIFT)
// A DMA / TFRQ request asserts when >= 2 FIFO slots are empty.
#define SI32_SPI_A_CONFIG_TFTH_TWO_VALUE  1
#define SI32_SPI_A_CONFIG_TFTH_TWO_U32 \
   (SI32_SPI_A_CONFIG_TFTH_TWO_VALUE << SI32_SPI_A_CONFIG_TFTH_SHIFT)
// A DMA / TFRQ request asserts when >= 4 FIFO slots are empty.
#define SI32_SPI_A_CONFIG_TFTH_FOUR_VALUE  2
#define SI32_SPI_A_CONFIG_TFTH_FOUR_U32 \
   (SI32_SPI_A_CONFIG_TFTH_FOUR_VALUE << SI32_SPI_A_CONFIG_TFTH_SHIFT)
// A DMA / TFRQ request asserts when all FIFO slots are empty.
#define SI32_SPI_A_CONFIG_TFTH_EMPTY_VALUE  3
#define SI32_SPI_A_CONFIG_TFTH_EMPTY_U32 \
   (SI32_SPI_A_CONFIG_TFTH_EMPTY_VALUE << SI32_SPI_A_CONFIG_TFTH_SHIFT)

#define SI32_SPI_A_CONFIG_DSIZE_MASK  0x00F00000
#define SI32_SPI_A_CONFIG_DSIZE_SHIFT  20

#define SI32_SPI_A_CONFIG_DMAEN_MASK  0x01000000
#define SI32_SPI_A_CONFIG_DMAEN_SHIFT  24
// Disable DMA requests.
#define SI32_SPI_A_CONFIG_DMAEN_DISABLED_VALUE  0
#define SI32_SPI_A_CONFIG_DMAEN_DISABLED_U32 \
   (SI32_SPI_A_CONFIG_DMAEN_DISABLED_VALUE << SI32_SPI_A_CONFIG_DMAEN_SHIFT)
// Enable DMA requests when the transmit buffer is empty or the receive buffer is
// full.
#define SI32_SPI_A_CONFIG_DMAEN_ENABLED_VALUE  1
#define SI32_SPI_A_CONFIG_DMAEN_ENABLED_U32 \
   (SI32_SPI_A_CONFIG_DMAEN_ENABLED_VALUE << SI32_SPI_A_CONFIG_DMAEN_SHIFT)

#define SI32_SPI_A_CONFIG_RFIFOFL_MASK  0x20000000
#define SI32_SPI_A_CONFIG_RFIFOFL_SHIFT  29
// Flush the receive FIFO.
#define SI32_SPI_A_CONFIG_RFIFOFL_SET_VALUE  1
#define SI32_SPI_A_CONFIG_RFIFOFL_SET_U32 \
   (SI32_SPI_A_CONFIG_RFIFOFL_SET_VALUE << SI32_SPI_A_CONFIG_RFIFOFL_SHIFT)

#define SI32_SPI_A_CONFIG_TFIFOFL_MASK  0x40000000
#define SI32_SPI_A_CONFIG_TFIFOFL_SHIFT  30
// Flush the transmit FIFO.
#define SI32_SPI_A_CONFIG_TFIFOFL_SET_VALUE  1
#define SI32_SPI_A_CONFIG_TFIFOFL_SET_U32 \
   (SI32_SPI_A_CONFIG_TFIFOFL_SET_VALUE << SI32_SPI_A_CONFIG_TFIFOFL_SHIFT)

#define SI32_SPI_A_CONFIG_RESET_MASK  0x80000000
#define SI32_SPI_A_CONFIG_RESET_SHIFT  31
// SPI module is not in soft reset.
#define SI32_SPI_A_CONFIG_RESET_INACTIVE_VALUE  0U
#define SI32_SPI_A_CONFIG_RESET_INACTIVE_U32 \
   (SI32_SPI_A_CONFIG_RESET_INACTIVE_VALUE << SI32_SPI_A_CONFIG_RESET_SHIFT)
// SPI module is in soft reset and some of the module bits cannot be accessed until
// this bit is cleared to 0 by hardware.
#define SI32_SPI_A_CONFIG_RESET_ACTIVE_VALUE  1U
#define SI32_SPI_A_CONFIG_RESET_ACTIVE_U32 \
   (SI32_SPI_A_CONFIG_RESET_ACTIVE_VALUE << SI32_SPI_A_CONFIG_RESET_SHIFT)



struct SI32_SPI_A_CLKRATE_Struct
{
   union
   {
      struct
      {
         // Clock Divider
         volatile uint16_t CLKDIV;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_SPI_A_CLKRATE_CLKDIV_MASK  0x0000FFFF
#define SI32_SPI_A_CLKRATE_CLKDIV_SHIFT  0



struct SI32_SPI_A_FSTATUS_Struct
{
   union
   {
      struct
      {
         // Receive FIFO Read Pointer
         volatile uint32_t RFRPTR: 4;
         // Receive FIFO Write Pointer
         volatile uint32_t RFWPTR: 4;
         // Transmit FIFO Read Pointer
         volatile uint32_t TFRPTR: 4;
         // Transmit FIFO Write Pointer
         volatile uint32_t TFWPTR: 4;
                  uint32_t reserved0: 16;
      };
      volatile uint32_t U32;
   };
};

#define SI32_SPI_A_FSTATUS_RFRPTR_MASK  0x0000000F
#define SI32_SPI_A_FSTATUS_RFRPTR_SHIFT  0

#define SI32_SPI_A_FSTATUS_RFWPTR_MASK  0x000000F0
#define SI32_SPI_A_FSTATUS_RFWPTR_SHIFT  4

#define SI32_SPI_A_FSTATUS_TFRPTR_MASK  0x00000F00
#define SI32_SPI_A_FSTATUS_TFRPTR_SHIFT  8

#define SI32_SPI_A_FSTATUS_TFWPTR_MASK  0x0000F000
#define SI32_SPI_A_FSTATUS_TFWPTR_SHIFT  12



typedef struct SI32_SPI_A_Struct
{
   struct SI32_SPI_A_DATA_Struct                   DATA           ; // Base Address + 0x0
   uint32_t                                        reserved0;
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   struct SI32_SPI_A_CONTROL_Struct                CONTROL        ; // Base Address + 0x10
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved3;
   struct SI32_SPI_A_CONFIG_Struct                 CONFIG         ; // Base Address + 0x20
   volatile uint32_t                               CONFIG_SET;
   volatile uint32_t                               CONFIG_CLR;
   uint32_t                                        reserved4;
   struct SI32_SPI_A_CLKRATE_Struct                CLKRATE        ; // Base Address + 0x30
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   uint32_t                                        reserved7;
   struct SI32_SPI_A_FSTATUS_Struct                FSTATUS        ; // Base Address + 0x40
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   uint32_t                                        reserved10;
} SI32_SPI_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_SPI_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

