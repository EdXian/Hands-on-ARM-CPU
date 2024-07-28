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

	.text
	.global reset, sum
        .extern  IRQ_Handler
reset:
  LDR PC, reset_handler_addr
  b .
  b .
  b .
  b .
  B .
  LDR PC, irq_handler_addr
  b .

reset_handler_addr:          .word reset_handler
irq_handler_addr:            .word IRQ_Handler

reset_handler:	
        ldr sp, =stack_top

        ldr r2, =a
	ldr r0, [r2]
	ldr r2, =b
	ldr r1, [r2]

	bl  main
        b .
	ldr r2, =c
	str r0, [r2]
stop:	b   stop
	
	.data
a:	.word  1
b:	.word  2
c:	.word  0

	
	
