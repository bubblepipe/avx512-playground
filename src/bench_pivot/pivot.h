#include <cstdint>
#include <bench_pivot/matrix.h>
#include <bench_pivot/utils.h>

template <typename T, typename T_Zmm> 
bool pivot(matrix<T> & tableau, unsigned pivotRow, unsigned pivotCol) ;
