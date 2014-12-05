#ifndef PRIORITYQUEUES_H_INCLUDED
#define PRIORITYQUEUES_H_INCLUDED
#include "Linkops.h"

extern PQ MaxHeapify(PQ p, int i);
extern PQ InsertPQ(PQ p,int n);
extern int MaximumPQ(PQ p);
extern PQ IncreaseKeyPQ(PQ p, int x, int k);
extern int ExtractMaxPQ(PQ *p);
extern PQ CreatePQ();
extern void ExchangePQ(priorityqueue *p,priorityqueue* q);
extern void InsertValuePQ(priorityqueue *p, int n);
extern PQ MinHeapify(PQ p, int i);
extern PQ InsertPQ(PQ p,int n);
extern PQ InsertMinPQ(PQ p,int n);
extern int MinimumPQ(PQ p);
extern PQ DecreaseKeyPQ(PQ p, int x, int k);
extern int ExtractMinPQ(PQ *p);


PQ CreatePQ()
{
    PQ p;
    p.p = (pq)malloc(sizeof(struct priorityqueue));
    p.size=0;
    return p;
}

PQ MaxHeapify(PQ p, int i)
{
    int left = 2*i+1, right = 2*i+2,large;
    if (left<p.size&&ValuePQ(p.p[left])>ValuePQ(p.p[i]))
        large = left;
    else
        large = i;
    if (right<p.size && ValuePQ(p.p[right])>ValuePQ(p.p[large]))
        large = right;
    if(large!=i)
    {
        ExchangePQ(&p.p[i],&p.p[large]);
        p = MaxHeapify(p,large);
    }
    return p;
}

PQ InsertPQ(PQ p,int n)
{
    InsertValuePQ(&p.p[p.size],-1);
    p = IncreaseKeyPQ(p,p.size,n);
    p.size++;
    return p;
}

int MaximumPQ(PQ p)
{
    return ValuePQ(p.p[0]);
}

PQ IncreaseKeyPQ(PQ p, int x, int k)
{
    if(ValuePQ(p.p[x])>k)
    {
        printf("ERROR: new key smaller than previous");
        return p;
    }
    InsertValuePQ(&p.p[x],k);
    while(x>0&&ValuePQ(p.p[x/2])<ValuePQ(p.p[x]))
    {
        ExchangePQ(&p.p[x], &p.p[x/2]);
        x = x/2;
    }
    return p;
}


int ExtractMaxPQ(PQ *q)
{
    PQ p = *q;
    int max = ValuePQ(p.p[0]);
    p.p[0].k =  p.p[p.size-1].k;
    p.size--;
    p = MaxHeapify(p, 0);
    *q = p;
    return max;
}

void PrintPQ(PQ p)
{
    int i=0;
    printf("\nsize %d\n",p.size);
    while(i<p.size)
    {
        printf("%d ",ValuePQ(p.p[i]));
        i++;
    }
}


void ExchangePQ(priorityqueue *p,priorityqueue* q)
{
    /*pq * temp;
    temp = p;
    p = q;
    q = temp;*/
    printf("bp = %d bq = %d",(*p).k,(*q).k);
    priorityqueue temp;
    temp = *p;
    *p = *q;
    *q = temp;
    printf("ap = %d aq = %d\n",(*p).k,(*q).k);
}

void InsertValuePQ(priorityqueue *p, int n)
{
    (*p).k = n;
    //printf("aa");
}


PQ MinHeapify(PQ p, int i)
{
    int left = 2*i+1, right = 2*i+2,small;
    if (left<p.size&&ValuePQ(p.p[left])<ValuePQ(p.p[i]))
        small = left;
    else
        small = i;
    if (right<p.size && ValuePQ(p.p[right])<ValuePQ(p.p[small]))
        small = right;
    if(small!=i)
    {
        ExchangePQ(&p.p[i],&p.p[small]);
        p = MinHeapify(p,small);
    }
    return p;
}

PQ InsertMinPQ(PQ p,int n)
{
    InsertValuePQ(&p.p[p.size],1000);
    p = DecreaseKeyPQ(p,p.size,n);
    p.size++;
    return p;

}

int MinimumPQ(PQ p)
{
    return ValuePQ(p.p[0]);
}

PQ DecreaseKeyPQ(PQ p, int x, int k)
{
    if(ValuePQ(p.p[x])<k)
    {
        printf("ERROR: new key larger than previous");
        return p;
    }
    InsertValuePQ(&p.p[x],k);
    while(x>0&&ValuePQ(p.p[x/2])>ValuePQ(p.p[x]))
    {
        ExchangePQ(&p.p[x], &p.p[x/2]);
        x = x/2;
    }
    return p;
}


int ExtractMinPQ(PQ *q)
{
    PQ p = *q;
    int min = ValuePQ(p.p[0]);
    p.p[0].k =  p.p[p.size-1].k;
    p.size--;
    p = MinHeapify(p, 0);
    *q = p;
    return min;
}
#endif // PRIORITYQUEUES_H_INCLUDED
