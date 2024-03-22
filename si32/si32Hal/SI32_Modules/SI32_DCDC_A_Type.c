//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
/// @file SI32_DCDC_A_Type.c
//
// Script: 0.62
// HAL Source: 0.6
// Version: 26

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_DCDC_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_DCDC_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_initialize(
   SI32_DCDC_A_Type * basePointer,
   // Write to CONTROL register.
   uint32_t control,
   // Write to CONFIG register.
   uint32_t config)
{
   //{{
   basePointer->CONTROL.U32 = control;
   basePointer->CONFIG.U32 = config;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_write_control
//
// Write to CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_write_control(
   SI32_DCDC_A_Type * basePointer,
   uint32_t control)
{
   assert(control < 4);   // control < 2^2
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_read_control
//
// Read from CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DCDC_A_read_control(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_is_output_high_flag_set
//
// True = the output voltage is greater than 105% of the programmed
// output value, False =  the output voltage is less than 105% of the
// programmed output value.
//-----------------------------------------------------------------------------
bool
_SI32_DCDC_A_is_output_high_flag_set(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.RDYHIGHF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_is_output_low_flag_set
//
// True = the output voltage is greater  than RDYLOWTH% of the programmed
// output value, False = the output voltage is less  than RDYLOWTH% of
// the programmed output value.
//-----------------------------------------------------------------------------
bool
_SI32_DCDC_A_is_output_low_flag_set(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.RDYLOWF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_is_dropout_flag_set
//
// True = the difference between the input and the output voltage is less
// than 0.4 V, False = The difference between the input and the output
// voltage is greater than 0.4 V.
//-----------------------------------------------------------------------------
bool
_SI32_DCDC_A_is_dropout_flag_set(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.DROPOUTF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_is_bandgap_voltage_above_threshold
//
// True = bandgap voltage is above 0.9 V, False = bandgap voltage is
// below 0.9 V.
//-----------------------------------------------------------------------------
bool
_SI32_DCDC_A_is_bandgap_voltage_above_threshold(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.BGRDYF;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_enable_dcdc_oscillator
//
// Enables the DC-DC local oscillator.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_enable_dcdc_oscillator(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_OSCDIS_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_disable_dcdc_oscillator
//
// Disables the DC-DC local oscillator.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_disable_dcdc_oscillator(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_OSCDIS_ACTIVE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_select_clock_source_apb
//
// Selects the APB clock as the DC-DC converter clock source.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_select_clock_source_apb(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
      basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_CLKSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_select_clock_source_local
//
// Selects the DC-DC local oscillator as the DC-DC converter clock
// source.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_select_clock_source_local(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
      basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_CLKSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_select_clock_divider
//
// Divides the input clock (APB) to the DC-DC converter. This setting is
// only applicable if the APB is selected as the DC-DC clock source.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_select_clock_divider(
   SI32_DCDC_A_Type * basePointer,
   uint32_t divider)
{
   assert((divider >= 0) && (divider <= 4));
   //{{
   basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_CLKDIV_MASK;
   basePointer->CONTROL_SET = divider << SI32_DCDC_A_CONTROL_CLKDIV_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_select_adc_synchronous_mode
//
// Synchronizes the ADC with the DC-DC converter.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_select_adc_synchronous_mode(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
      basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_ADCSYNCEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_select_adc_asynchronous_mode
//
// Disables synchronizing between the ADC and DC-DC converter.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_select_adc_asynchronous_mode(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
    basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_ADCSYNCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_enable_converter_clock_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_enable_converter_clock_inversion(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_CLKINVEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_disable_converter_clock_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_disable_converter_clock_inversion(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_CLKINVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_enable_adc_clock_inversion
//
// Inverts the ADC0 clock derived from the DC-DC converter clock when the
// DC-DC converter is synchronized with ADC0.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_enable_adc_clock_inversion(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
        basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_ADCCLKINVEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_disable_adc_clock_inversion
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_disable_adc_clock_inversion(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
         basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_ADCCLKINVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_select_output_voltage
//
// Sets the output voltage of the converter from 1.8 V to 3.6 V. If the
// voltage parameter is less than 11, the voltage step size is 50 mV. If
// the voltage paramters is greater than or equal to 11, the voltage step
// size is 100 mV.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_select_output_voltage(
   SI32_DCDC_A_Type * basePointer,
   uint32_t voltage)
{
   assert(voltage < 32);   // voltage < 2^5
   //{{
   basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_OUTVSEL_MASK;
   basePointer->CONTROL_SET = voltage << SI32_DCDC_A_CONTROL_OUTVSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_enable_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_enable_interrupt(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
      basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_MIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_disable_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_disable_interrupt(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
      basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_MIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_select_minimum_pulse_width
//
// Sets the minimum pulse width to: 0 = no pulse skipping, 1 = 10 ns, 2 =
// 20 ns, 3 = 40 ns.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_select_minimum_pulse_width(
   SI32_DCDC_A_Type * basePointer,
   SI32_DCDC_MIN_PULSE_WIDTH_Enum_Type width)
{
   assert(width < 4);   // width < 2^2
   //{{
   basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_MINPWSEL_MASK;
   basePointer->CONTROL_SET = width << SI32_DCDC_A_CONTROL_MINPWSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_select_power_switch_size
//
// Selects the size of the power switches M1, M2. Using smaller switches
// will result in higher efficiency and lower supply currents.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_select_power_switch_size(
   SI32_DCDC_A_Type * basePointer,
   uint32_t size)
{
   assert(size < 4);   // size < 2^2
   //{{
   basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_PSMD_MASK;
   basePointer->CONTROL_SET = size << SI32_DCDC_A_CONTROL_PSMD_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_enable_async_mode
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_enable_async_mode(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
      basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_ASYNCEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_enable_sync_mode
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_enable_sync_mode(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
      basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_ASYNCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_enter_auto_bypass_mode
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_enter_auto_bypass_mode(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_ABEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_exit_auto_bypass_mode
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_exit_auto_bypass_mode(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_ABEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_enter_bypass_mode
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_enter_bypass_mode(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_BEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_exit_bypass_mode
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_exit_bypass_mode(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_BEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_enable_module
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_enable_module(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_DCDCEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_disable_module(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_DCDCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_write_config
//
// Write to CONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_write_config(
   SI32_DCDC_A_Type * basePointer,
   uint32_t config)
{
   //{{
   basePointer->CONFIG.U32 = config;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_read_config
//
// Reads from CONFIG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_DCDC_A_read_config(
   SI32_DCDC_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_select_current_limit
//
// Sets the peak current limit to (limit +1) * 100 mA: 0 = reserved, 1 =
// 200 mA. 2 = 300 mA, 3 = 400 mA, ... , 7 = 800 mA.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_select_current_limit(
   SI32_DCDC_A_Type * basePointer,
   uint32_t limit)
{
   assert(limit < 8);   // limit < 2^3
   //{{
   basePointer->CONFIG.ILIMIT = limit;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_select_interrupt_mode
//
// Sets the condition under which a DC-DC converter interrupt occurs, if
// enabled (MIEN = 1).
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_select_interrupt_mode(
   SI32_DCDC_A_Type * basePointer,
   SI32_DCDC_INTERRUPT_MODE_Enum_Type mode)
{
   assert(mode < 4);   // mode < 2^2
   //{{
      basePointer->CONFIG.INTMD = mode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_DCDC_A_select_converter_ready_low_threshold
//
// Sets the percentage of the programmed output voltage to compare with
// the regulated output voltage threshold for setting the RDYLOWF flag:
// 0=95%, 1=90%, 2=85%, 3=80%.
//-----------------------------------------------------------------------------
void
_SI32_DCDC_A_select_converter_ready_low_threshold(
   SI32_DCDC_A_Type * basePointer,
   SI32_DCDC_READY_LOW_THRESHOLD_Enum_Type threshold)
{
   assert(threshold < 4);   // threshold < 2^2
   //{{
       basePointer->CONFIG.RDYLOWTH = threshold;
   //}}
}


//-eof--------------------------------------------------------------------------
