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

#include "type.h"
#include "string.c"

char *tab = "0123456789ABCDEF";
int BASE;
int color;

#include "uart.c"
#include "kbd.c"
#include "timer.c"
#include "vid.c"
#include "exceptions.c"
int again = 0;

int mkPtable()
{
  int i;
  u32 pentry, *ptable;
  printf("            Welcome to WANIX in Arm\n");
  printf("1. build level-1 pgtable at 16KB\n");

  ptable = (u32 *)0x4000; // page table at 0x4000

  for (i=0; i<4096; i++){ // clear 4K entries to 0
     ptable[i] = 0;
  }
  printf("2. fill 258 entries of ptable to ID map 258MB VA to PA\n");
  pentry = 0 | 0x412;
  //  pentry = 0 | 0x41E;
  
  for (i=0; i<258; i++){
    ptable[i] = pentry;
    pentry += 0x100000;   // inc by 1MB
  }
  printf("3. finished building level-1 page table\n");
  printf("4. return to set TTB, doman and enable MMU\n");
}

int data_abort_handler()
{
  u32 fault_status, fault_addr, domain, status;
  int spsr = get_spsr();
  int oldcolor = color;
  again++;
  color = RED;
  kprintf("data_abort exception in ");
  if ((spsr & 0x1F)==0x13)
    kprintf("SVC mode\n");
  if ((spsr & 0x1F)==0x10)
    kprintf("USER mode\n");

  fault_status = get_fault_status();
  fault_addr   = get_fault_addr();
  // fault_status = 7654 3210
  //                doma status
  domain = (fault_status & 0xF0) >> 4;
  status = fault_status & 0xF;
  kprintf("status  = %x: domain=%x status=%x (0x5=Trans Invalid)\n", 
           fault_status, domain, status);
  kprintf("VA addr = %x\n", fault_addr);
  color = oldcolor;
  
  // if assembly code used lr-8: shall return to the SAME bad instruction
  // => infinite loop. If so, set a limit to stop the program
  if (again>3)   // limit to 3 times then HANG here
     while(1);
}

void copy_vector_table(void) {
    extern u32 vectors_start;
    extern u32 vectors_end;
    u32 *vectors_src = &vectors_start;
    u32 *vectors_dst = (u32 *)0;
    while(vectors_src < &vectors_end)
       *vectors_dst++ = *vectors_src++;
}

int kprintf(char *fmt, ...);
void timer0_handler();

// IRQ interrupts handlers in C
void irq_chandler()
{
    int vicstatus, sicstatus;

    // read VIC status register to find out which interrupt
    vicstatus = VIC_STATUS; // VIC_STATUS=0x10140000=status reg
    sicstatus = SIC_STATUS;  

    if (vicstatus & 0x0010){
         timer0_handler();
    }

    if (vicstatus & (1<<12)){
         uart_handler(&uart[0]);
    }
    if (vicstatus & 0x80000000){
      if (sicstatus & (1<<3)){
          kbd_handler();
       }
    }
}

int main()
{
   int i, *p;
   char line[128]; 
   int size = sizeof(int);
   UART *up;
   
   kbd_init();

   // enable IRQ routing on VIC
   VIC_INTENABLE |= (1<<4);     // timer0,1 at 4 
   VIC_INTENABLE |= (1<<12);    // UART0 at 12
   VIC_INTENABLE |= (1<<31);    // SIC to VIC's IRQ31
   // enable UART0 RXIM interrupt
   UART0_IMSC |= 1<<4;
   // enable KBD IRQ on SIC
   SIC_ENSET |= 1<<3;           // KBD int=3 on SIC
   
   timer_init();
   timer_start(0);

   uart_init();
   up = &uart[0];

   printf("\n");
   printf("main running at %x using level-1 1MB sections\n", main);
 
   printf("test MMU protection: try to access VA=0x00200000=2MB\n");
   p = (int *)0x00200000;
   *p = 123;

   printf("test MMU protection: try to access VA=0x02000000=32MB\n");
   p = (int *)0x02000000;
   *p = 123;

   printf("test MMU protection: try to access VA=0x20000000=512MB\n");
   p = (int *)0x20000000;
   *p = 123;

   color = CYAN;
   uprints(up, "enter a line from this UART\n\r");
   ugets(up, line);
   uprints(up, line);
   
   while(1){
     printf("main running Input a line: ");
     kgets(line);
     printf("\nline = %s\n", line);
   }
}
