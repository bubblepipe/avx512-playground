#include <bench_pivot/pivot.h>

// float YMM vector size is 8
// 8 -> 1 vector for a row
// 16 -> 2 vector for a row
// 24, 32 -> column loop

template<> bool pivot<float, _8, YMM>(matrix<float, YMM> & mat_src, matrix<float, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {

  typedef float T;
  typedef floatYmm Vec;
  auto nColPadding = YmmFloatVecSize; //mat_src.nColPadding;

  #include <bench_pivot/pivot_floating_row_vec_1>

}

template<> bool pivot<float, _16, YMM>(matrix<float, YMM> & mat_src, matrix<float, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  typedef float T;
  typedef floatYmm Vec;
  auto const step_size = YmmFloatVecSize;
  auto const nColPadding = mat_src.nColPadding;
  auto const nCol = mat_src.nCol;

  #include <bench_pivot/pivot_floating_row_vec_2>
}

template<> bool pivot<float, _24, YMM>(matrix<float, YMM> & mat_src, matrix<float, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
  typedef float T;
  typedef floatYmm Vec;
  auto const step_size = YmmFloatVecSize;
  auto const nColPadding = 24;
  auto const nCol = 24;
  
  #include <bench_pivot/pivot_floating_row_vec_loop>
}

// template<> bool pivot<float, _32, YMM>(matrix<float, YMM> & mat_src, matrix<float, YMM> & mat_dst, unsigned pivotRow, unsigned pivotCol) {
//   // FECLEAREXCEPT

//   typedef float T;
//   typedef floatYmm Vec;
//   auto const step_size = YmmFloatVecSize;
//   auto const nColPadding = 32;
//   auto const nCol = 32;
  
//   #include <bench_pivot/pivot_floating_row_vec_loop>
// }

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
      
  *(floatYmm *)(dstRowPtr + 0) = *(floatYmm *)(srcRowPtr + 0);
  *(floatYmm *)(dstRowPtr + YmmFloatVecSize) = *(floatYmm *)(srcRowPtr + YmmFloatVecSize);      srcRowPtr += nColPadding; 
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