#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int t,n,i,count;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        count=0;
        for(i=5;i<=n;i*=5)
        {
            count+=n/i;
        }
        printf("%d\n",count);
    }
    return 0;
}
