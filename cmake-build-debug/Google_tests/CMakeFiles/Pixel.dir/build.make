# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/209/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/209/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zvgdb/Clion-GoogleTest-Starter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zvgdb/Clion-GoogleTest-Starter/cmake-build-debug

# Include any dependencies generated for this target.
include Google_tests/CMakeFiles/Pixel.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Google_tests/CMakeFiles/Pixel.dir/compiler_depend.make

# Include the progress variables for this target.
include Google_tests/CMakeFiles/Pixel.dir/progress.make

# Include the compile flags for this target's objects.
include Google_tests/CMakeFiles/Pixel.dir/flags.make

Google_tests/CMakeFiles/Pixel.dir/Pixel.cpp.o: Google_tests/CMakeFiles/Pixel.dir/flags.make
Google_tests/CMakeFiles/Pixel.dir/Pixel.cpp.o: ../Google_tests/Pixel.cpp
Google_tests/CMakeFiles/Pixel.dir/Pixel.cpp.o: Google_tests/CMakeFiles/Pixel.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zvgdb/Clion-GoogleTest-Starter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Google_tests/CMakeFiles/Pixel.dir/Pixel.cpp.o"
	cd /home/zvgdb/Clion-GoogleTest-Starter/cmake-build-debug/Google_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Google_tests/CMakeFiles/Pixel.dir/Pixel.cpp.o -MF CMakeFiles/Pixel.dir/Pixel.cpp.o.d -o CMakeFiles/Pixel.dir/Pixel.cpp.o -c /home/zvgdb/Clion-GoogleTest-Starter/Google_tests/Pixel.cpp

Google_tests/CMakeFiles/Pixel.dir/Pixel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pixel.dir/Pixel.cpp.i"
	cd /home/zvgdb/Clion-GoogleTest-Starter/cmake-build-debug/Google_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zvgdb/Clion-GoogleTest-Starter/Google_tests/Pixel.cpp > CMakeFiles/Pixel.dir/Pixel.cpp.i

Google_tests/CMakeFiles/Pixel.dir/Pixel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pixel.dir/Pixel.cpp.s"
	cd /home/zvgdb/Clion-GoogleTest-Starter/cmake-build-debug/Google_tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zvgdb/Clion-GoogleTest-Starter/Google_tests/Pixel.cpp -o CMakeFiles/Pixel.dir/Pixel.cpp.s

# Object files for target Pixel
Pixel_OBJECTS = \
"CMakeFiles/Pixel.dir/Pixel.cpp.o"

# External object files for target Pixel
Pixel_EXTERNAL_OBJECTS =

Google_tests/Pixel: Google_tests/CMakeFiles/Pixel.dir/Pixel.cpp.o
Google_tests/Pixel: Google_tests/CMakeFiles/Pixel.dir/build.make
Google_tests/Pixel: Google_tests/CMakeFiles/Pixel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zvgdb/Clion-GoogleTest-Starter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Pixel"
	cd /home/zvgdb/Clion-GoogleTest-Starter/cmake-build-debug/Google_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pixel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Google_tests/CMakeFiles/Pixel.dir/build: Google_tests/Pixel
.PHONY : Google_tests/CMakeFiles/Pixel.dir/build

Google_tests/CMakeFiles/Pixel.dir/clean:
	cd /home/zvgdb/Clion-GoogleTest-Starter/cmake-build-debug/Google_tests && $(CMAKE_COMMAND) -P CMakeFiles/Pixel.dir/cmake_clean.cmake
.PHONY : Google_tests/CMakeFiles/Pixel.dir/clean

Google_tests/CMakeFiles/Pixel.dir/depend:
	cd /home/zvgdb/Clion-GoogleTest-Starter/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zvgdb/Clion-GoogleTest-Starter /home/zvgdb/Clion-GoogleTest-Starter/Google_tests /home/zvgdb/Clion-GoogleTest-Starter/cmake-build-debug /home/zvgdb/Clion-GoogleTest-Starter/cmake-build-debug/Google_tests /home/zvgdb/Clion-GoogleTest-Starter/cmake-build-debug/Google_tests/CMakeFiles/Pixel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Google_tests/CMakeFiles/Pixel.dir/depend

