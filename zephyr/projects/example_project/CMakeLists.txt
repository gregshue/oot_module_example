# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

# Extract module name and path

string(REGEX REPLACE
  "/zephyr/samples/[a-zA-Z_/-]*$" ""
  MODULE_NAME
  ${CMAKE_CURRENT_SOURCE_DIR})
get_filename_component(MODULE_NAME ${MODULE_NAME} NAME)
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(${PROJECT_NAME})

target_sources(app PRIVATE src/main.c)

add_definitions(-DPROJECT_NAME="${PROJECT_NAME}")
