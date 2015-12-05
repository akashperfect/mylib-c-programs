#ifndef LINKOPS_H_INCLUDED
#define LINKOPS_H_INCLUDED
#include "Link.h"


extern NODE CreateNode();
extern NODE InsertValue(NODE n, int val);
extern int Value(NODE n);

NODE CreateNode(int val)
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node));
    n->data=val;
    n->prev = NULL;
    //n->s.st = (char*)malloc(100*sizeof(char));
    //n->s.w = 0;
    n->next=NULL;
    return n;
}

NODE InsertValue(NODE n, int val)
{
    n->data = val;
    return n;
}

//NODE InsertValueS(NODE n, SAT e)
//{
//    n->data = e.num;
//    strcpy(n->s.st,e.st);
//    return n;
//}

List CreateList()
{
    List l;
    l.size = 0;
    l.head = NULL;
    l.tail = NULL;
    return l;
}

List InsertList(List L, int n)
{
    NODE v,curr,pre;
    pre = curr = L.head;
    v = (NODE)malloc(sizeof(struct node));
    v->data = n;
    v->next = NULL;
    if(L.head==NULL)
    L.head = v;
    else if(curr->data>n)
    {
        v->next = curr;
        L.head = v;
    }
    else
    {
        while(curr!=NULL&&curr->data<n)
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

List UnsortInsert(List L, int n)
{
    NODE v;
    v = CreateNode(n);
    if(L.head==NULL)
    L.head = v;
    else
    {
        v->next = L.head;
        L.head = v;
    }
    L.size++;
    return L;

}

List UnsortInsertDLL(List L, int n)
{
    NODE v;
    v = CreateNode(n);
    if(L.head == NULL)
    {
        L.head = v;
        L.tail = v;
    }
    else
    {
        v->next = L.head;
        L.head->prev = v;
        L.head = v;
    }
    L.size++;
    return L;
}


List GenerateList(int size)
{
    List L = CreateList();
    int i;
    for(i=0;i<size;i++)
    {
        L = UnsortInsertDLL(L,rand());
    }
    return L;
}

int Length(NODE n)
{
    NODE curr = n;
    int count = 0;
    while(curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
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
    //printf("r%d\n",n->data);
    if(n==NULL) return acc;
    //printf("s%d\n",n->data);
    NODE next = n->next;
    n->next = acc;
    return ReverseListWP(next,n);

}

List DeleteNode(List L, int n)
{
    NODE prev,curr;
    prev = curr = L.head;
    if(L.head->data==n)
    L.head = curr->next;
    else
    {while(curr != NULL)  // This should be enough
{
     if(curr->data == n)
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

NODE Search(List L, int n)
{
    NODE curr = L.head;
    while(curr!=NULL)
    {
        if(curr->data==n)
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

NODE CircularMatchNode(NODE n)
{
    int flag = 0;
    NODE hare,tort;
    tort = hare = n->next;
    hare = tort->next;
    while(hare!=tort)
    {
        tort = tort->next;
        hare = hare->next->next;
    }
    return hare;

}


NODE NodeCircluarList(List L) /*This functions returns the node at the beginning of the loop of a circular linked list*/
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
    printf("%d \n",n->data);
    int flag=0;
    temp = n->next;
    if(temp==NULL) free(n);
    if(cirr==NULL) // IsCircularN determines whether the neighbour of the NODE n is in the loop or not
    {
        printf("%d \n",n->data);
        n->data = temp->data;
        n->next = temp->next;
        free(temp);
    }
    else
    {
        printf("cirr = %d\n",cirr->data);
        n->data = temp->data;
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
    FILE *fp;
    fp  = fopen("Sort.txt","w");
    while(curr!=NULL)
    {
        fprintf(fp,"%d\n",curr->data);
        //printf("%d\n",curr->data);
        curr = curr->next;
    }
    printf("\n");
    fclose(fp);
}

int PrintNode(NODE n, FILE *fp)
{
    NODE curr = n;
    int i=0;
    //fprintf(fp,"len = %d\n",Length(curr));
    while(curr!=NULL)
    {
        fprintf(fp,"%d ",curr->data);
        curr = curr->next;
    }
    fprintf(fp,"\n");
    return n->data;
}

int Value(NODE n)
{
    return n->data;
}

NODE CheckPali(NODE curr, NODE rev, int *test) /* Recursive function called by CheckPalindrome to check for palindrome */
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

int CheckPalindrome(List L) /*Function to check if a Link is Palindrome or not*/
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
