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
/// @file SI32_PBHD_A_Type.c
//
// This file applies to the SIM3U1XX_PBHD_A module
//
// Script: 0.58
// HAL Source: 0.5
// Version: 4

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_PBHD_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_PBHD_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_initialize(
   SI32_PBHD_A_Type * basePointer,
   // Write to PB register.
   uint32_t pb,
   // Write to PBMDSEL register.
   uint32_t pbmdsel,
   // Write to PBDEN register.
   uint32_t pbden,
   // Write to PBDRV register.
   uint32_t pbdrv,
   // Write to PBILIMIT register.
   uint32_t pbilimit,
   // Write to PBFSEL register.
   uint32_t pbfsel,
   // Write to PBSS register.
   uint32_t pbss,
   // Writes to PBLOCK register.
   uint32_t pblock)
{
   //{{
   basePointer->PB.U32       = pb;
   basePointer->PBMDSEL.U32  = pbmdsel;
   basePointer->PBDEN.U32    = pbden;
   basePointer->PBDRV.U32    = pbdrv;
   basePointer->PBILIMIT.U32 = pbilimit;
   basePointer->PBFSEL.U32   = pbfsel;
   basePointer->PBSS.U32     = pbss;
   basePointer->PBLOCK.U32   = pblock;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_write_pb
//
// Writes to PB register.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_write_pb(
   SI32_PBHD_A_Type * basePointer,
   uint32_t pb)
{
   //{{
   basePointer->PB.U32 = pb;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_read_pb
//
// Reads PB register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBHD_A_read_pb(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   return basePointer->PB.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_write_pins_high
//
// Writes selected pins high.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_write_pins_high(
   SI32_PBHD_A_Type * basePointer,
   // Mask for pin writes : 1 = set pin to high.
   uint32_t pin_mask)
{
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
   basePointer->PB_SET = pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_write_pins_low
//
// Writes selected pins low.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_write_pins_low(
   SI32_PBHD_A_Type * basePointer,
   // Mask for pin writes : 1 = clear pin to low.
   uint32_t pin_mask)
{
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
   basePointer->PB_CLR = pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_write_pins_masked
//
// Write selected pins.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_write_pins_masked(
   SI32_PBHD_A_Type * basePointer,
   // Values for latch.
   uint32_t pin_value,
   // Mask value : 1 = write, 0 = ignore.
   uint32_t pin_mask)
{
   assert(pin_value < 64);   // pin_value < 2^6
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
   basePointer->PB_MSK = (pin_mask<<16)|(pin_value);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_toggle_pins
//
// Toggle selected pins.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_toggle_pins(
   SI32_PBHD_A_Type * basePointer,
   // Mask for pin toggles : 1 = toggle pin.
   uint32_t pin_mask)
{
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
   basePointer->PB_MSK = (pin_mask<<16)|(~(basePointer->PB.U32) & 0xFFFF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_read_pins
//
// Reads PBPIN register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBHD_A_read_pins(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   return (basePointer->PBPIN.U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_read_pin
//
// Reads the state of a single pin.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBHD_A_read_pin(
   SI32_PBHD_A_Type * basePointer,
   // Number of the pin to read : 0 = pin 0.
   uint32_t pin_number)
{
   assert(pin_number < 64);   // pin_number < 2^6
   //{{
   return ((basePointer->PBPIN.U32) >> pin_number) & 1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_write_pbmdsel
//
// Writes to PBMDSEL register.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_write_pbmdsel(
   SI32_PBHD_A_Type * basePointer,
   uint32_t pbmdsel)
{
   //{{
   basePointer->PBMDSEL.U32 = pbmdsel;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_read_pbmdsel
//
// Reads PBMDSEL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBHD_A_read_pbmdsel(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   return basePointer->PBMDSEL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_set_pins_push_pull_output
//
// Sets the pins masked with 1's to digital push-pull.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_set_pins_push_pull_output(
   SI32_PBHD_A_Type * basePointer,
   // Selects which pins to configure digital push-pull.
   uint32_t pin_mask)
{
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
	basePointer->PBMDSEL_SET = pin_mask;
   basePointer->PBDEN_SET =
      pin_mask << SI32_PBHD_A_PBDEN_PBNDEN_SHIFT;
   basePointer->PBDEN_SET =
      pin_mask << SI32_PBHD_A_PBDEN_PBPDEN_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_set_pins_digital_input
//
// Sets the pins masked with 1's to open-drain input.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_set_pins_digital_input(
   SI32_PBHD_A_Type * basePointer,
   // Selects which pins to configure open-drain input.
   uint32_t pin_mask)
{
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
   basePointer->PBMDSEL_SET = pin_mask;
   basePointer->PBDEN_SET =
      pin_mask << SI32_PBHD_A_PBDEN_PBNDEN_SHIFT;
   basePointer->PBDEN_CLR =
      pin_mask << SI32_PBHD_A_PBDEN_PBPDEN_SHIFT;
   basePointer->PB_SET = pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_set_pins_analog
//
// Sets the pins masked with 1's to analog mode.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_set_pins_analog(
   SI32_PBHD_A_Type * basePointer,
   // Selects which pins to configure as analog.
   uint32_t pin_mask)
{
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
   basePointer->PBMDSEL_CLR = pin_mask;
   basePointer->PBDEN_CLR =
      pin_mask << SI32_PBHD_A_PBDEN_PBNDEN_SHIFT;
   basePointer->PBDEN_CLR =
      pin_mask << SI32_PBHD_A_PBDEN_PBPDEN_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_set_pins_weak_pulldown
//
// Sets the pins masked with 1's to weak pulldown.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_set_pins_weak_pulldown(
   SI32_PBHD_A_Type * basePointer,
   // Selects which pins to configure as weak pulldown.
   uint32_t pin_mask)
{
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
   basePointer->PBMDSEL_SET = pin_mask;
   basePointer->PBDEN_SET =
      pin_mask << SI32_PBHD_A_PBDEN_PBPDEN_SHIFT;
   basePointer->PBDEN_CLR =
      pin_mask << SI32_PBHD_A_PBDEN_PBNDEN_SHIFT;
   basePointer->PB_CLR = pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_write_pbden
//
// Writes to PBDEN register.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_write_pbden(
   SI32_PBHD_A_Type * basePointer,
   uint32_t pbden)
{
   //{{
   basePointer->PBDEN.U32 = pbden;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_read_pbden
//
// Read PBDEN register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBHD_A_read_pbden(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   return basePointer->PBDEN.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_enable_n_channel_drivers
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_enable_n_channel_drivers(
   SI32_PBHD_A_Type * basePointer,
   // Each bit corresponds to a pin.
   uint32_t pin_mask)
{
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
   basePointer->PBDEN.PBNDEN |= pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_disable_n_channel_drivers
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_disable_n_channel_drivers(
   SI32_PBHD_A_Type * basePointer,
   // Each bit corresponds to a pin.
   uint32_t pin_mask)
{
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
   basePointer->PBDEN.PBNDEN &= ~pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_enable_p_channel_drivers
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_enable_p_channel_drivers(
   SI32_PBHD_A_Type * basePointer,
   // Each bit corresponds to a pin.
   uint32_t pin_mask)
{
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
   basePointer->PBDEN.PBPDEN |= pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_disable_p_channel_drivers
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_disable_p_channel_drivers(
   SI32_PBHD_A_Type * basePointer,
   // Each bit corresponds to a pin.
   uint32_t pin_mask)
{
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
   basePointer->PBDEN.PBPDEN &= ~pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_write_pbdrv
//
// Writes to PBDRV register.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_write_pbdrv(
   SI32_PBHD_A_Type * basePointer,
   uint32_t pbdrv)
{
   //{{
   basePointer->PBDRV.U32 = pbdrv;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_read_pbdrv
//
// Reads PBDRV register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBHD_A_read_pbdrv(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   return basePointer->PBDRV.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_set_pins_high_drive_strength
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_set_pins_high_drive_strength(
   SI32_PBHD_A_Type * basePointer,
   uint32_t pin_mask)
{
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
   basePointer->PBDRV_SET = pin_mask << SI32_PBHD_A_PBDRV_PBDRV_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_set_pins_low_drive_strength
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_set_pins_low_drive_strength(
   SI32_PBHD_A_Type * basePointer,
   uint32_t pin_mask)
{
   assert(pin_mask < 64);   // pin_mask < 2^6
   //{{
   basePointer->PBDRV_CLR = pin_mask << SI32_PBHD_A_PBDRV_PBDRV_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_enable_pullup_resistors
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_enable_pullup_resistors(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBDRV_SET = SI32_PBHD_A_PBDRV_PBPUEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_disable_pullup_resistors
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_disable_pullup_resistors(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBDRV_CLR = SI32_PBHD_A_PBDRV_PBPUEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_low_power_port_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_low_power_port_mode(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBDRV_SET = SI32_PBHD_A_PBDRV_PBLVMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_normal_power_port_mode
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_normal_power_port_mode(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBDRV_CLR = SI32_PBHD_A_PBDRV_PBLVMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_slew_rate
//
// Select the slew rate for all port pins.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_slew_rate(
   SI32_PBHD_A_Type * basePointer,
   SI32_PBHD_A_Slew_Enum_Type rate)
{
   assert(rate < 4);   // rate < 2^2
   //{{
   basePointer->PBDRV_CLR = SI32_PBHD_A_PBDRV_PBSLEW_MASK;
   basePointer->PBDRV_SET = rate << SI32_PBHD_A_PBDRV_PBSLEW_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_enable_bias
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_enable_bias(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBDRV_SET = SI32_PBHD_A_PBDRV_PBBIASEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_disable_bias
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_disable_bias(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBDRV_CLR = SI32_PBHD_A_PBDRV_PBBIASEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_enable_drivers
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_enable_drivers(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBDRV_SET = SI32_PBHD_A_PBDRV_PBDRVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_disable_drivers
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_disable_drivers(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBDRV_CLR = SI32_PBHD_A_PBDRV_PBDRVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_enable_vddhd_tracking
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_enable_vddhd_tracking(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBDRV_SET = SI32_PBHD_A_PBDRV_PBVTRKEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_disable_vddhd_tracking
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_disable_vddhd_tracking(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBDRV_CLR = SI32_PBHD_A_PBDRV_PBVTRKEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_write_pbilimit
//
// Writes to PBLIMIT register.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_write_pbilimit(
   SI32_PBHD_A_Type * basePointer,
   uint32_t ilimit)
{
   //{{
   basePointer->PBILIMIT.U32 = ilimit;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_read_pbilimit
//
// Read PBILIMIT.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBHD_A_read_pbilimit(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   return basePointer->PBILIMIT.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_enable_pin_current_limit
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_enable_pin_current_limit(
   SI32_PBHD_A_Type * basePointer,
   // Each bit corresponds to a pin.
   uint32_t pins)
{
   assert(pins < 64);   // pins < 2^6
   //{{
   basePointer->PBILIMIT_CLR = SI32_PBHD_A_PBILIMIT_PBILEN_MASK;
   basePointer->PBILIMIT_SET =
      pins << SI32_PBHD_A_PBILIMIT_PBILEN_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_disable_pin_current_limit
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_disable_pin_current_limit(
   SI32_PBHD_A_Type * basePointer,
   // Each bit corresponds to a pin.
   uint32_t pins)
{
   assert(pins < 64);   // pins < 2^6
   //{{
   basePointer->PBILIMIT_CLR =
      pins << SI32_PBHD_A_PBILIMIT_PBILEN_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_nchannel_current_limit
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_nchannel_current_limit(
   SI32_PBHD_A_Type * basePointer,
   // See Electrical Specifications for limit values.
   uint32_t limit)
{
   assert(limit < 16);   // limit < 2^4
   //{{
   basePointer->PBILIMIT_CLR = SI32_PBHD_A_PBILIMIT_NILIMIT_MASK;
   basePointer->PBILIMIT_SET =
      limit << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_pchannel_current_limit
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_pchannel_current_limit(
   SI32_PBHD_A_Type * basePointer,
   // See Electrical Specifications for limit values.
   uint32_t limit)
{
   assert(limit < 16);   // limit < 2^4
   //{{
   basePointer->PBILIMIT_CLR = SI32_PBHD_A_PBILIMIT_PILIMIT_MASK;
   basePointer->PBILIMIT_SET =
      limit << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_write_pbfsel
//
// Writes to PBFSEL register.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_write_pbfsel(
   SI32_PBHD_A_Type * basePointer,
   uint32_t pbfsel)
{
   //{{
   basePointer->PBFSEL.U32 = pbfsel;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_read_pbfsel
//
// Reads PBFSEL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBHD_A_read_pbfsel(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   return basePointer->PBFSEL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_pin0_function
//
// Configure function for PB4.0.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_pin0_function(
   SI32_PBHD_A_Type * basePointer,
   SI32_PBHD_A_Function_Enum_Type function)
{
   assert(function < 4);   // function < 2^2
   //{{
   basePointer->PBFSEL.PB0SEL = function;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_pin1_function
//
// Configure function for PB4.1.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_pin1_function(
   SI32_PBHD_A_Type * basePointer,
   SI32_PBHD_A_Function_Enum_Type function)
{
   assert(function < 4);   // function < 2^2
   //{{
   basePointer->PBFSEL.PB1SEL = function;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_pin2_function
//
// Configure function for PB4.2.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_pin2_function(
   SI32_PBHD_A_Type * basePointer,
   SI32_PBHD_A_Function_Enum_Type function)
{
   assert(function < 4);   // function < 2^2
   //{{
   basePointer->PBFSEL.PB2SEL = function;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_pin3_function
//
// Configure function for PB4.3.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_pin3_function(
   SI32_PBHD_A_Type * basePointer,
   SI32_PBHD_A_Function_Enum_Type function)
{
   assert(function < 4);   // function < 2^2
   //{{
   basePointer->PBFSEL.PB3SEL = function;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_pin4_function
//
// Configure function for PB4.4.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_pin4_function(
   SI32_PBHD_A_Type * basePointer,
   SI32_PBHD_A_Function_Enum_Type function)
{
   assert(function < 4);   // function < 2^2
   //{{
   basePointer->PBFSEL.PB4SEL = function;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_pin5_function
//
// Configure function for PB4.5.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_pin5_function(
   SI32_PBHD_A_Type * basePointer,
   SI32_PBHD_A_Function_Enum_Type function)
{
   assert(function < 8);   // function < 2^3
   //{{
   basePointer->PBFSEL.PB5SEL = function;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_write_pbss
//
// Writes to PBSS register.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_write_pbss(
   SI32_PBHD_A_Type * basePointer,
   uint32_t pbss)
{
   //{{
   basePointer->PBSS.U32 = pbss;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_read_pbss
//
// Reads PBSS register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBHD_A_read_pbss(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   return basePointer->PBSS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_pin0_safe_state
//
// Configure safe state of this pin.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_pin0_safe_state(
   SI32_PBHD_A_Type * basePointer,
   SI32_PBHD_A_Safe_State_Enum_Type safe_state)
{
   assert(safe_state < 4);   // safe_state < 2^2
   //{{
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PB0SSSEL_MASK;
   basePointer->PBSS_SET =
      safe_state << SI32_PBHD_A_PBSS_PB0SSSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_pin1_safe_state
//
// Configure safe state of this pin.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_pin1_safe_state(
   SI32_PBHD_A_Type * basePointer,
   SI32_PBHD_A_Safe_State_Enum_Type safe_state)
{
   assert(safe_state < 4);   // safe_state < 2^2
   //{{
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PB1SSSEL_MASK;
   basePointer->PBSS_SET =
      safe_state << SI32_PBHD_A_PBSS_PB1SSSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_pin2_safe_state
//
// Configure safe state of this pin.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_pin2_safe_state(
   SI32_PBHD_A_Type * basePointer,
   SI32_PBHD_A_Safe_State_Enum_Type safe_state)
{
   assert(safe_state < 4);   // safe_state < 2^2
   //{{
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PB2SSSEL_MASK;
   basePointer->PBSS_SET =
      safe_state << SI32_PBHD_A_PBSS_PB2SSSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_pin3_safe_state
//
// Configure safe state of this pin.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_pin3_safe_state(
   SI32_PBHD_A_Type * basePointer,
   SI32_PBHD_A_Safe_State_Enum_Type safe_state)
{
   assert(safe_state < 4);   // safe_state < 2^2
   //{{
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PB3SSSEL_MASK;
   basePointer->PBSS_SET =
      safe_state << SI32_PBHD_A_PBSS_PB3SSSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_pin4_safe_state
//
// Configure safe state of this pin.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_pin4_safe_state(
   SI32_PBHD_A_Type * basePointer,
   SI32_PBHD_A_Safe_State_Enum_Type safe_state)
{
   assert(safe_state < 4);   // safe_state < 2^2
   //{{
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PB4SSSEL_MASK;
   basePointer->PBSS_SET =
      safe_state << SI32_PBHD_A_PBSS_PB4SSSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_select_pin5_safe_state
//
// Configure safe state of this pin.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_select_pin5_safe_state(
   SI32_PBHD_A_Type * basePointer,
   SI32_PBHD_A_Safe_State_Enum_Type safe_state)
{
   assert(safe_state < 4);   // safe_state < 2^2
   //{{
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PB5SSSEL_MASK;
   basePointer->PBSS_SET =
      safe_state << SI32_PBHD_A_PBSS_PB5SSSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_enter_safe_state
//
// Manually enter safe state.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_enter_safe_state(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBSS_SET = SI32_PBHD_A_PBSS_SSMDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_exit_safe_state
//
// Manually exit safe state.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_exit_safe_state(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_SSMDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_is_port_in_safe_state
//
// Check safe state of PB4.
//-----------------------------------------------------------------------------
bool
_SI32_PBHD_A_is_port_in_safe_state(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->PBSS.SSMDEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_enable_kill_signal_deglitch
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_enable_kill_signal_deglitch(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PBSSSMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_disable_kill_signal_deglitch
//
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_disable_kill_signal_deglitch(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   basePointer->PBSS_SET = SI32_PBHD_A_PBSS_PBSSSMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_write_pblock
//
// Writes to PBLOCK register.
//-----------------------------------------------------------------------------
void
_SI32_PBHD_A_write_pblock(
   SI32_PBHD_A_Type * basePointer,
   uint32_t pblock)
{
   //{{
   basePointer->PBLOCK.U32 = pblock;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBHD_A_read_pblock
//
// Reads PBLOCK register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBHD_A_read_pblock(
   SI32_PBHD_A_Type * basePointer)
{
   //{{
   return basePointer->PBLOCK.U32;
   //}}
}


//-eof--------------------------------------------------------------------------
