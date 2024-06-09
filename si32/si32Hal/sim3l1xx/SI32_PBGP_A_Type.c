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
/// @file SI32_PBGP_A_Type.c
//
// This file applies to the SIM3L1XX_PBGP_A module
//
// Script: 0.59
// HAL Source: 0.2
// Version: 6

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_PBGP_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_PBGP_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_initialize(
   SI32_PBGP_A_Type * basePointer,
   // Write to PB register.
   uint32_t pb,
   // Write to PBMDSEL register.
   uint32_t pbmdsel,
   // Write to PBOUTMD register.
   uint32_t pboutmd,
   // Write to PBDRV register.
   uint32_t pbdrv,
   // Write to PM register.
   uint32_t pm,
   // Write to PMEN register.
   uint32_t pmen)
{
   //{{
   basePointer->PB.U32       = pb;
   basePointer->PBMDSEL.U32  = pbmdsel;
   basePointer->PBOUTMD.U32  = pboutmd;
   basePointer->PBDRV.U32    = pbdrv;
   basePointer->PM.U32       = pm;
   basePointer->PMEN.U32     = pmen;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_write_pb
//
// Writes to PB register.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_write_pb(
   SI32_PBGP_A_Type * basePointer,
   uint32_t pb)
{
   //{{
   basePointer->PB.U32 = pb;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_read_pb
//
// Reads PB register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBGP_A_read_pb(
   SI32_PBGP_A_Type * basePointer)
{
   //{{
   return basePointer->PB.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_write_pins_high
//
// Writes selected pins high.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_write_pins_high(
   SI32_PBGP_A_Type * basePointer,
   // Mask for pin writes : 1 = set pin to high.
   uint32_t pin_mask)
{
   assert(pin_mask < 65536);   // pin_mask < 2^16
   //{{
   basePointer->PB_SET = pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_write_pins_low
//
// Writes selected pins low.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_write_pins_low(
   SI32_PBGP_A_Type * basePointer,
   // Mask for pin writes : 1 = clear pin to low.
   uint32_t pin_mask)
{
   assert(pin_mask < 65536);   // pin_mask < 2^16
   //{{
   basePointer->PB_CLR = pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_write_pins_masked
//
// Write selected pins.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_write_pins_masked(
   SI32_PBGP_A_Type * basePointer,
   // Values for latch.
   uint32_t pin_value,
   // Mask value : 1 = write, 0 = ignore.
   uint32_t pin_mask)
{
   assert(pin_value < 65536);   // pin_value < 2^16
   assert(pin_mask < 65536);   // pin_mask < 2^16
   //{{
   basePointer->PB_MSK = (pin_mask<<16)|(pin_value);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_toggle_pins
//
// Toggle selected pins.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_toggle_pins(
   SI32_PBGP_A_Type * basePointer,
   // Mask for pin toggles : 1 = toggle pin.
   uint32_t pin_mask)
{
   assert(pin_mask < 65536);   // pin_mask < 2^16
   //{{
   basePointer->PB_MSK = (pin_mask<<16)|(~(basePointer->PB.U32) & 0xFFFF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_read_pins
//
// Reads PBPIN register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBGP_A_read_pins(
   SI32_PBGP_A_Type * basePointer)
{
   //{{
   return (basePointer->PBPIN.U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_read_pin
//
// Reads the state of a single pin.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBGP_A_read_pin(
   SI32_PBGP_A_Type * basePointer,
   // Number of the pin to read : 0 = pin 0.
   uint32_t pin_number)
{
   assert(pin_number < 65536);   // pin_number < 2^16
   //{{
   return ((basePointer->PBPIN.U32) >> pin_number) & 1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_write_pbmdsel
//
// Writes to PBMDSEL register.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_write_pbmdsel(
   SI32_PBGP_A_Type * basePointer,
   uint32_t pbmdsel)
{
   //{{
   basePointer->PBMDSEL.U32 = pbmdsel;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_read_pbmdsel
//
// Reads PBMDSEL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBGP_A_read_pbmdsel(
   SI32_PBGP_A_Type * basePointer)
{
   //{{
   return basePointer->PBMDSEL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_set_pins_push_pull_output
//
// Sets the pins masked with 1's to digital push-pull.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_set_pins_push_pull_output(
   SI32_PBGP_A_Type * basePointer,
   // Selects which pins to configure digital push-pull.
   uwide16_t pin_mask)
{
   assert(pin_mask < 65536);   // pin_mask < 2^16
   //{{
   basePointer->PBOUTMD_SET = pin_mask;
   basePointer->PBMDSEL_SET = pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_set_pins_digital_input
//
// Sets the pins masked with 1's to open-drain input.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_set_pins_digital_input(
   SI32_PBGP_A_Type * basePointer,
   // Selects which pins to configure open-drain input.
   uwide16_t pin_mask)
{
   assert(pin_mask < 65536);   // pin_mask < 2^16
   //{{
   basePointer->PBOUTMD_CLR = pin_mask;
   basePointer->PB_SET      = pin_mask;
   basePointer->PBMDSEL_SET = pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_set_pins_analog
//
// Sets the pins masked with 1's to analog mode.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_set_pins_analog(
   SI32_PBGP_A_Type * basePointer,
   // Selects which pins to configure as analog.
   uwide16_t pin_mask)
{
   assert(pin_mask < 65536);   // pin_mask < 2^16
   //{{
   basePointer->PBMDSEL_CLR = pin_mask;
   basePointer->PB_SET      = pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_write_pboutmd
//
// Writes to PBOUTMD register.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_write_pboutmd(
   SI32_PBGP_A_Type * basePointer,
   uint32_t pboutmd)
{
   //{{
   basePointer->PBOUTMD.U32 = pboutmd;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_read_pboutmd
//
// Reads PBOUTMD register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBGP_A_read_pboutmd(
   SI32_PBGP_A_Type * basePointer)
{
   //{{
   return basePointer->PBOUTMD.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_write_pbdrv
//
// Writes to PBDRV register.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_write_pbdrv(
   SI32_PBGP_A_Type * basePointer,
   uint32_t pbdrv)
{
   //{{
   basePointer->PBDRV.U32 = pbdrv;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_read_pbdrv
//
// Reads PBDRV register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBGP_A_read_pbdrv(
   SI32_PBGP_A_Type * basePointer)
{
   //{{
   return basePointer->PBDRV.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_set_pins_high_drive_strength
//
// Sets the drive strength to high for masked pins.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_set_pins_high_drive_strength(
   SI32_PBGP_A_Type * basePointer,
   // Selects which pins to configure drive high.
   uwide16_t pin_mask)
{
   assert(pin_mask < 65536);   // pin_mask < 2^16
   //{{
   basePointer->PBDRV_SET = pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_set_pins_low_drive_strength
//
// Sets the drive strength to low for masked pins.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_set_pins_low_drive_strength(
   SI32_PBGP_A_Type * basePointer,
   // Selects which pins to configure drive low.
   uwide16_t pin_mask)
{
   assert(pin_mask < 65536);   // pin_mask < 2^16
   //{{
   basePointer->PBDRV_CLR = pin_mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_enable_pullup_resistors
//
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_enable_pullup_resistors(
   SI32_PBGP_A_Type * basePointer)
{
   //{{
   basePointer->PBDRV_SET = SI32_PBGP_A_PBDRV_PBPUEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_disable_pullup_resistors
//
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_disable_pullup_resistors(
   SI32_PBGP_A_Type * basePointer)
{
   //{{
   basePointer->PBDRV_CLR = SI32_PBGP_A_PBDRV_PBPUEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_write_pm
//
// Writes to PM register, available on all ports.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_write_pm(
   SI32_PBGP_A_Type * basePointer,
   uint32_t pm)
{
   //{{
   basePointer->PM.U32 = pm;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_read_pm
//
// Reads PM register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBGP_A_read_pm(
   SI32_PBGP_A_Type * basePointer)
{
   //{{
   return basePointer->PM.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_set_port_match_pin_value
//
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_set_port_match_pin_value(
   SI32_PBGP_A_Type * basePointer,
   // Number of the pin to set the port match value high : 0 = pin 0.
   uint32_t pin_number)
{
   assert(pin_number < 65536);   // pin_number < 2^16
   //{{
   basePointer->PM_SET = (1 << pin_number);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_clear_port_match_pin_value
//
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_clear_port_match_pin_value(
   SI32_PBGP_A_Type * basePointer,
   // Number of the pin to set the port match value low : 0 = pin 0.
   uint32_t pin_number)
{
   assert(pin_number < 65536);   // pin_number < 2^16
   //{{
   basePointer->PM_CLR = (1 << pin_number);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_write_pmen
//
// Writes to PMEN register, available on all ports.
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_write_pmen(
   SI32_PBGP_A_Type * basePointer,
   uint32_t pmen)
{
   //{{
   basePointer->PMEN.U32 = pmen;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_read_pmen
//
// Reads PMEN register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_PBGP_A_read_pmen(
   SI32_PBGP_A_Type * basePointer)
{
   //{{
   return basePointer->PMEN.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_enable_port_match_pin
//
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_enable_port_match_pin(
   SI32_PBGP_A_Type * basePointer,
   // Number of the pin to enable port match : 0 = pin 0.
   uint32_t pin_number)
{
   assert(pin_number < 65536);   // pin_number < 2^16
   //{{
   basePointer->PMEN_SET = (1 << pin_number);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_PBGP_A_disable_port_match_pin
//
//-----------------------------------------------------------------------------
void
_SI32_PBGP_A_disable_port_match_pin(
   SI32_PBGP_A_Type * basePointer,
   // Number of the pin to disable port match : 0 = pin 0.
   uint32_t pin_number)
{
   assert(pin_number < 65536);   // pin_number < 2^16
   //{{
   basePointer->PMEN_CLR = (1 << pin_number);
   //}}
}


//-eof--------------------------------------------------------------------------
