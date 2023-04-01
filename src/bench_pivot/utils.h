#ifndef UTILS_H
#define UTILS_H

#include <cstdarg>
#include <cstdint>
#include <vector>
#include <stdio.h>
#include <float.h>
#include <limits>
#include <signal.h>
#include <stdlib.h>
#include <immintrin.h>
#include <cfenv>

// #define PIVOT_DEFAULT
// #define NO_LOG
// #define USE_INT64
// #define USE_MPInt
// #define USE_INT16
#define USE_INT23
// #define USE_INT52
// #define EMPTY_PIVOT
// #define CHECK_OVERFLOW

#define NCOL _8
// #define NCOL _16
// #define NCOL _24
// #define NCOL _32

// #define VECTOR_SIZE XMM
#define VECTOR_SIZE YMM
// #define VECTOR_SIZE ZMM

#define UNROLL
#define SKIP_rowPtr_pivotCol_eq_0


#define NROW 30

enum VectorSize { scalar, XMM, YMM, ZMM };
enum MatColSize { _0, _8, _16, _24, _32,  };
int lookup(MatColSize matColSize);

#define ZmmDoubleVecSize 8
#define ZmmInt64VecSize 8
#define ZmmInt16VecSize 32
#define YmmInt16VecSize 16
#define XmmInt16VecSize 8
#define ZmmFloatVecSize 16
#define YmmFloatVecSize 8

typedef double doubleZmm __attribute__((ext_vector_type(ZmmDoubleVecSize)));
typedef float floatYmm __attribute__((ext_vector_type(YmmFloatVecSize)));
typedef float floatZmm __attribute__((ext_vector_type(ZmmFloatVecSize)));
typedef int64_t int64Zmm __attribute__((ext_vector_type(ZmmInt64VecSize)));
typedef int16_t int16Zmm __attribute__((ext_vector_type(ZmmInt16VecSize)));

void trigger_FPE();

#define TRIVIAL 0
#define INFO 114
#define WARNING 514
#define ERROR 1919
void printx(int priority, const char *__restrict format, ...);


// Copied from https://github.com/openbsd/src/blob/master/lib/libm/arch/amd64/fenv.c

inline int feclearexcept_local_sse(int excepts) {
	unsigned int mxcsr;
	__asm__ volatile ("stmxcsr %0" : "=m" (mxcsr));
	mxcsr &= ~excepts;
	__asm__ volatile ("ldmxcsr %0" : : "m" (mxcsr));
	return (0);
}

inline int fetestexcept_local_sse(int excepts) {
	unsigned short status = 0;
	unsigned int mxcsr = 0;
	excepts &= FE_ALL_EXCEPT;
	__asm__ volatile ("stmxcsr %0" : "=m" (mxcsr));
	return ((status | mxcsr) & excepts);
}

#endif