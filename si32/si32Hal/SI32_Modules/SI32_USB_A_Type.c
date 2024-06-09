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
/// @file SI32_USB_A_Type.c
//
// Script: 0.58
// HAL Source: 0.4
// Version: 9

#include <assert.h>
#include "si32WideTypes.h"
#include "SI32_USB_A_Type.h"


//-----------------------------------------------------------------------------
// _SI32_USB_A_initialize
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_initialize(
   SI32_USB_A_Type * basePointer,
   // Write to FADDR register.
   uint32_t faddr,
   // Write to POWER register.
   uint32_t power,
   // Write to IOINT register.
   uint32_t ioint,
   // Write to CMINT register.
   uint32_t cmint,
   // Write to IOINTE register.
   uint32_t iointe,
   // Write to CMINTEPE register.
   uint32_t cmintepe,
   // Write to CRCONTROL register.
   uint32_t crcontrol,
   // Write to TCONTROL register.
   uint32_t tcontrol,
   // Write to CLKSEL register.
   uint32_t clksel,
   // Write to OSCCONTROL register.
   uint32_t osccontrol,
   // Write to DMACONTROL register.
   uint32_t dmacontrol,
   // Write to EP0CONTROL register.
   uint32_t ep0control)
{
   //{{
   basePointer->FADDR.U32 = faddr;
   basePointer->POWER.U32 = power;
   basePointer->IOINT.U32 = ioint;
   basePointer->CMINT.U32 = cmint;
   basePointer->IOINTE.U32 = iointe;
   basePointer->CMINTEPE.U32 = cmintepe;
   basePointer->CRCONTROL.U32 = crcontrol;
   basePointer->TCONTROL.U32 = tcontrol;
   basePointer->CLKSEL.U32 = clksel;
   basePointer->OSCCONTROL.U32 = osccontrol;
   basePointer->DMACONTROL.U32 = dmacontrol;
   basePointer->EP0CONTROL.U32 = ep0control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_faddr
//
// Writes to FADDR register.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_faddr(
   SI32_USB_A_Type * basePointer,
   uint32_t faddr)
{
   //{{
   basePointer->FADDR.U32 = faddr;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_faddr
//
// Reads FADDR register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_faddr(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return basePointer->FADDR.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_function_address_updating
//
// Returns TRUE if update is in progress, returns FALSE if update is
// complete.
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_function_address_updating(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->FADDR.FADDRUPD);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_power
//
// Writes to POWER register.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_power(
   SI32_USB_A_Type * basePointer,
   uint32_t power)
{
   //{{
   basePointer->POWER.U32 = power;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_power
//
// Reads POWER register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_power(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return basePointer->POWER.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_suspend_detection
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_suspend_detection(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->POWER.SUSDEN = SI32_USB_A_POWER_SUSDEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_suspend_detection
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_suspend_detection(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->POWER.SUSDEN = SI32_USB_A_POWER_SUSDEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_suspend_detected
//
// Returns TRUE if in suspend, otherwise returns FALSE.
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_suspend_detected(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->POWER.SUSMDF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_generate_resume_signaling
//
// After function call, firmware should call stop_resume_signalling()
// after 10-15 ms.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_generate_resume_signaling(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->POWER.RESUME = SI32_USB_A_POWER_RESUME_GENERATE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_stop_resume_signaling
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_stop_resume_signaling(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->POWER.RESUME = SI32_USB_A_POWER_RESUME_STOP_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_reset_detected
//
// Returns TRUE of reset signaling detected, otherwise returns FALSE.
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_reset_detected(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->POWER.RSTDETF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_module
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_module(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->POWER.USBINH = SI32_USB_A_POWER_USBINH_INACTIVE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_module
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_module(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->POWER.USBINH = SI32_USB_A_POWER_USBINH_ACTIVE_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_signal_dither
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_signal_dither(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->POWER.DITHEN = SI32_USB_A_POWER_DITHEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_signal_dither
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_signal_dither(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->POWER.DITHEN = SI32_USB_A_POWER_DITHEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_send_isochronous_packet_on_in
//
// For isochronous endpoints, when software writes INPRDY = '1', USBn
// will send the packet when the next IN token is received.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_send_isochronous_packet_on_in(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->POWER.ISOUPDMD = SI32_USB_A_POWER_ISOUPDMD_SEND_ON_IN_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_send_isochronous_packet_on_sof
//
// For isochronous endpoints, when software writes INPRDY = '1', USBn
// will wait for a SOF token before sending the packet. If an IN token is
// received before a SOF token, USBn will send a zero-length data packet.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_send_isochronous_packet_on_sof(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->POWER.ISOUPDMD = SI32_USB_A_POWER_ISOUPDMD_SEND_ON_SOF_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_ioint
//
// Writes to IOINT register.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_ioint(
   SI32_USB_A_Type * basePointer,
   uint32_t ioint)
{
   //{{
   basePointer->IOINT.U32 = ioint;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_ioint
//
// Reads IOINT register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_ioint(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return basePointer->IOINT.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_ep0_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_ep0_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINT.U32 = SI32_USB_A_IOINT_EP0I_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep0_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep0_interrupt_pending(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->IOINT.EP0I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_ep1_in_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_ep1_in_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINT.U32 = SI32_USB_A_IOINT_IN1I_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep1_in_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep1_in_interrupt_pending(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->IOINT.IN1I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_ep2_in_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_ep2_in_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINT.U32 = SI32_USB_A_IOINT_IN2I_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep2_in_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep2_in_interrupt_pending(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->IOINT.IN2I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_ep3_in_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_ep3_in_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINT.U32 = SI32_USB_A_IOINT_IN3I_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep3_in_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep3_in_interrupt_pending(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->IOINT.IN3I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_ep4_in_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_ep4_in_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINT.U32 = SI32_USB_A_IOINT_IN4I_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep4_in_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep4_in_interrupt_pending(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->IOINT.IN4I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_ep1_out_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_ep1_out_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINT.U32 = SI32_USB_A_IOINT_OUT1I_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep1_out_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep1_out_interrupt_pending(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->IOINT.OUT1I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_ep2_out_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_ep2_out_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINT.U32 = SI32_USB_A_IOINT_OUT2I_SET_U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep2_out_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep2_out_interrupt_pending(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->IOINT.OUT2I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_ep3_out_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_ep3_out_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINT.U32 = SI32_USB_A_IOINT_OUT3I_SET_U32;;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep3_out_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep3_out_interrupt_pending(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->IOINT.OUT3I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_ep4_out_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_ep4_out_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINT.U32 = SI32_USB_A_IOINT_OUT4I_SET_U32;;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep4_out_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep4_out_interrupt_pending(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->IOINT.OUT4I);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_cmint
//
// Writes to CMINT register.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_cmint(
   SI32_USB_A_Type * basePointer,
   uint32_t cmint)
{
   //{{
   basePointer->CMINT.U32 = cmint;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_cmint
//
// Reads CMINT register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_cmint(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return basePointer->CMINT.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_suspend_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_suspend_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINT.SUSI = SI32_USB_A_CMINT_SUSI_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_suspend_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_suspend_interrupt_pending(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CMINT.SUSI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_resume_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_resume_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINT.RESI = SI32_USB_A_CMINT_RESI_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_resume_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_resume_interrupt_pending(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CMINT.RESI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_reset_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_reset_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINT.RSTI = SI32_USB_A_CMINT_RSTI_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_reset_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_reset_interrupt_pending(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CMINT.RSTI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_start_of_frame_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_start_of_frame_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINT.SOFI = SI32_USB_A_CMINT_SOFI_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_start_of_frame_interrupt_pending
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_start_of_frame_interrupt_pending(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CMINT.SOFI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_iointe
//
// Writes to IOINT register.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_iointe(
   SI32_USB_A_Type * basePointer,
   uint32_t iointe)
{
   //{{
   basePointer->IOINTE.U32 = iointe;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_iointe
//
// Reads IOINT register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_iointe(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return basePointer->IOINTE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep0_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep0_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.EP0IEN = SI32_USB_A_IOINTE_EP0IEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep0_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep0_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.EP0IEN = SI32_USB_A_IOINTE_EP0IEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep0_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep0_interrupt_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->IOINTE.EP0IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep1_in_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep1_in_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.IN1IEN = SI32_USB_A_IOINTE_IN1IEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep1_in_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep1_in_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.IN1IEN = SI32_USB_A_IOINTE_IN1IEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep1_in_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep1_in_interrupt_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->IOINTE.IN1IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep2_in_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep2_in_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.IN2IEN = SI32_USB_A_IOINTE_IN2IEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep2_in_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep2_in_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.IN2IEN = SI32_USB_A_IOINTE_IN2IEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep2_in_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep2_in_interrupt_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->IOINTE.IN2IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep3_in_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep3_in_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.IN3IEN = SI32_USB_A_IOINTE_IN3IEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep3_in_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep3_in_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.IN3IEN = SI32_USB_A_IOINTE_IN3IEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep3_in_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep3_in_interrupt_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->IOINTE.IN3IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep4_in_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep4_in_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.IN4IEN = SI32_USB_A_IOINTE_IN4IEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep4_in_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep4_in_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.IN4IEN = SI32_USB_A_IOINTE_IN4IEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep4_in_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep4_in_interrupt_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->IOINTE.IN4IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep1_out_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep1_out_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.OUT1IEN = SI32_USB_A_IOINTE_OUT1IEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep1_out_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep1_out_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.OUT1IEN = SI32_USB_A_IOINTE_OUT1IEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep1_out_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep1_out_interrupt_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->IOINTE.OUT1IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep2_out_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep2_out_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.OUT2IEN = SI32_USB_A_IOINTE_OUT2IEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep2_out_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep2_out_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.OUT2IEN = SI32_USB_A_IOINTE_OUT2IEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep2_out_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep2_out_interrupt_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->IOINTE.OUT2IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep3_out_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep3_out_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.OUT3IEN = SI32_USB_A_IOINTE_OUT3IEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep3_out_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep3_out_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.OUT3IEN = SI32_USB_A_IOINTE_OUT3IEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep3_out_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep3_out_interrupt_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->IOINTE.OUT3IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep4_out_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep4_out_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.OUT4IEN = SI32_USB_A_IOINTE_OUT4IEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep4_out_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep4_out_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->IOINTE.OUT4IEN = SI32_USB_A_IOINTE_OUT4IEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep4_out_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep4_out_interrupt_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->IOINTE.OUT4IEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_cmintepe
//
// Writes to CMINTEPE register.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_cmintepe(
   SI32_USB_A_Type * basePointer,
   uint32_t cmintepe)
{
   //{{
   basePointer->CMINTEPE.U32 = cmintepe;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_cmintepe
//
// Reads CMINTEPE register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_cmintepe(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return basePointer->CMINTEPE.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_suspend_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_suspend_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.SUSIEN = SI32_USB_A_CMINTEPE_SUSIEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_suspend_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_suspend_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.SUSIEN = SI32_USB_A_CMINTEPE_SUSIEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_suspend_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_suspend_interrupt_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CMINTEPE.SUSIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_resume_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_resume_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.RESIEN = SI32_USB_A_CMINTEPE_RESIEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_resume_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_resume_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.RESIEN = SI32_USB_A_CMINTEPE_RESIEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_resume_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_resume_interrupt_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CMINTEPE.RESIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_reset_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_reset_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.RSTIEN = SI32_USB_A_CMINTEPE_RSTIEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_reset_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_reset_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.RSTIEN = SI32_USB_A_CMINTEPE_RSTIEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_reset_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_reset_interrupt_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CMINTEPE.RSTIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_start_of_frame_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_start_of_frame_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.SOFIEN = SI32_USB_A_CMINTEPE_SOFIEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_start_of_frame_interrupt
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_start_of_frame_interrupt(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.SOFIEN = SI32_USB_A_CMINTEPE_SOFIEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_start_of_frame_interrupt_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_start_of_frame_interrupt_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
	return (bool)(basePointer->CMINTEPE.SOFIEN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep0
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep0(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.EP0EN = SI32_USB_A_CMINTEPE_EP0EN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep0
//
// Endpoint 0 is disabled (no NACK, ACK, or STALL on the USB network).
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep0(
   SI32_USB_A_Type * basePointer)
{
   //{{
	basePointer->CMINTEPE.EP0EN = SI32_USB_A_CMINTEPE_EP0EN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep0_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep0_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CMINTEPE.EP0EN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep1
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep1(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.EP1EN = SI32_USB_A_CMINTEPE_EP1EN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep1
//
// Endpoint 1 is disabled (no NACK, ACK, or STALL on the USB network).
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep1(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.EP1EN = SI32_USB_A_CMINTEPE_EP1EN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep1_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep1_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CMINTEPE.EP1EN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep2
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep2(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.EP2EN = SI32_USB_A_CMINTEPE_EP2EN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep2
//
// Endpoint 2 is disabled (no NACK, ACK, or STALL on the USB network).
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep2(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.EP2EN = SI32_USB_A_CMINTEPE_EP2EN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep2_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep2_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CMINTEPE.EP2EN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep3
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep3(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.EP3EN = SI32_USB_A_CMINTEPE_EP3EN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep3
//
// Endpoint 3 is disabled (no NACK, ACK, or STALL on the USB network).
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep3(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.EP3EN = SI32_USB_A_CMINTEPE_EP3EN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep3_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep3_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CMINTEPE.EP3EN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_ep4
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_ep4(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.EP4EN = SI32_USB_A_CMINTEPE_EP4EN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_ep4
//
// Endpoint 4 is disabled (no NACK, ACK, or STALL on the USB network).
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_ep4(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CMINTEPE.EP4EN = SI32_USB_A_CMINTEPE_EP4EN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_ep4_enabled
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_ep4_enabled(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->CMINTEPE.EP4EN);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_crcontrol
//
// Writes to CRCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_crcontrol(
   SI32_USB_A_Type * basePointer,
   uint32_t crcontrol)
{
   //{{
   basePointer->CRCONTROL.U32 = crcontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_crcontrol
//
// Reads CRCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_crcontrol(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return basePointer->CRCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_open_loop_mode
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_open_loop_mode(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CRCONTROL.OLEN = SI32_USB_A_CRCONTROL_OLEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_open_loop_mode
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_open_loop_mode(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CRCONTROL.OLEN = SI32_USB_A_CRCONTROL_OLEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_select_clock_recovery_mode_full_speed
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_select_clock_recovery_mode_full_speed(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CRCONTROL.LSCRMD = SI32_USB_A_CRCONTROL_LSCRMD_FULL_SPEED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_select_clock_recovery_mode_low_speed
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_select_clock_recovery_mode_low_speed(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CRCONTROL.LSCRMD = SI32_USB_A_CRCONTROL_LSCRMD_LOW_SPEED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_select_clock_recovery_single_step_cal
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_select_clock_recovery_single_step_cal(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CRCONTROL.CRSSEN = SI32_USB_A_CRCONTROL_CRSSEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_select_clock_recovery_normal_cal
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_select_clock_recovery_normal_cal(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CRCONTROL.CRSSEN = SI32_USB_A_CRCONTROL_CRSSEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_clock_recovery
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_clock_recovery(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CRCONTROL.CREN = SI32_USB_A_CRCONTROL_CREN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_clock_recovery
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_clock_recovery(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CRCONTROL.CREN = SI32_USB_A_CRCONTROL_CREN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_tcontrol
//
// Writes to TCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_tcontrol(
   SI32_USB_A_Type * basePointer,
   uint32_t tcontrol)
{
   //{{
  basePointer->TCONTROL.U32 = tcontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_tcontrol
//
// Reads TCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_tcontrol(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return basePointer->TCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_select_transceiver_full_speed
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_select_transceiver_full_speed(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->TCONTROL.SSEL = SI32_USB_A_TCONTROL_SSEL_FULL_SPEED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_select_transceiver_low_speed
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_select_transceiver_low_speed(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->TCONTROL.SSEL = SI32_USB_A_TCONTROL_SSEL_LOW_SPEED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_transceiver
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_transceiver(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->TCONTROL.PHYEN = SI32_USB_A_TCONTROL_PHYEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_transceiver
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_transceiver(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->TCONTROL.PHYEN = SI32_USB_A_TCONTROL_PHYEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_internal_pull_up
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_internal_pull_up(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->TCONTROL.PUEN = SI32_USB_A_TCONTROL_PUEN_ENABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_internal_pull_up
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_internal_pull_up(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->TCONTROL.PUEN = SI32_USB_A_TCONTROL_PUEN_DISABLED_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_clksel
//
// Writes to CLKSEL register.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_clksel(
   SI32_USB_A_Type * basePointer,
   uint32_t clksel)
{
   //{{
   basePointer->CLKSEL.U32 = clksel;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_clksel
//
// Reads CLKSEL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_clksel(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return basePointer->CLKSEL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_select_usb_clock_48mhz
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_select_usb_clock_48mhz(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CLKSEL.CLKSEL_BITS = SI32_USB_A_CLKSEL_CLKSEL_USBNOSC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_select_usb_clock_pll
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_select_usb_clock_pll(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CLKSEL.CLKSEL_BITS = SI32_USB_A_CLKSEL_CLKSEL_PLLNOSC_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_select_usb_clock_external_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_select_usb_clock_external_oscillator(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CLKSEL.CLKSEL_BITS = SI32_USB_A_CLKSEL_CLKSEL_EXTOSCN_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_select_clock_divider_1
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_select_clock_divider_1(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CLKSEL.CLKDIV = SI32_USB_A_CLKSEL_CLKDIV_DIV1_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_select_clock_divider_2
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_select_clock_divider_2(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CLKSEL.CLKDIV = SI32_USB_A_CLKSEL_CLKDIV_DIV2_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_select_clock_divider_4
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_select_clock_divider_4(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CLKSEL.CLKDIV = SI32_USB_A_CLKSEL_CLKDIV_DIV4_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_select_clock_divider_8
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_select_clock_divider_8(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CLKSEL.CLKDIV = SI32_USB_A_CLKSEL_CLKDIV_DIV8_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_reset_module
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_reset_module(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->CLKSEL.RESET = SI32_USB_A_CLKSEL_RESET_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_osccontrol
//
// Writes to OSCCONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_osccontrol(
   SI32_USB_A_Type * basePointer,
   uint32_t osccontrol)
{
   //{{
   basePointer->OSCCONTROL.U32 = osccontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_osccontrol
//
// Reads OSCCONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_osccontrol(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return basePointer->OSCCONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_suspend_usb_oscillator
//
// Places the dedicated USB oscillator in Suspend mode.  Oscillator
// resumes operation when one of the waking events occurs.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_suspend_usb_oscillator(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->OSCCONTROL_SET = SI32_USB_A_OSCCONTROL_SUSPEND_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_oscillator_ready
//
// Returns TRUE when oscillator ready, otherwise returns FALSE.
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_oscillator_ready(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->OSCCONTROL.SUSPEND);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_usb_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_usb_oscillator(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->OSCCONTROL_SET = SI32_USB_A_OSCCONTROL_OSCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_usb_oscillator
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_usb_oscillator(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->OSCCONTROL_CLR = SI32_USB_A_OSCCONTROL_OSCEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_afadjust
//
// Writes to AFADJUST register.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_afadjust(
   SI32_USB_A_Type * basePointer,
   uint32_t afadjust)
{
   //{{
   basePointer->AFADJUST.U32 = afadjust;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_afadjust
//
// Reads AFADJUST register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_afadjust(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return basePointer->AFADJUST.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_enable_oscillator_dither
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_enable_oscillator_dither(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->AFADJUST_SET = SI32_USB_A_AFADJUST_DITHEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_disable_oscillator_dither
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_disable_oscillator_dither(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->AFADJUST_CLR = SI32_USB_A_AFADJUST_DITHEN_MASK;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_dmacontrol
//
// Writes to DMACONTROL register.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_dmacontrol(
   SI32_USB_A_Type * basePointer,
   uint32_t dmacontrol)
{
   //{{
   basePointer->DMACONTROL.U32 = dmacontrol;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_dmacontrol
//
// Reads DMACONTROL register.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_dmacontrol(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return basePointer->DMACONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_dma_error
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_dma_error(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->DMACONTROL.TERRF = SI32_USB_A_DMACONTROL_TERRF_NOT_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_dma_error_set
//
// Returns TRUE if DMA error occurred, otherwise returns FALSE.
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_dma_error_set(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->DMACONTROL.TERRF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_dma_busy
//
// Returns TRUE if DMA is busy, otherwise returns FALSE.
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_dma_busy(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->DMACONTROL.DBUSYF);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_flush_dma_buffer
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_flush_dma_buffer(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->DMACONTROL.DFIFOFL = SI32_USB_A_DMACONTROL_DFIFOFL_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_ep0control
//
// Writes to EP0CONTROL.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_ep0control(
   SI32_USB_A_Type * basePointer,
   uint32_t ep0control)
{
   //{{
   basePointer->EP0CONTROL.U32 = ep0control;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_ep0control
//
// Reads EP0CONTROL regsiter.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_ep0control(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return basePointer->EP0CONTROL.U32;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_out_packet_ready_ep0
//
// Returns TRUE if packet available, otherwise returns FALSE.
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_out_packet_ready_ep0(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->EP0CONTROL.OPRDYI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_set_in_packet_ready_ep0
//
// Sets IPRDY bit to indicate packet loaded to EP0FIFO for transmit to
// host.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_set_in_packet_ready_ep0(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->EP0CONTROL.IPRDYI = SI32_USB_A_EP0CONTROL_IPRDYI_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_stall_sent_ep0
//
// Returns TRUE if stall sent, otherwise returns FALSE.
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_stall_sent_ep0(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->EP0CONTROL.STSTLI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_stall_sent_ep0
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_stall_sent_ep0(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->EP0CONTROL.STSTLI = SI32_USB_A_EP0CONTROL_STSTLI_NOT_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_set_data_end_ep0
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_set_data_end_ep0(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->EP0CONTROL.DEND = SI32_USB_A_EP0CONTROL_DEND_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_is_setup_end_early_ep0
//
//-----------------------------------------------------------------------------
bool
_SI32_USB_A_is_setup_end_early_ep0(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (bool)(basePointer->EP0CONTROL.SUENDI);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_send_stall_ep0
//
//-----------------------------------------------------------------------------
void
_SI32_USB_A_send_stall_ep0(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->EP0CONTROL.SDSTL = SI32_USB_A_EP0CONTROL_SDSTL_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_out_packet_ready_ep0
//
// Sets OPRDYIS bit, which clears OPRDYI.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_out_packet_ready_ep0(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->EP0CONTROL.OPRDYIS = SI32_USB_A_EP0CONTROL_OPRDYIS_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_clear_setup_end_early_ep0
//
// Sets SUENDIS bit, which clears SUENDI.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_clear_setup_end_early_ep0(
   SI32_USB_A_Type * basePointer)
{
   //{{
   basePointer->EP0CONTROL.SUENDIS = SI32_USB_A_EP0CONTROL_SUENDIS_SET_VALUE;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_ep0_count
//
// Returns number of received data bytes in Endpoint 0 FIFO.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_ep0_count(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (uint32_t)(basePointer->EP0COUNT.U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_ep0_fifo_u32
//
// Writes one word to Endpoint 0 FIFO.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_ep0_fifo_u32(
   SI32_USB_A_Type * basePointer,
   uint32_t dataval)
{
   //{{
   basePointer->EP0FIFO.U32 = dataval;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_ep0_fifo_u16
//
// Writes one half-word to Endpoint 0 FIFO.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_ep0_fifo_u16(
   SI32_USB_A_Type * basePointer,
   uint16_t dataval)
{
   //{{
   basePointer->EP0FIFO.U16 = dataval;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_write_ep0_fifo_u8
//
// Writes one byte to Endpont 0 FIFO.
//-----------------------------------------------------------------------------
void
_SI32_USB_A_write_ep0_fifo_u8(
   SI32_USB_A_Type * basePointer,
   uint8_t dataval)
{
   //{{
   basePointer->EP0FIFO.U8 = dataval;
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_ep0_fifo_u32
//
// Reads one word from Endpoint 0 FIFO.
//-----------------------------------------------------------------------------
uint32_t
_SI32_USB_A_read_ep0_fifo_u32(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (basePointer->EP0FIFO.U32);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_ep0_fifo_u16
//
// Reads one half-word from Endpoint 0 FIFO.
//-----------------------------------------------------------------------------
uint16_t
_SI32_USB_A_read_ep0_fifo_u16(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (basePointer->EP0FIFO.U16);
   //}}
}

//-----------------------------------------------------------------------------
// _SI32_USB_A_read_ep0_fifo_u8
//
// Reads one byte from Endpoint 0 FIFO.
//-----------------------------------------------------------------------------
uint8_t
_SI32_USB_A_read_ep0_fifo_u8(
   SI32_USB_A_Type * basePointer)
{
   //{{
   return (basePointer->EP0FIFO.U8);
   //}}
}


//-eof--------------------------------------------------------------------------
