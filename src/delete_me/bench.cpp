#include <iostream>
#include <benchmark/benchmark.h>
#include <thread>
#include <time.h>
#include <stdlib.h>


#include "vector.cpp"

static void bench_horizontal_sum(benchmark::State& state) {

    FILE* somefile = fopen("/dev/shm/1145141919810", "w");

    uint32_t group_size = 32;
    uint32_t src_size = 128*group_size;
    uint32_t dst_size = 128;
    uint32_t * src_ptr = (uint32_t *) malloc(src_size * sizeof (uint32_t));
    uint32_t * dst_ptr = (uint32_t *) malloc(dst_size * sizeof(uint32_t));

    for (uint32_t i = 0; i < src_size; i += 1 ){
      src_ptr[i] = rand();
    }

    for (uint32_t i = 0; i < dst_size; i += 1 ){
      dst_ptr[i] = 0;
    }

    for (auto _ : state) {
      vec_add_horizontal_sum(src_size, src_ptr, dst_size, dst_ptr, group_size);
    }

    for (uint32_t i = 0; i < dst_size; i += 1 ){
      fprintf(somefile, "%x\n",  dst_ptr[i]);
    }

  free(src_ptr);
  free(dst_ptr);
}


static void bench_shasha(benchmark::State& state) {

    FILE* somefile = fopen("/dev/shm/1145141919810", "w");

    uint32_t size = 128*128;
    uint32_t * src1_ptr = (uint32_t *) malloc(size * sizeof (uint32_t));
    uint32_t * src2_ptr = (uint32_t *) malloc(size * sizeof (uint32_t));
    uint32_t * dst_ptr = (uint32_t *) malloc(size * sizeof(uint32_t));

    // fill src with rand, bring dst in cache
    for (uint32_t i = 0; i < size; i += 1 ){
      src1_ptr[i] = rand();
      src2_ptr[i] = rand();
      dst_ptr[i] = 0;
    }

    for (auto _ : state) {
      vec_add_莎莎(size, src1_ptr, src2_ptr, dst_ptr);
    }

    for (uint32_t i = 0; i < size; i += 1 ){
      fprintf(somefile, "%x\n",  dst_ptr[i]);
    }

  free(src1_ptr);
  free(src2_ptr);
  free(dst_ptr);
}


static void bench_set_zero(benchmark::State& state) {
  FILE* somefile = fopen("/dev/shm/1145141919810", "w");

  uint32_t src_size = 128*128;
  uint32_t * src_ptr = (uint32_t *) malloc(src_size * sizeof (uint32_t));

  for (uint32_t i = 0; i < src_size; i += 1 ){
    src_ptr[i] = i;
  }

  for (auto _ : state) {
    vector_set_zero(src_size, src_ptr);
  }

  for (uint32_t i = 0; i < src_size; i += 1 ){
    fprintf(somefile, "%x\n",  src_ptr[i]);
  }

}
BENCHMARK(bench_set_zero);
BENCHMARK_MAIN();