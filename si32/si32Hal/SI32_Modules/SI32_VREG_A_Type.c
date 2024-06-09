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
/// @file SI32_VREG_A_Type.c
//
// Script: 0.58
// HAL Source: 0.3
// Version: 5

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_VREG_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_VREG_A_initialize
//
// Writes all VREG registers.
//-----------------------------------------------------------------------------
void
_SI32_VREG_A_initialize(
   SI32_VREG_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_write_control
//
// Writes CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_VREG_A_write_control(
   SI32_VREG_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_read_control
//
// Reads CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_VREG_A_read_control(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_is_vbus_valid
//
//-----------------------------------------------------------------------------
bool
_SI32_VREG_A_is_vbus_valid(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.VBUSVLDF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_enter_suspend_mode
//
//-----------------------------------------------------------------------------
void
_SI32_VREG_A_enter_suspend_mode(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_VREG_A_CONTROL_SUSEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_exit_suspend_mode
//
//-----------------------------------------------------------------------------
void
_SI32_VREG_A_exit_suspend_mode(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VREG_A_CONTROL_SUSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_enable_band_gap
//
//-----------------------------------------------------------------------------
void
_SI32_VREG_A_enable_band_gap(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VREG_A_CONTROL_BGDIS_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_disable_band_gap
//
//-----------------------------------------------------------------------------
void
_SI32_VREG_A_disable_band_gap(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_VREG_A_CONTROL_BGDIS_ACTIVE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_enable_vreg_sense
//
//-----------------------------------------------------------------------------
void
_SI32_VREG_A_enable_vreg_sense(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_VREG_A_CONTROL_SENSEEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_disable_vreg_sense
//
//-----------------------------------------------------------------------------
void
_SI32_VREG_A_disable_vreg_sense(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VREG_A_CONTROL_SENSEEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_is_vbus_invalid_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_VREG_A_is_vbus_invalid_interrupt_pending(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.VBUSIVLDI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_clear_vbus_invalid_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_VREG_A_clear_vbus_invalid_interrupt(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VREG_A_CONTROL_VBUSIVLDI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_enable_vbus_invalid_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_VREG_A_enable_vbus_invalid_interrupt(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_VREG_A_CONTROL_VBUSIVLDIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_disable_vbus_invalid_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_VREG_A_disable_vbus_invalid_interrupt(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VREG_A_CONTROL_VBUSIVLDIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_is_vbus_invalid_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_VREG_A_is_vbus_invalid_interrupt_enabled(
   SI32_VREG_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.VBUSIVLDIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_enable_voltage_regulator
//
//-----------------------------------------------------------------------------
void
_SI32_VREG_A_enable_voltage_regulator(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VREG_A_CONTROL_VREGDIS_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREG_A_disable_voltage_regulator
//
//-----------------------------------------------------------------------------
void
_SI32_VREG_A_disable_voltage_regulator(
   SI32_VREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_VREG_A_CONTROL_VREGDIS_ACTIVE_U32;
   //}}
}


//-eof--------------------------------------------------------------------------
