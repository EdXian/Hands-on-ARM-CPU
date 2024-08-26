# Introduction



```
arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c start.s -o start.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -g -c main.c -o main.o
arm-none-eabi-ld start.o main.o -Tlink.ld -o example.elf
```



Analyzing the disassembly code

dump your code:

```
arm-none-eabi-objdump -D  example.elf > dump.txt
```



![image-20240728171102376](../png/disassembly.png)



# MSP vs PSP(Optional)

​     Typically, most systems use a single stack for execution. However, in certain scenarios—such as when an RTOS (Real-Time Operating System) is deployed—the CPU may operate in different modes (user or kernel). The stack used in user mode differs from the one in kernel mode. This separation ensures that user applications cannot directly access kernel data, maintaining security.  

"When it comes to Cortex-M series processors, we have our stack superheroes: the **PSP** (Process Stack Pointer) and the **MSP** (Main Stack Pointer). Here’s the backstage scoop:

- **PSP (Process Stack Pointer)**: This is the user mode stack. 
- **MSP (Main Stack Pointer)**: This is the kernel mode stack. 
