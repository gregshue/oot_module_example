.. raw:: html

   <a href="https://www.zephyrproject.org">
     <p align="center">
       <img src="https://github.com/zephyrproject-rtos/zephyr/blob/v1.14-branch/doc/images/Zephyr-Project.png">
     </p>
   </a>

   <a href="https://bestpractices.coreinfrastructure.org/projects/74"><img
   src="https://bestpractices.coreinfrastructure.org/projects/74/badge"></a>
   <a href="https://buildkite.com/zephyr/zephyr">
   <img
   src="https://badge.buildkite.com/f5bd0dc88306cee17c9b38e78d11bb74a6291e3f40e7d13f31.svg?branch=master"></a>


The Zephyr Project is a scalable real-time operating system (RTOS) supporting
multiple hardware architectures, optimized for resource constrained devices,
and built with security in mind.

The Zephyr module OMX (Out-of-tree Module eXample) is a reference
for how existing repositories may be extended into a well-integrated
Zephyr module.

..
  below included in doc/introduction/introduction.rst

.. start_include_here

Getting Started
***************

Welcome to Zephyr! See the `Introduction to Zephyr`_ for a high-level
overview, and the documentation's `Getting Started Guide`_ to start
developing.

The Zephyr module OMX is a compliant extension of the Zephyr Project
ecosystem. It is a manifest module repository. Development work is
supported in the same range of environments as the main Zephyr code
repository.

Checking Out Code
=================

The Zephyr module OMX may be cloned and added to the Zephyr build system
in exactly the same way as any other repository.

Follow this guide to:

- Get the source code with Zephyr module OMX as the :ref:`west <west>`
  manifest repository
- Build and run a sample application


Get Zephyr and install Python dependencies
------------------------------------------

Clone Zephyr module OMX and its dependencies into a new :ref:`west <west>`
workspace named :file:`zp`. You'll also install additional Python
dependencies.

.. tabs::

   .. group-tab:: Ubuntu

      #. Get the Zephyr source code:

         .. code-block:: bash

            west init \
              -m https://github.com/zephyrproject-rtos/oot_module_example \
              --mr zephyr \
              --mf zephyr/manifests/zp/zephyr-v2.4.0/west.yml \
              ~/zp
            cd ~/zp
            west update
            source zephyr/zephyr-env.sh

      #. Export a :ref:`Zephyr CMake packate <cmake_pkg>`. This allows CMake to
         automatically load boilerplate code required for building Zephyr
         applications.

         .. code-block:: console

            west zephyr-export

      #. Install additional Python dependencies specified by any module

         .. code-block:: bash
 
            pip3 install --user -r ~/zp/zephyr/scripts/requirements.txt
            pip3 install --user -r \
              ~/zp/oot_module_example/zephyr/scripts/requirements.txt

      #. Configure :ref:`west <west>` to place build output in 
         project-board-specific folders

         .. code-block:: bash

            west config \
              build.dir-fmt ${ZEPHYR_BASE}/../build/{source_dir}/{board}


Build and Run the OMX Module Hello Sample
-----------------------------------------

Build the :ref:`OMX module-hello sample <omx-module-hello-sample> with
:ref:`west build <west-building>`, changing ``<your-board-name>``
appropriately for your board:

.. tabs::

   .. group-tab:: Ubuntu

      #. Build the sample directly from the command line

         .. code-block:: bash

            west build -p auto -b native_posix \
              omx_module_example/zephyr/samples/module_hello

      #. (Flash and) Run the sample from the command line

         .. code-block:: bash

            ./build/omx_module_example/zephyr/samples/module_hello/native_posix/zephyr/zephyr.exe

      #. Build and run the sample using Zephyr's
         :ref:`sanitycheck script <sanitycheck_script>`

         .. code-block:: bash

            zephyr/scripts/sanitycheck -p native_posix \
              -T oot_module_example/zephyr/samples/module_hello

Once the build system integration is verified, a branch of the module
may be checked out and developed without impacting the other repository
clones.

Creating a New Module
=====================

This module is designed to be a boilerplate for other modules simply by:

- cloning

- renaming module names and abbreviations to reference your module:

  - 'Out-of-tree Module eXample'
  - 'OMX'
  - 'omx'

- stripping out any unnecessary content (e.g. no drivers or subsystems)


The following points should be kept in mind for any new module:

- Module infrastructure and interface to the Zephyr build system will
  evolve. Tracking and propagating those evolutions is important for
  ongoing support.

- Module code may be referenced by future modules, increasing the risk
  of name collisions for symbols in the module that do not share the
  same prefix.


Community Support
*****************

Community support is provided via mailing lists and Slack; see the Resources
below for details.

.. _project-resources:

Resources
*********

Here's a quick summary of resources to help you find your way around:

* **Help**: `Asking for Help Tips`_
* **Documentation**: http://docs.zephyrproject.org (`Getting Started Guide`_)
* **Source Code**: https://github.com/zephyrproject-rtos/zephyr is the main
  repository; https://elixir.bootlin.com/zephyr/latest/source contains a
  searchable index
* **Releases**: https://github.com/zephyrproject-rtos/zephyr/releases
* **Samples and example code**: see `Sample and Demo Code Examples`_
* **Mailing Lists**: users@lists.zephyrproject.org and
  devel@lists.zephyrproject.org are the main user and developer mailing lists,
  respectively. You can join the developer's list and search its archives at
  `Zephyr Development mailing list`_. The other `Zephyr mailing list
  subgroups`_ have their own archives and sign-up pages.
* **Nightly CI Build Status**: https://lists.zephyrproject.org/g/builds
  The builds@lists.zephyrproject.org mailing list archives the CI
  (shippable) nightly build results.
* **Chat**: Zephyr's Slack workspace is https://zephyrproject.slack.com.  Use
  this `Slack Invite`_ to register.
* **Contributing**: see the `Contribution Guide`_
* **Wiki**: `Zephyr GitHub wiki`_
* **Issues**: https://github.com/zephyrproject-rtos/zephyr/issues
* **Security Issues**: Email vulnerabilities@zephyrproject.org to report
  security issues; also see our `Security`_ documentation. Security issues are
  tracked separately at https://zephyrprojectsec.atlassian.net.
* **Zephyr Project Website**: https://zephyrproject.org

.. _Slack Invite: https://tinyurl.com/y5glwylp
.. _supported boards: http://docs.zephyrproject.org/latest/boards/index.html
.. _Zephyr Documentation: http://docs.zephyrproject.org
.. _Introduction to Zephyr: http://docs.zephyrproject.org/latest/introduction/index.html
.. _Getting Started Guide: http://docs.zephyrproject.org/latest/getting_started/index.html
.. _Contribution Guide: http://docs.zephyrproject.org/latest/contribute/index.html
.. _Zephyr GitHub wiki: https://github.com/zephyrproject-rtos/zephyr/wiki
.. _Zephyr Development mailing list: https://lists.zephyrproject.org/g/devel
.. _Zephyr mailing list subgroups: https://lists.zephyrproject.org/g/main/subgroups
.. _Sample and Demo Code Examples: http://docs.zephyrproject.org/latest/samples/index.html
.. _Security: http://docs.zephyrproject.org/latest/security/index.html
.. _Asking for Help Tips: https://docs.zephyrproject.org/latest/guides/getting-help.html
