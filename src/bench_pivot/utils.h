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

// #define PIVOT_DEFAULT
// #define NO_LOG
// #define SCALAR
// #define USE_MPInt
// #define USE_INT52
#define USE_INT23

#define TRIVIAL 0
#define INFO 114
#define WARNING 514
#define ERROR 1919

void printx(int priority, const char *__restrict format, ...);

#define ZmmDoubleVecSize 8
#define ZmmInt64VecSize 8
#define ZmmFloatVecSize 16

typedef double doubleZmm __attribute__((ext_vector_type(ZmmDoubleVecSize)));
typedef float floatZmm __attribute__((ext_vector_type(ZmmFloatVecSize)));
typedef int64_t int64Zmm __attribute__((ext_vector_type(ZmmInt64VecSize)));

void trigger_FPE();



int fetestexcept_local(int excepts);