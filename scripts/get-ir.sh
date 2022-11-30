#!/bin/bash

# params="-DBENCH"
# targets='clang++-15 -S -emit-llvm  -O3 -march=native' 
# cc=$targets
# clang++-15 -o -S -mno-avx -mno-sse -emit-llvm  -O3 -march=native ./src/matrix-dynamic-size.cpp $params -std=c++11 -I ./src/ -isystem benchmark/include  -L benchmark/build/src -l benchmark -lpthread -o ./simplex-llvm-ir-scalar

# clang++-15 -S -mno-avx -mno-sse -emit-llvm  -O3 -march=native ./x.cpp $params -std=c++11 -I ../src/  -o ./simplex-llvm-ir-scalar








IFS=$'\n'
bold=$(tput bold)
normal=$(tput sgr0)

# note: must enable -O3 flag to have vectorization 
# native -mno-avx

targets=('clang++-15 -O3 -march=native' 
         'clang++-15 -O3 -march=native -mno-avx -mno-sse' )

params="-DBENCH"
for cc in ${targets[@]}
do
    llvm_ir_filename=`echo "$cc""-step012.ll" | sed 's/ //g'`
    echo ${bold}$cc${normal}
    bash -c "$cc -S  -emit-llvm ./src/matrix-dynamic-size.cpp $params -std=c++11 -I ./src/ -isystem benchmark/include  -L benchmark/build/src -l benchmark -lpthread -o $llvm_ir_filename" 
done
