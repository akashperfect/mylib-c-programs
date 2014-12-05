#include<stdio.h>
int main()
{
    int i,*a;
    for(i=0;i<100;i++)
    {a =(int*)malloc(200000001*sizeof(int));}
    *(a+20000000)=8789;
    printf("%d",a[20000000]);
}
