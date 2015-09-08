#ifndef PRIORITYQUEUES_H_INCLUDED
#define PRIORITYQUEUES_H_INCLUDED
#include "linked_list/Linkops.h"

// extern void CreatePQ();
// extern void MaxHeapify(PQ *p, int i);
// // extern PQ InsertPQ(PQ p,int n);
// extern int MaximumPQ(PQ p);
// extern PQ IncreaseKeyPQ(PQ p, int x, int k);
// extern int ExtractMaxPQ(PQ *p);
// extern void ExchangePQ(priorityqueue *p,priorityqueue* q);
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
    pqueue.arr = (arrayNode *)calloc(size, sizeof(struct arrayNode));
    pqueue.size = 0;
    for(i = 0; i < size; i ++){
        pqueue.arr[i]->data = NULL;
        pqueue.arr[i]->k = -1;
    }
}

void
InsertPQ(void *data, int pri)
{
    pqueue.arr[pqueue.size]->data = data;
    // InsertValuePQ(&pqueue.p[pqueue.size],-1);
    IncreaseKeyPQ(pri);
    q->size ++;
}

// void
// MaxHeapify(PQ *p, int i)
// {
//     int left = 2*i+1, right = 2*i+2, large;
//     if (left < p->size && ValuePQ(p->p[left]) > ValuePQ(p->p[i]))
//         large = left;
//     else
//         large = i;
//     if (right < p->size && ValuePQ(p->p[right]) > ValuePQ(p->p[large]))
//         large = right;
//     if(large != i)
//     {
//         ExchangePQ(&(p->p[i]), &(p->p[large]));
//         MaxHeapify(p,large);
//     }
// }


// int MaximumPQ(PQ p)
// {
//     return ValuePQ(p.p[0]);
// }

// PQ IncreaseKeyPQ(PQ p, int x, int k)
// {
//     if(ValuePQ(p.p[x])>k)
//     {
//         printf("ERROR: new key smaller than previous");
//         return p;
//     }
//     InsertValuePQ(&p.p[x],k);
//     while(x>0&&ValuePQ(p.p[x/2])<ValuePQ(p.p[x]))
//     {
//         ExchangePQ(&p.p[x], &p.p[x/2]);
//         x = x/2;
//     }
//     return p;
// }


// int ExtractMaxPQ(PQ *q)
// {
//     int max = ValuePQ(q->p[0]);
//     q->p[0].k =  q->p[q->size-1].k;
//     q->size--;
//     MaxHeapify(q, 0);
//     return max;
// }

// void PrintPQ(PQ p)
// {
//     int i=0;
//     printf("\nsize %d\n",p.size);
//     while(i<p.size)
//     {
//         printf("%d ",ValuePQ(p.p[i]));
//         i++;
//     }
// }


// void ExchangePQ(priorityqueue *p,priorityqueue* q)
// {
//     /*pq * temp;
//     temp = p;
//     p = q;
//     q = temp;*/
//     printf("bp = %d bq = %d",(*p).k,(*q).k);
//     priorityqueue *temp;
//     *temp = *p;
//     *p = *q;
//     *q = *temp;
//     printf("ap = %d aq = %d\n",(*p).k,(*q).k);
// }

// void InsertValuePQ(priorityqueue *p, int n)
// {
//     p->k = n;
//     //printf("aa");
// }


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
//     p.p[0].k =  p.p[p.size-1].k;
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
