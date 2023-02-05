#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cfenv>
#include <pthread.h>


int main(){
    int16_t i16 = 0xf0ff;
    uint32_t u32 = i16;
    printf("i16: %#06hx, u32: %x\n", i16, u32);
    return 0;
}