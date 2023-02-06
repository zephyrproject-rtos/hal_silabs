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
// This file applies to the SIM3L1XX_PBCFG_A module
//
// Script: 0.59
// HAL Source: 0.1
// Version: 11

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
   uint32_t xbar0,
   uint32_t pbkey)
{
   //{{
   basePointer->CONTROL0.U32 = control0;
   basePointer->CONTROL1.U32 = control1;
   basePointer->XBAR0.U32    = xbar0;
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
// _SI32_PBCFG_A_select_interrupt_0_level_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_0_level_mode(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT0MD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_interrupt_0_rising_edge_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_0_rising_edge_mode(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT0MD_EDGE_U32 | 
		SI32_PBCFG_A_CONTROL0_INT0POL_HIGH_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_interrupt_0_falling_edge_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_0_falling_edge_mode(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT0MD_EDGE_U32;
	basePointer->CONTROL0_CLR =	SI32_PBCFG_A_CONTROL0_INT0POL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_interrupt_0_dual_edge_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_0_dual_edge_mode(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT0MD_DUAL_EDGE_U32;
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
// _SI32_PBCFG_A_select_interrupt_1_level_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_1_level_mode(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL0_CLR = SI32_PBCFG_A_CONTROL0_INT1MD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_interrupt_1_rising_edge_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_1_rising_edge_mode(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT1MD_EDGE_U32 | 
		SI32_PBCFG_A_CONTROL0_INT1POL_HIGH_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_interrupt_1_falling_edge_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_1_falling_edge_mode(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT1MD_EDGE_U32;
	basePointer->CONTROL0_CLR =	SI32_PBCFG_A_CONTROL0_INT1POL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_select_interrupt_1_dual_edge_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_select_interrupt_1_dual_edge_mode(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL0_SET = SI32_PBCFG_A_CONTROL0_INT1MD_DUAL_EDGE_U32;
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
// _SI32_PBCFG_A_enable_swv
//
// Enable Serial Wire Viewer output on PB0.11.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_swv(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_SWVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_swv
//
// Disconnect SWV function from port pin.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_swv(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_SWVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_spi1_on_crossbar
//
// Dedicates the following pins for SPI1: PB2.0 - CTS, PB2.4 - SCK1,
// PB2.5 - MISO1, PB2.6 - MOSI1, PB2.7 -NSS1.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_spi1_on_crossbar(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_SPI1SEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_spi1_on_crossbar
//
// Allows pins PB2.0, PB2.4, PB2.5, PB2.6, PB2.7 to be used by the
// crossbar for other peripherals or GPIO.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_spi1_on_crossbar(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_SPI1SEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_port_match_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_port_match_interrupt(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_PMATCHEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_port_match_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_port_match_interrupt(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_PMATCHEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_low_power_timer_output0
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_low_power_timer_output0(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL1_CLR = SI32_PBCFG_A_CONTROL1_LPTOSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_low_power_timer_output1
//
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_low_power_timer_output1(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL1_SET = SI32_PBCFG_A_CONTROL1_LPTOSEL_MASK;	   
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_unlock_port_registers
//
// Unlocks write access to CONTROL1, XBAR0, and PBSKIP registers.
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
// Locks write access to CONTROL1, XBAR0, and PBSKIP registers.
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
// _SI32_PBCFG_A_write_xbar0
//
// Writes XBAR0 register.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_write_xbar0(
   SI32_PBCFG_A_Type * basePointer,
   uint32_t xbar0)
{
   //{{
   basePointer->XBAR0.U32 = xbar0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_read_xbar0
//
// Reads XBAR0 register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBCFG_A_read_xbar0(
   SI32_PBCFG_A_Type * basePointer)
{
   //{{
   return basePointer->XBAR0.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_enable_xbar0_peripherals
//
// See Support.h for peripheral definitions.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_enable_xbar0_peripherals(
   SI32_PBCFG_A_Type * basePointer,
   // Peripherals to enable.
   uint32_t mask)
{
   //{{
   basePointer->XBAR0_SET = mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBCFG_A_disable_xbar0_peripherals
//
// See Support.h for peripheral definitions.
//-----------------------------------------------------------------------------
void
_SI32_PBCFG_A_disable_xbar0_peripherals(
   SI32_PBCFG_A_Type * basePointer,
   // Peripherals to disable.
   uint32_t mask)
{
   //{{
   basePointer->XBAR0_CLR = mask;
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
   if (signal & 0x80)
   {
       basePointer->XBAR0_CLR = SI32_PBCFG_A_XBAR0_EPCA0EN_MASK;
       basePointer->XBAR0_SET = n << SI32_PBCFG_A_XBAR0_EPCA0EN_SHIFT;
   }
   else
   {
       basePointer->XBAR0_SET = 1 << n;
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
   if (signal & 0x80)
   {
       basePointer->XBAR0_CLR = SI32_PBCFG_A_XBAR0_EPCA0EN_MASK;
   }
   else
   {
       basePointer->XBAR0_CLR = 1 << (signal & 0x1F);
   }
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
   basePointer->XBAR0_SET = SI32_PBCFG_A_XBAR0_XBAR0EN_MASK;
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
   basePointer->XBAR0_CLR = SI32_PBCFG_A_XBAR0_XBAR0EN_MASK;
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
