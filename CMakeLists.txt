cmake_minimum_required(VERSION 3.16.0)
project(ARMV8_ASM )

message(STATUS "build target is ${TARGET}")

if(${TARGET} STREQUAL Linux)
add_subdirectory(Linux)
endif()

if(${TARGET} STREQUAL arm926)
add_subdirectory(arm926)
endif()

