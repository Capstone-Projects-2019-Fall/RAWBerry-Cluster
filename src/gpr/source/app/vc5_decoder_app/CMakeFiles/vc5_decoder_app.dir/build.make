# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr

# Include any dependencies generated for this target.
include source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/depend.make

# Include the progress variables for this target.
include source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/progress.make

# Include the compile flags for this target's objects.
include source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/flags.make

source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.o: source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/flags.make
source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.o: source/app/vc5_decoder_app/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/vc5_decoder_app && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vc5_decoder_app.dir/main.cpp.o -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/vc5_decoder_app/main.cpp

source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vc5_decoder_app.dir/main.cpp.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/vc5_decoder_app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/vc5_decoder_app/main.cpp > CMakeFiles/vc5_decoder_app.dir/main.cpp.i

source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vc5_decoder_app.dir/main.cpp.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/vc5_decoder_app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/vc5_decoder_app/main.cpp -o CMakeFiles/vc5_decoder_app.dir/main.cpp.s

source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.o.requires:

.PHONY : source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.o.requires

source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.o.provides: source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.o.requires
	$(MAKE) -f source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/build.make source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.o.provides.build
.PHONY : source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.o.provides

source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.o.provides.build: source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.o


# Object files for target vc5_decoder_app
vc5_decoder_app_OBJECTS = \
"CMakeFiles/vc5_decoder_app.dir/main.cpp.o"

# External object files for target vc5_decoder_app
vc5_decoder_app_EXTERNAL_OBJECTS =

source/app/vc5_decoder_app/vc5_decoder_app: source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.o
source/app/vc5_decoder_app/vc5_decoder_app: source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/build.make
source/app/vc5_decoder_app/vc5_decoder_app: source/lib/vc5_decoder/libvc5_decoder.a
source/app/vc5_decoder_app/vc5_decoder_app: source/lib/vc5_common/libvc5_common.a
source/app/vc5_decoder_app/vc5_decoder_app: source/lib/common/libcommon.a
source/app/vc5_decoder_app/vc5_decoder_app: source/lib/md5_lib/libmd5_lib.a
source/app/vc5_decoder_app/vc5_decoder_app: source/app/common/argument_parser/libargument_parser.a
source/app/vc5_decoder_app/vc5_decoder_app: source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vc5_decoder_app"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/vc5_decoder_app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vc5_decoder_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/build: source/app/vc5_decoder_app/vc5_decoder_app

.PHONY : source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/build

source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/requires: source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/main.cpp.o.requires

.PHONY : source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/requires

source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/clean:
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/vc5_decoder_app && $(CMAKE_COMMAND) -P CMakeFiles/vc5_decoder_app.dir/cmake_clean.cmake
.PHONY : source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/clean

source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/depend:
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/vc5_decoder_app /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/vc5_decoder_app /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/app/vc5_decoder_app/CMakeFiles/vc5_decoder_app.dir/depend

