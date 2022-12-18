/**
 * This benchmark setup uses:
 *    class matrix 
 * not:
 *    vector<vector<T>>
 */

#include <iostream>
#include <benchmark/benchmark.h>
#include <thread>
#include <time.h>
#include <stdlib.h>

class matrix {

public:

  std::vector<std::vector<int>> m;

  matrix(unsigned int x, unsigned int y) {
    m.resize(x, std::vector<int>(y,0));
  }
  
  class matrix_row {
    std::vector<int>& row;
  
  public:
    
    matrix_row(std::vector<int>& r) : row(r) { }
    
    int& operator[](unsigned int y) {
      return row.at(y);
    }
  };
  
  matrix_row operator[](unsigned int x) {
    return m.at(x);
  }

};

#define ROW 64
#define COL 1024

static void fill_1(benchmark::State& state) {

  matrix my_matrix(ROW,COL);
  // std::this_thread::sleep_for(std::chrono::milliseconds (514));

  for (auto _ : state) {

    for (int i = 0; i < ROW; i += 1) {
      for (int j = 0; j < COL; j += 1) {
        my_matrix[i][j] = 1;
      }
    }

  }
}


static void matrix_add_1(benchmark::State& state) {

  matrix matrix_l(ROW,COL);

  for (int i = 0; i < ROW; i += 1) {
    for (int j = 0; j < COL; j += 1) {
      matrix_l[i][j] = rand();
    }
  }

  std::cout << matrix_l[0][0] << std::endl;

  for (auto _ : state) {
    for (int i = 0; i < ROW; i += 1) {
      for (int j = 0; j < COL; j += 1) {
        matrix_l[i][j] += 1;
      }
    }
  }

  std::cout << matrix_l[0][0] << std::endl;
}

static void matrix_add(benchmark::State& state) {

  matrix matrix_l(ROW,COL);
  matrix matrix_r(ROW,COL);

  for (int i = 0; i < ROW; i += 1) {
    for (int j = 0; j < COL; j += 1) {
      matrix_l[i][j] = rand();
      matrix_r[i][j] = rand();
    }
  }

  for (auto _ : state) {

    for (int i = 0; i < ROW; i += 1) {
      for (int j = 0; j < COL; j += 1) {
        matrix_l[i][j] += matrix_r[i][j];
      }
    }

  }
}


BENCHMARK(matrix_add);
BENCHMARK_MAIN();