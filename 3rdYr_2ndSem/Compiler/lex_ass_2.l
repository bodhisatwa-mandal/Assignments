%{
#include <stdio.h>
#include <stdlib.h>

int row=0, col=0;
%}

%%

\n 		{col++, row=0;}
[ ] 	{row++;}
"else"|"if"|"for"|"int"|"float"|"void"|"return" {printf("%s\tKeyword\t%d\t%d\n", yytext, row, col);row+=yyleng;}
"+"|"-"|"*"|"/"|"<"|">"|"="|";"|","|"("|")"|"{"|"}" {printf("%s\tSpecial\t%d\t%d\n", yytext, row, col);row+=yyleng;}
[0-9]+ {printf("%s\tNUM\t%d\t%d\n", yytext, row, col);row+=yyleng;}
[a-zA-Z0-9]+ {printf("%s\tID\t%d\t%d\n", yytext, row, col);row+=yyleng;}
. {row++;}

%%

int main(int argc, char* argv[])
{

	if (argc > 1)
	{
	    FILE *file;
	    file = fopen(argv[1], "r");
	    if (!file)
	    {
	        fprintf(stderr, "Could not open %s\n", argv[1]);
	        exit(1);
	    }
	    yyin = file;
	}

	yylex();
	/*
	printf("\n");
	printf("Character Count      : %d\n", charCount);
	printf("Word Count 	     : %d\n", wordCount);
	printf("Line Count 	     : %d\n", lineCount);
	printf("Number Count  	     : %d\n", numberCount);
	printf("Integer Count 	     : %d\n", integerCount);
	printf("Floating-point Count : %d\n", floatCount);
	printf("Unknown Count        : %d\n", unknownCount);
	*/
	return 0;
}
