#include <utils/bench_utils.cpp>
#include <cstdint>
#include <immintrin.h>
#include <stdexcept>
#include <vector>

typedef int32_t Vector32x16 __attribute__((ext_vector_type(16)));

inline __mmask32 equalMask(Vector32x16 x, Vector32x16 y) {
    return _mm512_cmp_epi16_mask(x, y, _MM_CMPINT_EQ);
}

inline void throwOverflowIf(bool cond) {
    if (cond)
        throw std::overflow_error("Overflow!");
}

template <bool isChecked>
inline Vector32x16 add(Vector32x16 x, Vector32x16 y) {
    Vector32x16 res = x + y;
    if constexpr (isChecked) {
        Vector32x16 z = _mm512_adds_epi16(x, y);
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
    Vector32x16 lo = _mm512_mullo_epi16(x, y);
    if constexpr (isChecked) {
        Vector32x16 hi = _mm512_mulhi_epi16(x, y);
        throwOverflowIf(~equalMask(lo >> 15, hi));
    }
    return lo;
}

class matrix {

  public:
    std::vector<int64_t> m;
    unsigned int row;
    unsigned int col;

    matrix(unsigned int r, unsigned int c) {
        row = r;
        col = c;
        m.resize(r * c);
    }

  public:
    int64_t get(unsigned int x, unsigned int y) {
        return m[col * x + y];
    }
    void set(unsigned int x, unsigned int y, int64_t val) {
        m[col * x + y] = val;
    }
};

void mat_add_manual(unsigned int row, unsigned int col,
                    matrix &mat_src1, matrix &mat_src2, matrix &mat_dst) {

    auto size = mat_src1.m.size();

    if (size % 8 != 0) {
        throw std::runtime_error(std::string("size not div by 8"));
    }

    int64_t *src1_ptr = (int64_t *)mat_src1.m.data();
    int64_t *src2_ptr = (int64_t *)mat_src2.m.data();
    int64_t *dst_ptr = (int64_t *)mat_dst.m.data();

    for (int64_t i = 0; i < size; i += 8) {
        __m512 src1 = _mm512_loadu_si512((__m512i_u *)(src1_ptr + i));
        __m512 src2 = _mm512_loadu_si512((__m512i_u *)(src2_ptr + i));
        __m512 result = add<true>(src1, src1);
        _mm512_storeu_si512((__m512i_u *)(dst_ptr + i), result);
    }
}