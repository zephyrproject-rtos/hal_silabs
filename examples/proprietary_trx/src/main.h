/***************************************************************************//**
 * @file main.h
 * @brief Main header file for the proprietary TRX example.
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

#ifndef MAIN_H
#define MAIN_H

// -----------------------------------------------------------------------------
// Includes

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/util.h>
#include <zephyr/sys/printk.h>
#include <inttypes.h>
#include <zephyr/shell/shell.h>
#include <zephyr/logging/log.h>
#include <zephyr/smf.h>

// -----------------------------------------------------------------------------
// Macros and Typedefs

// List of events
#define EVENT_REQUEST_SEND        BIT(0)
#define EVENT_CLI_RECEIVE_SETTING BIT(1)
#define EVENT_RADIO_RECEIVED      BIT(2)
#define EVENT_RADIO_SENT          BIT(3)
#define EVENT_RADIO_ERROR         BIT(4)

// A structure to contain all state machine, event, radio and gpio variables
struct s_prop_var {
	struct smf_ctx ctx;
	struct gpio_callback button_cb_data;
	struct k_event smf_event;
	bool allow_rx;
	bool packet_sent;
	uint64_t error_code;
	struct gpio_dt_spec led0;
	struct gpio_dt_spec led1;
	struct gpio_dt_spec button0;
	struct gpio_dt_spec button1;
};

// -----------------------------------------------------------------------------
// Global Variables

extern struct s_prop_var s_sl_machine;

#endif
