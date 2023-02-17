#include <cstdint>
#include <cstdio>
#include <immintrin.h>
#include <cfenv>

// typedef int64_t VectorI __attribute__((ext_vector_type(4)));
typedef int64_t VectorI __attribute__((ext_vector_type(8)));
typedef double VectorD __attribute__((ext_vector_type(8)));

int64_t * ifma(VectorI veca, VectorI vecb, VectorI vecc){
                                                // b * c + a
    __m512 result_ifma = _mm512_madd52lo_epu64(veca, vecb, vecc);
    auto result_ifma_arr = ((int64_t*)&result_ifma);
    printf("%ld\n", result_ifma_arr[0]);
    return result_ifma_arr;
}

double * dfma(VectorD veca, VectorD vecb, VectorD vecc){
    __m512 result_dfma = _mm512_fmadd_pd(veca, vecb, vecc);
    auto result_dfma_arr = ((double*)&result_dfma);
    printf("%f\n", result_dfma_arr[0]);
    return result_dfma_arr;
}

int main(){

    srand(1);

    VectorI a = rand();//3;
    VectorI b = rand();//5;
    VectorI c = rand();//7;
    __m512 veca = a;
    __m512 vecb = b;
    __m512 vecc = c;

    auto veca_arr = ((int64_t*)&veca);
    auto vecb_arr = ((int64_t*)&vecb);
    auto vecc_arr = ((int64_t*)&vecc);
    printf("%ld\n", veca_arr[0]);
    printf("%ld\n", vecb_arr[0]);
    printf("%ld\n", vecc_arr[0]);

    std::feclearexcept(FE_ALL_EXCEPT);
    feenableexcept (FE_INEXACT | FE_INVALID);

    printf("start ifma operation\n");
    ifma(2, 3, 4);
    ifma(veca, vecb, vecc);
    ifma(4, 5, 6);
    
    printf("start double operation\n");
    dfma(2.0, 3.0, 4.0);
    dfma(veca, vecb, vecc);


}