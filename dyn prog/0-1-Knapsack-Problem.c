#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"
#define I 5

int O1KP(int val[I], int wt[I], int W)
{
    int M[I+1][W+1],i,j;
    for(i=0;i<=I;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0||j==0) M[i][j] = 0;
            else if(wt[i-1]<=j)
            M[i][j] = max2(val[i-1] + M[i-1][j-wt[i-1]], M[i-1][j]);
            else
            M[i][j] = M[i-1][j];

        }
    }
    return M[I][W];

}


int main(int argc, char *argv[])
{
    int val[I] = {1,2,3,4,5};
    int wt[I] = {2,4,6,8,10},W=9;
    //int size = sizeof(a)/sizeof(a[0]);
    printf("0-1 Knapsack Problem = %d\n",O1KP(val,wt,W));

}
