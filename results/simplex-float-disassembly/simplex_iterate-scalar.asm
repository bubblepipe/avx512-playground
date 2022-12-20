000000000000a080 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE>:
    a080:	55                   	push   %rbp
    a081:	41 57                	push   %r15
    a083:	41 56                	push   %r14
    a085:	41 55                	push   %r13
    a087:	41 54                	push   %r12
    a089:	53                   	push   %rbx
    a08a:	48 83 ec 28          	sub    $0x28,%rsp
    a08e:	49 89 f8             	mov    %rdi,%r8
    a091:	48 8b 07             	mov    (%rdi),%rax
    a094:	48 8b 4f 08          	mov    0x8(%rdi),%rcx
    a098:	48 29 c1             	sub    %rax,%rcx
    a09b:	48 c1 f9 03          	sar    $0x3,%rcx
    a09f:	49 bd ab aa aa aa aa 	movabs $0xaaaaaaaaaaaaaaab,%r13
    a0a6:	aa aa aa 
    a0a9:	4c 0f af e9          	imul   %rcx,%r13
    a0ad:	48 8b 58 08          	mov    0x8(%rax),%rbx
    a0b1:	48 2b 18             	sub    (%rax),%rbx
    a0b4:	45 8d 65 ff          	lea    -0x1(%r13),%r12d
    a0b8:	4d 63 cc             	movslq %r12d,%r9
    a0bb:	4b 8d 2c 49          	lea    (%r9,%r9,2),%rbp
    a0bf:	48 8b 7c e8 08       	mov    0x8(%rax,%rbp,8),%rdi
    a0c4:	48 2b 3c e8          	sub    (%rax,%rbp,8),%rdi
    a0c8:	74 48                	je     a112 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x92>
    a0ca:	4c 89 4c 24 10       	mov    %r9,0x10(%rsp)
    a0cf:	48 b9 fd ff ff ff ff 	movabs $0x7ffffffffffffffd,%rcx
    a0d6:	ff ff 7f 
    a0d9:	48 39 cf             	cmp    %rcx,%rdi
    a0dc:	0f 83 10 04 00 00    	jae    a4f2 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x472>
    a0e2:	4d 89 c7             	mov    %r8,%r15
    a0e5:	4c 8d 34 e8          	lea    (%rax,%rbp,8),%r14
    a0e9:	e8 a2 c3 ff ff       	callq  6490 <_Znwm@plt>
    a0ee:	49 8b 36             	mov    (%r14),%rsi
    a0f1:	49 8b 56 08          	mov    0x8(%r14),%rdx
    a0f5:	48 29 f2             	sub    %rsi,%rdx
    a0f8:	74 0e                	je     a108 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x88>
    a0fa:	49 89 c6             	mov    %rax,%r14
    a0fd:	48 89 c7             	mov    %rax,%rdi
    a100:	e8 6b c6 ff ff       	callq  6770 <memmove@plt>
    a105:	4c 89 f0             	mov    %r14,%rax
    a108:	4d 89 f8             	mov    %r15,%r8
    a10b:	4c 8b 4c 24 10       	mov    0x10(%rsp),%r9
    a110:	eb 02                	jmp    a114 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x94>
    a112:	31 c0                	xor    %eax,%eax
    a114:	49 8b 08             	mov    (%r8),%rcx
    a117:	48 8b 34 e9          	mov    (%rcx,%rbp,8),%rsi
    a11b:	48 8b 4c e9 08       	mov    0x8(%rcx,%rbp,8),%rcx
    a120:	49 89 f6             	mov    %rsi,%r14
    a123:	48 39 ce             	cmp    %rcx,%rsi
    a126:	d9 ee                	fldz   
    a128:	74 3d                	je     a167 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0xe7>
    a12a:	dd d8                	fstp   %st(0)
    a12c:	48 8d 56 04          	lea    0x4(%rsi),%rdx
    a130:	49 89 f6             	mov    %rsi,%r14
    a133:	48 39 ca             	cmp    %rcx,%rdx
    a136:	d9 ee                	fldz   
    a138:	74 2d                	je     a167 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0xe7>
    a13a:	dd d8                	fstp   %st(0)
    a13c:	d9 06                	flds   (%rsi)
    a13e:	49 89 f6             	mov    %rsi,%r14
    a141:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
    a148:	0f 1f 84 00 00 00 00 
    a14f:	00 
    a150:	d9 02                	flds   (%rdx)
    a152:	d9 c9                	fxch   %st(1)
    a154:	db e9                	fucomi %st(1),%st
    a156:	db d1                	fcmovnbe %st(1),%st
    a158:	dd d9                	fstp   %st(1)
    a15a:	4c 0f 47 f2          	cmova  %rdx,%r14
    a15e:	48 83 c2 04          	add    $0x4,%rdx
    a162:	48 39 ca             	cmp    %rcx,%rdx
    a165:	75 e9                	jne    a150 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0xd0>
    a167:	dd d8                	fstp   %st(0)
    a169:	45 85 ed             	test   %r13d,%r13d
    a16c:	0f 8e 6f 03 00 00    	jle    a4e1 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x461>
    a172:	4c 89 6c 24 18       	mov    %r13,0x18(%rsp)
    a177:	49 29 f6             	sub    %rsi,%r14
    a17a:	45 85 e4             	test   %r12d,%r12d
    a17d:	0f 84 78 01 00 00    	je     a2fb <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x27b>
    a183:	4c 89 44 24 20       	mov    %r8,0x20(%rsp)
    a188:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    a18d:	49 c1 e1 02          	shl    $0x2,%r9
    a191:	4c 89 cf             	mov    %r9,%rdi
    a194:	4c 89 cd             	mov    %r9,%rbp
    a197:	e8 f4 c2 ff ff       	callq  6490 <_Znwm@plt>
    a19c:	49 89 c5             	mov    %rax,%r13
    a19f:	45 31 ff             	xor    %r15d,%r15d
    a1a2:	48 89 c7             	mov    %rax,%rdi
    a1a5:	31 f6                	xor    %esi,%esi
    a1a7:	48 89 6c 24 10       	mov    %rbp,0x10(%rsp)
    a1ac:	48 89 ea             	mov    %rbp,%rdx
    a1af:	e8 bc c0 ff ff       	callq  6270 <memset@plt>
    a1b4:	4c 8b 44 24 20       	mov    0x20(%rsp),%r8
    a1b9:	49 8b 10             	mov    (%r8),%rdx
    a1bc:	48 89 d9             	mov    %rbx,%rcx
    a1bf:	48 c1 e1 1e          	shl    $0x1e,%rcx
    a1c3:	48 b8 00 00 00 00 ff 	movabs $0xffffffff00000000,%rax
    a1ca:	ff ff ff 
    a1cd:	48 01 c8             	add    %rcx,%rax
    a1d0:	48 c1 f8 20          	sar    $0x20,%rax
    a1d4:	4c 89 f1             	mov    %r14,%rcx
    a1d7:	48 c1 e9 02          	shr    $0x2,%rcx
    a1db:	48 63 c9             	movslq %ecx,%rcx
    a1de:	44 89 e6             	mov    %r12d,%esi
    a1e1:	48 8d 7e ff          	lea    -0x1(%rsi),%rdi
    a1e5:	41 83 e4 03          	and    $0x3,%r12d
    a1e9:	48 83 ff 03          	cmp    $0x3,%rdi
    a1ed:	72 61                	jb     a250 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x1d0>
    a1ef:	83 e6 fc             	and    $0xfffffffc,%esi
    a1f2:	45 31 ff             	xor    %r15d,%r15d
    a1f5:	48 89 d7             	mov    %rdx,%rdi
    a1f8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    a1ff:	00 
    a200:	48 8b 2f             	mov    (%rdi),%rbp
    a203:	d9 44 85 00          	flds   0x0(%rbp,%rax,4)
    a207:	d8 74 8d 00          	fdivs  0x0(%rbp,%rcx,4)
    a20b:	43 d9 5c bd 00       	fstps  0x0(%r13,%r15,4)
    a210:	48 8b 6f 18          	mov    0x18(%rdi),%rbp
    a214:	d9 44 85 00          	flds   0x0(%rbp,%rax,4)
    a218:	d8 74 8d 00          	fdivs  0x0(%rbp,%rcx,4)
    a21c:	43 d9 5c bd 04       	fstps  0x4(%r13,%r15,4)
    a221:	48 8b 6f 30          	mov    0x30(%rdi),%rbp
    a225:	d9 44 85 00          	flds   0x0(%rbp,%rax,4)
    a229:	d8 74 8d 00          	fdivs  0x0(%rbp,%rcx,4)
    a22d:	43 d9 5c bd 08       	fstps  0x8(%r13,%r15,4)
    a232:	48 8b 6f 48          	mov    0x48(%rdi),%rbp
    a236:	d9 44 85 00          	flds   0x0(%rbp,%rax,4)
    a23a:	d8 74 8d 00          	fdivs  0x0(%rbp,%rcx,4)
    a23e:	43 d9 5c bd 0c       	fstps  0xc(%r13,%r15,4)
    a243:	49 83 c7 04          	add    $0x4,%r15
    a247:	48 83 c7 60          	add    $0x60,%rdi
    a24b:	4c 39 fe             	cmp    %r15,%rsi
    a24e:	75 b0                	jne    a200 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x180>
    a250:	4c 8b 4c 24 10       	mov    0x10(%rsp),%r9
    a255:	4d 01 e9             	add    %r13,%r9
    a258:	4d 85 e4             	test   %r12,%r12
    a25b:	74 3d                	je     a29a <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x21a>
    a25d:	4a 8d 34 bd 00 00 00 	lea    0x0(,%r15,4),%rsi
    a264:	00 
    a265:	4c 01 ee             	add    %r13,%rsi
    a268:	4b 8d 3c 7f          	lea    (%r15,%r15,2),%rdi
    a26c:	48 8d 14 fa          	lea    (%rdx,%rdi,8),%rdx
    a270:	31 ff                	xor    %edi,%edi
    a272:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
    a279:	1f 84 00 00 00 00 00 
    a280:	48 8b 2a             	mov    (%rdx),%rbp
    a283:	d9 44 85 00          	flds   0x0(%rbp,%rax,4)
    a287:	d8 74 8d 00          	fdivs  0x0(%rbp,%rcx,4)
    a28b:	d9 1c be             	fstps  (%rsi,%rdi,4)
    a28e:	48 ff c7             	inc    %rdi
    a291:	48 83 c2 18          	add    $0x18,%rdx
    a295:	49 39 fc             	cmp    %rdi,%r12
    a298:	75 e6                	jne    a280 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x200>
    a29a:	4d 39 cd             	cmp    %r9,%r13
    a29d:	74 6b                	je     a30a <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x28a>
    a29f:	49 8d 45 04          	lea    0x4(%r13),%rax
    a2a3:	4c 39 c8             	cmp    %r9,%rax
    a2a6:	4c 8b 7c 24 08       	mov    0x8(%rsp),%r15
    a2ab:	74 58                	je     a305 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x285>
    a2ad:	41 d9 45 00          	flds   0x0(%r13)
    a2b1:	48 63 4c 24 18       	movslq 0x18(%rsp),%rcx
    a2b6:	48 c1 e1 02          	shl    $0x2,%rcx
    a2ba:	b8 08 00 00 00       	mov    $0x8,%eax
    a2bf:	48 29 c8             	sub    %rcx,%rax
    a2c2:	b9 04 00 00 00       	mov    $0x4,%ecx
    a2c7:	4c 89 ef             	mov    %r13,%rdi
    a2ca:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    a2d0:	4a 8d 14 29          	lea    (%rcx,%r13,1),%rdx
    a2d4:	41 d9 44 0d 00       	flds   0x0(%r13,%rcx,1)
    a2d9:	d9 c9                	fxch   %st(1)
    a2db:	db e9                	fucomi %st(1),%st
    a2dd:	db d1                	fcmovnbe %st(1),%st
    a2df:	dd d9                	fstp   %st(1)
    a2e1:	48 0f 47 fa          	cmova  %rdx,%rdi
    a2e5:	48 8d 14 08          	lea    (%rax,%rcx,1),%rdx
    a2e9:	48 83 c2 04          	add    $0x4,%rdx
    a2ed:	48 83 c1 04          	add    $0x4,%rcx
    a2f1:	48 83 fa 04          	cmp    $0x4,%rdx
    a2f5:	75 d9                	jne    a2d0 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x250>
    a2f7:	dd d8                	fstp   %st(0)
    a2f9:	eb 17                	jmp    a312 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x292>
    a2fb:	49 89 c7             	mov    %rax,%r15
    a2fe:	45 31 ed             	xor    %r13d,%r13d
    a301:	31 ff                	xor    %edi,%edi
    a303:	eb 0d                	jmp    a312 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x292>
    a305:	4c 89 ef             	mov    %r13,%rdi
    a308:	eb 08                	jmp    a312 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x292>
    a30a:	4c 89 ef             	mov    %r13,%rdi
    a30d:	4c 8b 7c 24 08       	mov    0x8(%rsp),%r15
    a312:	48 c1 eb 02          	shr    $0x2,%rbx
    a316:	4c 29 ef             	sub    %r13,%rdi
    a319:	48 c1 ef 02          	shr    $0x2,%rdi
    a31d:	48 63 c7             	movslq %edi,%rax
    a320:	4d 8b 08             	mov    (%r8),%r9
    a323:	48 8d 04 40          	lea    (%rax,%rax,2),%rax
    a327:	4c 89 f2             	mov    %r14,%rdx
    a32a:	48 c1 e2 1e          	shl    $0x1e,%rdx
    a32e:	49 8b 0c c1          	mov    (%r9,%rax,8),%rcx
    a332:	48 c1 fa 1e          	sar    $0x1e,%rdx
    a336:	d9 04 11             	flds   (%rcx,%rdx,1)
    a339:	85 db                	test   %ebx,%ebx
    a33b:	0f 8e 67 01 00 00    	jle    a4a8 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x428>
    a341:	89 da                	mov    %ebx,%edx
    a343:	4c 8d 42 ff          	lea    -0x1(%rdx),%r8
    a347:	89 d8                	mov    %ebx,%eax
    a349:	83 e0 03             	and    $0x3,%eax
    a34c:	49 83 f8 03          	cmp    $0x3,%r8
    a350:	73 04                	jae    a356 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x2d6>
    a352:	31 f6                	xor    %esi,%esi
    a354:	eb 39                	jmp    a38f <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x30f>
    a356:	48 89 d5             	mov    %rdx,%rbp
    a359:	48 29 c5             	sub    %rax,%rbp
    a35c:	31 f6                	xor    %esi,%esi
    a35e:	66 90                	xchg   %ax,%ax
    a360:	d9 c0                	fld    %st(0)
    a362:	d8 3c b1             	fdivrs (%rcx,%rsi,4)
    a365:	d9 1c b1             	fstps  (%rcx,%rsi,4)
    a368:	d9 c0                	fld    %st(0)
    a36a:	d8 7c b1 04          	fdivrs 0x4(%rcx,%rsi,4)
    a36e:	d9 5c b1 04          	fstps  0x4(%rcx,%rsi,4)
    a372:	d9 c0                	fld    %st(0)
    a374:	d8 7c b1 08          	fdivrs 0x8(%rcx,%rsi,4)
    a378:	d9 5c b1 08          	fstps  0x8(%rcx,%rsi,4)
    a37c:	d9 c0                	fld    %st(0)
    a37e:	d8 7c b1 0c          	fdivrs 0xc(%rcx,%rsi,4)
    a382:	d9 5c b1 0c          	fstps  0xc(%rcx,%rsi,4)
    a386:	48 83 c6 04          	add    $0x4,%rsi
    a38a:	48 39 f5             	cmp    %rsi,%rbp
    a38d:	75 d1                	jne    a360 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x2e0>
    a38f:	48 85 c0             	test   %rax,%rax
    a392:	74 1c                	je     a3b0 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x330>
    a394:	48 8d 34 b1          	lea    (%rcx,%rsi,4),%rsi
    a398:	31 ed                	xor    %ebp,%ebp
    a39a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    a3a0:	d9 c0                	fld    %st(0)
    a3a2:	d8 3c ae             	fdivrs (%rsi,%rbp,4)
    a3a5:	d9 1c ae             	fstps  (%rsi,%rbp,4)
    a3a8:	48 ff c5             	inc    %rbp
    a3ab:	48 39 e8             	cmp    %rbp,%rax
    a3ae:	75 f0                	jne    a3a0 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x320>
    a3b0:	dd d8                	fstp   %st(0)
    a3b2:	85 db                	test   %ebx,%ebx
    a3b4:	d9 ee                	fldz   
    a3b6:	0f 8e ec 00 00 00    	jle    a4a8 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x428>
    a3bc:	dd d8                	fstp   %st(0)
    a3be:	83 7c 24 18 00       	cmpl   $0x0,0x18(%rsp)
    a3c3:	d9 ee                	fldz   
    a3c5:	0f 8e dd 00 00 00    	jle    a4a8 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x428>
    a3cb:	dd d8                	fstp   %st(0)
    a3cd:	49 c1 ee 02          	shr    $0x2,%r14
    a3d1:	4d 63 d6             	movslq %r14d,%r10
    a3d4:	41 89 fb             	mov    %edi,%r11d
    a3d7:	44 8b 74 24 18       	mov    0x18(%rsp),%r14d
    a3dc:	83 e3 03             	and    $0x3,%ebx
    a3df:	48 29 da             	sub    %rbx,%rdx
    a3e2:	31 c0                	xor    %eax,%eax
    a3e4:	d9 ee                	fldz   
    a3e6:	eb 18                	jmp    a400 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x380>
    a3e8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    a3ef:	00 
    a3f0:	dd d8                	fstp   %st(0)
    a3f2:	48 ff c0             	inc    %rax
    a3f5:	4c 39 f0             	cmp    %r14,%rax
    a3f8:	d9 ee                	fldz   
    a3fa:	0f 84 a8 00 00 00    	je     a4a8 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x428>
    a400:	dd d8                	fstp   %st(0)
    a402:	4c 39 d8             	cmp    %r11,%rax
    a405:	d9 ee                	fldz   
    a407:	74 e7                	je     a3f0 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x370>
    a409:	dd d8                	fstp   %st(0)
    a40b:	48 8d 34 40          	lea    (%rax,%rax,2),%rsi
    a40f:	49 8b 2c f1          	mov    (%r9,%rsi,8),%rbp
    a413:	42 d9 44 95 00       	flds   0x0(%rbp,%r10,4)
    a418:	d9 e0                	fchs   
    a41a:	31 ff                	xor    %edi,%edi
    a41c:	49 83 f8 03          	cmp    $0x3,%r8
    a420:	72 4e                	jb     a470 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x3f0>
    a422:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
    a429:	1f 84 00 00 00 00 00 
    a430:	d9 c0                	fld    %st(0)                               // part 2
    a432:	d8 0c b9             	fmuls  (%rcx,%rdi,4)                        // compute (fld,fmul,fadd,fstp)*4 throughput   
    a435:	d8 44 bd 00          	fadds  0x0(%rbp,%rdi,4)                     // instr    | latency | recip-throput | throughput      
    a439:	d9 5c bd 00          	fstps  0x0(%rbp,%rdi,4)                     // fld      | 1       | 0.5           | 2      
    a43d:	d9 c0                	fld    %st(0)                               // fmul     | 5       | 1             | 1          
    a43f:	d8 4c b9 04          	fmuls  0x4(%rcx,%rdi,4)                     // fadd     | 3       | 1             | 1          
    a443:	d8 44 bd 04          	fadds  0x4(%rbp,%rdi,4)                     // fstp     | 4       | 5             | 1/5          
    a447:	d9 5c bd 04          	fstps  0x4(%rbp,%rdi,4)                     
    a44b:	d9 c0                	fld    %st(0)
    a44d:	d8 4c b9 08          	fmuls  0x8(%rcx,%rdi,4)
    a451:	d8 44 bd 08          	fadds  0x8(%rbp,%rdi,4)
    a455:	d9 5c bd 08          	fstps  0x8(%rbp,%rdi,4)
    a459:	d9 c0                	fld    %st(0)
    a45b:	d8 4c b9 0c          	fmuls  0xc(%rcx,%rdi,4)
    a45f:	d8 44 bd 0c          	fadds  0xc(%rbp,%rdi,4)
    a463:	d9 5c bd 0c          	fstps  0xc(%rbp,%rdi,4)
    a467:	48 83 c7 04          	add    $0x4,%rdi
    a46b:	48 39 fa             	cmp    %rdi,%rdx
    a46e:	75 c0                	jne    a430 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x3b0>
    a470:	48 85 db             	test   %rbx,%rbx
    a473:	0f 84 77 ff ff ff    	je     a3f0 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x370>
    a479:	48 8d 34 b9          	lea    (%rcx,%rdi,4),%rsi
    a47d:	48 8d 3c bd 00 00 00 	lea    0x0(,%rdi,4),%rdi
    a484:	00 
    a485:	48 01 ef             	add    %rbp,%rdi
    a488:	31 ed                	xor    %ebp,%ebp
    a48a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    a490:	d9 c0                	fld    %st(0)
    a492:	d8 0c ae             	fmuls  (%rsi,%rbp,4)
    a495:	d8 04 af             	fadds  (%rdi,%rbp,4)
    a498:	d9 1c af             	fstps  (%rdi,%rbp,4)
    a49b:	48 ff c5             	inc    %rbp
    a49e:	48 39 eb             	cmp    %rbp,%rbx
    a4a1:	75 ed                	jne    a490 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x410>
    a4a3:	e9 48 ff ff ff       	jmpq   a3f0 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x370>
    a4a8:	dd d8                	fstp   %st(0)
    a4aa:	4d 85 ed             	test   %r13,%r13
    a4ad:	74 08                	je     a4b7 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x437>
    a4af:	4c 89 ef             	mov    %r13,%rdi
    a4b2:	e8 99 bf ff ff       	callq  6450 <_ZdlPv@plt>
    a4b7:	4d 85 ff             	test   %r15,%r15
    a4ba:	74 16                	je     a4d2 <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x452>
    a4bc:	4c 89 ff             	mov    %r15,%rdi
    a4bf:	48 83 c4 28          	add    $0x28,%rsp
    a4c3:	5b                   	pop    %rbx
    a4c4:	41 5c                	pop    %r12
    a4c6:	41 5d                	pop    %r13
    a4c8:	41 5e                	pop    %r14
    a4ca:	41 5f                	pop    %r15
    a4cc:	5d                   	pop    %rbp
    a4cd:	e9 7e bf ff ff       	jmpq   6450 <_ZdlPv@plt>
    a4d2:	48 83 c4 28          	add    $0x28,%rsp
    a4d6:	5b                   	pop    %rbx
    a4d7:	41 5c                	pop    %r12
    a4d9:	41 5d                	pop    %r13
    a4db:	41 5e                	pop    %r14
    a4dd:	41 5f                	pop    %r15
    a4df:	5d                   	pop    %rbp
    a4e0:	c3                   	retq   
    a4e1:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    a4e6:	48 8d 3d ac ab 04 00 	lea    0x4abac(%rip),%rdi        # 55099 <_IO_stdin_used+0x99>
    a4ed:	e8 5e bd ff ff       	callq  6250 <_ZSt20__throw_length_errorPKc@plt>
    a4f2:	e8 69 bc ff ff       	callq  6160 <_ZSt17__throw_bad_allocv@plt>
    a4f7:	48 89 c3             	mov    %rax,%rbx
    a4fa:	48 83 7c 24 08 00    	cmpq   $0x0,0x8(%rsp)
    a500:	74 0a                	je     a50c <_Z15simplex_iterateRSt6vectorIS_IfSaIfEESaIS1_EE+0x48c>
    a502:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
    a507:	e8 44 bf ff ff       	callq  6450 <_ZdlPv@plt>
    a50c:	48 89 df             	mov    %rbx,%rdi
    a50f:	e8 0c c3 ff ff       	callq  6820 <_Unwind_Resume@plt>
    a514:	66 66 66 2e 0f 1f 84 	data16 data16 nopw %cs:0x0(%rax,%rax,1)
    a51b:	00 00 00 00 00 
