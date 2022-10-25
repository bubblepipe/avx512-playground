# Getting Started

```
./setup.sh
./run-benchmark.sh
```

# Discovery 

## Section 0

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


## Section 1
5. If I don't use the result (e.g. print it), then `-O3` will optimize away any computation. 

**Suspection: `-O3` bad**  
the amont of computation are not the same each in compilation 

6. I add this bit of code to force save the result. 
```
  for (int i = 0; i < dst_size; i += 1 ){
    fprintf(somefile, "%x\n",  dst_ptr[i]);
  }
```

|                    |  vec_add(8), zen3, clang | vec_add(8), zen3, g++ |
|---                 |---|---|
| -O3                | 104  | 86.8 |
| -O3 -march=nehalem | 72  | 86.2 |
| -O3 -march=skylake | 102 | 135  |

|                    |  vec_add(32), zen3, clang | vec_add(32), zen3, g++ |
|---                 |---|---|
| -O3                | 356  | 181  |
| -O3 -march=nehalem | 355  | 183  |
| -O3 -march=skylake | 1571 | 107  |

At this stage the result is very messy. Should we abandon `-O3`?
Is it possible to use `cc -O0` but still getting vectorization? 

Consider another benchmark toolkit?