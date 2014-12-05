#include<stdio.h>
int main()
{
    FILE *fp;
    int count=0,d;
    fp = fopen("new1A,B,C.txt","r");
    while(fscanf(fp,"%d",&d)!=EOF)
    if(d==69)
    count++;
    printf("%d",count);
}
