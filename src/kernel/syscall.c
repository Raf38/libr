#include "syscall.h"
#include <linux/unistd.h>

long _syscall1(long type, long a1)
{
	long ret;
	asm
	(
		"syscall"
	    	: "=a"(ret)
		: "a"(type), "D"(a1)
	);
	return ret;
}

long _syscall2(long type, long a1, long a2)
{
	long ret;
	asm
	(
		"syscall"
	    	: "=a"(ret)
		: "a"(type), "D"(a1), "S"(a2)
	);
	return ret;
}

long _syscall3(long type, long a1, long a2, long a3)
{
	long ret;
	asm
	(
		"syscall"
	    	: "=a"(ret)
		: "a"(type), "D"(a1), "S"(a2), "d"(a3)
	);
	return ret;
}


//exit is special as it doesnt return
void exit(int status)
{
	_syscall1(__NR_exit,status);
}

long nanosleep(const struct timespec* a, struct timespec* b)
{
	return _syscall2(__NR_nanosleep,(long)a,(long)b);
}

long write(int fd, const void* buffer, long length)
{
	return _syscall3(__NR_write, (long)fd, (long)buffer, length);
}

//void* mmap(void* addr, long length, int prot, int flags, int fd, long offset)
//{
//	return (void*)_asyscall6(__NR_mmap, (long)addr, length, (long)prot, (long)flags, (long)fd, offset);
//}

int open(const char* pathname, int flags, int mode)
{
	return _syscall3(__NR_open, (long)pathname, (long)flags, (long)mode);
}

//int munmap(void* addr, long length)
//{
//	return 0;//_(int)asyscall2(__NR_munmap,(long)addr,length);
//}

