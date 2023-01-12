#include <simdpp/simd.h>
// #include "/usr/local/include/libsimdpp-2.1/simdpp/simd.h"
// #include "/usr/local/include/libsimdpp-2.1/simdpp/simd.h"
#include <iostream>
#include <simdpp/dispatch/get_arch_gcc_builtin_cpu_supports.h>
#define SIMDPP_USER_ARCH_INFO ::simdpp::get_arch_gcc_builtin_cpu_supports()

#define SIMDPP_ARCH_X86_AVX2

namespace SIMDPP_ARCH_NAMESPACE {
 
void x()
{
    std::cout << static_cast<unsigned>(simdpp::this_compile_arch()) << '\n';
    
    simdpp::float32<8> vec1 (simdpp::make_float(114,2,3,4,114,2,3,4));
    simdpp::float32<8> vec2 (simdpp::make_float(514,2,3,4,514,2,3,4));
    for (int i = 0; i < 10000; i += 1)
        vec2 = simdpp::add(vec1,vec2);
    printf("%x\n", vec2.size_tag);
    printf("%x\n", vec2.length_bytes);
    printf("%f\n", simdpp::extract<0>(vec2));
    printf("%f\n", simdpp::extract<1>(vec2));
    printf("%f\n", simdpp::extract<2>(vec2));
    printf("%f\n", simdpp::extract<3>(vec2));
}
 
} // namespace SIMDPP_ARCH_NAMESPACE
 
SIMDPP_MAKE_DISPATCHER((void)(x)());

float * floatmalloctest() {
    int size = 16;
    int i = 8;
    float * src1_ptr = (float *) malloc(size * sizeof (float));
    float * src2_ptr = (float *) malloc(size * sizeof (float));
    float * dst_ptr =  (float *) malloc(size * sizeof (float));
    for (uint32_t i = 0; i < size; i += 8 ){
      src1_ptr[i] = (float(rand())/float((RAND_MAX)));
      src2_ptr[i] = (float(rand())/float((RAND_MAX)));
      dst_ptr[i] = 0;
    }
    simdpp::float32<8> src1_ymm = simdpp::load(src1_ptr + i);
    simdpp::float32<8> src2_ymm = simdpp::load(src2_ptr + i);
    auto dst_ymm = simdpp::add(src1_ymm, src2_ymm);
    simdpp::store(dst_ptr + i, dst_ymm);
    return dst_ptr;
}
SIMDPP_MAKE_DISPATCHER((void)(floatmalloctest)());

int main()
{

    // arch_avx2::x();

    auto dst_ptr = floatmalloctest();

    for (uint32_t i = 0; i < 16; i += 1 ){
        printf("%f\n",  dst_ptr[i]);
    }
}