# Install script for directory: /home/ds/Documents/23/PX4-Autopilot/src/lib/mixer

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
    set(CMAKE_INSTALL_CONFIG_NAME "MinSizeRel")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ds/Documents/23/PX4-Autopilot/build/nxp_fmuk66-v3_default/src/lib/mixer/MixerBase/cmake_install.cmake")
  include("/home/ds/Documents/23/PX4-Autopilot/build/nxp_fmuk66-v3_default/src/lib/mixer/HelicopterMixer/cmake_install.cmake")
  include("/home/ds/Documents/23/PX4-Autopilot/build/nxp_fmuk66-v3_default/src/lib/mixer/MultirotorMixer/cmake_install.cmake")
  include("/home/ds/Documents/23/PX4-Autopilot/build/nxp_fmuk66-v3_default/src/lib/mixer/NullMixer/cmake_install.cmake")
  include("/home/ds/Documents/23/PX4-Autopilot/build/nxp_fmuk66-v3_default/src/lib/mixer/SimpleMixer/cmake_install.cmake")

endif()

