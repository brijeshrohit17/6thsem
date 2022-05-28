//u19cs009
/*Brijesh Roghit*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void parseString(char *str)
{
    int i = 0, j = 0;
    while (str[i] == ' ')
    {
        i++;
    }
    while (i < strlen(str))
    {
        str[j] = str[i];
        i++;
        j++;
    }
    str[j] = '\0';
    j = strlen(str) - 1;
    while (str[j] == ' ')
    {
        j--;
    }
    str[j + 1] = '\0';
}
bool singlelinecomment(char* str, int s)
{
    while (str[s] == ' ') s++;
    int l = strlen(str) - s;
    if (l < 2) return false;
    if (str[s] != '/' || str[s + 1] != '/') return false;
    return true;
}
bool multilinecomment(char* str, int s)
{
    while (str[s] == ' ') s++;
    int l = strlen(str) - s;
    if (l < 4) return false;


    if (str[s] != '/' || str[s + 1] != '*') return false;
    int end = -1;
    for (int i = s + 2; i < strlen(str) - 1; i++)
    {
        if (str[i] == '*' && str[i + 1] == '/')
        {
            end = i + 1;
            break;
        }
    }
    if (end == -1) return false;
    if (end != strlen(str) - 1) return singlelinecomment(str, end + 1) || multilinecomment(str, end + 1);
    return true;
}
int main()
{
    char string[100];
    printf("Enter the string : ");
    scanf("%[^\n]s", string);
    parseString(string);

    if (singlelinecomment(string, 0))
    {
        printf("String is single line comment!!!\n");
    }
    else if (multilinecomment(string, 0))
    {
        printf("String is multiline comment!!!\n");
    }
    else
    {
        printf("String is not a comment!!!\n");
    }
    return 0;
}