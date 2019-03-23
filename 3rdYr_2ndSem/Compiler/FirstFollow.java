import java.util.*;
import java.io.*;
class FirstFollow
{
	static String ntermnl[],termnl[];
	static int ntlen,tlen;
	static String grmr[][][],fst[][],flw[][];
	public static void main(String args[]) throws IOException
	{

		String input_file_name = "input.txt";
		File input_file = new File(input_file_name);
		BufferedReader br=new BufferedReader(new FileReader(input_file));

		String first_file_name = "first.txt";
		PrintWriter first_file = new PrintWriter(first_file_name, "UTF-8");

		String follow_file_name = "follow.txt";
		PrintWriter follow_file = new PrintWriter(follow_file_name, "UTF-8");

		String temp="";
		int i,j,n;


		ntermnl=br.readLine().split(" ");
		ntlen=ntermnl.length;	

		termnl=br.readLine().split(" ");
		tlen=termnl.length;


		grmr=new String[ntlen][][];
		for(i=0;i<ntlen;i++)
		{

			n=Integer.parseInt(br.readLine());
			grmr[i]=new String[n][];

			for(j=0;j<n;j++)
				grmr[i][j]=br.readLine().split(" ");
		}
		fst=new String[ntlen][];
		for(i=0;i<ntlen;i++)
		{
			temp=first(i);
			fst[i]=temp.split(" ");
		}

		for(i=0;i<ntlen;i++)
		{
			first_file.print(ntermnl[i]+" : ");
			fst[i]=removeDuplicates(fst[i]);
			for(j=0; j<fst[i].length; j++)
				first_file.print(fst[i][j]+" ");
			first_file.println();
		}
		first_file.close();
		
		flw=new String[ntlen][];
		for(i=0;i<ntlen;i++)
		{
			temp=follow(i);
			flw[i]=temp.split(" ");
		}

		for(i=0;i<ntlen;i++)
		{
			follow_file.print(ntermnl[i]+" : ");
			flw[i]=removeDuplicates(flw[i]);
			for(j=0; j<flw[i].length; j++)
				follow_file.print(flw[i][j]+" ");
			follow_file.println();
		}
		follow_file.close();
	}
	static String first(int i)
	{
		int j,k,l=0,found=0;
		String temp="",str="";
		for(j=0;j<grmr[i].length;j++) //number of productions
		{
			for(k=0;k<grmr[i][j].length;k++,found=0) //when nonterminal has epsilon production
			{
				for(l=0;l<ntlen;l++) //finding nonterminal
				{
					if(grmr[i][j][k].equals(ntermnl[l])) //for nonterminal in first set
					{
						str=first(l);
						if(!(str.length()==2 && str.charAt(0)=='#')) //when epsilon production is the only nonterminal production
							temp=temp+str+" ";
						found=1;
						break;
					}
				}
				if(found==1)
				{
					if(str.contains("#")) //here epsilon will lead to next nonterminal's first set
						continue;
				}
				else //if first set includes terminal
					temp=temp+grmr[i][j][k]+" ";
				break;
			}
		}
		return temp;
	}
	static String follow(int i)
	{
		String pro[],chr[];
		String temp="";
		int j,k,l,m,n,found=0;
		if(i==0)
			temp="$ ";
		for(j=0;j<ntlen;j++)
		{
			for(k=0;k<grmr[j].length;k++) //entering grammar matrix
			{
				pro=grmr[j][k];
				for(l=0;l<pro.length;l++) //entering each production
				{
					if(pro[l].equals(ntermnl[i])) //finding the nonterminal whose follow set is to be found
					{
						if(l==pro.length-1) //if it is the last terminal/non-terminal then follow of current non-terminal
						{
							if(j<i)
							{
								for(int p=0; p<flw[j].length; p++)
									temp=temp+flw[j][p]+" ";
							}
						}
						else
						{
							for(m=0;m<ntlen;m++)
							{
								if(pro[l+1].equals(ntermnl[m])) //first of next non-terminal otherwise (else later…)
								{
									//temp="";
									//for(int p=0; p<fst[m].length; p++)
									//	chr+=fst[m][p]+" ";
									chr=fst[m];
									for(n=0;n<chr.length;n++)
									{
										if(chr[n].equals("#")) //if first includes epsilon
										{
											if(l+1==pro.length-1)
												temp=temp+follow(j)+" "; //when non-terminal is second last
											else
												temp=temp+follow(m)+" ";

										}
										else
										{	
											temp=temp+chr[n]+"+"; //include whole first set except epsilon
										}
									}
									found=1;
								}
							}
							if(found!=1)
							{
								temp=temp+pro[l+1]+" "; //follow set will include terminal(else is here)
							}
						}
					}
				}
			}
		}

		return temp;
	}
	static String[] removeDuplicates(String str[])
	{
		int i;
		String temp="";
		for(i=0; i<str.length; i++)
			if(temp.indexOf(str[i])==-1)
				temp = temp+str[i]+" ";
		return temp.split(" ");
	}
}
