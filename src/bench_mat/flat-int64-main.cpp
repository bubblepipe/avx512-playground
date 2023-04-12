// #include <utils/bench_utils.cpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <bench_vec/bench_vector_int.hpp>
#include <immintrin.h>
#include <utils/matrix.cpp>

void overflow_handler()
{
    printf("overflow!\n");
    exit(0);
}

void mat_fma_scalar_inacurate_check ( unsigned int row, unsigned int col, 
    matrix<int64_t> & mat_src1, matrix<int64_t> & mat_src2, matrix<int64_t> & mat_src3, matrix<int64_t> & mat_dst ) {
    bool overflow = false;
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            int64_t r1, r2;
            int64_t src1 = mat_src1.get(i,j);
            int64_t src2 = mat_src2.get(i,j);
            int64_t src3 = mat_src3.get(i,j);

            overflow |= __builtin_mul_overflow(src1, src2, &r1);
            overflow |= __builtin_add_overflow(r1, src3, &r2);

            mat_dst.set(i,j,  r2);
        }
    }
    if (overflow) {
        overflow_handler();
    } 
}


void mat_fma ( unsigned int row, unsigned int col, 
    matrix<int64_t> & mat_src1, matrix<int64_t> & mat_src2, matrix<int64_t> & mat_src3, matrix<int64_t> & mat_dst ) {
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            int64_t src1 = mat_src1.get(i,j);
            int64_t src2 = mat_src2.get(i,j);
            int64_t src3 = mat_src3.get(i,j);
            mat_dst.set(i,j,  (src1 * src2) + src3);
        }
    }
}
void mat_add ( unsigned int row, unsigned int col, 
    matrix<int64_t> & mat_src1, matrix<int64_t> & mat_src2, matrix<int64_t> & mat_src3, matrix<int64_t> & mat_dst ) {

    auto size = mat_src1.m.size();
    int64_t * src1_ptr = (int64_t *) mat_src1.m.data();
    int64_t * src2_ptr = (int64_t *) mat_src2.m.data();
    int64_t * dst_ptr  = (int64_t *) mat_dst.m.data();
    exit(0);
}



 
#undef AVX512_ENABLED
#ifdef AVX512_ENABLED

void mat_add_manual ( unsigned int row, unsigned int col, 
    matrix<int64_t> & mat_src1, matrix<int64_t> & mat_src2, matrix<int64_t> & mat_src3, matrix<int64_t> & mat_dst ) {
    
    auto size = mat_src1.m.size();
    
    if (size % 8 != 0) {
        throw std::runtime_error(std::string("size not div by 8"));
    }

    int64_t * src1_ptr = (int64_t *) mat_src1.m.data();
    int64_t * src2_ptr = (int64_t *) mat_src2.m.data();
    int64_t * dst_ptr  = (int64_t *) mat_dst.m.data();

    for (int64_t i = 0; i < size; i += 8 ){
        __m256 src1 = _mm256_loadu_si256 ((__m256i_u*) (src1_ptr + i));
        __m256 src2 = _mm256_loadu_si256 ((__m256i_u*) (src2_ptr + i));
        __m256 result = _mm256_add_epi64(src1, src2);
        _mm256_storeu_si256((__m256i_u*) (dst_ptr + i), result);
    }

}

void mat_fma_manual ( unsigned int row, unsigned int col, 
    matrix<int64_t> & mat_src1, matrix<int64_t> & mat_src2, matrix<int64_t> & mat_src3, matrix<int64_t> & mat_dst ) {
    auto size = mat_src1.m.size();
    int64_t * src1_ptr = (int64_t *) mat_src1.m.data();
    int64_t * src2_ptr = (int64_t *) mat_src2.m.data();
    int64_t * src3_ptr = (int64_t *) mat_src3.m.data();
    int64_t * dst_ptr  = (int64_t *) mat_dst.m.data();

    for (int64_t i = 0; i < size; i += 4 ){
        __m256 src1 = _mm256_loadu_si256 ((__m256i_u*) (src1_ptr + i));
        __m256 src2 = _mm256_loadu_si256 ((__m256i_u*) (src2_ptr + i));
        __m256 r1 = _mm256_mullo_epi32(src1, src2);
        
        __m256 src3 = _mm256_loadu_si256 ((__m256i_u*) (src3_ptr + i));

        __m256 r2 = _mm256_add_epi32(r1, src3);
        _mm256_storeu_si256((__m256i_u*) (dst_ptr + i), r2);
    }
}

void mat_fma_manual_inacurate_check ( unsigned int row, unsigned int col, 
    matrix<int64_t> & mat_src1, matrix<int64_t> & mat_src2, matrix<int64_t> & mat_src3, matrix<int64_t> & mat_dst ) {
    auto size = mat_src1.m.size();
    int64_t * src1_ptr = (int64_t *) mat_src1.m.data();
    int64_t * src2_ptr = (int64_t *) mat_src2.m.data();
    int64_t * src3_ptr = (int64_t *) mat_src3.m.data();
    int64_t * dst_ptr  = (int64_t *) mat_dst.m.data();

    for (int64_t i = 0; i < size; i += 8 ){
        __m256 src1 = _mm256_loadu_si256 ((__m256i_u*) (src1_ptr + i));
        __m256 src2 = _mm256_loadu_si256 ((__m256i_u*) (src2_ptr + i));
        __m256 r1 = _mm256_mullo_epi32(src1, src2);
        
        __m256 src3 = _mm256_loadu_si256 ((__m256i_u*) (src3_ptr + i));

        __m256 r2 = _mm256_add_epi32(r1, src3);
        _mm256_storeu_si256((__m256i_u*) (dst_ptr + i), r2);
        
        // TODO
        
        exit(0);
    }
}
#endif
static void flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix<int64_t> &, matrix<int64_t> &, matrix<int64_t> &, matrix<int64_t> & )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");
    srand(1);

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix<int64_t> mat_src1(row,col);
    matrix<int64_t> mat_src2(row,col);
    matrix<int64_t> mat_src3(row,col);
    matrix<int64_t> mat_dst(row,col);

    for (int r = 0; r < row; r += 1) {
        for (int c = 0; c < col; c += 1) {
            // mat_src1.set(r,c, 0x7ffffffffffffff0); // rand() );
            mat_src1.set(r,c, rand() );
            mat_src2.set(r,c, rand() );
            mat_src3.set(r,c, rand() );
            mat_dst. set(r,c, rand() );
        }
    }
    
    for (auto _ : state) {
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_src3, mat_dst);
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            fprintf(somefile, "%ld, %ld, %ld -> %ld\n", 
                mat_src1.get(i,j), mat_src2.get(i,j), 
                mat_src3.get(i,j), mat_dst.get(i,j));
        }
    }

    fclose(somefile);
}

BENCHMARK_CAPTURE(flat, add, &mat_add)->BMarg;
BENCHMARK_CAPTURE(flat, fma, &mat_fma)->BMarg;
BENCHMARK_CAPTURE(flat, fma_s_check, &mat_fma_scalar_inacurate_check)->BMarg;

#ifdef AVX512_ENABLED
BENCHMARK_CAPTURE(flat, add_m, &mat_add_manual)->BMarg;
BENCHMARK_CAPTURE(flat, fma_i, &mat_fma_manual)->BMarg;
BENCHMARK_CAPTURE(flat, fma_m_acurate, &mat_fma_manual_inacurate_check)->BMarg;
#endif
BENCHMARK_MAIN();