%{
    #include "y.tab.h"
    extern int yylval;
%}
%%

[a-zA-Z][a-zA-Z0-9]* {return ID;}
. {return yytext[0];}
%%
