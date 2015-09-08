#ifndef PRIORITYQUEUES_H_INCLUDED
#define PRIORITYQUEUES_H_INCLUDED
#include "linked_list/Linkops.h"

// extern void CreatePQ();
// extern void MaxHeapify(PQ *p, int i);
// // extern PQ InsertPQ(PQ p,int n);
// extern int MaximumPQ(PQ p);
// extern int ExtractMaxPQ(PQ *p);
extern void ExchangePQ(int ,int );
extern void IncreaseKeyPQ(int x, int k);
extern int GetPriority(int );
extern void SetPriority(int ,int );
// extern void InsertValuePQ(priorityqueue *p, int n);
// extern PQ MinHeapify(PQ p, int i);
// // extern PQ InsertPQ(PQ p,int n);
// extern void InsertMinPQ(PQ *p,int n);
// extern int MinimumPQ(PQ p);
// extern void DecreaseKeyPQ(PQ *p, int x, int k);
// extern int ExtractMinPQ(PQ *p);

priorityQueue pqueue;

void
CreatePQ(int size)
{
    int i;
    pqueue.arr = (arrayNode *)calloc(size, 
                    sizeof(struct arrayNode));
    pqueue.size = 0;
    for(i = 0; i < size; i ++){
        pqueue.arr[i].data = NULL;
        pqueue.arr[i].k = -1;
    }
}

/*  Inserts an elemnent in the PQ
    also the size indicates the number 
    of elements currently in the PQ
*/

void
InsertPQ(void *data, int pri)
{
    pqueue.arr[pqueue.size].data = data;
    IncreaseKeyPQ(pqueue.size, pri);
    pqueue.size ++;
}

void 
IncreaseKeyPQ(int x, int pri)
{
    SetPriority(x, pri);
    while(x > 0 && GetPriority((x - 1)/2)
                     < GetPriority(x)){
        ExchangePQ(x, (x - 1)/2);
        x = (x - 1)/2;
    }
    return ;
}

void
MaxHeapify(int i)
{
    int left = 2*i+1, right = 2*i+2, large;
    if (left < pqueue.size && 
            GetPriority(left) > GetPriority(i))
        large = left;
    else
        large = i;
    if (right < pqueue.size && 
            GetPriority(right) > GetPriority(large))
        large = right;
    if(large != i)
    {
        ExchangePQ(i, large);
        MaxHeapify(large);
    }
}


arrayNode 
ExtractMaxPQ()
{
    arrayNode max = pqueue.arr[0];
    ExchangePQ(0, pqueue.size - 1);
    pqueue.size--;
    MaxHeapify(0);
    return max;
}

int 
GetPriority(int index)
{
    return pqueue.arr[index].k;
}

void 
SetPriority(int index, int value)
{
    pqueue.arr[index].k = value;
}

int MaximumPQ()
{
    return pqueue.arr[0].k;
}

void 
PrintPQ()
{
    int i = 0;
    printf("Printing Priority Queue of size %d\n",
     pqueue.size);
    while(i < pqueue.size){
        printf("%d ", GetPriority(i));
        i ++;
    }
    printf("\n");
}

/*  Not sending the pointers for 
    the exchange as pqueue is global
*/
void 
ExchangePQ(int a, int b)
{
    arrayNode temp;
    temp = pqueue.arr[a];
    pqueue.arr[a] = pqueue.arr[b];
    pqueue.arr[b] = temp;
    return ;
}


// PQ MinHeapify(PQ p, int i)
// {
//     int left = 2*i+1, right = 2*i+2,small;
//     if (left<p.size&&ValuePQ(p.p[left])<ValuePQ(p.p[i]))
//         small = left;
//     else
//         small = i;
//     if (right<p.size && ValuePQ(p.p[right])<ValuePQ(p.p[small]))
//         small = right;
//     if(small!=i)
//     {
//         ExchangePQ(&p.p[i],&p.p[small]);
//         p = MinHeapify(p,small);
//     }
//     return p;
// }

// void
// InsertMinPQ(PQ *q, int n)
// {
//     InsertValuePQ(&(q->p[q->size]), MAXINT);
//     DecreaseKeyPQ(q, q->size, n);
//     q->size++;
// }

// int MinimumPQ(PQ p)
// {
//     return ValuePQ(p.p[0]);
// }

// void
// DecreaseKeyPQ(PQ *q, int x, int k)
// {
//     if(ValuePQ(q->p[x]) < k){
//         printf("ERROR: new key larger than previous");
//         return ;
//     }
//     InsertValuePQ(&q->p[x], k);
//     while(x > 0){
//         if(ValuePQ(q->p[x/2]) > ValuePQ(q->p[x])){
//             ExchangePQ(&q->p[x], &q->p[x/2]);
//         }
//         x = x/2;
//     }
// }


// int ExtractMinPQ(PQ *q)
// {
//     PQ p = *q;
//     int min = ValuePQ(p.p[0]);
    //     p.p[0) =  p.p[p.size-1);
//     p.size--;
//     p = MinHeapify(p, 0);
//     *q = p;
//     return min;
// }

// int ValuePQ(priorityqueue p)
// {
//     return p.k;
// }

// // void
// // PrintPQ(PQ q)
// // {
// //     int i;
// //     for ( i = 0; i < q.size; ++i){
// //         printf("%d ", Value(q.p[i].data));
// //     }
// // }
#endif // PRIORITYQUEUES_H_INCLUDED
