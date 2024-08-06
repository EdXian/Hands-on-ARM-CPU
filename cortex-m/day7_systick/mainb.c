
#define __REG_TYPE	volatile uint32_t
#define __REG		__REG_TYPE *

#define     STCSR   (*(int*)0xE000E010)       //control register
#define     STRVR   (*(int*)0xE000E014)       //reload value register
#define     STCVR   (*(int*)0xE000E018)       //current value register
#define     ICSR            ((int*)0xE000ED04)
#define     NVIC_ISER   ((int*)0xE000E100)

#define SYSTICK		((__REG_TYPE) 0xE000E010)
#define SYSTICK_CTRL	((__REG) (SYSTICK + 0x00))
#define SYSTICK_LOAD	((__REG) (SYSTICK + 0x04))
#define SYSTICK_VAL	((__REG) (SYSTICK + 0x08))
#define SYSTICK_CALIB	((__REG) (SYSTICK + 0x0C))

#define    COUNTFLAG     (1<< 16)
#define    CLKSOURCE      (1<< 2)
#define    TICKINT              (1<<1)
#define    ENABLE              (1<<0)
//SysTick_IRQn  15


#include "stdint.h"
#define     __IOM    volatile  
typedef struct
{
  __IOM uint32_t ISER[16U];              /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[16U];
  __IOM uint32_t ICER[16U];              /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RSERVED1[16U];
  __IOM uint32_t ISPR[16U];              /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[16U];
  __IOM uint32_t ICPR[16U];              /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[16U];
  __IOM uint32_t IABR[16U];              /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        uint32_t RESERVED4[16U];
  __IOM uint32_t ITNS[16U];              /*!< Offset: 0x280 (R/W)  Interrupt Non-Secure State Register */
        uint32_t RESERVED5[16U];
  __IOM uint32_t IPR[124U];              /*!< Offset: 0x300 (R/W)  Interrupt Priority Register */
}  NVIC_Type;

#define SCS_BASE            (0xE000E000UL) 
#define NVIC_BASE           (SCS_BASE +  0x0100UL)
#define NVIC                ((NVIC_Type      *)     NVIC_BASE        ) 

typedef enum IRQn
{
  NonMaskableInt_IRQn      = -14,/**<  2 Non Maskable Interrupt                */
  HardFault_IRQn           = -13,/**<  3 Cortex-M4 Hard Fault Interrupt        */
  MemoryManagement_IRQn    = -12,/**<  4 Cortex-M4 Memory Management Interrupt */
  BusFault_IRQn            = -11,/**<  5 Cortex-M4 Bus Fault Interrupt         */
  UsageFault_IRQn          = -10,/**<  6 Cortex-M4 Usage Fault Interrupt       */
  SVCall_IRQn              = -5, /**< 11 Cortex-M4 SV Call Interrupt           */
  DebugMonitor_IRQn        = -4, /**< 12 Cortex-M4 Debug Monitor Interrupt     */
  PendSV_IRQn              = -2, /**< 14 Cortex-M4 Pend SV Interrupt           */
  SysTick_IRQn             = -1, /**< 15 Cortex-M4 System Tick Interrupt       */
}IRQn_Type;

 void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    //__COMPILER_BARRIER();
    NVIC->ISER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    //__COMPILER_BARRIER();
  }
}
/*
 #define __NVIC_PRIO_BITS          3U
 void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    NVIC->IP[((uint32_t)IRQn)]               = (uint8_t)((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
  }
  else
  {
    SCB->SHP[(((uint32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
  }
}
*/

void systick_init(void){
   
    STCSR = 0;  //disable clock
    STCVR = 0;   //reset value

    STRVR =7200000;
    STCSR =  0x07;//(ENABLE | TICKINT | CLKSOURCE); 
    __NVIC_EnableIRQ(SysTick_IRQn );
}
void __attribute__((interrupt)) SysTick_Handler(void){
   
   asm("nop");
}
static inline void __enable_irq(void)
{
    asm("cpsie i");
}
static inline void __disable_irq(void)
{
    asm("cpsid i");
}
int main(void){
(*(int*)0xE000ED24) |= 2 << 17;
//__disable_irq();
 //  systick_init();
//__enable_irq();
	*SYSTICK_LOAD = 7200000;
	*SYSTICK_VAL = 0;
	*SYSTICK_CTRL = 0x07;

   while(1);
}