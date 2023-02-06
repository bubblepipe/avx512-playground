CC=clang++-15

# CFLAGS=-O3 -march=native -I src/ -fno-omit-frame-pointer -std=c++17 -Wno-format 
CFLAGS=-O3 -march=native -I src/ -fno-omit-frame-pointer -std=c++17 
CFLAGS_no_vec=-O3 -mno-avx -mno-sse -march=native -I src/ -fno-omit-frame-pointer -std=c++17
# CFLAGS=-O0 -march=native -I src/ -fno-omit-frame-pointer -std=c++17 -g

INC_GBENCH=-isystem include/benchmark/include
INC_LIBSIMDPP=-I ./include/libsimdpp

INC += $(INC_LIBSIMDPP)
INC += $(INC_GBENCH)

LINK=-L include/benchmark/build/src -lbenchmark -lpthread 

BENCH_SIZE=-D SIZE_BIG
# CFLAGS+=$BENCH_SIZE

OUT=build/

TARGET=flat vecvec flat-int52 flat-int64 flat-float flat-double
TEST-TARGET=flat-test vecvec-test

################################################################################
rand_int_float_int test_all_int52 i16u32 doubledouble fe_inexact clang-overflow:
	$(CC) $(CFLAGS) src/float/$@.cpp -o $(OUT)$@  -lpthread 
bench_except:
	$(CC) $(CFLAGS) src/float/$@.cpp -o $(OUT)$@ $(INC)  $(LINK)

floatexample:
	$(CC) $(CFLAGS) src/float/example2.cpp -o $(OUT)$@ 

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


flat-int: vector_int.o
	$(CC) $(CFLAGS) $(OUT)vector_int.o src/bench_mat/flat-int-main.cpp -o $(OUT)$@ $(INC) $(LINK)

# flat-int-test: vector_int.o
# 	$(CC) $(CFLAGS) $(OUT)vector_int.o src/bench_mat/flat-int.cpp -o $(OUT)$@ $(INC) $(LINK) -DTEST 
# flat-int64-test: vector_int.o
# 	$(CC) $(CFLAGS) $(OUT)vector_int.o src/bench_mat/flat-int64.cpp -o $(OUT)$@ $(INC) $(LINK) -DTEST 


$(TARGET):
	$(CC) $(CFLAGS) src/bench_mat/$@-main.cpp -o $(OUT)$@ $(INC) $(LINK)

int16.o:
	$(CC) $(CFLAGS) -c src/bench_mat/int16.cpp -o $(OUT)vector_int.o $(INC) 
int16_main: int16.o
	$(CC) $(CFLAGS) $(OUT)vector_int.o src/bench_mat/int16_main.cpp -o $(OUT)$@ $(INC) $(LINK)

################################################################################

plot-auto-vectorize-bad-float: flat-float
	rm $@ &
	./build/flat-float --benchmark_filter="flat/fma_m/" | tee -a $@
	./build/flat-float --benchmark_filter="flat/fma/" | tee -a $@
	./scripts/plot_benchmark_result.py $@ 15

plot-auto-vectorize-bad-int: flat-int
	./build/flat-int --benchmark_filter="flat/fma_m/" | tee $@
	./build/flat-int --benchmark_filter="flat/fma/" | tee -a $@
	./scripts/plot_benchmark_result.py $@ 15

flat-int-scalar: 
	$(CC) $(CFLAGS_no_vec) -c src/bench_vec/bench_vector_int.cpp -o $(OUT)vector_int.o $(INC) -D SCALAR_ONLY
	$(CC) $(CFLAGS_no_vec) $(OUT)vector_int.o $(CFLAGS) src/bench_mat/flat-int-main.cpp -o $(OUT)$@ $(INC) $(LINK) -D SCALAR_ONLY

plot-scalar-bad:  flat-int-scalar
	rm $@
	./build/flat-int-scalar --benchmark_filter="flat/fma/" | tee $@
	./scripts/plot_benchmark_result.py $@ 15

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

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -rf build/*
