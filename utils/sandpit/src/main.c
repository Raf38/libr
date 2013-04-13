#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <sys/socket.h>
#include <fcntl.h>

int main(int argc, char** argv, char** env)
{
	printf("#define SOCK_STREAM %u\n",SOCK_STREAM);
	return 0;
}
