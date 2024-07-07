ENTRY(reset)
SECTIONS
{
  . = 0x8000;
/*  .text : { ts.o }  */
  .text : { *(.text) }
  .data : { *(.data) }

  .bss  : { 	
  __bss_start__ = .;
  *(.bss*)
  *(COMMON)
  __bss_end__ = .;  
  }
  . = ALIGN(8);
  . = . + 0x2000; /* 4kB of stack memory */
  stack_top = .;
}

