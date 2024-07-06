/****************
qemu with -kernel file.bin ==> start to execute from 0x10000 ==>
file.bin must be loaded to 0x10000 ==> . = 0x10000
************/
ENTRY(reset_start)
SECTIONS
{
  . = 0x10000;
  .text : { ts.o *(.text) }
  .data : { *(.data) }
  .bss : { *(.bss) }
  .data : { panda.o }
  /*.data : { panda.o }*/       /* panda file */
  .data : { porkcar.o }     /* porkcar file */

  . = ALIGN(8);
  . = . + 0x4000;           /* SVC stack */
  stack_top = .;

}

