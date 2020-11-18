.. _omx_module_example_project_doc:

OMX Module Example Project
##########################

Overview
********

A example of the simplest module project, using the module_hello service.

Building and Running
********************

This application can be built and executed on native POSIX as follows:

.. zephyr-app-commands::
   :zephyr-app: projects/example_project
   :host-os: unix
   :board: native_posix
   :goals: run
   :compact:

To build for another board, change "native_posix" above to that board's name.

Sample Output
=============

.. code-block:: console

    Hello from oot_module_example!

