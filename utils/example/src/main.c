#include "stdio.h"
#include "stdlib.h"

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
	return 0;
}
