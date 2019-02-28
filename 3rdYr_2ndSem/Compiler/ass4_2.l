%{
#include"y.tab.c"
extern yylval;
%}


%%
[0-9]+ {yylval=atoi(yytext); return NUMBER;}   
[a-zA-Z]+ {return ID;}                                         
[\t]+ ;
\n {return 0;}
. {return yytext[0];}
%%
