#ifndef INT16_UTILS_H
#define INT16_UTILS_H

#include <cstdint>
#include <limits>
#include <stdexcept>
#include <immintrin.h>
#include <bench_pivot/utils.h>

typedef int16_t Vector16x32 __attribute__((ext_vector_type(32)));

inline __attribute__((always_inline)) void throwOverflowIf(bool cond) {
  if (cond) {
    throw std::overflow_error("Overflow!");
  }
}

inline __attribute__((always_inline)) __mmask32 equalMask(Vector16x32 x, Vector16x32 y) {
  return _mm512_cmp_epi16_mask(x, y, _MM_CMPINT_EQ);
}

inline __attribute__((always_inline)) __mmask32 negs(Vector16x32 x) {
  return _mm512_cmp_epi16_mask(x, Vector16x32(0), _MM_CMPINT_LT);
}

template <bool isChecked>
inline __attribute__((always_inline)) Vector16x32 negate(Vector16x32 x, bool & overflow_accum) {
  if constexpr (isChecked) {
    bool overflow = equalMask(x, std::numeric_limits<int16_t>::min());
    overflow_accum |= overflow;
  }
  return -x;
}

inline __attribute__((always_inline)) __mmask32 equalMask(int16Ymm x, int16Ymm y) {
  return _mm256_cmp_epi16_mask(x, y, _MM_CMPINT_EQ);
}

template <bool isChecked>
inline __attribute__((always_inline)) int16Ymm negate(int16Ymm x, bool & overflow_accum) {
  if constexpr (isChecked) {
    bool overflow = equalMask(x, std::numeric_limits<int16_t>::min());
    overflow_accum |= overflow;
  }
  return -x;
}

inline __attribute__((always_inline)) __mmask32 equalMask(int16Xmm x, int16Xmm y) {
  return _mm_cmp_epi16_mask(x, y, _MM_CMPINT_EQ);
}

template <bool isChecked>
inline __attribute__((always_inline)) int16Xmm negate(int16Xmm x, bool & overflow_accum) {
  if constexpr (isChecked) {
    bool overflow = equalMask(x, std::numeric_limits<int16_t>::min());
    overflow_accum |= overflow;
  }
  return -x;
}

template <bool isChecked>
inline __attribute__((always_inline)) Vector16x32 add(Vector16x32 x, Vector16x32 y, bool & overflow_accum) {
  Vector16x32 res = x + y;
  if constexpr (isChecked) {
    Vector16x32 z = _mm512_adds_epi16(x, y);
    bool overflow = ~equalMask(z, res);
    overflow_accum |= overflow;
  }
  return res;
}
template <bool isChecked>
inline __attribute__((always_inline)) int16Ymm add(int16Ymm x, int16Ymm y, bool & overflow_accum) {
  int16Ymm res = x + y;
  if constexpr (isChecked) {
    int16Ymm z = _mm256_adds_epi16(x, y);
    bool overflow = ~equalMask(z, res);
    overflow_accum |= overflow;
  }
  return res;
}
template <bool isChecked>
inline __attribute__((always_inline)) int16Xmm add(int16Xmm x, int16Xmm y, bool & overflow_accum) {
  int16Xmm res = x + y;
  if constexpr (isChecked) {
    int16Xmm z = _mm_adds_epi16(x, y);
    bool overflow = ~equalMask(z, res);
    overflow_accum |= overflow;
  }
  return res;
}
template <bool isChecked>
inline __attribute__((always_inline)) Vector16x32 mul(Vector16x32 x, Vector16x32 y, bool & overflow_accum) {
  Vector16x32 lo = _mm512_mullo_epi16(x, y);
  if constexpr (isChecked) {
    Vector16x32 hi = _mm512_mulhi_epi16(x, y);
    bool overflow = ~equalMask(lo >> 15, hi);
    overflow_accum |= overflow;
  }
  return lo;
}


template <bool isChecked>
inline __attribute__((always_inline)) int16Ymm mul(int16Ymm x, int16Ymm y, bool & overflow_accum) {
  int16Ymm lo = _mm256_mullo_epi16(x, y);
  if constexpr (isChecked) {
    int16Ymm hi = _mm256_mulhi_epi16(x, y);
    bool overflow = ~equalMask(lo >> 15, hi);
    overflow_accum |= overflow;
  }
  return lo;
}


template <bool isChecked>
inline __attribute__((always_inline)) int16Xmm mul(int16Xmm x, int16Xmm y, bool & overflow_accum) {
  int16Xmm lo = _mm_mullo_epi16(x, y);
  if constexpr (isChecked) {
    int16Xmm hi = _mm_mulhi_epi16(x, y);
    bool overflow = ~equalMask(lo >> 15, hi);
    overflow_accum |= overflow;
  }
  return lo;
}
#endif