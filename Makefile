CC=clang++-17

# CFLAGS=-O3 -march=native -I src/ -fno-omit-frame-pointer -std=c++17 -Wno-format 
CFLAGS=-O3 -march=native -I src/ -fno-omit-frame-pointer -std=c++17 
CFLAGS_no_vec=-O3 -mno-avx -mno-sse -march=native -I src/ -fno-omit-frame-pointer -std=c++17
# CFLAGS=-O0 -march=native -I src/ -fno-omit-frame-pointer -std=c++17 -g

INC_GBENCH=-isystem include/benchmark/include
INC_LIBSIMDPP=-I ./include/libsimdpp

INC += $(INC_LIBSIMDPP)
INC += $(INC_GBENCH)

LINK=-L include/benchmark/build/src -lbenchmark -lpthread 

# export BENCH_SIZE="-D SIZE_BIG"
# export BENCH_SIZE="-D SIZE_MODERATE"
# export BENCH_SIZE="-D SIZE_8_16_32"
# export BENCH_SIZE=""
CFLAGS+=${BENCH_SIZE}


# export AVX512_ENABLED="-D AVX512_ENABLED"
# export AVX512_ENABLED=""
CFLAGS+=${AVX512_ENABLED}

OUT=build/


# pivot
################################################################################
pivot:
	$(CC) $(CFLAGS) src/bench_pivot/main.cpp -o $(OUT)$@ $(INC) $(LINK)


# float toys
################################################################################

cast_int64_to_float rand_int_float_int test_all_int52 i16u32 doubledouble fe_inexact clang-overflow ifma:
	$(CC) $(CFLAGS) src/float/$@.cpp -o $(OUT)$@  -lpthread 
bench_except:
	$(CC) $(CFLAGS) src/float/$@.cpp -o $(OUT)$@ $(INC)  $(LINK)
floatexample:
	$(CC) $(CFLAGS) src/float/example2.cpp -o $(OUT)$@ 



# vector
################################################################################

vector_float: 
	$(CC) $(CFLAGS) src/bench_vec/bench_vector_float.cpp -o $(OUT)$@ $(INC) $(LINK)

vector_int.o:
	$(CC) $(CFLAGS) -c src/bench_vec/bench_vector_int.cpp -o $(OUT)vector_int.o $(INC) 
vector_int: vector_int.o
	$(CC) $(CFLAGS) $(OUT)vector_int.o src/bench_vec/bench_vector_int_main.cpp -o $(OUT)$@ $(INC) $(LINK)

vector_int_overflow.o:
	$(CC) $(CFLAGS) -c src/bench_vec/bench_vector_int_overflow.cpp -o $(OUT)vector_int.o $(INC) 
vector_int_overflow: vector_int_overflow.o
	$(CC) $(CFLAGS) $(OUT)vector_int.o src/bench_vec/bench_vector_int_main.cpp -o $(OUT)$@ $(INC) $(LINK) -DOVERFLOW



# matrix
################################################################################
TARGET=vecvec flat-int64 flat-int16 flat-float flat-double
TEST-TARGET=flat-test vecvec-test
$(TARGET):
	$(CC) $(CFLAGS) src/bench_mat/$@-main.cpp -o $(OUT)$@ $(INC) $(LINK)

flat-int32: vector_int.o
	$(CC) $(CFLAGS) $(OUT)vector_int.o src/bench_mat/flat-int32-main.cpp -o $(OUT)$@ $(INC) $(LINK)

# int-SafeInteger.o:
# 	$(CC) $(CFLAGS) -c src/bench_mat/int-SafeInteger.cpp -o $(OUT)vector_int.o $(INC) 
int-SafeInteger: 
	$(CC) $(CFLAGS) src/bench_mat/int-SafeInteger-main.cpp -o $(OUT)$@ $(INC) $(LINK)



# plot-verified
################################################################################

# require manual renaming 
plot-scalar-bad:  flat-int-scalar flat-int32
	./build/flat-int-scalar --benchmark_filter="flat/add/" | tee $@
	./build/flat-int32 --benchmark_filter="flat/add/" | tee -a $@
	codium $@ 

# use 15 to show clang is inconsistent
plot-vectorizer-diff: flat-float
	./build/flat-float --benchmark_filter="flat/fma/"  | tee $@
	./build/flat-float --benchmark_filter="flat/fma_m/" | tee -a $@
	./build/flat-float --benchmark_filter="flat/fma_i/" | tee -a $@
# ./scripts/plot_benchmark_result.py $@ 4

# turn on export BENCH_SIZE="-D SIZE_MODERATE"
plot-flat-vecvec: flat-float vecvec
	./build/vecvec --benchmark_filter="bench_mat_vecvec/fma_manual/" | tee $@
	./build/flat-float --benchmark_filter="flat/fma_m/" | tee -a $@
	./scripts/plot_benchmark_result.py $@ 4

plot-data-type-float-int: flat-float flat-int32
	./build/flat-int32 --benchmark_filter="flat/fma_i/" | tee $@
	./build/flat-float --benchmark_filter="flat/fma_i/" | tee -a $@
	codium $@ 

plot-data-type-int-16-32-64: flat-int32 flat-int64 flat-int16
	./build/flat-int16 --benchmark_filter="flat/fma_i/" | tee $@
	./build/flat-int32 --benchmark_filter="flat/fma_i/" | tee -a $@
	./build/flat-int64 --benchmark_filter="flat/fma_i/" | tee -a $@
	codium $@ 

# turn on export BENCH_SIZE="-D SIZE_MODERATE"
plot-int16-fma-checked-unchecked: flat-int16
	./build/flat-int16 --benchmark_filter="flat/fma_i/" | tee $@
	./build/flat-int16 --benchmark_filter="flat/fma_ic/" | tee -a $@
	codium $@ 

plot-SIGFPE-float-double: flat-float flat-double
	./build/flat-float --benchmark_filter="flat/fma_ic/" | tee $@
	./build/flat-double --benchmark_filter="flat/fma_ic/" | tee -a $@
	codium $@ 
unchecked: flat-int16 flat-int32 flat-float flat-double
	./build/flat-int16 --benchmark_filter="flat/fma_i/" | tee $@
	./build/flat-int32 --benchmark_filter="flat/fma_i/" | tee -a $@
	./build/flat-float --benchmark_filter="flat/fma_i/" | tee -a $@
	./build/flat-double --benchmark_filter="flat/fma_i/" | tee -a $@
	codium $@ 
# plot-testing
################################################################################

# export BENCH_SIZE="-D SIZE_8_16_32"
checked: flat-int16 flat-int32 flat-float flat-double
	./build/flat-int16 --benchmark_filter="flat/fma_ic/" | tee $@
	./build/flat-int32 --benchmark_filter="flat/fma_ic/" | tee -a $@
	./build/flat-float --benchmark_filter="flat/fma_ic/" | tee -a $@
	./build/flat-double --benchmark_filter="flat/fma_ic/" | tee -a $@
	codium $@ 

################################################################################

plot-auto-vectorize-bad-float: flat-float
	python3 --version
	exit
	rm $@ &
	./build/flat-float --benchmark_filter="flat/fma_m/" | tee -a $@
	./build/flat-float --benchmark_filter="flat/fma/" | tee -a $@
	./scripts/plot_benchmark_result.py $@ 15

plot-auto-vectorize-bad-int: flat-int32
	./build/flat-int32 --benchmark_filter="flat/fma_m/" | tee $@
	./build/flat-int32 --benchmark_filter="flat/fma/" | tee -a $@
	./scripts/plot_benchmark_result.py $@ 15

flat-int-scalar: 
	$(CC) $(CFLAGS_no_vec) -c src/bench_vec/bench_vector_int.cpp -o $(OUT)vector_int.o $(INC) -D SCALAR_ONLY
	$(CC) $(CFLAGS_no_vec) $(OUT)vector_int.o $(CFLAGS) src/bench_mat/flat-int32-main.cpp -o $(OUT)$@ $(INC) $(LINK) -D SCALAR_ONLY



# PHONY
################################################################################
.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -rf build/*
	rm -rf plot-*

# TESTS (may not work)
################################################################################

flat-double-test:
	$(CC) $(CFLAGS) src/bench_mat/flat-double.cpp -o $(OUT)$@ $(INC) -DTEST $(LINK)
flat-int52-test:
	$(CC) $(CFLAGS) src/bench_mat/flat-int52.cpp -o $(OUT)$@ $(INC) -DTEST $(LINK)


bold=`tput bold`
normal=`tput sgr0`

flat-test-fma: flat-test
	# ./build/flat-test --benchmark_filter=bench_mat_flat/fma_auto/8/16 > /dev/null 2>&1
	# diff /dev/shm/1145141919810 ./tests/fma_8_16_iter1 
	./build/flat-test --benchmark_filter=bench_mat_flat/float_fma_m/8/16 > /dev/null 2>&1
	diff /dev/shm/1145141919810 ./tests/fma_8_16_iter1 & echo $(bold)PASS$(normal)

# vecvec-test-fma: vecvec-test
# 	./build/flat-test --benchmark_filter=bench_mat_vecvec/fma_auto/8/16 > /dev/null 2>&1
# 	diff /dev/shm/1145141919810 ./tests/fma_8_16_iter1 
# 	./build/flat-test --benchmark_filter=bench_mat_vecvec/fma_manual/8/16 > /dev/null 2>&1
# 	diff /dev/shm/1145141919810 ./tests/fma_8_16_iter1 & echo $(bold)PASS$(normal)

