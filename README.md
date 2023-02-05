### Update 0204
```
make bench_except 
./scripts/flame.sh ./build/bench_except except_on_off_local
sudo perf report
```

### Update 0201
```
./build/flat-double --benchmark_filter=flat/2m1a_m_local_check/4/4
./build/flat-double --benchmark_filter=flat/2m1a_m_check/4/4
```
### Update 0130
`feenableexcept` has almost no overhead
```
./scripts/flame.sh ./build/flat-double "flat/fma_m_acurate/128/128"
./scripts/flame.sh ./build/flat-double "flat/fma_m/128/128"
```


`int32` `mat_fma_manual_half_width`
```
make flat-int
./scripts/flame.sh ./build/flat-int "flat/fma_m_hw/128/128"
./scripts/flame.sh ./build/flat-int "flat/fma_m/128/128"
```

`mat_fma_scalar_inacurate_check`
```
make flat-int64
./scripts/flame.sh ./build/flat-int64 "flat/fma_s_acurate/4/4"
```


# Getting Started

```
./setup.sh
./run-benchmark.sh
```
# IFMA

[AVX-512-IFMA extension ](https://en.wikipedia.org/wiki/Advanced_Vector_Extensions#:~:text=BW-,IFMA,-VBMI)

[vpmadd52luq](https://www.felixcloutier.com/x86/vpmadd52luq)

```
Intel Cannon Lake (2018)
Intel Ice Lake (2019)
Intel Tiger Lake (2020)
Intel Rocket Lake (2021)
Intel Alder Lake (2021)
AMD Zen 4 (2022)
Intel Sapphire Rapids (2023)
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

# Versions

### `3064fe5`
```
git checkout 3064fe5
make flat_int  
./scripts/flame.sh ./build/flat_int flat/add/128/128 # about 1500 ns
./scripts/flame.sh ./build/flat_int flat/add_m/128/128 # 30000 ns, pure scalar
# goto src/bench_mat/flat-int.cpp, uncomnent for loop, delete vec_add_莎莎
make flat_int  
./scripts/flame.sh ./build/flat_int flat/add/128/128 # about 15000 ns, no vectorized int add instruction issued 
```