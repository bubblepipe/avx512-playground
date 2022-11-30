; Function Attrs: mustprogress nofree nosync nounwind uwtable
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
  br i1 %21, label %22, label %429

22:                                               ; preds = %1
  %23 = and i64 %8, 4294967295
  %24 = and i64 %17, 4294967295
  %25 = add nsw i64 %24, -1
  %26 = add nsw i64 %23, -1
  %27 = and i64 %8, 3
  %28 = icmp ult i64 %26, 3
  br i1 %28, label %342, label %29

29:                                               ; preds = %22
  %30 = sub nsw i64 %23, %27
  %31 = and i64 %17, 7
  %32 = icmp ult i64 %25, 7
  %33 = sub nsw i64 %24, %31
  %34 = icmp eq i64 %31, 0
  %35 = and i64 %17, 7
  %36 = icmp ult i64 %25, 7
  %37 = sub nsw i64 %24, %35
  %38 = icmp eq i64 %35, 0
  %39 = and i64 %17, 7
  %40 = icmp ult i64 %25, 7
  %41 = sub nsw i64 %24, %39
  %42 = icmp eq i64 %39, 0
  %43 = and i64 %17, 7
  %44 = icmp ult i64 %25, 7
  %45 = sub nsw i64 %24, %43
  %46 = icmp eq i64 %43, 0
  br label %47

47:                                               ; preds = %338, %29
  %48 = phi i64 [ 0, %29 ], [ %339, %338 ]
  %49 = phi i64 [ 0, %29 ], [ %340, %338 ]
  %50 = icmp eq i64 %48, 0
  br i1 %50, label %122, label %51

51:                                               ; preds = %47
  %52 = getelementptr inbounds %"class.std::vector.0", ptr %4, i64 %48
  %53 = load ptr, ptr %52, align 8, !tbaa !13
  %54 = load float, ptr %53, align 4, !tbaa !24
  %55 = fneg float %54
  br i1 %32, label %109, label %56

56:                                               ; preds = %51, %56
  %57 = phi i64 [ %106, %56 ], [ 0, %51 ]
  %58 = phi i64 [ %107, %56 ], [ 0, %51 ]
  %59 = getelementptr inbounds float, ptr %53, i64 %57
  %60 = load float, ptr %59, align 4, !tbaa !24
  %61 = getelementptr inbounds float, ptr %12, i64 %57
  %62 = load float, ptr %61, align 4, !tbaa !24
  %63 = tail call float @llvm.fmuladd.f32(float %55, float %62, float %60)
  store float %63, ptr %59, align 4, !tbaa !24
  %64 = or i64 %57, 1
  %65 = getelementptr inbounds float, ptr %53, i64 %64
  %66 = load float, ptr %65, align 4, !tbaa !24
  %67 = getelementptr inbounds float, ptr %12, i64 %64
  %68 = load float, ptr %67, align 4, !tbaa !24
  %69 = tail call float @llvm.fmuladd.f32(float %55, float %68, float %66)
  store float %69, ptr %65, align 4, !tbaa !24
  %70 = or i64 %57, 2
  %71 = getelementptr inbounds float, ptr %53, i64 %70
  %72 = load float, ptr %71, align 4, !tbaa !24
  %73 = getelementptr inbounds float, ptr %12, i64 %70
  %74 = load float, ptr %73, align 4, !tbaa !24
  %75 = tail call float @llvm.fmuladd.f32(float %55, float %74, float %72)
  store float %75, ptr %71, align 4, !tbaa !24
  %76 = or i64 %57, 3
  %77 = getelementptr inbounds float, ptr %53, i64 %76
  %78 = load float, ptr %77, align 4, !tbaa !24
  %79 = getelementptr inbounds float, ptr %12, i64 %76
  %80 = load float, ptr %79, align 4, !tbaa !24
  %81 = tail call float @llvm.fmuladd.f32(float %55, float %80, float %78)
  store float %81, ptr %77, align 4, !tbaa !24
  %82 = or i64 %57, 4
  %83 = getelementptr inbounds float, ptr %53, i64 %82
  %84 = load float, ptr %83, align 4, !tbaa !24
  %85 = getelementptr inbounds float, ptr %12, i64 %82
  %86 = load float, ptr %85, align 4, !tbaa !24
  %87 = tail call float @llvm.fmuladd.f32(float %55, float %86, float %84)
  store float %87, ptr %83, align 4, !tbaa !24
  %88 = or i64 %57, 5
  %89 = getelementptr inbounds float, ptr %53, i64 %88
  %90 = load float, ptr %89, align 4, !tbaa !24
  %91 = getelementptr inbounds float, ptr %12, i64 %88
  %92 = load float, ptr %91, align 4, !tbaa !24
  %93 = tail call float @llvm.fmuladd.f32(float %55, float %92, float %90)
  store float %93, ptr %89, align 4, !tbaa !24
  %94 = or i64 %57, 6
  %95 = getelementptr inbounds float, ptr %53, i64 %94
  %96 = load float, ptr %95, align 4, !tbaa !24
  %97 = getelementptr inbounds float, ptr %12, i64 %94
  %98 = load float, ptr %97, align 4, !tbaa !24
  %99 = tail call float @llvm.fmuladd.f32(float %55, float %98, float %96)
  store float %99, ptr %95, align 4, !tbaa !24
  %100 = or i64 %57, 7
  %101 = getelementptr inbounds float, ptr %53, i64 %100
  %102 = load float, ptr %101, align 4, !tbaa !24
  %103 = getelementptr inbounds float, ptr %12, i64 %100
  %104 = load float, ptr %103, align 4, !tbaa !24
  %105 = tail call float @llvm.fmuladd.f32(float %55, float %104, float %102)
  store float %105, ptr %101, align 4, !tbaa !24
  %106 = add nuw nsw i64 %57, 8
  %107 = add i64 %58, 8
  %108 = icmp eq i64 %107, %33
  br i1 %108, label %109, label %56, !llvm.loop !35

109:                                              ; preds = %56, %51
  %110 = phi i64 [ 0, %51 ], [ %106, %56 ]
  br i1 %34, label %122, label %111

111:                                              ; preds = %109, %111
  %112 = phi i64 [ %119, %111 ], [ %110, %109 ]
  %113 = phi i64 [ %120, %111 ], [ 0, %109 ]
  %114 = getelementptr inbounds float, ptr %53, i64 %112
  %115 = load float, ptr %114, align 4, !tbaa !24
  %116 = getelementptr inbounds float, ptr %12, i64 %112
  %117 = load float, ptr %116, align 4, !tbaa !24
  %118 = tail call float @llvm.fmuladd.f32(float %55, float %117, float %115)
  store float %118, ptr %114, align 4, !tbaa !24
  %119 = add nuw nsw i64 %112, 1
  %120 = add i64 %113, 1
  %121 = icmp eq i64 %120, %31
  br i1 %121, label %122, label %111, !llvm.loop !36

122:                                              ; preds = %47, %111, %109
  %123 = or i64 %48, 1
  %124 = getelementptr inbounds %"class.std::vector.0", ptr %4, i64 %123
  %125 = load ptr, ptr %124, align 8, !tbaa !13
  %126 = load float, ptr %125, align 4, !tbaa !24
  %127 = fneg float %126
  br i1 %36, label %181, label %128

128:                                              ; preds = %122, %128
  %129 = phi i64 [ %178, %128 ], [ 0, %122 ]
  %130 = phi i64 [ %179, %128 ], [ 0, %122 ]
  %131 = getelementptr inbounds float, ptr %125, i64 %129
  %132 = load float, ptr %131, align 4, !tbaa !24
  %133 = getelementptr inbounds float, ptr %12, i64 %129
  %134 = load float, ptr %133, align 4, !tbaa !24
  %135 = tail call float @llvm.fmuladd.f32(float %127, float %134, float %132)
  store float %135, ptr %131, align 4, !tbaa !24
  %136 = or i64 %129, 1
  %137 = getelementptr inbounds float, ptr %125, i64 %136
  %138 = load float, ptr %137, align 4, !tbaa !24
  %139 = getelementptr inbounds float, ptr %12, i64 %136
  %140 = load float, ptr %139, align 4, !tbaa !24
  %141 = tail call float @llvm.fmuladd.f32(float %127, float %140, float %138)
  store float %141, ptr %137, align 4, !tbaa !24
  %142 = or i64 %129, 2
  %143 = getelementptr inbounds float, ptr %125, i64 %142
  %144 = load float, ptr %143, align 4, !tbaa !24
  %145 = getelementptr inbounds float, ptr %12, i64 %142
  %146 = load float, ptr %145, align 4, !tbaa !24
  %147 = tail call float @llvm.fmuladd.f32(float %127, float %146, float %144)
  store float %147, ptr %143, align 4, !tbaa !24
  %148 = or i64 %129, 3
  %149 = getelementptr inbounds float, ptr %125, i64 %148
  %150 = load float, ptr %149, align 4, !tbaa !24
  %151 = getelementptr inbounds float, ptr %12, i64 %148
  %152 = load float, ptr %151, align 4, !tbaa !24
  %153 = tail call float @llvm.fmuladd.f32(float %127, float %152, float %150)
  store float %153, ptr %149, align 4, !tbaa !24
  %154 = or i64 %129, 4
  %155 = getelementptr inbounds float, ptr %125, i64 %154
  %156 = load float, ptr %155, align 4, !tbaa !24
  %157 = getelementptr inbounds float, ptr %12, i64 %154
  %158 = load float, ptr %157, align 4, !tbaa !24
  %159 = tail call float @llvm.fmuladd.f32(float %127, float %158, float %156)
  store float %159, ptr %155, align 4, !tbaa !24
  %160 = or i64 %129, 5
  %161 = getelementptr inbounds float, ptr %125, i64 %160
  %162 = load float, ptr %161, align 4, !tbaa !24
  %163 = getelementptr inbounds float, ptr %12, i64 %160
  %164 = load float, ptr %163, align 4, !tbaa !24
  %165 = tail call float @llvm.fmuladd.f32(float %127, float %164, float %162)
  store float %165, ptr %161, align 4, !tbaa !24
  %166 = or i64 %129, 6
  %167 = getelementptr inbounds float, ptr %125, i64 %166
  %168 = load float, ptr %167, align 4, !tbaa !24
  %169 = getelementptr inbounds float, ptr %12, i64 %166
  %170 = load float, ptr %169, align 4, !tbaa !24
  %171 = tail call float @llvm.fmuladd.f32(float %127, float %170, float %168)
  store float %171, ptr %167, align 4, !tbaa !24
  %172 = or i64 %129, 7
  %173 = getelementptr inbounds float, ptr %125, i64 %172
  %174 = load float, ptr %173, align 4, !tbaa !24
  %175 = getelementptr inbounds float, ptr %12, i64 %172
  %176 = load float, ptr %175, align 4, !tbaa !24
  %177 = tail call float @llvm.fmuladd.f32(float %127, float %176, float %174)
  store float %177, ptr %173, align 4, !tbaa !24
  %178 = add nuw nsw i64 %129, 8
  %179 = add i64 %130, 8
  %180 = icmp eq i64 %179, %37
  br i1 %180, label %181, label %128, !llvm.loop !35

181:                                              ; preds = %128, %122
  %182 = phi i64 [ 0, %122 ], [ %178, %128 ]
  br i1 %38, label %194, label %183

183:                                              ; preds = %181, %183
  %184 = phi i64 [ %191, %183 ], [ %182, %181 ]
  %185 = phi i64 [ %192, %183 ], [ 0, %181 ]
  %186 = getelementptr inbounds float, ptr %125, i64 %184
  %187 = load float, ptr %186, align 4, !tbaa !24
  %188 = getelementptr inbounds float, ptr %12, i64 %184
  %189 = load float, ptr %188, align 4, !tbaa !24
  %190 = tail call float @llvm.fmuladd.f32(float %127, float %189, float %187)
  store float %190, ptr %186, align 4, !tbaa !24
  %191 = add nuw nsw i64 %184, 1
  %192 = add i64 %185, 1
  %193 = icmp eq i64 %192, %35
  br i1 %193, label %194, label %183, !llvm.loop !36

194:                                              ; preds = %183, %181
  %195 = or i64 %48, 2
  %196 = getelementptr inbounds %"class.std::vector.0", ptr %4, i64 %195
  %197 = load ptr, ptr %196, align 8, !tbaa !13
  %198 = load float, ptr %197, align 4, !tbaa !24
  %199 = fneg float %198
  br i1 %40, label %253, label %200

200:                                              ; preds = %194, %200
  %201 = phi i64 [ %250, %200 ], [ 0, %194 ]
  %202 = phi i64 [ %251, %200 ], [ 0, %194 ]
  %203 = getelementptr inbounds float, ptr %197, i64 %201
  %204 = load float, ptr %203, align 4, !tbaa !24
  %205 = getelementptr inbounds float, ptr %12, i64 %201
  %206 = load float, ptr %205, align 4, !tbaa !24
  %207 = tail call float @llvm.fmuladd.f32(float %199, float %206, float %204)
  store float %207, ptr %203, align 4, !tbaa !24
  %208 = or i64 %201, 1
  %209 = getelementptr inbounds float, ptr %197, i64 %208
  %210 = load float, ptr %209, align 4, !tbaa !24
  %211 = getelementptr inbounds float, ptr %12, i64 %208
  %212 = load float, ptr %211, align 4, !tbaa !24
  %213 = tail call float @llvm.fmuladd.f32(float %199, float %212, float %210)
  store float %213, ptr %209, align 4, !tbaa !24
  %214 = or i64 %201, 2
  %215 = getelementptr inbounds float, ptr %197, i64 %214
  %216 = load float, ptr %215, align 4, !tbaa !24
  %217 = getelementptr inbounds float, ptr %12, i64 %214
  %218 = load float, ptr %217, align 4, !tbaa !24
  %219 = tail call float @llvm.fmuladd.f32(float %199, float %218, float %216)
  store float %219, ptr %215, align 4, !tbaa !24
  %220 = or i64 %201, 3
  %221 = getelementptr inbounds float, ptr %197, i64 %220
  %222 = load float, ptr %221, align 4, !tbaa !24
  %223 = getelementptr inbounds float, ptr %12, i64 %220
  %224 = load float, ptr %223, align 4, !tbaa !24
  %225 = tail call float @llvm.fmuladd.f32(float %199, float %224, float %222)
  store float %225, ptr %221, align 4, !tbaa !24
  %226 = or i64 %201, 4
  %227 = getelementptr inbounds float, ptr %197, i64 %226
  %228 = load float, ptr %227, align 4, !tbaa !24
  %229 = getelementptr inbounds float, ptr %12, i64 %226
  %230 = load float, ptr %229, align 4, !tbaa !24
  %231 = tail call float @llvm.fmuladd.f32(float %199, float %230, float %228)
  store float %231, ptr %227, align 4, !tbaa !24
  %232 = or i64 %201, 5
  %233 = getelementptr inbounds float, ptr %197, i64 %232
  %234 = load float, ptr %233, align 4, !tbaa !24
  %235 = getelementptr inbounds float, ptr %12, i64 %232
  %236 = load float, ptr %235, align 4, !tbaa !24
  %237 = tail call float @llvm.fmuladd.f32(float %199, float %236, float %234)
  store float %237, ptr %233, align 4, !tbaa !24
  %238 = or i64 %201, 6
  %239 = getelementptr inbounds float, ptr %197, i64 %238
  %240 = load float, ptr %239, align 4, !tbaa !24
  %241 = getelementptr inbounds float, ptr %12, i64 %238
  %242 = load float, ptr %241, align 4, !tbaa !24
  %243 = tail call float @llvm.fmuladd.f32(float %199, float %242, float %240)
  store float %243, ptr %239, align 4, !tbaa !24
  %244 = or i64 %201, 7
  %245 = getelementptr inbounds float, ptr %197, i64 %244
  %246 = load float, ptr %245, align 4, !tbaa !24
  %247 = getelementptr inbounds float, ptr %12, i64 %244
  %248 = load float, ptr %247, align 4, !tbaa !24
  %249 = tail call float @llvm.fmuladd.f32(float %199, float %248, float %246)
  store float %249, ptr %245, align 4, !tbaa !24
  %250 = add nuw nsw i64 %201, 8
  %251 = add i64 %202, 8
  %252 = icmp eq i64 %251, %41
  br i1 %252, label %253, label %200, !llvm.loop !35

253:                                              ; preds = %200, %194
  %254 = phi i64 [ 0, %194 ], [ %250, %200 ]
  br i1 %42, label %266, label %255

255:                                              ; preds = %253, %255
  %256 = phi i64 [ %263, %255 ], [ %254, %253 ]
  %257 = phi i64 [ %264, %255 ], [ 0, %253 ]
  %258 = getelementptr inbounds float, ptr %197, i64 %256
  %259 = load float, ptr %258, align 4, !tbaa !24
  %260 = getelementptr inbounds float, ptr %12, i64 %256
  %261 = load float, ptr %260, align 4, !tbaa !24
  %262 = tail call float @llvm.fmuladd.f32(float %199, float %261, float %259)
  store float %262, ptr %258, align 4, !tbaa !24
  %263 = add nuw nsw i64 %256, 1
  %264 = add i64 %257, 1
  %265 = icmp eq i64 %264, %39
  br i1 %265, label %266, label %255, !llvm.loop !36

266:                                              ; preds = %255, %253
  %267 = or i64 %48, 3
  %268 = getelementptr inbounds %"class.std::vector.0", ptr %4, i64 %267
  %269 = load ptr, ptr %268, align 8, !tbaa !13
  %270 = load float, ptr %269, align 4, !tbaa !24
  %271 = fneg float %270
  br i1 %44, label %325, label %272

272:                                              ; preds = %266, %272
  %273 = phi i64 [ %322, %272 ], [ 0, %266 ]
  %274 = phi i64 [ %323, %272 ], [ 0, %266 ]
  %275 = getelementptr inbounds float, ptr %269, i64 %273
  %276 = load float, ptr %275, align 4, !tbaa !24
  %277 = getelementptr inbounds float, ptr %12, i64 %273
  %278 = load float, ptr %277, align 4, !tbaa !24
  %279 = tail call float @llvm.fmuladd.f32(float %271, float %278, float %276)
  store float %279, ptr %275, align 4, !tbaa !24
  %280 = or i64 %273, 1
  %281 = getelementptr inbounds float, ptr %269, i64 %280
  %282 = load float, ptr %281, align 4, !tbaa !24
  %283 = getelementptr inbounds float, ptr %12, i64 %280
  %284 = load float, ptr %283, align 4, !tbaa !24
  %285 = tail call float @llvm.fmuladd.f32(float %271, float %284, float %282)
  store float %285, ptr %281, align 4, !tbaa !24
  %286 = or i64 %273, 2
  %287 = getelementptr inbounds float, ptr %269, i64 %286
  %288 = load float, ptr %287, align 4, !tbaa !24
  %289 = getelementptr inbounds float, ptr %12, i64 %286
  %290 = load float, ptr %289, align 4, !tbaa !24
  %291 = tail call float @llvm.fmuladd.f32(float %271, float %290, float %288)
  store float %291, ptr %287, align 4, !tbaa !24
  %292 = or i64 %273, 3
  %293 = getelementptr inbounds float, ptr %269, i64 %292
  %294 = load float, ptr %293, align 4, !tbaa !24
  %295 = getelementptr inbounds float, ptr %12, i64 %292
  %296 = load float, ptr %295, align 4, !tbaa !24
  %297 = tail call float @llvm.fmuladd.f32(float %271, float %296, float %294)
  store float %297, ptr %293, align 4, !tbaa !24
  %298 = or i64 %273, 4
  %299 = getelementptr inbounds float, ptr %269, i64 %298
  %300 = load float, ptr %299, align 4, !tbaa !24
  %301 = getelementptr inbounds float, ptr %12, i64 %298
  %302 = load float, ptr %301, align 4, !tbaa !24
  %303 = tail call float @llvm.fmuladd.f32(float %271, float %302, float %300)
  store float %303, ptr %299, align 4, !tbaa !24
  %304 = or i64 %273, 5
  %305 = getelementptr inbounds float, ptr %269, i64 %304
  %306 = load float, ptr %305, align 4, !tbaa !24
  %307 = getelementptr inbounds float, ptr %12, i64 %304
  %308 = load float, ptr %307, align 4, !tbaa !24
  %309 = tail call float @llvm.fmuladd.f32(float %271, float %308, float %306)
  store float %309, ptr %305, align 4, !tbaa !24
  %310 = or i64 %273, 6
  %311 = getelementptr inbounds float, ptr %269, i64 %310
  %312 = load float, ptr %311, align 4, !tbaa !24
  %313 = getelementptr inbounds float, ptr %12, i64 %310
  %314 = load float, ptr %313, align 4, !tbaa !24
  %315 = tail call float @llvm.fmuladd.f32(float %271, float %314, float %312)
  store float %315, ptr %311, align 4, !tbaa !24
  %316 = or i64 %273, 7
  %317 = getelementptr inbounds float, ptr %269, i64 %316
  %318 = load float, ptr %317, align 4, !tbaa !24
  %319 = getelementptr inbounds float, ptr %12, i64 %316
  %320 = load float, ptr %319, align 4, !tbaa !24
  %321 = tail call float @llvm.fmuladd.f32(float %271, float %320, float %318)
  store float %321, ptr %317, align 4, !tbaa !24
  %322 = add nuw nsw i64 %273, 8
  %323 = add i64 %274, 8
  %324 = icmp eq i64 %323, %45
  br i1 %324, label %325, label %272, !llvm.loop !35

325:                                              ; preds = %272, %266
  %326 = phi i64 [ 0, %266 ], [ %322, %272 ]
  br i1 %46, label %338, label %327

327:                                              ; preds = %325, %327
  %328 = phi i64 [ %335, %327 ], [ %326, %325 ]
  %329 = phi i64 [ %336, %327 ], [ 0, %325 ]
  %330 = getelementptr inbounds float, ptr %269, i64 %328
  %331 = load float, ptr %330, align 4, !tbaa !24
  %332 = getelementptr inbounds float, ptr %12, i64 %328
  %333 = load float, ptr %332, align 4, !tbaa !24
  %334 = tail call float @llvm.fmuladd.f32(float %271, float %333, float %331)
  store float %334, ptr %330, align 4, !tbaa !24
  %335 = add nuw nsw i64 %328, 1
  %336 = add i64 %329, 1
  %337 = icmp eq i64 %336, %43
  br i1 %337, label %338, label %327, !llvm.loop !36

338:                                              ; preds = %325, %327
  %339 = add nuw nsw i64 %48, 4
  %340 = add i64 %49, 4
  %341 = icmp eq i64 %340, %30
  br i1 %341, label %342, label %47, !llvm.loop !38

342:                                              ; preds = %338, %22
  %343 = phi i64 [ 0, %22 ], [ %339, %338 ]
  %344 = icmp eq i64 %27, 0
  br i1 %344, label %429, label %345

345:                                              ; preds = %342
  %346 = and i64 %17, 7
  %347 = icmp ult i64 %25, 7
  %348 = sub nsw i64 %24, %346
  %349 = icmp eq i64 %346, 0
  br label %350

350:                                              ; preds = %425, %345
  %351 = phi i64 [ %343, %345 ], [ %426, %425 ]
  %352 = phi i64 [ 0, %345 ], [ %427, %425 ]
  %353 = icmp eq i64 %351, 0
  br i1 %353, label %425, label %354

354:                                              ; preds = %350
  %355 = getelementptr inbounds %"class.std::vector.0", ptr %4, i64 %351
  %356 = load ptr, ptr %355, align 8, !tbaa !13
  %357 = load float, ptr %356, align 4, !tbaa !24
  %358 = fneg float %357
  br i1 %347, label %412, label %359

359:                                              ; preds = %354, %359
  %360 = phi i64 [ %409, %359 ], [ 0, %354 ]
  %361 = phi i64 [ %410, %359 ], [ 0, %354 ]
  %362 = getelementptr inbounds float, ptr %356, i64 %360
  %363 = load float, ptr %362, align 4, !tbaa !24
  %364 = getelementptr inbounds float, ptr %12, i64 %360
  %365 = load float, ptr %364, align 4, !tbaa !24
  %366 = tail call float @llvm.fmuladd.f32(float %358, float %365, float %363)
  store float %366, ptr %362, align 4, !tbaa !24
  %367 = or i64 %360, 1
  %368 = getelementptr inbounds float, ptr %356, i64 %367
  %369 = load float, ptr %368, align 4, !tbaa !24
  %370 = getelementptr inbounds float, ptr %12, i64 %367
  %371 = load float, ptr %370, align 4, !tbaa !24
  %372 = tail call float @llvm.fmuladd.f32(float %358, float %371, float %369)
  store float %372, ptr %368, align 4, !tbaa !24
  %373 = or i64 %360, 2
  %374 = getelementptr inbounds float, ptr %356, i64 %373
  %375 = load float, ptr %374, align 4, !tbaa !24
  %376 = getelementptr inbounds float, ptr %12, i64 %373
  %377 = load float, ptr %376, align 4, !tbaa !24
  %378 = tail call float @llvm.fmuladd.f32(float %358, float %377, float %375)
  store float %378, ptr %374, align 4, !tbaa !24
  %379 = or i64 %360, 3
  %380 = getelementptr inbounds float, ptr %356, i64 %379
  %381 = load float, ptr %380, align 4, !tbaa !24
  %382 = getelementptr inbounds float, ptr %12, i64 %379
  %383 = load float, ptr %382, align 4, !tbaa !24
  %384 = tail call float @llvm.fmuladd.f32(float %358, float %383, float %381)
  store float %384, ptr %380, align 4, !tbaa !24
  %385 = or i64 %360, 4
  %386 = getelementptr inbounds float, ptr %356, i64 %385
  %387 = load float, ptr %386, align 4, !tbaa !24
  %388 = getelementptr inbounds float, ptr %12, i64 %385
  %389 = load float, ptr %388, align 4, !tbaa !24
  %390 = tail call float @llvm.fmuladd.f32(float %358, float %389, float %387)
  store float %390, ptr %386, align 4, !tbaa !24
  %391 = or i64 %360, 5
  %392 = getelementptr inbounds float, ptr %356, i64 %391
  %393 = load float, ptr %392, align 4, !tbaa !24
  %394 = getelementptr inbounds float, ptr %12, i64 %391
  %395 = load float, ptr %394, align 4, !tbaa !24
  %396 = tail call float @llvm.fmuladd.f32(float %358, float %395, float %393)
  store float %396, ptr %392, align 4, !tbaa !24
  %397 = or i64 %360, 6
  %398 = getelementptr inbounds float, ptr %356, i64 %397
  %399 = load float, ptr %398, align 4, !tbaa !24
  %400 = getelementptr inbounds float, ptr %12, i64 %397
  %401 = load float, ptr %400, align 4, !tbaa !24
  %402 = tail call float @llvm.fmuladd.f32(float %358, float %401, float %399)
  store float %402, ptr %398, align 4, !tbaa !24
  %403 = or i64 %360, 7
  %404 = getelementptr inbounds float, ptr %356, i64 %403
  %405 = load float, ptr %404, align 4, !tbaa !24
  %406 = getelementptr inbounds float, ptr %12, i64 %403
  %407 = load float, ptr %406, align 4, !tbaa !24
  %408 = tail call float @llvm.fmuladd.f32(float %358, float %407, float %405)
  store float %408, ptr %404, align 4, !tbaa !24
  %409 = add nuw nsw i64 %360, 8
  %410 = add i64 %361, 8
  %411 = icmp eq i64 %410, %348
  br i1 %411, label %412, label %359, !llvm.loop !35

412:                                              ; preds = %359, %354
  %413 = phi i64 [ 0, %354 ], [ %409, %359 ]
  br i1 %349, label %425, label %414

414:                                              ; preds = %412, %414
  %415 = phi i64 [ %422, %414 ], [ %413, %412 ]
  %416 = phi i64 [ %423, %414 ], [ 0, %412 ]
  %417 = getelementptr inbounds float, ptr %356, i64 %415
  %418 = load float, ptr %417, align 4, !tbaa !24
  %419 = getelementptr inbounds float, ptr %12, i64 %415
  %420 = load float, ptr %419, align 4, !tbaa !24
  %421 = tail call float @llvm.fmuladd.f32(float %358, float %420, float %418)
  store float %421, ptr %417, align 4, !tbaa !24
  %422 = add nuw nsw i64 %415, 1
  %423 = add i64 %416, 1
  %424 = icmp eq i64 %423, %346
  br i1 %424, label %425, label %414, !llvm.loop !36

425:                                              ; preds = %412, %414, %350
  %426 = add nuw nsw i64 %351, 1
  %427 = add i64 %352, 1
  %428 = icmp eq i64 %427, %27
  br i1 %428, label %429, label %350, !llvm.loop !39

429:                                              ; preds = %342, %425, %1
  ret void
}
