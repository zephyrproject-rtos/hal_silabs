/*******************************************************************************
* @file  rsi_sdio_frame_rd_wr.c
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
 * @file     rsi_sdio_frame_rd_wr.c
 * @version  0.1
 * @date     15 Aug 2015
 *
 *
 *
 * @brief SDIO Control: Functions to control SDIO frame read/write functions
 *
 * Description
 * SDIO function to read/write management descriptors frames to/from the wlan module
 *
 * Improvements
 * Function header is modified for frameDscRd() function
 */

/*
  Includes
 */
#include "rsi_driver.h"
#include "rsi_pkt_mgmt.h"
#ifdef RSI_SDIO_INTERFACE
/*
  Global Variables
 */
/** @addtogroup DRIVER1
* @{
*/
/*====================================================*/
/**
 * @brief       This API reads the frame from the host interface. 
 * @param[in]   read_buff         - The frame contents read from the host interface are populated to this buffer. 
 * @return       0                - Success \n
 * @return       Non-Zero value   - Failure \n
 *             
 */
int16_t rsi_frame_read(uint8_t *read_buff)
{
  int16_t retval   = RSI_SUCCESS;
  uint8_t response = 0;
  uint16_t no_of_blocks;

  // Read number of blocks
  retval = rsi_reg_rd(0xf1, &response);
  if (retval != RSI_SUCCESS) {
    return retval;
  }
#ifdef CHIP_9117B0
  no_of_blocks = (response & 0xFF);
#else
  no_of_blocks = (response & 0x1F);
#endif

  // Frame read
  retval = rsi_sdio_read_multiple(read_buff, no_of_blocks);
  return retval;
}

/*====================================================*/
/**
 * @brief       This API writes the frame to the host interface. 
 * @param[in]   uFrameDscFrame  -  16 bytes host descriptor. 
 * @param[in]   payloadparam    -  buffer to the frame payload.
 * @param[in]   size_param      -  size of the payload.
 * @return       0              -  Success \n
 * @return       Negative value -  Failure \n
 *             
 */
int16_t rsi_frame_write(rsi_frame_desc_t *uFrameDscFrame, uint8_t *payloadparam, uint16_t size_param)
{
  UNUSED_PARAMETER(payloadparam); //This statement is added only to resolve compilation warning, value is unchanged
  int16_t retval        = RSI_SUCCESS;
  uint16_t Addr         = 0x0000;
  uint16_t no_of_blocks = 0;
  uint16_t queue_type   = 0;

  uint16_t size_of_headroom = 0;

  queue_type = (uFrameDscFrame->frame_len_queue_no[1] >> 4);
#ifdef CHIP_9117
  if ((queue_type == RSI_WLAN_DATA_Q) || (queue_type == RSI_WLAN_MGMT_Q)) {
    size_of_headroom = SIZE_OF_HEADROOM;
  }
#endif

  // Calculate number of blocks
  no_of_blocks = ((size_param + 16 + size_of_headroom) / 256);
  if ((size_param + 16 + size_of_headroom) % 256) {
    no_of_blocks = no_of_blocks + 1;
  }

  Addr = (no_of_blocks * 256);

  Addr = (Addr | (queue_type << 12));

  // Transfer packet
  retval = rsi_sdio_write_multiple(((uint8_t *)uFrameDscFrame - size_of_headroom), Addr, no_of_blocks);
  if (retval == 0) {
    return retval;
  } else {
    return RSI_ERROR_SDIO_WRITE_FAIL;
  }
}
#endif
/** @} */
