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
		: "memory"
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
		: "memory"
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
		: "memory"
	);
	return ret;
}
/*
long _syscall4(long type, long a1, long a2, long a3, long a4)
{
	long ret;
	asm
	(
		"syscall"
	    	: "=a"(ret)
		: "a"(type), "D"(a1), "S"(a2), "d"(a3)
		: "memory"
	);
	return ret;
}
*/

//exit is special as it doesnt return
void exit(int status)
{
	_syscall1(__NR_exit,(long)status);
}

long nanosleep(const struct timespec* a, struct timespec* b)
{
	return _syscall2(__NR_nanosleep,(long)a,(long)b);
}

long write(long fd, const void* buffer, long length)
{
	return _syscall3(__NR_write, (long)fd, (long)buffer, length);
}

long read(long fd, void* buffer, long length)
{
	return _syscall3(__NR_read, (long)fd, (long)buffer, length);
}

//void* mmap(void* addr, long length, int prot, int flags, int fd, long offset)
//{
//	return (void*)_asyscall6(__NR_mmap, (long)addr, length, (long)prot, (long)flags, (long)fd, offset);
//}

long open(const char* pathname, long flags, long mode)
{
	return _syscall3(__NR_open, (long)pathname, (long)flags, (long)mode);
}

long close(long file_descriptor)
{
	return _syscall1(__NR_close, (long)file_descriptor);
}

long socket(long domain, long type, long protocol)
{
	return _syscall3(__NR_socket,domain,type,protocol);
}

long bind(long sockfd, struct sockaddr* my_addr, long addr_len)
{
	return _syscall3(__NR_bind,sockfd,(long)my_addr,addr_len);
}

long listen(long sockfd, long backlog)
{
	return _syscall2(__NR_listen,sockfd,backlog);
}

long accept(long sockfd, struct sockaddr* addr, long* addrlen)
{
	return _syscall3(__NR_accept,sockfd,(long)addr,(long)addrlen);
}
(int, void __user *, size_t, unsigned,                                struct sockaddr __user *, int);
long sendto(long sockfd, const void* msg, size_t len, long flags)
{
	return _syscall4(sockfd, (long)msg, len, flags, __NR_send);
}

long recv(long sockfd, void* buf, long len, long flags)
{
	return 0;
}

//int munmap(void* addr, long length)
//{
//	return 0;//_(int)asyscall2(__NR_munmap,(long)addr,length);
//}

