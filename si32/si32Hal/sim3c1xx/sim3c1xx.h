
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

#ifndef __SIM3C1XX_H__
#define __SIM3C1XX_H__

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
  DMACH0_IRQn           = 4,
  DMACH1_IRQn           = 5,
  DMACH2_IRQn           = 6,
  DMACH3_IRQn           = 7,
  DMACH4_IRQn           = 8,
  DMACH5_IRQn           = 9,
  DMACH6_IRQn           = 10,
  DMACH7_IRQn           = 11,
  DMACH8_IRQn           = 12,
  DMACH9_IRQn           = 13,
  DMACH10_IRQn          = 14,
  DMACH11_IRQn          = 15,
  DMACH12_IRQn          = 16,
  DMACH13_IRQn          = 17,
  DMACH14_IRQn          = 18,
  DMACH15_IRQn          = 19,
  TIMER0L_IRQn          = 20,
  TIMER0H_IRQn          = 21,
  TIMER1L_IRQn          = 22,
  TIMER1H_IRQn          = 23,
  EPCA0_IRQn            = 24,
  PCA0_IRQn             = 25,
  PCA1_IRQn             = 26,
  USART0_IRQn           = 27,
  USART1_IRQn           = 28,
  SPI0_IRQn             = 29,
  SPI1_IRQn             = 30,
  SPI2_IRQn             = 31,
  I2C0_IRQn             = 32,
  I2C1_IRQn             = 33,
  SARADC0_IRQn          = 35,
  SARADC1_IRQn          = 36,
  CMP0_IRQn             = 37,
  CMP1_IRQn             = 38,
  CAPSENSE0_IRQn        = 39,
  I2S0RX_IRQn           = 40,
  I2S0TX_IRQn           = 41,
  AES0_IRQn             = 42,
  VDDLOW_IRQn           = 43,
  RTC0FAIL_IRQn         = 44,
  PMATCH_IRQn           = 45,
  UART0_IRQn            = 46,
  UART1_IRQn            = 47,
  IDAC0_IRQn            = 48,
  IDAC1_IRQn            = 49,
  LPTIMER0_IRQn         = 50,
  PLL0_IRQn             = 51,
  VBUSINVALID_IRQn      = 52,
  VREG0LOW_IRQn         = 53,
} IRQn_Type;

#include <core_cm3.h>
#include <system_sim3c1xx.h>

//-----------------------------------------------------------------------------

#include <SI32_AES_A_Registers.h>
#include <SI32_CAPSENSE_A_Registers.h>
#include <SI32_CMP_A_Registers.h>
#include <SI32_CRC_A_Registers.h>
#include <SI32_DMACTRL_A_Registers.h>
#include <SI32_DMADESC_A_Registers.h>
#include <SI32_EMIF_A_Registers.h>
#include <SI32_EMIFIF_A_Registers.h>
#include <SI32_EPCA_A_Registers.h>
#include <SI32_EPCACH_A_Registers.h>
#include <SI32_EXTOSC_A_Registers.h>
#include <SI32_EXTVREG_A_Registers.h>
#include <SI32_FLASHCTRL_A_Registers.h>
#include <SI32_I2C_A_Registers.h>
#include <SI32_I2S_A_Registers.h>
#include <SI32_IDAC_A_Registers.h>
#include <SI32_IVC_A_Registers.h>
#include <SI32_LPTIMER_A_Registers.h>
#include <SI32_PCA_A_Registers.h>
#include <SI32_PCACH_A_Registers.h>
#include <SI32_PLL_A_Registers.h>
#include <SI32_RTC_A_Registers.h>
#include <SI32_SARADC_A_Registers.h>
#include <SI32_SPI_A_Registers.h>
#include <SI32_SSG_A_Registers.h>
#include <SI32_TIMER_A_Registers.h>
#include <SI32_USART_A_Registers.h>
#include <SI32_UART_A_Registers.h>
#include <SI32_VMON_A_Registers.h>
#include <SI32_VREF_A_Registers.h>
#include <SI32_VREG_A_Registers.h>
#include <SI32_WDTIMER_A_Registers.h>

#include <SI32_SIM3C1XX_CLKCTRL_A_Registers.h>
#include <SI32_SIM3C1XX_DEVICEID_A_Registers.h>
#include <SI32_SIM3C1XX_DMAXBAR_A_Registers.h>
#include <SI32_SIM3C1XX_LDO_A_Registers.h>
#include <SI32_SIM3C1XX_LOCK_A_Registers.h>
#include <SI32_SIM3C1XX_PBCFG_A_Registers.h>
#include <SI32_SIM3C1XX_PBSTD_A_Registers.h>
#include <SI32_SIM3C1XX_PBHD_A_Registers.h>
#include <SI32_SIM3C1XX_PMU_A_Registers.h>
#include <SI32_SIM3C1XX_RSTSRC_A_Registers.h>
#include <SI32_SIM3C1XX_SCONFIG_A_Registers.h>

//-----------------------------------------------------------------------------
// Define constants for the chip's memory regions.
#define SI32_MCU_FLASH_BASE             0x00000000
#define SI32_MCU_RAM_BASE               0x20000000

#if defined(SI32_MCU_SIM3C16X)
# define SI32_MCU_FLASH_SIZE            0x0003FFFC
# define SI32_MCU_RAM_SIZE              0x00008000
#elif defined(SI32_MCU_SIM3C15X)
# define SI32_MCU_FLASH_SIZE            0x00020000
# define SI32_MCU_RAM_SIZE              0x00008000
#elif defined(SI32_MCU_SIM3C14X)
# define SI32_MCU_FLASH_SIZE            0x00010000
# define SI32_MCU_RAM_SIZE              0x00004000
#else //defined(SI32_MCU_SIM3C13X)
# define SI32_MCU_FLASH_SIZE            0x00008000
# define SI32_MCU_RAM_SIZE              0x00002000
#endif

#define SI32_MCU_RETENTION_RAM_BASE     SI32_MCU_RAM_BASE
#define SI32_MCU_RETENTION_RAM_SIZE     0x00001000

#define SI32_MCU_EMIF_CS0_BASE          0x60000000
#define SI32_MCU_EMIF_CS1_BASE          0x68000000
#define SI32_MCU_EMIF_SIZE              0x08000000

//------------------------------------------------------------------------------
// ARM RealView
#if defined (__CC_ARM)

#define __SI32_RETENTION_REGION __attribute__ ((section(".SI32.RETENTION"), zero_init))
#define __SI32_EMIF_CS0_REGION __attribute__ ((section(".SI32.EMIF_CS0")))
#define __SI32_EMIF_CS1_REGION __attribute__ ((section(".SI32.EMIF_CS1")))

//------------------------------------------------------------------------------
// IAR
#elif defined (__ICCARM__)

#define __SI32_RETENTION_REGION _Pragma("location=\".SI32.RETENTION\"")
#define __SI32_EMIF_CS0_REGION _Pragma("location=\".SI32.EMIF_CS0\"")
#define __SI32_EMIF_CS1_REGION _Pragma("location=\".SI32.EMIF_CS1\"")

//------------------------------------------------------------------------------
// GCC
#elif defined (__GNUC__)

#define __SI32_RETENTION_REGION __attribute__ ((section(".bss.$RESERVED")))
#define __SI32_EMIF_CS0_REGION
#define __SI32_EMIF_CS1_REGION

#endif

//-----------------------------------------------------------------------------
// Define the instances of the peripherals

// USART
#define SI32_USART_0 ((SI32_USART_A_Type*)0x40000000)
#define SI32_USART_1 ((SI32_USART_A_Type*)0x40001000)

// UART
#define SI32_UART_0 ((SI32_UART_A_Type*)0x40002000)
#define SI32_UART_1 ((SI32_UART_A_Type*)0x40003000)

// SPI
#define SI32_SPI_0 ((SI32_SPI_A_Type*)0x40004000)
#define SI32_SPI_1 ((SI32_SPI_A_Type*)0x40005000)
#define SI32_SPI_2 ((SI32_SPI_A_Type*)0x40006000)

// I2C
#define SI32_I2C_0 ((SI32_I2C_A_Type*)0x40009000)
#define SI32_I2C_1 ((SI32_I2C_A_Type*)0x4000A000)

// PCAE
#define SI32_EPCA_0     ((SI32_EPCA_A_Type*)  0x4000E180)
#define SI32_EPCA_0_CH0 ((SI32_EPCACH_A_Type*)0x4000E000)
#define SI32_EPCA_0_CH1 ((SI32_EPCACH_A_Type*)0x4000E040)
#define SI32_EPCA_0_CH2 ((SI32_EPCACH_A_Type*)0x4000E080)
#define SI32_EPCA_0_CH3 ((SI32_EPCACH_A_Type*)0x4000E0C0)
#define SI32_EPCA_0_CH4 ((SI32_EPCACH_A_Type*)0x4000E100)
#define SI32_EPCA_0_CH5 ((SI32_EPCACH_A_Type*)0x4000E140)

// PCA
#define SI32_PCA_0     ((SI32_PCA_A_Type*)  0x4000F180)
#define SI32_PCA_0_CH0 ((SI32_PCACH_A_Type*)0x4000F000)
#define SI32_PCA_0_CH1 ((SI32_PCACH_A_Type*)0x4000F040)
#define SI32_PCA_1     ((SI32_PCA_A_Type*)  0x40010180)
#define SI32_PCA_1_CH0 ((SI32_PCACH_A_Type*)0x40010000)
#define SI32_PCA_1_CH1 ((SI32_PCACH_A_Type*)0x40010040)

// Timers
#define SI32_TIMER_0 ((SI32_TIMER_A_Type*)0x40014000)
#define SI32_TIMER_1 ((SI32_TIMER_A_Type*)0x40015000)

// ADCs
#define SI32_SARADC_0 ((SI32_SARADC_A_Type*)0x4001A000)
#define SI32_SARADC_1 ((SI32_SARADC_A_Type*)0x4001B000)

// SSG0
 #define SI32_SSG_0 ((SI32_SSG_A_Type*)0x4001E000)

// Comparator
#define SI32_CMP_0 ((SI32_CMP_A_Type*)0x4001F000)
#define SI32_CMP_1 ((SI32_CMP_A_Type*)0x40020000)

// LDO
#define SI32_LDO_0 ((SI32_LDO_A_Type*)0x40039000)

// VREF
#define SI32_VREF_0 ((SI32_VREF_A_Type*)0x40039010)

// CapSense
#define SI32_CAPSENSE_0 ((SI32_CAPSENSE_A_Type*)0x40023000)

// EMIF
#define SI32_EMIF_0     ((SI32_EMIF_A_Type*)  0x40026000)
#define SI32_EMIF_0_IF0 ((SI32_EMIFIF_A_Type*)0x40026080)
#define SI32_EMIF_0_IF1 ((SI32_EMIFIF_A_Type*)0x40026100)

// AES
#define SI32_AES_0 ((SI32_AES_A_Type*)0x40027000)

// CRC
#define SI32_CRC_0 ((SI32_CRC_A_Type*)0x40028000)

// RTC and LFO
#define SI32_RTC_0 ((SI32_RTC_A_Type*)0x40029000)

// Port I/O
#define SI32_PBCFG_0 ((SI32_PBCFG_A_Type*)0x4002A000)
#define SI32_PBSTD_0 ((SI32_PBSTD_A_Type*)0x4002A0A0)
#define SI32_PBSTD_1 ((SI32_PBSTD_A_Type*)0x4002A140)
#define SI32_PBSTD_2 ((SI32_PBSTD_A_Type*)0x4002A1E0)
#define SI32_PBSTD_3 ((SI32_PBSTD_A_Type*)0x4002A320)
#define SI32_PBHD_4  ((SI32_PBHD_A_Type*) 0x4002A3C0)

// Clock Control
#define SI32_CLKCTRL_0 ((SI32_CLKCTRL_A_Type*)0x4002D000)

// Reset Sources
#define SI32_RSTSRC_0 ((SI32_RSTSRC_A_Type*)0x4002D060)

// Flash Interface
#define SI32_FLASHCTRL_0 ((SI32_FLASHCTRL_A_Type*)0x4002E000)

// VDD Monitor
#define SI32_VMON_0 ((SI32_VMON_A_Type*)0x4002F000)

// Watchdog Timer
#define SI32_WDTIMER_0 ((SI32_WDTIMER_A_Type*)0x40030000)

// DACs
#define SI32_IDAC_0 ((SI32_IDAC_A_Type*)0x40031000)
#define SI32_IDAC_1 ((SI32_IDAC_A_Type*)0x40032000)

// DMA Controller
#define SI32_DMACTRL_0 ((SI32_DMACTRL_A_Type*)0x40036000)

// DMA Crossbar
#define SI32_DMAXBAR_0 ((SI32_DMAXBAR_A_Type*)0x40037000)

// Low Power Timer
#define SI32_LPTIMER_0 ((SI32_LPTIMER_A_Type*)0x40038000)

// Voltage Regulators
#define SI32_VREG_0    ((SI32_VREG_A_Type*)   0x40040000)
#define SI32_EXTVREG_0 ((SI32_EXTVREG_A_Type*)0x40042000)

// I2S
#define SI32_I2S_0 ((SI32_I2S_A_Type*)0x4003A000)

// PLL
#define SI32_PLL_0 ((SI32_PLL_A_Type*)0x4003B000)

// IVC
#define SI32_IVC_0 ((SI32_IVC_A_Type*)0x40044000)

// Oscillators
#define SI32_LPOSC_0  ((SI32_LPOSC_A_Type*) 0x40041000)
#define SI32_EXTOSC_0 ((SI32_EXTOSC_A_Type*)0x4003C000)

// PMU
#define SI32_PMU_0 ((SI32_PMU_A_Type*)0x40048000)

// Lock
#define SI32_LOCK_0 ((SI32_LOCK_A_Type*)0x40049000)

// System Configuration
#define SI32_SCONFIG_0 ((SI32_SCONFIG_A_Type*)0x400490B0)

// Device ID
#define SI32_DEVICEID_0 ((SI32_DEVICEID_A_Type*)0x400490C0)

//-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // __SIM3C1XX_H__

//-eof-------------------------------------------------------------------------

