#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <simdpp/simd.h>
#include <cfenv>
#include <utils/cfenv_local.cpp>
#include <utils/bench_utils.cpp>
#include <x86intrin.h>
#include <immintrin.h>

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
class matrix2 {

  public:
  std::vector<T> m;
  // std::vector<T, AlignedAllocator<T, 32>> m;
    unsigned int row;
    unsigned int col;

    matrix2(unsigned int r, unsigned int c) {
        row = r;
        col = c;
        m.resize(r * c);
    }

  public:
    T get(unsigned int x, unsigned int y) {
        return m[col * x + y];
    }
    void set(unsigned int x, unsigned int y, T val) {
        m[col * x + y] = val;
    }
};

void mat_fma_intrinsic_aligned ( unsigned int row, unsigned int col, 
    matrix2<double> & mat_src1, matrix2<double> & mat_src2, matrix2<double> & mat_src3, matrix2<double> & mat_dst ) {
    auto size = mat_src1.m.size();
    double * src1_ptr = (double *) mat_src1.m.data();
    double * src2_ptr = (double *) mat_src2.m.data();
    double * src3_ptr = (double *) mat_src3.m.data();
    double * dst_ptr  = (double *) mat_dst.m.data();

    for (int i = 0; i < size; i += 8 ){
        __m512 src1 = _mm512_loadu_pd ((const double *) (src1_ptr + i));
        __m512 src2 = _mm512_loadu_pd ((const double *) (src2_ptr + i));
        __m512 src3 = _mm512_loadu_pd ((const double *) (src3_ptr + i));
        __m512 result = _mm512_fmadd_pd(src1, src2, src3);
        _mm512_storeu_pd((double *) (dst_ptr + i), result);
    }
}


static void flat(benchmark::State& state, 
        void (*func_ptr)(unsigned int, unsigned int, matrix2<double> &, matrix2<double> &, matrix2<double> &, matrix2<double> & )) {

    unsigned int row = state.range(0);
    unsigned int col = state.range(1);
    matrix2<double> mat_src1(row,col);
    matrix2<double> mat_src2(row,col);
    matrix2<double> mat_src3(row,col);
    matrix2<double> mat_dst(row,col);

// fprintf(stderr,"src1_ptr: %lx\n",  (uint64_t)((double *) mat_src1.m.data()) % 64);
// fprintf(stderr,"src2_ptr: %lx\n",  (uint64_t)((double *) mat_src2.m.data()) % 64);
// fprintf(stderr,"src3_ptr: %lx\n",  (uint64_t)((double *) mat_src3.m.data()) % 64);
// fprintf(stderr,"dst_ptr: %lx\n",   (uint64_t) ((double *) mat_dst.m.data()) % 64);

    for (int r = 0; r < row; r += 1) {
        for (int c = 0; c < col; c += 1) {
            mat_src1.set(r,c, (double)r); // rand()/1 );
            mat_src2.set(r,c, (double)c); // rand()/1 );
            mat_src3.set(r,c, (double)c); // rand()/1 );
            mat_dst. set(r,c, (double)c); // rand()/1 );
        }
    }

    for (auto _ : state) {
        (*func_ptr)(row, col, mat_src1, mat_src2, mat_src3, mat_dst);
    }

}

BENCHMARK_CAPTURE(flat, fma_iu, &mat_fma_intrinsic_aligned)->BMarg;
BENCHMARK_MAIN();
