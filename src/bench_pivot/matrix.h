#include <cstdint>
#include <cstdlib>
#include <vector>
#include <bench_pivot/utils.h>

template <class T, size_t Alignment>
struct AlignedAllocator {
  typedef T value_type;

  // The rebind is not needed from C++17 onwards, but it seems earlier stls
  // still require it. Hence, leave it in for now.
  template <typename U>
  struct rebind {
    typedef AlignedAllocator<U, Alignment> other;
  };

  constexpr unsigned to_next_alignment_multiple(unsigned alignment,
                                                unsigned size) {
    if ((size % alignment) == 0) {
      return size;
    } else {
      return size - (size % alignment) + alignment;
    }
  }

  AlignedAllocator() = default;
  template <class U, size_t Y>
  constexpr AlignedAllocator(const AlignedAllocator<U, Y> &) noexcept {}
  [[nodiscard]] T *allocate(std::size_t Elements) {
    if (auto p = static_cast<T *>(aligned_alloc(
            Alignment,
            to_next_alignment_multiple(Alignment, Elements * sizeof(T)))))
      return p;
    std::abort();
  }
  void deallocate(T *Pointer, std::size_t) noexcept { std::free(Pointer); }
};

template <typename T>
class matrix {

public:
  std::vector<T, AlignedAllocator<T, 64>> m;
  // std::vector<T> m;
  // std::vector<std::vector<T>> m;

  unsigned int nRow;
  unsigned int nCol;
  unsigned int nColPadding;

  // rowsize = nCol
  // colsize = nRow
  matrix(unsigned int r, unsigned int c);

  matrix(matrix<T> & other);

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
  void normalizeRow2(T * rowPtr);
};

inline int32_t greatestCommonDivisor(int32_t A, int32_t B) ;
