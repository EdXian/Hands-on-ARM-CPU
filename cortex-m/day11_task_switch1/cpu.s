

.thumb
.syntax unified

.global _dsb_
_dsb_:
   dsb sy
mov pc, lr

.global _isb_
_isb_:
  isb 
mov pc, lr

.global _dmb_
_dmb_:
  dmb
mov pc, lr

.global set_msp
set_msp:
msr msp, r0
mov pc, lr

.global get_msp
get_msp:
mrs r0, msp
mov pc, lr

.global set_psp
set_psp:
msr psp, r0
mov pc, lr

.global get_psp
get_psp:
mrs r0, psp
mov pc, lr

.global enable_irq
enable_irq:
cpsie  i
mov pc, lr

.global disable_irq
disable_irq:
cpsid  i
mov pc, lr

.global use_psp
use_psp:
mov r0, #0x02
msr control, r0
mov pc, lr

.global task_switch
task_switch:

	LDR		r0,=currentTCB
	LDR		r1,[r0]
	LDR		sp,[r1]
	ldmia   sp!,{r0-r12}  //store the task's r0-r12 into the cpu register
    add sp, sp, #12
	ldr  pc, [sp, #-8]    //ldr pc by relative addres