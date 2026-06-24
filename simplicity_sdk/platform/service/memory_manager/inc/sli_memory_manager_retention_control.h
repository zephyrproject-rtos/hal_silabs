/***************************************************************************//**
 * @file
 * @brief Memory Manager Retention Control.
 *******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#ifndef SLI_MEMORY_MANAGER_RETENTION_CONTROL_H_
#define SLI_MEMORY_MANAGER_RETENTION_CONTROL_H_

#include <stddef.h>
#include <stdint.h>

#include "sl_memory_manager.h"
#include "sli_memory_manager.h"
#include "sl_memory_manager_config.h"

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------------
// DEFINES

// Registers width in bits.
#define REGISTER_BIT_WIDTH   32U

// ----------------------------------------------------------------------------
// DATA TYPES

// Retention Control Structure.
// Retention statistics use a retained-primary model: retained_size is tracked
// in SLI_MEMORY_INCREMENT_BANK_COUNTER / SLI_MEMORY_DECREMENT_BANK_COUNTER.
// retained_high_watermark is updated only when the application calls
// sli_memory_manager_retention_update_high_watermark (e.g. at sleep entry).
typedef struct {
  uint32_t bank_size;
  uint16_t *banks_counter;
  uint32_t (*get_bank_id)(void *);
  uintptr_t (*get_bank_start_address_by_id)(uint32_t);
  void (*enable_retention)(uint32_t);
  void (*disable_retention)(uint32_t);
  sli_bank_coverage_t (*get_block_bank_coverage)(void *, uint32_t);
#if (SLI_MEMORY_MANAGER_RETENTION_STATISTICS_AVAILABLE == 1)
  uint32_t num_banks;
  size_t retained_size;
  size_t retained_high_watermark;
#endif
} sli_retention_control_t;

// ----------------------------------------------------------------------------
// PROTOTYPES

/***************************************************************************//**
 * Initialize Memory Manager related hardware.
 ******************************************************************************/
void sli_memory_manager_hal_init(void);

/***************************************************************************//**
 * Initialize Memory Manager HAL for the given heap.
 *
 * @param[in]  heap  Heap Handle.
 ******************************************************************************/
void sli_memory_manager_hal_heap_init(sl_memory_heap_t *heap);

/***************************************************************************//**
 * Gets RAM bank ID from address.
 *
 * @param[in]  heap  Heap Handle.
 * @param[in]  addr  Address.
 *
 * @return  RAM bank's ID.
 ******************************************************************************/
uint32_t sli_memory_manager_get_bank_id_by_addr(const sl_memory_heap_t *heap,
                                                void *addr);

/***************************************************************************//**
 * Gets the address of the start of a RAM bank for the heap's memory type.
 *
 * @param[in]  heap     Heap handle (determines DMEM / DTCM / PSRAM layout).
 * @param[in]  bank_id  Bank index
 *
 * @return  Absolute address of the first byte of that bank (REGION_BASE + bank_id * bank_size).
 ******************************************************************************/
uintptr_t sli_memory_manager_get_bank_start_address_by_id(const sl_memory_heap_t *heap,
                                                          uint32_t bank_id);

/***************************************************************************//**
 * Increments Bank Counters between a start bank ID and an end bank ID.
 *
 * @param[in]  heap      Heap Handle.
 * @param[in]  start_id  Start bank ID.
 * @param[in]  end_id    End bank ID.
 ******************************************************************************/
void sli_memory_manager_increment_bank_counter(sl_memory_heap_t *heap,
                                               uint32_t start_id,
                                               uint32_t end_id);

/***************************************************************************//**
 * Decrements Bank Counters between a start bank ID and an end bank ID.
 *
 * @param[in]  heap      Heap Handle.
 * @param[in]  start_id  Start bank ID.
 * @param[in]  end_id    End bank ID.
 ******************************************************************************/
void sli_memory_manager_decrement_bank_counter(sl_memory_heap_t *heap,
                                               uint32_t start_id,
                                               uint32_t end_id);

/***************************************************************************//**
 * Adds size_bytes to retained_size (retention statistics).
 * No-op when retention statistics are disabled. High watermark is not updated.
 *
 * @param[in]  heap        Heap Handle.
 * @param[in]  size_bytes  Size in bytes to add.
 ******************************************************************************/
void sli_memory_manager_retention_add_size(sl_memory_heap_t *heap,
                                           size_t size_bytes);

/***************************************************************************//**
 * Subtracts size_bytes from retained_size (retention statistics).
 * No-op when retention statistics are disabled. High watermark is not updated.
 *
 * @param[in]  heap        Heap Handle.
 * @param[in]  size_bytes  Size in bytes to subtract.
 ******************************************************************************/
void sli_memory_manager_retention_subtract_size(sl_memory_heap_t *heap,
                                           size_t size_bytes);

/***************************************************************************//**
 * Updates the retained high watermark from the current retained_size.
 * No-op when retention statistics are disabled.
 * Call this at the moment of going to sleep (not on every retained size change).
 *
 * @param[in]  heap  Heap Handle.
 ******************************************************************************/
void sli_memory_manager_retention_update_high_watermark(const sl_memory_heap_t *heap);

#ifdef __cplusplus
}
#endif

#endif // SLI_MEMORY_MANAGER_RETENTION_CONTROL_H_
