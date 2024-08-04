# Introduction









Part 1

```
arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c start.s -o start.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -g -c main.c -o main.o
arm-none-eabi-ld start.o main.o -Tlink.ld -o example.elf
```



In section 1, we dump the elf file to `dump.txt` in which we check the location of symbols and variables.

```
 arm-none-eabi-objdump -t  example.elf > dump.txt
```



![var_bss_data](../png/var_bss_data.png)

```
 arm-none-eabi-objdump -D -S  example.elf > dump.txt
```



![var_stack](../png/var_stack.png)









Part 2

In section 2, we create a new linker script `link2.ld` where we specify the location of each section along with the `stack_top`. Next, we build this example by the following commands.

```
arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c start.s -o start2.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -g -c main.c -o main.o
arm-none-eabi-ld start.o main.o -Tlink2.ld -o example.elf
```



```
arm-none-eabi-objdump -t  example.elf > dump.txt
```

![var2_bss_data](../png/var2_bss_data.png)



Part 3

linker script

![](../png/memory_ld.png)



![](../png/memory_ld2.png)



```
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -g -c main.c -o main.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -g -c __main.c -o __main.o
arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c start3.s -o start3.o
arm-none-eabi-ld start3.o main.o __main.o -Tlink3.ld -o example.elf
```



part4 :

relocation the data









Part5 (optional):

execute function in sram.





