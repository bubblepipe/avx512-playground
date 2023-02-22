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


static void if_fetestexcept(benchmark::State &state) {
  for (auto _ : state) {
      std::feclearexcept (FE_ALL_EXCEPT);
      if (std::fetestexcept(FE_INEXACT)) {
        exit(0);
    }
  }
}

BENCHMARK(except_on_off);
BENCHMARK(except_on_off_local);
BENCHMARK(if_fetestexcept);
BENCHMARK_MAIN();
