#include <stdlib.h>
#include <iostream>

// https://stackoverflow.com/questions/41403718/can-i-use-the-avx-fma-units-to-do-bit-exact-52-bit-integer-multiplications

union int52_t
{
    uint64_t i;     
    double d; 
};  

int52_t ROUND; 
int52_t SCALE; 


uint64_t mask =  0x3ff0000000000000;
uint64_t undo_mask = ~mask;

int main(){
    ROUND.d = 30423614405477505635920876929024.;    //  3 * 2^103
    SCALE.d = 1. / 4503599627370496;                //  1 / 2^52

    int52_t i, j, k;

    for (i.i = 0; i.i < 4; i.i += 1){
        for (j.i = 0; j.i < 4; j.i += 1){

            int52_t H, L;

            H.d = i.d * j.d + ROUND.d;
            H.d = H.d - ROUND.d;

            L.d = i.d * j.d - H.d;
            H.d = H.d * SCALE.d;

            printf("0x%lx * 0x%lx = 0x%lx 0x%lx\n",i.i, j.i, H.i, L.i);
            printf("\n");
        }
    }
    return 0;
}