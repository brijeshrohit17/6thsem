%{
    #include<stdio.h>
%}

%%

[0]([0-7])+ {fprintf(yyout,"%s : Octal Number\n",yytext);};
[0][x]([0-9a-fA-F])+ {fprintf(yyout,"%s : Hexadecimal Number\n",yytext);};
([0-9])+ {fprintf(yyout,"%s : Decimal Number\n",yytext);};

%%

int main()
{
    extern FILE * yyin,*yyout;
    yyin=fopen("input.txt","r");
    yyout=fopen("output.txt","w");
    yylex();
    return 0;
}