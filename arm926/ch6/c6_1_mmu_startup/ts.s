/********************************************************************
Copyright 2010-2017 K.C. Wang, <kwang@eecs.wsu.edu>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/

.global reset
.global vector_start
.global get_fault_status, get_fault_addr, get_spsr
.global lock, unlock, int_off, int_on

.global irq_handler, fiq_handler, data_handler, prefetch_abort_handler, swi_handler, undef_handler
.section .text.reset
vector_start:
LDR PC, reset_handler_addr
LDR PC, undef_handler_addr
LDR PC, swi_handler_addr
LDR PC, prefetch_abort_handler_addr
LDR PC, data_abort_handler_addr
B .
LDR PC, irq_handler_addr
B .

reset_handler_addr:          .word reset
undef_handler_addr:          .word undef_handler
swi_handler_addr:            .word swi_handler
prefetch_abort_handler_addr: .word prefetch_abort_handler
data_abort_handler_addr:     .word data_handler
irq_handler_addr:            .word irq_handler
fiq_handler_addr:            .word fiq_handler

reset:

    LDR sp, =stack_top
    BL uart_init

 // go in ABT mode to set ABT stack
  MOV r0, #0x17  //ORR r1, r1, #0x17
  MSR cpsr, r0
  LDR sp, =abt_stack_top
// go in UND mode to set UND stack
  mov r0, #0x1B
  MSR cpsr, r0
  LDR sp, =und_stack_top
// go in IRQ mode to set IRQ stack and enable IRQ interrupts
  mov r0, #0x12
  MSR cpsr, r0            // write to cspr, so in IRQ mode now 
  LDR sp, =irq_stack_top  // set IRQ stack poiner
  /* Enable IRQs */
	
// go back in SVC mode
  mov r0, #0x13           // r0 = SVC mode
  BIC r0, r0, #0x80       // ensure IRQ interrupt mask bit=0
  MSR cpsr, r0            // write r0 to CPSR






    // clear ptable at 0x4000
  mov r0, #0x4000
  mov r1, #4096              // 4096 entries
  mov r2, #0                 // all 0
3:
  str r2, [r0],#4            // store r2 to [r0]; inc r0 by 4
  subs r1,r1,#1              // r1-- 
  bgt 3b                     // loop r1=4096 times

	
/********** fill in 258 entries with 1MB increments ************/
// 258 entries in level-1 page table: 256MB RAM + 2MB I/O space at 256MB
  mov r0, #0x4000
  mov r1, #256               // r1=256 entries
  add r1, r1, #2             // r1=258

   mov r2, #0x100000         // r2=1MB

// load r3 with 0x412
   mov r3, #0x400
   orr r3, r3, #0x12
1:
   str r3, [r0],#0x04        // store r3 to [r0]; inc r0 by 4
   add r3, r3, r2            // inc r3 by 1M
   subs r1,r1,#1             // r1-- 
   bgt 1b                    // loop r1=4096 times

	
// DO IT in C:
  BL mkPtable
  	
// set TTB register
  mov r0, #0x4000
  mcr p15, 0, r0, c2, c0, 0  // set TTBase
  mcr p15, 0, r0, c8, c7, 0  // flush TLB
// set domain0: 01=client(check permission) 11=master(no check)
  mov r0,#1                  // client
  // mov r0,#0x3             // manager mode: NO permission check
  mcr p15, 0, r0, c3, c0, 0
// enable MMU
  mrc p15, 0, r0, c1, c0, 0   // get c1 into r0
  orr r0, r0, #0x00000001     // set bit0 to 1
  mcr p15, 0, r0, c1, c0, 0   // write to c1
  nop
  nop
  nop

    BL main
    B .



data_handler :
    b .

swi_handler:
 b .


irq_handler:
    sub	lr, lr, #4
    stmfd	sp!, {r0-r12, lr}
    bl	irq_chandler  
    ldmfd	sp!, {r0-r12, pc}^

unlock:	
    MRS r0, cpsr
    BIC r0, r0, #0x80   // clear bit means UNMASK IRQ interrupt
    MSR cpsr, r0
    mov pc, lr	

lock:	
    MRS r0, cpsr
    ORR r0, r0, #0x80    // set bit means MASK off IRQ interrupt 
    MSR cpsr, r0
    mov pc, lr	

int_on:	  // int_on(sr)
    MSR cpsr, r0
    mov pc, lr	

int_off:	// sr = int_off()
    MRS r0, cpsr
    MOV r1, r0
    ORR r1, r1, #0x80     // set bit means MASK off IRQ interrupt 
    MSR cpsr, r1
    mov pc, lr            // retunr CPSR in r0	

get_fault_status:	// read and return MMU reg 5
    MRC p15,0,r0,c5,c0,0  // read DFSR
    mov pc, lr	

get_fault_addr:	        // read and return MMU reg 6
    MRC p15,0,r0,c6,c0,0  // read DFSR
    mov pc, lr	

get_spsr:
    mrs r0, spsr
    mov pc, lr

.end
