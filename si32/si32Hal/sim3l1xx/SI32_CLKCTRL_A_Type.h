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
/// @file SI32_CLKCTRL_A_Type.h
//
// This file applies to the SIM3L1XX_CLKCTRL_A module
//
// Script: 0.62
// HAL Source: 0.1
// Version: 1

#ifndef __SI32_CLKCTRL_A_TYPE_H__
#define __SI32_CLKCTRL_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_SIM3L1XX_CLKCTRL_A_Registers.h"
#include "SI32_CLKCTRL_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_CLKCTRL_A_initialize(SI32_CLKCTRL_A_Type* basePointer,
///      uint32_t control,
///      uint32_t ahbclkg,
///      uint32_t apbclkg0,
///      uint32_t apbclkg1,
///      uint32_t pm3cn,
///      uint32_t config)
///
/// @brief
/// Writes all CLKCTRL registers.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
/// @param[in]
///  ahbclkg
///  Valid range is 32 bits.
///
/// @param[in]
///  apbclkg0
///  Valid range is 32 bits.
///
/// @param[in]
///  apbclkg1
///  Valid range is 32 bits.
///
/// @param[in]
///  pm3cn
///  Valid range is 32 bits.
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///
void
_SI32_CLKCTRL_A_initialize(SI32_CLKCTRL_A_Type* /*basePointer*/,
   uint32_t, /*control*/
   uint32_t, /*ahbclkg*/
   uint32_t, /*apbclkg0*/
   uint32_t, /*apbclkg1*/
   uint32_t, /*pm3cn*/
   uint32_t /*config*/);
///
/// @def SI32_CLKCTRL_A_initialize(basePointer, control, ahbclkg, apbclkg0, apbclkg1, pm3cn, config)
#define SI32_CLKCTRL_A_initialize(basePointer, control, ahbclkg, apbclkg0, apbclkg1, pm3cn, config) do{  \
   basePointer->CONTROL.U32 = control;\
   basePointer->AHBCLKG.U32 = ahbclkg;\
   basePointer->APBCLKG0.U32 = apbclkg0;\
   basePointer->APBCLKG1.U32 = apbclkg1;\
   basePointer->PM3CN.U32 = pm3cn;\
   basePointer->CONFIG.U32 = config;\
} while(0)


/// @fn _SI32_CLKCTRL_A_write_control(SI32_CLKCTRL_A_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Writes CONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
void
_SI32_CLKCTRL_A_write_control(SI32_CLKCTRL_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_CLKCTRL_A_write_control(basePointer, control)
#define SI32_CLKCTRL_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_CLKCTRL_A_read_control(SI32_CLKCTRL_A_Type* basePointer)
///
/// @brief
/// Reads CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CLKCTRL_A_read_control(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_read_control(basePointer)
#define SI32_CLKCTRL_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_CLKCTRL_A_select_ahb_source_low_power_oscillator(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_ahb_source_low_power_oscillator(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_ahb_source_low_power_oscillator(basePointer)
#define SI32_CLKCTRL_A_select_ahb_source_low_power_oscillator(basePointer) do{  \
   basePointer->CONTROL.AHBSEL =\
      SI32_CLKCTRL_A_CONTROL_AHBSEL_LPOSC0_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_ahb_source_low_frequency_oscillator(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_ahb_source_low_frequency_oscillator(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_ahb_source_low_frequency_oscillator(basePointer)
#define SI32_CLKCTRL_A_select_ahb_source_low_frequency_oscillator(basePointer) do{  \
   basePointer->CONTROL.AHBSEL =\
      SI32_CLKCTRL_A_CONTROL_AHBSEL_LFOSC0_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_ahb_source_rtc0tclk(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_ahb_source_rtc0tclk(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_ahb_source_rtc0tclk(basePointer)
#define SI32_CLKCTRL_A_select_ahb_source_rtc0tclk(basePointer) do{  \
   basePointer->CONTROL.AHBSEL =\
      SI32_CLKCTRL_A_CONTROL_AHBSEL_RTC0TCLK_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_ahb_source_external_oscillator(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_ahb_source_external_oscillator(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_ahb_source_external_oscillator(basePointer)
#define SI32_CLKCTRL_A_select_ahb_source_external_oscillator(basePointer) do{  \
   basePointer->CONTROL.AHBSEL =\
      SI32_CLKCTRL_A_CONTROL_AHBSEL_EXTOSC0_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_ahb_source_viorfclock(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_ahb_source_viorfclock(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_ahb_source_viorfclock(basePointer)
#define SI32_CLKCTRL_A_select_ahb_source_viorfclock(basePointer) do{  \
   basePointer->CONTROL.AHBSEL =\
      SI32_CLKCTRL_A_CONTROL_AHBSEL_VIORFCLK_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_ahb_source_pll(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_ahb_source_pll(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_ahb_source_pll(basePointer)
#define SI32_CLKCTRL_A_select_ahb_source_pll(basePointer) do{  \
   basePointer->CONTROL.AHBSEL =\
      SI32_CLKCTRL_A_CONTROL_AHBSEL_PLL0OSC_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_ahb_source_divided_low_power_oscillator(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_ahb_source_divided_low_power_oscillator(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_ahb_source_divided_low_power_oscillator(basePointer)
#define SI32_CLKCTRL_A_select_ahb_source_divided_low_power_oscillator(basePointer) do{  \
   basePointer->CONTROL.AHBSEL =\
      SI32_CLKCTRL_A_CONTROL_AHBSEL_LPOSC0_DIV_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_ahb_divider(SI32_CLKCTRL_A_Type* basePointer,
///      uint32_t divider)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  divider
///  Valid range is 0 to 7.
///  AHB divide amount is 2 ^ divider (0 = divide by 1, ..., 7 = divide by
///  128).
///
void
_SI32_CLKCTRL_A_select_ahb_divider(SI32_CLKCTRL_A_Type* /*basePointer*/,
   uint32_t /*divider*/);
///
/// @def SI32_CLKCTRL_A_select_ahb_divider(basePointer, divider)
#define SI32_CLKCTRL_A_select_ahb_divider(basePointer, divider) \
   (basePointer->CONTROL.AHBDIV = divider)


/// @fn _SI32_CLKCTRL_A_select_apb_divider_1(SI32_CLKCTRL_A_Type* basePointer)
///
/// @brief
/// Divides AHB by 1 to create APB.
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_apb_divider_1(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_apb_divider_1(basePointer)
#define SI32_CLKCTRL_A_select_apb_divider_1(basePointer) do{  \
   basePointer->CONTROL.APBDIV =\
      SI32_CLKCTRL_A_CONTROL_APBDIV_DIV1_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_apb_divider_2(SI32_CLKCTRL_A_Type* basePointer)
///
/// @brief
/// Divides AHB by 2 to create APB.
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_apb_divider_2(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_apb_divider_2(basePointer)
#define SI32_CLKCTRL_A_select_apb_divider_2(basePointer) do{  \
   basePointer->CONTROL.APBDIV =\
      SI32_CLKCTRL_A_CONTROL_APBDIV_DIV2_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_external_clock_dual_edge(SI32_CLKCTRL_A_Type* basePointer)
///
/// @brief
/// External clock generated from both edges of external oscillator.
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_external_clock_dual_edge(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_external_clock_dual_edge(basePointer)
#define SI32_CLKCTRL_A_select_external_clock_dual_edge(basePointer) do{  \
   basePointer->CONTROL.EXTESEL =\
      SI32_CLKCTRL_A_CONTROL_EXTESEL_BOTH_EDGES_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_external_clock_rising_edge(SI32_CLKCTRL_A_Type* basePointer)
///
/// @brief
/// External clock generated from rising edge of external oscillator.
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_external_clock_rising_edge(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_external_clock_rising_edge(basePointer)
#define SI32_CLKCTRL_A_select_external_clock_rising_edge(basePointer) do{  \
   basePointer->CONTROL.EXTESEL =\
      SI32_CLKCTRL_A_CONTROL_EXTESEL_RISING_ONLY_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_are_system_clocks_busy(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_CLKCTRL_A_are_system_clocks_busy(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_are_system_clocks_busy(basePointer)
#define SI32_CLKCTRL_A_are_system_clocks_busy(basePointer) \
((bool)(basePointer->CONTROL.OBUSYF))


/// @fn _SI32_CLKCTRL_A_enable_viorfclk_in(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_enable_viorfclk_in(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_enable_viorfclk_in(basePointer)
#define SI32_CLKCTRL_A_enable_viorfclk_in(basePointer) do{  \
   basePointer->CONTROL.U32 |=\
      SI32_CLKCTRL_A_CONTROL_VIORFCLKEN_ENABLED_U32;\
} while(0)


/// @fn _SI32_CLKCTRL_A_disable_viorfclk_in(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_disable_viorfclk_in(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_disable_viorfclk_in(basePointer)
#define SI32_CLKCTRL_A_disable_viorfclk_in(basePointer) do{  \
   basePointer->CONTROL.U32 &=\
      ~SI32_CLKCTRL_A_CONTROL_VIORFCLKEN_ENABLED_U32;\
} while(0)


/// @fn _SI32_CLKCTRL_A_enable_extosc_in(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_enable_extosc_in(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_enable_extosc_in(basePointer)
#define SI32_CLKCTRL_A_enable_extosc_in(basePointer) do{  \
   basePointer->CONTROL.U32 |=\
      SI32_CLKCTRL_A_CONTROL_EXTOSCEN_ENABLED_U32;\
} while(0)


/// @fn _SI32_CLKCTRL_A_disable_extosc_in(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_disable_extosc_in(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_disable_extosc_in(basePointer)
#define SI32_CLKCTRL_A_disable_extosc_in(basePointer) do{  \
   basePointer->CONTROL.U32 &=\
      ~SI32_CLKCTRL_A_CONTROL_EXTOSCEN_ENABLED_U32;\
} while(0)


/// @fn _SI32_CLKCTRL_A_write_ahbclkg(SI32_CLKCTRL_A_Type* basePointer,
///      uint32_t ahbclkg)
///
/// @brief
/// Writes AHBCLKG register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ahbclkg
///  Valid range is 32 bits.
///
void
_SI32_CLKCTRL_A_write_ahbclkg(SI32_CLKCTRL_A_Type* /*basePointer*/,
   uint32_t /*ahbclkg*/);
///
/// @def SI32_CLKCTRL_A_write_ahbclkg(basePointer, ahbclkg)
#define SI32_CLKCTRL_A_write_ahbclkg(basePointer, ahbclkg) \
   (basePointer->AHBCLKG.U32 = ahbclkg)


/// @fn _SI32_CLKCTRL_A_read_ahbclkg(SI32_CLKCTRL_A_Type* basePointer)
///
/// @brief
/// Reads AHBCLKG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CLKCTRL_A_read_ahbclkg(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_read_ahbclkg(basePointer)
#define SI32_CLKCTRL_A_read_ahbclkg(basePointer) \
(basePointer->AHBCLKG.U32)


/// @fn _SI32_CLKCTRL_A_enable_ahb_to_ram(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_enable_ahb_to_ram(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_enable_ahb_to_ram(basePointer)
#define SI32_CLKCTRL_A_enable_ahb_to_ram(basePointer) do{  \
   basePointer->AHBCLKG_SET =\
      SI32_CLKCTRL_A_AHBCLKG_RAMCEN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_disable_ahb_to_ram(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_disable_ahb_to_ram(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_disable_ahb_to_ram(basePointer)
#define SI32_CLKCTRL_A_disable_ahb_to_ram(basePointer) do{  \
   basePointer->AHBCLKG_CLR =\
      SI32_CLKCTRL_A_AHBCLKG_RAMCEN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_enable_ahb_to_dma_controller(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_enable_ahb_to_dma_controller(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_enable_ahb_to_dma_controller(basePointer)
#define SI32_CLKCTRL_A_enable_ahb_to_dma_controller(basePointer) do{  \
   basePointer->AHBCLKG_SET =\
      SI32_CLKCTRL_A_AHBCLKG_DMACEN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_disable_ahb_to_dma_controller(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_disable_ahb_to_dma_controller(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_disable_ahb_to_dma_controller(basePointer)
#define SI32_CLKCTRL_A_disable_ahb_to_dma_controller(basePointer) do{  \
   basePointer->AHBCLKG_CLR =\
      SI32_CLKCTRL_A_AHBCLKG_DMACEN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_enable_ahb_to_flash_controller(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_enable_ahb_to_flash_controller(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_enable_ahb_to_flash_controller(basePointer)
#define SI32_CLKCTRL_A_enable_ahb_to_flash_controller(basePointer) do{  \
   basePointer->AHBCLKG_SET =\
      SI32_CLKCTRL_A_AHBCLKG_FLASHCEN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_disable_ahb_to_flash_controller(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_disable_ahb_to_flash_controller(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_disable_ahb_to_flash_controller(basePointer)
#define SI32_CLKCTRL_A_disable_ahb_to_flash_controller(basePointer) do{  \
   basePointer->AHBCLKG_CLR =\
      SI32_CLKCTRL_A_AHBCLKG_FLASHCEN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_enable_ahb_to_dtm0(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_enable_ahb_to_dtm0(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_enable_ahb_to_dtm0(basePointer)
#define SI32_CLKCTRL_A_enable_ahb_to_dtm0(basePointer) do{  \
   basePointer->AHBCLKG_SET =\
      SI32_CLKCTRL_A_AHBCLKG_DTM0EN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_disable_ahb_to_dtm0(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_disable_ahb_to_dtm0(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_disable_ahb_to_dtm0(basePointer)
#define SI32_CLKCTRL_A_disable_ahb_to_dtm0(basePointer) do{  \
   basePointer->AHBCLKG_CLR =\
      SI32_CLKCTRL_A_AHBCLKG_DTM0EN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_enable_ahb_to_dtm1(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_enable_ahb_to_dtm1(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_enable_ahb_to_dtm1(basePointer)
#define SI32_CLKCTRL_A_enable_ahb_to_dtm1(basePointer) do{  \
   basePointer->AHBCLKG_SET =\
      SI32_CLKCTRL_A_AHBCLKG_DTM1EN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_disable_ahb_to_dtm1(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_disable_ahb_to_dtm1(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_disable_ahb_to_dtm1(basePointer)
#define SI32_CLKCTRL_A_disable_ahb_to_dtm1(basePointer) do{  \
   basePointer->AHBCLKG_CLR =\
      SI32_CLKCTRL_A_AHBCLKG_DTM1EN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_enable_ahb_to_dtm2(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_enable_ahb_to_dtm2(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_enable_ahb_to_dtm2(basePointer)
#define SI32_CLKCTRL_A_enable_ahb_to_dtm2(basePointer) do{  \
   basePointer->AHBCLKG_SET =\
      SI32_CLKCTRL_A_AHBCLKG_DTM2EN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_disable_ahb_to_dtm2(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_disable_ahb_to_dtm2(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_disable_ahb_to_dtm2(basePointer)
#define SI32_CLKCTRL_A_disable_ahb_to_dtm2(basePointer) do{  \
   basePointer->AHBCLKG_CLR =\
      SI32_CLKCTRL_A_AHBCLKG_DTM2EN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_enable_ahb_to_all_modules(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_enable_ahb_to_all_modules(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_enable_ahb_to_all_modules(basePointer)
#define SI32_CLKCTRL_A_enable_ahb_to_all_modules(basePointer) do{  \
   basePointer->AHBCLKG_SET =\
      SI32_CLKCTRL_A_AHBCLKG_RAMCEN_MASK\
      | SI32_CLKCTRL_A_AHBCLKG_DMACEN_MASK\
      | SI32_CLKCTRL_A_AHBCLKG_FLASHCEN_MASK\
      | SI32_CLKCTRL_A_AHBCLKG_DTM0EN_MASK\
      | SI32_CLKCTRL_A_AHBCLKG_DTM1EN_MASK\
      | SI32_CLKCTRL_A_AHBCLKG_DTM2EN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_write_apbclkg0(SI32_CLKCTRL_A_Type* basePointer,
///      uint32_t apbclkg0)
///
/// @brief
/// Writes APBCLKG0 register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  apbclkg0
///  Valid range is 32 bits.
///
void
_SI32_CLKCTRL_A_write_apbclkg0(SI32_CLKCTRL_A_Type* /*basePointer*/,
   uint32_t /*apbclkg0*/);
///
/// @def SI32_CLKCTRL_A_write_apbclkg0(basePointer, apbclkg0)
#define SI32_CLKCTRL_A_write_apbclkg0(basePointer, apbclkg0) \
   (basePointer->APBCLKG0.U32 = apbclkg0)


/// @fn _SI32_CLKCTRL_A_read_apbclkg0(SI32_CLKCTRL_A_Type* basePointer)
///
/// @brief
/// Reads APBCLKG0 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CLKCTRL_A_read_apbclkg0(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_read_apbclkg0(basePointer)
#define SI32_CLKCTRL_A_read_apbclkg0(basePointer) \
(basePointer->APBCLKG0.U32)


/// @fn _SI32_CLKCTRL_A_write_apbclkg1(SI32_CLKCTRL_A_Type* basePointer,
///      uint32_t apbclkg1)
///
/// @brief
/// Writes APBCLKG1 register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  apbclkg1
///  Valid range is 32 bits.
///
void
_SI32_CLKCTRL_A_write_apbclkg1(SI32_CLKCTRL_A_Type* /*basePointer*/,
   uint32_t /*apbclkg1*/);
///
/// @def SI32_CLKCTRL_A_write_apbclkg1(basePointer, apbclkg1)
#define SI32_CLKCTRL_A_write_apbclkg1(basePointer, apbclkg1) \
   (basePointer->APBCLKG1.U32 = apbclkg1)


/// @fn _SI32_CLKCTRL_A_read_apbclkg1(SI32_CLKCTRL_A_Type* basePointer)
///
/// @brief
/// Reads APBCLKG1 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CLKCTRL_A_read_apbclkg1(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_read_apbclkg1(basePointer)
#define SI32_CLKCTRL_A_read_apbclkg1(basePointer) \
(basePointer->APBCLKG1.U32)


/// @fn _SI32_CLKCTRL_A_enable_apb_to_modules_0(SI32_CLKCTRL_A_Type* basePointer,
///      uint32_t mask)
///
/// @brief
/// Enables APB to any number of modules in APBCLKG0.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mask
///  Valid range is 32 bits.
///  See Support.h for module mask definitions.
///
void
_SI32_CLKCTRL_A_enable_apb_to_modules_0(SI32_CLKCTRL_A_Type* /*basePointer*/,
   uint32_t /*mask*/);
///
/// @def SI32_CLKCTRL_A_enable_apb_to_modules_0(basePointer, mask)
#define SI32_CLKCTRL_A_enable_apb_to_modules_0(basePointer, mask) \
   (basePointer->APBCLKG0_SET = mask)


/// @fn _SI32_CLKCTRL_A_disable_apb_to_modules_0(SI32_CLKCTRL_A_Type* basePointer,
///      uint32_t mask)
///
/// @brief
/// Disables APB to any number of modules in APBCLKG0.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mask
///  Valid range is 32 bits.
///  See Support.h for module mask definitions.
///
void
_SI32_CLKCTRL_A_disable_apb_to_modules_0(SI32_CLKCTRL_A_Type* /*basePointer*/,
   uint32_t /*mask*/);
///
/// @def SI32_CLKCTRL_A_disable_apb_to_modules_0(basePointer, mask)
#define SI32_CLKCTRL_A_disable_apb_to_modules_0(basePointer, mask) \
   (basePointer->APBCLKG0_CLR = mask)


/// @fn _SI32_CLKCTRL_A_enable_apb_to_modules_1(SI32_CLKCTRL_A_Type* basePointer,
///      uint32_t mask)
///
/// @brief
/// Enables APB to any number of modules in APBCLKG1.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mask
///  Valid range is 32 bits.
///  See Support.h for module mask definitions.
///
void
_SI32_CLKCTRL_A_enable_apb_to_modules_1(SI32_CLKCTRL_A_Type* /*basePointer*/,
   uint32_t /*mask*/);
///
/// @def SI32_CLKCTRL_A_enable_apb_to_modules_1(basePointer, mask)
#define SI32_CLKCTRL_A_enable_apb_to_modules_1(basePointer, mask) \
   (basePointer->APBCLKG1_SET = mask)


/// @fn _SI32_CLKCTRL_A_disable_apb_to_modules_1(SI32_CLKCTRL_A_Type* basePointer,
///      uint32_t mask)
///
/// @brief
/// Disables APB to any number of modules in APBCLKG1.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mask
///  Valid range is 32 bits.
///  See Support.h for module mask definitions.
///
void
_SI32_CLKCTRL_A_disable_apb_to_modules_1(SI32_CLKCTRL_A_Type* /*basePointer*/,
   uint32_t /*mask*/);
///
/// @def SI32_CLKCTRL_A_disable_apb_to_modules_1(basePointer, mask)
#define SI32_CLKCTRL_A_disable_apb_to_modules_1(basePointer, mask) \
   (basePointer->APBCLKG1_CLR = mask)


/// @fn _SI32_CLKCTRL_A_enable_apb_to_all_modules(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_enable_apb_to_all_modules(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_enable_apb_to_all_modules(basePointer)
#define SI32_CLKCTRL_A_enable_apb_to_all_modules(basePointer) do{  \
   basePointer->APBCLKG0_SET =\
      SI32_CLKCTRL_A_APBCLKG0_PLL0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_ENCDEC0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_DCDC0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_LCD0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_DTM2CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_DTM1CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_DTM0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_ACCTR0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_LPT0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_IDAC0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_CRC0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_AES0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_CMP1CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_CMP0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_ADC0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_TIMER2CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_TIMER1CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_TIMER0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_EPCA0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_I2C0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_SPI1CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_SPI0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_UART0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_USART0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_PB0CEN_MASK\
	  | SI32_CLKCTRL_A_APBCLKG0_FLCTRLCEN_MASK;\
\
   basePointer->APBCLKG1_SET =\
      SI32_CLKCTRL_A_APBCLKG1_MISC0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG1_MISC1CEN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_disable_apb_to_all_modules(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_disable_apb_to_all_modules(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_disable_apb_to_all_modules(basePointer)
#define SI32_CLKCTRL_A_disable_apb_to_all_modules(basePointer) do{  \
      basePointer->APBCLKG0_CLR =\
      SI32_CLKCTRL_A_APBCLKG0_PLL0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_ENCDEC0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_DCDC0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_LCD0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_DTM2CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_DTM1CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_DTM0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_ACCTR0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_LPT0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_IDAC0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_CRC0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_AES0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_CMP1CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_CMP0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_ADC0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_TIMER2CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_TIMER1CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_TIMER0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_EPCA0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_I2C0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_SPI1CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_SPI0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_UART0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_USART0CEN_MASK\
      | SI32_CLKCTRL_A_APBCLKG0_PB0CEN_MASK\
	  | SI32_CLKCTRL_A_APBCLKG0_FLCTRLCEN_MASK;\
\
       basePointer->APBCLKG1_CLR =\
         SI32_CLKCTRL_A_APBCLKG1_MISC0CEN_MASK\
         | SI32_CLKCTRL_A_APBCLKG1_MISC1CEN_MASK;\
} while(0)


/// @fn _SI32_CLKCTRL_A_write_pm3cn(SI32_CLKCTRL_A_Type* basePointer,
///      uint32_t pm3cn)
///
/// @brief
/// Writes PM3CN register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pm3cn
///  Valid range is 32 bits.
///
void
_SI32_CLKCTRL_A_write_pm3cn(SI32_CLKCTRL_A_Type* /*basePointer*/,
   uint32_t /*pm3cn*/);
///
/// @def SI32_CLKCTRL_A_write_pm3cn(basePointer, pm3cn)
#define SI32_CLKCTRL_A_write_pm3cn(basePointer, pm3cn) \
   (basePointer->PM3CN.U32 = pm3cn)


/// @fn _SI32_CLKCTRL_A_read_pm3cn(SI32_CLKCTRL_A_Type* basePointer)
///
/// @brief
/// Reads PM3CN register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CLKCTRL_A_read_pm3cn(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_read_pm3cn(basePointer)
#define SI32_CLKCTRL_A_read_pm3cn(basePointer) \
(basePointer->PM3CN.U32)


/// @fn _SI32_CLKCTRL_A_enter_fast_wake_mode(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_enter_fast_wake_mode(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_enter_fast_wake_mode(basePointer)
#define SI32_CLKCTRL_A_enter_fast_wake_mode(basePointer) do{  \
   basePointer->PM3CN.PM3CEN =\
      SI32_CLKCTRL_A_PM3CN_PM3CEN_ENABLED_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_exit_fast_wake_mode(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_exit_fast_wake_mode(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_exit_fast_wake_mode(basePointer)
#define SI32_CLKCTRL_A_exit_fast_wake_mode(basePointer) do{  \
   basePointer->PM3CN.PM3CEN =\
      SI32_CLKCTRL_A_PM3CN_PM3CEN_DISABLED_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_fast_wake_clock_source_low_power_oscillator(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_low_power_oscillator(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_fast_wake_clock_source_low_power_oscillator(basePointer)
#define SI32_CLKCTRL_A_select_fast_wake_clock_source_low_power_oscillator(basePointer) do{  \
   basePointer->PM3CN.PM3CSEL =\
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_LPOSC0_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_fast_wake_clock_source_low_frequency_oscillator(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_low_frequency_oscillator(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_fast_wake_clock_source_low_frequency_oscillator(basePointer)
#define SI32_CLKCTRL_A_select_fast_wake_clock_source_low_frequency_oscillator(basePointer) do{  \
   basePointer->PM3CN.PM3CSEL =\
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_LFOSC0_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_fast_wake_clock_source_rtc0tclk(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_rtc0tclk(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_fast_wake_clock_source_rtc0tclk(basePointer)
#define SI32_CLKCTRL_A_select_fast_wake_clock_source_rtc0tclk(basePointer) do{  \
   basePointer->PM3CN.PM3CSEL =\
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_RTC0TCLK_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_fast_wake_clock_source_external_oscillator(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_external_oscillator(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_fast_wake_clock_source_external_oscillator(basePointer)
#define SI32_CLKCTRL_A_select_fast_wake_clock_source_external_oscillator(basePointer) do{  \
   basePointer->PM3CN.PM3CSEL =\
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_EXTOSC0_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_fast_wake_clock_source_viorfclk(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_viorfclk(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_fast_wake_clock_source_viorfclk(basePointer)
#define SI32_CLKCTRL_A_select_fast_wake_clock_source_viorfclk(basePointer) do{  \
   basePointer->PM3CN.PM3CSEL =\
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_VIORFCLK_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_fast_wake_clock_source_pll(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_pll(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_fast_wake_clock_source_pll(basePointer)
#define SI32_CLKCTRL_A_select_fast_wake_clock_source_pll(basePointer) do{  \
   basePointer->PM3CN.PM3CSEL =\
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_PLL0OSC_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_select_fast_wake_clock_source_divided_low_power_oscillator(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_select_fast_wake_clock_source_divided_low_power_oscillator(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_select_fast_wake_clock_source_divided_low_power_oscillator(basePointer)
#define SI32_CLKCTRL_A_select_fast_wake_clock_source_divided_low_power_oscillator(basePointer) do{  \
   basePointer->PM3CN.PM3CSEL =\
      SI32_CLKCTRL_A_PM3CN_PM3CSEL_LPOSC0_DIV_VALUE;\
} while(0)


/// @fn _SI32_CLKCTRL_A_write_config(SI32_CLKCTRL_A_Type* basePointer,
///      uint32_t config)
///
/// @brief
/// Writes CONFIG register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///
void
_SI32_CLKCTRL_A_write_config(SI32_CLKCTRL_A_Type* /*basePointer*/,
   uint32_t /*config*/);
///
/// @def SI32_CLKCTRL_A_write_config(basePointer, config)
#define SI32_CLKCTRL_A_write_config(basePointer, config) \
   (basePointer->CONFIG.U32 = config)


/// @fn _SI32_CLKCTRL_A_read_config(SI32_CLKCTRL_A_Type* basePointer)
///
/// @brief
/// Reads CONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CLKCTRL_A_read_config(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_read_config(basePointer)
#define SI32_CLKCTRL_A_read_config(basePointer) \
(basePointer->CONFIG.U32)


/// @fn _SI32_CLKCTRL_A_enable_power_mode_8(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_enable_power_mode_8(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_enable_power_mode_8(basePointer)
#define SI32_CLKCTRL_A_enable_power_mode_8(basePointer) \
   (basePointer->CONFIG_SET = SI32_CLKCTRL_A_CONFIG_PMSEL_PM8_EN_U32)


/// @fn _SI32_CLKCTRL_A_disable_power_mode_8(SI32_CLKCTRL_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CLKCTRL_A_disable_power_mode_8(SI32_CLKCTRL_A_Type* /*basePointer*/);
///
/// @def SI32_CLKCTRL_A_disable_power_mode_8(basePointer)
#define SI32_CLKCTRL_A_disable_power_mode_8(basePointer) \
   (basePointer->CONFIG_CLR = SI32_CLKCTRL_A_CONFIG_PMSEL_MASK)



#ifdef __cplusplus
}
#endif

#endif // __SI32_CLKCTRL_A_TYPE_H__

//-eof--------------------------------------------------------------------------
