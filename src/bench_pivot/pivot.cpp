#include <bench_pivot/pivot.h>
#include <bench_pivot/utils.h>
#include <bench_pivot/MPInt.h>
#include <cstdint>
#include <x86intrin.h>
#include <utils/int16_utils.cpp>

#define START_TIMER     unsigned int dummy;  \
    unsigned long t1 = __rdtscp(&dummy);
#define STOP_TIMER     unsigned long t2 = __rdtscp(&dummy); \
    printf("Time: %ld\n",  t2 - t1); \
    exit(0);


// true: no fpe
// false: no
template <typename T>
bool pivot(matrix<T> & mat, unsigned pivotRow, unsigned pivotCol) {

  if constexpr (std::is_same<T, double>::value || std::is_same<T, float>::value ) {
    std::feclearexcept (FE_INEXACT | FE_INVALID);
  }

  // printx(INFO, "\n>>> pivotRow %ld, pivotCol %ld <<<\n", (int64_t)pivotRow, (int64_t)pivotCol);

  // todo this
  // swapRowWithCol(pivotRow, pivotCol);

  unsigned nRow, nCol;
  nRow = mat.nRow;
  nCol = mat.nCol;

  T tmp = mat.get(pivotRow, 0);
  mat.set(pivotRow, 0, -mat.get(pivotRow, pivotCol));
  mat.set(pivotRow, pivotCol, -tmp);

  if (mat(pivotRow, 0) < 0) {
#ifdef SCALAR
    mat.negateRow(pivotRow);
#else
    mat.negateRowVectorized(pivotRow);
#endif
  }

  mat.normalizeRowScalar(pivotRow);

  T * pivotRowPtr = mat.getRowPtr(pivotRow);
  T * rowPtr = mat.getRowPtr(0);

// start of loop
  for (unsigned rowIndex = 0; rowIndex < nRow; rowIndex += 1) {
    auto pivotColBackup = mat(rowIndex, pivotCol);

    if (rowIndex == pivotRow) { 
      rowPtr += mat.nColPadding;
      continue;
    }

    T c = mat(rowIndex, pivotCol);
    if (c == 0) { 
      rowPtr += mat.nColPadding;
      continue; 
    }

#if defined SCALAR || defined USE_MPInt
    mat(rowIndex, 0) *= mat(pivotRow, 0);
    for (unsigned col = 1; col < nCol; ++col) {
      if (col == pivotCol){ continue; }

      mat(rowIndex, col) = mat(rowIndex, col) * mat(pivotRow, 0) +
                           mat(rowIndex, pivotCol) * mat(pivotRow, col);
    }

    mat(rowIndex, pivotCol) *= mat(pivotRow, pivotCol);

#else
    mat(rowIndex, 0) *= mat(pivotRow, 0);

    // row = row * ConstA +  ConstB * PivotRow;
    if constexpr (std::is_same<T, double>::value) {
      typedef doubleZmm T2_Zmm;
      T2_Zmm ConstA = mat(pivotRow, 0);
      T2_Zmm ConstC = mat(rowIndex, pivotCol);
      T index0 = mat(rowIndex, 0);
      for (unsigned colIndex = 0; colIndex < nCol; colIndex += ZmmDoubleVecSize) {
        __m512 mat_row_ymm = _mm512_load_pd((const T *)(rowPtr + colIndex));
        __m512 result0 = _mm512_mul_pd(mat_row_ymm, ConstA);
        __m512 pivot_row_ymm = _mm512_load_pd((const T *)(pivotRowPtr + colIndex));
        __m512 result1 = _mm512_fmadd_pd(ConstC, pivot_row_ymm, result0);
        _mm512_store_pd((T *)(rowPtr + colIndex), result1);
      }
      mat(rowIndex, 0) = index0;
    }
    else if constexpr (std::is_same<T, float>::value) {
      typedef floatZmm T2_Zmm;
      T2_Zmm ConstA = mat(pivotRow, 0);
      T2_Zmm ConstC = mat(rowIndex, pivotCol);
      for (unsigned colIndex = 1; colIndex < nCol; colIndex += ZmmFloatVecSize) {
        __m512 mat_row_ymm = _mm512_loadu_ps((const T *)(rowPtr + colIndex));
        __m512 result0 = _mm512_mul_ps(mat_row_ymm, ConstA);
        __m512 pivot_row_ymm = _mm512_loadu_ps((const T *)(pivotRowPtr + colIndex));
        __m512 result1 = _mm512_fmadd_ps(ConstC, pivot_row_ymm, result0);
        _mm512_storeu_ps((T *)(rowPtr + colIndex), result1);
      }
    } 
    else if constexpr (std::is_same<T, int16_t>::value) {
      typedef int16Zmm T2_Zmm;
      T2_Zmm ConstA = mat(pivotRow, 0);
      T2_Zmm ConstC = mat(rowIndex, pivotCol);
      for (unsigned colIndex = 1; colIndex < nCol; colIndex += ZmmInt16VecSize) {
        __m512 mat_row_ymm = _mm512_loadu_si512((const T *)(rowPtr + colIndex));
        __m512 result0 = mul<true>(mat_row_ymm, ConstA);
        __m512 pivot_row_ymm = _mm512_loadu_si512((const T *)(pivotRowPtr + colIndex));
        __m512 result1 = mul<true>(ConstC, pivot_row_ymm);
        __m512 result2 = add<true>(result1, result0);
        _mm512_storeu_si512((T *)(rowPtr + colIndex), result2);
      }
    }
    else {
      printf("neither USE_INT16, USE_INT23 not USE_INT52 is defined in pivot");
      exit(0);
    }
  
    // mat(rowIndex, pivotCol) = mat(rowIndex, pivotCol);
    mat(rowIndex, pivotCol) = pivotColBackup;
    mat(rowIndex, pivotCol) *= mat(pivotRow, pivotCol);

    rowPtr += mat.nColPadding;
#endif

    mat.normalizeRowScalar(rowIndex);
  }
// end of loop

  if constexpr (std::is_same<T, double>::value || std::is_same<T, float>::value ) {
    if (fetestexcept_local(FE_INEXACT | FE_INVALID)) {
      return false;
    } else {
      return true;
    } 
  } else {
    return true;
  }

}


template bool pivot <double>(matrix<double> & tableau, unsigned pivotRow, unsigned pivotCol);
template bool pivot <float>(matrix<float> & tableau, unsigned pivotRow, unsigned pivotCol);
template bool pivot <int64_t>(matrix<int64_t> & tableau, unsigned pivotRow, unsigned pivotCol);
template bool pivot <int16_t>(matrix<int16_t> & tableau, unsigned pivotRow, unsigned pivotCol);
template bool pivot <MPInt>(matrix<MPInt> & tableau, unsigned pivotRow, unsigned pivotCol);

