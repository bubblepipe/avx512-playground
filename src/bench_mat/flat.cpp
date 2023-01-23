#include <utils/bench_utils.cpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>

// #define DATA_TYPE double

template <typename T>
class matrix {

public:

    std::vector<T> m;
    unsigned int row;
    unsigned int col;

    matrix(unsigned int r, unsigned int c) {
        row = r;
        col = c;
        m.resize(r * c);
    }
  
    public:
        T get(unsigned int x, unsigned int y) {
            return m[col * x + y];
        }
        void set(unsigned int x, unsigned int y, T val) {
            m[col * x + y] = val;
        }
        T& set(unsigned int x, unsigned int y) {
            return m[col * x + y];
        }
};

union int52_t
{
    uint64_t i;     
    double d; 
};             
 
/*
void mat_add ( unsigned int row, unsigned int col, 
    matrix<DATA_TYPE> & mat_src1, matrix<DATA_TYPE> & mat_src2, matrix<DATA_TYPE> & mat_dst ) {
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            float src1 = mat_src1.get(i,j);
            float src2 = mat_src1.get(i,j);
            mat_dst.set(i,j,  src1 + src2) ;
        }
    }
}

void mat_add_manual ( unsigned int row, unsigned int col, 
    matrix<DATA_TYPE> & mat_src1, matrix<DATA_TYPE> & mat_src2, matrix<DATA_TYPE> & mat_dst ) {
    auto size = mat_src1.m.size();
    float * src1_ptr = (float *) mat_src1.m.data();
    float * src2_ptr = (float *) mat_src2.m.data();
    float * dst_ptr = (float *) mat_dst.m.data();

    for (uint32_t i = 0; i < size; i += 8 ){
        simdpp::float32<8> src1_ymm = simdpp::load(src1_ptr + i);
        simdpp::float32<8> src2_ymm = simdpp::load(src2_ptr + i);
        auto dst_ymm = simdpp::add(src1_ymm, src2_ymm);
        simdpp::store(dst_ptr + i, dst_ymm);                                         
    }
}
*/

/*
void mat_fma ( unsigned int row, unsigned int col, 
    matrix<DATA_TYPE> & mat_src1, matrix<DATA_TYPE> & mat_src2, matrix<DATA_TYPE> & mat_dst ) {
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            DATA_TYPE src1 = mat_src1.get(i,j);
            DATA_TYPE src2 = mat_src2.get(i,j);
            DATA_TYPE src3 = mat_dst.get(i,j);
            mat_dst.set(i,j,  (src1 * src2) + src3);
        }
    }
}
*/


/*
Important: use dedicated function for double and float
rather than generic, to reduce runtime overhead?
*/
template <typename T>
void mat_fma_manual ( unsigned int row, unsigned int col, 
    matrix<T> & mat_src1, matrix<T> & mat_src2, matrix<T> & mat_dst ) {
    auto size = mat_src1.m.size();
    T * src1_ptr = (T *) mat_src1.m.data();
    T * src2_ptr = (T *) mat_src2.m.data();
    T * dst_ptr  = (T *) mat_dst.m.data();

    if constexpr (std::is_same_v<T, float>) {
        for (uint32_t i = 0; i < size; i += 8 ){
            simdpp::float32<8> src1_ymm = simdpp::load(src1_ptr + i);
            simdpp::float32<8> src2_ymm = simdpp::load(src2_ptr + i);
            simdpp::float32<8> src3_ymm = simdpp::load(dst_ptr + i);
            auto dst_new_ymm = simdpp::fmadd(src1_ymm, src2_ymm, src3_ymm);
            simdpp::store(dst_ptr + i, dst_new_ymm );                                         
        }
    } else if constexpr ( std::is_same_v<T, int64_t> || std::is_same_v<T, double> || std::is_same_v<T, int52_t>) {
        for (uint32_t i = 0; i < size; i += 4 ){
            simdpp::float64<4> src1_ymm = simdpp::load(src1_ptr + i);
            simdpp::float64<4> src2_ymm = simdpp::load(src2_ptr + i);
            simdpp::float64<4> src3_ymm = simdpp::load(dst_ptr + i);
            auto dst_new_ymm = simdpp::fmadd(src1_ymm, src2_ymm, src3_ymm);
            simdpp::store(dst_ptr + i, dst_new_ymm );                                         
        }
    } else if constexpr (std::is_same_v<T, int32_t>) {
        for (uint32_t i = 0; i < size; i += 8 ){
            simdpp::int32<8> src1_ymm = simdpp::load(src1_ptr + i);
            simdpp::int32<8> src2_ymm = simdpp::load(src2_ptr + i);
            simdpp::int32<8> src3_ymm = simdpp::load(dst_ptr + i);
            auto tmp_mul = simdpp::mul_lo(src1_ymm, src2_ymm);
            auto dst_new_ymm = simdpp::add(tmp_mul, src3_ymm);
            simdpp::store(dst_ptr + i, dst_new_ymm );                                         
        }
    }
}

template <typename T>
static void bench_mat_flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix<T> &, matrix<T> &, matrix<T> & )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");
    srand(1);

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix<T> mat_src1(row,col);
    matrix<T> mat_src2(row,col);
    matrix<T> mat_dst(row,col);
    matrix<T> mat_dst_ref(row,col);

    if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>) {
        for (int r = 0; r < row; r += 1) {
            for (int c = 0; c < col; c += 1) {
                mat_src1.set(r,c,(T(rand())/T((RAND_MAX))));
                mat_src2.set(r,c,(T(rand())/T((RAND_MAX))));
                mat_dst. set(r,c,(T(rand())/T((RAND_MAX))));
                mat_dst_ref.set(r,c, mat_dst.get(r,c));
            }
        }
    } else if constexpr (std::is_same_v<T, int32_t> || std::is_same_v<T, int64_t> ) {
        for (int r = 0; r < row; r += 1) {
            for (int c = 0; c < col; c += 1) {
                mat_src1.set(r,c, r );
                mat_src2.set(r,c, c );
                mat_dst. set(r,c, r+c );
                mat_dst_ref.set(r,c, mat_dst.get(r,c));
            }
        }
    } else if constexpr (std::is_same_v<T, int52_t> ) {
        // mat_src1.set(0,0).i = 1;
        // mat_src1.set(0,1).i = 2;
        // printf("0x%x\n",mat_src1.get(0,0).i);
        // printf("0x%f\n",mat_src1.get(0,0).d);
        // printf("0x%x\n",mat_src1.get(0,1).i);
        // printf("0x%f\n",mat_src1.get(0,1).d);

        // double tmp = mat_src1.get(0,0).d + mat_src1.get(0,1).d;
        // mat_src1.set(0,2).d = tmp;
        // printf("0x%x\n",mat_src1.get(0,2).i);
        // printf("0x%f\n",mat_src1.get(0,2).d);

        // exit(0);
        for (int r = 0; r < row; r += 1) {
            for (int c = 0; c < col; c += 1) {
                mat_src1.set(r,c).d =  (double(rand())/double((RAND_MAX)));
                mat_src2.set(r,c).d =  (double(rand())/double((RAND_MAX)));
                mat_dst. set(r,c).d =  (double(rand())/double((RAND_MAX)));
                mat_dst_ref.set(r,c).i = mat_dst.get(r,c).i;
            }
        }
    }
    

    for (auto _ : state) {
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_dst);
    }

    if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>) {
        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                fprintf(somefile, "%f, %f, %f -> %f\n", 
                    mat_src1.get(i,j), mat_src2.get(i,j), 
                    mat_dst_ref.get(i,j), mat_dst.get(i,j));
            }
        }
    } else if constexpr (std::is_same_v<T, int32_t> || std::is_same_v<T, int64_t>) {
        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                fprintf(somefile, "%d, %d, %d -> %d\n", 
                    mat_src1.get(i,j), mat_src2.get(i,j), 
                    mat_dst_ref.get(i,j), mat_dst.get(i,j));
            }
        }
    }
    else if constexpr (std::is_same_v<T, int52_t>) {
        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                fprintf(somefile, "%x, %x, %x -> %x\n", 
                    mat_src1.get(i,j).i, mat_src2.get(i,j).i, 
                    mat_dst_ref.get(i,j).i, mat_dst.get(i,j).i);
            }
        }
    }
    fclose(somefile);
}


#ifdef TEST
#define BMarg Apply(RowColSizeArgs)->Iterations(1)
#else
#define BMarg Apply(RowColSizeArgs)
#endif	
// BENCHMARK_CAPTURE(bench_mat_flat, add_auto, &mat_add)->BMarg;
// BENCHMARK_CAPTURE(bench_mat_flat, add_manual, &mat_add_manual)->BMarg;
// BENCHMARK_CAPTURE(bench_mat_flat, fma_auto, &mat_fma)->BMarg;
BENCHMARK_CAPTURE(bench_mat_flat, float_fma_m, &mat_fma_manual<float>)->BMarg;
BENCHMARK_CAPTURE(bench_mat_flat, double_fma_m, &mat_fma_manual<double>)->BMarg;
BENCHMARK_CAPTURE(bench_mat_flat, int52_fma_m, &mat_fma_manual<int52_t>)->BMarg;
BENCHMARK_CAPTURE(bench_mat_flat, int64_fma_m, &mat_fma_manual<int64_t>)->BMarg;
BENCHMARK_CAPTURE(bench_mat_flat, int32_fma_m, &mat_fma_manual<int32_t>)->BMarg;
// BENCHMARK_CAPTURE(bench_mat_flat, int64_fma_m, &mat_fma_manual<int64_t>)->BMarg;

BENCHMARK_MAIN();