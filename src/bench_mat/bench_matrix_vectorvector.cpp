// #include <matrix-dynamic-size.h>
#include <utils/bench_utils.cpp>
#include <simdpp/simd.h>

void bench_matrix_add_malloc(benchmark::State &state) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");

    int size = 128;
    int row = 128;
    int col = 128;

    float * * mat_src1 = (float * *) malloc(row * sizeof (float *));
    float * * mat_src2 = (float * *) malloc(row * sizeof (float *));
    float * * mat_dst = (float * *) malloc(row * sizeof (float *));
    for (int i = 0; i < row; i += 1) {
        mat_src1[i] = (float *) malloc(col * sizeof (float));
        mat_src2[i] = (float *) malloc(col * sizeof (float));
        mat_dst[i] = (float *) malloc(col * sizeof (float));
    }
    
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

    free(mat_src1);
    free(mat_src2);
    free(mat_dst);
}

void mat_add(int row, int col, 
        std::vector<std::vector<float>> & mat_src1, 
        std::vector<std::vector<float>> & mat_src2,
        std::vector<std::vector<float>> & mat_dst){
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            mat_dst[i][j] = mat_src1[i][j] + mat_src2[i][j];
        }
    }
}

void mat_add_manual(int row, int col, 
        std::vector<std::vector<float>> & mat_src1, 
        std::vector<std::vector<float>> & mat_src2,
        std::vector<std::vector<float>> & mat_dst){


    for (int i = 0; i < row; i += 1) {
        auto size = mat_src1[i].size();
        float * src1_ptr = (float *) mat_src1[i].data();
        float * src2_ptr = (float *) mat_src2[i].data();
        float * dst_ptr = (float *) mat_dst[i].data();
        for (uint32_t i = 0; i < size; i += 8 ){
            simdpp::float32<8> src1_ymm = simdpp::load(src1_ptr + i);
            simdpp::float32<8> src2_ymm = simdpp::load(src2_ptr + i);
            auto dst_ymm = simdpp::add(src1_ymm, src2_ymm);
            simdpp::store(dst_ptr + i, dst_ymm);                                         
        }
    }
}

void mat_fma(int row, int col, 
        std::vector<std::vector<float>> & mat_src1, 
        std::vector<std::vector<float>> & mat_src2,
        std::vector<std::vector<float>> & mat_dst){
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            mat_dst[i][j] += mat_src1[i][j] * mat_src2[i][j];
        }
    }
}

void mat_fma_manual(int row, int col, 
        std::vector<std::vector<float>> & mat_src1, 
        std::vector<std::vector<float>> & mat_src2,
        std::vector<std::vector<float>> & mat_dst){
    for (int i = 0; i < row; i += 1) {
        auto size = mat_src1[i].size();
        float * src1_ptr = (float *) mat_src1[i].data();
        float * src2_ptr = (float *) mat_src2[i].data();
        float * dst_ptr = (float *) mat_dst[i].data();
        for (uint32_t i = 0; i < size; i += 8 ){
            simdpp::float32<8> src1_ymm = simdpp::load(src1_ptr + i);
            simdpp::float32<8> src2_ymm = simdpp::load(src2_ptr + i);
            simdpp::float32<8> dst_ymm = simdpp::load(src2_ptr + i);
            auto dst_new_ymm = simdpp::fmadd(src1_ymm, src2_ymm, dst_ymm);
            simdpp::store(dst_ptr + i, dst_new_ymm);                                         
        }
    }
}

void bench_matrix_vectorvector(benchmark::State &state,
        void (*func_ptr)(int, int, std::vector<std::vector<float>> &, std::vector<std::vector<float>> &, std::vector<std::vector<float>> & )) {
    FILE* somefile = fopen("/dev/shm/1145141919810", "w");

    int row = state.range(0);
    int col = state.range(1);
    std::vector<std::vector<float>> mat_src1;
    std::vector<std::vector<float>> mat_src2;
    std::vector<std::vector<float>> mat_dst;
    mat_src1.resize(row, std::vector<float>(col, 0));
    mat_src2.resize(row, std::vector<float>(col, 0));
    mat_dst.resize(row, std::vector<float>(col, 0));
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            mat_dst[i][j] = (float(rand())/float((RAND_MAX)));
            mat_src1[i][j] = (float(rand())/float((RAND_MAX)));
            mat_src2[i][j] = (float(rand())/float((RAND_MAX)));
        }
    }

    for (auto _ : state) {
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_dst);
    }

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            fprintf(somefile, "%f + %f = %f\n", mat_src1[i][j], mat_src2[i][j], mat_dst[i][j]);
        }
    }
    fclose(somefile);
}

#ifdef ADD
BENCHMARK_CAPTURE(bench_matrix_vectorvector, add, &mat_add)->Apply(RowColSizeArgs);
#endif

#ifdef ADDM
BENCHMARK_CAPTURE(bench_matrix_vectorvector, add_manual, &mat_add_manual)->Apply(RowColSizeArgs);
#endif

#ifdef FMA
BENCHMARK_CAPTURE(bench_matrix_vectorvector, fma, &mat_fma)->Apply(RowColSizeArgs);
#endif

#ifdef FMAM
BENCHMARK_CAPTURE(bench_matrix_vectorvector, fma_manual, &mat_fma_manual)->Apply(RowColSizeArgs);
#endif

BENCHMARK_MAIN();