#include <bench_pivot/matrix.h>
#include <bench_pivot/utils.h>
#include <bench_pivot/MPInt.h>
#include <cstdint>

template <typename T>
matrix<T>::matrix(unsigned int r, unsigned int c) {
  nRow = r;
  nCol = c;
  nColPadding = compute_nCol_padding(nCol);
  m.resize(nRow * nColPadding);
  }

template <typename T>
matrix<T>::matrix(matrix<T> & other) {
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

template <typename T>
T matrix<T>::get(unsigned int x, unsigned int y) const { return m[nColPadding * x + y]; }

template <typename T>
T &matrix<T>::get(unsigned int x, unsigned int y) { return m[nColPadding * x + y]; }

template <typename T>
void matrix<T>::set(unsigned int x, unsigned int y, T val) { m[nColPadding * x + y] = val; }

template <typename T>
T matrix<T>::operator()(unsigned int row, unsigned int column) const { return get(row, column); }

template <typename T>
T &matrix<T>::operator()(unsigned int row, unsigned int column) { return get(row, column); }

template <typename T>
T* matrix<T>::getPtr(){
  return m.data();
}

template <typename T>
T* matrix<T>::getRowPtr(unsigned int row){
  return m.data() + nColPadding * row;
}

template <typename T>
unsigned int matrix<T>::compute_nCol_padding(unsigned int nCol) {
  auto vector_size = 4;
  if (std::is_same<T, double>::value) {
    vector_size = ZmmDoubleVecSize;
  } else if (std::is_same<T, float>::value) {
    vector_size = ZmmFloatVecSize;
  } else if (std::is_same<T, int64_t>::value) {
    vector_size = ZmmInt64VecSize;
  } else if (std::is_same<T, MPInt>::value) {
    vector_size = ZmmInt64VecSize;
  } else if (std::is_same<T, int16_t>::value) {
    vector_size = ZmmInt16VecSize;
  } else {
    printf("compute_nCol_padding\n");
    exit(0); // TODO: 
  }
  return nCol + (vector_size - (nCol % vector_size)) + 1;
}

template <typename T>
void matrix<T>::print() {
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

template <typename T>
void matrix<T>::negateRow(unsigned int row) {
  unsigned rowSize = nCol;
  for (unsigned int i = 0; i < rowSize; i += 1) {
    set(row, i, -(get(row, i)));
  }
}

template <typename T>
void matrix<T>::negateRowVectorized(unsigned int row) {
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

template <typename T>
void matrix<T>::normalizeRowScalar(unsigned row) {
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

template class matrix<double>;
template class matrix<float>;
template class matrix<int64_t>;
template class matrix<int16_t>;
template class matrix<MPInt>;

inline int64_t greatestCommonDivisor(int64_t A, int64_t B) {
  while (B) {
    int64_t Tmp = B;
    B = A % B;
    A = Tmp;
  }
  return A;
}