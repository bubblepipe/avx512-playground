#include <benchmark/benchmark.h>
#include <bench_pivot/pivot.cpp>
#include <bench_pivot/input_matrix.cpp>

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
        printf("mismatch at %d,%d", rowIndex, colIndex);
      }
    }
  }
}

static void PivotCol16Bench(benchmark::State& state) {
    
  auto nRow = input_mat_row;
  auto nCol = input_mat_col;
  auto pivotRow = input_mat_pivot_row;
  auto pivotCol = input_mat_pivot_col;

  matrix<float> toy1(nRow,nCol);
  matrix<double> toy2(nRow,nCol);
  pivot<float, floatZmm>(toy1, pivotRow, pivotCol);
  pivot<double, doubleZmm>(toy2, pivotRow, pivotCol);
    

  matrix<double> mat(nRow,nCol);
  prepare_mat(mat);

  for (auto _ : state) {
    // prepare_mat(mat);
    pivot<double, doubleZmm>(mat, pivotRow, pivotCol);
    // validate(mat);
    // exit(0);


  }
}

BENCHMARK(PivotCol16Bench);
BENCHMARK_MAIN();
