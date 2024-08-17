#include "task.h"

tcb_t tcbs[NUM_OF_TASKS];
tcb_t *currentTCB;


extern int stack_psp_top;
int *PSPBase = &stack_psp_top;

typedef struct{
    int r0;
    int r1;
    int r2;
    int r3;
    int r4;
    int r5;
    int r6;
    int r7;
    int r8;
    int r9;
    int r10;
    int r11;
    int r12;
    int lr;
    int pc;
    int xpsr;
}stack_frame_t;


void task_stack_init(int i){
   
   int* pspt =  PSPBase - i * STACKSIZE;
   stack_frame_t *st;
   int frame_size = sizeof(stack_frame_t)>>2;
   tcbs[i].stackPt =  pspt - frame_size;
   st = (stack_frame_t*)(pspt - frame_size);
   st->xpsr = 0x01000000;
   st->pc = 0xa5a5a5a5;
   st->r0 = 0x00000000;
   st->r1 = 0x11111111;
   st->r2 = 0x22222222;
   st->r3 = 0x33333333;
   st->r4 = 0x44444444;
   st->r5 = 0x55555555;
   st->r6 = 0x66666666;
   st->r7 = 0x77777777;
   st->r8 = 0x88888888;
   st->r9 = 0x99999999;
   st->r10 = 0xaaaaaaaa;
   st->r11 = 0xbbbbbbbb;
   st->r12 = 0xcccccccc;
}


uint8_t task_init(void(*task0)(void), void(*task1)(void))
{
    void *pspt;

	tcbs[0].next_tcb = &tcbs[1];
    tcbs[1].next_tcb = &tcbs[0];
    
	task_stack_init(0);
    pspt =  PSPBase - 0 * STACKSIZE;    //the stack top of task0
	((void*)pspt)[-2] = (void*)task0;

    task_stack_init(1);
    pspt =  PSPBase - 1 * STACKSIZE;    //the stack top of task1 
	((void*)pspt)[-2] = (void*)task1;

	currentTCB =&tcbs[0];
	return 1;	
}
