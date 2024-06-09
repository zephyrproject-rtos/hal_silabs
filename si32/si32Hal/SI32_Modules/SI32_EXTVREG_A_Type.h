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
/// @file SI32_EXTVREG_A_Type.h
//
// Script: 0.58
// HAL Source: 0.3
// Version: 1

#ifndef __SI32_EXTVREG_A_TYPE_H__
#define __SI32_EXTVREG_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_EXTVREG_A_Registers.h"

// support definitions
#include "SI32_EXTVREG_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_EXTVREG_A_initialize(SI32_EXTVREG_A_Type* basePointer,
///      uint32_t config,
///      uint32_t control,
///      uint32_t csconfig,
///      uint32_t cscontrol)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///  Write to CONFIG register.
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Write to CONTROL register.
///
/// @param[in]
///  csconfig
///  Valid range is 32 bits.
///  Write to CSCONTROL register.
///
/// @param[in]
///  cscontrol
///  Valid range is 32 bits.
///  Write to CSCONFIG register.
///
void
_SI32_EXTVREG_A_initialize(SI32_EXTVREG_A_Type* /*basePointer*/,
   uint32_t, /*config*/
   uint32_t, /*control*/
   uint32_t, /*csconfig*/
   uint32_t /*cscontrol*/);
///
/// @def SI32_EXTVREG_A_initialize(basePointer, config, control, csconfig, cscontrol)
#define SI32_EXTVREG_A_initialize(basePointer, config, control, csconfig, cscontrol) do{  \
   basePointer->CONFIG.U32 = config;\
   basePointer->CONTROL.U32 = control;\
   basePointer->CSCONFIG.U32 = csconfig;\
   basePointer->CSCONTROL.U32 = cscontrol;\
} while(0)


/// @fn _SI32_EXTVREG_A_write_control(SI32_EXTVREG_A_Type* basePointer,
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
_SI32_EXTVREG_A_write_control(SI32_EXTVREG_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_EXTVREG_A_write_control(basePointer, control)
#define SI32_EXTVREG_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_EXTVREG_A_read_control(SI32_EXTVREG_A_Type* basePointer)
///
/// @return
///  Read CONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EXTVREG_A_read_control(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_read_control(basePointer)
#define SI32_EXTVREG_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_EXTVREG_A_select_stand_alone_mode(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_select_stand_alone_mode(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_select_stand_alone_mode(basePointer)
#define SI32_EXTVREG_A_select_stand_alone_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_EXTVREG_A_CONTROL_SAEN_MASK)


/// @fn _SI32_EXTVREG_A_select_normal_mode(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_select_normal_mode(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_select_normal_mode(basePointer)
#define SI32_EXTVREG_A_select_normal_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EXTVREG_A_CONTROL_SAEN_MASK)


/// @fn _SI32_EXTVREG_A_enable_weak_pull_up(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_enable_weak_pull_up(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_enable_weak_pull_up(basePointer)
#define SI32_EXTVREG_A_enable_weak_pull_up(basePointer) \
   (basePointer->CONTROL_SET = SI32_EXTVREG_A_CONTROL_WPULLEN_MASK)


/// @fn _SI32_EXTVREG_A_disable_weak_pull_up(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_disable_weak_pull_up(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_disable_weak_pull_up(basePointer)
#define SI32_EXTVREG_A_disable_weak_pull_up(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EXTVREG_A_CONTROL_WPULLEN_MASK)


/// @fn _SI32_EXTVREG_A_enable_foldback_limiting(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_enable_foldback_limiting(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_enable_foldback_limiting(basePointer)
#define SI32_EXTVREG_A_enable_foldback_limiting(basePointer) \
   (basePointer->CONTROL_SET = SI32_EXTVREG_A_CONTROL_FBLEN_MASK)


/// @fn _SI32_EXTVREG_A_disable_foldback_limiting(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_disable_foldback_limiting(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_disable_foldback_limiting(basePointer)
#define SI32_EXTVREG_A_disable_foldback_limiting(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EXTVREG_A_CONTROL_FBLEN_MASK)


/// @fn _SI32_EXTVREG_A_select_transistor_type_npn(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_select_transistor_type_npn(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_select_transistor_type_npn(basePointer)
#define SI32_EXTVREG_A_select_transistor_type_npn(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EXTVREG_A_CONTROL_PNSEL_MASK)


/// @fn _SI32_EXTVREG_A_select_transistor_type_pnp(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_select_transistor_type_pnp(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_select_transistor_type_pnp(basePointer)
#define SI32_EXTVREG_A_select_transistor_type_pnp(basePointer) \
   (basePointer->CONTROL_SET = SI32_EXTVREG_A_CONTROL_PNSEL_MASK)


/// @fn _SI32_EXTVREG_A_select_foldback_sensing_to_exregsn_pin(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_select_foldback_sensing_to_exregsn_pin(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_select_foldback_sensing_to_exregsn_pin(basePointer)
#define SI32_EXTVREG_A_select_foldback_sensing_to_exregsn_pin(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EXTVREG_A_CONTROL_FBPINSEL_MASK)


/// @fn _SI32_EXTVREG_A_select_foldback_sensing_to_vregin_pin(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_select_foldback_sensing_to_vregin_pin(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_select_foldback_sensing_to_vregin_pin(basePointer)
#define SI32_EXTVREG_A_select_foldback_sensing_to_vregin_pin(basePointer) \
   (basePointer->CONTROL_SET = SI32_EXTVREG_A_CONTROL_FBPINSEL_MASK)


/// @fn _SI32_EXTVREG_A_enable_module(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_enable_module(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_enable_module(basePointer)
#define SI32_EXTVREG_A_enable_module(basePointer) \
   (basePointer->CONTROL_SET = SI32_EXTVREG_A_CONTROL_EVREGEN_MASK)


/// @fn _SI32_EXTVREG_A_disable_module(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_disable_module(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_disable_module(basePointer)
#define SI32_EXTVREG_A_disable_module(basePointer) \
   (basePointer->CONTROL_CLR = SI32_EXTVREG_A_CONTROL_EVREGEN_MASK)


/// @fn _SI32_EXTVREG_A_write_config(SI32_EXTVREG_A_Type* basePointer,
///      uint32_t config)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///  Write to CONFIG register.
///
void
_SI32_EXTVREG_A_write_config(SI32_EXTVREG_A_Type* /*basePointer*/,
   uint32_t /*config*/);
///
/// @def SI32_EXTVREG_A_write_config(basePointer, config)
#define SI32_EXTVREG_A_write_config(basePointer, config) \
   (basePointer->CONFIG.U32 = config)


/// @fn _SI32_EXTVREG_A_read_config(SI32_EXTVREG_A_Type* basePointer)
///
/// @return
///  Read CONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EXTVREG_A_read_config(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_read_config(basePointer)
#define SI32_EXTVREG_A_read_config(basePointer) \
(basePointer->CONFIG.U32)


/// @fn _SI32_EXTVREG_A_set_current_limit_minimum(SI32_EXTVREG_A_Type* basePointer,
///      SI32_EXTVREG_A_CURRENT_LIMIT_MIN_COARSE_Enum_Type imin,
///      SI32_EXTVREG_A_CURRENT_LIMIT_MIN_FINE_Enum_Type iminfine)
///
/// @brief
/// Sets the minimum current limit, which is IMIN + IMINFINE.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  imin
///  Valid range is 1 to 8.
///  Coarse current trim, from 1 uA to 8 uA.
///
/// @param[in]
///  iminfine
///  Valid range is 0 to 3.
///  Fine current trim, in 0.25 uA steps (0 = 0 uA, 1 = 0.25 uA, 2 = 0.5
///  uA, 3 = 0.75 uA).
///
void
_SI32_EXTVREG_A_set_current_limit_minimum(SI32_EXTVREG_A_Type* /*basePointer*/,
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_COARSE_Enum_Type, /*imin*/
   SI32_EXTVREG_A_CURRENT_LIMIT_MIN_FINE_Enum_Type /*iminfine*/);
///
/// @def SI32_EXTVREG_A_set_current_limit_minimum(basePointer, imin, iminfine)
#define SI32_EXTVREG_A_set_current_limit_minimum(basePointer, imin, iminfine) do{  \
   basePointer->CONFIG.IMIN = imin-1;\
   basePointer->CONFIG.IMINFINE = iminfine;\
} while(0)


/// @fn _SI32_EXTVREG_A_set_foldback_voltage_offset(SI32_EXTVREG_A_Type* basePointer,
///      uint32_t fbvoff)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  fbvoff
///  Valid range is 0 to 7.
///  Foldback voltage offset, in 0.5V steps (0 = 0V, 1 = 0.5V, ... 7 =
///  3.5V).
///
void
_SI32_EXTVREG_A_set_foldback_voltage_offset(SI32_EXTVREG_A_Type* /*basePointer*/,
   uint32_t /*fbvoff*/);
///
/// @def SI32_EXTVREG_A_set_foldback_voltage_offset(basePointer, fbvoff)
#define SI32_EXTVREG_A_set_foldback_voltage_offset(basePointer, fbvoff) \
   (basePointer->CONFIG.FBVOSEL = fbvoff)


/// @fn _SI32_EXTVREG_A_set_foldback_rate(SI32_EXTVREG_A_Type* basePointer,
///      SI32_EXTVREG_A_FOLDBACK_VOLTAGE_OFFSET_Enum_Type fbrate)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  fbrate
///  Valid range is 0 to 7.
///  Sets foldback rate (0 = 4uA/V, 1 = 2uA/V, 2 = 1uA/V, 3 = 0.5uA/V, 4 =
///  4uA/V, 5 = 8uA/V, 6 = 16uA/V, 7 = 32uA/V).
///
void
_SI32_EXTVREG_A_set_foldback_rate(SI32_EXTVREG_A_Type* /*basePointer*/,
   SI32_EXTVREG_A_FOLDBACK_VOLTAGE_OFFSET_Enum_Type /*fbrate*/);
///
/// @def SI32_EXTVREG_A_set_foldback_rate(basePointer, fbrate)
#define SI32_EXTVREG_A_set_foldback_rate(basePointer, fbrate) \
   (basePointer->CONFIG.FBRATE = fbrate)


/// @fn _SI32_EXTVREG_A_set_current_limit_maximum(SI32_EXTVREG_A_Type* basePointer,
///      SI32_EXTVREG_A_CURRENT_LIMIT_MAX_Enum_Type imax)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  imax
///  Valid range is 2 to 9.
///  Coarse current limit, in uA.
///
void
_SI32_EXTVREG_A_set_current_limit_maximum(SI32_EXTVREG_A_Type* /*basePointer*/,
   SI32_EXTVREG_A_CURRENT_LIMIT_MAX_Enum_Type /*imax*/);
///
/// @def SI32_EXTVREG_A_set_current_limit_maximum(basePointer, imax)
#define SI32_EXTVREG_A_set_current_limit_maximum(basePointer, imax) \
   (basePointer->CONFIG.IMAX = imax-2)


/// @fn _SI32_EXTVREG_A_set_voltage_output(SI32_EXTVREG_A_Type* basePointer,
///      uint32_t vout)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  vout
///  Valid range is 18 to 50.
///  Output voltage times 10 ranging from 18 to 50. (18 = 1.8V, 19 = 1.9V,
///  ... 50 = 5.0V).
///
void
_SI32_EXTVREG_A_set_voltage_output(SI32_EXTVREG_A_Type* /*basePointer*/,
   uint32_t /*vout*/);
///
/// @def SI32_EXTVREG_A_set_voltage_output(basePointer, vout)
#define SI32_EXTVREG_A_set_voltage_output(basePointer, vout) \
   (basePointer->CONFIG.VOUTSEL = vout-18)


/// @fn _SI32_EXTVREG_A_is_max_foldback_reached(SI32_EXTVREG_A_Type* basePointer)
///
/// @return
///  True = the maxium foldback has been reached, False = the maximum
///  foldback has not been reached.
///
/// @param[in]
///  basePointer
///
bool
_SI32_EXTVREG_A_is_max_foldback_reached(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_is_max_foldback_reached(basePointer)
#define SI32_EXTVREG_A_is_max_foldback_reached(basePointer) \
((bool)(basePointer->STATUS.FBMAXF))


/// @fn _SI32_EXTVREG_A_write_cscontrol(SI32_EXTVREG_A_Type* basePointer,
///      uint32_t cscontrol)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  cscontrol
///  Valid range is 32 bits.
///  Write to CSCONTROL register.
///
void
_SI32_EXTVREG_A_write_cscontrol(SI32_EXTVREG_A_Type* /*basePointer*/,
   uint32_t /*cscontrol*/);
///
/// @def SI32_EXTVREG_A_write_cscontrol(basePointer, cscontrol)
#define SI32_EXTVREG_A_write_cscontrol(basePointer, cscontrol) \
   (basePointer->CSCONTROL.U32 = cscontrol)


/// @fn _SI32_EXTVREG_A_read_cscontrol(SI32_EXTVREG_A_Type* basePointer)
///
/// @return
///  Read CSCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EXTVREG_A_read_cscontrol(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_read_cscontrol(basePointer)
#define SI32_EXTVREG_A_read_cscontrol(basePointer) \
(basePointer->CSCONTROL.U32)


/// @fn _SI32_EXTVREG_A_enable_current_sense(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_enable_current_sense(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_enable_current_sense(basePointer)
#define SI32_EXTVREG_A_enable_current_sense(basePointer) \
   (basePointer->CSCONTROL_SET = SI32_EXTVREG_A_CSCONTROL_ISNSEN_MASK)


/// @fn _SI32_EXTVREG_A_disable_current_sense(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_disable_current_sense(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_disable_current_sense(basePointer)
#define SI32_EXTVREG_A_disable_current_sense(basePointer) \
   (basePointer->CSCONTROL_CLR = SI32_EXTVREG_A_CSCONTROL_ISNSEN_MASK)


/// @fn _SI32_EXTVREG_A_enable_adc_current_sense(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_enable_adc_current_sense(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_enable_adc_current_sense(basePointer)
#define SI32_EXTVREG_A_enable_adc_current_sense(basePointer) \
   (basePointer->CSCONTROL_SET = SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_MASK)


/// @fn _SI32_EXTVREG_A_disable_adc_current_sense(SI32_EXTVREG_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_EXTVREG_A_disable_adc_current_sense(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_disable_adc_current_sense(basePointer)
#define SI32_EXTVREG_A_disable_adc_current_sense(basePointer) \
   (basePointer->CSCONTROL_CLR = SI32_EXTVREG_A_CSCONTROL_ADCISNSEN_MASK)


/// @fn _SI32_EXTVREG_A_write_csconfig(SI32_EXTVREG_A_Type* basePointer,
///      uint32_t csconfig)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  csconfig
///  Valid range is 32 bits.
///  Write to CSCONTROL register.
///
void
_SI32_EXTVREG_A_write_csconfig(SI32_EXTVREG_A_Type* /*basePointer*/,
   uint32_t /*csconfig*/);
///
/// @def SI32_EXTVREG_A_write_csconfig(basePointer, csconfig)
#define SI32_EXTVREG_A_write_csconfig(basePointer, csconfig) \
   (basePointer->CSCONFIG.U32 = csconfig)


/// @fn _SI32_EXTVREG_A_read_csconfig(SI32_EXTVREG_A_Type* basePointer)
///
/// @return
///  Read to CSCONFIG register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_EXTVREG_A_read_csconfig(SI32_EXTVREG_A_Type* /*basePointer*/);
///
/// @def SI32_EXTVREG_A_read_csconfig(basePointer)
#define SI32_EXTVREG_A_read_csconfig(basePointer) \
(basePointer->CSCONFIG.U32)


/// @fn _SI32_EXTVREG_A_set_current_sense_adc_channel_gain(SI32_EXTVREG_A_Type* basePointer,
///      SI32_EXTVREG_A_ADC_CURRENT_SENSE_GAIN_Enum_Type mode)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 0 to 4.
///  Selects the ADC current sense gain to: 0 = 16x, 1 = 8x, 2 = 4x, 3 =
///  2x, 4 = 1x.
///
void
_SI32_EXTVREG_A_set_current_sense_adc_channel_gain(SI32_EXTVREG_A_Type* /*basePointer*/,
   SI32_EXTVREG_A_ADC_CURRENT_SENSE_GAIN_Enum_Type /*mode*/);
///
/// @def SI32_EXTVREG_A_set_current_sense_adc_channel_gain(basePointer, mode)
#define SI32_EXTVREG_A_set_current_sense_adc_channel_gain(basePointer, mode) \
   (basePointer->CSCONFIG.ISADCGAIN = mode)


/// @fn _SI32_EXTVREG_A_set_current_sense_extreg_channel_gain(SI32_EXTVREG_A_Type* basePointer,
///      SI32_EXTVREG_A_REG_CURRENT_SENSE_GAIN_Enum_Type mode)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 0 to 4.
///  Selects the external regulator current sense gain to: 0 = 16x, 1 = 8x,
///  2 = 4x, 3 = 2x, 4 = 1x.
///
void
_SI32_EXTVREG_A_set_current_sense_extreg_channel_gain(SI32_EXTVREG_A_Type* /*basePointer*/,
   SI32_EXTVREG_A_REG_CURRENT_SENSE_GAIN_Enum_Type /*mode*/);
///
/// @def SI32_EXTVREG_A_set_current_sense_extreg_channel_gain(basePointer, mode)
#define SI32_EXTVREG_A_set_current_sense_extreg_channel_gain(basePointer, mode) \
   (basePointer->CSCONFIG.ISOGAIN = mode)


/// @fn _SI32_EXTVREG_A_set_current_sensing_mode(SI32_EXTVREG_A_Type* basePointer,
///      uint32_t mode)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  mode
///  Valid range is 0 to 2.
///  Sets the current sensing mode to 0, 1, or 2.
///
void
_SI32_EXTVREG_A_set_current_sensing_mode(SI32_EXTVREG_A_Type* /*basePointer*/,
   uint32_t /*mode*/);
///
/// @def SI32_EXTVREG_A_set_current_sensing_mode(basePointer, mode)
#define SI32_EXTVREG_A_set_current_sensing_mode(basePointer, mode) \
   (basePointer->CSCONFIG.ISINSEL = mode)



#ifdef __cplusplus
}
#endif

#endif // __SI32_EXTVREG_A_TYPE_H__

//-eof--------------------------------------------------------------------------
