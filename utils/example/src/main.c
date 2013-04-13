#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "syscall.h"
#include "socket.h"
#include <linux/net.h>
#include <linux/socket.h>

int main(int argc, char** argv, char** env)
{
	print("Hello Brave New World\n");
	print("Here are your arguments:\n");
	long n=0;
	for(n=0;n<argc;n++)
	{
		print(argv[n]);
		print("\n");
		sleep(1);
	}
	if (argc > 1)
	{	
		return atoi(argv[1]);
	}
	print("Socket\n");
	int sock = socket(PF_INET,SOCK_STREAM,0);



	struct sockaddr_in my_addr;
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = 0x6666;     // short, network byte order
	my_addr.sin_addr.s_addr = 0;
	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);

	bind(sock, (struct sockaddr *)&my_addr, sizeof my_addr);
	listen(sock,1);
	sleep(100);
	print("Writing file\n");
	int fd = open("/tmp/abc.txt",O_RDWR|O_CREAT,0644);
	const char buffer[] = "messgae";
	write(fd,buffer,strlen(buffer));
	close(fd);
	return 0;
}
