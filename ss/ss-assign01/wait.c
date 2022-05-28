#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
	int cpid;
	if (fork()== 0)
	{
		printf("\nHello from child!!");
		printf("\nChild process pid : %d", getpid());
	}
    else
    {
        printf("\nHello from parent!!");
        printf("\nParent process pid : %d", getpid());
        wait(NULL);
        printf("\nChild is terminated");
    }
 
    printf("\nBye!!");
    printf("\n\n");
	return 0;
}