#include <cfenv>

inline int fetestexcept_local(int excepts)
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
