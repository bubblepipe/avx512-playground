#include <benchmark/benchmark.h>
#include <bench_pivot/pivot.h>
#include <bench_pivot/input_matrix_16.cpp>
#include <bench_pivot/utils.h>
#include <cstdarg>
#include <cstdint>
#include <bench_pivot/MPInt.h>

template <typename T>
void prepare_mat(matrix<T> & mat){
  for (int rowIndex = 0; rowIndex < mat.nRow; rowIndex += 1) {
    for (int colIndex = 0; colIndex < mat.nCol; colIndex += 1) {
      mat(rowIndex, colIndex) = input_mat_arr[rowIndex][colIndex];
    }
  }
}

template <typename T>
bool validate(matrix<T> & mat){
  bool ret = true;
  for (int rowIndex = 0; rowIndex < mat.nRow; rowIndex += 1) {
    for (int colIndex = 0; colIndex < mat.nCol; colIndex += 1) {
      if (! (mat(rowIndex, colIndex) == expected_out_mat_arr[rowIndex][colIndex])){
        if constexpr (std::is_same<T, int16_t>::value){
          printf("mismatch at %d,%d: %hd, %d\n", rowIndex, colIndex, mat(rowIndex, colIndex), expected_out_mat_arr[rowIndex][colIndex]);
        } else if constexpr (std::is_same<T, MPInt>::value){
          printf("mismatch at %d,%d: %ld, %d\n", rowIndex, colIndex, (int64_t)mat(rowIndex, colIndex), expected_out_mat_arr[rowIndex][colIndex]);
        } else {
          printf("mismatch at %d,%d: %f, %d\n", rowIndex, colIndex, mat(rowIndex, colIndex), expected_out_mat_arr[rowIndex][colIndex]);        }
        ret = false;
      }
    }
  }
  return ret; 
}

static void PivotCol16Bench(benchmark::State& state) {
    
  auto nRow = input_mat_row;
  auto nCol = input_mat_col;
  auto pivotRow = input_mat_pivot_row;
  auto pivotCol = input_mat_pivot_col;

#define BENCH(TYPE)    {                                    \
    matrix<TYPE> mat(nRow,nCol);                            \
    prepare_mat(mat);                                       \
    pivot<TYPE>(mat, pivotRow, pivotCol);                   \
    if (!validate(mat)) {mat.print(); exit(0);}                          \
    prepare_mat(mat);                                       \
    for (auto _ : state) {                                  \
      pivot<TYPE>(mat, pivotRow, pivotCol);                 \
    }                                                       \
  }

#ifdef SCALAR
  BENCH(int64_t)
#elif defined USE_MPInt
  BENCH(MPInt)
#elif defined USE_INT16
  BENCH(int16_t)
# elif defined USE_INT52
  BENCH(double)
# elif defined USE_INT23
  BENCH(float)
# else
  printf("neither USE_INT23 not USE_INT52 is defined in pivot"); exit(0);
# endif

}


#ifdef SCALAR
  BENCH(int64_t)
#elif defined USE_MPInt
  BENCHMARK(PivotCol16Bench)->Name("MPInt");
#elif defined USE_INT16
  BENCHMARK(PivotCol16Bench)->Name("int16_t");
# elif defined USE_INT52
  BENCHMARK(PivotCol16Bench)->Name("double");
# elif defined USE_INT23
  BENCHMARK(PivotCol16Bench)->Name("float");
# else
  printf("neither USE_INT23 not USE_INT52 is defined in pivot"); exit(0);
# endif
BENCHMARK_MAIN();
