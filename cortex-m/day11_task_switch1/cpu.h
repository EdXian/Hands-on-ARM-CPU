#ifndef _CPU_H_
#define _CPU_H_

#include "stdint.h"

#define     STCSR   (*(int*)0xE000E010)       //control register
#define     STRVR   (*(int*)0xE000E014)       //reload value register
#define     STCVR   (*(int*)0xE000E018)       //current value register
#define     ICSR            (*(int*)0xE000ED04)
#define     NVIC_ISER   ((int*)0xE000E100)
#define    COUNTFLAG     (1<< 16)
#define    CLKSOURCE      (1<< 2)
#define    TICKINT              (1<<1)
#define    ENABLE              (1<<0)
#define    ICSR_PENDSVSET  (1<<28)





#endif