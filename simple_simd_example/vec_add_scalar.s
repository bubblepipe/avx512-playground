00000000000011d0 <_Z14vec_add_莎莎jPfS_S_>:
    11d0:	85 ff                	test   %edi,%edi
    11d2:	0f 84 b9 00 00 00    	je     1291 <_Z14vec_add_莎莎jPfS_S_+0xc1>
    11d8:	89 ff                	mov    %edi,%edi
    11da:	41 89 f8             	mov    %edi,%r8d
    11dd:	48 8d 47 ff          	lea    -0x1(%rdi),%rax
    11e1:	41 83 e0 07          	and    $0x7,%r8d
    11e5:	48 83 f8 07          	cmp    $0x7,%rax
    11e9:	73 04                	jae    11ef <_Z14vec_add_莎莎jPfS_S_+0x1f>
    11eb:	31 c0                	xor    %eax,%eax
    11ed:	eb 77                	jmp    1266 <_Z14vec_add_莎莎jPfS_S_+0x96>
    11ef:	83 e7 f8             	and    $0xfffffff8,%edi
    11f2:	31 c0                	xor    %eax,%eax
    11f4:	66 66 66 2e 0f 1f 84 	data16 data16 cs nopw 0x0(%rax,%rax,1)
    11fb:	00 00 00 00 00 
    1200:	d9 04 86             	flds   (%rsi,%rax,4)
    1203:	d8 04 82             	fadds  (%rdx,%rax,4)
    1206:	d9 1c 81             	fstps  (%rcx,%rax,4)
    1209:	d9 44 86 04          	flds   0x4(%rsi,%rax,4)
    120d:	d8 44 82 04          	fadds  0x4(%rdx,%rax,4)
    1211:	d9 5c 81 04          	fstps  0x4(%rcx,%rax,4)
    1215:	d9 44 86 08          	flds   0x8(%rsi,%rax,4)
    1219:	d8 44 82 08          	fadds  0x8(%rdx,%rax,4)
    121d:	d9 5c 81 08          	fstps  0x8(%rcx,%rax,4)
    1221:	d9 44 86 0c          	flds   0xc(%rsi,%rax,4)
    1225:	d8 44 82 0c          	fadds  0xc(%rdx,%rax,4)
    1229:	d9 5c 81 0c          	fstps  0xc(%rcx,%rax,4)
    122d:	d9 44 86 10          	flds   0x10(%rsi,%rax,4)
    1231:	d8 44 82 10          	fadds  0x10(%rdx,%rax,4)
    1235:	d9 5c 81 10          	fstps  0x10(%rcx,%rax,4)
    1239:	d9 44 86 14          	flds   0x14(%rsi,%rax,4)
    123d:	d8 44 82 14          	fadds  0x14(%rdx,%rax,4)
    1241:	d9 5c 81 14          	fstps  0x14(%rcx,%rax,4)
    1245:	d9 44 86 18          	flds   0x18(%rsi,%rax,4)
    1249:	d8 44 82 18          	fadds  0x18(%rdx,%rax,4)
    124d:	d9 5c 81 18          	fstps  0x18(%rcx,%rax,4)
    1251:	d9 44 86 1c          	flds   0x1c(%rsi,%rax,4)
    1255:	d8 44 82 1c          	fadds  0x1c(%rdx,%rax,4)
    1259:	d9 5c 81 1c          	fstps  0x1c(%rcx,%rax,4)
    125d:	48 83 c0 08          	add    $0x8,%rax
    1261:	48 39 c7             	cmp    %rax,%rdi
    1264:	75 9a                	jne    1200 <_Z14vec_add_莎莎jPfS_S_+0x30>
    1266:	4d 85 c0             	test   %r8,%r8
    1269:	74 26                	je     1291 <_Z14vec_add_莎莎jPfS_S_+0xc1>
    126b:	48 8d 0c 81          	lea    (%rcx,%rax,4),%rcx
    126f:	48 8d 14 82          	lea    (%rdx,%rax,4),%rdx
    1273:	48 8d 04 86          	lea    (%rsi,%rax,4),%rax
    1277:	31 f6                	xor    %esi,%esi
    1279:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1280:	d9 04 b0             	flds   (%rax,%rsi,4)
    1283:	d8 04 b2             	fadds  (%rdx,%rsi,4)
    1286:	d9 1c b1             	fstps  (%rcx,%rsi,4)
    1289:	48 ff c6             	inc    %rsi
    128c:	49 39 f0             	cmp    %rsi,%r8
    128f:	75 ef                	jne    1280 <_Z14vec_add_莎莎jPfS_S_+0xb0>
    1291:	c3                   	ret
    1292:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)
    1299:	1f 84 00 00 00 00 00 