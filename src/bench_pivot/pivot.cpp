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

template <typename T, MatColSize matColSize>
bool pivot(matrix<T> & mat_src, matrix<T> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return false;
}


template<> bool pivot<float, _16>(matrix<float> & mat_src, matrix<float> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  // FECLEAREXCEPT

  typedef float T;
  typedef floatZmm Zmm;
  auto nColPadding = ZmmFloatVecSize; //mat_src.nColPadding;

  T * srcPivotRowPtr = mat_src.getRowPtr(pivotRow);
  T * dstPivotRowPtr = mat_dst.getRowPtr(pivotRow);
  Zmm pivotRowVec = *(Zmm *)srcPivotRowPtr;
  
  T tmp = pivotRowVec[0];
  pivotRowVec[0] = -pivotRowVec[pivotCol];
  pivotRowVec[pivotCol] = -tmp;

  auto pivotRow_pivotCol = -tmp;
  auto pivotRow_0 = pivotRowVec[0];

  if (pivotRow_0 < 0) {  // negate pivot row
    pivotRowVec = -pivotRowVec; _mm512_xor_ps(pivotRowVec, _mm512_set1_ps(-0.0));
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

    #ifdef SKIP_rowPtr_pivotCol_eq_0
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
    srcRowPtr += nColPadding;
    dstRowPtr += nColPadding;
  }

  if_fetestexcept_return_false_else
  return true;

}

template<> bool pivot<float, _8>(matrix<float> & mat_src, matrix<float> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<float, _16>(mat_src, mat_dst, pivotRow, pivotCol);
}

inline __attribute__((always_inline)) void copy_row(double * dstRowPtr, double * srcRowPtr , unsigned nCol){
  *(doubleZmm *)(dstRowPtr + 0) = *(doubleZmm *)(srcRowPtr + 0);
  *(doubleZmm *)(dstRowPtr + ZmmDoubleVecSize) = *(doubleZmm *)(srcRowPtr + ZmmDoubleVecSize);
}

template<> bool pivot<double, _16>(matrix<double> & mat_src, matrix<double> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  // FECLEAREXCEPT

  typedef double T;
  typedef doubleZmm Zmm;
  auto const nColPadding = mat_src.nColPadding;
  auto const nCol = mat_src.nCol;

  T * srcPivotRowPtr = mat_src.getRowPtr(pivotRow);
  T * dstPivotRowPtr = mat_dst.getRowPtr(pivotRow);

  Zmm pivotRow_head = *(Zmm *)srcPivotRowPtr;
  Zmm pivotRow_tail = *(Zmm *)(srcPivotRowPtr + ZmmDoubleVecSize);

  T tmp = pivotRow_head[0];
  if (pivotCol < ZmmDoubleVecSize) { // head
    pivotRow_head[0] = -pivotRow_head[pivotCol];
    pivotRow_head[pivotCol] = -tmp;
  } else { // pivotCol in tail
    pivotRow_head[0] = -pivotRow_tail[pivotCol];
    pivotRow_tail[pivotCol] = -tmp;
  }

  auto pivotRow_pivotCol = -tmp;
  auto pivotRow_0 = pivotRow_head[0];

  if (pivotRow_0 < 0) {
    // mat_dst.negateRowVectorized(pivotRow);
    __m512 pivotRow_head = -pivotRow_head; // _mm512_xor_ps(pivotRow_head, _mm512_set1_pd(-0.0)); // from https://stackoverflow.com/questions/20083997/how-to-negate-change-sign-of-the-floating-point-elements-in-a-m128-type-vari
    __m512 pivotRow_tail = -pivotRow_head; // _mm512_xor_ps(pivotRow_tail, _mm512_set1_pd(-0.0)); // from https://stackoverflow.com/questions/20083997/how-to-negate-change-sign-of-the-floating-point-elements-in-a-m128-type-vari
  }  
  //mat.normalizerow2(pivotRowPtr);
  *(Zmm *)dstPivotRowPtr = pivotRow_head;
  *(Zmm *)(dstPivotRowPtr + ZmmDoubleVecSize) = pivotRow_tail;
  
  T * srcRowPtr = srcPivotRowPtr + nColPadding; 
  T * dstRowPtr = dstPivotRowPtr + nColPadding; 
   
  pivotRow_head[0] = 0;
  Zmm ConstA = pivotRow_0;
  Zmm ConstA_head = pivotRow_0;
  ConstA_head[0] = 1;
  
  #ifdef UNROLL
  #pragma clang loop unroll(full)
  #endif
  
  for (unsigned rowIndex = 1; rowIndex < NROW; rowIndex += 1) {
    
    T pivotColBackup = srcRowPtr[pivotCol];
    
    #ifdef SKIP_rowPtr_pivotCol_eq_0
    if (pivotColBackup == 0) { 
      copy_row(dstRowPtr, srcRowPtr, nColPadding);
      srcRowPtr += nColPadding; 
      dstRowPtr += nColPadding;
      continue; 
    }
    #endif

    Zmm ConstC = pivotColBackup;
    Zmm rowVec_head = *(Zmm *)(srcRowPtr);
    Zmm result_head = ConstC * pivotRow_head + rowVec_head * ConstA_head;
    rowVec_head[0] *= pivotRow_0;
    *(Zmm *)(dstRowPtr) =  result_head;

    auto colIndex = ZmmDoubleVecSize;
    Zmm rowVec_tail = *(Zmm *)(srcRowPtr + colIndex);
    Zmm pivotRow_tail = *(Zmm *)(dstPivotRowPtr + colIndex);
    Zmm result_tail = ConstC * pivotRow_tail + rowVec_tail * ConstA;
    *(Zmm *)(dstRowPtr + colIndex) = result_tail;

    dstRowPtr[pivotCol] = pivotColBackup * pivotRow_pivotCol;
    //mat.normalizerow2(rowPtr);
    srcRowPtr += nColPadding;
    dstRowPtr += nColPadding;
  }

  if_fetestexcept_return_false_else
  return true;

}

template<> bool pivot<int16_t, _32>(matrix<int16_t> & mat_src, matrix<int16_t> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  bool overflow_accum = false;

  typedef int16_t T;
  typedef int16Zmm Zmm;
  auto nColPadding = ZmmInt16VecSize; // mat_src.nColPadding;

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

    #ifdef SKIP_rowPtr_pivotCol_eq_0
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
    srcRowPtr += nColPadding;
    dstRowPtr += nColPadding;
  }

  return !overflow_accum;
}

template<> bool pivot<int16_t, _8>(matrix<int16_t> & mat_src, matrix<int16_t> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<int16_t, _32>(mat_src, mat_dst, pivotRow, pivotCol);
}
template<> bool pivot<int16_t, _16>(matrix<int16_t> & mat_src, matrix<int16_t> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<int16_t, _32>(mat_src, mat_dst, pivotRow, pivotCol);
}
template<> bool pivot<int16_t, _24>(matrix<int16_t> & mat_src, matrix<int16_t> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<int16_t, _32>(mat_src, mat_dst, pivotRow, pivotCol);
}

template<> bool pivot<MPInt, _0>(matrix<MPInt> & mat, matrix<MPInt> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

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



template<> bool pivot<int64_t, _0>(matrix<int64_t> & mat, matrix<int64_t> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

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
// template bool pivot <uint64_t>(matrix<uint64_t> & mat, matrix<uint64_t> & mat_dst, unsigned pivotRow, unsigned pivotCol);

