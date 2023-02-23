#include <bench_pivot/utils.cpp>

template <typename T>
class matrix {

public:
  std::vector<std::vector<T>> m;

  unsigned int nRow;
  unsigned int nCol;
  unsigned int nColPadding;

  // rowsize = nCol
  // colsize = nRow
  matrix(unsigned int r, unsigned int c) {
    nRow = r;
    nCol = c;
    nColPadding = compute_nCol_padding(nCol);
    m.resize(nRow, std::vector<T>(nColPadding, 0));
  }
  
//   matrix(mlir::presburger::Matrix &tableau, unsigned nRow_, unsigned nCol_) {
//     nRow = nRow_;
//     nCol = nCol_;
//     nColPadding = compute_nCol_padding(nCol);
//     m.resize(nRow, std::vector<T>(nColPadding, 0));
//     for (unsigned r = 0; r < nRow; r += 1) {
//       for (unsigned c = 0; c < nCol; c += 1) {
//         mlir::presburger::MPInt x = tableau(r, c);
//         set(r, c, (int64_t)x);
//       }
//     }
//   }

  T get(unsigned int x, unsigned int y) const { return m[x][y]; }
  T &get(unsigned int x, unsigned int y) { return m[x][y]; }
  void set(unsigned int x, unsigned int y, T val) { m[x][y] = val; }
  T operator()(unsigned row, unsigned column) const { return get(row, column); }
  T &operator()(unsigned row, unsigned column) { return get(row, column); }

  T* getPtr(){
    return m.data();
  }

  T* getRowPtr(unsigned int row){
    return m[row].data();
  }

  unsigned int compute_nCol_padding(unsigned int nCol) {
    auto vector_size = 4;
    if (std::is_same<T, double>::value) {
      vector_size = ZmmDoubleVecSize;
    } else if (std::is_same<T, float>::value) {
      vector_size = ZmmFloatVecSize;
    } else {
      printf("compute_nCol_padding\n");
      exit(0); // TODO: 
    }
    return nCol + (vector_size - (nCol % vector_size)) + 1;
  }

  void print() {
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

  void negateRow(unsigned int row) {
    unsigned rowSize = nCol;
    for (unsigned int i = 0; i < rowSize; i += 1) {
      set(row, i, -(get(row, i)));
    }
  }

  void negateRowVectorized(unsigned int row) {
    T * rowPtr = getRowPtr(row);
    if (std::is_same<T, double>::value) {
      for (unsigned colIndex = 0; colIndex < nCol; colIndex += ZmmDoubleVecSize) {
        __m512 mat_row_ymm = _mm512_loadu_pd((const double *)(rowPtr + colIndex));
        // __m512 result = _mm512_sub_pd(_mm512_set1_pd(0.0), mat_row_ymm);
        __m512 result = _mm512_xor_ps(mat_row_ymm, _mm512_set1_pd(-0.0)); // from https://stackoverflow.com/questions/20083997/how-to-negate-change-sign-of-the-floating-point-elements-in-a-m128-type-vari
        _mm512_storeu_pd((double *)(rowPtr + colIndex), result);
      }
    } else if (std::is_same<T, float>::value) {
      for (unsigned colIndex = 0; colIndex < nCol; colIndex += ZmmFloatVecSize) {
        __m512 mat_row_ymm = _mm512_loadu_ps((const float *)(rowPtr + colIndex));
        __m512 result = _mm512_xor_ps(mat_row_ymm, _mm512_set1_ps(-0.0));
        _mm512_storeu_ps((float *)(rowPtr + colIndex), result);
      }
    } else {
      negateRow(row);
    }
  }

  void normalizeRowScalar(unsigned row) {
    T gcd = 0;
    for (unsigned col = 0; col < nCol; ++col) {
      if (gcd == 1)
        break;
      // TODO: this is slow?
      printx(TRIVIAL, "gcd %f, elem %f\n", gcd, this->get(row, col));
      gcd = greatestCommonDivisor((int64_t)gcd, std::abs((int64_t)this->get(row, col)));
    }

    if (gcd == 0 || gcd == 1)
      return;
    for (unsigned col = 0; col < nCol; ++col) {
      auto val = this->get(row, col) / gcd;
      this->set(row, col, val);
    }
    assert(this->get(row, 0) != 0);
  }
};
