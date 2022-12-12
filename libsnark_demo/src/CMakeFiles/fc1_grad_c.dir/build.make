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
include src/CMakeFiles/fc1_grad_c.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/fc1_grad_c.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/fc1_grad_c.dir/flags.make

src/CMakeFiles/fc1_grad_c.dir/Training/LeNet5/circuit/fc1_grad_c.cpp.o: src/CMakeFiles/fc1_grad_c.dir/flags.make
src/CMakeFiles/fc1_grad_c.dir/Training/LeNet5/circuit/fc1_grad_c.cpp.o: src/Training/LeNet5/circuit/fc1_grad_c.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/libsnarkdemo/libsnark_demo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/fc1_grad_c.dir/Training/LeNet5/circuit/fc1_grad_c.cpp.o"
	cd /home/libsnarkdemo/libsnark_demo/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fc1_grad_c.dir/Training/LeNet5/circuit/fc1_grad_c.cpp.o -c /home/libsnarkdemo/libsnark_demo/src/Training/LeNet5/circuit/fc1_grad_c.cpp

src/CMakeFiles/fc1_grad_c.dir/Training/LeNet5/circuit/fc1_grad_c.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fc1_grad_c.dir/Training/LeNet5/circuit/fc1_grad_c.cpp.i"
	cd /home/libsnarkdemo/libsnark_demo/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/libsnarkdemo/libsnark_demo/src/Training/LeNet5/circuit/fc1_grad_c.cpp > CMakeFiles/fc1_grad_c.dir/Training/LeNet5/circuit/fc1_grad_c.cpp.i

src/CMakeFiles/fc1_grad_c.dir/Training/LeNet5/circuit/fc1_grad_c.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fc1_grad_c.dir/Training/LeNet5/circuit/fc1_grad_c.cpp.s"
	cd /home/libsnarkdemo/libsnark_demo/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/libsnarkdemo/libsnark_demo/src/Training/LeNet5/circuit/fc1_grad_c.cpp -o CMakeFiles/fc1_grad_c.dir/Training/LeNet5/circuit/fc1_grad_c.cpp.s

# Object files for target fc1_grad_c
fc1_grad_c_OBJECTS = \
"CMakeFiles/fc1_grad_c.dir/Training/LeNet5/circuit/fc1_grad_c.cpp.o"

# External object files for target fc1_grad_c
fc1_grad_c_EXTERNAL_OBJECTS =

train_LeNet5_backward/fc1_grad_c: src/CMakeFiles/fc1_grad_c.dir/Training/LeNet5/circuit/fc1_grad_c.cpp.o
train_LeNet5_backward/fc1_grad_c: src/CMakeFiles/fc1_grad_c.dir/build.make
train_LeNet5_backward/fc1_grad_c: depends/libsnark/libsnark/libsnark.a
train_LeNet5_backward/fc1_grad_c: depends/libsnark/depends/libff/libff/libff.a
train_LeNet5_backward/fc1_grad_c: /usr/lib/x86_64-linux-gnu/libgmp.so
train_LeNet5_backward/fc1_grad_c: /usr/lib/x86_64-linux-gnu/libgmp.so
train_LeNet5_backward/fc1_grad_c: /usr/lib/x86_64-linux-gnu/libgmpxx.so
train_LeNet5_backward/fc1_grad_c: src/CMakeFiles/fc1_grad_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/libsnarkdemo/libsnark_demo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../train_LeNet5_backward/fc1_grad_c"
	cd /home/libsnarkdemo/libsnark_demo/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fc1_grad_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/fc1_grad_c.dir/build: train_LeNet5_backward/fc1_grad_c

.PHONY : src/CMakeFiles/fc1_grad_c.dir/build

src/CMakeFiles/fc1_grad_c.dir/clean:
	cd /home/libsnarkdemo/libsnark_demo/src && $(CMAKE_COMMAND) -P CMakeFiles/fc1_grad_c.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/fc1_grad_c.dir/clean

src/CMakeFiles/fc1_grad_c.dir/depend:
	cd /home/libsnarkdemo/libsnark_demo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/libsnarkdemo/libsnark_demo /home/libsnarkdemo/libsnark_demo/src /home/libsnarkdemo/libsnark_demo /home/libsnarkdemo/libsnark_demo/src /home/libsnarkdemo/libsnark_demo/src/CMakeFiles/fc1_grad_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/fc1_grad_c.dir/depend

