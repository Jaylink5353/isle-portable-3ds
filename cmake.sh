rm -fr ~/isle-portable-3ds/build
cmake -S. -Bbuild -DCMAKE_TOOLCHAIN_FILE="$DEVKITPRO/cmake/3DS.cmake" -DCMAKE_BUILD_TYPE=Release -DISLE_BUILD_CONFIG=OFF
cd build 
make
