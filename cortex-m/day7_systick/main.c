#define     STCSR   (*(int*)0xE000E010)       //control register
#define     STRVR   (*(int*)0xE000E014)       //reload value register
#define     STCVR   (*(int*)0xE000E018)       //current value register
#define     ICSR            ((int*)0xE000ED04)
#define     NVIC_ISER   ((int*)0xE000E100)
#define    COUNTFLAG     (1<< 16)
#define    CLKSOURCE      (1<< 2)
#define    TICKINT              (1<<1)
#define    ENABLE              (1<<0)

void systick_init(void){
   
    STCSR = 0;  //disable clock
    STCVR = 0;   //reset value

    STRVR =  (1024)-1; 
    STCSR = (ENABLE | TICKINT | CLKSOURCE);
}

void SysTick_Handler(void){
   asm("nop");
}


int main(void){
    systick_init();
    while(1);
}