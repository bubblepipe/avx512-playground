#include <bench_mat/int16.cpp>
#include <cstdint>


static void flat(benchmark::State& state, 
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
            fprintf(somefile, "%ld, %ld, %ld -> %ld\n", 
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
BENCHMARK_CAPTURE(flat, add_m, &mat_add_manual)->BMarg;

