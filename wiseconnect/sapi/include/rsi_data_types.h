/*******************************************************************************
* @file  rsi_data_types.h
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

#ifndef RSI_DATA_TYPES_H
#define RSI_DATA_TYPES_H
#include <stdint.h>
/******************************************************
 * *                      Macros
 * ******************************************************/
#ifndef NULL
#define NULL 0
#endif

//! Enable feature
#define RSI_ENABLE 1
//! Disable feature
#define RSI_DISABLE 0

/******************************************************
 * *                    Constants
 * ******************************************************/
/******************************************************
 * *                   Enumerations
 * ******************************************************/
/******************************************************
 * *                 Type Definitions
 * ******************************************************/
#if 0
#ifndef int8_t
typedef signed char  	int8_t;
#endif

#ifndef uint8_t
typedef unsigned char  	uint8_t;
#endif

#ifndef int16_t
typedef short int  int16_t;
#endif

#ifndef uint16_t
typedef unsigned short int  uint16_t;
#endif

#ifndef int32_t
typedef int  int32_t;
#endif

#ifndef uint32_t
typedef unsigned int  uint32_t;
#endif

#ifndef int64_t
typedef signed long long int 	int64_t;
#endif

#ifndef uint64_t
typedef unsigned long long int 	uint64_t;
#endif
#endif

#ifndef RSI_M4_INTERFACE
#define STATIC static
#define INLINE inline
#endif
/******************************************************
 * *                    Structures
 * ******************************************************/
/******************************************************
 * *                 Global Variables
 * ******************************************************/
/******************************************************
 * *               Function Declarations
 * ******************************************************/
#endif
