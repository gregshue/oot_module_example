.. _omx_native_posix:

OMX Native POSIX execution (native_posix)
#########################################

.. contents::
   :depth: 1
   :backlinks: entry
   :local:

Overview
********

Documentation placeholder for OMX Native POSIX board

This board provides a few peripherals such as an Ethernet driver and UART.
See `Peripherals`_ for more information.

.. _omx_native_posix_deps:

Host system dependencies
========================


.. _omx_native_important_limitations:

Important limitations
*********************


Working around these limitations
================================



How to use it
*************

Compiling
=========

Specify the native_posix board target to build a native POSIX application:

.. zephyr-app-commands::
   :zephyr-app: samples/hello_world
   :host-os: unix
   :board: omx_native_posix
   :goals: build
   :compact:

Running
=======


Debugging
=========


Coverage reports
================


Architecture
************


Peripherals
***********

The following peripherals are currently provided with this board:


UART
****

This driver can be configured with

Subsystems backends
*******************

Apart from its own peripherals, the this board also has some dedicated
backends for some of Zephyr's subsystems. These backends are designed to ease
development by integrating more seamlessly with the host operating system:


Host based flash access
***********************

