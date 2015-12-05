#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hashtableadt.h"
#include "HashFunctions.h"

hashtable h;

hashtable CreateHashTable(int size)
{
    int i=0;
    h.buckets = (bucket*)malloc(size*sizeof(bucket));
    h.size = size;
    while(i<size)
    {
        h.buckets[i].head = NULL;
        h.buckets[i].tail = NULL;
        h.buckets[i].size = 0;
        i++;
    }
}


void InsertElementHashTable(char * s)
{
    NODE n = CreateNode();
    strcpy(n->str , s);
    int hash = CharacterHash(h.size , s);
    if(h.buckets[hash].head == NULL)
    {
        h.buckets[hash].head = n;
        h.buckets[hash].tail = n;
    }
    else
    {
        n->next = h.buckets[hash].head;
        h.buckets[hash].head->prev = n;
        h.buckets[hash].head = n;
    }
    h.buckets[hash].size++;
}


void InsertElementHashTableSort(SAT e)
{
    NODE n,curr;
    n = CreateNode();
    n = InsertValueS(n,e);
    int hash = Characterhash(h.size,e);
    if(h.buckets[hash].head==NULL)
    {
        h.buckets[hash].head=n;
        h.buckets[hash].tail=n;
    }
    else
    {
        curr = h.buckets[hash].head;
        while(curr!=NULL&&Value(curr)<e.num)
        {
            curr = curr->next;
        }
        if(curr!=NULL)
        {
            n->next = curr;
            n->prev = curr->prev;
            curr->prev->next = n;
            curr->prev = n;
        }
        else
        {
            n->prev = h.buckets[hash].tail;
            h.buckets[hash].tail->next = n;
            h.buckets[hash].tail = n;
        }
    }
    h.buckets[hash].size++;
}

void DeleteElementHashTable(SAT e)
{
    int hash = Characterhash(h.size,e);
    NODE temp,curr;
    if(h.buckets[hash].head==h.buckets[hash].tail)
    {
        temp = h.buckets[hash].head;
        h.buckets[hash].head=NULL;
        h.buckets[hash].tail=NULL;
    }
    else if(Value(h.buckets[hash].head)==e.num)
    {
        temp = h.buckets[hash].head;
        h.buckets[hash].head->next->prev = NULL;
        h.buckets[hash].head = h.buckets[hash].head->next;
    }
    else if(Value(h.buckets[hash].tail)==e.num)
    {
        temp = h.buckets[hash].tail;
        h.buckets[hash].tail->prev->next = NULL;
        h.buckets[hash].tail = h.buckets[hash].head->prev;
    }
    else
    {
        curr = h.buckets[hash].head;
        while(Value(curr)!=e.num&&curr!=NULL)
        {
            curr = curr->next;
        }
        if(curr!=NULL)
        {
            temp = curr;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        else
        {
            printf("ERROR: Element Not Found");
            exit(0);
        }
    }
    h.buckets[hash].size--;
    free(temp);
}


int FindElementHashTable(SAT e)
{
    int hash = Characterhash(h.size,e);
    NODE curr;
    curr = h.buckets[hash].head;
    while(curr!=NULL&&Value(curr)!=e.num)
    {
        curr = curr->next;
    }
    if(curr!=NULL)
    return Value(curr);
    else
    {
        printf("ERROR: Element Not Found");
        exit(0);
    }

}

void PrintHashTable(hashtable H)
{
    int i=0;
    NODE curr;
    FILE *fp;
    fp = fopen("hashout.txt","w");
    for(i;i<H.size;i++)
    {
        if(H.buckets[i].size!=0)
        {
            curr = H.buckets[i].head;
            while(curr!=NULL)
            {
                fprintf(fp,"%d %s\n",i,curr->s.st);
                curr = curr->next;
            }
        }
    }
    return ;
}

int main()
{
    

    FILE *fp;
    h = CreateHashTable(113);
    SAT n;int i=0,j;
    n.st = (char*)malloc(100*sizeof(char));
    char ch[10000][20];
    fp = fopen("dataset.txt","r");
    while(fscanf(fp,"%s",ch[i])!=EOF)
    {
        i++;
    }
    for(j=0;j<i;j++)
    {
        n.num = 10;
        strcpy(n.st,ch[j]);
        h = InsertElementHashTable(h,n);
    }
    PrintHashTable(h);

}
