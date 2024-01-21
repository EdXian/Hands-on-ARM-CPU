.section .text
.global _start


/*x1 msg x2 len*/
func1: 
   //x0 reserved for index
   /*x1 msg x2 len*/
   ldr x3,=msg_list
   add x3,x3,x0
   ldr x1,[x3]

   ldr x3,=len_list
   add x3,x3,x0
   ldr x2,[x3]
   ret
func2:
   nop
   ret
func3:
   nop
   ret


_start:


main:

    ldr x0,=0x08    //offset
    ldr x2,=fvec    //vector base
    ldr x1,[x2,x0]  //function =vector_base + offset 

    blr x1  //branch to function

    mov x0, #1
    mov x8, 0x40 //write syscall
    svc 0

    mov x8, #93 //exit syscall
    svc 0
    
    
/***********************************  
 *The data section is for initialized data
 **********************************/    
.data
msg1: .asciz "arg1\n"
len1 = . - msg1
msg2: .asciz "arg2\n"
len2 = . - msg2
msg3: .asciz "arg3\n"
len3 = . - msg3

msg_list:
  .quad msg1
  .quad msg2
  .quad msg3

len_list:
  .quad len1
  .quad len2
  .quad len3

fvec:
 .quad func1
 .quad func2
 .quad func3
