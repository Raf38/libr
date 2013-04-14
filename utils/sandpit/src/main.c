#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <sys/socket.h>
#include <fcntl.h>

int main(int argc, char** argv, char** env)
{
	int n = send(1,"abc",3,4);
	printf("#define SOCK_STREAM %u\n",SOCK_STREAM);
	return 0;
}
