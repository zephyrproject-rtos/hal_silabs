/*******************************************************************************
* @file  rsi_hal_mcu_ioports.c
* @brief
*******************************************************************************
* # License
* Copyright 2020 Silicon Laboratories Inc. http://www.silabs.com/
*******************************************************************************
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*  http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
******************************************************************************/

/*
 * Copyright (c) 2022 T-Mobile USA, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * Includes
 */
#include "rsi_driver.h"

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>

#define DT_DRV_COMPAT silabs_rs9116w

/**
 * Global Variales
 */

static const struct gpio_dt_spec reset_gpio =
	GPIO_DT_SPEC_INST_GET(0, reset_gpios);
static const struct gpio_dt_spec int_gpio = GPIO_DT_SPEC_INST_GET(0, int_gpios);

#if DT_INST_NODE_HAS_PROP(0, sleep_wake_indication_gpios)
static const struct gpio_dt_spec wake_gpio =
	GPIO_DT_SPEC_INST_GET(0, sleep_wake_indication_gpios);
#endif

#if DT_INST_NODE_HAS_PROP(0, sleep_wake_confirmation_gpios)
static const struct gpio_dt_spec sleep_gpio =
	GPIO_DT_SPEC_INST_GET(0, sleep_wake_confirmation_gpios);
#endif

static const struct gpio_dt_spec *get_gpio(uint8_t gpio_number) 
{
	switch (gpio_number) {
	case RSI_HAL_RESET_PIN:
		return &reset_gpio;
		break;
	case RSI_HAL_MODULE_INTERRUPT_PIN:
		return &int_gpio;
		break;
#if DT_INST_NODE_HAS_PROP(0, sleep_wake_indication_gpios)
	case RSI_HAL_WAKEUP_INDICATION_PIN:
		return &wake_gpio;
		break;
#endif
#if DT_INST_NODE_HAS_PROP(0, sleep_wake_confirmation_gpios)
	case RSI_HAL_SLEEP_CONFIRM_PIN:
	case RSI_HAL_LP_SLEEP_CONFIRM_PIN:
		return &sleep_gpio;
		break;
#endif
	default:
		return NULL;
		break;
	}	
}

/*===========================================================*/
/**
 * @fn            void rsi_hal_config_gpio(uint8_t gpio_number,uint8_t
 * mode,uint8_t value)
 * @brief         Configures gpio pin in output mode,with a value
 * @param[in]     uint8_t gpio_number, gpio pin number to be configured
 * @param[in]     uint8_t mode , input/output mode of the gpio pin to configure
 *                0 - input mode
 *                1 - output mode
 * @param[in]     uint8_t value, default value to be driven if gpio is
 * configured in output mode 0 - low 1 - high
 * @param[out]    none
 * @return        none
 * @description This API is used to configure host gpio pin in output mode.
 */
void rsi_hal_config_gpio(uint8_t gpio_number, uint8_t mode, uint8_t value)
{

	//! Initialise the gpio pins in input/output mode

	//! Drive a default value on gpio if gpio is configured in output mode

	gpio_flags_t pin_flags;
	if (mode) {
		pin_flags = value ? GPIO_OUTPUT_ACTIVE : GPIO_OUTPUT_INACTIVE;
	} else {
		pin_flags = GPIO_INPUT;
	}
  const struct gpio_dt_spec *gpio = get_gpio(gpio_number);
	gpio_pin_configure(gpio->port, gpio->pin, pin_flags);

	return;
}

/*===========================================================*/
/**
 * @fn            void rsi_hal_set_gpio(uint8_t gpio_number)
 * @brief         Makes/drives the gpio  value high
 * @param[in]     uint8_t gpio_number, gpio pin number
 * @param[out]    none
 * @return        none
 * @description   This API is used to drives or makes the host gpio value high.
 */
void rsi_hal_set_gpio(uint8_t gpio_number)
{

	//! drives a high value on GPIO

	const struct gpio_dt_spec *gpio = get_gpio(gpio_number);
	gpio_pin_set_raw(gpio->port, gpio->pin, 1);

	return;
}

/*===========================================================*/
/**
 * @fn          uint8_t rsi_hal_get_gpio(void)
 * @brief       get the gpio pin value
 * @param[in]   uint8_t gpio_number, gpio pin number
 * @param[out]  none
 * @return      gpio pin value
 * @description This API is used to configure get the gpio pin value.
 */
uint8_t rsi_hal_get_gpio(uint8_t gpio_number)
{
	uint8_t gpio_value = 0;

	//! Get the gpio value
	const struct gpio_dt_spec *gpio = get_gpio(gpio_number);
	gpio_value = gpio_pin_get_raw(gpio->port, gpio->pin);

	return gpio_value;
}

/*===========================================================*/
/**
 * @fn            void rsi_hal_set_gpio(uint8_t gpio_number)
 * @brief         Makes/drives the gpio value to low
 * @param[in]     uint8_t gpio_number, gpio pin number
 * @param[out]    none
 * @return        none
 * @description   This API is used to drives or makes the host gpio value low.
 */
void rsi_hal_clear_gpio(uint8_t gpio_number)
{

	//! drives a low value on GPIO

	const struct gpio_dt_spec *gpio = get_gpio(gpio_number);
	gpio_pin_set_raw(gpio->port, gpio->pin, 0);

	return;
}
