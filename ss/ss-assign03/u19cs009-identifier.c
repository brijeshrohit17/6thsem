//u19cs009
/*Brijesh Rohit*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char keywords[32][10] = {
    "auto","case","char","continue","default","do","else","double",
    "const","enum","extern","float","for","goto","if","int","while",
    "break","long","register","return","short","signed","sizeof",
    "static","struct","switch","typedef","union","unsigned","void",
    "volatile"
};

bool isKeyword(char* str)
{
    for(int i = 0 ; i < 32 ; i++)
    {
        if(!strcmp(str,keywords[i]))
            return true;
    }
    return false;
}

bool isIdentifier(char* str)
{
    if (isKeyword(str)) 
        return false;

    if (!isalpha(str[0]) && str[0] != '_') 
        return false;

    for (int i = 1; i < strlen(str); i++)
    {
        if (!isalnum(str[i])) 
            return false;
    }
    return true;
}

int main()
{
    char str[100];
    printf("Enter the string : ");
    scanf("%s", str);
    if (isIdentifier(str))
    {
        printf("Given string is a Valid Identifier!!!\n");
    }
    else {
        printf("Given string is an Invalid identifier!!!\n");
    }
    return 0;
}