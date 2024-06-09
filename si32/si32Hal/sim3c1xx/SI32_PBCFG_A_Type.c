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
/// @file SI32_PBCFG_A_Type.c
//
// This file applies to the SIM3C1XX_PBCFG_A module
//
// Script: 0.58
// HAL Source: 0.1
// Version: 1

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_PBCFG_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_initialize
//
// Writes to PBCFG registers.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_initialize(
   SI32_PBCFG_A_Type * basePointer,
   uint32_t control0,
   uint32_t control1,
   uint32_t xbar0l,
   uint32_t xbar0h,
   uint32_t xbar1,
   uint32_t pbkey)
{
   //{{
   basePointer->CONTROL0.U32 = control0;
   basePointer->CONTROL1.U32 = control1;
   basePointer->XBAR0L.U32   = xbar0l;
   basePointer->XBAR0H.U32   = xbar0h;
   basePointer->XBAR1.U32    = xbar1;
   basePointer->PBKEY.U32    = pbkey;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_write_control0
//
// Writes CONTROL0 register.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_write_control0(
   SI32_PBCFG_A_Type * basePointer,
   uint32_t control0)
{
   //{{
   basePointer->CONTROL0.U32 = control0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_read_control0
//
// Reads CONTROL0 register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBCFG_A_read_control0(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL0.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_interrupt_0_pin
//
// Selects external pin to use as INT0.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_0_pin(
   SI32_PBCFG_A_Type * basePointer,
   // Pin to use as INT0 (0 = INT0.0, ..., 15 = INT0.15).
   uint32_t source)
{
   assert(source < 16);   // source < 2^4
   //{{
   basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT0SEL_MASK;
   basePointer->CONTROL0_SET =
      source << SI32_PBCFG_A_CONTROL0_INT0SEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_set_interrupt_0_polarity_low
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_set_interrupt_0_polarity_low(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT0POL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_set_interrupt_0_polarity_high
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_set_interrupt_0_polarity_high(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT0POL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_interrupt_0_sensitivity_level
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_0_sensitivity_level(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT0MD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_interrupt_0_sensitivity_edge
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_0_sensitivity_edge(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT0MD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_interrupt_0
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_interrupt_0(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT0EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_interrupt_0
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_interrupt_0(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT0EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_interrupt_1_pin
//
// Selects external pin to use as INT1.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_1_pin(
   SI32_PBCFG_A_Type * basePointer,
   // Pin to use as INT1 (0 = INT1.0, ..., 15 = INT1.15).
   uint32_t source)
{
   assert(source < 16);   // source < 2^4
   //{{
   basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT1SEL_MASK;
   basePointer->CONTROL0_SET =
      source << SI32_PBCFG_A_CONTROL0_INT1SEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_set_interrupt_1_polarity_low
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_set_interrupt_1_polarity_low(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT1POL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_set_interrupt_1_polarity_high
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_set_interrupt_1_polarity_high(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT1POL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_interrupt_1_sensitivity_level
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_1_sensitivity_level(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT1MD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_interrupt_1_sensitivity_edge
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_1_sensitivity_edge(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT1MD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_interrupt_1
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_interrupt_1(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT1EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_interrupt_1
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_interrupt_1(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT1EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_set_pulse_generator_timer
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_set_pulse_generator_timer(
   SI32_PBCFG_A_Type * basePointer,
   uint32_t timer)
{
   assert(timer < 32);   // timer < 2^5
   //{{
   basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_PGTIMER_MASK;
   basePointer->CONTROL0_SET =
      timer << SI32_PBCFG_A_CONTROL0_PGTIMER_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_get_pulse_generator_timer
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBCFG_A_get_pulse_generator_timer(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL0.PGTIMER;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_is_pulse_generator_timer_done
//
//-----------------------------------------------------------------------------
bool
_SI32_PBCFG_A_is_pulse_generator_timer_done(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL0.PGDONEF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_write_control1
//
// Writes CONTROL1 register.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_write_control1(
   SI32_PBCFG_A_Type * basePointer,
   uint32_t control1)
{
   //{{
   basePointer->CONTROL1.U32 = control1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_read_control1
//
// Reads CONTROL1 register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBCFG_A_read_control1(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL1.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_jtag
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_jtag(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_JTAGEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_jtag
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_jtag(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_JTAGEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_etm
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_etm(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_ETMEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_etm
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_etm(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_ETMEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_emif_be0_pin
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_emif_be0_pin(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_EMIFBE0BEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_emif_be0_pin
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_emif_be0_pin(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_EMIFBE0BEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_emif_cs1_pin
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_emif_cs1_pin(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_EMIFCS1EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_emif_cs1_pin
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_emif_cs1_pin(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_EMIFCS1EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_emif
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_emif(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_EMIFEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_emif
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_emif(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_EMIFEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_set_emif_width
//
// Sets the total address lines to addrwidth + 8. 0 = 8 lines, 1 = 9
// lines, 2 = 10 lines, etc.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_set_emif_width(
   SI32_PBCFG_A_Type * basePointer,
   // Range is 8 to 24 address lines.
   uint32_t addrwidth)
{
   assert((addrwidth >= 0) && (addrwidth <= 16));
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_EMIFWIDTH_MASK;
   basePointer->CONTROL1_SET =
      (addrwidth) << SI32_PBCFG_A_CONTROL1_EMIFWIDTH_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_get_emif_width
//
// Returns the number of additional pins allocated to EMIF.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBCFG_A_get_emif_width(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL1.EMIFWIDTH + 8;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_port_match_mode_pin_match
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_port_match_mode_pin_match(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_MATMD_MASK;
   basePointer->CONTROL1_SET =
      SI32_PBCFG_A_CONTROL1_MATMD_PINMATCH_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_port_match_mode_capsense_tx
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_port_match_mode_capsense_tx(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_MATMD_MASK;
   basePointer->CONTROL1_SET =
      SI32_PBCFG_A_CONTROL1_MATMD_CAPSENSE_TX_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_port_match_mode_capsense_rx
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_port_match_mode_capsense_rx(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_MATMD_MASK;
   basePointer->CONTROL1_SET =
      SI32_PBCFG_A_CONTROL1_MATMD_CAPSENSE_RX_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_external_regulator_reset_from_all_sources
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_external_regulator_reset_from_all_sources(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_EVREGRMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_external_regulator_reset_from_power_on
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_external_regulator_reset_from_power_on(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_EVREGRMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_unlock_port_registers
//
// Unlocks write access to CONTROL1, XBAR0L, XBAR0H, XBAR1, and PBSKIP
// registers.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_unlock_port_registers(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_LOCK_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_lock_port_registers
//
// Locks write access to CONTROL1, XBAR0L, XBAR0H, XBAR1, and PBSKIP
// registers.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_lock_port_registers(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_LOCK_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_write_xbar0l
//
// Writes XBAR0L register.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_write_xbar0l(
   SI32_PBCFG_A_Type * basePointer,
   uint32_t xbar0l)
{
   //{{
   basePointer->XBAR0L.U32 = xbar0l;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_read_xbar0l
//
// Reads XBAR0L register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBCFG_A_read_xbar0l(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   return basePointer->XBAR0L.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_xbar0l_peripherals
//
// See Support.h for peripheral definitions.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_xbar0l_peripherals(
   SI32_PBCFG_A_Type * basePointer,
   // Peripherals to enable.
   uint32_t mask)
{
   //{{
   basePointer->XBAR0L_SET = mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_xbar0l_peripherals
//
// See Support.h for peripheral definitions.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_xbar0l_peripherals(
   SI32_PBCFG_A_Type * basePointer,
   // Peripherals to disable.
   uint32_t mask)
{
   //{{
   basePointer->XBAR0L_CLR = mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_xbar0_signal
//
// Enables a signal on crossbar 0.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_xbar0_signal(
   SI32_PBCFG_A_Type * basePointer,
   // See Support.h for signal definitions.
   SI32_PBCFG_A_XBAR0_Enum_Type signal)
{
   assert(signal < 256);   // signal < 2^8
   //{{
   uint32_t n = signal & 0x1F;
   switch (signal & 0xE0)
   {
   case 0x00:
       basePointer->XBAR0L_SET = 1 << n;
       break;
   case 0x20:
       basePointer->XBAR0H_SET = 1 << n;
       break;
   case 0x80:
       basePointer->XBAR0L_CLR = SI32_PBCFG_A_XBAR0L_EPCA0EN_MASK;
       basePointer->XBAR0L_SET = n << SI32_PBCFG_A_XBAR0L_EPCA0EN_SHIFT;
       break;
   case 0xA0:
       basePointer->XBAR0L_CLR = SI32_PBCFG_A_XBAR0L_PCA0EN_MASK;
       basePointer->XBAR0L_SET = n << SI32_PBCFG_A_XBAR0L_PCA0EN_SHIFT;
       break;
   case 0xC0:
       basePointer->XBAR0L_CLR = SI32_PBCFG_A_XBAR0L_PCA1EN_MASK;
       basePointer->XBAR0L_SET = n << SI32_PBCFG_A_XBAR0L_PCA1EN_SHIFT;
       break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_xbar0_signal
//
// Disables a signal on crossbar 0.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_xbar0_signal(
   SI32_PBCFG_A_Type * basePointer,
   // See Support.h for signal definitions.
   SI32_PBCFG_A_XBAR0_Enum_Type signal)
{
   assert(signal < 256);   // signal < 2^8
   //{{
   uint32_t n = signal & 0x1F;
   switch (signal & 0xE0)
   {
   case 0x00:
       basePointer->XBAR0L_CLR = 1 << n;
       break;
   case 0x20:
       basePointer->XBAR0H_CLR = 1 << n;
       break;
   case 0x80:
       basePointer->XBAR0L_CLR = SI32_PBCFG_A_XBAR0L_EPCA0EN_MASK;
       break;
   case 0xA0:
       basePointer->XBAR0L_CLR = SI32_PBCFG_A_XBAR0L_PCA0EN_MASK;
       break;
   case 0xC0:
       basePointer->XBAR0L_CLR = SI32_PBCFG_A_XBAR0L_PCA1EN_MASK;
       break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_write_xbar0h
//
// Writes XBAR0H register.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_write_xbar0h(
   SI32_PBCFG_A_Type * basePointer,
   uint32_t xbar0h)
{
   //{{
   basePointer->XBAR0H.U32 = xbar0h;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_read_xbar0h
//
// Reads XBAR0H register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBCFG_A_read_xbar0h(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   return basePointer->XBAR0H.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_xbar0h_peripherals
//
// See Support.h for peripheral definitions.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_xbar0h_peripherals(
   SI32_PBCFG_A_Type * basePointer,
   // Peripherals to enable.
   uint32_t mask)
{
   //{{
   basePointer->XBAR0H_SET = mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_xbar0h_peripherals
//
// See Support.h for peripheral definitions.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_xbar0h_peripherals(
   SI32_PBCFG_A_Type * basePointer,
   // Peripherals to disable.
   uint32_t mask)
{
   //{{
   basePointer->XBAR0H_CLR = mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_crossbar_0
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_crossbar_0(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->XBAR0H_SET = SI32_PBCFG_A_XBAR0H_XBAR0EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_crossbar_0
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_crossbar_0(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->XBAR0H_CLR = SI32_PBCFG_A_XBAR0H_XBAR0EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_write_xbar1
//
// Writes XBAR1 register.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_write_xbar1(
   SI32_PBCFG_A_Type * basePointer,
   uint32_t xbar1)
{
   //{{
   basePointer->XBAR1.U32 = xbar1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_read_xbar1
//
// Reads XBAR1 register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBCFG_A_read_xbar1(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   return basePointer->XBAR1.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_xbar1_peripherals
//
// See Support.h for peripheral definitions.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_xbar1_peripherals(
   SI32_PBCFG_A_Type * basePointer,
   // Peripherals to enable.
   uint32_t mask)
{
   //{{
   basePointer->XBAR1_SET = mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_xbar1_peripherals
//
// See Support.h for peripheral definitions.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_xbar1_peripherals(
   SI32_PBCFG_A_Type * basePointer,
   // Peripherals to disable.
   uint32_t mask)
{
   //{{
   basePointer->XBAR1_CLR = mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_xbar1_signal
//
// Enables a signal on crossbar 1.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_xbar1_signal(
   SI32_PBCFG_A_Type * basePointer,
   // See Support.h for signal definitions.
   SI32_PBCFG_A_XBAR1_Enum_Type signal)
{
   assert(signal < 256);   // signal < 2^8
   //{{
   uint32_t n = signal & 0x1F;
   if (signal & 0x80)
   {
       basePointer->XBAR1_CLR = SI32_PBCFG_A_XBAR1_SSG0EN_MASK;
       basePointer->XBAR1_SET = n << SI32_PBCFG_A_XBAR1_SSG0EN_SHIFT;
   }
   else
   {
       basePointer->XBAR1_SET = 1 << n;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_xbar1_signal
//
// Disables a signal on crossbar 1.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_xbar1_signal(
   SI32_PBCFG_A_Type * basePointer,
   // See Support.h for signal definitions.
   SI32_PBCFG_A_XBAR1_Enum_Type signal)
{
   assert(signal < 256);   // signal < 2^8
   //{{
   if (signal & 0x80)
   {
       basePointer->XBAR1_CLR = SI32_PBCFG_A_XBAR1_SSG0EN_MASK;
   }
   else
   {
       basePointer->XBAR1_CLR = 1 << (signal & 0x1F);
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_crossbar_1
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_crossbar_1(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->XBAR1_SET = SI32_PBCFG_A_XBAR1_XBAR1EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_crossbar_1
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_crossbar_1(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->XBAR1_CLR = SI32_PBCFG_A_XBAR1_XBAR1EN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_write_pbkey
//
// Writes PBKEY register.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_write_pbkey(
   SI32_PBCFG_A_Type * basePointer,
   uint32_t pbkey)
{
   //{{
   basePointer->PBKEY.U32 = pbkey;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_read_pbkey
//
// Reads PBKEY register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBCFG_A_read_pbkey(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   return basePointer->PBKEY.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_unlock_ports
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_unlock_ports(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   if (basePointer->PBKEY.U32 == SI32_PBCFG_A_PBKEY_KEY_UNLOCKED_U32)
   {
      return;
   }
   if (basePointer->PBKEY.U32 == SI32_PBCFG_A_PBKEY_KEY_INTERMEDIATE_U32)
   {
      basePointer->PBKEY.U32 = 0xF1;
      return;
   }
   if (basePointer->PBKEY.U32 == SI32_PBCFG_A_PBKEY_KEY_LOCKED_U32)
   {
      basePointer->PBKEY.U32 = 0xA5;
      basePointer->PBKEY.U32 = 0xF1;
      return;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_lock_ports
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_lock_ports(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   // Any incorrect sequence value to PBKEY will lock the interface
   basePointer->PBKEY.U32 = 0x00;
   //}}
}


//-eof--------------------------------------------------------------------------
