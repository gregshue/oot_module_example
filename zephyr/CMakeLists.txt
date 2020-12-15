cmake_minimum_required(VERSION 3.10 FATAL_ERROR)


# Detect the platform reliably
if(ZEPHYR_BASE)
  if (NOT CONFIG_OMX)
    return()
  endif()
  set(ZEPHYR YES)
else()
  message(FATAL_ERROR "ZEPHYR_BASE needs to be defined for Zephyr builds")
endif()

#Do not allow in source builds
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

get_filename_component(MODULE_NAME ${ZEPHYR_CURRENT_MODULE_DIR} NAME)
add_definitions(
  -DMODULE_NAME="${MODULE_NAME}"
  )


#
# Module options managed through Kconfig and use names CONFIG_*
#



#
# sources
#

zephyr_include_directories(include)

add_subdirectory(subsys)


#
# library
#

#zephyr_library()
#
#zephyr_library_compile_definitions(
#  )
#
#zephyr_library_sources(
#  )
#
#zephyr_include_directories(
#  )
#
#target_compile_definitions(
#  app PRIVATE
#  )
