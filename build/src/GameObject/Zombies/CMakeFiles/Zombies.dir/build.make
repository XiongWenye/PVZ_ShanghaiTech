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
include src/GameObject/Zombies/CMakeFiles/Zombies.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/GameObject/Zombies/CMakeFiles/Zombies.dir/compiler_depend.make

# Include the progress variables for this target.
include src/GameObject/Zombies/CMakeFiles/Zombies.dir/progress.make

# Include the compile flags for this target's objects.
include src/GameObject/Zombies/CMakeFiles/Zombies.dir/flags.make

src/GameObject/Zombies/CMakeFiles/Zombies.dir/Zombies.cpp.obj: src/GameObject/Zombies/CMakeFiles/Zombies.dir/flags.make
src/GameObject/Zombies/CMakeFiles/Zombies.dir/Zombies.cpp.obj: src/GameObject/Zombies/CMakeFiles/Zombies.dir/includes_CXX.rsp
src/GameObject/Zombies/CMakeFiles/Zombies.dir/Zombies.cpp.obj: D:/Documents/Shanghaitech/CS_100_2024_spring/Homework8/src/GameObject/Zombies/Zombies.cpp
src/GameObject/Zombies/CMakeFiles/Zombies.dir/Zombies.cpp.obj: src/GameObject/Zombies/CMakeFiles/Zombies.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/GameObject/Zombies/CMakeFiles/Zombies.dir/Zombies.cpp.obj"
	cd /d D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Zombies && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/GameObject/Zombies/CMakeFiles/Zombies.dir/Zombies.cpp.obj -MF CMakeFiles\Zombies.dir\Zombies.cpp.obj.d -o CMakeFiles\Zombies.dir\Zombies.cpp.obj -c D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\src\GameObject\Zombies\Zombies.cpp

src/GameObject/Zombies/CMakeFiles/Zombies.dir/Zombies.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Zombies.dir/Zombies.cpp.i"
	cd /d D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Zombies && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\src\GameObject\Zombies\Zombies.cpp > CMakeFiles\Zombies.dir\Zombies.cpp.i

src/GameObject/Zombies/CMakeFiles/Zombies.dir/Zombies.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Zombies.dir/Zombies.cpp.s"
	cd /d D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Zombies && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\src\GameObject\Zombies\Zombies.cpp -o CMakeFiles\Zombies.dir\Zombies.cpp.s

# Object files for target Zombies
Zombies_OBJECTS = \
"CMakeFiles/Zombies.dir/Zombies.cpp.obj"

# External object files for target Zombies
Zombies_EXTERNAL_OBJECTS =

lib/libZombies.a: src/GameObject/Zombies/CMakeFiles/Zombies.dir/Zombies.cpp.obj
lib/libZombies.a: src/GameObject/Zombies/CMakeFiles/Zombies.dir/build.make
lib/libZombies.a: src/GameObject/Zombies/CMakeFiles/Zombies.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\..\lib\libZombies.a"
	cd /d D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Zombies && $(CMAKE_COMMAND) -P CMakeFiles\Zombies.dir\cmake_clean_target.cmake
	cd /d D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Zombies && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Zombies.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/GameObject/Zombies/CMakeFiles/Zombies.dir/build: lib/libZombies.a
.PHONY : src/GameObject/Zombies/CMakeFiles/Zombies.dir/build

src/GameObject/Zombies/CMakeFiles/Zombies.dir/clean:
	cd /d D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Zombies && $(CMAKE_COMMAND) -P CMakeFiles\Zombies.dir\cmake_clean.cmake
.PHONY : src/GameObject/Zombies/CMakeFiles/Zombies.dir/clean

src/GameObject/Zombies/CMakeFiles/Zombies.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8 D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\src\GameObject\Zombies D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Zombies D:\Documents\Shanghaitech\CS_100_2024_spring\Homework8\build\src\GameObject\Zombies\CMakeFiles\Zombies.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/GameObject/Zombies/CMakeFiles/Zombies.dir/depend

