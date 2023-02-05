#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cfenv>
#include <pthread.h>
#include <thread>
#include <vector>

double double_mul(double A, double B){
    return A * B;
}

#define INT52_MAX 0xFFFFFFFFFFFFF

void * mul_finder(uint64_t i_lo, uint64_t i_hi,
              uint64_t j_lo, uint64_t j_hi) {
        
    for(uint64_t i = i_lo; i < i_hi; i += 1){
        // printf("%lx * (%lx -> %lx)\n", i, j_lo, j_hi);

        for(uint64_t j = j_lo; j < j_hi; j += 1){

            uint64_t A = i;
            uint64_t B = j;

           int bits = (64 - __builtin_clzll(A)) + (64 - __builtin_clzll(B));

            if (bits <= 52 ) {
                uint64_t int_mul = A * B;
                uint64_t doub_mul = double_mul(A, B);
                if ((doub_mul != int_mul)) {
                    printf("%ld * %ld = %ld | %f NEQ\n", A, B, int_mul, doub_mul);
                    printf("0x%lx * 0x%lx = 0x%lx | 0x%lx NEQ\n", A, B, int_mul, doub_mul);
                    exit(0);
                }
            }
        }   
    }
    return 0;
    
}

int main(){
    std::vector<std::thread> threads;

    uint64_t threads_count = 20;
    uint64_t interval = 0xFFFF;
    // uint64_t interval = INT52_MAX / threads_count;
    printf("threads: %ld, interval: %ld\n", threads_count, interval); 

  
    for (uint64_t i = 0; i < 20; i += 1) {
        threads.push_back(std::thread(mul_finder, i, i+interval, 0, 0xFFFF));
    }

    for (auto &th : threads) {
        th.join();
    }
    // mul_finder(114,115, 0, INT52_MAX);

    return 0;
}