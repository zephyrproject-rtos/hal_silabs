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
/// @file SI32_PBHD_A_Type.h
//
// This file applies to the SIM3C1XX_PBHD_A module
//
// Script: 0.58
// HAL Source: 0.1
// Version: 1

#ifndef __SI32_PBHD_A_TYPE_H__
#define __SI32_PBHD_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_SIM3C1XX_PBHD_A_Registers.h"

// support definitions
#include "SI32_PBHD_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_PBHD_A_initialize(SI32_PBHD_A_Type* basePointer,
///      uint32_t pb,
///      uint32_t pbmdsel,
///      uint32_t pbden,
///      uint32_t pbdrv,
///      uint32_t pbilimit,
///      uint32_t pbfsel,
///      uint32_t pbss,
///      uint32_t pblock)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pb
///  Valid range is 32 bits.
///  Write to PB register.
///
/// @param[in]
///  pbmdsel
///  Valid range is 32 bits.
///  Write to PBMDSEL register.
///
/// @param[in]
///  pbden
///  Valid range is 32 bits.
///  Write to PBDEN register.
///
/// @param[in]
///  pbdrv
///  Valid range is 32 bits.
///  Write to PBDRV register.
///
/// @param[in]
///  pbilimit
///  Valid range is 32 bits.
///  Write to PBILIMIT register.
///
/// @param[in]
///  pbfsel
///  Valid range is 32 bits.
///  Write to PBFSEL register.
///
/// @param[in]
///  pbss
///  Valid range is 32 bits.
///  Write to PBSS register.
///
/// @param[in]
///  pblock
///  Valid range is 32 bits.
///  Writes to PBLOCK register.
///
void
_SI32_PBHD_A_initialize(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t, /*pb*/
   uint32_t, /*pbmdsel*/
   uint32_t, /*pbden*/
   uint32_t, /*pbdrv*/
   uint32_t, /*pbilimit*/
   uint32_t, /*pbfsel*/
   uint32_t, /*pbss*/
   uint32_t /*pblock*/);
///
/// @def SI32_PBHD_A_initialize(basePointer, pb, pbmdsel, pbden, pbdrv, pbilimit, pbfsel, pbss, pblock)
#define SI32_PBHD_A_initialize(basePointer, pb, pbmdsel, pbden, pbdrv, pbilimit, pbfsel, pbss, pblock) do{  \
   basePointer->PB.U32       = pb;\
   basePointer->PBMDSEL.U32  = pbmdsel;\
   basePointer->PBDEN.U32    = pbden;\
   basePointer->PBDRV.U32    = pbdrv;\
   basePointer->PBILIMIT.U32 = pbilimit;\
   basePointer->PBFSEL.U32   = pbfsel;\
   basePointer->PBSS.U32     = pbss;\
   basePointer->PBLOCK.U32   = pblock;\
} while(0)


/// @fn _SI32_PBHD_A_write_pb(SI32_PBHD_A_Type* basePointer,
///      uint32_t pb)
///
/// @brief
/// Writes to PB register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pb
///  Valid range is 32 bits.
///
void
_SI32_PBHD_A_write_pb(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pb*/);
///
/// @def SI32_PBHD_A_write_pb(basePointer, pb)
#define SI32_PBHD_A_write_pb(basePointer, pb) \
   (basePointer->PB.U32 = pb)


/// @fn _SI32_PBHD_A_read_pb(SI32_PBHD_A_Type* basePointer)
///
/// @brief
/// Reads PB register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBHD_A_read_pb(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_read_pb(basePointer)
#define SI32_PBHD_A_read_pb(basePointer) \
(basePointer->PB.U32)


/// @fn _SI32_PBHD_A_write_pins_high(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_mask)
///
/// @brief
/// Writes selected pins high.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///  Mask for pin writes : 1 = set pin to high.
///
void
_SI32_PBHD_A_write_pins_high(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_write_pins_high(basePointer, pin_mask)
#define SI32_PBHD_A_write_pins_high(basePointer, pin_mask) \
   (basePointer->PB_SET = pin_mask)


/// @fn _SI32_PBHD_A_write_pins_low(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_mask)
///
/// @brief
/// Writes selected pins low.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///  Mask for pin writes : 1 = clear pin to low.
///
void
_SI32_PBHD_A_write_pins_low(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_write_pins_low(basePointer, pin_mask)
#define SI32_PBHD_A_write_pins_low(basePointer, pin_mask) \
   (basePointer->PB_CLR = pin_mask)


/// @fn _SI32_PBHD_A_write_pins_masked(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_value,
///      uint32_t pin_mask)
///
/// @brief
/// Write selected pins.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_value
///  Valid range is 6 bits.
///  Values for latch.
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///  Mask value : 1 = write, 0 = ignore.
///
void
_SI32_PBHD_A_write_pins_masked(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t, /*pin_value*/
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_write_pins_masked(basePointer, pin_value, pin_mask)
#define SI32_PBHD_A_write_pins_masked(basePointer, pin_value, pin_mask) \
   (basePointer->PB_MSK = (pin_mask<<16)|(pin_value))


/// @fn _SI32_PBHD_A_toggle_pins(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_mask)
///
/// @brief
/// Toggle selected pins.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///  Mask for pin toggles : 1 = toggle pin.
///
void
_SI32_PBHD_A_toggle_pins(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_toggle_pins(basePointer, pin_mask)
#define SI32_PBHD_A_toggle_pins(basePointer, pin_mask) \
   (basePointer->PB_MSK = (pin_mask<<16)|(~(basePointer->PB.U32) & 0xFFFF))


/// @fn _SI32_PBHD_A_read_pins(SI32_PBHD_A_Type* basePointer)
///
/// @brief
/// Reads PBPIN register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBHD_A_read_pins(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_read_pins(basePointer)
#define SI32_PBHD_A_read_pins(basePointer) \
((basePointer->PBPIN.U32))


/// @fn _SI32_PBHD_A_read_pin(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_number)
///
/// @brief
/// Reads the state of a single pin.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_number
///  Valid range is 6 bits.
///  Number of the pin to read : 0 = pin 0.
///
uint32_t
_SI32_PBHD_A_read_pin(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_number*/);
///
/// @def SI32_PBHD_A_read_pin(basePointer, pin_number)
#define SI32_PBHD_A_read_pin(basePointer, pin_number) \
(((basePointer->PBPIN.U32) >> pin_number) & 1)


/// @fn _SI32_PBHD_A_write_pbmdsel(SI32_PBHD_A_Type* basePointer,
///      uint32_t pbmdsel)
///
/// @brief
/// Writes to PBMDSEL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pbmdsel
///  Valid range is 32 bits.
///
void
_SI32_PBHD_A_write_pbmdsel(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pbmdsel*/);
///
/// @def SI32_PBHD_A_write_pbmdsel(basePointer, pbmdsel)
#define SI32_PBHD_A_write_pbmdsel(basePointer, pbmdsel) \
   (basePointer->PBMDSEL.U32 = pbmdsel)


/// @fn _SI32_PBHD_A_read_pbmdsel(SI32_PBHD_A_Type* basePointer)
///
/// @brief
/// Reads PBMDSEL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBHD_A_read_pbmdsel(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_read_pbmdsel(basePointer)
#define SI32_PBHD_A_read_pbmdsel(basePointer) \
(basePointer->PBMDSEL.U32)


/// @fn _SI32_PBHD_A_set_pins_push_pull_output(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_mask)
///
/// @brief
/// Sets the pins masked with 1's to digital push-pull.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///  Selects which pins to configure digital push-pull.
///
void
_SI32_PBHD_A_set_pins_push_pull_output(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_set_pins_push_pull_output(basePointer, pin_mask)
#define SI32_PBHD_A_set_pins_push_pull_output(basePointer, pin_mask) do{  \
	basePointer->PBMDSEL_SET = pin_mask;\
   basePointer->PBDEN_SET =\
      pin_mask << SI32_PBHD_A_PBDEN_PBNDEN_SHIFT;\
   basePointer->PBDEN_SET =\
      pin_mask << SI32_PBHD_A_PBDEN_PBPDEN_SHIFT;\
} while(0)


/// @fn _SI32_PBHD_A_set_pins_digital_input(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_mask)
///
/// @brief
/// Sets the pins masked with 1's to open-drain input.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///  Selects which pins to configure open-drain input.
///
void
_SI32_PBHD_A_set_pins_digital_input(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_set_pins_digital_input(basePointer, pin_mask)
#define SI32_PBHD_A_set_pins_digital_input(basePointer, pin_mask) do{  \
   basePointer->PBMDSEL_SET = pin_mask;\
   basePointer->PBDEN_SET =\
      pin_mask << SI32_PBHD_A_PBDEN_PBNDEN_SHIFT;\
   basePointer->PBDEN_CLR =\
      pin_mask << SI32_PBHD_A_PBDEN_PBPDEN_SHIFT;\
   basePointer->PB_SET = pin_mask;\
} while(0)


/// @fn _SI32_PBHD_A_set_pins_analog(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_mask)
///
/// @brief
/// Sets the pins masked with 1's to analog mode.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///  Selects which pins to configure as analog.
///
void
_SI32_PBHD_A_set_pins_analog(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_set_pins_analog(basePointer, pin_mask)
#define SI32_PBHD_A_set_pins_analog(basePointer, pin_mask) do{  \
   basePointer->PBMDSEL_CLR = pin_mask;\
   basePointer->PBDEN_CLR =\
      pin_mask << SI32_PBHD_A_PBDEN_PBNDEN_SHIFT;\
   basePointer->PBDEN_CLR =\
      pin_mask << SI32_PBHD_A_PBDEN_PBPDEN_SHIFT;\
} while(0)


/// @fn _SI32_PBHD_A_set_pins_weak_pulldown(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_mask)
///
/// @brief
/// Sets the pins masked with 1's to weak pulldown.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///  Selects which pins to configure as weak pulldown.
///
void
_SI32_PBHD_A_set_pins_weak_pulldown(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_set_pins_weak_pulldown(basePointer, pin_mask)
#define SI32_PBHD_A_set_pins_weak_pulldown(basePointer, pin_mask) do{  \
   basePointer->PBMDSEL_SET = pin_mask;\
   basePointer->PBDEN_SET =\
      pin_mask << SI32_PBHD_A_PBDEN_PBPDEN_SHIFT;\
   basePointer->PBDEN_CLR =\
      pin_mask << SI32_PBHD_A_PBDEN_PBNDEN_SHIFT;\
   basePointer->PB_CLR = pin_mask;\
} while(0)


/// @fn _SI32_PBHD_A_write_pbden(SI32_PBHD_A_Type* basePointer,
///      uint32_t pbden)
///
/// @brief
/// Writes to PBDEN register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pbden
///  Valid range is 32 bits.
///
void
_SI32_PBHD_A_write_pbden(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pbden*/);
///
/// @def SI32_PBHD_A_write_pbden(basePointer, pbden)
#define SI32_PBHD_A_write_pbden(basePointer, pbden) \
   (basePointer->PBDEN.U32 = pbden)


/// @fn _SI32_PBHD_A_read_pbden(SI32_PBHD_A_Type* basePointer)
///
/// @brief
/// Read PBDEN register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBHD_A_read_pbden(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_read_pbden(basePointer)
#define SI32_PBHD_A_read_pbden(basePointer) \
(basePointer->PBDEN.U32)


/// @fn _SI32_PBHD_A_enable_n_channel_drivers(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_mask)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///  Each bit corresponds to a pin.
///
void
_SI32_PBHD_A_enable_n_channel_drivers(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_enable_n_channel_drivers(basePointer, pin_mask)
#define SI32_PBHD_A_enable_n_channel_drivers(basePointer, pin_mask) \
   (basePointer->PBDEN.PBNDEN |= pin_mask)


/// @fn _SI32_PBHD_A_disable_n_channel_drivers(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_mask)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///  Each bit corresponds to a pin.
///
void
_SI32_PBHD_A_disable_n_channel_drivers(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_disable_n_channel_drivers(basePointer, pin_mask)
#define SI32_PBHD_A_disable_n_channel_drivers(basePointer, pin_mask) \
   (basePointer->PBDEN.PBNDEN &= ~pin_mask)


/// @fn _SI32_PBHD_A_enable_p_channel_drivers(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_mask)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///  Each bit corresponds to a pin.
///
void
_SI32_PBHD_A_enable_p_channel_drivers(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_enable_p_channel_drivers(basePointer, pin_mask)
#define SI32_PBHD_A_enable_p_channel_drivers(basePointer, pin_mask) \
   (basePointer->PBDEN.PBPDEN |= pin_mask)


/// @fn _SI32_PBHD_A_disable_p_channel_drivers(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_mask)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///  Each bit corresponds to a pin.
///
void
_SI32_PBHD_A_disable_p_channel_drivers(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_disable_p_channel_drivers(basePointer, pin_mask)
#define SI32_PBHD_A_disable_p_channel_drivers(basePointer, pin_mask) \
   (basePointer->PBDEN.PBPDEN &= ~pin_mask)


/// @fn _SI32_PBHD_A_write_pbdrv(SI32_PBHD_A_Type* basePointer,
///      uint32_t pbdrv)
///
/// @brief
/// Writes to PBDRV register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pbdrv
///  Valid range is 32 bits.
///
void
_SI32_PBHD_A_write_pbdrv(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pbdrv*/);
///
/// @def SI32_PBHD_A_write_pbdrv(basePointer, pbdrv)
#define SI32_PBHD_A_write_pbdrv(basePointer, pbdrv) \
   (basePointer->PBDRV.U32 = pbdrv)


/// @fn _SI32_PBHD_A_read_pbdrv(SI32_PBHD_A_Type* basePointer)
///
/// @brief
/// Reads PBDRV register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBHD_A_read_pbdrv(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_read_pbdrv(basePointer)
#define SI32_PBHD_A_read_pbdrv(basePointer) \
(basePointer->PBDRV.U32)


/// @fn _SI32_PBHD_A_set_pins_high_drive_strength(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_mask)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///
void
_SI32_PBHD_A_set_pins_high_drive_strength(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_set_pins_high_drive_strength(basePointer, pin_mask)
#define SI32_PBHD_A_set_pins_high_drive_strength(basePointer, pin_mask) \
   (basePointer->PBDRV_SET = pin_mask << SI32_PBHD_A_PBDRV_PBDRV_SHIFT)


/// @fn _SI32_PBHD_A_set_pins_low_drive_strength(SI32_PBHD_A_Type* basePointer,
///      uint32_t pin_mask)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 6 bits.
///
void
_SI32_PBHD_A_set_pins_low_drive_strength(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBHD_A_set_pins_low_drive_strength(basePointer, pin_mask)
#define SI32_PBHD_A_set_pins_low_drive_strength(basePointer, pin_mask) \
   (basePointer->PBDRV_CLR = pin_mask << SI32_PBHD_A_PBDRV_PBDRV_SHIFT)


/// @fn _SI32_PBHD_A_enable_pullup_resistors(SI32_PBHD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_enable_pullup_resistors(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_enable_pullup_resistors(basePointer)
#define SI32_PBHD_A_enable_pullup_resistors(basePointer) \
   (basePointer->PBDRV_SET = SI32_PBHD_A_PBDRV_PBPUEN_MASK)


/// @fn _SI32_PBHD_A_disable_pullup_resistors(SI32_PBHD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_disable_pullup_resistors(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_disable_pullup_resistors(basePointer)
#define SI32_PBHD_A_disable_pullup_resistors(basePointer) \
   (basePointer->PBDRV_CLR = SI32_PBHD_A_PBDRV_PBPUEN_MASK)


/// @fn _SI32_PBHD_A_select_low_power_port_mode(SI32_PBHD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_select_low_power_port_mode(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_select_low_power_port_mode(basePointer)
#define SI32_PBHD_A_select_low_power_port_mode(basePointer) \
   (basePointer->PBDRV_SET = SI32_PBHD_A_PBDRV_PBLVMD_MASK)


/// @fn _SI32_PBHD_A_select_normal_power_port_mode(SI32_PBHD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_select_normal_power_port_mode(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_select_normal_power_port_mode(basePointer)
#define SI32_PBHD_A_select_normal_power_port_mode(basePointer) \
   (basePointer->PBDRV_CLR = SI32_PBHD_A_PBDRV_PBLVMD_MASK)


/// @fn _SI32_PBHD_A_select_slew_rate(SI32_PBHD_A_Type* basePointer,
///      SI32_PBHD_A_Slew_Enum_Type rate)
///
/// @brief
/// Select the slew rate for all port pins.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  rate
///  Valid range is 2 bits.
///
void
_SI32_PBHD_A_select_slew_rate(SI32_PBHD_A_Type* /*basePointer*/,
   SI32_PBHD_A_Slew_Enum_Type /*rate*/);
///
/// @def SI32_PBHD_A_select_slew_rate(basePointer, rate)
#define SI32_PBHD_A_select_slew_rate(basePointer, rate) do{  \
   basePointer->PBDRV_CLR = SI32_PBHD_A_PBDRV_PBSLEW_MASK;\
   basePointer->PBDRV_SET = rate << SI32_PBHD_A_PBDRV_PBSLEW_SHIFT;\
} while(0)


/// @fn _SI32_PBHD_A_enable_bias(SI32_PBHD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_enable_bias(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_enable_bias(basePointer)
#define SI32_PBHD_A_enable_bias(basePointer) \
   (basePointer->PBDRV_SET = SI32_PBHD_A_PBDRV_PBBIASEN_MASK)


/// @fn _SI32_PBHD_A_disable_bias(SI32_PBHD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_disable_bias(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_disable_bias(basePointer)
#define SI32_PBHD_A_disable_bias(basePointer) \
   (basePointer->PBDRV_CLR = SI32_PBHD_A_PBDRV_PBBIASEN_MASK)


/// @fn _SI32_PBHD_A_enable_drivers(SI32_PBHD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_enable_drivers(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_enable_drivers(basePointer)
#define SI32_PBHD_A_enable_drivers(basePointer) \
   (basePointer->PBDRV_SET = SI32_PBHD_A_PBDRV_PBDRVEN_MASK)


/// @fn _SI32_PBHD_A_disable_drivers(SI32_PBHD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_disable_drivers(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_disable_drivers(basePointer)
#define SI32_PBHD_A_disable_drivers(basePointer) \
   (basePointer->PBDRV_CLR = SI32_PBHD_A_PBDRV_PBDRVEN_MASK)


/// @fn _SI32_PBHD_A_enable_vddhd_tracking(SI32_PBHD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_enable_vddhd_tracking(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_enable_vddhd_tracking(basePointer)
#define SI32_PBHD_A_enable_vddhd_tracking(basePointer) \
   (basePointer->PBDRV_SET = SI32_PBHD_A_PBDRV_PBVTRKEN_MASK)


/// @fn _SI32_PBHD_A_disable_vddhd_tracking(SI32_PBHD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_disable_vddhd_tracking(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_disable_vddhd_tracking(basePointer)
#define SI32_PBHD_A_disable_vddhd_tracking(basePointer) \
   (basePointer->PBDRV_CLR = SI32_PBHD_A_PBDRV_PBVTRKEN_MASK)


/// @fn _SI32_PBHD_A_write_pbilimit(SI32_PBHD_A_Type* basePointer,
///      uint32_t ilimit)
///
/// @brief
/// Writes to PBLIMIT register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ilimit
///  Valid range is 32 bits.
///
void
_SI32_PBHD_A_write_pbilimit(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*ilimit*/);
///
/// @def SI32_PBHD_A_write_pbilimit(basePointer, ilimit)
#define SI32_PBHD_A_write_pbilimit(basePointer, ilimit) \
   (basePointer->PBILIMIT.U32 = ilimit)


/// @fn _SI32_PBHD_A_read_pbilimit(SI32_PBHD_A_Type* basePointer)
///
/// @brief
/// Read PBILIMIT.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBHD_A_read_pbilimit(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_read_pbilimit(basePointer)
#define SI32_PBHD_A_read_pbilimit(basePointer) \
(basePointer->PBILIMIT.U32)


/// @fn _SI32_PBHD_A_enable_pin_current_limit(SI32_PBHD_A_Type* basePointer,
///      uint32_t pins)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pins
///  Valid range is 6 bits.
///  Each bit corresponds to a pin.
///
void
_SI32_PBHD_A_enable_pin_current_limit(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pins*/);
///
/// @def SI32_PBHD_A_enable_pin_current_limit(basePointer, pins)
#define SI32_PBHD_A_enable_pin_current_limit(basePointer, pins) do{  \
   basePointer->PBILIMIT_CLR = SI32_PBHD_A_PBILIMIT_PBILEN_MASK;\
   basePointer->PBILIMIT_SET =\
      pins << SI32_PBHD_A_PBILIMIT_PBILEN_SHIFT;\
} while(0)


/// @fn _SI32_PBHD_A_disable_pin_current_limit(SI32_PBHD_A_Type* basePointer,
///      uint32_t pins)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pins
///  Valid range is 6 bits.
///  Each bit corresponds to a pin.
///
void
_SI32_PBHD_A_disable_pin_current_limit(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pins*/);
///
/// @def SI32_PBHD_A_disable_pin_current_limit(basePointer, pins)
#define SI32_PBHD_A_disable_pin_current_limit(basePointer, pins) do{  \
   basePointer->PBILIMIT_CLR =\
      pins << SI32_PBHD_A_PBILIMIT_PBILEN_SHIFT;\
} while(0)


/// @fn _SI32_PBHD_A_select_nchannel_current_limit(SI32_PBHD_A_Type* basePointer,
///      uint32_t limit)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  limit
///  Valid range is 4 bits.
///  See Electrical Specifications for limit values.
///
void
_SI32_PBHD_A_select_nchannel_current_limit(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*limit*/);
///
/// @def SI32_PBHD_A_select_nchannel_current_limit(basePointer, limit)
#define SI32_PBHD_A_select_nchannel_current_limit(basePointer, limit) do{  \
   basePointer->PBILIMIT_CLR = SI32_PBHD_A_PBILIMIT_NILIMIT_MASK;\
   basePointer->PBILIMIT_SET =\
      limit << SI32_PBHD_A_PBILIMIT_NILIMIT_SHIFT;\
} while(0)


/// @fn _SI32_PBHD_A_select_pchannel_current_limit(SI32_PBHD_A_Type* basePointer,
///      uint32_t limit)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  limit
///  Valid range is 4 bits.
///  See Electrical Specifications for limit values.
///
void
_SI32_PBHD_A_select_pchannel_current_limit(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*limit*/);
///
/// @def SI32_PBHD_A_select_pchannel_current_limit(basePointer, limit)
#define SI32_PBHD_A_select_pchannel_current_limit(basePointer, limit) do{  \
   basePointer->PBILIMIT_CLR = SI32_PBHD_A_PBILIMIT_PILIMIT_MASK;\
   basePointer->PBILIMIT_SET =\
      limit << SI32_PBHD_A_PBILIMIT_PILIMIT_SHIFT;\
} while(0)


/// @fn _SI32_PBHD_A_write_pbfsel(SI32_PBHD_A_Type* basePointer,
///      uint32_t pbfsel)
///
/// @brief
/// Writes to PBFSEL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pbfsel
///  Valid range is 32 bits.
///
void
_SI32_PBHD_A_write_pbfsel(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pbfsel*/);
///
/// @def SI32_PBHD_A_write_pbfsel(basePointer, pbfsel)
#define SI32_PBHD_A_write_pbfsel(basePointer, pbfsel) \
   (basePointer->PBFSEL.U32 = pbfsel)


/// @fn _SI32_PBHD_A_read_pbfsel(SI32_PBHD_A_Type* basePointer)
///
/// @brief
/// Reads PBFSEL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBHD_A_read_pbfsel(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_read_pbfsel(basePointer)
#define SI32_PBHD_A_read_pbfsel(basePointer) \
(basePointer->PBFSEL.U32)


/// @fn _SI32_PBHD_A_select_pin0_function(SI32_PBHD_A_Type* basePointer,
///      SI32_PBHD_A_Function_Enum_Type function)
///
/// @brief
/// Configure function for PB4.0.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  function
///  Valid range is 2 bits.
///
void
_SI32_PBHD_A_select_pin0_function(SI32_PBHD_A_Type* /*basePointer*/,
   SI32_PBHD_A_Function_Enum_Type /*function*/);
///
/// @def SI32_PBHD_A_select_pin0_function(basePointer, function)
#define SI32_PBHD_A_select_pin0_function(basePointer, function) \
   (basePointer->PBFSEL.PB0SEL = function)


/// @fn _SI32_PBHD_A_select_pin1_function(SI32_PBHD_A_Type* basePointer,
///      SI32_PBHD_A_Function_Enum_Type function)
///
/// @brief
/// Configure function for PB4.1.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  function
///  Valid range is 2 bits.
///
void
_SI32_PBHD_A_select_pin1_function(SI32_PBHD_A_Type* /*basePointer*/,
   SI32_PBHD_A_Function_Enum_Type /*function*/);
///
/// @def SI32_PBHD_A_select_pin1_function(basePointer, function)
#define SI32_PBHD_A_select_pin1_function(basePointer, function) \
   (basePointer->PBFSEL.PB1SEL = function)


/// @fn _SI32_PBHD_A_select_pin2_function(SI32_PBHD_A_Type* basePointer,
///      SI32_PBHD_A_Function_Enum_Type function)
///
/// @brief
/// Configure function for PB4.2.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  function
///  Valid range is 2 bits.
///
void
_SI32_PBHD_A_select_pin2_function(SI32_PBHD_A_Type* /*basePointer*/,
   SI32_PBHD_A_Function_Enum_Type /*function*/);
///
/// @def SI32_PBHD_A_select_pin2_function(basePointer, function)
#define SI32_PBHD_A_select_pin2_function(basePointer, function) \
   (basePointer->PBFSEL.PB2SEL = function)


/// @fn _SI32_PBHD_A_select_pin3_function(SI32_PBHD_A_Type* basePointer,
///      SI32_PBHD_A_Function_Enum_Type function)
///
/// @brief
/// Configure function for PB4.3.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  function
///  Valid range is 2 bits.
///
void
_SI32_PBHD_A_select_pin3_function(SI32_PBHD_A_Type* /*basePointer*/,
   SI32_PBHD_A_Function_Enum_Type /*function*/);
///
/// @def SI32_PBHD_A_select_pin3_function(basePointer, function)
#define SI32_PBHD_A_select_pin3_function(basePointer, function) \
   (basePointer->PBFSEL.PB3SEL = function)


/// @fn _SI32_PBHD_A_select_pin4_function(SI32_PBHD_A_Type* basePointer,
///      SI32_PBHD_A_Function_Enum_Type function)
///
/// @brief
/// Configure function for PB4.4.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  function
///  Valid range is 2 bits.
///
void
_SI32_PBHD_A_select_pin4_function(SI32_PBHD_A_Type* /*basePointer*/,
   SI32_PBHD_A_Function_Enum_Type /*function*/);
///
/// @def SI32_PBHD_A_select_pin4_function(basePointer, function)
#define SI32_PBHD_A_select_pin4_function(basePointer, function) \
   (basePointer->PBFSEL.PB4SEL = function)


/// @fn _SI32_PBHD_A_select_pin5_function(SI32_PBHD_A_Type* basePointer,
///      SI32_PBHD_A_Function_Enum_Type function)
///
/// @brief
/// Configure function for PB4.5.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  function
///  Valid range is 3 bits.
///
void
_SI32_PBHD_A_select_pin5_function(SI32_PBHD_A_Type* /*basePointer*/,
   SI32_PBHD_A_Function_Enum_Type /*function*/);
///
/// @def SI32_PBHD_A_select_pin5_function(basePointer, function)
#define SI32_PBHD_A_select_pin5_function(basePointer, function) \
   (basePointer->PBFSEL.PB5SEL = function)


/// @fn _SI32_PBHD_A_write_pbss(SI32_PBHD_A_Type* basePointer,
///      uint32_t pbss)
///
/// @brief
/// Writes to PBSS register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pbss
///  Valid range is 32 bits.
///
void
_SI32_PBHD_A_write_pbss(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pbss*/);
///
/// @def SI32_PBHD_A_write_pbss(basePointer, pbss)
#define SI32_PBHD_A_write_pbss(basePointer, pbss) \
   (basePointer->PBSS.U32 = pbss)


/// @fn _SI32_PBHD_A_read_pbss(SI32_PBHD_A_Type* basePointer)
///
/// @brief
/// Reads PBSS register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBHD_A_read_pbss(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_read_pbss(basePointer)
#define SI32_PBHD_A_read_pbss(basePointer) \
(basePointer->PBSS.U32)


/// @fn _SI32_PBHD_A_select_pin0_safe_state(SI32_PBHD_A_Type* basePointer,
///      SI32_PBHD_A_Safe_State_Enum_Type safe_state)
///
/// @brief
/// Configure safe state of this pin.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  safe_state
///  Valid range is 2 bits.
///
void
_SI32_PBHD_A_select_pin0_safe_state(SI32_PBHD_A_Type* /*basePointer*/,
   SI32_PBHD_A_Safe_State_Enum_Type /*safe_state*/);
///
/// @def SI32_PBHD_A_select_pin0_safe_state(basePointer, safe_state)
#define SI32_PBHD_A_select_pin0_safe_state(basePointer, safe_state) do{  \
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PB0SSSEL_MASK;\
   basePointer->PBSS_SET =\
      safe_state << SI32_PBHD_A_PBSS_PB0SSSEL_SHIFT;\
} while(0)


/// @fn _SI32_PBHD_A_select_pin1_safe_state(SI32_PBHD_A_Type* basePointer,
///      SI32_PBHD_A_Safe_State_Enum_Type safe_state)
///
/// @brief
/// Configure safe state of this pin.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  safe_state
///  Valid range is 2 bits.
///
void
_SI32_PBHD_A_select_pin1_safe_state(SI32_PBHD_A_Type* /*basePointer*/,
   SI32_PBHD_A_Safe_State_Enum_Type /*safe_state*/);
///
/// @def SI32_PBHD_A_select_pin1_safe_state(basePointer, safe_state)
#define SI32_PBHD_A_select_pin1_safe_state(basePointer, safe_state) do{  \
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PB1SSSEL_MASK;\
   basePointer->PBSS_SET =\
      safe_state << SI32_PBHD_A_PBSS_PB1SSSEL_SHIFT;\
} while(0)


/// @fn _SI32_PBHD_A_select_pin2_safe_state(SI32_PBHD_A_Type* basePointer,
///      SI32_PBHD_A_Safe_State_Enum_Type safe_state)
///
/// @brief
/// Configure safe state of this pin.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  safe_state
///  Valid range is 2 bits.
///
void
_SI32_PBHD_A_select_pin2_safe_state(SI32_PBHD_A_Type* /*basePointer*/,
   SI32_PBHD_A_Safe_State_Enum_Type /*safe_state*/);
///
/// @def SI32_PBHD_A_select_pin2_safe_state(basePointer, safe_state)
#define SI32_PBHD_A_select_pin2_safe_state(basePointer, safe_state) do{  \
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PB2SSSEL_MASK;\
   basePointer->PBSS_SET =\
      safe_state << SI32_PBHD_A_PBSS_PB2SSSEL_SHIFT;\
} while(0)


/// @fn _SI32_PBHD_A_select_pin3_safe_state(SI32_PBHD_A_Type* basePointer,
///      SI32_PBHD_A_Safe_State_Enum_Type safe_state)
///
/// @brief
/// Configure safe state of this pin.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  safe_state
///  Valid range is 2 bits.
///
void
_SI32_PBHD_A_select_pin3_safe_state(SI32_PBHD_A_Type* /*basePointer*/,
   SI32_PBHD_A_Safe_State_Enum_Type /*safe_state*/);
///
/// @def SI32_PBHD_A_select_pin3_safe_state(basePointer, safe_state)
#define SI32_PBHD_A_select_pin3_safe_state(basePointer, safe_state) do{  \
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PB3SSSEL_MASK;\
   basePointer->PBSS_SET =\
      safe_state << SI32_PBHD_A_PBSS_PB3SSSEL_SHIFT;\
} while(0)


/// @fn _SI32_PBHD_A_select_pin4_safe_state(SI32_PBHD_A_Type* basePointer,
///      SI32_PBHD_A_Safe_State_Enum_Type safe_state)
///
/// @brief
/// Configure safe state of this pin.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  safe_state
///  Valid range is 2 bits.
///
void
_SI32_PBHD_A_select_pin4_safe_state(SI32_PBHD_A_Type* /*basePointer*/,
   SI32_PBHD_A_Safe_State_Enum_Type /*safe_state*/);
///
/// @def SI32_PBHD_A_select_pin4_safe_state(basePointer, safe_state)
#define SI32_PBHD_A_select_pin4_safe_state(basePointer, safe_state) do{  \
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PB4SSSEL_MASK;\
   basePointer->PBSS_SET =\
      safe_state << SI32_PBHD_A_PBSS_PB4SSSEL_SHIFT;\
} while(0)


/// @fn _SI32_PBHD_A_select_pin5_safe_state(SI32_PBHD_A_Type* basePointer,
///      SI32_PBHD_A_Safe_State_Enum_Type safe_state)
///
/// @brief
/// Configure safe state of this pin.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  safe_state
///  Valid range is 2 bits.
///
void
_SI32_PBHD_A_select_pin5_safe_state(SI32_PBHD_A_Type* /*basePointer*/,
   SI32_PBHD_A_Safe_State_Enum_Type /*safe_state*/);
///
/// @def SI32_PBHD_A_select_pin5_safe_state(basePointer, safe_state)
#define SI32_PBHD_A_select_pin5_safe_state(basePointer, safe_state) do{  \
   basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PB5SSSEL_MASK;\
   basePointer->PBSS_SET =\
      safe_state << SI32_PBHD_A_PBSS_PB5SSSEL_SHIFT;\
} while(0)


/// @fn _SI32_PBHD_A_enter_safe_state(SI32_PBHD_A_Type* basePointer)
///
/// @brief
/// Manually enter safe state.
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_enter_safe_state(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_enter_safe_state(basePointer)
#define SI32_PBHD_A_enter_safe_state(basePointer) \
   (basePointer->PBSS_SET = SI32_PBHD_A_PBSS_SSMDEN_MASK)


/// @fn _SI32_PBHD_A_exit_safe_state(SI32_PBHD_A_Type* basePointer)
///
/// @brief
/// Manually exit safe state.
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_exit_safe_state(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_exit_safe_state(basePointer)
#define SI32_PBHD_A_exit_safe_state(basePointer) \
   (basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_SSMDEN_MASK)


/// @fn _SI32_PBHD_A_is_port_in_safe_state(SI32_PBHD_A_Type* basePointer)
///
/// @brief
/// Check safe state of PB4.
///
/// @return
///  True = safe state.
///
/// @param[in]
///  basePointer
///
bool
_SI32_PBHD_A_is_port_in_safe_state(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_is_port_in_safe_state(basePointer)
#define SI32_PBHD_A_is_port_in_safe_state(basePointer) \
((bool)(basePointer->PBSS.SSMDEN))


/// @fn _SI32_PBHD_A_enable_kill_signal_deglitch(SI32_PBHD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_enable_kill_signal_deglitch(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_enable_kill_signal_deglitch(basePointer)
#define SI32_PBHD_A_enable_kill_signal_deglitch(basePointer) \
   (basePointer->PBSS_CLR = SI32_PBHD_A_PBSS_PBSSSMD_MASK)


/// @fn _SI32_PBHD_A_disable_kill_signal_deglitch(SI32_PBHD_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBHD_A_disable_kill_signal_deglitch(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_disable_kill_signal_deglitch(basePointer)
#define SI32_PBHD_A_disable_kill_signal_deglitch(basePointer) \
   (basePointer->PBSS_SET = SI32_PBHD_A_PBSS_PBSSSMD_MASK)


/// @fn _SI32_PBHD_A_write_pblock(SI32_PBHD_A_Type* basePointer,
///      uint32_t pblock)
///
/// @brief
/// Writes to PBLOCK register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pblock
///  Valid range is 32 bits.
///
void
_SI32_PBHD_A_write_pblock(SI32_PBHD_A_Type* /*basePointer*/,
   uint32_t /*pblock*/);
///
/// @def SI32_PBHD_A_write_pblock(basePointer, pblock)
#define SI32_PBHD_A_write_pblock(basePointer, pblock) \
   (basePointer->PBLOCK.U32 = pblock)


/// @fn _SI32_PBHD_A_read_pblock(SI32_PBHD_A_Type* basePointer)
///
/// @brief
/// Reads PBLOCK register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBHD_A_read_pblock(SI32_PBHD_A_Type* /*basePointer*/);
///
/// @def SI32_PBHD_A_read_pblock(basePointer)
#define SI32_PBHD_A_read_pblock(basePointer) \
(basePointer->PBLOCK.U32)



#ifdef __cplusplus
}
#endif

#endif // __SI32_PBHD_A_TYPE_H__

//-eof--------------------------------------------------------------------------
