.thumb           // Q0
.section .text   // Q1

.global vector_start
vector_start:
//stack_top: .word 0x20002000
 .word stack_top
reset_entry: .word Reset_Handler + 1   //why Reset Handler + 1
reserved: .space 0x400

Reset_Handler:
    nop     
    b main      //Infinite loop.
    b .
.end
