#!/bin/bash
rm -rf build
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=cmake/arm-none-eabi-gcc.cmake -DTARGET=arm926 ..
make
