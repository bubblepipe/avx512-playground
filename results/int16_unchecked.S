vpbroadcastw %ecx,%zmm2                                
vpmullw      %zmm0,%zmm2,%zmm2                         
vpmullw      (%rax),%zmm1,%zmm3                        
vpaddw       %zmm2,%zmm3,%zmm2                         
vmovdqa64    %zmm2,(%rax)                              
imul         0x3c(%rsp),%ecx                           
mov          %cx,(%rax,%r15,2)                         
