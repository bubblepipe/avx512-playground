#include <utils/bench_utils.cpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <simdpp/simd.h>
#include <utils/matrix.cpp>


void mat_fma ( unsigned int row, unsigned int col, 
    matrix<float> & mat_src1, matrix<float> & mat_src2, matrix<float> & mat_dst ) {
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            float src1 = mat_src1.get(i,j);
            float src2 = mat_src2.get(i,j);
            float src3 = mat_dst.get(i,j);
            mat_dst.set(i,j,  (src1 * src2) + src3);
        }
    }
}


void mat_fma_manual ( unsigned int row, unsigned int col, 
    matrix<float> & mat_src1, matrix<float> & mat_src2, matrix<float> & mat_dst ) {
    auto size = mat_src1.m.size();
    float * src1_ptr = (float *) mat_src1.m.data();
    float * src2_ptr = (float *) mat_src2.m.data();
    float * dst_ptr  = (float *) mat_dst.m.data();

    for (int i = 0; i < size; i += 8 ){
        simdpp::float32<8> src1_ymm = simdpp::load(src1_ptr + i);
        simdpp::float32<8> src2_ymm = simdpp::load(src2_ptr + i);
        simdpp::float32<8> src3_ymm = simdpp::load(dst_ptr + i);
        auto dst_new_ymm = simdpp::fmadd(src1_ymm, src2_ymm, src3_ymm);
        simdpp::store(dst_ptr + i, dst_new_ymm );                                         
    }
}

