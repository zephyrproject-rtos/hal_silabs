/***************************************************************************//**
 * @file main.c
 * @brief Main file for the proprietary_trx example.
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
#include "rail.h"
#include "rail_types.h"
#include "pa_conversions_efr32.h"
#include "sl_rail_util_init.h"
#include "app_gpio.h"
#include "app_rail.h"
#include "main.h"

// -----------------------------------------------------------------------------
// Macros and Typedefs
LOG_MODULE_REGISTER(trx_app_log, LOG_LEVEL_INF);

/* List of application states */
enum radio_state {
	INIT,
	IDLE,
	SEND,
	SENT,
	RECEIVE,
	ERROR
};

// -----------------------------------------------------------------------------
// Static Function Declarations

static void init_run(void *o);
static void idle_run(void *o);
static void send_run(void *o);
static void sent_run(void *o);
static void received_run(void *o);
static void error_run(void *o);

// -----------------------------------------------------------------------------
// Global Variables

//
struct s_prop_var s_sl_machine = {.led1 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led1), gpios, {0}),
				  .led0 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led0), gpios, {0}),
				  .button1 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(sw1), gpios, {0}),
				  .button0 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(sw0), gpios, {0})};

// -----------------------------------------------------------------------------
// Static Variables

static const struct smf_state radio_states[] = {
	[INIT] = SMF_CREATE_STATE(NULL, init_run, NULL),
	[IDLE] = SMF_CREATE_STATE(NULL, idle_run, NULL),
	[SEND] = SMF_CREATE_STATE(NULL, send_run, NULL),
	[SENT] = SMF_CREATE_STATE(NULL, sent_run, NULL),
	[RECEIVE] = SMF_CREATE_STATE(NULL, received_run, NULL),
	[ERROR] = SMF_CREATE_STATE(NULL, error_run, NULL),

};

// -----------------------------------------------------------------------------
// Public Function Definitions

int main(void)
{
	uint8_t ret = 0;
	uint32_t incoming_events = 0;
	/* Initialize the event */
	k_event_init(&s_sl_machine.smf_event);
	smf_set_initial(&s_sl_machine.ctx, &radio_states[INIT]);

	while (1) {
		ret = smf_run_state(&s_sl_machine.ctx);
		if (ret) {
			return -1;
		}

		/* Block until an event is detected */
		incoming_events =
			k_event_wait(&s_sl_machine.smf_event,
				     (EVENT_REQUEST_SEND | EVENT_RADIO_SENT | EVENT_RADIO_RECEIVED |
				      EVENT_CLI_RECEIVE_SETTING | EVENT_RADIO_ERROR),
				     false, K_FOREVER);

		if (incoming_events & EVENT_REQUEST_SEND) {
			smf_set_state(&s_sl_machine.ctx, &radio_states[SEND]);
		}
		if (incoming_events & EVENT_RADIO_SENT) {
			smf_set_state(&s_sl_machine.ctx, &radio_states[SENT]);
		}
		if (incoming_events & EVENT_RADIO_RECEIVED) {
			smf_set_state(&s_sl_machine.ctx, &radio_states[RECEIVE]);
		}
		if (incoming_events & EVENT_RADIO_ERROR) {
			smf_set_state(&s_sl_machine.ctx, &radio_states[ERROR]);
		}
	}
	return 0;
}

// -----------------------------------------------------------------------------
// Static Function Definitions

static void init_run(void *o)
{
	RAIL_Version_t rail_version;
	struct s_prop_var *s = o;
	LOG_INF("INIT STATE");
	if (app_init_gpios(s)) {
		LOG_ERR("LED and Button init failed!");
	}
	app_rail_init();
	RAIL_GetVersion(&rail_version, 1);
	printk("RAIL LIB version: %d.%d.%d\n", rail_version.major, rail_version.minor,
	       rail_version.rev);
	printk("            HASH: %u\n", rail_version.hash);
	printk("Press the button\n");
	s->packet_sent = true;
	smf_set_state(&s->ctx, &radio_states[IDLE]);
}

static void idle_run(void *o)
{
	struct s_prop_var *s = o;
	LOG_INF("IDLE STATE");
	if (k_event_test(&(s->smf_event), EVENT_CLI_RECEIVE_SETTING)) {
		set_continuous_rx(s->allow_rx);
		k_event_clear(&(s->smf_event), EVENT_CLI_RECEIVE_SETTING);
	}
}

static void send_run(void *o)
{
	struct s_prop_var *s = o;
	LOG_INF("SEND STATE");
	handle_send(&(s->packet_sent));
	smf_set_state(&s->ctx, &radio_states[IDLE]);
	k_event_clear(&(s->smf_event), EVENT_REQUEST_SEND);
}

static void sent_run(void *o)
{
	struct s_prop_var *s = o;
	LOG_INF("SENT STATE");
	handle_sent(&(s->packet_sent));
	app_update_send_led(s);
	smf_set_state(&s->ctx, &radio_states[IDLE]);
	k_event_clear(&(s->smf_event), EVENT_RADIO_SENT);
}

static void received_run(void *o)
{
	struct s_prop_var *s = o;
	LOG_INF("RECEIVE STATE");
	handle_receive();
	app_update_receive_led(s);
	smf_set_state(&s->ctx, &radio_states[IDLE]);
	k_event_clear(&(s->smf_event), EVENT_RADIO_RECEIVED);
}

static void error_run(void *o)
{
	struct s_prop_var *s = o;
	LOG_INF("ERROR STATE");
	handle_error(&(s->error_code));
	smf_set_state(&s->ctx, &radio_states[IDLE]);
	k_event_clear(&(s->smf_event), EVENT_RADIO_ERROR);
}
