
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Queueops.h"
int main()
{
    queue s = CreateQueue();
    NODE n = CreateNode();
    NODE n1 = CreateNode();
    NODE n2 = CreateNode();
    printf("aa");
    n = InsertValue(n,9);
    printf("bb");
    s = Enqueue(s,n);
    printf("cc");
    n1 = InsertValue(n1,6);
    s = Enqueue(s,n1);
    printf("dd");
     n2 = InsertValue(n2,4);
     printf("ff");
    s = Enqueue(s,n2);
    printf("ee");
    PrintQueue(s);
    s = Dequeue(s);
    PrintQueue(s);
    //printf("%d\n",top(s)->s.num);
    return 0;
}
