/*******************************************************************************
* @file  rsi_utils_rom.c
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
  Include files
 */
#include "rsi_driver.h"
#ifndef ROM_WIRELESS
/*
  Global defines
 */

/** @addtogroup DRIVER12
* @{
*/
/*=============================================================================*/
/**
 * @fn              void ROM_WL_rsi_uint16_to_2bytes(global_cb_t *global_cb_p, uint8_t *dBuf, uint16_t val)
 * @brief           Convert uint16 to two byte array
 * @param[in]       global_cb_p - pointer to the common buffer
 * @param[in]       dBuf 		- pointer to buffer to put the data in
 * @param[in]       val 		- data to convert
 * @return          void
 */
/// @private
void ROM_WL_rsi_uint16_to_2bytes(global_cb_t *global_cb_p, uint8_t *dBuf, uint16_t val)
{
  if (global_cb_p->endian == IS_LITTLE_ENDIAN) {
    dBuf[0] = val & 0x00ff;
    dBuf[1] = (val >> 8) & 0x00ff;
  } else {
    dBuf[1] = val & 0x00ff;
    dBuf[0] = (val >> 8) & 0x00ff;
  }
}

/*=============================================================================*/
/**
 * @fn              void ROM_WL_rsi_uint32_to_4bytes(global_cb_t *global_cb_p,  uint8_t *dBuf, uint32_t val)
 * @brief           Convert uint32 to four byte array
 * @param[in]       global_cb_p - pointer to the common buffer
 * @param[in]       dBuf        - pointer to the buffer to put the data in
 * @param[in]       val      	- data to convert
 * @return          void
 */
/// @private
void ROM_WL_rsi_uint32_to_4bytes(global_cb_t *global_cb_p, uint8_t *dBuf, uint32_t val)
{
  if (global_cb_p->endian == IS_LITTLE_ENDIAN) {
    dBuf[0] = val & 0x000000ff;
    dBuf[1] = (val >> 8) & 0x000000ff;
    dBuf[2] = (val >> 16) & 0x000000ff;
    dBuf[3] = (val >> 24) & 0x000000ff;
  } else {
    dBuf[3] = val & 0x000000ff;
    dBuf[2] = (val >> 8) & 0x000000ff;
    dBuf[1] = (val >> 16) & 0x000000ff;
    dBuf[0] = (val >> 24) & 0x000000ff;
  }
}

/*=============================================================================*/
/**
 * @fn              uint16_t ROM_WL_rsi_bytes2R_to_uint16(global_cb_t *global_cb_p, uint8_t *dBuf)
 * @brief           Convert a 2 byte array to uint16, first byte in array is LSB
 * @param[in]       global_cb_p - pointer to the common buffer
 * @param[in]       dBuf        - pointer to a buffer to get the data from
 * @return          Converted data
 */
/// @private
uint16_t ROM_WL_rsi_bytes2R_to_uint16(global_cb_t *global_cb_p, uint8_t *dBuf)
{
  uint16_t val;
  if (global_cb_p->endian == IS_LITTLE_ENDIAN) {
    val = dBuf[1];
    val <<= 8;
    val |= dBuf[0] & 0x000000ff;
  } else {
    val = dBuf[0];
    val <<= 8;
    val |= dBuf[1] & 0x000000ff;
  }
  return val;
}

/*=============================================================================*/
/**
 * @fn           uint32_t ROM_WL_rsi_bytes4R_to_uint32(global_cb_t *global_cb_p,  uint8_t *dBuf)
 * @brief        Convert a 4 byte array to uint32, first byte in array is LSB
 * @param[in]    global_cb_p - pointer to the common buffer
 * @param[in]    dBuf        - pointer to buffer to get the data from
 * @return       Converted data
 */
/// @private
uint32_t ROM_WL_rsi_bytes4R_to_uint32(global_cb_t *global_cb_p, uint8_t *dBuf)
{
  // the 32-bit value to return
  uint32_t val;

  if (global_cb_p->endian == IS_LITTLE_ENDIAN) {
    val = dBuf[3];
    val <<= 8;
    val |= dBuf[2] & 0x000000ff;
    val <<= 8;
    val |= dBuf[1] & 0x000000ff;
    val <<= 8;
    val |= dBuf[0] & 0x000000ff;
  } else {
    val = dBuf[0];
    val <<= 8;
    val |= dBuf[1] & 0x000000ff;
    val <<= 8;
    val |= dBuf[2] & 0x000000ff;
    val <<= 8;
    val |= dBuf[3] & 0x000000ff;
  }

  return val;
}
#endif
/** @} */
