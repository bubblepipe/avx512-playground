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

void mat_fma_intrinsic_aligned ( unsigned int row, unsigned int col, 
    matrix<double> & mat_src1, matrix<double> & mat_src2, matrix<double> & mat_src3, matrix<double> & mat_dst ) {
    auto size = mat_src1.m.size();
    double * src1_ptr = (double *) mat_src1.m.data();
    double * src2_ptr = (double *) mat_src2.m.data();
    double * src3_ptr = (double *) mat_src3.m.data();
    double * dst_ptr  = (double *) mat_dst.m.data();

    for (int i = 0; i < size; i += 8 ){
        __m512 src1 = _mm512_loadu_pd ((const double *) (src1_ptr + i));
        __m512 src2 = _mm512_loadu_pd ((const double *) (src2_ptr + i));
        __m512 src3 = _mm512_loadu_pd ((const double *) (src3_ptr + i));
        __m512 result = _mm512_fmadd_pd(src1, src2, src3);
        _mm512_storeu_pd((double *) (dst_ptr + i), result);
    }
}

static void flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix<double> &, matrix<double> &, matrix<double> &, matrix<double> & )) {

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix<double> mat_src1(row,col);
    matrix<double> mat_src2(row,col);
    matrix<double> mat_src3(row,col);
    matrix<double> mat_dst(row,col);

fprintf(stderr,"src1_ptr: %lx\n",  (uint64_t)((double *) mat_src1.m.data()) % 64);
fprintf(stderr,"src2_ptr: %lx\n",  (uint64_t)((double *) mat_src2.m.data()) % 64);
fprintf(stderr,"src3_ptr: %lx\n",  (uint64_t)((double *) mat_src3.m.data()) % 64);
fprintf(stderr,"dst_ptr: %lx\n",   (uint64_t) ((double *) mat_dst.m.data()) % 64);

    for (int r = 0; r < row; r += 1) {
        for (int c = 0; c < col; c += 1) {
            mat_src1.set(r,c, (double)r); // rand()/1 );
            mat_src2.set(r,c, (double)c); // rand()/1 );
            mat_src3.set(r,c, (double)c); // rand()/1 );
            mat_dst. set(r,c, (double)c); // rand()/1 );
        }
    }

    for (auto _ : state) {
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_src3, mat_dst);
    }

}

BENCHMARK_CAPTURE(flat, fma_iu, &mat_fma_intrinsic_aligned)->BMarg;
BENCHMARK_MAIN();
