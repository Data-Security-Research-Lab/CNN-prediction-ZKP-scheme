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
include depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/depend.make

# Include the progress variables for this target.
include depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/progress.make

# Include the compile flags for this target's objects.
include depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/flags.make

depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp.o: depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/flags.make
depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp.o: depends/libsnark/libsnark/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/libsnarkdemo/libsnark_demo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp.o"
	cd /home/libsnarkdemo/libsnark_demo/depends/libsnark/libsnark && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp.o -c /home/libsnarkdemo/libsnark_demo/depends/libsnark/libsnark/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp

depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp.i"
	cd /home/libsnarkdemo/libsnark_demo/depends/libsnark/libsnark && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/libsnarkdemo/libsnark_demo/depends/libsnark/libsnark/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp > CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp.i

depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp.s"
	cd /home/libsnarkdemo/libsnark_demo/depends/libsnark/libsnark && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/libsnarkdemo/libsnark_demo/depends/libsnark/libsnark/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp -o CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp.s

# Object files for target profile_r1cs_mp_ppzkpcd
profile_r1cs_mp_ppzkpcd_OBJECTS = \
"CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp.o"

# External object files for target profile_r1cs_mp_ppzkpcd
profile_r1cs_mp_ppzkpcd_EXTERNAL_OBJECTS =

depends/libsnark/libsnark/profile_r1cs_mp_ppzkpcd: depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/zk_proof_systems/pcd/r1cs_pcd/r1cs_mp_ppzkpcd/profiling/profile_r1cs_mp_ppzkpcd.cpp.o
depends/libsnark/libsnark/profile_r1cs_mp_ppzkpcd: depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/build.make
depends/libsnark/libsnark/profile_r1cs_mp_ppzkpcd: depends/libsnark/libsnark/libsnark.a
depends/libsnark/libsnark/profile_r1cs_mp_ppzkpcd: depends/libsnark/depends/libff/libff/libff.a
depends/libsnark/libsnark/profile_r1cs_mp_ppzkpcd: /usr/lib/x86_64-linux-gnu/libgmp.so
depends/libsnark/libsnark/profile_r1cs_mp_ppzkpcd: /usr/lib/x86_64-linux-gnu/libgmp.so
depends/libsnark/libsnark/profile_r1cs_mp_ppzkpcd: /usr/lib/x86_64-linux-gnu/libgmpxx.so
depends/libsnark/libsnark/profile_r1cs_mp_ppzkpcd: depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/libsnarkdemo/libsnark_demo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable profile_r1cs_mp_ppzkpcd"
	cd /home/libsnarkdemo/libsnark_demo/depends/libsnark/libsnark && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/build: depends/libsnark/libsnark/profile_r1cs_mp_ppzkpcd

.PHONY : depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/build

depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/clean:
	cd /home/libsnarkdemo/libsnark_demo/depends/libsnark/libsnark && $(CMAKE_COMMAND) -P CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/cmake_clean.cmake
.PHONY : depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/clean

depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/depend:
	cd /home/libsnarkdemo/libsnark_demo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/libsnarkdemo/libsnark_demo /home/libsnarkdemo/libsnark_demo/depends/libsnark/libsnark /home/libsnarkdemo/libsnark_demo /home/libsnarkdemo/libsnark_demo/depends/libsnark/libsnark /home/libsnarkdemo/libsnark_demo/depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : depends/libsnark/libsnark/CMakeFiles/profile_r1cs_mp_ppzkpcd.dir/depend

