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
/// @file SI32_CMP_A_Type.c
//
// Script: 0.58
// HAL Source: 0.3
// Version: 5

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_CMP_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_CMP_A_initialize
//
// Writes all CMP registers.
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_initialize(
   SI32_CMP_A_Type * basePointer,
   uint32_t control,
   uint32_t mode)
{
   //{{
	basePointer->CONTROL.U32 = control;
	basePointer->MODE.U32 = mode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_write_control
//
// Writes CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_write_control(
   SI32_CMP_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_read_control
//
// Reads CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_CMP_A_read_control(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_is_rising_edge_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_CMP_A_is_rising_edge_interrupt_pending(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.CMPRI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_clear_rising_edge_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_clear_rising_edge_interrupt(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CMP_A_CONTROL_CMPRI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_is_falling_edge_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_CMP_A_is_falling_edge_interrupt_pending(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.CMPFI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_clear_falling_edge_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_clear_falling_edge_interrupt(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CMP_A_CONTROL_CMPFI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_is_positive_input_greater_than_negative_input
//
//-----------------------------------------------------------------------------
bool
_SI32_CMP_A_is_positive_input_greater_than_negative_input(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.CMPOUT);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_enable_module
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_enable_module(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CMP_A_CONTROL_CMPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_disable_module(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CMP_A_CONTROL_CMPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_write_mode
//
// Writes MODE register.
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_write_mode(
   SI32_CMP_A_Type * basePointer,
   uint32_t mode)
{
   //{{
   basePointer->MODE.U32 = mode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_read_mode
//
// Reads MODE register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_CMP_A_read_mode(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   return basePointer->MODE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_select_negative_input
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_select_negative_input(
   SI32_CMP_A_Type * basePointer,
   // Selects negative input from 0 (CMPnN.0) to 15 (CMPnN.15).
   uint32_t input)
{
   assert(input < 16);   // input < 2^4
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_NMUX_MASK;
   basePointer->MODE_SET = input << SI32_CMP_A_MODE_NMUX_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_select_positive_input
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_select_positive_input(
   SI32_CMP_A_Type * basePointer,
   // Selects positive input from 0 (CMPnP.0) to 15 (CMPnP.15).
   uint32_t input)
{
   assert(input < 16);   // input < 2^4
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_PMUX_MASK;
   basePointer->MODE_SET = input << SI32_CMP_A_MODE_PMUX_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_select_mux
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_select_mux(
   SI32_CMP_A_Type * basePointer,
   // 0: Configures the positive input to connect to the signal based off of
   // CMXOP and the negative input to connect to the signal based off of
   // CMXON.  1: Configures the negative input to connect to VDD and the
   // positive input to connect to the signal based off of CMXOP.  2:
   // Configures the negative input to connect to the signal based off of
   // CMXON and the positive input to connect to the DAC.  3: Configures the
   // negative input to connect to the DAC and the positive input to connect
   // to the signal based off of CMXOP.
   SI32_CMP_A_INPUT_MUX_Enum_Type mux)
{
   assert(mux < 4);   // mux < 2^2
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_INMUX_MASK;
   basePointer->MODE_SET = mux << SI32_CMP_A_MODE_INMUX_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_select_response_power_mode
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_select_response_power_mode(
   SI32_CMP_A_Type * basePointer,
   // From mode 0 (fastest response time, highest power consumption) to mode
   // 3 (slowest response time, lowest power consumption).
   SI32_CMP_A_RESPONSE_POWER_MODE_Enum_Type mode)
{
   assert(mode < 4);   // mode < 2^2
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPMD_MASK;
   basePointer->MODE_SET = mode << SI32_CMP_A_MODE_CMPMD_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_enable_falling_edge_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_enable_falling_edge_interrupt(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_SET = SI32_CMP_A_MODE_FIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_disable_falling_edge_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_disable_falling_edge_interrupt(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_FIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_is_falling_edge_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_CMP_A_is_falling_edge_interrupt_enabled(
   SI32_CMP_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->MODE.FIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_enable_rising_edge_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_enable_rising_edge_interrupt(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_SET = SI32_CMP_A_MODE_RIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_disable_rising_edge_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_disable_rising_edge_interrupt(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_RIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_is_rising_edge_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_CMP_A_is_rising_edge_interrupt_enabled(
   SI32_CMP_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->MODE.RIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_write_dac_level_setting
//
// Writes the DAC level setting.  The setting represents (REFDAC / 64) *
// VREF.
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_write_dac_level_setting(
   SI32_CMP_A_Type * basePointer,
   uint32_t value)
{
   assert(value < 64);   // value < 2^6
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_DACLVL_MASK;
   basePointer->MODE_SET = value << SI32_CMP_A_MODE_DACLVL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_read_dac_level_setting
//
// Reads the DAC level setting.  The setting represents (REFDAC / 64) *
// VREF.
//-----------------------------------------------------------------------------
uint32_t
_SI32_CMP_A_read_dac_level_setting(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   return basePointer->MODE.DACLVL;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_enable_negative_weak_pullup
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_enable_negative_weak_pullup(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_SET = SI32_CMP_A_MODE_NWPUEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_disable_negative_weak_pullup
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_disable_negative_weak_pullup(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_NWPUEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_enable_positive_weak_pullup
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_enable_positive_weak_pullup(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_SET = SI32_CMP_A_MODE_PWPUEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_disable_positive_weak_pullup
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_disable_positive_weak_pullup(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_PWPUEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_select_negative_hysteresis_disabled
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_select_negative_hysteresis_disabled(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_select_negative_hysteresis_5mv
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_select_negative_hysteresis_5mv(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYN_MASK;
   basePointer->MODE_SET = SI32_CMP_A_MODE_CMPHYN_NEG_5_MV_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_select_negative_hysteresis_10mv
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_select_negative_hysteresis_10mv(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYN_MASK;
   basePointer->MODE_SET = SI32_CMP_A_MODE_CMPHYN_NEG_10_MV_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_select_negative_hysteresis_20mv
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_select_negative_hysteresis_20mv(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYN_MASK;
   basePointer->MODE_SET = SI32_CMP_A_MODE_CMPHYN_NEG_20_MV_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_select_positive_hysteresis_disabled
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_select_positive_hysteresis_disabled(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYP_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_select_positive_hysteresis_5mv
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_select_positive_hysteresis_5mv(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYP_MASK;
   basePointer->MODE_SET = SI32_CMP_A_MODE_CMPHYP_POS_5_MV_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_select_positive_hysteresis_10mv
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_select_positive_hysteresis_10mv(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYP_MASK;
   basePointer->MODE_SET = SI32_CMP_A_MODE_CMPHYP_POS_10_MV_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_select_positive_hysteresis_20mv
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_select_positive_hysteresis_20mv(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_CMPHYP_MASK;
   basePointer->MODE_SET = SI32_CMP_A_MODE_CMPHYP_POS_20_MV_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_enable_inverted_output
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_enable_inverted_output(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_SET = SI32_CMP_A_MODE_INVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CMP_A_disable_inverted_output
//
//-----------------------------------------------------------------------------
void
_SI32_CMP_A_disable_inverted_output(
   SI32_CMP_A_Type * basePointer)
{
   //{{
   basePointer->MODE_CLR = SI32_CMP_A_MODE_INVEN_MASK;
   //}}
}


//-eof--------------------------------------------------------------------------
