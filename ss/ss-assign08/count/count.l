%{
    #include<stdio.h>
    int countLine = 0, countWords = 0, countChars = 0;
%}

%%
\n {countLine++;}
[^ \n\t]+ {countWords++, countChars+=yyleng-1;} 
. {countChars++;} 
%%

int yywrap(void){}

int main(int argc, char*argv[])
{
	yyin=fopen(argv[1],"r");
	yylex();
	
	printf("Number of lines : %d\n", countLine);
	printf("Number of words : %d\n", countWords);
	printf("Number of chars : %d\n", countChars);
}
