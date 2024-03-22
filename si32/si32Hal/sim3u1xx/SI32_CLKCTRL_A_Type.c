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
/// @file SI32_CLKCTRL_A_Type.c
//
// This file applies to the SIM3U1XX_CLKCTRL_A module
//
// Script: 0.58
// HAL Source: 0.5
// Version: 2

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_CLKCTRL_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_initialize
//
// Writes all CLKCTRL registers.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_initialize(
   SI32_CLKCTRL_A_Type * basePointer,
   uint32_t control,
   uint32_t ahbclkg,
   uint32_t apbclkg0,
   uint32_t apbclkg1,
   uint32_t pm3cn)
{
   //{{
   basePointer->CONTROL.U32 = control;
   basePointer->AHBCLKG.U32 = ahbclkg;
   basePointer->APBCLKG0.U32 = apbclkg0;
   basePointer->APBCLKG1.U32 = apbclkg1;
   basePointer->PM3CN.U32 = pm3cn;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_write_control
//
// Writes CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_write_control(
   SI32_CLKCTRL_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_read_control
//
// Reads CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_CLKCTRL_A_read_control(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_ahb_source_low_power_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_ahb_source_low_power_oscillator(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.AHBSEL =
      SI32_CLKCTRL_A_CONTROL_AHBSEL_LPOSC0_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_ahb_source_low_frequency_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_ahb_source_low_frequency_oscillator(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.AHBSEL =
      SI32_CLKCTRL_A_CONTROL_AHBSEL_LFOSC0_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_ahb_source_rtc_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_ahb_source_rtc_oscillator(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.AHBSEL =
      SI32_CLKCTRL_A_CONTROL_AHBSEL_RTC0OSC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_ahb_source_external_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_ahb_source_external_oscillator(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.AHBSEL =
      SI32_CLKCTRL_A_CONTROL_AHBSEL_EXTOSC0_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_ahb_source_usb_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_ahb_source_usb_oscillator(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.AHBSEL =
      SI32_CLKCTRL_A_CONTROL_AHBSEL_USB0OSC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_ahb_source_pll
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_ahb_source_pll(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.AHBSEL =
      SI32_CLKCTRL_A_CONTROL_AHBSEL_PLL0OSC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_ahb_source_divided_low_power_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_ahb_source_divided_low_power_oscillator(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.AHBSEL =
      SI32_CLKCTRL_A_CONTROL_AHBSEL_LPOSC0_DIV_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_ahb_divider
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_ahb_divider(
   SI32_CLKCTRL_A_Type * basePointer,
   // AHB divide amount is 2 ^ divider (0 = divide by 1, ..., 7 = divide by
   // 128).
   uint32_t divider)
{
   assert((divider >= 0) && (divider <= 7));
   //{{
   basePointer->CONTROL.AHBDIV = divider;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_apb_divider_1
//
// Divides AHB by 1 to create APB.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_apb_divider_1(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.APBDIV =
      SI32_CLKCTRL_A_CONTROL_APBDIV_DIV1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_apb_divider_2
//
// Divides AHB by 2 to create APB.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_apb_divider_2(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.APBDIV =
      SI32_CLKCTRL_A_CONTROL_APBDIV_DIV2_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_external_clock_dual_edge
//
// External clock generated from both edges of external oscillator.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_external_clock_dual_edge(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.EXTESEL =
      SI32_CLKCTRL_A_CONTROL_EXTESEL_BOTH_EDGES_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_external_clock_rising_edge
//
// External clock generated from rising edge of external oscillator.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_external_clock_rising_edge(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL.EXTESEL =
      SI32_CLKCTRL_A_CONTROL_EXTESEL_RISING_ONLY_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_are_system_clocks_busy
//
//-----------------------------------------------------------------------------
bool
_SI32_CLKCTRL_A_are_system_clocks_busy(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.OBUSYF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_write_ahbclkg
//
// Writes AHBCLKG register.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_write_ahbclkg(
   SI32_CLKCTRL_A_Type * basePointer,
   uint32_t ahbclkg)
{
   //{{
   basePointer->AHBCLKG.U32 = ahbclkg;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_read_ahbclkg
//
// Reads AHBCLKG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_CLKCTRL_A_read_ahbclkg(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   return basePointer->AHBCLKG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_enable_ahb_to_ram
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_enable_ahb_to_ram(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->AHBCLKG_SET =
      SI32_CLKCTRL_A_AHBCLKG_RAMCEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_disable_ahb_to_ram
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_disable_ahb_to_ram(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->AHBCLKG_CLR =
      SI32_CLKCTRL_A_AHBCLKG_RAMCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_enable_ahb_to_dma_controller
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_enable_ahb_to_dma_controller(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->AHBCLKG_SET =
      SI32_CLKCTRL_A_AHBCLKG_DMACEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_disable_ahb_to_dma_controller
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_disable_ahb_to_dma_controller(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->AHBCLKG_CLR =
      SI32_CLKCTRL_A_AHBCLKG_DMACEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_enable_ahb_to_flash_controller
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_enable_ahb_to_flash_controller(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->AHBCLKG_SET =
      SI32_CLKCTRL_A_AHBCLKG_FLASHCEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_disable_ahb_to_flash_controller
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_disable_ahb_to_flash_controller(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->AHBCLKG_CLR =
      SI32_CLKCTRL_A_AHBCLKG_FLASHCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_enable_ahb_to_emif
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_enable_ahb_to_emif(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->AHBCLKG_SET =
      SI32_CLKCTRL_A_AHBCLKG_EMIF0CEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_disable_ahb_to_emif
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_disable_ahb_to_emif(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->AHBCLKG_CLR =
      SI32_CLKCTRL_A_AHBCLKG_EMIF0CEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_enable_ahb_to_usb_buffer
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_enable_ahb_to_usb_buffer(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->AHBCLKG_SET =
      SI32_CLKCTRL_A_AHBCLKG_USB0BCEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_disable_ahb_to_usb_buffer
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_disable_ahb_to_usb_buffer(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->AHBCLKG_CLR =
      SI32_CLKCTRL_A_AHBCLKG_USB0BCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_enable_ahb_to_all_modules
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_enable_ahb_to_all_modules(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->AHBCLKG_SET =
      SI32_CLKCTRL_A_AHBCLKG_RAMCEN_ENABLED_U32
      | SI32_CLKCTRL_A_AHBCLKG_DMACEN_ENABLED_U32
      | SI32_CLKCTRL_A_AHBCLKG_FLASHCEN_ENABLED_U32
      | SI32_CLKCTRL_A_AHBCLKG_EMIF0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_AHBCLKG_USB0BCEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_disable_ahb_to_all_modules
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_disable_ahb_to_all_modules(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->AHBCLKG_CLR =
      SI32_CLKCTRL_A_AHBCLKG_RAMCEN_MASK
      | SI32_CLKCTRL_A_AHBCLKG_DMACEN_MASK
      | SI32_CLKCTRL_A_AHBCLKG_FLASHCEN_MASK
      | SI32_CLKCTRL_A_AHBCLKG_EMIF0CEN_MASK
      | SI32_CLKCTRL_A_AHBCLKG_USB0BCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_write_apbclkg0
//
// Writes APBCLKG0 register.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_write_apbclkg0(
   SI32_CLKCTRL_A_Type * basePointer,
   uint32_t apbclkg0)
{
   //{{
   basePointer->APBCLKG0.U32 = apbclkg0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_read_apbclkg0
//
// Reads APBCLKG0 register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_CLKCTRL_A_read_apbclkg0(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   return basePointer->APBCLKG0.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_write_apbclkg1
//
// Writes APBCLKG1 register.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_write_apbclkg1(
   SI32_CLKCTRL_A_Type * basePointer,
   uint32_t apbclkg1)
{
   //{{
   basePointer->APBCLKG1.U32 = apbclkg1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_read_apbclkg1
//
// Reads APBCLKG1 register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_CLKCTRL_A_read_apbclkg1(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   return basePointer->APBCLKG1.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_enable_apb_to_modules_0
//
// Enables APB to any number of modules in APBCLKG0.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_enable_apb_to_modules_0(
   SI32_CLKCTRL_A_Type * basePointer,
   // See Support.h for module mask definitions.
   uint32_t mask)
{
   //{{
   basePointer->APBCLKG0_SET = mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_disable_apb_to_modules_0
//
// Disables APB to any number of modules in APBCLKG0.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_disable_apb_to_modules_0(
   SI32_CLKCTRL_A_Type * basePointer,
   // See Support.h for module mask definitions.
   uint32_t mask)
{
   //{{
   basePointer->APBCLKG0_CLR = mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_enable_apb_to_modules_1
//
// Enables APB to any number of modules in APBCLKG1.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_enable_apb_to_modules_1(
   SI32_CLKCTRL_A_Type * basePointer,
   // See Support.h for module mask definitions.
   uint32_t mask)
{
   //{{
   basePointer->APBCLKG1_SET = mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_disable_apb_to_modules_1
//
// Disables APB to any number of modules in APBCLKG1.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_disable_apb_to_modules_1(
   SI32_CLKCTRL_A_Type * basePointer,
   // See Support.h for module mask definitions.
   uint32_t mask)
{
   //{{
   basePointer->APBCLKG1_CLR = mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_enable_apb_to_all_modules
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_enable_apb_to_all_modules(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->APBCLKG0_SET =
      SI32_CLKCTRL_A_APBCLKG0_PLL0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_PB0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_USART0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_USART1CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_UART0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_UART1CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_SPI0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_SPI1CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_SPI2CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_I2C0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_I2C1CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_EPCA0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_PCA0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_PCA1CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_SSG0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_TIMER0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_TIMER1CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_ADC0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_ADC1CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_CMP0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_CMP1CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_CS0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_AES0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_CRC0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_IDAC0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_IDAC1CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_LPT0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_I2S0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_USB0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_EVREGCEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG0_FLCTRLCEN_ENABLED_U32;

   basePointer->APBCLKG1_SET =
      SI32_CLKCTRL_A_APBCLKG1_MISC0CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG1_MISC1CEN_ENABLED_U32
      | SI32_CLKCTRL_A_APBCLKG1_MISC2CEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_disable_apb_to_all_modules
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_disable_apb_to_all_modules(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->APBCLKG0_CLR =
      SI32_CLKCTRL_A_APBCLKG0_PLL0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_PB0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_USART0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_USART1CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_UART0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_UART1CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_SPI0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_SPI1CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_SPI2CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_I2C0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_I2C1CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_EPCA0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_PCA0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_PCA1CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_SSG0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_TIMER0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_TIMER1CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_ADC0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_ADC1CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_CMP0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_CMP1CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_CS0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_AES0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_CRC0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_IDAC0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_IDAC1CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_LPT0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_I2S0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_USB0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_EVREGCEN_MASK
      | SI32_CLKCTRL_A_APBCLKG0_FLCTRLCEN_MASK;

    basePointer->APBCLKG1_CLR =
      SI32_CLKCTRL_A_APBCLKG1_MISC0CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG1_MISC1CEN_MASK
      | SI32_CLKCTRL_A_APBCLKG1_MISC2CEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_write_pm3cn
//
// Writes PM3CN register.
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_write_pm3cn(
   SI32_CLKCTRL_A_Type * basePointer,
   uint32_t pm3cn)
{
   //{{
   basePointer->PM3CN.U32 = pm3cn;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_read_pm3cn
//
// Reads PM3CN register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_CLKCTRL_A_read_pm3cn(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   return basePointer->PM3CN.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_enter_fast_wake_mode
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_enter_fast_wake_mode(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->PM3CN.PM3CEN =
      SI32_CLKCTRL_A_PM3CN_PM3CEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_exit_fast_wake_mode
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_exit_fast_wake_mode(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->PM3CN.PM3CEN =
      SI32_CLKCTRL_A_PM3CN_PM3CEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_fast_wake_clock_source_low_power_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_low_power_oscillator(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->PM3CN.PM3CSEL =
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_LPOSC0_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_fast_wake_clock_source_low_frequency_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_low_frequency_oscillator(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->PM3CN.PM3CSEL =
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_LFOSC0_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_fast_wake_clock_source_rtc_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_rtc_oscillator(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->PM3CN.PM3CSEL =
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_RTC0OSC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_fast_wake_clock_source_external_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_external_oscillator(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->PM3CN.PM3CSEL =
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_EXTOSC0_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_fast_wake_clock_source_usb_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_usb_oscillator(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->PM3CN.PM3CSEL =
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_USB0OSC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_fast_wake_clock_source_pll
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_pll(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->PM3CN.PM3CSEL =
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_PLL0OSC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CLKCTRL_A_select_fast_wake_clock_source_divided_low_power_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_divided_low_power_oscillator(
   SI32_CLKCTRL_A_Type * basePointer)
{
   //{{
   basePointer->PM3CN.PM3CSEL =
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_LPOSC0_DIV_VALUE;
   //}}
}


//-eof--------------------------------------------------------------------------
