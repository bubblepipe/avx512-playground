#ifndef PIVOT_H
#define PIVOT_H

#include <cstdint>
#include <bench_pivot/matrix.h>
#include <x86intrin.h>
#include <string.h>

#define START_TIMER     unsigned int dummy;  \
    unsigned long t1 = __rdtscp(&dummy);
#define STOP_TIMER     unsigned long t2 = __rdtscp(&dummy); \
    printf("Time: %ld\n",  t2 - t1); \
    exit(0);

#ifdef CHECK_OVERFLOW
  #define FECLEAREXCEPT feclearexcept_local_sse (FE_INEXACT | FE_INVALID);
  #define if_fetestexcept_return_false_else \
    if (fetestexcept_local_sse(FE_INEXACT | FE_INVALID)) { \
      return false; \
    } else  
#else 
  #define FECLEAREXCEPT 
  #define if_fetestexcept_return_false_else 
#endif


inline __attribute__((always_inline)) void copy_row(float * dstRowPtr, float * srcRowPtr , unsigned nCol){
  *(floatZmm *)(dstRowPtr + 0) = *(floatZmm *)(srcRowPtr + 0);
  *(floatZmm *)(dstRowPtr + ZmmFloatVecSize) = *(floatZmm *)(srcRowPtr + ZmmFloatVecSize);
}

inline __attribute__((always_inline)) void copy_row(double * dstRowPtr, double * srcRowPtr , unsigned nCol){
  *(doubleZmm *)(dstRowPtr + 0) = *(doubleZmm *)(srcRowPtr + 0);
  *(doubleZmm *)(dstRowPtr + ZmmDoubleVecSize) = *(doubleZmm *)(srcRowPtr + ZmmDoubleVecSize);
}


template <typename T, MatColSize matColSize, VectorSize vectorSize> 
bool pivot(matrix<T, vectorSize> & tableau_src, matrix<T, vectorSize> & tableau_dst, unsigned pivotRow, unsigned pivotCol) ;

#define F32_64_OP(__m512X, _mm512_load_pX) \
    __m512X mat_row_ymm = _mm512_load_pX((const T *)(rowPtr + colIndex)); \
    __m512X result0 = mat_row_ymm * ConstA; \
    __m512X pivot_row_ymm = _mm512_load_pX((const T *)(pivotRowPtr + colIndex)); \
    __m512X result1 = ConstC * pivot_row_ymm + result0; 

#define F64_MASK_STORE \
    _mm512_mask_store_pd((T *)(rowPtr + colIndex), 0b11111110, result1);

#define F32_MASK_STORE \
    _mm512_mask_store_ps((T *)(rowPtr + colIndex), 0b1111111111111110, result1);

#define F32_64_STORE(_mm512_store_pX) \
    _mm512_store_pX((T *)(rowPtr + colIndex), result1);

#define CONST_A_C \
      Zmm ConstA = pivotRowPtr[0]; \
      Zmm ConstC = rowPtr[pivotCol]; 
    

#define I16_OP \
    __m512 mat_row_ymm = _mm512_load_si512((const T *)(rowPtr + colIndex)); \
    __m512 result0 = mul<true>(mat_row_ymm, ConstA); \
    __m512 pivot_row_ymm = _mm512_load_si512((const T *)(pivotRowPtr + colIndex)); \
    __m512 result1 = mul<true>(ConstC, pivot_row_ymm); \
    __m512 result2 = add<true>(result1, result0); 

#define I16_TORE \
    _mm512_store_si512((T *)(rowPtr + colIndex), result2);

#endif