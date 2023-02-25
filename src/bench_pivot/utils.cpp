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


int fetestexcept_local(int excepts)
{
	// Copied from https://github.com/openbsd/src/blob/master/lib/libm/arch/amd64/fenv.c
	unsigned short status = 0;
	unsigned int mxcsr = 0;

	excepts &= FE_ALL_EXCEPT;

	/* Store the current x87 status register */
	// Tobias: Removed, not sure why this is needed
	//__asm__ volatile ("fnstsw %0" : "=am" (status));

	/* Store the MXCSR register state */
	__asm__ volatile ("stmxcsr %0" : "=m" (mxcsr));

	return ((status | mxcsr) & excepts);
}
