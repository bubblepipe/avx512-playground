# clang++-15 -O3 -march=native -mno-avx -mno-sse ./x.cpp -o /tmp/x
clang++-15 -O3 -march=native ./x.cpp -o /tmp/x
objdump -d /tmp/x > /tmp/x.asm