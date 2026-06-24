/***************************************************************************//**
 * @file
 * @brief Common LTO-safe primitives shared across the platform/security
 *        components (currently: secret-buffer zeroization).
 *******************************************************************************
 * # License
 * <b>Copyright 2026 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SLI_PSEC_COMMON_H
#define SLI_PSEC_COMMON_H

#include <stddef.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************//**
 * @brief
 *   LTO-safe zeroization of a secret-bearing buffer.
 *
 * @details
 *   Defeats dead-store elimination, including the memset-aware DSE that
 *   GCC/Clang apply under LTO, so that wipes immediately before the buffer
 *   leaves scope are guaranteed to be emitted in the compiled object.
 *
 *   Strength tiers (chosen at compile time):
 *     - GCC, Clang/armclang: memset() followed by an inline-asm ":memory"
 *       clobber. The clobber forces the optimizer to treat the prior memset
 *       stores as observable by external code, blocking DSE.
 *     - IAR EWARM 9.20+: same pattern via the GCC-compatible extended-asm
 *       syntax that EWARM 9.x supports. Covers the supported IAR matrix.
 *     - Any other compiler: per-byte volatile-store loop. Each store is a
 *       side effect the C standard requires to be preserved (C17 6.7.3p7
 *       and 5.1.2.3), no compiler extension required.
 *
 *   The volatile-pointer-loop helper used historically (sli_psa_zeroize,
 *   now a thin wrapper around this function) is functionally equivalent
 *   under the volatile-store rule, but the asm-clobber form gives a
 *   stricter optimizer barrier and uses libc memset on real-world buffer
 *   sizes, which is faster and smaller.
 *
 *   Note that the function-pointer indirection used by upstream
 *   mbedtls_platform_zeroize is unnecessary on top of the asm clobber: the
 *   indirection only protects the memset call from memset-aware DSE, and
 *   the asm clobber already does that more directly by binding the buffer
 *   contents to an opaque external observer.
 *
 *   This helper is *not* thread-safe and provides no synchronization.
 *   Callers are responsible for serializing concurrent access to the
 *   buffer being wiped.
 *
 *   Calling with @p n == 0 is a no-op.
 *
 * @param[out] v
 *   Start of the buffer to wipe. May be NULL only when @p n is 0.
 *
 * @param[in] n
 *   Number of bytes to wipe.
 ******************************************************************************/
static inline void sli_psec_zeroize(void *v, size_t n)
{
  if (n == 0u) {
    return;
  }
#if defined(__GNUC__) || defined(__clang__)
  memset(v, 0, n);
  __asm__ __volatile__ ("" : : "r" (v), "r" (n) : "memory");
#elif defined(__IAR_SYSTEMS_ICC__) && (__VER__ >= 9020001)
  /* IAR EWARM 9.20+ accepts GCC-compatible extended inline-asm syntax. */
  memset(v, 0, n);
  asm volatile ("" : : : "memory");
#else
  /* Fallback for any compiler outside the supported matrix. The volatile
   * stores are a language-level guarantee and need no compiler extension. */
  volatile unsigned char *p = (volatile unsigned char *)v;
  while (n-- != 0u) {
    *p++ = 0u;
  }
#endif
}

#ifdef __cplusplus
}
#endif

#endif /* SLI_PSEC_COMMON_H */
