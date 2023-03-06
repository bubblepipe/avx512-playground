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
