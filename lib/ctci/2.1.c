#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "..\\Linked lists\\basicdef.h"
#include "..\\Linked lists\\Link.h"
#include "..\\Linked lists\\Linkops.h"
#include "..\\Linked lists\\LL_Mergesort.h"

void DeleteNodeGen(NODE * n)
{

    NODE temp = (*n)->next;
    (*n)->data = temp->data;
    (*n)->next = temp->next;
    free(temp);

}

void RemoveDuplicates(NODE * n)
{
    if((*n)==NULL) return;
    NODE curr = (*n)->next , prev = *n;
    while(curr!=NULL)
    {
        if(curr->data == prev->data)
        {

            if(curr->next!=NULL)
            DeleteNodeGen(&curr); //Used if list is not circular IF it is use DeleteNodeP
            else
            {prev->next = NULL;
            free(curr);}
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }

    }
}

int main(int argc, char *argv[])
{
    int i,r;
    clock_t begin, end;
    FILE *fp;
    fp = fopen("Time Test.txt","a+");
    List L = CreateList();
    List L1 = CreateList();
    for(i=0;i<1000000;i++)
    {
        L = UnsortInsert(L,rand());
    }
    //PrintList(L);
    L1.head = mergesort((L.head));
    RemoveDuplicates(&(L1.head));
    PrintList(L1);

}
