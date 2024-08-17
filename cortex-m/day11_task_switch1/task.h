#ifndef _TASK_H_
#define _TASK_H_
#include "stdint.h"
#define NUM_OF_TASKS 2
#define STACKSIZE 0x200



typedef struct{
	
  int32_t *stackPt;
  struct tcb *next_tcb;
}tcb_t;

void task_stack_init(int i);

uint8_t task_init(void(*task0)(void), void(*task1)(void));

#endif