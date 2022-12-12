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
include src/CMakeFiles/relu2_F15.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/relu2_F15.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/relu2_F15.dir/flags.make

src/CMakeFiles/relu2_F15.dir/LeNet5/circuit/relu2_F15.cpp.o: src/CMakeFiles/relu2_F15.dir/flags.make
src/CMakeFiles/relu2_F15.dir/LeNet5/circuit/relu2_F15.cpp.o: src/LeNet5/circuit/relu2_F15.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/libsnarkdemo/libsnark_demo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/relu2_F15.dir/LeNet5/circuit/relu2_F15.cpp.o"
	cd /home/libsnarkdemo/libsnark_demo/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/relu2_F15.dir/LeNet5/circuit/relu2_F15.cpp.o -c /home/libsnarkdemo/libsnark_demo/src/LeNet5/circuit/relu2_F15.cpp

src/CMakeFiles/relu2_F15.dir/LeNet5/circuit/relu2_F15.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/relu2_F15.dir/LeNet5/circuit/relu2_F15.cpp.i"
	cd /home/libsnarkdemo/libsnark_demo/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/libsnarkdemo/libsnark_demo/src/LeNet5/circuit/relu2_F15.cpp > CMakeFiles/relu2_F15.dir/LeNet5/circuit/relu2_F15.cpp.i

src/CMakeFiles/relu2_F15.dir/LeNet5/circuit/relu2_F15.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/relu2_F15.dir/LeNet5/circuit/relu2_F15.cpp.s"
	cd /home/libsnarkdemo/libsnark_demo/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/libsnarkdemo/libsnark_demo/src/LeNet5/circuit/relu2_F15.cpp -o CMakeFiles/relu2_F15.dir/LeNet5/circuit/relu2_F15.cpp.s

# Object files for target relu2_F15
relu2_F15_OBJECTS = \
"CMakeFiles/relu2_F15.dir/LeNet5/circuit/relu2_F15.cpp.o"

# External object files for target relu2_F15
relu2_F15_EXTERNAL_OBJECTS =

LeNet5/relu2_F15: src/CMakeFiles/relu2_F15.dir/LeNet5/circuit/relu2_F15.cpp.o
LeNet5/relu2_F15: src/CMakeFiles/relu2_F15.dir/build.make
LeNet5/relu2_F15: depends/libsnark/libsnark/libsnark.a
LeNet5/relu2_F15: depends/libsnark/depends/libff/libff/libff.a
LeNet5/relu2_F15: /usr/lib/x86_64-linux-gnu/libgmp.so
LeNet5/relu2_F15: /usr/lib/x86_64-linux-gnu/libgmp.so
LeNet5/relu2_F15: /usr/lib/x86_64-linux-gnu/libgmpxx.so
LeNet5/relu2_F15: src/CMakeFiles/relu2_F15.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/libsnarkdemo/libsnark_demo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../LeNet5/relu2_F15"
	cd /home/libsnarkdemo/libsnark_demo/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/relu2_F15.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/relu2_F15.dir/build: LeNet5/relu2_F15

.PHONY : src/CMakeFiles/relu2_F15.dir/build

src/CMakeFiles/relu2_F15.dir/clean:
	cd /home/libsnarkdemo/libsnark_demo/src && $(CMAKE_COMMAND) -P CMakeFiles/relu2_F15.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/relu2_F15.dir/clean

src/CMakeFiles/relu2_F15.dir/depend:
	cd /home/libsnarkdemo/libsnark_demo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/libsnarkdemo/libsnark_demo /home/libsnarkdemo/libsnark_demo/src /home/libsnarkdemo/libsnark_demo /home/libsnarkdemo/libsnark_demo/src /home/libsnarkdemo/libsnark_demo/src/CMakeFiles/relu2_F15.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/relu2_F15.dir/depend

