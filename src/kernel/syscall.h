#ifndef __LIBR_SYSCALL
#define __LIBR_SYSCALL

#include "time.h"

long asyscall6  (long a, long b, long c, long d, long e, long f);
void  exit      (int status);
long  nanosleep (const struct timespec* req, struct timespec* rem);
long  write     (int fd, const void* buffer, long length);
//void* mmap      (void* addr, long length, int prot, int flags, int fd, long offset);
//int   munmap    (void* addr, long length);

#endif
