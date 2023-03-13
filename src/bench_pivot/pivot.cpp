#include <bench_pivot/pivot.h>
#include <bench_pivot/MPInt.h>
#include <utils/int16_utils.cpp>

// #include <utils/cfenv_local.cpp>

#define START_TIMER     unsigned int dummy;  \
    unsigned long t1 = __rdtscp(&dummy);
#define STOP_TIMER     unsigned long t2 = __rdtscp(&dummy); \
    printf("Time: %ld\n",  t2 - t1); \
    exit(0);

#ifdef CHECK_OVERFLOW
  #define FECLEAREXCEPT feclearexcept_local_sse (FE_INEXACT | FE_INVALID);
  #define if_fetestexcept_return_false_else \
    if (fetestexcept_local_sse(FE_INEXACT | FE_INVALID)) { \
      return false; \
    } else  
#else 
  #define FECLEAREXCEPT 
  #define if_fetestexcept_return_false_else 
#endif

template <typename T>
bool pivot(matrix<T> & mat_src, matrix<T> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return false;
}

template<> bool pivot<float>(matrix<float> & mat_src, matrix<float> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  // FECLEAREXCEPT

  typedef float T;
  typedef floatZmm Zmm;
  auto nColPadding = mat_src.nColPadding;

  T * srcPivotRowPtr = mat_src.getRowPtr(pivotRow);
  T * dstPivotRowPtr = mat_dst.getRowPtr(pivotRow);
  Zmm pivotRowVec = *(Zmm *)srcPivotRowPtr;
  
  T tmp = pivotRowVec[0];
  pivotRowVec[0] = -pivotRowVec[pivotCol];
  pivotRowVec[pivotCol] = -tmp;

  auto pivotRow_pivotCol = -tmp;
  auto pivotRow_0 = pivotRowVec[0];

  if (pivotRow_0 < 0) {  // negate pivot row
    pivotRowVec = _mm512_xor_ps(pivotRowVec, _mm512_set1_ps(-0.0));
  }
  *(Zmm *)(dstPivotRowPtr) = pivotRowVec;

  T * srcRowPtr = srcPivotRowPtr + ZmmFloatVecSize; // row[0] is pivot row
  T * dstRowPtr = dstPivotRowPtr + ZmmFloatVecSize; // row[1] is ...

  pivotRowVec[0] = 0;
  Zmm ConstA = pivotRow_0;
  ConstA[0] = 1;
  
  #ifdef UNROLL
  #pragma clang loop unroll(full)
  #endif
  for (unsigned rowIndex = 1; rowIndex < NROW; rowIndex += 1) {
    T pivotColBackup = srcRowPtr[pivotCol];

    #ifdef rowPtr_pivotCol_eq_0
    if (pivotColBackup == 0) { // skip calculation, cp src dst
      Zmm matRowVec = *(Zmm *)(srcRowPtr);
      *(Zmm *)(dstRowPtr) = matRowVec;
      srcRowPtr += nColPadding; 
      dstRowPtr += nColPadding; 
      continue; 
    }
    #endif
    
    Zmm ConstC = pivotColBackup;
    Zmm matRowVec = *(Zmm *)(srcRowPtr);
    matRowVec[0] *= pivotRow_0; // TODO: https://grosser.zulipchat.com/#narrow/stream/240241-Presburger-.26-Polyhedral/topic/vectorized.20pivot/near/339397953
    Zmm result = ConstC * pivotRowVec + matRowVec * ConstA;
    *(Zmm *)(dstRowPtr) = result;

    dstRowPtr[pivotCol] = pivotColBackup * pivotRow_pivotCol;
    //mat.normalizerow2(rowPtr);
    srcRowPtr += ZmmFloatVecSize;
    dstRowPtr += ZmmFloatVecSize;
  }

  if_fetestexcept_return_false_else
  return true;

}


template<> bool pivot<double>(matrix<double> & mat, matrix<double> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  // FECLEAREXCEPT

  typedef double T;
  typedef doubleZmm Zmm;

  // auto mat_nCol = ZmmDoubleVecSize;

  // unsigned nRow, nCol;
  // nRow = mat.nRow;
  // nCol = mat.nCol;
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

  T * rowPtr = mat.getRowPtr(1); // first row[0] is pivot row
   
  Zmm pivotRowVec_head = *(Zmm *)pivotRowPtr;
  pivotRowVec_head[0] = 0;
  Zmm ConstA = pivotRowPtr_0;
  Zmm ConstA_head = pivotRowPtr_0;
  ConstA_head[0] = 1;
  
  #ifdef UNROLL
  #pragma clang loop unroll(full)
  #endif
  for (unsigned rowIndex = 1; rowIndex < NROW; rowIndex += 1) {
    
    T pivotColBackup = rowPtr[pivotCol];
    
    #ifdef rowPtr_pivotCol_eq_0
    if (pivotColBackup == 0) { rowPtr += mat.nColPadding; continue; }
    #endif

    Zmm ConstC = pivotColBackup;
    Zmm matRowVec_head = *(Zmm *)(rowPtr);
    Zmm result = ConstC * pivotRowVec_head + matRowVec_head * ConstA_head;
    matRowVec_head[0] *= pivotRowPtr_0;
    *(Zmm *)(rowPtr) =  result;

    for (unsigned colIndex = ZmmDoubleVecSize; colIndex < mat.nColPadding; colIndex += ZmmDoubleVecSize) {
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
  return true;

}

template<> bool pivot<int16_t>(matrix<int16_t> & mat_src, matrix<int16_t> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  bool overflow_accum = false;

  typedef int16_t T;
  typedef int16Zmm Zmm;
  auto nColPadding = mat_src.nColPadding;

  T * srcPivotRowPtr = mat_src.getRowPtr(pivotRow);
  T * dstPivotRowPtr = mat_dst.getRowPtr(pivotRow);
  Zmm pivotRowVec = *(Zmm *)srcPivotRowPtr;

  T tmp = pivotRowVec[0];
  T tmq = pivotRowVec[pivotCol];

  #ifdef CHECK_OVERFLOW
  overflow_accum |=  std::numeric_limits<int16_t>::min() == tmq;
  overflow_accum |= std::numeric_limits<int16_t>::min() == tmp;
  #endif

  pivotRowVec[0] = -tmq;  
  pivotRowVec[pivotCol] = -tmp; 
  auto pivotRow_pivotCol = -tmp; 
  auto pivotRow_0 = pivotRowVec[0];

  if (pivotRow_0 < 0) { 
    #ifdef CHECK_OVERFLOW
    negate<true>(pivotRowVec, overflow_accum);
    #else
    negate<false>(pivotRowVec, overflow_accum);
    #endif
  }
  *(Zmm *)(dstPivotRowPtr) = pivotRowVec;

  //mat.normalizerow2(pivotRowPtr);

  T * srcRowPtr = srcPivotRowPtr + ZmmInt16VecSize; // row[0] is pivot row
  T * dstRowPtr = dstPivotRowPtr + ZmmInt16VecSize; // row[1] is ...

  pivotRowVec[0] = 0; 
  Zmm ConstA = pivotRow_0; 
  ConstA[0] = 1; 
  
  #ifdef UNROLL
  #pragma clang loop unroll(full)
  #endif
  for (unsigned rowIndex = 1; rowIndex < NROW; rowIndex += 1) {
    T pivotColBackup = srcRowPtr[pivotCol];

    #ifdef rowPtr_pivotCol_eq_0
    if (pivotColBackup == 0) { // skip calculation, cp src dst
      Zmm matRowVec = *(Zmm *)(srcRowPtr);
      *(Zmm *)(dstRowPtr) = matRowVec;
      srcRowPtr += nColPadding; 
      dstRowPtr += nColPadding; 
      continue; 
    }      
    #endif

    Zmm ConstC = pivotColBackup;
    Zmm matRowVec = *(Zmm *)(srcRowPtr);
    #ifdef CHECK_OVERFLOW
    auto mul0 = mul<true>(ConstC, pivotRowVec, overflow_accum);
    auto mul1 = mul<true>(matRowVec, ConstA, overflow_accum);
    Zmm result = add<true>(mul0,mul1, overflow_accum);
    #else
    Zmm result = ConstC * pivotRowVec + matRowVec * ConstA;
    #endif
    *(Zmm *)(dstRowPtr) =  result;

    int16_t lo = pivotColBackup * pivotRow_pivotCol; 
    dstRowPtr[pivotCol] = lo;
    #ifdef CHECK_OVERFLOW
    int32_t hi_lo = pivotColBackup * pivotRow_pivotCol;
    overflow_accum |= lo != hi_lo;
    #endif

    //mat.normalizerow2(rowPtr);
    srcRowPtr += ZmmInt16VecSize;
    dstRowPtr += ZmmInt16VecSize;
  }

  return !overflow_accum;
}



template<> bool pivot<MPInt>(matrix<MPInt> & mat, matrix<MPInt> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

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

  for (unsigned rowIndex = 0; rowIndex < NROW; rowIndex += 1) {
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



template<> bool pivot<int64_t>(matrix<int64_t> & mat, matrix<int64_t> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

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

  for (unsigned rowIndex = 0; rowIndex < NROW; rowIndex += 1) {
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
template bool pivot <uint64_t>(matrix<uint64_t> & mat, matrix<uint64_t> & mat_dst, unsigned pivotRow, unsigned pivotCol);

