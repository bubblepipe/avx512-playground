; Function Attrs: uwtable
define dso_local void @_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE(ptr nocapture noundef nonnull readonly align 8 dereferenceable(24) %0) local_unnamed_addr #5 personality ptr @__gxx_personality_v0 {
  %2 = getelementptr inbounds %"struct.std::_Vector_base<std::vector<float>, std::allocator<std::vector<float>>>::_Vector_impl_data", ptr %0, i64 0, i32 1
  %3 = load ptr, ptr %2, align 8, !tbaa !5
  %4 = load ptr, ptr %0, align 8, !tbaa !10
  %5 = ptrtoint ptr %3 to i64
  %6 = ptrtoint ptr %4 to i64
  %7 = sub i64 %5, %6
  %8 = sdiv exact i64 %7, 24
  %9 = trunc i64 %8 to i32
  %10 = getelementptr inbounds %"struct.std::_Vector_base<float, std::allocator<float>>::_Vector_impl_data", ptr %4, i64 0, i32 1
  %11 = load ptr, ptr %10, align 8, !tbaa !11
  %12 = load ptr, ptr %4, align 8, !tbaa !13
  %13 = ptrtoint ptr %11 to i64
  %14 = ptrtoint ptr %12 to i64
  %15 = sub i64 %13, %14
  %16 = add nsw i32 %9, -1
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds %"class.std::vector.0", ptr %4, i64 %17
  %19 = getelementptr inbounds %"struct.std::_Vector_base<float, std::allocator<float>>::_Vector_impl_data", ptr %18, i64 0, i32 1
  %20 = load ptr, ptr %19, align 8, !tbaa !11
  %21 = load ptr, ptr %18, align 8, !tbaa !13
  %22 = ptrtoint ptr %20 to i64
  %23 = ptrtoint ptr %21 to i64
  %24 = sub i64 %22, %23
  %25 = icmp eq ptr %20, %21
  br i1 %25, label %38, label %26

26:                                               ; preds = %1
  %27 = icmp ugt i64 %24, 9223372036854775804
  br i1 %27, label %28, label %29, !prof !35

28:                                               ; preds = %26
  tail call void @_ZSt28__throw_bad_array_new_lengthv() #16
  unreachable

29:                                               ; preds = %26
  %30 = tail call noalias noundef nonnull ptr @_Znwm(i64 noundef %24) #17
  %31 = load ptr, ptr %18, align 8, !tbaa !36
  %32 = load ptr, ptr %19, align 8, !tbaa !36
  %33 = icmp eq ptr %32, %31
  br i1 %33, label %38, label %34

34:                                               ; preds = %29
  %35 = ptrtoint ptr %32 to i64
  %36 = ptrtoint ptr %31 to i64
  %37 = sub i64 %35, %36
  tail call void @llvm.memmove.p0.p0.i64(ptr nonnull align 4 %30, ptr align 4 %31, i64 %37, i1 false)
  br label %38

38:                                               ; preds = %1, %29, %34
  %39 = phi ptr [ %30, %29 ], [ %30, %34 ], [ null, %1 ]
  %40 = load ptr, ptr %0, align 8, !tbaa !10
  %41 = getelementptr inbounds %"class.std::vector.0", ptr %40, i64 %17
  %42 = load ptr, ptr %41, align 8, !tbaa !36
  %43 = getelementptr inbounds %"struct.std::_Vector_base<float, std::allocator<float>>::_Vector_impl_data", ptr %41, i64 0, i32 1
  %44 = load ptr, ptr %43, align 8, !tbaa !36
  %45 = icmp eq ptr %42, %44
  %46 = getelementptr inbounds float, ptr %42, i64 1
  %47 = icmp eq ptr %46, %44
  %48 = select i1 %45, i1 true, i1 %47
  br i1 %48, label %61, label %49

49:                                               ; preds = %38
  %50 = load float, ptr %42, align 4, !tbaa !24
  br label %51

51:                                               ; preds = %51, %49
  %52 = phi float [ %57, %51 ], [ %50, %49 ]
  %53 = phi ptr [ %59, %51 ], [ %46, %49 ]
  %54 = phi ptr [ %58, %51 ], [ %42, %49 ]
  %55 = load float, ptr %53, align 4, !tbaa !24
  %56 = fcmp olt float %55, %52
  %57 = select i1 %56, float %55, float %52
  %58 = select i1 %56, ptr %53, ptr %54
  %59 = getelementptr inbounds float, ptr %53, i64 1
  %60 = icmp eq ptr %59, %44
  br i1 %60, label %61, label %51, !llvm.loop !37

61:                                               ; preds = %51, %38
  %62 = phi ptr [ %42, %38 ], [ %58, %51 ]
  %63 = ptrtoint ptr %62 to i64
  %64 = ptrtoint ptr %42 to i64
  %65 = sub i64 %63, %64
  %66 = icmp slt i32 %9, 1
  br i1 %66, label %67, label %69

67:                                               ; preds = %61
  invoke void @_ZSt20__throw_length_errorPKc(ptr noundef nonnull @.str.6) #16
          to label %68 unwind label %92

68:                                               ; preds = %67
  unreachable

69:                                               ; preds = %61
  %70 = icmp eq i32 %16, 0
  br i1 %70, label %190, label %71

71:                                               ; preds = %69
  %72 = shl nuw nsw i64 %17, 2
  %73 = invoke noalias noundef nonnull ptr @_Znwm(i64 noundef %72) #17
          to label %74 unwind label %92

74:                                               ; preds = %71
  store float 0.000000e+00, ptr %73, align 4, !tbaa !24
  %75 = icmp eq i32 %16, 1
  br i1 %75, label %79, label %76

76:                                               ; preds = %74
  %77 = getelementptr float, ptr %73, i64 1
  %78 = add nsw i64 %72, -4
  tail call void @llvm.memset.p0.i64(ptr align 4 %77, i8 0, i64 %78, i1 false), !tbaa !24
  br label %79

79:                                               ; preds = %76, %74
  %80 = load ptr, ptr %0, align 8, !tbaa !10
  %81 = shl i64 %15, 30
  %82 = add i64 %81, -4294967296
  %83 = ashr exact i64 %82, 32
  %84 = shl i64 %65, 30
  %85 = ashr exact i64 %84, 32
  %86 = zext i32 %16 to i64
  %87 = add nsw i64 %86, -1
  %88 = and i64 %86, 7
  %89 = icmp ult i64 %87, 7
  br i1 %89, label %172, label %90

90:                                               ; preds = %79
  %91 = and i64 %86, 4294967288
  br label %95

92:                                               ; preds = %71, %67
  %93 = landingpad { ptr, i32 }
          cleanup
  %94 = icmp eq ptr %39, null
  br i1 %94, label %195, label %194

95:                                               ; preds = %95, %90
  %96 = phi i64 [ 0, %90 ], [ %169, %95 ]
  %97 = phi i64 [ 0, %90 ], [ %170, %95 ]
  %98 = getelementptr inbounds %"class.std::vector.0", ptr %80, i64 %96
  %99 = load ptr, ptr %98, align 8, !tbaa !13
  %100 = getelementptr inbounds float, ptr %99, i64 %83
  %101 = load float, ptr %100, align 4, !tbaa !24
  %102 = getelementptr inbounds float, ptr %99, i64 %85
  %103 = load float, ptr %102, align 4, !tbaa !24
  %104 = fdiv float %101, %103
  %105 = getelementptr inbounds float, ptr %73, i64 %96
  store float %104, ptr %105, align 4, !tbaa !24
  %106 = or i64 %96, 1
  %107 = getelementptr inbounds %"class.std::vector.0", ptr %80, i64 %106
  %108 = load ptr, ptr %107, align 8, !tbaa !13
  %109 = getelementptr inbounds float, ptr %108, i64 %83
  %110 = load float, ptr %109, align 4, !tbaa !24
  %111 = getelementptr inbounds float, ptr %108, i64 %85
  %112 = load float, ptr %111, align 4, !tbaa !24
  %113 = fdiv float %110, %112
  %114 = getelementptr inbounds float, ptr %73, i64 %106
  store float %113, ptr %114, align 4, !tbaa !24
  %115 = or i64 %96, 2
  %116 = getelementptr inbounds %"class.std::vector.0", ptr %80, i64 %115
  %117 = load ptr, ptr %116, align 8, !tbaa !13
  %118 = getelementptr inbounds float, ptr %117, i64 %83
  %119 = load float, ptr %118, align 4, !tbaa !24
  %120 = getelementptr inbounds float, ptr %117, i64 %85
  %121 = load float, ptr %120, align 4, !tbaa !24
  %122 = fdiv float %119, %121
  %123 = getelementptr inbounds float, ptr %73, i64 %115
  store float %122, ptr %123, align 4, !tbaa !24
  %124 = or i64 %96, 3
  %125 = getelementptr inbounds %"class.std::vector.0", ptr %80, i64 %124
  %126 = load ptr, ptr %125, align 8, !tbaa !13
  %127 = getelementptr inbounds float, ptr %126, i64 %83
  %128 = load float, ptr %127, align 4, !tbaa !24
  %129 = getelementptr inbounds float, ptr %126, i64 %85
  %130 = load float, ptr %129, align 4, !tbaa !24
  %131 = fdiv float %128, %130
  %132 = getelementptr inbounds float, ptr %73, i64 %124
  store float %131, ptr %132, align 4, !tbaa !24
  %133 = or i64 %96, 4
  %134 = getelementptr inbounds %"class.std::vector.0", ptr %80, i64 %133
  %135 = load ptr, ptr %134, align 8, !tbaa !13
  %136 = getelementptr inbounds float, ptr %135, i64 %83
  %137 = load float, ptr %136, align 4, !tbaa !24
  %138 = getelementptr inbounds float, ptr %135, i64 %85
  %139 = load float, ptr %138, align 4, !tbaa !24
  %140 = fdiv float %137, %139
  %141 = getelementptr inbounds float, ptr %73, i64 %133
  store float %140, ptr %141, align 4, !tbaa !24
  %142 = or i64 %96, 5
  %143 = getelementptr inbounds %"class.std::vector.0", ptr %80, i64 %142
  %144 = load ptr, ptr %143, align 8, !tbaa !13
  %145 = getelementptr inbounds float, ptr %144, i64 %83
  %146 = load float, ptr %145, align 4, !tbaa !24
  %147 = getelementptr inbounds float, ptr %144, i64 %85
  %148 = load float, ptr %147, align 4, !tbaa !24
  %149 = fdiv float %146, %148
  %150 = getelementptr inbounds float, ptr %73, i64 %142
  store float %149, ptr %150, align 4, !tbaa !24
  %151 = or i64 %96, 6
  %152 = getelementptr inbounds %"class.std::vector.0", ptr %80, i64 %151
  %153 = load ptr, ptr %152, align 8, !tbaa !13
  %154 = getelementptr inbounds float, ptr %153, i64 %83
  %155 = load float, ptr %154, align 4, !tbaa !24
  %156 = getelementptr inbounds float, ptr %153, i64 %85
  %157 = load float, ptr %156, align 4, !tbaa !24
  %158 = fdiv float %155, %157
  %159 = getelementptr inbounds float, ptr %73, i64 %151
  store float %158, ptr %159, align 4, !tbaa !24
  %160 = or i64 %96, 7
  %161 = getelementptr inbounds %"class.std::vector.0", ptr %80, i64 %160
  %162 = load ptr, ptr %161, align 8, !tbaa !13
  %163 = getelementptr inbounds float, ptr %162, i64 %83
  %164 = load float, ptr %163, align 4, !tbaa !24
  %165 = getelementptr inbounds float, ptr %162, i64 %85
  %166 = load float, ptr %165, align 4, !tbaa !24
  %167 = fdiv float %164, %166
  %168 = getelementptr inbounds float, ptr %73, i64 %160
  store float %167, ptr %168, align 4, !tbaa !24
  %169 = add nuw nsw i64 %96, 8
  %170 = add i64 %97, 8
  %171 = icmp eq i64 %170, %91
  br i1 %171, label %172, label %95, !llvm.loop !38

172:                                              ; preds = %95, %79
  %173 = phi i64 [ 0, %79 ], [ %169, %95 ]
  %174 = icmp eq i64 %88, 0
  br i1 %174, label %189, label %175

175:                                              ; preds = %172, %175
  %176 = phi i64 [ %186, %175 ], [ %173, %172 ]
  %177 = phi i64 [ %187, %175 ], [ 0, %172 ]
  %178 = getelementptr inbounds %"class.std::vector.0", ptr %80, i64 %176
  %179 = load ptr, ptr %178, align 8, !tbaa !13
  %180 = getelementptr inbounds float, ptr %179, i64 %83
  %181 = load float, ptr %180, align 4, !tbaa !24
  %182 = getelementptr inbounds float, ptr %179, i64 %85
  %183 = load float, ptr %182, align 4, !tbaa !24
  %184 = fdiv float %181, %183
  %185 = getelementptr inbounds float, ptr %73, i64 %176
  store float %184, ptr %185, align 4, !tbaa !24
  %186 = add nuw nsw i64 %176, 1
  %187 = add i64 %177, 1
  %188 = icmp eq i64 %187, %88
  br i1 %188, label %189, label %175, !llvm.loop !39

189:                                              ; preds = %175, %172
  tail call void @_ZdlPv(ptr noundef nonnull %73) #18
  br label %190

190:                                              ; preds = %69, %189
  %191 = icmp eq ptr %39, null
  br i1 %191, label %193, label %192

192:                                              ; preds = %190
  tail call void @_ZdlPv(ptr noundef nonnull %39) #18
  br label %193

193:                                              ; preds = %190, %192
  ret void

194:                                              ; preds = %92
  tail call void @_ZdlPv(ptr noundef nonnull %39) #18
  br label %195

195:                                              ; preds = %92, %194
  resume { ptr, i32 } %93
}