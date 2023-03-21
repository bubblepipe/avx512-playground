#include <cstdarg>
#include <cstdint>
#include <vector>
#include <stdio.h>
#include <float.h>
#include <cfenv>
#include <limits>
#include <signal.h>
#include <stdlib.h>
#include <immintrin.h>
#include <bench_pivot/utils.h>

int lookup(MatColSize matColSize) {

    switch (matColSize) {
        case MatColSize::_0:   return 0;
        case MatColSize::_8:   return 8;
        case MatColSize::_16:  return 16;
        case MatColSize::_24:  return 24;
        case MatColSize::_32:  return 32;
    }
}

void printx(int priority, const char *__restrict format, ...) {

#ifdef NO_LOG
  if (false) {
#else
  if (priority >= 1) {
#endif
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
  }
}

void trigger_FPE(){
  double a = (double)0x7FFFFFF1234FFFFF;
  double b = a * a;
  printf("%f %f\n",a, b);
}
