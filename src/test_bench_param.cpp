#include <benchmark/benchmark.h>
#include <iostream>

// define your chunksize and iteration count combinations here (for i and j) 
static void RowColSizeArgs(benchmark::internal::Benchmark* b) {
    int sizes[4] = {16,32,64,128};
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            b->Args({sizes[i], sizes[j]});
}

// the string (name of the used function is passed later)
static void TestBenchmark(benchmark::State& state, std::string func_name) {
  // cout for testing purposes
  std::cout << state.range(0) /* = i */ << " " << state.range(1) /* = j */ 
  << " " << func_name << std::endl;
  for (auto _ : state) {
     // do whatever with i and j and func_name
  }
}

// This macro is used to pass the string "function_name1/2/3" 
// as a parameter to TestBenchmark
BENCHMARK_CAPTURE(TestBenchmark, benchmarkname, "name")
    ->Apply(RowColSizeArgs);


BENCHMARK_MAIN();