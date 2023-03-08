#include <cstdint>
#include <cstdio>
int main() {
    int16_t i16 = 0xffff;
    int32_t i32 = 0xffffff;
    bool eq = i16 == i32;
    printf("%d\n",eq);
}