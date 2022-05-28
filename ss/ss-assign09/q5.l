%{
    #include<stdio.h>
%}

%%

aa([a-zA-Z])*bcd {fprintf(yyout,"%s : Accepted",yytext);};
([a-zA-Z])+ {fprintf(yyout,"%s : Declined",yytext);};

%%

int main()
{
    extern FILE * yyin,*yyout;
    yyin=fopen("input.txt","r");
    yyout=fopen("output.txt","w");
    yylex();
    return 0;
}