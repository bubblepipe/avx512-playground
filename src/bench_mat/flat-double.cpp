#include <utils/bench_utils.cpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <simdpp/simd.h>
#include <cfenv>
#include <csignal>
#include <utils/cfenv_local.cpp>

class matrix {

public:

    std::vector<double> m;
    unsigned int row;
    unsigned int col;

    matrix(unsigned int r, unsigned int c) {
        row = r;
        col = c;
        m.resize(r * c);
    }
  
    public:
        double get(unsigned int x, unsigned int y) {
            return m[col * x + y];
        }
        void set(unsigned int x, unsigned int y, double val) {
            m[col * x + y] = val;
        }
};

void mat_fma ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
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
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {

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
}

void mat_fma_manual_check ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
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
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
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
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
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
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
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
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
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
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
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

void signal_handler(int signal)
{
    printf("signal handler\n");
    exit(0);
}
 
static void flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix &, matrix &, matrix & )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");
    srand(1);
    std::signal(SIGFPE, signal_handler);

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix mat_src1(row,col);
    matrix mat_src2(row,col);
    matrix mat_dst(row,col);
    matrix mat_dst_ref(row,col);

    for (int r = 0; r < row; r += 1) {
        for (int c = 0; c < col; c += 1) {
            mat_src1.set(r,c, r + 1 ); // rand()/1 );
            mat_src2.set(r,c, c + 1 ); // rand()/1 );
            mat_dst. set(r,c, c + 1 ); // rand()/1 );
            mat_dst_ref.set(r,c, mat_dst.get(r,c));
        }
    }

    for (auto _ : state) {
        for (int r = 0; r < row; r += 1) {
            for (int c = 0; c < col; c += 1) {
                mat_dst.set(r,c, mat_dst_ref.get(r,c) );
            }
        }
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_dst);
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            fprintf(somefile, "%f, %f, %f -> %f\n", 
                mat_src1.get(i,j), mat_src2.get(i,j), 
                mat_dst_ref.get(i,j), mat_dst.get(i,j));
        }
    }

    fclose(somefile);
}


#ifdef TEST
#define BMarg Apply(RowColSizeArgs)->Iterations(1)
#else
#define BMarg Apply(RowColSizeArgs)
#endif	
BENCHMARK_CAPTURE(flat, fma_m, &mat_fma_manual)->BMarg;
BENCHMARK_CAPTURE(flat, fma, &mat_fma)->BMarg;
BENCHMARK_CAPTURE(flat, fma_check, &mat_fma_check)->BMarg;
BENCHMARK_CAPTURE(flat, fma_m_check, &mat_fma_manual_check)->BMarg;

BENCHMARK_CAPTURE(flat, 2m1a_m, &mat_2m1a_manual)->BMarg;
BENCHMARK_CAPTURE(flat, 2m1a_m_check, &mat_2m1a_manual_check_REALISTIC)->BMarg;
BENCHMARK_CAPTURE(flat, 2m1a_m_local_check, &mat_2m1a_manual_local_check_REALISTIC)->BMarg;

BENCHMARK_MAIN();