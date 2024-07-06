ENTRY(reset)
SECTIONS
{
  . = 0x8000;
  .text : { *(.text.reset) } 
  .text : { *(.text) }
  .data : { *(.data) }
  .bss  : { *(.bss)  }
  . = ALIGN(8);
  . = . + 0x2000; /* 4kB of stack memory */
  stack_top = .;
}

