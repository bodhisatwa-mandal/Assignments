#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;
 
map<string, char> TokenMap;
map<string, char> nonTokenMap;
 
void createTokenMap(vector<string>& tokens)
{
  char mappedChar = 'a';
  string token;
  for (unsigned i=0; i < tokens.size(); i++)
  {
    token = tokens[i];
    TokenMap.insert(pair<string, char>(token, mappedChar));
    mappedChar = mappedChar + 1;
  }
  /*
  cout << "\n";
  for(map<string, char>::const_iterator it = TokenMap.begin();
      it != TokenMap.end(); ++it)
  {
    std::cout << it->first << " " << it->second << "\n";
  }
  */
}

void createNonTokenMap(vector<string> lines)
{
    char mappedChar = 'A';
    string non_term;
    for(int i=0; i<lines.size(); i++)
    {
    	non_term=lines[i].substr(0,lines[i].find(" "));
    	if(nonTokenMap.find(non_term)==nonTokenMap.end())
 	       nonTokenMap.insert(pair<string,char>(non_term,mappedChar++));
    }
}


//map EPS
 
void readGrammar(string fileName, vector<string>& items)
{
  string line;
  std::ifstream infile(fileName);
  for( std::string line; getline( infile, line ); )
  {
    items.push_back(line);
    cout << line << "\n";
  }
}
 
void mapProductionToNew()
{
        
}

void printNonTokens()
{
cout << "\n";
   for(map<string, char>::const_iterator it = nonTokenMap.begin();
       it != nonTokenMap.end(); ++it)
   {
     std::cout << it->first << " " << it->second << "\n";
   }

}

int main()
{
  vector<string> lines, tokens;
  readGrammar("SampleGrammar.txt", lines);
  readGrammar("Tokens.txt", tokens);
  cout << tokens.size();
  createTokenMap(tokens);
  createNonTokenMap(lines); 
  printNonTokens();
  return 0;
}
