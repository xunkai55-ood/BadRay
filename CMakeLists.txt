cmake_minimum_required(VERSION 2.6)

project(BADRAY) 
message(STATUS "Bad Ray: ${PROJECT_SOURCE_DIR}")
message(STATUS "Bad Ray: ${PROJECT_BINARY_DIR}")

set(CMAKE_BUILD_TYPE RELEASE) 

message("Build: ${CMAKE_BUILD_TYPE}")
message("Flags: ${CMAKE_CXX_FLAGS_RELEASE}")

add_subdirectory(src) 
