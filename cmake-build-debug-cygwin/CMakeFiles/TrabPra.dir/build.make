# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /cygdrive/c/Users/beatr/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/beatr/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/P/TrabPra

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/P/TrabPra/cmake-build-debug-cygwin

# Include any dependencies generated for this target.
include CMakeFiles/TrabPra.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TrabPra.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TrabPra.dir/flags.make

CMakeFiles/TrabPra.dir/jogo.c.o: CMakeFiles/TrabPra.dir/flags.make
CMakeFiles/TrabPra.dir/jogo.c.o: ../jogo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/P/TrabPra/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TrabPra.dir/jogo.c.o"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TrabPra.dir/jogo.c.o -c /cygdrive/d/P/TrabPra/jogo.c

CMakeFiles/TrabPra.dir/jogo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TrabPra.dir/jogo.c.i"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/P/TrabPra/jogo.c > CMakeFiles/TrabPra.dir/jogo.c.i

CMakeFiles/TrabPra.dir/jogo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TrabPra.dir/jogo.c.s"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/P/TrabPra/jogo.c -o CMakeFiles/TrabPra.dir/jogo.c.s

CMakeFiles/TrabPra.dir/main.c.o: CMakeFiles/TrabPra.dir/flags.make
CMakeFiles/TrabPra.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/P/TrabPra/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TrabPra.dir/main.c.o"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TrabPra.dir/main.c.o -c /cygdrive/d/P/TrabPra/main.c

CMakeFiles/TrabPra.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TrabPra.dir/main.c.i"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/P/TrabPra/main.c > CMakeFiles/TrabPra.dir/main.c.i

CMakeFiles/TrabPra.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TrabPra.dir/main.c.s"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/P/TrabPra/main.c -o CMakeFiles/TrabPra.dir/main.c.s

CMakeFiles/TrabPra.dir/utils.c.o: CMakeFiles/TrabPra.dir/flags.make
CMakeFiles/TrabPra.dir/utils.c.o: ../utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/P/TrabPra/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TrabPra.dir/utils.c.o"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TrabPra.dir/utils.c.o -c /cygdrive/d/P/TrabPra/utils.c

CMakeFiles/TrabPra.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TrabPra.dir/utils.c.i"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/P/TrabPra/utils.c > CMakeFiles/TrabPra.dir/utils.c.i

CMakeFiles/TrabPra.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TrabPra.dir/utils.c.s"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/P/TrabPra/utils.c -o CMakeFiles/TrabPra.dir/utils.c.s

# Object files for target TrabPra
TrabPra_OBJECTS = \
"CMakeFiles/TrabPra.dir/jogo.c.o" \
"CMakeFiles/TrabPra.dir/main.c.o" \
"CMakeFiles/TrabPra.dir/utils.c.o"

# External object files for target TrabPra
TrabPra_EXTERNAL_OBJECTS =

TrabPra.exe: CMakeFiles/TrabPra.dir/jogo.c.o
TrabPra.exe: CMakeFiles/TrabPra.dir/main.c.o
TrabPra.exe: CMakeFiles/TrabPra.dir/utils.c.o
TrabPra.exe: CMakeFiles/TrabPra.dir/build.make
TrabPra.exe: CMakeFiles/TrabPra.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/P/TrabPra/cmake-build-debug-cygwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable TrabPra.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TrabPra.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TrabPra.dir/build: TrabPra.exe

.PHONY : CMakeFiles/TrabPra.dir/build

CMakeFiles/TrabPra.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TrabPra.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TrabPra.dir/clean

CMakeFiles/TrabPra.dir/depend:
	cd /cygdrive/d/P/TrabPra/cmake-build-debug-cygwin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/P/TrabPra /cygdrive/d/P/TrabPra /cygdrive/d/P/TrabPra/cmake-build-debug-cygwin /cygdrive/d/P/TrabPra/cmake-build-debug-cygwin /cygdrive/d/P/TrabPra/cmake-build-debug-cygwin/CMakeFiles/TrabPra.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TrabPra.dir/depend

