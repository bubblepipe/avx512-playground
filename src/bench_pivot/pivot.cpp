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
  T * pivotRowPtr = mat.getRowPtr(pivotRow);

  T tmp = pivotRowPtr[0];
  pivotRowPtr[0] = -pivotRowPtr[pivotCol];
  pivotRowPtr[pivotCol] = -tmp;

  if (pivotRowPtr[0] < 0) {
#ifdef SCALAR
    mat.negateRow(pivotRow);
#else
    mat.negateRowVectorized(pivotRow);
#endif
  }

  mat.normalizeRowScalar(pivotRow);

  T * rowPtr = mat.getRowPtr(0);

// start of loop
  for (unsigned rowIndex = 0; rowIndex < nRow; rowIndex += 1) {
    // T * rowPtr = mat.getRowPtr(rowIndex);

    if (rowIndex == pivotRow) { 
      rowPtr += mat.nColPadding;
      continue;
    }

    T c = rowPtr[pivotCol];
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
    auto pivotColBackup = rowPtr[pivotCol];
    rowPtr[0] *= pivotRowPtr[0];

    // row = row * ConstA +  ConstB * PivotRow;
    if constexpr (std::is_same<T, double>::value) {
      typedef doubleZmm Zmm;
      CONST_A_C
      unsigned colIndex = 0;
      F32_64_OP(__m512d, _mm512_load_pd, _mm512_mul_pd, _mm512_fmadd_pd)
      F64_MASK_STORE
      for (colIndex = ZmmDoubleVecSize; colIndex < nCol; colIndex += ZmmDoubleVecSize) {
        F32_64_OP(__m512d, _mm512_load_pd, _mm512_mul_pd, _mm512_fmadd_pd)
        F32_64_STORE(_mm512_store_pd)
      }
    }
    else if constexpr (std::is_same<T, float>::value) {
      typedef floatZmm Zmm;
      CONST_A_C
      unsigned colIndex = 0;
      F32_64_OP(__m512, _mm512_load_ps, _mm512_mul_ps, _mm512_fmadd_ps)
      F32_MASK_STORE
      for (colIndex = ZmmFloatVecSize; colIndex < nCol; colIndex += ZmmFloatVecSize) {
        F32_64_OP(__m512, _mm512_load_ps, _mm512_mul_ps, _mm512_fmadd_ps)
        F32_64_STORE(_mm512_store_ps)
      }
    } 
    else if constexpr (std::is_same<T, int16_t>::value) {
      T index0 = rowPtr[0]; // manual backup of the first element
      typedef int16Zmm Zmm;
      CONST_A_C
      unsigned colIndex = 0;
      for (colIndex = 0; colIndex < nCol; colIndex += ZmmInt16VecSize) {
        I16_OP
        I16_TORE
      }
      rowPtr[0] = index0;
    }
    else {
      printf("neither USE_INT16, USE_INT23 not USE_INT52 is defined in pivot");
      exit(0);
    }
    
    rowPtr[pivotCol] = pivotColBackup * pivotRowPtr[pivotCol];

#endif

    mat.normalizeRowScalar(rowIndex);
    rowPtr += mat.nColPadding;
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

