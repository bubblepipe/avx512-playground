#!/bin/bash
IFS=$'\n'
bold=$(tput bold)
normal=$(tput sgr0)

# note: must enable -O3 flag to have vectorization 
# native -mno-avx

ccs=( 
     'clang++-15 -O3 -march=native -mno-avx -mno-sse' 
     'clang++-15 -O3 -march=native'
    )

# src=./src/vector_add.cpp
src=./src/bench_matrix_fma.cpp

params="-DBENCH"cc
for cc in ${ccs[@]}
do
    echo ${bold}$cc${normal}
    bash -c "$cc $src -Wno-format $params -std=c++11 -I ./src/ -isystem benchmark/include  -L benchmark/build/src -l benchmark -lpthread -o /tmp/x" 
    # bash -c "$cc ./simple_simd_example/x-gb.cpp $params -std=c++11 -I ./src/ -isystem benchmark/include  -L benchmark/build/src -l benchmark -lpthread -o /tmp/x" 
    echo ========================================================
    cc_t=`echo "$cc" | sed 's/ //g'`
    objdump -M no-aliases -d /tmp/x > $cc_t".asm"
    # ./scripts/find-simd.sh $cc_t".asm"
    # echo ========================================================
    /tmp/x 
    echo
done
