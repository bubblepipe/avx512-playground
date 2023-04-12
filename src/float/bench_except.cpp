#include <cfenv>
#include <utils/cfenv_local.cpp>
#include <stdlib.h>
#include <benchmark/benchmark.h>

// static void except_on(benchmark::State &state) {
//   for (auto _ : state) {
//     std::feclearexcept (FE_ALL_EXCEPT);
//     feenableexcept (FE_INEXACT | FE_INVALID);
//   }
//   fedisableexcept (FE_INEXACT | FE_INVALID);
// }

// static void except_off(benchmark::State &state) {
  // for (auto _ : state) {
      // fedisableexcept (FE_INEXACT | FE_INVALID);
  // }
// }


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


static void fetestexcept_local(benchmark::State &state) {
  std::feclearexcept (FE_ALL_EXCEPT);
  for (auto _ : state) {
    if ( ! fetestexcept_local(FE_INEXACT)) {
      exit(0);
    }
  }
}
static void fetestexcept_mxcsr(benchmark::State &state) {
  std::feclearexcept (FE_ALL_EXCEPT);
  for (auto _ : state) {
    if  (! fetestexcept_mxcsr(FE_INEXACT)) {
      exit(0);
    }
  }
}
static void fetestexcept_x87(benchmark::State &state) {
  std::feclearexcept (FE_ALL_EXCEPT);
  for (auto _ : state) {
    if  ( fetestexcept_x87(FE_INEXACT)) {
      exit(0);
    }
  }
}

static void feclearexcept_lib(benchmark::State &state) {
  for (auto _ : state) {
  std::feclearexcept (FE_ALL_EXCEPT);
  }
}

static void feclearexcept_local(benchmark::State &state) {
  for (auto _ : state) {
    feclearexcept_local (FE_ALL_EXCEPT);
  }
}
static void feclearexcept_local_x87(benchmark::State &state) {
  for (auto _ : state) {
    feclearexcept_local_x87(FE_ALL_EXCEPT);
  }
}

static void feclearexcept_mxcsr(benchmark::State &state) {
  for (auto _ : state) {
    feclearexcept_local_sse(FE_ALL_EXCEPT);
  }
}

static void fetestexcept_feclearexcept_mxcsr(benchmark::State &state) {
  std::feclearexcept (FE_ALL_EXCEPT);
  for (auto _ : state) {
    feclearexcept_local_sse(FE_ALL_EXCEPT);
    if  (fetestexcept_mxcsr(FE_INEXACT)) {
      exit(0);
    }
  }
}

// BENCHMARK(except_on_off);


BENCHMARK(fetestexcept_local);
BENCHMARK(fetestexcept_x87);
BENCHMARK(fetestexcept_mxcsr);

// BENCHMARK(feclearexcept_lib);

BENCHMARK(feclearexcept_local);
BENCHMARK(feclearexcept_local_x87);
BENCHMARK(feclearexcept_mxcsr);

// BENCHMARK(fetestexcept_feclearexcept_mxcsr);


// \item fetestexcept                           8.15 ns
// \item fetestexcept\_x87                       4.33 ns
// \item fetestexcept\_mxcsr                     4.55 ns

// \item feclearexcept                          49.3 ns
// \item feclearexcept\_local\_x87                45.5 ns
// \item feclearexcept\_mxcsr                    9.42 ns
BENCHMARK_MAIN();
