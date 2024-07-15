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
.code 32

.global main, proc0, procsize
.global reset_handler, tswitch, scheduler, running

reset_handler:
// set SVC sp to proc0 high end 
  LDR r0, =proc0
  LDR r1, =procsize
  LDR r2, [r1, #0]
  ADD r0, r0, r2
  MOV sp, r0
	
// call main() in C
  BL  main
	
tswitch:
//       1  2  3  4  5  6  7  8  9  10  11  12  13  14
//       ---------------------------------------------
// stack=r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r14
//       ---------------------------------------------
SAVE:	
  stmfd	sp!, {r0-r12, lr}
  LDR r0, =running     // r0=&running
  LDR r1, [r0, #0]     // r1->runningPROC
  str sp, [r1, #4]     // running->ksp = sp
FIND:	
  bl	scheduler
RESUME:	
  LDR r0, =running
  LDR r1, [r0, #0]     // r1->runningPROC
  LDR sp, [r1, #4]
  ldmfd	sp!, {r0-r12, pc}

	.end
