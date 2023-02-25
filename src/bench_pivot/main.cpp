#include <benchmark/benchmark.h>
#include <bench_pivot/pivot.h>
#include <bench_pivot/input_matrix.cpp>
#include <bench_pivot/utils.h>

template <typename T>
void prepare_mat(matrix<T> & mat){
  for (int rowIndex = 0; rowIndex < mat.nRow; rowIndex += 1) {
    for (int colIndex = 0; colIndex < mat.nCol; colIndex += 1) {
      mat(rowIndex, colIndex) = input_mat_arr[rowIndex][colIndex];
    }
  }
}

void validate(matrix<double> & mat){
  for (int rowIndex = 0; rowIndex < mat.nRow; rowIndex += 1) {
    for (int colIndex = 0; colIndex < mat.nCol; colIndex += 1) {
      if (mat(rowIndex, colIndex) != expected_out_mat_arr[rowIndex][colIndex]){
        printf("mismatch at %d,%d\n", rowIndex, colIndex);
      }
    }
  }
}

static void PivotCol16Bench(benchmark::State& state) {
    
  auto nRow = input_mat_row;
  auto nCol = input_mat_col;
  auto pivotRow = input_mat_pivot_row;
  auto pivotCol = input_mat_pivot_col;

# ifdef USE_INT52
  matrix<double> mat(nRow,nCol);
  prepare_mat(mat);

  for (auto _ : state) {
    pivot<double, doubleZmm>(mat, pivotRow, pivotCol);
    // validate(mat); exit(0);
  }
# elif defined USE_INT23
  matrix<float> mat(nRow,nCol);
  prepare_mat(mat);

  for (auto _ : state) {
    pivot<float, floatZmm>(mat, pivotRow, pivotCol);
    // validate(mat); exit(0);
  }
# else
  printf("neither USE_INT23 not USE_INT52 is defined in pivot"); exit(0);
# endif

}

BENCHMARK(PivotCol16Bench);
BENCHMARK_MAIN();
