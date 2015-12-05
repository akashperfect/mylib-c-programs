#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    double n,m;
    scanf("%lf%lf",&n,&m);
    if(n>m-0.5)
    {
        printf("%.2lf\n",m);
    }
    else if(((int)n)%5!=0)
    {
        printf("%.2lf\n",m);
    }
    else
    {
        printf("%.2lf\n",m-n-.5);
    }
    return 0;
}
