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
/// @file SI32_DTM_A_Type.h
//
// Script: 0.6
// HAL Source: 0.2
// Version: 1

#ifndef __SI32_DTM_A_TYPE_H__
#define __SI32_DTM_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_DTM_A_Registers.h"

// support defeinitions
#include "SI32_DTM_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_DTM_A_initialize(SI32_DTM_A_Type* basePointer,
///      uint32_t control,
///      uint32_t timeout,
///      uint32_t mstcount,
///      uint32_t stateaddr)
///
/// @brief
/// Initializes all writeable DTM registers.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  Initial CONTROL register value.
///
/// @param[in]
///  timeout
///  Valid range is 32 bits.
///  Initial TIMEOUT register value.
///
/// @param[in]
///  mstcount
///  Valid range is 32 bits.
///  Initial MSTCOUNT register value.
///
/// @param[in]
///  stateaddr
///  Valid range is 32 bits.
///  Initial STATEADDR register value.
///
void
_SI32_DTM_A_initialize(SI32_DTM_A_Type* /*basePointer*/,
   uint32_t, /*control*/
   uint32_t, /*timeout*/
   uint32_t, /*mstcount*/
   uint32_t /*stateaddr*/);
///
/// @def SI32_DTM_A_initialize(basePointer, control, timeout, mstcount, stateaddr)
#define SI32_DTM_A_initialize(basePointer, control, timeout, mstcount, stateaddr) do{  \
   basePointer->CONTROL.U32 = control;\
   basePointer->TIMEOUT.U32 = timeout;\
   basePointer->MSTCOUNT.U32 = mstcount;\
   basePointer->STATEADDR.U32 = stateaddr;\
} while(0)


/// @fn _SI32_DTM_A_write_control(SI32_DTM_A_Type* basePointer,
///      uint32_t control)
///
/// @brief
/// Writes the CONTROL register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  control
///  Valid range is 32 bits.
///  CONTROL register value.
///
void
_SI32_DTM_A_write_control(SI32_DTM_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_DTM_A_write_control(basePointer, control)
#define SI32_DTM_A_write_control(basePointer, control) \
   (basePointer->CONTROL.U32 = control)


/// @fn _SI32_DTM_A_read_control(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Reads the CONTROL register.
///
/// @return
///  CONTROL register value.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_read_control(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_read_control(basePointer)
#define SI32_DTM_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_DTM_A_set_active_state_counter(SI32_DTM_A_Type* basePointer,
///      uint32_t count)
///
/// @brief
/// Sets the active state counter to the requested value.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  count
///  Valid range is 8 bits.
///  Requested active state count.
///
void
_SI32_DTM_A_set_active_state_counter(SI32_DTM_A_Type* /*basePointer*/,
   uint32_t /*count*/);
///
/// @def SI32_DTM_A_set_active_state_counter(basePointer, count)
#define SI32_DTM_A_set_active_state_counter(basePointer, count) do{  \
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_STCOUNT_MASK;\
   basePointer->CONTROL_SET = (count)<<SI32_DTM_A_CONTROL_STCOUNT_SHIFT;\
} while(0)


/// @fn _SI32_DTM_A_get_active_state_counter(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Reads the active state counter.
///
/// @return
///  The current active state count.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_get_active_state_counter(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_get_active_state_counter(basePointer)
#define SI32_DTM_A_get_active_state_counter(basePointer) \
(basePointer->CONTROL.STCOUNT)


/// @fn _SI32_DTM_A_set_active_state(SI32_DTM_A_Type* basePointer,
///      uint32_t state)
///
/// @brief
/// Sets the active state to the requested value.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  state
///  Valid range is 4 bits.
///  Requested active state.
///
void
_SI32_DTM_A_set_active_state(SI32_DTM_A_Type* /*basePointer*/,
   uint32_t /*state*/);
///
/// @def SI32_DTM_A_set_active_state(basePointer, state)
#define SI32_DTM_A_set_active_state(basePointer, state) do{  \
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_ST_MASK;\
   basePointer->CONTROL_SET = (state)<<SI32_DTM_A_CONTROL_ST_SHIFT;\
} while(0)


/// @fn _SI32_DTM_A_get_active_state(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Reads the active state.
///
/// @return
///  The current active state.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_get_active_state(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_get_active_state(basePointer)
#define SI32_DTM_A_get_active_state(basePointer) \
(basePointer->CONTROL.ST)


/// @fn _SI32_DTM_A_get_last_state(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Reads the last state.
///
/// @return
///  The last state.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_get_last_state(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_get_last_state(basePointer)
#define SI32_DTM_A_get_last_state(basePointer) \
(basePointer->CONTROL.LASTST)


/// @fn _SI32_DTM_A_set_inhibit_signal_selection(SI32_DTM_A_Type* basePointer,
///      uint32_t signal)
///
/// @brief
/// Sets which DTMnINH.x signal is used for inhibit control.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  signal
///  Valid range is 4 bits.
///  The requested inhibit signal.
///
void
_SI32_DTM_A_set_inhibit_signal_selection(SI32_DTM_A_Type* /*basePointer*/,
   uint32_t /*signal*/);
///
/// @def SI32_DTM_A_set_inhibit_signal_selection(basePointer, signal)
#define SI32_DTM_A_set_inhibit_signal_selection(basePointer, signal) do{  \
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_INHSSEL_MASK;\
   basePointer->CONTROL_SET = (signal)<<SI32_DTM_A_CONTROL_INHSSEL_SHIFT;\
} while(0)


/// @fn _SI32_DTM_A_get_inhibit_signal_selection(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Gets which DTMnINH.x signal is used for inhibit control.
///
/// @return
///  The selected inhibit signal.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_get_inhibit_signal_selection(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_get_inhibit_signal_selection(basePointer)
#define SI32_DTM_A_get_inhibit_signal_selection(basePointer) \
(basePointer->CONTROL.INHSSEL)


/// @fn _SI32_DTM_A_read_inhibit_signal_status(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Reads the status of the inhibit signal selected by the INHSEN field.
///
/// @return
///  Status of the inhibit signal.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_read_inhibit_signal_status(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_read_inhibit_signal_status(basePointer)
#define SI32_DTM_A_read_inhibit_signal_status(basePointer) \
(basePointer->CONTROL.INHF)


/// @fn _SI32_DTM_A_enable_stall_in_debug_mode(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Enables stalling the DTM module when the core is halted.
///
/// @param[in]
///  basePointer
///
void
_SI32_DTM_A_enable_stall_in_debug_mode(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_enable_stall_in_debug_mode(basePointer)
#define SI32_DTM_A_enable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_SET = SI32_DTM_A_CONTROL_DBGMD_MASK)


/// @fn _SI32_DTM_A_disable_stall_in_debug_mode(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Disables stalling the DTM module when the core is halted.
///
/// @param[in]
///  basePointer
///
void
_SI32_DTM_A_disable_stall_in_debug_mode(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_disable_stall_in_debug_mode(basePointer)
#define SI32_DTM_A_disable_stall_in_debug_mode(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_DBGMD_MASK)


/// @fn _SI32_DTM_A_read_destination_dma_request_status(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Reads the status of the destination DMA request signal.
///
/// @return
///  Status of the  destination DMA request signal.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_read_destination_dma_request_status(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_read_destination_dma_request_status(basePointer)
#define SI32_DTM_A_read_destination_dma_request_status(basePointer) \
(basePointer->CONTROL.DSTREQF)


/// @fn _SI32_DTM_A_read_source_dma_request_status(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Reads the status of the source DMA request signal.
///
/// @return
///  Status of the  source DMA request signal.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_read_source_dma_request_status(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_read_source_dma_request_status(basePointer)
#define SI32_DTM_A_read_source_dma_request_status(basePointer) \
(basePointer->CONTROL.SRCREQF)


/// @fn _SI32_DTM_A_enable_module_inhibit(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Pauses the DTM module. DMA requests are ignored.
///
/// @param[in]
///  basePointer
///
void
_SI32_DTM_A_enable_module_inhibit(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_enable_module_inhibit(basePointer)
#define SI32_DTM_A_enable_module_inhibit(basePointer) \
   (basePointer->CONTROL_SET = SI32_DTM_A_CONTROL_DTMINH_MASK)


/// @fn _SI32_DTM_A_disable_module_inhibit(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Resumes the DTM module. DMA requests are honored.
///
/// @param[in]
///  basePointer
///
void
_SI32_DTM_A_disable_module_inhibit(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_disable_module_inhibit(basePointer)
#define SI32_DTM_A_disable_module_inhibit(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_DTMINH_MASK)


/// @fn _SI32_DTM_A_clear_timeout_error_interrupt(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Clears timeout error interrupt flag.
///
/// @param[in]
///  basePointer
///
void
_SI32_DTM_A_clear_timeout_error_interrupt(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_clear_timeout_error_interrupt(basePointer)
#define SI32_DTM_A_clear_timeout_error_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_TOERRI_MASK)


/// @fn _SI32_DTM_A_is_timeout_error_interrupt_pending(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Checks if timeout error interrupt flag is set.
///
/// @return
///  True if interrupt is pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_DTM_A_is_timeout_error_interrupt_pending(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_is_timeout_error_interrupt_pending(basePointer)
#define SI32_DTM_A_is_timeout_error_interrupt_pending(basePointer) \
((bool)basePointer->CONTROL.TOERRI)


/// @fn _SI32_DTM_A_clear_dma_error_interrupt(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Clears DMA error interrupt flag.
///
/// @param[in]
///  basePointer
///
void
_SI32_DTM_A_clear_dma_error_interrupt(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_clear_dma_error_interrupt(basePointer)
#define SI32_DTM_A_clear_dma_error_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_DMAERRI_MASK)


/// @fn _SI32_DTM_A_is_dma_error_interrupt_pending(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Checks if DMA error interrupt flag is set.
///
/// @return
///  True if interrupt is pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_DTM_A_is_dma_error_interrupt_pending(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_is_dma_error_interrupt_pending(basePointer)
#define SI32_DTM_A_is_dma_error_interrupt_pending(basePointer) \
((bool)basePointer->CONTROL.DMAERRI)


/// @fn _SI32_DTM_A_clear_module_interrupt(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Clears DTM module interrupt flag.
///
/// @param[in]
///  basePointer
///
void
_SI32_DTM_A_clear_module_interrupt(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_clear_module_interrupt(basePointer)
#define SI32_DTM_A_clear_module_interrupt(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_DTMI_MASK)


/// @fn _SI32_DTM_A_is_module_interrupt_pending(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Checks if DTM module interrupt flag is set.
///
/// @return
///  True if interrupt is pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_DTM_A_is_module_interrupt_pending(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_is_module_interrupt_pending(basePointer)
#define SI32_DTM_A_is_module_interrupt_pending(basePointer) \
((bool)basePointer->CONTROL.DTMI)


/// @fn _SI32_DTM_A_clear_all_interrupts(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Clear all DTM interrupt flags.
///
/// @param[in]
///  basePointer
///
void
_SI32_DTM_A_clear_all_interrupts(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_clear_all_interrupts(basePointer)
#define SI32_DTM_A_clear_all_interrupts(basePointer) do{  \
   basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_TOERRI_MASK\
                            | SI32_DTM_A_CONTROL_DMAERRI_MASK\
                            | SI32_DTM_A_CONTROL_DTMI_MASK;\
} while(0)


/// @fn _SI32_DTM_A_is_any_interrupt_pending(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Checks if any DTM interrupt flag is set.
///
/// @return
///  True if any interrupt is pending.
///
/// @param[in]
///  basePointer
///
bool
_SI32_DTM_A_is_any_interrupt_pending(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_is_any_interrupt_pending(basePointer)
#define SI32_DTM_A_is_any_interrupt_pending(basePointer) \
   _SI32_DTM_A_is_any_interrupt_pending(basePointer)


/// @fn _SI32_DTM_A_enable_module(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Enables the DTM module.
///
/// @param[in]
///  basePointer
///
void
_SI32_DTM_A_enable_module(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_enable_module(basePointer)
#define SI32_DTM_A_enable_module(basePointer) \
   (basePointer->CONTROL_SET = SI32_DTM_A_CONTROL_DTMEN_MASK)


/// @fn _SI32_DTM_A_disable_module(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Disables the DTM module.
///
/// @param[in]
///  basePointer
///
void
_SI32_DTM_A_disable_module(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_disable_module(basePointer)
#define SI32_DTM_A_disable_module(basePointer) \
   (basePointer->CONTROL_CLR = SI32_DTM_A_CONTROL_DTMEN_MASK)


/// @fn _SI32_DTM_A_write_timeout(SI32_DTM_A_Type* basePointer,
///      uint32_t timeout)
///
/// @brief
/// Writes the TIMEOUT register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  timeout
///  Valid range is 32 bits.
///  TIMEOUT register value.
///
void
_SI32_DTM_A_write_timeout(SI32_DTM_A_Type* /*basePointer*/,
   uint32_t /*timeout*/);
///
/// @def SI32_DTM_A_write_timeout(basePointer, timeout)
#define SI32_DTM_A_write_timeout(basePointer, timeout) \
   (basePointer->TIMEOUT.U32 = timeout)


/// @fn _SI32_DTM_A_read_timeout(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Reads the TIMEOUT register.
///
/// @return
///  TIMEOUT register value.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_read_timeout(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_read_timeout(basePointer)
#define SI32_DTM_A_read_timeout(basePointer) \
(basePointer->TIMEOUT.U32)


/// @fn _SI32_DTM_A_set_timeout_counter_reload(SI32_DTM_A_Type* basePointer,
///      uint32_t toreload)
///
/// @brief
/// Sets the timeout counter reload value.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  toreload
///  Valid range is 16 bits.
///  Timeout counter reload value.
///
void
_SI32_DTM_A_set_timeout_counter_reload(SI32_DTM_A_Type* /*basePointer*/,
   uint32_t /*toreload*/);
///
/// @def SI32_DTM_A_set_timeout_counter_reload(basePointer, toreload)
#define SI32_DTM_A_set_timeout_counter_reload(basePointer, toreload) \
   (basePointer->TIMEOUT.TORELOAD = toreload)


/// @fn _SI32_DTM_A_get_timeout_counter_reload(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Reads the timeout counter reload value.
///
/// @return
///  Timeout counter reload value.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_get_timeout_counter_reload(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_get_timeout_counter_reload(basePointer)
#define SI32_DTM_A_get_timeout_counter_reload(basePointer) \
(basePointer->TIMEOUT.TORELOAD)


/// @fn _SI32_DTM_A_get_timeout_count(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Returns current value of the timeout counter.
///
/// @return
///  Current timeout count.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_get_timeout_count(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_get_timeout_count(basePointer)
#define SI32_DTM_A_get_timeout_count(basePointer) \
(basePointer->TIMEOUT.TOCOUNT)


/// @fn _SI32_DTM_A_set_master_count(SI32_DTM_A_Type* basePointer,
///      uint32_t count)
///
/// @brief
/// Sets the master counter value.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  count
///  Valid range is 16 bits.
///  The requested master counter value.
///
void
_SI32_DTM_A_set_master_count(SI32_DTM_A_Type* /*basePointer*/,
   uint32_t /*count*/);
///
/// @def SI32_DTM_A_set_master_count(basePointer, count)
#define SI32_DTM_A_set_master_count(basePointer, count) \
   (basePointer->MSTCOUNT.MSTCOUNT_BITS = count)


/// @fn _SI32_DTM_A_get_master_count(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Gets the master counter value.
///
/// @return
///  The current master counter value.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_get_master_count(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_get_master_count(basePointer)
#define SI32_DTM_A_get_master_count(basePointer) \
(basePointer->MSTCOUNT.MSTCOUNT_BITS)


/// @fn _SI32_DTM_A_write_state_address(SI32_DTM_A_Type* basePointer,
///      uint32_t stateaddr)
///
/// @brief
/// Writes the STATEADDR register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  stateaddr
///  Valid range is 32 bits.
///  STATEADDR register value.
///
void
_SI32_DTM_A_write_state_address(SI32_DTM_A_Type* /*basePointer*/,
   uint32_t /*stateaddr*/);
///
/// @def SI32_DTM_A_write_state_address(basePointer, stateaddr)
#define SI32_DTM_A_write_state_address(basePointer, stateaddr) \
   (basePointer->STATEADDR.U32 = (stateaddr) & SI32_DTM_A_STATEADDR_STATEADDR_MASK)


/// @fn _SI32_DTM_A_read_state_address(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Reads the STATEADDR register.
///
/// @return
///  STATEADDR register value.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_read_state_address(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_read_state_address(basePointer)
#define SI32_DTM_A_read_state_address(basePointer) \
(basePointer->STATEADDR.U32)


/// @fn _SI32_DTM_A_read_state(SI32_DTM_A_Type* basePointer)
///
/// @brief
/// Reads the STATE register.
///
/// @return
///  STATE register value.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_DTM_A_read_state(SI32_DTM_A_Type* /*basePointer*/);
///
/// @def SI32_DTM_A_read_state(basePointer)
#define SI32_DTM_A_read_state(basePointer) \
(basePointer->STATE.U32)



#ifdef __cplusplus
}
#endif

#endif // __SI32_DTM_A_TYPE_H__

//-eof--------------------------------------------------------------------------
