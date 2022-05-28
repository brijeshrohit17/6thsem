#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	printf("\nAfter how many process do you want to kill ?");
    printf("\nEnter you number : ");
    int n;
    scanf("%d",&n);
    printf("\nEven after entering a number greater than 15, it won't work more than 15 times!.");
    
    pid_t retVal;
    retVal = fork();
    if(retVal > 0)
    {
        int i = 0;
        while(i++ < n)
        {
            printf("\nIn the parent process.(%d)",i);
            sleep(1);
        }
        //kill the child process
        kill(retVal, SIGKILL);

    } 
    else if (retVal == 0)
    {
        int i = 0;
        //will not ever get to 15, because
        //the parent process will kill it
        while(i++ < 15)
        {
            printf("\nIn the child process.(%d)", i);
            sleep(1);
        }
    } 
    else 
    {
        //something bad happened.
        printf("\nSomething bad happened.");
        exit(EXIT_FAILURE);
    }
    printf("\n\n");
    return 0;

}