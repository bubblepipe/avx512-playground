#include <stdio.h>
#include <float.h>
#include <cfenv>
#include <limits>
#include <signal.h>
#include <stdlib.h>

#pragma STDC FENV_ACCESS ON

#define	_SSE_MASK_SHIFT	7

int
feenableexcept_local(int mask)
{
	// Copied from https://github.com/openbsd/src/blob/master/lib/libm/arch/amd64/fenv.c
	unsigned int mxcsr, omask;
	unsigned short control;

	mask &= FE_ALL_EXCEPT;

	__asm__ volatile ("fnstcw %0" : "=m" (control));
	__asm__ volatile ("stmxcsr %0" : "=m" (mxcsr));

	omask = ~(control | (mxcsr >> _SSE_MASK_SHIFT)) & FE_ALL_EXCEPT;
	control &= ~mask;
	__asm__ volatile ("fldcw %0" : : "m" (control));

	mxcsr &= ~(mask << _SSE_MASK_SHIFT);
	__asm__ volatile ("ldmxcsr %0" : : "m" (mxcsr));

	return (omask);
}

int
fetestexcept_local(int excepts)
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

void catch_overflow (int sig) {
  printf ("caught f imprecise \n");
  // We could use longjmp to flip to a higher precision.
  exit(0);
}

void fmul_with_bits(int bits, bool trap) {
	printf("# Computing with %d bits\n", bits);

	std::feclearexcept (FE_ALL_EXCEPT);
	signal (SIGFPE, catch_overflow);

	if (trap) {
		// feenableexcept (FE_INEXACT);
		feenableexcept_local(FE_INEXACT);
	}

	double a = (2l << bits) + 13;
	long la = a;

	long lc = la * la + 13;
	double c = a * a + 13;


	printf("%f\n", c);
	printf("%ld\n", lc);

	// if (std::fetestexcept(FE_INEXACT))
	if (fetestexcept_local(FE_INEXACT))
		printf ("the computation was inexact\n");
	else
		printf ("the computation was exact\n");

	printf("\n");
}

// int main() {
// 	fmul_with_bits(20, false);
// 	fmul_with_bits(30, false);
// 	fmul_with_bits(20, false);

// 	fmul_with_bits(20, true /* trap */);
// 	fmul_with_bits(30, true /* trap */);
// 	fmul_with_bits(20, true /* trap */);
// }
