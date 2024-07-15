	.cpu arm926ej-s
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"t.c"
	.text
	.align	2
	.global	A
	.type	A, %function
A:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r0, r3
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	A, .-A
	.align	2
	.global	kc_handler
	.type	kc_handler, %function
kc_handler:
	@ Interrupt Service Routine.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	sub	lr, lr, #4
	stmfd	sp!, {r0, r1, r2, r3, fp, ip, lr}
	add	fp, sp, #24
	sub	sp, sp, #20
	mov	r3, #1
	str	r3, [fp, #-32]
	mov	r3, #2
	str	r3, [fp, #-36]
	ldr	r0, [fp, #-32]
	ldr	r1, [fp, #-36]
	bl	A
	str	r0, [fp, #-40]
	sub	sp, fp, #24
	@ sp needed
	ldmfd	sp!, {r0, r1, r2, r3, fp, ip, pc}^
	.size	kc_handler, .-kc_handler
	.ident	"GCC: (4.8.2-14ubuntu1+6) 4.8.2"
