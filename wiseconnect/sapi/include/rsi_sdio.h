/*******************************************************************************
* @file  rsi_sdio.h
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

#ifndef RSI_SDIO_H
#define RSI_SDIO_H

#ifndef LINUX_PLATFORM
#ifdef RSI_SDIO_INTERFACE
#include "rsi_data_types.h"
#include "stdint.h"
// host descriptor structure
typedef struct rsi_frame_desc_s {
  // Data frame body length. Bits 14:12=queue, 000 for data, Bits 11:0 are the length
  uint8_t frame_len_queue_no[2];
  // Frame type
  uint8_t frame_type;
  // Unused , set to 0x00
  uint8_t reserved[9];
  // Management frame descriptor response status, 0x00=success, else error
  uint8_t status;
  uint8_t reserved1[3];
} rsi_frame_desc_t;

// SDIO Apis defines
#define SD_MASTER_ACCESS     BIT(16)
#define RSI_SDIO_TIMEOUT     50000
#define RSI_INC_SDIO_TIMER   rsi_driver_cb_non_rom->rsi_sdioTimer++
#define RSI_RESET_SDIO_TIMER rsi_driver_cb_non_rom->rsi_sdioTimer = 0
int16_t rsi_sdio_iface_init(void);
int16_t rsi_sdio_write_multiple(uint8_t *tx_data, uint32_t Addr, uint16_t no_of_blocks);
int8_t rsi_sdio_read_multiple(uint8_t *read_buff, uint32_t no_of_blocks);
int8_t sdio_reg_writeb(uint32_t Addr, uint8_t *dBuf);
int8_t sdio_reg_readb(uint32_t Addr, uint8_t *dBuf);
int16_t rsi_sdio_readb(uint32_t addr, uint16_t len, uint8_t *dBuf);
int16_t rsi_sdio_writeb(uint32_t addr, uint16_t len, uint8_t *dBuf);
int16_t rsi_mem_wr(uint32_t addr, uint16_t len, uint8_t *dBuf);
int16_t rsi_mem_rd(uint32_t addr, uint16_t len, uint8_t *dBuf);
int16_t rsi_reg_rd(uint8_t regAddr, uint8_t *dBuf);
int16_t rsi_reg_wr(uint8_t regAddr, uint8_t *dBuf);
int32_t rsi_mcu_sdio_init(void);
int16_t rsi_device_interrupt_status(uint8_t *int_status);
int16_t rsi_frame_write(rsi_frame_desc_t *uFrameDscFrame, uint8_t *payloadparam, uint16_t size_param);
int16_t rsi_frame_read(uint8_t *pkt_buffer);

void smih_callback_handler(uint32_t event);
#endif
#endif
#ifndef RSI_BUFFER_FULL
// buffer full indication register value from module
#define RSI_BUFFER_FULL 0x01
#endif
// RX packet pending register value from module
#define RSI_RX_PKT_PENDING 0x08

// Assertion Interrupt indication from module
#define RSI_ASSERT_INTR 0x80 // BIT(7)
#endif
