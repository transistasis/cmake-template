# Create an executable from project source code
add_executable ( ${EXECUTABLE_NAME} main.cpp )

# Link the library target to the executable target
# This means that Library is a dependency of Executable
# The link can either be PUBLIC, PRIVATE, or INTERFACE
target_link_libraries ( ${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME} )
