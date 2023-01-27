#include <iostream>
#include <vector>
#include <bench_vec/bench_vector_int.hpp>
#include <immintrin.h>

void vec_fma(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr) {
    throw std::runtime_error(std::string("not implemented"));
}

void vec_mul(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr) {
    for (uint32_t i = 0; i < size; i += 1 ){
        auto tmp = __builtin_mul_overflow(src1_ptr[i]  , src2_ptr[i], &dst_ptr[i]);
        dst_ptr[i] = tmp;
    }
}

void vec_add_莎莎(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr) {
    for (uint32_t i = 0; i < size; i += 1 ){
        auto tmp = __builtin_add_overflow(src1_ptr[i]  , src2_ptr[i], &dst_ptr[i]);
        dst_ptr[i] = tmp;
    }
}

void vec_add_intrin(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr) {
    throw std::runtime_error(std::string("not implemented"));
}

void vec_add_simdpp(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr) {
    throw std::runtime_error(std::string("not implemented"));
}
