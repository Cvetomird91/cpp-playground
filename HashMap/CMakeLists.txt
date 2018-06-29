cmake_minimum_required (VERSION 3.5)

project (HashMap)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
include_directories("${PROJECT_SOURCE_DIR}/include/")

file (GLOB source_files "${source_dir}/*.cpp" "${PROJECT_SOURCE_DIR}/include/*.h")

add_executable (HashMap ${source_files} "main.cpp")

