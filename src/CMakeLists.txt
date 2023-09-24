# Add a library that can be used in the project
# A library can be STATIC, SHARED, or MODULE
# A specific library can be compiled by using the following command:
#   cmake --build . --target Library
add_library ( ${LIBRARY_NAME} STATIC my_library.cpp )

# Specify the location where relevent header files can be found
target_include_directories( ${LIBRARY_NAME} PUBLIC "." )
