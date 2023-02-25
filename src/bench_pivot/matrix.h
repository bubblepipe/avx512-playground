#include <cstdint>
#include <vector>

template <typename T>
class matrix {

public:
  std::vector<std::vector<T>> m;

  unsigned int nRow;
  unsigned int nCol;
  unsigned int nColPadding;

  // rowsize = nCol
  // colsize = nRow
  matrix(unsigned int r, unsigned int c);

  matrix(matrix<double> & other);

  T get(unsigned int x, unsigned int y) const;
  T &get(unsigned int x, unsigned int y);
  void set(unsigned int x, unsigned int y, T val);
  T operator()(unsigned row, unsigned column) const;
  T &operator()(unsigned row, unsigned column);

  T* getPtr();

  T* getRowPtr(unsigned int row);

  unsigned int compute_nCol_padding(unsigned int nCol);

  void print();

  void negateRow(unsigned int row);

  void negateRowVectorized(unsigned int row);

  void normalizeRowScalar(unsigned row);
};

inline int64_t greatestCommonDivisor(int64_t A, int64_t B) ;
