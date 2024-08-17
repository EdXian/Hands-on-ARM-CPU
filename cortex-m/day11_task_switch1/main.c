#include "cpu.h"
#include "task.h"
#include "string.h"


extern tcb_t tcbs[NUM_OF_TASKS];
extern tcb_t *currentTCB;


#define	QUANTA	10

uint32_t count0,count1,count2;

void Task0(void)
{ 
	 count0++;

}

void Task1(void){
	count1++;
}

int main(void)
{
	task_init(&Task0, &Task1);

	while(1){
		task_switch();
		currentTCB = currentTCB->next_tcb;
	}
}