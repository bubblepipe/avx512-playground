#include <bench_pivot/pivot.h>
#include <bench_pivot/utils.h>
#include <bench_pivot/MPInt.h>
#include <cstdint>
#include <x86intrin.h>
#include <utils/int16_utils.cpp>
#include <utils/cfenv_local.cpp>

#define START_TIMER     unsigned int dummy;  \
    unsigned long t1 = __rdtscp(&dummy);
#define STOP_TIMER     unsigned long t2 = __rdtscp(&dummy); \
    printf("Time: %ld\n",  t2 - t1); \
    exit(0);

#ifdef CHECK_OVERFLOW
  #define FECLEAREXCEPT feclearexcept_local_sse (FE_INEXACT | FE_INVALID);
  #define if_fetestexcept_return_false_else \
    if (fetestexcept_local(FE_INEXACT | FE_INVALID)) { \
      return false; \
    } else  
#else 
  #define FECLEAREXCEPT 
  #define if_fetestexcept_return_false_else 
#endif

template <typename T>
bool pivot(matrix<T> & mat, unsigned pivotRow, unsigned pivotCol) {
  return false;
}

template<> bool pivot<float>(matrix<float> & mat, unsigned pivotRow, unsigned pivotCol) {

  FECLEAREXCEPT

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
  //mat.normalizerow2(pivotRowPtr);

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
    //mat.normalizerow2(rowPtr);
    rowPtr += mat.nColPadding;
  }

  if_fetestexcept_return_false_else
  return true;

}


template<> bool pivot<double>(matrix<double> & mat, unsigned pivotRow, unsigned pivotCol) {

  FECLEAREXCEPT

  typedef double T;
  typedef doubleZmm Zmm;

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
  //mat.normalizerow2(pivotRowPtr);

  T * rowPtr = mat.getRowPtr(0);
   
  Zmm pivotRowVec_head = *(Zmm *)pivotRowPtr;
  pivotRowVec_head[0] = 0;
  Zmm ConstA = pivotRowPtr_0;
  Zmm ConstA_head = pivotRowPtr_0;
  ConstA_head[0] = 1;
  
  for (unsigned rowIndex = 0; rowIndex < nRow; rowIndex += 1) {
    
    if (rowIndex == pivotRow) { rowPtr += mat.nColPadding; continue; }
    T pivotColBackup = rowPtr[pivotCol];
    if (pivotColBackup == 0) { rowPtr += mat.nColPadding; continue; }

    Zmm ConstC = pivotColBackup;
    Zmm matRowVec_head = *(Zmm *)(rowPtr);
    Zmm result = ConstC * pivotRowVec_head + matRowVec_head * ConstA_head;
    matRowVec_head[0] *= pivotRowPtr_0;
    *(Zmm *)(rowPtr) =  result;

    for (unsigned colIndex = ZmmDoubleVecSize; colIndex < nCol; colIndex += ZmmDoubleVecSize) {
      Zmm matRowVec = *(Zmm *)(rowPtr + colIndex);
      Zmm pivotRowVec = *(Zmm *)(pivotRowPtr + colIndex);
      Zmm result = ConstC * pivotRowVec + matRowVec * ConstA;
      *(Zmm *)(rowPtr + colIndex) = result;
    }

    rowPtr[pivotCol] = pivotColBackup * pivotRowPtr_pivotCol;
    //mat.normalizerow2(rowPtr);
    rowPtr += mat.nColPadding;
  }

  if_fetestexcept_return_false_else
  return false;

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

  Zmm pivotRowVec = *(Zmm *)pivotRowPtr;

  if (pivotRowPtr_0 < 0) { 
    #ifdef CHECK_OVERFLOW
    negate<true>(pivotRowVec);
    #else
    negate<false>(pivotRowVec);
    #endif
  }
  //mat.normalizerow2(pivotRowPtr);

  T * rowPtr = mat.getRowPtr(0);
   
  pivotRowVec[0] = 0;
  Zmm ConstA = pivotRowPtr_0;
  ConstA[0] = 1;
  
  for (unsigned rowIndex = 0; rowIndex < nRow; rowIndex += 1) {
    if (rowIndex == pivotRow) { rowPtr += mat.nColPadding; continue; }
    T pivotColBackup = rowPtr[pivotCol];
    if (pivotColBackup == 0) { rowPtr += mat.nColPadding; continue; }

    Zmm ConstC = pivotColBackup;
    Zmm matRowVec = *(Zmm *)(rowPtr);
    #ifdef CHECK_OVERFLOW
    Zmm result = add<true>(mul<true>(ConstC, pivotRowVec), mul<true>(matRowVec, ConstA));
    #else
    Zmm result = ConstC * pivotRowVec + matRowVec * ConstA;
    #endif
    matRowVec[0] *= pivotRowPtr_0;
    *(Zmm *)(rowPtr) =  result;

    rowPtr[pivotCol] = pivotColBackup * pivotRowPtr_pivotCol;
    //mat.normalizerow2(rowPtr);
    rowPtr += mat.nColPadding;
  }

  return true;

}



template<> bool pivot<MPInt>(matrix<MPInt> & mat, unsigned pivotRow, unsigned pivotCol) {

  typedef MPInt T;

  unsigned nRow, nCol;
  nRow = mat.nRow;
  nCol = mat.nCol;
  T * pivotRowPtr = mat.getRowPtr(pivotRow);

  T tmp = pivotRowPtr[0];
  pivotRowPtr[0] = -pivotRowPtr[pivotCol];
  pivotRowPtr[pivotCol] = -tmp;

  if (pivotRowPtr[0] < 0) {
    mat.negateRow(pivotRow);
  }

  //mat.normalizeRowScalar(pivotRow);

  for (unsigned rowIndex = 0; rowIndex < nRow; rowIndex += 1) {
    auto pivotColBackup = mat(rowIndex, pivotCol);

    if ( rowIndex == pivotRow) { continue; }

    T c = mat(rowIndex, pivotCol);
    if (c == 0) { continue;   }

    mat(rowIndex, 0) *= mat(pivotRow, 0);
    for (unsigned col = 1; col < nCol; ++col) {
      if (col == pivotCol){ continue; }

      mat(rowIndex, col) = mat(rowIndex, col) * mat(pivotRow, 0) +
                           mat(rowIndex, pivotCol) * mat(pivotRow, col);
    }

    mat(rowIndex, pivotCol) *= mat(pivotRow, pivotCol);
    //mat.normalizeRowScalar(rowIndex);
  }

  return true;
}



template<> bool pivot<int64_t>(matrix<int64_t> & mat, unsigned pivotRow, unsigned pivotCol) {

  typedef int64_t T;

  unsigned nRow, nCol;
  nRow = mat.nRow;
  nCol = mat.nCol;
  T * pivotRowPtr = mat.getRowPtr(pivotRow);

  T tmp = pivotRowPtr[0];
  pivotRowPtr[0] = -pivotRowPtr[pivotCol];
  pivotRowPtr[pivotCol] = -tmp;

  if (pivotRowPtr[0] < 0) {
    mat.negateRow(pivotRow);
  }

  //mat.normalizeRowScalar(pivotRow);

  for (unsigned rowIndex = 0; rowIndex < nRow; rowIndex += 1) {
    auto pivotColBackup = mat(rowIndex, pivotCol);

    if ( rowIndex == pivotRow) { continue; }

    T c = mat(rowIndex, pivotCol);
    if (c == 0) { continue;   }

    mat(rowIndex, 0) *= mat(pivotRow, 0);
    for (unsigned col = 1; col < nCol; ++col) {
      if (col == pivotCol){ continue; }

      mat(rowIndex, col) = mat(rowIndex, col) * mat(pivotRow, 0) +
                           mat(rowIndex, pivotCol) * mat(pivotRow, col);
    }

    mat(rowIndex, pivotCol) *= mat(pivotRow, pivotCol);
    //mat.normalizeRowScalar(rowIndex);
  }

  return true;
}



// template bool pivot <double>(matrix<double> & tableau, unsigned pivotRow, unsigned pivotCol);
// template bool pivot <float>(matrix<float> & tableau, unsigned pivotRow, unsigned pivotCol);
// template bool pivot <int64_t>(matrix<int64_t> & tableau, unsigned pivotRow, unsigned pivotCol);
// template bool pivot <int16_t>(matrix<int16_t> & tableau, unsigned pivotRow, unsigned pivotCol);
// template bool pivot <MPInt>(matrix<MPInt> & tableau, unsigned pivotRow, unsigned pivotCol);

