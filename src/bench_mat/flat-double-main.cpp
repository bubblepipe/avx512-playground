/*
Benchmark for double, including: 
 - fma (auto)
 - fma (manual)
 - fma (checked)
 - 2m1a
*/

#include <bench_mat/flat-double.cpp>
#include <csignal>

void signal_handler(int signal)
{
    printf("signal handler\n");
    exit(0);
}
 

static void flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix<double> &, matrix<double> &, matrix<double> &, matrix<double> & )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");
    srand(1);
    std::signal(SIGFPE, signal_handler);

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix<double> mat_src1(row,col);
    matrix<double> mat_src2(row,col);
    matrix<double> mat_src3(row,col);
    matrix<double> mat_dst(row,col);

    for (int r = 0; r < row; r += 1) {
        for (int c = 0; c < col; c += 1) {
            mat_src1.set(r,c, r + 1 ); // rand()/1 );
            mat_src2.set(r,c, c + 1 ); // rand()/1 );
            mat_src3.set(r,c, c + 1 ); // rand()/1 );
            mat_dst. set(r,c, c + 1 ); // rand()/1 );
        }
    }

    for (auto _ : state) {
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_src3, mat_dst);
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            fprintf(somefile, "%f, %f, %f -> %f\n", 
                mat_src1.get(i,j), mat_src2.get(i,j), 
                mat_src3.get(i,j), mat_dst.get(i,j));
        }
    }

    fclose(somefile);
}

BENCHMARK_CAPTURE(flat, fma, &mat_fma)->BMarg;
BENCHMARK_CAPTURE(flat, fma_m, &mat_fma_manual)->BMarg;
BENCHMARK_CAPTURE(flat, fma_i, &mat_fma_intrinsic)->BMarg;
BENCHMARK_CAPTURE(flat, fma_c, &mat_fma_check)->BMarg;
BENCHMARK_CAPTURE(flat, fma_ic, &mat_fma_intrinsic_check)->BMarg;

// BENCHMARK_CAPTURE(flat, 2m1a_m, &mat_2m1a_manual)->BMarg;
// BENCHMARK_CAPTURE(flat, 2m1a_m_check, &mat_2m1a_manual_check_REALISTIC)->BMarg;
// BENCHMARK_CAPTURE(flat, 2m1a_m_local_check, &mat_2m1a_manual_local_check_REALISTIC)->BMarg;

BENCHMARK_CAPTURE(flat, fma_i_rdtscp, &mat_fma_intrinsic_rdtscp)->BMarg;

BENCHMARK_MAIN();
