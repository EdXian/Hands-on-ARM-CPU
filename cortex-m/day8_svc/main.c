#include "stdint.h"
#define SVC_COMPUTE 4
#define svc(code) asm volatile ("svc %[immediate]"::[immediate] "I" (code))


void sys_memcpy(void *a, void* b, int size){
      asm("svc  #0"); 
}

typedef void (*svcall_t)(void*);

void  service_call(void (*func)(void*), void* args) ;
 
void service_call(void (*func)(void*), void* args){
     //by convention func is in r0 and args is in r1
     asm volatile("svc 0");
}

extern void svc_call(void);
void my_priv_func(void * data){
    int * my_int;
    my_int = data;
    if (*my_int == 10 ){
        *my_int = 0;
    }
}
void func(int a,int b,int *c){
    *c = a+b+*c; 
}


uint32_t test = 0;
void SVC_Handler_C(int *svc_args){

    int svc_number;
    svc_number = ((char *)svc_args[6])[-2];

    switch(svc_number)
    {
        case SVC_COMPUTE:
            func(svc_args[0],svc_args[1],(int*)svc_args[2]);

            return;
        default:
            /* Unknown SVC */
            break;
    }
}

__attribute__ ((noinline)) void sv_call_write_data(int a, int b, int *c)
{
    svc(SVC_COMPUTE);
}

int main(void){
   int var;
   var = 10;
   sv_call_write_data(3,5,&var);
   while(1);
}