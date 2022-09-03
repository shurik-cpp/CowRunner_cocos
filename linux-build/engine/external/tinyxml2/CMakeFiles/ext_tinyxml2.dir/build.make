# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shurik/myCodes/myGames/CowRunner_cocos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shurik/myCodes/myGames/CowRunner_cocos/linux-build

# Include any dependencies generated for this target.
include engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/depend.make

# Include the progress variables for this target.
include engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/progress.make

# Include the compile flags for this target's objects.
include engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/flags.make

engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/tinyxml2.cpp.o: engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/flags.make
engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/tinyxml2.cpp.o: ../cocos2d/external/tinyxml2/tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shurik/myCodes/myGames/CowRunner_cocos/linux-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/tinyxml2.cpp.o"
	cd /home/shurik/myCodes/myGames/CowRunner_cocos/linux-build/engine/external/tinyxml2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ext_tinyxml2.dir/tinyxml2.cpp.o -c /home/shurik/myCodes/myGames/CowRunner_cocos/cocos2d/external/tinyxml2/tinyxml2.cpp

engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ext_tinyxml2.dir/tinyxml2.cpp.i"
	cd /home/shurik/myCodes/myGames/CowRunner_cocos/linux-build/engine/external/tinyxml2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shurik/myCodes/myGames/CowRunner_cocos/cocos2d/external/tinyxml2/tinyxml2.cpp > CMakeFiles/ext_tinyxml2.dir/tinyxml2.cpp.i

engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ext_tinyxml2.dir/tinyxml2.cpp.s"
	cd /home/shurik/myCodes/myGames/CowRunner_cocos/linux-build/engine/external/tinyxml2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shurik/myCodes/myGames/CowRunner_cocos/cocos2d/external/tinyxml2/tinyxml2.cpp -o CMakeFiles/ext_tinyxml2.dir/tinyxml2.cpp.s

# Object files for target ext_tinyxml2
ext_tinyxml2_OBJECTS = \
"CMakeFiles/ext_tinyxml2.dir/tinyxml2.cpp.o"

# External object files for target ext_tinyxml2
ext_tinyxml2_EXTERNAL_OBJECTS =

lib/libext_tinyxml2.a: engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/tinyxml2.cpp.o
lib/libext_tinyxml2.a: engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/build.make
lib/libext_tinyxml2.a: engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shurik/myCodes/myGames/CowRunner_cocos/linux-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libext_tinyxml2.a"
	cd /home/shurik/myCodes/myGames/CowRunner_cocos/linux-build/engine/external/tinyxml2 && $(CMAKE_COMMAND) -P CMakeFiles/ext_tinyxml2.dir/cmake_clean_target.cmake
	cd /home/shurik/myCodes/myGames/CowRunner_cocos/linux-build/engine/external/tinyxml2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ext_tinyxml2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/build: lib/libext_tinyxml2.a

.PHONY : engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/build

engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/clean:
	cd /home/shurik/myCodes/myGames/CowRunner_cocos/linux-build/engine/external/tinyxml2 && $(CMAKE_COMMAND) -P CMakeFiles/ext_tinyxml2.dir/cmake_clean.cmake
.PHONY : engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/clean

engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/depend:
	cd /home/shurik/myCodes/myGames/CowRunner_cocos/linux-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shurik/myCodes/myGames/CowRunner_cocos /home/shurik/myCodes/myGames/CowRunner_cocos/cocos2d/external/tinyxml2 /home/shurik/myCodes/myGames/CowRunner_cocos/linux-build /home/shurik/myCodes/myGames/CowRunner_cocos/linux-build/engine/external/tinyxml2 /home/shurik/myCodes/myGames/CowRunner_cocos/linux-build/engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : engine/external/tinyxml2/CMakeFiles/ext_tinyxml2.dir/depend
