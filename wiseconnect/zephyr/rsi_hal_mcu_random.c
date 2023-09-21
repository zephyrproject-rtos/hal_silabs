/*******************************************************************************
* @file  rsi_hal_mcu_random.c
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
#include <zephyr/random/rand32.h>

/**
 * Global Variables
 */


/*==================================================================*/
/**
 * @fn          uint32_t rsi_get_random_number(void)
 * @param[in]   None
 * @return      Random number
 * @description This API is used to return random number.
 */
uint32_t rsi_get_random_number(void)
{

  //! Call the API which generates random number

  return sys_rand32_get();
}

