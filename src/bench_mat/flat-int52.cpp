#include <utils/bench_utils.cpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>

uint64_t mask =  0x3ff0000000000000;
uint64_t undo_mask = ~mask;

// #define DATA_TYPE double
union int52_t
{
    uint64_t i;     
    double d; 
};  
class matrix {

public:

    std::vector<int52_t> m;
    unsigned int row;
    unsigned int col;

    matrix(unsigned int r, unsigned int c) {
        row = r;
        col = c;
        m.resize(r * c);
    }
  
    public:
        int52_t get(unsigned int x, unsigned int y) {
            return m[col * x + y];
        }
        void set(unsigned int x, unsigned int y, int52_t val) {
            m[col * x + y] = val;
        }
        int52_t& set(unsigned int x, unsigned int y) {
            return m[col * x + y];
        }
};

           
void mat_fma_manual ( unsigned int row, unsigned int col, 
    matrix & mat_src1, matrix & mat_src2, matrix & mat_dst ) {
    auto size = mat_src1.m.size();
    int52_t * src1_ptr = (int52_t *) mat_src1.m.data();
    int52_t * src2_ptr = (int52_t *) mat_src2.m.data();
    int52_t * dst_ptr  = (int52_t *) mat_dst.m.data();

    for (uint32_t i = 0; i < size; i += 4 ){

        simdpp::float64<4> src1_ymm = simdpp::load(src1_ptr + i);
        simdpp::float64<4> src2_ymm = simdpp::load(src2_ptr + i);
        simdpp::float64<4> src3_ymm = simdpp::load(dst_ptr + i);
        auto dst_new_ymm = simdpp::fmadd((src1_ymm | mask), (src2_ymm | mask), src3_ymm);
        auto dst_new_ymm2 = dst_new_ymm & undo_mask;
        simdpp::store(dst_ptr + i, dst_new_ymm2 );                                         
    }
}

static void bench_mat_flat(benchmark::State& state, 
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
            mat_src1.set(r,c).i = 3; // (r | mask) ;//(double(rand())/double((RAND_MAX)));
            mat_src2.set(r,c).i = 3; // (c | mask) ;//(double(rand())/double((RAND_MAX)));
            mat_dst. set(r,c).i = 4; // ((r+c) | mask) ;//(double(rand())/double((RAND_MAX)));
            mat_dst_ref.set(r,c).i = mat_dst.get(r,c).i;
        }
    }



    double d1 = mat_src1.get(0,0).d;
    double d2 = mat_src2.get(0,0).d;
    double d3 = mat_dst.get(0,0).d;
    uint64_t i1 = mat_src1.get(0,0).i;
    uint64_t i2 = mat_src2.get(0,0).i;
    uint64_t i3 = mat_dst.get(0,0).i;

        int52_t src1, src2, src3, tmp1;
        src1.i = (mat_src1.get(0,0).i  | mask);
        src2.i = (mat_src2.get(0,0).i  | mask);
        src3.i = (mat_dst.get(0,0).i );
        printf("1 float masked %f\n",src1.d);
        printf("1 float masked 0x%lx\n",src1.i);
        printf("2 float masked %f\n",src2.d);
        printf("2 float masked 0x%lx\n",src2.i);
        printf("3  0x%lx\n",src3.i);
        
        printf("mul\n");
        tmp1.d = src1.d * src2.d;
        printf("tmp1 float %f\n",tmp1.d);
        printf("tmp1 0x%lx\n",tmp1.i);
        
        // undo mask
        tmp1.i = tmp1.i & undo_mask;
        printf("undo mask\n");
        printf("tmp1 float %f\n",tmp1.d);
        printf("tmp1 0x%lx\n",tmp1.i);
        
        // add
        tmp1.d = tmp1.d + src3.d;
        printf("add\n");
        printf("tmp1 float %f\n",tmp1.d);
        printf("tmp1 0x%lx\n",tmp1.i);
        exit(0);


    for (auto _ : state) {
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_dst);
    }

        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                fprintf(somefile, "%lx, %lx, %lx -> %lx\n", 
                    mat_src1.get(i,j).i, mat_src2.get(i,j).i, 
                    mat_dst_ref.get(i,j).i, mat_dst.get(i,j).i);
                fprintf(somefile, "%f, %f, %f -> %f\n", 
                    mat_src1.get(i,j).d, mat_src2.get(i,j).d, 
                    mat_dst_ref.get(i,j).d, mat_dst.get(i,j).d);
            }
        }
    fclose(somefile);
}


#ifdef TEST
#define BMarg Apply(RowColSizeArgs)->Iterations(1)
#else
#define BMarg Apply(RowColSizeArgs)
#endif	
BENCHMARK_CAPTURE(bench_mat_flat, int52_fma_m, &mat_fma_manual)->BMarg;

BENCHMARK_MAIN();