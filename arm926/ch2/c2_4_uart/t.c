#include <stdio.h>
#include "nuc980.h"
#include "sys.h"
#include "uart.h"

void UART_Init()
{
    /* enable UART0 clock */
    *(uint32_t*)REG_CLK_PCLKEN0 |= 0x10000;

    /* GPF11, GPF12 */
    *(uint32_t*)REG_SYS_GPF_MFPH = (*(uint32_t*)REG_SYS_GPF_MFPH&0xfff00fff) | 0x11000; // UART0 multi-function
    
    *(uint32_t*)REG_UART0_LCR |= 0x07;  /* UART0 line configuration for (115200,n,8,1) */
   
    *(uint32_t*)REG_UART0_BAUD |= 0x30000066;   /* 12MHz reference clock input, 115200 */
}

extern int _write (int fd, char *ptr, int len);
int main(){
    sysDisableCache();
    sysFlushCache(I_D_CACHE);
    sysEnableCache(CACHE_WRITE_BACK);

 UART_Init();
 //UART_Write(UART0, "test\r\n", 6);
_write(0, "test\r\n",6);
}
int sum(int x, int y)
{
  return x+y;
}

  
