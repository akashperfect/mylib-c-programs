#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    int t,*n,size,num,j,l,i,c,r,k1;
    double k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lf%d",&size,&k,&l);
        n = (int*)malloc((size)*sizeof(int));
        c=0;
        k1 = (int)pow(10.0,k);
        for(i=0;i<size;i++)
        {
            *(n+i)=i;c+=i;}
        *(n+size)=c;
        for(i=size,j=size;i<l;i++)
        {
            if(j==size)
            {
                num = (n[j]*2-n[0]+k1)-k1*((n[j]*2-n[0]+k1)/k1);
                n[0] = num;
                j=-1;

            }
            else
            {
                num = (n[j]*2-n[j+1]+k1)-k1*((n[j]*2-n[j+1]+k1)/k1);
                n[j+1] = num;

            }

            j++;

        }
        printf("%d\n",num);

    }
    return 0;
}
