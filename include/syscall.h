#ifndef __LIBR_SYSCALL
#define __LIBR_SYSCALL

#include <linux/socket.h>
#include <linux/time.h>
#include <linux/fcntl.h>

#long asyscall6 (long a, long b, long c, long d, long e, long f);
void exit      (int status);
long nanosleep (const struct timespec* req, struct timespec* rem);
long write     (long fd, const void* buffer, long length);
long read      (long fd, void* buffer, long length);
long open      (const char* pathname, long flags, long mode);
long close     (long file_descriptor);
long socket    (long domain, long type, long protocol);
long bind      (long sockfd, struct sockaddr* my_addr, long addr_len);
long listen    (long sockfd, long backlog);
//void* mmap      (void* addr, long length, int prot, int flags, int fd, long offset);
//int   munmap    (void* addr, long length);

#endif
