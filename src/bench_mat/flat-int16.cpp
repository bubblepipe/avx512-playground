#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <bench_vec/bench_vector_int.hpp>
#include <immintrin.h>
#include <utils/matrix.cpp>
#include <utils/int16_utils.cpp>

#ifdef AVX512_ENABLED

void mat_fma_intrinsic ( unsigned int row, unsigned int col, 
    matrix<int16_t> &mat_src1, matrix<int16_t> &mat_src2,
    matrix<int16_t> &mat_src3, matrix<int16_t> &mat_dst) {

    auto size = mat_src1.m.size();
    int16_t * src1_ptr = (int16_t *) mat_src1.m.data();
    int16_t * src2_ptr = (int16_t *) mat_src2.m.data();
    int16_t * src3_ptr = (int16_t *) mat_src3.m.data();
    int16_t * dst_ptr  = (int16_t *) mat_dst.m.data();

    bool ofl;

    for (unsigned int i = 0; i < size; i += 32 ){
        __m512 src1 = _mm512_loadu_si512((int16_t *)(src1_ptr + i));
        __m512 src2 = _mm512_loadu_si512((int16_t *)(src2_ptr + i));
        __m512 mul_result = mul<false>(src1, src2, ofl);
        __m512 src3 = _mm512_loadu_si512((int16_t *)(src3_ptr + i));
        __m512 result = add<false>(mul_result, src3, ofl);
        _mm512_storeu_si512((int16_t *)(dst_ptr + i), result);
    }

}


void mat_fma_intrinsic_checked(unsigned int row, unsigned int col,
    matrix<int16_t> &mat_src1, matrix<int16_t> &mat_src2,
    matrix<int16_t> &mat_src3, matrix<int16_t> &mat_dst) {

    auto size = mat_src1.m.size();

    int16_t *src1_ptr = (int16_t *)mat_src1.m.data();
    int16_t *src2_ptr = (int16_t *)mat_src2.m.data();
    int16_t *src3_ptr = (int16_t *) mat_src3.m.data();
    int16_t *dst_ptr  = (int16_t *)mat_dst.m.data();

    bool ofl = false;

    for (int64_t i = 0; i < size; i += 32) {
        __m512 src1 = _mm512_loadu_si512((int16_t *)(src1_ptr + i));
        __m512 src2 = _mm512_loadu_si512((int16_t *)(src2_ptr + i));
        __m512 mul_result = mul<true>(src1, src2, ofl);
        __m512 src3 = _mm512_loadu_si512((int16_t *)(src3_ptr + i));
        __m512 result = add<true>(mul_result, src3, ofl);
        _mm512_storeu_si512((int16_t *)(dst_ptr + i), result);
    }

    if (ofl) {exit(0);}
}
#endif