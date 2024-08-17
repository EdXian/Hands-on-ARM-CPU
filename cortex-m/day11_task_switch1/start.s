.thumb      
.syntax unified

.extern NMI_Handler
.extern HardFault_Handler
.extern MemManage_Handler
.extern BusFault_Handler 
.extern UsageFault_Handler
.extern SecureFault_Handler
.extern SVC_Handler
.extern DebugMon_Handler
.extern PendSV_Handler
.extern SysTick_Handler

.section .text.vector   
.global vector_start
vector_start:
 .word stack_msp_top
reset_entry:        .word     Reset_Handler + 1 
nmi_enrty:          .word     NMI_Handler + 1
hardfault_entry:    .word     HardFault_Handler + 1     
memange_entry:      .word     MemManage_Handler + 1
busfault_entry:     .word     BusFault_Handler + 1
usagefault_entry:   .word     UsageFault_Handler + 1
securefault_entry:  .word     SecureFault_Handler + 1
.word 0xFFFFFFFF
.word 0xFFFFFFFF
.word 0xFFFFFFFF
svc_entry:          .word     SVC_Handler + 1
debugmon_entry:     .word     DebugMon_Handler + 1
.word 0xFFFFFFFF
pendsv_entry:       .word     PendSV_Handler + 1
systick_entry:      .word     SysTick_Handler + 1
 
reserved: .space 0x400

Reset_Handler:
    nop

 
    bl __main    
    b .      //Infinite loop.


.end
