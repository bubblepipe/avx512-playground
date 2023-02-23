#include <cstdint>
#include <stdio.h>
#include <cfenv>

int main() {

    std::feclearexcept(FE_ALL_EXCEPT);

    int64_t i = 2147483647;
    float f32 = (float) i;
    double f64 = (double) i;

    // if (std::fetestexcept(FE_INEXACT)) {
    if (std::fetestexcept(FE_ALL_EXCEPT)) {
        printf("inexact result reported\n");
    }

    printf("int: %ld \n", i);
    printf("float: %f \n", f32);
    printf("double: %f \n", f64);
}