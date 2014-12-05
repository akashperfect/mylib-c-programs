
/* Hash Table code for using key and data both as integers */
/* Hash Function implemented : (double)k*(sqrt(5)-1.0)/2.0 (multiplication hash) */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Hashtableadt.h"
#include "HashFunctions.h"

hashtable h;

/* Create a Hash Table with the size as input */

void CreateHashTable(int size)
{
    int i = 0;
    h.buckets = (bucket*)malloc(size*sizeof(bucket));
    h.size = size;
    while(i < size)
    {
        h.buckets[i].head = NULL;
        h.buckets[i].tail = NULL;
        h.buckets[i].size = 0;
        i++;
    }
}

/* Inserts Integer element in the Hash Table in stack manner  */

void InsertElementHashTable(int e)
{
    NODE n = CreateNode();
    n->num = e;
    int hash = MultiplicationHash(e,h.size);
    if(h.buckets[hash].head==NULL)
    {
        h.buckets[hash].head=n;
        h.buckets[hash].tail=n;
    }
    else
    {
        n->next = h.buckets[hash].head;
        h.buckets[hash].head->prev = n;
        h.buckets[hash].head = n;
    }
    h.buckets[hash].size++;
}

/* Inserts Integer element in the Hash Table in sorted manner  */

void InsertElementHashTableSort(int e)
{
    NODE n,curr;
    n = CreateNode();
    n->num = e;
    int hash = MultiplicationHash(e,h.size);
    if(h.buckets[hash].head==NULL)
    {
        h.buckets[hash].head=n;
        h.buckets[hash].tail=n;
    }
    else
    {
        curr = h.buckets[hash].head;
        if (curr->num > e)
        {
            n->next = h.buckets[hash].head;
            h.buckets[hash].head = n;
        }
        else
        {
            while(curr != NULL && curr->num < e)
            {
                curr = curr->next;
            }
            if(curr != NULL)
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
        
    }
    h.buckets[hash].size++;
}


/* Delete an element from the Hash Table */

void DeleteElementHashTable(int d)
{
    int hash = MultiplicationHash(d,h.size);
    NODE temp,curr;
    if(h.buckets[hash].head == h.buckets[hash].tail)
    {
        temp = h.buckets[hash].head;
        h.buckets[hash].head = NULL;
        h.buckets[hash].tail = NULL;
    }
    else if(h.buckets[hash].head->num == d)
    {
        temp = h.buckets[hash].head;
        h.buckets[hash].head->next->prev = NULL;
        h.buckets[hash].head = h.buckets[hash].head->next;
    }
    else if(h.buckets[hash].tail->num == d)
    {
        temp = h.buckets[hash].tail;
        h.buckets[hash].tail->prev->next = NULL;
        h.buckets[hash].tail = h.buckets[hash].tail->prev;
    }
    else
    {
        curr = h.buckets[hash].head;
        while(curr->num != d && curr != NULL)
        {
            curr = curr->next;
        }
        if(curr != NULL)
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


NODE FindElementHashTable(int k)
{
    int hash = MultiplicationHash(k,h.size);
    NODE curr = h.buckets[hash].head;
    while(curr != NULL && curr->num != k)
    {
        curr = curr->next;
    }
    if(curr != NULL)
    {
        printf("Element Found");
        return curr;
    }
    else
    {
        printf("ERROR: Element Not Found");
        exit(0);
    }
    return NULL;

}

void PrintHashTable()
{
    int i = 0;
    NODE curr;
    FILE *fp;
    fp = fopen("hashout.txt","w");
    fprintf(fp,"Index \t Number\n");
    for( ; i < h.size ; i++)
    {
        curr = h.buckets[i].head;
        while(curr!=NULL)
        {
            fprintf(fp,"%d \t %d\n",i,curr->num);
            curr = curr->next;
        }
    }
}


/* The main function inserts 100000 elements in hash table */

int main()
{
    FILE *fp;
    // clock_t begin, end;
    // begin = clock();
    CreateHashTable(113);
    int i = 0;
    for(i ; i < 100000 ; i++)
    {
        InsertElementHashTable(rand());
    }
    // end = clock();
    PrintHashTable();
    // printf("%lf\n",  (double)(end - begin) / CLOCKS_PER_SEC);
    return 0;
}
