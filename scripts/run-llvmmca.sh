src='./src/matrix-dynamic-size.cpp'
flags='-std=c++11 -I ./src/ -isystem benchmark/include  -L benchmark/build/src -l benchmark -lpthread'
clang++-15 -O3 -march=native $src $flags -S -o - | llvm-mca-15  > mca-SIMD
clang++-15 -O3 -march=native -mno-avx -mno-sse $src $flags -S -o - | llvm-mca-15  > mca-scalar