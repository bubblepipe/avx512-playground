define dso_local void @_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE(ptr nocapture noundef nonnull readonly align 8 dereferenceable(24) %0) local_unnamed_addr #5 {
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
  %16 = freeze i64 %15
  %17 = lshr i64 %16, 2
  %18 = icmp sgt i32 %9, 0
  %19 = trunc i64 %17 to i32
  %20 = icmp sgt i32 %19, 0
  %21 = and i1 %18, %20
  br i1 %21, label %22, label %651

22:                                               ; preds = %1
  %23 = and i64 %8, 4294967295
  %24 = and i64 %17, 4294967295
  %25 = shl nuw nsw i64 %24, 2
  %26 = getelementptr i8, ptr %12, i64 %25
  %27 = add nsw i64 %24, -1
  %28 = add nsw i64 %23, -1
  %29 = and i64 %8, 3
  %30 = icmp ult i64 %28, 3
  br i1 %30, label %520, label %31

31:                                               ; preds = %22
  %32 = sub nsw i64 %23, %29
  %33 = icmp ult i64 %24, 32
  %34 = and i64 %17, 31
  %35 = sub nsw i64 %24, %34
  %36 = icmp eq i64 %34, 0
  %37 = icmp ult i64 %24, 32
  %38 = and i64 %17, 31
  %39 = sub nsw i64 %24, %38
  %40 = icmp eq i64 %38, 0
  %41 = icmp ult i64 %24, 32
  %42 = and i64 %17, 31
  %43 = sub nsw i64 %24, %42
  %44 = icmp eq i64 %42, 0
  %45 = icmp ult i64 %24, 32
  %46 = and i64 %17, 31
  %47 = sub nsw i64 %24, %46
  %48 = icmp eq i64 %46, 0
  br label %49

49:                                               ; preds = %516, %31
  %50 = phi i64 [ 0, %31 ], [ %517, %516 ]
  %51 = phi i64 [ 0, %31 ], [ %518, %516 ]
  %52 = icmp eq i64 %50, 0
  br i1 %52, label %168, label %53

53:                                               ; preds = %49
  %54 = getelementptr inbounds %"class.std::vector.0", ptr %4, i64 %50
  %55 = load ptr, ptr %54, align 8, !tbaa !13
  %56 = load float, ptr %55, align 4, !tbaa !24
  %57 = fneg float %56
  br i1 %33, label %97, label %58

58:                                               ; preds = %53
  %59 = getelementptr i8, ptr %55, i64 %25
  %60 = icmp ult ptr %55, %26
  %61 = icmp ult ptr %12, %59
  %62 = and i1 %60, %61
  br i1 %62, label %97, label %63

63:                                               ; preds = %58
  %64 = insertelement <8 x float> poison, float %57, i64 0
  %65 = shufflevector <8 x float> %64, <8 x float> poison, <8 x i32> zeroinitializer
  %66 = insertelement <8 x float> poison, float %57, i64 0
  %67 = shufflevector <8 x float> %66, <8 x float> poison, <8 x i32> zeroinitializer
  %68 = insertelement <8 x float> poison, float %57, i64 0
  %69 = shufflevector <8 x float> %68, <8 x float> poison, <8 x i32> zeroinitializer
  %70 = insertelement <8 x float> poison, float %57, i64 0
  %71 = shufflevector <8 x float> %70, <8 x float> poison, <8 x i32> zeroinitializer
  br label %72

72:                                               ; preds = %72, %63
  %73 = phi i64 [ 0, %63 ], [ %94, %72 ]
  %74 = getelementptr inbounds float, ptr %55, i64 %73
  %75 = load <8 x float>, ptr %74, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %76 = getelementptr inbounds float, ptr %74, i64 8
  %77 = load <8 x float>, ptr %76, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %78 = getelementptr inbounds float, ptr %74, i64 16
  %79 = load <8 x float>, ptr %78, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %80 = getelementptr inbounds float, ptr %74, i64 24
  %81 = load <8 x float>, ptr %80, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %82 = getelementptr inbounds float, ptr %12, i64 %73
  %83 = load <8 x float>, ptr %82, align 4, !tbaa !24, !alias.scope !38
  %84 = getelementptr inbounds float, ptr %82, i64 8
  %85 = load <8 x float>, ptr %84, align 4, !tbaa !24, !alias.scope !38
  %86 = getelementptr inbounds float, ptr %82, i64 16
  %87 = load <8 x float>, ptr %86, align 4, !tbaa !24, !alias.scope !38
  %88 = getelementptr inbounds float, ptr %82, i64 24
  %89 = load <8 x float>, ptr %88, align 4, !tbaa !24, !alias.scope !38
  %90 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %65, <8 x float> %83, <8 x float> %75)
  %91 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %67, <8 x float> %85, <8 x float> %77)
  %92 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %69, <8 x float> %87, <8 x float> %79)
  %93 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %71, <8 x float> %89, <8 x float> %81)
  store <8 x float> %90, ptr %74, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %91, ptr %76, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %92, ptr %78, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %93, ptr %80, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %94 = add nuw i64 %73, 32
  %95 = icmp eq i64 %94, %35
  br i1 %95, label %96, label %72, !llvm.loop !40

96:                                               ; preds = %72
  br i1 %36, label %168, label %97

97:                                               ; preds = %58, %53, %96
  %98 = phi i64 [ 0, %58 ], [ 0, %53 ], [ %35, %96 ]
  %99 = sub nsw i64 %17, %98
  %100 = sub nsw i64 %27, %98
  %101 = and i64 %99, 7
  %102 = icmp eq i64 %101, 0
  br i1 %102, label %114, label %103

103:                                              ; preds = %97, %103
  %104 = phi i64 [ %111, %103 ], [ %98, %97 ]
  %105 = phi i64 [ %112, %103 ], [ 0, %97 ]
  %106 = getelementptr inbounds float, ptr %55, i64 %104
  %107 = load float, ptr %106, align 4, !tbaa !24
  %108 = getelementptr inbounds float, ptr %12, i64 %104
  %109 = load float, ptr %108, align 4, !tbaa !24
  %110 = tail call float @llvm.fmuladd.f32(float %57, float %109, float %107)
  store float %110, ptr %106, align 4, !tbaa !24
  %111 = add nuw nsw i64 %104, 1
  %112 = add i64 %105, 1
  %113 = icmp eq i64 %112, %101
  br i1 %113, label %114, label %103, !llvm.loop !42

114:                                              ; preds = %103, %97
  %115 = phi i64 [ %98, %97 ], [ %111, %103 ]
  %116 = icmp ult i64 %100, 7
  br i1 %116, label %168, label %117

117:                                              ; preds = %114, %117
  %118 = phi i64 [ %166, %117 ], [ %115, %114 ]
  %119 = getelementptr inbounds float, ptr %55, i64 %118
  %120 = load float, ptr %119, align 4, !tbaa !24
  %121 = getelementptr inbounds float, ptr %12, i64 %118
  %122 = load float, ptr %121, align 4, !tbaa !24
  %123 = tail call float @llvm.fmuladd.f32(float %57, float %122, float %120)
  store float %123, ptr %119, align 4, !tbaa !24
  %124 = add nuw nsw i64 %118, 1
  %125 = getelementptr inbounds float, ptr %55, i64 %124
  %126 = load float, ptr %125, align 4, !tbaa !24
  %127 = getelementptr inbounds float, ptr %12, i64 %124
  %128 = load float, ptr %127, align 4, !tbaa !24
  %129 = tail call float @llvm.fmuladd.f32(float %57, float %128, float %126)
  store float %129, ptr %125, align 4, !tbaa !24
  %130 = add nuw nsw i64 %118, 2
  %131 = getelementptr inbounds float, ptr %55, i64 %130
  %132 = load float, ptr %131, align 4, !tbaa !24
  %133 = getelementptr inbounds float, ptr %12, i64 %130
  %134 = load float, ptr %133, align 4, !tbaa !24
  %135 = tail call float @llvm.fmuladd.f32(float %57, float %134, float %132)
  store float %135, ptr %131, align 4, !tbaa !24
  %136 = add nuw nsw i64 %118, 3
  %137 = getelementptr inbounds float, ptr %55, i64 %136
  %138 = load float, ptr %137, align 4, !tbaa !24
  %139 = getelementptr inbounds float, ptr %12, i64 %136
  %140 = load float, ptr %139, align 4, !tbaa !24
  %141 = tail call float @llvm.fmuladd.f32(float %57, float %140, float %138)
  store float %141, ptr %137, align 4, !tbaa !24
  %142 = add nuw nsw i64 %118, 4
  %143 = getelementptr inbounds float, ptr %55, i64 %142
  %144 = load float, ptr %143, align 4, !tbaa !24
  %145 = getelementptr inbounds float, ptr %12, i64 %142
  %146 = load float, ptr %145, align 4, !tbaa !24
  %147 = tail call float @llvm.fmuladd.f32(float %57, float %146, float %144)
  store float %147, ptr %143, align 4, !tbaa !24
  %148 = add nuw nsw i64 %118, 5
  %149 = getelementptr inbounds float, ptr %55, i64 %148
  %150 = load float, ptr %149, align 4, !tbaa !24
  %151 = getelementptr inbounds float, ptr %12, i64 %148
  %152 = load float, ptr %151, align 4, !tbaa !24
  %153 = tail call float @llvm.fmuladd.f32(float %57, float %152, float %150)
  store float %153, ptr %149, align 4, !tbaa !24
  %154 = add nuw nsw i64 %118, 6
  %155 = getelementptr inbounds float, ptr %55, i64 %154
  %156 = load float, ptr %155, align 4, !tbaa !24
  %157 = getelementptr inbounds float, ptr %12, i64 %154
  %158 = load float, ptr %157, align 4, !tbaa !24
  %159 = tail call float @llvm.fmuladd.f32(float %57, float %158, float %156)
  store float %159, ptr %155, align 4, !tbaa !24
  %160 = add nuw nsw i64 %118, 7
  %161 = getelementptr inbounds float, ptr %55, i64 %160
  %162 = load float, ptr %161, align 4, !tbaa !24
  %163 = getelementptr inbounds float, ptr %12, i64 %160
  %164 = load float, ptr %163, align 4, !tbaa !24
  %165 = tail call float @llvm.fmuladd.f32(float %57, float %164, float %162)
  store float %165, ptr %161, align 4, !tbaa !24
  %166 = add nuw nsw i64 %118, 8
  %167 = icmp eq i64 %166, %24
  br i1 %167, label %168, label %117, !llvm.loop !44

168:                                              ; preds = %49, %96, %117, %114
  %169 = or i64 %50, 1
  %170 = getelementptr inbounds %"class.std::vector.0", ptr %4, i64 %169
  %171 = load ptr, ptr %170, align 8, !tbaa !13
  %172 = load float, ptr %171, align 4, !tbaa !24
  %173 = fneg float %172
  br i1 %37, label %213, label %174

174:                                              ; preds = %168
  %175 = getelementptr i8, ptr %171, i64 %25
  %176 = icmp ult ptr %171, %26
  %177 = icmp ult ptr %12, %175
  %178 = and i1 %176, %177
  br i1 %178, label %213, label %179

179:                                              ; preds = %174
  %180 = insertelement <8 x float> poison, float %173, i64 0
  %181 = shufflevector <8 x float> %180, <8 x float> poison, <8 x i32> zeroinitializer
  %182 = insertelement <8 x float> poison, float %173, i64 0
  %183 = shufflevector <8 x float> %182, <8 x float> poison, <8 x i32> zeroinitializer
  %184 = insertelement <8 x float> poison, float %173, i64 0
  %185 = shufflevector <8 x float> %184, <8 x float> poison, <8 x i32> zeroinitializer
  %186 = insertelement <8 x float> poison, float %173, i64 0
  %187 = shufflevector <8 x float> %186, <8 x float> poison, <8 x i32> zeroinitializer
  br label %188

188:                                              ; preds = %188, %179
  %189 = phi i64 [ 0, %179 ], [ %210, %188 ]
  %190 = getelementptr inbounds float, ptr %171, i64 %189
  %191 = load <8 x float>, ptr %190, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %192 = getelementptr inbounds float, ptr %190, i64 8
  %193 = load <8 x float>, ptr %192, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %194 = getelementptr inbounds float, ptr %190, i64 16
  %195 = load <8 x float>, ptr %194, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %196 = getelementptr inbounds float, ptr %190, i64 24
  %197 = load <8 x float>, ptr %196, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %198 = getelementptr inbounds float, ptr %12, i64 %189
  %199 = load <8 x float>, ptr %198, align 4, !tbaa !24, !alias.scope !38
  %200 = getelementptr inbounds float, ptr %198, i64 8
  %201 = load <8 x float>, ptr %200, align 4, !tbaa !24, !alias.scope !38
  %202 = getelementptr inbounds float, ptr %198, i64 16
  %203 = load <8 x float>, ptr %202, align 4, !tbaa !24, !alias.scope !38
  %204 = getelementptr inbounds float, ptr %198, i64 24
  %205 = load <8 x float>, ptr %204, align 4, !tbaa !24, !alias.scope !38
  %206 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %181, <8 x float> %199, <8 x float> %191)
  %207 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %183, <8 x float> %201, <8 x float> %193)
  %208 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %185, <8 x float> %203, <8 x float> %195)
  %209 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %187, <8 x float> %205, <8 x float> %197)
  store <8 x float> %206, ptr %190, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %207, ptr %192, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %208, ptr %194, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %209, ptr %196, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %210 = add nuw i64 %189, 32
  %211 = icmp eq i64 %210, %39
  br i1 %211, label %212, label %188, !llvm.loop !40

212:                                              ; preds = %188
  br i1 %40, label %284, label %213

213:                                              ; preds = %212, %174, %168
  %214 = phi i64 [ 0, %174 ], [ 0, %168 ], [ %39, %212 ]
  %215 = sub nsw i64 %17, %214
  %216 = sub nsw i64 %27, %214
  %217 = and i64 %215, 7
  %218 = icmp eq i64 %217, 0
  br i1 %218, label %230, label %219

219:                                              ; preds = %213, %219
  %220 = phi i64 [ %227, %219 ], [ %214, %213 ]
  %221 = phi i64 [ %228, %219 ], [ 0, %213 ]
  %222 = getelementptr inbounds float, ptr %171, i64 %220
  %223 = load float, ptr %222, align 4, !tbaa !24
  %224 = getelementptr inbounds float, ptr %12, i64 %220
  %225 = load float, ptr %224, align 4, !tbaa !24
  %226 = tail call float @llvm.fmuladd.f32(float %173, float %225, float %223)
  store float %226, ptr %222, align 4, !tbaa !24
  %227 = add nuw nsw i64 %220, 1
  %228 = add i64 %221, 1
  %229 = icmp eq i64 %228, %217
  br i1 %229, label %230, label %219, !llvm.loop !42

230:                                              ; preds = %219, %213
  %231 = phi i64 [ %214, %213 ], [ %227, %219 ]
  %232 = icmp ult i64 %216, 7
  br i1 %232, label %284, label %233

233:                                              ; preds = %230, %233
  %234 = phi i64 [ %282, %233 ], [ %231, %230 ]
  %235 = getelementptr inbounds float, ptr %171, i64 %234
  %236 = load float, ptr %235, align 4, !tbaa !24
  %237 = getelementptr inbounds float, ptr %12, i64 %234
  %238 = load float, ptr %237, align 4, !tbaa !24
  %239 = tail call float @llvm.fmuladd.f32(float %173, float %238, float %236)
  store float %239, ptr %235, align 4, !tbaa !24
  %240 = add nuw nsw i64 %234, 1
  %241 = getelementptr inbounds float, ptr %171, i64 %240
  %242 = load float, ptr %241, align 4, !tbaa !24
  %243 = getelementptr inbounds float, ptr %12, i64 %240
  %244 = load float, ptr %243, align 4, !tbaa !24
  %245 = tail call float @llvm.fmuladd.f32(float %173, float %244, float %242)
  store float %245, ptr %241, align 4, !tbaa !24
  %246 = add nuw nsw i64 %234, 2
  %247 = getelementptr inbounds float, ptr %171, i64 %246
  %248 = load float, ptr %247, align 4, !tbaa !24
  %249 = getelementptr inbounds float, ptr %12, i64 %246
  %250 = load float, ptr %249, align 4, !tbaa !24
  %251 = tail call float @llvm.fmuladd.f32(float %173, float %250, float %248)
  store float %251, ptr %247, align 4, !tbaa !24
  %252 = add nuw nsw i64 %234, 3
  %253 = getelementptr inbounds float, ptr %171, i64 %252
  %254 = load float, ptr %253, align 4, !tbaa !24
  %255 = getelementptr inbounds float, ptr %12, i64 %252
  %256 = load float, ptr %255, align 4, !tbaa !24
  %257 = tail call float @llvm.fmuladd.f32(float %173, float %256, float %254)
  store float %257, ptr %253, align 4, !tbaa !24
  %258 = add nuw nsw i64 %234, 4
  %259 = getelementptr inbounds float, ptr %171, i64 %258
  %260 = load float, ptr %259, align 4, !tbaa !24
  %261 = getelementptr inbounds float, ptr %12, i64 %258
  %262 = load float, ptr %261, align 4, !tbaa !24
  %263 = tail call float @llvm.fmuladd.f32(float %173, float %262, float %260)
  store float %263, ptr %259, align 4, !tbaa !24
  %264 = add nuw nsw i64 %234, 5
  %265 = getelementptr inbounds float, ptr %171, i64 %264
  %266 = load float, ptr %265, align 4, !tbaa !24
  %267 = getelementptr inbounds float, ptr %12, i64 %264
  %268 = load float, ptr %267, align 4, !tbaa !24
  %269 = tail call float @llvm.fmuladd.f32(float %173, float %268, float %266)
  store float %269, ptr %265, align 4, !tbaa !24
  %270 = add nuw nsw i64 %234, 6
  %271 = getelementptr inbounds float, ptr %171, i64 %270
  %272 = load float, ptr %271, align 4, !tbaa !24
  %273 = getelementptr inbounds float, ptr %12, i64 %270
  %274 = load float, ptr %273, align 4, !tbaa !24
  %275 = tail call float @llvm.fmuladd.f32(float %173, float %274, float %272)
  store float %275, ptr %271, align 4, !tbaa !24
  %276 = add nuw nsw i64 %234, 7
  %277 = getelementptr inbounds float, ptr %171, i64 %276
  %278 = load float, ptr %277, align 4, !tbaa !24
  %279 = getelementptr inbounds float, ptr %12, i64 %276
  %280 = load float, ptr %279, align 4, !tbaa !24
  %281 = tail call float @llvm.fmuladd.f32(float %173, float %280, float %278)
  store float %281, ptr %277, align 4, !tbaa !24
  %282 = add nuw nsw i64 %234, 8
  %283 = icmp eq i64 %282, %24
  br i1 %283, label %284, label %233, !llvm.loop !44

284:                                              ; preds = %212, %233, %230
  %285 = or i64 %50, 2
  %286 = getelementptr inbounds %"class.std::vector.0", ptr %4, i64 %285
  %287 = load ptr, ptr %286, align 8, !tbaa !13
  %288 = load float, ptr %287, align 4, !tbaa !24
  %289 = fneg float %288
  br i1 %41, label %329, label %290

290:                                              ; preds = %284
  %291 = getelementptr i8, ptr %287, i64 %25
  %292 = icmp ult ptr %287, %26
  %293 = icmp ult ptr %12, %291
  %294 = and i1 %292, %293
  br i1 %294, label %329, label %295

295:                                              ; preds = %290
  %296 = insertelement <8 x float> poison, float %289, i64 0
  %297 = shufflevector <8 x float> %296, <8 x float> poison, <8 x i32> zeroinitializer
  %298 = insertelement <8 x float> poison, float %289, i64 0
  %299 = shufflevector <8 x float> %298, <8 x float> poison, <8 x i32> zeroinitializer
  %300 = insertelement <8 x float> poison, float %289, i64 0
  %301 = shufflevector <8 x float> %300, <8 x float> poison, <8 x i32> zeroinitializer
  %302 = insertelement <8 x float> poison, float %289, i64 0
  %303 = shufflevector <8 x float> %302, <8 x float> poison, <8 x i32> zeroinitializer
  br label %304

304:                                              ; preds = %304, %295
  %305 = phi i64 [ 0, %295 ], [ %326, %304 ]
  %306 = getelementptr inbounds float, ptr %287, i64 %305
  %307 = load <8 x float>, ptr %306, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %308 = getelementptr inbounds float, ptr %306, i64 8
  %309 = load <8 x float>, ptr %308, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %310 = getelementptr inbounds float, ptr %306, i64 16
  %311 = load <8 x float>, ptr %310, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %312 = getelementptr inbounds float, ptr %306, i64 24
  %313 = load <8 x float>, ptr %312, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %314 = getelementptr inbounds float, ptr %12, i64 %305
  %315 = load <8 x float>, ptr %314, align 4, !tbaa !24, !alias.scope !38
  %316 = getelementptr inbounds float, ptr %314, i64 8
  %317 = load <8 x float>, ptr %316, align 4, !tbaa !24, !alias.scope !38
  %318 = getelementptr inbounds float, ptr %314, i64 16
  %319 = load <8 x float>, ptr %318, align 4, !tbaa !24, !alias.scope !38
  %320 = getelementptr inbounds float, ptr %314, i64 24
  %321 = load <8 x float>, ptr %320, align 4, !tbaa !24, !alias.scope !38
  %322 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %297, <8 x float> %315, <8 x float> %307)
  %323 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %299, <8 x float> %317, <8 x float> %309)
  %324 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %301, <8 x float> %319, <8 x float> %311)
  %325 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %303, <8 x float> %321, <8 x float> %313)
  store <8 x float> %322, ptr %306, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %323, ptr %308, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %324, ptr %310, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %325, ptr %312, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %326 = add nuw i64 %305, 32
  %327 = icmp eq i64 %326, %43
  br i1 %327, label %328, label %304, !llvm.loop !40

328:                                              ; preds = %304
  br i1 %44, label %400, label %329

329:                                              ; preds = %328, %290, %284
  %330 = phi i64 [ 0, %290 ], [ 0, %284 ], [ %43, %328 ]
  %331 = sub nsw i64 %17, %330
  %332 = sub nsw i64 %27, %330
  %333 = and i64 %331, 7
  %334 = icmp eq i64 %333, 0
  br i1 %334, label %346, label %335

335:                                              ; preds = %329, %335
  %336 = phi i64 [ %343, %335 ], [ %330, %329 ]
  %337 = phi i64 [ %344, %335 ], [ 0, %329 ]
  %338 = getelementptr inbounds float, ptr %287, i64 %336
  %339 = load float, ptr %338, align 4, !tbaa !24
  %340 = getelementptr inbounds float, ptr %12, i64 %336
  %341 = load float, ptr %340, align 4, !tbaa !24
  %342 = tail call float @llvm.fmuladd.f32(float %289, float %341, float %339)
  store float %342, ptr %338, align 4, !tbaa !24
  %343 = add nuw nsw i64 %336, 1
  %344 = add i64 %337, 1
  %345 = icmp eq i64 %344, %333
  br i1 %345, label %346, label %335, !llvm.loop !42

346:                                              ; preds = %335, %329
  %347 = phi i64 [ %330, %329 ], [ %343, %335 ]
  %348 = icmp ult i64 %332, 7
  br i1 %348, label %400, label %349

349:                                              ; preds = %346, %349
  %350 = phi i64 [ %398, %349 ], [ %347, %346 ]
  %351 = getelementptr inbounds float, ptr %287, i64 %350
  %352 = load float, ptr %351, align 4, !tbaa !24
  %353 = getelementptr inbounds float, ptr %12, i64 %350
  %354 = load float, ptr %353, align 4, !tbaa !24
  %355 = tail call float @llvm.fmuladd.f32(float %289, float %354, float %352)
  store float %355, ptr %351, align 4, !tbaa !24
  %356 = add nuw nsw i64 %350, 1
  %357 = getelementptr inbounds float, ptr %287, i64 %356
  %358 = load float, ptr %357, align 4, !tbaa !24
  %359 = getelementptr inbounds float, ptr %12, i64 %356
  %360 = load float, ptr %359, align 4, !tbaa !24
  %361 = tail call float @llvm.fmuladd.f32(float %289, float %360, float %358)
  store float %361, ptr %357, align 4, !tbaa !24
  %362 = add nuw nsw i64 %350, 2
  %363 = getelementptr inbounds float, ptr %287, i64 %362
  %364 = load float, ptr %363, align 4, !tbaa !24
  %365 = getelementptr inbounds float, ptr %12, i64 %362
  %366 = load float, ptr %365, align 4, !tbaa !24
  %367 = tail call float @llvm.fmuladd.f32(float %289, float %366, float %364)
  store float %367, ptr %363, align 4, !tbaa !24
  %368 = add nuw nsw i64 %350, 3
  %369 = getelementptr inbounds float, ptr %287, i64 %368
  %370 = load float, ptr %369, align 4, !tbaa !24
  %371 = getelementptr inbounds float, ptr %12, i64 %368
  %372 = load float, ptr %371, align 4, !tbaa !24
  %373 = tail call float @llvm.fmuladd.f32(float %289, float %372, float %370)
  store float %373, ptr %369, align 4, !tbaa !24
  %374 = add nuw nsw i64 %350, 4
  %375 = getelementptr inbounds float, ptr %287, i64 %374
  %376 = load float, ptr %375, align 4, !tbaa !24
  %377 = getelementptr inbounds float, ptr %12, i64 %374
  %378 = load float, ptr %377, align 4, !tbaa !24
  %379 = tail call float @llvm.fmuladd.f32(float %289, float %378, float %376)
  store float %379, ptr %375, align 4, !tbaa !24
  %380 = add nuw nsw i64 %350, 5
  %381 = getelementptr inbounds float, ptr %287, i64 %380
  %382 = load float, ptr %381, align 4, !tbaa !24
  %383 = getelementptr inbounds float, ptr %12, i64 %380
  %384 = load float, ptr %383, align 4, !tbaa !24
  %385 = tail call float @llvm.fmuladd.f32(float %289, float %384, float %382)
  store float %385, ptr %381, align 4, !tbaa !24
  %386 = add nuw nsw i64 %350, 6
  %387 = getelementptr inbounds float, ptr %287, i64 %386
  %388 = load float, ptr %387, align 4, !tbaa !24
  %389 = getelementptr inbounds float, ptr %12, i64 %386
  %390 = load float, ptr %389, align 4, !tbaa !24
  %391 = tail call float @llvm.fmuladd.f32(float %289, float %390, float %388)
  store float %391, ptr %387, align 4, !tbaa !24
  %392 = add nuw nsw i64 %350, 7
  %393 = getelementptr inbounds float, ptr %287, i64 %392
  %394 = load float, ptr %393, align 4, !tbaa !24
  %395 = getelementptr inbounds float, ptr %12, i64 %392
  %396 = load float, ptr %395, align 4, !tbaa !24
  %397 = tail call float @llvm.fmuladd.f32(float %289, float %396, float %394)
  store float %397, ptr %393, align 4, !tbaa !24
  %398 = add nuw nsw i64 %350, 8
  %399 = icmp eq i64 %398, %24
  br i1 %399, label %400, label %349, !llvm.loop !44

400:                                              ; preds = %328, %349, %346
  %401 = or i64 %50, 3
  %402 = getelementptr inbounds %"class.std::vector.0", ptr %4, i64 %401
  %403 = load ptr, ptr %402, align 8, !tbaa !13
  %404 = load float, ptr %403, align 4, !tbaa !24
  %405 = fneg float %404
  br i1 %45, label %445, label %406

406:                                              ; preds = %400
  %407 = getelementptr i8, ptr %403, i64 %25
  %408 = icmp ult ptr %403, %26
  %409 = icmp ult ptr %12, %407
  %410 = and i1 %408, %409
  br i1 %410, label %445, label %411

411:                                              ; preds = %406
  %412 = insertelement <8 x float> poison, float %405, i64 0
  %413 = shufflevector <8 x float> %412, <8 x float> poison, <8 x i32> zeroinitializer
  %414 = insertelement <8 x float> poison, float %405, i64 0
  %415 = shufflevector <8 x float> %414, <8 x float> poison, <8 x i32> zeroinitializer
  %416 = insertelement <8 x float> poison, float %405, i64 0
  %417 = shufflevector <8 x float> %416, <8 x float> poison, <8 x i32> zeroinitializer
  %418 = insertelement <8 x float> poison, float %405, i64 0
  %419 = shufflevector <8 x float> %418, <8 x float> poison, <8 x i32> zeroinitializer
  br label %420

420:                                              ; preds = %420, %411
  %421 = phi i64 [ 0, %411 ], [ %442, %420 ]
  %422 = getelementptr inbounds float, ptr %403, i64 %421
  %423 = load <8 x float>, ptr %422, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %424 = getelementptr inbounds float, ptr %422, i64 8
  %425 = load <8 x float>, ptr %424, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %426 = getelementptr inbounds float, ptr %422, i64 16
  %427 = load <8 x float>, ptr %426, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %428 = getelementptr inbounds float, ptr %422, i64 24
  %429 = load <8 x float>, ptr %428, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %430 = getelementptr inbounds float, ptr %12, i64 %421
  %431 = load <8 x float>, ptr %430, align 4, !tbaa !24, !alias.scope !38
  %432 = getelementptr inbounds float, ptr %430, i64 8
  %433 = load <8 x float>, ptr %432, align 4, !tbaa !24, !alias.scope !38
  %434 = getelementptr inbounds float, ptr %430, i64 16
  %435 = load <8 x float>, ptr %434, align 4, !tbaa !24, !alias.scope !38
  %436 = getelementptr inbounds float, ptr %430, i64 24
  %437 = load <8 x float>, ptr %436, align 4, !tbaa !24, !alias.scope !38
  %438 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %413, <8 x float> %431, <8 x float> %423)
  %439 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %415, <8 x float> %433, <8 x float> %425)
  %440 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %417, <8 x float> %435, <8 x float> %427)
  %441 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %419, <8 x float> %437, <8 x float> %429)
  store <8 x float> %438, ptr %422, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %439, ptr %424, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %440, ptr %426, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %441, ptr %428, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %442 = add nuw i64 %421, 32
  %443 = icmp eq i64 %442, %47
  br i1 %443, label %444, label %420, !llvm.loop !40

444:                                              ; preds = %420
  br i1 %48, label %516, label %445

445:                                              ; preds = %444, %406, %400
  %446 = phi i64 [ 0, %406 ], [ 0, %400 ], [ %47, %444 ]
  %447 = sub nsw i64 %17, %446
  %448 = sub nsw i64 %27, %446
  %449 = and i64 %447, 7
  %450 = icmp eq i64 %449, 0
  br i1 %450, label %462, label %451

451:                                              ; preds = %445, %451
  %452 = phi i64 [ %459, %451 ], [ %446, %445 ]
  %453 = phi i64 [ %460, %451 ], [ 0, %445 ]
  %454 = getelementptr inbounds float, ptr %403, i64 %452
  %455 = load float, ptr %454, align 4, !tbaa !24
  %456 = getelementptr inbounds float, ptr %12, i64 %452
  %457 = load float, ptr %456, align 4, !tbaa !24
  %458 = tail call float @llvm.fmuladd.f32(float %405, float %457, float %455)
  store float %458, ptr %454, align 4, !tbaa !24
  %459 = add nuw nsw i64 %452, 1
  %460 = add i64 %453, 1
  %461 = icmp eq i64 %460, %449
  br i1 %461, label %462, label %451, !llvm.loop !42

462:                                              ; preds = %451, %445
  %463 = phi i64 [ %446, %445 ], [ %459, %451 ]
  %464 = icmp ult i64 %448, 7
  br i1 %464, label %516, label %465

465:                                              ; preds = %462, %465
  %466 = phi i64 [ %514, %465 ], [ %463, %462 ]
  %467 = getelementptr inbounds float, ptr %403, i64 %466
  %468 = load float, ptr %467, align 4, !tbaa !24
  %469 = getelementptr inbounds float, ptr %12, i64 %466
  %470 = load float, ptr %469, align 4, !tbaa !24
  %471 = tail call float @llvm.fmuladd.f32(float %405, float %470, float %468)
  store float %471, ptr %467, align 4, !tbaa !24
  %472 = add nuw nsw i64 %466, 1
  %473 = getelementptr inbounds float, ptr %403, i64 %472
  %474 = load float, ptr %473, align 4, !tbaa !24
  %475 = getelementptr inbounds float, ptr %12, i64 %472
  %476 = load float, ptr %475, align 4, !tbaa !24
  %477 = tail call float @llvm.fmuladd.f32(float %405, float %476, float %474)
  store float %477, ptr %473, align 4, !tbaa !24
  %478 = add nuw nsw i64 %466, 2
  %479 = getelementptr inbounds float, ptr %403, i64 %478
  %480 = load float, ptr %479, align 4, !tbaa !24
  %481 = getelementptr inbounds float, ptr %12, i64 %478
  %482 = load float, ptr %481, align 4, !tbaa !24
  %483 = tail call float @llvm.fmuladd.f32(float %405, float %482, float %480)
  store float %483, ptr %479, align 4, !tbaa !24
  %484 = add nuw nsw i64 %466, 3
  %485 = getelementptr inbounds float, ptr %403, i64 %484
  %486 = load float, ptr %485, align 4, !tbaa !24
  %487 = getelementptr inbounds float, ptr %12, i64 %484
  %488 = load float, ptr %487, align 4, !tbaa !24
  %489 = tail call float @llvm.fmuladd.f32(float %405, float %488, float %486)
  store float %489, ptr %485, align 4, !tbaa !24
  %490 = add nuw nsw i64 %466, 4
  %491 = getelementptr inbounds float, ptr %403, i64 %490
  %492 = load float, ptr %491, align 4, !tbaa !24
  %493 = getelementptr inbounds float, ptr %12, i64 %490
  %494 = load float, ptr %493, align 4, !tbaa !24
  %495 = tail call float @llvm.fmuladd.f32(float %405, float %494, float %492)
  store float %495, ptr %491, align 4, !tbaa !24
  %496 = add nuw nsw i64 %466, 5
  %497 = getelementptr inbounds float, ptr %403, i64 %496
  %498 = load float, ptr %497, align 4, !tbaa !24
  %499 = getelementptr inbounds float, ptr %12, i64 %496
  %500 = load float, ptr %499, align 4, !tbaa !24
  %501 = tail call float @llvm.fmuladd.f32(float %405, float %500, float %498)
  store float %501, ptr %497, align 4, !tbaa !24
  %502 = add nuw nsw i64 %466, 6
  %503 = getelementptr inbounds float, ptr %403, i64 %502
  %504 = load float, ptr %503, align 4, !tbaa !24
  %505 = getelementptr inbounds float, ptr %12, i64 %502
  %506 = load float, ptr %505, align 4, !tbaa !24
  %507 = tail call float @llvm.fmuladd.f32(float %405, float %506, float %504)
  store float %507, ptr %503, align 4, !tbaa !24
  %508 = add nuw nsw i64 %466, 7
  %509 = getelementptr inbounds float, ptr %403, i64 %508
  %510 = load float, ptr %509, align 4, !tbaa !24
  %511 = getelementptr inbounds float, ptr %12, i64 %508
  %512 = load float, ptr %511, align 4, !tbaa !24
  %513 = tail call float @llvm.fmuladd.f32(float %405, float %512, float %510)
  store float %513, ptr %509, align 4, !tbaa !24
  %514 = add nuw nsw i64 %466, 8
  %515 = icmp eq i64 %514, %24
  br i1 %515, label %516, label %465, !llvm.loop !44

516:                                              ; preds = %462, %465, %444
  %517 = add nuw nsw i64 %50, 4
  %518 = add i64 %51, 4
  %519 = icmp eq i64 %518, %32
  br i1 %519, label %520, label %49, !llvm.loop !45

520:                                              ; preds = %516, %22
  %521 = phi i64 [ 0, %22 ], [ %517, %516 ]
  %522 = icmp eq i64 %29, 0
  br i1 %522, label %651, label %523

523:                                              ; preds = %520
  %524 = icmp ult i64 %24, 32
  %525 = and i64 %17, 31
  %526 = sub nsw i64 %24, %525
  %527 = icmp eq i64 %525, 0
  br label %528

528:                                              ; preds = %647, %523
  %529 = phi i64 [ %521, %523 ], [ %648, %647 ]
  %530 = phi i64 [ 0, %523 ], [ %649, %647 ]
  %531 = icmp eq i64 %529, 0
  br i1 %531, label %647, label %532

532:                                              ; preds = %528
  %533 = getelementptr inbounds %"class.std::vector.0", ptr %4, i64 %529
  %534 = load ptr, ptr %533, align 8, !tbaa !13
  %535 = load float, ptr %534, align 4, !tbaa !24
  %536 = fneg float %535
  br i1 %524, label %576, label %537

537:                                              ; preds = %532
  %538 = getelementptr i8, ptr %534, i64 %25
  %539 = icmp ult ptr %534, %26
  %540 = icmp ult ptr %12, %538
  %541 = and i1 %539, %540
  br i1 %541, label %576, label %542

542:                                              ; preds = %537
  %543 = insertelement <8 x float> poison, float %536, i64 0
  %544 = shufflevector <8 x float> %543, <8 x float> poison, <8 x i32> zeroinitializer
  %545 = insertelement <8 x float> poison, float %536, i64 0
  %546 = shufflevector <8 x float> %545, <8 x float> poison, <8 x i32> zeroinitializer
  %547 = insertelement <8 x float> poison, float %536, i64 0
  %548 = shufflevector <8 x float> %547, <8 x float> poison, <8 x i32> zeroinitializer
  %549 = insertelement <8 x float> poison, float %536, i64 0
  %550 = shufflevector <8 x float> %549, <8 x float> poison, <8 x i32> zeroinitializer
  br label %551

551:                                              ; preds = %551, %542
  %552 = phi i64 [ 0, %542 ], [ %573, %551 ]
  %553 = getelementptr inbounds float, ptr %534, i64 %552
  %554 = load <8 x float>, ptr %553, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %555 = getelementptr inbounds float, ptr %553, i64 8
  %556 = load <8 x float>, ptr %555, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %557 = getelementptr inbounds float, ptr %553, i64 16
  %558 = load <8 x float>, ptr %557, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %559 = getelementptr inbounds float, ptr %553, i64 24
  %560 = load <8 x float>, ptr %559, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %561 = getelementptr inbounds float, ptr %12, i64 %552
  %562 = load <8 x float>, ptr %561, align 4, !tbaa !24, !alias.scope !38
  %563 = getelementptr inbounds float, ptr %561, i64 8
  %564 = load <8 x float>, ptr %563, align 4, !tbaa !24, !alias.scope !38
  %565 = getelementptr inbounds float, ptr %561, i64 16
  %566 = load <8 x float>, ptr %565, align 4, !tbaa !24, !alias.scope !38
  %567 = getelementptr inbounds float, ptr %561, i64 24
  %568 = load <8 x float>, ptr %567, align 4, !tbaa !24, !alias.scope !38
  %569 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %544, <8 x float> %562, <8 x float> %554)
  %570 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %546, <8 x float> %564, <8 x float> %556)
  %571 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %548, <8 x float> %566, <8 x float> %558)
  %572 = tail call <8 x float> @llvm.fmuladd.v8f32(<8 x float> %550, <8 x float> %568, <8 x float> %560)
  store <8 x float> %569, ptr %553, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %570, ptr %555, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %571, ptr %557, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  store <8 x float> %572, ptr %559, align 4, !tbaa !24, !alias.scope !35, !noalias !38
  %573 = add nuw i64 %552, 32
  %574 = icmp eq i64 %573, %526
  br i1 %574, label %575, label %551, !llvm.loop !40

575:                                              ; preds = %551
  br i1 %527, label %647, label %576

576:                                              ; preds = %575, %537, %532
  %577 = phi i64 [ 0, %537 ], [ 0, %532 ], [ %526, %575 ]
  %578 = sub nsw i64 %17, %577
  %579 = sub nsw i64 %27, %577
  %580 = and i64 %578, 7
  %581 = icmp eq i64 %580, 0
  br i1 %581, label %593, label %582

582:                                              ; preds = %576, %582
  %583 = phi i64 [ %590, %582 ], [ %577, %576 ]
  %584 = phi i64 [ %591, %582 ], [ 0, %576 ]
  %585 = getelementptr inbounds float, ptr %534, i64 %583
  %586 = load float, ptr %585, align 4, !tbaa !24
  %587 = getelementptr inbounds float, ptr %12, i64 %583
  %588 = load float, ptr %587, align 4, !tbaa !24
  %589 = tail call float @llvm.fmuladd.f32(float %536, float %588, float %586)
  store float %589, ptr %585, align 4, !tbaa !24
  %590 = add nuw nsw i64 %583, 1
  %591 = add i64 %584, 1
  %592 = icmp eq i64 %591, %580
  br i1 %592, label %593, label %582, !llvm.loop !42

593:                                              ; preds = %582, %576
  %594 = phi i64 [ %577, %576 ], [ %590, %582 ]
  %595 = icmp ult i64 %579, 7
  br i1 %595, label %647, label %596

596:                                              ; preds = %593, %596
  %597 = phi i64 [ %645, %596 ], [ %594, %593 ]
  %598 = getelementptr inbounds float, ptr %534, i64 %597
  %599 = load float, ptr %598, align 4, !tbaa !24
  %600 = getelementptr inbounds float, ptr %12, i64 %597
  %601 = load float, ptr %600, align 4, !tbaa !24
  %602 = tail call float @llvm.fmuladd.f32(float %536, float %601, float %599)
  store float %602, ptr %598, align 4, !tbaa !24
  %603 = add nuw nsw i64 %597, 1
  %604 = getelementptr inbounds float, ptr %534, i64 %603
  %605 = load float, ptr %604, align 4, !tbaa !24
  %606 = getelementptr inbounds float, ptr %12, i64 %603
  %607 = load float, ptr %606, align 4, !tbaa !24
  %608 = tail call float @llvm.fmuladd.f32(float %536, float %607, float %605)
  store float %608, ptr %604, align 4, !tbaa !24
  %609 = add nuw nsw i64 %597, 2
  %610 = getelementptr inbounds float, ptr %534, i64 %609
  %611 = load float, ptr %610, align 4, !tbaa !24
  %612 = getelementptr inbounds float, ptr %12, i64 %609
  %613 = load float, ptr %612, align 4, !tbaa !24
  %614 = tail call float @llvm.fmuladd.f32(float %536, float %613, float %611)
  store float %614, ptr %610, align 4, !tbaa !24
  %615 = add nuw nsw i64 %597, 3
  %616 = getelementptr inbounds float, ptr %534, i64 %615
  %617 = load float, ptr %616, align 4, !tbaa !24
  %618 = getelementptr inbounds float, ptr %12, i64 %615
  %619 = load float, ptr %618, align 4, !tbaa !24
  %620 = tail call float @llvm.fmuladd.f32(float %536, float %619, float %617)
  store float %620, ptr %616, align 4, !tbaa !24
  %621 = add nuw nsw i64 %597, 4
  %622 = getelementptr inbounds float, ptr %534, i64 %621
  %623 = load float, ptr %622, align 4, !tbaa !24
  %624 = getelementptr inbounds float, ptr %12, i64 %621
  %625 = load float, ptr %624, align 4, !tbaa !24
  %626 = tail call float @llvm.fmuladd.f32(float %536, float %625, float %623)
  store float %626, ptr %622, align 4, !tbaa !24
  %627 = add nuw nsw i64 %597, 5
  %628 = getelementptr inbounds float, ptr %534, i64 %627
  %629 = load float, ptr %628, align 4, !tbaa !24
  %630 = getelementptr inbounds float, ptr %12, i64 %627
  %631 = load float, ptr %630, align 4, !tbaa !24
  %632 = tail call float @llvm.fmuladd.f32(float %536, float %631, float %629)
  store float %632, ptr %628, align 4, !tbaa !24
  %633 = add nuw nsw i64 %597, 6
  %634 = getelementptr inbounds float, ptr %534, i64 %633
  %635 = load float, ptr %634, align 4, !tbaa !24
  %636 = getelementptr inbounds float, ptr %12, i64 %633
  %637 = load float, ptr %636, align 4, !tbaa !24
  %638 = tail call float @llvm.fmuladd.f32(float %536, float %637, float %635)
  store float %638, ptr %634, align 4, !tbaa !24
  %639 = add nuw nsw i64 %597, 7
  %640 = getelementptr inbounds float, ptr %534, i64 %639
  %641 = load float, ptr %640, align 4, !tbaa !24
  %642 = getelementptr inbounds float, ptr %12, i64 %639
  %643 = load float, ptr %642, align 4, !tbaa !24
  %644 = tail call float @llvm.fmuladd.f32(float %536, float %643, float %641)
  store float %644, ptr %640, align 4, !tbaa !24
  %645 = add nuw nsw i64 %597, 8
  %646 = icmp eq i64 %645, %24
  br i1 %646, label %647, label %596, !llvm.loop !44

647:                                              ; preds = %593, %596, %575, %528
  %648 = add nuw nsw i64 %529, 1
  %649 = add i64 %530, 1
  %650 = icmp eq i64 %649, %29
  br i1 %650, label %651, label %528, !llvm.loop !46

651:                                              ; preds = %520, %647, %1
  ret void
}
