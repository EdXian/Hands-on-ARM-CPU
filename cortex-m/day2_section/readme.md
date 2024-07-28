







```
arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c start.s -o start.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -g -c main.c -o main.o
arm-none-eabi-ld start.o main.o -Tlink.ld -o example.elf
```





section

```
 arm-none-eabi-objdump -t  example.elf > dump.txt
```



![var_bss_data](../png/var_bss_data.png)

```
 arm-none-eabi-objdump -D -S  example.elf > dump.txt
```



![var_stack](../png/var_stack.png)
