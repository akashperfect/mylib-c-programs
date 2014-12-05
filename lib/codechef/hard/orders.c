#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int t,i,j,n;
    scanf("%d",&t );
    while(t--)
    {
        scanf("%d",&n);
        int *a = (int*)malloc(n*4);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0,j=1;j<n&&i<n;j++)
        {
            if(a[j]==0)
            {
                while(i<j)
                {
                    a[i] = j-a[i];
                    i++;
                }
            }
        }
        while(i<j)
        {
            a[i] = j-a[i];
            i++;
        }
        for(i=0;i<n;i++)
        printf("%d ",a[i]);
        printf("\n");
    }
    return 0;

}
