%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    int yyerror(char *);
%}

%token ID

%%
start: ID {printf("It is a valid Identifier!!\n");}
%%

int yyerror(char* s) 
{
    printf("Invalid Identifier\n");
}
int main() 
{
    printf("Enter statement: \n");
    yyparse();
    return 0;
}