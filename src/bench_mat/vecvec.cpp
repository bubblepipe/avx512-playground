// #include <matrix-dynamic-size.h>
#include <utils/bench_utils.cpp>
#include <immintrin.h>

void mat_add(int row, int col, 
        std::vector<std::vector<float>> & mat_src1, 
        std::vector<std::vector<float>> & mat_src2,
        std::vector<std::vector<float>> & mat_src3,
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
        std::vector<std::vector<float>> & mat_src3,
        std::vector<std::vector<float>> & mat_dst){
    for (int i = 0; i < row; i += 1) {
        auto size = mat_src1[i].size();
        float * src1_ptr = (float *) mat_src1[i].data();
        float * src2_ptr = (float *) mat_src2[i].data();
        float * dst_ptr = (float *) mat_dst[i].data();
        for (uint32_t j = 0; j < size; j += 8 ){
            simdpp::float32<8> src1_ymm = simdpp::load(src1_ptr + j);
            simdpp::float32<8> src2_ymm = simdpp::load(src2_ptr + j);
            auto dst_ymm = simdpp::add(src1_ymm, src2_ymm);
            simdpp::store(dst_ptr + j, dst_ymm);                                         
        }
    }
}

void mat_fma(int row, int col, 
        std::vector<std::vector<float>> & mat_src1, 
        std::vector<std::vector<float>> & mat_src2,
        std::vector<std::vector<float>> & mat_src3,
        std::vector<std::vector<float>> & mat_dst){
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            auto tmp = mat_src1[i][j] * mat_src2[i][j] + mat_src3[i][j] ;
            mat_dst[i][j] = tmp;
        }
    }
}

void mat_fma_manual(int row, int col, 
        std::vector<std::vector<float>> & mat_src1, 
        std::vector<std::vector<float>> & mat_src2,
        std::vector<std::vector<float>> & mat_src3,
        std::vector<std::vector<float>> & mat_dst){
    for (int i = 0; i < row; i += 1) {
        auto size = mat_src1[i].size();
        float * src1_ptr = (float *) mat_src1[i].data();
        float * src2_ptr = (float *) mat_src2[i].data();
        float * src3_ptr = (float *) mat_src3[i].data();
        float * dst_ptr = (float *) mat_dst[i].data();
        for (uint32_t j = 0; j < size; j += 8 ){
            simdpp::float32<8> src1_ymm = simdpp::load(src1_ptr + j);
            simdpp::float32<8> src2_ymm = simdpp::load(src2_ptr + j);
            simdpp::float32<8> src3_ymm = simdpp::load(src3_ptr + j);
            auto dst_new_ymm = simdpp::fmadd(src1_ymm, src2_ymm, src3_ymm);
            simdpp::store(dst_ptr + j, dst_new_ymm);                                         
        }
    }
}

void mat_fma_intrinsc(int row, int col, 
        std::vector<std::vector<float>> & mat_src1, 
        std::vector<std::vector<float>> & mat_src2,
        std::vector<std::vector<float>> & mat_src3,
        std::vector<std::vector<float>> & mat_dst){
    for (int i = 0; i < row; i += 1) {
        auto size = mat_src1[i].size();
        float * src1_ptr = (float *) mat_src1[i].data();
        float * src2_ptr = (float *) mat_src2[i].data();
        float * src3_ptr = (float *) mat_src3[i].data();
        float * dst_ptr = (float *) mat_dst[i].data();
        // #ifdef AVX512_ENABLED
        //     for (int i = 0; i < size; i += 16 ){
        //         __m512 src1 = _mm512_loadu_ps ((const float *) (src1_ptr + i));
        //         __m512 src2 = _mm512_loadu_ps ((const float *) (src2_ptr + i));
        //         __m512 src3 = _mm512_loadu_ps ((const float *) (src3_ptr + i));
        //         __m512 result = _mm512_fmadd_ps(src1, src2, src3);
        //         __m512 rx = _mm512_mul_ps(result, src3);
        //         _mm512_storeu_ps((float *) (dst_ptr + i), rx);
        //     }
        // #else
            for (int i = 0; i < size; i += 8 ){
                __m256 src1 = _mm256_loadu_ps ((const float *) (src1_ptr + i));
                __m256 src2 = _mm256_loadu_ps ((const float *) (src2_ptr + i));
                __m256 src3 = _mm256_loadu_ps ((const float *) (src3_ptr + i));
                __m256 result = _mm256_fmadd_ps(src1, src2, src3);
                _mm256_storeu_ps((float *) (dst_ptr + i), result);
            }
        // #endif
    }
}
