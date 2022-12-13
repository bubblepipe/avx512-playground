00000000000011d0 <_Z14vec_add_莎莎jPfS_S_>:
    11d0:	41 56                	push   %r14
    11d2:	53                   	push   %rbx
    11d3:	85 ff                	test   %edi,%edi
    11d5:	0f 84 6f 05 00 00    	je     174a <_Z14vec_add_莎莎jPfS_S_+0x57a>
    11db:	41 89 f9             	mov    %edi,%r9d
    11de:	83 ff 20             	cmp    $0x20,%edi
    11e1:	73 07                	jae    11ea <_Z14vec_add_莎莎jPfS_S_+0x1a>
    11e3:	31 ff                	xor    %edi,%edi
    11e5:	e9 75 04 00 00       	jmp    165f <_Z14vec_add_莎莎jPfS_S_+0x48f>
    11ea:	48 89 c8             	mov    %rcx,%rax
    11ed:	48 29 f0             	sub    %rsi,%rax
    11f0:	31 ff                	xor    %edi,%edi
    11f2:	48 3d 80 00 00 00    	cmp    $0x80,%rax
    11f8:	0f 82 61 04 00 00    	jb     165f <_Z14vec_add_莎莎jPfS_S_+0x48f>
    11fe:	48 89 c8             	mov    %rcx,%rax
    1201:	48 29 d0             	sub    %rdx,%rax
    1204:	48 3d 80 00 00 00    	cmp    $0x80,%rax
    120a:	0f 82 4f 04 00 00    	jb     165f <_Z14vec_add_莎莎jPfS_S_+0x48f>
    1210:	44 89 cf             	mov    %r9d,%edi
    1213:	83 e7 e0             	and    $0xffffffe0,%edi
    1216:	48 8d 47 e0          	lea    -0x20(%rdi),%rax
    121a:	49 89 c2             	mov    %rax,%r10
    121d:	49 c1 ea 05          	shr    $0x5,%r10
    1221:	49 ff c2             	inc    %r10
    1224:	45 89 d0             	mov    %r10d,%r8d
    1227:	41 83 e0 07          	and    $0x7,%r8d
    122b:	48 3d e0 00 00 00    	cmp    $0xe0,%rax
    1231:	73 07                	jae    123a <_Z14vec_add_莎莎jPfS_S_+0x6a>
    1233:	31 c0                	xor    %eax,%eax
    1235:	e9 a6 03 00 00       	jmp    15e0 <_Z14vec_add_莎莎jPfS_S_+0x410>
    123a:	49 83 e2 f8          	and    $0xfffffffffffffff8,%r10
    123e:	4c 8d 9e e0 03 00 00 	lea    0x3e0(%rsi),%r11
    1245:	4c 8d b2 e0 03 00 00 	lea    0x3e0(%rdx),%r14
    124c:	48 8d 99 e0 03 00 00 	lea    0x3e0(%rcx),%rbx
    1253:	31 c0                	xor    %eax,%eax
    1255:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
    125c:	00 00 00 00 
    1260:	c4 c1 7c 10 84 83 20 	vmovups -0x3e0(%r11,%rax,4),%ymm0
    1267:	fc ff ff 
    126a:	c4 c1 7c 10 8c 83 40 	vmovups -0x3c0(%r11,%rax,4),%ymm1
    1271:	fc ff ff 
    1274:	c4 c1 7c 10 94 83 60 	vmovups -0x3a0(%r11,%rax,4),%ymm2
    127b:	fc ff ff 
    127e:	c4 c1 7c 10 9c 83 80 	vmovups -0x380(%r11,%rax,4),%ymm3
    1285:	fc ff ff 
    1288:	c4 c1 7c 58 84 86 20 	vaddps -0x3e0(%r14,%rax,4),%ymm0,%ymm0
    128f:	fc ff ff 
    1292:	c4 c1 74 58 8c 86 40 	vaddps -0x3c0(%r14,%rax,4),%ymm1,%ymm1
    1299:	fc ff ff 
    129c:	c4 c1 6c 58 94 86 60 	vaddps -0x3a0(%r14,%rax,4),%ymm2,%ymm2
    12a3:	fc ff ff 
    12a6:	c4 c1 64 58 9c 86 80 	vaddps -0x380(%r14,%rax,4),%ymm3,%ymm3
    12ad:	fc ff ff 
    12b0:	c5 fc 11 84 83 20 fc 	vmovups %ymm0,-0x3e0(%rbx,%rax,4)
    12b7:	ff ff 
    12b9:	c5 fc 11 8c 83 40 fc 	vmovups %ymm1,-0x3c0(%rbx,%rax,4)
    12c0:	ff ff 
    12c2:	c5 fc 11 94 83 60 fc 	vmovups %ymm2,-0x3a0(%rbx,%rax,4)
    12c9:	ff ff 
    12cb:	c5 fc 11 9c 83 80 fc 	vmovups %ymm3,-0x380(%rbx,%rax,4)
    12d2:	ff ff 
    12d4:	c4 c1 7c 10 84 83 a0 	vmovups -0x360(%r11,%rax,4),%ymm0
    12db:	fc ff ff 
    12de:	c4 c1 7c 10 8c 83 c0 	vmovups -0x340(%r11,%rax,4),%ymm1
    12e5:	fc ff ff 
    12e8:	c4 c1 7c 10 94 83 e0 	vmovups -0x320(%r11,%rax,4),%ymm2
    12ef:	fc ff ff 
    12f2:	c4 c1 7c 10 9c 83 00 	vmovups -0x300(%r11,%rax,4),%ymm3
    12f9:	fd ff ff 
    12fc:	c4 c1 7c 58 84 86 a0 	vaddps -0x360(%r14,%rax,4),%ymm0,%ymm0
    1303:	fc ff ff 
    1306:	c4 c1 74 58 8c 86 c0 	vaddps -0x340(%r14,%rax,4),%ymm1,%ymm1
    130d:	fc ff ff 
    1310:	c4 c1 6c 58 94 86 e0 	vaddps -0x320(%r14,%rax,4),%ymm2,%ymm2
    1317:	fc ff ff 
    131a:	c4 c1 64 58 9c 86 00 	vaddps -0x300(%r14,%rax,4),%ymm3,%ymm3
    1321:	fd ff ff 
    1324:	c5 fc 11 84 83 a0 fc 	vmovups %ymm0,-0x360(%rbx,%rax,4)
    132b:	ff ff 
    132d:	c5 fc 11 8c 83 c0 fc 	vmovups %ymm1,-0x340(%rbx,%rax,4)
    1334:	ff ff 
    1336:	c5 fc 11 94 83 e0 fc 	vmovups %ymm2,-0x320(%rbx,%rax,4)
    133d:	ff ff 
    133f:	c5 fc 11 9c 83 00 fd 	vmovups %ymm3,-0x300(%rbx,%rax,4)
    1346:	ff ff 
    1348:	c4 c1 7c 10 84 83 20 	vmovups -0x2e0(%r11,%rax,4),%ymm0
    134f:	fd ff ff 
    1352:	c4 c1 7c 10 8c 83 40 	vmovups -0x2c0(%r11,%rax,4),%ymm1
    1359:	fd ff ff 
    135c:	c4 c1 7c 10 94 83 60 	vmovups -0x2a0(%r11,%rax,4),%ymm2
    1363:	fd ff ff 
    1366:	c4 c1 7c 10 9c 83 80 	vmovups -0x280(%r11,%rax,4),%ymm3
    136d:	fd ff ff 
    1370:	c4 c1 7c 58 84 86 20 	vaddps -0x2e0(%r14,%rax,4),%ymm0,%ymm0
    1377:	fd ff ff 
    137a:	c4 c1 74 58 8c 86 40 	vaddps -0x2c0(%r14,%rax,4),%ymm1,%ymm1
    1381:	fd ff ff 
    1384:	c4 c1 6c 58 94 86 60 	vaddps -0x2a0(%r14,%rax,4),%ymm2,%ymm2
    138b:	fd ff ff 
    138e:	c4 c1 64 58 9c 86 80 	vaddps -0x280(%r14,%rax,4),%ymm3,%ymm3
    1395:	fd ff ff 
    1398:	c5 fc 11 84 83 20 fd 	vmovups %ymm0,-0x2e0(%rbx,%rax,4)
    139f:	ff ff 
    13a1:	c5 fc 11 8c 83 40 fd 	vmovups %ymm1,-0x2c0(%rbx,%rax,4)
    13a8:	ff ff 
    13aa:	c5 fc 11 94 83 60 fd 	vmovups %ymm2,-0x2a0(%rbx,%rax,4)
    13b1:	ff ff 
    13b3:	c5 fc 11 9c 83 80 fd 	vmovups %ymm3,-0x280(%rbx,%rax,4)
    13ba:	ff ff 
    13bc:	c4 c1 7c 10 84 83 a0 	vmovups -0x260(%r11,%rax,4),%ymm0
    13c3:	fd ff ff 
    13c6:	c4 c1 7c 10 8c 83 c0 	vmovups -0x240(%r11,%rax,4),%ymm1
    13cd:	fd ff ff 
    13d0:	c4 c1 7c 10 94 83 e0 	vmovups -0x220(%r11,%rax,4),%ymm2
    13d7:	fd ff ff 
    13da:	c4 c1 7c 10 9c 83 00 	vmovups -0x200(%r11,%rax,4),%ymm3
    13e1:	fe ff ff 
    13e4:	c4 c1 7c 58 84 86 a0 	vaddps -0x260(%r14,%rax,4),%ymm0,%ymm0
    13eb:	fd ff ff 
    13ee:	c4 c1 74 58 8c 86 c0 	vaddps -0x240(%r14,%rax,4),%ymm1,%ymm1
    13f5:	fd ff ff 
    13f8:	c4 c1 6c 58 94 86 e0 	vaddps -0x220(%r14,%rax,4),%ymm2,%ymm2
    13ff:	fd ff ff 
    1402:	c4 c1 64 58 9c 86 00 	vaddps -0x200(%r14,%rax,4),%ymm3,%ymm3
    1409:	fe ff ff 
    140c:	c5 fc 11 84 83 a0 fd 	vmovups %ymm0,-0x260(%rbx,%rax,4)
    1413:	ff ff 
    1415:	c5 fc 11 8c 83 c0 fd 	vmovups %ymm1,-0x240(%rbx,%rax,4)
    141c:	ff ff 
    141e:	c5 fc 11 94 83 e0 fd 	vmovups %ymm2,-0x220(%rbx,%rax,4)
    1425:	ff ff 
    1427:	c5 fc 11 9c 83 00 fe 	vmovups %ymm3,-0x200(%rbx,%rax,4)
    142e:	ff ff 
    1430:	c4 c1 7c 10 84 83 20 	vmovups -0x1e0(%r11,%rax,4),%ymm0
    1437:	fe ff ff 
    143a:	c4 c1 7c 10 8c 83 40 	vmovups -0x1c0(%r11,%rax,4),%ymm1
    1441:	fe ff ff 
    1444:	c4 c1 7c 10 94 83 60 	vmovups -0x1a0(%r11,%rax,4),%ymm2
    144b:	fe ff ff 
    144e:	c4 c1 7c 10 9c 83 80 	vmovups -0x180(%r11,%rax,4),%ymm3
    1455:	fe ff ff 
    1458:	c4 c1 7c 58 84 86 20 	vaddps -0x1e0(%r14,%rax,4),%ymm0,%ymm0
    145f:	fe ff ff 
    1462:	c4 c1 74 58 8c 86 40 	vaddps -0x1c0(%r14,%rax,4),%ymm1,%ymm1
    1469:	fe ff ff 
    146c:	c4 c1 6c 58 94 86 60 	vaddps -0x1a0(%r14,%rax,4),%ymm2,%ymm2
    1473:	fe ff ff 
    1476:	c4 c1 64 58 9c 86 80 	vaddps -0x180(%r14,%rax,4),%ymm3,%ymm3
    147d:	fe ff ff 
    1480:	c5 fc 11 84 83 20 fe 	vmovups %ymm0,-0x1e0(%rbx,%rax,4)
    1487:	ff ff 
    1489:	c5 fc 11 8c 83 40 fe 	vmovups %ymm1,-0x1c0(%rbx,%rax,4)
    1490:	ff ff 
    1492:	c5 fc 11 94 83 60 fe 	vmovups %ymm2,-0x1a0(%rbx,%rax,4)
    1499:	ff ff 
    149b:	c5 fc 11 9c 83 80 fe 	vmovups %ymm3,-0x180(%rbx,%rax,4)
    14a2:	ff ff 
    14a4:	c4 c1 7c 10 84 83 a0 	vmovups -0x160(%r11,%rax,4),%ymm0
    14ab:	fe ff ff 
    14ae:	c4 c1 7c 10 8c 83 c0 	vmovups -0x140(%r11,%rax,4),%ymm1
    14b5:	fe ff ff 
    14b8:	c4 c1 7c 10 94 83 e0 	vmovups -0x120(%r11,%rax,4),%ymm2
    14bf:	fe ff ff 
    14c2:	c4 c1 7c 10 9c 83 00 	vmovups -0x100(%r11,%rax,4),%ymm3
    14c9:	ff ff ff 
    14cc:	c4 c1 7c 58 84 86 a0 	vaddps -0x160(%r14,%rax,4),%ymm0,%ymm0
    14d3:	fe ff ff 
    14d6:	c4 c1 74 58 8c 86 c0 	vaddps -0x140(%r14,%rax,4),%ymm1,%ymm1
    14dd:	fe ff ff 
    14e0:	c4 c1 6c 58 94 86 e0 	vaddps -0x120(%r14,%rax,4),%ymm2,%ymm2
    14e7:	fe ff ff 
    14ea:	c4 c1 64 58 9c 86 00 	vaddps -0x100(%r14,%rax,4),%ymm3,%ymm3
    14f1:	ff ff ff 
    14f4:	c5 fc 11 84 83 a0 fe 	vmovups %ymm0,-0x160(%rbx,%rax,4)
    14fb:	ff ff 
    14fd:	c5 fc 11 8c 83 c0 fe 	vmovups %ymm1,-0x140(%rbx,%rax,4)
    1504:	ff ff 
    1506:	c5 fc 11 94 83 e0 fe 	vmovups %ymm2,-0x120(%rbx,%rax,4)
    150d:	ff ff 
    150f:	c5 fc 11 9c 83 00 ff 	vmovups %ymm3,-0x100(%rbx,%rax,4)
    1516:	ff ff 
    1518:	c4 c1 7c 10 84 83 20 	vmovups -0xe0(%r11,%rax,4),%ymm0
    151f:	ff ff ff 
    1522:	c4 c1 7c 10 8c 83 40 	vmovups -0xc0(%r11,%rax,4),%ymm1
    1529:	ff ff ff 
    152c:	c4 c1 7c 10 94 83 60 	vmovups -0xa0(%r11,%rax,4),%ymm2
    1533:	ff ff ff 
    1536:	c4 c1 7c 10 5c 83 80 	vmovups -0x80(%r11,%rax,4),%ymm3
    153d:	c4 c1 7c 58 84 86 20 	vaddps -0xe0(%r14,%rax,4),%ymm0,%ymm0
    1544:	ff ff ff 
    1547:	c4 c1 74 58 8c 86 40 	vaddps -0xc0(%r14,%rax,4),%ymm1,%ymm1
    154e:	ff ff ff 
    1551:	c4 c1 6c 58 94 86 60 	vaddps -0xa0(%r14,%rax,4),%ymm2,%ymm2
    1558:	ff ff ff 
    155b:	c4 c1 64 58 5c 86 80 	vaddps -0x80(%r14,%rax,4),%ymm3,%ymm3
    1562:	c5 fc 11 84 83 20 ff 	vmovups %ymm0,-0xe0(%rbx,%rax,4)
    1569:	ff ff 
    156b:	c5 fc 11 8c 83 40 ff 	vmovups %ymm1,-0xc0(%rbx,%rax,4)
    1572:	ff ff 
    1574:	c5 fc 11 94 83 60 ff 	vmovups %ymm2,-0xa0(%rbx,%rax,4)
    157b:	ff ff 
    157d:	c5 fc 11 5c 83 80    	vmovups %ymm3,-0x80(%rbx,%rax,4)
    1583:	c4 c1 7c 10 44 83 a0 	vmovups -0x60(%r11,%rax,4),%ymm0
    158a:	c4 c1 7c 10 4c 83 c0 	vmovups -0x40(%r11,%rax,4),%ymm1
    1591:	c4 c1 7c 10 54 83 e0 	vmovups -0x20(%r11,%rax,4),%ymm2
    1598:	c4 c1 7c 10 1c 83    	vmovups (%r11,%rax,4),%ymm3
    159e:	c4 c1 7c 58 44 86 a0 	vaddps -0x60(%r14,%rax,4),%ymm0,%ymm0
    15a5:	c4 c1 74 58 4c 86 c0 	vaddps -0x40(%r14,%rax,4),%ymm1,%ymm1
    15ac:	c4 c1 6c 58 54 86 e0 	vaddps -0x20(%r14,%rax,4),%ymm2,%ymm2
    15b3:	c4 c1 64 58 1c 86    	vaddps (%r14,%rax,4),%ymm3,%ymm3
    15b9:	c5 fc 11 44 83 a0    	vmovups %ymm0,-0x60(%rbx,%rax,4)
    15bf:	c5 fc 11 4c 83 c0    	vmovups %ymm1,-0x40(%rbx,%rax,4)
    15c5:	c5 fc 11 54 83 e0    	vmovups %ymm2,-0x20(%rbx,%rax,4)
    15cb:	c5 fc 11 1c 83       	vmovups %ymm3,(%rbx,%rax,4)
    15d0:	48 05 00 01 00 00    	add    $0x100,%rax
    15d6:	49 83 c2 f8          	add    $0xfffffffffffffff8,%r10
    15da:	0f 85 80 fc ff ff    	jne    1260 <_Z14vec_add_莎莎jPfS_S_+0x90>
    15e0:	4d 85 c0             	test   %r8,%r8
    15e3:	74 71                	je     1656 <_Z14vec_add_莎莎jPfS_S_+0x486>
    15e5:	4c 8d 54 81 60       	lea    0x60(%rcx,%rax,4),%r10
    15ea:	4c 8d 5c 82 60       	lea    0x60(%rdx,%rax,4),%r11
    15ef:	48 8d 44 86 60       	lea    0x60(%rsi,%rax,4),%rax
    15f4:	49 c1 e0 07          	shl    $0x7,%r8
    15f8:	31 db                	xor    %ebx,%ebx
    15fa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1600:	c5 fc 10 44 18 a0    	vmovups -0x60(%rax,%rbx,1),%ymm0
    1606:	c5 fc 10 4c 18 c0    	vmovups -0x40(%rax,%rbx,1),%ymm1
    160c:	c5 fc 10 54 18 e0    	vmovups -0x20(%rax,%rbx,1),%ymm2
    1612:	c5 fc 10 1c 18       	vmovups (%rax,%rbx,1),%ymm3
    1617:	c4 c1 7c 58 44 1b a0 	vaddps -0x60(%r11,%rbx,1),%ymm0,%ymm0
    161e:	c4 c1 74 58 4c 1b c0 	vaddps -0x40(%r11,%rbx,1),%ymm1,%ymm1
    1625:	c4 c1 6c 58 54 1b e0 	vaddps -0x20(%r11,%rbx,1),%ymm2,%ymm2
    162c:	c4 c1 64 58 1c 1b    	vaddps (%r11,%rbx,1),%ymm3,%ymm3
    1632:	c4 c1 7c 11 44 1a a0 	vmovups %ymm0,-0x60(%r10,%rbx,1)
    1639:	c4 c1 7c 11 4c 1a c0 	vmovups %ymm1,-0x40(%r10,%rbx,1)
    1640:	c4 c1 7c 11 54 1a e0 	vmovups %ymm2,-0x20(%r10,%rbx,1)
    1647:	c4 c1 7c 11 1c 1a    	vmovups %ymm3,(%r10,%rbx,1)
    164d:	48 83 eb 80          	sub    $0xffffffffffffff80,%rbx
    1651:	49 39 d8             	cmp    %rbx,%r8
    1654:	75 aa                	jne    1600 <_Z14vec_add_莎莎jPfS_S_+0x430>
    1656:	4c 39 cf             	cmp    %r9,%rdi
    1659:	0f 84 eb 00 00 00    	je     174a <_Z14vec_add_莎莎jPfS_S_+0x57a>
    165f:	48 89 f8             	mov    %rdi,%rax
    1662:	48 f7 d0             	not    %rax
    1665:	4c 89 cb             	mov    %r9,%rbx
    1668:	4c 01 c8             	add    %r9,%rax
    166b:	48 83 e3 07          	and    $0x7,%rbx
    166f:	74 26                	je     1697 <_Z14vec_add_莎莎jPfS_S_+0x4c7>
    1671:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)
    1678:	0f 1f 84 00 00 00 00 
    167f:	00 
    1680:	c5 fa 10 04 be       	vmovss (%rsi,%rdi,4),%xmm0
    1685:	c5 fa 58 04 ba       	vaddss (%rdx,%rdi,4),%xmm0,%xmm0
    168a:	c5 fa 11 04 b9       	vmovss %xmm0,(%rcx,%rdi,4)
    168f:	48 ff c7             	inc    %rdi
    1692:	48 ff cb             	dec    %rbx
    1695:	75 e9                	jne    1680 <_Z14vec_add_莎莎jPfS_S_+0x4b0>
    1697:	48 83 f8 07          	cmp    $0x7,%rax
    169b:	0f 82 a9 00 00 00    	jb     174a <_Z14vec_add_莎莎jPfS_S_+0x57a>
    16a1:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)
    16a8:	0f 1f 84 00 00 00 00 
    16af:	00 
    16b0:	c5 fa 10 04 be       	vmovss (%rsi,%rdi,4),%xmm0
    16b5:	c5 fa 58 04 ba       	vaddss (%rdx,%rdi,4),%xmm0,%xmm0
    16ba:	c5 fa 11 04 b9       	vmovss %xmm0,(%rcx,%rdi,4)
    16bf:	c5 fa 10 44 be 04    	vmovss 0x4(%rsi,%rdi,4),%xmm0
    16c5:	c5 fa 58 44 ba 04    	vaddss 0x4(%rdx,%rdi,4),%xmm0,%xmm0
    16cb:	c5 fa 11 44 b9 04    	vmovss %xmm0,0x4(%rcx,%rdi,4)
    16d1:	c5 fa 10 44 be 08    	vmovss 0x8(%rsi,%rdi,4),%xmm0
    16d7:	c5 fa 58 44 ba 08    	vaddss 0x8(%rdx,%rdi,4),%xmm0,%xmm0
    16dd:	c5 fa 11 44 b9 08    	vmovss %xmm0,0x8(%rcx,%rdi,4)
    16e3:	c5 fa 10 44 be 0c    	vmovss 0xc(%rsi,%rdi,4),%xmm0
    16e9:	c5 fa 58 44 ba 0c    	vaddss 0xc(%rdx,%rdi,4),%xmm0,%xmm0
    16ef:	c5 fa 11 44 b9 0c    	vmovss %xmm0,0xc(%rcx,%rdi,4)
    16f5:	c5 fa 10 44 be 10    	vmovss 0x10(%rsi,%rdi,4),%xmm0
    16fb:	c5 fa 58 44 ba 10    	vaddss 0x10(%rdx,%rdi,4),%xmm0,%xmm0
    1701:	c5 fa 11 44 b9 10    	vmovss %xmm0,0x10(%rcx,%rdi,4)
    1707:	c5 fa 10 44 be 14    	vmovss 0x14(%rsi,%rdi,4),%xmm0
    170d:	c5 fa 58 44 ba 14    	vaddss 0x14(%rdx,%rdi,4),%xmm0,%xmm0
    1713:	c5 fa 11 44 b9 14    	vmovss %xmm0,0x14(%rcx,%rdi,4)
    1719:	c5 fa 10 44 be 18    	vmovss 0x18(%rsi,%rdi,4),%xmm0
    171f:	c5 fa 58 44 ba 18    	vaddss 0x18(%rdx,%rdi,4),%xmm0,%xmm0
    1725:	c5 fa 11 44 b9 18    	vmovss %xmm0,0x18(%rcx,%rdi,4)
    172b:	c5 fa 10 44 be 1c    	vmovss 0x1c(%rsi,%rdi,4),%xmm0
    1731:	c5 fa 58 44 ba 1c    	vaddss 0x1c(%rdx,%rdi,4),%xmm0,%xmm0
    1737:	c5 fa 11 44 b9 1c    	vmovss %xmm0,0x1c(%rcx,%rdi,4)
    173d:	48 83 c7 08          	add    $0x8,%rdi
    1741:	49 39 f9             	cmp    %rdi,%r9
    1744:	0f 85 66 ff ff ff    	jne    16b0 <_Z14vec_add_莎莎jPfS_S_+0x4e0>
    174a:	5b                   	pop    %rbx
    174b:	41 5e                	pop    %r14
    174d:	c5 f8 77             	vzeroupper
    1750:	c3                   	ret
    1751:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)
    1758:	0f 1f 84 00 00 00 00 
    175f:	00 
