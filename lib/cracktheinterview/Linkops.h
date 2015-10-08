#ifndef LINKOPS_H_INCLUDED
#define LINKOPS_H_INCLUDED
#include "Link.h"


extern NODE CreateNode();
extern NODE InsertValue(NODE n, int val);
extern int Value(NODE n);

NODE CreateNode()
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node));
    n->s.num=0;
    //n->s.w = 0;
    n->next=NULL;
    n->prev=NULL;
    return n;
}

NODE InsertValue(NODE n, int val)
{
    n->s.num = val;
    return n;
}

List CreateList()
{
    List l;
    l.size = 0;
    l.head = NULL;
    return l;
}

List InsertList(List L, int n)
{
    NODE v,curr,pre;
    pre = curr = L.head;
    v = CreateNode();
    v->s.num = n;
    if(L.head==NULL)
    L.head = v;
    else if(curr->s.num>n)
    {
        v->next = curr;
        L.head = v;
    }
    else
    {
        while(curr!=NULL&&curr->s.num<n)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = v;
        v->next = curr;
    }
    L.size++;
    return L;
}

List ReverseList(List L)
{
    NODE prev,curr,temp;
    if(L.head==NULL) return L;
    prev = curr = L.head;
    curr = curr->next;
    prev->next = NULL;
    while(curr!=NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    L.head = prev;
    return L;
}

NODE ReverseListWP(NODE n, NODE acc)
{
    //printf("r%d\n",n->s.num);
    if(n==NULL) return acc;
    //printf("s%d\n",n->s.num);
    NODE next = n->next;
    n->next = acc;
    return ReverseListWP(next,n);

}

List DeleteNode(List L, int n)
{
    NODE prev,curr;
    prev = curr = L.head;
    if(L.head->s.num==n)
    L.head = curr->next;
    else
    {while(curr != NULL)  // This should be enough
{
     if(curr->s.num == n)
     {
          // make the current node (before the 'deletion point')
          // lined to the one after the 'deletion point (next of the next)
          prev->next = curr->next;
          // delete the node.
          free(curr);
          // Make the next pointer point to the new next.
          curr = prev->next;
     }
    // Otherwise advance both current and next.
     else {
           prev = curr;
           curr = curr->next;
     }
}
    }
    return L;
}

NODE Search(List L, int n)
{
    NODE curr = L.head;
    while(curr!=NULL)
    {
        if(curr->s.num==n)
        return curr;
        curr = curr->next;
    }
    return;
}

List DeleteList(List L)
{
    NODE listptr,nextptr;
    for(listptr = L.head; listptr != NULL; listptr = nextptr)
    {
          nextptr = listptr->next;
          free(listptr);
    }
    L.head = NULL;
}

NODE IsCircularN(NODE n)
{
    int flag = 0;
    NODE temp = n->next,hare,tort,prevh,prevt;
    tort = hare = n->next->next;
    hare = tort->next;
    while(hare!=NULL&&hare!=tort)
    {
        if(hare == n||tort == n) flag=1;
        if(hare == temp||tort == temp) break;
        prevt = tort;
        prevh = hare->next;
        tort = tort->next;
        if(hare->next==NULL) break;
        hare = hare->next->next;
    }
    if((hare == temp||tort == temp)&&flag==0)
    {
        if(hare==temp) return prevh;
        if(tort==temp) return prevt;
    }
    return NULL;

}

int IsCircular(List L)
{
    NODE hare,tort;
    if(L.head==NULL) return 0;
    tort = L.head;
    if(tort==NULL) return 0;
    hare = tort->next;
    while(hare!=NULL&&hare!=tort)
    {
        tort = tort->next;
        if(hare->next==NULL) break;
        hare = hare->next->next;
    }
    if(hare==tort) return 1;
    return 0;
}

void DeleteNodeP( NODE n)
{
    NODE curr = n,temp,trav,cirr = IsCircularN(n);
    printf("%d \n",n->s.num);
    int flag=0;
    temp = n->next;
    if(temp==NULL) free(n);
    if(cirr==NULL) // IsCircularN determines whether the neighbour of the NODE n is in the loop or not
    {
        printf("%d \n",n->s.num);
        n->s = temp->s;
        n->next = temp->next;
        free(temp);
    }
    else
    {
        printf("cirr = %d\n",cirr->s.num);
        n->s = temp->s;
        n->next = temp->next;
        cirr->next = n;
        free(temp);
    }
    return ;

}

void PrintList(List L)
{
    NODE curr = L.head;
    int i=0;
    while(curr!=NULL&&i++<10)
    {
        printf("%d ",curr->s.num);
        curr = curr->next;
    }
    printf("\n");
}

int Value(NODE n)
{
    return n->s.num;
}

int ValuePQ(priorityqueue p)
{
    return p.k;
}
/*
int Weight(NODE n)
{
    return n->s.w;
}
*/
#endif // LINKOPS_H_INCLUDED
