#include <cstdint>
#include <limits>
#include <stdexcept>
#include <immintrin.h>

#ifdef AVX512_ENABLED

typedef int32_t Vector32x16 __attribute__((ext_vector_type(16)));

inline void throwOverflowIf(bool cond) {
  if (cond)
    throw std::overflow_error("Overflow!");
}

inline __mmask32 equalMask(Vector32x16 x, Vector32x16 y) {
  return _mm512_cmp_epi16_mask(x, y, _MM_CMPINT_EQ);
}

inline __mmask32 negs(Vector32x16 x) {
  return _mm512_cmp_epi16_mask(x, Vector32x16(0), _MM_CMPINT_LT);
}

template <bool isChecked>
inline Vector32x16 negate(Vector32x16 x) {
  if constexpr (isChecked) {
    bool overflow = equalMask(x, std::numeric_limits<int16_t>::min());
    throwOverflowIf(overflow);
  }
  return -x;
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

template <bool isChecked>
inline Vector32x16 mul(Vector32x16 x, Vector32x16 y) {
  Vector32x16 lo = _mm512_mullo_epi16(x, y);
  if constexpr (isChecked) {
    Vector32x16 hi = _mm512_mulhi_epi16(x, y);
    throwOverflowIf(~equalMask(lo >> 15, hi));
  }
  return lo;
}

#endif