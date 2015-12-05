#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//#include "basicdef.h"

int * GenerateLPS(char * pat)
{
    int j,m = strlen(pat),* lps = (int*)calloc(m,1);
    for(j=1;j<m;j++)
    {
        if(pat[j] == pat[j-1])
            lps[j] = lps[j-1] + 1;
    }
    for(j=0;j<m;j++) printf("%d ",lps[j]);
    return lps;

}

void KMPSearch(char * txt, char * pat)
{
    int i=0,j=0,m = strlen(pat),n = strlen(txt), *lps = GenerateLPS(pat);
    while(i<n)
    {
        if(txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if(j == m)
        {
            printf("Pattern found at %d\n",i-m);
            j=0;
        }
        else if(pat[j]!=txt[i])
        {
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    int a[] = {-2,-6,4,-1,3,8,-4,9,2,-6,7};
    int size = sizeof(a)/sizeof(a[0]);
    char *txt = "AAABBBABCCDDDEFFAABCBBSFCFDASESFDAD";
    char *pat = "AAB";
    KMPSearch(txt,pat);

}
