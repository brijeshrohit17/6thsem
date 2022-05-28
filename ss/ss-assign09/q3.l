%{
    #include<stdio.h>
    int scount=0 ,mcount=0;
%}

%%

[/][/]([a-zA-Z0-9 \t])*[\n] {fprintf(yyout,"\nSingle line Comment :\n%s",yytext);scount++;};
[/][*]([a-zA-Z0-9 \t\n])*[*][/] {fprintf(yyout,"\nMultiline Comment :\n%s",yytext);mcount++;};
end {fprintf(yyout,"\nSingle line comment count : %d\nMultiple Line comment count : %d",scount,mcount);};

%%

int main()
{
    extern FILE * yyin,*yyout;
    yyin=fopen("input.txt","r");
    yyout=fopen("output.txt","w");
    yylex();
    return 0;
}