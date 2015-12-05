#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"

#define MAXINT 2147483647

int MNJRE(int * a,int len)
{
    int i;
    int *jumps,j;
    jumps = (int*)calloc(len,sizeof(int));
    for(i=1;i<len;i++) jumps[i] = MAXINT;
    for(i=0;i<len;i++)
    {
        for(j=1;j+i<len&&j<=a[i];j++)
        {
            jumps[j+i] = min(jumps[j+i],jumps[i]+1);
        }
        if(j==len) break;

    }
    return jumps[len-1];
}

int main(int argc, char *argv[])
{
    int a[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int size = sizeof(a)/sizeof(a[0]);
    printf("Minimum number of jumps to reach end = %d\n",MNJRE(a,size));
}
