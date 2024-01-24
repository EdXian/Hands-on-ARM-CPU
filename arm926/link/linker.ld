
SECTIONS
{
   
 .text : {
   . = 0x00000; 
   *(.text.vector)
   . = . +0x40;
   *(.text.function)
   *(.text.misc)
   *(.rodata)
 }
 .data : {
    *(.data.arr)
 }
 .bss : {
   *(.bss)
 }

}
