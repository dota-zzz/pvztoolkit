# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = S:\software\cmake\bin\cmake.exe

# The command to remove a file.
RM = S:\software\cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\zzz\code\c++\test2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\zzz\code\c++\test2\build

# Include any dependencies generated for this target.
include CMakeFiles/test1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test1.dir/flags.make

CMakeFiles/test1.dir/src/main.cpp.obj: CMakeFiles/test1.dir/flags.make
CMakeFiles/test1.dir/src/main.cpp.obj: CMakeFiles/test1.dir/includes_CXX.rsp
CMakeFiles/test1.dir/src/main.cpp.obj: D:/zzz/code/c++/test2/src/main.cpp
CMakeFiles/test1.dir/src/main.cpp.obj: CMakeFiles/test1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\zzz\code\c++\test2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test1.dir/src/main.cpp.obj"
	S:\software\mingw\mingw64-8.1.0\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test1.dir/src/main.cpp.obj -MF CMakeFiles\test1.dir\src\main.cpp.obj.d -o CMakeFiles\test1.dir\src\main.cpp.obj -c D:\zzz\code\c++\test2\src\main.cpp

CMakeFiles/test1.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test1.dir/src/main.cpp.i"
	S:\software\mingw\mingw64-8.1.0\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\zzz\code\c++\test2\src\main.cpp > CMakeFiles\test1.dir\src\main.cpp.i

CMakeFiles/test1.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test1.dir/src/main.cpp.s"
	S:\software\mingw\mingw64-8.1.0\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\zzz\code\c++\test2\src\main.cpp -o CMakeFiles\test1.dir\src\main.cpp.s

# Object files for target test1
test1_OBJECTS = \
"CMakeFiles/test1.dir/src/main.cpp.obj"

# External object files for target test1
test1_EXTERNAL_OBJECTS =

test1.exe: CMakeFiles/test1.dir/src/main.cpp.obj
test1.exe: CMakeFiles/test1.dir/build.make
test1.exe: CMakeFiles/test1.dir/linklibs.rsp
test1.exe: CMakeFiles/test1.dir/objects1.rsp
test1.exe: CMakeFiles/test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\zzz\code\c++\test2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test1.dir/build: test1.exe
.PHONY : CMakeFiles/test1.dir/build

CMakeFiles/test1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test1.dir/clean

CMakeFiles/test1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\zzz\code\c++\test2 D:\zzz\code\c++\test2 D:\zzz\code\c++\test2\build D:\zzz\code\c++\test2\build D:\zzz\code\c++\test2\build\CMakeFiles\test1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test1.dir/depend

