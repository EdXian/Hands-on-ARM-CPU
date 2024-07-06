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
	.arm
.section .text.start
	.global start
start:	ldr sp, =stack_top
	bl  sum
stop:	b   stop
sum:
	mov r0, #0
	ldr r1, =Array
	ldr r2, =N
	ldr r2, [r2]
loop:
	ldr r3, [r1], #4
	add r0, r0, r3
	sub r2, r2, #1
	cmp r2, #0
	bne loop
	ldr r4, =Result
	str r0, [r4]
	mov pc, lr

	.data
N:	.word  10
Array:	.word  1,2,3,4,5,6,7,8,9,10
Result:	.word  0
	
	
