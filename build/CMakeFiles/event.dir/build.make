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
CMAKE_SOURCE_DIR = /home/emery/cube

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emery/cube/build

# Include any dependencies generated for this target.
include CMakeFiles/event.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/event.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/event.dir/flags.make

CMakeFiles/event.dir/src/event.c.o: CMakeFiles/event.dir/flags.make
CMakeFiles/event.dir/src/event.c.o: ../src/event.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emery/cube/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/event.dir/src/event.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/event.dir/src/event.c.o   -c /home/emery/cube/src/event.c

CMakeFiles/event.dir/src/event.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/event.dir/src/event.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/emery/cube/src/event.c > CMakeFiles/event.dir/src/event.c.i

CMakeFiles/event.dir/src/event.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/event.dir/src/event.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/emery/cube/src/event.c -o CMakeFiles/event.dir/src/event.c.s

# Object files for target event
event_OBJECTS = \
"CMakeFiles/event.dir/src/event.c.o"

# External object files for target event
event_EXTERNAL_OBJECTS =

../lib/libevent.so: CMakeFiles/event.dir/src/event.c.o
../lib/libevent.so: CMakeFiles/event.dir/build.make
../lib/libevent.so: CMakeFiles/event.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emery/cube/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library ../lib/libevent.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/event.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/event.dir/build: ../lib/libevent.so

.PHONY : CMakeFiles/event.dir/build

CMakeFiles/event.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/event.dir/cmake_clean.cmake
.PHONY : CMakeFiles/event.dir/clean

CMakeFiles/event.dir/depend:
	cd /home/emery/cube/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emery/cube /home/emery/cube /home/emery/cube/build /home/emery/cube/build /home/emery/cube/build/CMakeFiles/event.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/event.dir/depend
