; Function Attrs: mustprogress nofree norecurse nosync nounwind uwtable
define dso_local void @_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE(ptr nocapture noundef nonnull readonly align 8 dereferenceable(24) %0) local_unnamed_addr #5 {
  %2 = load ptr, ptr %0, align 8, !tbaa !10
  %3 = getelementptr inbounds %"struct.std::_Vector_base<float, std::allocator<float>>::_Vector_impl_data", ptr %2, i64 0, i32 1
  %4 = load ptr, ptr %3, align 8, !tbaa !11
  %5 = load ptr, ptr %2, align 8, !tbaa !13
  %6 = ptrtoint ptr %4 to i64
  %7 = ptrtoint ptr %5 to i64
  %8 = sub i64 %6, %7
  %9 = lshr exact i64 %8, 2
  %10 = trunc i64 %9 to i32
  %11 = icmp sgt i32 %10, 0
  br i1 %11, label %12, label %38

12:                                               ; preds = %1
  %13 = and i64 %9, 4294967295
  %14 = icmp ult i64 %13, 32
  br i1 %14, label %36, label %15

15:                                               ; preds = %12
  %16 = and i64 %9, 31
  %17 = sub nsw i64 %13, %16
  br label %18

18:                                               ; preds = %18, %15
  %19 = phi i64 [ 0, %15 ], [ %32, %18 ]
  %20 = getelementptr inbounds float, ptr %5, i64 %19
  %21 = load <8 x float>, ptr %20, align 4, !tbaa !24
  %22 = getelementptr inbounds float, ptr %20, i64 8
  %23 = load <8 x float>, ptr %22, align 4, !tbaa !24
  %24 = getelementptr inbounds float, ptr %20, i64 16
  %25 = load <8 x float>, ptr %24, align 4, !tbaa !24
  %26 = getelementptr inbounds float, ptr %20, i64 24
  %27 = load <8 x float>, ptr %26, align 4, !tbaa !24
  %28 = fdiv <8 x float> %21, <float 114514, float 114514, float 114514, float 114514, float 114514, float 114514, float 114514, float 114514>
  %29 = fdiv <8 x float> %23, <float 114514, float 114514, float 114514, float 114514, float 114514, float 114514, float 114514, float 114514>
  %30 = fdiv <8 x float> %25, <float 114514, float 114514, float 114514, float 114514, float 114514, float 114514, float 114514, float 114514>
  %31 = fdiv <8 x float> %27, <float 114514, float 114514, float 114514, float 114514, float 114514, float 114514, float 114514, float 114514>
  store <8 x float> %28, ptr %20, align 4, !tbaa !24
  store <8 x float> %29, ptr %22, align 4, !tbaa !24
  store <8 x float> %30, ptr %24, align 4, !tbaa !24
  store <8 x float> %31, ptr %26, align 4, !tbaa !24
  %32 = add nuw i64 %19, 32
  %33 = icmp eq i64 %32, %17
  br i1 %33, label %34, label %18, !llvm.loop !35

34:                                               ; preds = %18
  %35 = icmp eq i64 %16, 0
  br i1 %35, label %38, label %36

36:                                               ; preds = %12, %34
  %37 = phi i64 [ 0, %12 ], [ %17, %34 ]
  br label %39

38:                                               ; preds = %39, %34, %1
  ret void

39:                                               ; preds = %36, %39
  %40 = phi i64 [ %44, %39 ], [ %37, %36 ]
  %41 = getelementptr inbounds float, ptr %5, i64 %40
  %42 = load float, ptr %41, align 4, !tbaa !24
  %43 = fdiv float %42, 114514
  store float %43, ptr %41, align 4, !tbaa !24
  %44 = add nuw nsw i64 %40, 1
  %45 = icmp eq i64 %44, %13
  br i1 %45, label %38, label %39, !llvm.loop !37
}
