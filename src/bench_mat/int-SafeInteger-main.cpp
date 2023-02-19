#include <bench_mat/int-SafeInteger-512.cpp>
#include <cstdint>


static void flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix<int32_t> &, matrix<int32_t> &, matrix<int32_t> & )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");
    srand(1);

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix<int32_t> mat_src1(row,col);
    matrix<int32_t> mat_src2(row,col);
    matrix<int32_t> mat_dst(row,col);
    matrix<int32_t> mat_dst_ref(row,col);

    for (int r = 0; r < row; r += 1) {
        for (int c = 0; c < col; c += 1) {
            // mat_src1.set(r,c, 0x7ffffffffffffff0); // rand() );
            mat_src1.set(r,c, r); // rand() );
            mat_src2.set(r,c, c); // rand() );
            mat_dst. set(r,c, r); // rand() );
            mat_dst_ref.set(r,c, mat_dst.get(r,c));
        }
    }
    
    for (auto _ : state) {
        for (int r = 0; r < row; r += 1) {
            for (int c = 0; c < col; c += 1) {
                mat_dst. set(r,c, mat_dst_ref.get(r,c) );
            }
        }
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_dst);
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            fprintf(somefile, "%d, %d, %d -> %d\n", 
                mat_src1.get(i,j), mat_src2.get(i,j), 
                mat_dst_ref.get(i,j), mat_dst.get(i,j));
        }
    }

    fclose(somefile);
}

BENCHMARK_CAPTURE(flat, add_m, &mat_add_manual)->BMarg; 