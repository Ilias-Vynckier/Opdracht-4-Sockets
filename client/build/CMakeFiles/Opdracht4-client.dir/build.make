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
CMAKE_SOURCE_DIR = /home/pi/embed2/Opdracht-4-Sockets/client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/embed2/Opdracht-4-Sockets/client/build

# Include any dependencies generated for this target.
include CMakeFiles/Opdracht4-client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Opdracht4-client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Opdracht4-client.dir/flags.make

CMakeFiles/Opdracht4-client.dir/main.c.o: CMakeFiles/Opdracht4-client.dir/flags.make
CMakeFiles/Opdracht4-client.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/embed2/Opdracht-4-Sockets/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Opdracht4-client.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Opdracht4-client.dir/main.c.o   -c /home/pi/embed2/Opdracht-4-Sockets/client/main.c

CMakeFiles/Opdracht4-client.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Opdracht4-client.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/embed2/Opdracht-4-Sockets/client/main.c > CMakeFiles/Opdracht4-client.dir/main.c.i

CMakeFiles/Opdracht4-client.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Opdracht4-client.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/embed2/Opdracht-4-Sockets/client/main.c -o CMakeFiles/Opdracht4-client.dir/main.c.s

# Object files for target Opdracht4-client
Opdracht4__client_OBJECTS = \
"CMakeFiles/Opdracht4-client.dir/main.c.o"

# External object files for target Opdracht4-client
Opdracht4__client_EXTERNAL_OBJECTS =

Opdracht4-client: CMakeFiles/Opdracht4-client.dir/main.c.o
Opdracht4-client: CMakeFiles/Opdracht4-client.dir/build.make
Opdracht4-client: /home/pi/embed2/tlpi-dist/libtlpi.a
Opdracht4-client: CMakeFiles/Opdracht4-client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/embed2/Opdracht-4-Sockets/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Opdracht4-client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Opdracht4-client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Opdracht4-client.dir/build: Opdracht4-client

.PHONY : CMakeFiles/Opdracht4-client.dir/build

CMakeFiles/Opdracht4-client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Opdracht4-client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Opdracht4-client.dir/clean

CMakeFiles/Opdracht4-client.dir/depend:
	cd /home/pi/embed2/Opdracht-4-Sockets/client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/embed2/Opdracht-4-Sockets/client /home/pi/embed2/Opdracht-4-Sockets/client /home/pi/embed2/Opdracht-4-Sockets/client/build /home/pi/embed2/Opdracht-4-Sockets/client/build /home/pi/embed2/Opdracht-4-Sockets/client/build/CMakeFiles/Opdracht4-client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Opdracht4-client.dir/depend
