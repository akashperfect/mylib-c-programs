#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    int *a,i,t,k,count,total,n,size,m=0;
    a = (int*)malloc(100000*sizeof(int));
    char c,s[100000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&n,s);

        c = s[0];count=1;
        total=0;m=0;
        for(i=0;i<100000;i++) a[i]=0;
        for(i=1;i<strlen(s);i++)
        {
            if(c==s[i])
            count++;
            else
            {
                c=s[i];
                a[count]++;
                if(count>m) m=count;
                count=1;
            }
        }
        a[count]++;
        if(count>m)m=count;
        for(i=0;i<=m;i++) printf("%d ",a[i]);
        while(n>0)
        {
            total+=((a[m]<n)?a[m]:n)*m;
            n-=a[m];
            m--;
        }
        printf("%d\n",total);
    }
    return 0;
}
