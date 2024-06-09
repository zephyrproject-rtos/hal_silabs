/*******************************************************************************
* @file  rsi_sdio_iface_init.c
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
/**
 * @file     rsi_sdio_iface_init.c
 * @version  0.1
 * @date     15 Aug 2015
 *
 *
 *
 * @brief SPI INIT: Functions that initialize the SPI hardware interface in the module
 * This file contains the SPI Initialization function.
 * This function enables the SPI interface on the chip.
 * This function is only ran once during startup, after power-on, or reset
 *
 *
 */

/*
  Includes
 */
#include "rsi_driver.h"
#ifdef RSI_SDIO_INTERFACE
/*
  Global Variables
 */
void rsi_sdio_hal_efm_deinit(void);

/** @addtogroup DRIVER1
* @{
*/
/*=============================================*/
/**
 * @brief        Initialize the RS9116 SDIO secondary device interface.
 * @param[in]    void
 * @return       0              - Success \n
 * @return       Non-Zero Value - Failure
 */

int16_t rsi_sdio_iface_init(void)
{
  int16_t retval = RSI_SUCCESS;
  SL_PRINTF(SL_SDIO_IFACE_INIT_ENTRY, DRIVER, LOG_INFO);
  uint8_t data;

#ifdef MXRT_595s
  // Do enumeration
  retval = rsi_mcu_sdcard_init();

  if (retval != RSI_SUCCESS) {
    SL_PRINTF(SL_SDIO_IFACE_INIT_EXIT_1, DRIVER, LOG_ERROR, "retval: %d", retval);
    return retval;
  }
#endif
  // Do enumeration
  retval = rsi_mcu_sdio_init();

  if (retval != RSI_SUCCESS) {
    SL_PRINTF(SL_SDIO_IFACE_INIT_EXIT_2, DRIVER, LOG_ERROR, "retval: %d", retval);
    return retval;
  }

  // SDIO_READ_START_LVL
  data   = 0x24;
  retval = rsi_reg_wr(0xfc, &data);
  if (retval != RSI_SUCCESS) {
    SL_PRINTF(SL_SDIO_IFACE_INIT_EXIT_3, DRIVER, LOG_ERROR, "retval: %d", retval);
    return retval;
  }

  // SDIO_READ_FIFO_CTL
  data   = 0x60;
  retval = rsi_reg_wr(0xfd, &data);
  if (retval != RSI_SUCCESS) {
    SL_PRINTF(SL_SDIO_IFACE_INIT_EXIT_4, DRIVER, LOG_ERROR, "retval: %d", retval);
    return retval;
  }

  // SDIO_WRITE_FIFO_CTL
  data   = 0x20;
  retval = rsi_reg_wr(0xfe, &data);
  if (retval != RSI_SUCCESS) {
    SL_PRINTF(SL_SDIO_IFACE_INIT_EXIT_5, DRIVER, LOG_ERROR, "retval: %d", retval);
    return retval;
  }
  SL_PRINTF(SL_SDIO_IFACE_INIT_EXIT_6, DRIVER, LOG_INFO, "retval: %d", retval);
  return retval;
}

/**
 * @brief       This API deinitializes SDIO host interface.
 * 
 */

void rsi_sdio_deinit(void)
{
#ifdef EFM32GG11B820F2048GL192
  rsi_sdio_hal_efm_deinit();
#endif
  return;
}
#endif
/** @} */
