Sorry for being late, I have redo some tests and discussed with Tobias two days ago: 
1. Vectoized `float` and `uint32_t` is about 4 times faster than the scalar version, when doing a vector or matrix add. 
2. Performance drops by half when the matrix size is bigger than cache. 
2. `float` and `uint32_t` is 2x faster than `double` and `uint64_t` when vectorized, and there is not any difference with scalar instructions. 
3. `malloc` is similar to `vector<vector<>>`



We also discussed about whether int will be slower than float due to lack of FMA. The result was No, but we were not sure about its reason. 

```
void xxxx(int row, int col, 
          std::vector<std::vector<T>> & mat_src1, 
          std::vector<std::vector<T>> & mat_src2,
          std::vector<std::vector<T>> & mat_dst){
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            // mat_dst[i][j] = mat_src1[i][j] + mat_src2[i][j];
            mat_dst[i][j] += mat_src1[i][j] * mat_src2[i][j];
        }
    }
}

void bench_matrix_add_vectorvector(benchmark::State &state) {
    
    // initialization  
    
    for (auto _ : state) {
        xxxx(row, col, mat_src1, mat_src2, mat_dst);
    }
```
When `T` is `float` and `int`, Google benchmark gives similar performances. 

`llvm-mca` says
```
            vfmadd  vpaddd vpmulld
Latency	    11      10     8
Rthroughput 0.5	    0.5    0.5
```
Latency does not matter here, assuming RThroughput is correct, it indicates that in case `float` and `int` have similair performance, the amount of AVX2 FMA units should be equal to the amount of AVX2 Int Add + AVX2 Int Mul. This reasoning matches [this diagram](https://en.wikichip.org/wiki/File:zen_2_core_diagram.svg): 
zen2 has 4 ALU and 2 FMA, [same as zen3](https://en.wikichip.org/wiki/amd/microarchitectures/zen_3#Key_changes_from_Zen_2)

However, when I runs `llvm-mca` on the assembly of `xxxx` for both data types, it says Block Rthroughput is `143.5` for float and `81` for int, indicating that float should be significanlty slower than int. 


Note that the pattern looks like 
```
vmovups 0x40(%r8,%rdx,4),%ymm2
vmovups 0x60(%rbp,%rdx,4),%ymm1
vmovups 0x60(%r8,%rdx,4),%ymm3
vfmadd213ps 0x40(%rcx,%rdx,4),%ymm0,%ymm2
vfmadd213ps 0x60(%rcx,%rdx,4),%ymm1,%ymm3
vmovups %ymm2,0x40(%rcx,%rdx,4)
vmovups %ymm3,0x60(%rcx,%rdx,4)
vmovups 0x80(%rbp,%rdx,4),%ymm0
```
and 
```
vmovdqu -0x1e0(%r9,%r15,4),%ymm0
vmovdqu -0x1c0(%r9,%r15,4),%ymm1
vmovdqu -0x1a0(%r9,%r15,4),%ymm2
vmovdqu -0x180(%r9,%r15,4),%ymm3
vpmulld -0x1e0(%r8,%r15,4),%ymm0,%ymm0
vpmulld -0x1c0(%r8,%r15,4),%ymm1,%ymm1
vpmulld -0x1a0(%r8,%r15,4),%ymm2,%ymm2
vpmulld -0x180(%r8,%r15,4),%ymm3,%ymm3
vpaddd -0x1e0(%r10,%r15,4),%ymm0,%ymm0
vpaddd -0x1c0(%r10,%r15,4),%ymm1,%ymm1
vpaddd -0x1a0(%r10,%r15,4),%ymm2,%ymm2
vpaddd -0x180(%r10,%r15,4),%ymm3,%ymm3
vmovdqu %ymm0,-0x1e0(%r10,%r15,4)
vmovdqu %ymm1,-0x1c0(%r10,%r15,4)
vmovdqu %ymm2,-0x1a0(%r10,%r15,4)
vmovdqu %ymm3,-0x180(%r10,%r15,4)
```
For `float` there are 2 `vfmadd213ps` in a batch, but for int there are 4 `vpaddd` and `vpmulld`. 

The `int` version has more `vmovdqu` instructions, but I don't believe the number matters here. Total amount of memory operations shuold be the same. 

I also doubt this pattern does not mean anything, because of instruction reschduling? 





How does performance related to the shape of matrix?