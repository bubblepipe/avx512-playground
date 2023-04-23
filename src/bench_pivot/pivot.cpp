
#include "bench_pivot/MPInt.h"
#include <bench_pivot/pivot_f32_zmm.cpp>
#include <bench_pivot/pivot_f32_ymm.cpp>
#include <bench_pivot/pivot_f64.cpp>
#include <bench_pivot/pivot_i16_zmm.cpp>
#include <bench_pivot/pivot_i16_ymm.cpp>
#include <bench_pivot/pivot_i16_xmm.cpp>
#include <bench_pivot/pivot_MPInt.cpp>

// template<> bool pivot<int64_t, _0>(matrix<int64_t> & mat, matrix<int64_t> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
template<> bool pivot<int64_t, _32, scalar>(matrix<int64_t, scalar> & mat, matrix<int64_t, scalar> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  typedef int64_t T;

  unsigned nRow, nCol;
  nRow = mat.nRow;
  nCol = mat.nCol;
  T * pivotRowPtr = mat.getRowPtr(pivotRow);

  T tmp = pivotRowPtr[0];
  pivotRowPtr[0] = -pivotRowPtr[pivotCol];
  pivotRowPtr[pivotCol] = -tmp;

  if (pivotRowPtr[0] < 0) {
    mat.negateRow(pivotRow);
  }

  //mat.normalizeRowScalar(pivotRow);

  for (unsigned rowIndex = 0; rowIndex < NROW; rowIndex += 1) {
    auto pivotColBackup = mat(rowIndex, pivotCol);

    if ( rowIndex == pivotRow) { continue; }

    T c = mat(rowIndex, pivotCol);
    if (c == 0) { continue;   }

    mat(rowIndex, 0) *= mat(pivotRow, 0);
    for (unsigned col = 1; col < nCol; ++col) {
      if (col == pivotCol){ continue; }

      mat(rowIndex, col) = mat(rowIndex, col) * mat(pivotRow, 0) +
                           mat(rowIndex, pivotCol) * mat(pivotRow, col);
    }

    mat(rowIndex, pivotCol) *= mat(pivotRow, pivotCol);
    //mat.normalizeRowScalar(rowIndex);
  }

  return true;
}


template<> bool pivot<MPInt, _32, scalar>(matrix<MPInt, scalar> & mat_src, matrix<MPInt, scalar> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  typedef MPInt T;

  unsigned nRow, nCol;
  nRow = mat_src.nRow;
  nCol = mat_src.nCol;
  T * pivotRowPtr = mat_src.getRowPtr(pivotRow);

  T tmp = pivotRowPtr[0];
  pivotRowPtr[0] = -pivotRowPtr[pivotCol];
  pivotRowPtr[pivotCol] = -tmp;

  if (pivotRowPtr[0] < 0) {
    mat_src.negateRow(pivotRow);
  }

  //mat.normalizeRowScalar(pivotRow);

  for (unsigned rowIndex = 0; rowIndex < NROW; rowIndex += 1) {
    auto pivotColBackup = mat_src(rowIndex, pivotCol);

    if ( rowIndex == pivotRow) { continue; }

    T c = mat_src(rowIndex, pivotCol);
    if (c == 0) { continue;   }

    mat_src(rowIndex, 0) *= mat_src(pivotRow, 0);
    for (unsigned col = 1; col < nCol; ++col) {
      if (col == pivotCol){ continue; }

      mat_src(rowIndex, col) = mat_src(rowIndex, col) * mat_src(pivotRow, 0) +
                           mat_src(rowIndex, pivotCol) * mat_src(pivotRow, col);
    }

    mat_src(rowIndex, pivotCol) *= mat_src(pivotRow, pivotCol);
    //mat.normalizeRowScalar(rowIndex);
  }

  return true;
}

template <typename T, MatColSize matColSize, VectorSize vectorSize>
bool pivot(matrix<T, vectorSize> & mat_src, matrix<T, vectorSize> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  exit(0);
  return false;
}




