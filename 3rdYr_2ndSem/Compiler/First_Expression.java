class First_Expression
{
	static String epsilon = "#";
	public static void main(String args[])
	{
		// Ei form e amar first gulo saved ache, line wise input niye space separate kore nis
		String firsts[][] = {
						 {"AA",":","aa",epsilon},
						 {"BB",":","aa","bb",epsilon}
						};
		String expression = "AA BB";
		String result="";
		//String expression = "AA BB aa"
		int i,j,k;
		boolean flag;
		String expr_array[] = expression.split(" ");//Array Return kore, string ta ke split korche with whitespace as delimiter
		for(i=0; i<expr_array.length; i++)
		{
			for(j=0; j<firsts.length; j++)
				if(expr_array[i].equals(firsts[j][0]))
					break;
			if(j==firsts.length) //terminal
			{
				if(result.indexOf(expr_array[i]+" ")==-1)//non-terminal not present in result
					result += expr_array[i]+" ";
				break;
			}

			//non-terminal
			flag = false;
			for(k=2; k<firsts[j].length; k++)
			{
				if(firsts[j][k].equals(epsilon))
				{
					flag=true;
					continue;
				}
				if(result.indexOf(firsts[j][k]+" ")==-1)//non-terminal not present in result
					result += firsts[j][k]+" ";
			}
			if(flag==false)
				break;
		}
		result=result.trim();//Remove additional whitespace at last
		System.out.println(result);
	}
}