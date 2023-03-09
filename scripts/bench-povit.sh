#!/bin/bash


for overflow in uncheck check
do
    for datatype in -DUSE_INT16 -DUSE_INT23 -DUSE_INT52
    do
        flags=$datatype 
        if [ "$overflow" = "check" ]; then
            flags+=" -DCHECK_OVERFLOW"
        fi
        export PIVOT_SETTING=$flags
        make bench-pivot -j8 > /dev/null 
        for x in {1..8}
        do
            OUTPUT=$(./build/pivot 2>/dev/null | tail -1) 
            OUTPUT=$overflow/$OUTPUT
            echo $OUTPUT
        done
    done
done
export PIVOT_SETTING=""