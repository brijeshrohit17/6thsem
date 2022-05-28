#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	printf("\nI'm the process which will call new process.");
	printf("\nI'm also called \"CALLING\" process.");
	//EXEC
	char *args[] = {"./exec", NULL};
	execvp(args[0], args);
	printf("\nAfter calling, I'm running a print statement.");
	printf("\nWhich will not be printed.\n");
	return 0;
}