//-----------------------------------------------------------------------------
// Copyright 2013 (c) Silicon Laboratories Inc.
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
/// @file SI32_SARADC_A_Type.c
//
// Script: 0.62
// HAL Source: 1.8
// Version: 14

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_SARADC_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_SARADC_A_initialize
//
// Initialize control and configuration registers.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_initialize(
   SI32_SARADC_A_Type * basePointer,
   // Value to write to the CONFIG register.
   uint32_t config,
   // Value to write to the CONTROL register.
   uint32_t control,
   // Value to write to the WCLIMITS register.
   uint32_t wclimits)
{
   //{{
   basePointer->CONFIG.U32 = config;
   basePointer->CONTROL.U32 = control;
   basePointer->WCLIMITS.U32 = wclimits;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_initialize_channels
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_initialize_channels(
   SI32_SARADC_A_Type * basePointer,
   // Value to write to the CHAR10 register.
   uint32_t char10,
   // Value to write to the CHAR32 register.
   uint32_t char32,
   // Value to write to the SQ3210 register.
   uint32_t sq3210,
   // Value to write to the SQ7654 register.
   uint32_t sq7654)
{
   //{{
   basePointer->CHAR10.U32 = char10;
   basePointer->CHAR32.U32 = char32;
   basePointer->SQ3210.U32 = sq3210;
   basePointer->SQ7654.U32 = sq7654;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_write_config
//
// Write to the CONFIG register.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_write_config(
   SI32_SARADC_A_Type * basePointer,
   uint32_t config)
{
   //{{
   basePointer->CONFIG.U32 = config;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_read_config
//
// Reads the CONFIG register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SARADC_A_read_config(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return basePointer->CONFIG.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_set_sampling_phase
//
// Allows the ADC to delay sampling from the start-of-conversion source
// to one of 16 different phases.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_set_sampling_phase(
   SI32_SARADC_A_Type * basePointer,
   // 1 = Phase one, 2 = Phase two,..., 15 = Phase fifteen.
   uint32_t sphase)
{
   assert((sphase >= 0) && (sphase <= 15));
   //{{
   basePointer->CONFIG_CLR = 0x0000000F;
   basePointer->CONFIG_SET = sphase;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_sampling_phase
//
// Enable delayed sampling as specified by the sampling phase setting.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_sampling_phase(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_sampling_phase
//
// Disable delayed sampling as specified by the sampling phase setting.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_sampling_phase(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_ssg_conversion_start
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_ssg_conversion_start(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SSGEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_ssg_conversion_start
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_ssg_conversion_start(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SSGEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_output_packing_mode_upper_halfword_only
//
// Selects output packing format bits to place the output in the upper
// half-word (UHW).
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_output_packing_mode_upper_halfword_only(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_PACKMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_output_packing_mode_lower_halfword_only
//
// Selects output packing format bits to place the output in the lower
// half-word (LHW).
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_output_packing_mode_lower_halfword_only(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_PACKMD_MASK;
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_PACKMD_LOWER_ONLY_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_output_packing_mode_upper_halfword_first
//
// Selects output packing format bits to place the first output in the
// upper half-word (UHW) and the second output in the lower half-word
// (LHW).
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_output_packing_mode_upper_halfword_first(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_PACKMD_MASK;
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_PACKMD_UPPER_FIRST_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_output_packing_mode_lower_halfword_first
//
// Selects output packing format bits to place the first output in the
// lower half-word (LHW) and the second output in the upper half-word
// (UHW).
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_output_packing_mode_lower_halfword_first(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_PACKMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_simultaneous_conversion
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_simultaneous_conversion(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SIMCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_simultaneous_conversion
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_simultaneous_conversion(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SIMCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_interleaved_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_interleaved_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_INTLVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_interleaved_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_interleaved_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_INTLVEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_autoscan
//
// Enables automatic scan, which allows the ADC to use the channel
// sequencer.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_autoscan(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SCANEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_autoscan
//
// Disables automatic scan and does not allow the ADC to use the channel
// sequencer.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_autoscan(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SCANEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_autoscan_mode_once
//
// Selects the scan mode to go through the sequencer once upon rising
// edge of ADSCAN.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_autoscan_mode_once(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SCANMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_autoscan_mode_loop
//
// Selects the scan mode to loop through the sequencer indefinitely upon
// rising edge of ADSCAN (until the ADSCAN bit is cleared by software).
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_autoscan_mode_loop(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SCANMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_dma
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_dma(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_DMAEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_dma
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_dma(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_DMAEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_burst_mode_clock_lposc0
//
// Burst mode uses Low Power Oscillator.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_burst_mode_clock_lposc0(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_BCLKSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_burst_mode_clock_apb_clock
//
// Burst mode uses APB clock.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_burst_mode_clock_apb_clock(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_BCLKSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_sar_clock_divider
//
// Selects the SAR clock divider to be from 0 to 2047. For values less
// than three, the APB clock is used as the SAR clock. For values greater
// than or equal to 3, the SAR clock frequency is given by the equation
// Fclk_SAR = (2 x Fapb)/(sar_clk_div +1).
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_sar_clock_divider(
   SI32_SARADC_A_Type * basePointer,
   // SAR Clock Divider.
   uint32_t sar_clk_div)
{
   assert(sar_clk_div < 2048);   // sar_clk_div < 2^11
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_CLKDIV_MASK;
   basePointer->CONFIG_SET = sar_clk_div << SI32_SARADC_A_CONFIG_CLKDIV_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_single_conversion_complete_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_single_conversion_complete_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SCCIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_single_conversion_complete_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_single_conversion_complete_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SCCIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_single_conversion_complete_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_single_conversion_complete_interrupt_enabled(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONFIG.SCCIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_scan_done_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_scan_done_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SDIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_scan_done_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_scan_done_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SDIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_scan_done_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_scan_done_interrupt_enabled(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONFIG.SDIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_fifo_overrun_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_fifo_overrun_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_FORIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_fifo_overrun_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_fifo_overrun_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_FORIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_fifo_overrun_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_fifo_overrun_interrupt_enabled(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONFIG.FORIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_fifo_underrun_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_fifo_underrun_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_FURIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_fifo_underrun_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_fifo_underrun_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_FURIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_fifo_underrun_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_fifo_underrun_interrupt_enabled(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CONFIG.FURIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_write_control
//
// Writes to the CONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_write_control(
   SI32_SARADC_A_Type * basePointer,
   uint32_t control)
{
   //{{
   basePointer->CONTROL.U32 = control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_read_control
//
// Reads the CONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SARADC_A_read_control(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return basePointer->CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_reference_ground_internal
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_reference_ground_internal(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_REFGNDSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_reference_ground_external
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_reference_ground_external(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_REFGNDSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_rising_clock_edge_sampling
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_rising_clock_edge_sampling(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_CLKESEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_falling_clock_edge_sampling
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_falling_clock_edge_sampling(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_CLKESEL_FALLING_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_burst_mode_track_time
//
// Sets the delay between consecutive conversions performed in burst mode
// to be from 0 to 63. The burst mode tracking time is (64-burst_track +
// (3*TRKMD))/Fapb.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_burst_mode_track_time(
   SI32_SARADC_A_Type * basePointer,
   uint32_t burst_track)
{
   assert((burst_track >= 0) && (burst_track <= 63));
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_BMTK_MASK;
   basePointer->CONTROL_SET = burst_track << SI32_SARADC_A_CONTROL_BMTK_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_start_of_conversion_source
//
// Selects the start of conversion source number from 0 to 15; see the
// SARADC section of the datasheet for more information.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_start_of_conversion_source(
   SI32_SARADC_A_Type * basePointer,
   uint32_t soc_source)
{
   assert((soc_source >= 0) && (soc_source <= 15));
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_SCSEL_MASK;
   basePointer->CONTROL_SET = soc_source << SI32_SARADC_A_CONTROL_SCSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_burst_mode_power_up_time
//
// Selects the time delay required for ADC to power up from a low power
// state from 0 to 15. The burst mode power up time equal to (8 x
// burst_pwrup)/Fapb.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_burst_mode_power_up_time(
   SI32_SARADC_A_Type * basePointer,
   uint32_t burst_pwrup)
{
   assert((burst_pwrup >= 0) && (burst_pwrup <= 15));
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_PWRTIME_MASK;
   basePointer->CONTROL_SET = burst_pwrup << SI32_SARADC_A_CONTROL_PWRTIME_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_burst_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_burst_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_BURSTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_burst_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_burst_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_BURSTEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_module
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_module(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_ADCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_module(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_ADCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_12bit_sample_mode_four
//
// Re-sample before each of the four conversions In 12-bit mode.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_12bit_sample_mode_four(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_AD12BSSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_12bit_sample_mode_one
//
// Sample only before the first conversion in 12-bit mode.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_12bit_sample_mode_one(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_AD12BSSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_common_mode_buffer
//
// Vcm Buffer will be enabled.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_common_mode_buffer(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_VCMEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_common_mode_buffer
//
// Vcm Buffer will be disabled.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_common_mode_buffer(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_VCMEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_accumulator
//
// Enables multiple conversions to be accumulated in ACC (when burst mode
// is disabled).
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_accumulator(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_ACCMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_accumulator
//
// Disables multiple conversions accumulation in ACC.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_accumulator(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_ACCMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_normal_track_mode
//
// Sets normal track mode so conversions begin immediately following
// start-of-conversion signal.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_normal_track_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_TRKMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_delayed_track_mode
//
// Sets delayed track mode so conversions begin 3 SAR clocks following
// start-of-conversion signal.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_delayed_track_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_TRKMD_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_start_conversion
//
// Initiate an ADC conversion when the start of conversion source is set
// to ADBUSY.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_start_conversion(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_ADBUSY_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_busy
//
// Returns TRUE if ADC is busy, otherwise returns FALSE.
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_busy(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->CONTROL.ADBUSY;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_bias_power
//
// Sets SAR bias currents from 0 (maximum value) to 3 (minimum value).
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_bias_power(
   SI32_SARADC_A_Type * basePointer,
   SI32_SARADC_A_BIAS_POWER_Enum_Type bias)
{
   assert((bias >= 0) && (bias <= 3));
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_BIASSEL_MASK;
   basePointer->CONTROL_SET = bias << SI32_SARADC_A_CONTROL_BIASSEL_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_low_power_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_low_power_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_LPMDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_low_power_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_low_power_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_LPMDEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_mux_vref_low_power_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_mux_vref_low_power_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_MREFLPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_mux_vref_low_power_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_mux_vref_low_power_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_MREFLPEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_vref_internal
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_vref_internal(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_VREFSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_vref_vdd
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_vref_vdd(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_VREFSEL_MASK;
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_VREFSEL_VDD_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_vref_ldo_output
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_vref_ldo_output(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_VREFSEL_MASK;
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_VREFSEL_LDO_OUT_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_vref_external
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_vref_external(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_VREFSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_write_sq7654
//
// Writes to the SQ7654 register.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_write_sq7654(
   SI32_SARADC_A_Type * basePointer,
   uint32_t sq7654)
{
   //{{
   basePointer->SQ7654.U32 = sq7654;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_read_sq7654
//
// Reads the SQ7654 register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SARADC_A_read_sq7654(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return basePointer->SQ7654.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_write_sq3210
//
// Writes to the SQ3210 register.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_write_sq3210(
   SI32_SARADC_A_Type * basePointer,
   uint32_t sq3210)
{
   //{{
   basePointer->SQ3210.U32 = sq3210;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_read_sq3210
//
// Reads the SQ3210 register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SARADC_A_read_sq3210(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return basePointer->SQ3210.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot_channel_character_group
//
// Selects the channel character for the specified time slot of the
// sequencer.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot_channel_character_group(
   SI32_SARADC_A_Type * basePointer,
   // Sequencer time slot number (0 to 7).
   uint32_t timeslot_num,
   // Channel characteristic group number (0 to 3).
   uint32_t ch_char_group_num)
{
   assert((timeslot_num >= 0) && (timeslot_num <= 7));
   assert((ch_char_group_num >= 0) && (ch_char_group_num <= 3));
   //{{
   switch (timeslot_num)
   {
      case 0:
        basePointer->SQ3210.TS0CHR = ch_char_group_num;
        break;
      case 1:
        basePointer->SQ3210.TS1CHR = ch_char_group_num;
        break;
      case 2:
        basePointer->SQ3210.TS2CHR = ch_char_group_num;
        break;
      case 3:
        basePointer->SQ3210.TS3CHR = ch_char_group_num;
        break;
      case 4:
        basePointer->SQ7654.TS4CHR = ch_char_group_num;
        break;
      case 5:
        basePointer->SQ7654.TS5CHR = ch_char_group_num;
        break;
      case 6:
        basePointer->SQ7654.TS6CHR = ch_char_group_num;
        break;
      case 7:
        basePointer->SQ7654.TS7CHR = ch_char_group_num;
        break;
      default:
        break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot0_to_use_characteristic0
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot0_to_use_characteristic0(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS0CHR = 0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot0_to_use_characteristic1
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot0_to_use_characteristic1(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS0CHR = 1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot0_to_use_characteristic2
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot0_to_use_characteristic2(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS0CHR = 2;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot0_to_use_characteristic3
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot0_to_use_characteristic3(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS0CHR = 3;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot1_to_use_characteristic0
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot1_to_use_characteristic0(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS1CHR = 0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot1_to_use_characteristic1
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot1_to_use_characteristic1(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS1CHR = 1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot1_to_use_characteristic2
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot1_to_use_characteristic2(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS1CHR = 2;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot1_to_use_characteristic3
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot1_to_use_characteristic3(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS1CHR = 3;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot2_to_use_characteristic0
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot2_to_use_characteristic0(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS2CHR = 0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot2_to_use_characteristic1
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot2_to_use_characteristic1(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS2CHR = 1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot2_to_use_characteristic2
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot2_to_use_characteristic2(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS2CHR = 2;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot2_to_use_characteristic3
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot2_to_use_characteristic3(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS2CHR = 3;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot3_to_use_characteristic0
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot3_to_use_characteristic0(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS3CHR = 0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot3_to_use_characteristic1
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot3_to_use_characteristic1(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS3CHR = 1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot3_to_use_characteristic2
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot3_to_use_characteristic2(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS3CHR = 2;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot3_to_use_characteristic3
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot3_to_use_characteristic3(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ3210.TS3CHR = 3;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot4_to_use_characteristic0
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot4_to_use_characteristic0(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS4CHR = 0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot4_to_use_characteristic1
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot4_to_use_characteristic1(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS4CHR = 1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot4_to_use_characteristic2
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot4_to_use_characteristic2(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS4CHR = 2;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot4_to_use_characteristic3
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot4_to_use_characteristic3(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS4CHR = 3;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot5_to_use_characteristic0
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot5_to_use_characteristic0(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS5CHR = 0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot5_to_use_characteristic1
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot5_to_use_characteristic1(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS5CHR = 1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot5_to_use_characteristic2
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot5_to_use_characteristic2(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS5CHR = 2;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot5_to_use_characteristic3
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot5_to_use_characteristic3(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS5CHR = 3;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot6_to_use_characteristic0
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot6_to_use_characteristic0(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS6CHR = 0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot6_to_use_characteristic1
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot6_to_use_characteristic1(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS6CHR = 1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot6_to_use_characteristic2
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot6_to_use_characteristic2(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS6CHR = 2;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot6_to_use_characteristic3
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot6_to_use_characteristic3(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS6CHR = 3;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot7_to_use_characteristic0
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot7_to_use_characteristic0(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS7CHR = 0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot7_to_use_characteristic1
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot7_to_use_characteristic1(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS7CHR = 1;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot7_to_use_characteristic2
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot7_to_use_characteristic2(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS7CHR = 2;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot7_to_use_characteristic3
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot7_to_use_characteristic3(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->SQ7654.TS7CHR = 3;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot_channel
//
// Sets the channel number for the specified time slot.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot_channel(
   SI32_SARADC_A_Type * basePointer,
   // Sequencer time slot number (0 to 7).
   uint32_t timeslot_num,
   // Channel number (0 to 31).
   uint32_t channel)
{
   assert((timeslot_num >= 0) && (timeslot_num <= 7));
   assert((channel >= 0) && (channel <= 31));
   //{{
   switch (timeslot_num)
   {
      case 0:
      basePointer->SQ3210.TS0MUX = channel;
       break;
      case 1:
      basePointer->SQ3210.TS1MUX = channel;
       break;
    case 2:
      basePointer->SQ3210.TS2MUX = channel;
       break;
      case 3:
      basePointer->SQ3210.TS3MUX = channel;
       break;
    case 4:
         basePointer->SQ7654.TS4MUX = channel;
       break;
      case 5:
      basePointer->SQ7654.TS5MUX = channel;
       break;
    case 6:
      basePointer->SQ7654.TS6MUX = channel;
       break;
    case 7:
      basePointer->SQ7654.TS7MUX = channel;
       break;
      default:
       break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot0_channel
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot0_channel(
   SI32_SARADC_A_Type * basePointer,
   // Channel number (0 to 31).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 31));
   //{{
   basePointer->SQ3210.TS0MUX = channel;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot1_channel
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot1_channel(
   SI32_SARADC_A_Type * basePointer,
   // Channel number (0 to 31).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 31));
   //{{
   basePointer->SQ3210.TS1MUX = channel;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot2_channel
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot2_channel(
   SI32_SARADC_A_Type * basePointer,
   // Channel number (0 to 31).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 31));
   //{{
   basePointer->SQ3210.TS2MUX = channel;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot3_channel
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot3_channel(
   SI32_SARADC_A_Type * basePointer,
   // Channel number (0 to 31).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 31));
   //{{
   basePointer->SQ3210.TS3MUX = channel;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot4_channel
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot4_channel(
   SI32_SARADC_A_Type * basePointer,
   // Channel number (0 to 31).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 31));
   //{{
   basePointer->SQ7654.TS4MUX = channel;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot5_channel
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot5_channel(
   SI32_SARADC_A_Type * basePointer,
   // Channel number (0 to 31).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 31));
   //{{
   basePointer->SQ7654.TS5MUX = channel;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot6_channel
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot6_channel(
   SI32_SARADC_A_Type * basePointer,
   // Channel number (0 to 31).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 31));
   //{{
   basePointer->SQ7654.TS6MUX = channel;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_timeslot7_channel
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_timeslot7_channel(
   SI32_SARADC_A_Type * basePointer,
   // Channel number (0 to 31).
   uint32_t channel)
{
   assert((channel >= 0) && (channel <= 31));
   //{{
   basePointer->SQ7654.TS7MUX = channel;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_write_char32
//
// Writes to the CHAR32 register.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_write_char32(
   SI32_SARADC_A_Type * basePointer,
   uint32_t char32)
{
   //{{
   basePointer->CHAR32.U32 = char32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_read_char32
//
// Reads the CHAR32 register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SARADC_A_read_char32(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return basePointer->CHAR32.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_write_char10
//
// Writes to the CHAR10 register.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_write_char10(
   SI32_SARADC_A_Type * basePointer,
   uint32_t char10)
{
   //{{
   basePointer->CHAR10.U32 = char10;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_read_char10
//
// Reads the CHAR10 register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SARADC_A_read_char10(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return basePointer->CHAR10.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_character_group_gain_one
//
// Selects the on-chip PGA gain to 1 for the specified channel
// characteristic group.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_character_group_gain_one(
   SI32_SARADC_A_Type * basePointer,
   // Channel characteristic group number (0 to 3).
   uint32_t ch_char_group_num)
{
   assert((ch_char_group_num >= 0) && (ch_char_group_num <= 3));
   //{{
   switch (ch_char_group_num)
   {
      case 0:
       basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0GN_MASK;
       break;
    case 1:
       basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1GN_MASK;
       break;
    case 2:
       basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2GN_MASK;
       break;
    case 3:
       basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3GN_MASK;
       break;
    default:
       break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic0_gain_one
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic0_gain_one(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0GN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic1_gain_one
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic1_gain_one(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1GN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic2_gain_one
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic2_gain_one(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2GN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic3_gain_one
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic3_gain_one(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3GN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_character_group_gain_half
//
// Selects the on-chip PGA gain to 0.5 for the specified channel
// characteristic group.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_character_group_gain_half(
   SI32_SARADC_A_Type * basePointer,
   // Channel characteristic group number (0 to 3).
   uint32_t ch_char_group_num)
{
   assert((ch_char_group_num >= 0) && (ch_char_group_num <= 3));
   //{{
   switch (ch_char_group_num)
   {
      case 0:
       basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR0GN_MASK;
       break;
    case 1:
       basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR1GN_MASK;
       break;
    case 2:
       basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR2GN_MASK;
       break;
    case 3:
       basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR3GN_MASK;
       break;
    default:
       break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic0_gain_half
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic0_gain_half(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR0GN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic1_gain_half
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic1_gain_half(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR1GN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic2_gain_half
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic2_gain_half(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR2GN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic3_gain_half
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic3_gain_half(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR3GN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_burst_mode_repeat_count
//
// Sets number of conversions to perform and accumulate in Burst Mode for
// the specified channel characteristic group.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_burst_mode_repeat_count(
   SI32_SARADC_A_Type * basePointer,
   // Channel characteristic group number (0 to 3).
   uint32_t ch_char_group_num,
   // Number of samples to accumulate: 0=1 sample, 1=4 samples, 2=8 samples,
   // 3=16 samples, 4=32 samples, 5=64 samples.
   SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type repeat_count)
{
   assert((ch_char_group_num >= 0) && (ch_char_group_num <= 3));
   assert((repeat_count >= 0) && (repeat_count <= 5));
   //{{
   switch (ch_char_group_num)
   {
      case 0:
         basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0RPT_MASK;
      basePointer->CHAR10_SET = repeat_count << SI32_SARADC_A_CHAR10_CHR0RPT_SHIFT;
       break;
    case 1:
         basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1RPT_MASK;
      basePointer->CHAR10_SET = repeat_count << SI32_SARADC_A_CHAR10_CHR1RPT_SHIFT;
       break;
    case 2:
         basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2RPT_MASK;
      basePointer->CHAR32_SET = repeat_count << SI32_SARADC_A_CHAR32_CHR2RPT_SHIFT;
       break;
    case 3:
         basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3RPT_MASK;
      basePointer->CHAR32_SET = repeat_count << SI32_SARADC_A_CHAR32_CHR3RPT_SHIFT;
       break;
    default:
       break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic0_burst_mode_repeat_count
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic0_burst_mode_repeat_count(
   SI32_SARADC_A_Type * basePointer,
   // Number of samples to accumulate: 0=1 sample, 1=4 samples, 2=8 samples,
   // 3=16 samples, 4=32 samples, 5=64 samples.
   SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type repeat_count)
{
   assert((repeat_count >= 0) && (repeat_count <= 5));
   //{{
   basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0RPT_MASK;
   basePointer->CHAR10_SET = repeat_count << SI32_SARADC_A_CHAR10_CHR0RPT_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic1_burst_mode_repeat_count
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic1_burst_mode_repeat_count(
   SI32_SARADC_A_Type * basePointer,
   // Number of samples to accumulate: 0=1 sample, 1=4 samples, 2=8 samples,
   // 3=16 samples, 4=32 samples, 5=64 samples.
   SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type repeat_count)
{
   assert((repeat_count >= 0) && (repeat_count <= 5));
   //{{
   basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1RPT_MASK;
   basePointer->CHAR10_SET = repeat_count << SI32_SARADC_A_CHAR10_CHR1RPT_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic2_burst_mode_repeat_count
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic2_burst_mode_repeat_count(
   SI32_SARADC_A_Type * basePointer,
   // Number of samples to accumulate: 0=1 sample, 1=4 samples, 2=8 samples,
   // 3=16 samples, 4=32 samples, 5=64 samples.
   SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type repeat_count)
{
   assert((repeat_count >= 0) && (repeat_count <= 5));
   //{{
   basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2RPT_MASK;
   basePointer->CHAR32_SET = repeat_count << SI32_SARADC_A_CHAR32_CHR2RPT_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic3_burst_mode_repeat_count
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic3_burst_mode_repeat_count(
   SI32_SARADC_A_Type * basePointer,
   // Number of samples to accumulate: 0=1 sample, 1=4 samples, 2=8 samples,
   // 3=16 samples, 4=32 samples, 5=64 samples.
   SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type repeat_count)
{
   assert((repeat_count >= 0) && (repeat_count <= 5));
   //{{
   basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3RPT_MASK;
   basePointer->CHAR32_SET = repeat_count << SI32_SARADC_A_CHAR32_CHR3RPT_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_number_of_left_shift_bits
//
// Sets the number of left shift bits to the accumulated 16-bit data; 0s
// are shifted in to the LSBs.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_number_of_left_shift_bits(
   SI32_SARADC_A_Type * basePointer,
   // Channel characteristic group number (0 to 3).
   uint32_t ch_char_group_num,
   // Number of left shift bits (0 to 7).
   uint32_t num_left_shift_bits)
{
   assert((ch_char_group_num >= 0) && (ch_char_group_num <= 3));
   assert((num_left_shift_bits >= 0) && (num_left_shift_bits <= 7));
   //{{
   switch (ch_char_group_num)
   {
      case 0:
         basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0LS_MASK;
      basePointer->CHAR10_SET = num_left_shift_bits << SI32_SARADC_A_CHAR10_CHR0LS_SHIFT;
       break;
    case 1:
         basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1LS_MASK;
      basePointer->CHAR10_SET = num_left_shift_bits << SI32_SARADC_A_CHAR10_CHR1LS_SHIFT;
       break;
    case 2:
         basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2LS_MASK;
      basePointer->CHAR32_SET = num_left_shift_bits << SI32_SARADC_A_CHAR32_CHR2LS_SHIFT;      break;
    case 3:
         basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3LS_MASK;
      basePointer->CHAR32_SET = num_left_shift_bits << SI32_SARADC_A_CHAR32_CHR3LS_SHIFT;
       break;
    default:
       break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic0_left_shift_bits
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic0_left_shift_bits(
   SI32_SARADC_A_Type * basePointer,
   // Number of left shift bits (0 to 7).
   uint32_t num_left_shift_bits)
{
   assert((num_left_shift_bits >= 0) && (num_left_shift_bits <= 7));
   //{{
   basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0LS_MASK;
   basePointer->CHAR10_SET = num_left_shift_bits << SI32_SARADC_A_CHAR10_CHR0LS_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic1_left_shift_bits
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic1_left_shift_bits(
   SI32_SARADC_A_Type * basePointer,
   // Number of left shift bits (0 to 7).
   uint32_t num_left_shift_bits)
{
   assert((num_left_shift_bits >= 0) && (num_left_shift_bits <= 7));
   //{{
   basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1LS_MASK;
   basePointer->CHAR10_SET = num_left_shift_bits << SI32_SARADC_A_CHAR10_CHR1LS_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic2_left_shift_bits
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic2_left_shift_bits(
   SI32_SARADC_A_Type * basePointer,
   // Number of left shift bits (0 to 7).
   uint32_t num_left_shift_bits)
{
   assert((num_left_shift_bits >= 0) && (num_left_shift_bits <= 7));
   //{{
   basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2LS_MASK;
   basePointer->CHAR32_SET = num_left_shift_bits << SI32_SARADC_A_CHAR32_CHR2LS_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic3_left_shift_bits
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic3_left_shift_bits(
   SI32_SARADC_A_Type * basePointer,
   // Number of left shift bits (0 to 7).
   uint32_t num_left_shift_bits)
{
   assert((num_left_shift_bits >= 0) && (num_left_shift_bits <= 7));
   //{{
   basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3LS_MASK;
   basePointer->CHAR32_SET = num_left_shift_bits << SI32_SARADC_A_CHAR32_CHR3LS_SHIFT;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enter_12bit_mode
//
// ADC 12-bit mode will be enabled for the specified channel
// characteristic group; BURSTEN needs to be set to use this with SCAN.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enter_12bit_mode(
   SI32_SARADC_A_Type * basePointer,
   // Channel characteristic group number (0 to 3).
   uint32_t ch_char_group_num)
{
   assert((ch_char_group_num >= 0) && (ch_char_group_num <= 3));
   //{{
   switch (ch_char_group_num)
   {
      case 0:
       basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR0RSEL_MASK;
       break;
    case 1:
       basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR1RSEL_MASK;
       break;
    case 2:
       basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR2RSEL_MASK;
       break;
    case 3:
       basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR3RSEL_MASK;
       break;
    default:
       break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic0_12bit_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic0_12bit_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR0RSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic1_12bit_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic1_12bit_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR1RSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic2_12bit_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic2_12bit_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR2RSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic3_12bit_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic3_12bit_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR3RSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enter_10bit_mode
//
// ADC will be set to 10-bit mode for the specified channel
// characteristic group.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enter_10bit_mode(
   SI32_SARADC_A_Type * basePointer,
   // Channel characteristic group number (0 to 3).
   uint32_t ch_char_group_num)
{
   assert((ch_char_group_num >= 0) && (ch_char_group_num <= 3));
   //{{
   switch (ch_char_group_num)
   {
      case 0:
       basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0RSEL_MASK;
       break;
    case 1:
       basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1RSEL_MASK;
       break;
    case 2:
       basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2RSEL_MASK;
       break;
    case 3:
       basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3RSEL_MASK;
       break;
    default:
       break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic0_10bit_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic0_10bit_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0RSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic1_10bit_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic1_10bit_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1RSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic2_10bit_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic2_10bit_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2RSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_channel_characteristic3_10bit_mode
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_channel_characteristic3_10bit_mode(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3RSEL_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_window_comparison_interrupt
//
// Comparison between the accumulated data and the programmed windowing
// data is enabled for the specified channel charateristic group.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_window_comparison_interrupt(
   SI32_SARADC_A_Type * basePointer,
   // Channel characteristic group number (0 to 3).
   uint32_t ch_char_group_num)
{
   assert((ch_char_group_num >= 0) && (ch_char_group_num <= 3));
   //{{
   switch (ch_char_group_num)
   {
      case 0:
       basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR0WCIEN_MASK;
       break;
    case 1:
       basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR1WCIEN_MASK;
       break;
    case 2:
       basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR2WCIEN_MASK;
       break;
    case 3:
       basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR3WCIEN_MASK;
       break;
    default:
       break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_characteristic0_window_comparison_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_characteristic0_window_comparison_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR0WCIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_characteristic1_window_comparison_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_characteristic1_window_comparison_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR1WCIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_characteristic2_window_comparison_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_characteristic2_window_comparison_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR2WCIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_enable_characteristic3_window_comparison_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_enable_characteristic3_window_comparison_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR3WCIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_window_comparison_interrupt
//
// Comparison between the accumulated data and the programmed windowing
// data is disabled for the specified channel charateristic group.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_window_comparison_interrupt(
   SI32_SARADC_A_Type * basePointer,
   // Channel characteristic group number (0 to 3).
   uint32_t ch_char_group_num)
{
   assert((ch_char_group_num >= 0) && (ch_char_group_num <= 3));
   //{{
   switch (ch_char_group_num)
   {
      case 0:
       basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0WCIEN_MASK;
       break;
    case 1:
       basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1WCIEN_MASK;
       break;
    case 2:
       basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2WCIEN_MASK;
       break;
    case 3:
       basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3WCIEN_MASK;
       break;
    default:
       break;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_characteristic0_window_comparison_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_characteristic0_window_comparison_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0WCIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_characteristic1_window_comparison_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_characteristic1_window_comparison_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1WCIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_characteristic2_window_comparison_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_characteristic2_window_comparison_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2WCIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_disable_characteristic3_window_comparison_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_disable_characteristic3_window_comparison_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3WCIEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_characteristic0_window_comparison_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_characteristic0_window_comparison_interrupt_enabled(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CHAR10.CHR0WCIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_characteristic1_window_comparison_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_characteristic1_window_comparison_interrupt_enabled(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CHAR10.CHR1WCIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_characteristic2_window_comparison_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_characteristic2_window_comparison_interrupt_enabled(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CHAR32.CHR2WCIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_characteristic3_window_comparison_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_characteristic3_window_comparison_interrupt_enabled(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CHAR32.CHR3WCIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_read_data
//
// Read ADC conversion result from its data register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SARADC_A_read_data(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return basePointer->DATA.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_write_wclimits
//
// Writes to the WCLIMITS register.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_write_wclimits(
   SI32_SARADC_A_Type * basePointer,
   uint32_t wclimits)
{
   //{{
   basePointer->WCLIMITS.U32 = wclimits;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_read_wclimits
//
// Reads the WCLIMITS register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SARADC_A_read_wclimits(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return basePointer->WCLIMITS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_greater_than_window_comparator_limit
//
// Sets the 16-bit greater-than window compare value to be used to
// compare with the accumulated data.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_greater_than_window_comparator_limit(
   SI32_SARADC_A_Type * basePointer,
   // 16-bit right-justified Greater-Than window compare value.
   uint32_t adc_gt)
{
   assert((adc_gt >= 0) && (adc_gt <= 65535));
   //{{
   basePointer->WCLIMITS.WCGT = adc_gt;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_less_than_window_comparator_limit
//
// Sets the 16-bit less-than window compare value to be used to compare
// with the accumulated data.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_less_than_window_comparator_limit(
   SI32_SARADC_A_Type * basePointer,
   // 16-bit right-justified Less-Than window compare value.
   uint32_t adc_lt)
{
   assert((adc_lt >= 0) && (adc_lt <= 65535));
   //{{
   basePointer->WCLIMITS.WCLT = adc_lt;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_select_window_limits
//
// Sets the ADC window comparator limits and selects if the interrupt
// should occur when the data falls within the window or outside the
// window.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_select_window_limits(
   SI32_SARADC_A_Type * basePointer,
   // 16-bit right-justified window compare limit 0.
   uint32_t adc_limit0,
   // 16-bit right-justified window compare limit 1.
   uint32_t adc_limit1,
   // Returns TRUE if data is within the specified limits, returns FALSE if
   // the data is outside the specified limits.
   bool interrupt_in_window)
{
   assert((adc_limit0 >= 0) && (adc_limit0 <= 65535));
   assert((adc_limit1 >= 0) && (adc_limit1 <= 65535));
   //{{
   if (interrupt_in_window == true)
   {
      // If ADLT < ADGT, interrupt occurs when data is in between the limits
      basePointer->WCLIMITS.WCLT = (adc_limit0 < adc_limit1) ? adc_limit0 : adc_limit1;
      basePointer->WCLIMITS.WCGT = (adc_limit0 < adc_limit1) ? adc_limit1 : adc_limit0;
   }
   else
   {
      // If ADLT > ADGT, interrupt occurs when data is outside the limits
      basePointer->WCLIMITS.WCLT = (adc_limit0 > adc_limit1) ? adc_limit0 : adc_limit1;
      basePointer->WCLIMITS.WCGT = (adc_limit0 > adc_limit1) ? adc_limit1 : adc_limit0;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_write_acc
//
// Writes to the ACC register.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_write_acc(
   SI32_SARADC_A_Type * basePointer,
   uint32_t acc)
{
   assert(acc < 65536);   // acc < 2^16
   //{{
   basePointer->ACC.U32 = acc;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_clear_accumulator
//
// The accumulator used in ADC burst mode will be cleared to 0.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_clear_accumulator(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->ACC.U32 = 0;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_write_status
//
// Writes to the STATUS register.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_write_status(
   SI32_SARADC_A_Type * basePointer,
   uint32_t status)
{
   //{{
   basePointer->STATUS.U32 = status;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_read_status
//
// Reads the STATUS register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SARADC_A_read_status(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return basePointer->STATUS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_window_compare_interrupt_pending
//
// Check ADWINT flag.
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_window_compare_interrupt_pending(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.WCI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_clear_window_compare_interrupt
//
// Clear ADWINT flag.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_clear_window_compare_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_SARADC_A_STATUS_WCI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_single_conversion_complete_interrupt_pending
//
// Check ADINT flag.
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_single_conversion_complete_interrupt_pending(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.SCCI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_clear_single_conversion_complete_interrupt
//
// Clear ADINT flag.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_clear_single_conversion_complete_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_SARADC_A_STATUS_SCCI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_scan_done_interrupt_pending
//
// Check SCANDN flag.
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_scan_done_interrupt_pending(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.SDI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_clear_scan_done_interrupt
//
// Clear SCANDN flag.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_clear_scan_done_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_SARADC_A_STATUS_SDI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_fifo_overrun_interrupt_pending
//
// Check FIFOOF flag.
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_fifo_overrun_interrupt_pending(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.FORI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_clear_fifo_overrun_interrupt
//
// Clear FIFOOF flag.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_clear_fifo_overrun_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_SARADC_A_STATUS_FORI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_fifo_underrun_interrupt_pending
//
// Check FIFOUF flag.
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_fifo_underrun_interrupt_pending(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return (bool)basePointer->STATUS.FURI;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_clear_fifo_underrun_interrupt
//
// Clear FIFOUF flag.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_clear_fifo_underrun_interrupt(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR = SI32_SARADC_A_STATUS_FURI_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_is_any_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_SARADC_A_is_any_interrupt_pending(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   if (basePointer->STATUS.U32
     && (SI32_SARADC_A_STATUS_WCI_MASK
     | SI32_SARADC_A_STATUS_SCCI_MASK
     | SI32_SARADC_A_STATUS_SDI_MASK
     | SI32_SARADC_A_STATUS_FORI_MASK
     | SI32_SARADC_A_STATUS_FURI_MASK)
     != 0)
   {
      return true;
   }
   else
   {
      return false;
   }
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_clear_all_interrupts
//
// Clear all ADC interrupt flags.
//-----------------------------------------------------------------------------
void
_SI32_SARADC_A_clear_all_interrupts(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   basePointer->STATUS_CLR =
     (SI32_SARADC_A_STATUS_WCI_MASK
     | SI32_SARADC_A_STATUS_SCCI_MASK
     | SI32_SARADC_A_STATUS_SDI_MASK
     | SI32_SARADC_A_STATUS_FORI_MASK
     | SI32_SARADC_A_STATUS_FURI_MASK);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_read_fifostatus
//
// Reads the FIFOSTATUS register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SARADC_A_read_fifostatus(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return basePointer->FIFOSTATUS.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_SARADC_A_get_num_words_in_fifo
//
// Get number of ADC words in the FIFO. Each word may contain one or two
// samples, depending on the packing mode.
//-----------------------------------------------------------------------------
uint32_t
_SI32_SARADC_A_get_num_words_in_fifo(
   SI32_SARADC_A_Type * basePointer)
{
   //{{
   return basePointer->FIFOSTATUS.FIFOLVL;
   //}}
}


//-eof--------------------------------------------------------------------------
