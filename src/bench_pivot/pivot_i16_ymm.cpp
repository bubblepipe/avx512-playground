#include <bench_pivot/pivot.h>
#include <utils/int16_utils.cpp>

template<> bool pivot<int16_t, _32, YMM>(matrix<int16_t, YMM> & mat_src, matrix<int16_t, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  bool overflow_accum = false;

  typedef int16_t T;
  typedef int16Ymm Ymm;
  auto nColPadding = YmmInt16VecSize; // mat_src.nColPadding;

  T * srcPivotRowPtr = mat_src.getRowPtr(pivotRow);
  T * dstPivotRowPtr = mat_dst.getRowPtr(pivotRow);
  Ymm pivotRowVec = *(Ymm *)srcPivotRowPtr;

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
  *(Ymm *)(dstPivotRowPtr) = pivotRowVec;

  //mat.normalizerow2(pivotRowPtr);

  T * srcRowPtr = srcPivotRowPtr + YmmInt16VecSize; // row[0] is pivot row
  T * dstRowPtr = dstPivotRowPtr + YmmInt16VecSize; // row[1] is ...

  pivotRowVec[0] = 0; 
  Ymm ConstA = pivotRow_0; 
  ConstA[0] = 1; 
  
  #ifdef UNROLL
  #pragma clang loop unroll(full)
  #endif
  for (unsigned rowIndex = 1; rowIndex < NROW; rowIndex += 1) {
    T pivotColBackup = srcRowPtr[pivotCol];

    #ifdef SKIP_rowPtr_pivotCol_eq_0
    if (pivotColBackup == 0) { // skip calculation, cp src dst
      Ymm matRowVec = *(Ymm *)(srcRowPtr);
      *(Ymm *)(dstRowPtr) = matRowVec;
      srcRowPtr += nColPadding; 
      dstRowPtr += nColPadding; 
      continue; 
    }      
    #endif

    Ymm ConstC = pivotColBackup;
    Ymm matRowVec = *(Ymm *)(srcRowPtr);
    #ifdef CHECK_OVERFLOW
    auto mul0 = mul<true>(ConstC, pivotRowVec, overflow_accum);
    auto mul1 = mul<true>(matRowVec, ConstA, overflow_accum);
    Ymm result = add<true>(mul0,mul1, overflow_accum);
    #else
    Ymm result = ConstC * pivotRowVec + matRowVec * ConstA;
    #endif
    *(Ymm *)(dstRowPtr) =  result;

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

template<> bool pivot<int16_t, _8, YMM>(matrix<int16_t, YMM> & mat_src, matrix<int16_t, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<int16_t, _32, YMM>(mat_src, mat_dst, pivotRow, pivotCol);
}
template<> bool pivot<int16_t, _16, YMM>(matrix<int16_t, YMM> & mat_src, matrix<int16_t, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<int16_t, _32, YMM>(mat_src, mat_dst, pivotRow, pivotCol);
}
template<> bool pivot<int16_t, _24, YMM>(matrix<int16_t, YMM> & mat_src, matrix<int16_t, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<int16_t, _32, YMM>(mat_src, mat_dst, pivotRow, pivotCol);
}
