ENTRY(vector_table_start)
SECTIONS
{
 . = 0x10000;
 .text : {
   *(.text.vector)
   *(.text.entry)
   *(.rodata)
 }
 .data : {
    *(.data)
 }
 .bss : {
   *(.bss)
 }
 . = ALIGN(8);
 . = . + 0x1000;
 stack_top = .;
 . = . + 0x1000;
 irq_stack_top = .;
}
