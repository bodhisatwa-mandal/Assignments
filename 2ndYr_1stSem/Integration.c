#include <stdio.h>
#include <math.h>
void input(float* a,float* b,float* max_error);
float Trapezoidal(float a,float b,float max_error);
float Simpson1_3(float a,float b,float max_error);
float Simpson3_8(float a,float b,float max_error);
float f(float x);
int main()
{
	float sum,a,b,max_error;
	input(&a,&b,&max_error);
	printf("\nUsing Trapezoidal Method :-\n");
	sum=Trapezoidal(a,b,max_error);
	printf("Integration of the function in (%f,%f] = %f\n",a,b,sum);
	printf("\nUsing Simpson's 1/3 Rule :-\n");
	sum=Simpson1_3(a,b,max_error);
	printf("Integration of the function in (%f,%f] = %f\n",a,b,sum);
	printf("\nUsing Simpson's 3/8 Rule :-\n");
	sum=Simpson3_8(a,b,max_error);
	printf("Integration of the function in (%f,%f] = %f\n",a,b,sum);
	return 0;
}
void input(float* a,float* b,float* max_error)
{
	printf("Enter lower and upper limits respectively : ");
	scanf("%f %f",a,b);
	printf("Enter max error : ");
	scanf("%f",max_error);
}
float f(float x)
{
	return 1.0/(1+x);
}
float Trapezoidal(float a,float b,float max_error)
{
	int iterations=1;
	float x,dist=b-a,sum0,sum1,error,width;
	width=dist;
	sum1=0.5*dist*(f(a)+f(b));
	for(x=0;x<105;x++)
		printf("-");
	printf("\n");
	printf("|   Iterations  ||  Partitions  |\tPrevious Sum\t|\tCurrent Sum\t|\tError\t\t|\n");
	printf("|");
	for(x=0;x<103;x++)
		printf("=");
	printf("|\n");
	do
	{
		sum0=sum1;
		sum1=0;
		width/=2;
		for(x=a;x<=b-width;x+=width)
			sum1+=(f(x)+f(x+width))*width/2;
		error=fabs(sum1-sum0);
		printf("|\t%d\t||\t%ld\t|\t%f\t|\t%f\t|\t%f\t|\n",iterations++,(long)((b-a)/width),sum0,sum1,error);
	}while(error>max_error);
	for(x=0;x<105;x++)
		printf("-");
	printf("\n");
	return sum1;
}
float Simpson1_3(float a,float b,float max_error)
{
	int iterations=1;
	float x,width,dist=b-a,sum0,sum1,error;
	width=dist;
	sum1=(dist/6)*(f(a)+4*f((a+b)/2)+f(b));
	for(x=0;x<105;x++)
		printf("-");
	printf("\n");
	printf("|   Iterations  ||  Partitions  |\tPrevious Sum\t|\tCurrent Sum\t|\tError\t\t|\n");
	printf("|");
	for(x=0;x<103;x++)
		printf("=");
	printf("|\n");
	do
	{
		sum0=sum1;
		sum1=0;
		width/=2;
		//width=dist/(iterations+1);
		for(x=a;x<=b-width;x+=width)
			sum1+=(f(x)+4*f(x+(width/2))+f(x+width))*width/6;
		error=fabs(sum1-sum0);
		printf("|\t%d\t||\t%ld\t|\t%f\t|\t%f\t|\t%f\t|\n",iterations++,(long)((b-a)/width),sum0,sum1,error);
	}while(error>max_error);
	for(x=0;x<105;x++)
		printf("-");
	printf("\n");
	return sum1;
}
float Simpson3_8(float a,float b,float max_error)
{
	int iterations=1;
	float x,width,dist=b-a,sum0,sum1,error;
	width=dist;
	sum1=(dist/8)*(f(a)+3*f((2*a+b)/3)+3*f((a+2*b)/3)+f(b));
	for(x=0;x<105;x++)
		printf("-");
	printf("\n");
	printf("|   Iterations  ||  Partitions  |\tPrevious Sum\t|\tCurrent Sum\t|\tError\t\t|\n");
	printf("|");
	for(x=0;x<103;x++)
		printf("=");
	printf("|\n");
	do
	{
		sum0=sum1;
		sum1=0;
		width/=2;
		//width=dist/(iterations+1);
		for(x=a;x<=b-width;x+=width)
			sum1+=(f(x)+3*f(x+(width/3))+3*f(x+(2*width/3))+f(x+width))*width/8;
		error=fabs(sum1-sum0);
		printf("|\t%d\t||\t%ld\t|\t%f\t|\t%f\t|\t%f\t|\n",iterations++,(long)((b-a)/width),sum0,sum1,error);
	}while(error>max_error);
	for(x=0;x<105;x++)
		printf("-");
	printf("\n");
	return sum1;
}
