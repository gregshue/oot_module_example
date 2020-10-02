.. _omx_module_hello:

OMX Module Hello
################

Overview
********

A simple sample that prints "Hello from <module>" to the console.

Building and Running
********************

This application can be built and executed on native POSIX as follows:

.. zephyr-app-commands::
   :zephyr-app: samples/module_hello
   :host-os: unix
   :board: native_posix
   :goals: run
   :compact:

To build for another board, change "native_posix" above to that board's name.

Sample Output
=============

.. code-block:: console

    Hello from oot_module_example!

