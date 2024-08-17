arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c start.s -o start.o
arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c cpu.s -o cpu.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4  -g -c main.c -o main.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -g -c exception.c -o exception.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4  -g -c task.c -o task.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -g -c __main.c -o __main.o
arm-none-eabi-ld start.o main.o cpu.o  task.o exception.o __main.o -Tlink.ld -o example.elf


