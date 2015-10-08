#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "..\\Linked lists\\basicdef.h"
#include "..\\Linked lists\\Link.h"
#include "..\\Linked lists\\Linkops.h"
#include "..\\Linked lists\\LL_Mergesort.h"

NODE CheckPali(NODE curr, NODE rev, int *test)
{
    NODE n;
    if(rev==NULL)
    return curr;
    n = CheckPali(curr,rev->next,test);
    printf("n = %d rev = %d\n",n->data,rev->data);
    if(n->data == rev->data)
    return n->next;
    else
    *test = 0;
}

int CheckPalindrome(List L)
{
    NODE curr = L.head,rev = curr;
    int len = Length(L.head),t=1,mid;
    if(len%2==0)
        mid = len/2;
    else
        mid = len/2+1;
    while(mid--)
        rev = rev->next;
    CheckPali(curr,rev,&t);
    return t;
}

int main(int argc, char *argv[])
{
    List L = CreateList();
    L = UnsortInsert(L,5);
    L = UnsortInsert(L,4);
    L = UnsortInsert(L,2);
    L = UnsortInsert(L,1);
    L = UnsortInsert(L,3);
    L = UnsortInsert(L,2);
    L = UnsortInsert(L,4);
    L = UnsortInsert(L,5);
    PrintList(L);

    printf("%d\n",CheckPalindrome(L));

}
