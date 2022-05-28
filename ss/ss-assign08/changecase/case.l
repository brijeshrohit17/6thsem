%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

%}

%%
[a-z] printf("%c",yytext[0] - ('a' - 'A'));
[A-Z] printf("%c",yytext[0] + ('a' - 'A'));
. printf("%c",yytext[0]);
%%

int yywrap(){}

int main(){
    printf("Enter string : ");
    yylex();
    printf("\n");
    return 0;
}