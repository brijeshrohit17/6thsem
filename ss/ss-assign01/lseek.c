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
	printf("\n");
	int n, f;
	char buff[6];
	f = open("input.txt",O_RDWR);
	while(read(f,buff,6))
	{
		read(f,buff,6);
		write(1,buff,6);
		lseek(f,5,SEEK_CUR);
		read(f,buff,6);
		write(1,buff,6);
	}
	printf("\n");
	return 0;
}