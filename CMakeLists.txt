cmake_minimum_required(VERSION 2.6)

project(BADRAY) 
message(STATUS "Bad Ray: ${PROJECT_SOURCE_DIR}")
message(STATUS "Bad Ray: ${PROJECT_BINARY_DIR}")

set(CMAKE_BUILE_TYPE DEBUG) 

set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall") 

add_subdirectory(src) 
