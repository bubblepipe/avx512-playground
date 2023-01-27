#include <bench_vec/bench_vector_int.hpp>

void int_vector(benchmark::State& state, 
                   void (*func_ptr)(uint32_t, int32_t *, int32_t *, int32_t * ) ){
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");

    uint32_t row = state.range(0);
    uint32_t col = state.range(1);
    uint32_t size = row * col;
    int32_t * src1_ptr = (int32_t *) malloc(size * sizeof (int32_t));
    int32_t * src2_ptr = (int32_t *) malloc(size * sizeof (int32_t));
    int32_t * dst_ptr =  (int32_t *) malloc(size * sizeof (int32_t));

    // fill src with rand, bring dst in cache
    for (uint32_t i = 0; i < size; i += 1 ){
      src1_ptr[i] = rand()/1000000;
      src2_ptr[i] = rand()/1000000;
      dst_ptr[i]  = rand()/1000000;
    }

    for (auto _ : state) {
        (*func_ptr)(size, src1_ptr, src2_ptr, dst_ptr);
    }

    for (uint32_t i = 0; i < size; i += 1 ){
      fprintf(somefile, "%d, %d, %d\n", src1_ptr[i], src2_ptr[i], dst_ptr[i]);
    }

    free(src1_ptr);
    free(src2_ptr);
    free(dst_ptr);
    fclose(somefile);
}

#ifdef OVERFLOW
BENCHMARK_CAPTURE(int_vector, add_overflow,  &vec_add_莎莎)->Apply(RowColSizeArgs);
BENCHMARK_CAPTURE(int_vector, mul_overflow,  &vec_mul)->Apply(RowColSizeArgs);
#else
BENCHMARK_CAPTURE(int_vector, add,  &vec_add_莎莎)->Apply(RowColSizeArgs);
BENCHMARK_CAPTURE(int_vector, mul,  &vec_mul)->Apply(RowColSizeArgs);
// BENCHMARK_CAPTURE(int_vector, add_manual,  &vec_add_simdpp)->Apply(RowColSizeArgs);
// BENCHMARK_CAPTURE(int_vector, add_manual,  &vec_add_intrin)->Apply(RowColSizeArgs);
BENCHMARK_CAPTURE(int_vector, fma,  &vec_fma)->Apply(RowColSizeArgs);
#endif

BENCHMARK_MAIN();