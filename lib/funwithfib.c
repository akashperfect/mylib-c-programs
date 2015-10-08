#include<stdio.h>
int main(void)
{
    int t,a,b,n,m,f0,f1,temp,f2,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&n,&m);
        f0=a;
        f1=b;
        for(i=1,f2=f0+f1;i<n-1;i++)
        {
            temp=f0%m+f1%m;
            f0=f1%m;
            f1=temp%m;
            f2+=f1%m;
            f2%=m;
        }
        printf("%d\n",f2);
    }
    return 0;
}
