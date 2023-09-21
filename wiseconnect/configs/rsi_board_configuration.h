/*
 * Copyright (c) 2022 T-Mobile USA, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* This eliminates the sscanf warning */
#if !CONFIG_NEWLIB_LIBC
int sscanf(const char *str, const char *format, ...);
#endif
