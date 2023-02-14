#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <simdpp/simd.h>
#include <cfenv>
#include <utils/cfenv_local.cpp>
#include <utils/matrix.cpp>
#include <utils/bench_utils.cpp>
#include <x86intrin.h>
#include <immintrin.h>

void mat_fma ( unsigned int row, unsigned int col, 
    matrix<double> & mat_src1, matrix<double> & mat_src2, matrix<double> & mat_dst ) {
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            double src1 = mat_src1.get(i,j);
            double src2 = mat_src2.get(i,j);
            double src3 = mat_dst.get(i,j);
            mat_dst.set(i,j,  (src1 * src2) + src3);
        }
    }
}

void mat_fma_check ( unsigned int row, unsigned int col, 
    matrix<double> & mat_src1, matrix<double> & mat_src2, matrix<double> & mat_dst ) {

    std::feclearexcept (FE_ALL_EXCEPT);
    feenableexcept (FE_INEXACT | FE_INVALID);

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            double src1 = mat_src1.get(i,j);
            double src2 = mat_src2.get(i,j);
            double src3 = mat_dst.get(i,j);
            double result = (src1 * src2) + src3;

            mat_dst.set(i,j, result );

        }
    }

    fedisableexcept (FE_INEXACT | FE_INVALID);

}

void mat_fma_manual_check ( unsigned int row, unsigned int col, 
    matrix<double> & mat_src1, matrix<double> & mat_src2, matrix<double> & mat_dst ) {
    auto size = mat_src1.m.size();
    double * src1_ptr = (double *) mat_src1.m.data();
    double * src2_ptr = (double *) mat_src2.m.data();
    double * dst_ptr  = (double *) mat_dst.m.data();
    std::feclearexcept (FE_ALL_EXCEPT);
    feenableexcept (FE_INEXACT | FE_INVALID);

    for (int i = 0; i < size; i += 4 ){
            simdpp::float64<4> src1_ymm = simdpp::load(src1_ptr + i);
            simdpp::float64<4> src2_ymm = simdpp::load(src2_ptr + i);
            simdpp::float64<4> src3_ymm = simdpp::load(dst_ptr + i);
            auto dst_new_ymm = simdpp::fmadd(src1_ymm, src2_ymm, src3_ymm);
            simdpp::store(dst_ptr + i, dst_new_ymm );                
    }

    fedisableexcept (FE_INEXACT | FE_INVALID);
}

void mat_2m1a_manual_check ( unsigned int row, unsigned int col, 
    matrix<double> & mat_src1, matrix<double> & mat_src2, matrix<double> & mat_dst ) {
    auto size = mat_src1.m.size();
    double * src1_ptr = (double *) mat_src1.m.data();
    double * src2_ptr = (double *) mat_src2.m.data();
    double * dst_ptr  = (double *) mat_dst.m.data();
    std::feclearexcept (FE_ALL_EXCEPT);
    feenableexcept (FE_INEXACT | FE_INVALID);

    for (int i = 0; i < size; i += 4 ){
        simdpp::float64<4> src1_ymm = simdpp::load(src1_ptr + i);
        simdpp::float64<4> src2_ymm = simdpp::load(src2_ptr + i);
        simdpp::float64<4> src3_ymm = simdpp::load(dst_ptr + i);
        // (src1 * src3) + (src2 * src3)
        auto src2xsrc3 = simdpp::mul(src2_ymm, src3_ymm);
        auto dst_new_ymm = simdpp::fmadd(src1_ymm, src3_ymm, src2xsrc3);
        simdpp::store(dst_ptr + i, dst_new_ymm );                
    }

    fedisableexcept (FE_INEXACT | FE_INVALID);
}


void mat_2m1a_manual ( unsigned int row, unsigned int col, 
    matrix<double> & mat_src1, matrix<double> & mat_src2, matrix<double> & mat_dst ) {
    auto size = mat_src1.m.size();
    auto colsize = mat_src1.row;
    auto rowsize = mat_src1.col;

    // vec <- mat_src1[*]
    // BaseInt(c) <- mat_src2[*] 
    // pivotRowVecTerm <- src2[0] 
    // aVector <- src2[1] 

    // (vec * aVector) + (baseC * PivRowVecTerm)

    double * pivRow = (double *) mat_src2.m.data();
    double * aVec = (double *) mat_src2.m.data() + rowsize;
    double * baseC = (double *) mat_src2.m.data();
    double * vec = (double *) mat_src1.m.data();
    double * dst_ptr = (double *) mat_dst.m.data();
    
    for (int i = 0; i < colsize; i += 1 ){
        for (int j = 0; j < rowsize; j += 4 ){
            simdpp::float64<4> vec_ymm = simdpp::load(vec + i * rowsize + j);
            simdpp::float64<4> baseC_ymm = simdpp::load(baseC + i * rowsize + j);
            simdpp::float64<4> pivRow_ymm = simdpp::load(pivRow + j);
            simdpp::float64<4> aVec_ymm = simdpp::load(aVec + j);
            auto tmp = simdpp::mul(baseC_ymm, pivRow_ymm);
            auto result = simdpp::fmadd(vec_ymm, aVec_ymm, tmp);
            simdpp::store(dst_ptr + i, result );
        }
    }

}


void mat_2m1a_manual_check_REALISTIC ( unsigned int row, unsigned int col, 
    matrix<double> & mat_src1, matrix<double> & mat_src2, matrix<double> & mat_dst ) {
    auto size = mat_src1.m.size();
    auto colsize = mat_src1.row;
    auto rowsize = mat_src1.col;

    // vec <- mat_src1[*]
    // BaseInt(c) <- mat_src2[*] 
    // pivotRowVecTerm <- src2[0] 
    // aVector <- src2[1] 

    // (vec * aVector) + (baseC * PivRowVecTerm)

    double * pivRow = (double *) mat_src2.m.data();
    double * aVec = (double *) mat_src2.m.data() + rowsize;
    double * baseC = (double *) mat_src2.m.data();
    double * vec = (double *) mat_src1.m.data();
    double * dst_ptr = (double *) mat_dst.m.data();
    
    std::feclearexcept (FE_ALL_EXCEPT);
    feenableexcept (FE_INEXACT | FE_INVALID);

    for (int i = 0; i < colsize; i += 1 ){
        for (int j = 0; j < rowsize; j += 4 ){
            simdpp::float64<4> vec_ymm = simdpp::load(vec + i * rowsize + j);
            simdpp::float64<4> baseC_ymm = simdpp::load(baseC + i * rowsize + j);
            simdpp::float64<4> pivRow_ymm = simdpp::load(pivRow + j);
            simdpp::float64<4> aVec_ymm = simdpp::load(aVec + j);
            auto tmp = simdpp::mul(baseC_ymm, pivRow_ymm);
            auto result = simdpp::fmadd(vec_ymm, aVec_ymm, tmp);
            simdpp::store(dst_ptr + i, result );
        }
    }

    fedisableexcept (FE_INEXACT | FE_INVALID);
}

void mat_2m1a_manual_local_check_REALISTIC ( unsigned int row, unsigned int col, 
    matrix<double> & mat_src1, matrix<double> & mat_src2, matrix<double> & mat_dst ) {
    auto size = mat_src1.m.size();
    auto colsize = mat_src1.row;
    auto rowsize = mat_src1.col;

    // vec <- mat_src1[*]
    // BaseInt(c) <- mat_src2[*] 
    // pivotRowVecTerm <- src2[0] 
    // aVector <- src2[1] 

    // (vec * aVector) + (baseC * PivRowVecTerm)

    double * pivRow = (double *) mat_src2.m.data();
    double * aVec = (double *) mat_src2.m.data() + rowsize;
    double * baseC = (double *) mat_src2.m.data();
    double * vec = (double *) mat_src1.m.data();
    double * dst_ptr = (double *) mat_dst.m.data();
    
    std::feclearexcept (FE_ALL_EXCEPT);
    feenableexcept_local (FE_INEXACT | FE_INVALID);

    for (int i = 0; i < colsize; i += 1 ){
        for (int j = 0; j < rowsize; j += 4 ){
            simdpp::float64<4> vec_ymm = simdpp::load(vec + i * rowsize + j);
            simdpp::float64<4> baseC_ymm = simdpp::load(baseC + i * rowsize + j);
            simdpp::float64<4> pivRow_ymm = simdpp::load(pivRow + j);
            simdpp::float64<4> aVec_ymm = simdpp::load(aVec + j);
            auto tmp = simdpp::mul(baseC_ymm, pivRow_ymm);
            auto result = simdpp::fmadd(vec_ymm, aVec_ymm, tmp);
            simdpp::store(dst_ptr + i, result );
        }
    }

    fedisableexcept (FE_INEXACT | FE_INVALID);
}


void mat_fma_manual ( unsigned int row, unsigned int col, 
    matrix<double> & mat_src1, matrix<double> & mat_src2, matrix<double> & mat_dst ) {
    auto size = mat_src1.m.size();
    double * src1_ptr = (double *) mat_src1.m.data();
    double * src2_ptr = (double *) mat_src2.m.data();
    double * dst_ptr  = (double *) mat_dst.m.data();

    for (int i = 0; i < size; i += 4 ){
        simdpp::float64<4> src1_ymm = simdpp::load(src1_ptr + i);
        simdpp::float64<4> src2_ymm = simdpp::load(src2_ptr + i);
        simdpp::float64<4> src3_ymm = simdpp::load(dst_ptr + i);
        auto dst_new_ymm = simdpp::fmadd(src1_ymm, src2_ymm, src3_ymm);
        simdpp::store(dst_ptr + i, dst_new_ymm );                                         
    }
}

void mat_fma_intrinsic ( unsigned int row, unsigned int col, 
    matrix<double> & mat_src1, matrix<double> & mat_src2, matrix<double> & mat_dst ) {
    auto size = mat_src1.m.size();
    double * src1_ptr = (double *) mat_src1.m.data();
    double * src2_ptr = (double *) mat_src2.m.data();
    double * dst_ptr  = (double *) mat_dst.m.data();

    for (int i = 0; i < size; i += 4 ){
        __m256 src1 = _mm256_loadu_pd ((const double *) (src1_ptr + i));
        __m256 src2 = _mm256_loadu_pd ((const double *) (src2_ptr + i));
        __m256 src3 = _mm256_loadu_pd ((const double *) (dst_ptr + i));
        __m256 result = _mm256_fmadd_pd(src1, src2, src3);
        _mm256_storeu_pd((double *) (dst_ptr + i), result);
    }
}

void mat_fma_manual_rdtscp ( unsigned int row, unsigned int col, 
    matrix<double> & mat_src1, matrix<double> & mat_src2, matrix<double> & mat_dst ) {

    unsigned int dummy;
    unsigned long long t1 = __rdtscp(&dummy);

    mat_fma_manual(row, col, mat_src1, mat_src2, mat_dst);

    unsigned long long t2 = __rdtscp(&dummy);
    std::cout << "Time: " << t2 - t1 << std::endl;

    exit(0);
}



