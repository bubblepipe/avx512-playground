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
    cc_cmd=$(cat <<-END
$cc $src -Wno-format $2 $params -std=c++11 -o /tmp/x  
-I ./src/ 
-isystem include/benchmark/include -L include/benchmark/build/src -l benchmark -lpthread 
-I ./libsimdpp
END
)
    cc_cmd=$(echo $cc_cmd |tr '\n' ' ')
    echo $cc_cmd 1>&2
    sh -c $cc_cmd && /tmp/x
    echo ======================================================== 1>&2
    # cc_t=`echo "$cc" | sed 's/ //g'`
    # objdump -M no-aliases -d /tmp/x > $cc_t".asm"
     
    echo
done



# -I ~/Documents/avx-512/libsimdpp