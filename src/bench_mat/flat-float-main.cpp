#include <bench_mat/flat-float.cpp>

static void flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix<float> &, matrix<float> &, matrix<float> & )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");
    srand(1);

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix<float> mat_src1(row,col);
    matrix<float> mat_src2(row,col);
    matrix<float> mat_dst(row,col);
    matrix<float> mat_dst_ref(row,col);

    for (int r = 0; r < row; r += 1) {
        for (int c = 0; c < col; c += 1) {
            mat_src1.set(r,c, rand() );
            mat_src2.set(r,c, rand() );
            mat_dst. set(r,c, rand() );
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


BENCHMARK_CAPTURE(flat, fma, &mat_fma)->BMarg;
BENCHMARK_CAPTURE(flat, fma_m, &mat_fma_manual)->BMarg;

BENCHMARK_MAIN();