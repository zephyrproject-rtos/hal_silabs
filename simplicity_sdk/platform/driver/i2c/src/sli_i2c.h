/***************************************************************************//**
 * @file
 * @brief I2C Driver Private API definition.
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
 ******************************************************************************/

#ifndef SLI_I2C_H
#define SLI_I2C_H

#include "sl_i2c.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/

/***************************************************************************//**
 * Configure the I2C instance with initialization parameters.
 *
 * @details
 *   This function resets the I2C peripheral, configures interrupts, sets the
 *   operating mode (leader/follower), and sets the clock frequency for leader mode.
 *   It is called internally during driver initialization.
 *
 * @param[in] i2c_handle Pointer to the I2C instance handle.
 *
 * @return
 *   - SL_STATUS_OK on success.
 *   - SL_STATUS_NULL_POINTER if init_params is NULL.
 *   - SL_STATUS_NOT_SUPPORTED if the peripheral is invalid.
 *   - SL_STATUS_FAIL if clock frequency retrieval fails.
 ******************************************************************************/
sl_status_t sli_i2c_init_core(sl_i2c_handle_t *i2c_handle);

/***************************************************************************//**
 * Dispatch interrupt handler for the I2C Leader
 *
 * @details  Handles all I2C interrupts for leader mode, including ACK/NACK, STOP,
 *           arbitration lost, and bus errors. Updates the driver state and event fields.
 *           Called from the IRQ handler or internal state machine.
 *
 * @param[in] i2c_handle Pointer to the I2C instance handle.
 ******************************************************************************/
void sli_i2c_leader_dispatch_interrupt(sl_i2c_handle_t *i2c_handle);

/***************************************************************************//**
 * Dispatch interrupt handler for the I2C Follower
 *
 * @details  Handles all I2C interrupts for follower mode, including address match,
 *           RX data, STOP, and error conditions. Updates the driver state and event fields.
 *           Called from the IRQ handler or internal state machine.
 *
 * @param[in] i2c_handle Pointer to the I2C instance handle.
 ******************************************************************************/
void sli_i2c_follower_dispatch_interrupt(sl_i2c_handle_t *i2c_handle);

#ifdef __cplusplus
}
#endif

#endif // SLI_I2C_H
