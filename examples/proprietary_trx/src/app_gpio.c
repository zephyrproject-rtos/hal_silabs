/***************************************************************************//**
 * @file app_gpio.c
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
#include "errno.h"
#include "app_gpio.h"

// -----------------------------------------------------------------------------
// Macros and Typedefs

LOG_MODULE_DECLARE(trx_app_log);

// -----------------------------------------------------------------------------
// Static Function Declarations

// Callback function to handle button press for sending a packet
static void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins);

// Initialize given button to use button_press callback
static int init_button(const struct gpio_dt_spec *button);

static int init_led(const struct gpio_dt_spec *led);

// -----------------------------------------------------------------------------
// Global Variables

// -----------------------------------------------------------------------------
// Static Variables

// -----------------------------------------------------------------------------
// Public Function Definitions

int app_init_gpios(struct s_prop_var *s_state)
{
	BUILD_ASSERT(DT_NODE_HAS_STATUS(DT_ALIAS(sw0), okay),
		     "Unsupported board: sw0 devicetree alias is not defined");
	BUILD_ASSERT(DT_NODE_HAS_STATUS(DT_ALIAS(led0), okay),
		     "Unsupported board: led0 devicetree alias is not defined");

	int ret = 0;
	ret = init_button(&s_state->button0);
	if (ret) {
		return ret;
	}
	if (DT_NODE_HAS_STATUS(DT_ALIAS(sw1), okay)) {
		ret = init_button(&s_state->button1);
		if (ret) {
			return ret;
		}
	}

	ret = init_led(&s_state->led0);
	if (ret) {
		return ret;
	}

	if (DT_NODE_HAS_STATUS(DT_ALIAS(led1), okay)) {
		ret = init_led(&s_state->led1);
		if (ret) {
			return ret;
		}
	}

	return ret;
}

void app_update_receive_led(struct s_prop_var *s_state)
{
	int ret = 0;
	ret = gpio_pin_toggle_dt(&(s_state->led0));
	if (ret) {
		LOG_WRN("Led toggle for led0 returned with %d", ret);
	}
}

void app_update_send_led(struct s_prop_var *s_state)
{
	int ret = 0;
	if (DT_NODE_HAS_STATUS(DT_ALIAS(led1), okay)) {
		ret = gpio_pin_toggle_dt(&s_state->led1);
		if (ret) {
			LOG_WRN("Led toggle for led1 returned with %d", ret);
		}
	} else {
		ret = gpio_pin_toggle_dt(&s_state->led0);
		if (ret) {
			LOG_WRN("Led toggle for led0 returned with %d", ret);
		}
	}
}
// -----------------------------------------------------------------------------
// Static Function Definitions

static void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	struct s_prop_var *context = CONTAINER_OF(cb, struct s_prop_var, button_cb_data);
	k_event_post(&context->smf_event, EVENT_REQUEST_SEND);
}

static int init_button(const struct gpio_dt_spec *button)
{
	int ret = 0;
	if (!gpio_is_ready_dt(button)) {
		LOG_ERR("Error: button device %s is not ready", button->port->name);
		return -EINVAL;
	}

	ret = gpio_pin_configure_dt(button, GPIO_INPUT);
	if (ret) {
		LOG_ERR("Error %d: failed to configure %s pin %d", ret, button->port->name,
			button->pin);
		return ret;
	}

	ret = gpio_pin_interrupt_configure_dt(button, GPIO_INT_EDGE_TO_ACTIVE);
	if (ret) {
		LOG_ERR("Error %d: failed to configure interrupt on %s pin %d", ret,
			button->port->name, button->pin);
		return ret;
	}

	gpio_init_callback(&s_sl_machine.button_cb_data, button_pressed, BIT(button->pin));
	gpio_add_callback(button->port, &s_sl_machine.button_cb_data);

	return 0;
}

static int init_led(const struct gpio_dt_spec *led)
{
	int ret = 0;
	if (led->port && !gpio_is_ready_dt(led)) {
		LOG_ERR("LED device %s is not ready; ignoring it", led->port->name);
		return -EINVAL;
	}

	ret = gpio_pin_configure_dt(led, GPIO_OUTPUT);
	if (ret) {
		LOG_ERR("Error %d: failed to configure LED device %s pin %d", ret, led->port->name,
			led->pin);
		return ret;
	}

	ret = gpio_pin_set_dt(led, 0);
	if (ret) {
		LOG_WRN("Led clear for %s returned with %d", led->port->name, ret);
	}

	return 0;
}
