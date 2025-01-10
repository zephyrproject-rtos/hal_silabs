/***************************************************************************//**
 * @file
 * @brief This is a simple wrapper for the stdlib memory management functions
 *   like malloc, calloc, realloc and free in order to redirect memory_manager API
 *   to stdlib implementation.
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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

#include "sl_memory_manager.h"
#include "sl_status.h"
#include "sl_core.h"

#include <stdlib.h>

/***************************************************************************//**
 * Initializes the memory manager.
 ******************************************************************************/
sl_status_t sl_memory_init(void)
{
  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Allocates a memory block of at least requested size from the heap. Simple
 * version.
 *
 * This function will be redirected to the 'malloc()' function.
 ******************************************************************************/
void *sl_malloc(size_t size)
{
  void *block_avail;
  CORE_DECLARE_IRQ_STATE;

  CORE_ENTER_ATOMIC();

  block_avail = malloc(size);

  CORE_EXIT_ATOMIC();

  return block_avail;
}

/***************************************************************************//**
 * Dynamically allocates a block of memory. Advanced version that allows to
 * specify alignment.
 *
 * This function will be redirected to the standard 'malloc()' function.
 ******************************************************************************/
sl_status_t sl_memory_alloc_advanced(size_t size,
                                     size_t align,
                                     sl_memory_block_type_t type,
                                     void **block)
{
  (void)type;

  if (block == NULL) {
    return SL_STATUS_NULL_POINTER;
  }

  // No block allocated yet.
  *block = NULL;

  if ((size == 0) || (align == 0)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_ATOMIC();

  *block = malloc(size);

  CORE_EXIT_ATOMIC();

  if (*block == NULL) {
    return SL_STATUS_ALLOCATION_FAILED;
  }

  if ((align != SL_MEMORY_BLOCK_ALIGN_DEFAULT) && (((uintptr_t)*block % (uintptr_t)align) != 0)) {
    // Deallocate *block.
    sl_free(*block);
    *block = NULL;

    return SL_STATUS_INVALID_PARAMETER;
  }

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Dynamically allocates a block of memory.
 *
 * This function simplifies memory allocation by calling 'sl_memory_alloc_advanced()'
 * with alignment set to 8 bytes.
 ******************************************************************************/
sl_status_t sl_memory_alloc(size_t size,
                            sl_memory_block_type_t type,
                            void **block)
{
  return sl_memory_alloc_advanced(size, SL_MEMORY_BLOCK_ALIGN_DEFAULT, type, block);
}

/***************************************************************************//**
 * Dynamically allocates a block of memory cleared to 0. Simple version.
 *
 * This function will be redirected to the standard 'calloc()' function.
 ******************************************************************************/
void *sl_calloc(size_t item_count,
                size_t size)
{
  void *block_avail = NULL;

  (void)sl_memory_calloc(item_count, size, BLOCK_TYPE_LONG_TERM, &block_avail);

  return block_avail;
}

/***************************************************************************//**
 * Dynamically allocates a block of memory cleared to 0.
 *
 * This function will be redirected to the standard 'calloc()' function.
 ******************************************************************************/
sl_status_t sl_memory_calloc(size_t item_count,
                             size_t size,
                             sl_memory_block_type_t type,
                             void **block)
{
  (void)type;
  CORE_DECLARE_IRQ_STATE;

  // Verify that the block pointer isn't NULL.
  if (block == NULL) {
    return SL_STATUS_NULL_POINTER;
  }

  *block = NULL; // No block allocated yet.

  if ((size == 0) || (item_count == 0)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  CORE_ENTER_ATOMIC();

  *block = calloc(item_count, size);

  CORE_EXIT_ATOMIC();

  if (*block == NULL) {
    return SL_STATUS_ALLOCATION_FAILED;
  }

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Resizes a previously allocated memory block. Simple version.
 *
 * This function will be redirected to the standard 'realloc()' function.
 ******************************************************************************/
void *sl_realloc(void *ptr, size_t size)
{
  void *block_avail = NULL;

  (void)sl_memory_realloc(ptr, size, &block_avail);

  return block_avail;
}

/***************************************************************************//**
 * Resizes a previously allocated memory block.
 *
 * This function will be redirected to the standard 'realloc()' function.
 ******************************************************************************/
sl_status_t sl_memory_realloc(void *ptr,
                              size_t size,
                              void **block)
{
  (void)block;
  CORE_DECLARE_IRQ_STATE;

  // Verify that the block pointer isn't NULL.
  if (block == NULL) {
    return SL_STATUS_NULL_POINTER;
  }

  *block = NULL; // No block allocated yet.

  if ((ptr == NULL) && (size == 0)) {
    return SL_STATUS_INVALID_PARAMETER;
  }

  CORE_ENTER_ATOMIC();

  *block = realloc(ptr, size);

  CORE_EXIT_ATOMIC();

  if (*block == NULL) {
    return SL_STATUS_ALLOCATION_FAILED;
  }

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Frees a dynamically allocated block of memory.
 *
 * This function will be redirected to the standard 'free()' function.
 ******************************************************************************/
sl_status_t sl_memory_free(void *ptr)
{
  CORE_DECLARE_IRQ_STATE;

  if (ptr == NULL) {
    return SL_STATUS_NULL_POINTER;
  }

  CORE_ENTER_ATOMIC();

  free(ptr);

  CORE_EXIT_ATOMIC();

  return SL_STATUS_OK;
}

/***************************************************************************//**
 * Frees a previously allocated block back into the heap. Simple version.
 *
 * This function will be redirected to the 'free()' function.
 ******************************************************************************/
void sl_free(void *ptr)
{
  (void)sl_memory_free(ptr);
}
