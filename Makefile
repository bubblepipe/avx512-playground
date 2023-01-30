CC=clang++-15

# CFLAGS=-O3 -march=native -I src/ -fno-omit-frame-pointer -std=c++17 -Wno-format 
CFLAGS=-O3 -march=native -I src/ -fno-omit-frame-pointer -std=c++17
# CFLAGS=-O0 -march=native -I src/ -fno-omit-frame-pointer -std=c++17 -g

INC_GBENCH=-isystem include/benchmark/include
INC_LIBSIMDPP=-I ./include/libsimdpp

INC += $(INC_LIBSIMDPP)
INC += $(INC_GBENCH)

LINK=-L include/benchmark/build/src -lbenchmark -lpthread 

OUT=build/

TARGET=flat vecvec flat-int52 flat-int64 flat-float flat-double
TEST-TARGET=flat-test vecvec-test

rand_int_float_int:
	$(CC) $(CFLAGS) src/float/$@.cpp -o $(OUT)$@  -lpthread 
doubledouble fe_inexact:
	$(CC) $(CFLAGS) src/float/$@.cpp -o $(OUT)$@ 
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
	$(CC) $(CFLAGS) $(OUT)vector_int.o src/bench_mat/flat-int.cpp -o $(OUT)$@ $(INC) $(LINK)

flat-int-test: vector_int.o
	$(CC) $(CFLAGS) $(OUT)vector_int.o src/bench_mat/flat-int.cpp -o $(OUT)$@ $(INC) $(LINK) -DTEST 


$(TARGET):
	$(CC) $(CFLAGS) src/bench_mat/$@.cpp -o $(OUT)$@ $(INC) $(LINK)


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

vecvec-test-fma: vecvec-test
	./build/flat-test --benchmark_filter=bench_mat_vecvec/fma_auto/8/16 > /dev/null 2>&1
	diff /dev/shm/1145141919810 ./tests/fma_8_16_iter1 
	./build/flat-test --benchmark_filter=bench_mat_vecvec/fma_manual/8/16 > /dev/null 2>&1
	diff /dev/shm/1145141919810 ./tests/fma_8_16_iter1 & echo $(bold)PASS$(normal)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -rf build/*
