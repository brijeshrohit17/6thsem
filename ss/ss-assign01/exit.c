#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	printf("\nAfter calling exit(), nothing will be printed.");
	printf("\nInvoking exit() now.\n\n");
	exit(0);
	printf("not printing because of exit()");
	return 0;
}