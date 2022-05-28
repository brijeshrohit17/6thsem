#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

int main()
{
	int f;
	char buffer[100];
	//OPEN
	f = open("tp.txt", O_CREAT | O_WRONLY, 0600); 
	if (f == -1)
	{
		printf("Error opening the file");
		exit(1);
	}
	//WRITE CLOSE
	write(f, "Hi! This is sample added to file in c!\n", 39); 
	close(f);
	//READ
	f = open("tp.txt", O_RDONLY);
	if (f == -1)
	{
		printf("Error opening the file");
		exit(1);
	}
	read(f, buffer, 39);
	buffer[39] = '\0';
	close(f);
	printf("Buffer : %s", buffer);
	return 0;
}