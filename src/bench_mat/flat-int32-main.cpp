#include <bench_mat/flat-int32.cpp>

static void flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix<int32_t> &, matrix<int32_t> &, matrix<int32_t> &, matrix<int32_t> & )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");
    srand(1);

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix<int32_t> mat_src1(row,col);
    matrix<int32_t> mat_src2(row,col);
    matrix<int32_t> mat_src3(row,col);
    matrix<int32_t> mat_dst(row,col);

    for (int r = 0; r < row; r += 1) {
        for (int c = 0; c < col; c += 1) {
            mat_src1.set(r,c, c+1 );
            mat_src2.set(r,c, c+1 );
            mat_src3.set(r,c, c+1 );
            mat_dst. set(r,c, 2 );
        }
    }
    
    for (auto _ : state) {
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_src3, mat_dst);
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            fprintf(somefile, "%d, %d, %d -> %d\n", 
                mat_src1.get(i,j), mat_src2.get(i,j), 
                mat_src3.get(i,j), mat_dst.get(i,j));
        }
    }

    fclose(somefile);
}


BENCHMARK_CAPTURE(flat, add, &mat_add)->BMarg;
BENCHMARK_CAPTURE(flat, fma, &mat_fma)->BMarg;

#ifndef SCALAR_ONLY
BENCHMARK_CAPTURE(flat, add_m, &mat_add_manual)->BMarg;
BENCHMARK_CAPTURE(flat, fma_i, &mat_fma_intrinsic)->BMarg;
BENCHMARK_CAPTURE(flat, fma_ic, &mat_fma_intrinsic_checked)->BMarg;
BENCHMARK_CAPTURE(flat, fma_m_hw, &mat_fma_manual_half_width)->BMarg;
BENCHMARK_CAPTURE(flat, fma_s_check, &mat_fma_scalar_inacurate_check)->BMarg;
#endif

BENCHMARK_MAIN();