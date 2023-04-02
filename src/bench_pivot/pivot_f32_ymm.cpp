#include <bench_pivot/pivot.h>

// float YMM vector size is 8
// 8 -> 1 vector for a row
// 16 -> 2 vector for a row
// 24, 32 -> column loop

template<> bool pivot<float, _8, YMM>(matrix<float, YMM> & mat_src, matrix<float, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  typedef float T;
  typedef floatYmm Vec;
  auto nColPadding = YmmFloatVecSize; //mat_src.nColPadding;

  #include <bench_pivot/pivot_row_vec_1>

}

template<> bool pivot<float, _16, YMM>(matrix<float, YMM> & mat_src, matrix<float, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  typedef float T;
  typedef floatYmm Vec;
  auto const step_size = YmmFloatVecSize;
  auto const nColPadding = mat_src.nColPadding;
  auto const nCol = mat_src.nCol;

  #include <bench_pivot/pivot_row_vec_2>
}

template<> bool pivot<float, _24, YMM>(matrix<float, YMM> & mat_src, matrix<float, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  typedef float T;
  typedef floatYmm Vec;
  auto const step_size = YmmFloatVecSize;
  auto const nColPadding = 32;
  auto const nCol = 24;
  
  #include <bench_pivot/pivot_row_vec_loop>
}

template<> bool pivot<float, _32, YMM>(matrix<float, YMM> & mat_src, matrix<float, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  // FECLEAREXCEPT

  typedef float T;
  typedef floatYmm Vec;
  auto const step_size = YmmFloatVecSize;
  auto const nColPadding = 32;
  auto const nCol = 32;
  
  #include <bench_pivot/pivot_row_vec_loop>
}