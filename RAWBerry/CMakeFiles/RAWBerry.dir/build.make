# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /nfs/client/opt/rb/src/gpr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/client/opt/rb/src/gpr

# Include any dependencies generated for this target.
include source/app/RAWBerry/CMakeFiles/RAWBerry.dir/depend.make

# Include the progress variables for this target.
include source/app/RAWBerry/CMakeFiles/RAWBerry.dir/progress.make

# Include the compile flags for this target's objects.
include source/app/RAWBerry/CMakeFiles/RAWBerry.dir/flags.make

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/cluster.c.o: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/flags.make
source/app/RAWBerry/CMakeFiles/RAWBerry.dir/cluster.c.o: source/app/RAWBerry/cluster.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/client/opt/rb/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object source/app/RAWBerry/CMakeFiles/RAWBerry.dir/cluster.c.o"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RAWBerry.dir/cluster.c.o   -c /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/cluster.c

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/cluster.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RAWBerry.dir/cluster.c.i"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/cluster.c > CMakeFiles/RAWBerry.dir/cluster.c.i

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/cluster.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RAWBerry.dir/cluster.c.s"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/cluster.c -o CMakeFiles/RAWBerry.dir/cluster.c.s

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/collector.c.o: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/flags.make
source/app/RAWBerry/CMakeFiles/RAWBerry.dir/collector.c.o: source/app/RAWBerry/collector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/client/opt/rb/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object source/app/RAWBerry/CMakeFiles/RAWBerry.dir/collector.c.o"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RAWBerry.dir/collector.c.o   -c /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/collector.c

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/collector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RAWBerry.dir/collector.c.i"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/collector.c > CMakeFiles/RAWBerry.dir/collector.c.i

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/collector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RAWBerry.dir/collector.c.s"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/collector.c -o CMakeFiles/RAWBerry.dir/collector.c.s

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/input.c.o: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/flags.make
source/app/RAWBerry/CMakeFiles/RAWBerry.dir/input.c.o: source/app/RAWBerry/input.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/client/opt/rb/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object source/app/RAWBerry/CMakeFiles/RAWBerry.dir/input.c.o"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RAWBerry.dir/input.c.o   -c /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/input.c

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RAWBerry.dir/input.c.i"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/input.c > CMakeFiles/RAWBerry.dir/input.c.i

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RAWBerry.dir/input.c.s"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/input.c -o CMakeFiles/RAWBerry.dir/input.c.s

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/main.c.o: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/flags.make
source/app/RAWBerry/CMakeFiles/RAWBerry.dir/main.c.o: source/app/RAWBerry/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/client/opt/rb/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object source/app/RAWBerry/CMakeFiles/RAWBerry.dir/main.c.o"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RAWBerry.dir/main.c.o   -c /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/main.c

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RAWBerry.dir/main.c.i"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/main.c > CMakeFiles/RAWBerry.dir/main.c.i

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RAWBerry.dir/main.c.s"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/main.c -o CMakeFiles/RAWBerry.dir/main.c.s

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/master.c.o: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/flags.make
source/app/RAWBerry/CMakeFiles/RAWBerry.dir/master.c.o: source/app/RAWBerry/master.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/client/opt/rb/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object source/app/RAWBerry/CMakeFiles/RAWBerry.dir/master.c.o"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RAWBerry.dir/master.c.o   -c /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/master.c

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/master.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RAWBerry.dir/master.c.i"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/master.c > CMakeFiles/RAWBerry.dir/master.c.i

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/master.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RAWBerry.dir/master.c.s"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/master.c -o CMakeFiles/RAWBerry.dir/master.c.s

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/slave.c.o: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/flags.make
source/app/RAWBerry/CMakeFiles/RAWBerry.dir/slave.c.o: source/app/RAWBerry/slave.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/client/opt/rb/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object source/app/RAWBerry/CMakeFiles/RAWBerry.dir/slave.c.o"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RAWBerry.dir/slave.c.o   -c /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/slave.c

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/slave.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RAWBerry.dir/slave.c.i"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/slave.c > CMakeFiles/RAWBerry.dir/slave.c.i

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/slave.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RAWBerry.dir/slave.c.s"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/slave.c -o CMakeFiles/RAWBerry.dir/slave.c.s

# Object files for target RAWBerry
RAWBerry_OBJECTS = \
"CMakeFiles/RAWBerry.dir/cluster.c.o" \
"CMakeFiles/RAWBerry.dir/collector.c.o" \
"CMakeFiles/RAWBerry.dir/input.c.o" \
"CMakeFiles/RAWBerry.dir/main.c.o" \
"CMakeFiles/RAWBerry.dir/master.c.o" \
"CMakeFiles/RAWBerry.dir/slave.c.o"

# External object files for target RAWBerry
RAWBerry_EXTERNAL_OBJECTS =

source/app/RAWBerry/RAWBerry: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/cluster.c.o
source/app/RAWBerry/RAWBerry: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/collector.c.o
source/app/RAWBerry/RAWBerry: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/input.c.o
source/app/RAWBerry/RAWBerry: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/main.c.o
source/app/RAWBerry/RAWBerry: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/master.c.o
source/app/RAWBerry/RAWBerry: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/slave.c.o
source/app/RAWBerry/RAWBerry: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/build.make
source/app/RAWBerry/RAWBerry: source/lib/gpr_sdk/libgpr_sdk.a
source/app/RAWBerry/RAWBerry: /usr/lib/arm-linux-gnueabihf/openmpi/lib/libmpi_cxx.so
source/app/RAWBerry/RAWBerry: /usr/lib/arm-linux-gnueabihf/openmpi/lib/libmpi.so
source/app/RAWBerry/RAWBerry: source/lib/tiny_jpeg/libtiny_jpeg.a
source/app/RAWBerry/RAWBerry: source/lib/dng_sdk/libdng_sdk.a
source/app/RAWBerry/RAWBerry: source/lib/xmp_core/libxmp_core.a
source/app/RAWBerry/RAWBerry: source/lib/vc5_decoder/libvc5_decoder.a
source/app/RAWBerry/RAWBerry: source/lib/vc5_encoder/libvc5_encoder.a
source/app/RAWBerry/RAWBerry: source/lib/vc5_common/libvc5_common.a
source/app/RAWBerry/RAWBerry: source/lib/common/libcommon.a
source/app/RAWBerry/RAWBerry: source/lib/md5_lib/libmd5_lib.a
source/app/RAWBerry/RAWBerry: source/lib/expat_lib/libexpat_lib.a
source/app/RAWBerry/RAWBerry: source/app/common/cJSON/libcJSON.a
source/app/RAWBerry/RAWBerry: source/app/common/argument_parser/libargument_parser.a
source/app/RAWBerry/RAWBerry: source/app/RAWBerry/CMakeFiles/RAWBerry.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/client/opt/rb/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable RAWBerry"
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RAWBerry.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/app/RAWBerry/CMakeFiles/RAWBerry.dir/build: source/app/RAWBerry/RAWBerry

.PHONY : source/app/RAWBerry/CMakeFiles/RAWBerry.dir/build

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/clean:
	cd /nfs/client/opt/rb/src/gpr/source/app/RAWBerry && $(CMAKE_COMMAND) -P CMakeFiles/RAWBerry.dir/cmake_clean.cmake
.PHONY : source/app/RAWBerry/CMakeFiles/RAWBerry.dir/clean

source/app/RAWBerry/CMakeFiles/RAWBerry.dir/depend:
	cd /nfs/client/opt/rb/src/gpr && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/client/opt/rb/src/gpr /nfs/client/opt/rb/src/gpr/source/app/RAWBerry /nfs/client/opt/rb/src/gpr /nfs/client/opt/rb/src/gpr/source/app/RAWBerry /nfs/client/opt/rb/src/gpr/source/app/RAWBerry/CMakeFiles/RAWBerry.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/app/RAWBerry/CMakeFiles/RAWBerry.dir/depend

