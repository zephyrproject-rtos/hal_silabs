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
/// @file SI32_PBCFG_A_Type.h
//
// This file applies to the SIM3L1XX_PBCFG_A module
//
// Script: 0.59
// HAL Source: 0.1
// Version: 1

#ifndef __SI32_PBCFG_A_TYPE_H__
#define __SI32_PBCFG_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_SIM3L1XX_PBCFG_A_Registers.h"

// support definitions
#include "SI32_PBCFG_A_Support.h"


#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_PBCFG_A_initialize(SI32_PBCFG_A_Type* basePointer,
///      uint32_t control0,
///      uint32_t control1,
///      uint32_t xbar0,
///      uint32_t pbkey)
///
/// @brief
/// Writes to PBCFG registers.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control0
///  Valid range is 32 bits.
///
/// @param[in]
///  control1
///  Valid range is 32 bits.
///
/// @param[in]
///  xbar0
///  Valid range is 32 bits.
///
/// @param[in]
///  pbkey
///  Valid range is 32 bits.
///
void
_SI32_PBCFG_A_initialize(SI32_PBCFG_A_Type* /*basePointer*/,
   uint32_t, /*control0*/
   uint32_t, /*control1*/
   uint32_t, /*xbar0*/
   uint32_t /*pbkey*/);
///
/// @def SI32_PBCFG_A_initialize(basePointer, control0, control1, xbar0, pbkey)
#define SI32_PBCFG_A_initialize(basePointer, control0, control1, xbar0, pbkey) do{  \
   basePointer->CONTROL0.U32 = control0;\
   basePointer->CONTROL1.U32 = control1;\
   basePointer->XBAR0.U32    = xbar0;\
   basePointer->PBKEY.U32    = pbkey;\
} while(0)


/// @fn _SI32_PBCFG_A_write_control0(SI32_PBCFG_A_Type* basePointer,
///      uint32_t control0)
///
/// @brief
/// Writes CONTROL0 register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control0
///  Valid range is 32 bits.
///
void
_SI32_PBCFG_A_write_control0(SI32_PBCFG_A_Type* /*basePointer*/,
   uint32_t /*control0*/);
///
/// @def SI32_PBCFG_A_write_control0(basePointer, control0)
#define SI32_PBCFG_A_write_control0(basePointer, control0) \
   (basePointer->CONTROL0.U32 = control0)


/// @fn _SI32_PBCFG_A_read_control0(SI32_PBCFG_A_Type* basePointer)
///
/// @brief
/// Reads CONTROL0 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBCFG_A_read_control0(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_read_control0(basePointer)
#define SI32_PBCFG_A_read_control0(basePointer) \
(basePointer->CONTROL0.U32)


/// @fn _SI32_PBCFG_A_select_interrupt_0_pin(SI32_PBCFG_A_Type* basePointer,
///      uint32_t source)
///
/// @brief
/// Selects external pin to use as INT0.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  source
///  Valid range is 4 bits.
///  Pin to use as INT0 (0 = INT0.0, ..., 15 = INT0.15).
///
void
_SI32_PBCFG_A_select_interrupt_0_pin(SI32_PBCFG_A_Type* /*basePointer*/,
   uint32_t /*source*/);
///
/// @def SI32_PBCFG_A_select_interrupt_0_pin(basePointer, source)
#define SI32_PBCFG_A_select_interrupt_0_pin(basePointer, source) do{  \
   basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT0SEL_MASK;\
   basePointer->CONTROL0_SET =\
      source << SI32_PBCFG_A_CONTROL0_INT0SEL_SHIFT;\
} while(0)


/// @fn _SI32_PBCFG_A_set_interrupt_0_polarity_low(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_set_interrupt_0_polarity_low(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_set_interrupt_0_polarity_low(basePointer)
#define SI32_PBCFG_A_set_interrupt_0_polarity_low(basePointer) \
   (basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT0POL_MASK)


/// @fn _SI32_PBCFG_A_set_interrupt_0_polarity_high(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_set_interrupt_0_polarity_high(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_set_interrupt_0_polarity_high(basePointer)
#define SI32_PBCFG_A_set_interrupt_0_polarity_high(basePointer) \
   (basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT0POL_MASK)


/// @fn _SI32_PBCFG_A_select_interrupt_0_level_mode(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_select_interrupt_0_level_mode(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_select_interrupt_0_level_mode(basePointer)
#define SI32_PBCFG_A_select_interrupt_0_level_mode(basePointer) \
   (basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT0MD_MASK)


/// @fn _SI32_PBCFG_A_select_interrupt_0_rising_edge_mode(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_select_interrupt_0_rising_edge_mode(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_select_interrupt_0_rising_edge_mode(basePointer)
#define SI32_PBCFG_A_select_interrupt_0_rising_edge_mode(basePointer) do{  \
	basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT0MD_EDGE_U32 | \
		SI32_PBCFG_A_CONTROL0_INT0POL_HIGH_U32;\
} while(0)


/// @fn _SI32_PBCFG_A_select_interrupt_0_falling_edge_mode(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_select_interrupt_0_falling_edge_mode(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_select_interrupt_0_falling_edge_mode(basePointer)
#define SI32_PBCFG_A_select_interrupt_0_falling_edge_mode(basePointer) do{  \
	basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT0MD_EDGE_U32;\
	basePointer->CONTROL0_CLR =	SI32_PBCFG_A_CONTROL0_INT0POL_MASK;\
} while(0)


/// @fn _SI32_PBCFG_A_select_interrupt_0_dual_edge_mode(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_select_interrupt_0_dual_edge_mode(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_select_interrupt_0_dual_edge_mode(basePointer)
#define SI32_PBCFG_A_select_interrupt_0_dual_edge_mode(basePointer) \
   (basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT0MD_DUAL_EDGE_U32)


/// @fn _SI32_PBCFG_A_enable_interrupt_0(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_enable_interrupt_0(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_enable_interrupt_0(basePointer)
#define SI32_PBCFG_A_enable_interrupt_0(basePointer) \
   (basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT0EN_MASK)


/// @fn _SI32_PBCFG_A_disable_interrupt_0(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_disable_interrupt_0(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_disable_interrupt_0(basePointer)
#define SI32_PBCFG_A_disable_interrupt_0(basePointer) \
   (basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT0EN_MASK)


/// @fn _SI32_PBCFG_A_select_interrupt_1_pin(SI32_PBCFG_A_Type* basePointer,
///      uint32_t source)
///
/// @brief
/// Selects external pin to use as INT1.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  source
///  Valid range is 4 bits.
///  Pin to use as INT1 (0 = INT1.0, ..., 15 = INT1.15).
///
void
_SI32_PBCFG_A_select_interrupt_1_pin(SI32_PBCFG_A_Type* /*basePointer*/,
   uint32_t /*source*/);
///
/// @def SI32_PBCFG_A_select_interrupt_1_pin(basePointer, source)
#define SI32_PBCFG_A_select_interrupt_1_pin(basePointer, source) do{  \
   basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT1SEL_MASK;\
   basePointer->CONTROL0_SET =\
      source << SI32_PBCFG_A_CONTROL0_INT1SEL_SHIFT;\
} while(0)


/// @fn _SI32_PBCFG_A_set_interrupt_1_polarity_low(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_set_interrupt_1_polarity_low(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_set_interrupt_1_polarity_low(basePointer)
#define SI32_PBCFG_A_set_interrupt_1_polarity_low(basePointer) \
   (basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT1POL_MASK)


/// @fn _SI32_PBCFG_A_set_interrupt_1_polarity_high(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_set_interrupt_1_polarity_high(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_set_interrupt_1_polarity_high(basePointer)
#define SI32_PBCFG_A_set_interrupt_1_polarity_high(basePointer) \
   (basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT1POL_MASK)


/// @fn _SI32_PBCFG_A_select_interrupt_1_level_mode(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_select_interrupt_1_level_mode(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_select_interrupt_1_level_mode(basePointer)
#define SI32_PBCFG_A_select_interrupt_1_level_mode(basePointer) \
   (basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT1MD_MASK)


/// @fn _SI32_PBCFG_A_select_interrupt_1_rising_edge_mode(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_select_interrupt_1_rising_edge_mode(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_select_interrupt_1_rising_edge_mode(basePointer)
#define SI32_PBCFG_A_select_interrupt_1_rising_edge_mode(basePointer) do{  \
	basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT1MD_EDGE_U32 | \
		SI32_PBCFG_A_CONTROL0_INT1POL_HIGH_U32;\
} while(0)


/// @fn _SI32_PBCFG_A_select_interrupt_1_falling_edge_mode(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_select_interrupt_1_falling_edge_mode(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_select_interrupt_1_falling_edge_mode(basePointer)
#define SI32_PBCFG_A_select_interrupt_1_falling_edge_mode(basePointer) do{  \
	basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT1MD_EDGE_U32;\
	basePointer->CONTROL0_CLR =	SI32_PBCFG_A_CONTROL0_INT1POL_MASK;\
} while(0)


/// @fn _SI32_PBCFG_A_select_interrupt_1_dual_edge_mode(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_select_interrupt_1_dual_edge_mode(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_select_interrupt_1_dual_edge_mode(basePointer)
#define SI32_PBCFG_A_select_interrupt_1_dual_edge_mode(basePointer) \
   (basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT1MD_DUAL_EDGE_U32)


/// @fn _SI32_PBCFG_A_enable_interrupt_1(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_enable_interrupt_1(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_enable_interrupt_1(basePointer)
#define SI32_PBCFG_A_enable_interrupt_1(basePointer) \
   (basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT1EN_MASK)


/// @fn _SI32_PBCFG_A_disable_interrupt_1(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_disable_interrupt_1(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_disable_interrupt_1(basePointer)
#define SI32_PBCFG_A_disable_interrupt_1(basePointer) \
   (basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT1EN_MASK)


/// @fn _SI32_PBCFG_A_set_pulse_generator_timer(SI32_PBCFG_A_Type* basePointer,
///      uint32_t timer)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  timer
///  Valid range is 5 bits.
///
void
_SI32_PBCFG_A_set_pulse_generator_timer(SI32_PBCFG_A_Type* /*basePointer*/,
   uint32_t /*timer*/);
///
/// @def SI32_PBCFG_A_set_pulse_generator_timer(basePointer, timer)
#define SI32_PBCFG_A_set_pulse_generator_timer(basePointer, timer) do{  \
   basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_PGTIMER_MASK;\
   basePointer->CONTROL0_SET =\
      timer << SI32_PBCFG_A_CONTROL0_PGTIMER_SHIFT;\
} while(0)


/// @fn _SI32_PBCFG_A_get_pulse_generator_timer(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBCFG_A_get_pulse_generator_timer(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_get_pulse_generator_timer(basePointer)
#define SI32_PBCFG_A_get_pulse_generator_timer(basePointer) \
(basePointer->CONTROL0.PGTIMER)


/// @fn _SI32_PBCFG_A_is_pulse_generator_timer_done(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_PBCFG_A_is_pulse_generator_timer_done(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_is_pulse_generator_timer_done(basePointer)
#define SI32_PBCFG_A_is_pulse_generator_timer_done(basePointer) \
((bool)(basePointer->CONTROL0.PGDONEF))


/// @fn _SI32_PBCFG_A_write_control1(SI32_PBCFG_A_Type* basePointer,
///      uint32_t control1)
///
/// @brief
/// Writes CONTROL1 register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control1
///  Valid range is 32 bits.
///
void
_SI32_PBCFG_A_write_control1(SI32_PBCFG_A_Type* /*basePointer*/,
   uint32_t /*control1*/);
///
/// @def SI32_PBCFG_A_write_control1(basePointer, control1)
#define SI32_PBCFG_A_write_control1(basePointer, control1) \
   (basePointer->CONTROL1.U32 = control1)


/// @fn _SI32_PBCFG_A_read_control1(SI32_PBCFG_A_Type* basePointer)
///
/// @brief
/// Reads CONTROL1 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBCFG_A_read_control1(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_read_control1(basePointer)
#define SI32_PBCFG_A_read_control1(basePointer) \
(basePointer->CONTROL1.U32)


/// @fn _SI32_PBCFG_A_enable_jtag(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_enable_jtag(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_enable_jtag(basePointer)
#define SI32_PBCFG_A_enable_jtag(basePointer) \
   (basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_JTAGEN_MASK)


/// @fn _SI32_PBCFG_A_disable_jtag(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_disable_jtag(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_disable_jtag(basePointer)
#define SI32_PBCFG_A_disable_jtag(basePointer) \
   (basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_JTAGEN_MASK)


/// @fn _SI32_PBCFG_A_enable_etm(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_enable_etm(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_enable_etm(basePointer)
#define SI32_PBCFG_A_enable_etm(basePointer) \
   (basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_ETMEN_MASK)


/// @fn _SI32_PBCFG_A_disable_etm(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_disable_etm(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_disable_etm(basePointer)
#define SI32_PBCFG_A_disable_etm(basePointer) \
   (basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_ETMEN_MASK)


/// @fn _SI32_PBCFG_A_enable_swv(SI32_PBCFG_A_Type* basePointer)
///
/// @brief
/// Enable Serial Wire Viewer output on PB0.11.
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_enable_swv(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_enable_swv(basePointer)
#define SI32_PBCFG_A_enable_swv(basePointer) \
   (basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_SWVEN_MASK)


/// @fn _SI32_PBCFG_A_disable_swv(SI32_PBCFG_A_Type* basePointer)
///
/// @brief
/// Disconnect SWV function from port pin.
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_disable_swv(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_disable_swv(basePointer)
#define SI32_PBCFG_A_disable_swv(basePointer) \
   (basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_SWVEN_MASK)


/// @fn _SI32_PBCFG_A_enable_spi1_on_crossbar(SI32_PBCFG_A_Type* basePointer)
///
/// @brief
/// Dedicates the following pins for SPI1: PB2.0 - CTS, PB2.4 - SCK1,
/// PB2.5 - MISO1, PB2.6 - MOSI1, PB2.7 -NSS1.
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_enable_spi1_on_crossbar(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_enable_spi1_on_crossbar(basePointer)
#define SI32_PBCFG_A_enable_spi1_on_crossbar(basePointer) \
   (basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_SPI1SEL_MASK)


/// @fn _SI32_PBCFG_A_disable_spi1_on_crossbar(SI32_PBCFG_A_Type* basePointer)
///
/// @brief
/// Allows pins PB2.0, PB2.4, PB2.5, PB2.6, PB2.7 to be used by the
/// crossbar for other peripherals or GPIO.
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_disable_spi1_on_crossbar(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_disable_spi1_on_crossbar(basePointer)
#define SI32_PBCFG_A_disable_spi1_on_crossbar(basePointer) \
   (basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_SPI1SEL_MASK)


/// @fn _SI32_PBCFG_A_enable_port_match_interrupt(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_enable_port_match_interrupt(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_enable_port_match_interrupt(basePointer)
#define SI32_PBCFG_A_enable_port_match_interrupt(basePointer) \
   (basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_PMATCHEN_MASK)


/// @fn _SI32_PBCFG_A_disable_port_match_interrupt(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_disable_port_match_interrupt(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_disable_port_match_interrupt(basePointer)
#define SI32_PBCFG_A_disable_port_match_interrupt(basePointer) \
   (basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_PMATCHEN_MASK)


/// @fn _SI32_PBCFG_A_enable_low_power_timer_output0(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_enable_low_power_timer_output0(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @defSI32_PBCFG_A_enable_low_power_timer_output0(basePointer)
#define SI32_PBCFG_A_enable_low_power_timer_output0(basePointer) \
	(basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_LPTOSEL_MASK)


/// @fn _SI32_PBCFG_A_enable_low_power_timer_output1(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_enable_low_power_timer_output1(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_enable_low_power_timer_output1(basePointer)
#define SI32_PBCFG_A_enable_low_power_timer_output1(basePointer) \
	(basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_LPTOSEL_MASK)


/// @fn _SI32_PBCFG_A_unlock_port_registers(SI32_PBCFG_A_Type* basePointer)
///
/// @brief
/// Unlocks write access to CONTROL1, XBAR0, and PBSKIP registers.
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_unlock_port_registers(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_unlock_port_registers(basePointer)
#define SI32_PBCFG_A_unlock_port_registers(basePointer) \
   (basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_LOCK_MASK)


/// @fn _SI32_PBCFG_A_lock_port_registers(SI32_PBCFG_A_Type* basePointer)
///
/// @brief
/// Locks write access to CONTROL1, XBAR0, and PBSKIP registers.
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_lock_port_registers(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_lock_port_registers(basePointer)
#define SI32_PBCFG_A_lock_port_registers(basePointer) \
   (basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_LOCK_MASK)


/// @fn _SI32_PBCFG_A_write_xbar0(SI32_PBCFG_A_Type* basePointer,
///      uint32_t xbar0)
///
/// @brief
/// Writes XBAR0 register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  xbar0
///  Valid range is 32 bits.
///
void
_SI32_PBCFG_A_write_xbar0(SI32_PBCFG_A_Type* /*basePointer*/,
   uint32_t /*xbar0*/);
///
/// @def SI32_PBCFG_A_write_xbar0(basePointer, xbar0)
#define SI32_PBCFG_A_write_xbar0(basePointer, xbar0) \
   (basePointer->XBAR0.U32 = xbar0)


/// @fn _SI32_PBCFG_A_read_xbar0(SI32_PBCFG_A_Type* basePointer)
///
/// @brief
/// Reads XBAR0 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBCFG_A_read_xbar0(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_read_xbar0(basePointer)
#define SI32_PBCFG_A_read_xbar0(basePointer) \
(basePointer->XBAR0.U32)


/// @fn _SI32_PBCFG_A_enable_xbar0_peripherals(SI32_PBCFG_A_Type* basePointer,
///      uint32_t mask)
///
/// @brief
/// See Support.h for peripheral definitions.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mask
///  Valid range is 32 bits.
///  Peripherals to enable.
///
void
_SI32_PBCFG_A_enable_xbar0_peripherals(SI32_PBCFG_A_Type* /*basePointer*/,
   uint32_t /*mask*/);
///
/// @def SI32_PBCFG_A_enable_xbar0_peripherals(basePointer, mask)
#define SI32_PBCFG_A_enable_xbar0_peripherals(basePointer, mask) \
   (basePointer->XBAR0_SET = mask)


/// @fn _SI32_PBCFG_A_disable_xbar0_peripherals(SI32_PBCFG_A_Type* basePointer,
///      uint32_t mask)
///
/// @brief
/// See Support.h for peripheral definitions.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mask
///  Valid range is 32 bits.
///  Peripherals to disable.
///
void
_SI32_PBCFG_A_disable_xbar0_peripherals(SI32_PBCFG_A_Type* /*basePointer*/,
   uint32_t /*mask*/);
///
/// @def SI32_PBCFG_A_disable_xbar0_peripherals(basePointer, mask)
#define SI32_PBCFG_A_disable_xbar0_peripherals(basePointer, mask) \
   (basePointer->XBAR0_CLR = mask)


/// @fn _SI32_PBCFG_A_enable_xbar0_signal(SI32_PBCFG_A_Type* basePointer,
///      SI32_PBCFG_A_XBAR0_Enum_Type signal)
///
/// @brief
/// Enables a signal on crossbar 0.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  signal
///  Valid range is 8 bits.
///  See Support.h for signal definitions.
///
void
_SI32_PBCFG_A_enable_xbar0_signal(SI32_PBCFG_A_Type* /*basePointer*/,
   SI32_PBCFG_A_XBAR0_Enum_Type /*signal*/);
///
/// @def SI32_PBCFG_A_enable_xbar0_signal(basePointer, signal)
#define SI32_PBCFG_A_enable_xbar0_signal(basePointer, signal) \
   _SI32_PBCFG_A_enable_xbar0_signal(basePointer, signal) 


/// @fn _SI32_PBCFG_A_disable_xbar0_signal(SI32_PBCFG_A_Type* basePointer,
///      SI32_PBCFG_A_XBAR0_Enum_Type signal)
///
/// @brief
/// Disables a signal on crossbar 0.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  signal
///  Valid range is 8 bits.
///  See Support.h for signal definitions.
///
void
_SI32_PBCFG_A_disable_xbar0_signal(SI32_PBCFG_A_Type* /*basePointer*/,
   SI32_PBCFG_A_XBAR0_Enum_Type /*signal*/);
///
/// @def SI32_PBCFG_A_disable_xbar0_signal(basePointer, signal)
#define SI32_PBCFG_A_disable_xbar0_signal(basePointer, signal) \
   _SI32_PBCFG_A_disable_xbar0_signal(basePointer, signal) 


/// @fn _SI32_PBCFG_A_enable_crossbar_0(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_enable_crossbar_0(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_enable_crossbar_0(basePointer)
#define SI32_PBCFG_A_enable_crossbar_0(basePointer) \
   (basePointer->XBAR0_SET = SI32_PBCFG_A_XBAR0_XBAR0EN_MASK)


/// @fn _SI32_PBCFG_A_disable_crossbar_0(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_disable_crossbar_0(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_disable_crossbar_0(basePointer)
#define SI32_PBCFG_A_disable_crossbar_0(basePointer) \
   (basePointer->XBAR0_CLR = SI32_PBCFG_A_XBAR0_XBAR0EN_MASK)


/// @fn _SI32_PBCFG_A_write_pbkey(SI32_PBCFG_A_Type* basePointer,
///      uint32_t pbkey)
///
/// @brief
/// Writes PBKEY register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pbkey
///  Valid range is 32 bits.
///
void
_SI32_PBCFG_A_write_pbkey(SI32_PBCFG_A_Type* /*basePointer*/,
   uint32_t /*pbkey*/);
///
/// @def SI32_PBCFG_A_write_pbkey(basePointer, pbkey)
#define SI32_PBCFG_A_write_pbkey(basePointer, pbkey) \
   (basePointer->PBKEY.U32 = pbkey)


/// @fn _SI32_PBCFG_A_read_pbkey(SI32_PBCFG_A_Type* basePointer)
///
/// @brief
/// Reads PBKEY register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBCFG_A_read_pbkey(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_read_pbkey(basePointer)
#define SI32_PBCFG_A_read_pbkey(basePointer) \
(basePointer->PBKEY.U32)


/// @fn _SI32_PBCFG_A_unlock_ports(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_unlock_ports(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_unlock_ports(basePointer)
#define SI32_PBCFG_A_unlock_ports(basePointer) \
   _SI32_PBCFG_A_unlock_ports(basePointer) 


/// @fn _SI32_PBCFG_A_lock_ports(SI32_PBCFG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBCFG_A_lock_ports(SI32_PBCFG_A_Type* /*basePointer*/);
///
/// @def SI32_PBCFG_A_lock_ports(basePointer)
#define SI32_PBCFG_A_lock_ports(basePointer) \
   (basePointer->PBKEY.U32 = 0x00)



#ifdef __cplusplus
}
#endif

#endif // __SI32_PBCFG_A_TYPE_H__

//-eof--------------------------------------------------------------------------
