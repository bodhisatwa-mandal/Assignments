%{
#include<stdio.h>
%}


%token NUMBER ID
%left '+' '-' 
%left '*' '/'
%%

expr: expr '+' expr 
     |expr '-' expr
     |expr '*' expr
     |expr '/' expr
     |'-'NUMBER
     |'-'ID
     |'('expr')'
     |NUMBER
     |ID
     ;
%% 

int yyerror(char *s)
{
printf("Expression is Invalid\n");
exit(0);
}

main()
{
printf("Enter Expression: ");
yyparse();
printf("Expression is Valid\n");
exit(0);
}
