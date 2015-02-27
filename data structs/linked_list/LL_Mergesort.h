#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "basicdef.h"
#include "Link.h"
#include "Linkops.h"
#include<time.h>

int FrontBackSplit(NODE source, NODE *front, NODE *back)
{
    if(source == NULL) return;
    int len = Length(source), mid,i=0;
    if(len == 1) return len;
    if(len%2==0)
        mid = len/2;
    else
        mid = len/2+1;

    *front = source;
    NODE prev,curr = source;
    prev = source;
    while(i<mid)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }

    *back = curr;
    prev->next = NULL;

}

NODE merge(NODE *a, NODE *b)
{
    NODE temp;
    FILE *fp;
//    fp = fopen("global_dump.txt","a+");
//    fprintf(fp,"Node a = %d Node b = %d\n",PrintNode(*a,fp),PrintNode(*b,fp));
    if((*a) == NULL || (*b) == NULL) return ;
    //printf("A");
    if((*a)->data > (*b)->data)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    NODE prev = *a,curr = *a,prevb = *b,currb = *b;
    curr = curr->next;
    while(curr!=NULL && prevb!=NULL)
    {
        if(currb->data < curr->data)
        {
            prev->next = prevb;
            currb = currb->next;
            prevb->next = curr;
            prev = prevb;
            prevb = currb;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    if(prevb!=NULL)
    prev->next = prevb;
//    fprintf(fp,"Node a = %d\n",PrintNode(*a,fp));
//    fclose(fp);
    return *a;

}

NODE smerge(NODE a, NODE b)
{
    NODE temp;
    FILE *fp;
//    fp = fopen("global_dump.txt","a+");
//    fprintf(fp,"Node a = %d Node b = %d\n",PrintNode(a,fp),PrintNode(b,fp));
    if((a) == NULL || (b) == NULL) return ;
//    printf("A");
    if((a)->data > (b)->data)
    {
        temp = a;
        a = b;
        b = temp;
    }
    NODE prev = a,curr = a,prevb = b,currb = b;
    curr = curr->next;
    while(curr!=NULL && prevb!=NULL)
    {
        if(currb->data < curr->data)
        {
            prev->next = prevb;
            currb = currb->next;
            prevb->next = curr;
            prev = prevb;
            prevb = currb;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    if(prevb!=NULL)
    prev->next = prevb;
//    fprintf(fp,"Node a = %d\n",PrintNode(a,fp));
//    fclose(fp);
    return a;

}


NODE mergesort(NODE  head)
{
    NODE  s,en;
//    FILE *fp1;
//
//    fp1 = fopen("global_dump.txt","a+");
    s = CreateNode(0);
    en = CreateNode(0);
//    fprintf(fp1,"head = %d\n",PrintNode((head),fp1));
    if(FrontBackSplit((head),&s,&en)==1) return head;
//    fprintf(fp1,"start = %d end = %d\n",PrintNode(s,fp1),PrintNode(en,fp1));
//    fclose(fp1);
    s = mergesort(s);
    en = mergesort(en);

    return smerge(s,en);

}
/*
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
    begin = clock();
    L1.head = mergesort((L.head));
    end = clock();
    fprintf(fp,"Linked List Merge Sort sort time : %lf\nNumber of Inputs : %d\n", (double)(end - begin) / CLOCKS_PER_SEC,i );
    //PrintList(L1);




}*/
