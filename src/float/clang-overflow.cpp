#include <cstdio>
#include <stdint.h>

int main() {
    int32_t x, y, z, ret;
    x = 1;
    y = 0x7fffffff;
    ret = __builtin_add_overflow(x, y,&z);
    printf("%d + %d = %d, %d \n", x, y, z, ret);
    return 0;
}