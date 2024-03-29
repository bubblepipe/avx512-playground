#include <stdio.h>
#include <stdlib.h>

#include <cfenv>
#include <iostream>
#include <limits>

#include <utils/cfenv_local.cpp>

#pragma STDC FENV_ACCESS ON

union uintd {
    uint64_t u;
    double d;
};

int main() {

    srand(1);

    uintd A, B;
    A.u = rand() / 1000;
    B.u = rand() / 1000;
    // A.d = 0;
    // B.d = 0;

    std::feclearexcept(FE_ALL_EXCEPT);

    // feenableexcept (FE_INEXACT | FE_INVALID);

    double x = A.d * B.d;
    if (std::fetestexcept(FE_INEXACT)) {
        std::cout << "inexact result reported\n";
    }

    feclearexcept_local_sse(FE_ALL_EXCEPT);

    if (std::fetestexcept(FE_INEXACT)) {
        std::cout << "inexact result reported\n";
    }

}