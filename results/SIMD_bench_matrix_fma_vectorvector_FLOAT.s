push   %rbp
push   %r15
push   %r14
push   %r13
push   %r12
push   %rbx
test   %edi,%edi
jle    c893 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xde3>
test   %esi,%esi
jle    c893 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xde3>
mov    (%rdx),%rax
mov    %esi,%r14d
lea    0x0(,%r14,4),%r12

lea    -0x1(%r14),%r10
mov    %r10,-0x58(%rsp)
mov    %rax,-0x38(%rsp)
mov    (%rcx),%rax
mov    %edi,%ecx
mov    %rcx,-0x18(%rsp)
mov    %rax,-0x40(%rsp)
mov    (%r8),%rax
mov    %rax,-0x48(%rsp)
mov    %r14d,%eax
and    $0xfffffff0,%eax
add    $0xfffffffffffffff0,%rax
mov    %rax,-0x50(%rsp)
shr    $0x4,%rax
inc    %rax
mov    %rax,-0x28(%rsp)
cmp    $0x1,%edi
jne    bb5e <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xae>
xor    %r11d,%r11d
testb  $0x1,-0x18(%rsp)
je     c893 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xde3>
mov    -0x38(%rsp),%rcx
mov    -0x40(%rsp),%rdx
shl    $0x3,%r11
lea    (%r11,%r11,2),%rax
mov    (%rcx,%rax,1),%rdi
mov    (%rdx,%rax,1),%rcx
mov    -0x48(%rsp),%rdx
mov    (%rdx,%rax,1),%rbp
cmp    $0x10,%esi
jae    c47d <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x9cd>
xor    %edx,%edx
jmp    c779 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xcc9>
mov    %eax,%r13d
and    $0xfffffffe,%ecx
and    $0x7,%r13d
mov    %r14d,%r15d
and    $0xfffffffffffffff8,%rax
and    $0x7,%r15d
xor    %r11d,%r11d
mov    %rcx,-0x8(%rsp)
mov    %r14d,%ecx
and    $0xfffffff0,%ecx
mov    %r13,-0x10(%rsp)
shl    $0x6,%r13
mov    %rax,-0x30(%rsp)
mov    %rcx,-0x20(%rsp)
jmp    bbaf <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xff>
cs nopw 0x0(%rax,%rax,1)

add    $0x2,%r11
cmp    -0x8(%rsp),%r11
je     bb20 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x70>
mov    -0x38(%rsp),%rcx
mov    -0x40(%rsp),%rdx
mov    -0x48(%rsp),%rdi
lea    0x0(,%r11,8),%r8

lea    (%r8,%r8,2),%rax
mov    (%rdx,%rax,1),%rbx
mov    (%rcx,%rax,1),%rcx
mov    (%rdi,%rax,1),%rdx
cmp    $0x10,%esi
jae    bbf0 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x140>
xor    %edi,%edi
jmp    bf10 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x460>
data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)

lea    (%rcx,%r12,1),%rax
lea    (%rdx,%r12,1),%rdi
lea    (%rbx,%r12,1),%rbp
cmp    %rax,%rdx
setb   %r9b
cmp    %rdi,%rcx
setb   %r10b
cmp    %rbp,%rdx
setb   %al
cmp    %rdi,%rbx
setb   %dil
test   %r10b,%r9b
jne    bc3e <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x18e>
mov    -0x58(%rsp),%r10
and    %dil,%al
mov    $0x0,%edi
jne    bf10 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x460>
cmpq   $0x70,-0x50(%rsp)
jae    bc4a <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x19a>
xor    %edi,%edi
jmp    be8a <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x3da>
mov    -0x58(%rsp),%r10
xor    %edi,%edi
jmp    bf10 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x460>
mov    -0x30(%rsp),%rbp
xor    %edi,%edi
data16 data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)


vmovups (%rcx,%rdi,4),%ymm0
vmovups (%rbx,%rdi,4),%ymm2
vmovups 0x20(%rcx,%rdi,4),%ymm1
vmovups 0x20(%rbx,%rdi,4),%ymm3
vfmadd213ps (%rdx,%rdi,4),%ymm0,%ymm2
vfmadd213ps 0x20(%rdx,%rdi,4),%ymm1,%ymm3
vmovups %ymm2,(%rdx,%rdi,4)
vmovups %ymm3,0x20(%rdx,%rdi,4)
vmovups 0x40(%rcx,%rdi,4),%ymm0
vmovups 0x40(%rbx,%rdi,4),%ymm2
vmovups 0x60(%rcx,%rdi,4),%ymm1
vmovups 0x60(%rbx,%rdi,4),%ymm3
vfmadd213ps 0x40(%rdx,%rdi,4),%ymm0,%ymm2
vfmadd213ps 0x60(%rdx,%rdi,4),%ymm1,%ymm3
vmovups %ymm2,0x40(%rdx,%rdi,4)
vmovups %ymm3,0x60(%rdx,%rdi,4)
vmovups 0x80(%rcx,%rdi,4),%ymm0

vmovups 0x80(%rbx,%rdi,4),%ymm2

vmovups 0xa0(%rcx,%rdi,4),%ymm1

vmovups 0xa0(%rbx,%rdi,4),%ymm3

vfmadd213ps 0x80(%rdx,%rdi,4),%ymm0,%ymm2

vfmadd213ps 0xa0(%rdx,%rdi,4),%ymm1,%ymm3

vmovups %ymm2,0x80(%rdx,%rdi,4)

vmovups %ymm3,0xa0(%rdx,%rdi,4)

vmovups 0xc0(%rcx,%rdi,4),%ymm0

vmovups 0xc0(%rbx,%rdi,4),%ymm2

vmovups 0xe0(%rcx,%rdi,4),%ymm1

vmovups 0xe0(%rbx,%rdi,4),%ymm3

vfmadd213ps 0xc0(%rdx,%rdi,4),%ymm0,%ymm2

vfmadd213ps 0xe0(%rdx,%rdi,4),%ymm1,%ymm3

vmovups %ymm2,0xc0(%rdx,%rdi,4)

vmovups %ymm3,0xe0(%rdx,%rdi,4)

vmovups 0x100(%rcx,%rdi,4),%ymm0

vmovups 0x100(%rbx,%rdi,4),%ymm2

vmovups 0x120(%rcx,%rdi,4),%ymm1

vmovups 0x120(%rbx,%rdi,4),%ymm3

vfmadd213ps 0x100(%rdx,%rdi,4),%ymm0,%ymm2

vfmadd213ps 0x120(%rdx,%rdi,4),%ymm1,%ymm3

vmovups %ymm2,0x100(%rdx,%rdi,4)

vmovups %ymm3,0x120(%rdx,%rdi,4)

vmovups 0x140(%rcx,%rdi,4),%ymm0

vmovups 0x140(%rbx,%rdi,4),%ymm2

vmovups 0x160(%rcx,%rdi,4),%ymm1

vmovups 0x160(%rbx,%rdi,4),%ymm3

vfmadd213ps 0x140(%rdx,%rdi,4),%ymm0,%ymm2

vfmadd213ps 0x160(%rdx,%rdi,4),%ymm1,%ymm3

vmovups %ymm2,0x140(%rdx,%rdi,4)

vmovups %ymm3,0x160(%rdx,%rdi,4)

vmovups 0x180(%rcx,%rdi,4),%ymm0

vmovups 0x180(%rbx,%rdi,4),%ymm2

vmovups 0x1a0(%rcx,%rdi,4),%ymm1

vmovups 0x1a0(%rbx,%rdi,4),%ymm3

vfmadd213ps 0x180(%rdx,%rdi,4),%ymm0,%ymm2

vfmadd213ps 0x1a0(%rdx,%rdi,4),%ymm1,%ymm3

vmovups %ymm2,0x180(%rdx,%rdi,4)

vmovups %ymm3,0x1a0(%rdx,%rdi,4)

vmovups 0x1c0(%rcx,%rdi,4),%ymm0

vmovups 0x1c0(%rbx,%rdi,4),%ymm2

vmovups 0x1e0(%rcx,%rdi,4),%ymm1

vmovups 0x1e0(%rbx,%rdi,4),%ymm3

vfmadd213ps 0x1c0(%rdx,%rdi,4),%ymm0,%ymm2

vfmadd213ps 0x1e0(%rdx,%rdi,4),%ymm1,%ymm3

vmovups %ymm2,0x1c0(%rdx,%rdi,4)

vmovups %ymm3,0x1e0(%rdx,%rdi,4)

sub    $0xffffffffffffff80,%rdi
add    $0xfffffffffffffff8,%rbp
jne    bc60 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x1b0>
cmpq   $0x0,-0x10(%rsp)
je     beef <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x43f>
lea    0x20(%rdx,%rdi,4),%rbp
lea    0x20(%rbx,%rdi,4),%r9
lea    0x20(%rcx,%rdi,4),%rdi
xor    %r10d,%r10d
data16 data16 cs nopw 0x0(%rax,%rax,1)

vmovups -0x20(%rdi,%r10,1),%ymm0
vmovups -0x20(%r9,%r10,1),%ymm2
vmovups (%rdi,%r10,1),%ymm1
vmovups (%r9,%r10,1),%ymm3
vfmadd213ps -0x20(%rbp,%r10,1),%ymm0,%ymm2
vfmadd213ps 0x0(%rbp,%r10,1),%ymm1,%ymm3
vmovups %ymm2,-0x20(%rbp,%r10,1)
vmovups %ymm3,0x0(%rbp,%r10,1)
add    $0x40,%r10
cmp    %r10,%r13
jne    beb0 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x400>
mov    -0x20(%rsp),%rax
mov    -0x58(%rsp),%r10
mov    %rax,%rdi
cmp    %r14,%rax
je     c021 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x571>
data16 cs nopw 0x0(%rax,%rax,1)

mov    %r10,%rbp
sub    %rdi,%rbp
test   %r15,%r15
je     bf3d <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x48d>
mov    %r15,%rax
xchg   %ax,%ax
vmovss (%rcx,%rdi,4),%xmm0
vmovss (%rbx,%rdi,4),%xmm1
vfmadd213ss (%rdx,%rdi,4),%xmm0,%xmm1
vmovss %xmm1,(%rdx,%rdi,4)
inc    %rdi
dec    %rax
jne    bf20 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x470>
cmp    $0x7,%rbp
jb     c021 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x571>
nopw   0x0(%rax,%rax,1)

vmovss (%rcx,%rdi,4),%xmm0
vmovss (%rbx,%rdi,4),%xmm1
vfmadd213ss (%rdx,%rdi,4),%xmm0,%xmm1
vmovss %xmm1,(%rdx,%rdi,4)
vmovss 0x4(%rcx,%rdi,4),%xmm0
vmovss 0x4(%rbx,%rdi,4),%xmm1
vfmadd213ss 0x4(%rdx,%rdi,4),%xmm0,%xmm1
vmovss %xmm1,0x4(%rdx,%rdi,4)
vmovss 0x8(%rcx,%rdi,4),%xmm0
vmovss 0x8(%rbx,%rdi,4),%xmm1
vfmadd213ss 0x8(%rdx,%rdi,4),%xmm0,%xmm1
vmovss %xmm1,0x8(%rdx,%rdi,4)
vmovss 0xc(%rcx,%rdi,4),%xmm0
vmovss 0xc(%rbx,%rdi,4),%xmm1
vfmadd213ss 0xc(%rdx,%rdi,4),%xmm0,%xmm1
vmovss %xmm1,0xc(%rdx,%rdi,4)
vmovss 0x10(%rcx,%rdi,4),%xmm0
vmovss 0x10(%rbx,%rdi,4),%xmm1
vfmadd213ss 0x10(%rdx,%rdi,4),%xmm0,%xmm1
vmovss %xmm1,0x10(%rdx,%rdi,4)
vmovss 0x14(%rcx,%rdi,4),%xmm0
vmovss 0x14(%rbx,%rdi,4),%xmm1
vfmadd213ss 0x14(%rdx,%rdi,4),%xmm0,%xmm1
vmovss %xmm1,0x14(%rdx,%rdi,4)
vmovss 0x18(%rcx,%rdi,4),%xmm0
vmovss 0x18(%rbx,%rdi,4),%xmm1
vfmadd213ss 0x18(%rdx,%rdi,4),%xmm0,%xmm1
vmovss %xmm1,0x18(%rdx,%rdi,4)
vmovss 0x1c(%rcx,%rdi,4),%xmm0
vmovss 0x1c(%rbx,%rdi,4),%xmm1
vfmadd213ss 0x1c(%rdx,%rdi,4),%xmm0,%xmm1
vmovss %xmm1,0x1c(%rdx,%rdi,4)
add    $0x8,%rdi
cmp    %rdi,%r14
jne    bf50 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x4a0>
mov    -0x38(%rsp),%rcx
mov    -0x40(%rsp),%rdi
mov    -0x48(%rsp),%rdx
or     $0x8,%r8
lea    (%r8,%r8,2),%rax
mov    (%rcx,%rax,1),%rbp
mov    (%rdi,%rax,1),%r8
mov    (%rdx,%rax,1),%rcx
cmp    $0x10,%esi
jb     c0a0 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x5f0>
lea    0x0(%rbp,%r12,1),%rax
lea    (%rcx,%r12,1),%rdx
lea    (%r8,%r12,1),%rdi
cmp    %rax,%rcx
setb   %r9b
cmp    %rdx,%rbp
setb   %bl
cmp    %rdi,%rcx
setb   %al
cmp    %rdx,%r8
setb   %dl
test   %bl,%r9b
jne    c0a0 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x5f0>
and    %dl,%al
mov    $0x0,%edx
jne    c0a2 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x5f2>
cmpq   $0x70,-0x50(%rsp)
mov    -0x28(%rsp),%rax
jae    c1cf <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x71f>
xor    %edx,%edx
jmp    c41b <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x96b>
data16 cs nopw 0x0(%rax,%rax,1)

xor    %edx,%edx
mov    %r10,%rdi
sub    %rdx,%rdi
test   $0x7,%r14b
je     c0df <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x62f>
mov    %r15,%rax
data16 data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)


vmovss 0x0(%rbp,%rdx,4),%xmm0
vmovss (%r8,%rdx,4),%xmm1
vfmadd213ss (%rcx,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,(%rcx,%rdx,4)
inc    %rdx
dec    %rax
jne    c0c0 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x610>
cmp    $0x7,%rdi
jb     bba0 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xf0>
nopl   0x0(%rax)
vmovss 0x0(%rbp,%rdx,4),%xmm0
vmovss (%r8,%rdx,4),%xmm1
vfmadd213ss (%rcx,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,(%rcx,%rdx,4)
vmovss 0x4(%rbp,%rdx,4),%xmm0
vmovss 0x4(%r8,%rdx,4),%xmm1
vfmadd213ss 0x4(%rcx,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x4(%rcx,%rdx,4)
vmovss 0x8(%rbp,%rdx,4),%xmm0
vmovss 0x8(%r8,%rdx,4),%xmm1
vfmadd213ss 0x8(%rcx,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x8(%rcx,%rdx,4)
vmovss 0xc(%rbp,%rdx,4),%xmm0
vmovss 0xc(%r8,%rdx,4),%xmm1
vfmadd213ss 0xc(%rcx,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0xc(%rcx,%rdx,4)
vmovss 0x10(%rbp,%rdx,4),%xmm0
vmovss 0x10(%r8,%rdx,4),%xmm1
vfmadd213ss 0x10(%rcx,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x10(%rcx,%rdx,4)
vmovss 0x14(%rbp,%rdx,4),%xmm0
vmovss 0x14(%r8,%rdx,4),%xmm1
vfmadd213ss 0x14(%rcx,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x14(%rcx,%rdx,4)
vmovss 0x18(%rbp,%rdx,4),%xmm0
vmovss 0x18(%r8,%rdx,4),%xmm1
vfmadd213ss 0x18(%rcx,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x18(%rcx,%rdx,4)
vmovss 0x1c(%rbp,%rdx,4),%xmm0
vmovss 0x1c(%r8,%rdx,4),%xmm1
vfmadd213ss 0x1c(%rcx,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x1c(%rcx,%rdx,4)
add    $0x8,%rdx
cmp    %rdx,%r14
jne    c0f0 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x640>
jmp    bba0 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xf0>
mov    -0x30(%rsp),%rdi
xor    %edx,%edx
cs nopw 0x0(%rax,%rax,1)

vmovups 0x0(%rbp,%rdx,4),%ymm0
vmovups (%r8,%rdx,4),%ymm2
vmovups 0x20(%rbp,%rdx,4),%ymm1
vmovups 0x20(%r8,%rdx,4),%ymm3
vfmadd213ps (%rcx,%rdx,4),%ymm0,%ymm2
vfmadd213ps 0x20(%rcx,%rdx,4),%ymm1,%ymm3
vmovups %ymm2,(%rcx,%rdx,4)
vmovups %ymm3,0x20(%rcx,%rdx,4)
vmovups 0x40(%rbp,%rdx,4),%ymm0
vmovups 0x40(%r8,%rdx,4),%ymm2
vmovups 0x60(%rbp,%rdx,4),%ymm1
vmovups 0x60(%r8,%rdx,4),%ymm3
vfmadd213ps 0x40(%rcx,%rdx,4),%ymm0,%ymm2
vfmadd213ps 0x60(%rcx,%rdx,4),%ymm1,%ymm3
vmovups %ymm2,0x40(%rcx,%rdx,4)
vmovups %ymm3,0x60(%rcx,%rdx,4)
vmovups 0x80(%rbp,%rdx,4),%ymm0

vmovups 0x80(%r8,%rdx,4),%ymm2

vmovups 0xa0(%rbp,%rdx,4),%ymm1

vmovups 0xa0(%r8,%rdx,4),%ymm3

vfmadd213ps 0x80(%rcx,%rdx,4),%ymm0,%ymm2

vfmadd213ps 0xa0(%rcx,%rdx,4),%ymm1,%ymm3

vmovups %ymm2,0x80(%rcx,%rdx,4)

vmovups %ymm3,0xa0(%rcx,%rdx,4)

vmovups 0xc0(%rbp,%rdx,4),%ymm0

vmovups 0xc0(%r8,%rdx,4),%ymm2

vmovups 0xe0(%rbp,%rdx,4),%ymm1

vmovups 0xe0(%r8,%rdx,4),%ymm3

vfmadd213ps 0xc0(%rcx,%rdx,4),%ymm0,%ymm2

vfmadd213ps 0xe0(%rcx,%rdx,4),%ymm1,%ymm3

vmovups %ymm2,0xc0(%rcx,%rdx,4)

vmovups %ymm3,0xe0(%rcx,%rdx,4)

vmovups 0x100(%rbp,%rdx,4),%ymm0

vmovups 0x100(%r8,%rdx,4),%ymm2

vmovups 0x120(%rbp,%rdx,4),%ymm1

vmovups 0x120(%r8,%rdx,4),%ymm3

vfmadd213ps 0x100(%rcx,%rdx,4),%ymm0,%ymm2

vfmadd213ps 0x120(%rcx,%rdx,4),%ymm1,%ymm3

vmovups %ymm2,0x100(%rcx,%rdx,4)

vmovups %ymm3,0x120(%rcx,%rdx,4)

vmovups 0x140(%rbp,%rdx,4),%ymm0

vmovups 0x140(%r8,%rdx,4),%ymm2

vmovups 0x160(%rbp,%rdx,4),%ymm1

vmovups 0x160(%r8,%rdx,4),%ymm3

vfmadd213ps 0x140(%rcx,%rdx,4),%ymm0,%ymm2

vfmadd213ps 0x160(%rcx,%rdx,4),%ymm1,%ymm3

vmovups %ymm2,0x140(%rcx,%rdx,4)

vmovups %ymm3,0x160(%rcx,%rdx,4)

vmovups 0x180(%rbp,%rdx,4),%ymm0

vmovups 0x180(%r8,%rdx,4),%ymm2

vmovups 0x1a0(%rbp,%rdx,4),%ymm1

vmovups 0x1a0(%r8,%rdx,4),%ymm3

vfmadd213ps 0x180(%rcx,%rdx,4),%ymm0,%ymm2

vfmadd213ps 0x1a0(%rcx,%rdx,4),%ymm1,%ymm3

vmovups %ymm2,0x180(%rcx,%rdx,4)

vmovups %ymm3,0x1a0(%rcx,%rdx,4)

vmovups 0x1c0(%rbp,%rdx,4),%ymm0

vmovups 0x1c0(%r8,%rdx,4),%ymm2

vmovups 0x1e0(%rbp,%rdx,4),%ymm1

vmovups 0x1e0(%r8,%rdx,4),%ymm3

vfmadd213ps 0x1c0(%rcx,%rdx,4),%ymm0,%ymm2

vfmadd213ps 0x1e0(%rcx,%rdx,4),%ymm1,%ymm3

vmovups %ymm2,0x1c0(%rcx,%rdx,4)

vmovups %ymm3,0x1e0(%rcx,%rdx,4)

sub    $0xffffffffffffff80,%rdx
add    $0xfffffffffffffff8,%rdi
jne    c1e0 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x730>
test   $0x7,%al
je     c467 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x9b7>
lea    0x20(%rcx,%rdx,4),%rdi
lea    0x20(%r8,%rdx,4),%rbx
lea    0x20(%rbp,%rdx,4),%rdx
xor    %eax,%eax
vmovups -0x20(%rdx,%rax,1),%ymm0
vmovups -0x20(%rbx,%rax,1),%ymm2
vmovups (%rdx,%rax,1),%ymm1
vmovups (%rbx,%rax,1),%ymm3
vfmadd213ps -0x20(%rdi,%rax,1),%ymm0,%ymm2
vfmadd213ps (%rdi,%rax,1),%ymm1,%ymm3
vmovups %ymm2,-0x20(%rdi,%rax,1)
vmovups %ymm3,(%rdi,%rax,1)
add    $0x40,%rax
cmp    %rax,%r13
jne    c430 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x980>
mov    -0x20(%rsp),%rax
mov    %rax,%rdx
cmp    %r14,%rax
je     bba0 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xf0>
jmp    c0a2 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0x5f2>
lea    (%rdi,%r12,1),%rax
lea    0x0(%rbp,%r12,1),%rdx
add    %rcx,%r12
cmp    %rax,%rbp
setb   %r8b
cmp    %rdx,%rdi
setb   %bl
cmp    %r12,%rbp
setb   %al
cmp    %rdx,%rcx
setb   %sil
xor    %edx,%edx
test   %bl,%r8b
jne    c779 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xcc9>
and    %sil,%al
jne    c779 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xcc9>
mov    -0x28(%rsp),%rax
mov    %r14d,%edx
and    $0xfffffff0,%edx
mov    %eax,%r8d
and    $0x7,%r8d
cmpq   $0x70,-0x50(%rsp)
jae    c4d8 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xa28>
xor    %ebx,%ebx
jmp    c70c <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xc5c>
and    $0xfffffffffffffff8,%rax
xor    %ebx,%ebx
xchg   %ax,%ax
vmovups (%rdi,%rbx,4),%ymm0
vmovups (%rcx,%rbx,4),%ymm2
vmovups 0x20(%rdi,%rbx,4),%ymm1
vmovups 0x20(%rcx,%rbx,4),%ymm3
vfmadd213ps 0x0(%rbp,%rbx,4),%ymm0,%ymm2
vfmadd213ps 0x20(%rbp,%rbx,4),%ymm1,%ymm3
vmovups %ymm2,0x0(%rbp,%rbx,4)
vmovups %ymm3,0x20(%rbp,%rbx,4)
vmovups 0x40(%rdi,%rbx,4),%ymm0
vmovups 0x40(%rcx,%rbx,4),%ymm2
vmovups 0x60(%rdi,%rbx,4),%ymm1
vmovups 0x60(%rcx,%rbx,4),%ymm3
vfmadd213ps 0x40(%rbp,%rbx,4),%ymm0,%ymm2
vfmadd213ps 0x60(%rbp,%rbx,4),%ymm1,%ymm3
vmovups %ymm2,0x40(%rbp,%rbx,4)
vmovups %ymm3,0x60(%rbp,%rbx,4)
vmovups 0x80(%rdi,%rbx,4),%ymm0

vmovups 0x80(%rcx,%rbx,4),%ymm2

vmovups 0xa0(%rdi,%rbx,4),%ymm1

vmovups 0xa0(%rcx,%rbx,4),%ymm3

vfmadd213ps 0x80(%rbp,%rbx,4),%ymm0,%ymm2

vfmadd213ps 0xa0(%rbp,%rbx,4),%ymm1,%ymm3

vmovups %ymm2,0x80(%rbp,%rbx,4)

vmovups %ymm3,0xa0(%rbp,%rbx,4)

vmovups 0xc0(%rdi,%rbx,4),%ymm0

vmovups 0xc0(%rcx,%rbx,4),%ymm2

vmovups 0xe0(%rdi,%rbx,4),%ymm1

vmovups 0xe0(%rcx,%rbx,4),%ymm3

vfmadd213ps 0xc0(%rbp,%rbx,4),%ymm0,%ymm2

vfmadd213ps 0xe0(%rbp,%rbx,4),%ymm1,%ymm3

vmovups %ymm2,0xc0(%rbp,%rbx,4)

vmovups %ymm3,0xe0(%rbp,%rbx,4)

vmovups 0x100(%rdi,%rbx,4),%ymm0

vmovups 0x100(%rcx,%rbx,4),%ymm2

vmovups 0x120(%rdi,%rbx,4),%ymm1

vmovups 0x120(%rcx,%rbx,4),%ymm3

vfmadd213ps 0x100(%rbp,%rbx,4),%ymm0,%ymm2

vfmadd213ps 0x120(%rbp,%rbx,4),%ymm1,%ymm3

vmovups %ymm2,0x100(%rbp,%rbx,4)

vmovups %ymm3,0x120(%rbp,%rbx,4)

vmovups 0x140(%rdi,%rbx,4),%ymm0

vmovups 0x140(%rcx,%rbx,4),%ymm2

vmovups 0x160(%rdi,%rbx,4),%ymm1

vmovups 0x160(%rcx,%rbx,4),%ymm3

vfmadd213ps 0x140(%rbp,%rbx,4),%ymm0,%ymm2

vfmadd213ps 0x160(%rbp,%rbx,4),%ymm1,%ymm3

vmovups %ymm2,0x140(%rbp,%rbx,4)

vmovups %ymm3,0x160(%rbp,%rbx,4)

vmovups 0x180(%rdi,%rbx,4),%ymm0

vmovups 0x180(%rcx,%rbx,4),%ymm2

vmovups 0x1a0(%rdi,%rbx,4),%ymm1

vmovups 0x1a0(%rcx,%rbx,4),%ymm3

vfmadd213ps 0x180(%rbp,%rbx,4),%ymm0,%ymm2

vfmadd213ps 0x1a0(%rbp,%rbx,4),%ymm1,%ymm3

vmovups %ymm2,0x180(%rbp,%rbx,4)

vmovups %ymm3,0x1a0(%rbp,%rbx,4)

vmovups 0x1c0(%rdi,%rbx,4),%ymm0

vmovups 0x1c0(%rcx,%rbx,4),%ymm2

vmovups 0x1e0(%rdi,%rbx,4),%ymm1

vmovups 0x1e0(%rcx,%rbx,4),%ymm3

vfmadd213ps 0x1c0(%rbp,%rbx,4),%ymm0,%ymm2

vfmadd213ps 0x1e0(%rbp,%rbx,4),%ymm1,%ymm3

vmovups %ymm2,0x1c0(%rbp,%rbx,4)

vmovups %ymm3,0x1e0(%rbp,%rbx,4)

sub    $0xffffffffffffff80,%rbx
add    $0xfffffffffffffff8,%rax
jne    c4e0 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xa30>
test   %r8,%r8
je     c76b <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xcbb>
lea    0x20(%rbp,%rbx,4),%rsi
lea    0x20(%rcx,%rbx,4),%r9
lea    0x20(%rdi,%rbx,4),%r10
shl    $0x6,%r8
xor    %ebx,%ebx
cs nopw 0x0(%rax,%rax,1)

vmovups -0x20(%r10,%rbx,1),%ymm0
vmovups -0x20(%r9,%rbx,1),%ymm2
vmovups (%r10,%rbx,1),%ymm1
vmovups (%r9,%rbx,1),%ymm3
vfmadd213ps -0x20(%rsi,%rbx,1),%ymm0,%ymm2
vfmadd213ps (%rsi,%rbx,1),%ymm1,%ymm3
vmovups %ymm2,-0x20(%rsi,%rbx,1)
vmovups %ymm3,(%rsi,%rbx,1)
add    $0x40,%rbx
cmp    %rbx,%r8
jne    c730 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xc80>
mov    -0x58(%rsp),%r10
cmp    %r14,%rdx
je     c893 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xde3>
sub    %rdx,%r10
mov    %r14,%rsi
and    $0x7,%rsi
je     c7af <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xcff>
data16 cs nopw 0x0(%rax,%rax,1)

vmovss (%rdi,%rdx,4),%xmm0
vmovss (%rcx,%rdx,4),%xmm1
vfmadd213ss 0x0(%rbp,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x0(%rbp,%rdx,4)
inc    %rdx
dec    %rsi
jne    c790 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xce0>
cmp    $0x7,%r10
jb     c893 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xde3>
nopl   0x0(%rax)
vmovss (%rdi,%rdx,4),%xmm0
vmovss (%rcx,%rdx,4),%xmm1
vfmadd213ss 0x0(%rbp,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x0(%rbp,%rdx,4)
vmovss 0x4(%rdi,%rdx,4),%xmm0
vmovss 0x4(%rcx,%rdx,4),%xmm1
vfmadd213ss 0x4(%rbp,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x4(%rbp,%rdx,4)
vmovss 0x8(%rdi,%rdx,4),%xmm0
vmovss 0x8(%rcx,%rdx,4),%xmm1
vfmadd213ss 0x8(%rbp,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x8(%rbp,%rdx,4)
vmovss 0xc(%rdi,%rdx,4),%xmm0
vmovss 0xc(%rcx,%rdx,4),%xmm1
vfmadd213ss 0xc(%rbp,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0xc(%rbp,%rdx,4)
vmovss 0x10(%rdi,%rdx,4),%xmm0
vmovss 0x10(%rcx,%rdx,4),%xmm1
vfmadd213ss 0x10(%rbp,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x10(%rbp,%rdx,4)
vmovss 0x14(%rdi,%rdx,4),%xmm0
vmovss 0x14(%rcx,%rdx,4),%xmm1
vfmadd213ss 0x14(%rbp,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x14(%rbp,%rdx,4)
vmovss 0x18(%rdi,%rdx,4),%xmm0
vmovss 0x18(%rcx,%rdx,4),%xmm1
vfmadd213ss 0x18(%rbp,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x18(%rbp,%rdx,4)
vmovss 0x1c(%rdi,%rdx,4),%xmm0
vmovss 0x1c(%rcx,%rdx,4),%xmm1
vfmadd213ss 0x1c(%rbp,%rdx,4),%xmm0,%xmm1
vmovss %xmm1,0x1c(%rbp,%rdx,4)
add    $0x8,%rdx
cmp    %rdx,%r14
jne    c7c0 <_Z4xxxxiiRSt6vectorIS_IfSaIfEESaIS1_EES4_S4_+0xd10>
pop    %rbx
pop    %r12
pop    %r13
pop    %r14
pop    %r15
pop    %rbp
vzeroupper
ret
data16 data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)
