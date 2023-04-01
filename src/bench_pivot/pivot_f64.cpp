#include <bench_pivot/pivot.h>

template<> bool pivot<double, _8, ZMM>(matrix<double, ZMM> & mat_src, matrix<double, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  exit(0);
}

template<> bool pivot<double, _16, ZMM>(matrix<double, ZMM> & mat_src, matrix<double, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

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
    __m512 pivotRow_head = -pivotRow_head; 
    __m512 pivotRow_tail = -pivotRow_tail; 
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

template<> bool pivot<double, _24, ZMM>(matrix<double, ZMM> & mat_src, matrix<double, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  exit(0);
  return pivot<double, _16, ZMM>(mat_src, mat_dst, pivotRow, pivotCol);
}

template<> bool pivot<double, _32, ZMM>(matrix<double, ZMM> & mat_src, matrix<double, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  exit(0);
  return pivot<double, _16, ZMM>(mat_src, mat_dst, pivotRow, pivotCol);
}
