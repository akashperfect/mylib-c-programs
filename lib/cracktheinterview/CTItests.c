#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "Linkops.h"


int main(int argc, char *argv[])
{
    int a[] = {-2,-6,4,-1,3,8,-4,9,2,-6,7};
    int size = sizeof(a)/sizeof(a[0]);
    List L = CreateList();
    L = InsertList(L,12);
    L = InsertList(L,1);
    L = InsertList(L,4);
    L = InsertList(L,7);
    L = InsertList(L,25);
    L = InsertList(L,5);
    PrintList(L);
    L = ReverseList(L);
    PrintList(L);
    L = DeleteNode(L,7);
    PrintList(L);
    DeleteNodeP(L.head->next);
    L = ReverseList(L);
    L = InsertList(L,12);
    PrintList(L);
    NODE test = NULL;
    L.head = ReverseListWP(L.head,test);
    PrintList(L);
    DeleteList(L);
    PrintList(L);
    printf("%d",L.head->s.num);
}
