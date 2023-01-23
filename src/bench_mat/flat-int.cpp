// #include <utils/bench_utils.cpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <bench_vec/bench_vector_int.hpp>

class matrix {

public:

    std::vector<int32_t> m;
    unsigned int row;
    unsigned int col;

    matrix(unsigned int r, unsigned int c) {
        row = r;
        col = c;
        m.resize(r * c);
    }
  
    public:
        int32_t get(unsigned int x, unsigned int y) {
            return m[col * x + y];
        }
        void set(unsigned int x, unsigned int y, int32_t val) {
            m[col * x + y] = val;
        }
};

void mat_fma ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            int32_t src1 = mat_src1.get(i,j);
            int32_t src2 = mat_src2.get(i,j);
            int32_t src3 = mat_dst.get(i,j);
            mat_dst.set(i,j,  (src1 * src2) + src3);
        }
    }
}
void mat_add ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {

    auto size = mat_src1.m.size();
    int32_t * src1_ptr = (int32_t *) mat_src1.m.data();
    int32_t * src2_ptr = (int32_t *) mat_src2.m.data();
    int32_t * dst_ptr  = (int32_t *) mat_dst.m.data();
    vec_add_莎莎(size, src1_ptr, src2_ptr, dst_ptr);

    // for (int i = 0; i < row; i += 1) {
    //     for (int j = 0; j < col; j += 1) {
    //         int32_t src1 = mat_src1.get(i,j);
    //         int32_t src2 = mat_src2.get(i,j);
    //         mat_dst.set(i,j,  src1 + src2);
    //     }
    // }
}
void mat_add_manual ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
    
    auto size = mat_src1.m.size();
    
    if (size % 8 != 0) {
        throw std::runtime_error(std::string("size not div by 8"));
    }

    int32_t * src1_ptr = (int32_t *) mat_src1.m.data();
    int32_t * src2_ptr = (int32_t *) mat_src2.m.data();
    int32_t * dst_ptr  = (int32_t *) mat_dst.m.data();

    vec_add_manual(size, src1_ptr, src2_ptr, dst_ptr);
    
    // for (int32_t i = 0; i < size; i += 8 ){
        // simdpp::int32<8> src1_ymm = simdpp::load(src1_ptr + i);
        // simdpp::int32<8> src2_ymm = simdpp::load(src2_ptr + i);
        // auto dst_new_ymm = simdpp::add(src1_ymm, src2_ymm);
        // simdpp::store(dst_ptr + i, dst_new_ymm );                                         
    // }
}


void mat_fma_manual ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
    auto size = mat_src1.m.size();
    int32_t * src1_ptr = (int32_t *) mat_src1.m.data();
    int32_t * src2_ptr = (int32_t *) mat_src2.m.data();
    int32_t * dst_ptr  = (int32_t *) mat_dst.m.data();

    for (int32_t i = 0; i < size; i += 8 ){
        simdpp::int32<8> src1_ymm = simdpp::load(src1_ptr + i);
        simdpp::int32<8> src2_ymm = simdpp::load(src2_ptr + i);
        simdpp::int32<8> src3_ymm = simdpp::load(dst_ptr + i);
        
        // auto dst_new_ymm = simdpp::add(src1_ymm, src2_ymm);

        auto tmp = simdpp::mul_lo(src1_ymm, src2_ymm);
        auto dst_new_ymm = simdpp::add(tmp, src3_ymm);

        simdpp::store(dst_ptr + i, dst_new_ymm );                                         

    }
}

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
            mat_src1.set(r,c,  rand() );
            mat_src2.set(r,c,  rand() );
            mat_dst. set(r,c,  rand() );
            mat_dst_ref.set(r,c, mat_dst.get(r,c));
        }
    }
    
    for (auto _ : state) {
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


#ifdef TEST
#define BMarg Apply(RowColSizeArgs)->Iterations(1)
#else
#define BMarg Apply(RowColSizeArgs)
#endif	
BENCHMARK_CAPTURE(flat, add, &mat_add)->BMarg;
BENCHMARK_CAPTURE(flat, add_m, &mat_add_manual)->BMarg;
BENCHMARK_CAPTURE(flat, fma_m, &mat_fma_manual)->BMarg;
BENCHMARK_CAPTURE(flat, fma, &mat_fma)->BMarg;

BENCHMARK_MAIN();