# Getting Started

```
./setup.sh
./run-benchmark.sh
```

# Discovery 

1. `clang++-15 -O3` does not automatically vectorize anything, even no sse, have to specify `clang++-15 -O3 skylake` 

2. Use `-O3 nehalem` generates `sse2` code. 

2. Google benchmark library introduces SSE and SSE2 instructions, this is annoying 

3. Using clang there is very weired performance behaviour  
sometimes `avx` is significantly **slower** ?

|               | vec_add(8) (skylake-U) | vec_add(8) (zen3) | vec_add_32 (zen3) | vec_add_64 (skylake-U) |
|---            |---|---|---|---|
| -O3           | 157 |  103  | 355  | 1342  |
| -O3 -march=nehalem | 194 |71.6 | 354  | 1325  |
| -O3 -march=skylake | 197 | 102   | 1561 | 3035  |

4. Compiling with `g++` also produces weired performance. 
version is `g++ (Debian 11.3.0-5) 11.3.0`

|               | vec_add(8) (skylake-U) | vec_add(8) (zen3) | vec_add_32 (zen3) | vec_add_64 (skylake-U) |
|---            |---|---|---|---|
| -O3           | 198 | 88.9   | 141  | 357  |
| -O3 -march=nehalem | 194 |   86.3  | 130  | 367  |
| -O3 -march=skylake | 297 |   134 | **105** | 266  |
