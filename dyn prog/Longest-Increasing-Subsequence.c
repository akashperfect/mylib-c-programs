#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"

int LIS(int *a, int size)
{
    int *lis,i,max=0,j;
    lis = (int*)malloc(size*sizeof(int));
    for(i=0;i<size;i++) lis[i] = 1;
    for(i=1;i<size;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j]&&lis[i]<lis[j]+1)
            lis[i] = lis[j]+1;
        }
    }
    for(i=0;i<size;i++)
    if(max<lis[i]) max = lis[i];
    return max;
}


int main(int argc, char *argv[])
{
    int a[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int size = sizeof(a)/sizeof(a[0]);
    printf("Longest Increasing Subsequence = %d\n",LIS(a,size));

}
