
import java.util.Stack;
import java.util.ArrayList;

class InfixtoPostfix
{
	// Function to return precedence of operators 
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

	// Function to convert infix expression to postfix
	String exp_convert(String infix)
	{
		Stack<Character> conversion_stack = new Stack<Character>();
		conversion_stack.push('$');
		int infix_length = infix.length();
		String postfix = "";
		char c;

		for(int infix_index = 0; infix_index < infix_length; infix_index++)
		{
			// If the scanned character is an operand, add it to output string. 
        	if((infix.charAt(infix_index) >= 'a' && infix.charAt(infix_index) <= 'z')||(infix.charAt(infix_index) >= 'A' && infix.charAt(infix_index) <= 'Z')||(infix.charAt(infix_index) == '#')) 
        		postfix+=infix.charAt(infix_index); 

        	// If the scanned character is an ‘(‘, push it to the stack. 
        	else if(infix.charAt(infix_index) == '(') 
          		conversion_stack.push('(');

          	// If the scanned character is an ‘)’, pop and to output string from the stack 
        	// until an ‘(‘ is encountered. 
        	else if(infix.charAt(infix_index) == ')') 
        	{ 
        	    while(conversion_stack.peek() != '$' && conversion_stack.peek() != '(') 
        	    { 
        	        c = conversion_stack.peek(); 
        	     	conversion_stack.pop(); 
        	    	postfix += c; 
        	    } 
        	    if(conversion_stack.peek() == '(') 
        	    { 
        	        c = conversion_stack.peek(); 
        	        conversion_stack.pop(); 
        	    } 
        	} 
          
        	//If an operator is scanned 
        	else
        	{ 
        	    while(conversion_stack.peek() != '$' && precedence(infix.charAt(infix_index)) <= precedence(conversion_stack.peek())) 
        	    { 
        	        c = conversion_stack.peek(); 
        	        conversion_stack.pop(); 
        	        postfix += c; 
        	    } 
        	    conversion_stack.push(infix.charAt(infix_index)); 
        	}
		}

		//Pop all the remaining elements from the stack 
    	while(conversion_stack.peek() != '$') 
    	{ 
    	    c = conversion_stack.peek(); 
    	    conversion_stack.pop(); 
    	    postfix += c; 
    	} 
    	return postfix;
	}
}

// Class defining Node data type
class Node
{
	char symbol;										// Symbol contained in the Node
	int id;												// Unique id of the Node
	boolean nullable;									// True is Node is nullable
	Node parent, first, second;							// Parent and Children of the Node
	ArrayList<Node> firstpos, lastpos;				// Firstpos and Lastpos of the Node

	Node()
	{
		firstpos  = new ArrayList<Node>();
		lastpos   = new ArrayList<Node>();
	}
}

class DFA_Transition
{
	ArrayList<Node> start_state;
	char transition;
	ArrayList<Node> final_state;
	DFA_Transition()
	{
		start_state = new ArrayList<Node>();
		transition = ' ';
		final_state = new ArrayList<Node>();
	}
}

// Class defining Syntax Tree data type
class SyntaxTree
{
	Node head;
	ArrayList<Node> nodes_list;
	ArrayList<ArrayList<Node>> followpos_table;
	int num_terminals;
	ArrayList<DFA_Transition> DTrans;
	ArratList<ArrayList<Node>> DStates;

	SyntaxTree()
	{
		nodes_list = new ArrayList<Node>();
		num_terminals = 0;
		followpos_table = new ArrayList<ArrayList<Node>>();
		DTrans = new ArrayList<DFA_Transition>();
	}

	// Function to create a Node and add it to tree
	// Will return the id of the newly created node
	Node addNode(char ch)
	{
		Node new_node = new Node();
		new_node.symbol = ch;
		new_node.id = nodes_list.size();
		new_node.nullable = ch=='*';
		nodes_list.add(new_node);
		return new_node;
	}

	// Function to build the Syntax Tree
	void make_tree(String postfix)
	{
		Stack<Node> stack = new Stack<Node>();
		int expression_length = postfix.length();
		char symbol;

		// Iterate over all symbols of the expression
		for(int postfix_index = 0; postfix_index < expression_length; postfix_index++)
		{
			symbol = postfix.charAt(postfix_index);

			if(symbol == '*')
			{
				Node new_node = addNode(symbol);
				Node popped_node = stack.pop();
				new_node.first = popped_node;
				popped_node.parent = new_node;
				for(int firstpos_index = 0; firstpos_index < popped_node.firstpos.size(); firstpos_index++)
					new_node.firstpos.add(popped_node.firstpos.get(firstpos_index));
				for(int lastpos_index = 0; lastpos_index < popped_node.lastpos.size(); lastpos_index++)
					new_node.lastpos.add(popped_node.lastpos.get(lastpos_index));
				stack.push(new_node);
				head = new_node;
			}
			else if(symbol == '|')
			{
				Node new_node = addNode(symbol);
				Node child_2 = stack.pop();
				Node child_1 = stack.pop();
				new_node.first = child_1;
				new_node.second = child_2;
				child_1.parent = new_node;
				child_2.parent = new_node;
				for(int firstpos_index = 0; firstpos_index < child_1.firstpos.size(); firstpos_index++)
					new_node.firstpos.add(child_1.firstpos.get(firstpos_index));
				for(int firstpos_index = 0; firstpos_index < child_2.firstpos.size(); firstpos_index++)
					new_node.firstpos.add(child_2.firstpos.get(firstpos_index));
				for(int lastpos_index = 0; lastpos_index < child_1.lastpos.size(); lastpos_index++)
					new_node.lastpos.add(child_1.lastpos.get(lastpos_index));
				for(int lastpos_index = 0; lastpos_index < child_2.lastpos.size(); lastpos_index++)
					new_node.lastpos.add(child_2.lastpos.get(lastpos_index));
				stack.push(new_node);
				head = new_node;
			}
			else if(symbol == '&')
			{
				Node new_node = addNode(symbol);
				Node child_2 = stack.pop();
				Node child_1 = stack.pop();
				new_node.first = child_1;
				new_node.second = child_2;
				child_1.parent = new_node;
				child_2.parent = new_node;
				for(int firstpos_index = 0; firstpos_index < child_1.firstpos.size(); firstpos_index++)
					new_node.firstpos.add(child_1.firstpos.get(firstpos_index));
				if(child_1.nullable)
					for(int firstpos_index = 0; firstpos_index < child_2.firstpos.size(); firstpos_index++)
						new_node.firstpos.add(child_2.firstpos.get(firstpos_index));
				if(child_2.nullable)
					for(int lastpos_index = 0; lastpos_index < child_1.lastpos.size(); lastpos_index++)
						new_node.lastpos.add(child_1.lastpos.get(lastpos_index));
				for(int lastpos_index = 0; lastpos_index < child_2.lastpos.size(); lastpos_index++)
					new_node.lastpos.add(child_2.lastpos.get(lastpos_index));
				stack.push(new_node);
				head = new_node;
			}
			else// if(isTerminal(symbol))
			{
				Node new_node = addNode(symbol);
				new_node.firstpos.add(new_node);
				new_node.lastpos.add(new_node);
				stack.push(new_node);
				num_terminals++;
				ArrayList<Node> temp = new ArrayList<Node>();
				temp.add(new_node);
				followpos_table.add(temp);
			}
		}
	}

	void make_followpos_table()
	{
		Node temp;
		for(int node_index = 0; node_index < nodes_list.size(); node_index++)
		{
			temp = nodes_list.get(node_index);
			if(temp.symbol == '&')
			{
				for(int c1_i=0; c1_i<temp.first.lastpos.size(); c1_i++)
					for(int c2_i=0; c2_i<temp.second.firstpos.size(); c2_i++)
						for(int table_index=0; table_index<followpos_table.size(); table_index++)
							if(followpos_table.get(table_index).get(0).id == temp.first.lastpos.get(c1_i).id)
								if(followpos_table.get(table_index).indexOf(temp.second.firstpos.get(c2_i)) <= 0)
									followpos_table.get(table_index).add(temp.second.firstpos.get(c2_i));
			}
			else if(temp.symbol == '*')
			{
				for(int n_i=0; n_i<temp.first.lastpos.size(); n_i++)
					for(int n_j=0; n_j<temp.first.firstpos.size(); n_j++)
						for(int table_index=0; table_index<followpos_table.size(); table_index++)
							if(followpos_table.get(table_index).get(0).id == temp.first.lastpos.get(n_i).id)
								if(followpos_table.get(table_index).indexOf(temp.first.firstpos.get(n_j)) <= 0)
									followpos_table.get(table_index).add(temp.first.firstpos.get(n_j));
			}				
		}
	}

	void print_tree()
	{
		for(int index=0; index<nodes_list.size(); index++)
		{
			System.out.println(nodes_list.get(index).symbol);
			System.out.println(nodes_list.get(index).id);
			System.out.println(nodes_list.get(index).nullable);
			for(int i=0; i<nodes_list.get(index).firstpos.size(); i++)
				System.out.print(nodes_list.get(index).firstpos.get(i).id);
			System.out.println();
			for(int i=0; i<nodes_list.get(index).lastpos.size(); i++)
				System.out.print(nodes_list.get(index).lastpos.get(i).id);
			System.out.println();
			System.out.println();
		}
	}

	void print_followpos_table()
	{
		for(int i=0; i<followpos_table.size(); i++)
		{
			for(int j=0; j<followpos_table.get(i).size(); j++)
				System.out.print(followpos_table.get(i).get(j).id);
			System.out.println();
		}
	}

	void make_DFA()
	{
		// Add firstpos of head node
		DStates.add(head.firstpos);
		
		// Add terminal symbols
		ArrayList<Node> terminals = new ArrayList<Node>();
		for(int index=0; index<nodes_list.size(); index++)
			if(nodes_list.get(i).symbol!='*' && nodes_list.get(i).symbol!='|' && nodes_list.get(i).symbol!='&')
				terminals.add(nodes_list.get(i));

		int state_index=0;
		while(state_index != DStates.size())
		{
			ArrayList<Node> start_symbol = DStates.get(state_index);
			for(int terminal_index=0; terminal_index<terminals.size(); terminal_index++)
			{
				ArrayList<Node> end_symbol = new ArrayList();
				for(int subsymbol_index=0; subsymbol_index<start_symbol.size(); subsymbol_index++)
				{
					if(start_symbol.get(subsymbol_index).id == terminal_symbol.get(terminal_index).id)
					{
						
					}
				}
			}
		}
	}

	void build(String postfix)
	{
		make_tree(postfix);
		print_tree();
		make_followpos_table();
		print_followpos_table();
	}
}

class RE_DFA
{
	public static void main(String args[])
	{
		InfixtoPostfix obj = new InfixtoPostfix();
		SyntaxTree tree = new SyntaxTree();
		String infix = "z&(a|b)*&y&#";
		String postfix = obj.exp_convert(infix);
		System.out.println(postfix);
		tree.build(postfix);
	}
}