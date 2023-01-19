#include <utils/bench_utils.cpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <simdpp/simd.h>

class matrix {

public:

    std::vector<float> m;
    unsigned int row;
    unsigned int col;

    matrix(unsigned int r, unsigned int c) {
        row = r;
        col = c;
        m.resize(r * c);
    }
  
    public:
        float get(unsigned int x, unsigned int y) {
            return m[col * x + y];
        }
        void set(unsigned int x, unsigned int y, float val) {
            m[col * x + y] = val;
        }
};


void mat_add ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            float src1 = mat_src1.get(i,j);
            float src2 = mat_src1.get(i,j);
            mat_dst.set(i,j,  src1 + src2) ;
        }
    }
}

void mat_add_manual ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
    auto size = mat_src1.m.size();
    float * src1_ptr = (float *) mat_src1.m.data();
    float * src2_ptr = (float *) mat_src2.m.data();
    float * dst_ptr = (float *) mat_dst.m.data();

    for (uint32_t i = 0; i < size; i += 8 ){
        simdpp::float32<8> src1_ymm = simdpp::load(src1_ptr + i);
        simdpp::float32<8> src2_ymm = simdpp::load(src2_ptr + i);
        auto dst_ymm = simdpp::add(src1_ymm, src2_ymm);
        simdpp::store(dst_ptr + i, dst_ymm);                                         
    }
}

void mat_fma_manual ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
    auto size = mat_src1.m.size();
    float * src1_ptr = (float *) mat_src1.m.data();
    float * src2_ptr = (float *) mat_src2.m.data();
    float * dst_ptr = (float *) mat_dst.m.data();

    for (uint32_t i = 0; i < size; i += 8 ){
        simdpp::float32<8> src1_ymm = simdpp::load(src1_ptr + i);
        simdpp::float32<8> src2_ymm = simdpp::load(src2_ptr + i);
        simdpp::float32<8> src3_ymm = simdpp::load(dst_ptr + i);
        auto dst_new_ymm = simdpp::fmadd(src1_ymm, src2_ymm, src3_ymm);
        simdpp::store(dst_ptr + i, dst_new_ymm );                                         
    }
}

void mat_fma ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            float src1 = mat_src1.get(i,j);
            float src2 = mat_src2.get(i,j);
            float src3 = mat_dst.get(i,j);
            mat_dst.set(i,j,  (src1 * src2) + src3);
        }
    }
}

static void bench_mat_flat(benchmark::State& state, 
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
            mat_src1.set(r,c,(float(rand())/float((RAND_MAX))));
            mat_src2.set(r,c,(float(rand())/float((RAND_MAX))));
            mat_dst. set(r,c,(float(rand())/float((RAND_MAX))));
            mat_dst_ref.set(r,c, mat_dst.get(r,c));
        }
    }

    for (auto _ : state) {
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

static void bench_mat_flat_other_sequence(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix, matrix, matrix )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix mat_src1(row,col);
    matrix mat_src2(row,col);
    matrix mat_dst(row,col);
    matrix mat_dst_ref(row,col);

    for (int c = 0; c < col; c += 1) {
        for (int r = 0; r < row; r += 1) {
            mat_src1.set(r,c,(float(rand())/float((RAND_MAX))));
            mat_src2.set(r,c,(float(rand())/float((RAND_MAX))));
            mat_dst. set(r,c,(float(rand())/float((RAND_MAX))));
            mat_dst_ref.set(r,c, mat_dst.get(r,c));
        }
    }


    for (auto _ : state) {
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
BENCHMARK_CAPTURE(bench_mat_flat, add_auto, &mat_add)->BMarg;
BENCHMARK_CAPTURE(bench_mat_flat, add_manual, &mat_add_manual)->BMarg;
BENCHMARK_CAPTURE(bench_mat_flat, fma_auto, &mat_fma)->BMarg;
BENCHMARK_CAPTURE(bench_mat_flat, fma_manual, &mat_fma_manual)->BMarg;

BENCHMARK_MAIN();