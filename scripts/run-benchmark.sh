#!/bin/bash
IFS=$'\n'
bold=$(tput bold)
normal=$(tput sgr0)

# note: must enable -O3 flag to have vectorization 
# native -mno-avx

ccs=( 
    #  'clang++-15 -g -O3 -march=native -mno-avx -mno-sse' 
     'clang++-15 -g -O3 -march=native'
    #  '/opt/llvm-project/llvm_install/bin/clang++ -O3 -march=native'
    )

src=$1

params="-DBENCH"
for cc in ${ccs[@]}
do
    echo ${bold}$cc${normal} 1>&2
    echo "$cc $src -Wno-format $params -std=c++11 -I ./src/ -isystem benchmark/include  -L benchmark/build/src -l benchmark -lpthread -o /tmp/x"  1>&2
    bash -c "$cc $src -Wno-format $params -std=c++11 -I ./src/ -isystem benchmark/include  -L benchmark/build/src -l benchmark -lpthread -o /tmp/x" && /tmp/x
    echo ======================================================== 1>&2
    # cc_t=`echo "$cc" | sed 's/ //g'`
    # objdump -M no-aliases -d /tmp/x > $cc_t".asm"
     
    echo
done
