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
/// @file SI32_CAPSENSE_A_Type.c
//
// Script: 0.59
// HAL Source: 0.5
// Version: 9

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_CAPSENSE_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_initialize(
   SI32_CAPSENSE_A_Type * basePointer,
   // Write to CONTROL register.
   uint32_t control,
   // Write to MODE register.
   uint32_t mode,
   // Write to SCANM register.
   uint32_t scanm,
   // Write to CSTH register.
   uint32_t csth,
   // Write to MUX register.
   uint32_t mux)
{
   //{{
   basePointer->CONTROL.U32 = control;
   basePointer->MODE.U32    = mode;
   basePointer->SCAN.U32    = scanm;
   basePointer->CSTH.U32    = csth;
   basePointer->MUX.U32     = mux;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_write_control
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_write_control(
   SI32_CAPSENSE_A_Type * basePointer,
   // Write to CONTROL register.
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_read_control
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_CAPSENSE_A_read_control(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_is_conversion_in_progress
//
//-----------------------------------------------------------------------------
bool
_SI32_CAPSENSE_A_is_conversion_in_progress(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.BUSYF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_start_manual_conversion
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_start_manual_conversion(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_BUSYF_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_enable_module
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_enable_module(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_disable_module(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CSEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_enable_bias
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_enable_bias(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_BIASEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_disable_bias
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_disable_bias(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_BIASEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_set_threshold_polarity_to_less_than_or_equal
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_set_threshold_polarity_to_less_than_or_equal(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CMPPOL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_set_threshold_polarity_to_greater_than
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_set_threshold_polarity_to_greater_than(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CMPPOL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_select_single_conversion_mode
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_select_single_conversion_mode(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_select_single_scan_mode
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_select_single_scan_mode(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CMD_MASK;
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CMD_SCAN_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_select_continuous_single_conversion_mode
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_select_continuous_single_conversion_mode(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CMD_MASK;
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CMD_CONT_SINGLE_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_select_continuous_scan_mode
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_select_continuous_scan_mode(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CMD_CONT_SCAN_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_set_conversion_rate
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_set_conversion_rate(
   SI32_CAPSENSE_A_Type * basePointer,
   // Conversions last n internal capsense clocks and are n bits in length:
   // 0 = n is 12, 1 = n is 13, 2 = n is 14, 3 = n is 16.
   SI32_CAPSENSE_A_CONVERSION_RATE_Enum_Type rate)
{
   assert(rate < 4);   // rate < 2^2
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CNVR_MASK;
   basePointer->CONTROL_SET = rate << SI32_CAPSENSE_A_CONTROL_CNVR_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_set_number_to_accumulate
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_set_number_to_accumulate(
   SI32_CAPSENSE_A_Type * basePointer,
   // Accumulate n samples: 0 = 1 sample, 1 = 4 samples, 2 = 8 samples, 3 =
   // 16 samples, 4 = 32 samples, 5 = 64 samples.
   SI32_CAPSENSE_A_ACCUMULATOR_MODE_Enum_Type samples)
{
   assert((samples >= 0) && (samples <= 5));
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_ACCMD_MASK;
   basePointer->CONTROL_SET = samples << SI32_CAPSENSE_A_CONTROL_ACCMD_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_enter_channels_connected_mode
//
// Channels selected by the scan registers are internally shorted
// together and the combined node is selected as the capsense input. This
// mode can be used to detect a capacitance change on multiple channels
// using a single conversion.
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_enter_channels_connected_mode(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_MCEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_exit_channels_connected_mode
//
// Channels are measured individually.
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_exit_channels_connected_mode(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_MCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_set_conversion_start_source
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_set_conversion_start_source(
   SI32_CAPSENSE_A_Type * basePointer,
   // See datasheet for settings information.
   uint32_t source)
{
   assert(source < 16);   // source < 2^4
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CSCM_MASK;
   basePointer->CONTROL_SET = source <<
      SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_set_number_of_retries
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_set_number_of_retries(
   SI32_CAPSENSE_A_Type * basePointer,
   // Configures the Pin Monitor Mode bits: 0 = always retry on pin state
   // change, 1 = retry up to twice on consecutive pin change cycles, 2 =
   // retry up to four times on consecutive pin change cycles, 3 = ignore
   // monitored signal state change.
   SI32_CAPSENSE_A_PIN_MONITOR_MODE_Enum_Type retries)
{
   assert(retries < 4);   // retries < 2^2
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_PMMD_MASK;
   basePointer->CONTROL_SET = retries <<
      SI32_CAPSENSE_A_CONTROL_PMMD_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_has_retry_occurred
//
//-----------------------------------------------------------------------------
bool
_SI32_CAPSENSE_A_has_retry_occurred(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.PMEF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_clear_retries_flag
//
// Clears the Pin Monitor Event Flag.
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_clear_retries_flag(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_PMEF_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_enable_threshold_compare
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_enable_threshold_compare(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CMPEN_MASK;
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CMPEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_disable_threshold_compare
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_disable_threshold_compare(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CMPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_is_threshold_compare_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_CAPSENSE_A_is_threshold_compare_enabled(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.CMPEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_enable_conversion_done_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_enable_conversion_done_interrupt(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CDIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_disable_conversion_done_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_disable_conversion_done_interrupt(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CDIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_is_conversion_done_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_CAPSENSE_A_is_conversion_done_interrupt_enabled(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.CDIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_enable_end_of_scan_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_enable_end_of_scan_interrupt(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_EOSIEN_ENABLED_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_disable_end_of_scan_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_disable_end_of_scan_interrupt(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_EOSIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_is_end_of_scan_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_CAPSENSE_A_is_end_of_scan_interrupt_enabled(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CONTROL.EOSIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_is_threshold_compare_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_CAPSENSE_A_is_threshold_compare_interrupt_pending(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.CMPI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_is_conversion_complete_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_CAPSENSE_A_is_conversion_complete_interrupt_pending(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.CDI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_clear_conversion_complete_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_clear_conversion_complete_interrupt(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CDI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_is_end_of_scan_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_CAPSENSE_A_is_end_of_scan_interrupt_pending(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONTROL.EOSI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_write_mode
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_write_mode(
   SI32_CAPSENSE_A_Type * basePointer,
   // Write to MODE register.
   uint32_t mode)
{
   //{{
   basePointer->MODE.U32 = mode;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_read_mode
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_CAPSENSE_A_read_mode(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   return basePointer->MODE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_set_gain
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_set_gain(
   SI32_CAPSENSE_A_Type * basePointer,
   // Select the gain applied to the capacitance measurement. Lower gain
   // values increase the size of the capacitance that can be measured with
   // the capsense module. The capacitance gain is equivalent to gain + 1.
   uint32_t gain)
{
   assert(gain < 8);   // gain < 2^3
   //{{
   basePointer->MODE_CLR = SI32_CAPSENSE_A_MODE_CGSEL_MASK;
   basePointer->MODE_SET = gain << SI32_CAPSENSE_A_MODE_CGSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_set_ramp_selection
//
// Configures the ramp time. Slower ramp times allow the capsense module
// to measure buttons with more impedance.
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_set_ramp_selection(
   SI32_CAPSENSE_A_Type * basePointer,
   // Ramp value of 0 = ramp time is less than 1.5 us, 1 = ramp time is
   // between 1.5 us and 3 us, 2 = ramp time is between 3 us and 6 us, 3 =
   // ramp time is greater than 6 us.
   uint32_t ramp)
{
   assert(ramp < 4);   // ramp < 2^2
   //{{
   basePointer->MODE_CLR = SI32_CAPSENSE_A_MODE_RAMPSEL_MASK;
   basePointer->MODE_SET = ramp << SI32_CAPSENSE_A_MODE_RAMPSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_set_output_current
//
// Changes the current used to charge the external capacitive element.
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_set_output_current(
   SI32_CAPSENSE_A_Type * basePointer,
   // Current value of 0 = full current, 1 = 1/8 current, 2 = 1/4 current, 3
   // = 3/8 current, 4 = 1/2 current, 5 = 5/8 current, 6 = 3/4 current, 7 =
   // 7/8 current.
   uint32_t current)
{
   assert(current < 8);   // current < 2^3
   //{{
   basePointer->MODE_CLR = SI32_CAPSENSE_A_MODE_IASEL_MASK;
   basePointer->MODE_SET = current << SI32_CAPSENSE_A_MODE_IASEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_set_discharge_time
//
// Adjusts the primary reset time.
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_set_discharge_time(
   SI32_CAPSENSE_A_Type * basePointer,
   // Time value of  0 = 0.75 us, 1 = 1.0 us, 2 = 1.2 us, 3 = 1.5 us, 4 = 2
   // us, 5 = 3 us, 6 = 6 us, 7 = 12 us.
   uint32_t time)
{
   assert(time < 8);   // time < 2^3
   //{{
   basePointer->MODE_CLR = SI32_CAPSENSE_A_MODE_DTSEL_MASK;
   basePointer->MODE_SET = time << SI32_CAPSENSE_A_MODE_DTSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_read_data
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_CAPSENSE_A_read_data(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   return basePointer->DATA.DATA_BITS;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_write_scanm
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_write_scanm(
   SI32_CAPSENSE_A_Type * basePointer,
   // Write to SCANM register.
   uint32_t scanm)
{
   //{{
   basePointer->SCAN.U32 = scanm;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_read_scanm
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_CAPSENSE_A_read_scanm(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   return basePointer->SCAN.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_set_channel_scan_mask
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_set_channel_scan_mask(
   SI32_CAPSENSE_A_Type * basePointer,
   uint32_t mask)
{
   assert(mask < 65536);   // mask < 2^16
   //{{
   basePointer->SCAN.U32 = mask;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_get_channel_scan_mask
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_CAPSENSE_A_get_channel_scan_mask(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   return basePointer->SCAN.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_write_csth
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_write_csth(
   SI32_CAPSENSE_A_Type * basePointer,
   // Write to CSTH register.
   uint32_t csth)
{
   //{{
   basePointer->CSTH.U32 = csth;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_read_csth
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_CAPSENSE_A_read_csth(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   return basePointer->CSTH.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_write_mux
//
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_write_mux(
   SI32_CAPSENSE_A_Type * basePointer,
   // Write to MUX register.
   uint32_t mux)
{
   //{{
   basePointer->MUX.U32 = mux;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_read_mux
//
//-----------------------------------------------------------------------------
uint32_t
_SI32_CAPSENSE_A_read_mux(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   return basePointer->MUX.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_connect_capsense_channel
//
// Connect the channel selected by the MUX register to the module.
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_connect_capsense_channel(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->MUX.CSDISC = SI32_CAPSENSE_A_MUX_CSDISC_CONNECT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_disconnect_capsense_channel
//
// Disconnects the capacitive sense input channel from the module.
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_disconnect_capsense_channel(
   SI32_CAPSENSE_A_Type * basePointer)
{
   //{{
   basePointer->MUX.CSDISC = SI32_CAPSENSE_A_MUX_CSDISC_DISCONNECT_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_set_double_reset
//
// WARNING: THIS FUNCTION IS DEPRECATED AS OF si32-1.1.1. NOT FOR NEW
// DESIGN. As of this release, the function has no effect device
// settings.
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_set_double_reset(
   SI32_CAPSENSE_A_Type * basePointer,
   uint32_t reset)
{
   assert(reset < 4);   // reset < 2^2
   //{{
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_CAPSENSE_A_set_low_pass_filter_corner_frequency
//
// WARNING: THIS FUNCTION IS DEPRECATED AS OF si32-1.1.1. NOT FOR NEW
// DESIGN. As of this release, the function has no effect device
// settings.
//-----------------------------------------------------------------------------
void
_SI32_CAPSENSE_A_set_low_pass_filter_corner_frequency(
   SI32_CAPSENSE_A_Type * basePointer,
   uint32_t filter)
{
   assert(filter < 8);   // filter < 2^3
   //{{
   //}}
}


//-eof--------------------------------------------------------------------------
