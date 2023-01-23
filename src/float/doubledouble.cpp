#include <stdlib.h>
#include <iostream>
#include <math.h>
typedef struct {
  double hi;
  double lo;
} doubledouble;

static doubledouble quick_two_sum(double a, double b) {
  double s = a + b;
  double e = b - (s - a);
  return (doubledouble){s, e};
}

static doubledouble two_prod(double a, double b) {
  double p = a*b;
  double e = fma(a, b, -p);
  return (doubledouble){p, e};
}

doubledouble df64_mul(doubledouble a, doubledouble b) {
  doubledouble p = two_prod(a.hi, b.hi);
  p.lo += a.hi*b.lo;
  p.lo += a.lo*b.hi;
  return quick_two_sum(p.hi, p.lo);
}
int main(){
    int a = 114;
    int b = 2;
    auto x = two_prod(a,b);
    // auto x = two_prod(3202129,4807935);
    int64_t s = x.hi+x.lo;
    printf("0x%lx\n", s);
    printf("%ld\n", s);
}