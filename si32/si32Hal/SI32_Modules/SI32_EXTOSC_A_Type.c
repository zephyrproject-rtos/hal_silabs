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
/// @file SI32_EXTOSC_A_Type.c
//
// Script: 0.58
// HAL Source: 0.2
// Version: 6

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_EXTOSC_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_EXTOSC_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_EXTOSC_A_initialize(
   SI32_EXTOSC_A_Type * basePointer,
   // Write to CONTROL register.
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTOSC_A_write_control
//
//-----------------------------------------------------------------------------
void
_SI32_EXTOSC_A_write_control(
   SI32_EXTOSC_A_Type * basePointer,
   // Write to CONTROL register.
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTOSC_A_read_control
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_EXTOSC_A_read_control(
   SI32_EXTOSC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTOSC_A_set_frequency_control_range
//
//-----------------------------------------------------------------------------
void
_SI32_EXTOSC_A_set_frequency_control_range(
   SI32_EXTOSC_A_Type * basePointer,
   // Frequency control range value.
   uint32_t freqcn)
{
   assert(freqcn < 8);   // freqcn < 2^3
   //{{
   basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_FREQCN_MASK;
   basePointer->CONTROL_SET = freqcn;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTOSC_A_is_oscillator_valid
//
//-----------------------------------------------------------------------------
bool
_SI32_EXTOSC_A_is_oscillator_valid(
   SI32_EXTOSC_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.OSCVLDF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTOSC_A_select_oscillator_mode_off
//
// Turn off the external oscillator circuit.
//-----------------------------------------------------------------------------
void
_SI32_EXTOSC_A_select_oscillator_mode_off(
   SI32_EXTOSC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_OSCMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTOSC_A_select_oscillator_mode_cmos
//
// Use external CMOS clock as the external oscillator source.
//-----------------------------------------------------------------------------
void
_SI32_EXTOSC_A_select_oscillator_mode_cmos(
   SI32_EXTOSC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_OSCMD_MASK;
   basePointer->CONTROL_SET = SI32_EXTOSC_A_CONTROL_OSCMD_CMOS_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTOSC_A_select_oscillator_mode_cmos_div2
//
// Use external CMOS clock with divide-by-2 stage as the external
// oscillator source.
//-----------------------------------------------------------------------------
void
_SI32_EXTOSC_A_select_oscillator_mode_cmos_div2(
   SI32_EXTOSC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_OSCMD_MASK;
   basePointer->CONTROL_SET = SI32_EXTOSC_A_CONTROL_OSCMD_CMOSDIV2_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTOSC_A_select_oscillator_mode_rc_div2
//
// Use external RC oscillator with divide-by-2 stage as the external
// oscillator source.
//-----------------------------------------------------------------------------
void
_SI32_EXTOSC_A_select_oscillator_mode_rc_div2(
   SI32_EXTOSC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_OSCMD_MASK;
   basePointer->CONTROL_SET = SI32_EXTOSC_A_CONTROL_OSCMD_RC_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTOSC_A_select_oscillator_mode_c_div2
//
// Use external C oscillator with divide-by-2 stage as the external
// oscillator source.
//-----------------------------------------------------------------------------
void
_SI32_EXTOSC_A_select_oscillator_mode_c_div2(
   SI32_EXTOSC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_OSCMD_MASK;
   basePointer->CONTROL_SET = SI32_EXTOSC_A_CONTROL_OSCMD_C_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTOSC_A_select_oscillator_mode_crystal
//
// Use external crystal oscillator as the external oscillator source.
//-----------------------------------------------------------------------------
void
_SI32_EXTOSC_A_select_oscillator_mode_crystal(
   SI32_EXTOSC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EXTOSC_A_CONTROL_OSCMD_MASK;
   basePointer->CONTROL_SET = SI32_EXTOSC_A_CONTROL_OSCMD_XTAL_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTOSC_A_select_oscillator_mode_crystal_div2
//
// Use external crystal oscillator with divide-by-2 stage as the external
// oscillator source.
//-----------------------------------------------------------------------------
void
_SI32_EXTOSC_A_select_oscillator_mode_crystal_div2(
   SI32_EXTOSC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET	= SI32_EXTOSC_A_CONTROL_OSCMD_XTALDIV2_U32;
   //}}
}


//-eof--------------------------------------------------------------------------
