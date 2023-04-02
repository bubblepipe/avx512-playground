#include "bench_pivot/utils.h"
#include <bench_pivot/pivot.h>

// double ZMM vector size is 8
// 8 -> 1 vector for a row
// 16 -> 2 vector for a row
// 


template<> bool pivot<double, _8, ZMM>(matrix<double, ZMM> & mat_src, matrix<double, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  // FECLEAREXCEPT

  typedef double T;
  typedef doubleZmm Vec;
  auto const nColPadding = ZmmDoubleVecSize; //mat_src.nColPadding;

  #include <bench_pivot/pivot_floating_row_vec_1>

}

template<> bool pivot<double, _16, ZMM>(matrix<double, ZMM> & mat_src, matrix<double, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  // FECLEAREXCEPT

  typedef double T;
  typedef doubleZmm Vec;
  auto const step_size = ZmmDoubleVecSize;
  auto const nColPadding = 16;
  auto const nCol = 16;

  #include <bench_pivot/pivot_floating_row_vec_2>

}

template<> bool pivot<double, _24, ZMM>(matrix<double, ZMM> & mat_src, matrix<double, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  typedef double T;
  typedef doubleZmm Vec;
  auto const step_size = ZmmDoubleVecSize;
  auto const nColPadding = 24;
  auto const nCol = 24;
  
  #include <bench_pivot/pivot_floating_row_vec_loop>
}

template<> bool pivot<double, _32, ZMM>(matrix<double, ZMM> & mat_src, matrix<double, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  typedef double T;
  typedef doubleZmm Vec;
  auto const step_size = ZmmDoubleVecSize;
  auto const nColPadding = 32;
  auto const nCol = 32;
  
  #include <bench_pivot/pivot_floating_row_vec_loop>
}
