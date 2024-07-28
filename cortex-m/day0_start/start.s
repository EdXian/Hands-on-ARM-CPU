.thumb           // Q0
.section .text   // Q1

.global vector_start
vector_start:
stack_top: .word 0x00000000
reset_entry: .word Reset_Handler + 1   //why Reset Handler + 1
reserved: .space 0x400

Reset_Handler:
    nop     
    b Reset_Handler     //Infinite loop.
