

#include "type.h"
#include "uart.h"
PROC proc0, *running;
int procsize = sizeof(PROC);

int scheduler()
{
  running = &proc0;
}  
extern int tswitch(void);
int main()
{ 
  uart_init();
   printf("Welcome to Wanix in Arm\n");
   running = &proc0;
   printf("call tswitch()\n");
   tswitch();
   printf("back to main()\n");
   printf("enter while(1) loop\n");
   while(1);
}
