// #include <utils/bench_utils.cpp>
#include <bench_mat/flat-int16.cpp>

static void flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix<int16_t> &, matrix<int16_t> &, matrix<int16_t> &, matrix<int16_t> & )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");
    srand(1);

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix<int16_t> mat_src1(row,col);
    matrix<int16_t> mat_src2(row,col);
    matrix<int16_t> mat_src3(row,col);
    matrix<int16_t> mat_dst(row,col);

    for (int r = 0; r < row; r += 1) {
        for (int c = 0; c < col; c += 1) {
            // mat_src1.set(r,c, 0x7ffffffffffffff0); // rand() );
            mat_src1.set(r,c, r); // rand() );
            mat_src2.set(r,c, r); // rand() );
            mat_src3.set(r,c, r); // rand() );
            mat_dst. set(r,c, r); // rand() );
        }
    }
    
    for (auto _ : state) {

        // actual work
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_src3, mat_dst);
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            fprintf(somefile, "%hd, %hd, %hd -> %hd\n", 
                mat_src1.get(i,j), mat_src2.get(i,j), 
                mat_src3.get(i,j), mat_dst.get(i,j));
        }
    }

    fclose(somefile);
}

#ifdef AVX512_ENABLED

BENCHMARK_CAPTURE(flat, fma_i, &mat_fma_intrinsic)->BMarg;
BENCHMARK_CAPTURE(flat, fma_ic, &mat_fma_intrinsic_checked)->BMarg;

#endif

BENCHMARK_MAIN();