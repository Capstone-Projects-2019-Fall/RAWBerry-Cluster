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
include source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/depend.make

# Include the progress variables for this target.
include source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/progress.make

# Include the compile flags for this target's objects.
include source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/flags.make

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.o: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/flags.make
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.o: source/lib/vc5_decoder/wavelet.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vc5_decoder.dir/wavelet.c.o   -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/wavelet.c

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vc5_decoder.dir/wavelet.c.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/wavelet.c > CMakeFiles/vc5_decoder.dir/wavelet.c.i

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vc5_decoder.dir/wavelet.c.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/wavelet.c -o CMakeFiles/vc5_decoder.dir/wavelet.c.s

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.o.requires:

.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.o.requires

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.o.provides: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.o.requires
	$(MAKE) -f source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build.make source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.o.provides.build
.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.o.provides

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.o.provides.build: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.o


source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.o: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/flags.make
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.o: source/lib/vc5_decoder/parameters.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vc5_decoder.dir/parameters.c.o   -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/parameters.c

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vc5_decoder.dir/parameters.c.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/parameters.c > CMakeFiles/vc5_decoder.dir/parameters.c.i

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vc5_decoder.dir/parameters.c.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/parameters.c -o CMakeFiles/vc5_decoder.dir/parameters.c.s

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.o.requires:

.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.o.requires

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.o.provides: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.o.requires
	$(MAKE) -f source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build.make source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.o.provides.build
.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.o.provides

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.o.provides.build: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.o


source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.o: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/flags.make
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.o: source/lib/vc5_decoder/inverse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vc5_decoder.dir/inverse.c.o   -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/inverse.c

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vc5_decoder.dir/inverse.c.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/inverse.c > CMakeFiles/vc5_decoder.dir/inverse.c.i

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vc5_decoder.dir/inverse.c.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/inverse.c -o CMakeFiles/vc5_decoder.dir/inverse.c.s

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.o.requires:

.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.o.requires

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.o.provides: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.o.requires
	$(MAKE) -f source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build.make source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.o.provides.build
.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.o.provides

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.o.provides.build: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.o


source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.o: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/flags.make
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.o: source/lib/vc5_decoder/raw.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vc5_decoder.dir/raw.c.o   -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/raw.c

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vc5_decoder.dir/raw.c.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/raw.c > CMakeFiles/vc5_decoder.dir/raw.c.i

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vc5_decoder.dir/raw.c.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/raw.c -o CMakeFiles/vc5_decoder.dir/raw.c.s

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.o.requires:

.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.o.requires

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.o.provides: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.o.requires
	$(MAKE) -f source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build.make source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.o.provides.build
.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.o.provides

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.o.provides.build: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.o


source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.o: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/flags.make
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.o: source/lib/vc5_decoder/codebooks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vc5_decoder.dir/codebooks.c.o   -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/codebooks.c

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vc5_decoder.dir/codebooks.c.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/codebooks.c > CMakeFiles/vc5_decoder.dir/codebooks.c.i

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vc5_decoder.dir/codebooks.c.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/codebooks.c -o CMakeFiles/vc5_decoder.dir/codebooks.c.s

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.o.requires:

.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.o.requires

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.o.provides: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.o.requires
	$(MAKE) -f source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build.make source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.o.provides.build
.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.o.provides

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.o.provides.build: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.o


source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.o: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/flags.make
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.o: source/lib/vc5_decoder/dequantize.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vc5_decoder.dir/dequantize.c.o   -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/dequantize.c

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vc5_decoder.dir/dequantize.c.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/dequantize.c > CMakeFiles/vc5_decoder.dir/dequantize.c.i

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vc5_decoder.dir/dequantize.c.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/dequantize.c -o CMakeFiles/vc5_decoder.dir/dequantize.c.s

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.o.requires:

.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.o.requires

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.o.provides: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.o.requires
	$(MAKE) -f source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build.make source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.o.provides.build
.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.o.provides

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.o.provides.build: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.o


source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.o: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/flags.make
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.o: source/lib/vc5_decoder/syntax.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vc5_decoder.dir/syntax.c.o   -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/syntax.c

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vc5_decoder.dir/syntax.c.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/syntax.c > CMakeFiles/vc5_decoder.dir/syntax.c.i

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vc5_decoder.dir/syntax.c.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/syntax.c -o CMakeFiles/vc5_decoder.dir/syntax.c.s

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.o.requires:

.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.o.requires

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.o.provides: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.o.requires
	$(MAKE) -f source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build.make source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.o.provides.build
.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.o.provides

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.o.provides.build: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.o


source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.o: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/flags.make
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.o: source/lib/vc5_decoder/vlc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vc5_decoder.dir/vlc.c.o   -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/vlc.c

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vc5_decoder.dir/vlc.c.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/vlc.c > CMakeFiles/vc5_decoder.dir/vlc.c.i

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vc5_decoder.dir/vlc.c.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/vlc.c -o CMakeFiles/vc5_decoder.dir/vlc.c.s

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.o.requires:

.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.o.requires

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.o.provides: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.o.requires
	$(MAKE) -f source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build.make source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.o.provides.build
.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.o.provides

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.o.provides.build: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.o


source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/flags.make
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o: source/lib/vc5_decoder/vc5_decoder.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o   -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/vc5_decoder.c

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vc5_decoder.dir/vc5_decoder.c.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/vc5_decoder.c > CMakeFiles/vc5_decoder.dir/vc5_decoder.c.i

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vc5_decoder.dir/vc5_decoder.c.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/vc5_decoder.c -o CMakeFiles/vc5_decoder.dir/vc5_decoder.c.s

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o.requires:

.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o.requires

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o.provides: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o.requires
	$(MAKE) -f source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build.make source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o.provides.build
.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o.provides

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o.provides.build: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o


source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.o: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/flags.make
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.o: source/lib/vc5_decoder/decoder.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vc5_decoder.dir/decoder.c.o   -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/decoder.c

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vc5_decoder.dir/decoder.c.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/decoder.c > CMakeFiles/vc5_decoder.dir/decoder.c.i

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vc5_decoder.dir/decoder.c.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/decoder.c -o CMakeFiles/vc5_decoder.dir/decoder.c.s

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.o.requires:

.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.o.requires

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.o.provides: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.o.requires
	$(MAKE) -f source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build.make source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.o.provides.build
.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.o.provides

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.o.provides.build: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.o


source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.o: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/flags.make
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.o: source/lib/vc5_decoder/component.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.o"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vc5_decoder.dir/component.c.o   -c /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/component.c

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vc5_decoder.dir/component.c.i"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/component.c > CMakeFiles/vc5_decoder.dir/component.c.i

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vc5_decoder.dir/component.c.s"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/component.c -o CMakeFiles/vc5_decoder.dir/component.c.s

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.o.requires:

.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.o.requires

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.o.provides: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.o.requires
	$(MAKE) -f source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build.make source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.o.provides.build
.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.o.provides

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.o.provides.build: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.o


# Object files for target vc5_decoder
vc5_decoder_OBJECTS = \
"CMakeFiles/vc5_decoder.dir/wavelet.c.o" \
"CMakeFiles/vc5_decoder.dir/parameters.c.o" \
"CMakeFiles/vc5_decoder.dir/inverse.c.o" \
"CMakeFiles/vc5_decoder.dir/raw.c.o" \
"CMakeFiles/vc5_decoder.dir/codebooks.c.o" \
"CMakeFiles/vc5_decoder.dir/dequantize.c.o" \
"CMakeFiles/vc5_decoder.dir/syntax.c.o" \
"CMakeFiles/vc5_decoder.dir/vlc.c.o" \
"CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o" \
"CMakeFiles/vc5_decoder.dir/decoder.c.o" \
"CMakeFiles/vc5_decoder.dir/component.c.o"

# External object files for target vc5_decoder
vc5_decoder_EXTERNAL_OBJECTS =

source/lib/vc5_decoder/libvc5_decoder.a: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.o
source/lib/vc5_decoder/libvc5_decoder.a: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.o
source/lib/vc5_decoder/libvc5_decoder.a: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.o
source/lib/vc5_decoder/libvc5_decoder.a: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.o
source/lib/vc5_decoder/libvc5_decoder.a: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.o
source/lib/vc5_decoder/libvc5_decoder.a: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.o
source/lib/vc5_decoder/libvc5_decoder.a: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.o
source/lib/vc5_decoder/libvc5_decoder.a: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.o
source/lib/vc5_decoder/libvc5_decoder.a: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o
source/lib/vc5_decoder/libvc5_decoder.a: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.o
source/lib/vc5_decoder/libvc5_decoder.a: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.o
source/lib/vc5_decoder/libvc5_decoder.a: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build.make
source/lib/vc5_decoder/libvc5_decoder.a: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C static library libvc5_decoder.a"
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && $(CMAKE_COMMAND) -P CMakeFiles/vc5_decoder.dir/cmake_clean_target.cmake
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vc5_decoder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build: source/lib/vc5_decoder/libvc5_decoder.a

.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/build

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/requires: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/wavelet.c.o.requires
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/requires: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/parameters.c.o.requires
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/requires: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/inverse.c.o.requires
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/requires: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/raw.c.o.requires
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/requires: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/codebooks.c.o.requires
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/requires: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/dequantize.c.o.requires
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/requires: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/syntax.c.o.requires
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/requires: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vlc.c.o.requires
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/requires: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/vc5_decoder.c.o.requires
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/requires: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/decoder.c.o.requires
source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/requires: source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/component.c.o.requires

.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/requires

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/clean:
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder && $(CMAKE_COMMAND) -P CMakeFiles/vc5_decoder.dir/cmake_clean.cmake
.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/clean

source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/depend:
	cd /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/lib/vc5_decoder/CMakeFiles/vc5_decoder.dir/depend

