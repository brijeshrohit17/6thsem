%{
    #include<stdio.h>
    #include<stdlib.h>
    int count = 0;
    int yylex();
    int yyerror(char *);
%}

%token IF RELATIONAL_OP S NUMBER ID NL

%%
start: if_stmt NL { printf("Number of nested 'if' statements is :%d\n", count);exit(0);};
if_stmt : IF '(' cond ')' '{' if_stmt '}' {count++;}
        | IF '(' cond ')' if_stmt {count++;}
        | S
        ;
cond : x RELATIONAL_OP x;
x : ID | NUMBER;
%%

int yyerror(char* s) 
{
    printf("%s\n", s);
    exit(1);
}
int main() 
{
    printf("Enter statement: \n");
    yyparse();
    return 0;
}
