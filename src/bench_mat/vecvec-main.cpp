#include <bench_mat/vecvec.cpp>

void bench_mat_vecvec(benchmark::State &state,
        void (*func_ptr)( int, int, 
            std::vector<std::vector<float>> &, 
            std::vector<std::vector<float>> &, 
            std::vector<std::vector<float>> & 
        )
    ) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");
    srand(1);

    int row = state.range(0);
    int col = state.range(1);
    std::vector<std::vector<float>> mat_src1;
    std::vector<std::vector<float>> mat_src2;
    std::vector<std::vector<float>> mat_dst;
    std::vector<std::vector<float>> mat_dst_ref;
    mat_src1.resize(row, std::vector<float>(col, 0));
    mat_src2.resize(row, std::vector<float>(col, 0));
    mat_dst.resize(row, std::vector<float>(col, 0));
    mat_dst_ref.resize(row, std::vector<float>(col, 0));

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            mat_src1[i][j] = (float(rand())/float((RAND_MAX)));
            mat_src2[i][j] = (float(rand())/float((RAND_MAX)));
            mat_dst[i][j] = (float(rand())/float((RAND_MAX)));
            mat_dst_ref[i][j] = mat_dst[i][j];
        }
    }

    for (auto _ : state) {
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_dst);
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            fprintf(somefile, "%f, %f, %f -> %f \n", 
                mat_src1[i][j], mat_src2[i][j], 
                mat_dst_ref[i][j], mat_dst[i][j]);
        }
    }

    fclose(somefile);
}

BENCHMARK_CAPTURE(bench_mat_vecvec, add, &mat_add)
    ->BMarg;
BENCHMARK_CAPTURE(bench_mat_vecvec, add_manual, &mat_add_manual)
    ->BMarg;
BENCHMARK_CAPTURE(bench_mat_vecvec, fma, &mat_fma)
    ->BMarg;
BENCHMARK_CAPTURE(bench_mat_vecvec, fma_manual, &mat_fma_manual)
    ->BMarg;

BENCHMARK_MAIN();