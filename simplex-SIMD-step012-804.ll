804:                                              ; preds = %799
  %805 = insertelement <8 x float> poison, float %798, i64 0
  %806 = shufflevector <8 x float> %805, <8 x float> poison, <8 x i32> zeroinitializer
  %807 = insertelement <8 x float> poison, float %798, i64 0
  %808 = shufflevector <8 x float> %807, <8 x float> poison, <8 x i32> zeroinitializer
  %809 = insertelement <8 x float> poison, float %798, i64 0
  %810 = shufflevector <8 x float> %809, <8 x float> poison, <8 x i32> zeroinitializer
  %811 = insertelement <8 x float> poison, float %798, i64 0
  %812 = shufflevector <8 x float> %811, <8 x float> poison, <8 x i32> zeroinitializer
  br label %813

813:                                              ; preds = %813, %804
  %814 = phi i64 [ 0, %804 ], [ %835, %813 ]
  %815 = getelementptr inbounds float, ptr %795, i64 %814
  %816 = load <8 x float>, ptr %815, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %817 = getelementptr inbounds float, ptr %815, i64 8
  %818 = load <8 x float>, ptr %817, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %819 = getelementptr inbounds float, ptr %815, i64 16
  %820 = load <8 x float>, ptr %819, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %821 = getelementptr inbounds float, ptr %815, i64 24
  %822 = load <8 x float>, ptr %821, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %823 = getelementptr inbounds float, ptr %224, i64 %814
  %824 = load <8 x float>, ptr %823, align 4, !tbaa !24, !alias.scope !46
  %825 = getelementptr inbounds float, ptr %823, i64 8
  %826 = load <8 x float>, ptr %825, align 4, !tbaa !24, !alias.scope !46
  %827 = getelementptr inbounds float, ptr %823, i64 16
  %828 = load <8 x float>, ptr %827, align 4, !tbaa !24, !alias.scope !46
  %829 = getelementptr inbounds float, ptr %823, i64 24
  %830 = load <8 x float>, ptr %829, align 4, !tbaa !24, !alias.scope !46
  %831 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %806, <8 x float> %824, <8 x float> %816)
  %832 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %808, <8 x float> %826, <8 x float> %818)
  %833 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %810, <8 x float> %828, <8 x float> %820)
  %834 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %812, <8 x float> %830, <8 x float> %822)
  store <8 x float> %831, ptr %815, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %832, ptr %817, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %833, ptr %819, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  store <8 x float> %834, ptr %821, align 4, !tbaa !24, !alias.scope !43, !noalias !46
  %835 = add nuw i64 %814, 32
  %836 = icmp eq i64 %835, %787
  br i1 %836, label %837, label %813, !llvm.loop !48

837:                                              ; preds = %813
  br i1 %788, label %909, label %838

838:                                              ; preds = %837, %799, %793
  %839 = phi i64 [ 0, %799 ], [ 0, %793 ], [ %787, %837 ]
  %840 = sub nsw i64 %17, %839
  %841 = sub nsw i64 %271, %839
  %842 = and i64 %840, 7
  %843 = icmp eq i64 %842, 0
  br i1 %843, label %855, label %844

844:                                              ; preds = %838, %844
  %845 = phi i64 [ %852, %844 ], [ %839, %838 ]
  %846 = phi i64 [ %853, %844 ], [ 0, %838 ]
  %847 = getelementptr inbounds float, ptr %795, i64 %845
  %848 = load float, ptr %847, align 4, !tbaa !24
  %849 = getelementptr inbounds float, ptr %224, i64 %845
  %850 = load float, ptr %849, align 4, !tbaa !24
  %851 = tail call float @llvm.fmuladd.f32(float %798, float %850, float %848)
  store float %851, ptr %847, align 4, !tbaa !24
  %852 = add nuw nsw i64 %845, 1
  %853 = add i64 %846, 1
  %854 = icmp eq i64 %853, %842
  br i1 %854, label %855, label %844, !llvm.loop !49

855:                                              ; preds = %844, %838
  %856 = phi i64 [ %839, %838 ], [ %852, %844 ]
  %857 = icmp ult i64 %841, 7
  br i1 %857, label %909, label %858

858:                                              ; preds = %855, %858
  %859 = phi i64 [ %907, %858 ], [ %856, %855 ]
  %860 = getelementptr inbounds float, ptr %795, i64 %859
  %861 = load float, ptr %860, align 4, !tbaa !24
  %862 = getelementptr inbounds float, ptr %224, i64 %859
  %863 = load float, ptr %862, align 4, !tbaa !24
  %864 = tail call float @llvm.fmuladd.f32(float %798, float %863, float %861)
  store float %864, ptr %860, align 4, !tbaa !24
  %865 = add nuw nsw i64 %859, 1
  %866 = getelementptr inbounds float, ptr %795, i64 %865
  %867 = load float, ptr %866, align 4, !tbaa !24
  %868 = getelementptr inbounds float, ptr %224, i64 %865
  %869 = load float, ptr %868, align 4, !tbaa !24
  %870 = tail call float @llvm.fmuladd.f32(float %798, float %869, float %867)
  store float %870, ptr %866, align 4, !tbaa !24
  %871 = add nuw nsw i64 %859, 2
  %872 = getelementptr inbounds float, ptr %795, i64 %871
  %873 = load float, ptr %872, align 4, !tbaa !24
  %874 = getelementptr inbounds float, ptr %224, i64 %871
  %875 = load float, ptr %874, align 4, !tbaa !24
  %876 = tail call float @llvm.fmuladd.f32(float %798, float %875, float %873)
  store float %876, ptr %872, align 4, !tbaa !24
  %877 = add nuw nsw i64 %859, 3
  %878 = getelementptr inbounds float, ptr %795, i64 %877
  %879 = load float, ptr %878, align 4, !tbaa !24
  %880 = getelementptr inbounds float, ptr %224, i64 %877
  %881 = load float, ptr %880, align 4, !tbaa !24
  %882 = tail call float @llvm.fmuladd.f32(float %798, float %881, float %879)
  store float %882, ptr %878, align 4, !tbaa !24
  %883 = add nuw nsw i64 %859, 4
  %884 = getelementptr inbounds float, ptr %795, i64 %883
  %885 = load float, ptr %884, align 4, !tbaa !24
  %886 = getelementptr inbounds float, ptr %224, i64 %883
  %887 = load float, ptr %886, align 4, !tbaa !24
  %888 = tail call float @llvm.fmuladd.f32(float %798, float %887, float %885)
  store float %888, ptr %884, align 4, !tbaa !24
  %889 = add nuw nsw i64 %859, 5
  %890 = getelementptr inbounds float, ptr %795, i64 %889
  %891 = load float, ptr %890, align 4, !tbaa !24
  %892 = getelementptr inbounds float, ptr %224, i64 %889
  %893 = load float, ptr %892, align 4, !tbaa !24
  %894 = tail call float @llvm.fmuladd.f32(float %798, float %893, float %891)
  store float %894, ptr %890, align 4, !tbaa !24
  %895 = add nuw nsw i64 %859, 6
  %896 = getelementptr inbounds float, ptr %795, i64 %895
  %897 = load float, ptr %896, align 4, !tbaa !24
  %898 = getelementptr inbounds float, ptr %224, i64 %895
  %899 = load float, ptr %898, align 4, !tbaa !24
  %900 = tail call float @llvm.fmuladd.f32(float %798, float %899, float %897)
  store float %900, ptr %896, align 4, !tbaa !24
  %901 = add nuw nsw i64 %859, 7
  %902 = getelementptr inbounds float, ptr %795, i64 %901
  %903 = load float, ptr %902, align 4, !tbaa !24
  %904 = getelementptr inbounds float, ptr %224, i64 %901
  %905 = load float, ptr %904, align 4, !tbaa !24
  %906 = tail call float @llvm.fmuladd.f32(float %798, float %905, float %903)
  store float %906, ptr %902, align 4, !tbaa !24
  %907 = add nuw nsw i64 %859, 8
  %908 = icmp eq i64 %907, %268
  br i1 %908, label %909, label %858, !llvm.loop !50

909:                                              ; preds = %855, %858, %837, %789
  %910 = add nuw nsw i64 %790, 1
  %911 = add i64 %791, 1
  %912 = icmp eq i64 %911, %273
  br i1 %912, label %913, label %789, !llvm.loop !54

913:                                              ; preds = %781, %909, %262, %211
  %914 = icmp eq ptr %212, null
  br i1 %914, label %916, label %915

915:                                              ; preds = %913
  tail call void @_ZdlPv(ptr noundef nonnull %212) #19
  br label %916

916:                                              ; preds = %913, %915
  %917 = icmp eq ptr %42, null
  br i1 %917, label %919, label %918

918:                                              ; preds = %916
  tail call void @_ZdlPv(ptr noundef nonnull %42) #19
  br label %919

919:                                              ; preds = %916, %918
  ret void

920:                                              ; preds = %131
  tail call void @_ZdlPv(ptr noundef nonnull %42) #19
  br label %921

921:                                              ; preds = %131, %920
  resume { ptr, i32 } %132
}
