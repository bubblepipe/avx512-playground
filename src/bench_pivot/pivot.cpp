#include <bench_pivot/pivot.h>
#include <bench_pivot/utils.h>
#include <x86intrin.h>

#define START_TIMER     unsigned int dummy;  \
    unsigned long t1 = __rdtscp(&dummy);
#define STOP_TIMER     unsigned long t2 = __rdtscp(&dummy); \
    printf("Time: %ld\n",  t2 - t1); \
    exit(0);


// true: no fpe
// false: no
template <typename T, typename T_Zmm>
bool pivot(matrix<T> & mat, unsigned pivotRow, unsigned pivotCol) {
  std::feclearexcept (FE_INEXACT | FE_INVALID);
  // printx(INFO, "\n>>> pivotRow %ld, pivotCol %ld <<<\n", (int64_t)pivotRow, (int64_t)pivotCol);

  // todo this
  // swapRowWithCol(pivotRow, pivotCol);

  unsigned nRow, nCol;
  nRow = mat.nRow;
  nCol = mat.nCol;

  // matrix<T> mat(tableau);
  // matrix<T> mat = tableau;
  // mat.print();
 
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

// start of loop
  for (unsigned rowIndex = 0; rowIndex < nRow; rowIndex += 1) {
    auto pivotColBackup = mat(rowIndex, pivotCol);

    if (rowIndex == pivotRow) { continue; }

    T c = mat(rowIndex, pivotCol);
    if (c == 0) { continue; }

    T_Zmm ConstA = mat(pivotRow, 0);
    T_Zmm ConstC = mat(rowIndex, pivotCol);
    T * pivotRowPtr = mat.getRowPtr(pivotRow);
    T * rowPtr = mat.getRowPtr(rowIndex);

#ifdef SCALAR
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
      for (unsigned colIndex = 1; colIndex < nCol; colIndex += ZmmDoubleVecSize) {
        __m512 mat_row_ymm = _mm512_loadu_pd((const T *)(rowPtr + colIndex));
        __m512 result0 = _mm512_mul_pd(mat_row_ymm, ConstA);
        __m512 pivot_row_ymm = _mm512_loadu_pd((const T *)(pivotRowPtr + colIndex));
        __m512 result1 = _mm512_fmadd_pd(ConstC, pivot_row_ymm, result0);
        _mm512_storeu_pd((T *)(rowPtr + colIndex), result1);
      }
    }
    else if constexpr (std::is_same<T, float>::value) {
      for (unsigned colIndex = 1; colIndex < nCol; colIndex += ZmmFloatVecSize) {
        __m512 mat_row_ymm = _mm512_loadu_ps((const T *)(rowPtr + colIndex));
        __m512 result0 = _mm512_mul_ps(mat_row_ymm, ConstA);
        __m512 pivot_row_ymm = _mm512_loadu_ps((const T *)(pivotRowPtr + colIndex));
        __m512 result1 = _mm512_fmadd_ps(ConstC, pivot_row_ymm, result0);
        _mm512_storeu_ps((T *)(rowPtr + colIndex), result1);
      }
  
    } else{
      printf("neither USE_INT23 not USE_INT52 is defined in pivot");
      exit(0);
    }
  
    // mat(rowIndex, pivotCol) = mat(rowIndex, pivotCol);
    mat(rowIndex, pivotCol) = pivotColBackup;
    mat(rowIndex, pivotCol) *= mat(pivotRow, pivotCol);

#endif

    mat.normalizeRowScalar(rowIndex);
  }

  // copy back to tableau
  // but if feinexact, don't
  if (fetestexcept_local(FE_INEXACT | FE_INVALID)) {
    // printf("fpe\n");
    // exit(0);
    return false;
  } else {

    // for (unsigned r = 0; r < nRow ; r += 1) {
    //   for (unsigned c = 0; c < nCol ; c += 1) {
    //     auto x = mat(r, c);
    //     tableau(r, c) = x;
    //   }
    // }
    return true;

    // TODO: is this necessary?
    // if (fetestexcept_local(FE_INEXACT | FE_INVALID)) {
    //   printf("error when converting backto int\n");
    //   exit(0);
    //   return false;
    // } else {
    //   return true;
    // }
  }
}


template bool pivot <double, doubleZmm>(matrix<double> & tableau, unsigned pivotRow, unsigned pivotCol);
template bool pivot <float, floatZmm>(matrix<float> & tableau, unsigned pivotRow, unsigned pivotCol);
template bool pivot <int64_t, int64Zmm>(matrix<int64_t> & tableau, unsigned pivotRow, unsigned pivotCol);

