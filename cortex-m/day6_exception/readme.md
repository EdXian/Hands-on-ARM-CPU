# Introduction







vector tables in Cortex-M4

```
	Stack_top
	ResetException
	NMIException,
	HardFaultException,
	MemManageException,
	BusFaultException,
	UsageFaultException,
	0, 0, 0, 0, 				    /* Reserved */
	SVCHandler,
	DebugMonitor,
	0,					    /* Reserved */
	PendSVC,
	SysTickHandler
```



```
arm-none-eabi-as -mthumb -mcpu=cortex-m4 -c start.s -o start.o
arm-none-eabi-gcc -mthumb  -mcpu=cortex-m4 -g  -c exception.c -o exception.o
arm-none-eabi-gcc -mthumb -mcpu=cortex-m4 -c __main.c -o __main.o
arm-none-eabi-gcc -mthumb  -mcpu=cortex-m4  -mfloat-abi=softfp -mfpu=vfpv4-d16 -g -c main.c -o main.o
arm-none-eabi-ld start.o main.o __main.o exception.o  -Tlink.ld -o example.elf
arm-none-eabi-objdump -S example.elf > dump.txt
```





