665:                                              ; preds = %660
  %666 = insertelement <8 x float> poison, float %659, i64 0
  %667 = shufflevector <8 x float> %666, <8 x float> poison, <8 x i32> zeroinitializer
  %668 = insertelement <8 x float> poison, float %659, i64 0
  %669 = shufflevector <8 x float> %668, <8 x float> poison, <8 x i32> zeroinitializer
  %670 = insertelement <8 x float> poison, float %659, i64 0
  %671 = shufflevector <8 x float> %670, <8 x float> poison, <8 x i32> zeroinitializer
  %672 = insertelement <8 x float> poison, float %659, i64 0
  %673 = shufflevector <8 x float> %672, <8 x float> poison, <8 x i32> zeroinitializer
  br label %674

674:                                              ; preds = %674, %665
  %675 = phi i64 [ 0, %665 ], [ %696, %674 ]
  %676 = getelementptr inbounds float, ptr %656, i64 %675
  %677 = load <8 x float>, ptr %676, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %678 = getelementptr inbounds float, ptr %676, i64 8
  %679 = load <8 x float>, ptr %678, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %680 = getelementptr inbounds float, ptr %676, i64 16
  %681 = load <8 x float>, ptr %680, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %682 = getelementptr inbounds float, ptr %676, i64 24
  %683 = load <8 x float>, ptr %682, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %684 = getelementptr inbounds float, ptr %224, i64 %675
  %685 = load <8 x float>, ptr %684, align 4, !tbaa !24, !alias.scope !46
  %686 = getelementptr inbounds float, ptr %684, i64 8
  %687 = load <8 x float>, ptr %686, align 4, !tbaa !24, !alias.scope !46
  %688 = getelementptr inbounds float, ptr %684, i64 16
  %689 = load <8 x float>, ptr %688, align 4, !tbaa !24, !alias.scope !46
  %690 = getelementptr inbounds float, ptr %684, i64 24
  %691 = load <8 x float>, ptr %690, align 4, !tbaa !24, !alias.scope !46
  %692 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %667, <8 x float> %685, <8 x float> %677)
  %693 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %669, <8 x float> %687, <8 x float> %679)
  %694 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %671, <8 x float> %689, <8 x float> %681)
  %695 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %673, <8 x float> %691, <8 x float> %683)
  store <8 x float> %692, ptr %676, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %693, ptr %678, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %694, ptr %680, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %695, ptr %682, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %696 = add nuw i64 %675, 32
  %697 = icmp eq i64 %696, %291
  br i1 %697, label %698, label %674, !llvm.loop !48

698:                                              ; preds = %674
  br i1 %292, label %770, label %699

699:                                              ; preds = %698, %660, %654
  %700 = phi i64 [ 0, %660 ], [ 0, %654 ], [ %291, %698 ]
  %701 = sub nsw i64 %17, %700
  %702 = sub nsw i64 %271, %700
  %703 = and i64 %701, 7
  %704 = icmp eq i64 %703, 0
  br i1 %704, label %716, label %705

705:                                              ; preds = %699, %705
  %706 = phi i64 [ %713, %705 ], [ %700, %699 ]
  %707 = phi i64 [ %714, %705 ], [ 0, %699 ]
  %708 = getelementptr inbounds float, ptr %656, i64 %706
  %709 = load float, ptr %708, align 4, !tbaa !24
  %710 = getelementptr inbounds float, ptr %224, i64 %706
  %711 = load float, ptr %710, align 4, !tbaa !24
  %712 = tail call float @llvm.fmuladd.f32(float %659, float %711, float %709)
  store float %712, ptr %708, align 4, !tbaa !24
  %713 = add nuw nsw i64 %706, 1
  %714 = add i64 %707, 1
  %715 = icmp eq i64 %714, %703
  br i1 %715, label %716, label %705, !llvm.loop !49

716:                                              ; preds = %705, %699
  %717 = phi i64 [ %700, %699 ], [ %713, %705 ]
  %718 = icmp ult i64 %702, 7
  br i1 %718, label %770, label %719

719:                                              ; preds = %716, %719
  %720 = phi i64 [ %768, %719 ], [ %717, %716 ]
  %721 = getelementptr inbounds float, ptr %656, i64 %720
  %722 = load float, ptr %721, align 4, !tbaa !24
  %723 = getelementptr inbounds float, ptr %224, i64 %720
  %724 = load float, ptr %723, align 4, !tbaa !24
  %725 = tail call float @llvm.fmuladd.f32(float %659, float %724, float %722)
  store float %725, ptr %721, align 4, !tbaa !24
  %726 = add nuw nsw i64 %720, 1
  %727 = getelementptr inbounds float, ptr %656, i64 %726
  %728 = load float, ptr %727, align 4, !tbaa !24
  %729 = getelementptr inbounds float, ptr %224, i64 %726
  %730 = load float, ptr %729, align 4, !tbaa !24
  %731 = tail call float @llvm.fmuladd.f32(float %659, float %730, float %728)
  store float %731, ptr %727, align 4, !tbaa !24
  %732 = add nuw nsw i64 %720, 2
  %733 = getelementptr inbounds float, ptr %656, i64 %732
  %734 = load float, ptr %733, align 4, !tbaa !24
  %735 = getelementptr inbounds float, ptr %224, i64 %732
  %736 = load float, ptr %735, align 4, !tbaa !24
  %737 = tail call float @llvm.fmuladd.f32(float %659, float %736, float %734)
  store float %737, ptr %733, align 4, !tbaa !24
  %738 = add nuw nsw i64 %720, 3
  %739 = getelementptr inbounds float, ptr %656, i64 %738
  %740 = load float, ptr %739, align 4, !tbaa !24
  %741 = getelementptr inbounds float, ptr %224, i64 %738
  %742 = load float, ptr %741, align 4, !tbaa !24
  %743 = tail call float @llvm.fmuladd.f32(float %659, float %742, float %740)
  store float %743, ptr %739, align 4, !tbaa !24
  %744 = add nuw nsw i64 %720, 4
  %745 = getelementptr inbounds float, ptr %656, i64 %744
  %746 = load float, ptr %745, align 4, !tbaa !24
  %747 = getelementptr inbounds float, ptr %224, i64 %744
  %748 = load float, ptr %747, align 4, !tbaa !24
  %749 = tail call float @llvm.fmuladd.f32(float %659, float %748, float %746)
  store float %749, ptr %745, align 4, !tbaa !24
  %750 = add nuw nsw i64 %720, 5
  %751 = getelementptr inbounds float, ptr %656, i64 %750
  %752 = load float, ptr %751, align 4, !tbaa !24
  %753 = getelementptr inbounds float, ptr %224, i64 %750
  %754 = load float, ptr %753, align 4, !tbaa !24
  %755 = tail call float @llvm.fmuladd.f32(float %659, float %754, float %752)
  store float %755, ptr %751, align 4, !tbaa !24
  %756 = add nuw nsw i64 %720, 6
  %757 = getelementptr inbounds float, ptr %656, i64 %756
  %758 = load float, ptr %757, align 4, !tbaa !24
  %759 = getelementptr inbounds float, ptr %22F4, i64 %756
  %760 = load float, ptr %759, align 4, !tbaa !24
  %761 = tail call float @llvm.fmuladd.f32(float %659, float %760, float %758)
  store float %761, ptr %757, align 4, !tbaa !24
  %762 = add nuw nsw i64 %720, 7
  %763 = getelementptr inbounds float, ptr %656, i64 %762
  %764 = load float, ptr %763, align 4, !tbaa !24
  %765 = getelementptr inbounds float, ptr %224, i64 %762
  %766 = load float, ptr %765, align 4, !tbaa !24
  %767 = tail call float @llvm.fmuladd.f32(float %659, float %766, float %764)
  store float %767, ptr %763, align 4, !tbaa !24
  %768 = add nuw nsw i64 %720, 8
  %769 = icmp eq i64 %768, %268
  br i1 %769, label %770, label %719, !llvm.loop !50

770:                                              ; preds = %716, %719, %698, %651
  %771 = add nuw nsw i64 %294, 4
  %772 = add i64 %295, 4
  %773 = icmp eq i64 %772, %276
  br i1 %773, label %781, label %293, !llvm.loop !51

774:                                              ; preds = %260, %774
  %775 = phi i64 [ %779, %774 ], [ %261, %260 ]
  %776 = getelementptr inbounds float, ptr %224, i64 %775
  %777 = load float, ptr %776, align 4, !tbaa !24
  %778 = fdiv float %777, %226
  store float %778, ptr %776, align 4, !tbaa !24
  %779 = add nuw nsw i64 %775, 1
  %780 = icmp eq i64 %779, %229
  br i1 %780, label %262, label %774, !llvm.loop !52

781:                                              ; preds = %770, %265
  %782 = phi i64 [ 0, %265 ], [ %771, %770 ]
  %783 = icmp eq i64 %273, 0
  br i1 %783, label %913, label %784

784:                                              ; preds = %781
  %785 = icmp ult i64 %229, 32
  %786 = and i64 %17, 31
  %787 = sub nsw i64 %229, %786
  %788 = icmp eq i64 %786, 0
  br label %789

789:                                              ; preds = %909, %784
  %790 = phi i64 [ %782, %784 ], [ %910, %909 ]
  %791 = phi i64 [ 0, %784 ], [ %911, %909 ]
  %792 = icmp eq i64 %790, %266
  br i1 %792, label %909, label %793

793:                                              ; preds = %789
  %794 = getelementptr inbounds %"class.std::vector.0", ptr %220, i64 %790
  %795 = load ptr, ptr %794, align 8, !tbaa !13
  %796 = getelementptr inbounds float, ptr %795, i64 %223
  %797 = load float, ptr %796, align 4, !tbaa !24
  %798 = fneg float %797
  br i1 %785, label %838, label %799

799:                                              ; preds = %793
  %800 = getelementptr i8, ptr %795, i64 %269
  %801 = icmp ult ptr %795, %270
  %802 = icmp ult ptr %224, %800
  %803 = and i1 %801, %802
  br i1 %803, label %838, label %804

