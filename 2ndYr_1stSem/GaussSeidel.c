#include <stdio.h>
#include <math.h>
int main()
{
      int i, j, n,iter=1;
      float temp, error, max, sum = 0; 
      float arr[10][10], y[10], allowed_error;
      printf("\nEnter Number of Equations:\t");
      scanf("%d", &n);
      printf("Enter Error:\t");
      scanf("%f", &allowed_error);
      printf("Enter Co-Efficients\n");
      for(i = 1; i <= n; i++)
      {
        printf("For Equation %d:",i);
        for(j = 1; j <= n + 1; j++)
            scanf("%f", &arr[i][j]);
      }
      for(i = 1; i <= n; i++)
      {     
            sum=0;
            for(j=1;j<=n;j++)
            {   
                if(i!=j)
                    sum+=fabs(arr[i][j]);
            }
                if(sum>arr[i][i])
                {
                    printf("Not Diagonally Dominant\n");
                    return 0;
                }
        }
        printf("  i\t");
      for(i = 1; i <= n; i++)
      {
        printf("|\t\tx%d\t",i);
            y[i] = 0;
      }
      printf("\n");
      for(i=1;i<=n;i++)
        printf("=========================");
    printf("\n");
      do
      {
            printf("%3d",iter++);
            max = 0;
            for(i = 1; i <= n; i++)
            {
                  sum = 0;
                  for(j = 1; j <= n; j++)
                        if(j != i)
                              sum = sum + arr[i][j] * y[j];
                  temp = (arr[i][n + 1] - sum) / arr[i][i];
                  error = fabs(y[i] - temp);
                  if(error > max)
                        max = error;
                  y[i] = temp;
                  printf("\t|\t%f", y[i]);
            }
            printf("\n");
      }
      while(max >= allowed_error);
      printf("\nSolution:\n");
      for(i = 1; i <= n; i++)
      {
            printf("x%d:%f\n", i, y[i]);
      }
      printf("\n");
      return 0;
}
