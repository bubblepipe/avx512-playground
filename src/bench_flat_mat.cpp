#include "bench_header.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

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


void mat_add (unsigned int row, unsigned int col, matrix mat_src1, matrix mat_src2, matrix mat_dst ) {
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            float src1 = mat_src1.get(i,j);
            float src2 = mat_src1.get(i,j);

            mat_dst.set(i,j,  src1 + src2) ;
        }
    }
}
void mat_fma (unsigned int row, unsigned int col, matrix mat_src1, matrix mat_src2, matrix mat_dst ) {
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            float src1 = mat_src1.get(i,j);
            float src2 = mat_src1.get(i,j);
            mat_dst.set(i,j,  src1 + src2) ;
        }
    }
}
static void bench_matrix_flatvector(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix, matrix, matrix )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix mat_src1(row,col);
    matrix mat_src2(row,col);
    matrix mat_dst(row,col);

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            mat_src1.set(i,j,(float(rand())/float((RAND_MAX))));
            mat_src2.set(i,j,(float(rand())/float((RAND_MAX))));
            mat_dst. set(i,j,(float(rand())/float((RAND_MAX))));
        }
    }

    for (auto _ : state) {
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_dst);
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
             fprintf(somefile, "%f + %f = %f\n", mat_src1.get(i,j), mat_src2.get(i,j), mat_dst.get(i,j));
        }
    }

    fclose(somefile);
}

BENCHMARK_CAPTURE(bench_matrix_flatvector, add, &mat_add)->Apply(RowColSizeArgs);
// BENCHMARK_CAPTURE(bench_matrix_flatvector, fma, &mat_fma)->Apply(RowColSizeArgs);

BENCHMARK_MAIN();