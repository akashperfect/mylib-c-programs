#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"

int main(int argc, char *argv[])
{
    int n,num=0;
    scanf("%d",&n);
    a = (int*)calloc(n,sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%c%d",&c,&x);
        if(c=='r'&&num==0)
        {
            printf("Wrong!\n");
            continue;
        }
        if(c=='a')
        {
            for(j=num-1;j>=0;j--)
            {
                if(*(a+j)>x)
                *(a+j+1) = *(a+j);
                else break;
            }
            *(a+j+1) = x;
            num++;

        }
        else if(c=='r')
        {
            for(j=num-2;j>=x;j--)
            {
                *(a+j) = *(a+j+1);
            }
            *(a+j) = x;
            num++;
        }


    }

}
