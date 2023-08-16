cmake_minimum_required(VERSION 3.5)
project(log_map)
set (CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE SOURCES "src/*h")
file(GLOB_RECURSE SOURCES "src/*cpp")
add_executable(log_map ${SOURCES}) 

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

