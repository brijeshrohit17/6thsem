//U19CS009
//Brijesh Rohit

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
	char s[20], c;
	int i = 0;
	printf("We have following grammar rules :");
	printf("\n1 : 'a'");
	printf("\n2 : 'abb'");
	printf("\n3 : 'a*b+'\n");
	printf("Enter a string : ");
	int n = scanf("%[^\n]s", s);
	if (n != 1)
	{
		printf("You didn't enterd any input!!\nHence it is recognized under 'a*' grammar.\n");
		return 0;
	}
	printf("Your input is ");
	if (strlen(s) == 3)
	{
		if (s[0] == 'a' && s[1] == 'b' && s[2] == 'b')
		{
			printf("recognized under 'abb' grammar.\n");
			return 0;
		}
	}
	int aflag = 0, bflag = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 'a')
		{
			if (bflag == 1)
			{
				printf("not recognized under any mentioned grammar!!\n");
				return 0;
			}
			aflag = 1;
		}
		else if(s[i] == 'b')
			bflag = 1;
		else
		{
			printf("not recognized under any mentioned grammar!!\n");
			return 0;
		}
	}
	if (aflag = 1 && bflag == 0)
		printf("recognized under 'a*' grammar.\n");
	else if (aflag >= 0 && bflag > 0)
		printf("recognized under 'a*b+' grammar.\n");
	else 
		printf("not recognized under any mentioned grammar!!\n");
	return 0;
}
