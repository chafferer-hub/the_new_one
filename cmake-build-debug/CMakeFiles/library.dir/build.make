# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Chafferer\CLionProjects\fishc\library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Chafferer\CLionProjects\fishc\library\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/library.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/library.dir/flags.make

CMakeFiles/library.dir/main.c.obj: CMakeFiles/library.dir/flags.make
CMakeFiles/library.dir/main.c.obj: CMakeFiles/library.dir/includes_C.rsp
CMakeFiles/library.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chafferer\CLionProjects\fishc\library\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/library.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\library.dir\main.c.obj   -c C:\Users\Chafferer\CLionProjects\fishc\library\main.c

CMakeFiles/library.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/library.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Chafferer\CLionProjects\fishc\library\main.c > CMakeFiles\library.dir\main.c.i

CMakeFiles/library.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/library.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Chafferer\CLionProjects\fishc\library\main.c -o CMakeFiles\library.dir\main.c.s

# Object files for target library
library_OBJECTS = \
"CMakeFiles/library.dir/main.c.obj"

# External object files for target library
library_EXTERNAL_OBJECTS =

library.exe: CMakeFiles/library.dir/main.c.obj
library.exe: CMakeFiles/library.dir/build.make
library.exe: CMakeFiles/library.dir/linklibs.rsp
library.exe: CMakeFiles/library.dir/objects1.rsp
library.exe: CMakeFiles/library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Chafferer\CLionProjects\fishc\library\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable library.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\library.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/library.dir/build: library.exe

.PHONY : CMakeFiles/library.dir/build

CMakeFiles/library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\library.dir\cmake_clean.cmake
.PHONY : CMakeFiles/library.dir/clean

CMakeFiles/library.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Chafferer\CLionProjects\fishc\library C:\Users\Chafferer\CLionProjects\fishc\library C:\Users\Chafferer\CLionProjects\fishc\library\cmake-build-debug C:\Users\Chafferer\CLionProjects\fishc\library\cmake-build-debug C:\Users\Chafferer\CLionProjects\fishc\library\cmake-build-debug\CMakeFiles\library.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/library.dir/depend

