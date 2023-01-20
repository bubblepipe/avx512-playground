# Getting Started

```
./setup.sh
./run-benchmark.sh
```

# Repo Structure

```
.
├── build
│   ├── flat
│   ├── flat-test
│   ├── vecvec
│   └── vecvec-test
├── doc
│   ├── 3428263.pdf
│   ├── 3485539.pdf
│   └── instruction_tables.pdf
├── fast-ap-integers.md
├── Makefile
├── Questions.md
├── README.md
├── scripts
│   ├── find-simd.sh
│   ├── get-ir.sh
│   ├── grep-avx.sh
│   ├── grep-sse.sh
│   ├── perfflame.sh
│   ├── plot_benchmark_result.py
│   ├── run-llvmmca.sh
│   └── setup.sh
├── src
│   ├── bench_mat
│   │   ├── flat.cpp
│   │   ├── mallocmalloc.cpp [deprecated]
│   │   └── vecvec.cpp
│   ├── bench_test
│   │   └── test.cpp 
│   ├── bench_vec
│   │   └── bench_vector_add.cpp [deprecated]
│   └── utils
│       └── bench_utils.cpp
└── tests
    └── fma_8_16_iter1

9 directories, 26 files

```