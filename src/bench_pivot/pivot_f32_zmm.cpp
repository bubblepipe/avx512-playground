#include <bench_pivot/pivot.h>

template<> bool pivot<float, _16, ZMM>(matrix<float, ZMM> & mat_src, matrix<float, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

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
    pivotRowVec = -pivotRowVec;
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

template<> bool pivot<float, _8, ZMM>(matrix<float, ZMM> & mat_src, matrix<float, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<float, _16, ZMM>(mat_src, mat_dst, pivotRow, pivotCol);
}

template<> bool pivot<float, _32, ZMM>(matrix<float, ZMM> & mat_src, matrix<float, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  // FECLEAREXCEPT

  typedef float T;
  typedef floatZmm Zmm;
  auto const nColPadding = mat_src.nColPadding;
  auto const nCol = mat_src.nCol;

  T * srcPivotRowPtr = mat_src.getRowPtr(pivotRow);
  T * dstPivotRowPtr = mat_dst.getRowPtr(pivotRow);

  Zmm pivotRow_head = *(Zmm *)srcPivotRowPtr;
  Zmm pivotRow_tail = *(Zmm *)(srcPivotRowPtr + ZmmFloatVecSize);

  T tmp = pivotRow_head[0];
  if (pivotCol < ZmmFloatVecSize) { // head
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
    __m512 pivotRow_tail = -pivotRow_tail; // _mm512_xor_ps(pivotRow_tail, _mm512_set1_pd(-0.0)); // from https://stackoverflow.com/questions/20083997/how-to-negate-change-sign-of-the-floating-point-elements-in-a-m128-type-vari
  }  
  //mat.normalizerow2(pivotRowPtr);
  *(Zmm *)dstPivotRowPtr = pivotRow_head;
  *(Zmm *)(dstPivotRowPtr + ZmmFloatVecSize) = pivotRow_tail;
  
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

    auto colIndex = ZmmFloatVecSize;
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

template<> bool pivot<float, _24, ZMM>(matrix<float, ZMM> & mat_src, matrix<float, ZMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  return pivot<float, _32, ZMM>(mat_src, mat_dst, pivotRow, pivotCol);
}
