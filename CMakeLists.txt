cmake_minimum_required(VERSION 3.2)
project(CppTutorials)

set(CMAKE_CXX_STANDARD 14)

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

### 
add_subdirectory(src/boost)