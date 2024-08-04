# Introduction

This chapter is optional. 

The following steps will show how to enable fpu and tell the compiler to use the fpu when calculating.





enable fpu before calculating floating point variable.

```
 *(uint32_t*)0xE000ED88 |= ((3UL << 10*2)|(3UL << 11*2)); 
 //or
 *(uint32_t*)0xE000ED88 |= 0x00F00000 ;
```





### Compile flags

choose the float-abi, the compiler will use instruction that call fpu to compute variable with floating point.

```
-mfloat-abi=softfp
```

```
-mfloat-abi=hard
```



### Vector Floating Point (VFP)

choose the vfp version that the FPU supports for. Generally, In arm cortex m4F, we can use `vfpv4-d16`

```
-mfpu=vfpv4-d16
```





```
arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c start.s -o start.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -c __main.c -o __main.o
arm-none-eabi-gcc -mthumb -mfloat-abi=softfp -mfpu=vfpv4-d16 -mcpu=cortex-m4 -g -c main.c -o main.o
arm-none-eabi-ld start.o main.o __main.o -lgcc -L. -Tlink.ld -o example.elf
arm-none-eabi-objdump -S example.elf > dump.txt

```







dump.txt(with fpu)

```
  return add(x, y)+a*b+d/c;
 438:   6839            ldr     r1, [r7, #0]
 43a:   6878            ldr     r0, [r7, #4]
 43c:   f7ff ffe8       bl      410 <add>
 440:   4601            mov     r1, r0
 442:   697b            ldr     r3, [r7, #20]
 444:   693a            ldr     r2, [r7, #16]
 446:   fb02 f303       mul.w   r3, r2, r3
 44a:   440b            add     r3, r1
 44c:   ee07 3a90       vmov    s15, r3
 450:   eeb8 7ae7       vcvt.f32.s32    s14, s15
 454:   ed97 6a02       vldr    s12, [r7, #8]
 458:   edd7 6a03       vldr    s13, [r7, #12]
 45c:   eec6 7a26       vdiv.f32        s15, s12, s13
 460:   ee77 7a27       vadd.f32        s15, s14, s15
 464:   ee17 3a90       vmov    r3, s15
}
 468:   4618            mov     r0, r3
 46a:   3718            adds    r7, #24
 46c:   46bd            mov     sp, r7
 46e:   bd80            pop     {r7, pc}
```





