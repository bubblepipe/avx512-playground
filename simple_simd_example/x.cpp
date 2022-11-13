#include <iostream>
#include <vector>


void vec_add_莎莎(uint32_t size, float * src1_ptr, float * src2_ptr, float * dst_ptr) {

    for (uint32_t i = 0; i < size; i += 1 ){
        dst_ptr[i] = src1_ptr[i] + src2_ptr[i];
    }
    // return(dst_ptr[size-1]);
}

int main(){
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");

    uint32_t size = 128*128;
    float * src1_ptr = (float *) malloc(size * sizeof (float));
    float * src2_ptr = (float *) malloc(size * sizeof (float));
    float * dst_ptr =  (float *) malloc(size * sizeof (float));

    // fill src with rand, bring dst in cache
    for (uint32_t i = 0; i < size; i += 1 ){
      src1_ptr[i] = rand();
      src2_ptr[i] = rand();
      dst_ptr[i] = 0;
    }

    vec_add_莎莎(size, src1_ptr, src2_ptr, dst_ptr);

    for (uint32_t i = 0; i < size; i += 1 ){
      fprintf(somefile, "%x\n",  dst_ptr[i]);
    }

    free(src1_ptr);
    free(src2_ptr);
    free(dst_ptr);
}