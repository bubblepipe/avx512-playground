#include <benchmark/benchmark.h>
#include <utils/int16_utils.cpp>
#include <x86intrin.h>
#include <bench_pivot/utils.h>

#define START_TIMER     unsigned int dummy;  \
    unsigned long t1 = __rdtscp(&dummy);
#define STOP_TIMER     unsigned long t2 = __rdtscp(&dummy); \
    printf("Time: %ld\n",  t2 - t1); \


__m512i mul_no(__m512i & a, __m512i & b) {
  return _mm512_mullo_epi16(a,b);
}

__m512i no(__m512i & a, __m512i & b){
  int16Zmm c;
  c = mul_no(a,b);
  return c;
}

__m512i yes(__m512i & a, __m512i & b){
  int16Zmm c;
  c = _mm512_mullo_epi16(a, b);
  Vector16x32 hi = _mm512_mulhi_epi16(a, b);
  volatile bool oflow = ~equalMask(c >> 15, hi);
  return c;
}


int main () {
  srand(time(NULL));
  __m512i a = {rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),};
  __m512i b = {rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),};
  __m512i c ;

  auto f = fopen("/dev/null", "w");

  START_TIMER

  for (int i = 0; i < 100000000; i += 1) {
    // a = no(a,b);
    a = yes(a,b);
  }

  STOP_TIMER

  fprintf(f,"%x\n",a[0]);
  fprintf(f,"%x\n",a[1]);
  fprintf(f,"%x\n",a[2]);
  fprintf(f,"%x\n",a[3]);
  return 0;
}