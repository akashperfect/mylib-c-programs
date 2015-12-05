#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"

int max(int a,int b)
{
    return (a>b)?a:b;
}

int LSCS(int *a, int size)
{
    int maxg=a[0],maxtrav=a[0],i;
    for(i=1;i<size;i++)
    {
        maxtrav = max2(a[i],maxtrav+a[i]);
        maxg = max2(maxg,maxtrav);
    }
    return maxg;
}

int main()
{
    int a[] = {-2,-6,4,-1,3,8,-4,9,2,-6,7};
    int size = sizeof(a)/sizeof(a[0]);
    printf("Max Sum = %d\n",LSCS(a,size));
}

