#include "uart.h"
#include "nuc980.h"

int uart_init(){
    /* enable UART0 clock */
    *(uint32_t*)REG_CLK_PCLKEN0 |= 0x10000;

    /* GPF11, GPF12 */
    *(uint32_t*)REG_SYS_GPF_MFPH = (*(uint32_t*)REG_SYS_GPF_MFPH&0xfff00fff) | 0x11000; // UART0 multi-function
    
    *(uint32_t*)REG_UART0_LCR |= 0x07;  /* UART0 line configuration for (115200,n,8,1) */
   
    *(uint32_t*)REG_UART0_BAUD |= 0x30000066;   /* 12MHz reference clock input, 115200 */
}

int uputc(UART *up, char c)
{
    while ((inpw(REG_UART0_FSR) & (1<<23))); //waits for TX_FULL bit is clear
    *(uint32_t*)REG_UART0_THR = c;
}

int ugetc(UART *up)
{
  while( (inpw(REG_UART0_FSR) & (1 << 14)) != 0);  // waits RX not empty
  return (char)(*((uint32_t*)REG_UART0_RBR));
}
