cmake_minimum_required (VERSION 2.8.12)

set( CMAKE_BUILD_TYPE Debug)
set( CMAKE_CXX_FLAGS "-O0 -g3 -DDEBUG -D_DEBUG -Wall -pedantic -std=c++0x -pthread" CACHE STRING "Debug options" FORCE)
set( CMAKE_CXX_FLAGS "-O2 -DNDEBUG -Wall -pedantic -std=c++0x -rdynamic -pthread" CACHE STRING "Release options" FORCE)

enable_testing()

add_subdirectory(ext/gtest)
add_subdirectory(SimpleDataStructures)
