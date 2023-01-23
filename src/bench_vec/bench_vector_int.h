#include <iostream>
#include <vector>
#include <utils/bench_utils.cpp>

void vec_fma(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr) {

    for (uint32_t i = 0; i < size; i += 1 ){
        dst_ptr[i] += src1_ptr[i] * src2_ptr[i];
    }
}

void vec_add_莎莎(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr) {

    for (uint32_t i = 0; i < size; i += 1 ){
        dst_ptr[i] = src1_ptr[i] + src2_ptr[i];
    }
}

void vec_add_manual(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr) {

    if (size % 8 != 0) {
        throw std::runtime_error(std::string("size not div by 8"));
    }

    for (uint32_t i = 0; i < size; i += 8 ){
        simdpp::uint32<8> src1_ymm = simdpp::load(src1_ptr + i);
        simdpp::uint32<8> src2_ymm = simdpp::load(src2_ptr + i);
        auto dst_ymm = simdpp::add(src1_ymm, src2_ymm);
        simdpp::store(dst_ptr + i, dst_ymm);
                                                        
    }
}


static void vector(benchmark::State& state, 
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
      src1_ptr[i] = (int32_t(rand())/int32_t((RAND_MAX)));
      src2_ptr[i] = (int32_t(rand())/int32_t((RAND_MAX)));
      dst_ptr[i] = (int32_t(rand())/int32_t((RAND_MAX)));
    }

    for (auto _ : state) {
        (*func_ptr)(size, src1_ptr, src2_ptr, dst_ptr);
    }

    for (uint32_t i = 0; i < size; i += 1 ){
      fprintf(somefile, "%x\n",  dst_ptr[i]);
    }

    free(src1_ptr);
    free(src2_ptr);
    free(dst_ptr);
    fclose(somefile);
}
