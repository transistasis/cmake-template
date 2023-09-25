# Create lists of the source files needed to build the application
set ( EXE_SOURCES
  main.cpp )

# Create an executable from project source code
add_executable ( ${EXECUTABLE_NAME} ${EXE_SOURCES} )

# Link the library target to the executable target
# This means that Library is a dependency of Executable
# The link can either be PUBLIC, PRIVATE, or INTERFACE
target_link_libraries ( ${EXECUTABLE_NAME} PUBLIC 
  ${LIBRARY_NAME} 
  nlohmann_json )
