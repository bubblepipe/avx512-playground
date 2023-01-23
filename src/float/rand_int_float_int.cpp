#include <stdlib.h>
#include <iostream>

double double_mul(double A, double B){
    printf("double mul %f * %f ", A, B);
    return A * B;
}

int main(){
    srand(1);

    // create 2 random int, 
    uint64_t A = rand();
    uint64_t B = rand();

    // do int mul
    uint64_t int_mul = A * B;
    printf("int mul %ld * %ld = %ld\n", A, B, int_mul);


    // convert to double, do double mul, convert back
    uint64_t doub_mul = double_mul(A, B);
    printf(" = %ld\n", doub_mul);

    // compare result
    
    printf("\n");
    return 0;
}