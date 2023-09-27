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
set( CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include ( AddGitSubmodule )

# In order to use a Git submodule, it would need to be submoduled in external (in this case)
# If the cloned repository isn't a CMake project, it can be compiled like the library in src
# add_git_submodule( external/json )

# How to import a CMake-based library without using Git submodules
include( FetchContent )

# When using FetchContent_Declare, the target is the project name in the project's CMakeLists.txt
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.2
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG 10.1.1
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.12.0
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
    cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts
    GIT_TAG v3.1.1
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(cxxopts)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v3.4.0
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(Catch2)

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
