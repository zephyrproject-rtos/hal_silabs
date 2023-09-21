/*******************************************************************************
* @file  rsi_spi_iface_init.c
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
 * @file     rsi_spi_iface_init.c
 * @version  0.1
 * @date     15 Aug 2015
 *
 *
 *
 * @brief SPI INIT: Functions to initiaize the SPI hardware interface in the module
 * Description
 * Contains the SPI Initialization function.
 * Enable the SPI interface on the Wi-Fi chip.
 * Only run once - during startup, after power-on, or reset
 *
 *
 */

/*
  Includes
 */
#include "rsi_driver.h"
#ifdef RSI_SPI_INTERFACE

/*
  Global Variables
 */
/** @addtogroup DRIVER2
* @{
*/
/*=============================================*/
/**
 * @brief       Initialize the SPI secondary device interface of the module
 * @param[in]   void
 * @return        0              - Success \n
 * @return        Non-Zero value - Failure \n
 */

int16_t rsi_spi_iface_init(void)
{
  SL_PRINTF(SL_SPI_IFACE_INIT_ENTRY, DRIVER, LOG_INFO);

  uint8_t txCmd[4];
  uint8_t localBuf[4] = { 0 };
  int16_t retval      = 0;
  uint16_t timeout;

  // 10ms timeout on command, nothing magic, just a reasonable number
  timeout = 10;

  // Init the timer counter
  RSI_RESET_TIMER1;
  while (1) {
    if (RSI_INC_TIMER_1 > timeout) {
      retval = RSI_ERROR_SPI_TIMEOUT;
      break;
    }

    txCmd[0] = (RSI_RS9116_INIT_CMD & 0xFF);
    txCmd[1] = ((RSI_RS9116_INIT_CMD >> 8) & 0xFF);
    txCmd[2] = ((RSI_RS9116_INIT_CMD >> 16) & 0xFF);
    txCmd[3] = ((RSI_RS9116_INIT_CMD >> 24) & 0xFF);

    retval = rsi_spi_transfer(txCmd, localBuf, sizeof(localBuf), RSI_MODE_8BIT);
    // Retval = rsi_spi_send(txCmd, 2, localBuf, RSI_MODE_8BIT);
    if (localBuf[3] == RSI_SPI_SUCCESS) {
      retval = RSI_SUCCESS;
      break;
    } else {
      retval = RSI_ERROR_SPI_BUSY;
    }
  }
  SL_PRINTF(SL_SPI_IFACE_INIT_EXIT, DRIVER, LOG_INFO, "retval: %d", retval);
  return retval;
}

/*=============================================*/
/**
 * @brief               Initialize the SPI secondary device interface of the module on ULP wakeup
 * @param[in]           void
 * @return              Void
 */
void rsi_ulp_wakeup_init(void)
{
  uint8_t txCmd[4];
  uint8_t rxbuff[2];

  txCmd[0] = (RSI_RS9116_INIT_CMD & 0xFF);
  txCmd[1] = ((RSI_RS9116_INIT_CMD >> 8) & 0xFF);
  txCmd[2] = ((RSI_RS9116_INIT_CMD >> 16) & 0xFF);
  txCmd[3] = ((RSI_RS9116_INIT_CMD >> 24) & 0xFF);

  while (1) {
    rsi_spi_transfer(txCmd, rxbuff, 2, RSI_MODE_8BIT);
    if (rxbuff[1] == RSI_SPI_FAIL) {
      return;
    } else if (rxbuff[1] == 0x00) {
      rsi_spi_transfer(&txCmd[2], rxbuff, 2, RSI_MODE_8BIT);
      if (rxbuff[1] == RSI_SPI_SUCCESS) {
        break;
      }
    }
  }
}
#endif
/** @} */
