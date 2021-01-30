PREFIX=$PWD/external/deps

mkdir -p build
cd build

cmake .. -DCMAKE_TOOLCHAIN_FILE=../i686-w64-mingw32.cmake \
	-DCMAKE_INSTALL_PREFIX=${PREFIX}/../bin \
	-DCMAKE_BUILD_TYPE=MinSizeRel
make
#make install


