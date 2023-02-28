#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <simdpp/simd.h>
#include <cfenv>
#include <utils/cfenv_local.cpp>
#include <utils/matrix.cpp>
#include <utils/bench_utils.cpp>
#include <x86intrin.h>
#include <immintrin.h>

typedef double doubleZmm __attribute__((ext_vector_type(8)));

void mat_fma_intrinsic_aligned ( unsigned int row, unsigned int col, 
    matrix<__m512d> & mat_src1, matrix<__m512d> & mat_src2, matrix<__m512d> & mat_src3, matrix<__m512d> & mat_dst ) {
    auto size = mat_src1.m.size();
    __m512d * src1_ptr = (__m512d *) mat_src1.m.data();
    __m512d * src2_ptr = (__m512d *) mat_src2.m.data();
    __m512d * src3_ptr = (__m512d *) mat_src3.m.data();
    __m512d * dst_ptr  = (__m512d *) mat_dst.m.data();


    for (int i = 0; i < size; i += 8 ){
        __m512 src1 = _mm512_load_pd ((const __m512d *) (src1_ptr + i));
        __m512 src2 = _mm512_load_pd ((const __m512d *) (src2_ptr + i));
        __m512 src3 = _mm512_load_pd ((const __m512d *) (src3_ptr + i));
        __m512 result = _mm512_fmadd_pd(src1, src2, src3);
        _mm512_store_pd((__m512d *) (dst_ptr + i), result);
    }
}

static void flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix<__m512d> &, matrix<__m512d> &, matrix<__m512d> &, matrix<__m512d> & )) {

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix<__m512d> mat_src1(row,col);
    matrix<__m512d> mat_src2(row,col);
    matrix<__m512d> mat_src3(row,col);
    matrix<__m512d> mat_dst(row,col);

fprintf(stderr,"src1_ptr: %lx\n",  (uint64_t)((double *) mat_src1.m.data()) % 64);
fprintf(stderr,"src2_ptr: %lx\n",  (uint64_t)((double *) mat_src2.m.data()) % 64);
fprintf(stderr,"src3_ptr: %lx\n",  (uint64_t)((double *) mat_src3.m.data()) % 64);
fprintf(stderr,"dst_ptr: %lx\n",   (uint64_t)((double *) mat_dst.m.data())  % 64);

    for (int r = 0; r < row; r += 1) {
        for (int c = 0; c < col; c += 1) {
            mat_src1.set(r,c, (doubleZmm)r); // rand()/1 );
            mat_src2.set(r,c, (doubleZmm)c); // rand()/1 );
            mat_src3.set(r,c, (doubleZmm)c); // rand()/1 );
            mat_dst. set(r,c, (doubleZmm)c); // rand()/1 );
        }
    }

    for (auto _ : state) {
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_src3, mat_dst);
    }

}

BENCHMARK_CAPTURE(flat, fma_ia, &mat_fma_intrinsic_aligned)->BMarg;
BENCHMARK_MAIN();
