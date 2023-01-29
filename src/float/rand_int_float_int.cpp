#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cfenv>
#include <pthread.h>

double double_mul(double A, double B){
    return A * B;
}

void * finder(void *arg) {
    while (true) {
        // create 2 random int, 
        uint64_t A = rand();// /10;
        uint64_t B = rand();// /10;

        uint64_t int_mul = A * B;
        int bits = 64 - __builtin_clzll(int_mul);

        uint64_t doub_mul = double_mul(A, B);
        // __sync_synchronize();
        // if (std::fetestexcept(FE_INEXACT)) printf ("inexact\n");

        if (doub_mul == int_mul) {
            printf("%ld * %ld = %ld | %ld EQ\n", A, B, int_mul, doub_mul);
        } else {
            printf("%ld * %ld = %ld | %ld NEQ\n", A, B, int_mul, doub_mul);
            return 0;
        }
    }
    return 0;
    
}
int main(){
    srand(1);

    pthread_t thread_id;

    for (int i = 0; i < 18; i += 1){
        pthread_create(&thread_id, NULL, &finder, NULL);
    }

    pthread_join(thread_id, NULL);

    return 0;
}