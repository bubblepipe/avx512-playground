flds   (%rsi,%rax,4)
fadds  (%rdx,%rax,4)
fstps  (%rcx,%rax,4)
flds   0x4(%rsi,%rax,4)
fadds  0x4(%rdx,%rax,4)
fstps  0x4(%rcx,%rax,4)
flds   0x8(%rsi,%rax,4)
fadds  0x8(%rdx,%rax,4)
fstps  0x8(%rcx,%rax,4)
flds   0xc(%rsi,%rax,4)
fadds  0xc(%rdx,%rax,4)
fstps  0xc(%rcx,%rax,4)

# 12 instructions -> 4 floats output
# Float Per Instr = 0.333

# llvm-mca: IPC = 2.93
# Float Per Clock = 0.97569

