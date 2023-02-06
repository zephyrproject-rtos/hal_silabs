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
/// @file SI32_VREF_B_Type.c
//
// Script: 0.61
// HAL Source: 0.1
// Version: 5

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_VREF_B_Type.h"


//-----------------------------------------------------------------------------
// _SI32_VREF_B_initialize
//
// Writes all VREF registers.
//-----------------------------------------------------------------------------
void
_SI32_VREF_B_initialize(
   SI32_VREF_B_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREF_B_write_control
//
// Writes CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_VREF_B_write_control(
   SI32_VREF_B_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREF_B_read_control
//
// Reads CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_VREF_B_read_control(
   SI32_VREF_B_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREF_B_select_1p2_volts
//
//-----------------------------------------------------------------------------
void
_SI32_VREF_B_select_1p2_volts(
   SI32_VREF_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VREF_B_CONTROL_VREF2X_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREF_B_select_2p4_volts
//
//-----------------------------------------------------------------------------
void
_SI32_VREF_B_select_2p4_volts(
   SI32_VREF_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_VREF_B_CONTROL_VREF2X_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREF_B_enable_temperature_sensor
//
//-----------------------------------------------------------------------------
void
_SI32_VREF_B_enable_temperature_sensor(
   SI32_VREF_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_VREF_B_CONTROL_TEMPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREF_B_disable_temperature_sensor
//
//-----------------------------------------------------------------------------
void
_SI32_VREF_B_disable_temperature_sensor(
   SI32_VREF_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VREF_B_CONTROL_TEMPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREF_B_enable_voltage_reference
//
//-----------------------------------------------------------------------------
void
_SI32_VREF_B_enable_voltage_reference(
   SI32_VREF_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_VREF_B_CONTROL_VREFOUTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_VREF_B_disable_voltage_reference
//
//-----------------------------------------------------------------------------
void
_SI32_VREF_B_disable_voltage_reference(
   SI32_VREF_B_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_VREF_B_CONTROL_VREFOUTEN_MASK;
   //}}
}


//-eof--------------------------------------------------------------------------
