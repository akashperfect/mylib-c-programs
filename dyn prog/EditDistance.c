#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"

int ED(char * s1, char * s2)
{
    int r = strlen(s1)+1,c = strlen(s2)+1,i,j;
    int ** t = DeclareDDArray(r,c);
    for(i=0;i<r;i++) t[i][0]=i;
    for(i=0;i<c;i++) t[0][i]=i;
    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            t[i][j] = min3(t[i-1][j]+1,t[i][j-1]+1,t[i-1][j-1] + (s1[i]!=s2[j]));
        }
    }
    return t[r-1][c-1];


}

int main(int argc, char *argv[])
{
    char *s1 = "AKASHSAXENA";
    char *s2 = "XANSENUANA";
    //int size = sizeof(a)/sizeof(a[0]);
    printf("Minimum edits required = %d",ED(s1,s2));

}
