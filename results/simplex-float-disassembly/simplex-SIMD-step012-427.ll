427:                                              ; preds = %___
  %___ = insertelement <8 x float> poison, float %___, i64 0
  %___ = shufflevector <8 x float> %___, <8 x float> poison, <8 x i32> zeroinitializer
  %___ = insertelement <8 x float> poison, float %___, i64 0
  %___ = shufflevector <8 x float> %___, <8 x float> poison, <8 x i32> zeroinitializer
  %___ = insertelement <8 x float> poison, float %___, i64 0
  %___ = shufflevector <8 x float> %___, <8 x float> poison, <8 x i32> zeroinitializer
  %___ = insertelement <8 x float> poison, float %___, i64 0
  %___ = shufflevector <8 x float> %___, <8 x float> poison, <8 x i32> zeroinitializer
  br label %___

436:                                              ; preds = %___, %___
  %___ = phi i64 [ 0, %___ ], [ %___, %___ ]
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load <8 x float>, ptr %___, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %___ = getelementptr inbounds float, ptr %___, i64 8
  %___ = load <8 x float>, ptr %___, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %___ = getelementptr inbounds float, ptr %___, i64 16
  %___ = load <8 x float>, ptr %___, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %___ = getelementptr inbounds float, ptr %___, i64 24
  %___ = load <8 x float>, ptr %___, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load <8 x float>, ptr %___, align 4, !tbaa !24, !alias.scope !46
  %___ = getelementptr inbounds float, ptr %___, i64 8
  %___ = load <8 x float>, ptr %___, align 4, !tbaa !24, !alias.scope !46
  %___ = getelementptr inbounds float, ptr %___, i64 16
  %___ = load <8 x float>, ptr %___, align 4, !tbaa !24, !alias.scope !46
  %___ = getelementptr inbounds float, ptr %___, i64 24
  %___ = load <8 x float>, ptr %___, align 4, !tbaa !24, !alias.scope !46
  %___ = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %___, <8 x float> %___, <8 x float> %___)
  %___ = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %___, <8 x float> %___, <8 x float> %___)
  %___ = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %___, <8 x float> %___, <8 x float> %___)
  %___ = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %___, <8 x float> %___, <8 x float> %___)
  store <8 x float> %___, ptr %___, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %___, ptr %___, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %___, ptr %___, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %___, ptr %___, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %___ = add nuw i64 %___, 32
  %___ = icmp eq i64 %___, %___
  br i1 %___, label %___, label %___, !llvm.loop !48

460:                                              ; preds = %___
  br i1 %___, label %___, label %___

461:                                              ; preds = %___, %___, %___
  %___ = phi i64 [ 0, %___ ], [ 0, %___ ], [ %___, %___ ]
  %___ = sub nsw i64 %17, %___
  %___ = sub nsw i64 %___, %___
  %___ = and i64 %___, 7
  %___ = icmp eq i64 %___, 0
  br i1 %___, label %___, label %___

467:                                              ; preds = %___, %___
  %___ = phi i64 [ %___, %___ ], [ %___, %___ ]
  %___ = phi i64 [ %___, %___ ], [ 0, %___ ]
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = tail call float @llvm.fmuladd.f32(float %___, float %___, float %___)
  store float %___, ptr %___, align 4, !tbaa !24
  %___ = add nuw nsw i64 %___, 1
  %___ = add i64 %___, 1
  %___ = icmp eq i64 %___, %___
  br i1 %___, label %___, label %___, !llvm.loop !49

478:                                              ; preds = %___, %___
  %___ = phi i64 [ %___, %___ ], [ %___, %___ ]
  %___ = icmp ult i64 %___, 7
  br i1 %___, label %___, label %___

481:                                              ; preds = %___, %___
  %___ = phi i64 [ %___, %___ ], [ %___, %___ ]
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = tail call float @llvm.fmuladd.f32(float %___, float %___, float %___)
  store float %___, ptr %___, align 4, !tbaa !24
  %___ = add nuw nsw i64 %___, 1
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = tail call float @llvm.fmuladd.f32(float %___, float %___, float %___)
  store float %___, ptr %___, align 4, !tbaa !24
  %___ = add nuw nsw i64 %___, 2
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = tail call float @llvm.fmuladd.f32(float %___, float %___, float %___)
  store float %___, ptr %___, align 4, !tbaa !24
  %___ = add nuw nsw i64 %___, 3
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = tail call float @llvm.fmuladd.f32(float %___, float %___, float %___)
  store float %___, ptr %___, align 4, !tbaa !24
  %___ = add nuw nsw i64 %___, 4
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = tail call float @llvm.fmuladd.f32(float %___, float %___, float %___)
  store float %___, ptr %___, align 4, !tbaa !24
  %___ = add nuw nsw i64 %___, 5
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = tail call float @llvm.fmuladd.f32(float %___, float %___, float %___)
  store float %___, ptr %___, align 4, !tbaa !24
  %___ = add nuw nsw i64 %___, 6
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = tail call float @llvm.fmuladd.f32(float %___, float %___, float %___)
  store float %___, ptr %___, align 4, !tbaa !24
  %___ = add nuw nsw i64 %___, 7
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = tail call float @llvm.fmuladd.f32(float %___, float %___, float %___)
  store float %___, ptr %___, align 4, !tbaa !24
  %___ = add nuw nsw i64 %___, 8
  %___ = icmp eq i64 %___, %___
  br i1 %___, label %___, label %___, !llvm.loop !50

532:                                              ; preds = %___, %___, %___, %___
  %___ = or i64 %___, 2
  %___ = icmp eq i64 %___, %___
  br i1 %___, label %___, label %___

535:                                              ; preds = %___
  %___ = getelementptr inbounds %"class.std::vector.0", ptr %___, i64 %___
  %___ = load ptr, ptr %___, align 8, !tbaa !13
  %___ = getelementptr inbounds float, ptr %___, i64 %___
  %___ = load float, ptr %___, align 4, !tbaa !24
  %___ = fneg float %___
  br i1 %___, label %___, label %___

541:                                              ; preds = %___
  %___ = getelementptr i8, ptr %___, i64 %___
  %___ = icmp ult ptr %___, %___
  %___ = icmp ult ptr %___, %___
  %___ = and i1 %___, %___
  br i1 %___, label %___, label %___

