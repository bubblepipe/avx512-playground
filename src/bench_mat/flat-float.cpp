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

#define AVX512_ENABLED


void mat_fma_auto ( unsigned int row, unsigned int col, 
    matrix<float> & mat_src1, matrix<float> & mat_src2, matrix<float> & mat_src3, matrix<float> & mat_dst ) {
    float * dst_ptr  = (float *) mat_dst.m.data();
    
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            float src1 = mat_src1.get(i,j);
            float src2 = mat_src2.get(i,j);
            float src3 = mat_src3.get(i,j);
            dst_ptr[i * col + j] = (src1 * src2) + src3;
        }
    }
}


void mat_fma_manual ( unsigned int row, unsigned int col, 
    matrix<float> & mat_src1, matrix<float> & mat_src2, matrix<float> & mat_src3, matrix<float> & mat_dst ) {
    auto size = mat_src1.m.size();
    float * src1_ptr = (float *) mat_src1.m.data();
    float * src2_ptr = (float *) mat_src2.m.data();
    float * src3_ptr = (float *) mat_src3.m.data();
    float * dst_ptr  = (float *) mat_dst.m.data();

    for (int i = 0; i < size; i += 8 ){
        simdpp::float32<8> src1_ymm = simdpp::load(src1_ptr + i);
        simdpp::float32<8> src2_ymm = simdpp::load(src2_ptr + i);
        simdpp::float32<8> src3_ymm = simdpp::load(src3_ptr + i);
        auto dst_ymm = simdpp::fmadd(src1_ymm, src2_ymm, src3_ymm);
        simdpp::store(dst_ptr + i, dst_ymm );                                         
    }
}
void mat_fma_clang_builtin ( unsigned int row, unsigned int col, 
    matrix<float> & mat_src1, matrix<float> & mat_src2, matrix<float> & mat_src3, matrix<float> & mat_dst ) {
    auto size = mat_src1.m.size();
    float * src1_ptr = (float *) mat_src1.m.data();
    float * src2_ptr = (float *) mat_src2.m.data();
    float * src3_ptr = (float *) mat_src3.m.data();
    float * dst_ptr  = (float *) mat_dst.m.data();


    typedef float FloatZmm __attribute__((ext_vector_type(32)));
    typedef float FloatYmm __attribute__((ext_vector_type(16)));

#ifdef AVX512_ENABLED
    typedef FloatZmm Vector;
    auto stepsize = 16;
#elif defined AVX2_ENABLED
    typedef FloatYmm Vector;
    auto stepsize = 8;
#else
    typedef float Vector;
    auto stepsize = 1;
#endif
    for (int i = 0; i < size; i += stepsize ){
        Vector src1Vec = *(Vector *)(src1_ptr + i);
        Vector src2Vec = *(Vector *)(src2_ptr + i);
        Vector src3Vec = *(Vector *)(src3_ptr + i);
        Vector result = src1Vec * src2Vec + src3Vec;
        *(Vector *)(dst_ptr + i) = result;
    }

}
void mat_fma_intrinsic ( unsigned int row, unsigned int col, 
    matrix<float> & mat_src1, matrix<float> & mat_src2, matrix<float> & mat_src3, matrix<float> & mat_dst ) {
    auto size = mat_src1.m.size();
    float * src1_ptr = (float *) mat_src1.m.data();
    float * src2_ptr = (float *) mat_src2.m.data();
    float * src3_ptr = (float *) mat_src3.m.data();
    float * dst_ptr  = (float *) mat_dst.m.data();

#ifdef AVX512_ENABLED
    for (int i = 0; i < size; i += 16 ){
        __m512 src1 = _mm512_loadu_ps ((const float *) (src1_ptr + i));
        __m512 src2 = _mm512_loadu_ps ((const float *) (src2_ptr + i));
        __m512 src3 = _mm512_loadu_ps ((const float *) (src3_ptr + i));
        __m512 result = _mm512_fmadd_ps(src1, src2, src3);
        // __m512 rx = _mm512_mul_ps(result, src3);
        _mm512_storeu_ps((float *) (dst_ptr + i), result);
    }
#else
    for (int i = 0; i < size; i += 8 ){
        __m256 src1 = _mm256_loadu_ps ((const float *) (src1_ptr + i));
        __m256 src2 = _mm256_loadu_ps ((const float *) (src2_ptr + i));
        __m256 src3 = _mm256_loadu_ps ((const float *) (src3_ptr + i));
        __m256 result = _mm256_fmadd_ps(src1, src2, src3);
        _mm256_storeu_ps((float *) (dst_ptr + i), result);
    }
#endif
}
void mat_add_intrinsic ( unsigned int row, unsigned int col, 
    matrix<float> & mat_src1, matrix<float> & mat_src2, matrix<float> & mat_src3, matrix<float> & mat_dst ) {
    auto size = mat_src1.m.size();
    float * src1_ptr = (float *) mat_src1.m.data();
    float * src2_ptr = (float *) mat_src2.m.data();
    float * src3_ptr = (float *) mat_src3.m.data();
    float * dst_ptr  = (float *) mat_dst.m.data();

#ifdef AVX512_ENABLED
    for (int i = 0; i < size; i += 16 ){
        __m512 src1 = _mm512_loadu_ps ((const float *) (src1_ptr + i));
        __m512 src2 = _mm512_loadu_ps ((const float *) (src2_ptr + i));
        __m512 src3 = _mm512_loadu_ps ((const float *) (src3_ptr + i));
        __m512 result0 = _mm512_add_ps(src1, src2);
        __m512 result1 = _mm512_add_ps(result0, src1);
        _mm512_storeu_ps((float *) (dst_ptr + i), result1);
    }
#else
    for (int i = 0; i < size; i += 8 ){
        __m256 src1 = _mm256_loadu_ps ((const float *) (src1_ptr + i));
        __m256 src2 = _mm256_loadu_ps ((const float *) (src2_ptr + i));
        __m256 src3 = _mm256_loadu_ps ((const float *) (src3_ptr + i));
        __m256 result = _mm256_fmadd_ps(src1, src2, src3);
        _mm256_storeu_ps((float *) (dst_ptr + i), result);
    }
#endif
}
void mat_fma_intrinsic_check ( unsigned int row, unsigned int col, 
    matrix<float> & mat_src1, matrix<float> & mat_src2, matrix<float> & mat_src3, matrix<float> & mat_dst ) {

    mat_fma_intrinsic( row, col, mat_src1, mat_src2, mat_src3, mat_dst ) ;
    volatile bool ofl = fetestexcept_local(FE_INEXACT | FE_INVALID);
    
}


void mat_fma_intrinsic_unroll ( unsigned int row, unsigned int col, 
    matrix<float> & mat_src1, matrix<float> & mat_src2, matrix<float> & mat_src3, matrix<float> & mat_dst ) {

    auto size = mat_src1.m.size();
    float * src1_ptr = (float *) mat_src1.m.data();
    float * src2_ptr = (float *) mat_src2.m.data();
    float * src3_ptr = (float *) mat_src3.m.data();
    float * dst_ptr  = (float *) mat_dst.m.data();

    for (int i = 0; i < size; i += 32 ){
        __m256 src1_1 = _mm256_loadu_ps ((const float *) (src1_ptr + i));
        __m256 src2_1 = _mm256_loadu_ps ((const float *) (src2_ptr + i));
        __m256 src3_1 = _mm256_loadu_ps ((const float *) (src3_ptr + i));
        __m256 result_1 = _mm256_fmadd_ps(src1_1, src2_1, src3_1);
        _mm256_storeu_ps((float *) (dst_ptr + i), result_1);

        __m256 src1_2 = _mm256_loadu_ps ((const float *) (src1_ptr + i+8));
        __m256 src2_2 = _mm256_loadu_ps ((const float *) (src2_ptr + i+8));
        __m256 src3_2 = _mm256_loadu_ps ((const float *) (src3_ptr  + i+8));
        __m256 result_2 = _mm256_fmadd_ps(src1_2, src2_2, src3_2);
        _mm256_storeu_ps((float *) (dst_ptr + i), result_2);

        __m256 src1_3 = _mm256_loadu_ps ((const float *) (src1_ptr + i+16));
        __m256 src2_3 = _mm256_loadu_ps ((const float *) (src2_ptr + i+16));
        __m256 src3_3 = _mm256_loadu_ps ((const float *) (src3_ptr +  i+16));
        __m256 result_3 = _mm256_fmadd_ps(src1_3, src2_3, src3_3);
        _mm256_storeu_ps((float *) (dst_ptr + i), result_3);

        __m256 src1_4 = _mm256_loadu_ps ((const float *) (src1_ptr + i+24));
        __m256 src2_4 = _mm256_loadu_ps ((const float *) (src2_ptr + i+24));
        __m256 src3_4 = _mm256_loadu_ps ((const float *) (src3_ptr +  i+24));
        __m256 result_4 = _mm256_fmadd_ps(src1_4, src2_4, src3_4);
        _mm256_storeu_ps((float *) (dst_ptr + i), result_4);
    }
}
