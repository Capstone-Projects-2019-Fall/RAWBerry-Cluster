# Install script for directory: /home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/common/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_common/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_decoder/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/vc5_decoder_app/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/vc5_encoder/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/vc5_encoder_app/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/dng_sdk/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/gpr_sdk/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/xmp_core/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/expat_lib/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/md5_lib/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/lib/tiny_jpeg/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/cJSON/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/common/argument_parser/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/gpr_tools/cmake_install.cmake")
  include("/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/source/app/RAWBerry/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/greg/Documents/Capstone/RAWBerry-Cluster/src/gpr/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")