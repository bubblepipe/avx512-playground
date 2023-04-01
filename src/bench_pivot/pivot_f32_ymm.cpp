#include <bench_pivot/pivot.h>

template<> bool pivot<float, _32, YMM>(matrix<float, YMM> & mat_src, matrix<float, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  // FECLEAREXCEPT

  typedef float T;
  typedef floatYmm Ymm;
  auto const nColPadding = mat_src.nColPadding;
  auto const nCol = mat_src.nCol;

  T * srcPivotRowPtr = mat_src.getRowPtr(pivotRow);
  T * dstPivotRowPtr = mat_dst.getRowPtr(pivotRow);

  // Ymm pivotRow_head = *(Ymm *)srcPivotRowPtr;
  // T tmp = pivotRow_head[0];

  T tmp = srcPivotRowPtr[0];
  for (auto i = 0; i < nCol; i += YmmFloatVecSize) {
    *(Ymm *)(dstPivotRowPtr + i) = *(Ymm *)(srcPivotRowPtr + i);
  }
  dstPivotRowPtr[0] = -dstPivotRowPtr[pivotCol];
  dstPivotRowPtr[pivotCol] = -tmp;

  auto pivotRow_pivotCol = -tmp;
  auto pivotRow_0 = dstPivotRowPtr[0];

  Ymm pivotRow_head = *(Ymm *)dstPivotRowPtr;

  if (pivotRow_0 < 0) {
    // negate row TODO:
  }  
  //mat.normalizerow2(pivotRowPtr);

  T * srcRowPtr = srcPivotRowPtr + nColPadding; 
  T * dstRowPtr = dstPivotRowPtr + nColPadding; 
   
  pivotRow_head[0] = 0;
  Ymm ConstA = pivotRow_0;
  Ymm ConstA_head = pivotRow_0;
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

    Ymm ConstC = pivotColBackup;
    Ymm rowVec_head = *(Ymm *)(srcRowPtr);
    Ymm result_head = ConstC * pivotRow_head + rowVec_head * ConstA_head;
    rowVec_head[0] *= pivotRow_0;
    *(Ymm *)(dstRowPtr) =  result_head;

    for (auto colIndex = YmmFloatVecSize; colIndex < nCol; colIndex += YmmFloatVecSize) {
      Ymm rowVec_tail = *(Ymm *)(srcRowPtr + colIndex);
      Ymm pivotRow_tail = *(Ymm *)(dstPivotRowPtr + colIndex);
      Ymm result_tail = ConstC * pivotRow_tail + rowVec_tail * ConstA;
      *(Ymm *)(dstRowPtr + colIndex) = result_tail;
    }

    dstRowPtr[pivotCol] = pivotColBackup * pivotRow_pivotCol;
    //mat.normalizerow2(rowPtr);
    srcRowPtr += nColPadding;
    dstRowPtr += nColPadding;
  }

  if_fetestexcept_return_false_else
  return true;
}

template<> bool pivot<float, _24, YMM>(matrix<float, YMM> & mat_src, matrix<float, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<float, _32, YMM>(mat_src, mat_dst, pivotRow, pivotCol);
}

template<> bool pivot<float, _16, YMM>(matrix<float, YMM> & mat_src, matrix<float, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<float, _32, YMM>(mat_src, mat_dst, pivotRow, pivotCol);
}

template<> bool pivot<float, _8, YMM>(matrix<float, YMM> & mat_src, matrix<float, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  // FECLEAREXCEPT

  typedef float T;
  typedef floatYmm Ymm;
  auto nColPadding = YmmFloatVecSize; //mat_src.nColPadding;

  T * srcPivotRowPtr = mat_src.getRowPtr(pivotRow);
  T * dstPivotRowPtr = mat_dst.getRowPtr(pivotRow);
  Ymm pivotRowVec = *(Ymm *)srcPivotRowPtr;
  
  T tmp = pivotRowVec[0];
  pivotRowVec[0] = -pivotRowVec[pivotCol];
  pivotRowVec[pivotCol] = -tmp;

  auto pivotRow_pivotCol = -tmp;
  auto pivotRow_0 = pivotRowVec[0];

  if (pivotRow_0 < 0) {  // negate pivot row
    pivotRowVec = -pivotRowVec;
  }
  *(Ymm *)(dstPivotRowPtr) = pivotRowVec;

  T * srcRowPtr = srcPivotRowPtr + YmmFloatVecSize; // row[0] is pivot row
  T * dstRowPtr = dstPivotRowPtr + YmmFloatVecSize; // row[1] is ...

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
    matRowVec[0] *= pivotRow_0; // TODO: https://grosser.zulipchat.com/#narrow/stream/240241-Presburger-.26-Polyhedral/topic/vectorized.20pivot/near/339397953
    Ymm result = ConstC * pivotRowVec + matRowVec * ConstA;
    *(Ymm *)(dstRowPtr) = result;

    dstRowPtr[pivotCol] = pivotColBackup * pivotRow_pivotCol;
    //mat.normalizerow2(rowPtr);
    srcRowPtr += nColPadding;
    dstRowPtr += nColPadding;
  }

  if_fetestexcept_return_false_else
  return true;

}
