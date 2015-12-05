#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "..\\Linked lists\\basicdef.h"
#include "..\\Linked lists\\Link.h"
#include "..\\Linked lists\\Linkops.h"
#include "..\\Linked lists\\LL_Mergesort.h"

NODE NodeCircluarList(List L)
{
    if(!IsCircular(L)) return NULL;
    NODE match = CircularMatchNode(L.head),start = L.head;
    while(start != match)
    {
        start = start->next;
        match = match->next;
    }
    return match;
}

int main(int argc, char *argv[])
{

    List L = GenerateList(10);
    PrintList(L);
    NODE start,curr = L.head;
    start = curr;
    while(curr->next!=NULL)
    curr = curr->next;
    curr->next = start->next->next->next->next;
    printf("%d\n",NodeCircluarList(L)->data);



}
