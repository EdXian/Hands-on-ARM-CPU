

void UsageFault_Handler(void){

  *((int*)0xE000ED88) |= 0x00F00000 ;

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
 *((int*)0xE000ED88) &= ~(0x00F00000) ;
  *(int*)0xE000ED24 |= 2 << 17; 
 float c=1.0,b=1.0;
  b=b/c;

  // the fpu is enabled...
   b=b/c;

}