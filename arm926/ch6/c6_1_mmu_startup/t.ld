ENTRY(vector_start)
SECTIONS
{
  . = 0x00000;

  .text : {
      ts.o
      *(.text .rodata)
  }
  .data : { *(.data) }
  .bss  : { *(.bss)  }
  . = ALIGN(8);
  . = . + 0x1000; /* 4kB of stack memory */
  stack_top = .;
  . = . + 0x1000; /* 4kB of stack memory */
  svc_stack_top = .;
  . = . + 0x1000; /* 4kB of irq stack memory */
  irq_stack_top = .;
  . = . + 0x1000; /* 4kB of abt stack memory */
  abt_stack_top = .;
  . = . + 0x1000; /* 4kB of und stack memory */
  und_stack_top = .;
}

