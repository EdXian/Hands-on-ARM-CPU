cmake_minimum_required(VERSION 3.16.0)
project(hello ASM)

set_property(SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/hello.s APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")

add_executable(${PROJECT_NAME}
${CMAKE_CURRENT_SOURCE_DIR}/hello.s
)

set(ASM_FLAGS -g -O0 -march=armv5te -mtune=arm926ej-s)

target_link_options(${PROJECT_NAME}
PRIVATE
${ARM_FLAGS}
-nostdlib
)
target_compile_options(${PROJECT_NAME}
PRIVATE
${ARM_FLAGS}
)

