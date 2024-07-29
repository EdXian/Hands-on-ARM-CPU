# Introduction





```
arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c start.s -o start.o
arm-none-eabi-gcc -mthumb -mfloat-abi=soft -mfpu=vfpv4-d16 -mcpu=cortex-m4 -g -c main.c -o main.o
arm-none-eabi-ld start.o main.o -lgcc -L. -Tlink.ld -o example.elf
```





issue:

```
 undefined reference to `__aeabi_i2f'
```



```
arm-none-eabi-objdump -S libgcc.a > dump.txt
```



```
vim dump.txt

00000174 <__aeabi_i2f>:
 174:   f010 4300       ands.w  r3, r0, #2147483648     ; 0x80000000
 178:   bf48            it      mi
 17a:   4240            negmi   r0, r0
 17c:   ea5f 0c00       movs.w  ip, r0
 180:   bf08            it      eq
 182:   4770            bxeq    lr
 184:   f043 4396       orr.w   r3, r3, #1258291200     ; 0x4b000000
 188:   4601            mov     r1, r0
 18a:   f04f 0000       mov.w   r0, #0
 18e:   e01c            b.n     1ca <__aeabi_l2f+0x2a>
```



To find the exact library in the toolchain:

```
 arm-none-eabi-gcc  -print-libgcc-file-name
 
 /../lib/gcc/arm-none-eabi/7.2.1/libgcc.a
```





math library:

