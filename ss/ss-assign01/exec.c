#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	//EXEC
	printf("\n\nI'm the new process!!\nI'm also called \"CALLED\" process.");
	printf("\nI replaced the current process!!");
	printf("\nMy process pid is : %d", getpid());
	printf("\n\n");
	return 0;
}