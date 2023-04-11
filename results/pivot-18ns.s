vmovss (%rax,%r12,4),%xmm3
vucomiss %xmm2,%xmm3
vbroadcastss %xmm3,%ymm4
vmulps (%rax),%ymm1,%ymm5
vfmadd231ps %ymm4,%ymm0,%ymm5
vmovaps %ymm5,(%rax)
vmulss %xmm6,%xmm3,%xmm3
vmovss %xmm3,(%rax,%r12,4)



#   1.24 │ d0:┌─→mov          0x20(%r14),%ecx                                                                                                                                                         ▒
#        │    │  lea          (%rax,%rcx,4),%rax                                                                                                                                                      ▒
#   3.74 │    │  inc          %r15d                                                                                                                                                                   ▒
#        │    │  cmp          %r15d,%r13d                                                                                                                                                             ▒
#        │    │↓ je           117                                                                                                                                                                     ▒
#   2.49 │ e0:│  cmp          %r15d,%ebx                                                                                                                                                              ▒
#        │    │↑ je           d0                                                                                                                                                                      ▒
#        │    │  vmovss       (%rax,%r12,4),%xmm3                                                                                                                                                     ▒
#        │    │  vucomiss     %xmm2,%xmm3                                                                                                                                                             ▒
#        │    │↓ jne          f3                                                                                                                                                                      ▒
#   1.24 │    │↑ jnp          d0                                                                                                                                                                      ▒
#        │ f3:│  vbroadcastss %xmm3,%zmm4                                                                                                                                                             ▒
#   3.76 │    │  vmulps       (%rax),%zmm1,%zmm5                                                                                                                                                      ▒
#        │    │  vfmadd231ps  %zmm4,%zmm0,%zmm5                                                                                                                                                       ▒
#        │    │  vmovaps      %zmm5,(%rax)                                                                                                                                                            ▒
#        │    │  vmulss       %xmm6,%xmm3,%xmm3                                                                                                                                                       ▒
#        │    │  vmovss       %xmm3,(%rax,%r12,4)                                                                                                                                                     ▒
#        │    └──jmp          d0                                                                                                                                                                      ▒
          