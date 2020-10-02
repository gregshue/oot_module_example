# Copyright (c) 2020 Legrand North America, LLC.
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(include)

zephyr_interface_library_named(omx_module_hello)

zephyr_library()
zephyr_library_sources(hello.c)

zephyr_library_link_libraries(omx_module_hello)

