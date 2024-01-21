rm -rf build
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=cmake/aarch64-linux-gcc.cmake ..
make
