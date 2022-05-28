#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	if (fork() == 0)
	{
		printf("\nParent process is called!!");
		printf("\nParent process pid : %d\n", getpid());
	}
	else
	{
		printf("\nChild process is called!!");
		printf("\nChild process pid : %d\n", getpid());
	}
	printf("\n");
	return 0;
}