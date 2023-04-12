#include <cstdint>
#include <utils/matrix.cpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <bench_vec/bench_vector_int.hpp>
#include <immintrin.h>
#include <utils/int32_utils.cpp>

void mat_fma_scalar_inacurate_check ( unsigned int row, unsigned int col, 
    matrix<int32_t> & mat_src1, matrix<int32_t> & mat_src2, matrix<int32_t> & mat_src3, matrix<int32_t> & mat_dst ) {
    bool overflow = false;
    auto size = mat_src1.m.size();
    
    int32_t * src1_ptr = (int32_t *) mat_src1.m.data();
    int32_t * src2_ptr = (int32_t *) mat_src2.m.data();
    int32_t * src3_ptr = (int32_t *) mat_src3.m.data();
    int32_t * dst_ptr  = (int32_t *) mat_dst.m.data();

    for (int i = 0; i < size; i += 1) {
        int32_t r1, r2;
        int32_t src1 = src1_ptr[i];
        int32_t src2 = src2_ptr[i];
        int32_t src3 = src3_ptr[i];
        overflow |= __builtin_mul_overflow(src1, src2, &r1);
        overflow |= __builtin_add_overflow(r1, src3, &r2);
        dst_ptr[i] = r2;
    }

    if (overflow) {
        exit(0);
    }
}


void mat_fma ( unsigned int row, unsigned int col, 
    matrix<int32_t> & mat_src1, matrix<int32_t> & mat_src2, matrix<int32_t> & mat_src3, matrix<int32_t> & mat_dst ) {
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            int32_t src1 = mat_src1.get(i,j);
            int32_t src2 = mat_src2.get(i,j);
            int32_t src3 = mat_src3.get(i,j);
            mat_dst.set(i,j,  (src1 * src2) + src3);
        }
    }
}
void mat_add ( unsigned int row, unsigned int col, 
    matrix<int32_t> & mat_src1, matrix<int32_t> & mat_src2, matrix<int32_t> & mat_src3, matrix<int32_t> & mat_dst ) {

    auto size = mat_src1.m.size();
    int32_t * src1_ptr = (int32_t *) mat_src1.m.data();
    int32_t * src2_ptr = (int32_t *) mat_src2.m.data();
    int32_t * dst_ptr  = (int32_t *) mat_dst.m.data();
    vec_add_莎莎(size, src1_ptr, src2_ptr, dst_ptr);

}


#undef AVX512_ENABLED
void mat_add_manual ( unsigned int row, unsigned int col, 
    matrix<int32_t> & mat_src1, matrix<int32_t> & mat_src2, matrix<int32_t> & mat_src3, matrix<int32_t> & mat_dst ) {
    
    auto size = mat_src1.m.size();
    
    if (size % 8 != 0) {
        throw std::runtime_error(std::string("size not div by 8"));
    }

    int32_t * src1_ptr = (int32_t *) mat_src1.m.data();
    int32_t * src2_ptr = (int32_t *) mat_src2.m.data();
    int32_t * src3_ptr = (int32_t *) mat_src3.m.data();
    int32_t * dst_ptr  = (int32_t *) mat_dst.m.data();

#ifdef AVX512_ENABLED
    for (int32_t i = 0; i < size; i += 16 ){
        __m512 src1 = _mm512_loadu_si512 ((__m512i_u*) (src1_ptr + i));
        __m512 src2 = _mm512_loadu_si512 ((__m512i_u*) (src2_ptr + i));
        __m512 src3 = _mm512_loadu_si512 ((__m512i_u*) (src3_ptr + i));
        __m512 result0 = _mm512_add_epi32(src1, src2);
        __m512 result = _mm512_add_epi32(result0, src3);
        _mm512_storeu_si512((__m512i_u*) (dst_ptr + i), result);
    }
#else
    for (int32_t i = 0; i < size; i += 8 ){
        __m256 src1 = _mm256_loadu_si256 ((__m256i_u*) (src1_ptr + i));
        __m256 src2 = _mm256_loadu_si256 ((__m256i_u*) (src2_ptr + i));
        __m256 src3 = _mm256_loadu_si256 ((__m256i_u*) (src3_ptr + i));
        __m256 result0 = _mm256_add_epi32(src1, src2);
        __m256 result = _mm256_add_epi32(result0, src3);
        _mm256_storeu_si256((__m256i_u*) (dst_ptr + i), result);
    }
#endif


}

void overflow_handler()
{
    printf("overflow!\n");
    exit(0);
}
 



void mat_fma_intrinsic ( unsigned int row, unsigned int col, 
    matrix<int32_t> & mat_src1, matrix<int32_t> & mat_src2, matrix<int32_t> & mat_src3, matrix<int32_t> & mat_dst ) {
    auto size = mat_src1.m.size();
    int32_t * src1_ptr = (int32_t *) mat_src1.m.data();
    int32_t * src2_ptr = (int32_t *) mat_src2.m.data();
    int32_t * src3_ptr = (int32_t *) mat_src3.m.data();
    int32_t * dst_ptr  = (int32_t *) mat_dst.m.data();
#ifdef AVX512_ENABLED
    for (int32_t i = 0; i < size; i += 16 ){
        __m512 src1 = _mm512_loadu_si512 ((__m512i_u*) (src1_ptr + i));
        __m512 src2 = _mm512_loadu_si512 ((__m512i_u*) (src2_ptr + i));
        __m512 r1 = _mm512_mullo_epi32(src1, src2);
        __m512 src3 = _mm512_loadu_si512 ((__m512i_u*) (src3_ptr + i));
        __m512 r2 = _mm512_add_epi32(r1, src3);
        __m512 rx = _mm512_mullo_epi32(r2, src3);
        _mm512_storeu_si512((__m512i_u*) (dst_ptr + i), rx);
    }
#else
    for (int32_t i = 0; i < size; i += 8 ){
        __m256 src1 = _mm256_loadu_si256 ((__m256i_u*) (src1_ptr + i));
        __m256 src2 = _mm256_loadu_si256 ((__m256i_u*) (src2_ptr + i));
        __m256 r1 = _mm256_mullo_epi32(src1, src2);
        __m256 src3 = _mm256_loadu_si256 ((__m256i_u*) (src3_ptr + i));
        __m256 r2 = _mm256_add_epi32(r1, src3);
        _mm256_storeu_si256((__m256i_u*) (dst_ptr + i), r2);
    }
#endif
// #undef AVX512_ENABLED
}

void mat_fma_intrinsic_checked ( unsigned int row, unsigned int col, 
    matrix<int32_t> & mat_src1, matrix<int32_t> & mat_src2, matrix<int32_t> & mat_src3, matrix<int32_t> & mat_dst ) {
    auto size = mat_src1.m.size();
    int32_t * src1_ptr = (int32_t *) mat_src1.m.data();
    int32_t * src2_ptr = (int32_t *) mat_src2.m.data();
    int32_t * src3_ptr = (int32_t *) mat_src3.m.data();
    int32_t * dst_ptr  = (int32_t *) mat_dst.m.data();

#ifdef AVX512_ENABLED
    for (int32_t i = 0; i < size; i += 16 ){
        __m512 src1 = _mm512_loadu_si512((int32_t *)(src1_ptr + i));
        __m512 src2 = _mm512_loadu_si512((int32_t *)(src2_ptr + i));
        __m512 mul_result = mul<true>(src1, src2);
        __m512 src3 = _mm512_loadu_si512((int32_t *)(src3_ptr + i));
        __m512 result = add<true>(mul_result, src3);
        _mm512_storeu_si512((int32_t *)(dst_ptr + i), result);
    }
#endif
}

void mat_fma_manual_half_width ( unsigned int row, unsigned int col, 
    matrix<int32_t> & mat_src1, matrix<int32_t> & mat_src2, matrix<int32_t> & mat_src3, matrix<int32_t> & mat_dst ) {
    auto size = mat_src1.m.size();
    int32_t * src1_ptr = (int32_t *) mat_src1.m.data();
    int32_t * src2_ptr = (int32_t *) mat_src2.m.data();
    int32_t * src3_ptr = (int32_t *) mat_src3.m.data();
    int32_t * dst_ptr  = (int32_t *) mat_dst.m.data();
    
    auto shiftleft = _mm256_setr_epi32(1,2,3,4,5,6,7,0);
    auto shiftright = _mm256_setr_epi32(7,0,1,2,3,4,5,6);
    auto zero = _mm256_setr_epi32(0,0,0,0,0,0,0,0);
    auto one = _mm256_setr_epi32(0xffffffff,0xffffffff,0xffffffff,0xffffffff,
                                 0xffffffff,0xffffffff,0xffffffff,0xffffffff);

    for (int32_t i = 0; i < size; i += 8 ){

        __m256 src1 = _mm256_loadu_si256 ((__m256i_u*) (src1_ptr + i));
        __m256 src2 = _mm256_loadu_si256 ((__m256i_u*) (src2_ptr + i));

        // src1[0,2,4,6] * src2[0,2,4,6];
        __m256 mul_res_1 = _mm256_mul_epi32(src1, src2);

        // srcx[0,2,4,6] <= srcx[1,3,5,7] 
        src1 = _mm256_permutevar8x32_epi32(src1, shiftleft);
        src2 = _mm256_permutevar8x32_epi32(src2, shiftleft);

        // src1 * src2
        __m256 mul_res_2 = _mm256_mul_epi32(src1, src2);

        // mul_res_x[1,3,5,7] should be 0. >0 indicates overflow. 
        __m256 mul_res_hi_sum = _mm256_add_epi32(mul_res_1, mul_res_2);
        __m256 mul_res_hi_shuf = _mm256_shuffle_epi32(mul_res_hi_sum, 0b11110101);
        int mul_overflow = _mm256_testz_si256(mul_res_hi_shuf, one);

        if (!mul_overflow) {
            int32_t * f; 
            // f = (int32_t *)&src1;
            // printf("%d %d %d %d %d %d %d %d\n", f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
            f = (int32_t *)&mul_res_hi_shuf;
            printf("%x %x %x %x %x %x %x %x\n", f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
            printf("result %d\n", mul_overflow );
            exit(0);
        }

        // merge mul lo result
        __m256 mul_res_lo_shuf = _mm256_permutevar8x32_epi32(mul_res_2, shiftright);
        __m256 mul_res_lo_shuf2 = _mm256_add_epi32(mul_res_1, mul_res_lo_shuf);

        // add src3
        __m256 src3 = _mm256_loadu_si256 ((__m256i_u*) (src3_ptr + i));
        __m256 r2 = _mm256_add_epi32(mul_res_lo_shuf2, src3);

        // write back
        _mm256_storeu_si256((__m256i_u*) (dst_ptr + i), r2);

    }
}