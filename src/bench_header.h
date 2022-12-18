#include <benchmark/benchmark.h>

#define ADD 0
#define FMA 1

#define SIZE 15
static void RowColSizeArgs(benchmark::internal::Benchmark* b) {
    // int sizes[SIZE] = {16,20,24,28,32,36,40,44,,48,56,64,128};
    int sizes[SIZE] = {16,24,32,40,48,56,64,72,80,88,96,104,112,120,128};
    // int sizes[SIZE] = {16,24,32,40,48,56,64,128};
    // int sizes[4] = {16,32,64,128};
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            b->Args({sizes[i], sizes[j]});
}