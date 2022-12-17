/**
 * This benchmark setup uses:
 *    class matrix 
 * not:
 *    vector<vector<T>>
 */

#include <iostream>
#include <benchmark/benchmark.h>
#include <thread>
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


void xxxx (unsigned int row, unsigned int col, matrix mat_src1, matrix mat_src2, matrix mat_dst ) {
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            float src1 = mat_src1.get(i,j);
            float src2 = mat_src1.get(i,j);

            mat_dst.set(i,j,  src1 + src2) ;
        }
    }
}

// int main(){
//     unsigned int row = 64;
//     unsigned int col = 32;
//     matrix mat(row,col);

//     for (int i = 0; i < row; i += 1) {
//         for (int j = 0; j < col; j += 1) {
//             mat.set(i,j,float(rand()/3));
//         }
//     }

//     for (int i = 0; i < row; i += 1) {
//         for (int j = 0; j < col; j += 1) {
//             printf("%f " , mat.get(i,j));
//         }
//         printf("\n");
//     }
//     return 0;
// }

static void mat_flat_add(benchmark::State& state) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");

    unsigned int row = state.range(0);
    unsigned int col = 64;
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
        xxxx(row, col, mat_src1, mat_src2, mat_dst);
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
             fprintf(somefile, "%f + %f = %f\n", mat_src1.get(i,j), mat_src2.get(i,j), mat_dst.get(i,j));
        }
    }

    fclose(somefile);
}


// 16 * 2 ^ step
// BENCHMARK(mat_flat_add)->DenseRange(0,3,1);
// BENCHMARK(mat_flat_add)->DenseRange(16,128,16);

BENCHMARK_MAIN();