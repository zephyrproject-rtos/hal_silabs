/***************************************************************************//**
 * @file app_gpio.h
 * @brief GPIO handling for the proprietary_trx example.
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef APP_GPIO_H
#define APP_GPIO_H

#include "main.h"

// -----------------------------------------------------------------------------
// Public Function Declarations

/**
 * @brief Initialize GPIOs for the application.
 *
 * Initializes the GPIOs used by the application.
 * One or two buttons, one is mandatory because of sending.
 * One or two leds, for showing the send, receive packets.
 *
 * @param s_state pointer to the state machine for the led variables
 *
 * @return uint8_t The initialization status. 0 indicates success, and non-zero
 * values indicate an error.
 */
int app_init_gpios(struct s_prop_var *s_state);

/**
 * @brief Update the receive LED status.
 *
 * @param s_state pointer to the state machine for the led variables
 *
 * Updates the status of the receive LED based on the application requirements.
 */
void app_update_receive_led(struct s_prop_var *s_state);

/**
 * @brief Update the send LED status.
 *
 * @param s_state pointer to the state machine for the led variables
 *
 * Updates the status of the send LED based on the application requirements.
 */
void app_update_send_led(struct s_prop_var *s_state);

#endif /*APP_GPIO_H*/
