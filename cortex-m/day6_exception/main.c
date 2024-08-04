

void UsageFault_Handler(void){

  __asm volatile(
    "LDR r2, =0xE000E00C    \n" // Load Coprocessor Power Control Register
    "MOV R3, #0x00000000    \n"
    "STR R3, [R2]           \n"
    "DSB                    \n"
    "ISB                    \n"
    "ADD R0, R0, #1         \n" // Increase flag if UsageFault has happened
    "BX  LR                 \n"
  );

}


int main(void){
  
   /*Hardfault handler*/
   //void (*p)(void);   
   //p = (void*)0xFFFFFFFF;
   //p();

   /*Hardfault handler*/
  //int a;
  // a = *(int*)0xFFFFFFFF ;

  /*Usage fault*/ 
  *(int*)0xE000ED24 |= 2 << 17; 
 float c=1.0,b=1.0;
  b=b/c;

}