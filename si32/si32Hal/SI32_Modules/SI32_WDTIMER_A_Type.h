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
/// @file SI32_WDTIMER_A_Type.h
//
// Script: 0.58
// HAL Source: 0.5
// Version: 1

#ifndef __SI32_WDTIMER_A_TYPE_H__
#define __SI32_WDTIMER_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_WDTIMER_A_Registers.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_WDTIMER_A_initialize(SI32_WDTIMER_A_Type* basePointer,
///      uint32_t control,
///      uint32_t threshold)
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
///  threshold
///  Valid range is 32 bits.
///  Write to THRESHOLD register.
///
void
_SI32_WDTIMER_A_initialize(SI32_WDTIMER_A_Type* /*basePointer*/,
   uint32_t, /*control*/
   uint32_t /*threshold*/);
///
/// @def SI32_WDTIMER_A_initialize(basePointer, control, threshold)
#define SI32_WDTIMER_A_initialize(basePointer, control, threshold) do{  \
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;\
   basePointer->CONTROL.U32 = control;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;\
   basePointer->THRESHOLD.U32 = threshold;\
} while(0)


/// @fn _SI32_WDTIMER_A_write_control(SI32_WDTIMER_A_Type* basePointer,
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
///  Valid range is 32 bits.
///
void
_SI32_WDTIMER_A_write_control(SI32_WDTIMER_A_Type* /*basePointer*/,
   uint32_t /*control*/);
///
/// @def SI32_WDTIMER_A_write_control(basePointer, control)
#define SI32_WDTIMER_A_write_control(basePointer, control) do{  \
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;\
   basePointer->CONTROL.U32 = control;\
} while(0)


/// @fn _SI32_WDTIMER_A_read_control(SI32_WDTIMER_A_Type* basePointer)
///
/// @brief
/// Read from CONTROL register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_WDTIMER_A_read_control(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_read_control(basePointer)
#define SI32_WDTIMER_A_read_control(basePointer) \
(basePointer->CONTROL.U32)


/// @fn _SI32_WDTIMER_A_enable_early_warning_interrupt(SI32_WDTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_WDTIMER_A_enable_early_warning_interrupt(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_enable_early_warning_interrupt(basePointer)
#define SI32_WDTIMER_A_enable_early_warning_interrupt(basePointer) do{  \
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;\
   basePointer->CONTROL_SET = SI32_WDTIMER_A_CONTROL_EWIEN_ENABLED_U32;\
} while(0)


/// @fn _SI32_WDTIMER_A_disable_early_warning_interrupt(SI32_WDTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_WDTIMER_A_disable_early_warning_interrupt(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_disable_early_warning_interrupt(basePointer)
#define SI32_WDTIMER_A_disable_early_warning_interrupt(basePointer) do{  \
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;\
   basePointer->CONTROL_CLR = SI32_WDTIMER_A_CONTROL_EWIEN_MASK;\
} while(0)


/// @fn _SI32_WDTIMER_A_is_early_warning_interrupt_enabled(SI32_WDTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
bool
_SI32_WDTIMER_A_is_early_warning_interrupt_enabled(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_is_early_warning_interrupt_enabled(basePointer)
#define SI32_WDTIMER_A_is_early_warning_interrupt_enabled(basePointer) \
((bool)(basePointer->CONTROL.EWIEN))


/// @fn _SI32_WDTIMER_A_enable_stall_in_debug_mode(SI32_WDTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_WDTIMER_A_enable_stall_in_debug_mode(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_enable_stall_in_debug_mode(basePointer)
#define SI32_WDTIMER_A_enable_stall_in_debug_mode(basePointer) do{  \
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;\
   basePointer->CONTROL_SET = SI32_WDTIMER_A_CONTROL_DBGMD_MASK;\
} while(0)


/// @fn _SI32_WDTIMER_A_disable_stall_in_debug_mode(SI32_WDTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_WDTIMER_A_disable_stall_in_debug_mode(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_disable_stall_in_debug_mode(basePointer)
#define SI32_WDTIMER_A_disable_stall_in_debug_mode(basePointer) do{  \
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;\
   basePointer->CONTROL_CLR = SI32_WDTIMER_A_CONTROL_DBGMD_MASK;\
} while(0)


/// @fn _SI32_WDTIMER_A_received_attention_key(SI32_WDTIMER_A_Type* basePointer)
///
/// @return
///  True = attention key has been recevied, False = no keys have been
///  processed.
///
/// @param[in]
///  basePointer
///
bool
_SI32_WDTIMER_A_received_attention_key(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_received_attention_key(basePointer)
#define SI32_WDTIMER_A_received_attention_key(basePointer) \
((bool)(basePointer->STATUS.KEYSTS))


/// @fn _SI32_WDTIMER_A_is_module_writable(SI32_WDTIMER_A_Type* basePointer)
///
/// @return
///  True = a write transaction can be performed on WDT registers, False =
///  the WDT registers are read-only.
///
/// @param[in]
///  basePointer
///
bool
_SI32_WDTIMER_A_is_module_writable(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_is_module_writable(basePointer)
#define SI32_WDTIMER_A_is_module_writable(basePointer) \
((bool)(basePointer->STATUS.PRIVSTS))


/// @fn _SI32_WDTIMER_A_is_early_warning_interrupt_pending(SI32_WDTIMER_A_Type* basePointer)
///
/// @return
///  True = EWTH match occurred and interrupt is pending, False = EWTH
///  match did not occur.
///
/// @param[in]
///  basePointer
///
bool
_SI32_WDTIMER_A_is_early_warning_interrupt_pending(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_is_early_warning_interrupt_pending(basePointer)
#define SI32_WDTIMER_A_is_early_warning_interrupt_pending(basePointer) \
((bool)(basePointer->STATUS.EWI))


/// @fn _SI32_WDTIMER_A_clear_early_warning_interrupt(SI32_WDTIMER_A_Type* basePointer)
///
/// @param[in]
///  basePointer
///
void
_SI32_WDTIMER_A_clear_early_warning_interrupt(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_clear_early_warning_interrupt(basePointer)
#define SI32_WDTIMER_A_clear_early_warning_interrupt(basePointer) do{  \
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;\
   basePointer->STATUS_CLR = SI32_WDTIMER_A_STATUS_EWI_MASK;\
} while(0)


/// @fn _SI32_WDTIMER_A_is_counter_less_than_reset_threshold(SI32_WDTIMER_A_Type* basePointer)
///
/// @return
///  True = WDT counter is currently less than RTH value, False = WDT
///  counter is currently greater than or equal to the RTH value.
///
/// @param[in]
///  basePointer
///
bool
_SI32_WDTIMER_A_is_counter_less_than_reset_threshold(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_is_counter_less_than_reset_threshold(basePointer)
#define SI32_WDTIMER_A_is_counter_less_than_reset_threshold(basePointer) \
((bool)(basePointer->STATUS.RTHF))


/// @fn _SI32_WDTIMER_A_is_threshold_update_pending(SI32_WDTIMER_A_Type* basePointer)
///
/// @return
///  True = An update of the THRESHOLD register is occurring, False = An
///  update of the THRESHOLD register is pending or completed. The
///  THRESHOLD register can be written.
///
/// @param[in]
///  basePointer
///
bool
_SI32_WDTIMER_A_is_threshold_update_pending(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_is_threshold_update_pending(basePointer)
#define SI32_WDTIMER_A_is_threshold_update_pending(basePointer) \
((bool)(basePointer->STATUS.UPDSTS))


/// @fn _SI32_WDTIMER_A_write_threshold(SI32_WDTIMER_A_Type* basePointer,
///      uint32_t threshold)
///
/// @brief
/// Write to THRESHOLD register.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  threshold
///  Valid range is 32 bits.
///
void
_SI32_WDTIMER_A_write_threshold(SI32_WDTIMER_A_Type* /*basePointer*/,
   uint32_t /*threshold*/);
///
/// @def SI32_WDTIMER_A_write_threshold(basePointer, threshold)
#define SI32_WDTIMER_A_write_threshold(basePointer, threshold) do{  \
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;\
   basePointer->THRESHOLD.U32 = threshold;\
} while(0)


/// @fn _SI32_WDTIMER_A_read_threshold(SI32_WDTIMER_A_Type* basePointer)
///
/// @brief
/// Reads from THRESHOLD register.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_WDTIMER_A_read_threshold(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_read_threshold(basePointer)
#define SI32_WDTIMER_A_read_threshold(basePointer) \
(basePointer->THRESHOLD.U32)


/// @fn _SI32_WDTIMER_A_set_early_warning_threshold(SI32_WDTIMER_A_Type* basePointer,
///      uint32_t count)
///
/// @brief
/// Write value to the  EWTH register. When the WDT counter matches EWTH,
/// a WDT interrupt will occur if WDT early warning interrupts are
/// enabled.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  count
///  Valid range is 16 bits.
///
void
_SI32_WDTIMER_A_set_early_warning_threshold(SI32_WDTIMER_A_Type* /*basePointer*/,
   uint32_t /*count*/);
///
/// @def SI32_WDTIMER_A_set_early_warning_threshold(basePointer, count)
#define SI32_WDTIMER_A_set_early_warning_threshold(basePointer, count) do{  \
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;\
   basePointer->THRESHOLD.U32 &= ~SI32_WDTIMER_A_THRESHOLD_EWTH_MASK;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;\
   basePointer->THRESHOLD.U32 |= count;\
} while(0)


/// @fn _SI32_WDTIMER_A_get_early_warning_threshold(SI32_WDTIMER_A_Type* basePointer)
///
/// @return
///  Value of EWTH counter. When the WDT counter matches EWTH, a WDT
///  interrupt will occur if WDT early warning interrupts are enabled.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_WDTIMER_A_get_early_warning_threshold(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_get_early_warning_threshold(basePointer)
#define SI32_WDTIMER_A_get_early_warning_threshold(basePointer) \
(basePointer->THRESHOLD.EWTH)


/// @fn _SI32_WDTIMER_A_set_reset_threshold(SI32_WDTIMER_A_Type* basePointer,
///      uint32_t count)
///
/// @brief
/// Write value to the RTH register. When the WDT counter matches RTH, a
/// system reset will occur if it is enabled as a reset source.
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  count
///  Valid range is 16 bits.
///
void
_SI32_WDTIMER_A_set_reset_threshold(SI32_WDTIMER_A_Type* /*basePointer*/,
   uint32_t /*count*/);
///
/// @def SI32_WDTIMER_A_set_reset_threshold(basePointer, count)
#define SI32_WDTIMER_A_set_reset_threshold(basePointer, count) do{  \
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;\
   basePointer->THRESHOLD.U32 &= ~SI32_WDTIMER_A_THRESHOLD_RTH_MASK;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_WRITE_U32;\
   basePointer->THRESHOLD.U32 |= count << SI32_WDTIMER_A_THRESHOLD_RTH_SHIFT;\
} while(0)


/// @fn _SI32_WDTIMER_A_get_reset_threshold(SI32_WDTIMER_A_Type* basePointer)
///
/// @return
///  Value of RTH counter. When the WDT counter matches RTH, a system reset
///  will occur if it is enabled as a reset source.
///
/// @param[in]
///  basePointer
///
uint32_t
_SI32_WDTIMER_A_get_reset_threshold(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_get_reset_threshold(basePointer)
#define SI32_WDTIMER_A_get_reset_threshold(basePointer) \
(basePointer->THRESHOLD.RTH)


/// @fn _SI32_WDTIMER_A_reset_counter(SI32_WDTIMER_A_Type* basePointer)
///
/// @brief
/// Writes attention key and reset key.
///
/// @param[in]
///  basePointer
///
void
_SI32_WDTIMER_A_reset_counter(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_reset_counter(basePointer)
#define SI32_WDTIMER_A_reset_counter(basePointer) do{  \
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_RESET_U32;\
} while(0)


/// @fn _SI32_WDTIMER_A_stop_counter(SI32_WDTIMER_A_Type* basePointer)
///
/// @brief
/// Writes attention key and disable key.
///
/// @param[in]
///  basePointer
///
void
_SI32_WDTIMER_A_stop_counter(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_stop_counter(basePointer)
#define SI32_WDTIMER_A_stop_counter(basePointer) do{  \
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_DISABLE_U32;\
} while(0)


/// @fn _SI32_WDTIMER_A_start_counter(SI32_WDTIMER_A_Type* basePointer)
///
/// @brief
/// Writes attention key and start key.
///
/// @param[in]
///  basePointer
///
void
_SI32_WDTIMER_A_start_counter(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_start_counter(basePointer)
#define SI32_WDTIMER_A_start_counter(basePointer) do{  \
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_START_U32;\
} while(0)


/// @fn _SI32_WDTIMER_A_lock_until_reset(SI32_WDTIMER_A_Type* basePointer)
///
/// @brief
/// Writes attention key and reset key.
///
/// @param[in]
///  basePointer
///
void
_SI32_WDTIMER_A_lock_until_reset(SI32_WDTIMER_A_Type* /*basePointer*/);
///
/// @def SI32_WDTIMER_A_lock_until_reset(basePointer)
#define SI32_WDTIMER_A_lock_until_reset(basePointer) do{  \
	basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_ATTN_U32;\
   basePointer->WDTKEY.U32 = SI32_WDTIMER_A_WDTKEY_KEY_LOCK_U32;\
} while(0)



#ifdef __cplusplus
}
#endif

#endif // __SI32_WDTIMER_A_TYPE_H__

//-eof--------------------------------------------------------------------------
