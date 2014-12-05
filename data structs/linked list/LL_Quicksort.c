#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"
#include "Link.h"
#include "Linkops.h"
#include<time.h>

int partition_space(List *L, int s, int en)
{

    int p=s,j=1,sm=1,tempi;
//    printf("part %d %d ",s,en);

    //PrintList(*L);
    NODE small=NULL,sn=NULL,piv = (*L).head,curr = (*L).head,temp,prev;
    while(j<s)
    {
        curr = curr->next;
        piv = piv->next;
        j++;
    }
    prev = curr;
    curr = curr->next;
//    printf("piv = %d\n",piv->data);
    while(j < en)
    {

        if(curr->data < piv->data)
        {

            if(small==NULL)
            sn = small = CreateNode(curr->data);
            else{
            small->next = CreateNode(curr->data);
            small = small->next;
            sm++;
            p = sm;}
            //printf("curr = %d ",curr->data);
            prev->next = curr->next;
            temp = curr;
            curr = curr->next;
            free(temp);
            j++;

        }
        else {
        prev = curr;
        j++;
        curr = curr->next;}
    }
    if(small != NULL){
    tempi = piv->data;
    piv->data = small->data;
    small->data = tempi;
    small->next = piv->next;
    piv->next = sn;}
    //printf("\n");
    return p;
}

int partition_opti(List *L, int s, int en)
{
    if(s==en) return s;

    int p=s,j=1,sm=1,mid,tempi;
    //printf("part %d %d ",s,en);

    //PrintList(*L);
    NODE small = (*L).head->next,piv = (*L).head,pivot = (*L).head,curr = (*L).head,temp;
    mid = (s+en)/2 - s;
    while(mid--)
    {
        piv = piv->next;
        pivot = pivot->next;
    }
    while(j<=s)
    {
        curr = curr->next;
        piv = piv->next;
        pivot = pivot->next;
        small = small->next;
        sm++;
        j++;
    }
    tempi = curr->data;
    curr->data = piv->data;
    piv->data = tempi;
    piv = pivot = curr;
    curr = curr->next;


    while(curr!=NULL && j<=en)
    {
        if(curr->data < piv->data)
        {
            temp = small->data;
            small->data = curr->data;
            curr->data = temp;
            p = sm;
            pivot = small;
            small = small->next;
            sm++;
        }
        j++;
        curr = curr->next;

    }
    temp = piv->data;
    piv->data = pivot->data;
    pivot->data = temp;
    //printf("\n");
    return p;
}


int partition(List *L, int s, int en)
{
    if(s==en) return s;

    int p=s,j=1,sm=1,tempi;
    //printf("part %d %d ",s,en);


    //PrintList(*L);
    NODE small = (*L).head->next,piv = (*L).head,pivot = (*L).head,curr = (*L).head->next,temp;

    while(curr!=NULL && j<=en)
    {
        if(j<=s)
        {
            curr = curr->next;
            piv = piv->next;
            pivot = pivot->next;
            small = small->next;
            sm++;
            j++;
        }
        else
        {
            //printf("%d ",curr->data);
            if(curr->data < piv->data)
            {
                tempi = small->data;
                small->data = curr->data;
                curr->data = tempi;
                p = sm;
                pivot = small;
                small = small->next;
                sm++;
            }
            j++;
            curr = curr->next;
        }
    }
    temp = piv->data;
    piv->data = pivot->data;
    pivot->data = temp;
    //printf("\n");
    return p;
}

NODE partition_dll(NODE *s, NODE *en)
{
    if(*s==*en) return *s;

    int tempi;
    //printf("part %d %d ",(*s)->data,(*en)->data);


    //PrintList(*L);
    NODE small = *s ,piv = *en,curr = *s,temp;

    while(curr!=NULL && curr!=*en)
    {
        if(curr->data < piv->data)
        {
            tempi = small->data;
            small->data = curr->data;
            curr->data = tempi;
            small = small->next;
        }
        curr = curr->next;

    }
    tempi = piv->data;
    piv->data = small->data;
    small->data = tempi;
    //printf("\n");
    return small;
}

void quicksort(List *L, NODE *s, NODE *en)
{
    NODE p;
//    printf("quick %d %d ",s,en);
    p = partition_dll(s,en);
//    printf("pivot = %d\n",p);
    if(*s!=p)
    quicksort(L,s,&(p->prev));
    if(p!=*en)
    quicksort(L,&(p->next),en);
}


int main(int argc, char *argv[])
{
    int i,r;
    clock_t begin, end;
    FILE *fp;
    fp = fopen("Time Test.txt","a+");
    List L = CreateList();
    for(i=0;i<10000000;i++)
    {

        //printf("%d \n",i);
        L = UnsortInsertDLL(L,rand());
    }
    //
    printf("Test");
    begin = clock();
    quicksort(&L,&(L.head),&(L.tail));
    end = clock();
    fprintf(fp,"Linked List Quick Sort sort time : %lf\nNumber of Inputs : %d\n", (double)(end - begin) / CLOCKS_PER_SEC,i );

    PrintList(L);


}
