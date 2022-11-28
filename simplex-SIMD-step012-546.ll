546:                                              ; preds = %541
  %547 = insertelement <8 x float> poison, float %540, i64 0
  %548 = shufflevector <8 x float> %547, <8 x float> poison, <8 x i32> zeroinitializer
  %549 = insertelement <8 x float> poison, float %540, i64 0
  %550 = shufflevector <8 x float> %549, <8 x float> poison, <8 x i32> zeroinitializer
  %551 = insertelement <8 x float> poison, float %540, i64 0
  %552 = shufflevector <8 x float> %551, <8 x float> poison, <8 x i32> zeroinitializer
  %553 = insertelement <8 x float> poison, float %540, i64 0
  %554 = shufflevector <8 x float> %553, <8 x float> poison, <8 x i32> zeroinitializer
  br label %555

555:                                              ; preds = %555, %546
  %556 = phi i64 [ 0, %546 ], [ %577, %555 ]
  %557 = getelementptr inbounds float, ptr %537, i64 %556
  %558 = load <8 x float>, ptr %557, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %559 = getelementptr inbounds float, ptr %557, i64 8
  %560 = load <8 x float>, ptr %559, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %561 = getelementptr inbounds float, ptr %557, i64 16
  %562 = load <8 x float>, ptr %561, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %563 = getelementptr inbounds float, ptr %557, i64 24
  %564 = load <8 x float>, ptr %563, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %565 = getelementptr inbounds float, ptr %224, i64 %556
  %566 = load <8 x float>, ptr %565, align 4, !tbaa !24, !alias.scope !46
  %567 = getelementptr inbounds float, ptr %565, i64 8
  %568 = load <8 x float>, ptr %567, align 4, !tbaa !24, !alias.scope !46
  %569 = getelementptr inbounds float, ptr %565, i64 16
  %570 = load <8 x float>, ptr %569, align 4, !tbaa !24, !alias.scope !46
  %571 = getelementptr inbounds float, ptr %565, i64 24
  %572 = load <8 x float>, ptr %571, align 4, !tbaa !24, !alias.scope !46
  %573 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %548, <8 x float> %566, <8 x float> %558)
  %574 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %550, <8 x float> %568, <8 x float> %560)
  %575 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %552, <8 x float> %570, <8 x float> %562)
  %576 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %554, <8 x float> %572, <8 x float> %564)
  store <8 x float> %573, ptr %557, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %574, ptr %559, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %575, ptr %561, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %576, ptr %563, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %577 = add nuw i64 %556, 32
  %578 = icmp eq i64 %577, %287
  br i1 %578, label %579, label %555, !llvm.loop !48

579:                                              ; preds = %555
  br i1 %288, label %651, label %580

580:                                              ; preds = %579, %541, %535
  %581 = phi i64 [ 0, %541 ], [ 0, %535 ], [ %287, %579 ]
  %582 = sub nsw i64 %17, %581
  %583 = sub nsw i64 %271, %581
  %584 = and i64 %582, 7
  %585 = icmp eq i64 %584, 0
  br i1 %585, label %597, label %586

586:                                              ; preds = %580, %586
  %587 = phi i64 [ %594, %586 ], [ %581, %580 ]
  %588 = phi i64 [ %595, %586 ], [ 0, %580 ]
  %589 = getelementptr inbounds float, ptr %537, i64 %587
  %590 = load float, ptr %589, align 4, !tbaa !24
  %591 = getelementptr inbounds float, ptr %224, i64 %587
  %592 = load float, ptr %591, align 4, !tbaa !24
  %593 = tail call float @llvm.fmuladd.f32(float %540, float %592, float %590)
  store float %593, ptr %589, align 4, !tbaa !24
  %594 = add nuw nsw i64 %587, 1
  %595 = add i64 %588, 1
  %596 = icmp eq i64 %595, %584
  br i1 %596, label %597, label %586, !llvm.loop !49

597:                                              ; preds = %586, %580
  %598 = phi i64 [ %581, %580 ], [ %594, %586 ]
  %599 = icmp ult i64 %583, 7
  br i1 %599, label %651, label %600

600:                                              ; preds = %597, %600
  %601 = phi i64 [ %649, %600 ], [ %598, %597 ]
  %602 = getelementptr inbounds float, ptr %537, i64 %601
  %603 = load float, ptr %602, align 4, !tbaa !24
  %604 = getelementptr inbounds float, ptr %224, i64 %601
  %605 = load float, ptr %604, align 4, !tbaa !24
  %606 = tail call float @llvm.fmuladd.f32(float %540, float %605, float %603)
  store float %606, ptr %602, align 4, !tbaa !24
  %607 = add nuw nsw i64 %601, 1
  %608 = getelementptr inbounds float, ptr %537, i64 %607
  %609 = load float, ptr %608, align 4, !tbaa !24
  %610 = getelementptr inbounds float, ptr %224, i64 %607
  %611 = load float, ptr %610, align 4, !tbaa !24
  %612 = tail call float @llvm.fmuladd.f32(float %540, float %611, float %609)
  store float %612, ptr %608, align 4, !tbaa !24
  %613 = add nuw nsw i64 %601, 2
  %614 = getelementptr inbounds float, ptr %537, i64 %613
  %615 = load float, ptr %614, align 4, !tbaa !24
  %616 = getelementptr inbounds float, ptr %224, i64 %613
  %617 = load float, ptr %616, align 4, !tbaa !24
  %618 = tail call float @llvm.fmuladd.f32(float %540, float %617, float %615)
  store float %618, ptr %614, align 4, !tbaa !24
  %619 = add nuw nsw i64 %601, 3
  %620 = getelementptr inbounds float, ptr %537, i64 %619
  %621 = load float, ptr %620, align 4, !tbaa !24
  %622 = getelementptr inbounds float, ptr %224, i64 %619
  %623 = load float, ptr %622, align 4, !tbaa !24
  %624 = tail call float @llvm.fmuladd.f32(float %540, float %623, float %621)
  store float %624, ptr %620, align 4, !tbaa !24
  %625 = add nuw nsw i64 %601, 4
  %626 = getelementptr inbounds float, ptr %537, i64 %625
  %627 = load float, ptr %626, align 4, !tbaa !24
  %628 = getelementptr inbounds float, ptr %224, i64 %625
  %629 = load float, ptr %628, align 4, !tbaa !24
  %630 = tail call float @llvm.fmuladd.f32(float %540, float %629, float %627)
  store float %630, ptr %626, align 4, !tbaa !24
  %631 = add nuw nsw i64 %601, 5
  %632 = getelementptr inbounds float, ptr %537, i64 %631
  %633 = load float, ptr %632, align 4, !tbaa !24
  %634 = getelementptr inbounds float, ptr %224, i64 %631
  %635 = load float, ptr %634, align 4, !tbaa !24
  %636 = tail call float @llvm.fmuladd.f32(float %540, float %635, float %633)
  store float %636, ptr %632, align 4, !tbaa !24
  %637 = add nuw nsw i64 %601, 6
  %638 = getelementptr inbounds float, ptr %537, i64 %637
  %639 = load float, ptr %638, align 4, !tbaa !24
  %640 = getelementptr inbounds float, ptr %224, i64 %637
  %641 = load float, ptr %640, align 4, !tbaa !24
  %642 = tail call float @llvm.fmuladd.f32(float %540, float %641, float %639)
  store float %642, ptr %638, align 4, !tbaa !24
  %643 = add nuw nsw i64 %601, 7
  %644 = getelementptr inbounds float, ptr %537, i64 %643
  %645 = load float, ptr %644, align 4, !tbaa !24
  %646 = getelementptr inbounds float, ptr %224, i64 %643
  %647 = load float, ptr %646, align 4, !tbaa !24
  %648 = tail call float @llvm.fmuladd.f32(float %540, float %647, float %645)
  store float %648, ptr %644, align 4, !tbaa !24
  %649 = add nuw nsw i64 %601, 8
  %650 = icmp eq i64 %649, %268
  br i1 %650, label %651, label %600, !llvm.loop !50

651:                                              ; preds = %597, %600, %579, %532
  %652 = or i64 %294, 3
  %653 = icmp eq i64 %652, %266
  br i1 %653, label %770, label %654

654:                                              ; preds = %651
  %655 = getelementptr inbounds %"class.std::vector.0", ptr %220, i64 %652
  %656 = load ptr, ptr %655, align 8, !tbaa !13
  %657 = getelementptr inbounds float, ptr %656, i64 %223
  %658 = load float, ptr %657, align 4, !tbaa !24
  %659 = fneg float %658
  br i1 %289, label %699, label %660

660:                                              ; preds = %654
  %661 = getelementptr i8, ptr %656, i64 %269
  %662 = icmp ult ptr %656, %270
  %663 = icmp ult ptr %224, %661
  %664 = and i1 %662, %663
  br i1 %664, label %699, label %665

