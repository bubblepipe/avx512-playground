#include "vector.cpp"

int main () {
  FILE* somefile = fopen("/dev/shm/1145141919810", "w");

  uint32_t src_size = 128*128;
  uint32_t * src_ptr = (uint32_t *) malloc(src_size * sizeof (uint32_t));

  for (uint32_t i = 0; i < src_size; i += 1 ){
    src_ptr[i] = i;
  }

    vector_set_zero(src_size, src_ptr);

  for (uint32_t i = 0; i < src_size; i += 1 ){
    fprintf(somefile, "%x\n",  src_ptr[i]);
  }

}