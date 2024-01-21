.section .data
.align 4
func_table:
  .word func1
  .word func2
  .word func3
  


.section .text

.global _start
_start:

.global main
main:
ldr r0, =func_table
ldr r1,[r0,#0]
//ldr r13,[PC,#4]
bl func1
nop


func1:
nop
bx lr

func2:
nop
bx lr

func3:
nop
bx lr
