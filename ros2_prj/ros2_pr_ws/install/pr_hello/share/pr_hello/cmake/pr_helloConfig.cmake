# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_pr_hello_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED pr_hello_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(pr_hello_FOUND FALSE)
  elseif(NOT pr_hello_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(pr_hello_FOUND FALSE)
  endif()
  return()
endif()
set(_pr_hello_CONFIG_INCLUDED TRUE)

# output package information
if(NOT pr_hello_FIND_QUIETLY)
  message(STATUS "Found pr_hello: 0.0.0 (${pr_hello_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'pr_hello' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT pr_hello_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(pr_hello_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${pr_hello_DIR}/${_extra}")
endforeach()
