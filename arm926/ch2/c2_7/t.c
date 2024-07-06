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

#include "defines.h"
#include "uart.c"
#include "vid.c"

extern char _binary_logo_start;

int BASE;
int color;

int show(char *p, int startRow, int startCol)
{ 
   int h, w, row, col, pixel; 
   unsigned char r, g, b;

   h = (*(p+3)<<24) + (*(p+2)<<16) + (*(p+1)<<8) + *p;
   p += 4;
   w = (*(p+3)<<24) + (*(p+2)<<16) + (*(p+1)<<8) + *p;
   p += 4;          // skip over 8 byes

   uprintf("h=%d w=%d\n", h, w);
   row = startRow; col = startCol;
   while(1){
     r = *p; g = *(p+1); b = *(p+2);
     pixel = (b<<16) + (g<<8) + r;
     //     fb[row*640 + col] = pixel;
     fb[row*WIDTH + col] = pixel;
     p += 3;         // advance p by 3 bytes
     col++;
     if (col >= w + startCol){  // to line width of jpg image
        col = startCol;
        row++;
     }
     if (row >= h+startRow)
        break;
   }
}


int main()
{
   char c, *p;
   char line[64];
   UART *up;
   
   uart_init();
   up = &uart[0];

   fbuf_init();
    
   p = &_binary_logo_start;
   show(p, 0, 0); 
   row = 4;
   while(1){
     color = GREEN;
     kprintf("enter a line from UART port : ");
     uprintf("enter line from UART : ");
     ugets(up, line);
     uprintf(" line=%s\n", line);
     color = RED;
     kprintf("line=%s\n", line);
   }
   while(1);   // loop here  
}
