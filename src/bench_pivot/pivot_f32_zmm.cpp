#include <bench_pivot/pivot.h>

// float ZMM vector size is 16
// 8 -> padding to 16
// 16 -> 1 vector for a row
// 24 -> padding to 32
// 32 -> 2 vector for a row

template<> bool pivot<float, _16, ZMM>(matrix<float, ZMM> & mat_src, matrix<float, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  // FECLEAREXCEPT

  typedef float T;
  typedef floatZmm Vec;
  auto const nColPadding = ZmmFloatVecSize; //mat_src.nColPadding;

  #include <bench_pivot/pivot_row_vec_1>

}

template<> bool pivot<float, _8, ZMM>(matrix<float, ZMM> & mat_src, matrix<float, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<float, _16, ZMM>(mat_src, mat_dst, pivotRow, pivotCol);
}

template<> bool pivot<float, _24, ZMM>(matrix<float, ZMM> & mat_src, matrix<float, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  typedef float T;
  typedef floatZmm Vec;
  auto const step_size = ZmmFloatVecSize;
  auto const nColPadding = 32;
  auto const nCol = 24;

  #include <bench_pivot/pivot_row_vec_2>
}

template<> bool pivot<float, _32, ZMM>(matrix<float, ZMM> & mat_src, matrix<float, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  // FECLEAREXCEPT

  typedef float T;
  typedef floatZmm Vec;
  auto const step_size = ZmmFloatVecSize;
  auto const nColPadding = 32;
  auto const nCol = 32;

  #include <bench_pivot/pivot_row_vec_2>

}


