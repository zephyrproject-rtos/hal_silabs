/*
 * Copyright (c) 2021 T-Mobile USA, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#ifndef RSI_BT_CONFIG_H
#define RSI_BT_CONFIG_H


#include <rsi_data_types.h>
#include <rsi_bt_common.h>
#include <rsi_bt_common_config.h>

#undef RSI_BT_FEATURE_BITMAP
#define RSI_BT_FEATURE_BITMAP  (BT_RF_TYPE | ENABLE_BLE_PROTOCOL)
#endif

