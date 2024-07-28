





section 1

```
arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c start.s -o start.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -g -c main.c -o main.o
arm-none-eabi-ld start.o main.o -Tlink.ld -o example.elf
```



In section 1, we dump the elf file to `dump.txt` in which we check the location of symbols and varirables.

```
 arm-none-eabi-objdump -t  example.elf > dump.txt
```



![var_bss_data](../png/var_bss_data.png)

```
 arm-none-eabi-objdump -D -S  example.elf > dump.txt
```



![var_stack](../png/var_stack.png)









Section2

In section 2, we create a new linker script `link2.ld` where we specify the location of each section along with the `stack_top`. Next we build the example by the following commands.

```
arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c start.s -o start2.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -g -c main.c -o main.o
arm-none-eabi-ld start.o main.o -Tlink2.ld -o example.elf
```



```
arm-none-eabi-objdump -t  example.elf > dump.txt
```

![var2_bss_data](../png/var2_bss_data.png)
