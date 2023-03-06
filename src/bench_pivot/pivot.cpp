#include <bench_pivot/pivot.h>
#include <bench_pivot/utils.h>
#include <bench_pivot/MPInt.h>
#include <cstdint>
#include <x86intrin.h>
#include <utils/int16_utils.cpp>

#define START_TIMER     unsigned int dummy;  \
    unsigned long t1 = __rdtscp(&dummy);
#define STOP_TIMER     unsigned long t2 = __rdtscp(&dummy); \
    printf("Time: %ld\n",  t2 - t1); \
    exit(0);

// template <typename Zmm>
// void normalizeRowVectorized(Zmm * rowPtr) {
//   T gcd = (T) 0;
//   for (unsigned col = 0; col < nCol; ++col) {
//     if (gcd == 1)
//       break;
//     gcd = greatestCommonDivisor((int32_t)gcd, std::abs((int32_t)rowPtr[col]));
//   }

//   if (gcd == 0 || gcd == 1)
//     return;
//   for (unsigned col = 0; col < nCol; ++col) {
//     auto val = rowPtr[col] / gcd;
//     rowPtr[col] = val;
//   }
// }
// true: no fpe
// false: no

template <typename T>
bool pivot(matrix<T> & mat, unsigned pivotRow, unsigned pivotCol) {
  return false;
}


template<> bool pivot<float>(matrix<float> & mat, unsigned pivotRow, unsigned pivotCol) {

  // std::feclearexcept (FE_INEXACT | FE_INVALID);

  typedef float T;
  typedef floatZmm Zmm;

  unsigned nRow, nCol;
  nRow = mat.nRow;
  nCol = mat.nCol;
  T * pivotRowPtr = mat.getRowPtr(pivotRow);
  
  T tmp = pivotRowPtr[0];
  pivotRowPtr[0] = -pivotRowPtr[pivotCol];
  pivotRowPtr[pivotCol] = -tmp;

  auto pivotRowPtr_pivotCol = -tmp;
  auto pivotRowPtr_0 = pivotRowPtr[0];

  if (pivotRowPtr_0 < 0) { 
    mat.negateRowVectorized(pivotRow);
  }
  mat.normalizeRow2(pivotRowPtr);

  T * rowPtr = mat.getRowPtr(0);
   
  Zmm pivotRowVec = *(Zmm *)pivotRowPtr;
  pivotRowVec[0] = 0;
  Zmm ConstA = pivotRowPtr_0;
  ConstA[0] = 1;
  
  for (unsigned rowIndex = 0; rowIndex < nRow; rowIndex += 1) {
    if (rowIndex == pivotRow) { rowPtr += mat.nColPadding; continue; }
    T pivotColBackup = rowPtr[pivotCol];
    if (pivotColBackup == 0) { rowPtr += mat.nColPadding; continue; }

    Zmm ConstC = pivotColBackup;
    Zmm matRowVec = *(Zmm *)(rowPtr);
    Zmm result = ConstC * pivotRowVec + matRowVec * ConstA;
    matRowVec[0] *= pivotRowPtr_0;
    *(Zmm *)(rowPtr) =  result;

    rowPtr[pivotCol] = pivotColBackup * pivotRowPtr_pivotCol;
    mat.normalizeRow2(rowPtr);
    rowPtr += mat.nColPadding;
  }

  // if (fetestexcept_local(FE_INEXACT | FE_INVALID)) {
    // return false;
  // } else 
  return true;

}

template<> bool pivot<int16_t>(matrix<int16_t> & mat, unsigned pivotRow, unsigned pivotCol) {

  typedef int16_t T;
  typedef int16Zmm Zmm;

  unsigned nRow, nCol;
  nRow = mat.nRow;
  nCol = mat.nCol;
  T * pivotRowPtr = mat.getRowPtr(pivotRow);
  
  T tmp = pivotRowPtr[0];
  pivotRowPtr[0] = -pivotRowPtr[pivotCol];
  pivotRowPtr[pivotCol] = -tmp;

  auto pivotRowPtr_pivotCol = -tmp;
  auto pivotRowPtr_0 = pivotRowPtr[0];

  if (pivotRowPtr_0 < 0) { 
    mat.negateRowVectorized(pivotRow);
  }
  mat.normalizeRow2(pivotRowPtr);

  T * rowPtr = mat.getRowPtr(0);
   
  Zmm pivotRowVec = *(Zmm *)pivotRowPtr;
  pivotRowVec[0] = 0;
  Zmm ConstA = pivotRowPtr_0;
  ConstA[0] = 1;
  
  for (unsigned rowIndex = 0; rowIndex < nRow; rowIndex += 1) {
    if (rowIndex == pivotRow) { rowPtr += mat.nColPadding; continue; }
    T pivotColBackup = rowPtr[pivotCol];
    if (pivotColBackup == 0) { rowPtr += mat.nColPadding; continue; }

    Zmm ConstC = pivotColBackup;
    Zmm matRowVec = *(Zmm *)(rowPtr);
    Zmm result = ConstC * pivotRowVec + matRowVec * ConstA;
    matRowVec[0] *= pivotRowPtr_0;
    *(Zmm *)(rowPtr) =  result;

    rowPtr[pivotCol] = pivotColBackup * pivotRowPtr_pivotCol;
    mat.normalizeRow2(rowPtr);
    rowPtr += mat.nColPadding;
  }

  return true;

}



template<> bool pivot<MPInt>(matrix<MPInt> & mat, unsigned pivotRow, unsigned pivotCol) {

  typedef MPInt T;

  unsigned nRow, nCol;
  nRow = mat.nRow;
  nCol = mat.nCol;
  if (mat(pivotRow, 0) < 0) {
    mat(pivotRow, 0) = -mat(pivotRow, 0);
    mat(pivotRow, pivotCol) = -mat(pivotRow, pivotCol);
  } else {
    for (unsigned col = 1, e = nCol; col < e; ++col) {
      if (col == pivotCol)
        continue;
      mat(pivotRow, col) = -mat(pivotRow, col);
    }
  }
  mat.normalizeRowScalar(pivotRow);

  for (unsigned rowIndex = 0; rowIndex < nRow; rowIndex += 1) {
      if (rowIndex == pivotRow) { continue; }
      if (mat(rowIndex, pivotCol) == 0) { continue; }

    mat(rowIndex, 0) *= mat(pivotRow, 0);
    for (unsigned col = 1; col < nCol; ++col) {
      if (col == pivotCol){ continue; }

      mat(rowIndex, col) = mat(rowIndex, col) * mat(pivotRow, 0) +
                           mat(rowIndex, pivotCol) * mat(pivotRow, col);
    }

    mat(rowIndex, pivotCol) *= mat(pivotRow, pivotCol);
    mat.normalizeRowScalar(rowIndex);
  }

  return true;
}


// // true: no fpe
// // false: no
// template <typename T>
// bool pivot(matrix<T> & mat, unsigned pivotRow, unsigned pivotCol) {

//   if constexpr (std::is_same<T, double>::value || std::is_same<T, float>::value ) {
//     // std::feclearexcept (FE_INEXACT | FE_INVALID);
//   }

//   // printx(INFO, "\n>>> pivotRow %ld, pivotCol %ld <<<\n", (int64_t)pivotRow, (int64_t)pivotCol);

//   // todo this
//   // swapRowWithCol(pivotRow, pivotCol);

//   unsigned nRow, nCol;
//   nRow = mat.nRow;
//   nCol = mat.nCol;
//   T * pivotRowPtr = mat.getRowPtr(pivotRow);
  
//   T tmp = pivotRowPtr[0];
//   pivotRowPtr[0] = -pivotRowPtr[pivotCol];
//   pivotRowPtr[pivotCol] = -tmp;

//   auto pivotRowPtr_pivotCol = -tmp;
//   auto pivotRowPtr_0 = pivotRowPtr[0];

//   if (pivotRowPtr_0 < 0) {
// #ifdef SCALAR
//     mat.negateRow(pivotRow);
// #else
//     mat.negateRowVectorized(pivotRow);
// #endif
//   }

//   mat.normalizeRow2(pivotRowPtr);

//   T * rowPtr = mat.getRowPtr(0);

// #if defined SCALAR || defined USE_MPInt
//     printf("not implemented\n");
//     exit(0);
//     mat(rowIndex, 0) *= mat(pivotRow, 0);
//     for (unsigned col = 1; col < nCol; ++col) {
//       if (col == pivotCol){ continue; }

//       mat(rowIndex, col) = mat(rowIndex, col) * mat(pivotRow, 0) +
//                            mat(rowIndex, pivotCol) * mat(pivotRow, col);
//     }

//     mat(rowIndex, pivotCol) *= mat(pivotRow, pivotCol);
//     mat.normalizeRow2(rowPtr);

// #else
//   if constexpr (std::is_same<T, float>::value){
    
//     typedef floatZmm Zmm;
//     Zmm pivotRowVec = *(Zmm *)pivotRowPtr;
//     pivotRowVec[0] = 0;
//     Zmm ConstA = pivotRowPtr_0;
//     ConstA[0] = 1;
    
//     for (unsigned rowIndex = 0; rowIndex < nRow; rowIndex += 1) {
//       if (rowIndex == pivotRow) { rowPtr += mat.nColPadding; continue; }
//       T pivotColBackup = rowPtr[pivotCol];
//       if (pivotColBackup == 0) { rowPtr += mat.nColPadding; continue; }

//       Zmm ConstC = pivotColBackup;
//       Zmm matRowVec = *(Zmm *)(rowPtr);
//       Zmm result = ConstC * pivotRowVec + matRowVec * ConstA;
//       matRowVec[0] *= pivotRowPtr_0;
//       *(Zmm *)(rowPtr) =  result;

//       rowPtr[pivotCol] = pivotColBackup * pivotRowPtr_pivotCol;
//       mat.normalizeRow2(rowPtr);
//       rowPtr += mat.nColPadding;
//     }
//   } 

//   else if constexpr (std::is_same<T, double>::value){

//   } 
//   else if constexpr (std::is_same<T, int16_t>::value){
//     typedef int16Zmm Zmm;
//     Zmm pivotRowVec = *(Zmm *)pivotRowPtr;
//     pivotRowVec[0] = 0;
//     Zmm ConstA = pivotRowPtr_0;
//     ConstA[0] = 1;
    
//     for (unsigned rowIndex = 0; rowIndex < nRow; rowIndex += 1) {
//       if (rowIndex == pivotRow) { rowPtr += mat.nColPadding; continue; }
//       T pivotColBackup = rowPtr[pivotCol];
//       if (pivotColBackup == 0) { rowPtr += mat.nColPadding; continue; }

//       Zmm ConstC = pivotColBackup;
//       Zmm matRowVec = *(Zmm *)(rowPtr);
//       Zmm result = ConstC * pivotRowVec + matRowVec * ConstA;
//       matRowVec[0] *= pivotRowPtr_0;
//       *(Zmm *)(rowPtr) =  result;

//       rowPtr[pivotCol] = pivotColBackup * pivotRowPtr_pivotCol;
//       mat.normalizeRow2(rowPtr);
//       rowPtr += mat.nColPadding;
//     }


//   } else {

//   }

// #endif

//   if constexpr (std::is_same<T, double>::value || std::is_same<T, float>::value ) {
//     // if (fetestexcept_local(FE_INEXACT | FE_INVALID)) {
//       // return false;
//     // } else 
//       return true;
//   } else {
//     return true;
//   }

// }


template bool pivot <double>(matrix<double> & tableau, unsigned pivotRow, unsigned pivotCol);
// template bool pivot <float>(matrix<float> & tableau, unsigned pivotRow, unsigned pivotCol);
template bool pivot <int64_t>(matrix<int64_t> & tableau, unsigned pivotRow, unsigned pivotCol);
// template bool pivot <int16_t>(matrix<int16_t> & tableau, unsigned pivotRow, unsigned pivotCol);
// template bool pivot <MPInt>(matrix<MPInt> & tableau, unsigned pivotRow, unsigned pivotCol);

