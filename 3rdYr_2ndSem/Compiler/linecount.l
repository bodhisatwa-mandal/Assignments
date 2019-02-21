%{
int charcount=0,linecount=0;
%}

%%

. charcount++
\n {linecount++;charcount++}

%%

int main()
{
	yylex();
	printf("Character count : %d\n", charcount);
	printf("Line count : %d\n", linecount);
	return 0;
}
