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
/// @file SI32_USB_A_Type.h
//
// Script: 0.58
// HAL Source: 0.4
// Version: 1

#ifndef __SI32_USB_A_TYPE_H__
#define __SI32_USB_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_USB_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_USB_A_initialize(SI32_USB_A_Type* basePointer,
///      uint32_t faddr,
///      uint32_t power,
///      uint32_t ioint,
///      uint32_t cmint,
///      uint32_t iointe,
///      uint32_t cmintepe,
///      uint32_t crcontrol,
///      uint32_t tcontrol,
///      uint32_t clksel,
///      uint32_t osccontrol,
///      uint32_t dmacontrol,
///      uint32_t ep0control)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  faddr
///  Valid range is 32 bits.
///  Write to FADDR register.
///
/// @param[in]
///  power
///  Valid range is 32 bits.
///  Write to POWER register.
///
/// @param[in]
///  ioint
///  Valid range is 32 bits.
///  Write to IOINT register.
///
/// @param[in]
///  cmint
///  Valid range is 32 bits.
///  Write to CMINT register.
///
/// @param[in]
///  iointe
///  Valid range is 32 bits.
///  Write to IOINTE register.
///
/// @param[in]
///  cmintepe
///  Valid range is 32 bits.
///  Write to CMINTEPE register.
///
/// @param[in]
///  crcontrol
///  Valid range is 32 bits.
///  Write to CRCONTROL register.
///
/// @param[in]
///  tcontrol
///  Valid range is 32 bits.
///  Write to TCONTROL register.
///
/// @param[in]
///  clksel
///  Valid range is 32 bits.
///  Write to CLKSEL register.
///
/// @param[in]
///  osccontrol
///  Valid range is 32 bits.
///  Write to OSCCONTROL register.
///
/// @param[in]
///  dmacontrol
///  Valid range is 32 bits.
///  Write to DMACONTROL register.
///
/// @param[in]
///  ep0control
///  Valid range is 32 bits.
///  Write to EP0CONTROL register.
///
void
_SI32_USB_A_initialize(SI32_USB_A_Type* /*basePointer*/,
   uint32_t, /*faddr*/
   uint32_t, /*power*/
   uint32_t, /*ioint*/
   uint32_t, /*cmint*/
   uint32_t, /*iointe*/
   uint32_t, /*cmintepe*/
   uint32_t, /*crcontrol*/
   uint32_t, /*tcontrol*/
   uint32_t, /*clksel*/
   uint32_t, /*osccontrol*/
   uint32_t, /*dmacontrol*/
   uint32_t /*ep0control*/);
///
/// @def SI32_USB_A_initialize(basePointer, faddr, power, ioint, cmint, iointe, cmintepe, crcontrol, tcontrol, clksel, osccontrol, dmacontrol, ep0control)
#define SI32_USB_A_initialize(basePointer, faddr, power, ioint, cmint, iointe, cmintepe, crcontrol, tcontrol, clksel, osccontrol, dmacontrol, ep0control) do{  \
   basePointer->FADDR.U32 = faddr;\
   basePointer->POWER.U32 = power;\
   basePointer->IOINT.U32 = ioint;\
   basePointer->CMINT.U32 = cmint;\
   basePointer->IOINTE.U32 = iointe;\
   basePointer->CMINTEPE.U32 = cmintepe;\
   basePointer->CRCONTROL.U32 = crcontrol;\
   basePointer->TCONTROL.U32 = tcontrol;\
   basePointer->CLKSEL.U32 = clksel;\
   basePointer->OSCCONTROL.U32 = osccontrol;\
   basePointer->DMACONTROL.U32 = dmacontrol;\
   basePointer->EP0CONTROL.U32 = ep0control;\
} while(0)


/// @fn _SI32_USB_A_write_faddr(SI32_USB_A_Type* basePointer,
///      uint32_t faddr)
///
/// @brief
/// Writes to FADDR register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  faddr
///  Valid range is 32 bits.
///
void
_SI32_USB_A_write_faddr(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*faddr*/);
///
/// @def SI32_USB_A_write_faddr(basePointer, faddr)
#define SI32_USB_A_write_faddr(basePointer, faddr) \
   (basePointer->FADDR.U32 = faddr)


/// @fn _SI32_USB_A_read_faddr(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads FADDR register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_faddr(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_faddr(basePointer)
#define SI32_USB_A_read_faddr(basePointer) \
(basePointer->FADDR.U32)


/// @fn _SI32_USB_A_is_function_address_updating(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if update is in progress, returns FALSE if update is
/// complete.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_function_address_updating(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_function_address_updating(basePointer)
#define SI32_USB_A_is_function_address_updating(basePointer) \
((bool)(basePointer->FADDR.FADDRUPD))


/// @fn _SI32_USB_A_write_power(SI32_USB_A_Type* basePointer,
///      uint32_t power)
///
/// @brief
/// Writes to POWER register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  power
///  Valid range is 32 bits.
///
void
_SI32_USB_A_write_power(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*power*/);
///
/// @def SI32_USB_A_write_power(basePointer, power)
#define SI32_USB_A_write_power(basePointer, power) \
   (basePointer->POWER.U32 = power)


/// @fn _SI32_USB_A_read_power(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads POWER register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_power(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_power(basePointer)
#define SI32_USB_A_read_power(basePointer) \
(basePointer->POWER.U32)


/// @fn _SI32_USB_A_enable_suspend_detection(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_suspend_detection(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_suspend_detection(basePointer)
#define SI32_USB_A_enable_suspend_detection(basePointer) \
   (basePointer->POWER.SUSDEN = SI32_USB_A_POWER_SUSDEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_suspend_detection(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_suspend_detection(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_suspend_detection(basePointer)
#define SI32_USB_A_disable_suspend_detection(basePointer) \
   (basePointer->POWER.SUSDEN = SI32_USB_A_POWER_SUSDEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_suspend_detected(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if in suspend, otherwise returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_suspend_detected(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_suspend_detected(basePointer)
#define SI32_USB_A_is_suspend_detected(basePointer) \
((bool)(basePointer->POWER.SUSMDF))


/// @fn _SI32_USB_A_generate_resume_signaling(SI32_USB_A_Type* basePointer)
///
/// @brief
/// After function call, firmware should call stop_resume_signalling()
/// after 10-15 ms.
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_generate_resume_signaling(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_generate_resume_signaling(basePointer)
#define SI32_USB_A_generate_resume_signaling(basePointer) \
   (basePointer->POWER.RESUME = SI32_USB_A_POWER_RESUME_GENERATE_VALUE)


/// @fn _SI32_USB_A_stop_resume_signaling(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_stop_resume_signaling(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_stop_resume_signaling(basePointer)
#define SI32_USB_A_stop_resume_signaling(basePointer) \
   (basePointer->POWER.RESUME = SI32_USB_A_POWER_RESUME_STOP_VALUE)


/// @fn _SI32_USB_A_is_reset_detected(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Returns TRUE of reset signaling detected, otherwise returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_reset_detected(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_reset_detected(basePointer)
#define SI32_USB_A_is_reset_detected(basePointer) \
((bool)(basePointer->POWER.RSTDETF))


/// @fn _SI32_USB_A_enable_module(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_module(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_module(basePointer)
#define SI32_USB_A_enable_module(basePointer) \
   (basePointer->POWER.USBINH = SI32_USB_A_POWER_USBINH_INACTIVE_VALUE)


/// @fn _SI32_USB_A_disable_module(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_module(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_module(basePointer)
#define SI32_USB_A_disable_module(basePointer) \
   (basePointer->POWER.USBINH = SI32_USB_A_POWER_USBINH_ACTIVE_VALUE)


/// @fn _SI32_USB_A_enable_signal_dither(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_signal_dither(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_signal_dither(basePointer)
#define SI32_USB_A_enable_signal_dither(basePointer) \
   (basePointer->POWER.DITHEN = SI32_USB_A_POWER_DITHEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_signal_dither(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_signal_dither(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_signal_dither(basePointer)
#define SI32_USB_A_disable_signal_dither(basePointer) \
   (basePointer->POWER.DITHEN = SI32_USB_A_POWER_DITHEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_send_isochronous_packet_on_in(SI32_USB_A_Type* basePointer)
///
/// @brief
/// For isochronous endpoints, when software writes INPRDY = '1', USBn
/// will send the packet when the next IN token is received.
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_send_isochronous_packet_on_in(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_send_isochronous_packet_on_in(basePointer)
#define SI32_USB_A_send_isochronous_packet_on_in(basePointer) \
   (basePointer->POWER.ISOUPDMD = SI32_USB_A_POWER_ISOUPDMD_SEND_ON_IN_VALUE)


/// @fn _SI32_USB_A_send_isochronous_packet_on_sof(SI32_USB_A_Type* basePointer)
///
/// @brief
/// For isochronous endpoints, when software writes INPRDY = '1', USBn
/// will wait for a SOF token before sending the packet. If an IN token is
/// received before a SOF token, USBn will send a zero-length data packet.
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_send_isochronous_packet_on_sof(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_send_isochronous_packet_on_sof(basePointer)
#define SI32_USB_A_send_isochronous_packet_on_sof(basePointer) \
   (basePointer->POWER.ISOUPDMD = SI32_USB_A_POWER_ISOUPDMD_SEND_ON_SOF_VALUE)


/// @fn _SI32_USB_A_write_ioint(SI32_USB_A_Type* basePointer,
///      uint32_t ioint)
///
/// @brief
/// Writes to IOINT register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ioint
///  Valid range is 32 bits.
///
void
_SI32_USB_A_write_ioint(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*ioint*/);
///
/// @def SI32_USB_A_write_ioint(basePointer, ioint)
#define SI32_USB_A_write_ioint(basePointer, ioint) \
   (basePointer->IOINT.U32 = ioint)


/// @fn _SI32_USB_A_read_ioint(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads IOINT register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_ioint(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_ioint(basePointer)
#define SI32_USB_A_read_ioint(basePointer) \
(basePointer->IOINT.U32)


/// @fn _SI32_USB_A_clear_ep0_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_ep0_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_ep0_interrupt(basePointer)
#define SI32_USB_A_clear_ep0_interrupt(basePointer) \
   (basePointer->IOINT.U32 = SI32_USB_A_IOINT_EP0I_SET_U32)


/// @fn _SI32_USB_A_is_ep0_interrupt_pending(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep0_interrupt_pending(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep0_interrupt_pending(basePointer)
#define SI32_USB_A_is_ep0_interrupt_pending(basePointer) \
((bool)(basePointer->IOINT.EP0I))


/// @fn _SI32_USB_A_clear_ep1_in_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_ep1_in_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_ep1_in_interrupt(basePointer)
#define SI32_USB_A_clear_ep1_in_interrupt(basePointer) \
   (basePointer->IOINT.U32 = SI32_USB_A_IOINT_IN1I_SET_U32)


/// @fn _SI32_USB_A_is_ep1_in_interrupt_pending(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep1_in_interrupt_pending(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep1_in_interrupt_pending(basePointer)
#define SI32_USB_A_is_ep1_in_interrupt_pending(basePointer) \
((bool)(basePointer->IOINT.IN1I))


/// @fn _SI32_USB_A_clear_ep2_in_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_ep2_in_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_ep2_in_interrupt(basePointer)
#define SI32_USB_A_clear_ep2_in_interrupt(basePointer) \
   (basePointer->IOINT.U32 = SI32_USB_A_IOINT_IN2I_SET_U32)


/// @fn _SI32_USB_A_is_ep2_in_interrupt_pending(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep2_in_interrupt_pending(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep2_in_interrupt_pending(basePointer)
#define SI32_USB_A_is_ep2_in_interrupt_pending(basePointer) \
((bool)(basePointer->IOINT.IN2I))


/// @fn _SI32_USB_A_clear_ep3_in_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_ep3_in_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_ep3_in_interrupt(basePointer)
#define SI32_USB_A_clear_ep3_in_interrupt(basePointer) \
   (basePointer->IOINT.U32 = SI32_USB_A_IOINT_IN3I_SET_U32)


/// @fn _SI32_USB_A_is_ep3_in_interrupt_pending(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep3_in_interrupt_pending(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep3_in_interrupt_pending(basePointer)
#define SI32_USB_A_is_ep3_in_interrupt_pending(basePointer) \
((bool)(basePointer->IOINT.IN3I))


/// @fn _SI32_USB_A_clear_ep4_in_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_ep4_in_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_ep4_in_interrupt(basePointer)
#define SI32_USB_A_clear_ep4_in_interrupt(basePointer) \
   (basePointer->IOINT.U32 = SI32_USB_A_IOINT_IN4I_SET_U32)


/// @fn _SI32_USB_A_is_ep4_in_interrupt_pending(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep4_in_interrupt_pending(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep4_in_interrupt_pending(basePointer)
#define SI32_USB_A_is_ep4_in_interrupt_pending(basePointer) \
((bool)(basePointer->IOINT.IN4I))


/// @fn _SI32_USB_A_clear_ep1_out_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_ep1_out_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_ep1_out_interrupt(basePointer)
#define SI32_USB_A_clear_ep1_out_interrupt(basePointer) \
   (basePointer->IOINT.U32 = SI32_USB_A_IOINT_OUT1I_SET_U32)


/// @fn _SI32_USB_A_is_ep1_out_interrupt_pending(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep1_out_interrupt_pending(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep1_out_interrupt_pending(basePointer)
#define SI32_USB_A_is_ep1_out_interrupt_pending(basePointer) \
((bool)(basePointer->IOINT.OUT1I))


/// @fn _SI32_USB_A_clear_ep2_out_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_ep2_out_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_ep2_out_interrupt(basePointer)
#define SI32_USB_A_clear_ep2_out_interrupt(basePointer) \
   (basePointer->IOINT.U32 = SI32_USB_A_IOINT_OUT2I_SET_U32)


/// @fn _SI32_USB_A_is_ep2_out_interrupt_pending(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep2_out_interrupt_pending(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep2_out_interrupt_pending(basePointer)
#define SI32_USB_A_is_ep2_out_interrupt_pending(basePointer) \
((bool)(basePointer->IOINT.OUT2I))


/// @fn _SI32_USB_A_clear_ep3_out_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_ep3_out_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_ep3_out_interrupt(basePointer)
#define SI32_USB_A_clear_ep3_out_interrupt(basePointer) \
   (basePointer->IOINT.U32 = SI32_USB_A_IOINT_OUT3I_SET_U32;)


/// @fn _SI32_USB_A_is_ep3_out_interrupt_pending(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep3_out_interrupt_pending(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep3_out_interrupt_pending(basePointer)
#define SI32_USB_A_is_ep3_out_interrupt_pending(basePointer) \
((bool)(basePointer->IOINT.OUT3I))


/// @fn _SI32_USB_A_clear_ep4_out_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_ep4_out_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_ep4_out_interrupt(basePointer)
#define SI32_USB_A_clear_ep4_out_interrupt(basePointer) \
   (basePointer->IOINT.U32 = SI32_USB_A_IOINT_OUT4I_SET_U32;)


/// @fn _SI32_USB_A_is_ep4_out_interrupt_pending(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep4_out_interrupt_pending(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep4_out_interrupt_pending(basePointer)
#define SI32_USB_A_is_ep4_out_interrupt_pending(basePointer) \
((bool)(basePointer->IOINT.OUT4I))


/// @fn _SI32_USB_A_write_cmint(SI32_USB_A_Type* basePointer,
///      uint32_t cmint)
///
/// @brief
/// Writes to CMINT register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  cmint
///  Valid range is 32 bits.
///
void
_SI32_USB_A_write_cmint(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*cmint*/);
///
/// @def SI32_USB_A_write_cmint(basePointer, cmint)
#define SI32_USB_A_write_cmint(basePointer, cmint) \
   (basePointer->CMINT.U32 = cmint)


/// @fn _SI32_USB_A_read_cmint(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads CMINT register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_cmint(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_cmint(basePointer)
#define SI32_USB_A_read_cmint(basePointer) \
(basePointer->CMINT.U32)


/// @fn _SI32_USB_A_clear_suspend_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_suspend_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_suspend_interrupt(basePointer)
#define SI32_USB_A_clear_suspend_interrupt(basePointer) \
   (basePointer->CMINT.SUSI = SI32_USB_A_CMINT_SUSI_SET_VALUE)


/// @fn _SI32_USB_A_is_suspend_interrupt_pending(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_suspend_interrupt_pending(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_suspend_interrupt_pending(basePointer)
#define SI32_USB_A_is_suspend_interrupt_pending(basePointer) \
((bool)(basePointer->CMINT.SUSI))


/// @fn _SI32_USB_A_clear_resume_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_resume_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_resume_interrupt(basePointer)
#define SI32_USB_A_clear_resume_interrupt(basePointer) \
   (basePointer->CMINT.RESI = SI32_USB_A_CMINT_RESI_SET_VALUE)


/// @fn _SI32_USB_A_is_resume_interrupt_pending(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_resume_interrupt_pending(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_resume_interrupt_pending(basePointer)
#define SI32_USB_A_is_resume_interrupt_pending(basePointer) \
((bool)(basePointer->CMINT.RESI))


/// @fn _SI32_USB_A_clear_reset_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_reset_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_reset_interrupt(basePointer)
#define SI32_USB_A_clear_reset_interrupt(basePointer) \
   (basePointer->CMINT.RSTI = SI32_USB_A_CMINT_RSTI_SET_VALUE)


/// @fn _SI32_USB_A_is_reset_interrupt_pending(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_reset_interrupt_pending(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_reset_interrupt_pending(basePointer)
#define SI32_USB_A_is_reset_interrupt_pending(basePointer) \
((bool)(basePointer->CMINT.RSTI))


/// @fn _SI32_USB_A_clear_start_of_frame_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_start_of_frame_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_start_of_frame_interrupt(basePointer)
#define SI32_USB_A_clear_start_of_frame_interrupt(basePointer) \
   (basePointer->CMINT.SOFI = SI32_USB_A_CMINT_SOFI_SET_VALUE)


/// @fn _SI32_USB_A_is_start_of_frame_interrupt_pending(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_start_of_frame_interrupt_pending(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_start_of_frame_interrupt_pending(basePointer)
#define SI32_USB_A_is_start_of_frame_interrupt_pending(basePointer) \
((bool)(basePointer->CMINT.SOFI))


/// @fn _SI32_USB_A_write_iointe(SI32_USB_A_Type* basePointer,
///      uint32_t iointe)
///
/// @brief
/// Writes to IOINT register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  iointe
///  Valid range is 32 bits.
///
void
_SI32_USB_A_write_iointe(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*iointe*/);
///
/// @def SI32_USB_A_write_iointe(basePointer, iointe)
#define SI32_USB_A_write_iointe(basePointer, iointe) \
   (basePointer->IOINTE.U32 = iointe)


/// @fn _SI32_USB_A_read_iointe(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads IOINT register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_iointe(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_iointe(basePointer)
#define SI32_USB_A_read_iointe(basePointer) \
(basePointer->IOINTE.U32)


/// @fn _SI32_USB_A_enable_ep0_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep0_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep0_interrupt(basePointer)
#define SI32_USB_A_enable_ep0_interrupt(basePointer) \
   (basePointer->IOINTE.EP0IEN = SI32_USB_A_IOINTE_EP0IEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep0_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep0_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep0_interrupt(basePointer)
#define SI32_USB_A_disable_ep0_interrupt(basePointer) \
   (basePointer->IOINTE.EP0IEN = SI32_USB_A_IOINTE_EP0IEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep0_interrupt_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep0_interrupt_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep0_interrupt_enabled(basePointer)
#define SI32_USB_A_is_ep0_interrupt_enabled(basePointer) \
((bool)(basePointer->IOINTE.EP0IEN))


/// @fn _SI32_USB_A_enable_ep1_in_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep1_in_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep1_in_interrupt(basePointer)
#define SI32_USB_A_enable_ep1_in_interrupt(basePointer) \
   (basePointer->IOINTE.IN1IEN = SI32_USB_A_IOINTE_IN1IEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep1_in_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep1_in_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep1_in_interrupt(basePointer)
#define SI32_USB_A_disable_ep1_in_interrupt(basePointer) \
   (basePointer->IOINTE.IN1IEN = SI32_USB_A_IOINTE_IN1IEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep1_in_interrupt_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep1_in_interrupt_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep1_in_interrupt_enabled(basePointer)
#define SI32_USB_A_is_ep1_in_interrupt_enabled(basePointer) \
((bool)(basePointer->IOINTE.IN1IEN))


/// @fn _SI32_USB_A_enable_ep2_in_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep2_in_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep2_in_interrupt(basePointer)
#define SI32_USB_A_enable_ep2_in_interrupt(basePointer) \
   (basePointer->IOINTE.IN2IEN = SI32_USB_A_IOINTE_IN2IEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep2_in_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep2_in_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep2_in_interrupt(basePointer)
#define SI32_USB_A_disable_ep2_in_interrupt(basePointer) \
   (basePointer->IOINTE.IN2IEN = SI32_USB_A_IOINTE_IN2IEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep2_in_interrupt_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep2_in_interrupt_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep2_in_interrupt_enabled(basePointer)
#define SI32_USB_A_is_ep2_in_interrupt_enabled(basePointer) \
((bool)(basePointer->IOINTE.IN2IEN))


/// @fn _SI32_USB_A_enable_ep3_in_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep3_in_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep3_in_interrupt(basePointer)
#define SI32_USB_A_enable_ep3_in_interrupt(basePointer) \
   (basePointer->IOINTE.IN3IEN = SI32_USB_A_IOINTE_IN3IEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep3_in_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep3_in_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep3_in_interrupt(basePointer)
#define SI32_USB_A_disable_ep3_in_interrupt(basePointer) \
   (basePointer->IOINTE.IN3IEN = SI32_USB_A_IOINTE_IN3IEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep3_in_interrupt_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep3_in_interrupt_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep3_in_interrupt_enabled(basePointer)
#define SI32_USB_A_is_ep3_in_interrupt_enabled(basePointer) \
((bool)(basePointer->IOINTE.IN3IEN))


/// @fn _SI32_USB_A_enable_ep4_in_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep4_in_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep4_in_interrupt(basePointer)
#define SI32_USB_A_enable_ep4_in_interrupt(basePointer) \
   (basePointer->IOINTE.IN4IEN = SI32_USB_A_IOINTE_IN4IEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep4_in_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep4_in_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep4_in_interrupt(basePointer)
#define SI32_USB_A_disable_ep4_in_interrupt(basePointer) \
   (basePointer->IOINTE.IN4IEN = SI32_USB_A_IOINTE_IN4IEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep4_in_interrupt_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep4_in_interrupt_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep4_in_interrupt_enabled(basePointer)
#define SI32_USB_A_is_ep4_in_interrupt_enabled(basePointer) \
((bool)(basePointer->IOINTE.IN4IEN))


/// @fn _SI32_USB_A_enable_ep1_out_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep1_out_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep1_out_interrupt(basePointer)
#define SI32_USB_A_enable_ep1_out_interrupt(basePointer) \
   (basePointer->IOINTE.OUT1IEN = SI32_USB_A_IOINTE_OUT1IEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep1_out_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep1_out_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep1_out_interrupt(basePointer)
#define SI32_USB_A_disable_ep1_out_interrupt(basePointer) \
   (basePointer->IOINTE.OUT1IEN = SI32_USB_A_IOINTE_OUT1IEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep1_out_interrupt_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep1_out_interrupt_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep1_out_interrupt_enabled(basePointer)
#define SI32_USB_A_is_ep1_out_interrupt_enabled(basePointer) \
((bool)(basePointer->IOINTE.OUT1IEN))


/// @fn _SI32_USB_A_enable_ep2_out_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep2_out_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep2_out_interrupt(basePointer)
#define SI32_USB_A_enable_ep2_out_interrupt(basePointer) \
   (basePointer->IOINTE.OUT2IEN = SI32_USB_A_IOINTE_OUT2IEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep2_out_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep2_out_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep2_out_interrupt(basePointer)
#define SI32_USB_A_disable_ep2_out_interrupt(basePointer) \
   (basePointer->IOINTE.OUT2IEN = SI32_USB_A_IOINTE_OUT2IEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep2_out_interrupt_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep2_out_interrupt_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep2_out_interrupt_enabled(basePointer)
#define SI32_USB_A_is_ep2_out_interrupt_enabled(basePointer) \
((bool)(basePointer->IOINTE.OUT2IEN))


/// @fn _SI32_USB_A_enable_ep3_out_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep3_out_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep3_out_interrupt(basePointer)
#define SI32_USB_A_enable_ep3_out_interrupt(basePointer) \
   (basePointer->IOINTE.OUT3IEN = SI32_USB_A_IOINTE_OUT3IEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep3_out_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep3_out_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep3_out_interrupt(basePointer)
#define SI32_USB_A_disable_ep3_out_interrupt(basePointer) \
   (basePointer->IOINTE.OUT3IEN = SI32_USB_A_IOINTE_OUT3IEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep3_out_interrupt_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep3_out_interrupt_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep3_out_interrupt_enabled(basePointer)
#define SI32_USB_A_is_ep3_out_interrupt_enabled(basePointer) \
((bool)(basePointer->IOINTE.OUT3IEN))


/// @fn _SI32_USB_A_enable_ep4_out_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep4_out_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep4_out_interrupt(basePointer)
#define SI32_USB_A_enable_ep4_out_interrupt(basePointer) \
   (basePointer->IOINTE.OUT4IEN = SI32_USB_A_IOINTE_OUT4IEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep4_out_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep4_out_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep4_out_interrupt(basePointer)
#define SI32_USB_A_disable_ep4_out_interrupt(basePointer) \
   (basePointer->IOINTE.OUT4IEN = SI32_USB_A_IOINTE_OUT4IEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep4_out_interrupt_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep4_out_interrupt_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep4_out_interrupt_enabled(basePointer)
#define SI32_USB_A_is_ep4_out_interrupt_enabled(basePointer) \
((bool)(basePointer->IOINTE.OUT4IEN))


/// @fn _SI32_USB_A_write_cmintepe(SI32_USB_A_Type* basePointer,
///      uint32_t cmintepe)
///
/// @brief
/// Writes to CMINTEPE register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  cmintepe
///  Valid range is 32 bits.
///
void
_SI32_USB_A_write_cmintepe(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*cmintepe*/);
///
/// @def SI32_USB_A_write_cmintepe(basePointer, cmintepe)
#define SI32_USB_A_write_cmintepe(basePointer, cmintepe) \
   (basePointer->CMINTEPE.U32 = cmintepe)


/// @fn _SI32_USB_A_read_cmintepe(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads CMINTEPE register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_cmintepe(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_cmintepe(basePointer)
#define SI32_USB_A_read_cmintepe(basePointer) \
(basePointer->CMINTEPE.U32)


/// @fn _SI32_USB_A_enable_suspend_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_suspend_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_suspend_interrupt(basePointer)
#define SI32_USB_A_enable_suspend_interrupt(basePointer) \
   (basePointer->CMINTEPE.SUSIEN = SI32_USB_A_CMINTEPE_SUSIEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_suspend_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_suspend_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_suspend_interrupt(basePointer)
#define SI32_USB_A_disable_suspend_interrupt(basePointer) \
   (basePointer->CMINTEPE.SUSIEN = SI32_USB_A_CMINTEPE_SUSIEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_suspend_interrupt_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_suspend_interrupt_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_suspend_interrupt_enabled(basePointer)
#define SI32_USB_A_is_suspend_interrupt_enabled(basePointer) \
((bool)(basePointer->CMINTEPE.SUSIEN))


/// @fn _SI32_USB_A_enable_resume_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_resume_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_resume_interrupt(basePointer)
#define SI32_USB_A_enable_resume_interrupt(basePointer) \
   (basePointer->CMINTEPE.RESIEN = SI32_USB_A_CMINTEPE_RESIEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_resume_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_resume_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_resume_interrupt(basePointer)
#define SI32_USB_A_disable_resume_interrupt(basePointer) \
   (basePointer->CMINTEPE.RESIEN = SI32_USB_A_CMINTEPE_RESIEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_resume_interrupt_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_resume_interrupt_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_resume_interrupt_enabled(basePointer)
#define SI32_USB_A_is_resume_interrupt_enabled(basePointer) \
((bool)(basePointer->CMINTEPE.RESIEN))


/// @fn _SI32_USB_A_enable_reset_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_reset_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_reset_interrupt(basePointer)
#define SI32_USB_A_enable_reset_interrupt(basePointer) \
   (basePointer->CMINTEPE.RSTIEN = SI32_USB_A_CMINTEPE_RSTIEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_reset_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_reset_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_reset_interrupt(basePointer)
#define SI32_USB_A_disable_reset_interrupt(basePointer) \
   (basePointer->CMINTEPE.RSTIEN = SI32_USB_A_CMINTEPE_RSTIEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_reset_interrupt_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_reset_interrupt_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_reset_interrupt_enabled(basePointer)
#define SI32_USB_A_is_reset_interrupt_enabled(basePointer) \
((bool)(basePointer->CMINTEPE.RSTIEN))


/// @fn _SI32_USB_A_enable_start_of_frame_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_start_of_frame_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_start_of_frame_interrupt(basePointer)
#define SI32_USB_A_enable_start_of_frame_interrupt(basePointer) \
   (basePointer->CMINTEPE.SOFIEN = SI32_USB_A_CMINTEPE_SOFIEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_start_of_frame_interrupt(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_start_of_frame_interrupt(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_start_of_frame_interrupt(basePointer)
#define SI32_USB_A_disable_start_of_frame_interrupt(basePointer) \
   (basePointer->CMINTEPE.SOFIEN = SI32_USB_A_CMINTEPE_SOFIEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_start_of_frame_interrupt_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_start_of_frame_interrupt_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_start_of_frame_interrupt_enabled(basePointer)
#define SI32_USB_A_is_start_of_frame_interrupt_enabled(basePointer) \
((bool)(basePointer->CMINTEPE.SOFIEN))


/// @fn _SI32_USB_A_enable_ep0(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep0(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep0(basePointer)
#define SI32_USB_A_enable_ep0(basePointer) \
   (basePointer->CMINTEPE.EP0EN = SI32_USB_A_CMINTEPE_EP0EN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep0(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Endpoint 0 is disabled (no NACK, ACK, or STALL on the USB network).
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep0(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep0(basePointer)
#define SI32_USB_A_disable_ep0(basePointer) \
   (basePointer->CMINTEPE.EP0EN = SI32_USB_A_CMINTEPE_EP0EN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep0_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep0_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep0_enabled(basePointer)
#define SI32_USB_A_is_ep0_enabled(basePointer) \
((bool)(basePointer->CMINTEPE.EP0EN))


/// @fn _SI32_USB_A_enable_ep1(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep1(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep1(basePointer)
#define SI32_USB_A_enable_ep1(basePointer) \
   (basePointer->CMINTEPE.EP1EN = SI32_USB_A_CMINTEPE_EP1EN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep1(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Endpoint 1 is disabled (no NACK, ACK, or STALL on the USB network).
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep1(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep1(basePointer)
#define SI32_USB_A_disable_ep1(basePointer) \
   (basePointer->CMINTEPE.EP1EN = SI32_USB_A_CMINTEPE_EP1EN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep1_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep1_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep1_enabled(basePointer)
#define SI32_USB_A_is_ep1_enabled(basePointer) \
((bool)(basePointer->CMINTEPE.EP1EN))


/// @fn _SI32_USB_A_enable_ep2(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep2(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep2(basePointer)
#define SI32_USB_A_enable_ep2(basePointer) \
   (basePointer->CMINTEPE.EP2EN = SI32_USB_A_CMINTEPE_EP2EN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep2(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Endpoint 2 is disabled (no NACK, ACK, or STALL on the USB network).
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep2(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep2(basePointer)
#define SI32_USB_A_disable_ep2(basePointer) \
   (basePointer->CMINTEPE.EP2EN = SI32_USB_A_CMINTEPE_EP2EN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep2_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep2_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep2_enabled(basePointer)
#define SI32_USB_A_is_ep2_enabled(basePointer) \
((bool)(basePointer->CMINTEPE.EP2EN))


/// @fn _SI32_USB_A_enable_ep3(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep3(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep3(basePointer)
#define SI32_USB_A_enable_ep3(basePointer) \
   (basePointer->CMINTEPE.EP3EN = SI32_USB_A_CMINTEPE_EP3EN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep3(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Endpoint 3 is disabled (no NACK, ACK, or STALL on the USB network).
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep3(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep3(basePointer)
#define SI32_USB_A_disable_ep3(basePointer) \
   (basePointer->CMINTEPE.EP3EN = SI32_USB_A_CMINTEPE_EP3EN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep3_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep3_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep3_enabled(basePointer)
#define SI32_USB_A_is_ep3_enabled(basePointer) \
((bool)(basePointer->CMINTEPE.EP3EN))


/// @fn _SI32_USB_A_enable_ep4(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_ep4(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_ep4(basePointer)
#define SI32_USB_A_enable_ep4(basePointer) \
   (basePointer->CMINTEPE.EP4EN = SI32_USB_A_CMINTEPE_EP4EN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_ep4(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Endpoint 4 is disabled (no NACK, ACK, or STALL on the USB network).
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_ep4(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_ep4(basePointer)
#define SI32_USB_A_disable_ep4(basePointer) \
   (basePointer->CMINTEPE.EP4EN = SI32_USB_A_CMINTEPE_EP4EN_DISABLED_VALUE)


/// @fn _SI32_USB_A_is_ep4_enabled(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_ep4_enabled(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_ep4_enabled(basePointer)
#define SI32_USB_A_is_ep4_enabled(basePointer) \
((bool)(basePointer->CMINTEPE.EP4EN))


/// @fn _SI32_USB_A_write_crcontrol(SI32_USB_A_Type* basePointer,
///      uint32_t crcontrol)
///
/// @brief
/// Writes to CRCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  crcontrol
///  Valid range is 32 bits.
///
void
_SI32_USB_A_write_crcontrol(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*crcontrol*/);
///
/// @def SI32_USB_A_write_crcontrol(basePointer, crcontrol)
#define SI32_USB_A_write_crcontrol(basePointer, crcontrol) \
   (basePointer->CRCONTROL.U32 = crcontrol)


/// @fn _SI32_USB_A_read_crcontrol(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads CRCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_crcontrol(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_crcontrol(basePointer)
#define SI32_USB_A_read_crcontrol(basePointer) \
(basePointer->CRCONTROL.U32)


/// @fn _SI32_USB_A_enable_open_loop_mode(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_open_loop_mode(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_open_loop_mode(basePointer)
#define SI32_USB_A_enable_open_loop_mode(basePointer) \
   (basePointer->CRCONTROL.OLEN = SI32_USB_A_CRCONTROL_OLEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_open_loop_mode(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_open_loop_mode(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_open_loop_mode(basePointer)
#define SI32_USB_A_disable_open_loop_mode(basePointer) \
   (basePointer->CRCONTROL.OLEN = SI32_USB_A_CRCONTROL_OLEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_select_clock_recovery_mode_full_speed(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_select_clock_recovery_mode_full_speed(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_select_clock_recovery_mode_full_speed(basePointer)
#define SI32_USB_A_select_clock_recovery_mode_full_speed(basePointer) \
   (basePointer->CRCONTROL.LSCRMD = SI32_USB_A_CRCONTROL_LSCRMD_FULL_SPEED_VALUE)


/// @fn _SI32_USB_A_select_clock_recovery_mode_low_speed(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_select_clock_recovery_mode_low_speed(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_select_clock_recovery_mode_low_speed(basePointer)
#define SI32_USB_A_select_clock_recovery_mode_low_speed(basePointer) \
   (basePointer->CRCONTROL.LSCRMD = SI32_USB_A_CRCONTROL_LSCRMD_LOW_SPEED_VALUE)


/// @fn _SI32_USB_A_select_clock_recovery_single_step_cal(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_select_clock_recovery_single_step_cal(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_select_clock_recovery_single_step_cal(basePointer)
#define SI32_USB_A_select_clock_recovery_single_step_cal(basePointer) \
   (basePointer->CRCONTROL.CRSSEN = SI32_USB_A_CRCONTROL_CRSSEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_select_clock_recovery_normal_cal(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_select_clock_recovery_normal_cal(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_select_clock_recovery_normal_cal(basePointer)
#define SI32_USB_A_select_clock_recovery_normal_cal(basePointer) \
   (basePointer->CRCONTROL.CRSSEN = SI32_USB_A_CRCONTROL_CRSSEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_enable_clock_recovery(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_clock_recovery(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_clock_recovery(basePointer)
#define SI32_USB_A_enable_clock_recovery(basePointer) \
   (basePointer->CRCONTROL.CREN = SI32_USB_A_CRCONTROL_CREN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_clock_recovery(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_clock_recovery(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_clock_recovery(basePointer)
#define SI32_USB_A_disable_clock_recovery(basePointer) \
   (basePointer->CRCONTROL.CREN = SI32_USB_A_CRCONTROL_CREN_DISABLED_VALUE)


/// @fn _SI32_USB_A_write_tcontrol(SI32_USB_A_Type* basePointer,
///      uint32_t tcontrol)
///
/// @brief
/// Writes to TCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  tcontrol
///  Valid range is 32 bits.
///
void
_SI32_USB_A_write_tcontrol(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*tcontrol*/);
///
/// @def SI32_USB_A_write_tcontrol(basePointer, tcontrol)
#define SI32_USB_A_write_tcontrol(basePointer, tcontrol) \
   (basePointer->TCONTROL.U32 = tcontrol)


/// @fn _SI32_USB_A_read_tcontrol(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads TCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_tcontrol(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_tcontrol(basePointer)
#define SI32_USB_A_read_tcontrol(basePointer) \
(basePointer->TCONTROL.U32)


/// @fn _SI32_USB_A_select_transceiver_full_speed(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_select_transceiver_full_speed(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_select_transceiver_full_speed(basePointer)
#define SI32_USB_A_select_transceiver_full_speed(basePointer) \
   (basePointer->TCONTROL.SSEL = SI32_USB_A_TCONTROL_SSEL_FULL_SPEED_VALUE)


/// @fn _SI32_USB_A_select_transceiver_low_speed(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_select_transceiver_low_speed(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_select_transceiver_low_speed(basePointer)
#define SI32_USB_A_select_transceiver_low_speed(basePointer) \
   (basePointer->TCONTROL.SSEL = SI32_USB_A_TCONTROL_SSEL_LOW_SPEED_VALUE)


/// @fn _SI32_USB_A_enable_transceiver(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_transceiver(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_transceiver(basePointer)
#define SI32_USB_A_enable_transceiver(basePointer) \
   (basePointer->TCONTROL.PHYEN = SI32_USB_A_TCONTROL_PHYEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_transceiver(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_transceiver(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_transceiver(basePointer)
#define SI32_USB_A_disable_transceiver(basePointer) \
   (basePointer->TCONTROL.PHYEN = SI32_USB_A_TCONTROL_PHYEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_enable_internal_pull_up(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_internal_pull_up(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_internal_pull_up(basePointer)
#define SI32_USB_A_enable_internal_pull_up(basePointer) \
   (basePointer->TCONTROL.PUEN = SI32_USB_A_TCONTROL_PUEN_ENABLED_VALUE)


/// @fn _SI32_USB_A_disable_internal_pull_up(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_internal_pull_up(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_internal_pull_up(basePointer)
#define SI32_USB_A_disable_internal_pull_up(basePointer) \
   (basePointer->TCONTROL.PUEN = SI32_USB_A_TCONTROL_PUEN_DISABLED_VALUE)


/// @fn _SI32_USB_A_write_clksel(SI32_USB_A_Type* basePointer,
///      uint32_t clksel)
///
/// @brief
/// Writes to CLKSEL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  clksel
///  Valid range is 32 bits.
///
void
_SI32_USB_A_write_clksel(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*clksel*/);
///
/// @def SI32_USB_A_write_clksel(basePointer, clksel)
#define SI32_USB_A_write_clksel(basePointer, clksel) \
   (basePointer->CLKSEL.U32 = clksel)


/// @fn _SI32_USB_A_read_clksel(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads CLKSEL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_clksel(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_clksel(basePointer)
#define SI32_USB_A_read_clksel(basePointer) \
(basePointer->CLKSEL.U32)


/// @fn _SI32_USB_A_select_usb_clock_48mhz(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_select_usb_clock_48mhz(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_select_usb_clock_48mhz(basePointer)
#define SI32_USB_A_select_usb_clock_48mhz(basePointer) \
   (basePointer->CLKSEL.CLKSEL_BITS = SI32_USB_A_CLKSEL_CLKSEL_USBNOSC_VALUE)


/// @fn _SI32_USB_A_select_usb_clock_pll(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_select_usb_clock_pll(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_select_usb_clock_pll(basePointer)
#define SI32_USB_A_select_usb_clock_pll(basePointer) \
   (basePointer->CLKSEL.CLKSEL_BITS = SI32_USB_A_CLKSEL_CLKSEL_PLLNOSC_VALUE)


/// @fn _SI32_USB_A_select_usb_clock_external_oscillator(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_select_usb_clock_external_oscillator(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_select_usb_clock_external_oscillator(basePointer)
#define SI32_USB_A_select_usb_clock_external_oscillator(basePointer) \
   (basePointer->CLKSEL.CLKSEL_BITS = SI32_USB_A_CLKSEL_CLKSEL_EXTOSCN_VALUE)


/// @fn _SI32_USB_A_select_clock_divider_1(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_select_clock_divider_1(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_select_clock_divider_1(basePointer)
#define SI32_USB_A_select_clock_divider_1(basePointer) \
   (basePointer->CLKSEL.CLKDIV = SI32_USB_A_CLKSEL_CLKDIV_DIV1_VALUE)


/// @fn _SI32_USB_A_select_clock_divider_2(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_select_clock_divider_2(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_select_clock_divider_2(basePointer)
#define SI32_USB_A_select_clock_divider_2(basePointer) \
   (basePointer->CLKSEL.CLKDIV = SI32_USB_A_CLKSEL_CLKDIV_DIV2_VALUE)


/// @fn _SI32_USB_A_select_clock_divider_4(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_select_clock_divider_4(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_select_clock_divider_4(basePointer)
#define SI32_USB_A_select_clock_divider_4(basePointer) \
   (basePointer->CLKSEL.CLKDIV = SI32_USB_A_CLKSEL_CLKDIV_DIV4_VALUE)


/// @fn _SI32_USB_A_select_clock_divider_8(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_select_clock_divider_8(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_select_clock_divider_8(basePointer)
#define SI32_USB_A_select_clock_divider_8(basePointer) \
   (basePointer->CLKSEL.CLKDIV = SI32_USB_A_CLKSEL_CLKDIV_DIV8_VALUE)


/// @fn _SI32_USB_A_reset_module(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_reset_module(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_reset_module(basePointer)
#define SI32_USB_A_reset_module(basePointer) \
   (basePointer->CLKSEL.RESET = SI32_USB_A_CLKSEL_RESET_SET_VALUE)


/// @fn _SI32_USB_A_write_osccontrol(SI32_USB_A_Type* basePointer,
///      uint32_t osccontrol)
///
/// @brief
/// Writes to OSCCONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  osccontrol
///  Valid range is 32 bits.
///
void
_SI32_USB_A_write_osccontrol(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*osccontrol*/);
///
/// @def SI32_USB_A_write_osccontrol(basePointer, osccontrol)
#define SI32_USB_A_write_osccontrol(basePointer, osccontrol) \
   (basePointer->OSCCONTROL.U32 = osccontrol)


/// @fn _SI32_USB_A_read_osccontrol(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads OSCCONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_osccontrol(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_osccontrol(basePointer)
#define SI32_USB_A_read_osccontrol(basePointer) \
(basePointer->OSCCONTROL.U32)


/// @fn _SI32_USB_A_suspend_usb_oscillator(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Places the dedicated USB oscillator in Suspend mode.  Oscillator
/// resumes operation when one of the waking events occurs.
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_suspend_usb_oscillator(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_suspend_usb_oscillator(basePointer)
#define SI32_USB_A_suspend_usb_oscillator(basePointer) \
   (basePointer->OSCCONTROL_SET = SI32_USB_A_OSCCONTROL_SUSPEND_MASK)


/// @fn _SI32_USB_A_is_oscillator_ready(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Returns TRUE when oscillator ready, otherwise returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_oscillator_ready(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_oscillator_ready(basePointer)
#define SI32_USB_A_is_oscillator_ready(basePointer) \
((bool)(basePointer->OSCCONTROL.SUSPEND))


/// @fn _SI32_USB_A_enable_usb_oscillator(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_usb_oscillator(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_usb_oscillator(basePointer)
#define SI32_USB_A_enable_usb_oscillator(basePointer) \
   (basePointer->OSCCONTROL_SET = SI32_USB_A_OSCCONTROL_OSCEN_MASK)


/// @fn _SI32_USB_A_disable_usb_oscillator(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_usb_oscillator(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_usb_oscillator(basePointer)
#define SI32_USB_A_disable_usb_oscillator(basePointer) \
   (basePointer->OSCCONTROL_CLR = SI32_USB_A_OSCCONTROL_OSCEN_MASK)


/// @fn _SI32_USB_A_write_afadjust(SI32_USB_A_Type* basePointer,
///      uint32_t afadjust)
///
/// @brief
/// Writes to AFADJUST register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  afadjust
///  Valid range is 32 bits.
///
void
_SI32_USB_A_write_afadjust(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*afadjust*/);
///
/// @def SI32_USB_A_write_afadjust(basePointer, afadjust)
#define SI32_USB_A_write_afadjust(basePointer, afadjust) \
   (basePointer->AFADJUST.U32 = afadjust)


/// @fn _SI32_USB_A_read_afadjust(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads AFADJUST register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_afadjust(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_afadjust(basePointer)
#define SI32_USB_A_read_afadjust(basePointer) \
(basePointer->AFADJUST.U32)


/// @fn _SI32_USB_A_enable_oscillator_dither(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_enable_oscillator_dither(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_enable_oscillator_dither(basePointer)
#define SI32_USB_A_enable_oscillator_dither(basePointer) \
   (basePointer->AFADJUST_SET = SI32_USB_A_AFADJUST_DITHEN_MASK)


/// @fn _SI32_USB_A_disable_oscillator_dither(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_disable_oscillator_dither(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_disable_oscillator_dither(basePointer)
#define SI32_USB_A_disable_oscillator_dither(basePointer) \
   (basePointer->AFADJUST_CLR = SI32_USB_A_AFADJUST_DITHEN_MASK)


/// @fn _SI32_USB_A_write_dmacontrol(SI32_USB_A_Type* basePointer,
///      uint32_t dmacontrol)
///
/// @brief
/// Writes to DMACONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dmacontrol
///  Valid range is 32 bits.
///
void
_SI32_USB_A_write_dmacontrol(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*dmacontrol*/);
///
/// @def SI32_USB_A_write_dmacontrol(basePointer, dmacontrol)
#define SI32_USB_A_write_dmacontrol(basePointer, dmacontrol) \
   (basePointer->DMACONTROL.U32 = dmacontrol)


/// @fn _SI32_USB_A_read_dmacontrol(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads DMACONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_dmacontrol(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_dmacontrol(basePointer)
#define SI32_USB_A_read_dmacontrol(basePointer) \
(basePointer->DMACONTROL.U32)


/// @fn _SI32_USB_A_clear_dma_error(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_dma_error(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_dma_error(basePointer)
#define SI32_USB_A_clear_dma_error(basePointer) \
   (basePointer->DMACONTROL.TERRF = SI32_USB_A_DMACONTROL_TERRF_NOT_SET_VALUE)


/// @fn _SI32_USB_A_is_dma_error_set(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if DMA error occurred, otherwise returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_dma_error_set(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_dma_error_set(basePointer)
#define SI32_USB_A_is_dma_error_set(basePointer) \
((bool)(basePointer->DMACONTROL.TERRF))


/// @fn _SI32_USB_A_is_dma_busy(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if DMA is busy, otherwise returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_dma_busy(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_dma_busy(basePointer)
#define SI32_USB_A_is_dma_busy(basePointer) \
((bool)(basePointer->DMACONTROL.DBUSYF))


/// @fn _SI32_USB_A_flush_dma_buffer(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_flush_dma_buffer(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_flush_dma_buffer(basePointer)
#define SI32_USB_A_flush_dma_buffer(basePointer) \
   (basePointer->DMACONTROL.DFIFOFL = SI32_USB_A_DMACONTROL_DFIFOFL_SET_VALUE)


/// @fn _SI32_USB_A_write_ep0control(SI32_USB_A_Type* basePointer,
///      uint32_t ep0control)
///
/// @brief
/// Writes to EP0CONTROL.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  ep0control
///  Valid range is 32 bits.
///
void
_SI32_USB_A_write_ep0control(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*ep0control*/);
///
/// @def SI32_USB_A_write_ep0control(basePointer, ep0control)
#define SI32_USB_A_write_ep0control(basePointer, ep0control) \
   (basePointer->EP0CONTROL.U32 = ep0control)


/// @fn _SI32_USB_A_read_ep0control(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads EP0CONTROL regsiter.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_ep0control(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_ep0control(basePointer)
#define SI32_USB_A_read_ep0control(basePointer) \
(basePointer->EP0CONTROL.U32)


/// @fn _SI32_USB_A_is_out_packet_ready_ep0(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if packet available, otherwise returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_out_packet_ready_ep0(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_out_packet_ready_ep0(basePointer)
#define SI32_USB_A_is_out_packet_ready_ep0(basePointer) \
((bool)(basePointer->EP0CONTROL.OPRDYI))


/// @fn _SI32_USB_A_set_in_packet_ready_ep0(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Sets IPRDY bit to indicate packet loaded to EP0FIFO for transmit to
/// host.
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_set_in_packet_ready_ep0(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_set_in_packet_ready_ep0(basePointer)
#define SI32_USB_A_set_in_packet_ready_ep0(basePointer) \
   (basePointer->EP0CONTROL.IPRDYI = SI32_USB_A_EP0CONTROL_IPRDYI_SET_VALUE)


/// @fn _SI32_USB_A_is_stall_sent_ep0(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Returns TRUE if stall sent, otherwise returns FALSE.
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_stall_sent_ep0(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_stall_sent_ep0(basePointer)
#define SI32_USB_A_is_stall_sent_ep0(basePointer) \
((bool)(basePointer->EP0CONTROL.STSTLI))


/// @fn _SI32_USB_A_clear_stall_sent_ep0(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_stall_sent_ep0(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_stall_sent_ep0(basePointer)
#define SI32_USB_A_clear_stall_sent_ep0(basePointer) \
   (basePointer->EP0CONTROL.STSTLI = SI32_USB_A_EP0CONTROL_STSTLI_NOT_SET_VALUE)


/// @fn _SI32_USB_A_set_data_end_ep0(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_set_data_end_ep0(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_set_data_end_ep0(basePointer)
#define SI32_USB_A_set_data_end_ep0(basePointer) \
   (basePointer->EP0CONTROL.DEND = SI32_USB_A_EP0CONTROL_DEND_SET_VALUE)


/// @fn _SI32_USB_A_is_setup_end_early_ep0(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_USB_A_is_setup_end_early_ep0(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_is_setup_end_early_ep0(basePointer)
#define SI32_USB_A_is_setup_end_early_ep0(basePointer) \
((bool)(basePointer->EP0CONTROL.SUENDI))


/// @fn _SI32_USB_A_send_stall_ep0(SI32_USB_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_send_stall_ep0(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_send_stall_ep0(basePointer)
#define SI32_USB_A_send_stall_ep0(basePointer) \
   (basePointer->EP0CONTROL.SDSTL = SI32_USB_A_EP0CONTROL_SDSTL_SET_VALUE)


/// @fn _SI32_USB_A_clear_out_packet_ready_ep0(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Sets OPRDYIS bit, which clears OPRDYI.
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_out_packet_ready_ep0(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_out_packet_ready_ep0(basePointer)
#define SI32_USB_A_clear_out_packet_ready_ep0(basePointer) \
   (basePointer->EP0CONTROL.OPRDYIS = SI32_USB_A_EP0CONTROL_OPRDYIS_SET_VALUE)


/// @fn _SI32_USB_A_clear_setup_end_early_ep0(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Sets SUENDIS bit, which clears SUENDI.
///
/// @param[in]
///  basePointer
///
void
_SI32_USB_A_clear_setup_end_early_ep0(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_clear_setup_end_early_ep0(basePointer)
#define SI32_USB_A_clear_setup_end_early_ep0(basePointer) \
   (basePointer->EP0CONTROL.SUENDIS = SI32_USB_A_EP0CONTROL_SUENDIS_SET_VALUE)


/// @fn _SI32_USB_A_read_ep0_count(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Returns number of received data bytes in Endpoint 0 FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_ep0_count(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_ep0_count(basePointer)
#define SI32_USB_A_read_ep0_count(basePointer) \
((uint32_t)(basePointer->EP0COUNT.U32))


/// @fn _SI32_USB_A_write_ep0_fifo_u32(SI32_USB_A_Type* basePointer,
///      uint32_t dataval)
///
/// @brief
/// Writes one word to Endpoint 0 FIFO.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dataval
///
void
_SI32_USB_A_write_ep0_fifo_u32(SI32_USB_A_Type* /*basePointer*/,
   uint32_t /*dataval*/);
///
/// @def SI32_USB_A_write_ep0_fifo_u32(basePointer, dataval)
#define SI32_USB_A_write_ep0_fifo_u32(basePointer, dataval) \
   (basePointer->EP0FIFO.U32 = dataval)


/// @fn _SI32_USB_A_write_ep0_fifo_u16(SI32_USB_A_Type* basePointer,
///      uint16_t dataval)
///
/// @brief
/// Writes one half-word to Endpoint 0 FIFO.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dataval
///
void
_SI32_USB_A_write_ep0_fifo_u16(SI32_USB_A_Type* /*basePointer*/,
   uint16_t /*dataval*/);
///
/// @def SI32_USB_A_write_ep0_fifo_u16(basePointer, dataval)
#define SI32_USB_A_write_ep0_fifo_u16(basePointer, dataval) \
   (basePointer->EP0FIFO.U16 = dataval)


/// @fn _SI32_USB_A_write_ep0_fifo_u8(SI32_USB_A_Type* basePointer,
///      uint8_t dataval)
///
/// @brief
/// Writes one byte to Endpont 0 FIFO.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  dataval
///
void
_SI32_USB_A_write_ep0_fifo_u8(SI32_USB_A_Type* /*basePointer*/,
   uint8_t /*dataval*/);
///
/// @def SI32_USB_A_write_ep0_fifo_u8(basePointer, dataval)
#define SI32_USB_A_write_ep0_fifo_u8(basePointer, dataval) \
   (basePointer->EP0FIFO.U8 = dataval)


/// @fn _SI32_USB_A_read_ep0_fifo_u32(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads one word from Endpoint 0 FIFO.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_USB_A_read_ep0_fifo_u32(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_ep0_fifo_u32(basePointer)
#define SI32_USB_A_read_ep0_fifo_u32(basePointer) \
((basePointer->EP0FIFO.U32))


/// @fn _SI32_USB_A_read_ep0_fifo_u16(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads one half-word from Endpoint 0 FIFO.
///
/// @param[in]
///  basePointer
///
uint16_t
_SI32_USB_A_read_ep0_fifo_u16(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_ep0_fifo_u16(basePointer)
#define SI32_USB_A_read_ep0_fifo_u16(basePointer) \
((basePointer->EP0FIFO.U16))


/// @fn _SI32_USB_A_read_ep0_fifo_u8(SI32_USB_A_Type* basePointer)
///
/// @brief
/// Reads one byte from Endpoint 0 FIFO.
///
/// @param[in]
///  basePointer
///
uint8_t
_SI32_USB_A_read_ep0_fifo_u8(SI32_USB_A_Type* /*basePointer*/);
///
/// @def SI32_USB_A_read_ep0_fifo_u8(basePointer)
#define SI32_USB_A_read_ep0_fifo_u8(basePointer) \
((basePointer->EP0FIFO.U8))



#ifdef __cplusplus
}
#endif

#endif // __SI32_USB_A_TYPE_H__

//-eof--------------------------------------------------------------------------
