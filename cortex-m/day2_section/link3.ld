ENTRY(vector_start)

MEMORY{
  rom (rx) : ORIGIN = 0x00000000, LENGTH = 64K
  ram (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS{
  .text : {
  *(.text.vector)
  *(.text*)
  *(.rodata)
_e_text = . ;
 } > rom

. = 0x20000000 ; 
.data  :  AT(_e_text) {
 _s_data = .  ;
 *(.data*)
 _e_data = .  ;
} > ram

 .bss : {
  _s_bss = .  ;
   *(.bss*)
  _e_bss =  .  ;
 } > ram

. = . + 0x2000 ; 
stack_top = . ;
}