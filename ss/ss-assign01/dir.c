#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

int main()
{
	struct dirent *dir;
	DIR* d = opendir(".");
	//READDIR
	while ((dir = readdir(d)) != NULL)
		printf("%s\n", dir->d_name);

	char s1[100];

	printf("\nCurrent path : %s\n", getcwd(s1, 50)); //CHDIR
	chdir("..");
	
	printf("New path after using chdir : %s\n", getcwd(s1, 50)); //READDIR
	while ((dir = readdir(d)) != NULL)
		printf("%s\n", dir->d_name);
	
	//CLOSEDIR
	closedir(d);
	printf("\n\n");
	exit(EXIT_SUCCESS);
	return 0;
}