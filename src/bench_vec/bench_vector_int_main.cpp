#include <bench_vec/bench_vector_int.hpp>

BENCHMARK_CAPTURE(vector, add,  &vec_add_莎莎)->Apply(RowColSizeArgs);
BENCHMARK_CAPTURE(vector, add_manual,  &vec_add_manual)->Apply(RowColSizeArgs);
BENCHMARK_CAPTURE(vector, fma,  &vec_fma)->Apply(RowColSizeArgs);
BENCHMARK_CAPTURE(vector, add_manual,  &vec_add_manual)->Apply(RowColSizeArgs);
BENCHMARK_MAIN();