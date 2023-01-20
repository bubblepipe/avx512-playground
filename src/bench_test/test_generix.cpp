#include <utils/bench_utils.cpp>
#include <simdpp/simd.h>
#include <chrono>

#include <iostream>
#include <thread>
 

template <class ...Args>
void BM_takes_args(benchmark::State& state, Args&&... args) {
  auto args_tuple = std::make_tuple(std::move(args)...);
  for (auto _ : state) {
    std::cout << std::get<0>(args_tuple) << ": " << std::get<1>(args_tuple)
              << '\n';
    [...]
  }
}


template <typename T>
void BM_takes_args2(benchmark::State& state, T t) {
  for (auto _ : state) {
    std::cout << t << '\n';
  }
}

// Registers a benchmark named "BM_takes_args/int_string_test" that passes
// the specified values to `args`.
BENCHMARK_CAPTURE(BM_takes_args, int_string_test, 42, std::string("abc"));

// Registers the same benchmark "BM_takes_args/int_test" that passes
// the specified values to `args`.
BENCHMARK_CAPTURE(BM_takes_args, int_test, 42, 43);

BENCHMARK_CAPTURE(BM_takes_args2, int_test, 42);

BENCHMARK_MAIN();
