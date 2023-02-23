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
#include <utils/cfenv_local.cpp>

// #define PIVOT_DEFAULT
// #define NO_LOG
// #define SCALAR
// #define USE_INT52
#define USE_INT23

#define TRIVIAL 0
#define INFO 114
#define WARNING 514
#define ERROR 1919

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

#define ZmmDoubleVecSize 8
#define ZmmFloatVecSize 16
// typedef double doubleYmm __attribute__((ext_vector_type(4)));
typedef double doubleZmm __attribute__((ext_vector_type(ZmmDoubleVecSize)));
// typedef float floatYmm __attribute__((ext_vector_type(8)));
typedef float floatZmm __attribute__((ext_vector_type(ZmmFloatVecSize)));

void trigger_FPE(){
  double a = (double)0x7FFFFFF1234FFFFF;
  double b = a * a;
  printf("%f %f\n",a, b);
}


template <typename T>
inline T greatestCommonDivisor(T A, T B) {
  while (B) {
    T Tmp = B;
    B = A % B;
    A = Tmp;
  }
  return A;
}