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
/// @file SI32_DCDC_A_Type.h
//
// Script: 0.62
// HAL Source: 0.6
// Version: 1

#ifndef __SI32_DCDC_A_TYPE_H__
#define __SI32_DCDC_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_DCDC_A_Registers.h"
#include "SI32_DCDC_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_DCDC_A_initialize(SI32_DCDC_A_Type* basePointer,
///      uint32_t control,
///      uint32_t config)
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
///  config
///  Valid range is 32 bits.
///  Write to CONFIG register.
///
void
_SI32_DCDC_A_initialize(SI32_DCDC_A_Type* /*basePointer*/,
   uint32_t, /*control*/
   uint32_t /*config*/);
///
/// @def SI32_DCDC_A_initialize(basePointer, control, config)
#define SI32_DCDC_A_initialize(basePointer, control, config) do{  \
   basePointer->CONTROL.U32 = control;\
   basePointer->CONFIG.U32 = config;\
} while(0)


/// @fn _SI32_DCDC_A_write_control(SI32_DCDC_A_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Write to CONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 2 bits.
///
void
_SI32_DCDC_A_write_control(SI32_DCDC_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_DCDC_A_write_control(basePointer, control)
#define SI32_DCDC_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_DCDC_A_read_control(SI32_DCDC_A_Type* basePointer)
///
/// @brief
/// Read from CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DCDC_A_read_control(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_read_control(basePointer)
#define SI32_DCDC_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_DCDC_A_is_output_high_flag_set(SI32_DCDC_A_Type* basePointer)
///
/// @brief
/// True = the output voltage is greater than 105% of the programmed
/// output value, False =  the output voltage is less than 105% of the
/// programmed output value.
///
/// @param[in]
///  basePointer
///
bool
_SI32_DCDC_A_is_output_high_flag_set(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_is_output_high_flag_set(basePointer)
#define SI32_DCDC_A_is_output_high_flag_set(basePointer) \
(basePointer->CONTROL.RDYHIGHF)


/// @fn _SI32_DCDC_A_is_output_low_flag_set(SI32_DCDC_A_Type* basePointer)
///
/// @brief
/// True = the output voltage is greater  than RDYLOWTH% of the programmed
/// output value, False = the output voltage is less  than RDYLOWTH% of
/// the programmed output value.
///
/// @param[in]
///  basePointer
///
bool
_SI32_DCDC_A_is_output_low_flag_set(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_is_output_low_flag_set(basePointer)
#define SI32_DCDC_A_is_output_low_flag_set(basePointer) \
(basePointer->CONTROL.RDYLOWF)


/// @fn _SI32_DCDC_A_is_dropout_flag_set(SI32_DCDC_A_Type* basePointer)
///
/// @brief
/// True = the difference between the input and the output voltage is less
/// than 0.4 V, False = The difference between the input and the output
/// voltage is greater than 0.4 V.
///
/// @param[in]
///  basePointer
///
bool
_SI32_DCDC_A_is_dropout_flag_set(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_is_dropout_flag_set(basePointer)
#define SI32_DCDC_A_is_dropout_flag_set(basePointer) \
(basePointer->CONTROL.DROPOUTF)


/// @fn _SI32_DCDC_A_is_bandgap_voltage_above_threshold(SI32_DCDC_A_Type* basePointer)
///
/// @brief
/// True = bandgap voltage is above 0.9 V, False = bandgap voltage is
/// below 0.9 V.
///
/// @param[in]
///  basePointer
///
bool
_SI32_DCDC_A_is_bandgap_voltage_above_threshold(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_is_bandgap_voltage_above_threshold(basePointer)
#define SI32_DCDC_A_is_bandgap_voltage_above_threshold(basePointer) \
(basePointer->CONTROL.BGRDYF)


/// @fn _SI32_DCDC_A_enable_dcdc_oscillator(SI32_DCDC_A_Type* basePointer)
///
/// @brief
/// Enables the DC-DC local oscillator.
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_enable_dcdc_oscillator(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_enable_dcdc_oscillator(basePointer)
#define SI32_DCDC_A_enable_dcdc_oscillator(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_OSCDIS_MASK)


/// @fn _SI32_DCDC_A_disable_dcdc_oscillator(SI32_DCDC_A_Type* basePointer)
///
/// @brief
/// Disables the DC-DC local oscillator.
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_disable_dcdc_oscillator(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_disable_dcdc_oscillator(basePointer)
#define SI32_DCDC_A_disable_dcdc_oscillator(basePointer) \
   (basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_OSCDIS_ACTIVE_U32)


/// @fn _SI32_DCDC_A_select_clock_source_apb(SI32_DCDC_A_Type* basePointer)
///
/// @brief
/// Selects the APB clock as the DC-DC converter clock source.
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_select_clock_source_apb(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_select_clock_source_apb(basePointer)
#define SI32_DCDC_A_select_clock_source_apb(basePointer) \
   (basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_CLKSEL_MASK)


/// @fn _SI32_DCDC_A_select_clock_source_local(SI32_DCDC_A_Type* basePointer)
///
/// @brief
/// Selects the DC-DC local oscillator as the DC-DC converter clock
/// source.
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_select_clock_source_local(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_select_clock_source_local(basePointer)
#define SI32_DCDC_A_select_clock_source_local(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_CLKSEL_MASK)


/// @fn _SI32_DCDC_A_select_clock_divider(SI32_DCDC_A_Type* basePointer,
///      uint32_t divider)
///
/// @brief
/// Divides the input clock (APB) to the DC-DC converter. This setting is
/// only applicable if the APB is selected as the DC-DC clock source.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  divider
///  Valid range is 0 to 4.
///
void
_SI32_DCDC_A_select_clock_divider(SI32_DCDC_A_Type* /*basePointer*/,
   uint32_t /*divider*/);
///
/// @def SI32_DCDC_A_select_clock_divider(basePointer, divider)
#define SI32_DCDC_A_select_clock_divider(basePointer, divider) do{  \
   basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_CLKDIV_MASK;\
   basePointer->CONTROL_SET = divider << SI32_DCDC_A_CONTROL_CLKDIV_SHIFT;\
} while(0)


/// @fn _SI32_DCDC_A_select_adc_synchronous_mode(SI32_DCDC_A_Type* basePointer)
///
/// @brief
/// Synchronizes the ADC with the DC-DC converter.
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_select_adc_synchronous_mode(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_select_adc_synchronous_mode(basePointer)
#define SI32_DCDC_A_select_adc_synchronous_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_ADCSYNCEN_ENABLED_U32)


/// @fn _SI32_DCDC_A_select_adc_asynchronous_mode(SI32_DCDC_A_Type* basePointer)
///
/// @brief
/// Disables synchronizing between the ADC and DC-DC converter.
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_select_adc_asynchronous_mode(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_select_adc_asynchronous_mode(basePointer)
#define SI32_DCDC_A_select_adc_asynchronous_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_ADCSYNCEN_MASK)


/// @fn _SI32_DCDC_A_enable_converter_clock_inversion(SI32_DCDC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_enable_converter_clock_inversion(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_enable_converter_clock_inversion(basePointer)
#define SI32_DCDC_A_enable_converter_clock_inversion(basePointer) \
   (basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_CLKINVEN_ENABLED_U32)


/// @fn _SI32_DCDC_A_disable_converter_clock_inversion(SI32_DCDC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_disable_converter_clock_inversion(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_disable_converter_clock_inversion(basePointer)
#define SI32_DCDC_A_disable_converter_clock_inversion(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_CLKINVEN_MASK)


/// @fn _SI32_DCDC_A_enable_adc_clock_inversion(SI32_DCDC_A_Type* basePointer)
///
/// @brief
/// Inverts the ADC0 clock derived from the DC-DC converter clock when the
/// DC-DC converter is synchronized with ADC0.
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_enable_adc_clock_inversion(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_enable_adc_clock_inversion(basePointer)
#define SI32_DCDC_A_enable_adc_clock_inversion(basePointer) \
   (basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_ADCCLKINVEN_ENABLED_U32)


/// @fn _SI32_DCDC_A_disable_adc_clock_inversion(SI32_DCDC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_disable_adc_clock_inversion(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_disable_adc_clock_inversion(basePointer)
#define SI32_DCDC_A_disable_adc_clock_inversion(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_ADCCLKINVEN_MASK)


/// @fn _SI32_DCDC_A_select_output_voltage(SI32_DCDC_A_Type* basePointer,
///      uint32_t voltage)
///
/// @brief
/// Sets the output voltage of the converter from 1.8 V to 3.6 V. If the
/// voltage parameter is less than 11, the voltage step size is 50 mV. If
/// the voltage paramters is greater than or equal to 11, the voltage step
/// size is 100 mV.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  voltage
///  Valid range is 5 bits.
///
void
_SI32_DCDC_A_select_output_voltage(SI32_DCDC_A_Type* /*basePointer*/,
   uint32_t /*voltage*/);
///
/// @def SI32_DCDC_A_select_output_voltage(basePointer, voltage)
#define SI32_DCDC_A_select_output_voltage(basePointer, voltage) do{  \
   basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_OUTVSEL_MASK;\
   basePointer->CONTROL_SET = voltage << SI32_DCDC_A_CONTROL_OUTVSEL_SHIFT;\
} while(0)


/// @fn _SI32_DCDC_A_enable_interrupt(SI32_DCDC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_enable_interrupt(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_enable_interrupt(basePointer)
#define SI32_DCDC_A_enable_interrupt(basePointer) \
   (basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_MIEN_ENABLED_U32)


/// @fn _SI32_DCDC_A_disable_interrupt(SI32_DCDC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_disable_interrupt(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_disable_interrupt(basePointer)
#define SI32_DCDC_A_disable_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_MIEN_MASK)


/// @fn _SI32_DCDC_A_select_minimum_pulse_width(SI32_DCDC_A_Type* basePointer,
///      SI32_DCDC_MIN_PULSE_WIDTH_Enum_Type width)
///
/// @brief
/// Sets the minimum pulse width to: 0 = no pulse skipping, 1 = 10 ns, 2 =
/// 20 ns, 3 = 40 ns.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  width
///  Valid range is 2 bits.
///
void
_SI32_DCDC_A_select_minimum_pulse_width(SI32_DCDC_A_Type* /*basePointer*/,
   SI32_DCDC_MIN_PULSE_WIDTH_Enum_Type /*width*/);
///
/// @def SI32_DCDC_A_select_minimum_pulse_width(basePointer, width)
#define SI32_DCDC_A_select_minimum_pulse_width(basePointer, width) do{  \
   basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_MINPWSEL_MASK;\
   basePointer->CONTROL_SET = width << SI32_DCDC_A_CONTROL_MINPWSEL_SHIFT;\
} while(0)


/// @fn _SI32_DCDC_A_select_power_switch_size(SI32_DCDC_A_Type* basePointer,
///      uint32_t size)
///
/// @brief
/// Selects the size of the power switches M1, M2. Using smaller switches
/// will result in higher efficiency and lower supply currents.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  size
///  Valid range is 2 bits.
///
void
_SI32_DCDC_A_select_power_switch_size(SI32_DCDC_A_Type* /*basePointer*/,
   uint32_t /*size*/);
///
/// @def SI32_DCDC_A_select_power_switch_size(basePointer, size)
#define SI32_DCDC_A_select_power_switch_size(basePointer, size) do{  \
   basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_PSMD_MASK;\
   basePointer->CONTROL_SET = size << SI32_DCDC_A_CONTROL_PSMD_SHIFT;\
} while(0)


/// @fn _SI32_DCDC_A_enable_async_mode(SI32_DCDC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_enable_async_mode(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_enable_async_mode(basePointer)
#define SI32_DCDC_A_enable_async_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_ASYNCEN_ENABLED_U32)


/// @fn _SI32_DCDC_A_enable_sync_mode(SI32_DCDC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_enable_sync_mode(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_enable_sync_mode(basePointer)
#define SI32_DCDC_A_enable_sync_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_ASYNCEN_MASK)


/// @fn _SI32_DCDC_A_enter_auto_bypass_mode(SI32_DCDC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_enter_auto_bypass_mode(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_enter_auto_bypass_mode(basePointer)
#define SI32_DCDC_A_enter_auto_bypass_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_ABEN_ENABLED_U32)


/// @fn _SI32_DCDC_A_exit_auto_bypass_mode(SI32_DCDC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_exit_auto_bypass_mode(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_exit_auto_bypass_mode(basePointer)
#define SI32_DCDC_A_exit_auto_bypass_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_ABEN_MASK)


/// @fn _SI32_DCDC_A_enter_bypass_mode(SI32_DCDC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_enter_bypass_mode(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_enter_bypass_mode(basePointer)
#define SI32_DCDC_A_enter_bypass_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_BEN_ENABLED_U32)


/// @fn _SI32_DCDC_A_exit_bypass_mode(SI32_DCDC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_exit_bypass_mode(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_exit_bypass_mode(basePointer)
#define SI32_DCDC_A_exit_bypass_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_BEN_MASK)


/// @fn _SI32_DCDC_A_enable_module(SI32_DCDC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_enable_module(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_enable_module(basePointer)
#define SI32_DCDC_A_enable_module(basePointer) \
   (basePointer->CONTROL_SET = SI32_DCDC_A_CONTROL_DCDCEN_ENABLED_U32)


/// @fn _SI32_DCDC_A_disable_module(SI32_DCDC_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_DCDC_A_disable_module(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_disable_module(basePointer)
#define SI32_DCDC_A_disable_module(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DCDC_A_CONTROL_DCDCEN_MASK)


/// @fn _SI32_DCDC_A_write_config(SI32_DCDC_A_Type* basePointer,
///      uint32_t config)
///
/// @brief
/// Write to CONFIG register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///
void
_SI32_DCDC_A_write_config(SI32_DCDC_A_Type* /*basePointer*/,
   uint32_t /*config*/);
///
/// @def SI32_DCDC_A_write_config(basePointer, config)
#define SI32_DCDC_A_write_config(basePointer, config) \
   (basePointer->CONFIG.U32 = config)


/// @fn _SI32_DCDC_A_read_config(SI32_DCDC_A_Type* basePointer)
///
/// @brief
/// Reads from CONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DCDC_A_read_config(SI32_DCDC_A_Type* /*basePointer*/);
///
/// @def SI32_DCDC_A_read_config(basePointer)
#define SI32_DCDC_A_read_config(basePointer) \
(basePointer->CONFIG.U32)


/// @fn _SI32_DCDC_A_select_current_limit(SI32_DCDC_A_Type* basePointer,
///      uint32_t limit)
///
/// @brief
/// Sets the peak current limit to (limit +1) * 100 mA: 0 = reserved, 1 =
/// 200 mA. 2 = 300 mA, 3 = 400 mA, ... , 7 = 800 mA.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  limit
///  Valid range is 3 bits.
///
void
_SI32_DCDC_A_select_current_limit(SI32_DCDC_A_Type* /*basePointer*/,
   uint32_t /*limit*/);
///
/// @def SI32_DCDC_A_select_current_limit(basePointer, limit)
#define SI32_DCDC_A_select_current_limit(basePointer, limit) \
   (basePointer->CONFIG.ILIMIT = limit)


/// @fn _SI32_DCDC_A_select_interrupt_mode(SI32_DCDC_A_Type* basePointer,
///      SI32_DCDC_INTERRUPT_MODE_Enum_Type mode)
///
/// @brief
/// Sets the condition under which a DC-DC converter interrupt occurs, if
/// enabled (MIEN = 1).
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 2 bits.
///
void
_SI32_DCDC_A_select_interrupt_mode(SI32_DCDC_A_Type* /*basePointer*/,
   SI32_DCDC_INTERRUPT_MODE_Enum_Type /*mode*/);
///
/// @def SI32_DCDC_A_select_interrupt_mode(basePointer, mode)
#define SI32_DCDC_A_select_interrupt_mode(basePointer, mode) \
   (basePointer->CONFIG.INTMD = mode)


/// @fn _SI32_DCDC_A_select_converter_ready_low_threshold(SI32_DCDC_A_Type* basePointer,
///      SI32_DCDC_READY_LOW_THRESHOLD_Enum_Type threshold)
///
/// @brief
/// Sets the percentage of the programmed output voltage to compare with
/// the regulated output voltage threshold for setting the RDYLOWF flag:
/// 0=95%, 1=90%, 2=85%, 3=80%.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Valid range is 2 bits.
///
void
_SI32_DCDC_A_select_converter_ready_low_threshold(SI32_DCDC_A_Type* /*basePointer*/,
   SI32_DCDC_READY_LOW_THRESHOLD_Enum_Type /*threshold*/);
///
/// @def SI32_DCDC_A_select_converter_ready_low_threshold(basePointer, threshold)
#define SI32_DCDC_A_select_converter_ready_low_threshold(basePointer, threshold) \
   (basePointer->CONFIG.RDYLOWTH = threshold)



#ifdef __cplusplus
}
#endif

#endif // __SI32_DCDC_A_TYPE_H__

//-eof--------------------------------------------------------------------------
