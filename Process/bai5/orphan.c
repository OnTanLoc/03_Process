#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
	int ret_var = fork();
	if(ret_var == 0)//children process
	{
		printf("children PID: %d\n",getpid());
		printf("parent PID: %d\n",getppid());
		printf("children process become orphan in 10s\n");
		sleep(10);
	}
	else if(ret_var >0)//parent process
	{
		exit(0);//exit parent process
	}

}
