%{
    #include "y.tab.h"
    extern int yylval;
%}
%%
"if" {return IF;}
[sS][0-9]* {return S;}
"<"|">"|"=="|"<="|">="|"!=" {return RELATIONAL_OP;}
[0-9]+ {return NUMBER;}
[a-z][a-zA-Z0-9_]* {return ID;}
[\t ] ;
\n {return NL;}
. {return yytext[0];}
%%
