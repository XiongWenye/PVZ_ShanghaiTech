# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = D:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build

# Include any dependencies generated for this target.
include src/GameObject/Plants/CMakeFiles/Plants.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/GameObject/Plants/CMakeFiles/Plants.dir/compiler_depend.make

# Include the progress variables for this target.
include src/GameObject/Plants/CMakeFiles/Plants.dir/progress.make

# Include the compile flags for this target's objects.
include src/GameObject/Plants/CMakeFiles/Plants.dir/flags.make

src/GameObject/Plants/CMakeFiles/Plants.dir/Plants.cpp.obj: src/GameObject/Plants/CMakeFiles/Plants.dir/flags.make
src/GameObject/Plants/CMakeFiles/Plants.dir/Plants.cpp.obj: src/GameObject/Plants/CMakeFiles/Plants.dir/includes_CXX.rsp
src/GameObject/Plants/CMakeFiles/Plants.dir/Plants.cpp.obj: D:/Documents/Shanghaitech/CS_100_2024_spring/Homework8/src/GameObject/Plants/Plants.cpp
src/GameObject/Plants/CMakeFiles/Plants.dir/Plants.cpp.obj: src/GameObject/Plants/CMakeFiles/Plants.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/GameObject/Plants/CMakeFiles/Plants.dir/Plants.cpp.obj"
	cd /d D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Plants && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/GameObject/Plants/CMakeFiles/Plants.dir/Plants.cpp.obj -MF CMakeFiles\Plants.dir\Plants.cpp.obj.d -o CMakeFiles\Plants.dir\Plants.cpp.obj -c D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\src\GameObject\Plants\Plants.cpp

src/GameObject/Plants/CMakeFiles/Plants.dir/Plants.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Plants.dir/Plants.cpp.i"
	cd /d D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Plants && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\src\GameObject\Plants\Plants.cpp > CMakeFiles\Plants.dir\Plants.cpp.i

src/GameObject/Plants/CMakeFiles/Plants.dir/Plants.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Plants.dir/Plants.cpp.s"
	cd /d D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Plants && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\src\GameObject\Plants\Plants.cpp -o CMakeFiles\Plants.dir\Plants.cpp.s

# Object files for target Plants
Plants_OBJECTS = \
"CMakeFiles/Plants.dir/Plants.cpp.obj"

# External object files for target Plants
Plants_EXTERNAL_OBJECTS =

lib/libPlants.a: src/GameObject/Plants/CMakeFiles/Plants.dir/Plants.cpp.obj
lib/libPlants.a: src/GameObject/Plants/CMakeFiles/Plants.dir/build.make
lib/libPlants.a: src/GameObject/Plants/CMakeFiles/Plants.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\..\lib\libPlants.a"
	cd /d D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Plants && $(CMAKE_COMMAND) -P CMakeFiles\Plants.dir\cmake_clean_target.cmake
	cd /d D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Plants && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Plants.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/GameObject/Plants/CMakeFiles/Plants.dir/build: lib/libPlants.a
.PHONY : src/GameObject/Plants/CMakeFiles/Plants.dir/build

src/GameObject/Plants/CMakeFiles/Plants.dir/clean:
	cd /d D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Plants && $(CMAKE_COMMAND) -P CMakeFiles\Plants.dir\cmake_clean.cmake
.PHONY : src/GameObject/Plants/CMakeFiles/Plants.dir/clean

src/GameObject/Plants/CMakeFiles/Plants.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8 D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\src\GameObject\Plants D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Plants D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Plants\CMakeFiles\Plants.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/GameObject/Plants/CMakeFiles/Plants.dir/depend

