#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main()
	{
		pid_t ret_var = fork();

		if(ret_var == 0)
		{
			printf("child PID: %d\n",getpid());
			printf("parent process use systemcall wait() after 10s\n");

			exit(0);//children process exit
		}
		else if(ret_var > 0)
		{
			sleep(10);//childen process become zombie in 10s
			int status;
			wait(&status);

		}
	}

