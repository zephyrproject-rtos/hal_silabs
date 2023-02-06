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
/// @file SI32_SARADC_A_Type.h
//
// Script: 0.62
// HAL Source: 1.8
// Version: 1

#ifndef __SI32_SARADC_A_TYPE_H__
#define __SI32_SARADC_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_SARADC_A_Registers.h"
#include "SI32_SARADC_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_SARADC_A_initialize(SI32_SARADC_A_Type* basePointer,
///      uint32_t config,
///      uint32_t control,
///      uint32_t wclimits)
///
/// @brief
/// Initialize control and configuration registers.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///  Value to write to the CONFIG register.
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Value to write to the CONTROL register.
///
/// @param[in]
///  wclimits
///  Valid range is 32 bits.
///  Value to write to the WCLIMITS register.
///
void
_SI32_SARADC_A_initialize(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t, /*config*/
   uint32_t, /*control*/
   uint32_t /*wclimits*/);
///
/// @def SI32_SARADC_A_initialize(basePointer, config, control, wclimits)
#define SI32_SARADC_A_initialize(basePointer, config, control, wclimits) do{  \
   basePointer->CONFIG.U32 = config;\
   basePointer->CONTROL.U32 = control;\
   basePointer->WCLIMITS.U32 = wclimits;\
} while(0)


/// @fn _SI32_SARADC_A_initialize_channels(SI32_SARADC_A_Type* basePointer,
///      uint32_t char10,
///      uint32_t char32,
///      uint32_t sq3210,
///      uint32_t sq7654)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  char10
///  Valid range is 32 bits.
///  Value to write to the CHAR10 register.
///
/// @param[in]
///  char32
///  Valid range is 32 bits.
///  Value to write to the CHAR32 register.
///
/// @param[in]
///  sq3210
///  Valid range is 32 bits.
///  Value to write to the SQ3210 register.
///
/// @param[in]
///  sq7654
///  Valid range is 32 bits.
///  Value to write to the SQ7654 register.
///
void
_SI32_SARADC_A_initialize_channels(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t, /*char10*/
   uint32_t, /*char32*/
   uint32_t, /*sq3210*/
   uint32_t /*sq7654*/);
///
/// @def SI32_SARADC_A_initialize_channels(basePointer, char10, char32, sq3210, sq7654)
#define SI32_SARADC_A_initialize_channels(basePointer, char10, char32, sq3210, sq7654) do{  \
   basePointer->CHAR10.U32 = char10;\
   basePointer->CHAR32.U32 = char32;\
   basePointer->SQ3210.U32 = sq3210;\
   basePointer->SQ7654.U32 = sq7654;\
} while(0)


/// @fn _SI32_SARADC_A_write_config(SI32_SARADC_A_Type* basePointer,
///      uint32_t config)
///
/// @brief
/// Write to the CONFIG register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///
void
_SI32_SARADC_A_write_config(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*config*/);
///
/// @def SI32_SARADC_A_write_config(basePointer, config)
#define SI32_SARADC_A_write_config(basePointer, config) \
   (basePointer->CONFIG.U32 = config)


/// @fn _SI32_SARADC_A_read_config(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Reads the CONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SARADC_A_read_config(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_read_config(basePointer)
#define SI32_SARADC_A_read_config(basePointer) \
(basePointer->CONFIG.U32)


/// @fn _SI32_SARADC_A_set_sampling_phase(SI32_SARADC_A_Type* basePointer,
///      uint32_t sphase)
///
/// @brief
/// Allows the ADC to delay sampling from the start-of-conversion source
/// to one of 16 different phases.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  sphase
///  Valid range is 0 to 15.
///  1 = Phase one, 2 = Phase two,..., 15 = Phase fifteen.
///
void
_SI32_SARADC_A_set_sampling_phase(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*sphase*/);
///
/// @def SI32_SARADC_A_set_sampling_phase(basePointer, sphase)
#define SI32_SARADC_A_set_sampling_phase(basePointer, sphase) do{  \
   basePointer->CONFIG_CLR = 0x0000000F;\
   basePointer->CONFIG_SET = sphase;\
} while(0)


/// @fn _SI32_SARADC_A_enable_sampling_phase(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Enable delayed sampling as specified by the sampling phase setting.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_sampling_phase(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_sampling_phase(basePointer)
#define SI32_SARADC_A_enable_sampling_phase(basePointer) \
   (basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SPEN_MASK)


/// @fn _SI32_SARADC_A_disable_sampling_phase(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Disable delayed sampling as specified by the sampling phase setting.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_sampling_phase(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_sampling_phase(basePointer)
#define SI32_SARADC_A_disable_sampling_phase(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SPEN_MASK)


/// @fn _SI32_SARADC_A_enable_ssg_conversion_start(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_ssg_conversion_start(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_ssg_conversion_start(basePointer)
#define SI32_SARADC_A_enable_ssg_conversion_start(basePointer) \
   (basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SSGEN_MASK)


/// @fn _SI32_SARADC_A_disable_ssg_conversion_start(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_ssg_conversion_start(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_ssg_conversion_start(basePointer)
#define SI32_SARADC_A_disable_ssg_conversion_start(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SSGEN_MASK)


/// @fn _SI32_SARADC_A_select_output_packing_mode_upper_halfword_only(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Selects output packing format bits to place the output in the upper
/// half-word (UHW).
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_output_packing_mode_upper_halfword_only(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_output_packing_mode_upper_halfword_only(basePointer)
#define SI32_SARADC_A_select_output_packing_mode_upper_halfword_only(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_PACKMD_MASK)


/// @fn _SI32_SARADC_A_select_output_packing_mode_lower_halfword_only(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Selects output packing format bits to place the output in the lower
/// half-word (LHW).
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_output_packing_mode_lower_halfword_only(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_output_packing_mode_lower_halfword_only(basePointer)
#define SI32_SARADC_A_select_output_packing_mode_lower_halfword_only(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_PACKMD_MASK;\
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_PACKMD_LOWER_ONLY_U32;\
} while(0)


/// @fn _SI32_SARADC_A_select_output_packing_mode_upper_halfword_first(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Selects output packing format bits to place the first output in the
/// upper half-word (UHW) and the second output in the lower half-word
/// (LHW).
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_output_packing_mode_upper_halfword_first(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_output_packing_mode_upper_halfword_first(basePointer)
#define SI32_SARADC_A_select_output_packing_mode_upper_halfword_first(basePointer) do{  \
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_PACKMD_MASK;\
   basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_PACKMD_UPPER_FIRST_U32;\
} while(0)


/// @fn _SI32_SARADC_A_select_output_packing_mode_lower_halfword_first(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Selects output packing format bits to place the first output in the
/// lower half-word (LHW) and the second output in the upper half-word
/// (UHW).
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_output_packing_mode_lower_halfword_first(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_output_packing_mode_lower_halfword_first(basePointer)
#define SI32_SARADC_A_select_output_packing_mode_lower_halfword_first(basePointer) \
   (basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_PACKMD_MASK)


/// @fn _SI32_SARADC_A_enable_simultaneous_conversion(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_simultaneous_conversion(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_simultaneous_conversion(basePointer)
#define SI32_SARADC_A_enable_simultaneous_conversion(basePointer) \
   (basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SIMCEN_MASK)


/// @fn _SI32_SARADC_A_disable_simultaneous_conversion(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_simultaneous_conversion(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_simultaneous_conversion(basePointer)
#define SI32_SARADC_A_disable_simultaneous_conversion(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SIMCEN_MASK)


/// @fn _SI32_SARADC_A_enable_interleaved_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_interleaved_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_interleaved_mode(basePointer)
#define SI32_SARADC_A_enable_interleaved_mode(basePointer) \
   (basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_INTLVEN_MASK)


/// @fn _SI32_SARADC_A_disable_interleaved_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_interleaved_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_interleaved_mode(basePointer)
#define SI32_SARADC_A_disable_interleaved_mode(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_INTLVEN_MASK)


/// @fn _SI32_SARADC_A_enable_autoscan(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Enables automatic scan, which allows the ADC to use the channel
/// sequencer.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_autoscan(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_autoscan(basePointer)
#define SI32_SARADC_A_enable_autoscan(basePointer) \
   (basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SCANEN_MASK)


/// @fn _SI32_SARADC_A_disable_autoscan(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Disables automatic scan and does not allow the ADC to use the channel
/// sequencer.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_autoscan(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_autoscan(basePointer)
#define SI32_SARADC_A_disable_autoscan(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SCANEN_MASK)


/// @fn _SI32_SARADC_A_select_autoscan_mode_once(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Selects the scan mode to go through the sequencer once upon rising
/// edge of ADSCAN.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_autoscan_mode_once(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_autoscan_mode_once(basePointer)
#define SI32_SARADC_A_select_autoscan_mode_once(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SCANMD_MASK)


/// @fn _SI32_SARADC_A_select_autoscan_mode_loop(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Selects the scan mode to loop through the sequencer indefinitely upon
/// rising edge of ADSCAN (until the ADSCAN bit is cleared by software).
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_autoscan_mode_loop(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_autoscan_mode_loop(basePointer)
#define SI32_SARADC_A_select_autoscan_mode_loop(basePointer) \
   (basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SCANMD_MASK)


/// @fn _SI32_SARADC_A_enable_dma(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_dma(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_dma(basePointer)
#define SI32_SARADC_A_enable_dma(basePointer) \
   (basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_DMAEN_MASK)


/// @fn _SI32_SARADC_A_disable_dma(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_dma(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_dma(basePointer)
#define SI32_SARADC_A_disable_dma(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_DMAEN_MASK)


/// @fn _SI32_SARADC_A_select_burst_mode_clock_lposc0(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Burst mode uses Low Power Oscillator.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_burst_mode_clock_lposc0(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_burst_mode_clock_lposc0(basePointer)
#define SI32_SARADC_A_select_burst_mode_clock_lposc0(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_BCLKSEL_MASK)


/// @fn _SI32_SARADC_A_select_burst_mode_clock_apb_clock(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Burst mode uses APB clock.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_burst_mode_clock_apb_clock(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_burst_mode_clock_apb_clock(basePointer)
#define SI32_SARADC_A_select_burst_mode_clock_apb_clock(basePointer) \
   (basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_BCLKSEL_MASK)


/// @fn _SI32_SARADC_A_select_sar_clock_divider(SI32_SARADC_A_Type* basePointer,
///      uint32_t sar_clk_div)
///
/// @brief
/// Selects the SAR clock divider to be from 0 to 2047. For values less
/// than three, the APB clock is used as the SAR clock. For values greater
/// than or equal to 3, the SAR clock frequency is given by the equation
/// Fclk_SAR = (2 x Fapb)/(sar_clk_div +1).
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  sar_clk_div
///  Valid range is 11 bits.
///  SAR Clock Divider.
///
void
_SI32_SARADC_A_select_sar_clock_divider(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*sar_clk_div*/);
///
/// @def SI32_SARADC_A_select_sar_clock_divider(basePointer, sar_clk_div)
#define SI32_SARADC_A_select_sar_clock_divider(basePointer, sar_clk_div) do{  \
   basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_CLKDIV_MASK;\
   basePointer->CONFIG_SET = sar_clk_div << SI32_SARADC_A_CONFIG_CLKDIV_SHIFT;\
} while(0)


/// @fn _SI32_SARADC_A_enable_single_conversion_complete_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_single_conversion_complete_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_single_conversion_complete_interrupt(basePointer)
#define SI32_SARADC_A_enable_single_conversion_complete_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SCCIEN_MASK)


/// @fn _SI32_SARADC_A_disable_single_conversion_complete_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_single_conversion_complete_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_single_conversion_complete_interrupt(basePointer)
#define SI32_SARADC_A_disable_single_conversion_complete_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SCCIEN_MASK)


/// @fn _SI32_SARADC_A_is_single_conversion_complete_interrupt_enabled(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_single_conversion_complete_interrupt_enabled(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_single_conversion_complete_interrupt_enabled(basePointer)
#define SI32_SARADC_A_is_single_conversion_complete_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.SCCIEN))


/// @fn _SI32_SARADC_A_enable_scan_done_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_scan_done_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_scan_done_interrupt(basePointer)
#define SI32_SARADC_A_enable_scan_done_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_SDIEN_MASK)


/// @fn _SI32_SARADC_A_disable_scan_done_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_scan_done_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_scan_done_interrupt(basePointer)
#define SI32_SARADC_A_disable_scan_done_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_SDIEN_MASK)


/// @fn _SI32_SARADC_A_is_scan_done_interrupt_enabled(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_scan_done_interrupt_enabled(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_scan_done_interrupt_enabled(basePointer)
#define SI32_SARADC_A_is_scan_done_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.SDIEN))


/// @fn _SI32_SARADC_A_enable_fifo_overrun_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_fifo_overrun_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_fifo_overrun_interrupt(basePointer)
#define SI32_SARADC_A_enable_fifo_overrun_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_FORIEN_MASK)


/// @fn _SI32_SARADC_A_disable_fifo_overrun_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_fifo_overrun_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_fifo_overrun_interrupt(basePointer)
#define SI32_SARADC_A_disable_fifo_overrun_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_FORIEN_MASK)


/// @fn _SI32_SARADC_A_is_fifo_overrun_interrupt_enabled(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_fifo_overrun_interrupt_enabled(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_fifo_overrun_interrupt_enabled(basePointer)
#define SI32_SARADC_A_is_fifo_overrun_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.FORIEN))


/// @fn _SI32_SARADC_A_enable_fifo_underrun_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_fifo_underrun_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_fifo_underrun_interrupt(basePointer)
#define SI32_SARADC_A_enable_fifo_underrun_interrupt(basePointer) \
   (basePointer->CONFIG_SET = SI32_SARADC_A_CONFIG_FURIEN_MASK)


/// @fn _SI32_SARADC_A_disable_fifo_underrun_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_fifo_underrun_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_fifo_underrun_interrupt(basePointer)
#define SI32_SARADC_A_disable_fifo_underrun_interrupt(basePointer) \
   (basePointer->CONFIG_CLR = SI32_SARADC_A_CONFIG_FURIEN_MASK)


/// @fn _SI32_SARADC_A_is_fifo_underrun_interrupt_enabled(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_fifo_underrun_interrupt_enabled(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_fifo_underrun_interrupt_enabled(basePointer)
#define SI32_SARADC_A_is_fifo_underrun_interrupt_enabled(basePointer) \
((bool)(basePointer->CONFIG.FURIEN))


/// @fn _SI32_SARADC_A_write_control(SI32_SARADC_A_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Writes to the CONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///
void
_SI32_SARADC_A_write_control(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_SARADC_A_write_control(basePointer, control)
#define SI32_SARADC_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_SARADC_A_read_control(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Reads the CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SARADC_A_read_control(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_read_control(basePointer)
#define SI32_SARADC_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_SARADC_A_select_reference_ground_internal(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_reference_ground_internal(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_reference_ground_internal(basePointer)
#define SI32_SARADC_A_select_reference_ground_internal(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_REFGNDSEL_MASK)


/// @fn _SI32_SARADC_A_select_reference_ground_external(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_reference_ground_external(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_reference_ground_external(basePointer)
#define SI32_SARADC_A_select_reference_ground_external(basePointer) \
   (basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_REFGNDSEL_MASK)


/// @fn _SI32_SARADC_A_select_rising_clock_edge_sampling(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_rising_clock_edge_sampling(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_rising_clock_edge_sampling(basePointer)
#define SI32_SARADC_A_select_rising_clock_edge_sampling(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_CLKESEL_MASK)


/// @fn _SI32_SARADC_A_select_falling_clock_edge_sampling(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_falling_clock_edge_sampling(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_falling_clock_edge_sampling(basePointer)
#define SI32_SARADC_A_select_falling_clock_edge_sampling(basePointer) \
   (basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_CLKESEL_FALLING_U32)


/// @fn _SI32_SARADC_A_select_burst_mode_track_time(SI32_SARADC_A_Type* basePointer,
///      uint32_t burst_track)
///
/// @brief
/// Sets the delay between consecutive conversions performed in burst mode
/// to be from 0 to 63. The burst mode tracking time is (64-burst_track +
/// (3*TRKMD))/Fapb.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  burst_track
///  Valid range is 0 to 63.
///
void
_SI32_SARADC_A_select_burst_mode_track_time(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*burst_track*/);
///
/// @def SI32_SARADC_A_select_burst_mode_track_time(basePointer, burst_track)
#define SI32_SARADC_A_select_burst_mode_track_time(basePointer, burst_track) do{  \
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_BMTK_MASK;\
   basePointer->CONTROL_SET = burst_track << SI32_SARADC_A_CONTROL_BMTK_SHIFT;\
} while(0)


/// @fn _SI32_SARADC_A_select_start_of_conversion_source(SI32_SARADC_A_Type* basePointer,
///      uint32_t soc_source)
///
/// @brief
/// Selects the start of conversion source number from 0 to 15; see the
/// SARADC section of the datasheet for more information.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  soc_source
///  Valid range is 0 to 15.
///
void
_SI32_SARADC_A_select_start_of_conversion_source(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*soc_source*/);
///
/// @def SI32_SARADC_A_select_start_of_conversion_source(basePointer, soc_source)
#define SI32_SARADC_A_select_start_of_conversion_source(basePointer, soc_source) do{  \
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_SCSEL_MASK;\
   basePointer->CONTROL_SET = soc_source << SI32_SARADC_A_CONTROL_SCSEL_SHIFT;\
} while(0)


/// @fn _SI32_SARADC_A_select_burst_mode_power_up_time(SI32_SARADC_A_Type* basePointer,
///      uint32_t burst_pwrup)
///
/// @brief
/// Selects the time delay required for ADC to power up from a low power
/// state from 0 to 15. The burst mode power up time equal to (8 x
/// burst_pwrup)/Fapb.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  burst_pwrup
///  Valid range is 0 to 15.
///
void
_SI32_SARADC_A_select_burst_mode_power_up_time(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*burst_pwrup*/);
///
/// @def SI32_SARADC_A_select_burst_mode_power_up_time(basePointer, burst_pwrup)
#define SI32_SARADC_A_select_burst_mode_power_up_time(basePointer, burst_pwrup) do{  \
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_PWRTIME_MASK;\
   basePointer->CONTROL_SET = burst_pwrup << SI32_SARADC_A_CONTROL_PWRTIME_SHIFT;\
} while(0)


/// @fn _SI32_SARADC_A_enable_burst_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_burst_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_burst_mode(basePointer)
#define SI32_SARADC_A_enable_burst_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_BURSTEN_MASK)


/// @fn _SI32_SARADC_A_disable_burst_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_burst_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_burst_mode(basePointer)
#define SI32_SARADC_A_disable_burst_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_BURSTEN_MASK)


/// @fn _SI32_SARADC_A_enable_module(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_module(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_module(basePointer)
#define SI32_SARADC_A_enable_module(basePointer) \
   (basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_ADCEN_MASK)


/// @fn _SI32_SARADC_A_disable_module(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_module(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_module(basePointer)
#define SI32_SARADC_A_disable_module(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_ADCEN_MASK)


/// @fn _SI32_SARADC_A_select_12bit_sample_mode_four(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Re-sample before each of the four conversions In 12-bit mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_12bit_sample_mode_four(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_12bit_sample_mode_four(basePointer)
#define SI32_SARADC_A_select_12bit_sample_mode_four(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_AD12BSSEL_MASK)


/// @fn _SI32_SARADC_A_select_12bit_sample_mode_one(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Sample only before the first conversion in 12-bit mode.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_12bit_sample_mode_one(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_12bit_sample_mode_one(basePointer)
#define SI32_SARADC_A_select_12bit_sample_mode_one(basePointer) \
   (basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_AD12BSSEL_MASK)


/// @fn _SI32_SARADC_A_enable_common_mode_buffer(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Vcm Buffer will be enabled.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_common_mode_buffer(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_common_mode_buffer(basePointer)
#define SI32_SARADC_A_enable_common_mode_buffer(basePointer) \
   (basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_VCMEN_MASK)


/// @fn _SI32_SARADC_A_disable_common_mode_buffer(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Vcm Buffer will be disabled.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_common_mode_buffer(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_common_mode_buffer(basePointer)
#define SI32_SARADC_A_disable_common_mode_buffer(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_VCMEN_MASK)


/// @fn _SI32_SARADC_A_enable_accumulator(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Enables multiple conversions to be accumulated in ACC (when burst mode
/// is disabled).
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_accumulator(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_accumulator(basePointer)
#define SI32_SARADC_A_enable_accumulator(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_ACCMD_MASK)


/// @fn _SI32_SARADC_A_disable_accumulator(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Disables multiple conversions accumulation in ACC.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_accumulator(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_accumulator(basePointer)
#define SI32_SARADC_A_disable_accumulator(basePointer) \
   (basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_ACCMD_MASK)


/// @fn _SI32_SARADC_A_select_normal_track_mode(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Sets normal track mode so conversions begin immediately following
/// start-of-conversion signal.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_normal_track_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_normal_track_mode(basePointer)
#define SI32_SARADC_A_select_normal_track_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_TRKMD_MASK)


/// @fn _SI32_SARADC_A_select_delayed_track_mode(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Sets delayed track mode so conversions begin 3 SAR clocks following
/// start-of-conversion signal.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_delayed_track_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_delayed_track_mode(basePointer)
#define SI32_SARADC_A_select_delayed_track_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_TRKMD_MASK)


/// @fn _SI32_SARADC_A_start_conversion(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Initiate an ADC conversion when the start of conversion source is set
/// to ADBUSY.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_start_conversion(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_start_conversion(basePointer)
#define SI32_SARADC_A_start_conversion(basePointer) \
   (basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_ADBUSY_MASK)


/// @fn _SI32_SARADC_A_is_busy(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if ADC is busy, otherwise returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_busy(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_busy(basePointer)
#define SI32_SARADC_A_is_busy(basePointer) \
((bool)basePointer->CONTROL.ADBUSY)


/// @fn _SI32_SARADC_A_select_bias_power(SI32_SARADC_A_Type* basePointer,
///      SI32_SARADC_A_BIAS_POWER_Enum_Type bias)
///
/// @brief
/// Sets SAR bias currents from 0 (maximum value) to 3 (minimum value).
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  bias
///  Valid range is 0 to 3.
///
void
_SI32_SARADC_A_select_bias_power(SI32_SARADC_A_Type* /*basePointer*/,
   SI32_SARADC_A_BIAS_POWER_Enum_Type /*bias*/);
///
/// @def SI32_SARADC_A_select_bias_power(basePointer, bias)
#define SI32_SARADC_A_select_bias_power(basePointer, bias) do{  \
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_BIASSEL_MASK;\
   basePointer->CONTROL_SET = bias << SI32_SARADC_A_CONTROL_BIASSEL_SHIFT;\
} while(0)


/// @fn _SI32_SARADC_A_enable_low_power_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_low_power_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_low_power_mode(basePointer)
#define SI32_SARADC_A_enable_low_power_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_LPMDEN_MASK)


/// @fn _SI32_SARADC_A_disable_low_power_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_low_power_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_low_power_mode(basePointer)
#define SI32_SARADC_A_disable_low_power_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_LPMDEN_MASK)


/// @fn _SI32_SARADC_A_enable_mux_vref_low_power_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_mux_vref_low_power_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_mux_vref_low_power_mode(basePointer)
#define SI32_SARADC_A_enable_mux_vref_low_power_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_MREFLPEN_MASK)


/// @fn _SI32_SARADC_A_disable_mux_vref_low_power_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_mux_vref_low_power_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_mux_vref_low_power_mode(basePointer)
#define SI32_SARADC_A_disable_mux_vref_low_power_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_MREFLPEN_MASK)


/// @fn _SI32_SARADC_A_select_vref_internal(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_vref_internal(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_vref_internal(basePointer)
#define SI32_SARADC_A_select_vref_internal(basePointer) \
   (basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_VREFSEL_MASK)


/// @fn _SI32_SARADC_A_select_vref_vdd(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_vref_vdd(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_vref_vdd(basePointer)
#define SI32_SARADC_A_select_vref_vdd(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_VREFSEL_MASK;\
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_VREFSEL_VDD_U32;\
} while(0)


/// @fn _SI32_SARADC_A_select_vref_ldo_output(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_vref_ldo_output(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_vref_ldo_output(basePointer)
#define SI32_SARADC_A_select_vref_ldo_output(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_SARADC_A_CONTROL_VREFSEL_MASK;\
   basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_VREFSEL_LDO_OUT_U32;\
} while(0)


/// @fn _SI32_SARADC_A_select_vref_external(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_vref_external(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_vref_external(basePointer)
#define SI32_SARADC_A_select_vref_external(basePointer) \
   (basePointer->CONTROL_SET = SI32_SARADC_A_CONTROL_VREFSEL_MASK)


/// @fn _SI32_SARADC_A_write_sq7654(SI32_SARADC_A_Type* basePointer,
///      uint32_t sq7654)
///
/// @brief
/// Writes to the SQ7654 register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  sq7654
///  Valid range is 32 bits.
///
void
_SI32_SARADC_A_write_sq7654(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*sq7654*/);
///
/// @def SI32_SARADC_A_write_sq7654(basePointer, sq7654)
#define SI32_SARADC_A_write_sq7654(basePointer, sq7654) \
   (basePointer->SQ7654.U32 = sq7654)


/// @fn _SI32_SARADC_A_read_sq7654(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Reads the SQ7654 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SARADC_A_read_sq7654(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_read_sq7654(basePointer)
#define SI32_SARADC_A_read_sq7654(basePointer) \
(basePointer->SQ7654.U32)


/// @fn _SI32_SARADC_A_write_sq3210(SI32_SARADC_A_Type* basePointer,
///      uint32_t sq3210)
///
/// @brief
/// Writes to the SQ3210 register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  sq3210
///  Valid range is 32 bits.
///
void
_SI32_SARADC_A_write_sq3210(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*sq3210*/);
///
/// @def SI32_SARADC_A_write_sq3210(basePointer, sq3210)
#define SI32_SARADC_A_write_sq3210(basePointer, sq3210) \
   (basePointer->SQ3210.U32 = sq3210)


/// @fn _SI32_SARADC_A_read_sq3210(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Reads the SQ3210 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SARADC_A_read_sq3210(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_read_sq3210(basePointer)
#define SI32_SARADC_A_read_sq3210(basePointer) \
(basePointer->SQ3210.U32)


/// @fn _SI32_SARADC_A_select_timeslot_channel_character_group(SI32_SARADC_A_Type* basePointer,
///      uint32_t timeslot_num,
///      uint32_t ch_char_group_num)
///
/// @brief
/// Selects the channel character for the specified time slot of the
/// sequencer.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  timeslot_num
///  Valid range is 0 to 7.
///  Sequencer time slot number (0 to 7).
///
/// @param[in]
///  ch_char_group_num
///  Valid range is 0 to 3.
///  Channel characteristic group number (0 to 3).
///
void
_SI32_SARADC_A_select_timeslot_channel_character_group(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t, /*timeslot_num*/
   uint32_t /*ch_char_group_num*/);
///
/// @def SI32_SARADC_A_select_timeslot_channel_character_group(basePointer, timeslot_num, ch_char_group_num)
#define SI32_SARADC_A_select_timeslot_channel_character_group(basePointer, timeslot_num, ch_char_group_num) \
   _SI32_SARADC_A_select_timeslot_channel_character_group(basePointer, timeslot_num, ch_char_group_num) 


/// @fn _SI32_SARADC_A_select_timeslot0_to_use_characteristic0(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot0_to_use_characteristic0(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot0_to_use_characteristic0(basePointer)
#define SI32_SARADC_A_select_timeslot0_to_use_characteristic0(basePointer) \
   (basePointer->SQ3210.TS0CHR = 0)


/// @fn _SI32_SARADC_A_select_timeslot0_to_use_characteristic1(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot0_to_use_characteristic1(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot0_to_use_characteristic1(basePointer)
#define SI32_SARADC_A_select_timeslot0_to_use_characteristic1(basePointer) \
   (basePointer->SQ3210.TS0CHR = 1)


/// @fn _SI32_SARADC_A_select_timeslot0_to_use_characteristic2(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot0_to_use_characteristic2(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot0_to_use_characteristic2(basePointer)
#define SI32_SARADC_A_select_timeslot0_to_use_characteristic2(basePointer) \
   (basePointer->SQ3210.TS0CHR = 2)


/// @fn _SI32_SARADC_A_select_timeslot0_to_use_characteristic3(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot0_to_use_characteristic3(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot0_to_use_characteristic3(basePointer)
#define SI32_SARADC_A_select_timeslot0_to_use_characteristic3(basePointer) \
   (basePointer->SQ3210.TS0CHR = 3)


/// @fn _SI32_SARADC_A_select_timeslot1_to_use_characteristic0(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot1_to_use_characteristic0(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot1_to_use_characteristic0(basePointer)
#define SI32_SARADC_A_select_timeslot1_to_use_characteristic0(basePointer) \
   (basePointer->SQ3210.TS1CHR = 0)


/// @fn _SI32_SARADC_A_select_timeslot1_to_use_characteristic1(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot1_to_use_characteristic1(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot1_to_use_characteristic1(basePointer)
#define SI32_SARADC_A_select_timeslot1_to_use_characteristic1(basePointer) \
   (basePointer->SQ3210.TS1CHR = 1)


/// @fn _SI32_SARADC_A_select_timeslot1_to_use_characteristic2(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot1_to_use_characteristic2(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot1_to_use_characteristic2(basePointer)
#define SI32_SARADC_A_select_timeslot1_to_use_characteristic2(basePointer) \
   (basePointer->SQ3210.TS1CHR = 2)


/// @fn _SI32_SARADC_A_select_timeslot1_to_use_characteristic3(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot1_to_use_characteristic3(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot1_to_use_characteristic3(basePointer)
#define SI32_SARADC_A_select_timeslot1_to_use_characteristic3(basePointer) \
   (basePointer->SQ3210.TS1CHR = 3)


/// @fn _SI32_SARADC_A_select_timeslot2_to_use_characteristic0(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot2_to_use_characteristic0(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot2_to_use_characteristic0(basePointer)
#define SI32_SARADC_A_select_timeslot2_to_use_characteristic0(basePointer) \
   (basePointer->SQ3210.TS2CHR = 0)


/// @fn _SI32_SARADC_A_select_timeslot2_to_use_characteristic1(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot2_to_use_characteristic1(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot2_to_use_characteristic1(basePointer)
#define SI32_SARADC_A_select_timeslot2_to_use_characteristic1(basePointer) \
   (basePointer->SQ3210.TS2CHR = 1)


/// @fn _SI32_SARADC_A_select_timeslot2_to_use_characteristic2(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot2_to_use_characteristic2(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot2_to_use_characteristic2(basePointer)
#define SI32_SARADC_A_select_timeslot2_to_use_characteristic2(basePointer) \
   (basePointer->SQ3210.TS2CHR = 2)


/// @fn _SI32_SARADC_A_select_timeslot2_to_use_characteristic3(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot2_to_use_characteristic3(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot2_to_use_characteristic3(basePointer)
#define SI32_SARADC_A_select_timeslot2_to_use_characteristic3(basePointer) \
   (basePointer->SQ3210.TS2CHR = 3)


/// @fn _SI32_SARADC_A_select_timeslot3_to_use_characteristic0(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot3_to_use_characteristic0(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot3_to_use_characteristic0(basePointer)
#define SI32_SARADC_A_select_timeslot3_to_use_characteristic0(basePointer) \
   (basePointer->SQ3210.TS3CHR = 0)


/// @fn _SI32_SARADC_A_select_timeslot3_to_use_characteristic1(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot3_to_use_characteristic1(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot3_to_use_characteristic1(basePointer)
#define SI32_SARADC_A_select_timeslot3_to_use_characteristic1(basePointer) \
   (basePointer->SQ3210.TS3CHR = 1)


/// @fn _SI32_SARADC_A_select_timeslot3_to_use_characteristic2(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot3_to_use_characteristic2(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot3_to_use_characteristic2(basePointer)
#define SI32_SARADC_A_select_timeslot3_to_use_characteristic2(basePointer) \
   (basePointer->SQ3210.TS3CHR = 2)


/// @fn _SI32_SARADC_A_select_timeslot3_to_use_characteristic3(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot3_to_use_characteristic3(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot3_to_use_characteristic3(basePointer)
#define SI32_SARADC_A_select_timeslot3_to_use_characteristic3(basePointer) \
   (basePointer->SQ3210.TS3CHR = 3)


/// @fn _SI32_SARADC_A_select_timeslot4_to_use_characteristic0(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot4_to_use_characteristic0(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot4_to_use_characteristic0(basePointer)
#define SI32_SARADC_A_select_timeslot4_to_use_characteristic0(basePointer) \
   (basePointer->SQ7654.TS4CHR = 0)


/// @fn _SI32_SARADC_A_select_timeslot4_to_use_characteristic1(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot4_to_use_characteristic1(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot4_to_use_characteristic1(basePointer)
#define SI32_SARADC_A_select_timeslot4_to_use_characteristic1(basePointer) \
   (basePointer->SQ7654.TS4CHR = 1)


/// @fn _SI32_SARADC_A_select_timeslot4_to_use_characteristic2(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot4_to_use_characteristic2(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot4_to_use_characteristic2(basePointer)
#define SI32_SARADC_A_select_timeslot4_to_use_characteristic2(basePointer) \
   (basePointer->SQ7654.TS4CHR = 2)


/// @fn _SI32_SARADC_A_select_timeslot4_to_use_characteristic3(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot4_to_use_characteristic3(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot4_to_use_characteristic3(basePointer)
#define SI32_SARADC_A_select_timeslot4_to_use_characteristic3(basePointer) \
   (basePointer->SQ7654.TS4CHR = 3)


/// @fn _SI32_SARADC_A_select_timeslot5_to_use_characteristic0(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot5_to_use_characteristic0(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot5_to_use_characteristic0(basePointer)
#define SI32_SARADC_A_select_timeslot5_to_use_characteristic0(basePointer) \
   (basePointer->SQ7654.TS5CHR = 0)


/// @fn _SI32_SARADC_A_select_timeslot5_to_use_characteristic1(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot5_to_use_characteristic1(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot5_to_use_characteristic1(basePointer)
#define SI32_SARADC_A_select_timeslot5_to_use_characteristic1(basePointer) \
   (basePointer->SQ7654.TS5CHR = 1)


/// @fn _SI32_SARADC_A_select_timeslot5_to_use_characteristic2(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot5_to_use_characteristic2(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot5_to_use_characteristic2(basePointer)
#define SI32_SARADC_A_select_timeslot5_to_use_characteristic2(basePointer) \
   (basePointer->SQ7654.TS5CHR = 2)


/// @fn _SI32_SARADC_A_select_timeslot5_to_use_characteristic3(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot5_to_use_characteristic3(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot5_to_use_characteristic3(basePointer)
#define SI32_SARADC_A_select_timeslot5_to_use_characteristic3(basePointer) \
   (basePointer->SQ7654.TS5CHR = 3)


/// @fn _SI32_SARADC_A_select_timeslot6_to_use_characteristic0(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot6_to_use_characteristic0(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot6_to_use_characteristic0(basePointer)
#define SI32_SARADC_A_select_timeslot6_to_use_characteristic0(basePointer) \
   (basePointer->SQ7654.TS6CHR = 0)


/// @fn _SI32_SARADC_A_select_timeslot6_to_use_characteristic1(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot6_to_use_characteristic1(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot6_to_use_characteristic1(basePointer)
#define SI32_SARADC_A_select_timeslot6_to_use_characteristic1(basePointer) \
   (basePointer->SQ7654.TS6CHR = 1)


/// @fn _SI32_SARADC_A_select_timeslot6_to_use_characteristic2(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot6_to_use_characteristic2(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot6_to_use_characteristic2(basePointer)
#define SI32_SARADC_A_select_timeslot6_to_use_characteristic2(basePointer) \
   (basePointer->SQ7654.TS6CHR = 2)


/// @fn _SI32_SARADC_A_select_timeslot6_to_use_characteristic3(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot6_to_use_characteristic3(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot6_to_use_characteristic3(basePointer)
#define SI32_SARADC_A_select_timeslot6_to_use_characteristic3(basePointer) \
   (basePointer->SQ7654.TS6CHR = 3)


/// @fn _SI32_SARADC_A_select_timeslot7_to_use_characteristic0(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot7_to_use_characteristic0(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot7_to_use_characteristic0(basePointer)
#define SI32_SARADC_A_select_timeslot7_to_use_characteristic0(basePointer) \
   (basePointer->SQ7654.TS7CHR = 0)


/// @fn _SI32_SARADC_A_select_timeslot7_to_use_characteristic1(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot7_to_use_characteristic1(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot7_to_use_characteristic1(basePointer)
#define SI32_SARADC_A_select_timeslot7_to_use_characteristic1(basePointer) \
   (basePointer->SQ7654.TS7CHR = 1)


/// @fn _SI32_SARADC_A_select_timeslot7_to_use_characteristic2(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot7_to_use_characteristic2(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot7_to_use_characteristic2(basePointer)
#define SI32_SARADC_A_select_timeslot7_to_use_characteristic2(basePointer) \
   (basePointer->SQ7654.TS7CHR = 2)


/// @fn _SI32_SARADC_A_select_timeslot7_to_use_characteristic3(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_timeslot7_to_use_characteristic3(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_timeslot7_to_use_characteristic3(basePointer)
#define SI32_SARADC_A_select_timeslot7_to_use_characteristic3(basePointer) \
   (basePointer->SQ7654.TS7CHR = 3)


/// @fn _SI32_SARADC_A_select_timeslot_channel(SI32_SARADC_A_Type* basePointer,
///      uint32_t timeslot_num,
///      uint32_t channel)
///
/// @brief
/// Sets the channel number for the specified time slot.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  timeslot_num
///  Valid range is 0 to 7.
///  Sequencer time slot number (0 to 7).
///
/// @param[in]
///  channel
///  Valid range is 0 to 31.
///  Channel number (0 to 31).
///
void
_SI32_SARADC_A_select_timeslot_channel(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t, /*timeslot_num*/
   uint32_t /*channel*/);
///
/// @def SI32_SARADC_A_select_timeslot_channel(basePointer, timeslot_num, channel)
#define SI32_SARADC_A_select_timeslot_channel(basePointer, timeslot_num, channel) \
   _SI32_SARADC_A_select_timeslot_channel(basePointer, timeslot_num, channel) 


/// @fn _SI32_SARADC_A_select_timeslot0_channel(SI32_SARADC_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 31.
///  Channel number (0 to 31).
///
void
_SI32_SARADC_A_select_timeslot0_channel(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_SARADC_A_select_timeslot0_channel(basePointer, channel)
#define SI32_SARADC_A_select_timeslot0_channel(basePointer, channel) \
   (basePointer->SQ3210.TS0MUX = channel)


/// @fn _SI32_SARADC_A_select_timeslot1_channel(SI32_SARADC_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 31.
///  Channel number (0 to 31).
///
void
_SI32_SARADC_A_select_timeslot1_channel(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_SARADC_A_select_timeslot1_channel(basePointer, channel)
#define SI32_SARADC_A_select_timeslot1_channel(basePointer, channel) \
   (basePointer->SQ3210.TS1MUX = channel)


/// @fn _SI32_SARADC_A_select_timeslot2_channel(SI32_SARADC_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 31.
///  Channel number (0 to 31).
///
void
_SI32_SARADC_A_select_timeslot2_channel(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_SARADC_A_select_timeslot2_channel(basePointer, channel)
#define SI32_SARADC_A_select_timeslot2_channel(basePointer, channel) \
   (basePointer->SQ3210.TS2MUX = channel)


/// @fn _SI32_SARADC_A_select_timeslot3_channel(SI32_SARADC_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 31.
///  Channel number (0 to 31).
///
void
_SI32_SARADC_A_select_timeslot3_channel(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_SARADC_A_select_timeslot3_channel(basePointer, channel)
#define SI32_SARADC_A_select_timeslot3_channel(basePointer, channel) \
   (basePointer->SQ3210.TS3MUX = channel)


/// @fn _SI32_SARADC_A_select_timeslot4_channel(SI32_SARADC_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 31.
///  Channel number (0 to 31).
///
void
_SI32_SARADC_A_select_timeslot4_channel(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_SARADC_A_select_timeslot4_channel(basePointer, channel)
#define SI32_SARADC_A_select_timeslot4_channel(basePointer, channel) \
   (basePointer->SQ7654.TS4MUX = channel)


/// @fn _SI32_SARADC_A_select_timeslot5_channel(SI32_SARADC_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 31.
///  Channel number (0 to 31).
///
void
_SI32_SARADC_A_select_timeslot5_channel(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_SARADC_A_select_timeslot5_channel(basePointer, channel)
#define SI32_SARADC_A_select_timeslot5_channel(basePointer, channel) \
   (basePointer->SQ7654.TS5MUX = channel)


/// @fn _SI32_SARADC_A_select_timeslot6_channel(SI32_SARADC_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 31.
///  Channel number (0 to 31).
///
void
_SI32_SARADC_A_select_timeslot6_channel(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_SARADC_A_select_timeslot6_channel(basePointer, channel)
#define SI32_SARADC_A_select_timeslot6_channel(basePointer, channel) \
   (basePointer->SQ7654.TS6MUX = channel)


/// @fn _SI32_SARADC_A_select_timeslot7_channel(SI32_SARADC_A_Type* basePointer,
///      uint32_t channel)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  channel
///  Valid range is 0 to 31.
///  Channel number (0 to 31).
///
void
_SI32_SARADC_A_select_timeslot7_channel(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*channel*/);
///
/// @def SI32_SARADC_A_select_timeslot7_channel(basePointer, channel)
#define SI32_SARADC_A_select_timeslot7_channel(basePointer, channel) \
   (basePointer->SQ7654.TS7MUX = channel)


/// @fn _SI32_SARADC_A_write_char32(SI32_SARADC_A_Type* basePointer,
///      uint32_t char32)
///
/// @brief
/// Writes to the CHAR32 register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  char32
///  Valid range is 32 bits.
///
void
_SI32_SARADC_A_write_char32(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*char32*/);
///
/// @def SI32_SARADC_A_write_char32(basePointer, char32)
#define SI32_SARADC_A_write_char32(basePointer, char32) \
   (basePointer->CHAR32.U32 = char32)


/// @fn _SI32_SARADC_A_read_char32(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Reads the CHAR32 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SARADC_A_read_char32(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_read_char32(basePointer)
#define SI32_SARADC_A_read_char32(basePointer) \
(basePointer->CHAR32.U32)


/// @fn _SI32_SARADC_A_write_char10(SI32_SARADC_A_Type* basePointer,
///      uint32_t char10)
///
/// @brief
/// Writes to the CHAR10 register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  char10
///  Valid range is 32 bits.
///
void
_SI32_SARADC_A_write_char10(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*char10*/);
///
/// @def SI32_SARADC_A_write_char10(basePointer, char10)
#define SI32_SARADC_A_write_char10(basePointer, char10) \
   (basePointer->CHAR10.U32 = char10)


/// @fn _SI32_SARADC_A_read_char10(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Reads the CHAR10 register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SARADC_A_read_char10(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_read_char10(basePointer)
#define SI32_SARADC_A_read_char10(basePointer) \
(basePointer->CHAR10.U32)


/// @fn _SI32_SARADC_A_select_channel_character_group_gain_one(SI32_SARADC_A_Type* basePointer,
///      uint32_t ch_char_group_num)
///
/// @brief
/// Selects the on-chip PGA gain to 1 for the specified channel
/// characteristic group.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ch_char_group_num
///  Valid range is 0 to 3.
///  Channel characteristic group number (0 to 3).
///
void
_SI32_SARADC_A_select_channel_character_group_gain_one(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*ch_char_group_num*/);
///
/// @def SI32_SARADC_A_select_channel_character_group_gain_one(basePointer, ch_char_group_num)
#define SI32_SARADC_A_select_channel_character_group_gain_one(basePointer, ch_char_group_num) \
   _SI32_SARADC_A_select_channel_character_group_gain_one(basePointer, ch_char_group_num) 


/// @fn _SI32_SARADC_A_select_channel_characteristic0_gain_one(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic0_gain_one(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic0_gain_one(basePointer)
#define SI32_SARADC_A_select_channel_characteristic0_gain_one(basePointer) \
   (basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0GN_MASK)


/// @fn _SI32_SARADC_A_select_channel_characteristic1_gain_one(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic1_gain_one(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic1_gain_one(basePointer)
#define SI32_SARADC_A_select_channel_characteristic1_gain_one(basePointer) \
   (basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1GN_MASK)


/// @fn _SI32_SARADC_A_select_channel_characteristic2_gain_one(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic2_gain_one(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic2_gain_one(basePointer)
#define SI32_SARADC_A_select_channel_characteristic2_gain_one(basePointer) \
   (basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2GN_MASK)


/// @fn _SI32_SARADC_A_select_channel_characteristic3_gain_one(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic3_gain_one(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic3_gain_one(basePointer)
#define SI32_SARADC_A_select_channel_characteristic3_gain_one(basePointer) \
   (basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3GN_MASK)


/// @fn _SI32_SARADC_A_select_channel_character_group_gain_half(SI32_SARADC_A_Type* basePointer,
///      uint32_t ch_char_group_num)
///
/// @brief
/// Selects the on-chip PGA gain to 0.5 for the specified channel
/// characteristic group.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ch_char_group_num
///  Valid range is 0 to 3.
///  Channel characteristic group number (0 to 3).
///
void
_SI32_SARADC_A_select_channel_character_group_gain_half(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*ch_char_group_num*/);
///
/// @def SI32_SARADC_A_select_channel_character_group_gain_half(basePointer, ch_char_group_num)
#define SI32_SARADC_A_select_channel_character_group_gain_half(basePointer, ch_char_group_num) \
   _SI32_SARADC_A_select_channel_character_group_gain_half(basePointer, ch_char_group_num) 


/// @fn _SI32_SARADC_A_select_channel_characteristic0_gain_half(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic0_gain_half(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic0_gain_half(basePointer)
#define SI32_SARADC_A_select_channel_characteristic0_gain_half(basePointer) \
   (basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR0GN_MASK)


/// @fn _SI32_SARADC_A_select_channel_characteristic1_gain_half(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic1_gain_half(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic1_gain_half(basePointer)
#define SI32_SARADC_A_select_channel_characteristic1_gain_half(basePointer) \
   (basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR1GN_MASK)


/// @fn _SI32_SARADC_A_select_channel_characteristic2_gain_half(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic2_gain_half(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic2_gain_half(basePointer)
#define SI32_SARADC_A_select_channel_characteristic2_gain_half(basePointer) \
   (basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR2GN_MASK)


/// @fn _SI32_SARADC_A_select_channel_characteristic3_gain_half(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic3_gain_half(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic3_gain_half(basePointer)
#define SI32_SARADC_A_select_channel_characteristic3_gain_half(basePointer) \
   (basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR3GN_MASK)


/// @fn _SI32_SARADC_A_select_burst_mode_repeat_count(SI32_SARADC_A_Type* basePointer,
///      uint32_t ch_char_group_num,
///      SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type repeat_count)
///
/// @brief
/// Sets number of conversions to perform and accumulate in Burst Mode for
/// the specified channel characteristic group.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ch_char_group_num
///  Valid range is 0 to 3.
///  Channel characteristic group number (0 to 3).
///
/// @param[in]
///  repeat_count
///  Valid range is 0 to 5.
///  Number of samples to accumulate: 0=1 sample, 1=4 samples, 2=8 samples,
///  3=16 samples, 4=32 samples, 5=64 samples.
///
void
_SI32_SARADC_A_select_burst_mode_repeat_count(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t, /*ch_char_group_num*/
   SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type /*repeat_count*/);
///
/// @def SI32_SARADC_A_select_burst_mode_repeat_count(basePointer, ch_char_group_num, repeat_count)
#define SI32_SARADC_A_select_burst_mode_repeat_count(basePointer, ch_char_group_num, repeat_count) \
   _SI32_SARADC_A_select_burst_mode_repeat_count(basePointer, ch_char_group_num, repeat_count) 


/// @fn _SI32_SARADC_A_select_channel_characteristic0_burst_mode_repeat_count(SI32_SARADC_A_Type* basePointer,
///      SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type repeat_count)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  repeat_count
///  Valid range is 0 to 5.
///  Number of samples to accumulate: 0=1 sample, 1=4 samples, 2=8 samples,
///  3=16 samples, 4=32 samples, 5=64 samples.
///
void
_SI32_SARADC_A_select_channel_characteristic0_burst_mode_repeat_count(SI32_SARADC_A_Type* /*basePointer*/,
   SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type /*repeat_count*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic0_burst_mode_repeat_count(basePointer, repeat_count)
#define SI32_SARADC_A_select_channel_characteristic0_burst_mode_repeat_count(basePointer, repeat_count) do{  \
   basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0RPT_MASK;\
   basePointer->CHAR10_SET = repeat_count << SI32_SARADC_A_CHAR10_CHR0RPT_SHIFT;\
} while(0)


/// @fn _SI32_SARADC_A_select_channel_characteristic1_burst_mode_repeat_count(SI32_SARADC_A_Type* basePointer,
///      SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type repeat_count)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  repeat_count
///  Valid range is 0 to 5.
///  Number of samples to accumulate: 0=1 sample, 1=4 samples, 2=8 samples,
///  3=16 samples, 4=32 samples, 5=64 samples.
///
void
_SI32_SARADC_A_select_channel_characteristic1_burst_mode_repeat_count(SI32_SARADC_A_Type* /*basePointer*/,
   SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type /*repeat_count*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic1_burst_mode_repeat_count(basePointer, repeat_count)
#define SI32_SARADC_A_select_channel_characteristic1_burst_mode_repeat_count(basePointer, repeat_count) do{  \
   basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1RPT_MASK;\
   basePointer->CHAR10_SET = repeat_count << SI32_SARADC_A_CHAR10_CHR1RPT_SHIFT;\
} while(0)


/// @fn _SI32_SARADC_A_select_channel_characteristic2_burst_mode_repeat_count(SI32_SARADC_A_Type* basePointer,
///      SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type repeat_count)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  repeat_count
///  Valid range is 0 to 5.
///  Number of samples to accumulate: 0=1 sample, 1=4 samples, 2=8 samples,
///  3=16 samples, 4=32 samples, 5=64 samples.
///
void
_SI32_SARADC_A_select_channel_characteristic2_burst_mode_repeat_count(SI32_SARADC_A_Type* /*basePointer*/,
   SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type /*repeat_count*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic2_burst_mode_repeat_count(basePointer, repeat_count)
#define SI32_SARADC_A_select_channel_characteristic2_burst_mode_repeat_count(basePointer, repeat_count) do{  \
   basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2RPT_MASK;\
   basePointer->CHAR32_SET = repeat_count << SI32_SARADC_A_CHAR32_CHR2RPT_SHIFT;\
} while(0)


/// @fn _SI32_SARADC_A_select_channel_characteristic3_burst_mode_repeat_count(SI32_SARADC_A_Type* basePointer,
///      SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type repeat_count)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  repeat_count
///  Valid range is 0 to 5.
///  Number of samples to accumulate: 0=1 sample, 1=4 samples, 2=8 samples,
///  3=16 samples, 4=32 samples, 5=64 samples.
///
void
_SI32_SARADC_A_select_channel_characteristic3_burst_mode_repeat_count(SI32_SARADC_A_Type* /*basePointer*/,
   SI32_SARADC_A_BURST_MODE_REPEAT_COUNT_Enum_Type /*repeat_count*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic3_burst_mode_repeat_count(basePointer, repeat_count)
#define SI32_SARADC_A_select_channel_characteristic3_burst_mode_repeat_count(basePointer, repeat_count) do{  \
   basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3RPT_MASK;\
   basePointer->CHAR32_SET = repeat_count << SI32_SARADC_A_CHAR32_CHR3RPT_SHIFT;\
} while(0)


/// @fn _SI32_SARADC_A_select_number_of_left_shift_bits(SI32_SARADC_A_Type* basePointer,
///      uint32_t ch_char_group_num,
///      uint32_t num_left_shift_bits)
///
/// @brief
/// Sets the number of left shift bits to the accumulated 16-bit data; 0s
/// are shifted in to the LSBs.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ch_char_group_num
///  Valid range is 0 to 3.
///  Channel characteristic group number (0 to 3).
///
/// @param[in]
///  num_left_shift_bits
///  Valid range is 0 to 7.
///  Number of left shift bits (0 to 7).
///
void
_SI32_SARADC_A_select_number_of_left_shift_bits(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t, /*ch_char_group_num*/
   uint32_t /*num_left_shift_bits*/);
///
/// @def SI32_SARADC_A_select_number_of_left_shift_bits(basePointer, ch_char_group_num, num_left_shift_bits)
#define SI32_SARADC_A_select_number_of_left_shift_bits(basePointer, ch_char_group_num, num_left_shift_bits) \
   _SI32_SARADC_A_select_number_of_left_shift_bits(basePointer, ch_char_group_num, num_left_shift_bits) 


/// @fn _SI32_SARADC_A_select_channel_characteristic0_left_shift_bits(SI32_SARADC_A_Type* basePointer,
///      uint32_t num_left_shift_bits)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  num_left_shift_bits
///  Valid range is 0 to 7.
///  Number of left shift bits (0 to 7).
///
void
_SI32_SARADC_A_select_channel_characteristic0_left_shift_bits(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*num_left_shift_bits*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic0_left_shift_bits(basePointer, num_left_shift_bits)
#define SI32_SARADC_A_select_channel_characteristic0_left_shift_bits(basePointer, num_left_shift_bits) \
   _SI32_SARADC_A_select_channel_characteristic0_left_shift_bits(basePointer, num_left_shift_bits) 


/// @fn _SI32_SARADC_A_select_channel_characteristic1_left_shift_bits(SI32_SARADC_A_Type* basePointer,
///      uint32_t num_left_shift_bits)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  num_left_shift_bits
///  Valid range is 0 to 7.
///  Number of left shift bits (0 to 7).
///
void
_SI32_SARADC_A_select_channel_characteristic1_left_shift_bits(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*num_left_shift_bits*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic1_left_shift_bits(basePointer, num_left_shift_bits)
#define SI32_SARADC_A_select_channel_characteristic1_left_shift_bits(basePointer, num_left_shift_bits) \
   _SI32_SARADC_A_select_channel_characteristic1_left_shift_bits(basePointer, num_left_shift_bits) 


/// @fn _SI32_SARADC_A_select_channel_characteristic2_left_shift_bits(SI32_SARADC_A_Type* basePointer,
///      uint32_t num_left_shift_bits)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  num_left_shift_bits
///  Valid range is 0 to 7.
///  Number of left shift bits (0 to 7).
///
void
_SI32_SARADC_A_select_channel_characteristic2_left_shift_bits(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*num_left_shift_bits*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic2_left_shift_bits(basePointer, num_left_shift_bits)
#define SI32_SARADC_A_select_channel_characteristic2_left_shift_bits(basePointer, num_left_shift_bits) \
   _SI32_SARADC_A_select_channel_characteristic2_left_shift_bits(basePointer, num_left_shift_bits) 


/// @fn _SI32_SARADC_A_select_channel_characteristic3_left_shift_bits(SI32_SARADC_A_Type* basePointer,
///      uint32_t num_left_shift_bits)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  num_left_shift_bits
///  Valid range is 0 to 7.
///  Number of left shift bits (0 to 7).
///
void
_SI32_SARADC_A_select_channel_characteristic3_left_shift_bits(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*num_left_shift_bits*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic3_left_shift_bits(basePointer, num_left_shift_bits)
#define SI32_SARADC_A_select_channel_characteristic3_left_shift_bits(basePointer, num_left_shift_bits) \
   _SI32_SARADC_A_select_channel_characteristic3_left_shift_bits(basePointer, num_left_shift_bits) 


/// @fn _SI32_SARADC_A_enter_12bit_mode(SI32_SARADC_A_Type* basePointer,
///      uint32_t ch_char_group_num)
///
/// @brief
/// ADC 12-bit mode will be enabled for the specified channel
/// characteristic group; BURSTEN needs to be set to use this with SCAN.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ch_char_group_num
///  Valid range is 0 to 3.
///  Channel characteristic group number (0 to 3).
///
void
_SI32_SARADC_A_enter_12bit_mode(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*ch_char_group_num*/);
///
/// @def SI32_SARADC_A_enter_12bit_mode(basePointer, ch_char_group_num)
#define SI32_SARADC_A_enter_12bit_mode(basePointer, ch_char_group_num) \
   _SI32_SARADC_A_enter_12bit_mode(basePointer, ch_char_group_num) 


/// @fn _SI32_SARADC_A_select_channel_characteristic0_12bit_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic0_12bit_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic0_12bit_mode(basePointer)
#define SI32_SARADC_A_select_channel_characteristic0_12bit_mode(basePointer) \
   (basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR0RSEL_MASK)


/// @fn _SI32_SARADC_A_select_channel_characteristic1_12bit_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic1_12bit_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic1_12bit_mode(basePointer)
#define SI32_SARADC_A_select_channel_characteristic1_12bit_mode(basePointer) \
   (basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR1RSEL_MASK)


/// @fn _SI32_SARADC_A_select_channel_characteristic2_12bit_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic2_12bit_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic2_12bit_mode(basePointer)
#define SI32_SARADC_A_select_channel_characteristic2_12bit_mode(basePointer) \
   (basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR2RSEL_MASK)


/// @fn _SI32_SARADC_A_select_channel_characteristic3_12bit_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic3_12bit_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic3_12bit_mode(basePointer)
#define SI32_SARADC_A_select_channel_characteristic3_12bit_mode(basePointer) \
   (basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR3RSEL_MASK)


/// @fn _SI32_SARADC_A_enter_10bit_mode(SI32_SARADC_A_Type* basePointer,
///      uint32_t ch_char_group_num)
///
/// @brief
/// ADC will be set to 10-bit mode for the specified channel
/// characteristic group.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ch_char_group_num
///  Valid range is 0 to 3.
///  Channel characteristic group number (0 to 3).
///
void
_SI32_SARADC_A_enter_10bit_mode(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*ch_char_group_num*/);
///
/// @def SI32_SARADC_A_enter_10bit_mode(basePointer, ch_char_group_num)
#define SI32_SARADC_A_enter_10bit_mode(basePointer, ch_char_group_num) \
   _SI32_SARADC_A_enter_10bit_mode(basePointer, ch_char_group_num) 


/// @fn _SI32_SARADC_A_select_channel_characteristic0_10bit_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic0_10bit_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic0_10bit_mode(basePointer)
#define SI32_SARADC_A_select_channel_characteristic0_10bit_mode(basePointer) \
   (basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0RSEL_MASK)


/// @fn _SI32_SARADC_A_select_channel_characteristic1_10bit_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic1_10bit_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic1_10bit_mode(basePointer)
#define SI32_SARADC_A_select_channel_characteristic1_10bit_mode(basePointer) \
   (basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1RSEL_MASK)


/// @fn _SI32_SARADC_A_select_channel_characteristic2_10bit_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic2_10bit_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic2_10bit_mode(basePointer)
#define SI32_SARADC_A_select_channel_characteristic2_10bit_mode(basePointer) \
   (basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2RSEL_MASK)


/// @fn _SI32_SARADC_A_select_channel_characteristic3_10bit_mode(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_select_channel_characteristic3_10bit_mode(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_select_channel_characteristic3_10bit_mode(basePointer)
#define SI32_SARADC_A_select_channel_characteristic3_10bit_mode(basePointer) \
   (basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3RSEL_MASK)


/// @fn _SI32_SARADC_A_enable_window_comparison_interrupt(SI32_SARADC_A_Type* basePointer,
///      uint32_t ch_char_group_num)
///
/// @brief
/// Comparison between the accumulated data and the programmed windowing
/// data is enabled for the specified channel charateristic group.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ch_char_group_num
///  Valid range is 0 to 3.
///  Channel characteristic group number (0 to 3).
///
void
_SI32_SARADC_A_enable_window_comparison_interrupt(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*ch_char_group_num*/);
///
/// @def SI32_SARADC_A_enable_window_comparison_interrupt(basePointer, ch_char_group_num)
#define SI32_SARADC_A_enable_window_comparison_interrupt(basePointer, ch_char_group_num) \
   _SI32_SARADC_A_enable_window_comparison_interrupt(basePointer, ch_char_group_num) 


/// @fn _SI32_SARADC_A_enable_characteristic0_window_comparison_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_characteristic0_window_comparison_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_characteristic0_window_comparison_interrupt(basePointer)
#define SI32_SARADC_A_enable_characteristic0_window_comparison_interrupt(basePointer) \
   (basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR0WCIEN_MASK)


/// @fn _SI32_SARADC_A_enable_characteristic1_window_comparison_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_characteristic1_window_comparison_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_characteristic1_window_comparison_interrupt(basePointer)
#define SI32_SARADC_A_enable_characteristic1_window_comparison_interrupt(basePointer) \
   (basePointer->CHAR10_SET = SI32_SARADC_A_CHAR10_CHR1WCIEN_MASK)


/// @fn _SI32_SARADC_A_enable_characteristic2_window_comparison_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_characteristic2_window_comparison_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_characteristic2_window_comparison_interrupt(basePointer)
#define SI32_SARADC_A_enable_characteristic2_window_comparison_interrupt(basePointer) \
   (basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR2WCIEN_MASK)


/// @fn _SI32_SARADC_A_enable_characteristic3_window_comparison_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_enable_characteristic3_window_comparison_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_enable_characteristic3_window_comparison_interrupt(basePointer)
#define SI32_SARADC_A_enable_characteristic3_window_comparison_interrupt(basePointer) \
   (basePointer->CHAR32_SET = SI32_SARADC_A_CHAR32_CHR3WCIEN_MASK)


/// @fn _SI32_SARADC_A_disable_window_comparison_interrupt(SI32_SARADC_A_Type* basePointer,
///      uint32_t ch_char_group_num)
///
/// @brief
/// Comparison between the accumulated data and the programmed windowing
/// data is disabled for the specified channel charateristic group.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ch_char_group_num
///  Valid range is 0 to 3.
///  Channel characteristic group number (0 to 3).
///
void
_SI32_SARADC_A_disable_window_comparison_interrupt(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*ch_char_group_num*/);
///
/// @def SI32_SARADC_A_disable_window_comparison_interrupt(basePointer, ch_char_group_num)
#define SI32_SARADC_A_disable_window_comparison_interrupt(basePointer, ch_char_group_num) \
   _SI32_SARADC_A_disable_window_comparison_interrupt(basePointer, ch_char_group_num) 


/// @fn _SI32_SARADC_A_disable_characteristic0_window_comparison_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_characteristic0_window_comparison_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_characteristic0_window_comparison_interrupt(basePointer)
#define SI32_SARADC_A_disable_characteristic0_window_comparison_interrupt(basePointer) \
   (basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR0WCIEN_MASK)


/// @fn _SI32_SARADC_A_disable_characteristic1_window_comparison_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_characteristic1_window_comparison_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_characteristic1_window_comparison_interrupt(basePointer)
#define SI32_SARADC_A_disable_characteristic1_window_comparison_interrupt(basePointer) \
   (basePointer->CHAR10_CLR = SI32_SARADC_A_CHAR10_CHR1WCIEN_MASK)


/// @fn _SI32_SARADC_A_disable_characteristic2_window_comparison_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_characteristic2_window_comparison_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_characteristic2_window_comparison_interrupt(basePointer)
#define SI32_SARADC_A_disable_characteristic2_window_comparison_interrupt(basePointer) \
   (basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR2WCIEN_MASK)


/// @fn _SI32_SARADC_A_disable_characteristic3_window_comparison_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_disable_characteristic3_window_comparison_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_disable_characteristic3_window_comparison_interrupt(basePointer)
#define SI32_SARADC_A_disable_characteristic3_window_comparison_interrupt(basePointer) \
   (basePointer->CHAR32_CLR = SI32_SARADC_A_CHAR32_CHR3WCIEN_MASK)


/// @fn _SI32_SARADC_A_is_characteristic0_window_comparison_interrupt_enabled(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_characteristic0_window_comparison_interrupt_enabled(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_characteristic0_window_comparison_interrupt_enabled(basePointer)
#define SI32_SARADC_A_is_characteristic0_window_comparison_interrupt_enabled(basePointer) \
((bool)(basePointer->CHAR10.CHR0WCIEN))


/// @fn _SI32_SARADC_A_is_characteristic1_window_comparison_interrupt_enabled(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_characteristic1_window_comparison_interrupt_enabled(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_characteristic1_window_comparison_interrupt_enabled(basePointer)
#define SI32_SARADC_A_is_characteristic1_window_comparison_interrupt_enabled(basePointer) \
((bool)(basePointer->CHAR10.CHR1WCIEN))


/// @fn _SI32_SARADC_A_is_characteristic2_window_comparison_interrupt_enabled(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_characteristic2_window_comparison_interrupt_enabled(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_characteristic2_window_comparison_interrupt_enabled(basePointer)
#define SI32_SARADC_A_is_characteristic2_window_comparison_interrupt_enabled(basePointer) \
((bool)(basePointer->CHAR32.CHR2WCIEN))


/// @fn _SI32_SARADC_A_is_characteristic3_window_comparison_interrupt_enabled(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_characteristic3_window_comparison_interrupt_enabled(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_characteristic3_window_comparison_interrupt_enabled(basePointer)
#define SI32_SARADC_A_is_characteristic3_window_comparison_interrupt_enabled(basePointer) \
((bool)(basePointer->CHAR10.CHR3WCIEN))


/// @fn _SI32_SARADC_A_read_data(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Read ADC conversion result from its data register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SARADC_A_read_data(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_read_data(basePointer)
#define SI32_SARADC_A_read_data(basePointer) \
(basePointer->DATA.U32)


/// @fn _SI32_SARADC_A_write_wclimits(SI32_SARADC_A_Type* basePointer,
///      uint32_t wclimits)
///
/// @brief
/// Writes to the WCLIMITS register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  wclimits
///  Valid range is 32 bits.
///
void
_SI32_SARADC_A_write_wclimits(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*wclimits*/);
///
/// @def SI32_SARADC_A_write_wclimits(basePointer, wclimits)
#define SI32_SARADC_A_write_wclimits(basePointer, wclimits) \
   (basePointer->WCLIMITS.U32 = wclimits)


/// @fn _SI32_SARADC_A_read_wclimits(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Reads the WCLIMITS register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SARADC_A_read_wclimits(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_read_wclimits(basePointer)
#define SI32_SARADC_A_read_wclimits(basePointer) \
(basePointer->WCLIMITS.U32)


/// @fn _SI32_SARADC_A_select_greater_than_window_comparator_limit(SI32_SARADC_A_Type* basePointer,
///      uint32_t adc_gt)
///
/// @brief
/// Sets the 16-bit greater-than window compare value to be used to
/// compare with the accumulated data.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  adc_gt
///  Valid range is 0 to 65535.
///  16-bit right-justified Greater-Than window compare value.
///
void
_SI32_SARADC_A_select_greater_than_window_comparator_limit(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*adc_gt*/);
///
/// @def SI32_SARADC_A_select_greater_than_window_comparator_limit(basePointer, adc_gt)
#define SI32_SARADC_A_select_greater_than_window_comparator_limit(basePointer, adc_gt) \
   (basePointer->WCLIMITS.WCGT = adc_gt)


/// @fn _SI32_SARADC_A_select_less_than_window_comparator_limit(SI32_SARADC_A_Type* basePointer,
///      uint32_t adc_lt)
///
/// @brief
/// Sets the 16-bit less-than window compare value to be used to compare
/// with the accumulated data.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  adc_lt
///  Valid range is 0 to 65535.
///  16-bit right-justified Less-Than window compare value.
///
void
_SI32_SARADC_A_select_less_than_window_comparator_limit(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*adc_lt*/);
///
/// @def SI32_SARADC_A_select_less_than_window_comparator_limit(basePointer, adc_lt)
#define SI32_SARADC_A_select_less_than_window_comparator_limit(basePointer, adc_lt) \
   (basePointer->WCLIMITS.WCLT = adc_lt)


/// @fn _SI32_SARADC_A_select_window_limits(SI32_SARADC_A_Type* basePointer,
///      uint32_t adc_limit0,
///      uint32_t adc_limit1,
///      bool interrupt_in_window)
///
/// @brief
/// Sets the ADC window comparator limits and selects if the interrupt
/// should occur when the data falls within the window or outside the
/// window.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  adc_limit0
///  Valid range is 0 to 65535.
///  16-bit right-justified window compare limit 0.
///
/// @param[in]
///  adc_limit1
///  Valid range is 0 to 65535.
///  16-bit right-justified window compare limit 1.
///
/// @param[in]
///  interrupt_in_window
///  Returns TRUE if data is within the specified limits, returns FALSE if
///  the data is outside the specified limits.
///
void
_SI32_SARADC_A_select_window_limits(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t, /*adc_limit0*/
   uint32_t, /*adc_limit1*/
   bool /*interrupt_in_window*/);
///
/// @def SI32_SARADC_A_select_window_limits(basePointer, adc_limit0, adc_limit1, interrupt_in_window)
#define SI32_SARADC_A_select_window_limits(basePointer, adc_limit0, adc_limit1, interrupt_in_window) \
   _SI32_SARADC_A_select_window_limits(basePointer, adc_limit0, adc_limit1, interrupt_in_window) 


/// @fn _SI32_SARADC_A_write_acc(SI32_SARADC_A_Type* basePointer,
///      uint32_t acc)
///
/// @brief
/// Writes to the ACC register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  acc
///  Valid range is 16 bits.
///
void
_SI32_SARADC_A_write_acc(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*acc*/);
///
/// @def SI32_SARADC_A_write_acc(basePointer, acc)
#define SI32_SARADC_A_write_acc(basePointer, acc) \
   (basePointer->ACC.U32 = acc)


/// @fn _SI32_SARADC_A_clear_accumulator(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// The accumulator used in ADC burst mode will be cleared to 0.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_clear_accumulator(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_clear_accumulator(basePointer)
#define SI32_SARADC_A_clear_accumulator(basePointer) \
   (basePointer->ACC.U32 = 0)


/// @fn _SI32_SARADC_A_write_status(SI32_SARADC_A_Type* basePointer,
///      uint32_t status)
///
/// @brief
/// Writes to the STATUS register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  status
///  Valid range is 32 bits.
///
void
_SI32_SARADC_A_write_status(SI32_SARADC_A_Type* /*basePointer*/,
   uint32_t /*status*/);
///
/// @def SI32_SARADC_A_write_status(basePointer, status)
#define SI32_SARADC_A_write_status(basePointer, status) \
   (basePointer->STATUS.U32 = status)


/// @fn _SI32_SARADC_A_read_status(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Reads the STATUS register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SARADC_A_read_status(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_read_status(basePointer)
#define SI32_SARADC_A_read_status(basePointer) \
(basePointer->STATUS.U32)


/// @fn _SI32_SARADC_A_is_window_compare_interrupt_pending(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Check ADWINT flag.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_window_compare_interrupt_pending(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_window_compare_interrupt_pending(basePointer)
#define SI32_SARADC_A_is_window_compare_interrupt_pending(basePointer) \
((bool)basePointer->STATUS.WCI)


/// @fn _SI32_SARADC_A_clear_window_compare_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Clear ADWINT flag.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_clear_window_compare_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_clear_window_compare_interrupt(basePointer)
#define SI32_SARADC_A_clear_window_compare_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_SARADC_A_STATUS_WCI_MASK)


/// @fn _SI32_SARADC_A_is_single_conversion_complete_interrupt_pending(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Check ADINT flag.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_single_conversion_complete_interrupt_pending(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_single_conversion_complete_interrupt_pending(basePointer)
#define SI32_SARADC_A_is_single_conversion_complete_interrupt_pending(basePointer) \
((bool)basePointer->STATUS.SCCI)


/// @fn _SI32_SARADC_A_clear_single_conversion_complete_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Clear ADINT flag.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_clear_single_conversion_complete_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_clear_single_conversion_complete_interrupt(basePointer)
#define SI32_SARADC_A_clear_single_conversion_complete_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_SARADC_A_STATUS_SCCI_MASK)


/// @fn _SI32_SARADC_A_is_scan_done_interrupt_pending(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Check SCANDN flag.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_scan_done_interrupt_pending(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_scan_done_interrupt_pending(basePointer)
#define SI32_SARADC_A_is_scan_done_interrupt_pending(basePointer) \
((bool)basePointer->STATUS.SDI)


/// @fn _SI32_SARADC_A_clear_scan_done_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Clear SCANDN flag.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_clear_scan_done_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_clear_scan_done_interrupt(basePointer)
#define SI32_SARADC_A_clear_scan_done_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_SARADC_A_STATUS_SDI_MASK)


/// @fn _SI32_SARADC_A_is_fifo_overrun_interrupt_pending(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Check FIFOOF flag.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_fifo_overrun_interrupt_pending(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_fifo_overrun_interrupt_pending(basePointer)
#define SI32_SARADC_A_is_fifo_overrun_interrupt_pending(basePointer) \
((bool)basePointer->STATUS.FORI)


/// @fn _SI32_SARADC_A_clear_fifo_overrun_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Clear FIFOOF flag.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_clear_fifo_overrun_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_clear_fifo_overrun_interrupt(basePointer)
#define SI32_SARADC_A_clear_fifo_overrun_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_SARADC_A_STATUS_FORI_MASK)


/// @fn _SI32_SARADC_A_is_fifo_underrun_interrupt_pending(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Check FIFOUF flag.
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_fifo_underrun_interrupt_pending(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_fifo_underrun_interrupt_pending(basePointer)
#define SI32_SARADC_A_is_fifo_underrun_interrupt_pending(basePointer) \
((bool)basePointer->STATUS.FURI)


/// @fn _SI32_SARADC_A_clear_fifo_underrun_interrupt(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Clear FIFOUF flag.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_clear_fifo_underrun_interrupt(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_clear_fifo_underrun_interrupt(basePointer)
#define SI32_SARADC_A_clear_fifo_underrun_interrupt(basePointer) \
   (basePointer->STATUS_CLR = SI32_SARADC_A_STATUS_FURI_MASK)


/// @fn _SI32_SARADC_A_is_any_interrupt_pending(SI32_SARADC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_SARADC_A_is_any_interrupt_pending(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_is_any_interrupt_pending(basePointer)
#define SI32_SARADC_A_is_any_interrupt_pending(basePointer) \
   _SI32_SARADC_A_is_any_interrupt_pending(basePointer) 


/// @fn _SI32_SARADC_A_clear_all_interrupts(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Clear all ADC interrupt flags.
///
/// @param[in]
///  basePointer
///
void
_SI32_SARADC_A_clear_all_interrupts(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_clear_all_interrupts(basePointer)
#define SI32_SARADC_A_clear_all_interrupts(basePointer) do{  \
   basePointer->STATUS_CLR =\
     (SI32_SARADC_A_STATUS_WCI_MASK\
     | SI32_SARADC_A_STATUS_SCCI_MASK\
     | SI32_SARADC_A_STATUS_SDI_MASK\
     | SI32_SARADC_A_STATUS_FORI_MASK\
     | SI32_SARADC_A_STATUS_FURI_MASK);\
} while(0)


/// @fn _SI32_SARADC_A_read_fifostatus(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Reads the FIFOSTATUS register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SARADC_A_read_fifostatus(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_read_fifostatus(basePointer)
#define SI32_SARADC_A_read_fifostatus(basePointer) \
(basePointer->FIFOSTATUS.U32)


/// @fn _SI32_SARADC_A_get_num_words_in_fifo(SI32_SARADC_A_Type* basePointer)
///
/// @brief
/// Get number of ADC words in the FIFO. Each word may contain one or two
/// samples, depending on the packing mode.
///
/// @return
///  Number of ADC Words in FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_SARADC_A_get_num_words_in_fifo(SI32_SARADC_A_Type* /*basePointer*/);
///
/// @def SI32_SARADC_A_get_num_words_in_fifo(basePointer)
#define SI32_SARADC_A_get_num_words_in_fifo(basePointer) \
(basePointer->FIFOSTATUS.FIFOLVL)



#ifdef __cplusplus
}
#endif

#endif // __SI32_SARADC_A_TYPE_H__

//-eof--------------------------------------------------------------------------
