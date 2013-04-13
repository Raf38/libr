#include "../../include/string.h"

long strlen(const char* string)
{
	long length = 0;
	while(string[0])
	{
		string++;
		length++;
	}
	return length;
}

void* memset ( void* ptr, int value, size_t num )
{
	size_t n = num;
	char* cPtr = (char*)ptr;
	for(n = num;n>0;n--)
	{
		cPtr[n] = value;
	}
	return ptr;
}

