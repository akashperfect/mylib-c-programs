#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include"hashtable_chaining.c"
int ** LCS(char *f,char *s,int **a)
{
    int m = strlen(f),n = strlen(s),i,j;
         for(i=0;i<1000;i++)
        for(j=0;j<1000;j++)
        a[i][j] = 0;
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(f[i-1]==s[j-1])
                a[i][j] = a[i-1][j-1]+1;
            else if(a[i-1][j]>=a[i][j-1])
                a[i][j] = a[i-1][j];
            else
                a[i][j] = a[i][j-1];
        }
    }
    printf("%d",a[100][100]);
    return a;
}


int main(void)
{
    int i,j,**a;
    char *f,*s;
    f = (char*)malloc(1000);
    s = (char*)malloc(1000);
    FILE *fp,*fp1;
    fp = fopen("first.txt","r");
    fp1 = fopen("second.txt","r");
    a=(int**)malloc(1000*sizeof(int*));
    for(j=0;j<1000;j++)
    a[j]= (int*)malloc(1000*sizeof(int));

    fscanf(fp,"%s",f);
    fscanf(fp1,"%s",s);
    a = LCS(f,s,a);
    printf("A%d",a[strlen(f)-1][strlen(s)-1]);
}
