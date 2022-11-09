#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t vec_add_8_init(uint32_t src_size, uint32_t * src_ptr, uint32_t dst_size, uint32_t * dst_ptr) {
    return 0;
}

uint32_t vec_add_horizontal_sum(uint32_t src_size, uint32_t * src_ptr, uint32_t dst_size, uint32_t * dst_ptr, uint32_t group_size) {

    for (uint32_t i = 0; i < dst_size; i += 1 ){
        uint32_t sum = 0;
        for (uint32_t j = 0; j < group_size; j += 1) {
            sum += src_ptr[i*group_size + j];
        }
        dst_ptr[i] = sum;
    }
    return(dst_ptr[dst_size-1]);
}


uint32_t vec_add_莎莎(uint32_t size, uint32_t * src1_ptr, uint32_t * src2_ptr, uint32_t * dst_ptr) {

    for (uint32_t i = 0; i < size; i += 1 ){
        dst_ptr[i] = src1_ptr[i] + src2_ptr[i];
    }
    return(dst_ptr[size-1]);
}

// uint32_t vec_add_流云(uint32_t size, uint32_t * src1_ptr, uint32_t * src2_ptr, uint32_t * dst_ptr) {

//     for (uint32_t i = 0; i < size; i += 1 ){
//         dst_ptr[i] = src1_ptr[i] + src2_ptr[i];
//     }
//     return(dst_ptr[size-1]);
// }

uint32_t vector_set_zero(uint32_t size, uint32_t * src_ptr) {

    for (uint32_t i = 0; i < size; i += 1 ){
        src_ptr[i] = 0;
    }
    return(src_ptr[size-1]);
}



// TODO: linear programming simplex operations
// 1. set row to 0 ?
// 2. ?

uint32_t nothing() {
    return 0;
}