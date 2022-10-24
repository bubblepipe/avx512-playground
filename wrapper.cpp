#include "vector.cpp"

int main () {
    int src_size = 1024;
    int dst_size = 128;
    int * src_ptr = (int *) malloc(src_size * sizeof (int));
    int * dst_ptr = (int *) malloc(dst_size * sizeof(int));

    for (int i = 0; i < src_size; i += 1 ){
        src_ptr[i] = rand();
    }
    return vec_add_8(src_size, src_ptr, dst_size, dst_ptr);
}