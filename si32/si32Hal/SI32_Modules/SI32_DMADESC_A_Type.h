//------------------------------------------------------------------------------
// Copyright 2012 (c) Silicon Laboratories Inc.
//
// SPDX-License-Identifier: Zlib
//
// This siHAL software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//------------------------------------------------------------------------------
/// @file SI32_DMADESC_A_Type.h
//
// Script: 0.58
// HAL Source: 0.1
// Version: 1

#ifndef __SI32_DMADESC_A_TYPE_H__
#define __SI32_DMADESC_A_TYPE_H__

// compiler dependencies
#include <stdbool.h>
#include "si32WideTypes.h"

// register definitions
#include "SI32_DMADESC_A_Registers.h"

// support definitions
#include "SI32_DMADESC_A_Support.h"

#ifdef __cplusplus
extern "C" {
#endif


/// @fn _SI32_DMADESC_A_initialize(SI32_DMADESC_A_Type* basePointer,
///      uint32_t srcend,
///      uint32_t dstend,
///      uint32_t config)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  srcend
///  Valid range is 32 bits.
///  Source data end pointer.
///
/// @param[in]
///  dstend
///  Valid range is 32 bits.
///  Destination data end pointer.
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///  Transfer configuration value. See SI32_DMADESC_A_Support.h for values.
///
void
_SI32_DMADESC_A_initialize(SI32_DMADESC_A_Type* /*basePointer*/,
   uint32_t, /*srcend*/
   uint32_t, /*dstend*/
   uint32_t /*config*/);
///
/// @def SI32_DMADESC_A_initialize(basePointer, srcend, dstend, config)
#define SI32_DMADESC_A_initialize(basePointer, srcend, dstend, config) do{  \
   (basePointer)->SRCEND.U32 = srcend;\
   (basePointer)->DSTEND.U32 = dstend;\
   (basePointer)->CONFIG.U32 = config;\
} while(0)


/// @fn _SI32_DMADESC_A_configure(SI32_DMADESC_A_Type* basePointer,
///      void volatile * srcPointer,
///      void volatile * dstPointer,
///      uint32_t count,
///      uint32_t config)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  srcPointer
///  Source data pointer.
///
/// @param[in]
///  dstPointer
///  Destination data pointer.
///
/// @param[in]
///  count
///  Valid range is 9 bits.
///  Transfer count. Units are in words, half words or bytes depending on
///  the config parameter.
///
/// @param[in]
///  config
///  Valid range is 32 bits.
///  Transfer configuration value. See SI32_DMADESC_A_Support.h for values.
///
void
_SI32_DMADESC_A_configure(SI32_DMADESC_A_Type* /*basePointer*/,
   void volatile *, /*srcPointer*/
   void volatile *, /*dstPointer*/
   uint32_t, /*count*/
   uint32_t /*config*/);
///
/// @def SI32_DMADESC_A_configure(basePointer, srcPointer, dstPointer, count, config)
#define SI32_DMADESC_A_configure(basePointer, srcPointer, dstPointer, count, config) \
   _SI32_DMADESC_A_configure(basePointer, srcPointer, dstPointer, count, config)


/// @fn _SI32_DMADESC_A_configure_memory_scatter_gather(SI32_DMADESC_A_Type* basePointer,
///      SI32_DMADESC_A_Type * descPointer,
///      uint32_t descCount)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  descPointer
///  Pointer to an array of DMA descriptors for the scatter-gather
///  transfers.
///
/// @param[in]
///  descCount
///  Valid range is 7 bits.
///  Number of scatter-gather descriptors.
///
void
_SI32_DMADESC_A_configure_memory_scatter_gather(SI32_DMADESC_A_Type* /*basePointer*/,
   SI32_DMADESC_A_Type *, /*descPointer*/
   uint32_t /*descCount*/);
///
/// @def SI32_DMADESC_A_configure_memory_scatter_gather(basePointer, descPointer, descCount)
#define SI32_DMADESC_A_configure_memory_scatter_gather(basePointer, descPointer, descCount) \
   _SI32_DMADESC_A_configure_memory_scatter_gather(basePointer, descPointer, descCount)


/// @fn _SI32_DMADESC_A_configure_peripheral_scatter_gather(SI32_DMADESC_A_Type* basePointer,
///      SI32_DMADESC_A_Type * descPointer,
///      uint32_t descCount)
///
/// @param[in]
///  basePointer
///
/// @param[in]
///  descPointer
///  Pointer to an array of DMA descriptors for the scatter-gather
///  transfers.
///
/// @param[in]
///  descCount
///  Valid range is 7 bits.
///  Number of scatter-gather descriptors.
///
void
_SI32_DMADESC_A_configure_peripheral_scatter_gather(SI32_DMADESC_A_Type* /*basePointer*/,
   SI32_DMADESC_A_Type *, /*descPointer*/
   uint32_t /*descCount*/);
///
/// @def SI32_DMADESC_A_configure_peripheral_scatter_gather(basePointer, descPointer, descCount)
#define SI32_DMADESC_A_configure_peripheral_scatter_gather(basePointer, descPointer, descCount) \
   _SI32_DMADESC_A_configure_peripheral_scatter_gather(basePointer, descPointer, descCount)


#ifdef __cplusplus
}
#endif

#endif // __SI32_DMADESC_A_TYPE_H__

//-eof--------------------------------------------------------------------------
