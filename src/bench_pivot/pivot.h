#include <cstdint>
#include <bench_pivot/matrix.cpp>

template <typename T, typename T_Zmm>
void pivot(matrix<T> & tableau, unsigned pivotRow, unsigned pivotCol) ;

template <typename T, typename T_Zmm>
bool pivot_vecvec(matrix<T> & tableau, unsigned pivotRow, unsigned pivotCol) ;