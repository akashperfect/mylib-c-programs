#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"



int UglyNum(int n)
{
    int *u,i2=0,i3=0,i5=0,i=0,n2,n3,n5,nextu;
    u = (int*)malloc(n*sizeof(int));
    u[0] = 1;
    while(i<n-1)
    {
        n2 = u[i2]*2;
        n3 = u[i3]*3;
        n5 = u[i5]*5;
        nextu = min3(n2,n3,n5);
        if(nextu==n2) i2++;
        if(nextu==n3) i3++;
        if(nextu==n5) i5++;
        i++;
        u[i] = nextu;
    }
    return u[n-1];
}


int main(int argc, char *argv[])
{
	int a[] = {-2,-6,4,-1,3,8,-4,9,2,-6,7};
    int size = sizeof(a)/sizeof(a[0]);
    printf("150th ugly num = %d\n",UglyNum(150));
}
