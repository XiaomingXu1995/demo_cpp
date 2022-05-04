set -x

mkdir -p bin
g++ src/sizeof.cpp -o bin/test_sizeof
g++ src/bloomFilter.cpp -O3 -o bin/test_bloomFilter
g++ src/bloomFilter_ontime.cpp -O3 -o bin/test_bloomFilterOntime
