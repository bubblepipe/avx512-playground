#include <utils/bench_utils.cpp>

void vec_fma(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr);

void vec_add_莎莎(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr);

void vec_add_manual(uint32_t size, int32_t * src1_ptr, int32_t * src2_ptr, int32_t * dst_ptr);


void vector(benchmark::State& state, 
                   void (*func_ptr)(uint32_t, int32_t *, int32_t *, int32_t * ) );
