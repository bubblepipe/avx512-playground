#include <bench_pivot/pivot.h>
#include <utils/int16_utils.cpp>

template<> bool pivot<int16_t, _32, ZMM>(matrix<int16_t, ZMM> & mat_src, matrix<int16_t, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  bool overflow_accum = false;

  typedef int16_t T;
  typedef int16Zmm Vec;
  auto nColPadding = ZmmInt16VecSize; // mat_src.nColPadding;

  #include <bench_pivot/pivot_int_row_vec_1>
}

template<> bool pivot<int16_t, _8, ZMM>(matrix<int16_t, ZMM> & mat_src, matrix<int16_t, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<int16_t, _32, ZMM>(mat_src, mat_dst, pivotRow, pivotCol);
}
template<> bool pivot<int16_t, _16, ZMM>(matrix<int16_t, ZMM> & mat_src, matrix<int16_t, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<int16_t, _32, ZMM>(mat_src, mat_dst, pivotRow, pivotCol);
}
template<> bool pivot<int16_t, _24, ZMM>(matrix<int16_t, ZMM> & mat_src, matrix<int16_t, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<int16_t, _32, ZMM>(mat_src, mat_dst, pivotRow, pivotCol);
}
