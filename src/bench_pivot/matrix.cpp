#include "bench_pivot/utils.h"
#include <bench_pivot/matrix.h>
#include <bench_pivot/MPInt.h>
#include <cstdint>
#include <cstdlib>

template <typename T, VectorSize vectorSize>
matrix<T, vectorSize>::matrix(unsigned int r, unsigned int c) {
  nRow = r;
  nCol = c;
  nColPadding = compute_nCol_padding(nCol);
  m.resize(nRow * nColPadding);
}

template <typename T, VectorSize vectorSize>
matrix<T, vectorSize>::matrix(matrix<T, vectorSize> & other) {
  nRow = other.nRow;
  nCol = other.nCol;
  nColPadding = other.nColPadding;
  m.resize(nRow * nColPadding);

  for (int rowIndex = 0; rowIndex < nRow; rowIndex += 1) {
    for (int colIndex = 0; colIndex < nCol; colIndex += 1) {
      this->set(rowIndex, colIndex, other(rowIndex, colIndex));
    }
  }
} 

template <typename T, VectorSize vectorSize>
inline T matrix<T, vectorSize>::get(unsigned int x, unsigned int y) const { return m[nColPadding * x + y]; }

template <typename T, VectorSize vectorSize>
inline T &matrix<T, vectorSize>::get(unsigned int x, unsigned int y) { return m[nColPadding * x + y]; }

template <typename T, VectorSize vectorSize>
inline void matrix<T, vectorSize>::set(unsigned int x, unsigned int y, T val) { m[nColPadding * x + y] = val; }

template <typename T, VectorSize vectorSize>
inline T matrix<T, vectorSize>::operator()(unsigned int row, unsigned int column) const { return get(row, column); }

template <typename T, VectorSize vectorSize>
inline T &matrix<T, vectorSize>::operator()(unsigned int row, unsigned int column) { return get(row, column); }

template <typename T, VectorSize vectorSize>
inline T* matrix<T, vectorSize>::getPtr(){
  return m.data();
}

template <typename T, VectorSize vectorSize>
inline T* matrix<T, vectorSize>::getRowPtr(unsigned int row){
  return m.data() + nColPadding * row;
}


template <>
unsigned int matrix<float, ZMM>::compute_nCol_padding(unsigned int nCol) {
  if (nCol == lookup(_8) || nCol == lookup(_16)) {
    return ZmmFloatVecSize;
  } else if (nCol == lookup(_24) || nCol == lookup(_32)) {
    return ZmmFloatVecSize * 2;
  } else {
    printf("this should not happen\n"); exit(0); 
  }
}

template <>
unsigned int matrix<float, YMM>::compute_nCol_padding(unsigned int nCol) {
  if (nCol == lookup(_8)) {
    return YmmFloatVecSize;
  } else if (nCol == lookup(_16)) {
    return YmmFloatVecSize * 2;
  } else if (nCol == lookup(_24)) {
    return YmmFloatVecSize * 3;
  } else if (nCol == lookup(_32)) {
    return YmmFloatVecSize * 4;
  } else {
    printf("this should not happen\n"); exit(0); 
  }
}

template <>
unsigned int matrix<double, ZMM>::compute_nCol_padding(unsigned int nCol) {
  if (nCol == lookup(_8)) {
    return ZmmDoubleVecSize;
  } else if (nCol == lookup(_16)) {
    return ZmmDoubleVecSize * 2;
  } else if (nCol == lookup(_24)) {
    return ZmmDoubleVecSize * 3;
  } else if (nCol == lookup(_32)) {
    return ZmmDoubleVecSize * 4;
  } else {
    printf("this should not happen\n"); exit(0); 
  }
}

template <>
unsigned int matrix<float, XMM>::compute_nCol_padding(unsigned int nCol) {
  printf("float, why XMM?\n"); exit(0); 
}

template <>
unsigned int matrix<double, YMM>::compute_nCol_padding(unsigned int nCol) {
  printf("double, why YMM?\n"); exit(0); 
}

template <>
unsigned int matrix<double, XMM>::compute_nCol_padding(unsigned int nCol) {
  printf("double, why XMM?\n"); exit(0); 
}

template <>
unsigned int matrix<int16_t, ZMM>::compute_nCol_padding(unsigned int nCol) {
  return ZmmInt64VecSize;
}

template <>
unsigned int matrix<int16_t, YMM>::compute_nCol_padding(unsigned int nCol) {
  if (nCol == lookup(_8) || nCol == lookup(_16)) {
    return YmmInt16VecSize;
  } else if (nCol == lookup(_24) || nCol == lookup(_32)) {
    return YmmInt16VecSize * 2;
  } else {
    printf("this should not happen\n"); exit(0); 
  }
}

template <>
unsigned int matrix<int16_t, XMM>::compute_nCol_padding(unsigned int nCol) {
  if (nCol == lookup(_8)) {
    return XmmInt16VecSize;
  } else if (nCol == lookup(_16)) {
    return XmmInt16VecSize * 2;
  } else if (nCol == lookup(_24)) {
    return XmmInt16VecSize * 3;
  } else if (nCol == lookup(_32)) {
    return XmmInt16VecSize * 4;
  } else {
    printf("this should not happen\n"); exit(0); 
  }
}


template <typename T, VectorSize vectorSize>
unsigned int matrix<T, vectorSize>::compute_nCol_padding(unsigned int nCol) {
  auto vector_size = 4;
  if (nCol % vector_size == 0) 
    return nCol;
  else 
    return nCol + (vector_size -(nCol % vector_size) );
}

template <typename T, VectorSize vectorSize>
void matrix<T, vectorSize>::print() {
  printx(INFO, "\n====START==OF==MATRIX====\n");
  for (unsigned i = 0; i < nRow; i += 1) {
    for (unsigned j = 0; j < nCol; j += 1) {
      // printx(INFO, "%ld(0x%lx) ", (int64_t) get(i, j), *((uint64_t
      // *)&get(i, j)));
      printx(INFO, "%ld ", (int64_t)get(i, j));
    }
    printx(INFO, "\n");
  }
  printx(INFO, "======END==OF==MATRIX======\n\n");
}

template <typename T, VectorSize vectorSize>
void matrix<T, vectorSize>::negateRow(unsigned int row) {
  unsigned rowSize = nCol;
  for (unsigned int i = 0; i < rowSize; i += 1) {
    set(row, i, -(get(row, i)));
  }
}

template <typename T, VectorSize vectorSize>
void matrix<T, vectorSize>::negateRowVectorized(unsigned int row) {
  T * rowPtr = getRowPtr(row);
  if constexpr (std::is_same<T, double>::value) {
    for (unsigned colIndex = 0; colIndex < nCol; colIndex += ZmmDoubleVecSize) {
      __m512 mat_row_ymm = _mm512_loadu_pd((const double *)(rowPtr + colIndex));
      // __m512 result = _mm512_sub_pd(_mm512_set1_pd(0.0), mat_row_ymm);
      __m512 result = _mm512_xor_ps(mat_row_ymm, _mm512_set1_pd(-0.0)); // from https://stackoverflow.com/questions/20083997/how-to-negate-change-sign-of-the-floating-point-elements-in-a-m128-type-vari
      _mm512_storeu_pd((double *)(rowPtr + colIndex), result);
    }
  } else if constexpr (std::is_same<T, float>::value) {
    for (unsigned colIndex = 0; colIndex < nCol; colIndex += ZmmFloatVecSize) {
      __m512 mat_row_ymm = _mm512_loadu_ps((const float *)(rowPtr + colIndex));
      __m512 result = _mm512_xor_ps(mat_row_ymm, _mm512_set1_ps(-0.0));
      _mm512_storeu_ps((float *)(rowPtr + colIndex), result);
    }
  } else {
    negateRow(row);
  }
}

template <typename T, VectorSize vectorSize>
void matrix<T, vectorSize>::normalizeRowScalar(unsigned row) {
  T gcd = (T) 0;
  for (unsigned col = 0; col < nCol; ++col) {
    if (gcd == 1)
      break;
    // TODO: this is slow?
    // printx(TRIVIAL, "gcd %f, elem %f\n", gcd, this->get(row, col));
    gcd = greatestCommonDivisor((int64_t)gcd, std::abs((int64_t)this->get(row, col)));
  }

  if (gcd == 0 || gcd == 1)
    return;
  for (unsigned col = 0; col < nCol; ++col) {
    auto val = this->get(row, col) / gcd;
    this->set(row, col, val);
  }
  // assert(this->get(row, 0) != 0);
}

template <typename T, VectorSize vectorSize>
void matrix<T, vectorSize>::normalizeRow2(T * rowPtr) {
  T gcd = (T) 0;
  for (unsigned col = 0; col < nCol; ++col) {
    if (gcd == 1)
      break;
    gcd = greatestCommonDivisor((int32_t)gcd, std::abs((int32_t)rowPtr[col]));
  }

  if (gcd == 0 || gcd == 1)
    return;
  for (unsigned col = 0; col < nCol; ++col) {
    auto val = rowPtr[col] / gcd;
    rowPtr[col] = val;
  }
}

template class matrix<double, XMM>;
template class matrix<double, YMM>;
template class matrix<double, ZMM>;
template class matrix<float, XMM>;
template class matrix<float, YMM>;
template class matrix<float, ZMM>;
template class matrix<int16_t, XMM>;
template class matrix<int16_t, YMM>;
template class matrix<int16_t, ZMM>;
template class matrix<int64_t, scalar>;
template class matrix<MPInt, scalar>;
template class matrix<uint64_t, scalar>;

inline int32_t greatestCommonDivisor(int32_t A, int32_t B) {
  while (B) {
    int32_t Tmp = B;
    B = A % B;
    A = Tmp;
  }
  return A;
}