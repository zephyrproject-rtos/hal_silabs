/*******************************************************************************
* @file  rsi_hal_mcu_interrupt.c
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
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>

#define DT_DRV_COMPAT silabs_rs9116w

static const struct gpio_dt_spec int_gpio = GPIO_DT_SPEC_INST_GET(0, int_gpios);

typedef void (* interrupt_callback_t)(void);

static struct gpio_callback cb_data;

static interrupt_callback_t callback;

void int_callback(const struct device *port,
	struct gpio_callback *cb, gpio_port_pins_t pins)
{
	callback();
}

/*===================================================*/
/**
 * @fn           void rsi_hal_intr_config(void (* rsi_interrupt_handler)())
 * @brief        Starts and enables the SPI interrupt
 * @param[in]    rsi_interrupt_handler() ,call back function to handle interrupt
 * @param[out]   none
 * @return       none
 * @description  This HAL API should contain the code to initialize the register/pins
 *               related to interrupts and enable the interrupts.
 */
void rsi_hal_intr_config(void (* rsi_interrupt_handler)(void))
{
	
	
	//! Configure interrupt pin/register in input mode and register the interrupt handler
	callback = rsi_interrupt_handler;

	gpio_pin_configure_dt(&int_gpio, GPIO_INPUT);

	gpio_init_callback(&cb_data, int_callback, BIT(int_gpio.pin));
	gpio_add_callback(int_gpio.port, &cb_data);

	return;

}


/*===================================================*/
/** 
 * @fn           void rsi_hal_intr_mask(void)
 * @brief        Disables the SPI Interrupt
 * @param[in]    none
 * @param[out]   none
 * @return       none
 * @description  This HAL API should contain the code to mask/disable interrupts.
 */
void rsi_hal_intr_mask(void)
{
 
	//! Mask/Disable the interrupt 
	gpio_pin_interrupt_configure_dt(&int_gpio, GPIO_INT_DISABLE);
	return;

}


/*===================================================*/
/**
 * @fn           void rsi_hal_intr_unmask(void)
 * @brief        Enables the SPI interrupt
 * @param[in]    none  
 * @param[out]   none
 * @return       none
 * @description  This HAL API should contain the code to enable interrupts.
 */
void rsi_hal_intr_unmask(void)
{
	
	//! Unmask/Enable the interrupt
	gpio_pin_interrupt_configure_dt(&int_gpio, GPIO_INT_EDGE_RISING);
	return;

}



/*===================================================*/
/**
 * @fn           void rsi_hal_intr_clear(void)
 * @brief        Clears the pending interrupt
 * @param[in]    none
 * @param[out]   none
 * @return       none
 * @description  This HAL API should contain the code to clear the handled interrupts.
 */
void rsi_hal_intr_clear(void)
{
	 //! Clear the interrupt
	 
	 return;

 
}


/*===================================================*/
/**
 * @fn          void rsi_hal_intr_pin_status(void)
 * @brief       Checks the SPI interrupt at pin level
 * @param[in]   none  
 * @param[out]  uint8_t, interrupt status 
 * @return      none
 * @description This API is used to check interrupt pin status(pin level whether it is high/low).
 */	
uint8_t rsi_hal_intr_pin_status(void)
{

	volatile uint8_t status = 0;

	//! Return interrupt pin  status(high(1) /low (0))
	status = rsi_hal_get_gpio(RSI_HAL_MODULE_INTERRUPT_PIN);

	return status;
}

