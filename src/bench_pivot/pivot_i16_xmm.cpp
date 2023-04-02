#include <bench_pivot/pivot.h>
#include <utils/int16_utils.cpp>

// int16 XMM vector size is 8
// 8 -> 1 vector for a row
// 16 -> 2 vector for a row
// 24, 32 -> column loop


template<> bool pivot<int16_t, _8, XMM>(matrix<int16_t, XMM> & mat_src, matrix<int16_t, XMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  bool overflow_accum = false;

  typedef int16_t T;
  typedef int16Xmm Vec;
  auto nColPadding = XmmInt16VecSize; // mat_src.nColPadding;

  #include <bench_pivot/pivot_int_row_vec_1>

}

template<> bool pivot<int16_t, _32, XMM>(matrix<int16_t, XMM> & mat_src, matrix<int16_t, XMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return false;
  exit(0);
  // return pivot<int16_t, _32, XMM>(mat_src, mat_dst, pivotRow, pivotCol);
}

template<> bool pivot<int16_t, _16, XMM>(matrix<int16_t, XMM> & mat_src, matrix<int16_t, XMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return false;
  exit(0);
  // return pivot<int16_t, _32, XMM>(mat_src, mat_dst, pivotRow, pivotCol);
}

template<> bool pivot<int16_t, _24, XMM>(matrix<int16_t, XMM> & mat_src, matrix<int16_t, XMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return false;
  exit(0);
  // return pivot<int16_t, _32, XMM>(mat_src, mat_dst, pivotRow, pivotCol);
}
