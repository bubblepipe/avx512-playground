vmovups 0x40(%r8,%rdx,4),%ymm2
vmovups 0x60(%rbp,%rdx,4),%ymm1
vmovups 0x60(%r8,%rdx,4),%ymm3
vfmadd213ps 0x40(%rcx,%rdx,4),%ymm0,%ymm2
vfmadd213ps 0x60(%rcx,%rdx,4),%ymm1,%ymm3
vmovups %ymm2,0x40(%rcx,%rdx,4)
vmovups %ymm3,0x60(%rcx,%rdx,4)
vmovups 0x80(%rbp,%rdx,4),%ymm0
