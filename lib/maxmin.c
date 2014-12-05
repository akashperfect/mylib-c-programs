#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int min,max,n,a,b,i;
     printf("Enter size and array\n");
    scanf("%d",&n);
    for(i=0;i<n/2;i++)
    {
        scanf("%d%d",&a,&b);
        if(a>b)
        {
            if(b<min) min=b;
            if(a>max) max=a;
        }
        else
        {
            if(a<min) min=a;
            if(b>max) max=b;
        }
    }
    if(n%2!=0)
    {
        scanf("%d",&a);
        if(a<min) min=a;
        else if(a>max) max=a;
    }
    printf("min=%d max=%d\n",min,max);
}
