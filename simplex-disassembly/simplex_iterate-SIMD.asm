000000000000a080 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE>:
    a080:	55                   	push   %rbp
    a081:	41 57                	push   %r15
    a083:	41 56                	push   %r14
    a085:	41 55                	push   %r13
    a087:	41 54                	push   %r12
    a089:	53                   	push   %rbx
    a08a:	48 83 ec 18          	sub    $0x18,%rsp
    a08e:	49 89 fa             	mov    %rdi,%r10
    a091:	48 8b 07             	mov    (%rdi),%rax
    a094:	48 8b 4f 08          	mov    0x8(%rdi),%rcx
    a098:	48 29 c1             	sub    %rax,%rcx
    a09b:	48 c1 f9 03          	sar    $0x3,%rcx
    a09f:	49 b9 ab aa aa aa aa 	movabs $0xaaaaaaaaaaaaaaab,%r9
    a0a6:	aa aa aa 
    a0a9:	4c 0f af c9          	imul   %rcx,%r9
    a0ad:	4c 8b 40 08          	mov    0x8(%rax),%r8
    a0b1:	4c 2b 00             	sub    (%rax),%r8
    a0b4:	45 8d 69 ff          	lea    -0x1(%r9),%r13d
    a0b8:	4d 63 e5             	movslq %r13d,%r12
    a0bb:	4b 8d 1c 64          	lea    (%r12,%r12,2),%rbx
    a0bf:	48 8b 7c d8 08       	mov    0x8(%rax,%rbx,8),%rdi
    a0c4:	48 2b 3c d8          	sub    (%rax,%rbx,8),%rdi
    a0c8:	74 4b                	je     a115 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x95>
    a0ca:	4c 89 14 24          	mov    %r10,(%rsp)
    a0ce:	48 b9 fd ff ff ff ff 	movabs $0x7ffffffffffffffd,%rcx
    a0d5:	ff ff 7f 
    a0d8:	48 39 cf             	cmp    %rcx,%rdi
    a0db:	0f 83 61 05 00 00    	jae    a642 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x5c2>
    a0e1:	4d 89 cf             	mov    %r9,%r15
    a0e4:	4c 89 c5             	mov    %r8,%rbp
    a0e7:	4c 8d 34 d8          	lea    (%rax,%rbx,8),%r14
    a0eb:	e8 a0 c3 ff ff       	callq  6490 <_Znwm@plt>
    a0f0:	49 8b 36             	mov    (%r14),%rsi
    a0f3:	49 8b 56 08          	mov    0x8(%r14),%rdx
    a0f7:	48 29 f2             	sub    %rsi,%rdx
    a0fa:	48 89 44 24 10       	mov    %rax,0x10(%rsp)
    a0ff:	74 08                	je     a109 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x89>
    a101:	48 89 c7             	mov    %rax,%rdi
    a104:	e8 67 c6 ff ff       	callq  6770 <memmove@plt>
    a109:	49 89 e8             	mov    %rbp,%r8
    a10c:	4d 89 f9             	mov    %r15,%r9
    a10f:	4c 8b 14 24          	mov    (%rsp),%r10
    a113:	eb 07                	jmp    a11c <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x9c>
    a115:	31 c0                	xor    %eax,%eax
    a117:	48 89 44 24 10       	mov    %rax,0x10(%rsp)
    a11c:	49 8b 0a             	mov    (%r10),%rcx
    a11f:	48 8b 04 d9          	mov    (%rcx,%rbx,8),%rax
    a123:	48 8b 4c d9 08       	mov    0x8(%rcx,%rbx,8),%rcx
    a128:	49 89 c6             	mov    %rax,%r14
    a12b:	48 39 c8             	cmp    %rcx,%rax
    a12e:	74 39                	je     a169 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0xe9>
    a130:	48 8d 50 04          	lea    0x4(%rax),%rdx
    a134:	49 89 c6             	mov    %rax,%r14
    a137:	48 39 ca             	cmp    %rcx,%rdx
    a13a:	74 2d                	je     a169 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0xe9>
    a13c:	c5 fa 10 00          	vmovss (%rax),%xmm0
    a140:	49 89 c6             	mov    %rax,%r14
    a143:	66 66 66 66 2e 0f 1f 	data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
    a14a:	84 00 00 00 00 00 
    a150:	c5 fa 10 0a          	vmovss (%rdx),%xmm1
    a154:	c5 f8 2e c1          	vucomiss %xmm1,%xmm0
    a158:	c5 f2 5d c0          	vminss %xmm0,%xmm1,%xmm0
    a15c:	4c 0f 47 f2          	cmova  %rdx,%r14
    a160:	48 83 c2 04          	add    $0x4,%rdx
    a164:	48 39 ca             	cmp    %rcx,%rdx
    a167:	75 e7                	jne    a150 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0xd0>
    a169:	45 85 c9             	test   %r9d,%r9d
    a16c:	0f 8e c4 04 00 00    	jle    a636 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x5b6>
    a172:	49 29 c6             	sub    %rax,%r14
    a175:	45 85 ed             	test   %r13d,%r13d
    a178:	74 73                	je     a1ed <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x16d>
    a17a:	4c 89 d5             	mov    %r10,%rbp
    a17d:	4c 89 0c 24          	mov    %r9,(%rsp)
    a181:	4c 89 44 24 08       	mov    %r8,0x8(%rsp)
    a186:	49 c1 e4 02          	shl    $0x2,%r12
    a18a:	4c 89 e7             	mov    %r12,%rdi
    a18d:	e8 fe c2 ff ff       	callq  6490 <_Znwm@plt>
    a192:	48 89 c3             	mov    %rax,%rbx
    a195:	45 31 ff             	xor    %r15d,%r15d
    a198:	48 89 c7             	mov    %rax,%rdi
    a19b:	31 f6                	xor    %esi,%esi
    a19d:	4c 89 e2             	mov    %r12,%rdx
    a1a0:	e8 cb c0 ff ff       	callq  6270 <memset@plt>
    a1a5:	49 89 ea             	mov    %rbp,%r10
    a1a8:	48 8b 55 00          	mov    0x0(%rbp),%rdx
    a1ac:	4c 8b 44 24 08       	mov    0x8(%rsp),%r8
    a1b1:	4c 89 c1             	mov    %r8,%rcx
    a1b4:	48 c1 e1 1e          	shl    $0x1e,%rcx
    a1b8:	48 b8 00 00 00 00 ff 	movabs $0xffffffff00000000,%rax
    a1bf:	ff ff ff 
    a1c2:	48 01 c8             	add    %rcx,%rax
    a1c5:	48 c1 f8 20          	sar    $0x20,%rax
    a1c9:	4c 89 f1             	mov    %r14,%rcx
    a1cc:	48 c1 e9 02          	shr    $0x2,%rcx
    a1d0:	48 63 c9             	movslq %ecx,%rcx
    a1d3:	44 89 ee             	mov    %r13d,%esi
    a1d6:	48 8d 7e ff          	lea    -0x1(%rsi),%rdi
    a1da:	41 83 e5 03          	and    $0x3,%r13d
    a1de:	48 83 ff 03          	cmp    $0x3,%rdi
    a1e2:	73 1f                	jae    a203 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x183>
    a1e4:	4c 8b 0c 24          	mov    (%rsp),%r9
    a1e8:	e9 8a 00 00 00       	jmpq   a277 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x1f7>
    a1ed:	31 db                	xor    %ebx,%ebx
    a1ef:	31 f6                	xor    %esi,%esi
    a1f1:	49 c1 e8 02          	shr    $0x2,%r8
    a1f5:	45 85 c0             	test   %r8d,%r8d
    a1f8:	0f 8f 26 01 00 00    	jg     a324 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x2a4>
    a1fe:	e9 f5 03 00 00       	jmpq   a5f8 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x578>
    a203:	83 e6 fc             	and    $0xfffffffc,%esi
    a206:	45 31 ff             	xor    %r15d,%r15d
    a209:	48 89 d7             	mov    %rdx,%rdi
    a20c:	4c 8b 0c 24          	mov    (%rsp),%r9
    a210:	48 8b 2f             	mov    (%rdi),%rbp
    a213:	c5 fa 10 44 85 00    	vmovss 0x0(%rbp,%rax,4),%xmm0
    a219:	c5 fa 5e 44 8d 00    	vdivss 0x0(%rbp,%rcx,4),%xmm0,%xmm0
    a21f:	c4 a1 7a 11 04 bb    	vmovss %xmm0,(%rbx,%r15,4)
    a225:	48 8b 6f 18          	mov    0x18(%rdi),%rbp
    a229:	c5 fa 10 44 85 00    	vmovss 0x0(%rbp,%rax,4),%xmm0
    a22f:	c5 fa 5e 44 8d 00    	vdivss 0x0(%rbp,%rcx,4),%xmm0,%xmm0
    a235:	c4 a1 7a 11 44 bb 04 	vmovss %xmm0,0x4(%rbx,%r15,4)
    a23c:	48 8b 6f 30          	mov    0x30(%rdi),%rbp
    a240:	c5 fa 10 44 85 00    	vmovss 0x0(%rbp,%rax,4),%xmm0
    a246:	c5 fa 5e 44 8d 00    	vdivss 0x0(%rbp,%rcx,4),%xmm0,%xmm0
    a24c:	c4 a1 7a 11 44 bb 08 	vmovss %xmm0,0x8(%rbx,%r15,4)
    a253:	48 8b 6f 48          	mov    0x48(%rdi),%rbp
    a257:	c5 fa 10 44 85 00    	vmovss 0x0(%rbp,%rax,4),%xmm0
    a25d:	c5 fa 5e 44 8d 00    	vdivss 0x0(%rbp,%rcx,4),%xmm0,%xmm0
    a263:	c4 a1 7a 11 44 bb 0c 	vmovss %xmm0,0xc(%rbx,%r15,4)
    a26a:	49 83 c7 04          	add    $0x4,%r15
    a26e:	48 83 c7 60          	add    $0x60,%rdi
    a272:	4c 39 fe             	cmp    %r15,%rsi
    a275:	75 99                	jne    a210 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x190>
    a277:	49 01 dc             	add    %rbx,%r12
    a27a:	4d 85 ed             	test   %r13,%r13
    a27d:	74 31                	je     a2b0 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x230>
    a27f:	4a 8d 34 bb          	lea    (%rbx,%r15,4),%rsi
    a283:	4b 8d 3c 7f          	lea    (%r15,%r15,2),%rdi
    a287:	48 8d 14 fa          	lea    (%rdx,%rdi,8),%rdx
    a28b:	31 ff                	xor    %edi,%edi
    a28d:	0f 1f 00             	nopl   (%rax)
    a290:	48 8b 2a             	mov    (%rdx),%rbp
    a293:	c5 fa 10 44 85 00    	vmovss 0x0(%rbp,%rax,4),%xmm0
    a299:	c5 fa 5e 44 8d 00    	vdivss 0x0(%rbp,%rcx,4),%xmm0,%xmm0
    a29f:	c5 fa 11 04 be       	vmovss %xmm0,(%rsi,%rdi,4)
    a2a4:	48 ff c7             	inc    %rdi
    a2a7:	48 83 c2 18          	add    $0x18,%rdx
    a2ab:	49 39 fd             	cmp    %rdi,%r13
    a2ae:	75 e0                	jne    a290 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x210>
    a2b0:	4c 39 e3             	cmp    %r12,%rbx
    a2b3:	0f 84 2f 03 00 00    	je     a5e8 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x568>
    a2b9:	48 8d 43 04          	lea    0x4(%rbx),%rax
    a2bd:	4c 39 e0             	cmp    %r12,%rax
    a2c0:	0f 84 10 03 00 00    	je     a5d6 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x556>
    a2c6:	c5 fa 10 03          	vmovss (%rbx),%xmm0
    a2ca:	49 63 c9             	movslq %r9d,%rcx
    a2cd:	48 c1 e1 02          	shl    $0x2,%rcx
    a2d1:	b8 08 00 00 00       	mov    $0x8,%eax
    a2d6:	48 29 c8             	sub    %rcx,%rax
    a2d9:	b9 04 00 00 00       	mov    $0x4,%ecx
    a2de:	48 89 de             	mov    %rbx,%rsi
    a2e1:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
    a2e8:	0f 1f 84 00 00 00 00 
    a2ef:	00 
    a2f0:	48 8d 14 0b          	lea    (%rbx,%rcx,1),%rdx
    a2f4:	c5 fa 10 0c 0b       	vmovss (%rbx,%rcx,1),%xmm1
    a2f9:	c5 f8 2e c1          	vucomiss %xmm1,%xmm0
    a2fd:	c5 f2 5d c0          	vminss %xmm0,%xmm1,%xmm0
    a301:	48 0f 47 f2          	cmova  %rdx,%rsi
    a305:	48 8d 14 08          	lea    (%rax,%rcx,1),%rdx
    a309:	48 83 c2 04          	add    $0x4,%rdx
    a30d:	48 83 c1 04          	add    $0x4,%rcx
    a311:	48 83 fa 04          	cmp    $0x4,%rdx
    a315:	75 d9                	jne    a2f0 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x270>
    a317:	49 c1 e8 02          	shr    $0x2,%r8
    a31b:	45 85 c0             	test   %r8d,%r8d
    a31e:	0f 8e d4 02 00 00    	jle    a5f8 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x578>
    a324:	48 29 de             	sub    %rbx,%rsi
    a327:	48 c1 ee 02          	shr    $0x2,%rsi
    a32b:	48 63 c6             	movslq %esi,%rax
    a32e:	4d 8b 1a             	mov    (%r10),%r11
    a331:	48 8d 04 40          	lea    (%rax,%rax,2),%rax
    a335:	4c 89 f2             	mov    %r14,%rdx
    a338:	48 c1 e2 1e          	shl    $0x1e,%rdx
    a33c:	49 8b 0c c3          	mov    (%r11,%rax,8),%rcx
    a340:	48 c1 fa 1e          	sar    $0x1e,%rdx
    a344:	c5 fa 10 04 11       	vmovss (%rcx,%rdx,1),%xmm0
    a349:	44 89 c2             	mov    %r8d,%edx
    a34c:	48 83 fa 20          	cmp    $0x20,%rdx
    a350:	73 04                	jae    a356 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x2d6>
    a352:	31 c0                	xor    %eax,%eax
    a354:	eb 6a                	jmp    a3c0 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x340>
    a356:	44 89 c7             	mov    %r8d,%edi
    a359:	83 e7 1f             	and    $0x1f,%edi
    a35c:	48 89 d0             	mov    %rdx,%rax
    a35f:	48 29 f8             	sub    %rdi,%rax
    a362:	c4 e2 7d 18 c8       	vbroadcastss %xmm0,%ymm1
    a367:	31 ed                	xor    %ebp,%ebp
    a369:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    a370:	c5 fc 10 14 a9       	vmovups (%rcx,%rbp,4),%ymm2                 // part 1
    a375:	c5 fc 10 5c a9 20    	vmovups 0x20(%rcx,%rbp,4),%ymm3             // compute (vmovups,vdivps,vmovups)*4 throughput
    a37b:	c5 fc 10 64 a9 40    	vmovups 0x40(%rcx,%rbp,4),%ymm4             // instr    | latency | recip-throput | throughput 
    a381:	c5 fc 10 6c a9 60    	vmovups 0x60(%rcx,%rbp,4),%ymm5             // vmovups  | 3       | 0.5           | 2
    a387:	c5 ec 5e d1          	vdivps %ymm1,%ymm2,%ymm2                    // vdivps   | 11      | 5             | 1/5  
    a38b:	c5 e4 5e d9          	vdivps %ymm1,%ymm3,%ymm3
    a38f:	c5 dc 5e e1          	vdivps %ymm1,%ymm4,%ymm4
    a393:	c5 d4 5e e9          	vdivps %ymm1,%ymm5,%ymm5
    a397:	c5 fc 11 14 a9       	vmovups %ymm2,(%rcx,%rbp,4)
    a39c:	c5 fc 11 5c a9 20    	vmovups %ymm3,0x20(%rcx,%rbp,4)
    a3a2:	c5 fc 11 64 a9 40    	vmovups %ymm4,0x40(%rcx,%rbp,4)
    a3a8:	c5 fc 11 6c a9 60    	vmovups %ymm5,0x60(%rcx,%rbp,4)
    a3ae:	48 83 c5 20          	add    $0x20,%rbp
    a3b2:	48 39 e8             	cmp    %rbp,%rax
    a3b5:	75 b9                	jne    a370 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x2f0>
    a3b7:	48 85 ff             	test   %rdi,%rdi
    a3ba:	74 1a                	je     a3d6 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x356>
    a3bc:	0f 1f 40 00          	nopl   0x0(%rax)
    a3c0:	c5 fa 10 0c 81       	vmovss (%rcx,%rax,4),%xmm1
    a3c5:	c5 f2 5e c8          	vdivss %xmm0,%xmm1,%xmm1
    a3c9:	c5 fa 11 0c 81       	vmovss %xmm1,(%rcx,%rax,4)
    a3ce:	48 ff c0             	inc    %rax
    a3d1:	48 39 c2             	cmp    %rax,%rdx
    a3d4:	75 ea                	jne    a3c0 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x340>
    a3d6:	45 85 c0             	test   %r8d,%r8d
    a3d9:	0f 8e 19 02 00 00    	jle    a5f8 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x578>
    a3df:	45 85 c9             	test   %r9d,%r9d
    a3e2:	0f 8e 10 02 00 00    	jle    a5f8 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x578>
    a3e8:	49 c1 ee 02          	shr    $0x2,%r14
    a3ec:	4d 63 f6             	movslq %r14d,%r14
    a3ef:	41 89 f7             	mov    %esi,%r15d
    a3f2:	45 89 cc             	mov    %r9d,%r12d
    a3f5:	48 8d 04 95 00 00 00 	lea    0x0(,%rdx,4),%rax
    a3fc:	00 
    a3fd:	48 89 04 24          	mov    %rax,(%rsp)
    a401:	4c 8d 0c 91          	lea    (%rcx,%rdx,4),%r9
    a405:	44 89 c0             	mov    %r8d,%eax
    a408:	83 e0 1f             	and    $0x1f,%eax
    a40b:	48 89 d5             	mov    %rdx,%rbp
    a40e:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    a413:	48 29 c5             	sub    %rax,%rbp
    a416:	31 f6                	xor    %esi,%esi
    a418:	c4 e2 79 18 05 e3 ab 	vbroadcastss 0x4abe3(%rip),%xmm0        # 55004 <_IO_stdin_used+0x4>
    a41f:	04 00 
    a421:	eb 19                	jmp    a43c <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x3bc>
    a423:	66 66 66 66 2e 0f 1f 	data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
    a42a:	84 00 00 00 00 00 
    a430:	48 ff c6             	inc    %rsi
    a433:	4c 39 e6             	cmp    %r12,%rsi
    a436:	0f 84 bc 01 00 00    	je     a5f8 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x578>
    a43c:	4c 39 fe             	cmp    %r15,%rsi
    a43f:	74 ef                	je     a430 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x3b0>
    a441:	48 8d 04 76          	lea    (%rsi,%rsi,2),%rax
    a445:	49 8b 3c c3          	mov    (%r11,%rax,8),%rdi
    a449:	c4 a1 7a 10 0c b7    	vmovss (%rdi,%r14,4),%xmm1
    a44f:	c5 f0 57 c8          	vxorps %xmm0,%xmm1,%xmm1
    a453:	83 fa 20             	cmp    $0x20,%edx
    a456:	72 19                	jb     a471 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x3f1>
    a458:	4c 39 cf             	cmp    %r9,%rdi
    a45b:	0f 83 06 01 00 00    	jae    a567 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x4e7>
    a461:	48 8b 04 24          	mov    (%rsp),%rax
    a465:	48 01 f8             	add    %rdi,%rax
    a468:	48 39 c1             	cmp    %rax,%rcx
    a46b:	0f 83 f6 00 00 00    	jae    a567 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x4e7>
    a471:	31 c0                	xor    %eax,%eax
    a473:	4d 89 c2             	mov    %r8,%r10
    a476:	45 89 c5             	mov    %r8d,%r13d
    a479:	41 29 c5             	sub    %eax,%r13d
    a47c:	49 89 c0             	mov    %rax,%r8
    a47f:	49 f7 d0             	not    %r8
    a482:	49 01 d0             	add    %rdx,%r8
    a485:	49 83 e5 07          	and    $0x7,%r13
    a489:	74 1d                	je     a4a8 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x428>
    a48b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
    a490:	c5 fa 10 14 81       	vmovss (%rcx,%rax,4),%xmm2
    a495:	c4 e2 71 a9 14 87    	vfmadd213ss (%rdi,%rax,4),%xmm1,%xmm2
    a49b:	c5 fa 11 14 87       	vmovss %xmm2,(%rdi,%rax,4)
    a4a0:	48 ff c0             	inc    %rax
    a4a3:	49 ff cd             	dec    %r13
    a4a6:	75 e8                	jne    a490 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x410>
    a4a8:	49 83 f8 07          	cmp    $0x7,%r8
    a4ac:	4d 89 d0             	mov    %r10,%r8
    a4af:	0f 82 7b ff ff ff    	jb     a430 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x3b0>
    a4b5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    a4bc:	00 00 00 00 
    a4c0:	c5 fa 10 14 81       	vmovss (%rcx,%rax,4),%xmm2              
    a4c5:	c4 e2 71 a9 14 87    	vfmadd213ss (%rdi,%rax,4),%xmm1,%xmm2
    a4cb:	c5 fa 11 14 87       	vmovss %xmm2,(%rdi,%rax,4) 
    a4d0:	c5 fa 10 54 81 04    	vmovss 0x4(%rcx,%rax,4),%xmm2
    a4d6:	c4 e2 71 a9 54 87 04 	vfmadd213ss 0x4(%rdi,%rax,4),%xmm1,%xmm2
    a4dd:	c5 fa 11 54 87 04    	vmovss %xmm2,0x4(%rdi,%rax,4)
    a4e3:	c5 fa 10 54 81 08    	vmovss 0x8(%rcx,%rax,4),%xmm2
    a4e9:	c4 e2 71 a9 54 87 08 	vfmadd213ss 0x8(%rdi,%rax,4),%xmm1,%xmm2
    a4f0:	c5 fa 11 54 87 08    	vmovss %xmm2,0x8(%rdi,%rax,4)
    a4f6:	c5 fa 10 54 81 0c    	vmovss 0xc(%rcx,%rax,4),%xmm2 
    a4fc:	c4 e2 71 a9 54 87 0c 	vfmadd213ss 0xc(%rdi,%rax,4),%xmm1,%xmm2
    a503:	c5 fa 11 54 87 0c    	vmovss %xmm2,0xc(%rdi,%rax,4)
    a509:	c5 fa 10 54 81 10    	vmovss 0x10(%rcx,%rax,4),%xmm2
    a50f:	c4 e2 71 a9 54 87 10 	vfmadd213ss 0x10(%rdi,%rax,4),%xmm1,%xmm2
    a516:	c5 fa 11 54 87 10    	vmovss %xmm2,0x10(%rdi,%rax,4)
    a51c:	c5 fa 10 54 81 14    	vmovss 0x14(%rcx,%rax,4),%xmm2
    a522:	c4 e2 71 a9 54 87 14 	vfmadd213ss 0x14(%rdi,%rax,4),%xmm1,%xmm2
    a529:	c5 fa 11 54 87 14    	vmovss %xmm2,0x14(%rdi,%rax,4)
    a52f:	c5 fa 10 54 81 18    	vmovss 0x18(%rcx,%rax,4),%xmm2
    a535:	c4 e2 71 a9 54 87 18 	vfmadd213ss 0x18(%rdi,%rax,4),%xmm1,%xmm2
    a53c:	c5 fa 11 54 87 18    	vmovss %xmm2,0x18(%rdi,%rax,4)
    a542:	c5 fa 10 54 81 1c    	vmovss 0x1c(%rcx,%rax,4),%xmm2
    a548:	c4 e2 71 a9 54 87 1c 	vfmadd213ss 0x1c(%rdi,%rax,4),%xmm1,%xmm2
    a54f:	c5 fa 11 54 87 1c    	vmovss %xmm2,0x1c(%rdi,%rax,4)
    a555:	48 83 c0 08          	add    $0x8,%rax
    a559:	48 39 c2             	cmp    %rax,%rdx
    a55c:	0f 85 5e ff ff ff    	jne    a4c0 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x440>
    a562:	e9 c9 fe ff ff       	jmpq   a430 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x3b0>
    a567:	c4 e2 7d 18 d1       	vbroadcastss %xmm1,%ymm2
    a56c:	31 c0                	xor    %eax,%eax
    a56e:	66 90                	xchg   %ax,%ax
    a570:	c5 fc 10 1c 81       	vmovups (%rcx,%rax,4),%ymm3                 // part 2
    a575:	c5 fc 10 64 81 20    	vmovups 0x20(%rcx,%rax,4),%ymm4             // compute (vmovups,vfmadd213ps,vmovups)*4 throughput   
    a57b:	c5 fc 10 6c 81 40    	vmovups 0x40(%rcx,%rax,4),%ymm5             // instr    | latency | recip-throput | throughput          
    a581:	c5 fc 10 74 81 60    	vmovups 0x60(%rcx,%rax,4),%ymm6             // vmovups  | 3       | 0.5           | 2  
    a587:	c4 e2 6d a8 1c 87    	vfmadd213ps (%rdi,%rax,4),%ymm2,%ymm3       // vfma     | 4       | 0.5           | 2  
    a58d:	c4 e2 6d a8 64 87 20 	vfmadd213ps 0x20(%rdi,%rax,4),%ymm2,%ymm4   // ymm, 256 bits <-> 8 floats
    a594:	c4 e2 6d a8 6c 87 40 	vfmadd213ps 0x40(%rdi,%rax,4),%ymm2,%ymm5
    a59b:	c4 e2 6d a8 74 87 60 	vfmadd213ps 0x60(%rdi,%rax,4),%ymm2,%ymm6
    a5a2:	c5 fc 11 1c 87       	vmovups %ymm3,(%rdi,%rax,4)
    a5a7:	c5 fc 11 64 87 20    	vmovups %ymm4,0x20(%rdi,%rax,4)
    a5ad:	c5 fc 11 6c 87 40    	vmovups %ymm5,0x40(%rdi,%rax,4)
    a5b3:	c5 fc 11 74 87 60    	vmovups %ymm6,0x60(%rdi,%rax,4)
    a5b9:	48 83 c0 20          	add    $0x20,%rax
    a5bd:	48 39 c5             	cmp    %rax,%rbp
    a5c0:	75 ae                	jne    a570 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x4f0>
    a5c2:	48 89 e8             	mov    %rbp,%rax
    a5c5:	48 83 7c 24 08 00    	cmpq   $0x0,0x8(%rsp)
    a5cb:	0f 85 a2 fe ff ff    	jne    a473 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x3f3>
    a5d1:	e9 5a fe ff ff       	jmpq   a430 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x3b0>
    a5d6:	48 89 de             	mov    %rbx,%rsi
    a5d9:	49 c1 e8 02          	shr    $0x2,%r8
    a5dd:	45 85 c0             	test   %r8d,%r8d
    a5e0:	0f 8f 3e fd ff ff    	jg     a324 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x2a4>
    a5e6:	eb 10                	jmp    a5f8 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x578>
    a5e8:	48 89 de             	mov    %rbx,%rsi
    a5eb:	49 c1 e8 02          	shr    $0x2,%r8
    a5ef:	45 85 c0             	test   %r8d,%r8d
    a5f2:	0f 8f 2c fd ff ff    	jg     a324 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x2a4>
    a5f8:	48 85 db             	test   %rbx,%rbx
    a5fb:	74 0b                	je     a608 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x588>
    a5fd:	48 89 df             	mov    %rbx,%rdi
    a600:	c5 f8 77             	vzeroupper 
    a603:	e8 48 be ff ff       	callq  6450 <_ZdlPv@plt>
    a608:	48 8b 7c 24 10       	mov    0x10(%rsp),%rdi
    a60d:	48 83 c4 18          	add    $0x18,%rsp
    a611:	48 85 ff             	test   %rdi,%rdi
    a614:	74 12                	je     a628 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x5a8>
    a616:	5b                   	pop    %rbx
    a617:	41 5c                	pop    %r12
    a619:	41 5d                	pop    %r13
    a61b:	41 5e                	pop    %r14
    a61d:	41 5f                	pop    %r15
    a61f:	5d                   	pop    %rbp
    a620:	c5 f8 77             	vzeroupper 
    a623:	e9 28 be ff ff       	jmpq   6450 <_ZdlPv@plt>
    a628:	5b                   	pop    %rbx
    a629:	41 5c                	pop    %r12
    a62b:	41 5d                	pop    %r13
    a62d:	41 5e                	pop    %r14
    a62f:	41 5f                	pop    %r15
    a631:	5d                   	pop    %rbp
    a632:	c5 f8 77             	vzeroupper 
    a635:	c3                   	retq   
    a636:	48 8d 3d b8 aa 04 00 	lea    0x4aab8(%rip),%rdi        # 550f5 <_IO_stdin_used+0xf5>
    a63d:	e8 0e bc ff ff       	callq  6250 <_ZSt20__throw_length_errorPKc@plt>
    a642:	e8 19 bb ff ff       	callq  6160 <_ZS    t17__throw_bad_allocv@plt>
    a647:	48 89 c3             	mov    %rax,%rbx
    a64a:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
    a64f:	48 85 c0             	test   %rax,%rax
    a652:	74 08                	je     a65c <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x5dc>
    a654:	48 89 c7             	mov    %rax,%rdi
    a657:	e8 f4 bd ff ff       	callq  6450 <_ZdlPv@plt>
    a65c:	48 89 df             	mov    %rbx,%rdi
    a65f:	e8 bc c1 ff ff       	callq  6820 <_Unwind_Resume@plt>
    a664:	66 66 66 2e 0f 1f 84 	data16 data16 nopw %cs:0x0(%rax,%rax,1)
    a66b:	00 00 00 00 00 
