// #include <utils/bench_utils.cpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <bench_vec/bench_vector_int.hpp>
#include <immintrin.h>
#include <utils/matrix.cpp>

void mat_fma_intrinsic ( unsigned int row, unsigned int col, 
    matrix<int16_t> & mat_src1, matrix<int16_t> & mat_src2, matrix<int16_t> & mat_dst ) {

    auto size = mat_src1.m.size();
    int16_t * src1_ptr = (int16_t *) mat_src1.m.data();
    int16_t * src2_ptr = (int16_t *) mat_src2.m.data();
    int16_t * dst_ptr  = (int16_t *) mat_dst.m.data();

    for (unsigned int i = 0; i < size; i += 16 ){
        __m256 src1 = _mm256_loadu_si256 ((__m256i_u*) (src1_ptr + i));
        __m256 src2 = _mm256_loadu_si256 ((__m256i_u*) (src2_ptr + i));
        __m256 r1 = _mm256_mullo_epi16(src1, src2);
        
        __m256 src3 = _mm256_loadu_si256 ((__m256i_u*) (dst_ptr + i));

        __m256 r2 = _mm256_add_epi16(r1, src3);
        _mm256_storeu_si256((__m256i_u*) (dst_ptr + i), r2);
    }

}

static void flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix<int16_t> &, matrix<int16_t> &, matrix<int16_t> & )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");
    srand(1);

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix<int16_t> mat_src1(row,col);
    matrix<int16_t> mat_src2(row,col);
    matrix<int16_t> mat_dst(row,col);
    matrix<int16_t> mat_dst_ref(row,col);

    for (int r = 0; r < row; r += 1) {
        for (int c = 0; c < col; c += 1) {
            // mat_src1.set(r,c, 0x7ffffffffffffff0); // rand() );
            mat_src1.set(r,c, r); // rand() );
            mat_src2.set(r,c, c); // rand() );
            mat_dst. set(r,c, r); // rand() );
            mat_dst_ref.set(r,c, mat_dst.get(r,c));
        }
    }
    
    for (auto _ : state) {
        // for (int r = 0; r < row; r += 1) {
        //     for (int c = 0; c < col; c += 1) {
        //         mat_dst. set(r,c, mat_dst_ref.get(r,c) );
        //     }
        // }
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_dst);
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            fprintf(somefile, "%hd, %hd, %hd -> %hd\n", 
                mat_src1.get(i,j), mat_src2.get(i,j), 
                mat_dst_ref.get(i,j), mat_dst.get(i,j));
        }
    }

    fclose(somefile);
}


#ifdef TEST
#define BMarg Apply(RowColSizeArgs)->Iterations(1)
#else
#define BMarg Apply(RowColSizeArgs)
#endif	
BENCHMARK_CAPTURE(flat, fma_i, &mat_fma_intrinsic)->BMarg;

BENCHMARK_MAIN();