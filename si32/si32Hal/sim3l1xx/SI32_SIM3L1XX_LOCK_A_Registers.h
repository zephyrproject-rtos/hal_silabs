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
// This file applies to the SIM3L1XX_LOCK_A module
//
// Script: 0.61
// Version: 1

#ifndef __SI32_LOCK_A_REGISTERS_H__
#define __SI32_LOCK_A_REGISTERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct SI32_LOCK_A_KEY_Struct
{
   union
   {
      struct
      {
         // Peripheral Lock Mask Key
         volatile uint8_t KEY_BITS;
                  uint32_t reserved0: 24;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LOCK_A_KEY_KEY_MASK  0x000000FF
#define SI32_LOCK_A_KEY_KEY_SHIFT  0
// PERIPHLOCK registers are locked and no valid values have been written to KEY.
#define SI32_LOCK_A_KEY_KEY_LOCKED_VALUE  0
#define SI32_LOCK_A_KEY_KEY_LOCKED_U32 \
   (SI32_LOCK_A_KEY_KEY_LOCKED_VALUE << SI32_LOCK_A_KEY_KEY_SHIFT)
// PERIPHLOCK registers are locked and the first valid value (0xA5) has been
// written to KEY.
#define SI32_LOCK_A_KEY_KEY_INTERMEDIATE_VALUE  1
#define SI32_LOCK_A_KEY_KEY_INTERMEDIATE_U32 \
   (SI32_LOCK_A_KEY_KEY_INTERMEDIATE_VALUE << SI32_LOCK_A_KEY_KEY_SHIFT)
// PERIPHLOCK registers are unlocked. Any subsequent writes to KEY will lock the
// interface.
#define SI32_LOCK_A_KEY_KEY_UNLOCKED_VALUE  2
#define SI32_LOCK_A_KEY_KEY_UNLOCKED_U32 \
   (SI32_LOCK_A_KEY_KEY_UNLOCKED_VALUE << SI32_LOCK_A_KEY_KEY_SHIFT)



struct SI32_LOCK_A_PERIPHLOCK0_Struct
{
   union
   {
      struct
      {
         // USART/UART Module Lock Enable
         volatile uint32_t USARTL: 1;
         // SPI Module Lock Enable
         volatile uint32_t SPIL: 1;
         // I2C Module Lock Enable
         volatile uint32_t I2CL: 1;
         // PCA Module Lock Enable
         volatile uint32_t PCAL: 1;
         // Timer Module Lock Enable
         volatile uint32_t TIMERL: 1;
         // SARADC Module Lock Enable
         volatile uint32_t SARADCL: 1;
         // Comparator Module Lock Enable
         volatile uint32_t CMPL: 1;
         // AES Module Lock Enable
         volatile uint32_t AESL: 1;
         // CRC Module Lock Enable
         volatile uint32_t CRCL: 1;
         // RTC Module Lock Enable
         volatile uint32_t RTCL: 1;
         // Reset Sources Module Lock Enable
         volatile uint32_t RSTSRCL: 1;
         // Clock Control Lock Enable
         volatile uint32_t CLKCTRL: 1;
         // Voltage Supply Monitor Module Lock Enable
         volatile uint32_t VMONL: 1;
         // IDAC Module Lock Enable
         volatile uint32_t IDACL: 1;
         // DMA Controller Module Lock Enable
         volatile uint32_t DMACTRLL: 1;
         // DMA Crossbar Module Lock Enable
         volatile uint32_t DMAXBARL: 1;
         // Low Power Timer Module Lock Enable
         volatile uint32_t LPTL: 1;
         // Voltage Reference Module Lock Enable
         volatile uint32_t LDOL: 1;
         // PLL Module Lock Enable
         volatile uint32_t PLLL: 1;
         // External Oscillator Module Lock Enable
         volatile uint32_t EXTOSCL: 1;
         // PVT Oscillator Module Lock Enable
         volatile uint32_t PVTL: 1;
         // Low Power Oscillator Lock Enable
         volatile uint32_t LPOSCL: 1;
         // Advanced Capture Counter  Module Lock
         volatile uint32_t ACCTRL: 1;
                  uint32_t reserved0: 4;
         // PMU Module Lock Enable
         volatile uint32_t PMUL: 1;
         // DTM Module Lock
         volatile uint32_t DTML: 1;
         // LCD Module Lock
         volatile uint32_t LCDL: 1;
         // DC-DC Converter Module Lock
         volatile uint32_t DCDCL: 1;
                  uint32_t reserved1: 1;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LOCK_A_PERIPHLOCK0_USARTL_MASK  0x00000001
#define SI32_LOCK_A_PERIPHLOCK0_USARTL_SHIFT  0
// Unlock the USART0 and UART0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_USARTL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_USARTL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_USARTL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_USARTL_SHIFT)
// Lock the USART0 and UART0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_USARTL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_USARTL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_USARTL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_USARTL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_SPIL_MASK  0x00000002
#define SI32_LOCK_A_PERIPHLOCK0_SPIL_SHIFT  1
// Unlock the SPI0 and SPI1 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_SPIL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_SPIL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_SPIL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_SPIL_SHIFT)
// Lock the SPI0 and SPI1 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_SPIL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_SPIL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_SPIL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_SPIL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_I2CL_MASK  0x00000004
#define SI32_LOCK_A_PERIPHLOCK0_I2CL_SHIFT  2
// Unlock the I2C0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_I2CL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_I2CL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_I2CL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_I2CL_SHIFT)
// Lock the I2C0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_I2CL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_I2CL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_I2CL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_I2CL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_PCAL_MASK  0x00000008
#define SI32_LOCK_A_PERIPHLOCK0_PCAL_SHIFT  3
// Unlock the EPCA0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_PCAL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_PCAL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_PCAL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_PCAL_SHIFT)
// Lock the EPCA0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_PCAL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_PCAL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_PCAL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_PCAL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_TIMERL_MASK  0x00000010
#define SI32_LOCK_A_PERIPHLOCK0_TIMERL_SHIFT  4
// Unlock the TIMER0, TIMER1, and TIMER2 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_TIMERL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_TIMERL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_TIMERL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_TIMERL_SHIFT)
// Lock the TIMER0, TIMER1, and TIMER2 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_TIMERL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_TIMERL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_TIMERL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_TIMERL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_SARADCL_MASK  0x00000020
#define SI32_LOCK_A_PERIPHLOCK0_SARADCL_SHIFT  5
// Unlock the SARADC0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_SARADCL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_SARADCL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_SARADCL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_SARADCL_SHIFT)
// Lock the SARADC0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_SARADCL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_SARADCL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_SARADCL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_SARADCL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_CMPL_MASK  0x00000040
#define SI32_LOCK_A_PERIPHLOCK0_CMPL_SHIFT  6
// Unlock the Comparator 0 and Comparator 1 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_CMPL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_CMPL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CMPL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CMPL_SHIFT)
// Lock the Comparator 0 and Comparator 1 Module registers (bits can still be
// read).
#define SI32_LOCK_A_PERIPHLOCK0_CMPL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_CMPL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CMPL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CMPL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_AESL_MASK  0x00000080
#define SI32_LOCK_A_PERIPHLOCK0_AESL_SHIFT  7
// Unlock the AES0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_AESL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_AESL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_AESL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_AESL_SHIFT)
// Lock the AES0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_AESL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_AESL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_AESL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_AESL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_CRCL_MASK  0x00000100
#define SI32_LOCK_A_PERIPHLOCK0_CRCL_SHIFT  8
// Unlock the CRC0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_CRCL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_CRCL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CRCL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CRCL_SHIFT)
// Lock the CRC0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_CRCL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_CRCL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CRCL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CRCL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_RTCL_MASK  0x00000200
#define SI32_LOCK_A_PERIPHLOCK0_RTCL_SHIFT  9
// Unlock the RTC0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_RTCL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_RTCL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_RTCL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_RTCL_SHIFT)
// Lock the RTC0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_RTCL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_RTCL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_RTCL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_RTCL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_RSTSRCL_MASK  0x00000400
#define SI32_LOCK_A_PERIPHLOCK0_RSTSRCL_SHIFT  10
// Unlock the Reset Sources (RSTSRC) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_RSTSRCL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_RSTSRCL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_RSTSRCL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_RSTSRCL_SHIFT)
// Lock the Reset Sources (RSTSRC) Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_RSTSRCL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_RSTSRCL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_RSTSRCL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_RSTSRCL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_CLKCTRL_MASK  0x00000800
#define SI32_LOCK_A_PERIPHLOCK0_CLKCTRL_SHIFT  11
// Unlock the Clock Control (CLKCTRL)Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_CLKCTRL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_CLKCTRL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CLKCTRL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CLKCTRL_SHIFT)
// Lock the Clock Control (CLKCTRL) Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_CLKCTRL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_CLKCTRL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CLKCTRL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CLKCTRL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_VMONL_MASK  0x00001000
#define SI32_LOCK_A_PERIPHLOCK0_VMONL_SHIFT  12
// Unlock the Voltage Supply Monitor (VMON0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_VMONL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_VMONL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_VMONL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_VMONL_SHIFT)
// Lock the Voltage Supply Monitor (VMON0) Module registers (bits can still be
// read).
#define SI32_LOCK_A_PERIPHLOCK0_VMONL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_VMONL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_VMONL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_VMONL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_IDACL_MASK  0x00002000
#define SI32_LOCK_A_PERIPHLOCK0_IDACL_SHIFT  13
// Unlock the IDAC0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_IDACL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_IDACL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_IDACL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_IDACL_SHIFT)
// Lock the IDAC0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_IDACL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_IDACL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_IDACL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_IDACL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_MASK  0x00004000
#define SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_SHIFT  14
// Unlock the DMA Controller (DMACTRL0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_SHIFT)
// Lock the DMA Controller (DMACTRL0) Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_MASK  0x00008000
#define SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_SHIFT  15
// Unlock the DMA Crossbar (DMAXBAR0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_SHIFT)
// Lock the DMA Crossbar (DMAXBAR0) Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_LPTL_MASK  0x00010000
#define SI32_LOCK_A_PERIPHLOCK0_LPTL_SHIFT  16
// Unlock the Low Power Timer (LPTIMER0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_LPTL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_LPTL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_LPTL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_LPTL_SHIFT)
// Lock the Low Power Timer (LPTIMER0) Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_LPTL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_LPTL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_LPTL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_LPTL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_LDOL_MASK  0x00020000
#define SI32_LOCK_A_PERIPHLOCK0_LDOL_SHIFT  17
// Unlock the LDO0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_LDOL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_LDOL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_LDOL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_LDOL_SHIFT)
// Lock the LDO0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_LDOL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_LDOL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_LDOL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_LDOL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_PLLL_MASK  0x00040000
#define SI32_LOCK_A_PERIPHLOCK0_PLLL_SHIFT  18
// Unlock the PLL0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_PLLL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_PLLL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_PLLL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_PLLL_SHIFT)
// Lock the PLL0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_PLLL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_PLLL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_PLLL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_PLLL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_MASK  0x00080000
#define SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_SHIFT  19
// Unlock the External Oscillator (EXTOSC0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_SHIFT)
// Lock the External Oscillator (EXTOSC0) Module registers (bits can still be
// read).
#define SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_PVTL_MASK  0x00100000
#define SI32_LOCK_A_PERIPHLOCK0_PVTL_SHIFT  20
// Unlock the PVTOSC0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_PVTL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_PVTL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_PVTL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_PVTL_SHIFT)
// Lock the PVTOSC0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_PVTL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_PVTL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_PVTL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_PVTL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_LPOSCL_MASK  0x00200000
#define SI32_LOCK_A_PERIPHLOCK0_LPOSCL_SHIFT  21
// Unlock the Low Power Oscillator (LPOSC0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_LPOSCL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_LPOSCL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_LPOSCL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_LPOSCL_SHIFT)
// Lock the Low Power Oscillator (LPOSC0) Module registers (bits can still be
// read).
#define SI32_LOCK_A_PERIPHLOCK0_LPOSCL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_LPOSCL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_LPOSCL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_LPOSCL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_ACCTRL_MASK  0x00400000
#define SI32_LOCK_A_PERIPHLOCK0_ACCTRL_SHIFT  22
// Unlock the Advanced Capture Counter (ACCTR0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_ACCTRL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_ACCTRL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_ACCTRL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_ACCTRL_SHIFT)
// Lock the Advanced Capture Counter (ACCTR0) Module registers (bits can still be
// read).
#define SI32_LOCK_A_PERIPHLOCK0_ACCTRL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_ACCTRL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_ACCTRL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_ACCTRL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_PMUL_MASK  0x08000000
#define SI32_LOCK_A_PERIPHLOCK0_PMUL_SHIFT  27
// Unlock the PMU Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_PMUL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_PMUL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_PMUL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_PMUL_SHIFT)
// Lock the PMU Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_PMUL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_PMUL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_PMUL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_PMUL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_DTML_MASK  0x10000000
#define SI32_LOCK_A_PERIPHLOCK0_DTML_SHIFT  28
// Unlock the DTM0, DTM1, and DTM2 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_DTML_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_DTML_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_DTML_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_DTML_SHIFT)
// Lock the DTM0, DTM1, and DTM2 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_DTML_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_DTML_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_DTML_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_DTML_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_LCDL_MASK  0x20000000
#define SI32_LOCK_A_PERIPHLOCK0_LCDL_SHIFT  29
// Unlock the LCD0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_LCDL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_LCDL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_LCDL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_LCDL_SHIFT)
// Lock the LCD0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_LCDL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_LCDL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_LCDL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_LCDL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_DCDCL_MASK  0x40000000
#define SI32_LOCK_A_PERIPHLOCK0_DCDCL_SHIFT  30
// Unlock the DCDC0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_DCDCL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_DCDCL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_DCDCL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_DCDCL_SHIFT)
// Lock the DCDC0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_DCDCL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_DCDCL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_DCDCL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_DCDCL_SHIFT)



struct SI32_LOCK_A_PERIPHLOCK1_Struct
{
   union
   {
      struct
      {
         // Encoder Decoder Module Lock
         volatile uint32_t ENCDECL: 1;
                  uint32_t reserved0: 31;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LOCK_A_PERIPHLOCK1_ENCDECL_MASK  0x00000001
#define SI32_LOCK_A_PERIPHLOCK1_ENCDECL_SHIFT  0
// Unlock the ENCDEC0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK1_ENCDECL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK1_ENCDECL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK1_ENCDECL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK1_ENCDECL_SHIFT)
// Lock the ENCDEC0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK1_ENCDECL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK1_ENCDECL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK1_ENCDECL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK1_ENCDECL_SHIFT)



typedef struct SI32_LOCK_A_Struct
{
   struct SI32_LOCK_A_KEY_Struct                   KEY            ; // Base Address + 0x0
   uint32_t                                        reserved0;
   uint32_t                                        reserved1;
   uint32_t                                        reserved2;
   uint32_t                                        reserved3[4];
   struct SI32_LOCK_A_PERIPHLOCK0_Struct           PERIPHLOCK0    ; // Base Address + 0x20
   volatile uint32_t                               PERIPHLOCK0_SET;
   volatile uint32_t                               PERIPHLOCK0_CLR;
   uint32_t                                        reserved4;
   uint32_t                                        reserved5[4];
   struct SI32_LOCK_A_PERIPHLOCK1_Struct           PERIPHLOCK1    ; // Base Address + 0x40
   volatile uint32_t                               PERIPHLOCK1_SET;
   volatile uint32_t                               PERIPHLOCK1_CLR;
   uint32_t                                        reserved6;
} SI32_LOCK_A_Type;

#ifdef __cplusplus
}
#endif

#endif // __SI32_LOCK_A_REGISTERS_H__

//-eof--------------------------------------------------------------------------

