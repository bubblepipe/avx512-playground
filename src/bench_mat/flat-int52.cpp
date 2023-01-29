/**
 * This whole file has no purpose
 * delete me
 * 
 */

#include <utils/bench_utils.cpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cfenv>

// #define DATA_TYPE double
union int52_t
{
    uint64_t i;     
    double f; 
};  

class matrix {

public:

    std::vector<int52_t> m;
    unsigned int row;
    unsigned int col;

    matrix(unsigned int r, unsigned int c) {
        row = r;
        col = c;
        m.resize(r * c);
    }
  
    public:
        int52_t get(unsigned int x, unsigned int y) {
            return m[col * x + y];
        }
        void set(unsigned int x, unsigned int y, int52_t val) {
            m[col * x + y] = val;
        }
        int52_t& set(unsigned int x, unsigned int y) {
            return m[col * x + y];
        }
};

void mat_fma ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
    auto size = mat_src1.m.size();
    
    int52_t * src1_ptr = (int52_t *) mat_src1.m.data();
    int52_t * src2_ptr = (int52_t *) mat_src2.m.data();
    int52_t * dst_ptr  = (int52_t *) mat_dst.m.data();

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            int52_t result;

            double src1 = mat_src1.get(i,j).f;
            double src2 = mat_src2.get(i,j).f;
            double src3 = mat_dst.get(i,j).f;
            result.f = (src1 * src2) + src3;

            if (std::fetestexcept(FE_INEXACT)){
                printf("[%d][%d]: %f, %f, %f -> %f\n", i, j, src1, src2, src3, result.f);

                uint64_t src1_int = mat_src1.get(i,j).f;
                uint64_t src2_int = mat_src2.get(i,j).f;
                uint64_t src3_int = mat_dst.get(i,j).f;
                result.i = (src1_int * src2_int) + src3_int;
            } 

            mat_dst.set(i,j, result);

        }
    }
}

           
void mat_fma_manual ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
    auto size = mat_src1.m.size();

    int52_t * src1_ptr = (int52_t *) mat_src1.m.data();
    int52_t * src2_ptr = (int52_t *) mat_src2.m.data();
    int52_t * dst_ptr  = (int52_t *) mat_dst.m.data();

    for (uint32_t i = 0; i < size; i += 4 ){

        // simdpp::uint64<4> src1_ymm = simdpp::load(src1_ptr + i);
        // simdpp::uint64<4> src2_ymm = simdpp::load(src2_ptr + i);
        // simdpp::uint64<4> src3_ymm = simdpp::load(dst_ptr + i);
        // auto src1_ymm_float = simdpp::to_float64(src1_ymm);
        // auto src2_ymm_float = simdpp::to_float64(src2_ymm);
        // auto src3_ymm_float = simdpp::to_float64(src3_ymm);
        // auto dst_new_ymm_float = simdpp::fmadd(src1_ymm_float , src2_ymm_float, src3_ymm_float);
        // auto dst_new_ymm_uint = simdpp::to_uint64(dst_new_ymm_float);
        // simdpp::store(dst_ptr + i, dst_new_ymm_uint);                                         

        // store as float
        simdpp::float64<4> src1_ymm_float = simdpp::load(src1_ptr + i);
        simdpp::float64<4> src2_ymm_float = simdpp::load(src2_ptr + i);
        simdpp::float64<4> src3_ymm_float = simdpp::load(dst_ptr + i);
        auto dst_new_ymm_float = simdpp::fmadd(src1_ymm_float , src2_ymm_float , src3_ymm_float);
        /*
         TODO: Impl overflow checking here
        */
        simdpp::store(dst_ptr + i, dst_new_ymm_float);                                         
    }
}

static void bench_mat_flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix &, matrix &, matrix & )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");
    srand(1);
    
    std::feclearexcept (FE_ALL_EXCEPT);

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix mat_src1(row,col);
    matrix mat_src2(row,col);
    matrix mat_dst(row,col);
    matrix mat_dst_ref(row,col);

    for (int r = 0; r < row; r += 1) {
        for (int c = 0; c < col; c += 1) {
            mat_src1.set(r,c).f = r; //(double(rand())/double((RAND_MAX)));
            mat_src2.set(r,c).f = c; //(double(rand())/double((RAND_MAX)));
            mat_dst. set(r,c).f = r+c; //(double(rand())/double((RAND_MAX)));
            mat_dst_ref.set(r,c).i = mat_dst.get(r,c).i;
        }
    }

    for (auto _ : state) {
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_dst);
    }

        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                fprintf(somefile, "%ld, %ld, %ld -> %ld\n", 
                    mat_src1.get(i,j).i, mat_src2.get(i,j).i, 
                    mat_dst_ref.get(i,j).i, mat_dst.get(i,j).i);
                fprintf(somefile, "%f, %f, %f -> %f\n", 
                    mat_src1.get(i,j).f, mat_src2.get(i,j).f, 
                    mat_dst_ref.get(i,j).f, mat_dst.get(i,j).f);
            }
        }
    fclose(somefile);
}


#ifdef TEST
#define BMarg Apply(RowColSizeArgs)->Iterations(1)
#else
#define BMarg Apply(RowColSizeArgs)
#endif	
BENCHMARK_CAPTURE(bench_mat_flat, int52_fma_m, &mat_fma_manual)->BMarg;
BENCHMARK_CAPTURE(bench_mat_flat, int52_fma, &mat_fma)->BMarg;

BENCHMARK_MAIN();