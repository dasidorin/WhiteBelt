# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/dsidorin/CLion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dsidorin/CLion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dsidorin/Documents/learning/coursera/art_of_development_on_modern_cpp/white_belt/fourth_week/Rational

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dsidorin/Documents/learning/coursera/art_of_development_on_modern_cpp/white_belt/fourth_week/Rational/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Rational.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Rational.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Rational.dir/flags.make

CMakeFiles/Rational.dir/main.cpp.o: CMakeFiles/Rational.dir/flags.make
CMakeFiles/Rational.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dsidorin/Documents/learning/coursera/art_of_development_on_modern_cpp/white_belt/fourth_week/Rational/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Rational.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Rational.dir/main.cpp.o -c /home/dsidorin/Documents/learning/coursera/art_of_development_on_modern_cpp/white_belt/fourth_week/Rational/main.cpp

CMakeFiles/Rational.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Rational.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dsidorin/Documents/learning/coursera/art_of_development_on_modern_cpp/white_belt/fourth_week/Rational/main.cpp > CMakeFiles/Rational.dir/main.cpp.i

CMakeFiles/Rational.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Rational.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dsidorin/Documents/learning/coursera/art_of_development_on_modern_cpp/white_belt/fourth_week/Rational/main.cpp -o CMakeFiles/Rational.dir/main.cpp.s

# Object files for target Rational
Rational_OBJECTS = \
"CMakeFiles/Rational.dir/main.cpp.o"

# External object files for target Rational
Rational_EXTERNAL_OBJECTS =

Rational: CMakeFiles/Rational.dir/main.cpp.o
Rational: CMakeFiles/Rational.dir/build.make
Rational: CMakeFiles/Rational.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dsidorin/Documents/learning/coursera/art_of_development_on_modern_cpp/white_belt/fourth_week/Rational/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Rational"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Rational.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Rational.dir/build: Rational
.PHONY : CMakeFiles/Rational.dir/build

CMakeFiles/Rational.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Rational.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Rational.dir/clean

CMakeFiles/Rational.dir/depend:
	cd /home/dsidorin/Documents/learning/coursera/art_of_development_on_modern_cpp/white_belt/fourth_week/Rational/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dsidorin/Documents/learning/coursera/art_of_development_on_modern_cpp/white_belt/fourth_week/Rational /home/dsidorin/Documents/learning/coursera/art_of_development_on_modern_cpp/white_belt/fourth_week/Rational /home/dsidorin/Documents/learning/coursera/art_of_development_on_modern_cpp/white_belt/fourth_week/Rational/cmake-build-debug /home/dsidorin/Documents/learning/coursera/art_of_development_on_modern_cpp/white_belt/fourth_week/Rational/cmake-build-debug /home/dsidorin/Documents/learning/coursera/art_of_development_on_modern_cpp/white_belt/fourth_week/Rational/cmake-build-debug/CMakeFiles/Rational.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Rational.dir/depend

