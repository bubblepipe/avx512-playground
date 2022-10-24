#!/bin/bash
IFS=$'\n'
bold=$(tput bold)
normal=$(tput sgr0)

# targets=('g++ -O3' 'g++ -O3 -march=nehalem' 'g++ -O3 -march=skylake')
targets=('clang++-15 -O3' 'clang++-15 -O3 -march=nehalem' 'clang++-15 -O3 -march=skylake')

# targets=('clang++-15 -O0' 'clang++-15 -O3')

for cc in ${targets[@]}
do
    echo ${bold}$cc${normal}
    # bash -c "$cc ./wrapper.cpp -std=c++11 -isystem benchmark/include  -L benchmark/build/src -l benchmark -lpthread -o /tmp/x" 
    bash -c "$cc ./bench.cpp -std=c++11 -isystem benchmark/include  -L benchmark/build/src -l benchmark -lpthread -o /tmp/x" 
    echo ========================================================
    cc_t=`echo "$cc" | sed 's/ //g'`
    objdump -d /tmp/x > $cc_t".asm"
    ./find-simd.sh $cc_t".asm"
    echo ========================================================
    /tmp/x 
    echo
done
