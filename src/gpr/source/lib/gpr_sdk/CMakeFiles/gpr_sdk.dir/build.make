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
CMAKE_SOURCE_DIR = /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr

# Include any dependencies generated for this target.
include source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/depend.make

# Include the progress variables for this target.
include source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/progress.make

# Include the compile flags for this target's objects.
include source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/flags.make

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr.cpp.o: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/flags.make
source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr.cpp.o: source/lib/gpr_sdk/private/gpr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr.cpp.o"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gpr_sdk.dir/private/gpr.cpp.o -c /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr.cpp

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpr_sdk.dir/private/gpr.cpp.i"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr.cpp > CMakeFiles/gpr_sdk.dir/private/gpr.cpp.i

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpr_sdk.dir/private/gpr.cpp.s"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr.cpp -o CMakeFiles/gpr_sdk.dir/private/gpr.cpp.s

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_exif_info.cpp.o: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/flags.make
source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_exif_info.cpp.o: source/lib/gpr_sdk/private/gpr_exif_info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_exif_info.cpp.o"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gpr_sdk.dir/private/gpr_exif_info.cpp.o -c /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_exif_info.cpp

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_exif_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpr_sdk.dir/private/gpr_exif_info.cpp.i"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_exif_info.cpp > CMakeFiles/gpr_sdk.dir/private/gpr_exif_info.cpp.i

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_exif_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpr_sdk.dir/private/gpr_exif_info.cpp.s"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_exif_info.cpp -o CMakeFiles/gpr_sdk.dir/private/gpr_exif_info.cpp.s

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_image_writer.cpp.o: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/flags.make
source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_image_writer.cpp.o: source/lib/gpr_sdk/private/gpr_image_writer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_image_writer.cpp.o"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gpr_sdk.dir/private/gpr_image_writer.cpp.o -c /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_image_writer.cpp

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_image_writer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpr_sdk.dir/private/gpr_image_writer.cpp.i"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_image_writer.cpp > CMakeFiles/gpr_sdk.dir/private/gpr_image_writer.cpp.i

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_image_writer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpr_sdk.dir/private/gpr_image_writer.cpp.s"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_image_writer.cpp -o CMakeFiles/gpr_sdk.dir/private/gpr_image_writer.cpp.s

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_profile_info.cpp.o: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/flags.make
source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_profile_info.cpp.o: source/lib/gpr_sdk/private/gpr_profile_info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_profile_info.cpp.o"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gpr_sdk.dir/private/gpr_profile_info.cpp.o -c /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_profile_info.cpp

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_profile_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpr_sdk.dir/private/gpr_profile_info.cpp.i"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_profile_info.cpp > CMakeFiles/gpr_sdk.dir/private/gpr_profile_info.cpp.i

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_profile_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpr_sdk.dir/private/gpr_profile_info.cpp.s"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_profile_info.cpp -o CMakeFiles/gpr_sdk.dir/private/gpr_profile_info.cpp.s

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_read_image.cpp.o: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/flags.make
source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_read_image.cpp.o: source/lib/gpr_sdk/private/gpr_read_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_read_image.cpp.o"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gpr_sdk.dir/private/gpr_read_image.cpp.o -c /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_read_image.cpp

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_read_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpr_sdk.dir/private/gpr_read_image.cpp.i"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_read_image.cpp > CMakeFiles/gpr_sdk.dir/private/gpr_read_image.cpp.i

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_read_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpr_sdk.dir/private/gpr_read_image.cpp.s"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_read_image.cpp -o CMakeFiles/gpr_sdk.dir/private/gpr_read_image.cpp.s

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_tuning_info.cpp.o: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/flags.make
source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_tuning_info.cpp.o: source/lib/gpr_sdk/private/gpr_tuning_info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_tuning_info.cpp.o"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gpr_sdk.dir/private/gpr_tuning_info.cpp.o -c /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_tuning_info.cpp

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_tuning_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpr_sdk.dir/private/gpr_tuning_info.cpp.i"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_tuning_info.cpp > CMakeFiles/gpr_sdk.dir/private/gpr_tuning_info.cpp.i

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_tuning_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpr_sdk.dir/private/gpr_tuning_info.cpp.s"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_tuning_info.cpp -o CMakeFiles/gpr_sdk.dir/private/gpr_tuning_info.cpp.s

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_utils.cpp.o: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/flags.make
source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_utils.cpp.o: source/lib/gpr_sdk/private/gpr_utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_utils.cpp.o"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gpr_sdk.dir/private/gpr_utils.cpp.o -c /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_utils.cpp

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpr_sdk.dir/private/gpr_utils.cpp.i"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_utils.cpp > CMakeFiles/gpr_sdk.dir/private/gpr_utils.cpp.i

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpr_sdk.dir/private/gpr_utils.cpp.s"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/private/gpr_utils.cpp -o CMakeFiles/gpr_sdk.dir/private/gpr_utils.cpp.s

# Object files for target gpr_sdk
gpr_sdk_OBJECTS = \
"CMakeFiles/gpr_sdk.dir/private/gpr.cpp.o" \
"CMakeFiles/gpr_sdk.dir/private/gpr_exif_info.cpp.o" \
"CMakeFiles/gpr_sdk.dir/private/gpr_image_writer.cpp.o" \
"CMakeFiles/gpr_sdk.dir/private/gpr_profile_info.cpp.o" \
"CMakeFiles/gpr_sdk.dir/private/gpr_read_image.cpp.o" \
"CMakeFiles/gpr_sdk.dir/private/gpr_tuning_info.cpp.o" \
"CMakeFiles/gpr_sdk.dir/private/gpr_utils.cpp.o"

# External object files for target gpr_sdk
gpr_sdk_EXTERNAL_OBJECTS =

source/lib/gpr_sdk/libgpr_sdk.a: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr.cpp.o
source/lib/gpr_sdk/libgpr_sdk.a: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_exif_info.cpp.o
source/lib/gpr_sdk/libgpr_sdk.a: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_image_writer.cpp.o
source/lib/gpr_sdk/libgpr_sdk.a: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_profile_info.cpp.o
source/lib/gpr_sdk/libgpr_sdk.a: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_read_image.cpp.o
source/lib/gpr_sdk/libgpr_sdk.a: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_tuning_info.cpp.o
source/lib/gpr_sdk/libgpr_sdk.a: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/private/gpr_utils.cpp.o
source/lib/gpr_sdk/libgpr_sdk.a: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/build.make
source/lib/gpr_sdk/libgpr_sdk.a: source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libgpr_sdk.a"
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && $(CMAKE_COMMAND) -P CMakeFiles/gpr_sdk.dir/cmake_clean_target.cmake
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gpr_sdk.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/build: source/lib/gpr_sdk/libgpr_sdk.a

.PHONY : source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/build

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/clean:
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk && $(CMAKE_COMMAND) -P CMakeFiles/gpr_sdk.dir/cmake_clean.cmake
.PHONY : source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/clean

source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/depend:
	cd /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk /home/pi/Desktop/Working/Good/RAWBerry-Cluster-milestone-2-demo/src/gpr/source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/lib/gpr_sdk/CMakeFiles/gpr_sdk.dir/depend

