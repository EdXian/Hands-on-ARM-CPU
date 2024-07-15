/********************************************************************
Copyright 2010-2017 K.C. Wang, <kwang@eecs.wsu.edu>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/
#include "stdint.h"
#include "uart.h"
#include "nuc980.h"
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/*
UART0 base address: 0x101f1000;
UART1 base address: 0x101f2000;
UART2 base address: 0x101f3000;
UART3 base address: 0x10009000;

UART Registers from base address:
0x00 Data          register
0x18 Flag          register
0x24 BaudRate      register
0x2C LineControl   register
0x38 InterruptMask register

// flag register at 0x18
//  7    6    5    4    3    2   1   0
// TXFE RXFF TXFF RXFE BUSY
// TX FULL : 0x20
// TX empty: 0x80
// RX FULL : 0x40
// RX empty: 0x10
// BUSY=1 :  0x08
*/

int N;
int v[] = {1,2,3,4,5,6,7,8,9,10};
int sum;

#include "string.c"


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

void irq_chandler()
{

}

int mkPtable()
{
  int i;
  u32 pentry, *ptable;
  uprintf("            Welcome to WANIX in Arm\n");
  uprintf("1. build level-1 pgtable at 16KB\n");

  ptable = (u32 *)0x4000; // page table at 0x4000

  for (i=0; i<4096; i++){ // clear 4K entries to 0
     ptable[i] = 0;
  }
  uprintf("2. fill 258 entries of ptable to ID map 258MB VA to PA\n");
  pentry = 0 | 0x412;
  //  pentry = 0 | 0x41E;
  
  for (i=0; i<258; i++){
    ptable[i] = pentry;
    pentry += 0x100000;   // inc by 1MB
  }
  uprintf("3. finished building level-1 page table\n");
  uprintf("4. return to set TTB, doman and enable MMU\n");
}


int main()
{
  int i;
  int size = sizeof(int);
  char string[32]; 
  char line[128]; 
  UART *up;
  
  N = 10;

  uart_init();

  up = &uart[0];
  uprintf("Enter lines from UART terminal, enter quit to exit\n");
  
  while(1){
    ugets(up, string);
    uprintf("    ");
    if (strcmp(string, "quit")==0)
       break;
    uprintf("%s\n", string);
  }
  uprintf("\n");

  uprintf("Compute sum of array\n");
  sum = 0;
  for (i=0; i<N; i++)
    sum += v[i];
  uprintf("sum = %d %x\n", sum, 100);
  uprintf("END OF UART DEMO\n");
  uprintf("Enter Control-a, then x to exit QEMU\n");

}
