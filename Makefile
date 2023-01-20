CC=clang++-15

CFLAGS=-O3 -march=native -I src/ -fno-omit-frame-pointer -std=c++17 -Wno-format 

INC_GBENCH=-isystem include/benchmark/include -L include/benchmark/build/src -lbenchmark -lpthread 
INC_LIBSIMDPP=-I ./include/libsimdpp

INC += $(INC_LIBSIMDPP)
INC += $(INC_GBENCH)

OUT=build/

TARGET=flat vecvec
TEST-TARGET=flat-test vecvec-test

$(TARGET):
	$(CC) $(CFLAGS) src/bench_mat/$@.cpp -o $(OUT)$@ $(INC) -D DATA_TYPE=double

flat-bench-fmam: flat
	./build/flat --benchmark_filter=bench_mat_flat/float_fma_m/
vecvec-bench-fmam: vecvec
	./build/vecvec --benchmark_filter=bench_mat_vecvec/fma_manual/8/8


flat-test:
	$(CC) $(CFLAGS) src/bench_mat/flat.cpp -o $(OUT)$@ $(INC) -DTEST
vecvec-test:
	$(CC) $(CFLAGS) src/bench_mat/vecvec.cpp -o $(OUT)$@ $(INC) -DTEST

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
