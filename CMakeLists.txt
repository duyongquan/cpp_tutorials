cmake_minimum_required(VERSION 3.2)
project(CppTutorials)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")

set(PROTOOLS_MAJOR_VERSION 0)
set(PROTOOLS_MINOR_VERSION 0)
set(PROTOOLS_PATCH_VERSION 1)
set(PROTOOLS_VERSION ${PROTOOLS_MAJOR_VERSION}.${PROTOOLS_MINOR_VERSION}.${PROTOOLS_PATCH_VERSION})
set(PROTOOLS_SOVERSION ${PROTOOLS_MAJOR_VERSION}.${PROTOOLS_MINOR_VERSION})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

option(BUILD_TEST  "Project build test" ON)

include("${PROJECT_SOURCE_DIR}/cmake/functions.cmake")
project_initialize()
project_enable_testing()

find_package(Eigen3 REQUIRED)
find_package(benchmark REQUIRED)
find_package(Threads REQUIRED)
find_library(GPERFTOOLS_LIBRARIES NAMES profiler)

### boost ### 
# add_subdirectory(src/boost)

### cpp20 ### 
add_subdirectory(src/cpp20)

### utils ### 
add_subdirectory(src/utils)