#include "syscall.h"
#include <linux/errno.h>

long atoi(const char *data)
{
	long result = 0;
	while (*data >= '0' && *data <= '9')
	{
		result *= 10;
		result += *data-'0';
		data++;
	}
	return result;
}

long sleep(long seconds)
{
	struct timespec req;
	req.tv_sec = seconds;
	req.tv_nsec = 0;
	struct timespec rem;
	long ret = nanosleep(&req,&rem);
	if (ret == -EINTR)
	{
		if (rem.tv_nsec)
		{
			rem.tv_sec++;
		}
		return rem.tv_sec;
	}
	return ret;
}

