# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_zpackage_ac_ser_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED zpackage_ac_ser_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(zpackage_ac_ser_FOUND FALSE)
  elseif(NOT zpackage_ac_ser_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(zpackage_ac_ser_FOUND FALSE)
  endif()
  return()
endif()
set(_zpackage_ac_ser_CONFIG_INCLUDED TRUE)

# output package information
if(NOT zpackage_ac_ser_FIND_QUIETLY)
  message(STATUS "Found zpackage_ac_ser: 0.0.0 (${zpackage_ac_ser_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'zpackage_ac_ser' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${zpackage_ac_ser_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(zpackage_ac_ser_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${zpackage_ac_ser_DIR}/${_extra}")
endforeach()
