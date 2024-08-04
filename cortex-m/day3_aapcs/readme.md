# Introduction





aapcs:







```
arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c start.s -o start.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -g -c __main.c -o __main.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -g -c main.c -o main.o
arm-none-eabi-ld start.o main.o __main.o -Tlink.ld -o example.elf
```





How to tell the compiler to compile the code in aapcs rule?

```
-mabi=aapcs
```



```
-mthumb-interwork
```







```
arm-none-eabi-as -mcpu=cortex-m4 -c start.s -o start.o
arm-none-eabi-gcc -mthumb -mthumb-interwork -mabi=aapcs -mcpu=cortex-m4 -g -c main.c -o main.o
arm-none-eabi-ld start.o main.o -Tlink.ld -o example.elf
```

