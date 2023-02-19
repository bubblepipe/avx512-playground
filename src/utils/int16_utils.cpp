#include <cstdint>
#include <limits>
#include <stdexcept>
#include <immintrin.h>

#ifdef AVX512_ENABLED

typedef int16_t Vector16x32 __attribute__((ext_vector_type(32)));

inline void throwOverflowIf(bool cond) {
  if (cond)
    throw std::overflow_error("Overflow!");
}

inline __mmask32 equalMask(Vector16x32 x, Vector16x32 y) {
  return _mm512_cmp_epi16_mask(x, y, _MM_CMPINT_EQ);
}

inline __mmask32 negs(Vector16x32 x) {
  return _mm512_cmp_epi16_mask(x, Vector16x32(0), _MM_CMPINT_LT);
}

template <bool isChecked>
inline Vector16x32 negate(Vector16x32 x) {
  if constexpr (isChecked) {
    bool overflow = equalMask(x, std::numeric_limits<int16_t>::min());
    throwOverflowIf(overflow);
  }
  return -x;
}

template <bool isChecked>
inline Vector16x32 add(Vector16x32 x, Vector16x32 y) {
  Vector16x32 res = x + y;
  if constexpr (isChecked) {
    Vector16x32 z = _mm512_adds_epi16(x, y);
    bool overflow = ~equalMask(z, res);
    throwOverflowIf(overflow);
  }
  return res;
}

template <bool isChecked>
inline Vector16x32 mul(Vector16x32 x, Vector16x32 y) {
  Vector16x32 lo = _mm512_mullo_epi16(x, y);
  if constexpr (isChecked) {
    Vector16x32 hi = _mm512_mulhi_epi16(x, y);
    throwOverflowIf(~equalMask(lo >> 15, hi));
  }
  return lo;
}
#endif
