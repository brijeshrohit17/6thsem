/*lex : c program -> count number of printf and scanf lines*/
/*printf by writef -> scanf by readf*/

%{
    #include <stdio.h>
    int countprintf = 0;
    int countscanf = 0;
    char ch;
%}

%%

([p][r][i][n][t][f])+ {fprintf(yyout, ("%s", "writef"), yytext); countprintf++;}
([s][c][a][n][f])+ {fprintf(yyout, ("%s", "readf"), yytext); countscanf++;}
([for][ ][(][a-zA-Z0-9=]*[;][a-zA-Z0-9<>!=][;][[a-zA-Z0-9+]])
%%

int yywrap() {};

int main()
{
    extern FILE *yyin, *yyout;
    yyin = fopen("input.c", "r");
    yyout = fopen("output.c", "w");
    yylex();
    printf("Number of printf lines  : %d\n", countprintf);
    printf("Number of scanf linrs   : %d\n", countscanf);
    return 0;
}