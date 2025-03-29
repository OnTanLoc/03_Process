#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler(int sig)//register signal handler
{
	printf("process children received SIGUSR1\n");
	exit(0);
}


void main()
{
	int return_var;

	return_var = fork();

	if(return_var == 0) //process children
	{
		if(signal(SIGUSR1, sig_handler) == SIG_ERR)
		{
			fprintf(stderr,"signal receiveved\n");
			exit(EXIT_FAILURE);
		}

		exit(0);
	}
	else if(return_var > 0) //process parrent
	{
		printf("parrent process send SIGUSR1 after 2s\n");
		printf("PID process childen: %d\n",return_var);
		sleep(2);
		if(kill(return_var, SIGUSR1) < 0)//send SIGUSR1 to children
			{
				printf("error");
			}
	}

}
