#include <benchmark/benchmark.h>

// #define SIZE 4
#define SIZE 15
static void RowColSizeArgs(benchmark::internal::Benchmark* b) {
    int sizes[SIZE] = {16,24,32,40,48,56,64,72,80,88,96,104,112,120,128};
    // int sizes[SIZE] = {16,24,32,40,48,56,64,128};
    // int sizes[SIZE] = {16,32,64,128};
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            b->Args({sizes[i], sizes[j]});


// bench_matrix_flatvector/fma/32/40          525 ns 
// bench_matrix_flatvector/fma/32/48          866 ns 
// bench_matrix_flatvector/fma/32/56          956 ns 
// bench_matrix_flatvector/fma/32/64          888 ns 
    // b->Args({32, 56}); 
    // b->Args({32, 64}); 

    // this is for matrix add vectorvector
    // b->Args({128, 24});
    // b->Args({128, 32});
    // b->Args({128, 33});
}