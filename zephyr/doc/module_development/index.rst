.. _zephyr_oot_module_development:

Module Development
##################

.. note::

   In this document, we'll assume the following

     - your **application directory** is :file:`<home>/<workspace>/oot_module_example/zephyr/apps/app`
     - its **zephyr directory** is :file:`<home>/<workspace>/zephyr`
     - its **build directory** is :file:`<home>/<workspace>/build`.
     - with the **build output** placed in :file:`<home>/<workspace>/build/<app_pathname>/<board>`

   (These terms are defined in the following Overview.)
   On Linux/macOS, <home> is equivalent to ``~``, whereas on Windows it's
   ``%userprofile%``.

Overview
********

Zephyr's build system is based on `CMake`_.

The build system is application-centric, and requires Zephyr-based applications
to initiate building the kernel source tree. The application build controls
the configuration and build process of both the application and Zephyr itself,
compiling them into a single binary.

Zephyr's base directory hosts Zephyr's build tools, own source code, and
its kernel configuration options. The Zephyr build process discovers
Zephyr modules through the build system variables :makevar:`ZEPHYR_MODULES`
and :makevar:`ZEPHYR_EXTRA_MODULES`, with the directory trees qualified
and described by the :file:`zephyr/module.yaml`.

.. note::
  Although alternate criteria has been used to qualify a
  directory tree as a Zephyr module, the presence of a valid
  :file:`zephyr/module.yaml` file is strongly recommended.

Modules necessary for providing and verifying primary RTOS
functionality on reference architectures, SOCs, and boards have
their "glue code" and configuration files in the :file:`modules/`
directory of the Zephyr repository. This includes Hardware Abstraction
Layer (:file:`hal_*.git`) and cryptographic modules.

Modules providing extended functionality (e.g. boards, drivers,
subsystems, applications) may also be included in the Zephyr
build. These modules necessarily have their licensing, configuration,
test, and documentation files and "glue code" outside of the
Zephyr repository (and usually in the module itself).
These extension module repositories may be provided outside of the
Zephyr Project.


.. _source_tree_v2:

Source Tree Structure
*********************

`Fundamental Theorem of Software Engineering`_

  "We can solve any problem by introducing an extra level of indirection."
  -- David J. Wheeler

Understanding the Zephyr OOT module OMX source tree can be helpful in
locating the code associated with a particular module feature. This is
especially important when extending an existing external repository.

Extending existing repositories is largely enabled by locating
Zephyr build system interface files beneath :file:`<repository-root>/zephyr`
following the directory tree of the Zephyr repository. These files
include configuration, build, test and sample discovery,
and documentation.

Example of an extensive folder and file structure for
Zephyr out-of-tree module extensions:

.. code-block:: none

   <module-root (i.e. repository-root)>
   ├── ...                   # Existing repository file and folder structure
   ├── .gitignore            # Ammended to exclude Zephyr-built files
   └── zephyr                # For Zephyr build/ci interface files and ??
       ├── .gitignore
       ├── CMakeLists.txt
       ├── Kconfig
       ├── Makefile
       ├── module.yml
       ├── README.rst
       ├── VERSION
       ├── west.yml
       ├── ...
       ├── apps
       ├── boards
       ├── cmake
       ├── doc
       ├── drivers
       ├── dts
       ├── include
       │   └── <module-abbrev>
       ├── manifests
       │   └── zp
       │       └── <zephyr-tag>
       │           └── west.yml
       ├── samples
       ├── scripts
       ├── subsys
       └── tests


At the top of the module tree there is only file and one directory that
are of importance:

:file:`.gitignore`
    The top-level file for controlling which files and file types are
    automatically excluded from being committed to the Git repository.
    This needs to include settings to ignore files built by Zephyr.

:file:`zephyr`
    The top-level directory required for Zephyr module discovery.


In the :file:`<module-root>/zephyr` directory there are several files that are of importance:

:file:`.gitignore`
    The module-interface-level file for controlling which files and
    file types are automatically excluded from being committed to the
    Git repository. This should include all settings in .gitignore of Zephyr.

:file:`CMakeLists.txt`
    The module-level file for the Zephyr build system.

:file:`Kconfig`
    The module-level Kconfig file.

:file:`Makefile`
    The module-level file for the Zephyr document generation system

:file:`module.yml`
    The module-level file used by the build system for module
    description to the build discovery system.

:file:`README.rst`
    The module-level documentation file (also processed by the
    document generation system).

:file:`west.yml`
    The ``west`` manifest for developing and verifying this module
    against the latest integrated and verified Zephyr reference.
    This may simply import alternate manifest files located elsewhere
    in this module.

:file:`VERSION`
    The version description used by the module build files.

The :file:`<module-root>/zephyr` tree also contains the following optional
directories, each of which may have one or more additional levels of
subdirectories which are not described here.

:file:`apps`
    Product application configurations and code.

:file:`boards`
    Board related code and configuration files provided by this module.

:file:`cmake`
    Additional or alternate build scripts needed to build this module.

:file:`doc`
    Module-specific Zephyr technical documentation source files and tools
    used to generate the module web content.

:file:`drivers`
    Device driver code.

:file:`dts`
    devicetree source files used to describe non-discoverable
    board-specific hardware details.

:file:`include/<module-abbrev>`
    Include files for all public APIs provided by this module.

:file:`manifests`
    Alternate and supplimentary manfifests. These may be used to support
    alternate configurations due to:

    - multiple versions of west projects (e.g. -rc1 vs -rc2)
    - multiple branches in west projects (e.g. latest release, LTS release)
    - forking of west projects (e.g. clone & locally fix bug quickly)

:file:`samples`
    Sample Zephyr applications that demonstrate the use of the
    module's features.

:file:`scripts`
    Various programs and other files used to build and test module
    applications.

:file:`subsys`
    Subsystems provided by this module, including:

    - communication protocol stacks
    - integratable services.

:file:`tests`
    Test code and benchmarks for module features.


Extending a Repository to be a Zephyr OOT Module
************************************************

Follow these steps to extend an existing codebase repository to be a
Zephyr OOT module.

#. Clone the Zephyr OOT module example into the new workspace.

   For example, in a Unix shell enter:

   .. code-block:: console

      cd ~
      git clone https://github.com/zephyrproject-rtos/oot_module_example

#. Extend the top-level .gitignore file of your repository with the rules
   in :file:`oot_module_example/.gitignore`.  These rules are to prevent
   committing any files derived by the Zephyr build system.

   For example, in a Unix shell enter:

   .. code-block:: console

      cd my_existing_repository
      cat ~/oot_module_example/.gitignore >> .gitignore
      
#. Copy the :file:`oot_module_example/zephyr` tree into your existing
   repository.

   For example, in a Unix shell enter:

   .. code-block:: console

      cd my_existing_repository
      cp -r ~/oot_module_example/zephyr .

#. Replace all usages of the reference module name and abbreviation with
   the name and abbreviation for the new module.  This includes in pathnames
   and file contents (including documentation and hidden files).


Verifying Zephyr OOT Modules
============================

Zephyr OOT modules must describe the environment and dependencies needed
to develop and verify all module functionality.  Zephyr OOT modules also
should be designed to be reused by other Zephyr OOT modules or applications.
This means:

  - Zephyr OOT Modules should support using Zephyr development and CI
    tools such as :file:`west` and :file:`sanitycheck`.

  - Zephyr OOT Modules documentation should parallel the Zephyr kernel
    documentation structure, patterns, and style.

  - Zephyr OOT Module code should be designed to co-exist with an arbitrary
    set of other OOT modules.

  - Zephyr OOT Modules should contain test suites to fully verify all
    provided functionality.

The points above allow any module to be verified using the following steps:

#. Test that the module is detected

   .. code-block: console

   west build -p always -b native_posix -t menuconfig zephyr/samples/hello_world

   Verify the module appears beneath the Modules section, and is not selected.


#. Verify the system builds cleanly when the module is not selected.

   .. code-block: console

   zephyr/scripts/sanitycheck -p native_posix -T zephyr/samples/hello_world

   Verify all test cases pass.


#. Verify the system builds cleanly when the module is selected with the
   default configuration.

   .. code-block: console

   zephyr/scripts/sanitycheck -p native_posix -T oot_module_example/zephyr/samples/module_hello

   Verify all test cases pass.


#. Verify the all module functionality.

   .. code-block: console

   zephyr/scripts/sanitycheck -p native_posix -T oot_module_example/zephyr/

   Verify all test cases pass.


.. _CMake: https://www.cmake.org
.. _Fundamental Theorem of Software Engineering: https://en.wikipedia.org/wiki/Fundamental_theorem_of_software_engineering
