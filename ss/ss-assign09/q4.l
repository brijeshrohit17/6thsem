%{
    #include<stdio.h>
    int nn=0,pn=0,zn=0;
%}

%%

[-][1-9]([0-9])* {nn++;};
[+][1-9]([0-9])* {pn++;};
[1-9]([0-9])* {pn++;};
([0])+ {zn++;};

%%

int main()
{
    yylex();
    printf("\nNumber of Positive Numbers: %d",pn);
    printf("\nNumber of Negative Numbers: %d",nn);
    printf("\nNumber of Zero Numbers: %d\n",zn);
    return 0;
}