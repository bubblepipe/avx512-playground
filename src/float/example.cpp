#include <stdlib.h>
#include <iostream>

union int52_t
{
    uint64_t i;     
    double d; 
};  

uint64_t mask =  0x3ff0000000000000;
uint64_t undo_mask = ~mask;

int main(){
    int52_t i, j, k;

    printf("Add\n=======================================\n");

    for (i.i = 0; i.i < 4; i.i += 1){
        for (j.i = 0; j.i < 4; j.i += 1){

            k.i = i.i + j.i;
            printf("int 0x%lx + 0x%lx = 0x%lx\n",i.i, j.i, k.i);

            k.d = i.d + j.d;
            printf("f64 0x%lx + 0x%lx = 0x%lx\n",i.i, j.i, k.i);

            printf("\n");

        }
    }


    printf("Mul\n=======================================\n");

    for (i.i = 0; i.i < 4; i.i += 1){
        for (j.i = 0; j.i < 4; j.i += 1){
            k.i = i.i * j.i;
            printf("int 0x%lx * 0x%lx = 0x%lx\n",i.i, j.i, k.i);

            int52_t i_tmp, j_tmp;
            i_tmp.i = i.i | mask;
            j_tmp.i = j.i | mask;
            k.d = i_tmp.d * j_tmp.d;
            k.i = k.i & undo_mask;
            printf("f64 0x%lx * 0x%lx = 0x%lx\n",i.i, j.i, k.i);

            printf("\n");
        }
    }
    return 0;
}