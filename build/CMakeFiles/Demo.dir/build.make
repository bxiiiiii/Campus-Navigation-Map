# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/cmake-3.22.1-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /usr/cmake-3.22.1-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bxiiiiii/progr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bxiiiiii/progr/build

# Include any dependencies generated for this target.
include CMakeFiles/Demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Demo.dir/flags.make

CMakeFiles/Demo.dir/src/main.c.o: CMakeFiles/Demo.dir/flags.make
CMakeFiles/Demo.dir/src/main.c.o: ../src/main.c
CMakeFiles/Demo.dir/src/main.c.o: CMakeFiles/Demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bxiiiiii/progr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Demo.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Demo.dir/src/main.c.o -MF CMakeFiles/Demo.dir/src/main.c.o.d -o CMakeFiles/Demo.dir/src/main.c.o -c /home/bxiiiiii/progr/src/main.c

CMakeFiles/Demo.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Demo.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bxiiiiii/progr/src/main.c > CMakeFiles/Demo.dir/src/main.c.i

CMakeFiles/Demo.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Demo.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bxiiiiii/progr/src/main.c -o CMakeFiles/Demo.dir/src/main.c.s

CMakeFiles/Demo.dir/src/UI.c.o: CMakeFiles/Demo.dir/flags.make
CMakeFiles/Demo.dir/src/UI.c.o: ../src/UI.c
CMakeFiles/Demo.dir/src/UI.c.o: CMakeFiles/Demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bxiiiiii/progr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Demo.dir/src/UI.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Demo.dir/src/UI.c.o -MF CMakeFiles/Demo.dir/src/UI.c.o.d -o CMakeFiles/Demo.dir/src/UI.c.o -c /home/bxiiiiii/progr/src/UI.c

CMakeFiles/Demo.dir/src/UI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Demo.dir/src/UI.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bxiiiiii/progr/src/UI.c > CMakeFiles/Demo.dir/src/UI.c.i

CMakeFiles/Demo.dir/src/UI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Demo.dir/src/UI.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bxiiiiii/progr/src/UI.c -o CMakeFiles/Demo.dir/src/UI.c.s

CMakeFiles/Demo.dir/src/Operations.c.o: CMakeFiles/Demo.dir/flags.make
CMakeFiles/Demo.dir/src/Operations.c.o: ../src/Operations.c
CMakeFiles/Demo.dir/src/Operations.c.o: CMakeFiles/Demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bxiiiiii/progr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Demo.dir/src/Operations.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Demo.dir/src/Operations.c.o -MF CMakeFiles/Demo.dir/src/Operations.c.o.d -o CMakeFiles/Demo.dir/src/Operations.c.o -c /home/bxiiiiii/progr/src/Operations.c

CMakeFiles/Demo.dir/src/Operations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Demo.dir/src/Operations.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bxiiiiii/progr/src/Operations.c > CMakeFiles/Demo.dir/src/Operations.c.i

CMakeFiles/Demo.dir/src/Operations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Demo.dir/src/Operations.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bxiiiiii/progr/src/Operations.c -o CMakeFiles/Demo.dir/src/Operations.c.s

# Object files for target Demo
Demo_OBJECTS = \
"CMakeFiles/Demo.dir/src/main.c.o" \
"CMakeFiles/Demo.dir/src/UI.c.o" \
"CMakeFiles/Demo.dir/src/Operations.c.o"

# External object files for target Demo
Demo_EXTERNAL_OBJECTS =

Demo: CMakeFiles/Demo.dir/src/main.c.o
Demo: CMakeFiles/Demo.dir/src/UI.c.o
Demo: CMakeFiles/Demo.dir/src/Operations.c.o
Demo: CMakeFiles/Demo.dir/build.make
Demo: CMakeFiles/Demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bxiiiiii/progr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Demo.dir/build: Demo
.PHONY : CMakeFiles/Demo.dir/build

CMakeFiles/Demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Demo.dir/clean

CMakeFiles/Demo.dir/depend:
	cd /home/bxiiiiii/progr/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bxiiiiii/progr /home/bxiiiiii/progr /home/bxiiiiii/progr/build /home/bxiiiiii/progr/build /home/bxiiiiii/progr/build/CMakeFiles/Demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Demo.dir/depend

