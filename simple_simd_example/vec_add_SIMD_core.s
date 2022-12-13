vmovups -0x3e0(%r11,%rax,4),%ymm0
vmovups -0x3c0(%r11,%rax,4),%ymm1
vmovups -0x3a0(%r11,%rax,4),%ymm2
vmovups -0x380(%r11,%rax,4),%ymm3
vaddps -0x3e0(%r14,%rax,4),%ymm0,%ymm0
vaddps -0x3c0(%r14,%rax,4),%ymm1,%ymm1
vaddps -0x3a0(%r14,%rax,4),%ymm2,%ymm2
vaddps -0x380(%r14,%rax,4),%ymm3,%ymm3
vmovups %ymm0,-0x3e0(%rbx,%rax,4)
vmovups %ymm1,-0x3c0(%rbx,%rax,4)
vmovups %ymm2,-0x3a0(%rbx,%rax,4)
vmovups %ymm3,-0x380(%rbx,%rax,4)

# VADDPS — Add Packed Single-Precision Floating-Point Values
# ymm 256 bits <-> 8 floats
# 12 instructions -> 32 floats output
# Float Per Instr = 2.666

# llvm-mca: IPC = 2.88 *
# Float Per Clock = 7.68
