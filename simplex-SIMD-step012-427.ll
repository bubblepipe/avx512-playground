427:                                              ; preds = %422
  %428 = insertelement <8 x float> poison, float %421, i64 0
  %429 = shufflevector <8 x float> %428, <8 x float> poison, <8 x i32> zeroinitializer
  %430 = insertelement <8 x float> poison, float %421, i64 0
  %431 = shufflevector <8 x float> %430, <8 x float> poison, <8 x i32> zeroinitializer
  %432 = insertelement <8 x float> poison, float %421, i64 0
  %433 = shufflevector <8 x float> %432, <8 x float> poison, <8 x i32> zeroinitializer
  %434 = insertelement <8 x float> poison, float %421, i64 0
  %435 = shufflevector <8 x float> %434, <8 x float> poison, <8 x i32> zeroinitializer
  br label %436

436:                                              ; preds = %436, %427
  %437 = phi i64 [ 0, %427 ], [ %458, %436 ]
  %438 = getelementptr inbounds float, ptr %418, i64 %437
  %439 = load <8 x float>, ptr %438, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %440 = getelementptr inbounds float, ptr %438, i64 8
  %441 = load <8 x float>, ptr %440, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %442 = getelementptr inbounds float, ptr %438, i64 16
  %443 = load <8 x float>, ptr %442, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %444 = getelementptr inbounds float, ptr %438, i64 24
  %445 = load <8 x float>, ptr %444, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %446 = getelementptr inbounds float, ptr %224, i64 %437
  %447 = load <8 x float>, ptr %446, align 4, !tbaa !24, !alias.scope !46
  %448 = getelementptr inbounds float, ptr %446, i64 8
  %449 = load <8 x float>, ptr %448, align 4, !tbaa !24, !alias.scope !46
  %450 = getelementptr inbounds float, ptr %446, i64 16
  %451 = load <8 x float>, ptr %450, align 4, !tbaa !24, !alias.scope !46
  %452 = getelementptr inbounds float, ptr %446, i64 24
  %453 = load <8 x float>, ptr %452, align 4, !tbaa !24, !alias.scope !46
  %454 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %429, <8 x float> %447, <8 x float> %439)
  %455 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %431, <8 x float> %449, <8 x float> %441)
  %456 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %433, <8 x float> %451, <8 x float> %443)
  %457 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %435, <8 x float> %453, <8 x float> %445)
  store <8 x float> %454, ptr %438, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %455, ptr %440, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %456, ptr %442, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %457, ptr %444, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %458 = add nuw i64 %437, 32
  %459 = icmp eq i64 %458, %283
  br i1 %459, label %460, label %436, !llvm.loop !48

460:                                              ; preds = %436
  br i1 %284, label %532, label %461

461:                                              ; preds = %460, %422, %416
  %462 = phi i64 [ 0, %422 ], [ 0, %416 ], [ %283, %460 ]
  %463 = sub nsw i64 %17, %462
  %464 = sub nsw i64 %271, %462
  %465 = and i64 %463, 7
  %466 = icmp eq i64 %465, 0
  br i1 %466, label %478, label %467

467:                                              ; preds = %461, %467
  %468 = phi i64 [ %475, %467 ], [ %462, %461 ]
  %469 = phi i64 [ %476, %467 ], [ 0, %461 ]
  %470 = getelementptr inbounds float, ptr %418, i64 %468
  %471 = load float, ptr %470, align 4, !tbaa !24
  %472 = getelementptr inbounds float, ptr %224, i64 %468
  %473 = load float, ptr %472, align 4, !tbaa !24
  %474 = tail call float @llvm.fmuladd.f32(float %421, float %473, float %471)
  store float %474, ptr %470, align 4, !tbaa !24
  %475 = add nuw nsw i64 %468, 1
  %476 = add i64 %469, 1
  %477 = icmp eq i64 %476, %465
  br i1 %477, label %478, label %467, !llvm.loop !49

478:                                              ; preds = %467, %461
  %479 = phi i64 [ %462, %461 ], [ %475, %467 ]
  %480 = icmp ult i64 %464, 7
  br i1 %480, label %532, label %481

481:                                              ; preds = %478, %481
  %482 = phi i64 [ %530, %481 ], [ %479, %478 ]
  %483 = getelementptr inbounds float, ptr %418, i64 %482
  %484 = load float, ptr %483, align 4, !tbaa !24
  %485 = getelementptr inbounds float, ptr %224, i64 %482
  %486 = load float, ptr %485, align 4, !tbaa !24
  %487 = tail call float @llvm.fmuladd.f32(float %421, float %486, float %484)
  store float %487, ptr %483, align 4, !tbaa !24
  %488 = add nuw nsw i64 %482, 1
  %489 = getelementptr inbounds float, ptr %418, i64 %488
  %490 = load float, ptr %489, align 4, !tbaa !24
  %491 = getelementptr inbounds float, ptr %224, i64 %488
  %492 = load float, ptr %491, align 4, !tbaa !24
  %493 = tail call float @llvm.fmuladd.f32(float %421, float %492, float %490)
  store float %493, ptr %489, align 4, !tbaa !24
  %494 = add nuw nsw i64 %482, 2
  %495 = getelementptr inbounds float, ptr %418, i64 %494
  %496 = load float, ptr %495, align 4, !tbaa !24
  %497 = getelementptr inbounds float, ptr %224, i64 %494
  %498 = load float, ptr %497, align 4, !tbaa !24
  %499 = tail call float @llvm.fmuladd.f32(float %421, float %498, float %496)
  store float %499, ptr %495, align 4, !tbaa !24
  %500 = add nuw nsw i64 %482, 3
  %501 = getelementptr inbounds float, ptr %418, i64 %500
  %502 = load float, ptr %501, align 4, !tbaa !24
  %503 = getelementptr inbounds float, ptr %224, i64 %500
  %504 = load float, ptr %503, align 4, !tbaa !24
  %505 = tail call float @llvm.fmuladd.f32(float %421, float %504, float %502)
  store float %505, ptr %501, align 4, !tbaa !24
  %506 = add nuw nsw i64 %482, 4
  %507 = getelementptr inbounds float, ptr %418, i64 %506
  %508 = load float, ptr %507, align 4, !tbaa !24
  %509 = getelementptr inbounds float, ptr %224, i64 %506
  %510 = load float, ptr %509, align 4, !tbaa !24
  %511 = tail call float @llvm.fmuladd.f32(float %421, float %510, float %508)
  store float %511, ptr %507, align 4, !tbaa !24
  %512 = add nuw nsw i64 %482, 5
  %513 = getelementptr inbounds float, ptr %418, i64 %512
  %514 = load float, ptr %513, align 4, !tbaa !24
  %515 = getelementptr inbounds float, ptr %224, i64 %512
  %516 = load float, ptr %515, align 4, !tbaa !24
  %517 = tail call float @llvm.fmuladd.f32(float %421, float %516, float %514)
  store float %517, ptr %513, align 4, !tbaa !24
  %518 = add nuw nsw i64 %482, 6
  %519 = getelementptr inbounds float, ptr %418, i64 %518
  %520 = load float, ptr %519, align 4, !tbaa !24
  %521 = getelementptr inbounds float, ptr %224, i64 %518
  %522 = load float, ptr %521, align 4, !tbaa !24
  %523 = tail call float @llvm.fmuladd.f32(float %421, float %522, float %520)
  store float %523, ptr %519, align 4, !tbaa !24
  %524 = add nuw nsw i64 %482, 7
  %525 = getelementptr inbounds float, ptr %418, i64 %524
  %526 = load float, ptr %525, align 4, !tbaa !24
  %527 = getelementptr inbounds float, ptr %224, i64 %524
  %528 = load float, ptr %527, align 4, !tbaa !24
  %529 = tail call float @llvm.fmuladd.f32(float %421, float %528, float %526)
  store float %529, ptr %525, align 4, !tbaa !24
  %530 = add nuw nsw i64 %482, 8
  %531 = icmp eq i64 %530, %268
  br i1 %531, label %532, label %481, !llvm.loop !50

532:                                              ; preds = %478, %481, %460, %413
  %533 = or i64 %294, 2
  %534 = icmp eq i64 %533, %266
  br i1 %534, label %651, label %535

535:                                              ; preds = %532
  %536 = getelementptr inbounds %"class.std::vector.0", ptr %220, i64 %533
  %537 = load ptr, ptr %536, align 8, !tbaa !13
  %538 = getelementptr inbounds float, ptr %537, i64 %223
  %539 = load float, ptr %538, align 4, !tbaa !24
  %540 = fneg float %539
  br i1 %285, label %580, label %541

541:                                              ; preds = %535
  %542 = getelementptr i8, ptr %537, i64 %269
  %543 = icmp ult ptr %537, %270
  %544 = icmp ult ptr %224, %542
  %545 = and i1 %543, %544
  br i1 %545, label %580, label %546

