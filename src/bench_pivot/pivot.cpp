#include <bench_pivot/pivot.h>

template <typename T, typename T_Zmm>
void pivot(matrix<T> & tableau , unsigned pivotRow, unsigned pivotCol) {
  printx(INFO, "\n>>> pivotRow %ld, pivotCol %ld <<<\n", (int64_t)pivotRow, (int64_t)pivotCol);

//   swapRowWithCol(pivotRow, pivotCol);

  std::feclearexcept (FE_INEXACT | FE_INVALID);

  bool no_overflow;
  if (std::is_same<T, double>::value) {
    no_overflow = pivot_int52_vecvec<double, doubleZmm>(tableau, pivotRow, pivotCol); 
  } else if (std::is_same<T, float>::value) {
    // no_overflow = pivot_int52_vecvec<float,  floatZmm> (tableau, pivotRow, pivotCol); 
  } else if (std::is_same<T, int16_t>::value) {
    printx(ERROR, "\nint16_t is not implemented!\n\n"); exit(0);
  } else{
    printx(ERROR, "\nunknown type\n\n"); exit(0);
  }

  if (! no_overflow) {
    printx(ERROR, "\noverflow!\n\n");
    printx(ERROR, "\npivot_default is not implemented!\n\n");
    exit(0);
  }
}

// true: fine
// false: overflow
template <typename T, typename T_Zmm>
bool pivot_int52_vecvec(matrix<T> & tableau, unsigned pivotRow, unsigned pivotCol) {

  // todo this
  // swapRowWithCol(pivotRow, pivotCol);

  unsigned nRow, nCol;
  nRow = tableau.nRow;
  nCol = tableau.nCol;

  matrix<T> mat(tableau);
  mat.print();

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

  for (unsigned rowIndex = 0; rowIndex < nRow; rowIndex += 1) {

    if (rowIndex == pivotRow) { continue; }

    T c = mat(rowIndex, pivotCol);
    if (c == 0) { continue; }

    T_Zmm ConstA = mat(pivotRow, 0);
    T_Zmm ConstC = mat(rowIndex, pivotCol);
    T * pivotRowPtr = mat.getRowPtr(pivotRow);
    T * rowPtr = mat.getRowPtr(rowIndex);

#ifdef SCALAR

    mat(rowIndex, 0) *= mat(pivotRow, 0);
    for (unsigned col = 1, numCols = getNumColumns(); col < numCols; ++col) {
      if (col == pivotCol){ continue; }

      mat(rowIndex, col) = mat(rowIndex, col) * mat(pivotRow, 0) +
                           mat(rowIndex, pivotCol) * mat(pivotRow, col);
    }

    mat(rowIndex, pivotCol) *= mat(pivotRow, pivotCol);

#else

  mat(rowIndex, 0) *= mat(pivotRow, 0);

  // row = row * ConstA +  ConstB * PivotRow;

  if (std::is_same<T, double>::value) {

    for (unsigned colIndex = 1; colIndex < nCol; colIndex += ZmmDoubleVecSize) {
      __m512 mat_row_ymm = _mm512_loadu_pd((const T *)(rowPtr + colIndex));
      __m512 pivot_row_ymm = _mm512_loadu_pd((const T *)(pivotRowPtr + colIndex));
      __m512 result0 = _mm512_mul_pd(mat_row_ymm, ConstA);
      __m512 result1 = _mm512_fmadd_pd(ConstC, pivot_row_ymm, result0);
      _mm512_storeu_pd((T *)(rowPtr + colIndex), result1);
    }
  }
  else if (std::is_same<T, float>::value) {

    for (unsigned colIndex = 1; colIndex < nCol; colIndex += ZmmFloatVecSize) {
      __m512 mat_row_ymm = _mm512_loadu_ps((const T *)(rowPtr + colIndex));
      __m512 pivot_row_ymm = _mm512_loadu_ps((const T *)(pivotRowPtr + colIndex));
      __m512 result0 = _mm512_mul_ps(mat_row_ymm, ConstA);
      __m512 result1 = _mm512_fmadd_ps(ConstC, pivot_row_ymm, result0);
      _mm512_storeu_ps((T *)(rowPtr + colIndex), result1);
    }

  } else{
    printf("neither USE_INT23 not USE_INT52 is defined in pivot");
    exit(0);
  }

    mat(rowIndex, pivotCol) = tableau(rowIndex, pivotCol);
    mat(rowIndex, pivotCol) *= mat(pivotRow, pivotCol);

#endif

    mat.normalizeRowScalar(rowIndex);
  }

  // copy back to tableau
  // but if feinexact, don't
  if (fetestexcept_local(FE_INEXACT | FE_INVALID)) {
    return false;
  } else {

    for (unsigned r = 0; r < nRow ; r += 1) {
      for (unsigned c = 0; c < nCol ; c += 1) {
        auto x = mat(r, c);
        tableau(r, c) = x;
      }
    }

    mat.print();

    // TODO: is this necessary?
    if (fetestexcept_local(FE_INEXACT | FE_INVALID)) {
      printf("error when converting backto int\n");
      exit(0);
      return false;
    } else {
      return true;
    }
  }
}


