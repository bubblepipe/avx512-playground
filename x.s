00000000000087d0 <_Z19mat_fma_vecty_checkjjR6matrixIfES1_S1_S1_>:
push   %rbp
mov    %rsp,%rbp
sub    $0x10,%rsp
mov    (%rdx),%r10
mov    0x8(%rdx),%rdx
sub    %r10,%rdx
je     8825 <_Z19mat_fma_vecty_checkjjR6matrixIfES1_S1_S1_+0x55>
mov    (%rcx),%rcx
mov    (%r8),%rsi
mov    (%r9),%rdi
sar    $0x2,%rdx
xor    %eax,%eax
data16 data16 data16 cs nopw 0x0(%rax,%rax,1)

vmovups (%r10,%rax,4),%zmm0
vmovups (%rcx,%rax,4),%zmm1
vfmadd213ps (%rsi,%rax,4),%zmm0,%zmm1
vmovups %zmm1,(%rdi,%rax,4)
add    $0x10,%rax
cmp    %rax,%rdx
ja     8800 <_Z19mat_fma_vecty_checkjjR6matrixIfES1_S1_S1_+0x30>
movl   $0x0,-0x4(%rbp)
stmxcsr -0x4(%rbp)
fwait
testb  $0x20,-0x4(%rbp)
je     8840 <_Z19mat_fma_vecty_checkjjR6matrixIfES1_S1_S1_+0x70>
add    $0x10,%rsp
pop    %rbp
vzeroupper 
ret    
xor    %edi,%edi
vzeroupper 
call   65b0 <exit@plt>
nopw   0x0(%rax,%rax,1)