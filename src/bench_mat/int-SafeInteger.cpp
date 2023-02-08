#include <utils/bench_utils.cpp>
#include <cstdint>
#include <immintrin.h>
#include <stdexcept>
#include <vector>
#include <utils/matrix.cpp>

// from 
// mlir/include/mlir/Analysis/Presburger/SafeInteger.h

typedef int32_t Vector32x16 __attribute__((ext_vector_type(8)));

inline __mmask32 equalMask(Vector32x16 x, Vector32x16 y) {
    return _mm256_cmp_epi16_mask(x, y, _MM_CMPINT_EQ);
}

inline void throwOverflowIf(bool cond) {
    if (cond)
        throw std::overflow_error("Overflow!");
}

template <bool isChecked>
inline Vector32x16 add(Vector32x16 x, Vector32x16 y) {
    Vector32x16 res = x + y;
    if constexpr (isChecked) {
        Vector32x16 z = _mm256_adds_epi16(x, y);
        bool overflow = ~equalMask(z, res);
        throwOverflowIf(overflow);
    }
    return res;
}

// If the 16th bit in the lower bits of the product is F then the result is
// negative and the high bits must all be F if no overflow occurred. Similarly,
// if the 16th in the low bits has value 0 then the result is non-negative and
// the high bits must all be 0 if no overflow occurred.
template <bool isChecked>
inline Vector32x16 mul(Vector32x16 x, Vector32x16 y) {
    Vector32x16 lo = _mm256_mullo_epi16(x, y);
    if constexpr (isChecked) {
        Vector32x16 hi = _mm256_mulhi_epi16(x, y);
        throwOverflowIf(~equalMask(lo >> 15, hi));
    }
    return lo;
}


void mat_add_manual(unsigned int row, unsigned int col,
                    matrix<int32_t> &mat_src1, matrix<int32_t> &mat_src2, matrix<int32_t> &mat_dst) {

    auto size = mat_src1.m.size();

    if (size % 8 != 0) {
        throw std::runtime_error(std::string("size not div by 8"));
    }

    int64_t *src1_ptr = (int64_t *)mat_src1.m.data();
    int64_t *src2_ptr = (int64_t *)mat_src2.m.data();
    int64_t *dst_ptr = (int64_t *)mat_dst.m.data();

    for (int64_t i = 0; i < size; i += 8) {
        __m256 src1 = _mm256_loadu_si256((__m256i_u *)(src1_ptr + i));
        __m256 src2 = _mm256_loadu_si256((__m256i_u *)(src2_ptr + i));
        __m256 result = add<true>(src1, src1);
        _mm256_storeu_si256((__m256i_u *)(dst_ptr + i), result);
    }
}