
#include <bench_pivot/pivot_f32_zmm.cpp>
#include <bench_pivot/pivot_f32_ymm.cpp>
#include <bench_pivot/pivot_f64.cpp>
#include <bench_pivot/pivot_i16.cpp>
#include <bench_pivot/pivot_MPInt.cpp>



template <typename T, MatColSize matColSize, VectorSize vectorSize>
bool pivot(matrix<T, vectorSize> & mat_src, matrix<T, vectorSize> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  exit(0);
  return false;
}



