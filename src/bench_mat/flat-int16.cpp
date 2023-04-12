#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <bench_vec/bench_vector_int.hpp>
#include <immintrin.h>
#include <utils/matrix.cpp>
#include <utils/int16_utils.cpp>

#define AVX512_ENABLED

#ifdef AVX512_ENABLED

void mat_fma_intrinsic ( unsigned int row, unsigned int col, 
    matrix<int16_t> &mat_src1, matrix<int16_t> &mat_src2,
    matrix<int16_t> &mat_src3, matrix<int16_t> &mat_dst) {
    bool overflow = false;

    auto size = mat_src1.m.size();

typedef int16_t int16ZmmU __attribute__((ext_vector_type(ZmmInt16VecSize), __aligned__));

    int16_t *src1_ptr = (int16_t *)mat_src1.m.data();
    int16_t *src2_ptr = (int16_t *)mat_src2.m.data();
    int16_t *src3_ptr = (int16_t *) mat_src3.m.data();
    int16_t *dst_ptr  = (int16_t *)mat_dst.m.data();

    for (int64_t i = 0; i < size; i += 32) {
        int16ZmmU src1 = *(int16ZmmU *)(src1_ptr + i);
        int16ZmmU src2 = *(int16ZmmU *)(src2_ptr + i);
        int16ZmmU src3 = *(int16ZmmU *)(src3_ptr + i);
        int16ZmmU mul_result = mul<false>(src1, src2, overflow);
        int16ZmmU result = add<false>(mul_result, src3, overflow);
        *(int16ZmmU *)(dst_ptr + i) = result;
    }

}



void mat_fma_intrinsic_checked(unsigned int row, unsigned int col,
    matrix<int16_t> &mat_src1, matrix<int16_t> &mat_src2,
    matrix<int16_t> &mat_src3, matrix<int16_t> &mat_dst) {
    bool overflow = false;

    auto size = mat_src1.m.size();

typedef int16_t int16ZmmU __attribute__((ext_vector_type(ZmmInt16VecSize), __aligned__));

    int16_t *src1_ptr = (int16_t *)mat_src1.m.data();
    int16_t *src2_ptr = (int16_t *)mat_src2.m.data();
    int16_t *src3_ptr = (int16_t *) mat_src3.m.data();
    int16_t *dst_ptr  = (int16_t *)mat_dst.m.data();

    for (int64_t i = 0; i < size; i += 32) {
        int16ZmmU src1 = *(int16ZmmU *)(src1_ptr + i);
        int16ZmmU src2 = *(int16ZmmU *)(src2_ptr + i);
        int16ZmmU src3 = *(int16ZmmU *)(src3_ptr + i);
        int16ZmmU mul_result = mul<true>(src1, src2, overflow);
        int16ZmmU result = add<true>(mul_result, src3, overflow);
        *(int16ZmmU *)(dst_ptr + i) = result;
    }

    if (overflow) {
        exit(0);
    }
}
#endif