/*******************************************************************************
* @file  rsi_sdio_mem_rd_wr.c
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
 * @file       rsi_sdio_mem_rd_wr.c
 * @version    0.1
 * @date       15 Aug 2015
 *
 *
 *
 * @brief SDIO MEMRDWR: SPI Memory Read/Write functions, r/w memory on the module via the SPI interface
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
/** @addtogroup DRIVER1
* @{
*/
/*===========================================================================*/
/**
 * @brief       This API writes contents of dBuf buffer to the device memory address addr for the length len 
 * @param[in]   addr            -  Device memory address. 
 * @param[in]   len             -  Length of the buffer.
 * @param[in]   dBuf            -  Data present in this buffer
 * @return       0              -  Success \n
 * @return       Non-Zero value -  Failure \n
 *             
 */

int16_t rsi_mem_wr(uint32_t addr, uint16_t len, uint8_t *dBuf)
{
  uint8_t data;
  int16_t retval        = RSI_SUCCESS;
  uint16_t no_of_blocks = 0;
  data                  = ((addr & 0xff000000) >> 24);
  // write MSB to 0xFB
  retval = rsi_reg_wr(0xfb, &data);
  if (retval != RSI_SUCCESS)
    return retval;

  data = ((addr & 0x00ff0000) >> 16);
  // write MSB to 0xFA
  retval = rsi_reg_wr(0xfa, &data);
  if (retval != RSI_SUCCESS)
    return retval;

  if (len > 256) {
    // Calculate number of blocks
    no_of_blocks = (len / 256);
    if (len % 256) {
      no_of_blocks = no_of_blocks + 1;
    }
    // Transfer packet
    return rsi_sdio_write_multiple(dBuf, (addr & 0xffff) | SD_MASTER_ACCESS, no_of_blocks);
  } else {
    return rsi_sdio_writeb((addr & 0xffff) | SD_MASTER_ACCESS, len, dBuf);
  }
}

/*===========================================================================*/
/**
 * @brief       This API reads the device memory contents present at the address addr into the dBuf buffer for the length len 
 * @param[in]   addr             -  Device memory address. 
 * @param[in]   len              -  Length of the buffer.
 * @param[in]   dBuf             -  Destination buffer.
 * @return       0               -  Success \n
 * @return       Non-Zero value  -  Failure \n
 *             
 */
int16_t rsi_mem_rd(uint32_t addr, uint16_t len, uint8_t *dBuf)
{
  int16_t retval = RSI_SUCCESS;
  uint8_t data;

  data = ((addr & 0xff000000) >> 24);
  // write MSB to 0xFB
  retval = rsi_reg_wr(0xfb, &data);
  if (retval != RSI_SUCCESS)
    return retval;

  data = ((addr & 0x00ff0000) >> 16);
  // write MSB to 0xFA
  retval = rsi_reg_wr(0xfa, &data);
  if (retval != RSI_SUCCESS)
    return retval;

  return rsi_sdio_readb((addr & 0xffff) | SD_MASTER_ACCESS, len, dBuf);
}

/*==================================================*/
/**
 * @brief       This API reads the status register of the host interface layer to validate the interrupt received.
 * @param[in]   int_status      -  Interrupt status. 
 * @return      0               -  Success \n
 * @return      Non-zero value  -  Failure (**Possible Error Codes** - 0xffffffd0, ) \n
 * 
 */
int16_t rsi_device_interrupt_status(uint8_t *int_status)
{
  int16_t retval;
  uint32_t timeout;
  timeout = RSI_SDIO_TIMEOUT;
  RSI_RESET_SDIO_TIMER;
  while (1) {
    if (RSI_INC_SDIO_TIMER > timeout) {
      retval = RSI_ERROR_SDIO_TIMEOUT;
      break;
    }
    // Read the interrupt register
    retval = rsi_reg_rd(RSI_SDIO_INTF_STATUS_REG, int_status);

    if (retval == 0) {
      break;
    }
  }

  return retval;
}
#endif
/** @} */
