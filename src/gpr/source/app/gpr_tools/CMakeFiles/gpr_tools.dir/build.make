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
include source/app/gpr_tools/CMakeFiles/gpr_tools.dir/depend.make

# Include the progress variables for this target.
include source/app/gpr_tools/CMakeFiles/gpr_tools.dir/progress.make

# Include the compile flags for this target's objects.
include source/app/gpr_tools/CMakeFiles/gpr_tools.dir/flags.make

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.o: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/flags.make
source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.o: source/app/gpr_tools/main_c.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gpr_tools.dir/main_c.c.o   -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/main_c.c

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gpr_tools.dir/main_c.c.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/main_c.c > CMakeFiles/gpr_tools.dir/main_c.c.i

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gpr_tools.dir/main_c.c.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/main_c.c -o CMakeFiles/gpr_tools.dir/main_c.c.s

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.o.requires:

.PHONY : source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.o.requires

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.o.provides: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.o.requires
	$(MAKE) -f source/app/gpr_tools/CMakeFiles/gpr_tools.dir/build.make source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.o.provides.build
.PHONY : source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.o.provides

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.o.provides.build: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.o


source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/flags.make
source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o: source/app/gpr_tools/gpr_print_utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/gpr_print_utils.cpp

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/gpr_print_utils.cpp > CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.i

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/gpr_print_utils.cpp -o CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.s

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o.requires:

.PHONY : source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o.requires

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o.provides: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o.requires
	$(MAKE) -f source/app/gpr_tools/CMakeFiles/gpr_tools.dir/build.make source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o.provides.build
.PHONY : source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o.provides

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o.provides.build: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o


source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.o: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/flags.make
source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.o: source/app/gpr_tools/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gpr_tools.dir/main.cpp.o -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/main.cpp

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpr_tools.dir/main.cpp.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/main.cpp > CMakeFiles/gpr_tools.dir/main.cpp.i

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpr_tools.dir/main.cpp.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/main.cpp -o CMakeFiles/gpr_tools.dir/main.cpp.s

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.o.requires:

.PHONY : source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.o.requires

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.o.provides: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.o.requires
	$(MAKE) -f source/app/gpr_tools/CMakeFiles/gpr_tools.dir/build.make source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.o.provides.build
.PHONY : source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.o.provides

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.o.provides.build: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.o


source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/flags.make
source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o: source/app/gpr_tools/gpr_parse_utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/gpr_parse_utils.cpp

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/gpr_parse_utils.cpp > CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.i

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/gpr_parse_utils.cpp -o CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.s

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o.requires:

.PHONY : source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o.requires

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o.provides: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o.requires
	$(MAKE) -f source/app/gpr_tools/CMakeFiles/gpr_tools.dir/build.make source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o.provides.build
.PHONY : source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o.provides

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o.provides.build: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o


# Object files for target gpr_tools
gpr_tools_OBJECTS = \
"CMakeFiles/gpr_tools.dir/main_c.c.o" \
"CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o" \
"CMakeFiles/gpr_tools.dir/main.cpp.o" \
"CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o"

# External object files for target gpr_tools
gpr_tools_EXTERNAL_OBJECTS =

source/app/gpr_tools/gpr_tools: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.o
source/app/gpr_tools/gpr_tools: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o
source/app/gpr_tools/gpr_tools: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.o
source/app/gpr_tools/gpr_tools: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o
source/app/gpr_tools/gpr_tools: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/build.make
source/app/gpr_tools/gpr_tools: source/lib/gpr_sdk/libgpr_sdk.a
source/app/gpr_tools/gpr_tools: source/lib/tiny_jpeg/libtiny_jpeg.a
source/app/gpr_tools/gpr_tools: source/lib/dng_sdk/libdng_sdk.a
source/app/gpr_tools/gpr_tools: source/lib/xmp_core/libxmp_core.a
source/app/gpr_tools/gpr_tools: source/lib/vc5_decoder/libvc5_decoder.a
source/app/gpr_tools/gpr_tools: source/lib/vc5_encoder/libvc5_encoder.a
source/app/gpr_tools/gpr_tools: source/lib/vc5_common/libvc5_common.a
source/app/gpr_tools/gpr_tools: source/lib/common/libcommon.a
source/app/gpr_tools/gpr_tools: source/lib/md5_lib/libmd5_lib.a
source/app/gpr_tools/gpr_tools: source/lib/expat_lib/libexpat_lib.a
source/app/gpr_tools/gpr_tools: source/app/common/cJSON/libcJSON.a
source/app/gpr_tools/gpr_tools: source/app/common/argument_parser/libargument_parser.a
source/app/gpr_tools/gpr_tools: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable gpr_tools"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gpr_tools.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/app/gpr_tools/CMakeFiles/gpr_tools.dir/build: source/app/gpr_tools/gpr_tools

.PHONY : source/app/gpr_tools/CMakeFiles/gpr_tools.dir/build

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/requires: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main_c.c.o.requires
source/app/gpr_tools/CMakeFiles/gpr_tools.dir/requires: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_print_utils.cpp.o.requires
source/app/gpr_tools/CMakeFiles/gpr_tools.dir/requires: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/main.cpp.o.requires
source/app/gpr_tools/CMakeFiles/gpr_tools.dir/requires: source/app/gpr_tools/CMakeFiles/gpr_tools.dir/gpr_parse_utils.cpp.o.requires

.PHONY : source/app/gpr_tools/CMakeFiles/gpr_tools.dir/requires

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/clean:
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools && $(CMAKE_COMMAND) -P CMakeFiles/gpr_tools.dir/cmake_clean.cmake
.PHONY : source/app/gpr_tools/CMakeFiles/gpr_tools.dir/clean

source/app/gpr_tools/CMakeFiles/gpr_tools.dir/depend:
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/CMakeFiles/gpr_tools.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/app/gpr_tools/CMakeFiles/gpr_tools.dir/depend
