#include <iostream>
#include <benchmark/benchmark.h>
#include <thread>
#include <time.h>
#include <stdlib.h>


#include "vector.cpp"

static void bench(benchmark::State& state) {

    FILE* somefile = fopen("/dev/shm/1145141919810", "w");

    int group_size = 32;
    int src_size = 128*group_size;
    int dst_size = 128;
    int * src_ptr = (int *) malloc(src_size * sizeof (int));
    int * dst_ptr = (int *) malloc(dst_size * sizeof(int));

    for (int i = 0; i < src_size; i += 1 ){
      src_ptr[i] = rand();
    }

    for (int i = 0; i < dst_size; i += 1 ){
      dst_ptr[i] = 0;
    }

    for (auto _ : state) {
      vec_add(src_size, src_ptr, dst_size, dst_ptr, group_size);
    }

    for (int i = 0; i < dst_size; i += 1 ){
      fprintf(somefile, "%x\n",  dst_ptr[i]);
    }

  free(src_ptr);
  free(dst_ptr);
}


static void bench_shasha(benchmark::State& state) {

    FILE* somefile = fopen("/dev/shm/1145141919810", "w");

    int size = 128*128;
    int * src1_ptr = (int *) malloc(size * sizeof (int));
    int * src2_ptr = (int *) malloc(size * sizeof (int));
    int * dst_ptr = (int *) malloc(size * sizeof(int));

    // fill src with rand, bring dst in cache
    for (int i = 0; i < size; i += 1 ){
      src1_ptr[i] = rand();
      src2_ptr[i] = rand();
      dst_ptr[i] = 0;
    }

    for (auto _ : state) {
      vec_add_shasha(size, src1_ptr, src2_ptr, dst_ptr);
    }

    for (int i = 0; i < size; i += 1 ){
      fprintf(somefile, "%x\n",  dst_ptr[i]);
    }

  free(src1_ptr);
  free(src2_ptr);
  free(dst_ptr);
}

BENCHMARK(bench_shasha);
BENCHMARK_MAIN();