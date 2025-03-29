#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void main(int argc,char *argv[])
{
	if(strcmp(argv[1],"1") == 0)
	{
		execlp("ls","ls",NULL);	
	}
	else if(strcmp(argv[1],"2")==0)
	{
		execlp("date","date",NULL);
	}
	else
	{
		printf("nhap lai gia tri 1 hoac 2\n");
	}
}

