# Create lists of the source files needed to build the library
# Source file names can also be wrapped in quotes, if desired:
#   e.g. "my_library.cpp" instead of my_library.cpp
set ( LIBRARY_SOURCES
  my_library.cpp )

set ( LIBRARY_HEADERS 
  my_library.h )

# Add a library that can be used in the project
# A library can be STATIC, SHARED, or MODULE
# A specific library can be compiled by using the following command:
#   cmake --build . --target Library
add_library ( ${LIBRARY_NAME} STATIC 
  ${LIBRARY_SOURCES}
  ${LIBRARY_HEADERS} )

# Specify the location where relevent header files can be found
target_include_directories( ${LIBRARY_NAME} PUBLIC 
  "."
  ${CMAKE_BINARY_DIR}/configured_files/include )
