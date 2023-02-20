#include <benchmark/benchmark.h>
#include <simdpp/simd.h>

#ifdef TEST
#define BMarg Apply(RowColSizeArgs)->Iterations(1)
#else
#define BMarg Apply(RowColSizeArgs)
#endif	

// #define SIZE 4
// #define SIZE 9
// #define SIZE 4
static void RowColSizeArgs(benchmark::internal::Benchmark* b) {
    
    #ifdef SIZE_8_16_32
        
    #define SIZE 3
    int sizes[SIZE] = {8,16,32};
    for (int i = 0; i < SIZE; ++i){
        int row = 8;
        int col = sizes[i];
        b->Args({row, col});
    }

    #else

        #ifdef SIZE_BIG
        #define SIZE 15
        int sizes[SIZE] = {16,24,32,40,48,56,64,72,80,88,96,104,112,120,128};
        #elif SIZE_MODERATE
        #define SIZE 4
        int sizes[SIZE] = {8,16,24,32};
        #else
        #define SIZE 4
        int sizes[SIZE] = {4, 8, 12, 16};
        #endif
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                b->Args({sizes[i], sizes[j]});
    #endif



// bench_matrix_flatvector/fma/32/40          525 ns 
// bench_matrix_flatvector/fma/32/48          866 ns 
// bench_matrix_flatvector/fma/32/56          956 ns 
// bench_matrix_flatvector/fma/32/64          888 ns 
    // b->Args({32, 48}); 
    // b->Args({32, 56}); 
    // b->Args({32, 64}); 

    // this is for matrix add vectorvector
    // b->Args({128, 24});
    // b->Args({128, 32});
    // b->Args({128, 33});

    // b->Args({88,72});
    // b->Args({88,80});
    // b->Args({88,88});

}