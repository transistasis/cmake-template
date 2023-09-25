cmake_minimum_required ( VERSION 3.22 )

project ( CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX )

# Override CMake-specific variables
# Some other useful options are CMAKE_GENERATOR and CMAKE_BUILD_TYPE
set ( CMAKE_CXX_STANDARD          17 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_EXTENSIONS        OFF )

# Define user-defined variables
set ( LIBRARY_NAME    Library )
set ( EXECUTABLE_NAME Executable )

# This is how to integrate external libraries by using Git submodules
# NOTE: This external project needs to be a CMake project
set( CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include ( AddGitSubmodule )

add_git_submodule( external/json )

# Define CMake options
# Build options can be modified from the command line when building using the -D flag:
#   cmake .. -DCOMPILE_EXECUTABLE=OFF
option ( COMPILE_EXECUTABLE "Determines whether to compile the executable or not" ON )

# Specify which subdirectories CMake should scan for additional dependencies
add_subdirectory ( src )
add_subdirectory ( configured )
add_subdirectory ( external )

# Determine whether to process the app directory CMakeLists.txt file or not
if ( COMPILE_EXECUTABLE )
  message( "Building with the app directory..." )
  add_subdirectory ( app )
else ()
  message( "Excluding the app directory..." )
endif()
