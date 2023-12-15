/***************************************************************************//**
 * @file app_rail.h
 * @brief RAIL configuration and handling functions.
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

#ifndef APP_RAIL_H
#define APP_RAIL_H

// -----------------------------------------------------------------------------
// Public Function Declarations

/**
 * @brief Handle the process of sending a packet.
 *
 * Handles the process of sending a packet, preparing the package,
 * and initiating the transmission.
 *
 * @param packet_sent pointer to sending flag
 */
void handle_send(bool *packet_sent);

/**
 * @brief Handle the event of a successfully sent packet.
 *
 * Handles the event when a packet has been successfully sent.
 *
 * @param packet_sent pointer to sending flag
 */
void handle_sent(bool *packet_sent);

/**
 * @brief Handle a radio error event.
 *
 * Handles events where a radio error has occurred.
 *
 * @param error_code pointer to the error events happened with RAIL
 */
void handle_error(uint64_t *error_code);

/**
 * @brief Set continuous receive mode.
 *
 * Sets the radio to continuous receive mode or disables it based on the provided parameter.
 *
 * @param enable_continuous_rx Boolean indicating whether to enable continuous receive mode.
 */
void set_continuous_rx(bool enable_continuous_rx);

/**
 * @brief Handle the process of receiving packets.
 *
 * Handles the process of receiving packets, including unpacking and logging.
 */
void handle_receive(void);

/**
 * @brief Initialize the RAIL communication.
 *
 * Initializes RAIL communication, installs ISRs, and sets up the TX FIFO.
 */
void app_rail_init(void);

#endif /*APP_RAIL_H*/
