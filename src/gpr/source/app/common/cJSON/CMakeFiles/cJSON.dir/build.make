# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr

# Include any dependencies generated for this target.
include source/app/common/cJSON/CMakeFiles/cJSON.dir/depend.make

# Include the progress variables for this target.
include source/app/common/cJSON/CMakeFiles/cJSON.dir/progress.make

# Include the compile flags for this target's objects.
include source/app/common/cJSON/CMakeFiles/cJSON.dir/flags.make

source/app/common/cJSON/CMakeFiles/cJSON.dir/cJSON.c.o: source/app/common/cJSON/CMakeFiles/cJSON.dir/flags.make
source/app/common/cJSON/CMakeFiles/cJSON.dir/cJSON.c.o: source/app/common/cJSON/cJSON.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object source/app/common/cJSON/CMakeFiles/cJSON.dir/cJSON.c.o"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cJSON.dir/cJSON.c.o   -c /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON/cJSON.c

source/app/common/cJSON/CMakeFiles/cJSON.dir/cJSON.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cJSON.dir/cJSON.c.i"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON/cJSON.c > CMakeFiles/cJSON.dir/cJSON.c.i

source/app/common/cJSON/CMakeFiles/cJSON.dir/cJSON.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cJSON.dir/cJSON.c.s"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON/cJSON.c -o CMakeFiles/cJSON.dir/cJSON.c.s

source/app/common/cJSON/CMakeFiles/cJSON.dir/cJSON_Utils.c.o: source/app/common/cJSON/CMakeFiles/cJSON.dir/flags.make
source/app/common/cJSON/CMakeFiles/cJSON.dir/cJSON_Utils.c.o: source/app/common/cJSON/cJSON_Utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object source/app/common/cJSON/CMakeFiles/cJSON.dir/cJSON_Utils.c.o"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cJSON.dir/cJSON_Utils.c.o   -c /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON/cJSON_Utils.c

source/app/common/cJSON/CMakeFiles/cJSON.dir/cJSON_Utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cJSON.dir/cJSON_Utils.c.i"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON/cJSON_Utils.c > CMakeFiles/cJSON.dir/cJSON_Utils.c.i

source/app/common/cJSON/CMakeFiles/cJSON.dir/cJSON_Utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cJSON.dir/cJSON_Utils.c.s"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON/cJSON_Utils.c -o CMakeFiles/cJSON.dir/cJSON_Utils.c.s

# Object files for target cJSON
cJSON_OBJECTS = \
"CMakeFiles/cJSON.dir/cJSON.c.o" \
"CMakeFiles/cJSON.dir/cJSON_Utils.c.o"

# External object files for target cJSON
cJSON_EXTERNAL_OBJECTS =

source/app/common/cJSON/libcJSON.a: source/app/common/cJSON/CMakeFiles/cJSON.dir/cJSON.c.o
source/app/common/cJSON/libcJSON.a: source/app/common/cJSON/CMakeFiles/cJSON.dir/cJSON_Utils.c.o
source/app/common/cJSON/libcJSON.a: source/app/common/cJSON/CMakeFiles/cJSON.dir/build.make
source/app/common/cJSON/libcJSON.a: source/app/common/cJSON/CMakeFiles/cJSON.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libcJSON.a"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON && $(CMAKE_COMMAND) -P CMakeFiles/cJSON.dir/cmake_clean_target.cmake
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cJSON.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/app/common/cJSON/CMakeFiles/cJSON.dir/build: source/app/common/cJSON/libcJSON.a

.PHONY : source/app/common/cJSON/CMakeFiles/cJSON.dir/build

source/app/common/cJSON/CMakeFiles/cJSON.dir/clean:
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON && $(CMAKE_COMMAND) -P CMakeFiles/cJSON.dir/cmake_clean.cmake
.PHONY : source/app/common/cJSON/CMakeFiles/cJSON.dir/clean

source/app/common/cJSON/CMakeFiles/cJSON.dir/depend:
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON/CMakeFiles/cJSON.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/app/common/cJSON/CMakeFiles/cJSON.dir/depend
