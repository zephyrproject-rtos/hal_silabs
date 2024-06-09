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
/// @file SI32_PBGP_A_Type.h
//
// This file applies to the SIM3L1XX_PBGP_A module
//
// Script: 0.59
// HAL Source: 0.2
// Version: 1

#ifndef __SI32_PBGP_A_TYPE_H__
#define __SI32_PBGP_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_SIM3L1XX_PBGP_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_PBGP_A_initialize(SI32_PBGP_A_Type* basePointer,
///      uint32_t pb,
///      uint32_t pbmdsel,
///      uint32_t pboutmd,
///      uint32_t pbdrv,
///      uint32_t pm,
///      uint32_t pmen)
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
///  pboutmd
///  Valid range is 32 bits.
///  Write to PBOUTMD register.
///
/// @param[in]
///  pbdrv
///  Valid range is 32 bits.
///  Write to PBDRV register.
///
/// @param[in]
///  pm
///  Valid range is 32 bits.
///  Write to PM register.
///
/// @param[in]
///  pmen
///  Valid range is 32 bits.
///  Write to PMEN register.
///
void
_SI32_PBGP_A_initialize(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t, /*pb*/
   uint32_t, /*pbmdsel*/
   uint32_t, /*pboutmd*/
   uint32_t, /*pbdrv*/
   uint32_t, /*pm*/
   uint32_t /*pmen*/);
///
/// @def SI32_PBGP_A_initialize(basePointer, pb, pbmdsel, pboutmd, pbdrv, pm, pmen)
#define SI32_PBGP_A_initialize(basePointer, pb, pbmdsel, pboutmd, pbdrv, pm, pmen) do{  \
   basePointer->PB.U32       = pb;\
   basePointer->PBMDSEL.U32  = pbmdsel;\
   basePointer->PBOUTMD.U32  = pboutmd;\
   basePointer->PBDRV.U32    = pbdrv;\
   basePointer->PM.U32       = pm;\
   basePointer->PMEN.U32     = pmen;\
} while(0)


/// @fn _SI32_PBGP_A_write_pb(SI32_PBGP_A_Type* basePointer,
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
_SI32_PBGP_A_write_pb(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pb*/);
///
/// @def SI32_PBGP_A_write_pb(basePointer, pb)
#define SI32_PBGP_A_write_pb(basePointer, pb) \
   (basePointer->PB.U32 = pb)


/// @fn _SI32_PBGP_A_read_pb(SI32_PBGP_A_Type* basePointer)
///
/// @brief
/// Reads PB register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBGP_A_read_pb(SI32_PBGP_A_Type* /*basePointer*/);
///
/// @def SI32_PBGP_A_read_pb(basePointer)
#define SI32_PBGP_A_read_pb(basePointer) \
(basePointer->PB.U32)


/// @fn _SI32_PBGP_A_write_pins_high(SI32_PBGP_A_Type* basePointer,
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
///  Valid range is 16 bits.
///  Mask for pin writes : 1 = set pin to high.
///
void
_SI32_PBGP_A_write_pins_high(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBGP_A_write_pins_high(basePointer, pin_mask)
#define SI32_PBGP_A_write_pins_high(basePointer, pin_mask) \
   (basePointer->PB_SET = pin_mask)


/// @fn _SI32_PBGP_A_write_pins_low(SI32_PBGP_A_Type* basePointer,
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
///  Valid range is 16 bits.
///  Mask for pin writes : 1 = clear pin to low.
///
void
_SI32_PBGP_A_write_pins_low(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBGP_A_write_pins_low(basePointer, pin_mask)
#define SI32_PBGP_A_write_pins_low(basePointer, pin_mask) \
   (basePointer->PB_CLR = pin_mask)


/// @fn _SI32_PBGP_A_write_pins_masked(SI32_PBGP_A_Type* basePointer,
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
///  Valid range is 16 bits.
///  Values for latch.
///
/// @param[in]
///  pin_mask
///  Valid range is 16 bits.
///  Mask value : 1 = write, 0 = ignore.
///
void
_SI32_PBGP_A_write_pins_masked(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t, /*pin_value*/
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBGP_A_write_pins_masked(basePointer, pin_value, pin_mask)
#define SI32_PBGP_A_write_pins_masked(basePointer, pin_value, pin_mask) \
   (basePointer->PB_MSK = (pin_mask<<16)|(pin_value))


/// @fn _SI32_PBGP_A_toggle_pins(SI32_PBGP_A_Type* basePointer,
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
///  Valid range is 16 bits.
///  Mask for pin toggles : 1 = toggle pin.
///
void
_SI32_PBGP_A_toggle_pins(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pin_mask*/);
///
/// @def SI32_PBGP_A_toggle_pins(basePointer, pin_mask)
#define SI32_PBGP_A_toggle_pins(basePointer, pin_mask) \
   (basePointer->PB_MSK = (pin_mask<<16)|(~(basePointer->PB.U32) & 0xFFFF))


/// @fn _SI32_PBGP_A_read_pins(SI32_PBGP_A_Type* basePointer)
///
/// @brief
/// Reads PBPIN register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBGP_A_read_pins(SI32_PBGP_A_Type* /*basePointer*/);
///
/// @def SI32_PBGP_A_read_pins(basePointer)
#define SI32_PBGP_A_read_pins(basePointer) \
((basePointer->PBPIN.U32))


/// @fn _SI32_PBGP_A_read_pin(SI32_PBGP_A_Type* basePointer,
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
///  Valid range is 16 bits.
///  Number of the pin to read : 0 = pin 0.
///
uint32_t
_SI32_PBGP_A_read_pin(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pin_number*/);
///
/// @def SI32_PBGP_A_read_pin(basePointer, pin_number)
#define SI32_PBGP_A_read_pin(basePointer, pin_number) \
(((basePointer->PBPIN.U32) >> pin_number) & 1)


/// @fn _SI32_PBGP_A_write_pbmdsel(SI32_PBGP_A_Type* basePointer,
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
_SI32_PBGP_A_write_pbmdsel(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pbmdsel*/);
///
/// @def SI32_PBGP_A_write_pbmdsel(basePointer, pbmdsel)
#define SI32_PBGP_A_write_pbmdsel(basePointer, pbmdsel) \
   (basePointer->PBMDSEL.U32 = pbmdsel)


/// @fn _SI32_PBGP_A_read_pbmdsel(SI32_PBGP_A_Type* basePointer)
///
/// @brief
/// Reads PBMDSEL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBGP_A_read_pbmdsel(SI32_PBGP_A_Type* /*basePointer*/);
///
/// @def SI32_PBGP_A_read_pbmdsel(basePointer)
#define SI32_PBGP_A_read_pbmdsel(basePointer) \
(basePointer->PBMDSEL.U32)


/// @fn _SI32_PBGP_A_set_pins_push_pull_output(SI32_PBGP_A_Type* basePointer,
///      uwide16_t pin_mask)
///
/// @brief
/// Sets the pins masked with 1's to digital push-pull.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 16 bits.
///  Selects which pins to configure digital push-pull.
///
void
_SI32_PBGP_A_set_pins_push_pull_output(SI32_PBGP_A_Type* /*basePointer*/,
   uwide16_t /*pin_mask*/);
///
/// @def SI32_PBGP_A_set_pins_push_pull_output(basePointer, pin_mask)
#define SI32_PBGP_A_set_pins_push_pull_output(basePointer, pin_mask) do{  \
   basePointer->PBOUTMD_SET = pin_mask;\
   basePointer->PBMDSEL_SET = pin_mask;\
} while(0)


/// @fn _SI32_PBGP_A_set_pins_digital_input(SI32_PBGP_A_Type* basePointer,
///      uwide16_t pin_mask)
///
/// @brief
/// Sets the pins masked with 1's to open-drain input.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 16 bits.
///  Selects which pins to configure open-drain input.
///
void
_SI32_PBGP_A_set_pins_digital_input(SI32_PBGP_A_Type* /*basePointer*/,
   uwide16_t /*pin_mask*/);
///
/// @def SI32_PBGP_A_set_pins_digital_input(basePointer, pin_mask)
#define SI32_PBGP_A_set_pins_digital_input(basePointer, pin_mask) do{  \
   basePointer->PBOUTMD_CLR = pin_mask;\
   basePointer->PB_SET      = pin_mask;\
   basePointer->PBMDSEL_SET = pin_mask;\
} while(0)


/// @fn _SI32_PBGP_A_set_pins_analog(SI32_PBGP_A_Type* basePointer,
///      uwide16_t pin_mask)
///
/// @brief
/// Sets the pins masked with 1's to analog mode.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 16 bits.
///  Selects which pins to configure as analog.
///
void
_SI32_PBGP_A_set_pins_analog(SI32_PBGP_A_Type* /*basePointer*/,
   uwide16_t /*pin_mask*/);
///
/// @def SI32_PBGP_A_set_pins_analog(basePointer, pin_mask)
#define SI32_PBGP_A_set_pins_analog(basePointer, pin_mask) do{  \
   basePointer->PBMDSEL_CLR = pin_mask;\
   basePointer->PB_SET      = pin_mask;\
} while(0)


/// @fn _SI32_PBGP_A_write_pboutmd(SI32_PBGP_A_Type* basePointer,
///      uint32_t pboutmd)
///
/// @brief
/// Writes to PBOUTMD register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pboutmd
///  Valid range is 32 bits.
///
void
_SI32_PBGP_A_write_pboutmd(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pboutmd*/);
///
/// @def SI32_PBGP_A_write_pboutmd(basePointer, pboutmd)
#define SI32_PBGP_A_write_pboutmd(basePointer, pboutmd) \
   (basePointer->PBOUTMD.U32 = pboutmd)


/// @fn _SI32_PBGP_A_read_pboutmd(SI32_PBGP_A_Type* basePointer)
///
/// @brief
/// Reads PBOUTMD register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBGP_A_read_pboutmd(SI32_PBGP_A_Type* /*basePointer*/);
///
/// @def SI32_PBGP_A_read_pboutmd(basePointer)
#define SI32_PBGP_A_read_pboutmd(basePointer) \
(basePointer->PBOUTMD.U32)


/// @fn _SI32_PBGP_A_write_pbdrv(SI32_PBGP_A_Type* basePointer,
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
_SI32_PBGP_A_write_pbdrv(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pbdrv*/);
///
/// @def SI32_PBGP_A_write_pbdrv(basePointer, pbdrv)
#define SI32_PBGP_A_write_pbdrv(basePointer, pbdrv) \
   (basePointer->PBDRV.U32 = pbdrv)


/// @fn _SI32_PBGP_A_read_pbdrv(SI32_PBGP_A_Type* basePointer)
///
/// @brief
/// Reads PBDRV register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBGP_A_read_pbdrv(SI32_PBGP_A_Type* /*basePointer*/);
///
/// @def SI32_PBGP_A_read_pbdrv(basePointer)
#define SI32_PBGP_A_read_pbdrv(basePointer) \
(basePointer->PBDRV.U32)


/// @fn _SI32_PBGP_A_set_pins_high_drive_strength(SI32_PBGP_A_Type* basePointer,
///      uwide16_t pin_mask)
///
/// @brief
/// Sets the drive strength to high for masked pins.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 16 bits.
///  Selects which pins to configure drive high.
///
void
_SI32_PBGP_A_set_pins_high_drive_strength(SI32_PBGP_A_Type* /*basePointer*/,
   uwide16_t /*pin_mask*/);
///
/// @def SI32_PBGP_A_set_pins_high_drive_strength(basePointer, pin_mask)
#define SI32_PBGP_A_set_pins_high_drive_strength(basePointer, pin_mask) \
   (basePointer->PBDRV_SET = pin_mask)


/// @fn _SI32_PBGP_A_set_pins_low_drive_strength(SI32_PBGP_A_Type* basePointer,
///      uwide16_t pin_mask)
///
/// @brief
/// Sets the drive strength to low for masked pins.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_mask
///  Valid range is 16 bits.
///  Selects which pins to configure drive low.
///
void
_SI32_PBGP_A_set_pins_low_drive_strength(SI32_PBGP_A_Type* /*basePointer*/,
   uwide16_t /*pin_mask*/);
///
/// @def SI32_PBGP_A_set_pins_low_drive_strength(basePointer, pin_mask)
#define SI32_PBGP_A_set_pins_low_drive_strength(basePointer, pin_mask) \
   (basePointer->PBDRV_CLR = pin_mask)


/// @fn _SI32_PBGP_A_enable_pullup_resistors(SI32_PBGP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBGP_A_enable_pullup_resistors(SI32_PBGP_A_Type* /*basePointer*/);
///
/// @def SI32_PBGP_A_enable_pullup_resistors(basePointer)
#define SI32_PBGP_A_enable_pullup_resistors(basePointer) \
   (basePointer->PBDRV_SET = SI32_PBGP_A_PBDRV_PBPUEN_MASK)


/// @fn _SI32_PBGP_A_disable_pullup_resistors(SI32_PBGP_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_PBGP_A_disable_pullup_resistors(SI32_PBGP_A_Type* /*basePointer*/);
///
/// @def SI32_PBGP_A_disable_pullup_resistors(basePointer)
#define SI32_PBGP_A_disable_pullup_resistors(basePointer) \
   (basePointer->PBDRV_CLR = SI32_PBGP_A_PBDRV_PBPUEN_MASK)


/// @fn _SI32_PBGP_A_write_pm(SI32_PBGP_A_Type* basePointer,
///      uint32_t pm)
///
/// @brief
/// Writes to PM register, available on all ports.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pm
///  Valid range is 32 bits.
///
void
_SI32_PBGP_A_write_pm(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pm*/);
///
/// @def SI32_PBGP_A_write_pm(basePointer, pm)
#define SI32_PBGP_A_write_pm(basePointer, pm) \
   (basePointer->PM.U32 = pm)


/// @fn _SI32_PBGP_A_read_pm(SI32_PBGP_A_Type* basePointer)
///
/// @brief
/// Reads PM register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBGP_A_read_pm(SI32_PBGP_A_Type* /*basePointer*/);
///
/// @def SI32_PBGP_A_read_pm(basePointer)
#define SI32_PBGP_A_read_pm(basePointer) \
(basePointer->PM.U32)


/// @fn _SI32_PBGP_A_set_port_match_pin_value(SI32_PBGP_A_Type* basePointer,
///      uint32_t pin_number)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_number
///  Valid range is 16 bits.
///  Number of the pin to set the port match value high : 0 = pin 0.
///
void
_SI32_PBGP_A_set_port_match_pin_value(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pin_number*/);
///
/// @def SI32_PBGP_A_set_port_match_pin_value(basePointer, pin_number)
#define SI32_PBGP_A_set_port_match_pin_value(basePointer, pin_number) \
   (basePointer->PM_SET = (1 << pin_number))


/// @fn _SI32_PBGP_A_clear_port_match_pin_value(SI32_PBGP_A_Type* basePointer,
///      uint32_t pin_number)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_number
///  Valid range is 16 bits.
///  Number of the pin to set the port match value low : 0 = pin 0.
///
void
_SI32_PBGP_A_clear_port_match_pin_value(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pin_number*/);
///
/// @def SI32_PBGP_A_clear_port_match_pin_value(basePointer, pin_number)
#define SI32_PBGP_A_clear_port_match_pin_value(basePointer, pin_number) \
   (basePointer->PM_CLR = (1 << pin_number))


/// @fn _SI32_PBGP_A_write_pmen(SI32_PBGP_A_Type* basePointer,
///      uint32_t pmen)
///
/// @brief
/// Writes to PMEN register, available on all ports.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pmen
///  Valid range is 32 bits.
///
void
_SI32_PBGP_A_write_pmen(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pmen*/);
///
/// @def SI32_PBGP_A_write_pmen(basePointer, pmen)
#define SI32_PBGP_A_write_pmen(basePointer, pmen) \
   (basePointer->PMEN.U32 = pmen)


/// @fn _SI32_PBGP_A_read_pmen(SI32_PBGP_A_Type* basePointer)
///
/// @brief
/// Reads PMEN register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_PBGP_A_read_pmen(SI32_PBGP_A_Type* /*basePointer*/);
///
/// @def SI32_PBGP_A_read_pmen(basePointer)
#define SI32_PBGP_A_read_pmen(basePointer) \
(basePointer->PMEN.U32)


/// @fn _SI32_PBGP_A_enable_port_match_pin(SI32_PBGP_A_Type* basePointer,
///      uint32_t pin_number)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_number
///  Valid range is 16 bits.
///  Number of the pin to enable port match : 0 = pin 0.
///
void
_SI32_PBGP_A_enable_port_match_pin(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pin_number*/);
///
/// @def SI32_PBGP_A_enable_port_match_pin(basePointer, pin_number)
#define SI32_PBGP_A_enable_port_match_pin(basePointer, pin_number) \
   (basePointer->PMEN_SET = (1 << pin_number))


/// @fn _SI32_PBGP_A_disable_port_match_pin(SI32_PBGP_A_Type* basePointer,
///      uint32_t pin_number)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  pin_number
///  Valid range is 16 bits.
///  Number of the pin to disable port match : 0 = pin 0.
///
void
_SI32_PBGP_A_disable_port_match_pin(SI32_PBGP_A_Type* /*basePointer*/,
   uint32_t /*pin_number*/);
///
/// @def SI32_PBGP_A_disable_port_match_pin(basePointer, pin_number)
#define SI32_PBGP_A_disable_port_match_pin(basePointer, pin_number) \
   (basePointer->PMEN_CLR = (1 << pin_number))



#ifdef __cplusplus
}
#endif

#endif // __SI32_PBGP_A_TYPE_H__

//-eof--------------------------------------------------------------------------
