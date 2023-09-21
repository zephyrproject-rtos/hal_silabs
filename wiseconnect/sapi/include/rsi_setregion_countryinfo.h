/*******************************************************************************
* @file  rsi_setregion_countryinfo.h
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

#ifndef _SETREGION_COUNTRYINFO_H_
#define _SETREGION_COUNTRYINFO_H_

#include <rsi_driver.h>

#define REGION_US        1
#define REGION_EU        2
#define REGION_JP        3
#define REGION_INDIA     4
#define REGION_SINGAPORE 5
#define REGION_KOREA     6

void extract_setregionap_country_info(rsi_req_set_region_ap_t *);
#endif
