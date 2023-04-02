#include <bench_pivot/pivot.h>
#include <cstddef>
#include <utils/int16_utils.cpp>

// int16 YMM vector size is 16
// 16 -> 1 vector for a row
// 8 -> padding, use 16
// 32 -> 2 vector for a row
// 24 -> padding, 32

template<> bool pivot<int16_t, _16, YMM>(matrix<int16_t, YMM> & mat_src, matrix<int16_t, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  bool overflow_accum = false;

  typedef int16_t T;
  typedef int16Ymm Vec;
  auto nColPadding = YmmInt16VecSize; // mat_src.nColPadding;

  #include <bench_pivot/pivot_int_row_vec_1>

}

template<> bool pivot<int16_t, _8, YMM>(matrix<int16_t, YMM> & mat_src, matrix<int16_t, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<int16_t, _16, YMM>(mat_src, mat_dst, pivotRow, pivotCol);
}

template<> bool pivot<int16_t, _24, YMM>(matrix<int16_t, YMM> & mat_src, matrix<int16_t, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return false;
  exit(0);
}
template<> bool pivot<int16_t, _32, YMM>(matrix<int16_t, YMM> & mat_src, matrix<int16_t, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return false;
  exit(0);
}
