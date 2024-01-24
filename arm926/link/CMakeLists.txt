cmake_minimum_required(VERSION 3.16.0)
project(link ASM)

set_property(SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/startup.s APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")

add_executable(${PROJECT_NAME}
${CMAKE_CURRENT_SOURCE_DIR}/startup.s
${CMAKE_CURRENT_SOURCE_DIR}/data.c
)

set(ASM_FLAGS -g -O0 -march=armv5te -mtune=arm926ej-s)

target_link_options(${PROJECT_NAME}
PRIVATE
-T ${CMAKE_CURRENT_SOURCE_DIR}/linker.ld
-nostdlib
${ARM_FLAGS}
)
target_compile_options(${PROJECT_NAME}
PRIVATE
${ARM_FLAGS}

)

