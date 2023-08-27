echo "********** COMPILING **********"
cd build
cmake --build .
echo "*********** RUNNING ***********"
cd ..
./bin/speck
