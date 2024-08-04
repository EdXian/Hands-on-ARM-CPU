.thumb           // Q0
.section .text.vector   // Q1
.global vector_start
vector_start:
//stack_top: .word 0x20002000
 .word stack_top
reset_entry: .word Reset_Handler + 1   //why Reset Handler + 1
reserved: .space 0x400

Reset_Handler:
    nop     
    bl __main    
    b .      //Infinite loop.


.global add
add:
push {r7}
add r2, r1,r0
mov r0, r2
pop {r7}
bx lr


.end
