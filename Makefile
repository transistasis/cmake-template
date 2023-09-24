# Builds the CMake project
build : process
	cd build && cmake --build .

# Generates the CMake files necessary to build the project
process : prepare
	cd build && cmake ..

# Creates a blank build directory (used to prepare for Windows CMake testing)
prepare : clean
	mkdir build

# Deletes the generated build directory
.PHONY : clean
clean :
	rm -rf build
