#include <benchmark/benchmark.h>
#include <bench_pivot/pivot.h>
#include <bench_pivot/input_matrix.cpp>
#include <bench_pivot/utils.h>

void prepare_mat(matrix<double> & mat){
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

  matrix<double> mat(nRow,nCol);

  for (auto _ : state) {
    prepare_mat(mat);
    pivot<double, doubleZmm>(mat, pivotRow, pivotCol);
    // validate(mat);
    // exit(0);


  }
}

BENCHMARK(PivotCol16Bench);
BENCHMARK_MAIN();
