# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/langelog/Desktop/lnn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/langelog/Desktop/lnn/build

# Include any dependencies generated for this target.
include libraries/lnn/CMakeFiles/lnn.dir/depend.make

# Include the progress variables for this target.
include libraries/lnn/CMakeFiles/lnn.dir/progress.make

# Include the compile flags for this target's objects.
include libraries/lnn/CMakeFiles/lnn.dir/flags.make

libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.o: libraries/lnn/CMakeFiles/lnn.dir/flags.make
libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.o: ../libraries/lnn/src/Neuron.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/langelog/Desktop/lnn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.o"
	cd /Users/langelog/Desktop/lnn/build/libraries/lnn && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lnn.dir/src/Neuron.cpp.o -c /Users/langelog/Desktop/lnn/libraries/lnn/src/Neuron.cpp

libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lnn.dir/src/Neuron.cpp.i"
	cd /Users/langelog/Desktop/lnn/build/libraries/lnn && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/langelog/Desktop/lnn/libraries/lnn/src/Neuron.cpp > CMakeFiles/lnn.dir/src/Neuron.cpp.i

libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lnn.dir/src/Neuron.cpp.s"
	cd /Users/langelog/Desktop/lnn/build/libraries/lnn && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/langelog/Desktop/lnn/libraries/lnn/src/Neuron.cpp -o CMakeFiles/lnn.dir/src/Neuron.cpp.s

libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.o.requires:

.PHONY : libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.o.requires

libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.o.provides: libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.o.requires
	$(MAKE) -f libraries/lnn/CMakeFiles/lnn.dir/build.make libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.o.provides.build
.PHONY : libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.o.provides

libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.o.provides.build: libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.o


# Object files for target lnn
lnn_OBJECTS = \
"CMakeFiles/lnn.dir/src/Neuron.cpp.o"

# External object files for target lnn
lnn_EXTERNAL_OBJECTS =

libraries/lnn/liblnn.a: libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.o
libraries/lnn/liblnn.a: libraries/lnn/CMakeFiles/lnn.dir/build.make
libraries/lnn/liblnn.a: libraries/lnn/CMakeFiles/lnn.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/langelog/Desktop/lnn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblnn.a"
	cd /Users/langelog/Desktop/lnn/build/libraries/lnn && $(CMAKE_COMMAND) -P CMakeFiles/lnn.dir/cmake_clean_target.cmake
	cd /Users/langelog/Desktop/lnn/build/libraries/lnn && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lnn.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libraries/lnn/CMakeFiles/lnn.dir/build: libraries/lnn/liblnn.a

.PHONY : libraries/lnn/CMakeFiles/lnn.dir/build

libraries/lnn/CMakeFiles/lnn.dir/requires: libraries/lnn/CMakeFiles/lnn.dir/src/Neuron.cpp.o.requires

.PHONY : libraries/lnn/CMakeFiles/lnn.dir/requires

libraries/lnn/CMakeFiles/lnn.dir/clean:
	cd /Users/langelog/Desktop/lnn/build/libraries/lnn && $(CMAKE_COMMAND) -P CMakeFiles/lnn.dir/cmake_clean.cmake
.PHONY : libraries/lnn/CMakeFiles/lnn.dir/clean

libraries/lnn/CMakeFiles/lnn.dir/depend:
	cd /Users/langelog/Desktop/lnn/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/langelog/Desktop/lnn /Users/langelog/Desktop/lnn/libraries/lnn /Users/langelog/Desktop/lnn/build /Users/langelog/Desktop/lnn/build/libraries/lnn /Users/langelog/Desktop/lnn/build/libraries/lnn/CMakeFiles/lnn.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libraries/lnn/CMakeFiles/lnn.dir/depend
