#include <stdio.h>
#include <stdlib.h>

int vec_add_8_init(int src_size, int * src_ptr, int dst_size, int * dst_ptr) {
    // int src_size = 1024;
    // int dst_size = 128;
    // int * src_ptr = (int *) malloc(src_size * sizeof (int));
    // int * dst_ptr = (int *) malloc(dst_size * sizeof(int));

    // for (int i = 0; i < src_size; i += 1 ){
    //         src_ptr[i] = rand();
    // }

    return 0;
}

int vec_add(int src_size, int * src_ptr, int dst_size, int * dst_ptr, int group_size) {

    for (int i = 0; i < dst_size; i += 1 ){
        int sum = 0;
        for (int j = 0; j < group_size; j += 1) {
            sum += src_ptr[i*group_size + j];
        }
        dst_ptr[i] = sum;
    }
    return(dst_ptr[dst_size-1]);
}


int vec_add_shasha(int size, int * src1_ptr, int * src2_ptr, int * dst_ptr) {

    for (int i = 0; i < size; i += 1 ){
        dst_ptr[i] = src1_ptr[i] + src2_ptr[i];
    }
    return(dst_ptr[size-1]);
}

int nothing() {
    return 0;
}