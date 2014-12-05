#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,m,i,j,t,a,b,l,mo,count;
    scanf("%d%d",&n,&m);
    int **mat,*temp;
    mat = (int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        mat[n] = (int*)calloc(n,sizeof(int));
    temp = (int*)calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            mat[i][j]=0;
        temp[i]=1;

    }

    t=n;
    while(t--)
    {
        scanf("%d%d",&a,&b);
        l = (a<b)?a:b;
        mo = (b>a)?b:a;
        mat[l][mo] = 1;
    }
    count=0;
    for(j=n-1;j>=0;j--)
    {
        for(i=n-1;i>=0;i--)
        {
            if(mat[i][j]==1)
            {
                if(temp[i]%2==0) count++;
                temp[i] += temp[j];
            }
        }

    }
    printf("%d\n",count-1);
    return 0;
}
