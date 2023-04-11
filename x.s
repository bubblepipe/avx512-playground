vmovaps (%rdx,%rsi,4),%ymm0
vmovaps (%rcx,%rax,4),%ymm1
vfmadd213ps (%r8,%rdi,4),%ymm0,%ymm1
vmovaps %ymm1,(%r9,%rax,4)