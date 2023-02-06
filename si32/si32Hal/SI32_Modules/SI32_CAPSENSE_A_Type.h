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
/// @file SI32_CAPSENSE_A_Type.h
//
// Script: 0.59
// HAL Source: 0.5
// Version: 1

#ifndef __SI32_CAPSENSE_A_TYPE_H__
#define __SI32_CAPSENSE_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_CAPSENSE_A_Registers.h"
#include "SI32_CAPSENSE_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_CAPSENSE_A_initialize(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t control,
///      uint32_t mode,
///      uint32_t scanm,
///      uint32_t csth,
///      uint32_t mux)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Write to CONTROL register.
///
/// @param[in]
///  mode
///  Valid range is 32 bits.
///  Write to MODE register.
///
/// @param[in]
///  scanm
///  Valid range is 32 bits.
///  Write to SCANM register.
///
/// @param[in]
///  csth
///  Valid range is 32 bits.
///  Write to CSTH register.
///
/// @param[in]
///  mux
///  Valid range is 32 bits.
///  Write to MUX register.
///
void
_SI32_CAPSENSE_A_initialize(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t, /*control*/
   uint32_t, /*mode*/
   uint32_t, /*scanm*/
   uint32_t, /*csth*/
   uint32_t /*mux*/);
///
/// @def SI32_CAPSENSE_A_initialize(basePointer, control, mode, scanm, csth, mux)
#define SI32_CAPSENSE_A_initialize(basePointer, control, mode, scanm, csth, mux) do{  \
   basePointer->CONTROL.U32 = control;\
   basePointer->MODE.U32    = mode;\
   basePointer->SCAN.U32    = scanm;\
   basePointer->CSTH.U32    = csth;\
   basePointer->MUX.U32     = mux;\
} while(0)


/// @fn _SI32_CAPSENSE_A_write_control(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t control)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Write to CONTROL register.
///
void
_SI32_CAPSENSE_A_write_control(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_CAPSENSE_A_write_control(basePointer, control)
#define SI32_CAPSENSE_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_CAPSENSE_A_read_control(SI32_CAPSENSE_A_Type* basePointer)
///
/// @return
///  Read from CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CAPSENSE_A_read_control(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_read_control(basePointer)
#define SI32_CAPSENSE_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_CAPSENSE_A_is_conversion_in_progress(SI32_CAPSENSE_A_Type* basePointer)
///
/// @return
///  True = conversion is in progress, False = conversion is complete or
///  not currently in progress.
///
/// @param[in]
///  basePointer
///
bool
_SI32_CAPSENSE_A_is_conversion_in_progress(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_is_conversion_in_progress(basePointer)
#define SI32_CAPSENSE_A_is_conversion_in_progress(basePointer) \
((bool)(basePointer->CONTROL.BUSYF))


/// @fn _SI32_CAPSENSE_A_start_manual_conversion(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_start_manual_conversion(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_start_manual_conversion(basePointer)
#define SI32_CAPSENSE_A_start_manual_conversion(basePointer) \
   (basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_BUSYF_MASK)


/// @fn _SI32_CAPSENSE_A_enable_module(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_enable_module(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_enable_module(basePointer)
#define SI32_CAPSENSE_A_enable_module(basePointer) \
   (basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CSEN_MASK)


/// @fn _SI32_CAPSENSE_A_disable_module(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_disable_module(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_disable_module(basePointer)
#define SI32_CAPSENSE_A_disable_module(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CSEN_MASK)


/// @fn _SI32_CAPSENSE_A_enable_bias(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_enable_bias(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_enable_bias(basePointer)
#define SI32_CAPSENSE_A_enable_bias(basePointer) \
   (basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_BIASEN_MASK)


/// @fn _SI32_CAPSENSE_A_disable_bias(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_disable_bias(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_disable_bias(basePointer)
#define SI32_CAPSENSE_A_disable_bias(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_BIASEN_MASK)


/// @fn _SI32_CAPSENSE_A_set_threshold_polarity_to_less_than_or_equal(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_set_threshold_polarity_to_less_than_or_equal(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_set_threshold_polarity_to_less_than_or_equal(basePointer)
#define SI32_CAPSENSE_A_set_threshold_polarity_to_less_than_or_equal(basePointer) \
   (basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CMPPOL_MASK)


/// @fn _SI32_CAPSENSE_A_set_threshold_polarity_to_greater_than(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_set_threshold_polarity_to_greater_than(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_set_threshold_polarity_to_greater_than(basePointer)
#define SI32_CAPSENSE_A_set_threshold_polarity_to_greater_than(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CMPPOL_MASK)


/// @fn _SI32_CAPSENSE_A_select_single_conversion_mode(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_select_single_conversion_mode(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_select_single_conversion_mode(basePointer)
#define SI32_CAPSENSE_A_select_single_conversion_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CMD_MASK)


/// @fn _SI32_CAPSENSE_A_select_single_scan_mode(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_select_single_scan_mode(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_select_single_scan_mode(basePointer)
#define SI32_CAPSENSE_A_select_single_scan_mode(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CMD_MASK;\
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CMD_SCAN_U32;\
} while(0)


/// @fn _SI32_CAPSENSE_A_select_continuous_single_conversion_mode(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_select_continuous_single_conversion_mode(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_select_continuous_single_conversion_mode(basePointer)
#define SI32_CAPSENSE_A_select_continuous_single_conversion_mode(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CMD_MASK;\
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CMD_CONT_SINGLE_U32;\
} while(0)


/// @fn _SI32_CAPSENSE_A_select_continuous_scan_mode(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_select_continuous_scan_mode(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_select_continuous_scan_mode(basePointer)
#define SI32_CAPSENSE_A_select_continuous_scan_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CMD_CONT_SCAN_U32)


/// @fn _SI32_CAPSENSE_A_set_conversion_rate(SI32_CAPSENSE_A_Type* basePointer,
///      SI32_CAPSENSE_A_CONVERSION_RATE_Enum_Type rate)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  rate
///  Valid range is 2 bits.
///  Conversions last n internal capsense clocks and are n bits in length:
///  0 = n is 12, 1 = n is 13, 2 = n is 14, 3 = n is 16.
///
void
_SI32_CAPSENSE_A_set_conversion_rate(SI32_CAPSENSE_A_Type* /*basePointer*/,
   SI32_CAPSENSE_A_CONVERSION_RATE_Enum_Type /*rate*/);
///
/// @def SI32_CAPSENSE_A_set_conversion_rate(basePointer, rate)
#define SI32_CAPSENSE_A_set_conversion_rate(basePointer, rate) do{  \
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CNVR_MASK;\
   basePointer->CONTROL_SET = rate << SI32_CAPSENSE_A_CONTROL_CNVR_SHIFT;\
} while(0)


/// @fn _SI32_CAPSENSE_A_set_number_to_accumulate(SI32_CAPSENSE_A_Type* basePointer,
///      SI32_CAPSENSE_A_ACCUMULATOR_MODE_Enum_Type samples)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  samples
///  Valid range is 0 to 5.
///  Accumulate n samples: 0 = 1 sample, 1 = 4 samples, 2 = 8 samples, 3 =
///  16 samples, 4 = 32 samples, 5 = 64 samples.
///
void
_SI32_CAPSENSE_A_set_number_to_accumulate(SI32_CAPSENSE_A_Type* /*basePointer*/,
   SI32_CAPSENSE_A_ACCUMULATOR_MODE_Enum_Type /*samples*/);
///
/// @def SI32_CAPSENSE_A_set_number_to_accumulate(basePointer, samples)
#define SI32_CAPSENSE_A_set_number_to_accumulate(basePointer, samples) do{  \
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_ACCMD_MASK;\
   basePointer->CONTROL_SET = samples << SI32_CAPSENSE_A_CONTROL_ACCMD_SHIFT;\
} while(0)


/// @fn _SI32_CAPSENSE_A_enter_channels_connected_mode(SI32_CAPSENSE_A_Type* basePointer)
///
/// @brief
/// Channels selected by the scan registers are internally shorted
/// together and the combined node is selected as the capsense input. This
/// mode can be used to detect a capacitance change on multiple channels
/// using a single conversion.
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_enter_channels_connected_mode(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_enter_channels_connected_mode(basePointer)
#define SI32_CAPSENSE_A_enter_channels_connected_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_MCEN_ENABLED_U32)


/// @fn _SI32_CAPSENSE_A_exit_channels_connected_mode(SI32_CAPSENSE_A_Type* basePointer)
///
/// @brief
/// Channels are measured individually.
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_exit_channels_connected_mode(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_exit_channels_connected_mode(basePointer)
#define SI32_CAPSENSE_A_exit_channels_connected_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_MCEN_MASK)


/// @fn _SI32_CAPSENSE_A_set_conversion_start_source(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t source)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  source
///  Valid range is 4 bits.
///  See datasheet for settings information.
///
void
_SI32_CAPSENSE_A_set_conversion_start_source(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t /*source*/);
///
/// @def SI32_CAPSENSE_A_set_conversion_start_source(basePointer, source)
#define SI32_CAPSENSE_A_set_conversion_start_source(basePointer, source) do{  \
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CSCM_MASK;\
   basePointer->CONTROL_SET = source <<\
      SI32_CAPSENSE_A_CONTROL_CSCM_SHIFT;\
} while(0)


/// @fn _SI32_CAPSENSE_A_set_number_of_retries(SI32_CAPSENSE_A_Type* basePointer,
///      SI32_CAPSENSE_A_PIN_MONITOR_MODE_Enum_Type retries)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  retries
///  Valid range is 2 bits.
///  Configures the Pin Monitor Mode bits: 0 = always retry on pin state
///  change, 1 = retry up to twice on consecutive pin change cycles, 2 =
///  retry up to four times on consecutive pin change cycles, 3 = ignore
///  monitored signal state change.
///
void
_SI32_CAPSENSE_A_set_number_of_retries(SI32_CAPSENSE_A_Type* /*basePointer*/,
   SI32_CAPSENSE_A_PIN_MONITOR_MODE_Enum_Type /*retries*/);
///
/// @def SI32_CAPSENSE_A_set_number_of_retries(basePointer, retries)
#define SI32_CAPSENSE_A_set_number_of_retries(basePointer, retries) do{  \
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_PMMD_MASK;\
   basePointer->CONTROL_SET = retries <<\
      SI32_CAPSENSE_A_CONTROL_PMMD_SHIFT;\
} while(0)


/// @fn _SI32_CAPSENSE_A_has_retry_occurred(SI32_CAPSENSE_A_Type* basePointer)
///
/// @return
///  Reads the Pin Monitor Event Flag: True = a retry occurred due to a pin
///  monitor event during the last conversion, False = a retry did not
///  occur due to a pin monitor event during the last conversion.
///
/// @param[in]
///  basePointer
///
bool
_SI32_CAPSENSE_A_has_retry_occurred(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_has_retry_occurred(basePointer)
#define SI32_CAPSENSE_A_has_retry_occurred(basePointer) \
((bool)(basePointer->CONTROL.PMEF))


/// @fn _SI32_CAPSENSE_A_clear_retries_flag(SI32_CAPSENSE_A_Type* basePointer)
///
/// @brief
/// Clears the Pin Monitor Event Flag.
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_clear_retries_flag(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_clear_retries_flag(basePointer)
#define SI32_CAPSENSE_A_clear_retries_flag(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_PMEF_MASK)


/// @fn _SI32_CAPSENSE_A_enable_threshold_compare(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_enable_threshold_compare(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_enable_threshold_compare(basePointer)
#define SI32_CAPSENSE_A_enable_threshold_compare(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CMPEN_MASK;\
   basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CMPEN_ENABLED_U32;\
} while(0)


/// @fn _SI32_CAPSENSE_A_disable_threshold_compare(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_disable_threshold_compare(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_disable_threshold_compare(basePointer)
#define SI32_CAPSENSE_A_disable_threshold_compare(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CMPEN_MASK)


/// @fn _SI32_CAPSENSE_A_is_threshold_compare_enabled(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_CAPSENSE_A_is_threshold_compare_enabled(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_is_threshold_compare_enabled(basePointer)
#define SI32_CAPSENSE_A_is_threshold_compare_enabled(basePointer) \
((bool)(basePointer->CONTROL.CMPEN))


/// @fn _SI32_CAPSENSE_A_enable_conversion_done_interrupt(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_enable_conversion_done_interrupt(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_enable_conversion_done_interrupt(basePointer)
#define SI32_CAPSENSE_A_enable_conversion_done_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_CDIEN_ENABLED_U32)


/// @fn _SI32_CAPSENSE_A_disable_conversion_done_interrupt(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_disable_conversion_done_interrupt(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_disable_conversion_done_interrupt(basePointer)
#define SI32_CAPSENSE_A_disable_conversion_done_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CDIEN_MASK)


/// @fn _SI32_CAPSENSE_A_is_conversion_done_interrupt_enabled(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_CAPSENSE_A_is_conversion_done_interrupt_enabled(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_is_conversion_done_interrupt_enabled(basePointer)
#define SI32_CAPSENSE_A_is_conversion_done_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.CDIEN))


/// @fn _SI32_CAPSENSE_A_enable_end_of_scan_interrupt(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_enable_end_of_scan_interrupt(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_enable_end_of_scan_interrupt(basePointer)
#define SI32_CAPSENSE_A_enable_end_of_scan_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_CAPSENSE_A_CONTROL_EOSIEN_ENABLED_U32)


/// @fn _SI32_CAPSENSE_A_disable_end_of_scan_interrupt(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_disable_end_of_scan_interrupt(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_disable_end_of_scan_interrupt(basePointer)
#define SI32_CAPSENSE_A_disable_end_of_scan_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_EOSIEN_MASK)


/// @fn _SI32_CAPSENSE_A_is_end_of_scan_interrupt_enabled(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_CAPSENSE_A_is_end_of_scan_interrupt_enabled(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_is_end_of_scan_interrupt_enabled(basePointer)
#define SI32_CAPSENSE_A_is_end_of_scan_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.EOSIEN))


/// @fn _SI32_CAPSENSE_A_is_threshold_compare_interrupt_pending(SI32_CAPSENSE_A_Type* basePointer)
///
/// @return
///  True = the capsense result caused a compare interrupt (this bit can
///  only be cleared by disabling the capsense module), False = the
///  capsense result did not cause a compare interrupt.
///
/// @param[in]
///  basePointer
///
bool
_SI32_CAPSENSE_A_is_threshold_compare_interrupt_pending(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_is_threshold_compare_interrupt_pending(basePointer)
#define SI32_CAPSENSE_A_is_threshold_compare_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.CMPI))


/// @fn _SI32_CAPSENSE_A_is_conversion_complete_interrupt_pending(SI32_CAPSENSE_A_Type* basePointer)
///
/// @return
///  True = the capsense module completed a data conversion, False = the
///  capsense module has not completed a data conversion since the last
///  time the pending bit was cleared.
///
/// @param[in]
///  basePointer
///
bool
_SI32_CAPSENSE_A_is_conversion_complete_interrupt_pending(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_is_conversion_complete_interrupt_pending(basePointer)
#define SI32_CAPSENSE_A_is_conversion_complete_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.CDI))


/// @fn _SI32_CAPSENSE_A_clear_conversion_complete_interrupt(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_clear_conversion_complete_interrupt(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_clear_conversion_complete_interrupt(basePointer)
#define SI32_CAPSENSE_A_clear_conversion_complete_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_CAPSENSE_A_CONTROL_CDI_MASK)


/// @fn _SI32_CAPSENSE_A_is_end_of_scan_interrupt_pending(SI32_CAPSENSE_A_Type* basePointer)
///
/// @return
///  True = the capsense module completed scan (this bit can only be
///  cleared by disabling the capsense module), False = the capsense module
///  has not completed a scan since the last time this bit was cleared.
///
/// @param[in]
///  basePointer
///
bool
_SI32_CAPSENSE_A_is_end_of_scan_interrupt_pending(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_is_end_of_scan_interrupt_pending(basePointer)
#define SI32_CAPSENSE_A_is_end_of_scan_interrupt_pending(basePointer) \
((bool)(basePointer->CONTROL.EOSI))


/// @fn _SI32_CAPSENSE_A_write_mode(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t mode)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 32 bits.
///  Write to MODE register.
///
void
_SI32_CAPSENSE_A_write_mode(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t /*mode*/);
///
/// @def SI32_CAPSENSE_A_write_mode(basePointer, mode)
#define SI32_CAPSENSE_A_write_mode(basePointer, mode) \
   (basePointer->MODE.U32 = mode)


/// @fn _SI32_CAPSENSE_A_read_mode(SI32_CAPSENSE_A_Type* basePointer)
///
/// @return
///  Read from MODE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CAPSENSE_A_read_mode(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_read_mode(basePointer)
#define SI32_CAPSENSE_A_read_mode(basePointer) \
(basePointer->MODE.U32)


/// @fn _SI32_CAPSENSE_A_set_gain(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t gain)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  gain
///  Valid range is 3 bits.
///  Select the gain applied to the capacitance measurement. Lower gain
///  values increase the size of the capacitance that can be measured with
///  the capsense module. The capacitance gain is equivalent to gain + 1.
///
void
_SI32_CAPSENSE_A_set_gain(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t /*gain*/);
///
/// @def SI32_CAPSENSE_A_set_gain(basePointer, gain)
#define SI32_CAPSENSE_A_set_gain(basePointer, gain) do{  \
   basePointer->MODE_CLR = SI32_CAPSENSE_A_MODE_CGSEL_MASK;\
   basePointer->MODE_SET = gain << SI32_CAPSENSE_A_MODE_CGSEL_SHIFT;\
} while(0)


/// @fn _SI32_CAPSENSE_A_set_ramp_selection(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t ramp)
///
/// @brief
/// Configures the ramp time. Slower ramp times allow the capsense module
/// to measure buttons with more impedance.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ramp
///  Valid range is 2 bits.
///  Ramp value of 0 = ramp time is less than 1.5 us, 1 = ramp time is
///  between 1.5 us and 3 us, 2 = ramp time is between 3 us and 6 us, 3 =
///  ramp time is greater than 6 us.
///
void
_SI32_CAPSENSE_A_set_ramp_selection(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t /*ramp*/);
///
/// @def SI32_CAPSENSE_A_set_ramp_selection(basePointer, ramp)
#define SI32_CAPSENSE_A_set_ramp_selection(basePointer, ramp) do{  \
   basePointer->MODE_CLR = SI32_CAPSENSE_A_MODE_RAMPSEL_MASK;\
   basePointer->MODE_SET = ramp << SI32_CAPSENSE_A_MODE_RAMPSEL_SHIFT;\
} while(0)


/// @fn _SI32_CAPSENSE_A_set_output_current(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t current)
///
/// @brief
/// Changes the current used to charge the external capacitive element.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  current
///  Valid range is 3 bits.
///  Current value of 0 = full current, 1 = 1/8 current, 2 = 1/4 current, 3
///  = 3/8 current, 4 = 1/2 current, 5 = 5/8 current, 6 = 3/4 current, 7 =
///  7/8 current.
///
void
_SI32_CAPSENSE_A_set_output_current(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t /*current*/);
///
/// @def SI32_CAPSENSE_A_set_output_current(basePointer, current)
#define SI32_CAPSENSE_A_set_output_current(basePointer, current) do{  \
   basePointer->MODE_CLR = SI32_CAPSENSE_A_MODE_IASEL_MASK;\
   basePointer->MODE_SET = current << SI32_CAPSENSE_A_MODE_IASEL_SHIFT;\
} while(0)


/// @fn _SI32_CAPSENSE_A_set_discharge_time(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t time)
///
/// @brief
/// Adjusts the primary reset time.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  time
///  Valid range is 3 bits.
///  Time value of  0 = 0.75 us, 1 = 1.0 us, 2 = 1.2 us, 3 = 1.5 us, 4 = 2
///  us, 5 = 3 us, 6 = 6 us, 7 = 12 us.
///
void
_SI32_CAPSENSE_A_set_discharge_time(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t /*time*/);
///
/// @def SI32_CAPSENSE_A_set_discharge_time(basePointer, time)
#define SI32_CAPSENSE_A_set_discharge_time(basePointer, time) do{  \
   basePointer->MODE_CLR = SI32_CAPSENSE_A_MODE_DTSEL_MASK;\
   basePointer->MODE_SET = time << SI32_CAPSENSE_A_MODE_DTSEL_SHIFT;\
} while(0)


/// @fn _SI32_CAPSENSE_A_read_data(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CAPSENSE_A_read_data(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_read_data(basePointer)
#define SI32_CAPSENSE_A_read_data(basePointer) \
(basePointer->DATA.DATA_BITS)


/// @fn _SI32_CAPSENSE_A_write_scanm(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t scanm)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  scanm
///  Valid range is 32 bits.
///  Write to SCANM register.
///
void
_SI32_CAPSENSE_A_write_scanm(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t /*scanm*/);
///
/// @def SI32_CAPSENSE_A_write_scanm(basePointer, scanm)
#define SI32_CAPSENSE_A_write_scanm(basePointer, scanm) \
   (basePointer->SCAN.U32 = scanm)


/// @fn _SI32_CAPSENSE_A_read_scanm(SI32_CAPSENSE_A_Type* basePointer)
///
/// @return
///  Read from SCANM register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CAPSENSE_A_read_scanm(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_read_scanm(basePointer)
#define SI32_CAPSENSE_A_read_scanm(basePointer) \
(basePointer->SCAN.U32)


/// @fn _SI32_CAPSENSE_A_set_channel_scan_mask(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t mask)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mask
///  Valid range is 16 bits.
///
void
_SI32_CAPSENSE_A_set_channel_scan_mask(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t /*mask*/);
///
/// @def SI32_CAPSENSE_A_set_channel_scan_mask(basePointer, mask)
#define SI32_CAPSENSE_A_set_channel_scan_mask(basePointer, mask) \
   (basePointer->SCAN.U32 = mask)


/// @fn _SI32_CAPSENSE_A_get_channel_scan_mask(SI32_CAPSENSE_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CAPSENSE_A_get_channel_scan_mask(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_get_channel_scan_mask(basePointer)
#define SI32_CAPSENSE_A_get_channel_scan_mask(basePointer) \
(basePointer->SCAN.U32)


/// @fn _SI32_CAPSENSE_A_write_csth(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t csth)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  csth
///  Valid range is 32 bits.
///  Write to CSTH register.
///
void
_SI32_CAPSENSE_A_write_csth(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t /*csth*/);
///
/// @def SI32_CAPSENSE_A_write_csth(basePointer, csth)
#define SI32_CAPSENSE_A_write_csth(basePointer, csth) \
   (basePointer->CSTH.U32 = csth)


/// @fn _SI32_CAPSENSE_A_read_csth(SI32_CAPSENSE_A_Type* basePointer)
///
/// @return
///  Read from CSTH register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CAPSENSE_A_read_csth(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_read_csth(basePointer)
#define SI32_CAPSENSE_A_read_csth(basePointer) \
(basePointer->CSTH.U32)


/// @fn _SI32_CAPSENSE_A_write_mux(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t mux)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mux
///  Valid range is 32 bits.
///  Write to MUX register.
///
void
_SI32_CAPSENSE_A_write_mux(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t /*mux*/);
///
/// @def SI32_CAPSENSE_A_write_mux(basePointer, mux)
#define SI32_CAPSENSE_A_write_mux(basePointer, mux) \
   (basePointer->MUX.U32 = mux)


/// @fn _SI32_CAPSENSE_A_read_mux(SI32_CAPSENSE_A_Type* basePointer)
///
/// @return
///  Read from MUX register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_CAPSENSE_A_read_mux(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_read_mux(basePointer)
#define SI32_CAPSENSE_A_read_mux(basePointer) \
(basePointer->MUX.U32)


/// @fn _SI32_CAPSENSE_A_connect_capsense_channel(SI32_CAPSENSE_A_Type* basePointer)
///
/// @brief
/// Connect the channel selected by the MUX register to the module.
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_connect_capsense_channel(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_connect_capsense_channel(basePointer)
#define SI32_CAPSENSE_A_connect_capsense_channel(basePointer) \
   (basePointer->MUX.CSDISC = SI32_CAPSENSE_A_MUX_CSDISC_CONNECT_VALUE)


/// @fn _SI32_CAPSENSE_A_disconnect_capsense_channel(SI32_CAPSENSE_A_Type* basePointer)
///
/// @brief
/// Disconnects the capacitive sense input channel from the module.
///
/// @param[in]
///  basePointer
///
void
_SI32_CAPSENSE_A_disconnect_capsense_channel(SI32_CAPSENSE_A_Type* /*basePointer*/);
///
/// @def SI32_CAPSENSE_A_disconnect_capsense_channel(basePointer)
#define SI32_CAPSENSE_A_disconnect_capsense_channel(basePointer) \
   (basePointer->MUX.CSDISC = SI32_CAPSENSE_A_MUX_CSDISC_DISCONNECT_VALUE)


/// @fn _SI32_CAPSENSE_A_set_double_reset(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t reset)
///
/// @brief
/// WARNING: THIS FUNCTION IS DEPRECATED AS OF si32-1.1.1. NOT FOR NEW
/// DESIGN. As of this release, the function has no effect device
/// settings.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  reset
///  Valid range is 2 bits.
///
void
_SI32_CAPSENSE_A_set_double_reset(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t /*reset*/);
///
/// @def SI32_CAPSENSE_A_set_double_reset(basePointer, reset)
#define SI32_CAPSENSE_A_set_double_reset(basePointer, reset) \


/// @fn _SI32_CAPSENSE_A_set_low_pass_filter_corner_frequency(SI32_CAPSENSE_A_Type* basePointer,
///      uint32_t filter)
///
/// @brief
/// WARNING: THIS FUNCTION IS DEPRECATED AS OF si32-1.1.1. NOT FOR NEW
/// DESIGN. As of this release, the function has no effect device
/// settings.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  filter
///  Valid range is 3 bits.
///
void
_SI32_CAPSENSE_A_set_low_pass_filter_corner_frequency(SI32_CAPSENSE_A_Type* /*basePointer*/,
   uint32_t /*filter*/);
///
/// @def SI32_CAPSENSE_A_set_low_pass_filter_corner_frequency(basePointer, filter)
#define SI32_CAPSENSE_A_set_low_pass_filter_corner_frequency(basePointer, filter) \



#ifdef __cplusplus
}
#endif

#endif // __SI32_CAPSENSE_A_TYPE_H__

//-eof--------------------------------------------------------------------------
