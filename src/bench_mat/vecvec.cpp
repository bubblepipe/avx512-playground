// #include <matrix-dynamic-size.h>
#include <utils/bench_utils.cpp>

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

void mat_fma_vecty ( int row,  int col, 
        std::vector<std::vector<float>> & mat_src1, 
        std::vector<std::vector<float>> & mat_src2,
        std::vector<std::vector<float>> & mat_src3,
        std::vector<std::vector<float>> & mat_dst ) {

    #define FloatZmmSize 16
    typedef float floatZmm __attribute__((ext_vector_type(FloatZmmSize), __aligned__));
    
    for (int i = 0; i < row; i += 1) {
        auto size = mat_src1[i].size();
        float * src1_ptr = (float *) mat_src1[i].data();
        float * src2_ptr = (float *) mat_src2[i].data();
        float * src3_ptr = (float *) mat_src3[i].data();
        float * dst_ptr = (float *) mat_dst[i].data();
        for (uint32_t j = 0; j < size; j += 16 ){
            floatZmm src1 = *(floatZmm* ) (src1_ptr + j);
            floatZmm src2 = *(floatZmm* ) (src2_ptr + j);
            floatZmm src3 = *(floatZmm* ) (src3_ptr + j);
            *(floatZmm *)(dst_ptr + j) = src1 * src2 + src3;
        }
    }

}
