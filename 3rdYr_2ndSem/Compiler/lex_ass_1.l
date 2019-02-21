%{
#include <stdio.h>
#include <stdlib.h>

int charCount=0, wordCount=0, lineCount=0, numberCount=0, 
integerCount=0, floatCount=0, unknownCount=0;
%}

%%


\n 		{lineCount++; wordCount++;}
[\t '] 	{wordCount++;}
[a-zA-Z] 		{charCount++;}
[0-9]+ 		{integerCount++;numberCount+=yyleng;}
[0-9]+"."[0-9]+ {floatCount++;numberCount+=yyleng-1;}
. {unknownCount++;}

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
	printf("\n");
	printf("Character Count      : %d\n", charCount);
	printf("Word Count 	     : %d\n", wordCount);
	printf("Line Count 	     : %d\n", lineCount);
	printf("Number Count  	     : %d\n", numberCount);
	printf("Integer Count 	     : %d\n", integerCount);
	printf("Floating-point Count : %d\n", floatCount);
	printf("Unknown Count        : %d\n", unknownCount);
	return 0;
}
