#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define R 3

float f(float x);
float df(float x);
float g(float x);
float dg(float x);

void bisecton();
void fixedPointIteration();
void regulaFalsi();
void newtonRaphson();
void secant();

int main ()
{
    bisecton();
    fixedPointIteration();
    regulaFalsi();
    newtonRaphson();
    secant();
    return 0;
}

float f(float x)
{
    return x*x-5*x+6;
}

float df(float x)
{
    return 2*x-5;
}

float g(float x)
{
    return sqrt(5*x-6);
}

float dg(float x)
{
    return 2.5/sqrt(5*x-6);
}

void bisecton()
{
    FILE *fp;
    fp = fopen ("bisection.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit (1);
    }
    int i=0;
    float a, b;
    printf("Enter approximate numbers for bisection method\n");
    scanf("%f %f",&a,&b);
	float c,e1=fabs(a-b),e0,n;
	while(e1>0.0001)
	{
		c=(a+b)/2;
		fprintf(fp,"%d\t%f\n",i++,c);
		if((f(a)*f(c))<0)
            b=c;
        else
            a=c;
        e0=e1;
		e1=fabs(a-b);
    }
    fclose(fp);
}

void fixedPointIteration()
{
    FILE *fp;
    fp = fopen ("fixedPointIteration.txt", "w");
    if (fp == NULL)
    {
        printf("Error opend file\n");
        exit (1);
    }

    int i=0;
    float x0;
    printf("Enter approximate root for fixed point iteration method\n");
    scanf("%f",&x0);
	float x1,e1=1,e0,n;
	while(e1>0.0001)
	{
		x1=g(x0);
        e1=fabs(x0-x1);
		fprintf(fp, "%d\t%f\n",i++,x1);
        e0=e1;
		x0=x1;
    }
    fclose(fp);
}

void regulaFalsi()
{
    FILE *fp;
    fp = fopen ("regulaFalsi.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit (1);
    }

    int i=0;
    float a, b;
    printf("Enter values for regula falsi method\n");
    scanf("%f %f",&a,&b);
	float c,e1=fabs(a-b),e0,n;
	while(fabs(e1)>0.0001)
	{
		c=(a*f(b)-b*f(a))/(f(b)-f(a));
		fprintf(fp, "%d\t%f\n",i++,c);
		if((f(a)*f(c))<0)
            b=c;
        else 
            a=c;
        e0=e1;
		e1=fabs(a-b);
    }
    fclose(fp);
}

void newtonRaphson()
{
    FILE *fp;
    fp = fopen ("newtonRaphson.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit (1);
    }

    int i=0;
    float x0;
    printf("Enter the approximate root for Newton Raphson method\n");
    scanf("%f",&x0);
	float x1,e1=1,e0,n;
	while(fabs(e1)>0.0001)
	{
		x1=x0-f(x0)/df(x0);
        e1=fabs(x1-x0);
		fprintf(fp, "%d\t%f\n",i++,x1);
		x0=x1;
        e0=e1;
    }
    fclose(fp);
}

void secant()
{
    FILE *fp;
    fp = fopen ("secant.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit (1);
    }
    int i=0;
    float a, b;
    printf("Enter values for secant method\n");
    scanf("%f %f",&a,&b);
	float c,e1=fabs(a-b),e0,n;
	while(fabs(e1)>0.0001)
	{
		c=(a*f(b)-b*f(a))/(f(b)-f(a));
        e1=fabs(a-b);
		fprintf(fp, "%d\t%f\n",i++,c);
		a=b;
		b=c;
        e0=e1;
    }
    fclose(fp);
}
