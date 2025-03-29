#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
	//int ret_var;
	pid_t ret_var = fork();

	if(ret_var == 0)//children process
	{
		printf("process children exit\n");
		exit(10);//exit code	
	}
	else if(ret_var > 0)//parrent process
	{
		int status;
		wait(&status);//wait children process end
		
		if(WIFEXITED(status))
		{

			printf("children process exit nomally, exit code: %d\n",WEXITSTATUS(status));
		}

		else 
		{
			printf("children process exit abnomally, exit code: %d\n",WEXITSTATUS(status));
		}
	}
}
