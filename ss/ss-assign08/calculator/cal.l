%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    char op;
    float num1=0, num2=0;
    int flag = 0, flag1 = 0;
%}

%%

([0-9])+ {if(flag==0) {num1=atoi(yytext);}else{num2=atoi(yytext);}};
([0-9])*[.]([0-9])* {if(flag==0) {num1=atof(yytext);}else{num2=atof(yytext);}};
([/*+-]) {op=yytext[0];flag=1;};
\n {flag=0;if(op=='+')printf("Answer: %f\n",num1+num2); else if(op=='-')printf("Answer: %f\n",num1-num2); else if(op=='*')printf("Answer: %f\n",num1*num2);else if(num2 ==0)printf("Division with 0 is invalid\n"); else if(op=='/')printf("Answer: %f\n",num1/num2);};
. {};

%%

int main()
{
    yylex();
    return 0;
}