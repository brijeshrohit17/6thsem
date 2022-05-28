%{
#include<stdio.h>

int yylex();
void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }
int flag=0;
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%left '(' ')'

1%%
ArithmeticExpression: E{
			printf("Result: %d\n\n",$$);
			return 0;
			};

E : E '+' E {$$=$1+$3;}
	| E '-' E {$$=$1-$3;}
	| E '/' E {$$=$1/$3;}
	| E '*' E {$$=$1*$3;}
	| '(' E ')' {$$=$2;}
	| NUMBER {$$=$1;}
	;
%%

void main()
{
	printf("\nEnter the Arithmatic Expression : ");
	yyparse();
}
