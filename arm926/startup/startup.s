.arm
.code 32
.global vector_table_start
.global vector_table_end
.global entry_table_start
.global entry_table_end
.global Reset_Handler
.global Undef_Handler 
.global SWI_Handler    
.global Prefetch_Handler  
.global Abort_Handler
.global  IRQ_Handler
.global FIQ_Handler
.global main

.section .text
.align 4
vector_table_start:
vectors = .
ldr PC, =Reset_Entry
ldr PC, =Undef_Entry
ldr PC, =SWI_Entry
ldr PC, =Prefetch_Entry
ldr PC, =Abort_Entry
B .
ldr PC, =IRQ_Entry
ldr PC, =FIQ_Entry

 Reset_Entry: .word Reset_Handler
 Undef_Entry: .word Undef_Handler
 SWI_Entry:   .word SWI_Handler
 Prefetch_Entry: .word Prefetch_Handler
 Abort_Entry: .word  Abort_Handler
 IRQ_Entry:   .word IRQ_Handler
 FIQ_Entry:   .word FIQ_Handler
vector_table_end:


Reset_Handler:
  B .
  
 
Undef_Handler:
  B .
  

SWI_Handler:
  B .
  
  
Prefetch_Handler:
  B .


Abort_Handler:
  B .
  

IRQ_Handler:
  B .
 

FIQ_Handler:
  B .


main:
  NOP
  B .


.end 
