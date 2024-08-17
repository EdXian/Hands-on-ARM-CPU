ENTRY(vector_start)

MEMORY{
  rom (rx) : ORIGIN = 0x00000000, LENGTH = 64K
  ram (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS{
  .text : {
  *(.text.vector)
  *(.text .text.*)
  *(.rodata)

 } > rom

_e_text = . ;
.data  :  AT(_e_text) {
 _s_data = .  ;
*(.data .data.*)
 *(.ramfunc)
 _e_data = .  ;
} > ram

 .bss : {
  _s_bss = .  ;
   *(.bss*)
  _e_bss =  .  ;
 } > ram

. =  0x20002000 ; 
stack_msp_top = . ;

. =  0x20008000 ; 
stack_psp_top = . ;
} 