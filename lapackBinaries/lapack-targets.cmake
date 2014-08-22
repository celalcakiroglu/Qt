# Generated by CMake 2.8.11

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget blas lapack tmglib)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target blas
add_library(blas SHARED IMPORTED)

# Create imported target lapack
add_library(lapack SHARED IMPORTED)

# Create imported target tmglib
add_library(tmglib SHARED IMPORTED)

# Import target "blas" for configuration ""
set_property(TARGET blas APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(blas PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "E:/Program Files/Work/created by me/QT/lapackBinaries/lib/libblas.dll.a"
  IMPORTED_LOCATION_NOCONFIG "E:/Program Files/Work/created by me/QT/lapackBinaries/bin/libblas.dll"
  )

# Import target "lapack" for configuration ""
set_property(TARGET lapack APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(lapack PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "E:/Program Files/Work/created by me/QT/lapackBinaries/lib/liblapack.dll.a"
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "blas"
  IMPORTED_LOCATION_NOCONFIG "E:/Program Files/Work/created by me/QT/lapackBinaries/bin/liblapack.dll"
  )

# Import target "tmglib" for configuration ""
set_property(TARGET tmglib APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(tmglib PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "E:/Program Files/Work/created by me/QT/lapackBinaries/lib/libtmglib.dll.a"
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "lapack"
  IMPORTED_LOCATION_NOCONFIG "E:/Program Files/Work/created by me/QT/lapackBinaries/bin/libtmglib.dll"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
