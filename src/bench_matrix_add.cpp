#include <benchmark/benchmark.h>
#include <matrix-dynamic-size.h>
// #include <"src/matrix-dynamic-size.h">


void bench_matrix_add_vectorvector(benchmark::State &state) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");

    int size = 128;
    int row = 64;
    int col = 128;
    std::vector<std::vector<float>> mat_src1;
    std::vector<std::vector<float>> mat_src2;
    std::vector<std::vector<float>> mat_dst;
    mat_src1.resize(row, std::vector<float>(col, 0));
    mat_src2.resize(row, std::vector<float>(col, 0));
    mat_dst.resize(row, std::vector<float>(col, 0));
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            mat_dst[i][j] = rand();
            mat_src1[i][j] = rand();
            mat_src2[i][j] = rand();
        }
    }

    for (auto _ : state) {
        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                mat_dst[i][j] = mat_src1[i][j] + mat_src2[i][j];
            }
        }
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < size; j += 1) {
            fprintf(somefile, "%x",  mat_dst[i][j]);
        }
    }
}

BENCHMARK(bench_matrix_add_vectorvector);
BENCHMARK_MAIN();