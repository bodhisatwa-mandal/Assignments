#include <stdio.h>
#include <stdlib.h>
int iteration=1;
void initialize(int n,float original[n][n],float copy[n][n],float inverse[n][n]);
void gaussJordan(int n,float original[n][n],float inverse[n][n]);
void multiply(int n,float copy[n][n],float inverse[n][n],float multiplied[n][n]);
void printDual(int n,float original[n][n],float inverse[n][n]);
void printSingle(int n,float arr[n][n]);
int main()
{
	int n,p,q;
	printf("Enter dimension\t:\t");
	scanf("%d",&n);
	float copy[n][n],original[n][n],inverse[n][n],multiplied[n][n];
	initialize(n,original,copy,inverse);
	gaussJordan(n,original,inverse);
	multiply(n,copy,inverse,multiplied);

	printf("\n\n\n");
	printf("Given Matrix\t:\n");
	printSingle(n,copy);

	printf("\n\n\n");
	printf("Inverse of the given matrix\t:\n");
	printSingle(n,inverse);

	printf("\n\n\n");
	printf("Multiplying the given matrix with the inverse calculated\t:\n");
	printSingle(n,multiplied);
}
void gaussJordan(int n,float original[n][n],float inverse[n][n])
{
	int i,j,k,p,q;
	float temp;
	for(i=0;i<n;i++)
	{
		if(!original[i][i])
		{
			printf("Gauss Jordan Method not Possible\n");
			exit(1);
		}
		if(i!=1)
			printDual(n,original,inverse);
		if(original[i][i]!=1)
		{
			temp=original[i][i];
			for(j=n-1;j>=0;j--)
			{
				inverse[i][j]/=temp;
				original[i][j]/=temp;
			}
			printDual(n,original,inverse);
		}
		for(j=i+1;j<n;j++)
		{
			temp=original[j][i];
			for(k=0;k<n;k++)
			{
				original[j][k]-=temp*original[i][k];
				inverse[j][k]-=temp*inverse[i][k];
			}
		}
		if(i!=n-1)
			printDual(n,original,inverse);
		for(j=i-1;j>=0;j--)
		{
			temp=original[j][i];
			for(k=0;k<n;k++)
			{
				original[j][k]-=temp*original[i][k];
				inverse[j][k]-=temp*inverse[i][k];
			}
		}
	}
	printDual(n,original,inverse);
}
void initialize(int n,float original[n][n],float copy[n][n],float inverse[n][n])
{
	int i,j;
	printf("Enter elements\t:-\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%f",&original[i][j]);
			copy[i][j]=original[i][j];
			if(i==j)
				inverse[i][j]=1;
			else
				inverse[i][j]=0;
		}
}
void printDual(int n,float original[n][n],float inverse[n][n])
{
	printf("\n\nStep\t:\t%d",iteration++);
	int p,q;
	printf("\n");
	printf("---");
	for(p=0;p<n;p++)
		printf("\t\t");
	for(p=0;p<n;p++)
		printf("\t\t");
	printf("\t      ---\n");
	for(p=0;p<n;p++)
	{
		printf("|");
		for(q=0;q<n;q++)
			printf("\t%f",original[p][q]);
		printf("\t|");
		for(q=0;q<n;q++)
			printf("\t%f",inverse[p][q]);
		printf("\t|\n");
	}
	printf("---");
	for(p=0;p<n;p++)
		printf("\t\t");
	for(p=0;p<n;p++)
		printf("\t\t");
	printf("\t      ---\n");
}
void printSingle(int n,float arr[n][n])
{
	int p,q;
	printf("\t---");
	for(p=0;p<n;p++)
		printf("\t\t");
	printf("      ---\n");
	for(p=0;p<n;p++)
	{
		printf("\t|");
		for(q=0;q<n;q++)
			printf("\t%f",arr[p][q]);
		printf("\t|\n");
	}
	printf("\t---");
	for(p=0;p<n;p++)
		printf("\t\t");
	printf("      ---\n");
}
void multiply(int n,float copy[n][n],float inverse[n][n],float multiplied[n][n])
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			multiplied[i][j]=0;
			for(k=0;k<n;k++)
				multiplied[i][j]+=copy[i][k]*inverse[k][j];
		}
}
