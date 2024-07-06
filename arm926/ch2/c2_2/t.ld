ENTRY(start)
SECTIONS
{
  . = 0x10000;
  .text : { *(.text.start) }
  .text : { *(.text) }
  .data : { *(.data) }
  .bss  : { *(.bss)  }
  . = ALIGN(8);
  . = . + 0x1000; /* 4kB of stack memory */
  stack_top = .;
}

