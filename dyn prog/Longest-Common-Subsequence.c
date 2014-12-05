#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"

int LCS(char * s1, char * s2)
{
    int r = strlen(s1)+1,c = strlen(s2)+1,i,j;
    int **l = DeclareDDArray(r,c);
    //printf("%d",l[r][c]);

    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            if(s1[i-1]==s2[j-1])
            l[i][j] = l[i-1][j-1] + 1;
            else
            l[i][j] = max2(l[i-1][j],l[i][j-1]);
        }
    }
    return l[r-1][c-1];
}

int main(int argc, char *argv[])
{
    int a[] = {-2,-6,4,-1,3,8,-4,9,2,-6,7};
    int size = sizeof(a)/sizeof(a[0]);
    char *s1 = "AKASHSAXENA";
    char *s2 = "SNAXESHAKAA";
    printf("Longest Common Subsequence = %d",LCS(s1,s2));

}
