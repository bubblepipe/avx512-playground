#!/bin/bash

for NCOL in _8 _16 _24 _32
do
    echo "Size: $NCOL"
    for overflow in uncheck check
    do
        for datatype in -DUSE_INT16 -DUSE_INT23 -DUSE_INT52
        do
            flags=$datatype 
            flags+=" -DNCOL=$NCOL"
            if [ "$overflow" = "check" ]; then
                flags+=" -DCHECK_OVERFLOW"
            fi
            export PIVOT_SETTING=$flags
            make bench-pivot -j8 > /dev/null 
            for x in {1}
            # for x in {1..3}
            do
                OUTPUT=$(./build/pivot 2>/dev/null | tail -1) 
                OUTPUT=$overflow/$OUTPUT
                echo $OUTPUT
            done
        done
    done
done

export PIVOT_SETTING=""