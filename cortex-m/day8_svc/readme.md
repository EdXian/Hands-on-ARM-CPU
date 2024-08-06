arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c start.s -o start.o
arm-none-eabi-gcc -mthumb  -mcpu=cortex-m4 -g  -c exception.c -o exception.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -c __main.c -o __main.o
arm-none-eabi-gcc -mthumb -mapcs-frame -mthumb-interwork  -mcpu=cortex-m4  -g -c main.c -o main.o
arm-none-eabi-ld start.o main.o __main.o exception.o  -Tlink.ld -o example.elf
arm-none-eabi-objdump -S example.elf > dump.txt