#include <bench_pivot/pivot.h>
#include <utils/int16_utils.cpp>

// int16 YMM vector size is 8
// 8 -> native
// 16, 24, 32 -> column loop

template<> bool pivot<int16_t, _8, XMM>(matrix<int16_t, XMM> & mat_src, matrix<int16_t, XMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  bool overflow_accum = false;

  typedef int16_t T;
  typedef int16Xmm Xmm;
  auto nColPadding = XmmInt16VecSize; // mat_src.nColPadding;

  T * srcPivotRowPtr = mat_src.getRowPtr(pivotRow);
  T * dstPivotRowPtr = mat_dst.getRowPtr(pivotRow);
  Xmm pivotRowVec = *(Xmm *)srcPivotRowPtr;

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
  *(Xmm *)(dstPivotRowPtr) = pivotRowVec;

  //mat.normalizerow2(pivotRowPtr);

  T * srcRowPtr = srcPivotRowPtr + XmmInt16VecSize; // row[0] is pivot row
  T * dstRowPtr = dstPivotRowPtr + XmmInt16VecSize; // row[1] is ...

  pivotRowVec[0] = 0; 
  Xmm ConstA = pivotRow_0; 
  ConstA[0] = 1; 
  
  #ifdef UNROLL
  #pragma clang loop unroll(full)
  #endif
  for (unsigned rowIndex = 1; rowIndex < NROW; rowIndex += 1) {
    T pivotColBackup = srcRowPtr[pivotCol];

    #ifdef SKIP_rowPtr_pivotCol_eq_0
    if (pivotColBackup == 0) { // skip calculation, cp src dst
      Xmm matRowVec = *(Xmm *)(srcRowPtr);
      *(Xmm *)(dstRowPtr) = matRowVec;
      srcRowPtr += nColPadding; 
      dstRowPtr += nColPadding; 
      continue; 
    }      
    #endif

    Xmm ConstC = pivotColBackup;
    Xmm matRowVec = *(Xmm *)(srcRowPtr);
    #ifdef CHECK_OVERFLOW
    auto mul0 = mul<true>(ConstC, pivotRowVec, overflow_accum);
    auto mul1 = mul<true>(matRowVec, ConstA, overflow_accum);
    Xmm result = add<true>(mul0,mul1, overflow_accum);
    #else
    Xmm result = ConstC * pivotRowVec + matRowVec * ConstA;
    #endif
    *(Xmm *)(dstRowPtr) =  result;

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

template<> bool pivot<int16_t, _32, XMM>(matrix<int16_t, XMM> & mat_src, matrix<int16_t, XMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return false;
  exit(0);
  // return pivot<int16_t, _32, XMM>(mat_src, mat_dst, pivotRow, pivotCol);
}

template<> bool pivot<int16_t, _16, XMM>(matrix<int16_t, XMM> & mat_src, matrix<int16_t, XMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return false;
  exit(0);
  // return pivot<int16_t, _32, XMM>(mat_src, mat_dst, pivotRow, pivotCol);
}

template<> bool pivot<int16_t, _24, XMM>(matrix<int16_t, XMM> & mat_src, matrix<int16_t, XMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return false;
  exit(0);
  // return pivot<int16_t, _32, XMM>(mat_src, mat_dst, pivotRow, pivotCol);
}
