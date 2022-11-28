308:                                              ; preds = %303
  %309 = insertelement <8 x float> poison, float %302, i64 0
  %310 = shufflevector <8 x float> %309, <8 x float> poison, <8 x i32> zeroinitializer
  %311 = insertelement <8 x float> poison, float %302, i64 0
  %312 = shufflevector <8 x float> %311, <8 x float> poison, <8 x i32> zeroinitializer
  %313 = insertelement <8 x float> poison, float %302, i64 0
  %314 = shufflevector <8 x float> %313, <8 x float> poison, <8 x i32> zeroinitializer
  %315 = insertelement <8 x float> poison, float %302, i64 0
  %316 = shufflevector <8 x float> %315, <8 x float> poison, <8 x i32> zeroinitializer
  br label %317

317:                                              ; preds = %317, %308
  %318 = phi i64 [ 0, %308 ], [ %339, %317 ]
  %319 = getelementptr inbounds float, ptr %299, i64 %318
  %320 = load <8 x float>, ptr %319, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %321 = getelementptr inbounds float, ptr %319, i64 8
  %322 = load <8 x float>, ptr %321, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %323 = getelementptr inbounds float, ptr %319, i64 16
  %324 = load <8 x float>, ptr %323, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %325 = getelementptr inbounds float, ptr %319, i64 24
  %326 = load <8 x float>, ptr %325, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %327 = getelementptr inbounds float, ptr %224, i64 %318
  %328 = load <8 x float>, ptr %327, align 4, !tbaa !24, !alias.scope !46
  %329 = getelementptr inbounds float, ptr %327, i64 8
  %330 = load <8 x float>, ptr %329, align 4, !tbaa !24, !alias.scope !46
  %331 = getelementptr inbounds float, ptr %327, i64 16
  %332 = load <8 x float>, ptr %331, align 4, !tbaa !24, !alias.scope !46
  %333 = getelementptr inbounds float, ptr %327, i64 24
  %334 = load <8 x float>, ptr %333, align 4, !tbaa !24, !alias.scope !46
  %335 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %310, <8 x float> %328, <8 x float> %320)
  %336 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %312, <8 x float> %330, <8 x float> %322)
  %337 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %314, <8 x float> %332, <8 x float> %324)
  %338 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %316, <8 x float> %334, <8 x float> %326)
  store <8 x float> %335, ptr %319, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %336, ptr %321, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %337, ptr %323, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %338, ptr %325, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %339 = add nuw i64 %318, 32
  %340 = icmp eq i64 %339, %279
  br i1 %340, label %341, label %317, !llvm.loop !48

341:                                              ; preds = %317
  br i1 %280, label %413, label %342

342:                                              ; preds = %303, %297, %341
  %343 = phi i64 [ 0, %303 ], [ 0, %297 ], [ %279, %341 ]
  %344 = sub nsw i64 %17, %343
  %345 = sub nsw i64 %271, %343
  %346 = and i64 %344, 7
  %347 = icmp eq i64 %346, 0
  br i1 %347, label %359, label %348

348:                                              ; preds = %342, %348
  %349 = phi i64 [ %356, %348 ], [ %343, %342 ]
  %350 = phi i64 [ %357, %348 ], [ 0, %342 ]
  %351 = getelementptr inbounds float, ptr %299, i64 %349
  %352 = load float, ptr %351, align 4, !tbaa !24
  %353 = getelementptr inbounds float, ptr %224, i64 %349
  %354 = load float, ptr %353, align 4, !tbaa !24
  %355 = tail call float @llvm.fmuladd.f32(float %302, float %354, float %352)
  store float %355, ptr %351, align 4, !tbaa !24
  %356 = add nuw nsw i64 %349, 1
  %357 = add i64 %350, 1
  %358 = icmp eq i64 %357, %346
  br i1 %358, label %359, label %348, !llvm.loop !49

359:                                              ; preds = %348, %342
  %360 = phi i64 [ %343, %342 ], [ %356, %348 ]
  %361 = icmp ult i64 %345, 7
  br i1 %361, label %413, label %362

362:                                              ; preds = %359, %362
  %363 = phi i64 [ %411, %362 ], [ %360, %359 ]
  %364 = getelementptr inbounds float, ptr %299, i64 %363
  %365 = load float, ptr %364, align 4, !tbaa !24
  %366 = getelementptr inbounds float, ptr %224, i64 %363
  %367 = load float, ptr %366, align 4, !tbaa !24
  %368 = tail call float @llvm.fmuladd.f32(float %302, float %367, float %365)
  store float %368, ptr %364, align 4, !tbaa !24
  %369 = add nuw nsw i64 %363, 1
  %370 = getelementptr inbounds float, ptr %299, i64 %369
  %371 = load float, ptr %370, align 4, !tbaa !24
  %372 = getelementptr inbounds float, ptr %224, i64 %369
  %373 = load float, ptr %372, align 4, !tbaa !24
  %374 = tail call float @llvm.fmuladd.f32(float %302, float %373, float %371)
  store float %374, ptr %370, align 4, !tbaa !24
  %375 = add nuw nsw i64 %363, 2
  %376 = getelementptr inbounds float, ptr %299, i64 %375
  %377 = load float, ptr %376, align 4, !tbaa !24
  %378 = getelementptr inbounds float, ptr %224, i64 %375
  %379 = load float, ptr %378, align 4, !tbaa !24
  %380 = tail call float @llvm.fmuladd.f32(float %302, float %379, float %377)
  store float %380, ptr %376, align 4, !tbaa !24
  %381 = add nuw nsw i64 %363, 3
  %382 = getelementptr inbounds float, ptr %299, i64 %381
  %383 = load float, ptr %382, align 4, !tbaa !24
  %384 = getelementptr inbounds float, ptr %224, i64 %381
  %385 = load float, ptr %384, align 4, !tbaa !24
  %386 = tail call float @llvm.fmuladd.f32(float %302, float %385, float %383)
  store float %386, ptr %382, align 4, !tbaa !24
  %387 = add nuw nsw i64 %363, 4
  %388 = getelementptr inbounds float, ptr %299, i64 %387
  %389 = load float, ptr %388, align 4, !tbaa !24
  %390 = getelementptr inbounds float, ptr %224, i64 %387
  %391 = load float, ptr %390, align 4, !tbaa !24
  %392 = tail call float @llvm.fmuladd.f32(float %302, float %391, float %389)
  store float %392, ptr %388, align 4, !tbaa !24
  %393 = add nuw nsw i64 %363, 5
  %394 = getelementptr inbounds float, ptr %299, i64 %393
  %395 = load float, ptr %394, align 4, !tbaa !24
  %396 = getelementptr inbounds float, ptr %224, i64 %393
  %397 = load float, ptr %396, align 4, !tbaa !24
  %398 = tail call float @llvm.fmuladd.f32(float %302, float %397, float %395)
  store float %398, ptr %394, align 4, !tbaa !24
  %399 = add nuw nsw i64 %363, 6
  %400 = getelementptr inbounds float, ptr %299, i64 %399
  %401 = load float, ptr %400, align 4, !tbaa !24
  %402 = getelementptr inbounds float, ptr %224, i64 %399
  %403 = load float, ptr %402, align 4, !tbaa !24
  %404 = tail call float @llvm.fmuladd.f32(float %302, float %403, float %401)
  store float %404, ptr %400, align 4, !tbaa !24
  %405 = add nuw nsw i64 %363, 7
  %406 = getelementptr inbounds float, ptr %299, i64 %405
  %407 = load float, ptr %406, align 4, !tbaa !24
  %408 = getelementptr inbounds float, ptr %224, i64 %405
  %409 = load float, ptr %408, align 4, !tbaa !24
  %410 = tail call float @llvm.fmuladd.f32(float %302, float %409, float %407)
  store float %410, ptr %406, align 4, !tbaa !24
  %411 = add nuw nsw i64 %363, 8
  %412 = icmp eq i64 %411, %268
  br i1 %412, label %413, label %362, !llvm.loop !50

413:                                              ; preds = %359, %362, %341, %293
  %414 = or i64 %294, 1
  %415 = icmp eq i64 %414, %266
  br i1 %415, label %532, label %416

416:                                              ; preds = %413
  %417 = getelementptr inbounds %"class.std::vector.0", ptr %220, i64 %414
  %418 = load ptr, ptr %417, align 8, !tbaa !13
  %419 = getelementptr inbounds float, ptr %418, i64 %223
  %420 = load float, ptr %419, align 4, !tbaa !24
  %421 = fneg float %420
  br i1 %281, label %461, label %422

422:                                              ; preds = %416
  %423 = getelementptr i8, ptr %418, i64 %269
  %424 = icmp ult ptr %418, %270
  %425 = icmp ult ptr %224, %423
  %426 = and i1 %424, %425
  br i1 %426, label %461, label %427

