# The configure_file function has two arguments: input and output
# It will generate a new header file using the input file and internal CMake variables
# CMAKE_BINARY_DIR is a path to the build folder, as managed by CMake
configure_file (
  "config.h.in"
  "${CMAKE_BINARY_DIR}/configured_files/include/config.h" ESCAPE_QUOTES
)