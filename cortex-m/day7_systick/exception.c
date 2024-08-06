void Default_Handler(void)
{
	while(1);
}
__attribute__((weak)) void NMI_Handler(void){
  Default_Handler();
}       
     
__attribute__((weak)) void HardFault_Handler(void){
     Default_Handler();
}      

__attribute__((weak)) void MemManage_Handler(void){
 Default_Handler();
}      

__attribute__((weak)) void BusFault_Handler(void){
     Default_Handler();
}       

__attribute__((weak)) void UsageFault_Handler(void){
 Default_Handler();
}     
__attribute__((weak)) void SecureFault_Handler(void){
 Default_Handler();
}    
__attribute__((weak)) void SVC_Handler(void){
 Default_Handler();
}            
__attribute__((weak)) void DebugMon_Handler(void){
 Default_Handler();
}       
__attribute__((weak)) void PendSV_Handler(void){
 Default_Handler();
}         
__attribute__((weak)) void SysTick_Handler(void){
 Default_Handler();
}       