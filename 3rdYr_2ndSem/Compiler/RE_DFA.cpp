#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


//Function to return precedence of operators 
int precedence(char c) 
{ 
    if(c == '*') 
    return 3; 
    else if(c == '&') 
    return 2; 
    else if(c == '|') 
    return 1; 
    else
    return -1; 
}


// Convert Infix to Postfix
string infixToPostfix(string infix) 
{ 
    stack<char> conversion_stack; 
    conversion_stack.push('N'); 
    int l = infix.length(); 
    string postfix; 
    for(int i = 0; i < l; i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if((infix[i] >= 'a' && infix[i] <= 'z')||(infix[i] >= 'A' && infix[i] <= 'Z')) 
        postfix+=infix[i]; 
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(infix[i] == '(') 
          
        conversion_stack.push('('); 
          
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(infix[i] == ')') 
        { 
            while(conversion_stack.top() != 'N' && conversion_stack.top() != '(') 
            { 
                char c = conversion_stack.top(); 
             	conversion_stack.pop(); 
            	postfix += c; 
            } 
            if(conversion_stack.top() == '(') 
            { 
                char c = conversion_stack.top(); 
                conversion_stack.pop(); 
            } 
        } 
          
        //If an operator is scanned 
        else
        { 
            while(conversion_stack.top() != 'N' && precedence(infix[i]) <= precedence(conversion_stack.top())) 
            { 
                char c = conversion_stack.top(); 
                conversion_stack.pop(); 
                postfix += c; 
            } 
            conversion_stack.push(infix[i]); 
        } 
  
    } 
    //Pop all the remaining elements from the stack 
    while(conversion_stack.top() != 'N') 
    { 
        char c = conversion_stack.top(); 
        conversion_stack.pop(); 
        postfix += c; 
    } 
    return postfix;
}

struct Node
{
	int id;							// Unique id for the node
	char name;						// Name 
	int type;						// Leaf node or not
	Node* left, right, parent;      // Pointer to other nodes
	vector<int> firstpos, lastpos;  // Firstpos and Lastpos are stored here
};

class Tree
{
	private:
			vector<Node*> nodeList;
			stack<Node*> nodeStack;
	public:
			void addNode(char ch)
			{
				
			}
};

int main()
{
	string infix = "z&(a|b)*&y";
	string postfix = infixToPostfix(infix);
	cout<<postfix<<endl;
	return 0;
}