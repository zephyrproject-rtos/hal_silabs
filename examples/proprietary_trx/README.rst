Proprietary TRX
###############

Overview
********

The Proprietary TRX example demonstrates the simplest exchange of transmit and
receive operation between two nodes implemented in RAIL.

This application can be used for setting up a simple link test, where the nodes
are listening except for the short periods where packet transmission takes
place. Also, this application can be used as a learning material.

Requirements
************

This application requires part or board that support RAIL, has radio antenna 
connection and has at least one LED and one button.

Building and Running
********************

This sample can be built for multiple boards, in this example we will build it
for the efr32bg22_brd4184a board:

.. code-block:: bash

    west build -p always -b efr32bg22_brd4184a


This example implements both the receiver (RX) and the transmitter (TX) nodes.
The implementation is therefore symmetric, as both nodes are capable of sending
and receiving messages. In this document the use of `RX node` and `TX node` are
implicit and these terms refer the devices temporary, while the denoted
operations are performed.

Compile the project and download the application to two radio boards.

On startup the Zephyr boot will be displayed, with additional information
about the RAIL library version. 

The devices start in the receiving state.

Issue the `send` command on the TX node to request packet transmission:

.. code-block:: bash

    send
    > Send packet request

Additional logs can be viewed by the logger, which can be turned off.

On the receiver side the following response will be printed out on packet
reception:

.. code-block:: bash

    > Packet has been received: 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
                                0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 

Additional logs can be viewed by the logger, which can be turned off.

If the reception is enabled the device will automatically switch back to RX mode
either after a successful or faulty reception or a transmission.


The reception can be disabled by the `receive` command.

.. code-block:: bash

    receive 0
    > Continues packet receiving is OFF

Receive mode can be enabled again by the same command:

.. code-block:: bash

    receive 1
    > Continues packet receiving is ON


Peripherals
***********

Same working can be achieved by pushing button or buttons and waiting for the 
led or LEDs to toggle.

Radio settings
**************

For changing any settings for the used radio or radio phy please re-generate 
the rail_config.c and rail_config.h files use 
Simplicity Studio's `EFR32 Radio Configurator`_.

.. _EFR32 Radio Configurator: https://www.silabs.com/documents/public/application-notes/an1253-efr32-radio-configurator-guide-for-ssv5.pdf

Advance settings
****************

For advance user settings please use Simplicity Studio's slc generator, where
more settings can be generated for rail components. If new settings are ready,
they should be copied from Simplicity Studio config folder to `hal/silabs/gecko`
folder and overwrite their original file. For example after editing with slc
the RAIL Utility component user should copy `sl_rail_util_init_inst0_config.h``
to `gecko/platform/radio/rail_lib/plugin/rail_util_init/config/proprietary/``

Extra Resources
***************

- `RAIL Tutorial Series`_:
  it is advised to read through the `Studio v5 series` first to familiarize the
  basics of packet transmission and reception

.. _RAIL Tutorial Series: https://community.silabs.com/s/article/rail-tutorial-series?language=en_US
