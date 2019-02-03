#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// delimiter, identifier, keyword, operator, constant, literal

int isSpaceNewLine(char ch)
{
  if(ch==' ' || ch=='\n' || ch=='\t')
    return 1;
  return 0;
}

int isDelimiter(char ch) 
{ 
    if (ch == ',' || ch == ';' || ch == '"' || ch == '\'') 
        return 1; 
    return 0; 
} 

int isBracket(char ch)
{
  if(ch == '(' || ch == ')' ||  
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
    return 1;
  return 0;
}

int isKeyword(char* str) 
{ 
    if (!strcmp(str, "if") || !strcmp(str, "else") || 
        !strcmp(str, "while") || !strcmp(str, "do") ||  
        !strcmp(str, "break") ||  
         !strcmp(str, "continue") || !strcmp(str, "int") 
        || !strcmp(str, "double") || !strcmp(str, "float") 
        || !strcmp(str, "return") || !strcmp(str, "char") 
        || !strcmp(str, "case") || !strcmp(str, "char") 
        || !strcmp(str, "sizeof") || !strcmp(str, "long") 
        || !strcmp(str, "short") || !strcmp(str, "typedef") 
        || !strcmp(str, "switch") || !strcmp(str, "unsigned") 
        || !strcmp(str, "void") || !strcmp(str, "static") 
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return 1; 
    return 0; 
}

// Returns 'true' if the string is an INTEGER. 
int isConstant(char* str) 
{ 
    int i, len = strlen(str); 
  
    if (len == 0) 
        return (false); 
    for (i = 0; i < len; i++) { 
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0)) 
            return 0; 
    } 
    return 1; 
} 

int isOperator(char* str)
{
  if (!strcmp(str, "+") || !strcmp(str, "-") || 
        !strcmp(str, "*") || !strcmp(str, "/") ||  
        !strcmp(str, ">") ||  
         !strcmp(str, "<") || !strcmp(str, "=") 
        || !strcmp(str, "<<") || !strcmp(str, ">>") 
        || !strcmp(str, ">>>") || !strcmp(str, "?") 
        || !strcmp(str, "|") || !strcmp(str, "||") 
        || !strcmp(str, "&&") || !strcmp(str, "&") 
        || !strcmp(str, "->") || !strcmp(str, ":"))
        return 1; 
    return 0; 
}

int isOperatorSingle(char ch)
{
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
      ch == '>' || ch == '<' || ch == '=' || ch == '?' ||
      ch == '|' || ch == '&' || ch == ':') 
        return 1; 
    return 0; 
}

int isNumber(char ch)
{
  if (ch == '0' || ch == '1' || ch == '2' ||  
      ch == '3' || ch == '4' || ch == '5' || 
      ch == '6' || ch == '7' || ch == '8' ||
      ch == '9') 
        return 1; 
    return 0; 
}

int main()
{
  int column=0, row=0;
  char ch,c, file_name[25] = "test.c";
  char buffer[100];
  FILE *fp;
  int is_literal=0,buffer_len=0;
  
  fp = fopen(file_name, "r"); // read mode
 
  if (fp == NULL)
  {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }
   
  while((ch = fgetc(fp)) != EOF)
  {

    // includes and defines are ignored
    if(ch == '#')
    {
      while((c = fgetc(fp)) != '\n');
      row++;
    }

    // space or newline are not tokens
    else if(isSpaceNewLine(ch))
    {
      if(is_literal)
      {
        buffer[buffer_len++] = ch;
        buffer[buffer_len] = '\0';
      }

      else if(isKeyword(buffer))
      {
        printf("Keyword,%s,%d,%d\n",buffer,column-strlen(buffer),row);
        buffer_len = 0;
        buffer[0] = '\0';
      }

      else if(isConstant(buffer))
      {
        printf("Constant,%s,%d,%d\n",buffer,column-strlen(buffer),row);
        buffer_len = 0;
        buffer[0] = '\0';
      }

      else if(isOperator(buffer))
      {
        printf("Operator,%s,%d,%d\n",buffer,column-strlen(buffer),row);
        buffer_len = 0;
        buffer[0] = '\0';
      }

      else
      {
        if(buffer_len>0)
          printf("Identifier,%s,%d,%d\n",buffer, column-strlen(buffer), row);
        buffer_len = 0;
        buffer[0] = '\0';
      }

      column++;
      if(ch == '\n')
      {
        column=0;
        row++;
      }
    }

    //Delimiter Encountered
    else if(isDelimiter(ch))
    {

      if(ch == '"' || ch == '\'')
      {
        if(is_literal == 0)
          is_literal = 1;
        else
        {
          printf("Literal,%s,%d,%d\n",buffer,column-strlen(buffer),row);
          buffer_len = 0;
          is_literal = 0;
          buffer[0] = '\0';
        }
      }

      else if(is_literal)
      {
        buffer[buffer_len++]=ch;
        buffer[buffer_len]='\0';
      }

      else if(isKeyword(buffer))
      {
        printf("Keyword,%s,%d,%d\n",buffer,column-strlen(buffer),row);
        buffer_len = 0;
        buffer[0] = '\0';
      }

      else if(isConstant(buffer))
      {
        printf("Constant,%s,%d,%d\n",buffer,column-strlen(buffer),row);
        buffer_len = 0;
        buffer[0] = '\0';
      }

      else if(isOperator(buffer))
      {
        printf("Operator,%s,%d,%d\n",buffer,column-strlen(buffer),row);
        buffer_len = 0;
        buffer[0] = '\0';
      }

      printf("Delimiter,%c,%d,%d\n",ch,column,row);
      column++;
    }

    else if(isBracket(ch))
    {
      if(is_literal)
      {
        buffer[buffer_len++]=ch;
        buffer[buffer_len] = '\0';
      }

      else if(isKeyword(buffer))
      {
        printf("Keyword,%s,%d,%d\n",buffer,column-strlen(buffer),row);
        buffer_len = 0;
        buffer[0] = '\0';
      }

      else if(isConstant(buffer))
      {
        printf("Constant,%s,%d,%d\n",buffer,column-strlen(buffer),row);
        buffer_len = 0;
        buffer[0] = '\0';
      }

      else if(isOperator(buffer))
      {
        printf("Operator,%s,%d,%d\n",buffer,column-strlen(buffer),row);
        buffer_len = 0;
        buffer[0] = '\0';
      }

      else
      {
        if(buffer_len>0)
          printf("Identifier,%s,%d,%d\n",buffer, column-strlen(buffer), row);
        buffer_len = 0;
        buffer[0] = '\0';
      }

      printf("Delimiter,%c,%d,%d\n",ch,column,row);
      column++;
    }

    else if(isOperatorSingle(ch))
    {
      if(is_literal)
      {
        buffer[buffer_len++]=ch;
        buffer[buffer_len]='\0';
      }

      else if(isConstant(buffer))
      {
        printf("Constant,%s,%d,%d\n",buffer,column-strlen(buffer),row);
        buffer_len = 0;
        buffer[0] = '\0';
        buffer[buffer_len++] = ch;
        buffer[buffer_len] = '\0';
      }

      else if(buffer_len!=0 && !isOperatorSingle(buffer[buffer_len-1]))
      {
        printf("Identifier,%s,%d,%d\n",buffer, column-strlen(buffer), row);
        buffer_len = 0;
        buffer[0] = '\0';
        buffer[buffer_len++] = ch;
        buffer[buffer_len] = '\0';
      }

      else
      {
        buffer[buffer_len++]=ch;
        buffer[buffer_len]='\0';
      }
      column++;
    }

    else if(isNumber(ch))
    {

      if(is_literal)
      {
        buffer[buffer_len++]=ch;
        buffer[buffer_len]='\0';
      }
      else if(isOperator(buffer))
      {
        printf("Operator,%s,%d,%d\n",buffer,column-strlen(buffer),row);
        buffer_len = 0;
        buffer[0] = '\0';
        buffer[buffer_len++]=ch;
        buffer[buffer_len]='\0';
      }

      else
      {
        buffer[buffer_len++]=ch;
        buffer[buffer_len]='\0';
      }
      column++;
    }

    else
    {
      if(buffer_len!=0 && isOperatorSingle(buffer[buffer_len-1]))
      {
        printf("Identifier,%s,%d,%d\n",buffer, column-strlen(buffer), row);
        buffer_len = 0;
        buffer[0] = '\0';
      }
      buffer[buffer_len++]=ch;
      buffer[buffer_len]='\0';
      column++;
    }
  }
     
  fclose(fp);
  return 0;
}

