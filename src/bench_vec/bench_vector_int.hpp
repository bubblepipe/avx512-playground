#include <utils/bench_utils.cpp>

void vec_fma(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr);

void vec_mul(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr);

void vec_add_莎莎(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr);

void vec_add_simdpp(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr);

void vec_add_intrin(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr);
