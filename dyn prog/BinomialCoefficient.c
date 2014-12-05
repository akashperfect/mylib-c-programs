#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"

int BC(int n,int k)
{
    int ** b,i,j;
    b = DeclareDDArray(k+1,n+1);
    for(i=0;i<=n;i++)
    b[0][i] = 1; //as nC0 = 1
    for(i=0;i<=k;i++)
    b[i][i] = 1; //as nCn = 1
    for(i=1;i<=k;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            b[i][j] = b[i][j-1] + b[i-1][j-1]; //as jCk = j-1Ck-1 + j-1Ck
        }
    }
    return b[k][n];

}

int main(int argc, char *argv[])
{
    int n=8,k=2;
    printf("Binomial Coefficient = %d\n",BC(n,k));
    return 0;

}
