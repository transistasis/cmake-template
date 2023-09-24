# Create an executable from project source code
add_executable ( Executable main.cpp )

# Link the library target to the executable target
# This means that Library is a dependency of Executable
# The link can either be PUBLIC, PRIVATE, or INTERFACE
target_link_libraries ( Executable PUBLIC Library )