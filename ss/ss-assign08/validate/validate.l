%{
    #include<stdio.h>
    int flag = 0;
%}

%%
[a-z.0-9_]+@[a-z]+".com"|".in"|".org" flag = 1;
[+91][1-9][0-9]* {if(yyleng == 13)flag = 1;}
%%
int yywrap(){}
int main()
{
    printf("Please enter your email/mobile number with initials : ");
    yylex();
    printf("\n");
    int flag1 = 1;
    if (flag == 1)
    {
        printf("Accepted\n");
        flag1 = 0;
    }
    if(flag1)
        printf("Invalid input\n");
    return 0;
}