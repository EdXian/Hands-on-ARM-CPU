.arm
.code 32

.align 4
.section .text.vector
ldr PC ,=main

.section .text.function
.global entry
entry:
b .

.global main
main:
b .

.align 1
.section .data
test1: .byte  0x10
test2: .byte  0x20
test3: .byte  0x30
.align 4
test4:  .word  0x10000



.end 
