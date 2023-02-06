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
// This file applies to the SIM3U1XX_LOCK_A module
//
// Script: 0.57
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
         // USB Module Lock Enable
         volatile uint32_t USBL: 1;
         // SARADC Module Lock Enable
         volatile uint32_t SARADCL: 1;
         // SSG Module Lock Enable
         volatile uint32_t SSGL: 1;
         // Comparator Module Lock Enable
         volatile uint32_t CMPL: 1;
         // Capacitive Sensing Module Lock Enable
         volatile uint32_t CSL: 1;
         // EMIF Module Lock Enable
         volatile uint32_t EMIFL: 1;
         // AES Module Lock Enable
         volatile uint32_t AESL: 1;
         // CRC Module Lock Enable
         volatile uint32_t CRCL: 1;
         // RTC Module Lock Enable
         volatile uint32_t RTCL: 1;
         // Clock Control and Reset Sources Lock Enable
         volatile uint32_t CLKRSTL: 1;
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
         volatile uint32_t VREFL: 1;
         // I2S Module Lock Enable
         volatile uint32_t I2SL: 1;
         // PLL Module Lock Enable
         volatile uint32_t PLLL: 1;
         // External Oscillator Module Lock Enable
         volatile uint32_t EXTOSCL: 1;
         // Voltage Regulator Module Lock Enable
         volatile uint32_t VREGL: 1;
         // Low Power Oscillator Lock Enable
         volatile uint32_t LPOSCL: 1;
         // External Regulator Module Lock Enable
         volatile uint32_t EVREGL: 1;
                  uint32_t reserved0: 1;
         // IVC Module Lock Enable
         volatile uint32_t IVCL: 1;
                  uint32_t reserved1: 3;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LOCK_A_PERIPHLOCK0_USARTL_MASK  0x00000001
#define SI32_LOCK_A_PERIPHLOCK0_USARTL_SHIFT  0
// Unlock the USART0, USART1, UART0, and UART1 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_USARTL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_USARTL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_USARTL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_USARTL_SHIFT)
// Lock the USART0, USART1, UART0, and UART1 Module registers (bits can still be
// read).
#define SI32_LOCK_A_PERIPHLOCK0_USARTL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_USARTL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_USARTL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_USARTL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_SPIL_MASK  0x00000002
#define SI32_LOCK_A_PERIPHLOCK0_SPIL_SHIFT  1
// Unlock the SPI0, SPI1, and SPI2 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_SPIL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_SPIL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_SPIL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_SPIL_SHIFT)
// Lock the SPI0, SPI1, and SPI2 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_SPIL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_SPIL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_SPIL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_SPIL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_I2CL_MASK  0x00000004
#define SI32_LOCK_A_PERIPHLOCK0_I2CL_SHIFT  2
// Unlock the I2C0 and I2C1 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_I2CL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_I2CL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_I2CL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_I2CL_SHIFT)
// Lock the I2C0 and I2C1 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_I2CL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_I2CL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_I2CL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_I2CL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_PCAL_MASK  0x00000008
#define SI32_LOCK_A_PERIPHLOCK0_PCAL_SHIFT  3
// Unlock the EPCA0, PCA0, and PCA1 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_PCAL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_PCAL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_PCAL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_PCAL_SHIFT)
// Lock the EPCA0, PCA0, and PCA1 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_PCAL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_PCAL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_PCAL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_PCAL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_TIMERL_MASK  0x00000010
#define SI32_LOCK_A_PERIPHLOCK0_TIMERL_SHIFT  4
// Unlock the TIMER0 and TIMER1 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_TIMERL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_TIMERL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_TIMERL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_TIMERL_SHIFT)
// Lock the TIMER0 and TIMER1 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_TIMERL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_TIMERL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_TIMERL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_TIMERL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_USBL_MASK  0x00000020
#define SI32_LOCK_A_PERIPHLOCK0_USBL_SHIFT  5
// Unlock the USB0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_USBL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_USBL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_USBL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_USBL_SHIFT)
// Lock the USB0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_USBL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_USBL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_USBL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_USBL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_SARADCL_MASK  0x00000040
#define SI32_LOCK_A_PERIPHLOCK0_SARADCL_SHIFT  6
// Unlock the SARADC0 and SARADC1 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_SARADCL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_SARADCL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_SARADCL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_SARADCL_SHIFT)
// Lock the SARADC0 and SARADC1 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_SARADCL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_SARADCL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_SARADCL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_SARADCL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_SSGL_MASK  0x00000080
#define SI32_LOCK_A_PERIPHLOCK0_SSGL_SHIFT  7
// Unlock the SSG0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_SSGL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_SSGL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_SSGL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_SSGL_SHIFT)
// Lock the SSG0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_SSGL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_SSGL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_SSGL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_SSGL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_CMPL_MASK  0x00000100
#define SI32_LOCK_A_PERIPHLOCK0_CMPL_SHIFT  8
// Unlock the Comparator 0 and Comparator 1 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_CMPL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_CMPL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CMPL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CMPL_SHIFT)
// Lock the Comparator 0 and Comparator 1 Module registers (bits can still be
// read).
#define SI32_LOCK_A_PERIPHLOCK0_CMPL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_CMPL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CMPL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CMPL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_CSL_MASK  0x00000200
#define SI32_LOCK_A_PERIPHLOCK0_CSL_SHIFT  9
// Unlock the Capacitive Sensing (CAPSENSE0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_CSL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_CSL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CSL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CSL_SHIFT)
// Lock the Capacitive Sensing (CAPSENSE0) Module registers (bits can still be
// read).
#define SI32_LOCK_A_PERIPHLOCK0_CSL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_CSL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CSL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CSL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_EMIFL_MASK  0x00000400
#define SI32_LOCK_A_PERIPHLOCK0_EMIFL_SHIFT  10
// Unlock the External Memory Interface (EMIF0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_EMIFL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_EMIFL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_EMIFL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_EMIFL_SHIFT)
// Lock the External Memory Interface (EMIF0) Module registers (bits can still be
// read).
#define SI32_LOCK_A_PERIPHLOCK0_EMIFL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_EMIFL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_EMIFL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_EMIFL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_AESL_MASK  0x00000800
#define SI32_LOCK_A_PERIPHLOCK0_AESL_SHIFT  11
// Unlock the AES0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_AESL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_AESL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_AESL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_AESL_SHIFT)
// Lock the AES0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_AESL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_AESL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_AESL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_AESL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_CRCL_MASK  0x00001000
#define SI32_LOCK_A_PERIPHLOCK0_CRCL_SHIFT  12
// Unlock the CRC0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_CRCL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_CRCL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CRCL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CRCL_SHIFT)
// Lock the CRC0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_CRCL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_CRCL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CRCL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CRCL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_RTCL_MASK  0x00002000
#define SI32_LOCK_A_PERIPHLOCK0_RTCL_SHIFT  13
// Unlock the RTC0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_RTCL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_RTCL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_RTCL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_RTCL_SHIFT)
// Lock the RTC0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_RTCL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_RTCL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_RTCL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_RTCL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_CLKRSTL_MASK  0x00004000
#define SI32_LOCK_A_PERIPHLOCK0_CLKRSTL_SHIFT  14
// Unlock the Clock Control (CLKCTRL) and Reset Sources (RSTSRC) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_CLKRSTL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_CLKRSTL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CLKRSTL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CLKRSTL_SHIFT)
// Lock the Clock Control (CLKCTRL) and Reset Sources (RSTSRC) Module registers
// (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_CLKRSTL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_CLKRSTL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_CLKRSTL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_CLKRSTL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_VMONL_MASK  0x00008000
#define SI32_LOCK_A_PERIPHLOCK0_VMONL_SHIFT  15
// Unlock the Voltage Supply Monitor (VMON0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_VMONL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_VMONL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_VMONL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_VMONL_SHIFT)
// Lock the Voltage Supply Monitor (VMON0) Module registers (bits can still be
// read).
#define SI32_LOCK_A_PERIPHLOCK0_VMONL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_VMONL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_VMONL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_VMONL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_IDACL_MASK  0x00010000
#define SI32_LOCK_A_PERIPHLOCK0_IDACL_SHIFT  16
// Unlock the IDAC0 and IDAC1 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_IDACL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_IDACL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_IDACL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_IDACL_SHIFT)
// Lock the IDAC0 and IDAC1 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_IDACL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_IDACL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_IDACL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_IDACL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_MASK  0x00020000
#define SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_SHIFT  17
// Unlock the DMA Controller (DMACTRL0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_SHIFT)
// Lock the DMA Controller (DMACTRL0) Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_DMACTRLL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_MASK  0x00040000
#define SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_SHIFT  18
// Unlock the DMA Crossbar (DMAXBAR0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_SHIFT)
// Lock the DMA Crossbar (DMAXBAR0) Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_DMAXBARL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_LPTL_MASK  0x00080000
#define SI32_LOCK_A_PERIPHLOCK0_LPTL_SHIFT  19
// Unlock the Low Power Timer (LPTIMER0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_LPTL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_LPTL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_LPTL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_LPTL_SHIFT)
// Lock the Low Power Timer (LPTIMER0) Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_LPTL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_LPTL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_LPTL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_LPTL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_VREFL_MASK  0x00100000
#define SI32_LOCK_A_PERIPHLOCK0_VREFL_SHIFT  20
// Unlock the Voltage Reference (VREF0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_VREFL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_VREFL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_VREFL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_VREFL_SHIFT)
// Lock the Voltage Reference (VREF0) Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_VREFL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_VREFL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_VREFL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_VREFL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_I2SL_MASK  0x00200000
#define SI32_LOCK_A_PERIPHLOCK0_I2SL_SHIFT  21
// Unlock the I2S0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_I2SL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_I2SL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_I2SL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_I2SL_SHIFT)
// Lock the I2S0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_I2SL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_I2SL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_I2SL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_I2SL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_PLLL_MASK  0x00400000
#define SI32_LOCK_A_PERIPHLOCK0_PLLL_SHIFT  22
// Unlock the PLL0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_PLLL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_PLLL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_PLLL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_PLLL_SHIFT)
// Lock the PLL0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_PLLL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_PLLL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_PLLL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_PLLL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_MASK  0x00800000
#define SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_SHIFT  23
// Unlock the External Oscillator (EXTOSC0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_SHIFT)
// Lock the External Oscillator (EXTOSC0) Module registers (bits can still be
// read).
#define SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_EXTOSCL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_VREGL_MASK  0x01000000
#define SI32_LOCK_A_PERIPHLOCK0_VREGL_SHIFT  24
// Unlock the Voltage Regulator (VREG0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_VREGL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_VREGL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_VREGL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_VREGL_SHIFT)
// Lock the Voltage Regulator (VREG0) Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_VREGL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_VREGL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_VREGL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_VREGL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_LPOSCL_MASK  0x02000000
#define SI32_LOCK_A_PERIPHLOCK0_LPOSCL_SHIFT  25
// Unlock the Low Power Oscillator (LPOSC0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_LPOSCL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_LPOSCL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_LPOSCL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_LPOSCL_SHIFT)
// Lock the Low Power Oscillator (LPOSC0) Module registers (bits can still be
// read).
#define SI32_LOCK_A_PERIPHLOCK0_LPOSCL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_LPOSCL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_LPOSCL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_LPOSCL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_EVREGL_MASK  0x04000000
#define SI32_LOCK_A_PERIPHLOCK0_EVREGL_SHIFT  26
// Unlock the External Regulator (EXTVREG0) Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_EVREGL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_EVREGL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_EVREGL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_EVREGL_SHIFT)
// Lock the External Regulator (EXTVREG0) Module registers (bits can still be
// read).
#define SI32_LOCK_A_PERIPHLOCK0_EVREGL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_EVREGL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_EVREGL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_EVREGL_SHIFT)

#define SI32_LOCK_A_PERIPHLOCK0_IVCL_MASK  0x10000000
#define SI32_LOCK_A_PERIPHLOCK0_IVCL_SHIFT  28
// Unlock the IVC0 Module registers.
#define SI32_LOCK_A_PERIPHLOCK0_IVCL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK0_IVCL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_IVCL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_IVCL_SHIFT)
// Lock the IVC0 Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK0_IVCL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK0_IVCL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK0_IVCL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK0_IVCL_SHIFT)



struct SI32_LOCK_A_PERIPHLOCK1_Struct
{
   union
   {
      struct
      {
         // PMU Module Lock Enable
         volatile uint32_t PMUL: 1;
                  uint32_t reserved0: 31;
      };
      volatile uint32_t U32;
   };
};

#define SI32_LOCK_A_PERIPHLOCK1_PMUL_MASK  0x00000001
#define SI32_LOCK_A_PERIPHLOCK1_PMUL_SHIFT  0
// Unlock the PMU Module registers.
#define SI32_LOCK_A_PERIPHLOCK1_PMUL_UNLOCKED_VALUE  0
#define SI32_LOCK_A_PERIPHLOCK1_PMUL_UNLOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK1_PMUL_UNLOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK1_PMUL_SHIFT)
// Lock the PMU Module registers (bits can still be read).
#define SI32_LOCK_A_PERIPHLOCK1_PMUL_LOCKED_VALUE  1
#define SI32_LOCK_A_PERIPHLOCK1_PMUL_LOCKED_U32 \
   (SI32_LOCK_A_PERIPHLOCK1_PMUL_LOCKED_VALUE << SI32_LOCK_A_PERIPHLOCK1_PMUL_SHIFT)



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

