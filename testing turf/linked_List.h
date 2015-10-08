#ifndef LINKOPS_H_INCLUDED
#define LINKOPS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* NODE;

struct node{
    void * data; 
    NODE next;
    NODE prev;
};

typedef struct
{
    int size;
    NODE head;
}List;


extern NODE CreateNode();
extern NODE InsertValue(NODE n, void * val);
extern void PrintList(List *l);

NODE 
CreateNode(void * data)
{
    NODE n;
    n = (NODE)calloc(1, sizeof(struct node));
    n->data = data;
    // n->data = (void *)malloc(sizeof(int));
    // memcpy(n->data, data, sizeof(int));
    n->next = NULL;
    n->prev = NULL;
    return n;
}

NODE 
InsertValue(NODE n, void * val)
{
    n->data = val;
    return n;
}

void * 
GetData(NODE n)
{
    return n->data;
}

void
CreateList(List *l)
{
    l->size = 0;
    l->head = NULL;
}

void
InsertList(List *l, void * data)
{
    NODE n = CreateNode(data);
    // printf("sizeof data = %d\n", sizeof(double));
    if(l->head == NULL)
        l->head = n;
    else
    {
        n->next = l->head;
        l->head = n;
    }
    l->size ++;
}

List InsertSortList(List L, void * n)
{
    NODE v,curr,pre;
    pre = curr = L.head;
    v = CreateNode(n);
    printf("%d ", *(int *) v->data);
    if(L.head == NULL)
        L.head = v;
    else if( *(int*) curr->data > *(int*) n)
    {
        v->next = curr;
        L.head = v;
    }
    else
    {
        while(curr != NULL && *(int*) curr->data < *(int*) n)
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

void
CustomList(List *l)
{

    int l1=1,l2=2,l3=3,l4=4,l5=5,l6=6,l7=7,l8=8,l9=9,l10=10;
    // printf("%u \n", &l);
    InsertList(l,&l5);
    InsertList(l,&l8);
    InsertList(l,&l3);
    InsertList(l,&l1);
    InsertList(l,&l10);
    InsertList(l,&l9);
    InsertList(l,&l4);
    InsertList(l,&l2);
    InsertList(l,&l7);
    // printf("%u \n", &l);
}

List ReverseList(List L)
{
    NODE prev,curr,temp;
    if(L.head == NULL) 
        return L;
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
    if( *(int*) L.head->data == n)
        L.head = curr->next;
    else
    {
        while(curr != NULL)  // This should be enough
        {
            if( *(int*) curr->data == n)
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
            else 
            {
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
    while(curr != NULL)
    {
        if( *(int *) curr->data == n)
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
    free(L.head);
}

NODE IsCircularN(NODE n)
{
    int flag = 0;
    NODE temp = n->next,hare,tort,prevh,prevt;
    tort = hare = n->next->next;
    hare = tort->next;
    while(hare != NULL && hare != tort)
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
    // printf("%d \n", *(int *) n->s.num);
    int flag=0;
    temp = n->next;
    if(temp==NULL) free(n);
    if(cirr==NULL) // IsCircularN determines whether the neighbour of the NODE n is in the loop or not
    {
        // printf("%d \n",n->s.num);
        n->data = temp->data;
        n->next = temp->next;
        free(temp);
    }
    else
    {
        // printf("cirr = %d\n",cirr->s.num);
        n->data = temp->data;
        n->next = temp->next;
        cirr->next = n;
        free(temp);
    }
    return ;

}

void PrintList(List *L)
{
    NODE curr = L->head;
    int i=0;
    while(curr != NULL && i++<10)
    {
        printf("%d ", *(int *) curr->data);
        curr = curr->next;
    }
    printf("\n");
}


#endif // LINKOPS_H_INCLUDED
