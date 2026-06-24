/***************************************************************************//**
 * @file
 * @brief CAN - Controller Area Network Flexible Data-Rate peripheral API
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

#ifndef SL_HAL_CAN_H
#define SL_HAL_CAN_H

#include "em_device.h"

#if defined(CAN_PRESENT)

#ifdef __cplusplus
extern "C" {
#endif

#include "sl_log_helper.h"
#include "sl_enum.h"

/// CAN configurable nominal  baud rates.
#define SL_HAL_CAN_BAUDRATE_125KBPS  125000
#define SL_HAL_CAN_BAUDRATE_250KBPS  250000
#define SL_HAL_CAN_BAUDRATE_500KBPS  500000
#define SL_HAL_CAN_BAUDRATE_1MBPS    1000000

/// CAN configurable data baud rates.
#define SL_HAL_CAN_BAUDRATE_2MBPS    2000000
#define SL_HAL_CAN_BAUDRATE_4MBPS    4000000
#define SL_HAL_CAN_BAUDRATE_5MBPS    5000000
#define SL_HAL_CAN_BAUDRATE_6MBPS    6000000
#define SL_HAL_CAN_BAUDRATE_8MBPS    8000000

/// CAN communication mode.
#define SL_HAL_CAN_CLASSIC  0x0              /* Frame transmitted/received in Classic CAN format */
#define SL_HAL_CAN_FD       0x1              /* Frame transmitted/received in CAN format       */

/// CAN bit rate switching.
#define SL_HAL_CAN_BRS_OFF  0x0              /* CAN frames transmitted/received without bit rate switching */
#define SL_HAL_CAN_BRS_ON   0x1              /* CAN frames transmitted/received with bit rate switching    */

/// CAN timing cancellation type.
#define SL_HAL_CAN_TIMING_AUTO     0x0
#define SL_HAL_CAN_TIMING_MANUAL   0x1

/// CAN id type.
#define SL_HAL_CAN_ID_STANDARD 0x0           /* Standard ID element */
#define SL_HAL_CAN_ID_EXTENDED 0x1           /* Extended ID element */

/// CAN frame type.
#define SL_HAL_CAN_FRAME_DATA    0x0         /* Data frame   */
#define SL_HAL_CAN_FRAME_REMOTE  0x1         /* Remote frame */

/// CAN error state indicator.
#define SL_HAL_CAN_ESI_ACTIVE   0x0          /* Transmitting node is error active  */
#define SL_HAL_CAN_ESI_PASSIVE  0x1          /* Transmitting node is error passive */

/// CAN event fifo control.
#define SL_HAL_CAN_TX_EVENTS_NO_STORE  0x0   /* Do not store Tx events */
#define SL_HAL_CAN_TX_EVENTS_STORE     0x1   /* Store Tx events        */

/// CAN event type.
#define SL_HAL_CAN_TX_EVENT              0x0 /* Tx event                              */
#define SL_HAL_CAN_TX_IN_SPITE_OF_ABORT  0x1 /* Transmission in spite of cancellation */

/// CAN Tx fifo/queue mode.
#define SL_HAL_CAN_TX_OPERATION_FIFO   0x0   /* FIFO mode  */
#define SL_HAL_CAN_TX_OPERATION_QUEUE  0x1   /* Queue mode */

/// CAN timestamp mode.
#define SL_HAL_CAN_TIMESTAMP_INTERNAL  0x1   /* Timestamp counter value incremented according to TCP */
#define SL_HAL_CAN_TIMESTAMP_EXTERNAL  0x2   /* External timestamp counter value used                */

/// CAN FIFO operation mode.
#define SL_HAL_CAN_RX_FIFO_BLOCKING  0x0     /* Rx FIFO blocking mode  */
#define SL_HAL_CAN_RX_FIFO_OVERWRITE 0x1     /* Rx FIFO overwrite mode */

/// CAN reject remote frames.
#define SL_HAL_CAN_REMOTE_FRAME_ACCEPT 0x0,  /* Filter remote frames */
#define SL_HAL_CAN_REMOTE_FRAME_REJECT 0x1   /* Reject all remote frames */

/// CAN operating mode.
SL_ENUM(sl_hal_can_operating_mode_t) {
  SL_HAL_CAN_OPERATION_MODE_NORMAL               = 0x0,/* Normal mode               */
  SL_HAL_CAN_OPERATION_MODE_RESTRICTED           = 0x1,/* Restricted Operation mode */
  SL_HAL_CAN_OPERATION_MODE_BUS_MONITORING       = 0x2,/* Bus Monitoring mode       */
  SL_HAL_CAN_OPERATION_MODE_INTERNAL_LOOPBACK    = 0x3,/* Internal LoopBack mode    */
  SL_HAL_CAN_OPERATION_MODE_EXTERNAL_LOOPBACK    = 0x4 /* External LoopBack mode    */
};

/// CAN filter type.
SL_ENUM(sl_hal_can_filter_type_t) {
  SL_HAL_CAN_FILTER_RANGE              = 0x0,    /* Range filter from FilterID1 to FilterID2                        */
  SL_HAL_CAN_FILTER_DUAL               = 0x1,    /* Dual ID filter for FilterID1 or FilterID2                       */
  SL_HAL_CAN_FILTER_MASK               = 0x2,    /* Classic filter: FilterID1 = filter, FilterID2 = mask            */
  SL_HAL_CAN_FILTER_RANGE_XIDM_NO_MASK = 0x3     /* Range filter from FilterID1 to FilterID2 (FilterID2 ≥ FilterID1), XIDAM mask not applied */
};

/// CAN filter configuration.
SL_ENUM(sl_hal_can_filter_config_t) {
  SL_HAL_CAN_FILTER_DISABLE                 = 0x0, /* Disable filter element                                    */
  SL_HAL_CAN_FILTER_TO_RXFIFO0              = 0x1, /* Store in Rx FIFO 0 if filter matches                      */
  SL_HAL_CAN_FILTER_TO_RXFIFO1              = 0x2, /* Store in Rx FIFO 1 if filter matches                      */
  SL_HAL_CAN_FILTER_REJECT                  = 0x3, /* Reject ID if filter matches                               */
  SL_HAL_CAN_FILTER_SET_PRIORITY            = 0x4, /* Set high priority if filter matches                       */
  SL_HAL_CAN_FILTER_TO_RXFIFO0_SET_PRIORITY = 0x5, /* Set high priority and store in FIFO 0 if filter matches   */
  SL_HAL_CAN_FILTER_TO_RXFIFO1_SET_PRIORITY = 0x6, /* Set high priority and store in FIFO 1 if filter matches   */
  SL_HAL_CAN_FILTER_TO_RXBUFFER             = 0x7  /* Store into Rx Buffer, configuration of FilterType ignored */
};

/// CAN rx location.
SL_ENUM(sl_hal_can_rx_location_t) {
  SL_HAL_CAN_RX_FIFO0    = 0x00, /* Get received message from Rx FIFO 0    */
  SL_HAL_CAN_RX_FIFO1    = 0x01, /* Get received message from Rx FIFO 1     */
  SL_HAL_CAN_RX_BUFFER   = 0x02  /* Get received message from Rx Buffer   */
};

/// CAN fifo watermark.
SL_ENUM(sl_hal_can_fifo_watermark_t) {
  SL_HAL_CAN_CFG_TX_EVENT_FIFO = 0x0, /* Tx event FIFO */
  SL_HAL_CAN_CFG_RX_FIFO0      = 0x1, /* Rx FIFO0      */
  SL_HAL_CAN_CFG_RX_FIFO1      = 0x2  /* Rx FIFO1      */
};

/// CAN non-matching frames.
SL_ENUM(sl_hal_can_non_matching_frames_t) {
  SL_HAL_CAN_NON_MATCHING_FRAMES_IN_RX_FIFO0 = 0x0, /* Accept in Rx FIFO 0 */
  SL_HAL_CAN_NON_MATCHING_FRAMES_IN_RX_FIFO1 = 0x1, /* Accept in Rx FIFO 1 */
  SL_HAL_CAN_NON_MATCHING_FRAMES_REJECT      = 0x2  /* Reject              */
};

/// CAN timeout operation.
SL_ENUM(sl_hal_can_timeout_operation_t) {
  SL_HAL_CAN_CONTINUOUS_OPERATION  = 0x0, /*  continuous operation        */
  SL_HAL_CAN_TIMEOUT_TX_EVENT_FIFO = 0x1, /* Timeout controlled by Tx Event FIFO */
  SL_HAL_CAN_TIMEOUT_RX_FIFO0      = 0x2, /* Timeout controlled by Rx FIFO 0     */
  SL_HAL_CAN_TIMEOUT_RX_FIFO1      = 0x3  /* Timeout controlled by Rx FIFO 1     */
};

/// CAN high priority message storage.
SL_ENUM(sl_hal_can_hpm_storage_t) {
  SL_HAL_CAN_HP_STORAGE_NO_FIFO  = 0x00, /* No FIFO selected         */
  SL_HAL_CAN_HP_STORAGE_MSG_LOST = 0x40, /* FIFO message lost        */
  SL_HAL_CAN_HP_STORAGE_RXFIFO0  = 0x80, /* Message stored in FIFO 0 */
  SL_HAL_CAN_HP_STORAGE_RXFIFO1  = 0xC0  /* Message stored in FIFO 1 */
};

/// CAN high priority message list.
SL_ENUM(sl_hal_can_hp_filter_list_t) {
  SL_HAL_CAN_HP_FILTER_LIST_STD = 0x0,  /* Standard Filter List */
  SL_HAL_CAN_HP_FILTER_LIST_EXD = 0x1   /* Extended Filter List */
};

/// DMU element Service.
SL_ENUM(sl_hal_can_dmu_element_service_t) {
  SL_HAL_CAN_DMU_SERVICE_TX       = 0x14, /* Detect DMU Tx element service   */
  SL_HAL_CAN_DMU_SERVICE_RX0      = 0x15, /* Detect DMU RX0 element service   */
  SL_HAL_CAN_DMU_SERVICE_RX1      = 0x16, /* Detect DMU RX1 element service   */
  SL_HAL_CAN_DMU_SERVICE_TX_EVENT = 0x17  /* Detect DMU Tx Event element service   */
};

/// DMU detect element handler state.
SL_ENUM(sl_hal_can_dmu_handler_state_t) {
  SL_HAL_CAN_DMU_WAIT_FOR_CCE              = 0x0,
  SL_HAL_CAN_DMU_WAIT_FOR_START_ADDRESS    = 0x1,
  SL_HAL_CAN_DMU_WAIT_FOR_TRIGGER_ADDRESS  = 0x2,
  SL_HAL_CAN_DMU_TRANSFER                  = 0x3,
  SL_HAL_CAN_DMU_ACK_TO_MCAN               = 0x4,
  SL_HAL_CAN_DMU_RECOVERY                  = 0x5
};

/// Brief CAN bit timing structure definition.
typedef struct {
  uint16_t sync_jump_width; /* Synchronisation jump width. */
  uint16_t phase_seg1;      /* Phase segment 1 */
  uint16_t phase_seg2;      /* Phase segment 2 */
  uint16_t prescaler;       /* Prescaler value */
}sl_hal_can_bit_timing_t;

/// Brief MRAM config structure definition.
typedef struct {
  uint8_t std_filters_number;              /* The number of standard Message ID filters.Number between 0 and 128         */
  uint8_t ext_filters_number;              /* The number of extended Message ID filters.Number between 0 and 64          */
  /** Sum of rx_fifo0_elements_number + rx_fifo1_elements_number + rx_buffers_number elements value should be less than or equal to 64 */
  uint8_t rx_fifo0_elements_number;        /* The number of Rx FIFO0 Elements.Number between 0 and 64                    */
  uint8_t rx_fifo0_elements_size;           /* The Data Field Size in an Rx FIFO 0 element.Value between 0 and 7          */
  uint8_t rx_fifo1_elements_number;        /* The number of Rx FIFO 1 Elements. Number between 0 and 64                  */
  uint8_t rx_fifo1_elements_size;           /* The Data Field Size in an Rx FIFO 1 element.Value between 0 and 7          */
  uint8_t rx_buffers_number;               /* The number of Dedicated Rx Buffer elements. Number between 0 and 64        */
  uint8_t rx_buffer_size;                  /* The Data Field Size in an Rx Buffer element.Value between 0 and 7          */
  uint8_t tx_events_number;                /* The number of Tx Event FIFO elements. Number between 0 and 32              */
  /** Sum of tx_buffers_element_number + tx_fifo_elements_number elements value should be less than or equal to 32 */
  uint8_t tx_buffer_elements_number;       /* The number of Dedicated Tx Buffers. Number between 0 and 32                */
  uint8_t tx_fifo_elements_number;         /* The number of Tx Buffers used for Tx FIFO/Queue. Number between 0 and 32   */
  uint8_t tx_element_size;                 /* The Data Field Size in a Tx Element.Value between 0 and 7                  */
} sl_hal_can_mram_init_t;

/// Brief CAN init structure definition.
typedef struct {
  union {
    struct {
      uint8_t fd_enable               : 1;   /* The CAN FD Operation 1: Enable, 0: Disable */
      uint8_t brs_enable              : 1;   /* The CAN Bit Rate Switch 1: Enable, 0: Disable */
      uint8_t auto_retransmission     : 1;   /* Automatic retransmission mode 0: Enable, 1: Disable */
      uint8_t transmit_pause          : 1;   /* Transmit Pause feature 1: Enable, 0: Disable */
      uint8_t protocol_exception      : 1;   /* Protocol Exception Handling 1: Enable, 0: Disable*/
      uint8_t tx_fifo_queue_mode      : 1;   /* Tx FIFO/Queue Mode selection */
      uint8_t reserve                 : 2;   /* Padding to complete 1 byte   */
    };
    uint8_t flags;                           /* Optional: access all flags at once */
  };
  sl_hal_can_operating_mode_t mode;          /* The CAN mode */
  sl_hal_can_mram_init_t  mram_init_params;  /* Message RAM initialization  */
  sl_hal_can_bit_timing_t  nominal_bitrate;  /* Can timing for arbitration phase*/
  sl_hal_can_bit_timing_t  data_bitrate;     /* Can timing for data phase*/
} sl_hal_can_init_params_t;

/// Brief CAN message object structure definition.
typedef union {
  struct {
    uint32_t identifier                  : 29;
    uint32_t frame_type                  : 1;
    uint32_t id_type                     : 1;
    uint32_t error_state_indicator       : 1;
    uint32_t reserve1                    : 16;
    uint32_t data_length                 : 4;
    uint32_t bit_rate_switch             : 1;
    uint32_t fd_format                   : 1;
    uint32_t reserve2                    : 1;
    uint32_t tx_event_fifo_control       : 1;
    uint32_t message_marker              : 8;
  };
  uint32_t word[2];
} sl_hal_can_tx_frame_object_t;

/// Brief CAN message object structure definition.
typedef union {
  struct {
    uint32_t identifier                   : 29;
    uint32_t frame_type                   : 1;
    uint32_t id_type                      : 1;
    uint32_t error_state_indicator        : 1;
    uint32_t rx_timestamp                 : 16;
    uint32_t data_length                  : 4;
    uint32_t bit_rate_switch              : 1;
    uint32_t fd_format                    : 1;
    uint32_t reserve2                     : 2;
    uint32_t filter_index                 : 7;
    uint32_t is_filter_matching_frame     : 1;
  };
  uint32_t word[2];
} sl_hal_can_rx_frame_object_t;

/// Brief CAN message object structure definition.
typedef union {
  struct {
    uint32_t identifier                   : 29;
    uint32_t frame_type                   : 1;
    uint32_t id_type                      : 1;
    uint32_t error_state_indicator        : 1;
    uint32_t txe_timestamp                : 16;
    uint32_t data_length                  : 4;
    uint32_t bit_rate_switch              : 1;
    uint32_t fd_format                    : 1;
    uint32_t event_type                   : 2;
    uint32_t message_marker               : 8;
  };
  uint32_t word[2];
} sl_hal_can_tx_event_object_t;

/// Brief CAN filter structure definition.
typedef struct {
  uint8_t id_type;                                             /* The identifier type */
  uint8_t filter_index;                                        /* The filter which will be initialized
                                                                  - 0 and 127, if id_type is STANDARD ID
                                                                  - 0 and 63,  if id_type is EXTENDED ID */
  sl_hal_can_filter_type_t filter_type;                        /* The filter type */
  sl_hal_can_filter_config_t filter_config;                    /* The filter configuration */
  uint32_t filter_id_one;                                      /* The filter identification 1
                                                                  - 0 and 0x7FF, if id_type is STANDARD ID
                                                                  - 0 and 0x1FFFFFFF, if id_type is EXTENDED ID */
  uint32_t filter_id_two;                                      /* The filter identification 2, ignored if filter_config is set to
                                                                  SL_HAL_CAN_FILTER_TO_RXBUFFER.
                                                                  - 0 and 0x7FF, if id_type is STANDARD ID
                                                                  - 0 and 0x1FFFFFFF, if id_type is EXTENDED ID */
  uint16_t rx_buffer_index;                                     /* Contains the index of the Rx buffer in which the matching message
                                                                   will be stored the value between 0 and 63 if rx_buffers_number is 64*/
} sl_hal_can_filter_t;

/// Brief  CAN high priority message status structure definition.
typedef struct {
  sl_hal_can_hp_filter_list_t filter_list;                     /* The filter list of the matching filter element */
  sl_hal_can_hpm_storage_t hpm_storage;                        /* The HP Message Storage  */
  uint8_t filter_index;                                        /* The index of matching filter element
                                                                  - 0 and 127, if filter_list is 0 (Standard)
                                                                  - 0 and 63, if filter_list is  1 (Extended)*/
  uint8_t    message_index;                                    /* The Index of Rx FIFO element to which the message was stored
                                                                  this is valid only when message storage is:
                                                                  SL_HAL_CAN_HP_STORAGE_RXFIFO0 or  SL_HAL_CAN_HP_STORAGE_RXFIFO1 */
} sl_hal_can_hpm_status_t;

/// Brief CAN protocol status structure definition.
typedef struct {
  uint32_t last_error_code          : 3;    /* last error that occurred on the CAN bus */
  uint32_t activity                 : 2;    /* The CAN module communication state */
  uint32_t error_passive            : 1;    /* The CAN module error status
                                               - 0 : The CAN is in error active state
                                               - 1 : The CAN is in error passive state */
  uint32_t warning                  : 1;    /* The CAN module warning status
                                               - 0 : error counters (TEC and REC) are below the error warning limit of 96
                                               - 1 : at least one of error counters has reached the error warning limit of 96           */
  uint32_t bus_off                  : 1;    /* The CAN module Bus_Off status
                                               - 0 : The CAN is not in bus off state
                                               - 1 : The CAN is in bus off state     */
  uint32_t data_last_error_code     : 3;    /* last error that occurred in the data phase of a CAN FD format
                                               frame with its BRS flag set */
  uint32_t rx_esi_flag              : 1;    /* ESI flag of last received CAN FD message
                                               - 0 : Last received message ESI flag not set
                                               - 1 : Last received message ESI flag set    */
  uint32_t rx_brs_flag              : 1;    /* BRS flag of last received CAN FD message
                                               - 0 : Last received message BRS flag not set
                                               - 1 : Last received message BRS flag set    */
  uint32_t rx_fdf_flag              : 1;    /* if CAN FD message (FDF flag set) has been received since last protocol status
                                               - 0 : Classic CAN message received
                                               - 1 : CAN FD message received    */
  uint32_t protocol_exception       : 1;    /* The CAN module Protocol Exception status
                                               - 0 : No protocol exception event occurred
                                               - 1 : Protocol exception event occurred */
  uint32_t reserved1                : 1;    /* Reserved - 0 */
  uint32_t tdc_value                : 7;    /* The transmitter delay compensation value between 0 and 127 */
  uint32_t reserved2                : 9;    /* Reserved - 1 */
} sl_hal_can_protocol_status_t;

/*******************************************************************************
 ****************************  STRUCT INITIALIZERS  ***************************
 ******************************************************************************/
/// Default configuration for the nominal bitrate.
#define SL_HAL_CAN_NOMINAL_TIME(sjw, seg1, seg2, clk_div) \
  (sl_hal_can_bit_timing_t){                              \
    .sync_jump_width = (sjw),                             \
    .phase_seg1      = (seg1),                            \
    .phase_seg2      = (seg2),                            \
    .prescaler       = (clk_div),                         \
  }

/// Default configuration for the data bitrate.
#define SL_HAL_CAN_DATA_TIME(sjw, seg1, seg2, clk_div) \
  (sl_hal_can_bit_timing_t){                           \
    .sync_jump_width = (sjw),                          \
    .phase_seg1      = (seg1),                         \
    .phase_seg2      = (seg2),                         \
    .prescaler       = (clk_div),                      \
  }

/// Default configuration for the mram initialization.
#define SL_HAL_CAN_MRAM_INIT          \
  (sl_hal_can_mram_init_t){           \
    .std_filters_number        = 128, \
    .ext_filters_number        =  64, \
    .rx_fifo0_elements_number  =  24, \
    .rx_fifo0_elements_size     =  7, \
    .rx_fifo1_elements_number  =  24, \
    .rx_fifo1_elements_size     =  7, \
    .rx_buffers_number         =  16, \
    .rx_buffer_size            =   7, \
    .tx_events_number          =  32, \
    .tx_buffer_elements_number =  16, \
    .tx_fifo_elements_number   =  16, \
    .tx_element_size           =   7, \
  }

/// Default configuration for CAN peripheral initialization.
#define SL_HAL_CAN_INIT_DEFAULT                             \
  (sl_hal_can_init_params_t){                               \
    .fd_enable = SL_HAL_CAN_FD,                             \
    .brs_enable = SL_HAL_CAN_BRS_OFF,                       \
    .auto_retransmission = 1,                               \
    .transmit_pause = 0,                                    \
    .protocol_exception = 0,                                \
    .tx_fifo_queue_mode = SL_HAL_CAN_TX_OPERATION_FIFO,     \
    .mode = SL_HAL_CAN_OPERATION_MODE_INTERNAL_LOOPBACK,    \
    .mram_init_params = SL_HAL_CAN_MRAM_INIT,               \
    .nominal_bitrate = SL_HAL_CAN_NOMINAL_TIME(0, 0, 0, 0), \
    .data_bitrate = SL_HAL_CAN_DATA_TIME(0, 0, 0, 0)        \
  }

/// Default configuration for standard id's reception filter.
#define SL_HAL_CAN_STD_ID_FILTER_CONFIG_DEFAULT                                                     \
  (sl_hal_can_filter_t) {                                                                           \
    .id_type          = SL_HAL_CAN_ID_STANDARD,        /* The identifier type */                    \
    .filter_index     = (uint32_t)0,                   /* [0 to 0x7FF] for Standard ID  */          \
    .filter_type      = SL_HAL_CAN_FILTER_RANGE,       /* The filter type */                        \
    .filter_config    = (SL_HAL_CAN_FILTER_TO_RXFIFO0),/* The filter configuration */               \
    .filter_id_one    = (uint32_t)0x0,                 /* The filter identification 1 [0 to 7FF] */ \
    .filter_id_two    = (uint32_t)0x7FF,               /* The filter identification 1 [0 to 7FF] */ \
    .rx_buffer_index  = 0                              /* Contains the index of the Rx buffer    */ \
  }

/// Default configuration for extended id's reception filter.
#define SL_HAL_CAN_EXD_ID_FILTER_CONFIG_DEFAULT                                                      \
  (sl_hal_can_filter_t) {                                                                            \
    .id_type          = SL_HAL_CAN_ID_EXTENDED,        /* The identifier type */                     \
    .filter_index     = (uint32_t)0,                   /* [0 to 0x1FFFFFFF] for Extended ID  */      \
    .filter_type      = SL_HAL_CAN_FILTER_RANGE,       /* The filter type */                         \
    .filter_config    = (SL_HAL_CAN_FILTER_TO_RXFIFO1),/* The filter configuration */                \
    .filter_id_one    = (uint32_t)0x0,                 /* The filter identification 1 [0 to 7FF] */  \
    .filter_id_two    = (uint32_t)0x1FFFFFFF,           /* The filter identification 1 [0 to 7FF] */ \
    .rx_buffer_index  = 0                              /* Contains the index of the Rx buffer    */  \
  }

/// Default configuration for classic CAN message header.
#define SL_HAL_CAN_MESSAGE_HEADER_DEFAULT \
  (sl_hal_can_tx_frame_object_t) {        \
    .identifier = 0x1,                              /* - 0 and 0x7FF, if id_type is STANDARD ID
                                                       - 0 and 0x1FFFFFFF, if id_type is EXTENDED ID */                               \
    .frame_type = SL_HAL_CAN_FRAME_DATA,            /* The frame type of the message that will be transmitted */                      \
    .id_type = SL_HAL_CAN_ID_STANDARD,              /* The identifier type for the message that will be transmitted */                \
    .error_state_indicator = SL_HAL_CAN_ESI_ACTIVE, /* The error state indicator */                                                   \
    .reserve1    = 0,                                                                                                                 \
    .data_length = 0x8,                             /* The length of the frame that will be transmitted */                            \
    .bit_rate_switch = SL_HAL_CAN_BRS_OFF,          /* whether the Tx frame will be transmitted with or without bit rate switching */ \
    .fd_format = SL_HAL_CAN_CLASSIC,                /* whether the Tx frame will be transmitted in classic or FD format */            \
    .reserve2    = 0,                                                                                                                 \
    .tx_event_fifo_control = SL_HAL_CAN_TX_EVENTS_NO_STORE, /* The event FIFO control */                                              \
    .message_marker = 0x52                                                                                                            \
  }

/// Default configuration for CANFD message header.
#define SL_HAL_CANFD_MESSAGE_HEADER_DEFAULT \
  (sl_hal_can_tx_frame_object_t) {          \
    .identifier = 0x1,                              /* - 0 and 0x7FF, if id_type is STANDARD ID
                                                       - 0 and 0x1FFFFFFF, if id_type is EXTENDED ID */                               \
    .frame_type = SL_HAL_CAN_FRAME_DATA,            /* The frame type of the message that will be transmitted */                      \
    .id_type = SL_HAL_CAN_ID_STANDARD,              /* The identifier type for the message that will be transmitted */                \
    .error_state_indicator = SL_HAL_CAN_ESI_ACTIVE, /* The error state indicator */                                                   \
    .reserve1    = 0,                                                                                                                 \
    .data_length = 0xF,                             /* The length of the frame that will be transmitted */                            \
    .bit_rate_switch = SL_HAL_CAN_BRS_OFF,          /* whether the Tx frame will be transmitted with or without bit rate switching */ \
    .fd_format = SL_HAL_CAN_FD,                     /* whether the Tx frame will be transmitted in classic or FD format */            \
    .reserve2    = 0,                                                                                                                 \
    .tx_event_fifo_control = SL_HAL_CAN_TX_EVENTS_NO_STORE, /* The event FIFO control */                                              \
    .message_marker = 0x52                                                                                                            \
  }

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/

/***************************************************************************//**
 * Initializes the CAN Device Peripheral.
 *
 * @param[in]  can       Pointer to the CAN peripheral register block.
 * @param[in]  init      A pointer to the initialization structure.
 * @return               On Success returns SL_STATUS_OK.
 *                       On Failure returns the respective error code.
 ******************************************************************************/
sl_status_t sl_hal_can_init(CAN_TypeDef *can,
                            const sl_hal_can_init_params_t *init);

/***************************************************************************//**
 * De-Initializes the CAN Device Peripheral.
 *
 * @param[in]  can       Pointer to the CAN peripheral register block.
 * @return               On Success returns SL_STATUS_OK.
 *                       On Failure returns the respective error code.
 ******************************************************************************/
sl_status_t sl_hal_can_deinit(CAN_TypeDef *can);

/***************************************************************************//**
 * Set Nominal and Data Bit Timing.
 *
 * @param[in]  can                      Pointer to the CAN peripheral register block.
 * @param[in]  nominal_bit_rate         Bit rate for arbitration phase
 * @param[in]  data_bit_rate            Bit rate for data phase
 * @return                              On Success returns SL_STATUS_OK.
 *                                      On Failure returns the respective error code.
 ******************************************************************************/
sl_status_t sl_hal_can_set_bit_rate(CAN_TypeDef *can,
                                    sl_hal_can_bit_timing_t nominal_bitrate,
                                    sl_hal_can_bit_timing_t data_bitrate
                                    );

/*****************************************************************************************************************//**
 * Configure the CAN reception filter according to the specified parameters in the sl_hal_can_Filter_t structure.
 *
 * @param[in]  can           Pointer to the CAN peripheral register block.
 * @param[in]  config_filter Pointer to an sl_hal_can_Filter_t structure that contains the filter configuration information
 * @return                   On Success returns SL_STATUS_OK.
 *                           On Failure returns the respective error code.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_configure_filter(CAN_TypeDef *can,
                                        const sl_hal_can_filter_t *config_filter);

/*****************************************************************************************************************//**
 * Remove the CAN reception filter.
 *
 * @param[in]  can       Pointer to the CAN peripheral register block.
 * @param[in]  id_type   Type of ID Standard or Extended.
 *                       SL_HAL_CAN_ID_STANDARD = 0x0
 *                       SL_HAL_CAN_ID_EXTENDED = 0x1
 * @param[in]  index     Value of filter index.
 *                       Standard ID : 0 to 128
 *                       Extended ID : 0 to 64
 * @return               On Success returns SL_STATUS_OK.
 *                       On Failure returns the respective error code.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_remove_rx_filter(CAN_TypeDef *can,
                                        uint8_t id_type,
                                        uint8_t index);

/*****************************************************************************************************************//**
 * Configure the Rx FIFO operation mode.
 *
 * @param[in]  can         Pointer to the CAN peripheral register block.
 * @param[in]  rx_fifo     Rx FIFO.
 *                         This parameter can be one of the following values:
 *                         Rx FIFO 0 or Rx FIFO 1
 * @param[in]  operation_mode operation mode.This parameter can be a value of
 *                          SL_HAL_CAN_RX_FIFO_BLOCKING  = 0x0
 *                          SL_HAL_CAN_RX_FIFO_OVERWRITE = 0x1
 * @return                 On Success returns SL_STATUS_OK.
 *                         On Failure returns the respective error code.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_config_rx_fifo_over_write(CAN_TypeDef *can,
                                                 sl_hal_can_rx_location_t rx_fifo,
                                                 uint8_t operation_mode);

/*****************************************************************************************************************//**
 * Configure the FIFO watermark.
 *
 * @param[in]  can         Pointer to the CAN peripheral register block.
 * @param[in]  fifo        Select the fifo to be configured.
 *                         This parameter can be a value of sl_hal_can_fifo_watermark_t type.
 * @param[in]  water_mark  Level for FIFO watermark interrupt.
 *                         This parameter must be a number between:
 *                         - 0 and 32, if FIFO is  SL_HAL_CAN_CFG_TX_EVENT_FIFO
 *                         - 0 and 16, if FIFO is SL_HAL_CAN_CFG_RX_FIFO0 or SL_HAL_CAN_CFG_RX_FIFO1
 * @return                 On Success returns SL_STATUS_OK.
 *                         On Failure returns the respective error code.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_config_fifo_water_mark(CAN_TypeDef *can,
                                              sl_hal_can_fifo_watermark_t fifo,
                                              uint8_t water_mark);

/*****************************************************************************************************************//**
 * Start the CAN module.
 *
 * @param[in]  can         Pointer to the CAN peripheral register block.
 ********************************************************************************************************************/
void sl_hal_can_start(CAN_TypeDef *can);

/*****************************************************************************************************************//**
 * Stop the CAN module and enable access to configuration registers.
 *
 * @param[in]  can         Pointer to the CAN peripheral register block.
 ********************************************************************************************************************/
void sl_hal_can_stop(CAN_TypeDef *can);

/*****************************************************************************************************************//**
 * Add a message to the Tx FIFO/Queue and activate the corresponding transmission request.
 *
 * @param[in]  can         Pointer to the CAN peripheral register block.
 * @param[in]  p_tx_object Pointer to a  sl_hal_can_tx_frame_object_t structure.
 * @param[in]  p_tx_data   Pointer to a buffer containing the payload of the Tx frame.
 * @return                 On Success returns SL_STATUS_OK.
 *                         On Failure returns the respective error code.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_add_message_to_tx_fifo(CAN_TypeDef *can,
                                              sl_hal_can_tx_frame_object_t *p_tx_object,
                                              const uint8_t *p_tx_data);

/*****************************************************************************************************************//**
 * Add a message to a dedicated Tx buffer.
 *
 * @param[in]  can          Pointer to the CAN peripheral register block.
 * @param[in]  p_tx_object  Pointer to a sl_hal_can_tx_frame_object_t structure.
 * @param[in]  p_tx_data    Pointer to a buffer containing the payload of the Tx frame.
 * @param[in]  buffer_index The index of the transmit buffer must be less than TX_BUFFER_ELEMENTS_NUMBER.
 * @return                  On Success returns SL_STATUS_OK.
 *                          On Failure returns the respective error code.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_add_message_to_tx_buffer(CAN_TypeDef *can,
                                                sl_hal_can_tx_frame_object_t *p_tx_object,
                                                const uint8_t *p_tx_data,
                                                uint8_t buffer_index);

/*****************************************************************************************************************//**
 * Cancel a Tx buffer transmission request.
 *
 * @param[in]  can          Pointer to the CAN peripheral register block.
 * @param[in]  buffer_index Request for cancel a Tx message in buffer.
 *                          This parameter can be any combination of  Tx location.
 * @return                  On Success returns SL_STATUS_OK.
 *                          On Failure returns the respective error code.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_request_abort_tx(CAN_TypeDef *can,
                                        uint32_t buffer_index);

/*****************************************************************************************************************//**
 * Get an CAN frame from the Rx Buffer/FIFO location.
 *
 * @param[in]  can         Pointer to the CAN peripheral register block.
 * @param[in]  rx_location Location of the received message to be read.
 * @param[in]  buffer_index Location of the received message within the RX dedicated buffers.
 *                         This must be configured when rx_location is set to SL_HAL_CAN_RX_BUFFER; otherwise, it should be zero.
 * @param[out] p_rx_object Pointer to a sl_hal_can_rx_frame_object_t structure.
 * @param[out] p_rx_data   Pointer to a buffer where the payload of the Rx frame will be stored.
 * @return                 On Success returns SL_STATUS_OK.
 *                         On Failure returns the respective error code.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_get_rx_message(CAN_TypeDef *can,
                                      sl_hal_can_rx_location_t rx_location,
                                      uint8_t buffer_index,
                                      sl_hal_can_rx_frame_object_t *p_rx_object,
                                      uint8_t *p_rx_data);

/*****************************************************************************************************************//**
 * Get an CAN Tx event from the Tx Event FIFO zone into the message RAM.
 *
 * @param[in]  can         Pointer to the CAN peripheral register block.
 * @param[out] p_tx_event  Pointer to a sl_hal_can_tx_event_object_t structure.
 * @return                 On Success returns SL_STATUS_OK.
 *                         On Failure returns the respective error code.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_get_tx_event(CAN_TypeDef *can,
                                    sl_hal_can_tx_event_object_t *p_tx_event);

/*****************************************************************************************************************//**
 * Get high priority message status.
 *
 * @param[in]  can               Pointer to the CAN peripheral register block.
 * @param[out] hp_msg_status     Pointer to an CAN_HpMsgStatusTypeDef structure.
 ********************************************************************************************************************/
void sl_hal_can_get_hpm_status(CAN_TypeDef *can,
                               sl_hal_can_hpm_status_t *hpm_msg_status);

/*****************************************************************************************************************//**
 * Get protocol status.
 *
 * @param[in] can                Pointer to the CAN peripheral register block.
 * @param[out] protocol_status   Pointer to an sl_hal_can_protocol_status_t structure.
 ********************************************************************************************************************/
void sl_hal_can_get_protocol_status(CAN_TypeDef *can,
                                    sl_hal_can_protocol_status_t *protocol_status);

/*****************************************************************************************************************//**
 * Enable interrupts.
 *
 * @param[in] can               Pointer to the CAN peripheral register block.
 * @param[in] flag              Indicates which interrupts will be enabled.
 *                              This parameter can be any combination of CAN Interrupts.
 * @param[in] interrupt_line    Indicates which interrupt line will be used.
 ********************************************************************************************************************/
void sl_hal_can_enable_interrupts(CAN_TypeDef *can,
                                  uint32_t flag,
                                  uint32_t interrupt_line);

/*****************************************************************************************************************//**
 * Disable interrupts.
 *
 * @param[in] can          Pointer to the CAN peripheral register block.
 * @param[in] flag  Indicates which interrupts will be disabled.
 *                         This parameter can be any combination of CAN Interrupts.
 ********************************************************************************************************************/
void sl_hal_can_disable_interrupts(CAN_TypeDef *can,
                                   uint32_t flag);

/*****************************************************************************************************************//**
 * Enable the timeout counter.
 *
 * @param[in] can                  Pointer to the CAN peripheral register block.
 * @param[in] timeout_operation    Timeout counter operation and value of sl_hal_can_timeout_operation_t.
 * @param[in] time_out_period      Start value of the timeout down-counter.
 *                                 This parameter must be a number between 0x0000 and 0xFFFF
 * @param[in] time_stamp_prescaler Timestamp Counter Prescaler value is [0 to 15].
 ********************************************************************************************************************/
sl_status_t sl_hal_can_enable_timeout_counter(CAN_TypeDef *can,
                                              sl_hal_can_timeout_operation_t timeout_operation,
                                              uint32_t timeout_period,
                                              uint8_t time_stamp_prescaler);

/*****************************************************************************************************************//**
 * Enable interrupts.
 *
 * @param[in] can          Pointer to the CAN peripheral register block.
 * @param[in] flag         Indicates which interrupts will be enabled.
 *                         This parameter can be any combination of CAN Interrupts.
 ********************************************************************************************************************/
void sl_hal_can_enable_dmu_interrupts(CAN_TypeDef *can,
                                      uint32_t flag);

/*****************************************************************************************************************//**
 * Disable interrupts.
 *
 * @param[in] can          Pointer to the CAN peripheral register block.
 * @param[in] flag         Indicates which interrupts will be disabled.
 *                         This parameter can be any combination of CAN Interrupts.
 ********************************************************************************************************************/
void sl_hal_can_disable_dmu_interrupts(CAN_TypeDef *can,
                                       uint32_t flag);

/*****************************************************************************************************************//**
 * The DMU supports the transfer of TSU timestamps via DMU Virtual Buffer.
 *
 * @param[in] can          Pointer to the CAN peripheral register block.
 * @param[in] value        Indicates DMU time support .
                           0 = No time stamp will be transferred via DMU Virtual Buffer
                           1 = Timestamp of message will be transferred from TSU via DMU virtual buffer
 * @return                 On Success returns SL_STATUS_OK.
 *                         On Failure returns the respective error code.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_enable_dmu_timestamp(CAN_TypeDef *can,
                                            bool value);

/*****************************************************************************************************************//**
 * Get the every queueing count value for each DMU element separately.
 *
 * @param[in]  can                  Pointer to the CAN peripheral register block.
 * @param[out] dmu_tx_counter       it gets the dmu tx event dequeueing counters value for each element.
 * @param[out] dmu_rx0_counter      it gets the dmu rx0 dequeueing counters value for each element.
 * @param[out] dmu_rx1_counter      it gets the dmu rx1 dequeueing counters value for each element.
 * @param[out] dmu_tx_event_counter it gets the dmu tx enqueueing counters value for each element.
 * @return                          On Success returns SL_STATUS_OK.
 *                                  On Failure returns the respective error code.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_get_dmu_queueing_counter(CAN_TypeDef *can,
                                                uint8_t *dmu_tx_counter,
                                                uint8_t *dmu_rx0_counter,
                                                uint8_t *dmu_rx1_counter,
                                                uint8_t *dmu_tx_event_counter);

/*****************************************************************************************************************//**
 * Define the DMU element services used for debugging.
 *
 * @param[in] can     Pointer to the CAN peripheral register block.
 * @param[in] value   indicates the detect DMU element service.
 *                    0 = queueing of DMU element does not activate interrupt flag
 *                    1 = queueing of DMU element will activate interrupt flag
 * @param[in] element indicates which the DMU Element Services used debugging.
 * @return            On Success returns SL_STATUS_OK.
 *                    On Failure returns the respective error code.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_configure_dmu_element_service(CAN_TypeDef *can,
                                                     bool value,
                                                     sl_hal_can_dmu_element_service_t element);

/*****************************************************************************************************************//**
 *  Configure the DMU element handler state for debugging.
 *
 * @param[in] can   Pointer to the CAN peripheral register block.
 * @param[in] value configure the DMU element handler state.
 * @return          On Success returns SL_STATUS_OK.
 *                  On Failure returns the respective error code.
 ********************************************************************************************************************/
sl_status_t sl_hal_can_configure_dmu_handler_state(CAN_TypeDef *can,
                                                   sl_hal_can_dmu_handler_state_t value);

/*****************************************************************************************************************//**
 * Requesting CAN power down mode.
 *
 * @param[in] can     Pointer to the CAN peripheral register block.
 ********************************************************************************************************************/
__INLINE void sl_hal_can_enter_power_down_mode(CAN_TypeDef *can)
{
  // Init structure must be provided.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Requesting clock stop CAN module.
  can->CCCR |= CAN_CCCR_CSR;

  while ((can->CCCR & CAN_CCCR_CSA) == 0) ;
}

/*****************************************************************************************************************//**
 * Exit CAN power down mode.
 *
 * @param[in] can    Pointer to the CAN peripheral register block.
 ********************************************************************************************************************/
__INLINE void sl_hal_can_exit_power_down_mode(CAN_TypeDef *can)
{
  // Init structure must be provided.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Requesting clock for CAN module.
  can->CCCR &= ~CAN_CCCR_CSR;

  while ((can->CCCR & CAN_CCCR_CSA) == CAN_CCCR_CSA) ;
}

/*****************************************************************************************************************//**
 * Configure the CAN global filter.
 *
 * @param[in] can               Pointer to the CAN peripheral register block.
 * @param[in] non_matching_std  defines how received messages with 11-bit IDs that do not match any element
 *                              of the filter list are treated and value is sl_hal_can_non_matching_frames_t type.
 * @param[in] non_matching_ext  defines how received messages with 29-bit IDs that do not match any element
 *                              of the filter list are treated and value is sl_hal_can_non_matching_frames_t type.
 * @param[in] reject_remote_std reject all the remote 11-bit IDs frames and value is sl_hal_can_reject_remote_frames_t type.
 *                              SL_HAL_CAN_REMOTE_FRAME_ACCEPT = 0x0,  Filter remote frames
 *                              SL_HAL_CAN_REMOTE_FRAME_REJECT = 0x1  Reject all remote frames
 * @param[in] reject_remote_ext reject all the remote 29-bit IDs frames and value is sl_hal_can_reject_remote_frames_t type.
 *                              SL_HAL_CAN_REMOTE_FRAME_ACCEPT = 0x0,  Filter remote frames
 *                              SL_HAL_CAN_REMOTE_FRAME_REJECT = 0x1  Reject all remote frames
 ********************************************************************************************************************/
__INLINE void sl_hal_can_config_global_filter(CAN_TypeDef *can,
                                              sl_hal_can_non_matching_frames_t non_matching_std,
                                              sl_hal_can_non_matching_frames_t non_matching_ext,
                                              bool reject_remote_std,
                                              bool reject_remote_ext)

{
  // Init structure must be provided.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Configure global filter.
  can->GFC = ((non_matching_std << _CAN_GFC_ANFS_SHIFT)
              | (non_matching_ext << _CAN_GFC_ANFE_SHIFT)
              | (reject_remote_std << _CAN_GFC_RRFS_SHIFT)
              | (reject_remote_ext << _CAN_GFC_RRFE_SHIFT));
}

/*****************************************************************************************************************//**
 * Configure the extended ID mask.
 *
 * @param[in] can          Pointer to the CAN peripheral register block.
 * @param[in] mask         mask the Extended ID Mask. This parameter must be a number between 0 and 0x1FFFFFFF
 ********************************************************************************************************************/
__INLINE void sl_hal_can_config_extended_id_mask(CAN_TypeDef *can,
                                                 uint32_t mask)
{
  // Init structure must be provided.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Configure the extended ID mask.
  can->XIDAM = mask;
}

/*****************************************************************************************************************//**
 * Enable the timestamp counter.
 *
 * @param[in] can                  Pointer to the CAN peripheral register block.
 * @param[in] time_stamp_operation Timestamp counter operation value of :
 *                                 SL_HAL_CAN_TIMESTAMP_INTERNAL = 0x1,
 *                                 SL_HAL_CAN_TIMESTAMP_EXTERNAL = 0x2
 * @param[in] time_stamp_prescaler Timestamp Counter Prescaler value is [0 to 15].
 ********************************************************************************************************************/
__INLINE void sl_hal_can_enable_timestamp_counter(CAN_TypeDef *can,
                                                  uint8_t time_stamp_operation,
                                                  uint8_t time_stamp_prescaler)
{
  // Init structure must be provided.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);
  SL_LOG_DEBUG_ASSERT((time_stamp_operation == SL_HAL_CAN_TIMESTAMP_INTERNAL) || (time_stamp_operation == SL_HAL_CAN_TIMESTAMP_EXTERNAL));
  SL_LOG_DEBUG_ASSERT(time_stamp_prescaler <= 15U);

  // Enable timestamp counter.
  can->TSCC &= ~((_CAN_TSCC_TSS_MASK) | (_CAN_TSCC_TCP_MASK));
  can->TSCC = (time_stamp_operation | (time_stamp_prescaler << _CAN_TSCC_TCP_SHIFT));
}

/*****************************************************************************************************************//**
 * Disable the timestamp counter.
 *
 * @param[in] can   Pointer to the CAN peripheral register block.
 ********************************************************************************************************************/
__INLINE void sl_hal_can_disable_timestamp_counter(CAN_TypeDef *can)
{
  // Init structure must be provided.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Disable timestamp counter.
  can->TSCC &= ~_CAN_TSCC_TSS_MASK;
}

/*****************************************************************************************************************//**
 * Disable the timeout counter.
 *
 * @param[in]   can   Pointer to the CAN peripheral register block.
 ********************************************************************************************************************/
__INLINE void sl_hal_can_disable_timeout_counter(CAN_TypeDef *can)
{
  // Init structure must be provided.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Disable timeout counter.
  can->TOCC &= ~CAN_TOCC_ETOC;
}

/*****************************************************************************************************************//**
 * Check if a new message is received in the selected Rx buffer.
 *
 * @param[in]   can             Pointer to the CAN peripheral register block.
 * @param[in]  rx_buffer_index Rx buffer index. This parameter must be a number between 0 and 63.
 * @return                      - false : No new message on rx_buffer_index.
 *                              - true : New message received on rx_buffer_index.
 ********************************************************************************************************************/
__INLINE bool sl_hal_can_is_rx_buffer_messages_available(CAN_TypeDef *can,
                                                         uint8_t rx_buffer_index)
{
  // Init structure must be provided.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  // Check function parameters.
  SL_LOG_DEBUG_ASSERT(rx_buffer_index <= 63U);
  uint32_t NewData1 = can->NDAT1;
  uint32_t NewData2 = can->NDAT2;

  // Check new message reception on the selected buffer.
  if (((rx_buffer_index < 32U) && ((NewData1 & (uint32_t)((uint32_t)1 << rx_buffer_index)) == 0U))
      || ((rx_buffer_index >= 32U) && ((NewData2 & (uint32_t)((uint32_t)1 << (rx_buffer_index & 0x1FU))) == 0U))) {
    return false;
  }

  return true;
}

/*****************************************************************************************************************//**
 * Return Rx FIFO fill level.
 *
 * @param[in]        can      Pointer to the CAN peripheral register block.
 * @param[in]        rx_fifo  This parameter can be one of the following values:
 *                            Rx FIFO 0 and Rx FIFO 1
 * @return                    Level Rx FIFO fill level.
 ********************************************************************************************************************/
__INLINE uint32_t sl_hal_can_get_rx_fifo_fill_level(CAN_TypeDef *can,
                                                    sl_hal_can_rx_location_t rx_fifo)
{
  // Init structure must be provided.
  SL_LOG_DEBUG_ASSERT(CAN_NUM(can) != -1);

  if (rx_fifo == SL_HAL_CAN_RX_FIFO0) {
    return (can->RXF0S & _CAN_RXF0S_F0FL_MASK);
  } else if (rx_fifo == SL_HAL_CAN_RX_FIFO1) {
    return (can->RXF1S & _CAN_RXF1S_F1FL_MASK);
  } else {
    return 0;
  }
}

#ifdef __cplusplus
}
#endif

#endif // CAN_PRESENT
#endif // SL_HAL_CAN_H
