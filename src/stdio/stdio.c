#include "string.h"
#include "syscall.h"
#include "stdio.h"

void print(const char* string)
{
	long len = strlen(string);
	write(STDOUT,string,len);
}

