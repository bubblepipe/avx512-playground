push   %rbp
push   %r15
push   %r14
push   %r13
push   %r12
push   %rbx
sub    $0x78,%rsp
mov    %rdi,%r14
lea    0x4ac3c(%rip),%rdi        # 56004 <_IO_stdin_used+0x4>
lea    0x4ac4c(%rip),%rsi        # 5601b <_IO_stdin_used+0x1b>
call   6590 <fopen@plt>
mov    %rax,%r12
movq   $0x0,0x70(%rsp)

movq   $0x0,0x68(%rsp)

movq   $0x0,0x60(%rsp)

movq   $0x0,0x48(%rsp)

movq   $0x0,0x40(%rsp)

movq   $0x0,0x38(%rsp)

movq   $0x0,0x30(%rsp)

movq   $0x0,0x28(%rsp)

movq   $0x0,0x20(%rsp)

mov    $0x200,%edi
call   64b0 <_Znwm@plt>
mov    %rax,%rbx
add    $0x200,%rbx
mov    $0x200,%edx
mov    %rax,0x8(%rsp)
mov    %rax,%rdi
xor    %esi,%esi
mov    %rbx,0x18(%rsp)
call   6280 <memset@plt>
mov    %rbx,0x10(%rsp)
lea    0x60(%rsp),%rdi
lea    0x8(%rsp),%rcx
mov    $0x80,%edx
xor    %esi,%esi
call   c230 <_ZNSt6vectorIS_IfSaIfEESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_>
mov    0x8(%rsp),%rdi
test   %rdi,%rdi
je     b47f <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0xcf>
call   6470 <_ZdlPv@plt>
movq   $0x0,0x18(%rsp)

movq   $0x0,0x10(%rsp)

movq   $0x0,0x8(%rsp)

mov    $0x200,%edi
call   64b0 <_Znwm@plt>
mov    %rax,%rbx
add    $0x200,%rbx
mov    $0x200,%edx
mov    %rax,0x8(%rsp)
mov    %rax,%rdi
xor    %esi,%esi
mov    %rbx,0x18(%rsp)
call   6280 <memset@plt>
mov    %rbx,0x10(%rsp)
mov    0x40(%rsp),%r15
mov    0x38(%rsp),%rbx
movabs $0xaaaaaaaaaaaaaaab,%r13

mov    %r15,%rax
sub    %rbx,%rax
mov    %rax,%rcx
sar    $0x3,%rcx
imul   %r13,%rcx
cmp    $0x7f,%rcx
ja     b513 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x163>
mov    $0x80,%edx
sub    %rcx,%rdx
lea    0x38(%rsp),%rdi
lea    0x8(%rsp),%rcx
mov    %r15,%rsi
call   c230 <_ZNSt6vectorIS_IfSaIfEESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_>
jmp    b54e <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x19e>
cmp    $0xc00,%rax
je     b54e <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x19e>
add    $0xc00,%rbx
cmp    %rbx,%r15
je     b54e <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x19e>
mov    %rbx,%rbp
jmp    b539 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x189>
nopl   0x0(%rax)
add    $0x18,%rbp
cmp    %r15,%rbp
je     b549 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x199>
mov    0x0(%rbp),%rdi
test   %rdi,%rdi
je     b530 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x180>
call   6470 <_ZdlPv@plt>
jmp    b530 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x180>
mov    %rbx,0x40(%rsp)
mov    0x8(%rsp),%rdi
test   %rdi,%rdi
je     b55d <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x1ad>
call   6470 <_ZdlPv@plt>
movq   $0x0,0x18(%rsp)

movq   $0x0,0x10(%rsp)

movq   $0x0,0x8(%rsp)

mov    $0x200,%edi
call   64b0 <_Znwm@plt>
mov    %rax,%rbx
add    $0x200,%rbx
mov    $0x200,%edx
mov    %rax,0x8(%rsp)
mov    %rax,%rdi
xor    %esi,%esi
mov    %rbx,0x18(%rsp)
call   6280 <memset@plt>
mov    0x28(%rsp),%r15
mov    0x20(%rsp),%rbp
mov    %rbx,0x10(%rsp)
mov    %r15,%rax
sub    %rbp,%rax
mov    %rax,%rcx
sar    $0x3,%rcx
imul   %r13,%rcx
cmp    $0x7f,%rcx
ja     b5e7 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x237>
mov    $0x80,%edx
sub    %rcx,%rdx
lea    0x20(%rsp),%rdi
lea    0x8(%rsp),%rcx
mov    %r15,%rsi
call   c230 <_ZNSt6vectorIS_IfSaIfEESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_>
jmp    b61d <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x26d>
cmp    $0xc00,%rax
je     b61d <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x26d>
add    $0xc00,%rbp
cmp    %rbp,%r15
je     b61d <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x26d>
mov    %rbp,%rbx
jmp    b609 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x259>
add    $0x18,%rbx
cmp    %r15,%rbx
je     b618 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x268>
mov    (%rbx),%rdi
test   %rdi,%rdi
je     b600 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x250>
call   6470 <_ZdlPv@plt>
jmp    b600 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x250>
mov    %rbp,0x28(%rsp)
mov    0x8(%rsp),%rdi
test   %rdi,%rdi
je     b62c <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x27c>
call   6470 <_ZdlPv@plt>
xor    %r15d,%r15d
nop
xor    %ebx,%ebx
data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)

call   60d0 <rand@plt>
mov    %eax,0x54(%rsp)
lea    0x0(,%r15,8),%rcx

fildl  0x54(%rsp)
mov    0x20(%rsp),%rax
lea    (%rcx,%rcx,2),%rbp
mov    (%rax,%rbp,1),%rax
fstps  (%rax,%rbx,4)
call   60d0 <rand@plt>
mov    %eax,0x58(%rsp)
fildl  0x58(%rsp)
mov    0x60(%rsp),%rax
mov    (%rax,%rbp,1),%rax
fstps  (%rax,%rbx,4)
call   60d0 <rand@plt>
mov    %eax,0x5c(%rsp)
fildl  0x5c(%rsp)
mov    0x38(%rsp),%rax
mov    (%rax,%rbp,1),%rax
fstps  (%rax,%rbx,4)
inc    %rbx
cmp    $0x80,%rbx
jne    b640 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x290>
inc    %r15
cmp    $0x80,%r15
jne    b630 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x280>
movzbl 0x1a(%r14),%ebx
mov    0x10(%r14),%r15
mov    %r14,%rdi
call   cf20 <_ZN9benchmark5State16StartKeepRunningEv>
test   %bl,%bl
jne    b94f <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x59f>
test   %r15,%r15
je     b94f <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x59f>
mov    0x60(%rsp),%r8
mov    0x38(%rsp),%r9
mov    0x20(%rsp),%rdx
xor    %esi,%esi
data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)

lea    0x0(,%rsi,8),%rax

xor    %ecx,%ecx
lea    (%rax,%rax,2),%rax
mov    (%r8,%rax,1),%rdi
mov    (%r9,%rax,1),%rbx
mov    (%rdx,%rax,1),%rax
add    $0x7c,%rdi
add    $0x7c,%rbx
add    $0x7c,%rax
cs nopw 0x0(%rax,%rax,1)

flds   -0x7c(%rdi,%rcx,4)
fmuls  -0x7c(%rbx,%rcx,4)
fadds  -0x7c(%rax,%rcx,4)
fstps  -0x7c(%rax,%rcx,4)
flds   -0x78(%rdi,%rcx,4)
fmuls  -0x78(%rbx,%rcx,4)
fadds  -0x78(%rax,%rcx,4)
fstps  -0x78(%rax,%rcx,4)
flds   -0x74(%rdi,%rcx,4)
fmuls  -0x74(%rbx,%rcx,4)
fadds  -0x74(%rax,%rcx,4)
fstps  -0x74(%rax,%rcx,4)
flds   -0x70(%rdi,%rcx,4)
fmuls  -0x70(%rbx,%rcx,4)
fadds  -0x70(%rax,%rcx,4)
fstps  -0x70(%rax,%rcx,4)
flds   -0x6c(%rdi,%rcx,4)
fmuls  -0x6c(%rbx,%rcx,4)
fadds  -0x6c(%rax,%rcx,4)
fstps  -0x6c(%rax,%rcx,4)
flds   -0x68(%rdi,%rcx,4)
fmuls  -0x68(%rbx,%rcx,4)
fadds  -0x68(%rax,%rcx,4)
fstps  -0x68(%rax,%rcx,4)
flds   -0x64(%rdi,%rcx,4)
fmuls  -0x64(%rbx,%rcx,4)
fadds  -0x64(%rax,%rcx,4)
fstps  -0x64(%rax,%rcx,4)
flds   -0x60(%rdi,%rcx,4)
fmuls  -0x60(%rbx,%rcx,4)
fadds  -0x60(%rax,%rcx,4)
fstps  -0x60(%rax,%rcx,4)
flds   -0x5c(%rdi,%rcx,4)
fmuls  -0x5c(%rbx,%rcx,4)
fadds  -0x5c(%rax,%rcx,4)
fstps  -0x5c(%rax,%rcx,4)
flds   -0x58(%rdi,%rcx,4)
fmuls  -0x58(%rbx,%rcx,4)
fadds  -0x58(%rax,%rcx,4)
fstps  -0x58(%rax,%rcx,4)
flds   -0x54(%rdi,%rcx,4)
fmuls  -0x54(%rbx,%rcx,4)
fadds  -0x54(%rax,%rcx,4)
fstps  -0x54(%rax,%rcx,4)
flds   -0x50(%rdi,%rcx,4)
fmuls  -0x50(%rbx,%rcx,4)
fadds  -0x50(%rax,%rcx,4)
fstps  -0x50(%rax,%rcx,4)
flds   -0x4c(%rdi,%rcx,4)
fmuls  -0x4c(%rbx,%rcx,4)
fadds  -0x4c(%rax,%rcx,4)
fstps  -0x4c(%rax,%rcx,4)
flds   -0x48(%rdi,%rcx,4)
fmuls  -0x48(%rbx,%rcx,4)
fadds  -0x48(%rax,%rcx,4)
fstps  -0x48(%rax,%rcx,4)
flds   -0x44(%rdi,%rcx,4)
fmuls  -0x44(%rbx,%rcx,4)
fadds  -0x44(%rax,%rcx,4)
fstps  -0x44(%rax,%rcx,4)
flds   -0x40(%rdi,%rcx,4)
fmuls  -0x40(%rbx,%rcx,4)
fadds  -0x40(%rax,%rcx,4)
fstps  -0x40(%rax,%rcx,4)
flds   -0x3c(%rdi,%rcx,4)
fmuls  -0x3c(%rbx,%rcx,4)
fadds  -0x3c(%rax,%rcx,4)
fstps  -0x3c(%rax,%rcx,4)
flds   -0x38(%rdi,%rcx,4)
fmuls  -0x38(%rbx,%rcx,4)
fadds  -0x38(%rax,%rcx,4)
fstps  -0x38(%rax,%rcx,4)
flds   -0x34(%rdi,%rcx,4)
fmuls  -0x34(%rbx,%rcx,4)
fadds  -0x34(%rax,%rcx,4)
fstps  -0x34(%rax,%rcx,4)
flds   -0x30(%rdi,%rcx,4)
fmuls  -0x30(%rbx,%rcx,4)
fadds  -0x30(%rax,%rcx,4)
fstps  -0x30(%rax,%rcx,4)
flds   -0x2c(%rdi,%rcx,4)
fmuls  -0x2c(%rbx,%rcx,4)
fadds  -0x2c(%rax,%rcx,4)
fstps  -0x2c(%rax,%rcx,4)
flds   -0x28(%rdi,%rcx,4)
fmuls  -0x28(%rbx,%rcx,4)
fadds  -0x28(%rax,%rcx,4)
fstps  -0x28(%rax,%rcx,4)
flds   -0x24(%rdi,%rcx,4)
fmuls  -0x24(%rbx,%rcx,4)
fadds  -0x24(%rax,%rcx,4)
fstps  -0x24(%rax,%rcx,4)
flds   -0x20(%rdi,%rcx,4)
fmuls  -0x20(%rbx,%rcx,4)
fadds  -0x20(%rax,%rcx,4)
fstps  -0x20(%rax,%rcx,4)
flds   -0x1c(%rdi,%rcx,4)
fmuls  -0x1c(%rbx,%rcx,4)
fadds  -0x1c(%rax,%rcx,4)
fstps  -0x1c(%rax,%rcx,4)
flds   -0x18(%rdi,%rcx,4)
fmuls  -0x18(%rbx,%rcx,4)
fadds  -0x18(%rax,%rcx,4)
fstps  -0x18(%rax,%rcx,4)
flds   -0x14(%rdi,%rcx,4)
fmuls  -0x14(%rbx,%rcx,4)
fadds  -0x14(%rax,%rcx,4)
fstps  -0x14(%rax,%rcx,4)
flds   -0x10(%rdi,%rcx,4)
fmuls  -0x10(%rbx,%rcx,4)
fadds  -0x10(%rax,%rcx,4)
fstps  -0x10(%rax,%rcx,4)
flds   -0xc(%rdi,%rcx,4)
fmuls  -0xc(%rbx,%rcx,4)
fadds  -0xc(%rax,%rcx,4)
fstps  -0xc(%rax,%rcx,4)
flds   -0x8(%rdi,%rcx,4)
fmuls  -0x8(%rbx,%rcx,4)
fadds  -0x8(%rax,%rcx,4)
fstps  -0x8(%rax,%rcx,4)
flds   -0x4(%rdi,%rcx,4)
fmuls  -0x4(%rbx,%rcx,4)
fadds  -0x4(%rax,%rcx,4)
fstps  -0x4(%rax,%rcx,4)
flds   (%rdi,%rcx,4)
fmuls  (%rbx,%rcx,4)
fadds  (%rax,%rcx,4)
fstps  (%rax,%rcx,4)
add    $0x20,%rcx
cmp    $0x80,%rcx
jne    b720 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x370>
inc    %rsi
cmp    $0x80,%rsi
jne    b6f0 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x340>
test   %r15,%r15
jle    bab1 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x701>
dec    %r15
jne    b6e0 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x330>
mov    %r14,%rdi
call   e5f0 <_ZN9benchmark5State17FinishKeepRunningEv>
lea    0x4a6bf(%rip),%r14        # 5601d <_IO_stdin_used+0x1d>
xor    %r15d,%r15d
data16 data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)


xor    %ebx,%ebx
data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)

mov    0x20(%rsp),%rax
lea    (%r15,%r15,2),%rcx
mov    %r12,%rdi
mov    %r14,%rsi
mov    (%rax,%rcx,8),%rax
flds   (%rax,%rbx,4)
xor    %eax,%eax
fstpl  (%rsp)
call   66e0 <fprintf@plt>
inc    %rbx
cmp    $0x80,%rbx
jne    b980 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x5d0>
inc    %r15
cmp    $0x80,%r15
jne    b970 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x5c0>
mov    0x20(%rsp),%rbx
mov    0x28(%rsp),%r14
cmp    %r14,%rbx
jne    ba29 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x679>
test   %rbx,%rbx
je     b9d4 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x624>
mov    %rbx,%rdi
call   6470 <_ZdlPv@plt>
mov    0x38(%rsp),%rbx
mov    0x40(%rsp),%r14
cmp    %r14,%rbx
jne    ba49 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x699>
test   %rbx,%rbx
je     b9f0 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x640>
mov    %rbx,%rdi
call   6470 <_ZdlPv@plt>
mov    0x60(%rsp),%rbx
mov    0x68(%rsp),%r14
cmp    %r14,%rbx
jne    ba69 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x6b9>
test   %rbx,%rbx
je     ba0c <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x65c>
mov    %rbx,%rdi
call   6470 <_ZdlPv@plt>
add    $0x78,%rsp
pop    %rbx
pop    %r12
pop    %r13
pop    %r14
pop    %r15
pop    %rbp
ret
nopl   0x0(%rax,%rax,1)
add    $0x18,%rbx
cmp    %r14,%rbx
je     ba78 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x6c8>
mov    (%rbx),%rdi
test   %rdi,%rdi
je     ba20 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x670>
call   6470 <_ZdlPv@plt>
jmp    ba20 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x670>
nopl   0x0(%rax,%rax,1)

add    $0x18,%rbx
cmp    %r14,%rbx
je     ba8b <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x6db>
mov    (%rbx),%rdi
test   %rdi,%rdi
je     ba40 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x690>
call   6470 <_ZdlPv@plt>
jmp    ba40 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x690>
nopl   0x0(%rax,%rax,1)

add    $0x18,%rbx
cmp    %r14,%rbx
je     ba9e <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x6ee>
mov    (%rbx),%rdi
test   %rdi,%rdi
je     ba60 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x6b0>
call   6470 <_ZdlPv@plt>
jmp    ba60 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x6b0>
mov    0x20(%rsp),%rbx
test   %rbx,%rbx
jne    b9cc <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x61c>
jmp    b9d4 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x624>
mov    0x38(%rsp),%rbx
test   %rbx,%rbx
jne    b9e8 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x638>
jmp    b9f0 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x640>
mov    0x60(%rsp),%rbx
test   %rbx,%rbx
jne    ba04 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x654>
jmp    ba0c <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x65c>
lea    0x4a590(%rip),%rdi        # 56048 <_IO_stdin_used+0x48>
lea    0x4a595(%rip),%rsi        # 56054 <_IO_stdin_used+0x54>
lea    0x4a5b6(%rip),%rcx        # 5607c <_IO_stdin_used+0x7c>
mov    $0x3af,%edx
call   6300 <__assert_fail@plt>
mov    0x8(%rsp),%rdi
mov    %rax,%rbx
test   %rdi,%rdi
jne    baff <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x74f>
jmp    bb0b <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x75b>
mov    0x8(%rsp),%rdi
mov    %rax,%rbx
test   %rdi,%rdi
jne    baff <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x74f>
jmp    bb0b <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x75b>
jmp    bb08 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x758>
jmp    bb08 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x758>
mov    0x8(%rsp),%rdi
mov    %rax,%rbx
test   %rdi,%rdi
je     bb0b <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x75b>
call   6470 <_ZdlPv@plt>
jmp    bb0b <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x75b>
jmp    bb08 <_Z29bench_matrix_add_vectorvectorRN9benchmark5StateE+0x758>
mov    %rax,%rbx
lea    0x20(%rsp),%rdi
call   c1c0 <_ZNSt6vectorIS_IfSaIfEESaIS1_EED2Ev>
lea    0x38(%rsp),%rdi
call   c1c0 <_ZNSt6vectorIS_IfSaIfEESaIS1_EED2Ev>
lea    0x60(%rsp),%rdi
call   c1c0 <_ZNSt6vectorIS_IfSaIfEESaIS1_EED2Ev>
mov    %rbx,%rdi
call   6870 <_Unwind_Resume@plt>
data16 data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)



0