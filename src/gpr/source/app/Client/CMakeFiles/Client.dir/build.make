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
include source/app/Client/CMakeFiles/Client.dir/depend.make

# Include the progress variables for this target.
include source/app/Client/CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include source/app/Client/CMakeFiles/Client.dir/flags.make

source/app/Client/CMakeFiles/Client.dir/client.cpp.o: source/app/Client/CMakeFiles/Client.dir/flags.make
source/app/Client/CMakeFiles/Client.dir/client.cpp.o: source/app/Client/client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/app/Client/CMakeFiles/Client.dir/client.cpp.o"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/client.cpp.o -c /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client/client.cpp

source/app/Client/CMakeFiles/Client.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/client.cpp.i"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client/client.cpp > CMakeFiles/Client.dir/client.cpp.i

source/app/Client/CMakeFiles/Client.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/client.cpp.s"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client/client.cpp -o CMakeFiles/Client.dir/client.cpp.s

source/app/Client/CMakeFiles/Client.dir/decode.c.o: source/app/Client/CMakeFiles/Client.dir/flags.make
source/app/Client/CMakeFiles/Client.dir/decode.c.o: source/app/Client/decode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object source/app/Client/CMakeFiles/Client.dir/decode.c.o"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/decode.c.o   -c /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client/decode.c

source/app/Client/CMakeFiles/Client.dir/decode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/decode.c.i"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client/decode.c > CMakeFiles/Client.dir/decode.c.i

source/app/Client/CMakeFiles/Client.dir/decode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/decode.c.s"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client/decode.c -o CMakeFiles/Client.dir/decode.c.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/client.cpp.o" \
"CMakeFiles/Client.dir/decode.c.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

source/app/Client/Client: source/app/Client/CMakeFiles/Client.dir/client.cpp.o
source/app/Client/Client: source/app/Client/CMakeFiles/Client.dir/decode.c.o
source/app/Client/Client: source/app/Client/CMakeFiles/Client.dir/build.make
source/app/Client/Client: source/lib/gpr_sdk/libgpr_sdk.a
source/app/Client/Client: /usr/local/Cellar/mpich/3.3.1/lib/libmpicxx.dylib
source/app/Client/Client: /usr/local/Cellar/mpich/3.3.1/lib/libmpi.dylib
source/app/Client/Client: /usr/local/Cellar/mpich/3.3.1/lib/libpmpi.dylib
source/app/Client/Client: source/lib/tiny_jpeg/libtiny_jpeg.a
source/app/Client/Client: source/lib/dng_sdk/libdng_sdk.a
source/app/Client/Client: source/lib/xmp_core/libxmp_core.a
source/app/Client/Client: source/lib/vc5_decoder/libvc5_decoder.a
source/app/Client/Client: source/lib/vc5_encoder/libvc5_encoder.a
source/app/Client/Client: source/lib/vc5_common/libvc5_common.a
source/app/Client/Client: source/lib/common/libcommon.a
source/app/Client/Client: source/lib/md5_lib/libmd5_lib.a
source/app/Client/Client: source/lib/expat_lib/libexpat_lib.a
source/app/Client/Client: source/app/common/cJSON/libcJSON.a
source/app/Client/Client: source/app/common/argument_parser/libargument_parser.a
source/app/Client/Client: source/app/Client/CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Client"
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/app/Client/CMakeFiles/Client.dir/build: source/app/Client/Client

.PHONY : source/app/Client/CMakeFiles/Client.dir/build

source/app/Client/CMakeFiles/Client.dir/clean:
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client && $(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : source/app/Client/CMakeFiles/Client.dir/clean

source/app/Client/CMakeFiles/Client.dir/depend:
	cd /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client /Users/user/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/Client/CMakeFiles/Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/app/Client/CMakeFiles/Client.dir/depend
