#include<stdio.h>
#include<math.h>
int main(void)
{
    int i,flag,count=0;
    FILE *fp;
    fp = fopen("prime.txt","a+");
    double n=11.0;
    while(n<=10000.0){
    for(i=3,flag=0;i<=sqrt(n);i+=2)
    {
        if(((int)n)%i==0)
        {
            flag=1;
            break;}
    }
    if(flag!=1)
     {fprintf(fp,"%d\n",(int)n);count++;}
    n+=2;
    }
    printf("%d",count);
    return 0;
}
