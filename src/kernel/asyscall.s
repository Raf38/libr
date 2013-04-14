.globl _syscall4

_syscall4:
  mov     %rcx,%r10
	mov     %r8, %rax
	syscall 
  retq
