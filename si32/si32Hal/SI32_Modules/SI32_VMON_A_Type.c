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
/// @file SI32_VMON_A_Type.c
//
// Script: 0.58
// HAL Source: 0.2
// Version: 5

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_VMON_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_VMON_A_initialize
//
// Writes all VMON registers.
//-----------------------------------------------------------------------------
void
_SI32_VMON_A_initialize(
   SI32_VMON_A_Type * basePointer,
   uint32_t control)
{
   //{{
	basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_write_control
//
// Writes CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_VMON_A_write_control(
   SI32_VMON_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_read_control
//
// Reads CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_VMON_A_read_control(
   SI32_VMON_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_enable_vreg_supply_monitor
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_A_enable_vreg_supply_monitor(
   SI32_VMON_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_VMON_A_CONTROL_VREGINSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_disable_vreg_supply_monitor
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_A_disable_vreg_supply_monitor(
   SI32_VMON_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_VMON_A_CONTROL_VREGINSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_is_vreg_low_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_VMON_A_is_vreg_low_interrupt_pending(
   SI32_VMON_A_Type * basePointer)
{
   //{{
	return !(bool)(basePointer->CONTROL.VREGINLI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_is_vdd_above_reset_threshold
//
//-----------------------------------------------------------------------------
bool
_SI32_VMON_A_is_vdd_above_reset_threshold(
   SI32_VMON_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.VDDRSTF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_is_vdd_low_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_VMON_A_is_vdd_low_interrupt_pending(
   SI32_VMON_A_Type * basePointer)
{
   //{{
	return !(bool)(basePointer->CONTROL.VDDLI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_select_vdd_high_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_A_select_vdd_high_threshold(
   SI32_VMON_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_VMON_A_CONTROL_VDDHITHEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_select_vdd_standard_threshold
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_A_select_vdd_standard_threshold(
   SI32_VMON_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VMON_A_CONTROL_VDDHITHEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_enable_vdd_low_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_A_enable_vdd_low_interrupt(
   SI32_VMON_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_VMON_A_CONTROL_VDDLIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_disable_vdd_low_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_A_disable_vdd_low_interrupt(
   SI32_VMON_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VMON_A_CONTROL_VDDLIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_is_vdd_low_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_VMON_A_is_vdd_low_interrupt_enabled(
   SI32_VMON_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.VDDLIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_enable_vreg_low_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_A_enable_vreg_low_interrupt(
   SI32_VMON_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_VMON_A_CONTROL_VREGINLIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_disable_vreg_low_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_A_disable_vreg_low_interrupt(
   SI32_VMON_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_VMON_A_CONTROL_VREGINLIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_is_vreg_low_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_VMON_A_is_vreg_low_interrupt_enabled(
   SI32_VMON_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.VREGINLIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_enable_vdd_supply_monitor
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_A_enable_vdd_supply_monitor(
   SI32_VMON_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL_SET = SI32_VMON_A_CONTROL_VMONEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VMON_A_disable_vdd_supply_monitor
//
//-----------------------------------------------------------------------------
void
_SI32_VMON_A_disable_vdd_supply_monitor(
   SI32_VMON_A_Type * basePointer)
{
   //{{
	basePointer->CONTROL_CLR = SI32_VMON_A_CONTROL_VMONEN_MASK;
   //}}
}


//-eof--------------------------------------------------------------------------
