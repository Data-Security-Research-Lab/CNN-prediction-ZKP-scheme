# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/libsnarkdemo/libsnark_demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/libsnarkdemo/libsnark_demo

# Include any dependencies generated for this target.
include src/CMakeFiles/relu2_1.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/relu2_1.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/relu2_1.dir/flags.make

src/CMakeFiles/relu2_1.dir/vgg16/circuit/relu2_1.cpp.o: src/CMakeFiles/relu2_1.dir/flags.make
src/CMakeFiles/relu2_1.dir/vgg16/circuit/relu2_1.cpp.o: src/vgg16/circuit/relu2_1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/libsnarkdemo/libsnark_demo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/relu2_1.dir/vgg16/circuit/relu2_1.cpp.o"
	cd /home/libsnarkdemo/libsnark_demo/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/relu2_1.dir/vgg16/circuit/relu2_1.cpp.o -c /home/libsnarkdemo/libsnark_demo/src/vgg16/circuit/relu2_1.cpp

src/CMakeFiles/relu2_1.dir/vgg16/circuit/relu2_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/relu2_1.dir/vgg16/circuit/relu2_1.cpp.i"
	cd /home/libsnarkdemo/libsnark_demo/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/libsnarkdemo/libsnark_demo/src/vgg16/circuit/relu2_1.cpp > CMakeFiles/relu2_1.dir/vgg16/circuit/relu2_1.cpp.i

src/CMakeFiles/relu2_1.dir/vgg16/circuit/relu2_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/relu2_1.dir/vgg16/circuit/relu2_1.cpp.s"
	cd /home/libsnarkdemo/libsnark_demo/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/libsnarkdemo/libsnark_demo/src/vgg16/circuit/relu2_1.cpp -o CMakeFiles/relu2_1.dir/vgg16/circuit/relu2_1.cpp.s

# Object files for target relu2_1
relu2_1_OBJECTS = \
"CMakeFiles/relu2_1.dir/vgg16/circuit/relu2_1.cpp.o"

# External object files for target relu2_1
relu2_1_EXTERNAL_OBJECTS =

vgg16/relu2_1: src/CMakeFiles/relu2_1.dir/vgg16/circuit/relu2_1.cpp.o
vgg16/relu2_1: src/CMakeFiles/relu2_1.dir/build.make
vgg16/relu2_1: depends/libsnark/libsnark/libsnark.a
vgg16/relu2_1: depends/libsnark/depends/libff/libff/libff.a
vgg16/relu2_1: /usr/lib/x86_64-linux-gnu/libgmp.so
vgg16/relu2_1: /usr/lib/x86_64-linux-gnu/libgmp.so
vgg16/relu2_1: /usr/lib/x86_64-linux-gnu/libgmpxx.so
vgg16/relu2_1: src/CMakeFiles/relu2_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/libsnarkdemo/libsnark_demo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../vgg16/relu2_1"
	cd /home/libsnarkdemo/libsnark_demo/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/relu2_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/relu2_1.dir/build: vgg16/relu2_1

.PHONY : src/CMakeFiles/relu2_1.dir/build

src/CMakeFiles/relu2_1.dir/clean:
	cd /home/libsnarkdemo/libsnark_demo/src && $(CMAKE_COMMAND) -P CMakeFiles/relu2_1.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/relu2_1.dir/clean

src/CMakeFiles/relu2_1.dir/depend:
	cd /home/libsnarkdemo/libsnark_demo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/libsnarkdemo/libsnark_demo /home/libsnarkdemo/libsnark_demo/src /home/libsnarkdemo/libsnark_demo /home/libsnarkdemo/libsnark_demo/src /home/libsnarkdemo/libsnark_demo/src/CMakeFiles/relu2_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/relu2_1.dir/depend

