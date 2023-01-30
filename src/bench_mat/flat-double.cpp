#include <utils/bench_utils.cpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <simdpp/simd.h>
#include <cfenv>

// #define DATA_TYPE double

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

void mat_fma_inacurate_check ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {

    std::feclearexcept (FE_ALL_EXCEPT);

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            double src1 = mat_src1.get(i,j);
            double src2 = mat_src2.get(i,j);
            double src3 = mat_dst.get(i,j);
            double result = (src1 * src2) + src3;

            if (std::fetestexcept(FE_INEXACT)){
                std::feclearexcept (FE_ALL_EXCEPT);
                printf("[%d][%d]: %f, %f, %f -> %f\n", i, j, src1, src2, src3, result);
                uint64_t src1_int = mat_src1.get(i,j);
                uint64_t src2_int = mat_src2.get(i,j);
                uint64_t src3_int = mat_dst.get(i,j);
                result = (src1_int * src2_int) + src3_int;
            }

            mat_dst.set(i,j, result );

        }
    }
}


void mat_fma_manual_inacurate_check ( unsigned int row, unsigned int col, 
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

static void flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix &, matrix &, matrix & )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");
    srand(1);

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix mat_src1(row,col);
    matrix mat_src2(row,col);
    matrix mat_dst(row,col);
    matrix mat_dst_ref(row,col);

    for (int r = 0; r < row; r += 1) {
        for (int c = 0; c < col; c += 1) {
            mat_src1.set(r,c, rand()/1 );//r  );
            mat_src2.set(r,c, rand()/1 );//r+c);
            mat_dst. set(r,c, rand()/1 );//c  );
            mat_dst_ref.set(r,c, mat_dst.get(r,c));
        }
    }
    
    for (auto _ : state) {
        // for (int r = 0; r < row; r += 1) {
        //     for (int c = 0; c < col; c += 1) {
        //         mat_dst. set(r,c, mat_dst_ref.get(r,c) );
        //     }
        // }
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
BENCHMARK_CAPTURE(flat, fma_acurate, &mat_fma_inacurate_check)->BMarg;
BENCHMARK_CAPTURE(flat, fma_m_acurate, &mat_fma_manual_inacurate_check)->BMarg;

BENCHMARK_MAIN();