cmake_minimum_required( VERSION 3.22 )

project (
  CppProjectTemplate
  VERSION 1.0.0
  LANGUAGES C CXX )

# Add a library that can be used in the project
# A library can be STATIC, SHARED, or MODULE
add_library (
  Library
  STATIC
  my_library.cpp )

# Create an executable from project source code
add_executable (
  Executable
  main.cpp )

# Link the library target to the executable target
# This means that Library is a dependency of Executable
# The link can either be PUBLIC, PRIVATE, or INTERFACE
target_link_libraries(
  Executable
  PUBLIC
  Library )
