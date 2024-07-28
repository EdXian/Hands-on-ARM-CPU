ENTRY(vector_start)



SECTIONS{
 . = 0x00000000;
  .text : {
  *(.text*)
 }
. = 0x20000000;
 .bss : {
   *(.bss*);
 }
.data : {
  *(.data*)
}
/*stack_top = . ;*/
}