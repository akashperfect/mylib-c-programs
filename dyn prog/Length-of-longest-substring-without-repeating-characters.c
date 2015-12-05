#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"
#define Chars 256

int LLSWRC(char * s)
{
    int len = strlen(s);
    int d[Chars],n[len],i=0,max=0;
    for(i=0;i<Chars;i++) d[i] = -1;
    i=0;
    n[i] = 1;
    d[s[i]] = 0;
    for(i=1;i<len;i++)
    {
        n[i] = min(i-d[s[i]]-1,n[i-1])+1;
        d[s[i]] = i;
    }
    for(i=0;i<len;i++)
    if(max<n[i]) max = n[i];
    return max;
}


int main(int argc, char *argv[])
{
    int a[] = {-2,-6,4,-1,3,8,-4,9,2,-6,7};
    int size = sizeof(a)/sizeof(a[0]);
    char *s = "GEEKSFORGEEKS";
    printf("Length of the longest substring without repeating characters = %d\n",LLSWRC(s));

}
