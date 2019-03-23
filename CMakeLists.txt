cmake_minimum_required(VERSION 3.0)

project(conversor VERSION 0.1 LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug")
endif(NOT CMAKE_BUILD_TYPE)
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo")

include_directories(include ${CMAKE_BINARY_DIR})

file(GLOB SOURCES src/*.cpp)

add_library(conversor ${SOURCES})

enable_testing()
add_subdirectory(test)
