/**
 * @file sli_cpc_timer.h
 * @brief CPC Timer API
 *******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

#ifndef SLI_CPC_TIMER_H
#define SLI_CPC_TIMER_H

#include <stdbool.h>
#include <stdint.h>

#include "sl_status.h"

/**
 * Ports provide a "sli_cpc_timer_types.h" that completes `sli_cpc_timer_t`, and
 * implement the `sli_cpc_timer_*` functions declared below in a port `.c`.
 *
 * Incomplete handle and callback types live in `sli_cpc_types.h` so
 * that include (and this port include) can stay with the other directives.
 */
#include "sli_cpc_timer_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************/ /**
 * Callback invoked when a one-shot CPC timer expires.
 *
 * @param timer The same `sli_cpc_timer_t` object pointer that was
 *        passed to `sli_cpc_timer_start()`, `sli_cpc_timer_start_timer_ms()`,
 *        or `sli_cpc_timer_restart()`. Ports must not substitute a backend
 *        timer object for this pointer.
 * @param data The `callback_data` pointer passed when the timer was started
 *        or restarted.
 ******************************************************************************/
typedef void (*sli_cpc_timer_callback_t)(sli_cpc_timer_t *timer, void *data);

/***************************************************************************/ /**
 * Initialize a CPC timer handle.
 *
 * Must be called before the handle is first used with start/restart/stop.
 * Zeroes the handle storage. That is sufficient preparation for ports whose
 * backend needs no further per-handle open; it is not a substitute for
 * backend lifecycle that happens later (for example NXP Timer Manager
 * `TM_Open` performed inside start). System-wide backend setup, when
 * required, is a separate port responsibility.
 *
 * @param timer Timer handle.
 *
 * @return SL_STATUS_OK if successful.
 ******************************************************************************/
sl_status_t sli_cpc_timer_init(sli_cpc_timer_t *timer);

/***************************************************************************/ /**
 * Get the CPC timer frequency.
 *
 * @return Timer frequency in hertz.
 ******************************************************************************/
uint32_t sli_cpc_timer_get_timer_frequency(void);

/***************************************************************************/ /**
 * Converts milliseconds into ticks.
 *
 * @param time_ms Number of milliseconds.
 *
 * @return Corresponding ticks number.
 *
 * @note The result is "rounded" to the superior tick number.
 *       This function is light and cannot fail so it should be privileged to
 *       perform a millisecond to tick conversion.
 ******************************************************************************/
uint32_t sli_cpc_timer_ms_to_tick(uint16_t time_ms);

/***************************************************************************/ /**
 * Converts ticks in milliseconds.
 *
 * @param tick Number of tick.
 *
 * @return Corresponding milliseconds number.
 *
 * @note The result is rounded to the inferior millisecond.
 ******************************************************************************/
uint32_t sli_cpc_timer_tick_to_ms(uint32_t tick);

/***************************************************************************/ /**
 * Gets current 32 bits global tick count.
 *
 * @return Current tick count.
 ******************************************************************************/
uint32_t sli_cpc_timer_get_tick_count(void);

/***************************************************************************/ /**
 * Gets current 64 bits global tick count.
 *
 * @return Current tick count.
 ******************************************************************************/
uint64_t sli_cpc_timer_get_tick_count64(void);

/***************************************************************************/ /**
 * Starts a 32 bits timer.
 *
 * @param timer Timer handle. The same pointer is passed to
 *        @p callback when the timer expires.
 * @param timeout Timer timeout, in timer ticks.
 * @param callback Callback function that will be called when
 *        timeout expires.
 * @param callback_data Pointer to user data that will be passed to callback.
 *
 * @return SL_STATUS_OK if successful.
 ******************************************************************************/
sl_status_t sli_cpc_timer_start(sli_cpc_timer_t *timer, uint32_t timeout, sli_cpc_timer_callback_t callback,
                                void *callback_data);

/**************************************************************************/ /**
 * Starts a 32 bits timer.
 *
 * @param timer Timer handle. The same pointer is passed to
 *        @p callback when the timer expires.
 * @param timeout_ms Timer timeout, in milliseconds.
 * @param callback Callback function that will be called when
 *        timeout expires.
 * @param callback_data Pointer to user data that will be passed to callback.
 *
 * @return SL_STATUS_OK if successful.
 *****************************************************************************/
sl_status_t sli_cpc_timer_start_timer_ms(sli_cpc_timer_t *timer, uint32_t timeout_ms, sli_cpc_timer_callback_t callback,
                                         void *callback_data);

/***************************************************************************/ /**
 * Restarts a 32 bits timer.
 *
 * @param timer Timer handle. The same pointer is passed to
 *        @p callback when the timer expires.
 * @param timeout Timer timeout, in timer ticks.
 * @param callback Callback function that will be called when
 *        initial/periodic timeout expires.
 * @param callback_data Pointer to user data that will be passed to callback.
 *
 * @return SL_STATUS_OK if successful.
 ******************************************************************************/
sl_status_t sli_cpc_timer_restart(sli_cpc_timer_t *timer, uint32_t timeout, sli_cpc_timer_callback_t callback,
                                  void *callback_data);

/***************************************************************************/ /**
 * Stops a timer.
 *
 * @param timer Timer handle.
 *
 * @return SL_STATUS_OK if successful.
 ******************************************************************************/
sl_status_t sli_cpc_timer_stop(sli_cpc_timer_t *timer);

/***************************************************************************/ /**
 * Checks whether a timer is running.
 *
 * @param timer Timer handle.
 *
 * @return true if the timer handle is valid and running, false otherwise.
 ******************************************************************************/
bool sli_cpc_timer_is_running(const sli_cpc_timer_t *timer);

/***************************************************************************/ /**
 * Delays for the specified number of milliseconds.
 *
 * @param delay_ms Delay in milliseconds.
 ******************************************************************************/
void sli_cpc_timer_delay_millisecond(uint16_t delay_ms);

#ifdef __cplusplus
}
#endif

#endif // SLI_CPC_TIMER_H
