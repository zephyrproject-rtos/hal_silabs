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
/// @file SI32_EXTVREG_A_Type.c
//
// Script: 0.58
// HAL Source: 0.3
// Version: 5

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_EXTVREG_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_initialize(
   SI32_EXTVREG_A_Type * basePointer,
   // Write to CONFIG register.
   uint32_t config,
   // Write to CONTROL register.
   uint32_t control,
   // Write to CSCONTROL register.
   uint32_t csconfig,
   // Write to CSCONFIG register.
   uint32_t cscontrol)
{
   //{{
   basePointer->CONFIG.U32 = config;
   basePointer->CONTROL.U32 = control;
   basePointer->CSCONFIG.U32 = csconfig;
   basePointer->CSCONTROL.U32 = cscontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_write_control
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_write_control(
   SI32_EXTVREG_A_Type * basePointer,
   // Write to CONTROL register.
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_read_control
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_EXTVREG_A_read_control(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_select_stand_alone_mode
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_select_stand_alone_mode(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EXTVREG_A_CONTROL_SAEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_select_normal_mode
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_select_normal_mode(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EXTVREG_A_CONTROL_SAEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_enable_weak_pull_up
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_enable_weak_pull_up(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EXTVREG_A_CONTROL_WPULLEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_disable_weak_pull_up
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_disable_weak_pull_up(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EXTVREG_A_CONTROL_WPULLEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_enable_foldback_limiting
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_enable_foldback_limiting(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EXTVREG_A_CONTROL_FBLEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_disable_foldback_limiting
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_disable_foldback_limiting(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EXTVREG_A_CONTROL_FBLEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_select_transistor_type_npn
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_select_transistor_type_npn(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EXTVREG_A_CONTROL_PNSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_select_transistor_type_pnp
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_select_transistor_type_pnp(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EXTVREG_A_CONTROL_PNSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_select_foldback_sensing_to_exregsn_pin
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_select_foldback_sensing_to_exregsn_pin(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EXTVREG_A_CONTROL_FBPINSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_select_foldback_sensing_to_vregin_pin
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_select_foldback_sensing_to_vregin_pin(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EXTVREG_A_CONTROL_FBPINSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_enable_module
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_enable_module(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_EXTVREG_A_CONTROL_EVREGEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_disable_module(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_EXTVREG_A_CONTROL_EVREGEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_write_config
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_write_config(
   SI32_EXTVREG_A_Type * basePointer,
   // Write to CONFIG register.
   uint32_t config)
{
   //{{
   basePointer->CONFIG.U32 = config;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_read_config
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_EXTVREG_A_read_config(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_set_current_limit_minimum
//
// Sets the minimum current limit, which is IMIN + IMINFINE.
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_set_current_limit_minimum(
   SI32_EXTVREG_A_Type * basePointer,
   // Coarse current trim, from 1 uA to 8 uA.
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_COARSE_Enum_Type imin,
   // Fine current trim, in 0.25 uA steps (0 = 0 uA, 1 = 0.25 uA, 2 = 0.5
   // uA, 3 = 0.75 uA).
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_FINE_Enum_Type iminfine)
{
   assert((imin >= 1) && (imin <= 8));
   assert((iminfine >= 0) && (iminfine <= 3));
   //{{
   basePointer->CONFIG.IMIN = imin-1;
   basePointer->CONFIG.IMINFINE = iminfine;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_set_foldback_voltage_offset
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_set_foldback_voltage_offset(
   SI32_EXTVREG_A_Type * basePointer,
   // Foldback voltage offset, in 0.5V steps (0 = 0V, 1 = 0.5V, ... 7 =
   // 3.5V).
   uint32_t fbvoff)
{
   assert((fbvoff >= 0) && (fbvoff <= 7));
   //{{
   basePointer->CONFIG.FBVOSEL = fbvoff;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_set_foldback_rate
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_set_foldback_rate(
   SI32_EXTVREG_A_Type * basePointer,
   // Sets foldback rate (0 = 4uA/V, 1 = 2uA/V, 2 = 1uA/V, 3 = 0.5uA/V, 4 =
   // 4uA/V, 5 = 8uA/V, 6 = 16uA/V, 7 = 32uA/V).
   SI32_EXTVREG_A_FOLDBACK_VOLTAGE_OFFSET_Enum_Type fbrate)
{
   assert((fbrate >= 0) && (fbrate <= 7));
   //{{
   basePointer->CONFIG.FBRATE = fbrate;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_set_current_limit_maximum
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_set_current_limit_maximum(
   SI32_EXTVREG_A_Type * basePointer,
   // Coarse current limit, in uA.
   SI32_EXTVREG_A_CURRENT_LIMIT_MAX_Enum_Type imax)
{
   assert((imax >= 2) && (imax <= 9));
   //{{
   basePointer->CONFIG.IMAX = imax-2;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_set_voltage_output
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_set_voltage_output(
   SI32_EXTVREG_A_Type * basePointer,
   // Output voltage times 10 ranging from 18 to 50. (18 = 1.8V, 19 = 1.9V,
   // ... 50 = 5.0V).
   uint32_t vout)
{
   assert((vout >= 18) && (vout <= 50));
   //{{
   basePointer->CONFIG.VOUTSEL = vout-18;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_is_max_foldback_reached
//
//-----------------------------------------------------------------------------
bool
_SI32_EXTVREG_A_is_max_foldback_reached(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->STATUS.FBMAXF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_write_cscontrol
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_write_cscontrol(
   SI32_EXTVREG_A_Type * basePointer,
   // Write to CSCONTROL register.
   uint32_t cscontrol)
{
   //{{
   basePointer->CSCONTROL.U32 = cscontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_read_cscontrol
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_EXTVREG_A_read_cscontrol(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   return basePointer->CSCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_enable_current_sense
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_enable_current_sense(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CSCONTROL_SET = SI32_EXTVREG_A_CSCONTROL_ISNSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_disable_current_sense
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_disable_current_sense(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CSCONTROL_CLR = SI32_EXTVREG_A_CSCONTROL_ISNSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_enable_adc_current_sense
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_enable_adc_current_sense(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CSCONTROL_SET = SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_disable_adc_current_sense
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_disable_adc_current_sense(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   basePointer->CSCONTROL_CLR = SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_write_csconfig
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_write_csconfig(
   SI32_EXTVREG_A_Type * basePointer,
   // Write to CSCONTROL register.
   uint32_t csconfig)
{
   //{{
   basePointer->CSCONFIG.U32 = csconfig;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_read_csconfig
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_EXTVREG_A_read_csconfig(
   SI32_EXTVREG_A_Type * basePointer)
{
   //{{
   return basePointer->CSCONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_set_current_sense_adc_channel_gain
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_set_current_sense_adc_channel_gain(
   SI32_EXTVREG_A_Type * basePointer,
   // Selects the ADC current sense gain to: 0 = 16x, 1 = 8x, 2 = 4x, 3 =
   // 2x, 4 = 1x.
   SI32_EXTVREG_A_ADC_CURRENT_SENSE_GAIN_Enum_Type mode)
{
   assert((mode >= 0) && (mode <= 4));
   //{{
   basePointer->CSCONFIG.ISADCGAIN = mode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_set_current_sense_extreg_channel_gain
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_set_current_sense_extreg_channel_gain(
   SI32_EXTVREG_A_Type * basePointer,
   // Selects the external regulator current sense gain to: 0 = 16x, 1 = 8x,
   // 2 = 4x, 3 = 2x, 4 = 1x.
   SI32_EXTVREG_A_REG_CURRENT_SENSE_GAIN_Enum_Type mode)
{
   assert((mode >= 0) && (mode <= 4));
   //{{
   basePointer->CSCONFIG.ISOGAIN = mode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_EXTVREG_A_set_current_sensing_mode
//
//-----------------------------------------------------------------------------
void
_SI32_EXTVREG_A_set_current_sensing_mode(
   SI32_EXTVREG_A_Type * basePointer,
   // Sets the current sensing mode to 0, 1, or 2.
   uint32_t mode)
{
   assert((mode >= 0) && (mode <= 2));
   //{{
   basePointer->CSCONFIG.ISINSEL = mode;
   //}}
}


//-eof--------------------------------------------------------------------------
