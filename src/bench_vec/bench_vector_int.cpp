#include <iostream>
#include <vector>
#include <bench_vec/bench_vector_int.hpp>
#include <immintrin.h>

/*
thia does not vectorize
*/
void vec_fma(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr) {

    for (uint32_t i = 0; i < size; i += 1 ){
        dst_ptr[i] = src1_ptr[i] * src2_ptr[i] + src1_ptr[i];
    }
}

void vec_mul(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr) {
    for (uint32_t i = 0; i < size; i += 1 ){
        dst_ptr[i] = src1_ptr[i] * src2_ptr[i];
    }
}

void vec_add_intrin(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr) {

    if (size % 8 != 0) {
        throw std::runtime_error(std::string("size not div by 8"));
    }
    // todo
    // for (uint32_t i = 0; i < size; i += 8 ){
        // __m256i src1_ymm = _mm256_load_si256(src1_ptr + i);
        // __m256i src2_ymm = simdpp::load(src2_ptr + i);
        // auto dst_ymm = simdpp::add(src1_ymm, src2_ymm);
        // simdpp::store(dst_ptr + i, dst_ymm);
                                                        
    // }
}

void vec_add_莎莎(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr) {

    for (uint32_t i = 0; i < size; i += 1 ){
        dst_ptr[i] = src1_ptr[i] + src2_ptr[i];
    }
}

void vec_add_simdpp(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr) {

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
