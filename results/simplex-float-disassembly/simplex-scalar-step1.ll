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
  br i1 %11, label %12, label %31

12:                                               ; preds = %1
  %13 = and i64 %9, 4294967295
  %14 = add nsw i64 %13, -1
  %15 = and i64 %9, 7
  %16 = icmp ult i64 %14, 7
  br i1 %16, label %19, label %17

17:                                               ; preds = %12
  %18 = sub nsw i64 %13, %15
  br label %32

19:                                               ; preds = %32, %12
  %20 = phi i64 [ 0, %12 ], [ %66, %32 ]
  %21 = icmp eq i64 %15, 0
  br i1 %21, label %31, label %22

22:                                               ; preds = %19, %22
  %23 = phi i64 [ %28, %22 ], [ %20, %19 ]
  %24 = phi i64 [ %29, %22 ], [ 0, %19 ]
  %25 = getelementptr inbounds float, ptr %5, i64 %23
  %26 = load float, ptr %25, align 4, !tbaa !24
  %27 = fdiv float %26, 114514
  store float %27, ptr %25, align 4, !tbaa !24
  %28 = add nuw nsw i64 %23, 1
  %29 = add i64 %24, 1
  %30 = icmp eq i64 %29, %15
  br i1 %30, label %31, label %22, !llvm.loop !35

31:                                               ; preds = %19, %22, %1
  ret void

32:                                               ; preds = %32, %17
  %33 = phi i64 [ 0, %17 ], [ %66, %32 ]
  %34 = phi i64 [ 0, %17 ], [ %67, %32 ]
  %35 = getelementptr inbounds float, ptr %5, i64 %33
  %36 = load float, ptr %35, align 4, !tbaa !24
  %37 = fdiv float %36, 114514
  store float %37, ptr %35, align 4, !tbaa !24
  %38 = or i64 %33, 1
  %39 = getelementptr inbounds float, ptr %5, i64 %38
  %40 = load float, ptr %39, align 4, !tbaa !24
  %41 = fdiv float %40, 114514
  store float %41, ptr %39, align 4, !tbaa !24
  %42 = or i64 %33, 2
  %43 = getelementptr inbounds float, ptr %5, i64 %42
  %44 = load float, ptr %43, align 4, !tbaa !24
  %45 = fdiv float %44, 114514
  store float %45, ptr %43, align 4, !tbaa !24
  %46 = or i64 %33, 3
  %47 = getelementptr inbounds float, ptr %5, i64 %46
  %48 = load float, ptr %47, align 4, !tbaa !24
  %49 = fdiv float %48, 114514
  store float %49, ptr %47, align 4, !tbaa !24
  %50 = or i64 %33, 4
  %51 = getelementptr inbounds float, ptr %5, i64 %50
  %52 = load float, ptr %51, align 4, !tbaa !24
  %53 = fdiv float %52, 114514
  store float %53, ptr %51, align 4, !tbaa !24
  %54 = or i64 %33, 5
  %55 = getelementptr inbounds float, ptr %5, i64 %54
  %56 = load float, ptr %55, align 4, !tbaa !24
  %57 = fdiv float %56, 114514
  store float %57, ptr %55, align 4, !tbaa !24
  %58 = or i64 %33, 6
  %59 = getelementptr inbounds float, ptr %5, i64 %58
  %60 = load float, ptr %59, align 4, !tbaa !24
  %61 = fdiv float %60, 114514
  store float %61, ptr %59, align 4, !tbaa !24
  %62 = or i64 %33, 7
  %63 = getelementptr inbounds float, ptr %5, i64 %62
  %64 = load float, ptr %63, align 4, !tbaa !24
  %65 = fdiv float %64, 114514
  store float %65, ptr %63, align 4, !tbaa !24
  %66 = add nuw nsw i64 %33, 8
  %67 = add i64 %34, 8
  %68 = icmp eq i64 %67, %18
  br i1 %68, label %19, label %32, !llvm.loop !37
}
