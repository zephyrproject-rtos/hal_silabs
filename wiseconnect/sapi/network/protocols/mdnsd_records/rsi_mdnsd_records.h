/*******************************************************************************
* @file  rsi_mdnsd_records.h
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
 * Includes
 */
#ifndef RSI_MDNSD_RECORDS_H
#define RSI_MDNSD_RECORDS_H

typedef struct rsi_mdns_txt_rec_g {
  uint8_t *buffer;   // Pointer to data
  uint16_t buflen;   // Length of buffer
  uint16_t datalen;  // Length currently in use
  uint16_t malloced; // Non-zero if buffer was allocated via malloc()
} rsi_mdns_txt_rec_t;

void rsi_mdns_txt_rec_create(rsi_mdns_txt_rec_t *txtRecord, uint16_t bufferLen, void *buffer);
int8_t rsi_mdns_txt_rec_setvalue(rsi_mdns_txt_rec_t *txtRecord, const char *key, uint8_t valueSize, const void *value);
uint8_t *rsi_mdns_txt_rec_search(uint16_t txtLen, const void *txtRecord, const char *key, uint32_t *keylen);
int8_t rsi_mdns_txt_rec_removevalue(rsi_mdns_txt_rec_t *txtRecord, const char *key);
const void *rsi_mdns_txt_get_bytes_ptr(rsi_mdns_txt_rec_t *txtRecord);
const void *rsi_mdns_get_txt_rec_buffer(rsi_mdns_txt_rec_t *txtRecord);
#endif
