#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
    int ReturnValue = fork();

    if(ReturnValue == 0)//process chilren
	{
		printf("my PID is: %d\n",getpid());
	}

    else if(ReturnValue > 0)//process parent
	{
		printf("children PID is: %d\n",ReturnValue);
	}

    else
	{
		printf("Error");
	}
}
