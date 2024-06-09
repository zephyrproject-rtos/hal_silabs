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

#ifndef __SI32_I2C_A_REGISTERS_H__
#define __SI32_I2C_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_I2C_A_CONTROL_Struct
{
   union
   {
      struct
      {
         // Busy Flag
         volatile uint32_t BUSYF: 1;
         // Acknowledge
         volatile uint32_t ACK: 1;
         // Arbitration Lost Flag
         volatile uint32_t ARBLF: 1;
         // Acknowledge Request Flag
         volatile uint32_t ACKRQF: 1;
         // Stop
         volatile uint32_t STO: 1;
         // Start
         volatile uint32_t STA: 1;
         // Transmit Mode Flag
         volatile uint32_t TXMDF: 1;
         // Master/Slave Mode Flag
         volatile uint32_t MSMDF: 1;
         // Stop Interrupt Flag
         volatile uint32_t STOI: 1;
         // Acknowledge Interrupt Flag
         volatile uint32_t ACKI: 1;
         // Receive Done Interrupt Flag
         volatile uint32_t RXI: 1;
         // Transmit Done Interrupt Flag
         volatile uint32_t TXI: 1;
         // Start Interrupt Flag
         volatile uint32_t STAI: 1;
         // Arbitration Lost Interrupt Flag
         volatile uint32_t ARBLI: 1;
         // I2C Timer Byte 0 Interrupt Flag
         volatile uint32_t T0I: 1;
         // I2C Timer Byte 1 Interrupt Flag
         volatile uint32_t T1I: 1;
         // I2C Timer Byte 2 Interrupt Flag
         volatile uint32_t T2I: 1;
         // I2C Timer Byte 3 Interrupt Flag
         volatile uint32_t T3I: 1;
         // Receive Arm
         volatile uint32_t RXARM: 1;
         // Transmit Arm
         volatile uint32_t TXARM: 1;
         // Slave Address Type Flag
         volatile uint32_t SLVAF: 1;
         // Auto Transmit or Receive Enable
         volatile uint32_t ATXRXEN: 1;
         // Filter Mode
         volatile uint32_t FMD: 1;
         // I2C Debug Mode
         volatile uint32_t DBGMD: 1;
         // Slave Mode Inhibit
         volatile uint32_t SMINH: 1;
         // Auto Acknowledge Enable
         volatile uint32_t HACKEN: 1;
                  uint32_t reserved0: 1;
         // Last Byte Acknowledge Enable
         volatile uint32_t LBACKEN: 1;
                  uint32_t reserved1: 1;
         // General Call Address Enable
         volatile uint32_t GCEN: 1;
         // Module Soft Reset
         volatile uint32_t RESET: 1;
         // I2C Enable
         volatile uint32_t I2CEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2C_A_CONTROL_BUSYF_MASK  0x00000001
#define SI32_I2C_A_CONTROL_BUSYF_SHIFT  0
// A transaction is not currently taking place.
#define SI32_I2C_A_CONTROL_BUSYF_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_BUSYF_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_BUSYF_NOT_SET_VALUE << SI32_I2C_A_CONTROL_BUSYF_SHIFT)
// A transaction is currently taking place.
#define SI32_I2C_A_CONTROL_BUSYF_SET_VALUE  1
#define SI32_I2C_A_CONTROL_BUSYF_SET_U32 \
   (SI32_I2C_A_CONTROL_BUSYF_SET_VALUE << SI32_I2C_A_CONTROL_BUSYF_SHIFT)

#define SI32_I2C_A_CONTROL_ACK_MASK  0x00000002
#define SI32_I2C_A_CONTROL_ACK_SHIFT  1
// Read: ACK has not been received. Write: Do not send an ACK.
#define SI32_I2C_A_CONTROL_ACK_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_ACK_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_ACK_NOT_SET_VALUE << SI32_I2C_A_CONTROL_ACK_SHIFT)
// Read: ACK received. Write: Send an ACK.
#define SI32_I2C_A_CONTROL_ACK_SET_VALUE  1
#define SI32_I2C_A_CONTROL_ACK_SET_U32 \
   (SI32_I2C_A_CONTROL_ACK_SET_VALUE << SI32_I2C_A_CONTROL_ACK_SHIFT)

#define SI32_I2C_A_CONTROL_ARBLF_MASK  0x00000004
#define SI32_I2C_A_CONTROL_ARBLF_SHIFT  2
// Arbitration lost error has not occurred.
#define SI32_I2C_A_CONTROL_ARBLF_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_ARBLF_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_ARBLF_NOT_SET_VALUE << SI32_I2C_A_CONTROL_ARBLF_SHIFT)
// Arbitration lost error occurred.
#define SI32_I2C_A_CONTROL_ARBLF_SET_VALUE  1
#define SI32_I2C_A_CONTROL_ARBLF_SET_U32 \
   (SI32_I2C_A_CONTROL_ARBLF_SET_VALUE << SI32_I2C_A_CONTROL_ARBLF_SHIFT)

#define SI32_I2C_A_CONTROL_ACKRQF_MASK  0x00000008
#define SI32_I2C_A_CONTROL_ACKRQF_SHIFT  3
// ACK has not been requested.
#define SI32_I2C_A_CONTROL_ACKRQF_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_ACKRQF_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_ACKRQF_NOT_SET_VALUE << SI32_I2C_A_CONTROL_ACKRQF_SHIFT)
// ACK requested.
#define SI32_I2C_A_CONTROL_ACKRQF_SET_VALUE  1
#define SI32_I2C_A_CONTROL_ACKRQF_SET_U32 \
   (SI32_I2C_A_CONTROL_ACKRQF_SET_VALUE << SI32_I2C_A_CONTROL_ACKRQF_SHIFT)

#define SI32_I2C_A_CONTROL_STO_MASK  0x00000010
#define SI32_I2C_A_CONTROL_STO_SHIFT  4
// Read: A stop is not pending and a stop / repeat start has not been detected.
// Write: Clear the STO bit.
#define SI32_I2C_A_CONTROL_STO_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_STO_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_STO_NOT_SET_VALUE << SI32_I2C_A_CONTROL_STO_SHIFT)
// Read: Stop or stop / repeat start detected. This bit must be cleared by
// firmware. Write: Generate a stop.
#define SI32_I2C_A_CONTROL_STO_SET_VALUE  1
#define SI32_I2C_A_CONTROL_STO_SET_U32 \
   (SI32_I2C_A_CONTROL_STO_SET_VALUE << SI32_I2C_A_CONTROL_STO_SHIFT)

#define SI32_I2C_A_CONTROL_STA_MASK  0x00000020
#define SI32_I2C_A_CONTROL_STA_SHIFT  5
// Read: A start is not pending and a repeat start has not been detected. Write:
// Clear the STA bit.
#define SI32_I2C_A_CONTROL_STA_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_STA_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_STA_NOT_SET_VALUE << SI32_I2C_A_CONTROL_STA_SHIFT)
// Read: Start or repeat start detected. This bit must be cleared by firmware.
// Write: Generate a start or repeat start.
#define SI32_I2C_A_CONTROL_STA_SET_VALUE  1
#define SI32_I2C_A_CONTROL_STA_SET_U32 \
   (SI32_I2C_A_CONTROL_STA_SET_VALUE << SI32_I2C_A_CONTROL_STA_SHIFT)

#define SI32_I2C_A_CONTROL_TXMDF_MASK  0x00000040
#define SI32_I2C_A_CONTROL_TXMDF_SHIFT  6
// Module is in receiver mode.
#define SI32_I2C_A_CONTROL_TXMDF_RECEIVE_VALUE  0
#define SI32_I2C_A_CONTROL_TXMDF_RECEIVE_U32 \
   (SI32_I2C_A_CONTROL_TXMDF_RECEIVE_VALUE << SI32_I2C_A_CONTROL_TXMDF_SHIFT)
// Module is in transmitter mode.
#define SI32_I2C_A_CONTROL_TXMDF_TRANSMIT_VALUE  1
#define SI32_I2C_A_CONTROL_TXMDF_TRANSMIT_U32 \
   (SI32_I2C_A_CONTROL_TXMDF_TRANSMIT_VALUE << SI32_I2C_A_CONTROL_TXMDF_SHIFT)

#define SI32_I2C_A_CONTROL_MSMDF_MASK  0x00000080
#define SI32_I2C_A_CONTROL_MSMDF_SHIFT  7
// Module is operating in Slave mode.
#define SI32_I2C_A_CONTROL_MSMDF_SLAVE_VALUE  0
#define SI32_I2C_A_CONTROL_MSMDF_SLAVE_U32 \
   (SI32_I2C_A_CONTROL_MSMDF_SLAVE_VALUE << SI32_I2C_A_CONTROL_MSMDF_SHIFT)
// Module is operating in Master mode.
#define SI32_I2C_A_CONTROL_MSMDF_MASTER_VALUE  1
#define SI32_I2C_A_CONTROL_MSMDF_MASTER_U32 \
   (SI32_I2C_A_CONTROL_MSMDF_MASTER_VALUE << SI32_I2C_A_CONTROL_MSMDF_SHIFT)

#define SI32_I2C_A_CONTROL_STOI_MASK  0x00000100
#define SI32_I2C_A_CONTROL_STOI_SHIFT  8
// Read: A stop interrupt has not occurred. Write: Clear the stop interrupt flag
// (STOI).
#define SI32_I2C_A_CONTROL_STOI_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_STOI_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_STOI_NOT_SET_VALUE << SI32_I2C_A_CONTROL_STOI_SHIFT)
// Read: Stop interrupt detected. In Slave mode, a stop has been detected on the
// bus.  In Master mode, a stop has been generated. Write: Force a stop interrupt.
#define SI32_I2C_A_CONTROL_STOI_SET_VALUE  1
#define SI32_I2C_A_CONTROL_STOI_SET_U32 \
   (SI32_I2C_A_CONTROL_STOI_SET_VALUE << SI32_I2C_A_CONTROL_STOI_SHIFT)

#define SI32_I2C_A_CONTROL_ACKI_MASK  0x00000200
#define SI32_I2C_A_CONTROL_ACKI_SHIFT  9
// Read: An acknowledge interrupt has not occurred. Write: Clear the acknowledge
// interrupt (ACKI).
#define SI32_I2C_A_CONTROL_ACKI_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_ACKI_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_ACKI_NOT_SET_VALUE << SI32_I2C_A_CONTROL_ACKI_SHIFT)
// Read: An acknowledge interrupt occurred. Write: Force an acknowledge interrupt.
#define SI32_I2C_A_CONTROL_ACKI_SET_VALUE  1
#define SI32_I2C_A_CONTROL_ACKI_SET_U32 \
   (SI32_I2C_A_CONTROL_ACKI_SET_VALUE << SI32_I2C_A_CONTROL_ACKI_SHIFT)

#define SI32_I2C_A_CONTROL_RXI_MASK  0x00000400
#define SI32_I2C_A_CONTROL_RXI_SHIFT  10
// Read: A receive done interrupt has not occurred. Write: Clear the receive done
// interrupt (RXI).
#define SI32_I2C_A_CONTROL_RXI_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_RXI_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_RXI_NOT_SET_VALUE << SI32_I2C_A_CONTROL_RXI_SHIFT)
// Read: Receive done interrupt occurred. Write: Force a receive done interrupt.
#define SI32_I2C_A_CONTROL_RXI_SET_VALUE  1
#define SI32_I2C_A_CONTROL_RXI_SET_U32 \
   (SI32_I2C_A_CONTROL_RXI_SET_VALUE << SI32_I2C_A_CONTROL_RXI_SHIFT)

#define SI32_I2C_A_CONTROL_TXI_MASK  0x00000800
#define SI32_I2C_A_CONTROL_TXI_SHIFT  11
// Read: A transmit done interrupt has not occurred. Write: Clear the transmit done
// interrupt (TXI).
#define SI32_I2C_A_CONTROL_TXI_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_TXI_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_TXI_NOT_SET_VALUE << SI32_I2C_A_CONTROL_TXI_SHIFT)
// Read: Transmit done interrupt detected. If the transmit is forced to abort by a
// NACK response, the acknowledge interrupt (ACKI) will also be set. Write: Force a
// transmit done interrupt.
#define SI32_I2C_A_CONTROL_TXI_SET_VALUE  1
#define SI32_I2C_A_CONTROL_TXI_SET_U32 \
   (SI32_I2C_A_CONTROL_TXI_SET_VALUE << SI32_I2C_A_CONTROL_TXI_SHIFT)

#define SI32_I2C_A_CONTROL_STAI_MASK  0x00001000
#define SI32_I2C_A_CONTROL_STAI_SHIFT  12
// Read: Start interrupt has not occurred. Write: Clear the start interrupt (STAI).
#define SI32_I2C_A_CONTROL_STAI_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_STAI_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_STAI_NOT_SET_VALUE << SI32_I2C_A_CONTROL_STAI_SHIFT)
// Read: Start or repeat start interrupt occurred.  In Slave mode, a start or
// repeat start is detected.  In Master mode, a start or repeat start has been
// generated.
#define SI32_I2C_A_CONTROL_STAI_SET_VALUE  1
#define SI32_I2C_A_CONTROL_STAI_SET_U32 \
   (SI32_I2C_A_CONTROL_STAI_SET_VALUE << SI32_I2C_A_CONTROL_STAI_SHIFT)

#define SI32_I2C_A_CONTROL_ARBLI_MASK  0x00002000
#define SI32_I2C_A_CONTROL_ARBLI_SHIFT  13
// Read: An arbitration lost interrupt has not occurred. Write: Clear the
// arbitration lost interrupt (ARBLI).
#define SI32_I2C_A_CONTROL_ARBLI_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_ARBLI_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_ARBLI_NOT_SET_VALUE << SI32_I2C_A_CONTROL_ARBLI_SHIFT)
// Read: Arbitration lost interrupt detected. Write: Force an arbitration lost
// interrupt.
#define SI32_I2C_A_CONTROL_ARBLI_SET_VALUE  1
#define SI32_I2C_A_CONTROL_ARBLI_SET_U32 \
   (SI32_I2C_A_CONTROL_ARBLI_SET_VALUE << SI32_I2C_A_CONTROL_ARBLI_SHIFT)

#define SI32_I2C_A_CONTROL_T0I_MASK  0x00004000
#define SI32_I2C_A_CONTROL_T0I_SHIFT  14
// Read: A I2C Timer Byte 0 interrupt has not occurred. Write: Clear the I2C Timer
// Byte 0 interrupt (T0I).
#define SI32_I2C_A_CONTROL_T0I_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_T0I_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_T0I_NOT_SET_VALUE << SI32_I2C_A_CONTROL_T0I_SHIFT)
// Read: I2C Timer Byte 0 overflow interrupt detected. Write: Force a I2C Timer
// Byte 0 interrupt.
#define SI32_I2C_A_CONTROL_T0I_SET_VALUE  1
#define SI32_I2C_A_CONTROL_T0I_SET_U32 \
   (SI32_I2C_A_CONTROL_T0I_SET_VALUE << SI32_I2C_A_CONTROL_T0I_SHIFT)

#define SI32_I2C_A_CONTROL_T1I_MASK  0x00008000
#define SI32_I2C_A_CONTROL_T1I_SHIFT  15
// Read: No interrupt occurred. Write: Clear the I2C Timer Byte 1 interrupt (T1I).
#define SI32_I2C_A_CONTROL_T1I_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_T1I_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_T1I_NOT_SET_VALUE << SI32_I2C_A_CONTROL_T1I_SHIFT)
// Read: I2C Timer Byte 1 overflow interrupt is detected. Write: Force a I2C Timer
// Byte 1 interrupt.
#define SI32_I2C_A_CONTROL_T1I_SET_VALUE  1
#define SI32_I2C_A_CONTROL_T1I_SET_U32 \
   (SI32_I2C_A_CONTROL_T1I_SET_VALUE << SI32_I2C_A_CONTROL_T1I_SHIFT)

#define SI32_I2C_A_CONTROL_T2I_MASK  0x00010000
#define SI32_I2C_A_CONTROL_T2I_SHIFT  16
// Read: A I2C Timer Byte 2 interrupt has not occurred. Write: Clear the I2C Timer
// Byte 2 interrupt (T2I).
#define SI32_I2C_A_CONTROL_T2I_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_T2I_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_T2I_NOT_SET_VALUE << SI32_I2C_A_CONTROL_T2I_SHIFT)
// Read: I2C Timer Byte 2 overflow interrupt detected. Write: Force a I2C Timer
// Byte 2 interrupt.
#define SI32_I2C_A_CONTROL_T2I_SET_VALUE  1
#define SI32_I2C_A_CONTROL_T2I_SET_U32 \
   (SI32_I2C_A_CONTROL_T2I_SET_VALUE << SI32_I2C_A_CONTROL_T2I_SHIFT)

#define SI32_I2C_A_CONTROL_T3I_MASK  0x00020000
#define SI32_I2C_A_CONTROL_T3I_SHIFT  17
// Read: A I2C Timer Byte 3 interrupt or SCL low timeout has not occurred. Write:
// Clear the I2C Timer Byte 3 interrupt (T3I).
#define SI32_I2C_A_CONTROL_T3I_NOT_SET_VALUE  0
#define SI32_I2C_A_CONTROL_T3I_NOT_SET_U32 \
   (SI32_I2C_A_CONTROL_T3I_NOT_SET_VALUE << SI32_I2C_A_CONTROL_T3I_SHIFT)
// Read: I2C Timer Byte 3 overflow or SCL low timeout interrupt detected. Write:
// Force a I2C Timer Byte 3 interrupt.
#define SI32_I2C_A_CONTROL_T3I_SET_VALUE  1
#define SI32_I2C_A_CONTROL_T3I_SET_U32 \
   (SI32_I2C_A_CONTROL_T3I_SET_VALUE << SI32_I2C_A_CONTROL_T3I_SHIFT)

#define SI32_I2C_A_CONTROL_RXARM_MASK  0x00040000
#define SI32_I2C_A_CONTROL_RXARM_SHIFT  18
// Disable data and address reception.
#define SI32_I2C_A_CONTROL_RXARM_DISABLED_VALUE  0
#define SI32_I2C_A_CONTROL_RXARM_DISABLED_U32 \
   (SI32_I2C_A_CONTROL_RXARM_DISABLED_VALUE << SI32_I2C_A_CONTROL_RXARM_SHIFT)
// Enable the module to perform a receive operation.
#define SI32_I2C_A_CONTROL_RXARM_ENABLED_VALUE  1
#define SI32_I2C_A_CONTROL_RXARM_ENABLED_U32 \
   (SI32_I2C_A_CONTROL_RXARM_ENABLED_VALUE << SI32_I2C_A_CONTROL_RXARM_SHIFT)

#define SI32_I2C_A_CONTROL_TXARM_MASK  0x00080000
#define SI32_I2C_A_CONTROL_TXARM_SHIFT  19
// Disable data and address transmission.
#define SI32_I2C_A_CONTROL_TXARM_DISABLED_VALUE  0
#define SI32_I2C_A_CONTROL_TXARM_DISABLED_U32 \
   (SI32_I2C_A_CONTROL_TXARM_DISABLED_VALUE << SI32_I2C_A_CONTROL_TXARM_SHIFT)
// Enable the module to perform a transmit operation.
#define SI32_I2C_A_CONTROL_TXARM_ENABLED_VALUE  1
#define SI32_I2C_A_CONTROL_TXARM_ENABLED_U32 \
   (SI32_I2C_A_CONTROL_TXARM_ENABLED_VALUE << SI32_I2C_A_CONTROL_TXARM_SHIFT)

#define SI32_I2C_A_CONTROL_SLVAF_MASK  0x00100000
#define SI32_I2C_A_CONTROL_SLVAF_SHIFT  20
// Slave address detected.
#define SI32_I2C_A_CONTROL_SLVAF_SLAVE_ADDRESS_VALUE  0
#define SI32_I2C_A_CONTROL_SLVAF_SLAVE_ADDRESS_U32 \
   (SI32_I2C_A_CONTROL_SLVAF_SLAVE_ADDRESS_VALUE << SI32_I2C_A_CONTROL_SLVAF_SHIFT)
// General Call address detected.
#define SI32_I2C_A_CONTROL_SLVAF_GENERAL_CALL_VALUE  1
#define SI32_I2C_A_CONTROL_SLVAF_GENERAL_CALL_U32 \
   (SI32_I2C_A_CONTROL_SLVAF_GENERAL_CALL_VALUE << SI32_I2C_A_CONTROL_SLVAF_SHIFT)

#define SI32_I2C_A_CONTROL_ATXRXEN_MASK  0x00200000
#define SI32_I2C_A_CONTROL_ATXRXEN_SHIFT  21
// Do not automatically switch to transmit or receive mode after a Start.
#define SI32_I2C_A_CONTROL_ATXRXEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONTROL_ATXRXEN_DISABLED_U32 \
   (SI32_I2C_A_CONTROL_ATXRXEN_DISABLED_VALUE << SI32_I2C_A_CONTROL_ATXRXEN_SHIFT)
// If automatic hardware acknowledge mode is enabled (HACKEN = 1), automatically
// switch to transmit or receive mode after a Start.
#define SI32_I2C_A_CONTROL_ATXRXEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONTROL_ATXRXEN_ENABLED_U32 \
   (SI32_I2C_A_CONTROL_ATXRXEN_ENABLED_VALUE << SI32_I2C_A_CONTROL_ATXRXEN_SHIFT)

#define SI32_I2C_A_CONTROL_FMD_MASK  0x00400000
#define SI32_I2C_A_CONTROL_FMD_SHIFT  22
// Enable the input filter.
#define SI32_I2C_A_CONTROL_FMD_ENABLED_VALUE  0
#define SI32_I2C_A_CONTROL_FMD_ENABLED_U32 \
   (SI32_I2C_A_CONTROL_FMD_ENABLED_VALUE << SI32_I2C_A_CONTROL_FMD_SHIFT)
// Disable the input filter.
#define SI32_I2C_A_CONTROL_FMD_DISABLED_VALUE  1
#define SI32_I2C_A_CONTROL_FMD_DISABLED_U32 \
   (SI32_I2C_A_CONTROL_FMD_DISABLED_VALUE << SI32_I2C_A_CONTROL_FMD_SHIFT)

#define SI32_I2C_A_CONTROL_DBGMD_MASK  0x00800000
#define SI32_I2C_A_CONTROL_DBGMD_SHIFT  23
// The I2C module will continue to operate while the core is halted in debug mode.
#define SI32_I2C_A_CONTROL_DBGMD_RUN_VALUE  0
#define SI32_I2C_A_CONTROL_DBGMD_RUN_U32 \
   (SI32_I2C_A_CONTROL_DBGMD_RUN_VALUE << SI32_I2C_A_CONTROL_DBGMD_SHIFT)
// A debug breakpoint will cause the I2C module to halt.
#define SI32_I2C_A_CONTROL_DBGMD_HALT_VALUE  1
#define SI32_I2C_A_CONTROL_DBGMD_HALT_U32 \
   (SI32_I2C_A_CONTROL_DBGMD_HALT_VALUE << SI32_I2C_A_CONTROL_DBGMD_SHIFT)

#define SI32_I2C_A_CONTROL_SMINH_MASK  0x01000000
#define SI32_I2C_A_CONTROL_SMINH_SHIFT  24
// Enable Slave modes.
#define SI32_I2C_A_CONTROL_SMINH_INACTIVE_VALUE  0
#define SI32_I2C_A_CONTROL_SMINH_INACTIVE_U32 \
   (SI32_I2C_A_CONTROL_SMINH_INACTIVE_VALUE << SI32_I2C_A_CONTROL_SMINH_SHIFT)
// Inhibit Slave modes. The module will not respond to a Master on the bus.
#define SI32_I2C_A_CONTROL_SMINH_ACTIVE_VALUE  1
#define SI32_I2C_A_CONTROL_SMINH_ACTIVE_U32 \
   (SI32_I2C_A_CONTROL_SMINH_ACTIVE_VALUE << SI32_I2C_A_CONTROL_SMINH_SHIFT)

#define SI32_I2C_A_CONTROL_HACKEN_MASK  0x02000000
#define SI32_I2C_A_CONTROL_HACKEN_SHIFT  25
// Disable automatic hardware acknowledge.
#define SI32_I2C_A_CONTROL_HACKEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONTROL_HACKEN_DISABLED_U32 \
   (SI32_I2C_A_CONTROL_HACKEN_DISABLED_VALUE << SI32_I2C_A_CONTROL_HACKEN_SHIFT)
// Enable automatic hardware acknowledge.
#define SI32_I2C_A_CONTROL_HACKEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONTROL_HACKEN_ENABLED_U32 \
   (SI32_I2C_A_CONTROL_HACKEN_ENABLED_VALUE << SI32_I2C_A_CONTROL_HACKEN_SHIFT)

#define SI32_I2C_A_CONTROL_LBACKEN_MASK  0x08000000
#define SI32_I2C_A_CONTROL_LBACKEN_SHIFT  27
// NACK after the last byte is received.
#define SI32_I2C_A_CONTROL_LBACKEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONTROL_LBACKEN_DISABLED_U32 \
   (SI32_I2C_A_CONTROL_LBACKEN_DISABLED_VALUE << SI32_I2C_A_CONTROL_LBACKEN_SHIFT)
// ACK after the last byte is received.
#define SI32_I2C_A_CONTROL_LBACKEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONTROL_LBACKEN_ENABLED_U32 \
   (SI32_I2C_A_CONTROL_LBACKEN_ENABLED_VALUE << SI32_I2C_A_CONTROL_LBACKEN_SHIFT)

#define SI32_I2C_A_CONTROL_GCEN_MASK  0x20000000
#define SI32_I2C_A_CONTROL_GCEN_SHIFT  29
// Disable General Call address decoding.
#define SI32_I2C_A_CONTROL_GCEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONTROL_GCEN_DISABLED_U32 \
   (SI32_I2C_A_CONTROL_GCEN_DISABLED_VALUE << SI32_I2C_A_CONTROL_GCEN_SHIFT)
// Enable General Call address decoding.
#define SI32_I2C_A_CONTROL_GCEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONTROL_GCEN_ENABLED_U32 \
   (SI32_I2C_A_CONTROL_GCEN_ENABLED_VALUE << SI32_I2C_A_CONTROL_GCEN_SHIFT)

#define SI32_I2C_A_CONTROL_RESET_MASK  0x40000000
#define SI32_I2C_A_CONTROL_RESET_SHIFT  30
// I2C module is not in soft reset.
#define SI32_I2C_A_CONTROL_RESET_INACTIVE_VALUE  0
#define SI32_I2C_A_CONTROL_RESET_INACTIVE_U32 \
   (SI32_I2C_A_CONTROL_RESET_INACTIVE_VALUE << SI32_I2C_A_CONTROL_RESET_SHIFT)
// I2C module is in soft reset and firmware cannot access all bits in the module.
#define SI32_I2C_A_CONTROL_RESET_ACTIVE_VALUE  1
#define SI32_I2C_A_CONTROL_RESET_ACTIVE_U32 \
   (SI32_I2C_A_CONTROL_RESET_ACTIVE_VALUE << SI32_I2C_A_CONTROL_RESET_SHIFT)

#define SI32_I2C_A_CONTROL_I2CEN_MASK  0x80000000
#define SI32_I2C_A_CONTROL_I2CEN_SHIFT  31
// Disable the I2C module.
#define SI32_I2C_A_CONTROL_I2CEN_DISABLED_VALUE  0U
#define SI32_I2C_A_CONTROL_I2CEN_DISABLED_U32 \
   (SI32_I2C_A_CONTROL_I2CEN_DISABLED_VALUE << SI32_I2C_A_CONTROL_I2CEN_SHIFT)
// Enable the I2C module.
#define SI32_I2C_A_CONTROL_I2CEN_ENABLED_VALUE  1U
#define SI32_I2C_A_CONTROL_I2CEN_ENABLED_U32 \
   (SI32_I2C_A_CONTROL_I2CEN_ENABLED_VALUE << SI32_I2C_A_CONTROL_I2CEN_SHIFT)



struct SI32_I2C_A_CONFIG_Struct
{
   union
   {
      struct
      {
         // I2C Clock Scaler
         volatile uint32_t SCALER: 6;
                  uint32_t reserved0: 2;
         // Stop Interrupt Enable
         volatile uint32_t STOIEN: 1;
         // Acknowledge Interrupt Enable
         volatile uint32_t ACKIEN: 1;
         // Receive Done Interrupt Enable
         volatile uint32_t RXIEN: 1;
         // Transmit Done Interrupt Enable
         volatile uint32_t TXIEN: 1;
         // Start Interrupt Enable
         volatile uint32_t STAIEN: 1;
         // Arbitration Lost Interrupt Enable
         volatile uint32_t ARBLIEN: 1;
         // I2C Timer Byte 0 Interrupt Enable
         volatile uint32_t T0IEN: 1;
         // I2C Timer Byte 1 Interrupt Enable
         volatile uint32_t T1IEN: 1;
         // I2C Timer Byte 2 Interrupt Enable
         volatile uint32_t T2IEN: 1;
         // I2C Timer Byte 3 Interrupt Enable
         volatile uint32_t T3IEN: 1;
                  uint32_t reserved1: 2;
         // Transfer Byte Count
         volatile uint32_t BC: 2;
         // Transfer Byte Pointer
         volatile uint32_t BP: 2;
         // I2C Timer Byte 0 Run
         volatile uint32_t T0RUN: 1;
         // I2C Timer Byte 1 Run
         volatile uint32_t T1RUN: 1;
         // I2C Timer Byte 2 Run
         volatile uint32_t T2RUN: 1;
         // I2C Timer Byte 3 Run
         volatile uint32_t T3RUN: 1;
         // I2C Timer Mode
         volatile uint32_t TMD: 2;
                  uint32_t reserved2: 1;
         // I2C Timer Enable
         volatile uint32_t TIMEREN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2C_A_CONFIG_SCALER_MASK  0x0000003F
#define SI32_I2C_A_CONFIG_SCALER_SHIFT  0

#define SI32_I2C_A_CONFIG_STOIEN_MASK  0x00000100
#define SI32_I2C_A_CONFIG_STOIEN_SHIFT  8
// Disable the stop interrupt.
#define SI32_I2C_A_CONFIG_STOIEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONFIG_STOIEN_DISABLED_U32 \
   (SI32_I2C_A_CONFIG_STOIEN_DISABLED_VALUE << SI32_I2C_A_CONFIG_STOIEN_SHIFT)
// Enable the stop interrupt (STOI).
#define SI32_I2C_A_CONFIG_STOIEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONFIG_STOIEN_ENABLED_U32 \
   (SI32_I2C_A_CONFIG_STOIEN_ENABLED_VALUE << SI32_I2C_A_CONFIG_STOIEN_SHIFT)

#define SI32_I2C_A_CONFIG_ACKIEN_MASK  0x00000200
#define SI32_I2C_A_CONFIG_ACKIEN_SHIFT  9
// Disable the acknowledge interrupt.
#define SI32_I2C_A_CONFIG_ACKIEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONFIG_ACKIEN_DISABLED_U32 \
   (SI32_I2C_A_CONFIG_ACKIEN_DISABLED_VALUE << SI32_I2C_A_CONFIG_ACKIEN_SHIFT)
// Enable the acknowledge interrupt (ACKI).
#define SI32_I2C_A_CONFIG_ACKIEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONFIG_ACKIEN_ENABLED_U32 \
   (SI32_I2C_A_CONFIG_ACKIEN_ENABLED_VALUE << SI32_I2C_A_CONFIG_ACKIEN_SHIFT)

#define SI32_I2C_A_CONFIG_RXIEN_MASK  0x00000400
#define SI32_I2C_A_CONFIG_RXIEN_SHIFT  10
// Disable the receive done interrupt.
#define SI32_I2C_A_CONFIG_RXIEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONFIG_RXIEN_DISABLED_U32 \
   (SI32_I2C_A_CONFIG_RXIEN_DISABLED_VALUE << SI32_I2C_A_CONFIG_RXIEN_SHIFT)
// Enable the receive done interrupt (RXI).
#define SI32_I2C_A_CONFIG_RXIEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONFIG_RXIEN_ENABLED_U32 \
   (SI32_I2C_A_CONFIG_RXIEN_ENABLED_VALUE << SI32_I2C_A_CONFIG_RXIEN_SHIFT)

#define SI32_I2C_A_CONFIG_TXIEN_MASK  0x00000800
#define SI32_I2C_A_CONFIG_TXIEN_SHIFT  11
// Disable the transmit done interrupt.
#define SI32_I2C_A_CONFIG_TXIEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONFIG_TXIEN_DISABLED_U32 \
   (SI32_I2C_A_CONFIG_TXIEN_DISABLED_VALUE << SI32_I2C_A_CONFIG_TXIEN_SHIFT)
// Enable the transmit done interrupt (TXI).
#define SI32_I2C_A_CONFIG_TXIEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONFIG_TXIEN_ENABLED_U32 \
   (SI32_I2C_A_CONFIG_TXIEN_ENABLED_VALUE << SI32_I2C_A_CONFIG_TXIEN_SHIFT)

#define SI32_I2C_A_CONFIG_STAIEN_MASK  0x00001000
#define SI32_I2C_A_CONFIG_STAIEN_SHIFT  12
// Disable the start interrupt.
#define SI32_I2C_A_CONFIG_STAIEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONFIG_STAIEN_DISABLED_U32 \
   (SI32_I2C_A_CONFIG_STAIEN_DISABLED_VALUE << SI32_I2C_A_CONFIG_STAIEN_SHIFT)
// Enable the start interrupt (STAI).
#define SI32_I2C_A_CONFIG_STAIEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONFIG_STAIEN_ENABLED_U32 \
   (SI32_I2C_A_CONFIG_STAIEN_ENABLED_VALUE << SI32_I2C_A_CONFIG_STAIEN_SHIFT)

#define SI32_I2C_A_CONFIG_ARBLIEN_MASK  0x00002000
#define SI32_I2C_A_CONFIG_ARBLIEN_SHIFT  13
// Disable the arbitration lost interrupt.
#define SI32_I2C_A_CONFIG_ARBLIEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONFIG_ARBLIEN_DISABLED_U32 \
   (SI32_I2C_A_CONFIG_ARBLIEN_DISABLED_VALUE << SI32_I2C_A_CONFIG_ARBLIEN_SHIFT)
// Enable the arbitration lost interrupt (ARBLI).
#define SI32_I2C_A_CONFIG_ARBLIEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONFIG_ARBLIEN_ENABLED_U32 \
   (SI32_I2C_A_CONFIG_ARBLIEN_ENABLED_VALUE << SI32_I2C_A_CONFIG_ARBLIEN_SHIFT)

#define SI32_I2C_A_CONFIG_T0IEN_MASK  0x00004000
#define SI32_I2C_A_CONFIG_T0IEN_SHIFT  14
// Disable the I2C Timer Byte 0 interrupt.
#define SI32_I2C_A_CONFIG_T0IEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONFIG_T0IEN_DISABLED_U32 \
   (SI32_I2C_A_CONFIG_T0IEN_DISABLED_VALUE << SI32_I2C_A_CONFIG_T0IEN_SHIFT)
// Enable the I2C Timer Byte 0 interrupt (T0I).
#define SI32_I2C_A_CONFIG_T0IEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONFIG_T0IEN_ENABLED_U32 \
   (SI32_I2C_A_CONFIG_T0IEN_ENABLED_VALUE << SI32_I2C_A_CONFIG_T0IEN_SHIFT)

#define SI32_I2C_A_CONFIG_T1IEN_MASK  0x00008000
#define SI32_I2C_A_CONFIG_T1IEN_SHIFT  15
// Disable the I2C Timer Byte 1 interrupt.
#define SI32_I2C_A_CONFIG_T1IEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONFIG_T1IEN_DISABLED_U32 \
   (SI32_I2C_A_CONFIG_T1IEN_DISABLED_VALUE << SI32_I2C_A_CONFIG_T1IEN_SHIFT)
// Enable the I2C Timer Byte 1 interrupt (T1I).
#define SI32_I2C_A_CONFIG_T1IEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONFIG_T1IEN_ENABLED_U32 \
   (SI32_I2C_A_CONFIG_T1IEN_ENABLED_VALUE << SI32_I2C_A_CONFIG_T1IEN_SHIFT)

#define SI32_I2C_A_CONFIG_T2IEN_MASK  0x00010000
#define SI32_I2C_A_CONFIG_T2IEN_SHIFT  16
// Disable the I2C Timer Byte 2 interrupt.
#define SI32_I2C_A_CONFIG_T2IEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONFIG_T2IEN_DISABLED_U32 \
   (SI32_I2C_A_CONFIG_T2IEN_DISABLED_VALUE << SI32_I2C_A_CONFIG_T2IEN_SHIFT)
// Enable the I2C Timer Byte 2 interrupt (T2I).
#define SI32_I2C_A_CONFIG_T2IEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONFIG_T2IEN_ENABLED_U32 \
   (SI32_I2C_A_CONFIG_T2IEN_ENABLED_VALUE << SI32_I2C_A_CONFIG_T2IEN_SHIFT)

#define SI32_I2C_A_CONFIG_T3IEN_MASK  0x00020000
#define SI32_I2C_A_CONFIG_T3IEN_SHIFT  17
// Disable the I2C Timer Byte 3 and SCL low timeout interrupt.
#define SI32_I2C_A_CONFIG_T3IEN_DISABLED_VALUE  0
#define SI32_I2C_A_CONFIG_T3IEN_DISABLED_U32 \
   (SI32_I2C_A_CONFIG_T3IEN_DISABLED_VALUE << SI32_I2C_A_CONFIG_T3IEN_SHIFT)
// Enable the I2C Timer Byte 3 and SCL low timeout interrupt (T3I).
#define SI32_I2C_A_CONFIG_T3IEN_ENABLED_VALUE  1
#define SI32_I2C_A_CONFIG_T3IEN_ENABLED_U32 \
   (SI32_I2C_A_CONFIG_T3IEN_ENABLED_VALUE << SI32_I2C_A_CONFIG_T3IEN_SHIFT)

#define SI32_I2C_A_CONFIG_BC_MASK  0x00300000
#define SI32_I2C_A_CONFIG_BC_SHIFT  20

#define SI32_I2C_A_CONFIG_BP_MASK  0x00C00000
#define SI32_I2C_A_CONFIG_BP_SHIFT  22

#define SI32_I2C_A_CONFIG_T0RUN_MASK  0x01000000
#define SI32_I2C_A_CONFIG_T0RUN_SHIFT  24
// Stop Timer Byte 0.
#define SI32_I2C_A_CONFIG_T0RUN_STOP_VALUE  0
#define SI32_I2C_A_CONFIG_T0RUN_STOP_U32 \
   (SI32_I2C_A_CONFIG_T0RUN_STOP_VALUE << SI32_I2C_A_CONFIG_T0RUN_SHIFT)
// Start Timer Byte 0 running.
#define SI32_I2C_A_CONFIG_T0RUN_START_VALUE  1
#define SI32_I2C_A_CONFIG_T0RUN_START_U32 \
   (SI32_I2C_A_CONFIG_T0RUN_START_VALUE << SI32_I2C_A_CONFIG_T0RUN_SHIFT)

#define SI32_I2C_A_CONFIG_T1RUN_MASK  0x02000000
#define SI32_I2C_A_CONFIG_T1RUN_SHIFT  25
// Stop Timer Byte 1.
#define SI32_I2C_A_CONFIG_T1RUN_STOP_VALUE  0
#define SI32_I2C_A_CONFIG_T1RUN_STOP_U32 \
   (SI32_I2C_A_CONFIG_T1RUN_STOP_VALUE << SI32_I2C_A_CONFIG_T1RUN_SHIFT)
// Start Timer Byte 1 running.
#define SI32_I2C_A_CONFIG_T1RUN_START_VALUE  1
#define SI32_I2C_A_CONFIG_T1RUN_START_U32 \
   (SI32_I2C_A_CONFIG_T1RUN_START_VALUE << SI32_I2C_A_CONFIG_T1RUN_SHIFT)

#define SI32_I2C_A_CONFIG_T2RUN_MASK  0x04000000
#define SI32_I2C_A_CONFIG_T2RUN_SHIFT  26
// Stop Timer Byte 2.
#define SI32_I2C_A_CONFIG_T2RUN_STOP_VALUE  0
#define SI32_I2C_A_CONFIG_T2RUN_STOP_U32 \
   (SI32_I2C_A_CONFIG_T2RUN_STOP_VALUE << SI32_I2C_A_CONFIG_T2RUN_SHIFT)
// Start Timer Byte 2 running.
#define SI32_I2C_A_CONFIG_T2RUN_START_VALUE  1
#define SI32_I2C_A_CONFIG_T2RUN_START_U32 \
   (SI32_I2C_A_CONFIG_T2RUN_START_VALUE << SI32_I2C_A_CONFIG_T2RUN_SHIFT)

#define SI32_I2C_A_CONFIG_T3RUN_MASK  0x08000000
#define SI32_I2C_A_CONFIG_T3RUN_SHIFT  27
// Stop Timer Byte 3.
#define SI32_I2C_A_CONFIG_T3RUN_STOP_VALUE  0
#define SI32_I2C_A_CONFIG_T3RUN_STOP_U32 \
   (SI32_I2C_A_CONFIG_T3RUN_STOP_VALUE << SI32_I2C_A_CONFIG_T3RUN_SHIFT)
// Start Timer Byte 3 running.
#define SI32_I2C_A_CONFIG_T3RUN_START_VALUE  1
#define SI32_I2C_A_CONFIG_T3RUN_START_U32 \
   (SI32_I2C_A_CONFIG_T3RUN_START_VALUE << SI32_I2C_A_CONFIG_T3RUN_SHIFT)

#define SI32_I2C_A_CONFIG_TMD_MASK  0x30000000
#define SI32_I2C_A_CONFIG_TMD_SHIFT  28
// I2C Timer Mode 0: Operate the I2C timer as a single 32-bit timer : Timer Bytes
// [3 : 2 : 1 : 0].
#define SI32_I2C_A_CONFIG_TMD_MODE0_VALUE  0
#define SI32_I2C_A_CONFIG_TMD_MODE0_U32 \
   (SI32_I2C_A_CONFIG_TMD_MODE0_VALUE << SI32_I2C_A_CONFIG_TMD_SHIFT)
// I2C Timer Mode 1: Operate the I2C timer as two 16-bit timers : Timer Bytes [3 :
// 2] and Timer Bytes [1 : 0].
#define SI32_I2C_A_CONFIG_TMD_MODE1_VALUE  1
#define SI32_I2C_A_CONFIG_TMD_MODE1_U32 \
   (SI32_I2C_A_CONFIG_TMD_MODE1_VALUE << SI32_I2C_A_CONFIG_TMD_SHIFT)
// I2C Timer Mode 2: Operate the I2C timer as four independent 8-bit timers :
// Timer Byte 3, Timer Byte 2, Timer Byte 1, and Timer Byte 0.
#define SI32_I2C_A_CONFIG_TMD_MODE2_VALUE  2
#define SI32_I2C_A_CONFIG_TMD_MODE2_U32 \
   (SI32_I2C_A_CONFIG_TMD_MODE2_VALUE << SI32_I2C_A_CONFIG_TMD_SHIFT)
// I2C Timer Mode 3: Operate the I2C timer as one 16-bit and two 8-bit timers :
// Timer Bytes [3 : 2], Timer Byte 1, and Timer Byte 0.
#define SI32_I2C_A_CONFIG_TMD_MODE3_VALUE  3
#define SI32_I2C_A_CONFIG_TMD_MODE3_U32 \
   (SI32_I2C_A_CONFIG_TMD_MODE3_VALUE << SI32_I2C_A_CONFIG_TMD_SHIFT)

#define SI32_I2C_A_CONFIG_TIMEREN_MASK  0x80000000
#define SI32_I2C_A_CONFIG_TIMEREN_SHIFT  31
// Disable I2C Timer.
#define SI32_I2C_A_CONFIG_TIMEREN_DISABLED_VALUE  0U
#define SI32_I2C_A_CONFIG_TIMEREN_DISABLED_U32 \
   (SI32_I2C_A_CONFIG_TIMEREN_DISABLED_VALUE << SI32_I2C_A_CONFIG_TIMEREN_SHIFT)
// Enable I2C Timer for general purpose use. This setting should not be used when
// the I2C module is enabled (I2CEN = 1).
#define SI32_I2C_A_CONFIG_TIMEREN_ENABLED_VALUE  1U
#define SI32_I2C_A_CONFIG_TIMEREN_ENABLED_U32 \
   (SI32_I2C_A_CONFIG_TIMEREN_ENABLED_VALUE << SI32_I2C_A_CONFIG_TIMEREN_SHIFT)



struct SI32_I2C_A_SADDRESS_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 1;
         // Slave Address
         volatile uint32_t ADDRESS: 7;
                  uint32_t reserved1: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2C_A_SADDRESS_ADDRESS_MASK  0x000000FE
#define SI32_I2C_A_SADDRESS_ADDRESS_SHIFT  1



struct SI32_I2C_A_SMASK_Struct
{
   union
   {
      struct
      {
                  uint32_t reserved0: 1;
         // Slave Address Mask
         volatile uint32_t MASK: 7;
                  uint32_t reserved1: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2C_A_SMASK_MASK_MASK  0x000000FE
#define SI32_I2C_A_SMASK_MASK_SHIFT  1



struct SI32_I2C_A_DATA_Struct
{
   union
   {
      struct
      {
         // Data
         volatile uint32_t DATA_BITS;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2C_A_DATA_DATA_MASK  0xFFFFFFFF
#define SI32_I2C_A_DATA_DATA_SHIFT  0



struct SI32_I2C_A_TIMER_Struct
{
   union
   {
      struct
      {
         // Timer Byte 0
         volatile uint8_t T0;
         // Timer Byte 1
         volatile uint8_t T1;
         // Timer Byte 2
         volatile uint8_t T2;
         // Timer Byte 3
         volatile uint8_t T3;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2C_A_TIMER_T0_MASK  0x000000FF
#define SI32_I2C_A_TIMER_T0_SHIFT  0

#define SI32_I2C_A_TIMER_T1_MASK  0x0000FF00
#define SI32_I2C_A_TIMER_T1_SHIFT  8

#define SI32_I2C_A_TIMER_T2_MASK  0x00FF0000
#define SI32_I2C_A_TIMER_T2_SHIFT  16

#define SI32_I2C_A_TIMER_T3_MASK  0xFF000000
#define SI32_I2C_A_TIMER_T3_SHIFT  24



struct SI32_I2C_A_TIMERRL_Struct
{
   union
   {
      struct
      {
         // Timer Byte 0 Reload / Bus Free Timeout
         volatile uint8_t T0RL;
         // Timer Byte 1 Reload / SCL High Time
         volatile uint8_t T1RL;
         // Timer Byte 2 Reload / SCL Low Timeout Bits [11:4]
         volatile uint8_t T2RL;
         // Timer Byte 3 Reload / SCL Low Timeout Bits [19:12]
         volatile uint8_t T3RL;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2C_A_TIMERRL_T0RL_MASK  0x000000FF
#define SI32_I2C_A_TIMERRL_T0RL_SHIFT  0

#define SI32_I2C_A_TIMERRL_T1RL_MASK  0x0000FF00
#define SI32_I2C_A_TIMERRL_T1RL_SHIFT  8

#define SI32_I2C_A_TIMERRL_T2RL_MASK  0x00FF0000
#define SI32_I2C_A_TIMERRL_T2RL_SHIFT  16

#define SI32_I2C_A_TIMERRL_T3RL_MASK  0xFF000000
#define SI32_I2C_A_TIMERRL_T3RL_SHIFT  24



struct SI32_I2C_A_SCONFIG_Struct
{
   union
   {
      struct
      {
         // Data Setup Time Extension
         volatile uint32_t SETUP: 4;
         // Data Hold Time Extension
         volatile uint32_t HOLD: 4;
         // SCL Low Time
         volatile uint8_t SCLL;
         // SCL Low Timeout Bits [3:0]
         volatile uint32_t SCLLTIMER: 4;
                  uint32_t reserved0: 12;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2C_A_SCONFIG_SETUP_MASK  0x0000000F
#define SI32_I2C_A_SCONFIG_SETUP_SHIFT  0

#define SI32_I2C_A_SCONFIG_HOLD_MASK  0x000000F0
#define SI32_I2C_A_SCONFIG_HOLD_SHIFT  4

#define SI32_I2C_A_SCONFIG_SCLL_MASK  0x0000FF00
#define SI32_I2C_A_SCONFIG_SCLL_SHIFT  8

#define SI32_I2C_A_SCONFIG_SCLLTIMER_MASK  0x000F0000
#define SI32_I2C_A_SCONFIG_SCLLTIMER_SHIFT  16



struct SI32_I2C_A_I2CDMA_Struct
{
   union
   {
      struct
      {
         // DMA Transfer Length
         volatile uint8_t DMALEN;
                  uint32_t reserved0: 23;
         // DMA Mode Enable
         volatile uint32_t DMAEN: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_I2C_A_I2CDMA_DMALEN_MASK  0x000000FF
#define SI32_I2C_A_I2CDMA_DMALEN_SHIFT  0

#define SI32_I2C_A_I2CDMA_DMAEN_MASK  0x80000000
#define SI32_I2C_A_I2CDMA_DMAEN_SHIFT  31
// Disable I2C DMA data requests.
#define SI32_I2C_A_I2CDMA_DMAEN_DISABLED_VALUE  0U
#define SI32_I2C_A_I2CDMA_DMAEN_DISABLED_U32 \
   (SI32_I2C_A_I2CDMA_DMAEN_DISABLED_VALUE << SI32_I2C_A_I2CDMA_DMAEN_SHIFT)
// Enable I2C DMA data requests.
#define SI32_I2C_A_I2CDMA_DMAEN_ENABLED_VALUE  1U
#define SI32_I2C_A_I2CDMA_DMAEN_ENABLED_U32 \
   (SI32_I2C_A_I2CDMA_DMAEN_ENABLED_VALUE << SI32_I2C_A_I2CDMA_DMAEN_SHIFT)



typedef struct SI32_I2C_A_Struct
{
   struct SI32_I2C_A_CONTROL_Struct                CONTROL        ; // Base Address + 0x0
   volatile uint32_t                               CONTROL_SET;
   volatile uint32_t                               CONTROL_CLR;
   uint32_t                                        reserved0;
   struct SI32_I2C_A_CONFIG_Struct                 CONFIG         ; // Base Address + 0x10
   volatile uint32_t                               CONFIG_SET;
   volatile uint32_t                               CONFIG_CLR;
   uint32_t                                        reserved1;
   struct SI32_I2C_A_SADDRESS_Struct               SADDRESS       ; // Base Address + 0x20
   uint32_t                                        reserved2;
   uint32_t                                        reserved3;
   uint32_t                                        reserved4;
   struct SI32_I2C_A_SMASK_Struct                  SMASK          ; // Base Address + 0x30
   uint32_t                                        reserved5;
   uint32_t                                        reserved6;
   uint32_t                                        reserved7;
   struct SI32_I2C_A_DATA_Struct                   DATA           ; // Base Address + 0x40
   uint32_t                                        reserved8;
   uint32_t                                        reserved9;
   uint32_t                                        reserved10;
   struct SI32_I2C_A_TIMER_Struct                  TIMER          ; // Base Address + 0x50
   uint32_t                                        reserved11;
   uint32_t                                        reserved12;
   uint32_t                                        reserved13;
   struct SI32_I2C_A_TIMERRL_Struct                TIMERRL        ; // Base Address + 0x60
   uint32_t                                        reserved14;
   uint32_t                                        reserved15;
   uint32_t                                        reserved16;
   struct SI32_I2C_A_SCONFIG_Struct                SCONFIG        ; // Base Address + 0x70
   uint32_t                                        reserved17;
   uint32_t                                        reserved18;
   uint32_t                                        reserved19;
   struct SI32_I2C_A_I2CDMA_Struct                 I2CDMA         ; // Base Address + 0x80
   uint32_t                                        reserved20;
   uint32_t                                        reserved21;
   uint32_t                                        reserved22;
   uint32_t                                        reserved23[4];
} SI32_I2C_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_I2C_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

