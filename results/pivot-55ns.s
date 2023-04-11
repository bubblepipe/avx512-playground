vmovss       (%rax,%r12,4),%xmm3
vucomiss     %xmm2,%xmm3
vmulss       (%rax),%xmm7,%xmm4
vmovss       %xmm4,(%rax)
vbroadcastss %xmm3,%ymm4
vmulps       (%rax),%ymm1,%ymm5
vfmadd231ps  %ymm4,%ymm0,%ymm5
vmovaps      %ymm5,(%rax)
vmulss       %xmm6,%xmm3,%xmm3
vmovss       %xmm3,(%rax,%r12,4)

#        │ e0:┌─→mov          0x20(%r14),%ecx                                                                                                                                                         
#   6.20 │    │  lea          (%rax,%rcx,4),%rax                                                                                                                                                      
#  12.87 │    │  inc          %r15d                                                                                                                                                                   
#  15.92 │    │  cmp          %r15d,%r13d                                                                                                                                                             
#        │    │↓ je           12f                                                                                                                                                                     
#   4.44 │ f0:│  cmp          %r15d,%ebx                                                                                                                                                              
#        │    │↑ je           e0                                                                                                                                                                      
#        │    │  vmovss       (%rax,%r12,4),%xmm3                                                                                                                                                     
# dump: W│    │  vucomissised %xmm2,%xmm3                                                                                                                                                             
#        │    │↓ jne          103                                                                                                                                                                     
#        │    │↑ jnp          e0                                                                                                                                                                      
#        │103:│  vmulss       (%rax),%xmm7,%xmm4                                                                                                                                                      
#   2.95 │    │  vmovss       %xmm4,(%rax)                                                                                                                                                            
#  0x22  │    │  vbroadcastss %xmm3,%zmm4                                                                                                                                                             
#   3.14 │    │  vmulps       (%rax),%zmm1,%zmm5                                                                                                                                                      
#  32.04 │    │  vfmadd231ps  %zmm4,%zmm0,%zmm5                                                                                                                                                       
#  16.38 │    │  vmovaps      %zmm5,(%rax)                                                                                                                                                            
#        │    │  vmulss       %xmm6,%xmm3,%xmm3                                                                                                                                                       
#        │    │  vmovss       %xmm3,(%rax,%r12,4)                                                                                                                                                                                                                                                                                                                               ▒
#        │    └──jmp          e0  
