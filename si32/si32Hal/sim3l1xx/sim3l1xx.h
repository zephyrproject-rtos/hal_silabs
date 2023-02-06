
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

#ifndef __SIM3L1XX_H__
#define __SIM3L1XX_H__

#ifdef __cplusplus
extern "C" {
#endif

#define __MPU_PRESENT             0
#define __NVIC_PRIO_BITS          4
#define __Vendor_SysTickConfig    0

typedef enum IRQn
{
  // CPU
  NonMaskableInt_IRQn   = -14, // 2
  MemoryManagement_IRQn = -12, // 4
  BusFault_IRQn         = -11, // 5
  UsageFault_IRQn       = -10, // 6
  SVCall_IRQn           = -5,  // 11
  DebugMonitor_IRQn     = -4,  // 12
  PendSV_IRQn           = -2,  // 14
  SysTick_IRQn          = -1,  // 15
  // MCU
  WDTIMER0_IRQn         = 0,
  PBEXT0_IRQn           = 1,
  PBEXT1_IRQn           = 2,
  RTC0ALRM_IRQn         = 3,
  LPTIMER0_IRQn         = 4,
  DMAERR_IRQn           = 5,
  DMACH0_IRQn           = 6,
  DMACH1_IRQn           = 7,
  DMACH2_IRQn           = 8,
  DMACH3_IRQn           = 9,
  DMACH4_IRQn           = 10,
  DMACH5_IRQn           = 11,
  DMACH6_IRQn           = 12,
  DMACH7_IRQn           = 13,
  DMACH8_IRQn           = 14,
  DMACH9_IRQn           = 15,
  TIMER0L_IRQn          = 16,
  TIMER0H_IRQn          = 17,
  TIMER1L_IRQn          = 18,
  TIMER1H_IRQn          = 19,
  TIMER2L_IRQn          = 20,
  TIMER2H_IRQn          = 21,
  ACCTR0_IRQn           = 22,
  EPCA0_IRQn            = 23,
  USART0_IRQn           = 24,
  UART0_IRQn            = 25,
  SPI0_IRQn             = 26,
  SPI1_IRQn             = 27,
  I2C0_IRQn             = 28,
  SARADC0_IRQn          = 29,
  CMP0_IRQn             = 30,
  CMP1_IRQn             = 31,
  DTM0_IRQn             = 32,
  DTM1_IRQn             = 33,
  DTM2_IRQn             = 34,
  AES0_IRQn             = 35,
  ENCDEC0_IRQn          = 36,
  RTC0FAIL_IRQn         = 37,
  VDDLOW_IRQn           = 38,
  CPFAIL_IRQn           = 39,
  DCDC0_IRQn            = 40,
  PMATCH_IRQn           = 41,
  IDAC0_IRQn            = 42,
  PLL0_IRQn             = 43,
} IRQn_Type;

//----------------------------------------------------------------------------
// WARNING: DCDC_IRQn IS DEPRECATED AS OF si32-1.1.1. NOT FOR NEW DESIGN.
// SUPERCEDED BY DCDC0_IRQn
//-----------------------------------------------------------------------------
#define DCDC_IRQn DCDC0_IRQn


#include <core_cm3.h>
#include <system_sim3l1xx.h>

//-----------------------------------------------------------------------------

#include <SI32_ACCTR_A_Registers.h>
#include <SI32_AES_B_Registers.h>
#include <SI32_CMP_A_Registers.h>
#include <SI32_ECRC_A_Registers.h>
#include <SI32_DCDC_A_Registers.h>
#include <SI32_DMACTRL_A_Registers.h>
#include <SI32_DMADESC_A_Registers.h>
#include <SI32_DTM_A_Registers.h>
#include <SI32_ENCDEC_A_Registers.h>
#include <SI32_EPCA_A_Registers.h>
#include <SI32_EPCACH_A_Registers.h>
#include <SI32_EXTOSC_A_Registers.h>
#include <SI32_FLASHCTRL_A_Registers.h>
#include <SI32_I2C_A_Registers.h>
#include <SI32_IDAC_A_Registers.h>
#include <SI32_LCD_A_Registers.h>
#include <SI32_LPTIMER_B_Registers.h>
#include <SI32_PLL_A_Registers.h>
#include <SI32_PVTOSC_A_Registers.h>
#include <SI32_RTC_B_Registers.h>
#include <SI32_SARADC_A_Registers.h>
#include <SI32_SPI_B_Registers.h>
#include <SI32_TIMER_A_Registers.h>
#include <SI32_UART_B_Registers.h>
#include <SI32_USART_B_Registers.h>
#include <SI32_VMON_B_Registers.h>
#include <SI32_VREF_B_Registers.h>
#include <SI32_WDTIMER_A_Registers.h>

#include <SI32_SIM3L1XX_CLKCTRL_A_Registers.h>
#include <SI32_SIM3L1XX_DEVICEID_A_Registers.h>
#include <SI32_SIM3L1XX_DMAXBAR_A_Registers.h>
#include <SI32_SIM3L1XX_LDO_A_Registers.h>
#include <SI32_SIM3L1XX_LOCK_A_Registers.h>
#include <SI32_SIM3L1XX_PBCFG_A_Registers.h>
#include <SI32_SIM3L1XX_PBSTD_A_Registers.h>
#include <SI32_SIM3L1XX_PBGP_A_Registers.h>
#include <SI32_SIM3L1XX_PMU_A_Registers.h>
#include <SI32_SIM3L1XX_RSTSRC_A_Registers.h>
#include <SI32_SIM3L1XX_SCONFIG_A_Registers.h>

//-----------------------------------------------------------------------------
// Define constants for the chip's memory regions.
#define SI32_MCU_FLASH_BASE             0x00000000
#define SI32_MCU_RAM_BASE               0x20000000

#if defined(SI32_MCU_SIM3L16X)
# define SI32_MCU_FLASH_SIZE            0x0003FFFC
# define SI32_MCU_RAM_SIZE              0x00008000
#elif defined(SI32_MCU_SIM3L15X)
# define SI32_MCU_FLASH_SIZE            0x00020000
# define SI32_MCU_RAM_SIZE              0x00004000
#elif defined(SI32_MCU_SIM3L14X)
# define SI32_MCU_FLASH_SIZE            0x00010000
# define SI32_MCU_RAM_SIZE              0x00002000
#else //defined(SI32_MCU_SIM3L13X)
# define SI32_MCU_FLASH_SIZE            0x00008000
# define SI32_MCU_RAM_SIZE              0x00002000
#endif

#define SI32_MCU_RETENTION_RAM_BASE     SI32_MCU_RAM_BASE
#define SI32_MCU_RETENTION_RAM_SIZE     SI32_MCU_RAM_SIZE

//------------------------------------------------------------------------------
// ARM RealView
#if defined (__CC_ARM)

#define __SI32_RETENTION_REGION __attribute__ ((section(".SI32.RETENTION"), zero_init))

//------------------------------------------------------------------------------
// IAR
#elif defined (__ICCARM__)

#define __SI32_RETENTION_REGION _Pragma("location=\".SI32.RETENTION\"")

//------------------------------------------------------------------------------
// GCC
#elif defined (__GNUC__)

#define __SI32_RETENTION_REGION __attribute__ ((section(".bss.$RESERVED")))

#endif

//-----------------------------------------------------------------------------
// Define the instances of the peripherals

// USART
#define SI32_USART_0 ((SI32_USART_B_Type*)0x40000000)
// UART
#define SI32_UART_0 ((SI32_UART_B_Type*)0x40001000)

// SPI
#define SI32_SPI_0 ((SI32_SPI_B_Type*)0x40004000)
#define SI32_SPI_1 ((SI32_SPI_B_Type*)0x40005000)

// I2C
#define SI32_I2C_0 ((SI32_I2C_A_Type*)0x40009000)

// PCAE
#define SI32_EPCA_0     ((SI32_EPCA_A_Type*)  0x4000E180)
#define SI32_EPCA_0_CH0 ((SI32_EPCACH_A_Type*)0x4000E000)
#define SI32_EPCA_0_CH1 ((SI32_EPCACH_A_Type*)0x4000E040)
#define SI32_EPCA_0_CH2 ((SI32_EPCACH_A_Type*)0x4000E080)
#define SI32_EPCA_0_CH3 ((SI32_EPCACH_A_Type*)0x4000E0C0)
#define SI32_EPCA_0_CH4 ((SI32_EPCACH_A_Type*)0x4000E100)
#define SI32_EPCA_0_CH5 ((SI32_EPCACH_A_Type*)0x4000E140)

// Timers
#define SI32_TIMER_0 ((SI32_TIMER_A_Type*)0x40014000)
#define SI32_TIMER_1 ((SI32_TIMER_A_Type*)0x40015000)
#define SI32_TIMER_2 ((SI32_TIMER_A_Type*)0x40016000)

// ADCs
#define SI32_SARADC_0 ((SI32_SARADC_A_Type*)0x4001A000)

// Comparator
#define SI32_CMP_0 ((SI32_CMP_A_Type*)0x4001F000)
#define SI32_CMP_1 ((SI32_CMP_A_Type*)0x40020000)

// AES
#define SI32_AES_0 ((SI32_AES_B_Type*)0x40027000)

// ECRC
#define SI32_ECRC_0 ((SI32_ECRC_A_Type*)0x40028000)

// RTC and LFO
#define SI32_RTC_0 ((SI32_RTC_B_Type*)0x40029000)

// Port I/O
#define SI32_PBCFG_0 ((SI32_PBCFG_A_Type*)0x4002A000)
#define SI32_PBSTD_0 ((SI32_PBSTD_A_Type*)0x4002A0A0)
#define SI32_PBSTD_1 ((SI32_PBSTD_A_Type*)0x4002A140)
#define SI32_PBSTD_2 ((SI32_PBSTD_A_Type*)0x4002A1E0)
#define SI32_PBSTD_3 ((SI32_PBSTD_A_Type*)0x4002A280)
#define SI32_PBGP_4 ((SI32_PBGP_A_Type*)0x4002A320)

// Reset Sources
#define SI32_RSTSRC_0 ((SI32_RSTSRC_A_Type*)0x4002C000)

// Clock Control
#define SI32_CLKCTRL_0 ((SI32_CLKCTRL_A_Type*)0x4002D000)

// Flash Interface
#define SI32_FLASHCTRL_0 ((SI32_FLASHCTRL_A_Type*)0x4002E000)

// VDD Monitor
#define SI32_VMON_0 ((SI32_VMON_B_Type*)0x4002F000)

// Watchdog Timer
#define SI32_WDTIMER_0 ((SI32_WDTIMER_A_Type*)0x40030000)

// DACs
#define SI32_IDAC_0 ((SI32_IDAC_A_Type*)0x40031000)

// DMA Controller
#define SI32_DMACTRL_0 ((SI32_DMACTRL_A_Type*)0x40036000)

// DMA Crossbar
#define SI32_DMAXBAR_0 ((SI32_DMAXBAR_A_Type*)0x40037000)

// Low Power Timer
#define SI32_LPTIMER_0 ((SI32_LPTIMER_B_Type*)0x40038000)

// LDO
#define SI32_LDO_0 ((SI32_LDO_A_Type*)0x40039000)

// VREF
#define SI32_VREF_0 ((SI32_VREF_B_Type*)0x40039010)

// Sleep Control
#define SI32_SLEEPCTRL_0 ((SI32_SLEEPCTRL_A_Type*)0x4003A000)

// PLL
#define SI32_PLL_0 ((SI32_PLL_A_Type*)0x4003B000)

// Advanced Capture Counter
#define SI32_ACCTR_0 ((SI32_ACCTR_A_Type*)0x40042000)

// Oscillators
#define SI32_EXTOSC_0 ((SI32_EXTOSC_A_Type*)0x4003C000)
#define SI32_LPOSC_0  ((SI32_LPOSC_A_Type*) 0x40041000)
#define SI32_PVTOSC_0 ((SI32_PVTOSC_A_Type*)0x4003D000)

// PMU
#define SI32_PMU_0 ((SI32_PMU_A_Type*)0x40048000)

// Lock
#define SI32_LOCK_0 ((SI32_LOCK_A_Type*)0x40049000)

// System Configuration
#define SI32_SCONFIG_0 ((SI32_SCONFIG_A_Type*)0x400490B0)

// Device ID
#define SI32_DEVICEID_0 ((SI32_DEVICEID_A_Type*)0x400490C0)

// Data Transfer Manager
#define SI32_DTM_0 ((SI32_DTM_A_Type*)0x4004A000)
#define SI32_DTM_1 ((SI32_DTM_A_Type*)0x4004B000)
#define SI32_DTM_2 ((SI32_DTM_A_Type*)0x4004C000)

// LCD
#define SI32_LCD_0 ((SI32_LCD_A_Type*)0x4004D000)

// DC DC Converter
#define SI32_DCDC_0 ((SI32_DCDC_A_Type*)0x4004E000)

// Encoder Decoder
#define SI32_ENCDEC_0 ((SI32_ENCDEC_A_Type*)0x4004F000)

//-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // __SIM3L1XX_H__

//-eof-------------------------------------------------------------------------
