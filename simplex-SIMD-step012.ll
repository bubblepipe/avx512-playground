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
  %16 = freeze i64 %15
  %17 = lshr i64 %16, 2
  %18 = trunc i64 %17 to i32
  %19 = add nsw i32 %9, -1
  %20 = sext i32 %19 to i64
  %21 = getelementptr inbounds %"class.std::vector.0", ptr %4, i64 %20
  %22 = getelementptr inbounds %"struct.std::_Vector_base<float, std::allocator<float>>::_Vector_impl_data", ptr %21, i64 0, i32 1
  %23 = load ptr, ptr %22, align 8, !tbaa !11
  %24 = load ptr, ptr %21, align 8, !tbaa !13
  %25 = ptrtoint ptr %23 to i64
  %26 = ptrtoint ptr %24 to i64
  %27 = sub i64 %25, %26
  %28 = icmp eq ptr %23, %24
  br i1 %28, label %41, label %29

29:                                               ; preds = %1
  %30 = icmp ugt i64 %27, 9223372036854775804
  br i1 %30, label %31, label %32, !prof !35

31:                                               ; preds = %29
  tail call void @_ZSt28__throw_bad_array_new_lengthv() #17
  unreachable

32:                                               ; preds = %29
  %33 = tail call noalias noundef nonnull ptr @_Znwm(i64 noundef %27) #18
  %34 = load ptr, ptr %21, align 8, !tbaa !36
  %35 = load ptr, ptr %22, align 8, !tbaa !36
  %36 = icmp eq ptr %35, %34
  br i1 %36, label %41, label %37

37:                                               ; preds = %32
  %38 = ptrtoint ptr %35 to i64
  %39 = ptrtoint ptr %34 to i64
  %40 = sub i64 %38, %39
  tail call void @llvm.memmove.p0.p0.i64(ptr nonnull align 4 %33, ptr align 4 %34, i64 %40, i1 false)
  br label %41

41:                                               ; preds = %1, %32, %37
  %42 = phi ptr [ %33, %32 ], [ %33, %37 ], [ null, %1 ]
  %43 = load ptr, ptr %0, align 8, !tbaa !10
  %44 = getelementptr inbounds %"class.std::vector.0", ptr %43, i64 %20
  %45 = load ptr, ptr %44, align 8, !tbaa !36
  %46 = getelementptr inbounds %"struct.std::_Vector_base<float, std::allocator<float>>::_Vector_impl_data", ptr %44, i64 0, i32 1
  %47 = load ptr, ptr %46, align 8, !tbaa !36
  %48 = icmp eq ptr %45, %47
  %49 = getelementptr inbounds float, ptr %45, i64 1
  %50 = icmp eq ptr %49, %47
  %51 = select i1 %48, i1 true, i1 %50
  br i1 %51, label %64, label %52

52:                                               ; preds = %41
  %53 = load float, ptr %45, align 4, !tbaa !24
  br label %54

54:                                               ; preds = %54, %52
  %55 = phi float [ %60, %54 ], [ %53, %52 ]
  %56 = phi ptr [ %62, %54 ], [ %49, %52 ]
  %57 = phi ptr [ %61, %54 ], [ %45, %52 ]
  %58 = load float, ptr %56, align 4, !tbaa !24
  %59 = fcmp olt float %58, %55
  %60 = select i1 %59, float %58, float %55
  %61 = select i1 %59, ptr %56, ptr %57
  %62 = getelementptr inbounds float, ptr %56, i64 1
  %63 = icmp eq ptr %62, %47
  br i1 %63, label %64, label %54, !llvm.loop !37

64:                                               ; preds = %54, %41
  %65 = phi ptr [ %45, %41 ], [ %61, %54 ]
  %66 = ptrtoint ptr %65 to i64
  %67 = ptrtoint ptr %45 to i64
  %68 = sub i64 %66, %67
  %69 = icmp slt i32 %9, 1
  br i1 %69, label %70, label %72

70:                                               ; preds = %64
  invoke void @_ZSt20__throw_length_errorPKc(ptr noundef nonnull @.str.6) #17
          to label %71 unwind label %131

71:                                               ; preds = %70
  unreachable

72:                                               ; preds = %64
  %73 = icmp eq i32 %19, 0
  br i1 %73, label %211, label %74

74:                                               ; preds = %72
  %75 = shl nuw nsw i64 %20, 2
  %76 = invoke noalias noundef nonnull ptr @_Znwm(i64 noundef %75) #18
          to label %77 unwind label %131

77:                                               ; preds = %74
  store float 0.000000e+00, ptr %76, align 4, !tbaa !24
  %78 = getelementptr float, ptr %76, i64 1
  %79 = icmp eq i32 %19, 1
  br i1 %79, label %83, label %80

80:                                               ; preds = %77
  %81 = getelementptr inbounds float, ptr %76, i64 %20
  %82 = add nsw i64 %75, -4
  tail call void @llvm.memset.p0.i64(ptr align 4 %78, i8 0, i64 %82, i1 false), !tbaa !24
  br label %83

83:                                               ; preds = %80, %77
  %84 = phi ptr [ %81, %80 ], [ %78, %77 ]
  %85 = load ptr, ptr %0, align 8, !tbaa !10
  %86 = shl i64 %16, 30
  %87 = add i64 %86, -4294967296
  %88 = ashr exact i64 %87, 32
  %89 = shl i64 %68, 30
  %90 = ashr exact i64 %89, 32
  %91 = zext i32 %19 to i64
  %92 = add nsw i64 %91, -1
  %93 = and i64 %91, 7
  %94 = icmp ult i64 %92, 7
  br i1 %94, label %97, label %95

95:                                               ; preds = %83
  %96 = and i64 %91, 4294967288
  br label %134

97:                                               ; preds = %134, %83
  %98 = phi i64 [ 0, %83 ], [ %208, %134 ]
  %99 = icmp eq i64 %93, 0
  br i1 %99, label %114, label %100

100:                                              ; preds = %97, %100
  %101 = phi i64 [ %111, %100 ], [ %98, %97 ]
  %102 = phi i64 [ %112, %100 ], [ 0, %97 ]
  %103 = getelementptr inbounds %"class.std::vector.0", ptr %85, i64 %101
  %104 = load ptr, ptr %103, align 8, !tbaa !13
  %105 = getelementptr inbounds float, ptr %104, i64 %88
  %106 = load float, ptr %105, align 4, !tbaa !24
  %107 = getelementptr inbounds float, ptr %104, i64 %90
  %108 = load float, ptr %107, align 4, !tbaa !24
  %109 = fdiv float %106, %108
  %110 = getelementptr inbounds float, ptr %76, i64 %101
  store float %109, ptr %110, align 4, !tbaa !24
  %111 = add nuw nsw i64 %101, 1
  %112 = add i64 %102, 1
  %113 = icmp eq i64 %112, %93
  br i1 %113, label %114, label %100, !llvm.loop !38

114:                                              ; preds = %100, %97
  %115 = icmp eq ptr %76, %84
  %116 = getelementptr inbounds float, ptr %76, i64 1
  %117 = icmp eq ptr %116, %84
  %118 = select i1 %115, i1 true, i1 %117
  br i1 %118, label %211, label %119

119:                                              ; preds = %114
  %120 = load float, ptr %76, align 4, !tbaa !24
  br label %121

121:                                              ; preds = %121, %119
  %122 = phi float [ %127, %121 ], [ %120, %119 ]
  %123 = phi ptr [ %129, %121 ], [ %116, %119 ]
  %124 = phi ptr [ %128, %121 ], [ %76, %119 ]
  %125 = load float, ptr %123, align 4, !tbaa !24
  %126 = fcmp olt float %125, %122
  %127 = select i1 %126, float %125, float %122
  %128 = select i1 %126, ptr %123, ptr %124
  %129 = getelementptr inbounds float, ptr %123, i64 1
  %130 = icmp eq ptr %129, %84
  br i1 %130, label %211, label %121, !llvm.loop !37

131:                                              ; preds = %74, %70
  %132 = landingpad { ptr, i32 }
          cleanup
  %133 = icmp eq ptr %42, null
  br i1 %133, label %921, label %920

134:                                              ; preds = %134, %95
  %135 = phi i64 [ 0, %95 ], [ %208, %134 ]
  %136 = phi i64 [ 0, %95 ], [ %209, %134 ]
  %137 = getelementptr inbounds %"class.std::vector.0", ptr %85, i64 %135
  %138 = load ptr, ptr %137, align 8, !tbaa !13
  %139 = getelementptr inbounds float, ptr %138, i64 %88
  %140 = load float, ptr %139, align 4, !tbaa !24
  %141 = getelementptr inbounds float, ptr %138, i64 %90
  %142 = load float, ptr %141, align 4, !tbaa !24
  %143 = fdiv float %140, %142
  %144 = getelementptr inbounds float, ptr %76, i64 %135
  store float %143, ptr %144, align 4, !tbaa !24
  %145 = or i64 %135, 1
  %146 = getelementptr inbounds %"class.std::vector.0", ptr %85, i64 %145
  %147 = load ptr, ptr %146, align 8, !tbaa !13
  %148 = getelementptr inbounds float, ptr %147, i64 %88
  %149 = load float, ptr %148, align 4, !tbaa !24
  %150 = getelementptr inbounds float, ptr %147, i64 %90
  %151 = load float, ptr %150, align 4, !tbaa !24
  %152 = fdiv float %149, %151
  %153 = getelementptr inbounds float, ptr %76, i64 %145
  store float %152, ptr %153, align 4, !tbaa !24
  %154 = or i64 %135, 2
  %155 = getelementptr inbounds %"class.std::vector.0", ptr %85, i64 %154
  %156 = load ptr, ptr %155, align 8, !tbaa !13
  %157 = getelementptr inbounds float, ptr %156, i64 %88
  %158 = load float, ptr %157, align 4, !tbaa !24
  %159 = getelementptr inbounds float, ptr %156, i64 %90
  %160 = load float, ptr %159, align 4, !tbaa !24
  %161 = fdiv float %158, %160
  %162 = getelementptr inbounds float, ptr %76, i64 %154
  store float %161, ptr %162, align 4, !tbaa !24
  %163 = or i64 %135, 3
  %164 = getelementptr inbounds %"class.std::vector.0", ptr %85, i64 %163
  %165 = load ptr, ptr %164, align 8, !tbaa !13
  %166 = getelementptr inbounds float, ptr %165, i64 %88
  %167 = load float, ptr %166, align 4, !tbaa !24
  %168 = getelementptr inbounds float, ptr %165, i64 %90
  %169 = load float, ptr %168, align 4, !tbaa !24
  %170 = fdiv float %167, %169
  %171 = getelementptr inbounds float, ptr %76, i64 %163
  store float %170, ptr %171, align 4, !tbaa !24
  %172 = or i64 %135, 4
  %173 = getelementptr inbounds %"class.std::vector.0", ptr %85, i64 %172
  %174 = load ptr, ptr %173, align 8, !tbaa !13
  %175 = getelementptr inbounds float, ptr %174, i64 %88
  %176 = load float, ptr %175, align 4, !tbaa !24
  %177 = getelementptr inbounds float, ptr %174, i64 %90
  %178 = load float, ptr %177, align 4, !tbaa !24
  %179 = fdiv float %176, %178
  %180 = getelementptr inbounds float, ptr %76, i64 %172
  store float %179, ptr %180, align 4, !tbaa !24
  %181 = or i64 %135, 5
  %182 = getelementptr inbounds %"class.std::vector.0", ptr %85, i64 %181
  %183 = load ptr, ptr %182, align 8, !tbaa !13
  %184 = getelementptr inbounds float, ptr %183, i64 %88
  %185 = load float, ptr %184, align 4, !tbaa !24
  %186 = getelementptr inbounds float, ptr %183, i64 %90
  %187 = load float, ptr %186, align 4, !tbaa !24
  %188 = fdiv float %185, %187
  %189 = getelementptr inbounds float, ptr %76, i64 %181
  store float %188, ptr %189, align 4, !tbaa !24
  %190 = or i64 %135, 6
  %191 = getelementptr inbounds %"class.std::vector.0", ptr %85, i64 %190
  %192 = load ptr, ptr %191, align 8, !tbaa !13
  %193 = getelementptr inbounds float, ptr %192, i64 %88
  %194 = load float, ptr %193, align 4, !tbaa !24
  %195 = getelementptr inbounds float, ptr %192, i64 %90
  %196 = load float, ptr %195, align 4, !tbaa !24
  %197 = fdiv float %194, %196
  %198 = getelementptr inbounds float, ptr %76, i64 %190
  store float %197, ptr %198, align 4, !tbaa !24
  %199 = or i64 %135, 7
  %200 = getelementptr inbounds %"class.std::vector.0", ptr %85, i64 %199
  %201 = load ptr, ptr %200, align 8, !tbaa !13
  %202 = getelementptr inbounds float, ptr %201, i64 %88
  %203 = load float, ptr %202, align 4, !tbaa !24
  %204 = getelementptr inbounds float, ptr %201, i64 %90
  %205 = load float, ptr %204, align 4, !tbaa !24
  %206 = fdiv float %203, %205
  %207 = getelementptr inbounds float, ptr %76, i64 %199
  store float %206, ptr %207, align 4, !tbaa !24
  %208 = add nuw nsw i64 %135, 8
  %209 = add i64 %136, 8
  %210 = icmp eq i64 %209, %96
  br i1 %210, label %97, label %134, !llvm.loop !40

211:                                              ; preds = %121, %72, %114
  %212 = phi ptr [ %76, %114 ], [ null, %72 ], [ %76, %121 ]
  %213 = phi ptr [ %76, %114 ], [ null, %72 ], [ %128, %121 ]
  %214 = ptrtoint ptr %213 to i64
  %215 = ptrtoint ptr %212 to i64
  %216 = sub i64 %214, %215
  %217 = lshr exact i64 %216, 2
  %218 = shl i64 %216, 30
  %219 = ashr exact i64 %218, 32
  %220 = load ptr, ptr %0, align 8, !tbaa !10
  %221 = getelementptr inbounds %"class.std::vector.0", ptr %220, i64 %219
  %222 = shl i64 %68, 30
  %223 = ashr exact i64 %222, 32
  %224 = load ptr, ptr %221, align 8, !tbaa !13
  %225 = getelementptr inbounds float, ptr %224, i64 %223
  %226 = load float, ptr %225, align 4, !tbaa !24
  %227 = icmp sgt i32 %18, 0
  br i1 %227, label %228, label %913

228:                                              ; preds = %211
  %229 = and i64 %17, 4294967295
  %230 = icmp ult i64 %229, 32
  br i1 %230, label %260, label %231

231:                                              ; preds = %228
  %232 = and i64 %17, 31
  %233 = sub nsw i64 %229, %232
  %234 = insertelement <8 x float> poison, float %226, i64 0
  %235 = shufflevector <8 x float> %234, <8 x float> poison, <8 x i32> zeroinitializer
  %236 = insertelement <8 x float> poison, float %226, i64 0
  %237 = shufflevector <8 x float> %236, <8 x float> poison, <8 x i32> zeroinitializer
  %238 = insertelement <8 x float> poison, float %226, i64 0
  %239 = shufflevector <8 x float> %238, <8 x float> poison, <8 x i32> zeroinitializer
  %240 = insertelement <8 x float> poison, float %226, i64 0
  %241 = shufflevector <8 x float> %240, <8 x float> poison, <8 x i32> zeroinitializer
  br label %242

;;;; this block is part 1 ;;;;
242:                                              ; preds = %242, %231
  %243 = phi i64 [ 0, %231 ], [ %256, %242 ]
  %244 = getelementptr inbounds float, ptr %224, i64 %243
  %245 = load <8 x float>, ptr %244, align 4, !tbaa !24
  %246 = getelementptr inbounds float, ptr %244, i64 8
  %247 = load <8 x float>, ptr %246, align 4, !tbaa !24
  %248 = getelementptr inbounds float, ptr %244, i64 16
  %249 = load <8 x float>, ptr %248, align 4, !tbaa !24
  %250 = getelementptr inbounds float, ptr %244, i64 24
  %251 = load <8 x float>, ptr %250, align 4, !tbaa !24
  %252 = fdiv <8 x float> %245, %235
  %253 = fdiv <8 x float> %247, %237
  %254 = fdiv <8 x float> %249, %239
  %255 = fdiv <8 x float> %251, %241
  store <8 x float> %252, ptr %244, align 4, !tbaa !24
  store <8 x float> %253, ptr %246, align 4, !tbaa !24
  store <8 x float> %254, ptr %248, align 4, !tbaa !24
  store <8 x float> %255, ptr %250, align 4, !tbaa !24
  %256 = add nuw i64 %243, 32
  %257 = icmp eq i64 %256, %233
  br i1 %257, label %258, label %242, !llvm.loop !41

258:                                              ; preds = %242
  %259 = icmp eq i64 %232, 0
  br i1 %259, label %262, label %260

260:                                              ; preds = %228, %258
  %261 = phi i64 [ 0, %228 ], [ %233, %258 ]
  br label %774

262:                                              ; preds = %774, %258
  %263 = icmp sgt i32 %9, 0
  %264 = and i1 %227, %263
  br i1 %264, label %265, label %913

265:                                              ; preds = %262
  %266 = and i64 %217, 4294967295
  %267 = and i64 %8, 4294967295
  %268 = and i64 %17, 4294967295
  %269 = shl nuw nsw i64 %229, 2
  %270 = getelementptr i8, ptr %224, i64 %269
  %271 = add nsw i64 %229, -1
  %272 = add nsw i64 %267, -1
  %273 = and i64 %8, 3
  %274 = icmp ult i64 %272, 3
  br i1 %274, label %781, label %275

275:                                              ; preds = %265
  %276 = sub nsw i64 %267, %273
  %277 = icmp ult i64 %229, 32
  %278 = and i64 %17, 31
  %279 = sub nsw i64 %229, %278
  %280 = icmp eq i64 %278, 0
  %281 = icmp ult i64 %229, 32
  %282 = and i64 %17, 31
  %283 = sub nsw i64 %229, %282
  %284 = icmp eq i64 %282, 0
  %285 = icmp ult i64 %229, 32
  %286 = and i64 %17, 31
  %287 = sub nsw i64 %229, %286
  %288 = icmp eq i64 %286, 0
  %289 = icmp ult i64 %229, 32
  %290 = and i64 %17, 31
  %291 = sub nsw i64 %229, %290
  %292 = icmp eq i64 %290, 0
  br label %293

293:                                              ; preds = %770, %275
  %294 = phi i64 [ 0, %275 ], [ %771, %770 ]
  %295 = phi i64 [ 0, %275 ], [ %772, %770 ]
  %296 = icmp eq i64 %294, %266
  br i1 %296, label %413, label %297

297:                                              ; preds = %293
  %298 = getelementptr inbounds %"class.std::vector.0", ptr %220, i64 %294
  %299 = load ptr, ptr %298, align 8, !tbaa !13
  %300 = getelementptr inbounds float, ptr %299, i64 %223
  %301 = load float, ptr %300, align 4, !tbaa !24
  %302 = fneg float %301
  br i1 %277, label %342, label %303

303:                                              ; preds = %297
  %304 = getelementptr i8, ptr %299, i64 %269
  %305 = icmp ult ptr %299, %270
  %306 = icmp ult ptr %224, %304
  %307 = and i1 %305, %306
  br i1 %307, label %342, label %308

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
