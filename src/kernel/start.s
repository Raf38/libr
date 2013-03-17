.globl _start

_start:
	pop  %rdi	# rdi = argc
	mov  %rsp, %rsi # rsi = argv
	mov  %rdi, %rax # rax = argc;
	add  $1,   %rax # rax++;
	sal  $3,   %rax # rax <<= 3 change to reflect num bytes
	mov  %rsp, %rdx # env = argv
	add  %rax, %rdx # env += rax;
	call main	# rax = main(rdi,rsi,rdx);
	mov  %rax, %rdi # rdi = rax;
	mov  $60,  %rax # rax = 60;
	syscall         # syscall(rax,rdi); //exit(rdi)

