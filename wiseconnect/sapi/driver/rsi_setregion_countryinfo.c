/*******************************************************************************
* @file  rsi_setregion_countryinfo.c
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
  Includes
 */

#include "rsi_setregion_countryinfo.h"

#if RSI_SET_REGION_AP_FROM_USER

/** @addtogroup DRIVER10
* @{
*/
/*====================================================*/
/**
 * @fn          void extract_setregionap_country_info(rsi_req_set_region_ap_t *rsi_set_region_ap)
 * @brief       Initialize the global parameter structure with parameters used in set region ap command based on the region.
 * @param[in]   ptr_setreg_ap - Pointer to the global parameter structure  
 * @return      void  
 */
///@private
void extract_setregionap_country_info(rsi_req_set_region_ap_t *rsi_set_region_ap)
{
  // The given domain rules are generic rules for some of the countries
  // USER can configure the domain regulations for the respective countries
  uint8_t region_code;

  if (!strcmp(RSI_COUNTRY_CODE, "US "))
    region_code = REGION_US;
  else if (!strcmp(RSI_COUNTRY_CODE, "EU "))
    region_code = REGION_EU;
  else if (!strcmp(RSI_COUNTRY_CODE, "JP "))
    region_code = REGION_JP;
  else if (!strcmp(RSI_COUNTRY_CODE, "SG "))
    region_code = REGION_SINGAPORE;
  else if (!strcmp(RSI_COUNTRY_CODE, "KR "))
    region_code = REGION_KOREA;

  switch (region_code) {
    case REGION_US: {

      if (RSI_BAND == RSI_BAND_2P4GHZ) {
        rsi_set_region_ap->no_of_rules[0]                 = 1;
        rsi_set_region_ap->channel_info[0].first_channel  = 1;
        rsi_set_region_ap->channel_info[0].no_of_channels = 11;
        rsi_set_region_ap->channel_info[0].max_tx_power   = 27;
      } else {
        rsi_set_region_ap->no_of_rules[0]                 = 5;
        rsi_set_region_ap->channel_info[0].first_channel  = 36;
        rsi_set_region_ap->channel_info[0].no_of_channels = 4;
        rsi_set_region_ap->channel_info[0].max_tx_power   = 16;
        rsi_set_region_ap->channel_info[1].first_channel  = 52;
        rsi_set_region_ap->channel_info[1].no_of_channels = 4;
        rsi_set_region_ap->channel_info[1].max_tx_power   = 23;
        rsi_set_region_ap->channel_info[2].first_channel  = 100;
        rsi_set_region_ap->channel_info[2].no_of_channels = 5;
        rsi_set_region_ap->channel_info[2].max_tx_power   = 23;
        rsi_set_region_ap->channel_info[3].first_channel  = 132;
        rsi_set_region_ap->channel_info[3].no_of_channels = 3;
        rsi_set_region_ap->channel_info[3].max_tx_power   = 23;
        rsi_set_region_ap->channel_info[4].first_channel  = 149;
        rsi_set_region_ap->channel_info[4].no_of_channels = 5;
        rsi_set_region_ap->channel_info[4].max_tx_power   = 29;
      }
    } break;
    case REGION_EU: {
      if (RSI_BAND == RSI_BAND_2P4GHZ) {
        rsi_set_region_ap->no_of_rules[0]                 = 1;
        rsi_set_region_ap->channel_info[0].first_channel  = 1;
        rsi_set_region_ap->channel_info[0].no_of_channels = 13;
        rsi_set_region_ap->channel_info[0].max_tx_power   = 20;
      } else {
        rsi_set_region_ap->no_of_rules[0]                 = 3;
        rsi_set_region_ap->channel_info[0].first_channel  = 36;
        rsi_set_region_ap->channel_info[0].no_of_channels = 4;
        rsi_set_region_ap->channel_info[0].max_tx_power   = 23;
        rsi_set_region_ap->channel_info[1].first_channel  = 52;
        rsi_set_region_ap->channel_info[1].no_of_channels = 4;
        rsi_set_region_ap->channel_info[1].max_tx_power   = 23;
        rsi_set_region_ap->channel_info[2].first_channel  = 100;
        rsi_set_region_ap->channel_info[2].no_of_channels = 11;
        rsi_set_region_ap->channel_info[2].max_tx_power   = 30;
      }

    } break;
    case REGION_JP: {
      if (RSI_BAND == RSI_BAND_2P4GHZ) {
        rsi_set_region_ap->no_of_rules[0]                 = 1;
        rsi_set_region_ap->channel_info[0].first_channel  = 1;
        rsi_set_region_ap->channel_info[0].no_of_channels = 14;
        rsi_set_region_ap->channel_info[0].max_tx_power   = 20;
      } else {
        rsi_set_region_ap->no_of_rules[0]                 = 3;
        rsi_set_region_ap->channel_info[0].first_channel  = 36;
        rsi_set_region_ap->channel_info[0].no_of_channels = 4;
        rsi_set_region_ap->channel_info[0].max_tx_power   = 20;
        rsi_set_region_ap->channel_info[1].first_channel  = 52;
        rsi_set_region_ap->channel_info[1].no_of_channels = 4;
        rsi_set_region_ap->channel_info[1].max_tx_power   = 20;
        rsi_set_region_ap->channel_info[2].first_channel  = 100;
        rsi_set_region_ap->channel_info[2].no_of_channels = 11;
        rsi_set_region_ap->channel_info[2].max_tx_power   = 30;
      }

    } break;

    case REGION_SINGAPORE:

    {
      if (RSI_BAND == RSI_BAND_2P4GHZ) {
        rsi_set_region_ap->no_of_rules[0]                 = 1;
        rsi_set_region_ap->channel_info[0].first_channel  = 1;
        rsi_set_region_ap->channel_info[0].no_of_channels = 13;
        rsi_set_region_ap->channel_info[0].max_tx_power   = 27;
      } else {
        rsi_set_region_ap->no_of_rules[0]                 = 5;
        rsi_set_region_ap->channel_info[0].first_channel  = 36;
        rsi_set_region_ap->channel_info[0].no_of_channels = 4;
        rsi_set_region_ap->channel_info[0].max_tx_power   = 16;
        rsi_set_region_ap->channel_info[1].first_channel  = 52;
        rsi_set_region_ap->channel_info[1].no_of_channels = 4;
        rsi_set_region_ap->channel_info[1].max_tx_power   = 23;
        rsi_set_region_ap->channel_info[2].first_channel  = 100;
        rsi_set_region_ap->channel_info[2].no_of_channels = 5;
        rsi_set_region_ap->channel_info[2].max_tx_power   = 23;
        rsi_set_region_ap->channel_info[3].first_channel  = 132;
        rsi_set_region_ap->channel_info[3].no_of_channels = 3;
        rsi_set_region_ap->channel_info[3].max_tx_power   = 23;
        rsi_set_region_ap->channel_info[4].first_channel  = 149;
        rsi_set_region_ap->channel_info[4].no_of_channels = 4;
        rsi_set_region_ap->channel_info[4].max_tx_power   = 29;
      }
    } break;
    case REGION_KOREA: {
      if (RSI_BAND == RSI_BAND_2P4GHZ) {
        rsi_set_region_ap->no_of_rules[0]                 = 1;
        rsi_set_region_ap->channel_info[0].first_channel  = 1;
        rsi_set_region_ap->channel_info[0].no_of_channels = 13;
        rsi_set_region_ap->channel_info[0].max_tx_power   = 27;
      } else {
        rsi_set_region_ap->no_of_rules[0]                 = 1;
        rsi_set_region_ap->channel_info[0].first_channel  = 149;
        rsi_set_region_ap->channel_info[0].no_of_channels = 4;
        rsi_set_region_ap->channel_info[0].max_tx_power   = 29;
      }
    }

    break;
    default: {
      if (RSI_BAND == RSI_BAND_2P4GHZ) {
        rsi_set_region_ap->no_of_rules[0]                 = 1;
        rsi_set_region_ap->channel_info[0].first_channel  = 1;
        rsi_set_region_ap->channel_info[0].no_of_channels = 11;
        rsi_set_region_ap->channel_info[0].max_tx_power   = 27;
      } else {
        rsi_set_region_ap->no_of_rules[0]                 = 5;
        rsi_set_region_ap->channel_info[0].first_channel  = 36;
        rsi_set_region_ap->channel_info[0].no_of_channels = 4;
        rsi_set_region_ap->channel_info[0].max_tx_power   = 16;
        rsi_set_region_ap->channel_info[1].first_channel  = 52;
        rsi_set_region_ap->channel_info[1].no_of_channels = 4;
        rsi_set_region_ap->channel_info[1].max_tx_power   = 23;
        rsi_set_region_ap->channel_info[2].first_channel  = 100;
        rsi_set_region_ap->channel_info[2].no_of_channels = 5;
        rsi_set_region_ap->channel_info[2].max_tx_power   = 23;
        rsi_set_region_ap->channel_info[3].first_channel  = 132;
        rsi_set_region_ap->channel_info[3].no_of_channels = 3;
        rsi_set_region_ap->channel_info[3].max_tx_power   = 23;
        rsi_set_region_ap->channel_info[4].first_channel  = 149;
        rsi_set_region_ap->channel_info[4].no_of_channels = 5;
        rsi_set_region_ap->channel_info[4].max_tx_power   = 29;
      }
    } break;
  }
}
#endif
/** @} */
