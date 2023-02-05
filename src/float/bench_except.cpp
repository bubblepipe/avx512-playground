#include <cfenv>
#include <utils/cfenv_local.cpp>
#include <stdlib.h>
#include <benchmark/benchmark.h>


static void except_on_off(benchmark::State &state) {
  for (auto _ : state) {
      std::feclearexcept (FE_ALL_EXCEPT);
      feenableexcept (FE_INEXACT | FE_INVALID);
      fedisableexcept (FE_INEXACT | FE_INVALID);
  }
}


static void except_on_off_local(benchmark::State &state) {
  for (auto _ : state) {
      std::feclearexcept (FE_ALL_EXCEPT);
      feenableexcept_local (FE_INEXACT | FE_INVALID);
      fedisableexcept (FE_INEXACT | FE_INVALID);
  }
}

BENCHMARK(except_on_off);
BENCHMARK(except_on_off_local);
BENCHMARK_MAIN();
