/*******************************************************************************
* @file  rsi_hal_mcu_spi.c
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
#include <zephyr/drivers/spi.h>
#include <zephyr/sys/printk.h>

#define DT_DRV_COMPAT silabs_rs9116w

struct rs9116w_config {
	struct spi_dt_spec spi;
};

static struct rs9116w_config rs9116w_conf = {
	.spi = SPI_DT_SPEC_INST_GET(0, SPI_OP_MODE_MASTER | SPI_WORD_SET(8), 2)
};

/**
 * Global Variables
 */


/*==================================================================*/
/**
 * @fn         int16_t cs_enable()
 * @param[out] None
 * @return     0, 0=success
 * @section description  
 * This API is used to enable the spi chip select pin in SPI interface.
 */
void cs_enable(void)
{
    //! enables the spi chip select pin on SPI interface
    
}

/*==================================================================*/
/**
 * @fn         int16_t cs_disable()
 * @param[out] None
 * @return     0, 0=success
 * @section description  
 * This API is used to disable the spi chip select pin in SPI interface.
 */
void cs_disable(void)
{
    
    //! disables the spi chip select pin on SPI interface

}
/*==================================================================*/
/**
 * @fn         int16_t rsi_spi_transfer(uint8_t *ptrBuf,uint16_t bufLen,uint8_t *valBuf,uint8_t mode)
 * @param[in]  uint8_t *tx_buff, pointer to the buffer with the data to be transfered
 * @param[in]  uint8_t *rx_buff, pointer to the buffer to store the data received
 * @param[in]  uint16_t transfer_length, Number of bytes to send and receive
 * @param[in]  uint8_t mode, To indicate mode 8 BIT/32 BIT mode transfers.
 * @param[out] None
 * @return     0, 0=success
 * @section description  
 * This API is used to tranfer/receive data to the Wi-Fi module through the SPI interface.
 */
int16_t rsi_spi_transfer(uint8_t *tx_buff, uint8_t *rx_buff, uint16_t transfer_length,uint8_t mode)
{
    #ifdef RSI_SPI_INTERFACE
    if(!spi_is_ready_dt(&rs9116w_conf.spi)) {
        printk("spi bus %s not ready", rs9116w_conf.spi.bus->name);	
        return -ENODEV;
    }

    struct spi_buf rx_buf, tx_buf;
    rx_buf.buf = rx_buff;
    rx_buf.len = transfer_length;
    tx_buf.buf = tx_buff;
    tx_buf.len = transfer_length;
    struct spi_buf_set rx, tx;
    rx.buffers = &rx_buf;
    rx.count = 1;
    tx.buffers = &tx_buf;
    tx.count = 1;

    int rc = spi_transceive_dt(&rs9116w_conf.spi, (const struct spi_buf_set *)&tx, (const struct spi_buf_set *)&rx);

    return rc;

    #else

    return 0;

    #endif
}
